// South Park (USA) runtime layer.
//
// South Park's libultra is 2.0D and the game drives some hardware directly instead of
// going through the libultra managers that N64ModernRuntime reimplements. This file
// provides the pieces the stock runtime doesn't:
//
//   * sp_osPiRawStartDma  - the game's own DMA thread calls osPiRawStartDma and then
//                           waits for the PI interrupt (OS_EVENT_PI).
//   * sp_osSetEventMesg   - remembers the PI and SI event queues (the runtime ignores
//                           OS_EVENT_PI) and forwards to the runtime.
//   * sp_osMapTLB & co.   - the game runs code and keeps data at TLB-mapped addresses
//                           (0x00200000 + phys, block 2 at 0x00400000). RDRAM is moved
//                           into a shared-memory object so physical pages can be mapped a
//                           second time at the virtual address.
//   * Demand paging       - the game streams ROM data through virtual "regions" above
//                           the fixed 0x00400000 block and relies on TLB-miss exceptions
//                           to page them in (its handler is func_002903DC). There are no
//                           CPU exceptions under the recompiler, so the host SIGSEGV
//                           handler pages them in instead (southpark_tlb_handle_fault).
//   * sp_osVirtualToPhysical, task pointers - translate TLB-mapped addresses through the
//                           game's TLB mappings before they reach the RSP/RDP.
//   * sp_osAiGetStatus    - AI FIFO-full flag the audio thread's refill loop waits for.
//   * sp_osSetThreadPri   - the runtime's thread_queue_remove only ever checks the head
//                           of a queue, so changing the priority of another thread that
//                           is queued behind others corrupts the queue (see below).
//   * sp_cart_io_read/write - PI I/O helpers used by the game's streaming code.
//   * Stand-ins for libultra internals that recompiled game code still calls (SI
//     access for Controller Pak / reset paths) and guards for internals that should
//     be unreachable.
//
// Function names here match tools/libultra_names.json and southpark.us.toml.

#include <algorithm>
#include <atomic>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <span>
#include <vector>

#if !defined(_WIN32)
#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>
#endif

#include "sp_recomp.h"
#include "librecomp/game.hpp"
#include "librecomp/addresses.hpp"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/error_handling.hpp"

namespace {
    constexpr uint32_t OS_READ = 0;
    constexpr uint32_t EVENT_SI = 5;
    constexpr uint32_t EVENT_PI = 8;

    // N64 physical RAM that TLB mappings may point into (8 MB with the Expansion Pak).
    constexpr size_t phys_ram_size = 8 * 1024 * 1024;
    // rdram + offset for a sign-extended 32-bit address `addr` (see MEM_W in recomp.h).
    inline uint64_t host_offset(uint32_t addr) {
        return (uint64_t)(int64_t)(int32_t)addr - 0xFFFFFFFF80000000ULL;
    }

    std::mutex event_mutex;
    int32_t pi_mq = 0, pi_msg = 0;
    int32_t si_mq = 0, si_msg = 0;

    void post_event(uint8_t* rdram, int32_t mq, int32_t msg) {
        if (mq != 0) {
            osSendMesg(PASS_RDRAM mq, msg, OS_MESG_NOBLOCK);
        }
    }

    uint32_t rom_word(uint32_t phys) {
        std::span<const uint8_t> rom = recomp::get_rom();
        uint64_t off = (uint64_t)phys - recomp::rom_base;
        if (phys < recomp::rom_base || off + 4 > rom.size()) {
            return 0;
        }
        return ((uint32_t)rom[off] << 24) | ((uint32_t)rom[off + 1] << 16) | ((uint32_t)rom[off + 2] << 8) | rom[off + 3];
    }

    // Cartridge address from a game-supplied device address (KSEG1, physical, or a
    // plain ROM offset OR'd with osRomBase).
    uint32_t cart_phys(uint8_t* rdram, uint32_t dev_addr) {
        uint32_t rom_base_reg = (uint32_t)MEM_W(0x308, (gpr)(int32_t)0x80000000);
        uint32_t phys = (dev_addr | rom_base_reg) & 0x1FFFFFFF;
        if (phys < recomp::rom_base) {
            phys |= recomp::rom_base;
        }
        return phys;
    }

    [[noreturn]] void unreachable_internal(const char* name) {
        char msg[256];
        std::snprintf(msg, sizeof(msg),
            "South Park: libultra internal %s was called.\n"
            "This should be unreachable once libultra is replaced by the runtime;\n"
            "please report it with what you were doing.", name);
        ultramodern::error_handling::message_box(msg);
        ULTRAMODERN_QUICK_EXIT();
        std::abort();
    }

    // ---- TLB emulation ----
    struct TlbEntry { bool used; uint64_t host_off; size_t size; };
    TlbEntry tlb_pages[64]{};   // two pages (even/odd) per TLB index
    // What the game mapped (for address translation), kept even when a host mapping
    // had to be skipped.
    struct TlbLogical { bool valid; uint32_t vaddr; uint32_t paddr; uint32_t size; };
    TlbLogical tlb_logical[64]{};
    int rdram_fd = -1;
    uint8_t* tlb_rdram = nullptr;
    std::mutex tlb_mutex;

