// Android crash diagnostics + lifecycle observability.
//
// RETAINED PERMANENTLY (not investigation scaffolding). Originally added to
// root-cause the background/resume audio-DSP SIGSEGV (Bug 6), it proved its
// worth and stays as a standing asset: any future fault on a new GPU / OS /
// lifecycle edge is classified instantly instead of needing a fresh repro.
//
// Installs an SA_SIGINFO handler for SIGSEGV/SIGBUS that, before chaining to
// the previously-installed handler (so the normal Android tombstone still
// prints), logs:
//   - the faulting address
//   - the RDRAM base and, if the fault is inside the 4 GB RDRAM reservation,
//     the N64-space offset + whether it is past the 512 MB committed guard
//     boundary (i.e. an out-of-bounds recompiled pointer -- how the Bug-6
//     audio fault was classified: a corrupted N64 pointer, not unmapped memory)
//   - the faulting thread name
//   - the current app lifecycle phase (foreground / backgrounded / resuming)
//
// set_phase() is also the lifecycle-transition log the pause gate relies on for
// observability (see input.cpp's SDL_APP_* handlers); it is load-bearing for
// diagnosability, not debug-only. The handler is cheap and __ANDROID__-guarded.

#if defined(__ANDROID__)

#include <atomic>
#include <cstdarg>
#include <csignal>
#include <cstdint>
#include <cerrno>
#include <cstring>
#include <ctime>

#include <android/log.h>
#include <dlfcn.h>
#include <ucontext.h>
#include <unwind.h>
#include <cstdio>
#include <pthread.h>
#include <unistd.h>

#include "librecomp/addresses.hpp"

#define DIAG_TAG "Goemon64-diag"
#define DIAGE(...) __android_log_print(ANDROID_LOG_ERROR, DIAG_TAG, __VA_ARGS__)
#define DIAGI(...) __android_log_print(ANDROID_LOG_INFO,  DIAG_TAG, __VA_ARGS__)

namespace southpark::crashlog {
    void write_raw(const char* data, size_t n);
}

// Game demand paging (src/game/southpark_os.cpp): a TLB miss on one of the game's VM
// regions arrives here as SIGSEGV and is serviced before anything is reported.
extern "C" bool southpark_tlb_handle_fault(uintptr_t host_addr);

// librecomp's shutdown flag (recomp.cpp). Once it is set, recomp::start() joins its
// helper threads and munmaps RDRAM, but the N64 game threads are not stopped first: one
// that is still running faults on its next RAM access. That is not a crash worth a
// report; see crash_handler().
extern std::atomic_bool exited;

namespace goemon64::diag {

    // App lifecycle phase, set from the SDL event pump (main thread) and read
    // from the (async-signal) crash handler. Plain int is lock-free and
    // async-signal-safe to read.
    enum Phase : int { Foreground = 0, Background = 1, Resuming = 2 };
    static std::atomic<int> g_phase{Foreground};

    // RDRAM base, published once the runtime has allocated it. Read in the
    // signal handler to compute the N64-space offset of a fault.
    static std::atomic<uintptr_t> g_rdram_base{0};

    void set_phase(int phase) {
        g_phase.store(phase, std::memory_order_relaxed);
        DIAGI("lifecycle phase -> %s",
              phase == Foreground ? "FOREGROUND" :
              phase == Background ? "BACKGROUND" : "RESUMING");
    }

    void set_rdram_base(const void* base) {
        g_rdram_base.store(reinterpret_cast<uintptr_t>(base), std::memory_order_relaxed);
        DIAGI("rdram base registered = %p (committed guard boundary at +0x%zx, reservation ends +0x%zx)",
              base, static_cast<size_t>(recomp::mem_size), static_cast<size_t>(recomp::allocation_size));
    }

