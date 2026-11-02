// Differential test: run recompiled South Park functions with fixed pseudo-random
// inputs and print a hash of the resulting CPU state and memory. Build for x86-64 and
// ARM64 and diff the output.
#define _GNU_SOURCE
#include <setjmp.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "sp_recomp.h"
#include "leaf_list.h"   // generated: LEAF_FUNCS(X) and declarations

#define RAM_WINDOW   (0x100000000ull + 0x10000)  // any sign-extended 32-bit address fits
#define HASH_BYTES   0x800000                    // hash the 8 MB of real RDRAM

static sigjmp_buf escape;
static volatile int escape_reason;

static void bail(int reason) { escape_reason = reason; siglongjmp(escape, 1); }
static void on_segv(int sig) { (void)sig; bail(1); }

// Runtime hooks. Leaf functions should never reach these; if they do, stop the run
// the same way on every architecture.
void cop0_status_write(recomp_context* ctx, gpr value) { ctx->status_reg = (uint32_t)value; }
gpr cop0_status_read(recomp_context* ctx) { return ctx->status_reg; }
void switch_error(const char* func, uint32_t vram, uint32_t jtbl) { (void)func; (void)vram; (void)jtbl; bail(2); }
void do_break(uint32_t vram) { (void)vram; bail(3); }
void pause_self(uint8_t* rdram) { (void)rdram; bail(4); }
static void bad_call(uint8_t* rdram, recomp_context* ctx) { (void)rdram; (void)ctx; bail(5); }
recomp_func_t* get_function(int32_t vram) { (void)vram; return bad_call; }

static uint64_t rng;
static uint64_t next(void) { rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17; return rng; }

static uint64_t fnv(const void* p, size_t n, uint64_t h) {
    const uint8_t* b = p;
    for (size_t i = 0; i < n; i++) { h ^= b[i]; h *= 0x100000001b3ull; }
    return h;
}