    // ---- Demand paging (see southpark_tlb_handle_fault) ----
    //
    // The game's VM manager (func_00290B10's thread) keeps a linked list of virtual
    // regions, each backed by a contiguous range of ROM:
    //   +0x00 next node (KSEG0)
    //   +0x04 u16 first virtual page (vaddr >> 12)
    //   +0x06 u16 page count
    //   +0x08 ROM address of the first page
    //   +0x10 per-page frame table (0xFF = not resident)
    // The list head is the fixed block at 0x00400000 (mapped with osMapTLB index 0); new
    // regions are appended after the last one (func_00290FAC). On hardware a TLB miss
    // DMAs the 4 KB page from ROM into one of a few dozen frames at phys 0x106000 and
    // maps it. Here every touched page gets its own host page, filled from ROM once,
    // and is dropped again when its region is freed or its range is reused.
    constexpr uint32_t vm_region_head = 0x800EB9F0u;
    constexpr uint32_t vm_page = 0x1000u;
    constexpr uint32_t vm_max_vpages = 0x10000u;   // vpage is a u16 in the region nodes

    std::atomic_flag vm_lock = ATOMIC_FLAG_INIT;   // taken from the signal handler: no mutex
    uint64_t vm_paged[vm_max_vpages / 64]{};       // 4 KB pages this file has mapped
    size_t host_page_size = 4096;
    std::atomic<uint32_t> vm_pages_in{0};
    std::atomic<uint32_t> dma_count{0};   // PI DMAs started (sp_osPiRawStartDma)

    struct VmLock {
        VmLock() { while (vm_lock.test_and_set(std::memory_order_acquire)) {} }
        ~VmLock() { vm_lock.clear(std::memory_order_release); }
    };

    bool vm_is_paged(uint32_t vpage) { return (vm_paged[vpage >> 6] >> (vpage & 63)) & 1; }
    void vm_set_paged(uint32_t vpage, bool on) {
        uint64_t bit = 1ull << (vpage & 63);
        vm_paged[vpage >> 6] = on ? (vm_paged[vpage >> 6] | bit) : (vm_paged[vpage >> 6] & ~bit);
    }

    // Region node covering vpage, or 0. Reads game memory directly; only valid KSEG0
    // RDRAM node pointers are followed, so a half-built list can't send us astray.
    uint32_t vm_find_region(uint8_t* rdram, uint32_t vpage, uint32_t* rom_addr_out) {
        uint32_t node = vm_region_head;
        for (int guard = 0; guard < 512 && node != 0; guard++) {
            if (node < 0x80000000u || node >= 0x80000000u + phys_ram_size - 0x18) {
                return 0;
            }
            gpr n = (gpr)(int32_t)node;
            uint32_t start = MEM_HU(0x4, n);
            uint32_t count = MEM_HU(0x6, n);
            if (vpage >= start && vpage < start + count) {
                *rom_addr_out = (uint32_t)MEM_W(0x8, n) + (vpage - start) * vm_page;
                return node;
            }
            node = (uint32_t)MEM_W(0x0, n);
        }
        return 0;
    }

    // Copy one 4 KB page from ROM into host memory in RDRAM byte order (big-endian
    // words stored native, as the runtime's DMA does).
    void vm_fill_page(uint8_t* dst, uint32_t rom_addr) {
        std::span<const uint8_t> rom = recomp::get_rom();
        uint64_t off = rom_addr & 0x0FFFFFFFu;   // plain offset, or 0x10000000/0xB0000000 based
        uint32_t* out = reinterpret_cast<uint32_t*>(dst);
        for (uint32_t i = 0; i < vm_page / 4; i++, off += 4) {
            uint32_t w = 0;
            if (off + 4 <= rom.size()) {
                std::memcpy(&w, rom.data() + off, 4);
                w = __builtin_bswap32(w);
            }
            out[i] = w;
        }
    }
}

