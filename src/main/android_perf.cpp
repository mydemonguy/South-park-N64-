// CPU-side performance help for Android: where the busy threads run, and a
// performance hint session that tells the OS what frame time they have to meet.
//
// Why: on the Adreno 710 phone the game fell 13-18% behind (by the sound it produced)
// in scenes where the GPU needed only 17-20 ms of a 33 ms frame, and the display-list
// parse -- about a thousand commands, which a big core does in about a millisecond --
// took 11-15 ms. That points at the CPU threads running on slow cores or at low
// clocks. Android picks cores and clocks from how busy a thread looks, and this
// renderer's threads spend much of each frame waiting on one another, so they look
// lighter than they are.
//
// The status report prints the busiest threads with the core each last ran on, and
// once they are known (a few seconds in) they are put in an APerformanceHint session
// with the game's frame time as the target. Each displayed frame then reports how long
// it took, and the OS raises clocks or moves the threads to faster cores when frames run
// late. APerformanceHint needs Android 13; it is looked up at run time so the app still
// installs on Android 9.

#include <dirent.h>
#include <dlfcn.h>
#include <unistd.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>

namespace {
    struct ThreadSample {
        std::string name;
        unsigned long long ticks = 0;
        int cpu = -1;
    };

    // Per-core top frequency in kHz, read once, so a core can be named little/big.
    std::vector<long> core_max_khz;

    long read_long(const char* path) {
        FILE* f = std::fopen(path, "r");
        if (f == nullptr) {
            return -1;
        }
        long v = -1;
        if (std::fscanf(f, "%ld", &v) != 1) {
            v = -1;
        }
        std::fclose(f);
        return v;
    }

    void load_cores() {
        if (!core_max_khz.empty()) {
            return;
        }
        for (int i = 0; i < 16; i++) {
            char path[96];
            std::snprintf(path, sizeof(path), "/sys/devices/system/cpu/cpu%d/cpufreq/cpuinfo_max_freq", i);
            long khz = read_long(path);
            if (khz < 0 && i >= 8) {
                break;
            }
            core_max_khz.push_back(khz);
        }
    }

    const char* core_class(int cpu) {
        if (cpu < 0 || cpu >= int(core_max_khz.size()) || core_max_khz[cpu] <= 0) {
            return "?";
        }
        long lo = 0, hi = 0;
        for (long k : core_max_khz) {
            if (k <= 0) continue;
            lo = (lo == 0) ? k : std::min(lo, k);
            hi = std::max(hi, k);
        }
        const long k = core_max_khz[cpu];
        if (k == hi && hi != lo) return "fast";
        if (k == lo) return "slow";
        return "mid";
    }

    // Reads every thread of this process. utime + stime are fields 14 and 15 of
    // /proc/.../stat and the core it last ran on is field 39, counted after the
    // ")" that ends the name (which may itself contain spaces).
    std::map<int, ThreadSample> sample_threads() {
        std::map<int, ThreadSample> out;
        DIR* dir = opendir("/proc/self/task");
        if (dir == nullptr) {
            return out;
        }
        while (dirent* e = readdir(dir)) {
            const int tid = std::atoi(e->d_name);
            if (tid <= 0) {
                continue;
            }
            char path[64];
            std::snprintf(path, sizeof(path), "/proc/self/task/%d/stat", tid);
            FILE* f = std::fopen(path, "r");
            if (f == nullptr) {
                continue;
            }
            char buf[1024];
            const size_t n = std::fread(buf, 1, sizeof(buf) - 1, f);
            std::fclose(f);
            buf[n] = '\0';
            char* open = std::strchr(buf, '(');
            char* close = std::strrchr(buf, ')');
            if (open == nullptr || close == nullptr || close < open) {
                continue;
            }
            ThreadSample s;
            s.name.assign(open + 1, close);
            // Field 3 (state) starts two characters after ')'.
            int field = 3;
            unsigned long long utime = 0, stime = 0;
            for (char* tok = std::strtok(close + 2, " "); tok != nullptr; tok = std::strtok(nullptr, " "), field++) {
                if (field == 14) utime = std::strtoull(tok, nullptr, 10);
                else if (field == 15) stime = std::strtoull(tok, nullptr, 10);
                else if (field == 39) { s.cpu = std::atoi(tok); break; }
            }
            s.ticks = utime + stime;
            out[tid] = s;
        }
        closedir(dir);
        return out;
    }