    namespace {
        // Crash report into the session log (see southpark_crashlog.cpp), so it can be
        // read on the device without adb. snprintf/dladdr aren't strictly
        // async-signal-safe, but the process is dying anyway.
        void report(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
        void report(const char* fmt, ...) {
            char buf[512];
            va_list ap;
            va_start(ap, fmt);
            int n = vsnprintf(buf, sizeof(buf) - 1, fmt, ap);
            va_end(ap);
            if (n < 0) return;
            if (n > (int)sizeof(buf) - 2) n = sizeof(buf) - 2;
            buf[n++] = '\n';
            southpark::crashlog::write_raw(buf, (size_t)n);
        }

        void report_symbol(const char* label, uintptr_t pc) {
            Dl_info info{};
            if (pc != 0 && dladdr(reinterpret_cast<void*>(pc), &info) && info.dli_fname) {
                const char* lib = strrchr(info.dli_fname, '/');
                lib = lib ? lib + 1 : info.dli_fname;
                if (info.dli_sname) {
                    report("  %s %s+0x%zx (%s)", label, info.dli_sname,
                           static_cast<size_t>(pc - reinterpret_cast<uintptr_t>(info.dli_saddr)), lib);
                } else {
                    report("  %s %s+0x%zx", label, lib,
                           static_cast<size_t>(pc - reinterpret_cast<uintptr_t>(info.dli_fbase)));
                }
            } else {
                report("  %s 0x%zx", label, static_cast<size_t>(pc));
            }
        }

        struct BacktraceState { int count; };
        _Unwind_Reason_Code backtrace_frame(struct _Unwind_Context* uc, void* arg) {
            auto* st = static_cast<BacktraceState*>(arg);
            uintptr_t pc = _Unwind_GetIP(uc);
            if (pc != 0) {
                char label[16];
                snprintf(label, sizeof(label), "#%02d", st->count);
                report_symbol(label, pc);
            }
            return ++st->count >= 32 ? _URC_END_OF_STACK : _URC_NO_REASON;
        }
    }

    namespace {
        struct sigaction g_prev_segv{};
        struct sigaction g_prev_bus{};
        struct sigaction g_prev_abrt{};
        struct sigaction g_prev_ill{};
        struct sigaction g_prev_fpe{};
        std::atomic<bool> g_installed{false};