// Call once, on the game thread, before any game code runs. Moves the first 8 MB of
// RDRAM into a shared-memory object (same address, same contents) so that TLB
// mappings can alias it.
extern "C" bool southpark_init_tlb_memory(uint8_t* rdram) {
#if defined(_WIN32)
    (void)rdram;
    return false;
#else
    std::lock_guard lock{ tlb_mutex };
    if (rdram_fd >= 0) {
        return true;
    }
    int fd = (int)syscall(SYS_memfd_create, "southpark-rdram", 0);
    if (fd < 0) {
        std::fprintf(stderr, "[southpark] memfd_create failed; TLB-mapped data will not work\n");
        return false;
    }
    if (ftruncate(fd, phys_ram_size) != 0) {
        close(fd);
        return false;
    }
    // Copy the current contents (the runtime has already loaded the boot image).
    size_t done = 0;
    while (done < phys_ram_size) {
        ssize_t n = pwrite(fd, rdram + done, phys_ram_size - done, (off_t)done);
        if (n <= 0) {
            close(fd);
            return false;
        }
        done += (size_t)n;
    }
    void* p = mmap(rdram, phys_ram_size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED, fd, 0);
    if (p != (void*)rdram) {
        std::fprintf(stderr, "[southpark] failed to remap RDRAM as shared memory\n");
        close(fd);
        return false;
    }
    rdram_fd = fd;
    tlb_rdram = rdram;
    host_page_size = (size_t)sysconf(_SC_PAGESIZE);

    // Uncached KSEG1 view of RAM (0xA0000000 + phys): same pages, mapped again. Game
    // and libultra code sometimes address RAM this way; without the mirror those
    // accesses land in the runtime's inaccessible guard region and fault.
    uint64_t kseg1_off = host_offset(0xA0000000u);
    void* k1 = mmap(rdram + kseg1_off, phys_ram_size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED, fd, 0);
    if (k1 == MAP_FAILED) {
        std::fprintf(stderr, "[southpark] KSEG1 RAM mirror failed\n");
    }
    return true;
#endif
}

