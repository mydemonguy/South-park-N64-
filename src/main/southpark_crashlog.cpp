// Session log + crash report for testing on devices without adb.
//
// Every line the game and runtime print (stdout/stderr, see main.cpp) is appended
// to <dataDir>/session.log, and <dataDir>/running.marker is created when the game
// starts. If the app dies, LauncherActivity finds the marker on the next launch and
// shows the end of session.log with Copy/Share buttons. The crash handler in
// android_diag.cpp writes its report here too, using only the raw fd.

#include <cstdio>
#include <cstring>
#include <filesystem>
#include <string>

#if defined(__ANDROID__) || defined(__linux__)
#include <fcntl.h>
#include <unistd.h>
#endif

namespace southpark::crashlog {
    namespace {
        int g_fd = -1;
        size_t g_written = 0;
        constexpr size_t max_bytes = 4 * 1024 * 1024;
        std::filesystem::path g_dir;
    }

    void start(const std::filesystem::path& dir) {
#if defined(__ANDROID__) || defined(__linux__)
        if (g_fd >= 0 || dir.empty()) {
            return;
        }
        g_dir = dir;
        g_fd = ::open((dir / "session.log").c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
        const char header[] = "=== South Park 64 session log ===\n";
        if (g_fd >= 0) {
            ssize_t r = ::write(g_fd, header, sizeof(header) - 1);
            (void)r;
        }
#else
        (void)dir;
#endif
    }

    // Async-signal-safe (only write()).
    void write_raw(const char* data, size_t n) {
#if defined(__ANDROID__) || defined(__linux__)
        if (g_fd < 0 || g_written > max_bytes) {
            return;
        }
        while (n > 0) {
            ssize_t r = ::write(g_fd, data, n);
            if (r <= 0) {
                return;
            }
            data += r;
            n -= (size_t)r;
            g_written += (size_t)r;
        }
#else
        (void)data; (void)n;
#endif
    }

    void write_line(const std::string& line) {
        write_raw(line.data(), line.size());
        write_raw("\n", 1);
    }

    void mark_game_running() {
#if defined(__ANDROID__) || defined(__linux__)
        if (g_dir.empty()) {
            return;
        }
        int fd = ::open((g_dir / "running.marker").c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
        if (fd >= 0) {
            ::close(fd);
        }
        write_line("[session] game started");
#endif
    }
}