        void crash_handler(int sig, siginfo_t* info, void* ucontext) {
            const uintptr_t fault = reinterpret_cast<uintptr_t>(info ? info->si_addr : nullptr);
            if ((sig == SIGSEGV || sig == SIGBUS) && southpark_tlb_handle_fault(fault)) {
                return; // page mapped; the faulting instruction retries
            }
            const uintptr_t base = g_rdram_base.load(std::memory_order_relaxed);
            if ((sig == SIGSEGV || sig == SIGBUS) && exited.load(std::memory_order_relaxed) &&
                base != 0 && fault >= base && fault < base + recomp::allocation_size) {
                // Shutdown race (see `exited` above): RDRAM is already freed. Saves were
                // flushed before that, so park this thread and let the exit finish; if it
                // hasn't within 3 s, end the process quietly.
                static const char msg[] = "[session] game thread touched RAM after shutdown began (ignored)\n";
                southpark::crashlog::write_raw(msg, sizeof(msg) - 1);
                struct timespec ts{3, 0};
                while (nanosleep(&ts, &ts) == -1 && errno == EINTR) {}
                _exit(0);
            }
            const int phase = g_phase.load(std::memory_order_relaxed);

            char tname[32] = {0};
            pthread_getname_np(pthread_self(), tname, sizeof(tname));

            DIAGE("==== SIGNAL %d (%s) fault_addr=0x%zx thread='%s' phase=%s ====",
                  sig, sig == SIGSEGV ? "SIGSEGV" : sig == SIGBUS ? "SIGBUS" : "?",
                  static_cast<size_t>(fault), tname,
                  phase == Foreground ? "FOREGROUND" :
                  phase == Background ? "BACKGROUND" : "RESUMING");

            report("==== CRASH: signal %d (%s) fault_addr=0x%zx thread='%s' ====",
                   sig, sig == SIGSEGV ? "SIGSEGV" : sig == SIGBUS ? "SIGBUS" :
                        sig == SIGABRT ? "SIGABRT" : sig == SIGILL ? "SIGILL" : sig == SIGFPE ? "SIGFPE" : "?",
                   static_cast<size_t>(fault), tname);
            if (base != 0 && fault >= base && fault < base + recomp::allocation_size) {
                const uintptr_t off = fault - base;
                // RDRAM offset -> N64 address (offsets past 2 GB are positive KUSEG/TLB addresses).
                const uint32_t n64 = off < 0x80000000ull ? static_cast<uint32_t>(0x80000000u + off)
                                                         : static_cast<uint32_t>(off - 0x80000000ull);
                report("  N64 address 0x%08X (rdram offset 0x%zx)", n64, static_cast<size_t>(off));
            }
#if defined(__aarch64__)
            if (ucontext) {
                const auto* uc = static_cast<const ucontext_t*>(ucontext);
                report_symbol("pc", static_cast<uintptr_t>(uc->uc_mcontext.pc));
                report_symbol("lr", static_cast<uintptr_t>(uc->uc_mcontext.regs[30]));
            }
#endif
            {
                BacktraceState st{0};
                _Unwind_Backtrace(backtrace_frame, &st);
            }
            report("==== end of crash report ====");

            if (base != 0 && fault >= base && fault < base + recomp::allocation_size) {
                const uintptr_t off = fault - base;
                const bool past_guard = off >= recomp::mem_size;
                DIAGE("  fault is INSIDE rdram reservation: n64_offset=0x%zx %s",
                      static_cast<size_t>(off),
                      past_guard ? "-> PAST 512MB COMMITTED GUARD (out-of-bounds recompiled pointer)"
                                 : "-> within committed 512MB (unexpected: valid region faulted)");
            } else if (base != 0) {
                DIAGE("  fault is OUTSIDE rdram reservation (base=0x%zx). Not an RDRAM-offset fault.",
                      static_cast<size_t>(base));
            } else {
                DIAGE("  rdram base not yet registered; cannot classify fault.");
            }

            // Chain to the previously-installed handler so the normal Android
            // tombstone/debuggerd path still runs.
            const struct sigaction& prev = (sig == SIGBUS) ? g_prev_bus :
                                           (sig == SIGABRT) ? g_prev_abrt :
                                           (sig == SIGILL) ? g_prev_ill :
                                           (sig == SIGFPE) ? g_prev_fpe : g_prev_segv;
            if (prev.sa_flags & SA_SIGINFO) {
                if (prev.sa_sigaction) {
                    prev.sa_sigaction(sig, info, ucontext);
                    return;
                }
            } else if (prev.sa_handler == SIG_IGN) {
                return;
            } else if (prev.sa_handler && prev.sa_handler != SIG_DFL) {
                prev.sa_handler(sig);
                return;
            }
            // Fall back to default disposition.
            signal(sig, SIG_DFL);
            raise(sig);
        }
    } // namespace

    void install_crash_handler() {
        if (g_installed.exchange(true)) {
            return;
        }
        struct sigaction sa{};
        sa.sa_sigaction = &crash_handler;
        sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
        sigemptyset(&sa.sa_mask);
        sigaction(SIGSEGV, &sa, &g_prev_segv);
        sigaction(SIGBUS, &sa, &g_prev_bus);
        sigaction(SIGABRT, &sa, &g_prev_abrt);
        sigaction(SIGILL, &sa, &g_prev_ill);
        sigaction(SIGFPE, &sa, &g_prev_fpe);
        DIAGI("crash diagnostics handler installed");
    }

} // namespace goemon64::diag

#endif // __ANDROID__
