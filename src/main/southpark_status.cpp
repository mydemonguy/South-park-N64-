// Periodic status lines in the session log, for diagnosing a game that runs but shows
// nothing: how many graphics tasks, audio buffers, screen updates and PI DMAs have gone
// through, and what every game thread is doing (and, if blocked, on which message queue).
//
//   [status] 10s gfx=0 audio=0 screen=600 dma=812 vm_pages=37
//   [status]   [Game] 3 id=3 pri=10 BLOCKED recv mq=0x800E6FC0 (0/8 msgs)
//
// Lines go to stderr, which main.cpp forwards to the session log. Every 5 s for the
// first minute, then every 30 s.

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

namespace goemon64 {
    std::string get_game_thread_name(const OSThread* t);
}

namespace southpark::status {
    namespace {
        std::atomic<uint32_t> gfx_tasks{0};
        std::atomic<uint32_t> audio_buffers{0};
        std::atomic<uint32_t> screen_updates{0};
        std::atomic<uint8_t*> rdram_base{nullptr};

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

        void report(uint8_t* rdram, long seconds) {
            std::fprintf(stderr, "[status] %lds gfx=%u audio=%u screen=%u dma=%u vm_pages=%u\n",
                         seconds, gfx_tasks.load(), audio_buffers.load(), screen_updates.load(),
                         southpark_dma_count(), southpark_vm_pages_in());
            // Copy the list and name threads without holding the lock: the naming
            // callback registers threads itself (register_thread takes the lock).
            std::vector<const OSThread*> snapshot;
            {
                std::lock_guard lock{ threads_mutex };
                snapshot = threads;
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
    void count_audio_buffer() { audio_buffers.fetch_add(1, std::memory_order_relaxed); }
    void count_screen_update() { screen_updates.fetch_add(1, std::memory_order_relaxed); }

    // From get_game_thread_name(), which the runtime calls once for every game thread.
    void register_thread(const OSThread* t) {
        std::lock_guard lock{ threads_mutex };
        for (const OSThread* x : threads) {
            if (x == t) return;
        }
        threads.push_back(t);
    }

    // Call once from the game's entry point.
    void start(uint8_t* rdram) {
        if (rdram_base.exchange(rdram) != nullptr) {
            return;
        }
        std::thread([rdram]() {
            using namespace std::chrono;
            const auto t0 = steady_clock::now();
            long next = 5;
            while (!exited.load()) {
                std::this_thread::sleep_for(milliseconds(250));
                const long s = (long)duration_cast<seconds>(steady_clock::now() - t0).count();
                if (s < next) continue;
                if (exited.load()) break;
                report(rdram, s);
                next = s < 60 ? s + 5 : s + 30;
            }
        }).detach();
    }
}