static void tlb_unmap_slot(int slot) {
    tlb_logical[slot] = {};
#if !defined(_WIN32)
    TlbEntry& e = tlb_pages[slot];
    if (!e.used) {
        return;
    }
    // Put the reserved, inaccessible mapping back.
    mmap(tlb_rdram + e.host_off, e.size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    e = {};
#else
    (void)slot;
#endif
}

static void tlb_map_page(int slot, uint32_t vaddr, uint32_t paddr, size_t size) {
#if !defined(_WIN32)
    tlb_unmap_slot(slot);
    if (paddr != 0xFFFFFFFFu && vaddr < 0x80000000u) {
        tlb_logical[slot] = { true, vaddr, paddr, (uint32_t)size };
    }
    if (paddr == 0xFFFFFFFFu || rdram_fd < 0) {
        return;
    }
    long host_page = sysconf(_SC_PAGESIZE);
    if ((vaddr % host_page) != 0 || (paddr % host_page) != 0 || (size % host_page) != 0) {
        std::fprintf(stderr, "[southpark] TLB page 0x%08X -> 0x%08X (0x%zX) not host-page aligned, skipped\n", vaddr, paddr, size);
        return;
    }
    if ((uint64_t)paddr + size > phys_ram_size) {
        if (paddr >= phys_ram_size) {
            return;
        }
        size = phys_ram_size - paddr;
    }
    if (vaddr >= 0x80000000u) {
        return; // KSEG0/1 are never TLB-mapped
    }
    uint64_t off = host_offset(vaddr);
    void* p = mmap(tlb_rdram + off, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED, rdram_fd, paddr);
    if (p == MAP_FAILED) {
        std::fprintf(stderr, "[southpark] TLB map 0x%08X -> 0x%08X failed\n", vaddr, paddr);
        return;
    }
    tlb_pages[slot] = { true, off, size };
#else
    (void)slot; (void)vaddr; (void)paddr; (void)size;
#endif
}

// Physical address for a virtual one: KSEG0/KSEG1 directly, KUSEG through the game's
// TLB mappings. Returns false if no mapping covers it (a demand-paged VM region, or
// unmapped), as the hardware TLB probe would.
static bool virtual_to_physical(uint32_t vaddr, uint32_t* paddr) {
    if (vaddr >= 0x80000000u && vaddr < 0xC0000000u) {
        *paddr = vaddr & 0x1FFFFFFFu;
        return true;
    }
    std::lock_guard lock{ tlb_mutex };
    for (const TlbLogical& e : tlb_logical) {
        if (e.valid && vaddr >= e.vaddr && vaddr - e.vaddr < e.size) {
            *paddr = e.paddr + (vaddr - e.vaddr);
            return true;
        }
    }
    return false;
}

// osVirtualToPhysical(void* vaddr): the runtime's version leaves TLB-mapped addresses
// unchanged ("TODO handle TLB mappings"), but this game's code and data live at
// 0x00200000 + phys and 0x00400000 -> 0x00780000, so a pointer it hands to the RSP/RDP
// came out as the wrong physical address. Translate through the game's TLB instead;
// an address no mapping covers gives -1, like the hardware TLB probe.
extern "C" void sp_osVirtualToPhysical(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    const uint32_t vaddr = (uint32_t)ctx->r4;
    uint32_t paddr = 0;
    if (!virtual_to_physical(vaddr, &paddr)) {
        static std::atomic<uint32_t> misses{0};
        const uint32_t n = misses.fetch_add(1);
        if (n < 16 || (n % 1000) == 0) {
            std::fprintf(stderr, "[southpark] osVirtualToPhysical(0x%08X): no TLB mapping, returning -1 (ra=0x%08X, #%u)\n",
                         vaddr, (uint32_t)ctx->r31, n + 1);
        }
        paddr = 0xFFFFFFFFu;
    } else if (vaddr < 0x80000000u) {
        static std::atomic<uint32_t> tlb_hits{0};
        if (tlb_hits.fetch_add(1) < 8) {
            std::fprintf(stderr, "[southpark] osVirtualToPhysical(0x%08X) -> 0x%08X via TLB (ra=0x%08X)\n",
                         vaddr, paddr, (uint32_t)ctx->r31);
        }
    }
    ctx->r2 = (gpr)(int32_t)paddr;
}

// osMapTLB(s32 index, OSPageMask pm, void* vaddr, u32 evenpaddr, u32 oddpaddr, s32 asid)
extern "C" void sp_osMapTLB(uint8_t* rdram, recomp_context* ctx) {
    int index = (int)(ctx->r4 & 31);
    uint32_t pm = (uint32_t)ctx->r5;
    uint32_t vaddr = (uint32_t)ctx->r6;
    uint32_t even = (uint32_t)ctx->r7;
    uint32_t odd = (uint32_t)MEM_W(0x10, ctx->r29);
    size_t page = (size_t)(((pm >> 13) & 0xFFF) + 1) * 0x1000;
    std::fprintf(stderr, "[southpark] osMapTLB idx=%d vaddr=0x%08X even=0x%08X odd=0x%08X page=0x%zX\n",
                 index, vaddr, even, odd, page);
    std::lock_guard lock{ tlb_mutex };
    tlb_map_page(index * 2, vaddr & ~(uint32_t)(page * 2 - 1), even, page);
    tlb_map_page(index * 2 + 1, (vaddr & ~(uint32_t)(page * 2 - 1)) + (uint32_t)page, odd, page);
}

extern "C" void sp_osUnmapTLB(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    int index = (int)(ctx->r4 & 31);
    std::lock_guard lock{ tlb_mutex };
    tlb_unmap_slot(index * 2);
    tlb_unmap_slot(index * 2 + 1);
}

extern "C" void sp_osUnmapTLBAll(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
    std::lock_guard lock{ tlb_mutex };
    for (int i = 0; i < 64; i++) {
        tlb_unmap_slot(i);
    }
}

// The mapping the boot stub sets up (index 31: 0x00200000 -> phys 0, 2 x 1 MB).
extern "C" void southpark_map_boot_tlb(uint8_t* rdram) {
    (void)rdram;
    std::lock_guard lock{ tlb_mutex };
    tlb_map_page(62, 0x00200000, 0x00000000, 0x100000);
    tlb_map_page(63, 0x00300000, 0x00100000, 0x100000);
}

// Called first thing from the SIGSEGV/SIGBUS handler with the faulting host address.
// If it is an unmapped page of one of the game's VM regions, map a host page there,
// fill it from ROM and return true: the faulting instruction then simply retries.
// Uses only raw syscalls and memory reads (no allocation, no mutex).
extern "C" bool southpark_tlb_handle_fault(uintptr_t host_addr) {
#if defined(_WIN32)
    (void)host_addr;
    return false;
#else
    uint8_t* rdram = tlb_rdram;
    if (rdram == nullptr || rdram_fd < 0) {
        return false;
    }
    const uintptr_t kuseg = reinterpret_cast<uintptr_t>(rdram) + host_offset(0);
    if (host_addr < kuseg || host_addr >= kuseg + (uintptr_t)vm_max_vpages * vm_page) {
        return false;
    }
    const uint32_t vaddr = (uint32_t)(host_addr - kuseg);
    const size_t hp = host_page_size;
    const uint32_t hp_vaddr = vaddr & ~(uint32_t)(hp - 1);
    const uint32_t first_vpage = hp_vaddr / vm_page;
    const uint32_t sub_pages = (uint32_t)(hp / vm_page);

    VmLock lock;
    uint32_t rom_addr = 0;
    if (vm_is_paged(vaddr / vm_page) || vm_find_region(rdram, vaddr / vm_page, &rom_addr) == 0) {
        return false; // not ours (or already mapped and faulting for another reason)
    }
    uint8_t* host = rdram + host_offset(hp_vaddr);
    void* p = mmap(host, hp, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    if (p == MAP_FAILED) {
        return false;
    }
    // A host page larger than 4 KB can span pages of neighbouring regions: fill each.
    for (uint32_t i = 0; i < sub_pages; i++) {
        uint32_t vp = first_vpage + i;
        if (vp < vm_max_vpages && vm_find_region(rdram, vp, &rom_addr) != 0) {
            vm_fill_page(host + (size_t)i * vm_page, rom_addr);
        }
        if (vp < vm_max_vpages) {
            vm_set_paged(vp, true);
        }
    }
    vm_pages_in.fetch_add(1, std::memory_order_relaxed);
    return true;
#endif
}

// Hook (southpark.us.toml [[patches.hook]]) in the VM manager when a region is created
// (func_00290FAC, node in $t0) or freed (func_00290EAC, node in $s0). Drops any pages
// paged in for that virtual range so a reused range refaults with the new ROM data.
extern "C" void southpark_vm_region_changed(uint8_t* rdram, uint32_t node, int freed) {
    gpr n = (gpr)(int32_t)node;
    uint32_t start = MEM_HU(0x4, n);
    uint32_t count = MEM_HU(0x6, n);
    uint32_t rom_addr = (uint32_t)MEM_W(0x8, n);
    uint32_t dropped = 0;
#if !defined(_WIN32)
    if (tlb_rdram != nullptr) {
        VmLock lock;
        const uint32_t sub_pages = (uint32_t)(host_page_size / vm_page);
        uint32_t vp = start - (start % sub_pages);
        for (; vp < start + count && vp < vm_max_vpages; vp += sub_pages) {
            bool any = false;
            for (uint32_t i = 0; i < sub_pages; i++) {
                any |= vm_is_paged(vp + i);
                vm_set_paged(vp + i, false);
            }
            if (any) {
                // Put the reserved, inaccessible mapping back.
                mmap(tlb_rdram + host_offset(vp * vm_page), host_page_size, PROT_NONE,
                     MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
                dropped++;
            }
        }
    }
#endif
    std::fprintf(stderr, "[southpark] VM region %s vaddr=0x%08X pages=0x%X rom=0x%08X (dropped %u, paged in %u so far)\n",
                 freed ? "freed" : "created", start * vm_page, count, rom_addr, dropped,
                 vm_pages_in.load(std::memory_order_relaxed));
}

// ---- Events and PI ----

// osSetEventMesg(OSEvent e, OSMesgQueue* mq, OSMesg msg)
extern "C" void osSetEventMesg_recomp(uint8_t* rdram, recomp_context* ctx);
extern "C" void sp_osSetEventMesg(uint8_t* rdram, recomp_context* ctx) {
    uint32_t event = (uint32_t)ctx->r4;
    {
        std::lock_guard lock{ event_mutex };
        if (event == EVENT_PI) { pi_mq = (int32_t)ctx->r5; pi_msg = (int32_t)ctx->r6; }
        if (event == EVENT_SI) { si_mq = (int32_t)ctx->r5; si_msg = (int32_t)ctx->r6; }
    }
    osSetEventMesg_recomp(rdram, ctx);
}

// osPiRawStartDma(s32 direction, u32 devAddr, void* dramAddr, u32 size)
extern "C" void sp_osPiRawStartDma(uint8_t* rdram, recomp_context* ctx) {
    uint32_t direction = (uint32_t)ctx->r4;
    uint32_t phys = cart_phys(rdram, (uint32_t)ctx->r5);
    gpr dram = ctx->r6;
    uint32_t size = (uint32_t)ctx->r7;

    uint32_t nth = dma_count.fetch_add(1);
    if (nth < 48 || (nth % 500) == 0) {
        std::fprintf(stderr, "[southpark] PI DMA #%u dir=%u rom=0x%08X -> 0x%08X size=0x%X\n",
                     nth, direction, phys, (uint32_t)dram, size);
    }
    if (direction == OS_READ) {
        std::span<const uint8_t> rom = recomp::get_rom();
        uint64_t off = (uint64_t)phys - recomp::rom_base;
        if (phys >= recomp::rom_base && off < rom.size()) {
            size_t n = (size_t)std::min<uint64_t>(size, rom.size() - off);
            for (size_t i = 0; i < n; i++) {
                MEM_B(i, dram) = (int8_t)rom[off + i];
            }
        } else {
            std::fprintf(stderr, "[southpark] PI DMA read from 0x%08X ignored\n", phys);
        }
    }
    int32_t mq, msg;
    {
        std::lock_guard lock{ event_mutex };
        mq = pi_mq; msg = pi_msg;
    }
    post_event(rdram, mq, msg);
    ctx->r2 = 0;
}

// osPiRawReadIo(u32 devAddr, u32* data)
extern "C" void osPiRawReadIo_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint32_t phys = cart_phys(rdram, (uint32_t)ctx->r4);
    MEM_W(0, ctx->r5) = (int32_t)rom_word(phys);
    ctx->r2 = 0;
}

// Streaming code's PI I/O helpers: write(u32* addr, u32 value), read(u32* addr).
extern "C" void sp_cart_io_write(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
}

extern "C" void sp_cart_io_read(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    uint32_t addr = (uint32_t)ctx->r4;
    uint32_t phys = addr & 0x1FFFFFFF;
    ctx->r2 = (gpr)(int32_t)rom_word(phys);
}

// ---- SI internals still called by recompiled code (Controller Pak / reset paths) ----
// Every command is answered with "no response", i.e. no accessory present.

extern "C" void __osSiGetAccess_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; (void)ctx; }
extern "C" void __osSiRelAccess_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; (void)ctx; }
extern "C" void __osSiDeviceBusy_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; ctx->r2 = 0; }
extern "C" void __osPackRequestData_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; (void)ctx; }
extern "C" void __osDpDeviceBusy_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; ctx->r2 = 0; }