static gpr pick_reg(void) {
    switch (next() % 4) {
        case 0: return next() % 256;                                          // small int
        case 1: return (gpr)(int32_t)(0x80000000u + (next() % 0x700000 & ~7u)); // RDRAM pointer
        case 2: return (gpr)(int32_t)(uint32_t)next();                         // any 32-bit value
        default: return (gpr)(int32_t)(next() % 2 ? 1 : -1);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) { fprintf(stderr, "usage: harness <rom.z64> [seeds]\n"); return 1; }
    int seeds = argc > 2 ? atoi(argv[2]) : 8;
    int clean = argc > 3 && strcmp(argv[3], "clean") == 0;  // finite floats only

    uint8_t* rdram = mmap(NULL, RAM_WINDOW, PROT_READ | PROT_WRITE,
                          MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
    if (rdram == MAP_FAILED) { perror("mmap"); return 1; }

    // Real game data: the 1 MB boot image goes to 0x80000400, stored the way the
    // runtime stores RDRAM (32-bit words in host order).
    FILE* f = fopen(argv[1], "rb");
    if (!f) { perror("rom"); return 1; }
    static uint8_t boot[0x100000];
    fseek(f, 0x1000, SEEK_SET);
    if (fread(boot, 1, sizeof boot, f) != sizeof boot) { fprintf(stderr, "short rom\n"); return 1; }
    fclose(f);
    static uint8_t image[HASH_BYTES];
    memset(image, 0, sizeof image);
    for (size_t i = 0; i < sizeof boot; i += 4) {
        uint32_t w = ((uint32_t)boot[i] << 24) | (boot[i+1] << 16) | (boot[i+2] << 8) | boot[i+3];
        memcpy(image + 0x400 + i, &w, 4);
    }

    memcpy(rdram, image, sizeof image);

    struct sigaction sa = {0};
    sa.sa_handler = on_segv;
    sa.sa_flags = SA_NODEFER;
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGBUS, &sa, NULL);

    struct { const char* name; recomp_func_t* fn; } funcs[] = {
#define X(name) { #name, name },
        LEAF_FUNCS(X)
#undef X
    };

    const char* only = argc > 4 ? argv[4] : NULL;
    for (size_t fi = 0; fi < sizeof funcs / sizeof funcs[0]; fi++) {
        if (only && strcmp(only, funcs[fi].name) != 0) continue;
        uint64_t h = 0xcbf29ce484222325ull;
        for (int s = 0; s < seeds; s++) {
            rng = 0x9E3779B97F4A7C15ull ^ ((uint64_t)fi << 20) ^ (uint64_t)s;
            recomp_context ctx;
            memset(&ctx, 0, sizeof ctx);
            gpr* r = &ctx.r0;
            for (int i = 1; i < 32; i++) r[i] = pick_reg();
            ctx.r29 = (gpr)(int32_t)0x803F0000;   // stack pointer inside RDRAM
            for (int i = 0; i < 32; i++) {
                fpr* fr = &ctx.f0 + i;
                switch (next() % (clean ? 2 : 3)) {
                    case 0: fr->fl = (float)((int32_t)(next() % 2001) - 1000) / 7.0f; break;
                    case 1: fr->d = (double)((int64_t)(next() % 200001) - 100000) / 13.0; break;
                    default: fr->u64 = next(); break;
                }
            }
            ctx.f_odd = &ctx.f0.u32h;
            ctx.mips3_float_mode = 1;   // the game runs with Status.FR = 1

            escape_reason = 0;
            if (sigsetjmp(escape, 1) == 0) {
                funcs[fi].fn(rdram, &ctx);
            }
            if (only) {
                printf("seed %d reason %d\n", s, escape_reason);
                for (int i = 0; i < 32; i++) printf(" r%d=%016llx", i, (unsigned long long)r[i]);
                printf("\n");
                for (int i = 0; i < 32; i++) printf(" f%d=%016llx", i, (unsigned long long)(&ctx.f0 + i)->u64);
                printf("\n hi=%llx lo=%llx\n", (unsigned long long)ctx.hi, (unsigned long long)ctx.lo);
            }
            h = fnv(&escape_reason, sizeof escape_reason, h);
            h = fnv(&ctx.r0, 32 * sizeof(gpr), h);
            h = fnv(&ctx.f0, 32 * sizeof(fpr), h);
            h = fnv(&ctx.hi, 2 * sizeof(uint64_t), h);
            // Hash the 4 KB blocks the function changed in RDRAM and in the TLB-mapped
            // window (virtual 0x00000000-0x007FFFFF), then reset all other memory.
            for (size_t off = 0x80000000; off < 0x80000000 + HASH_BYTES; off += 0x1000) {
                static const uint8_t zero[0x1000];
                if (memcmp(rdram + off, zero, 0x1000) != 0) {
                    h = fnv(&off, sizeof off, h);
                    h = fnv(rdram + off, 0x1000, h);
                }
            }
            if (mmap(rdram + HASH_BYTES, RAM_WINDOW - HASH_BYTES, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE | MAP_FIXED, -1, 0) == MAP_FAILED) {
                perror("remap"); return 1;
            }
            for (size_t off = 0; off < HASH_BYTES; off += 0x1000) {
                if (memcmp(rdram + off, image + off, 0x1000) != 0) {
                    if (only) for (size_t w = off; w < off + 0x1000; w += 4)
                        if (memcmp(rdram + w, image + w, 4)) printf(" mem[%08zx]=%08x\n", w + 0x80000000, *(uint32_t*)(rdram + w));
                    h = fnv(&off, sizeof off, h);
                    h = fnv(rdram + off, 0x1000, h);
                    memcpy(rdram + off, image + off, 0x1000);
                }
            }
        }
        printf("%s %016llx\n", funcs[fi].name, (unsigned long long)h);
    }
    return 0;
}
