// Periodic status lines in the session log, for diagnosing a game that runs but shows
// nothing: how many graphics tasks, audio buffers, screen updates and PI DMAs have gone
// through, and what every game thread is doing (and, if blocked, on which message queue).
//
//   [status] 10s gfx=0 audio=0 screen=600 dma=812 vm_pages=37
//   [status]   [Game] 3 id=3 pri=10 BLOCKED recv mq=0x800E6FC0 (0/8 msgs)
//
// Lines go to stderr, which main.cpp forwards to the session log. At 2 s and 5 s, every
// 5 s to the first minute, then every 30 s; plus a snapshot on quit and backgrounding.
// Thread lines are added to the first report, snapshots, and reports where graphics stalled.

#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include "ultramodern/ultramodern.hpp"

extern std::atomic_bool exited;   // librecomp (recomp.cpp)
extern "C" uint32_t southpark_dma_count();
extern "C" uint32_t southpark_vm_pages_in();
extern "C" void southpark_renderer_timings(char* out, size_t size);
#if defined(__ANDROID__)
std::string southpark_android_thread_report(long seconds);
#endif

namespace goemon64 {
    std::string get_game_thread_name(const OSThread* t);
}

void southpark_bot_summary();     // src/game/southpark_bot.cpp

namespace southpark::status {
    namespace {
        std::atomic<uint32_t> gfx_tasks{0};
        std::atomic<uint32_t> audio_buffers{0};
        std::atomic<uint64_t> audio_frames{0};     // stereo sample pairs queued
        std::atomic<uint32_t> screen_updates{0};
        std::atomic<uint8_t*> rdram_base{nullptr};
        std::chrono::steady_clock::time_point start_time;

        std::mutex threads_mutex;
        std::vector<const OSThread*> threads;   // host pointers into RDRAM

        const char* state_name(uint16_t s) {
            switch (s) {
            case STOPPED: return "STOPPED";
            case QUEUED:  return "QUEUED";
            case RUNNING: return "RUNNING";
            case BLOCKED: return "BLOCKED";
            default:      return "?";
            }
        }

        // The Adreno GPU's current clock and load, where the kernel lets an app read
        // them (many phones do not). Phone GPUs clock down when they look idle, and
        // RT64 leaves the GPU idle between frames while it waits, so a frame can be
        // slow because the clock is low rather than because the work is large.
        std::string gpu_clock_text() {
#if defined(__ANDROID__)
            static bool readable = true;
            if (!readable) {
                return "";
            }
            auto read_first_number = [](const char* path, long long& out) {
                FILE* f = std::fopen(path, "r");
                if (f == nullptr) {
                    return false;
                }
                const bool ok = std::fscanf(f, "%lld", &out) == 1;
                std::fclose(f);
                return ok;
            };
            long long clock = 0, busy = 0, max_clock = 0;
            const bool have_clock = read_first_number("/sys/class/kgsl/kgsl-3d0/gpuclk", clock);
            const bool have_busy = read_first_number("/sys/class/kgsl/kgsl-3d0/gpu_busy_percentage", busy);
            read_first_number("/sys/class/kgsl/kgsl-3d0/max_gpuclk", max_clock);
            if (!have_clock && !have_busy) {
                readable = false;
                return ", gpu clock not readable on this phone";
            }
            char text[96];
            std::snprintf(text, sizeof(text), ", gpu clock %lld of %lld MHz, gpu busy %lld%%",
                clock / 1000000, max_clock / 1000000, busy);
            return text;
#else
            return "";
#endif
        }

        // Where the game keeps its 4:3 constants, for the widescreen work: South Park PC's
        // field-of-view hack edits a single 4/3 float, and the N64 game's projection and
        // view culling most likely read the same kind of constant. Logged once, a few
        // seconds in (the code and its constants are loaded by then); the addresses are
        // matched against the game's float loads offline.
        std::string aspect_text;

        void log_aspect_constants(uint8_t* rdram) {
            struct Wanted { uint32_t bits; const char* name; };
            static const Wanted wanted[] = {
                { 0x3FAAAAABu, "4/3" }, { 0x3FAAAAAAu, "4/3 (low)" }, { 0x3F400000u, "3/4" },
                { 0x3FE38E39u, "16/9" }, { 0x3F100000u, "9/16" },
            };
            for (const Wanted& w : wanted) {
                std::string line;
                int count = 0;
                // KSEG0 code and data, where the game's constants live (0x80000000-0x80400000).
                for (uint32_t off = 0; off < 0x400000; off += 4) {
                    if (*reinterpret_cast<const uint32_t*>(rdram + off) == w.bits) {
                        if (count < 24) {
                            char item[16];
                            std::snprintf(item, sizeof(item), " %08X", 0x80000000u + off);
                            line += item;
                        }
                        count++;
                    }
                }
                char head[64];
                std::snprintf(head, sizeof(head), "[aspect] %s (%08X): %d found", w.name, w.bits, count);
                aspect_text += head + line + "\n";
            }
        }