// __osContGetInitData(u8* pattern, OSContStatus* data)
extern "C" void __osContGetInitData_recomp(uint8_t* rdram, recomp_context* ctx) {
    MEM_B(0, ctx->r4) = 0;
}

// __osSiRawStartDma(s32 direction, void* dramAddr): 64-byte PIF RAM transfer.
extern "C" void __osSiRawStartDma_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint32_t direction = (uint32_t)ctx->r4;
    gpr buf = ctx->r5;
    if (direction == OS_READ) {
        int i = 0;
        while (i < 63) {
            uint8_t tx = (uint8_t)MEM_BU(i, buf);
            if (tx == 0xFE) break;          // end of commands
            if (tx == 0xFF || tx == 0x00) { i++; continue; } // padding / skip channel
            uint8_t rx = (uint8_t)MEM_BU(i + 1, buf);
            MEM_B(i + 1, buf) = (int8_t)(rx | 0x80); // CONT_NO_RESPONSE_ERROR
            i += 2 + (tx & 0x3F) + (rx & 0x3F);
        }
        MEM_B(63, buf) = 0;
    }
    int32_t mq, msg;
    {
        std::lock_guard lock{ event_mutex };
        mq = si_mq; msg = si_msg;
    }
    post_event(rdram, mq, msg);
    ctx->r2 = 0;
}