    // ---- APerformanceHint, resolved at run time (Android 13+) ----
    using GetManagerFn = void* (*)();
    using CreateSessionFn = void* (*)(void*, const int32_t*, size_t, int64_t);
    using ReportFn = int (*)(void*, int64_t);

    std::atomic<void*> hint_session{ nullptr };
    ReportFn report_fn = nullptr;
    bool hint_tried = false;

    constexpr int64_t target_frame_ns = 33333333; // the game's 30 fps

    std::string start_hint_session(const std::vector<int32_t>& tids) {
        hint_tried = true;
        void* lib = dlopen("libandroid.so", RTLD_NOW);
        if (lib == nullptr) {
            return "performance hint: libandroid not found";
        }
        auto get_manager = reinterpret_cast<GetManagerFn>(dlsym(lib, "APerformanceHint_getManager"));
        auto create = reinterpret_cast<CreateSessionFn>(dlsym(lib, "APerformanceHint_createSession"));
        report_fn = reinterpret_cast<ReportFn>(dlsym(lib, "APerformanceHint_reportActualWorkDuration"));
        if (get_manager == nullptr || create == nullptr || report_fn == nullptr) {
            return "performance hint: not available (needs Android 13)";
        }
        void* manager = get_manager();
        void* session = (manager != nullptr) ? create(manager, tids.data(), tids.size(), target_frame_ns) : nullptr;
        if (session == nullptr) {
            return "performance hint: the system declined a session";
        }
        hint_session.store(session, std::memory_order_release);
        return "performance hint: session started for " + std::to_string(tids.size()) + " threads";
    }
}

// Called by the status report every few seconds. Returns lines to log (may be empty).
std::string southpark_android_thread_report(long seconds) {
    load_cores();
    static std::map<int, ThreadSample> last;
    static auto last_time = std::chrono::steady_clock::now();
    const auto now_time = std::chrono::steady_clock::now();
    const double dt = std::chrono::duration<double>(now_time - last_time).count();
    std::map<int, ThreadSample> now = sample_threads();

    struct Busy { int tid; double percent; const ThreadSample* s; };
    std::vector<Busy> busy;
    const double ticks_per_s = double(sysconf(_SC_CLK_TCK));
    if (dt > 0.5 && !last.empty()) {
        for (const auto& [tid, s] : now) {
            auto it = last.find(tid);
            if (it == last.end() || s.ticks < it->second.ticks) continue;
            const double pct = double(s.ticks - it->second.ticks) / ticks_per_s / dt * 100.0;
            if (pct >= 3.0) busy.push_back({ tid, pct, &s });
        }
    }
    std::sort(busy.begin(), busy.end(), [](const Busy& a, const Busy& b) { return a.percent > b.percent; });

    std::string text;
    if (!busy.empty()) {
        text += "[cpu]   busiest threads:";
        for (size_t i = 0; i < busy.size() && i < 7; i++) {
            char item[96];
            std::snprintf(item, sizeof(item), " %s %.0f%% (core %d %s)%s", busy[i].s->name.c_str(), busy[i].percent,
                busy[i].s->cpu, core_class(busy[i].s->cpu), (i + 1 < busy.size() && i < 6) ? "," : "");
            text += item;
        }
        text += "\n";
    }

    // A few seconds in, the threads that carry the frame are the busy ones.
    if (!hint_tried && seconds >= 8 && !busy.empty()) {
        std::vector<int32_t> tids;
        for (const Busy& b : busy) {
            if (b.percent >= 10.0 && tids.size() < 8) tids.push_back(b.tid);
        }
        if (!tids.empty()) {
            text += "[cpu]   " + start_hint_session(tids) + "\n";
        }
    }

    last = std::move(now);
    last_time = now_time;
    return text;
}

// Called once per game frame (each display list) from the graphics thread: the time
// since the previous one is how long the frame took end to end.
void southpark_android_frame_done() {
    void* session = hint_session.load(std::memory_order_acquire);
    static auto previous = std::chrono::steady_clock::now();
    const auto now = std::chrono::steady_clock::now();
    const int64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now - previous).count();
    previous = now;
    if (session != nullptr && report_fn != nullptr && ns > 0 && ns < 500000000) {
        report_fn(session, ns);
    }
}