        void report(uint8_t* rdram, long seconds, bool with_threads) {
            const uint64_t frames = audio_frames.load();
            static bool aspect_logged = false;
            if (!aspect_logged && seconds >= 20 && rdram != nullptr) {
                aspect_logged = true;
                log_aspect_constants(rdram);
            }
            // Repeated with every thread snapshot (backgrounding, quitting), which lands
            // in the part of the log that survives sharing.
            if (!aspect_text.empty() && (with_threads || seconds < 25)) {
                std::fputs(aspect_text.c_str(), stderr);
            }
            std::fprintf(stderr, "[status] %lds gfx=%u audio=%u (%llu Hz avg) screen=%u dma=%u vm_pages=%u\n",
                         seconds, gfx_tasks.load(), audio_buffers.load(),
                         (unsigned long long)(seconds > 0 ? frames / (uint64_t)seconds : 0), screen_updates.load(),
                         southpark_dma_count(), southpark_vm_pages_in());
            // Speed over the last interval, from the sound the game produced: a game
            // running slow makes less of it per second. Separates "the emulation is
            // behind" from "the game itself draws at 20 fps here", which looks the same
            // in the frame interval.
            {
                static uint64_t last_frames = 0;
                static long last_seconds = 0;
                if (seconds > last_seconds) {
                    const double hz = double(frames - last_frames) / double(seconds - last_seconds);
                    std::fprintf(stderr, "[status]   audio now %.0f Hz%s\n", hz, gpu_clock_text().c_str());
                }
                last_frames = frames;
                last_seconds = seconds;
            }
            char timings[1024];
            southpark_renderer_timings(timings, sizeof(timings));
            if (timings[0] != '\0') {
                std::fprintf(stderr, "[perf] %s\n", timings);
            }
#if defined(__ANDROID__)
            {
                const std::string cpu = southpark_android_thread_report(seconds);
                if (!cpu.empty()) {
                    std::fputs(cpu.c_str(), stderr);
                }
            }
#endif
            // Copy the list and name threads without holding the lock: the naming
            // callback registers threads itself (register_thread takes the lock).
            std::vector<const OSThread*> snapshot;
            {
                std::lock_guard lock{ threads_mutex };
                snapshot = threads;
            }
            if (!with_threads) {
                return;
            }
            for (const OSThread* t : snapshot) {
                std::string name = goemon64::get_game_thread_name(t);
                const uint32_t addr = (uint32_t)((const uint8_t*)t - rdram) + 0x80000000u;
                if (t->context == nullptr && t->state == STOPPED) {
                    std::fprintf(stderr, "[status]   %s @0x%08X id=%d pri=%d STOPPED/destroyed\n",
                                 name.c_str(), addr, (int)t->id, (int)t->priority);
                    continue;
                }
                const int32_t q = t->queue;
                if (t->state == BLOCKED && q != 0 && q != ultramodern::running_queue &&
                    (uint32_t)q >= 0x80000000u && (uint32_t)q < 0x80800000u) {
                    // The thread sits in mq->blocked_on_recv (offset 0) or blocked_on_send (4).
                    const bool send = (q & 4) != 0;
                    const int32_t mq_addr = send ? q - 4 : q;
                    const OSMesgQueue* mq = TO_PTR(OSMesgQueue, mq_addr);
                    std::fprintf(stderr, "[status]   %s @0x%08X id=%d pri=%d BLOCKED %s mq=0x%08X (%d/%d msgs)\n",
                                 name.c_str(), addr, (int)t->id, (int)t->priority, send ? "send" : "recv",
                                 (uint32_t)mq_addr, (int)mq->validCount, (int)mq->msgCount);
                } else {
                    std::fprintf(stderr, "[status]   %s @0x%08X id=%d pri=%d %s%s\n",
                                 name.c_str(), addr, (int)t->id, (int)t->priority, state_name(t->state),
                                 q == ultramodern::running_queue ? " (run queue)" : "");
                }
            }
        }
    }

    void count_gfx_task() { gfx_tasks.fetch_add(1, std::memory_order_relaxed); }
    void count_audio_buffer(size_t samples) {
        audio_buffers.fetch_add(1, std::memory_order_relaxed);
        audio_frames.fetch_add(samples / 2, std::memory_order_relaxed);   // 2 channels
    }
    void count_screen_update() { screen_updates.fetch_add(1, std::memory_order_relaxed); }

    // From get_game_thread_name(), which the runtime calls once for every game thread.
    void register_thread(const OSThread* t) {
        std::lock_guard lock{ threads_mutex };
        for (const OSThread* x : threads) {
            if (x == t) return;
        }
        threads.push_back(t);
    }

    // An immediate report (on quit / backgrounding), so a short run still shows threads.
    void report_now(const char* why) {
        uint8_t* rdram = rdram_base.load();
        if (rdram == nullptr || exited.load()) {
            return;
        }
        std::fprintf(stderr, "[status] snapshot: %s\n", why);
        southpark_bot_summary();
        report(rdram, (long)std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start_time).count(), true);
    }

    // Call once from the game's entry point.
    void start(uint8_t* rdram) {
        start_time = std::chrono::steady_clock::now();
        if (rdram_base.exchange(rdram) != nullptr) {
            return;
        }
        std::thread([rdram]() {
            using namespace std::chrono;
            const auto t0 = start_time;
            long next = 2;
            while (!exited.load()) {
                std::this_thread::sleep_for(milliseconds(250));
                const long s = (long)duration_cast<seconds>(steady_clock::now() - t0).count();
                if (s < next) continue;
                if (exited.load()) break;
                // Thread lines only on the first report and when graphics stopped advancing
                // (the case they help with); otherwise they crowd the log out.
                static uint32_t last_gfx = UINT32_MAX;
                const uint32_t gfx = gfx_tasks.load();
                report(rdram, s, last_gfx == UINT32_MAX || gfx == last_gfx);
                last_gfx = gfx;
                next = s < 5 ? 5 : s < 60 ? s + 5 : s + 30;
            }
        }).detach();
    }
}