extern "C" void __osSiRawReadIo_recomp(uint8_t* rdram, recomp_context* ctx) {
    MEM_W(0, ctx->r5) = 0;
    ctx->r2 = 0;
}

extern "C" void __osSiRawWriteIo_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; ctx->r2 = 0; }

// ---- Status register helpers ----
extern "C" void __osGetSR_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; ctx->r2 = cop0_status_read(ctx); }
// Only the FR bit is meaningful to the runtime; any other changed bit is fatal there.
extern "C" void __osSetSR_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    constexpr uint32_t SR_FR = 0x04000000;
    cop0_status_write(ctx, (gpr)((ctx->status_reg & ~SR_FR) | ((uint32_t)ctx->r4 & SR_FR)));
}

// ---- Internals that are only reachable from unused duplicate code ----
// (__osViSwapContext is already stubbed in unknown_symbols.cpp.)
#define SP_UNREACHABLE(name) \
    extern "C" void name##_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; (void)ctx; unreachable_internal(#name); }

SP_UNREACHABLE(__osDequeueThread)
SP_UNREACHABLE(__osDispatchThread)
SP_UNREACHABLE(__osEnqueueAndYield)
SP_UNREACHABLE(__osEnqueueThread)
SP_UNREACHABLE(__osPopThread)
SP_UNREACHABLE(__osInsertTimer)
SP_UNREACHABLE(__osSetTimerIntr)
SP_UNREACHABLE(__osSetCompare)
SP_UNREACHABLE(__osProbeTLB)

// osSetThreadPri(OSThread* t, OSPri pri)
//
// ultramodern's version removes t from its queue with thread_queue_remove(), whose loop
// never advances past the head: if t is not first, nothing is removed and the insert
// that follows links t in a second time, cutting off or looping the rest of the queue.
// The game raises and lowers other threads' priorities (func_0021F1A4, and the
// scheduler's thread at sc+0x1AB0 from func_00257E98 / func_002590F0), so threads can
// drop out of the run queue for good. Rebuild the queue instead, with the runtime's own
// pop/insert (which also reach the run queue, whose head the runtime keeps private).
extern "C" void sp_osSetThreadPri(uint8_t* rdram, recomp_context* ctx) {
    PTR(OSThread) t_ = (PTR(OSThread))ctx->r4;
    const OSPri pri = (OSPri)ctx->r5;
    if (t_ == NULLPTR) {
        t_ = ultramodern::this_thread();
    }
    OSThread* t = TO_PTR(OSThread, t_);
    if (t->priority == pri) {
        return;
    }
    const PTR(PTR(OSThread)) q = t->queue;
    if (t_ != ultramodern::this_thread() && t->state != OSThreadState::STOPPED && q != NULLPTR) {
        std::vector<PTR(OSThread)> rest;
        bool found = false;
        while (!ultramodern::thread_queue_empty(PASS_RDRAM q) && rest.size() < 256) {
            PTR(OSThread) x = ultramodern::thread_queue_pop(PASS_RDRAM q);
            if (x == t_) {
                found = true;
            } else {
                rest.push_back(x);
            }
        }
        // insert() goes in front of equal priorities, so put the others back last-first
        // to keep their order; then t, as the runtime's remove+insert intends.
        for (auto it = rest.rbegin(); it != rest.rend(); ++it) {
            ultramodern::thread_queue_insert(PASS_RDRAM q, *it);
        }
        t->priority = pri;
        if (found) {
            ultramodern::thread_queue_insert(PASS_RDRAM q, t_);
        } else {
            t->queue = q;   // not actually linked (e.g. running); keep its queue as it was
        }
    } else {
        t->priority = pri;
    }
    ultramodern::check_running_queue(PASS_RDRAM1);
}

