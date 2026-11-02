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
//   * sp_cart_io_read/write - PI I/O helpers used by the game's streaming code.
//   * Stand-ins for libultra internals that recompiled game code still calls (SI
//     access for Controller Pak / reset paths) and guards for internals that should
//     be unreachable.
//
// Function names here match tools/libultra_names.json and southpark.us.toml.

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <span>

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
    int rdram_fd = -1;
    uint8_t* tlb_rdram = nullptr;
    std::mutex tlb_mutex;
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
    return true;
#endif
}

static void tlb_unmap_slot(int slot) {
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

// osMapTLB(s32 index, OSPageMask pm, void* vaddr, u32 evenpaddr, u32 oddpaddr, s32 asid)
extern "C" void sp_osMapTLB(uint8_t* rdram, recomp_context* ctx) {
    int index = (int)(ctx->r4 & 31);
    uint32_t pm = (uint32_t)ctx->r5;
    uint32_t vaddr = (uint32_t)ctx->r6;
    uint32_t even = (uint32_t)ctx->r7;
    uint32_t odd = (uint32_t)MEM_W(0x10, ctx->r29);
    size_t page = (size_t)(((pm >> 13) & 0xFFF) + 1) * 0x1000;
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
extern "C" void __osSetSR_recomp(uint8_t* rdram, recomp_context* ctx) { (void)rdram; cop0_status_write(ctx, ctx->r4); }

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