// Hook (southpark.us.toml) at the start of the scheduler's __scHandleRSP (func_00258134,
// which = 0) and __scHandleRDP (func_00258618, which = 1). Both take sc->curRSPTask
// (sc+0x2F4) / sc->curRDPTask (sc+0x2F8) and dereference it unchecked. On hardware an
// RSP/RDP-done interrupt only comes for a running task; a done message with nothing
// running here crashed the scheduler (null+4). Skip it, and log the first few with the
// scheduler state so the source can be found. Returns 1 to skip the handler.
extern "C" int southpark_sched_guard(uint8_t* rdram, recomp_context* ctx, int which) {
    const gpr sc = ctx->r4;
    const uint32_t task = (uint32_t)MEM_W(which ? 0x2F8 : 0x2F4, sc);
    if (task != 0) {
        return 0;
    }
    static std::atomic<uint32_t> skipped[2]{};
    const uint32_t n = skipped[which].fetch_add(1);
    if (n < 8 || (n % 100) == 0) {
        std::fprintf(stderr, "[sched] %s done with no %s task (#%u): curRSP=0x%08X curRDP=0x%08X "
                     "audioQ=0x%08X gfxQ=0x%08X doAudio=%d\n",
                     which ? "RDP" : "RSP", which ? "RDP" : "RSP", n + 1,
                     (uint32_t)MEM_W(0x2F4, sc), (uint32_t)MEM_W(0x2F8, sc),
                     (uint32_t)MEM_W(0x2E4, sc), (uint32_t)MEM_W(0x2E8, sc), (int)MEM_W(0x300, sc));
    }
    return 1;
}

// Hook at the start of the scheduler's __scExec(sc, sp, dp) (func_00258F40): log the first
// task starts, flagging any that would replace an RSP/RDP task still marked as running.
// AI status read at 0x0029A700 (named osAiGetLength before; see libultra_names.json). The
// audio thread refills with `while (!(status & AI_STATUS_FIFO_FULL)) make_audio_frame();`
// (0x0026E50C), so it needs FIFO-full once enough is queued: the runtime's osAiGetLength
// never sets bit 31 and its osAiGetStatus always returns 0, so the game generated audio
// as fast as tasks completed (~40 frames per retrace: garbled sound). Report full once
// three of the game's own audio frames (samples per frame at 0x800E7762, 4 bytes each)
// are buffered: the hardware FIFO holds two, plus margin for the host audio thread.
extern "C" void sp_osAiGetStatus(uint8_t* rdram, recomp_context* ctx) {
    constexpr uint32_t AI_STATUS_FIFO_FULL = 0x80000000u;
    const uint32_t frame_samples = (uint32_t)MEM_HU(0x7762, (gpr)(int32_t)0x800E0000);
    const uint32_t frame_bytes = (frame_samples != 0 ? frame_samples : 0x200) * 4;
    static uint32_t logged_samples = 0xFFFFFFFFu;
    if (frame_samples != logged_samples) {
        logged_samples = frame_samples;
        std::fprintf(stderr, "[audio] game audio frame: %u samples\n", frame_samples);
    }
    const uint32_t buffered = ultramodern::get_remaining_audio_bytes();
    ctx->r2 = (gpr)(int32_t)((buffered >= 3 * frame_bytes) ? AI_STATUS_FIFO_FULL : 0);
}

// osViSwapBuffer(void* framebuffer): the runtime converts the pointer with its own
// TLB-unaware osVirtualToPhysical, so translate a TLB-mapped framebuffer first.
extern "C" void osViSwapBuffer_recomp(uint8_t* rdram, recomp_context* ctx);
extern "C" void sp_osViSwapBuffer(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t fb = (uint32_t)ctx->r4;
    uint32_t p = 0;
    static std::atomic<uint32_t> logged{0};
    const bool translated = fb < 0x80000000u && virtual_to_physical(fb, &p);
    if (translated) {
        ctx->r4 = (gpr)(int32_t)(p | 0x80000000u);
    }
    if (logged.fetch_add(1) < 4) {
        std::fprintf(stderr, "[southpark] osViSwapBuffer(0x%08X)%s\n", fb,
                     fb >= 0x80000000u ? "" : translated ? " -> TLB translated" : " (KUSEG, no TLB mapping)");
    }
    osViSwapBuffer_recomp(rdram, ctx);
}

// OSTask pointer fields, as offsets into OSTask (OSScTask + 0x10).
static constexpr uint32_t task_ptr_fields[] = { 0x08 /* ucode_boot */, 0x10 /* ucode */, 0x18 /* ucode_data */,
    0x20 /* dram_stack */, 0x28 /* output_buff */, 0x2C /* output_buff_size (a pointer) */,
    0x30 /* data_ptr */, 0x38 /* yield_data_ptr */ };

// libultra's osSpTaskLoad converts every task pointer with osVirtualToPhysical
// (_VirtualToPhysicalTask); the runtime's osSpTaskLoad does nothing and later just masks
// them, which is only right for KSEG0. Convert TLB-mapped (KUSEG) ones here, in place,
// before __scExec loads the task. The first graphics tasks are logged with their fields
// and the first words of the display list.
static void southpark_fix_task(uint8_t* rdram, uint32_t sc_task) {
    if (sc_task == 0) {
        return;
    }
    const gpr t = (gpr)(int32_t)(sc_task + 0x10);
    for (uint32_t off : task_ptr_fields) {
        const uint32_t v = (uint32_t)MEM_W(off, t);
        uint32_t p = 0;
        if (v != 0 && v < 0x80000000u) {
            if (virtual_to_physical(v, &p)) {
                MEM_W(off, t) = (int32_t)(p | 0x80000000u);   // KSEG0 form, as the runtime expects
            } else {
                static std::atomic<uint32_t> misses{0};
                if (misses.fetch_add(1) < 16) {
                    std::fprintf(stderr, "[sched] task 0x%08X field +0x%02X = 0x%08X has no TLB mapping\n", sc_task, off, v);
                }
            }
        }
    }
    const uint32_t type = (uint32_t)MEM_W(0x0, t);
    static std::atomic<uint32_t> gfx_logged{0};
    if (type == 1 && gfx_logged.fetch_add(1) < 3) {
        std::fprintf(stderr, "[sched] gfx task 0x%08X: ucode=0x%08X ucode_data=0x%08X dram_stack=0x%08X output_buff=0x%08X "
                     "data_ptr=0x%08X data_size=0x%X yield=0x%08X\n", sc_task,
                     (uint32_t)MEM_W(0x10, t), (uint32_t)MEM_W(0x18, t), (uint32_t)MEM_W(0x20, t), (uint32_t)MEM_W(0x28, t),
                     (uint32_t)MEM_W(0x30, t), (uint32_t)MEM_W(0x34, t), (uint32_t)MEM_W(0x38, t));
        const uint32_t dl = (uint32_t)MEM_W(0x30, t);
        if (dl >= 0x80000000u && dl < 0x80800000u) {
            const gpr d = (gpr)(int32_t)dl;
            std::fprintf(stderr, "[sched]   display list: %08X %08X  %08X %08X  %08X %08X  %08X %08X\n",
                         (uint32_t)MEM_W(0x00, d), (uint32_t)MEM_W(0x04, d), (uint32_t)MEM_W(0x08, d), (uint32_t)MEM_W(0x0C, d),
                         (uint32_t)MEM_W(0x10, d), (uint32_t)MEM_W(0x14, d), (uint32_t)MEM_W(0x18, d), (uint32_t)MEM_W(0x1C, d));
        }
    }
}

extern "C" void southpark_sched_trace(uint8_t* rdram, recomp_context* ctx) {
    southpark_fix_task(rdram, (uint32_t)ctx->r5);
    if ((uint32_t)ctx->r6 != (uint32_t)ctx->r5) {
        southpark_fix_task(rdram, (uint32_t)ctx->r6);
    }
    static std::atomic<uint32_t> calls{0};
    const uint32_t n = calls.fetch_add(1);
    const gpr sc = ctx->r4;
    const uint32_t sp = (uint32_t)ctx->r5, dp = (uint32_t)ctx->r6;
    const uint32_t cur_sp = (uint32_t)MEM_W(0x2F4, sc), cur_dp = (uint32_t)MEM_W(0x2F8, sc);
    const bool overlap = (sp != 0 && cur_sp != 0) || (dp != 0 && dp != sp && cur_dp != 0);
    if (n < 12 || overlap) {
        // OSScTask: list (OSTask) at +0x10, its type first.
        const int sp_type = sp ? (int)MEM_W(0x10, (gpr)(int32_t)sp) : -1;
        const int dp_type = dp ? (int)MEM_W(0x10, (gpr)(int32_t)dp) : -1;
        std::fprintf(stderr, "[sched] exec #%u sp=0x%08X(type %d) dp=0x%08X(type %d) curRSP=0x%08X curRDP=0x%08X%s\n",
                     n + 1, sp, sp_type, dp, dp_type, cur_sp, cur_dp, overlap ? "  <-- still running" : "");
    }
}

// For the session-log status lines (src/main/southpark_status.cpp).
extern "C" uint32_t southpark_dma_count() { return dma_count.load(std::memory_order_relaxed); }
extern "C" uint32_t southpark_vm_pages_in() { return vm_pages_in.load(std::memory_order_relaxed); }
