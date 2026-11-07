// Autoplay test (General tab, "Autoplay Test"): a simple bot that drives controller 1 so a
// session can be soak-tested on a phone without anyone holding it. It cannot beat the game;
// it checks that the game boots, gets through menus and cutscenes, and keeps running and
// responding while it walks, turns, throws and jumps -- and logs what it saw.
//
// How it knows what is happening: a hook in the game's camera code (southpark.us.toml,
// func_0025B68C) reports the camera each frame, and the camera's world position is the apex
// of its view frustum at +0x26C/+0x270/+0x274.
//
// Two modes. In menu mode (start, menus, cutscenes, dialogue) it never touches the stick --
// the main menu is a vertical list with Story Mode first, and the stick would wander into
// Enter Cheat -- and presses A every 1.5 s, Start every 6 s, and B now and then if it has
// been in menus a long time. Every few seconds it probes by holding C-Right (a sidestep in
// play, nothing in menus): if the camera then moves smoothly, it is in play mode. In play
// mode it walks, turns, throws and jumps; if nothing moves for 12 s (a cutscene, dialogue,
// a pause or a hang) it goes back to menu mode. The log, with the [status] lines, tells
// these apart.
//
// Controls used (the game's default "Turok" scheme): C-Up/C-Down walk forward/back, C-Right
// steps sideways, the stick aims (left/right turns; up/down is left alone so the view stays
// level), Z fires, R jumps, A/Start confirm and skip, B backs out.

#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include "goemon_config.h"

namespace {
    using Clock = std::chrono::steady_clock;

    constexpr uint16_t BTN_A = 0x8000;
    constexpr uint16_t BTN_B = 0x4000;
    constexpr uint16_t BTN_C_RIGHT = 0x0001;
    constexpr uint16_t BTN_C_UP = 0x0008;
    constexpr uint16_t BTN_C_DOWN = 0x0004;
    constexpr uint16_t BTN_Z = 0x2000;
    constexpr uint16_t BTN_START = 0x1000;
    constexpr uint16_t BTN_R = 0x0010;

    // Camera reported by the hook (game thread) and read by the input poll (also the game
    // thread, but kept atomic so a status reader elsewhere stays safe).
    std::atomic<uint8_t*> camera_rdram{ nullptr };
    std::atomic<uint32_t> camera_addr{ 0 };
    std::atomic<uint64_t> camera_frames{ 0 };

    struct Vec3 { float x, y, z; };

    bool read_camera_position(Vec3& out) {
        uint8_t* rdram = camera_rdram.load(std::memory_order_relaxed);
        const uint32_t addr = camera_addr.load(std::memory_order_relaxed);
        if ((rdram == nullptr) || (addr < 0x80000000u) || (addr >= 0x80800000u - 0x280u)) {
            return false;
        }
        // Recompiled RDRAM keeps each aligned 32-bit word in host order.
        const uint32_t offset = addr - 0x80000000u;
        float v[3];
        for (int i = 0; i < 3; i++) {
            uint32_t word;
            std::memcpy(&word, rdram + offset + 0x26C + i * 4, sizeof(word));
            std::memcpy(&v[i], &word, sizeof(float));
        }
        if (!std::isfinite(v[0]) || !std::isfinite(v[1]) || !std::isfinite(v[2])) {
            return false;
        }
        out = { v[0], v[1], v[2] };
        return true;
    }

    float distance(const Vec3& a, const Vec3& b) {
        const float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Small deterministic PRNG so runs vary their turns but are repeatable per session.
    uint32_t rng_state = 0x12345678u;
    uint32_t rng() {
        rng_state ^= rng_state << 13;
        rng_state ^= rng_state >> 17;
        rng_state ^= rng_state << 5;
        return rng_state;
    }
    float rng_unit() { return float(rng() & 0xFFFF) / 65535.0f; }

    enum class Action { Walk, Turn, Unstick, Menu, Probe };
    const char* action_name(Action a) {
        switch (a) {
        case Action::Walk: return "playing: walking";
        case Action::Turn: return "playing: turning";
        case Action::Unstick: return "playing: unsticking";
        case Action::Menu: return "menus: pressing A/Start";
        case Action::Probe: return "menus: checking for play";
        }
        return "?";
    }

    struct Bot {
        bool active = false;
        Clock::time_point start;
        Clock::time_point action_start;
        double action_length = 0.0;
        Action action = Action::Walk;
        float turn_dir = 1.0f;

        // Progress tracking.
        bool have_pos = false;
        Vec3 last_pos{};               // position at the last progress check
        Vec3 report_pos{};             // position at the last report
        Clock::time_point last_check;
        Clock::time_point last_moved;
        Clock::time_point last_report;
        uint64_t last_camera_frames = 0;
        Clock::time_point last_camera_change;
        bool camera_stalled_logged = false;
        double distance_total = 0.0;
        uint32_t stuck_count = 0, menu_pokes = 0, area_changes = 0;
        bool playing = false;
        Clock::time_point menu_since;       // when menu mode began
        Vec3 probe_start{}, probe_mid{};
        bool probe_have_start = false, probe_have_mid = false;
        uint32_t play_entries = 0;
        uint32_t fires = 0, jumps = 0;
        uint16_t prev_buttons = 0;
    } bot;

    double seconds(Clock::time_point a, Clock::time_point b) {
        return std::chrono::duration<double>(b - a).count();
    }

    void begin(Action a, double length, Clock::time_point now) {
        bot.action = a;
        bot.action_start = now;
        bot.action_length = length;
    }

    void start_bot(Clock::time_point now) {
        bot = Bot{};
        bot.active = true;
        bot.start = now;
        bot.last_check = now;
        bot.last_moved = now;
        bot.last_report = now;
        bot.last_camera_change = now;
        bot.last_camera_frames = camera_frames.load(std::memory_order_relaxed);
        rng_state = 0x12345678u ^ uint32_t(now.time_since_epoch().count());
        if (rng_state == 0) rng_state = 1;
        bot.menu_since = now;
        begin(Action::Menu, 6.0, now);
        std::fprintf(stderr, "[bot] autoplay test started in menu mode\n");
    }

    void report(Clock::time_point now) {
        Vec3 pos{};
        const bool have = read_camera_position(pos);
        const double t = seconds(bot.start, now);
        if (have) {
            std::fprintf(stderr,
                "[bot] %.0fs %s, camera at (%.0f, %.0f, %.0f), moved %.0f since last line, %.0f total; "
                "times in play %u, stuck %u, menu presses %u, area changes %u, throws %u, jumps %u\n",
                t, action_name(bot.action), double(pos.x), double(pos.y), double(pos.z),
                bot.have_pos ? double(distance(pos, bot.report_pos)) : 0.0, bot.distance_total,
                bot.play_entries, bot.stuck_count, bot.menu_pokes, bot.area_changes, bot.fires, bot.jumps);
            bot.report_pos = pos;
        }
        else {
            std::fprintf(stderr, "[bot] %.0fs %s, no 3D camera yet (menus or loading); menu presses %u\n",
                t, action_name(bot.action), bot.menu_pokes);
        }
    }
}

// Hook (southpark.us.toml, func_0025B68C): the game's per-frame camera update.
extern "C" void southpark_bot_camera(uint8_t* rdram, uint64_t camera) {
    camera_rdram.store(rdram, std::memory_order_relaxed);
    camera_addr.store(uint32_t(camera), std::memory_order_relaxed);
    camera_frames.fetch_add(1, std::memory_order_relaxed);
}

// Called from recomp::get_n64_input after the player's own input is read. Replaces it
// while the autoplay test is on; returns false (leaving the input alone) otherwise.
bool southpark_bot_input(uint16_t* buttons, float* x, float* y) {
    const bool enabled = goemon64::get_autoplay_mode() == goemon64::AutoplayMode::On;
    const Clock::time_point now = Clock::now();
    if (!enabled) {
        if (bot.active) {
            bot.active = false;
            report(now);
            std::fprintf(stderr, "[bot] autoplay test stopped after %.0fs\n", seconds(bot.start, now));
        }
        return false;
    }

    if (!bot.active) {
        start_bot(now);
    }

    // Is the game still producing camera frames? (Menus may not use the 3D camera, so this
    // is only reported, not acted on.)
    const uint64_t frames = camera_frames.load(std::memory_order_relaxed);
    if (frames != bot.last_camera_frames) {
        if (bot.camera_stalled_logged) {
            std::fprintf(stderr, "[bot] %.0fs camera updating again\n", seconds(bot.start, now));
        }
        bot.last_camera_frames = frames;
        bot.last_camera_change = now;
        bot.camera_stalled_logged = false;
    }
    else if (!bot.camera_stalled_logged && (seconds(bot.last_camera_change, now) > 10.0)) {
        std::fprintf(stderr, "[bot] %.0fs camera has not updated for 10s (menu, cutscene, loading screen or a hang)\n",
            seconds(bot.start, now));
        bot.camera_stalled_logged = true;
    }

    // Progress check twice a second: movement, area changes (a big jump), being stuck.
    if (seconds(bot.last_check, now) >= 0.5) {
        Vec3 pos{};
        if (read_camera_position(pos)) {
            if (bot.have_pos) {
                const float d = distance(pos, bot.last_pos);
                if (d > 600.0f) {
                    bot.area_changes++;
                    std::fprintf(stderr, "[bot] %.0fs camera jumped %.0f units to (%.0f, %.0f, %.0f): new area, respawn or cutscene\n",
                        seconds(bot.start, now), double(d), double(pos.x), double(pos.y), double(pos.z));
                }
                else {
                    bot.distance_total += d;
                }
                if (d > 2.0f) {
                    bot.last_moved = now;
                }
            }
            else {
                bot.report_pos = pos;
                bot.last_moved = now;
            }
            bot.last_pos = pos;
            bot.have_pos = true;
        }
        bot.last_check = now;
    }

    // Pick the next action when the current one ends.
    const double idle = seconds(bot.last_moved, now);
    if (bot.playing && (idle > 12.0)) {
        // Nothing has moved for a while: a cutscene, dialogue, a pause or a hang.
        bot.playing = false;
        bot.menu_since = now;
        std::fprintf(stderr, "[bot] %.0fs nothing moved for 12s: back to menu mode\n", seconds(bot.start, now));
        begin(Action::Menu, 6.0, now);
    }
    else if (seconds(bot.action_start, now) >= bot.action_length) {
        if (!bot.playing) {
            if (bot.action == Action::Probe) {
                // In play the camera holds still with no input, then the sidestep moves it
                // smoothly; an intro flythrough moves it either way, a menu not at all.
                Vec3 pos{};
                const bool moved = bot.probe_have_start && bot.probe_have_mid && read_camera_position(pos) &&
                    (distance(bot.probe_mid, bot.probe_start) < 1.0f) &&
                    (distance(pos, bot.probe_mid) > 3.0f) && (distance(pos, bot.probe_mid) < 400.0f);
                if (moved) {
                    bot.playing = true;
                    bot.play_entries++;
                    bot.last_moved = now;
                    std::fprintf(stderr, "[bot] %.0fs in play (the sidestep moved the camera): play mode\n", seconds(bot.start, now));
                    begin(Action::Walk, 3.0, now);
                }
                else {
                    begin(Action::Menu, 6.0, now);
                }
            }
            else {
                // After a menu stretch, probe for play.
                bot.probe_have_start = read_camera_position(bot.probe_start);
                bot.probe_have_mid = false;
                begin(Action::Probe, 1.5, now);
            }
        }
        else if (idle > 3.0) {
            bot.stuck_count++;
            bot.turn_dir = (rng() & 1) ? 1.0f : -1.0f;
            begin(Action::Unstick, 1.2 + rng_unit(), now);
        }
        else if (bot.action == Action::Walk) {
            bot.turn_dir = (rng() & 1) ? 1.0f : -1.0f;
            begin(Action::Turn, 0.3 + 0.9 * rng_unit(), now);
        }
        else {
            begin(Action::Walk, 2.0 + 3.0 * rng_unit(), now);
        }
    }

    // Produce this poll's input.
    const double t_action = seconds(bot.action_start, now);
    const double t_total = seconds(bot.start, now);
    uint16_t b = 0;
    float sx = 0.0f, sy = 0.0f;
    switch (bot.action) {
    case Action::Walk:
        b |= BTN_C_UP;
        sx = 0.2f * std::sin(float(t_total) * 0.7f);   // gentle weave so it sweeps the view
        break;
    case Action::Turn:
        b |= BTN_C_UP;
        sx = 0.8f * bot.turn_dir;
        break;
    case Action::Unstick:
        // Back off and turn, with a jump in the middle.
        b |= (t_action < 0.5) ? BTN_C_DOWN : BTN_C_UP;
        sx = 1.0f * bot.turn_dir;
        if ((t_action > 0.4) && (t_action < 0.6)) b |= BTN_R;
        break;
    case Action::Menu: {
        // Stick untouched. A every 1.5 s; Start once mid-way; after 90 s in menus, B now
        // and then to back out of a screen it should not be on.
        const double a_phase = std::fmod(t_action, 1.5);
        if (a_phase < 0.15) b |= BTN_A;
        if ((t_action > 3.0) && (t_action < 3.15)) b |= BTN_START;
        if ((seconds(bot.menu_since, now) > 90.0) && (std::fmod(seconds(bot.menu_since, now), 30.0) < 0.15)) {
            b = BTN_B;
        }
        break;
    }
    case Action::Probe:
        // 0.6 s with no input, then sidestep.
        if (t_action >= 0.6) {
            if (!bot.probe_have_mid) {
                bot.probe_have_mid = read_camera_position(bot.probe_mid);
            }
            b |= BTN_C_RIGHT;
        }
        break;
    }

    if (bot.playing) {
        // Throw for a moment every 1.5 s and jump now and then.
        const double phase = std::fmod(t_total, 1.5);
        if (phase < 0.12) {
            b |= BTN_Z;
        }
        if (std::fmod(t_total, 7.0) < 0.12) {
            b |= BTN_R;
        }
    }

    // Count presses (new this poll), not polls.
    const uint16_t pressed = uint16_t(b & ~bot.prev_buttons);
    if (pressed & BTN_Z) bot.fires++;
    if (pressed & BTN_R) bot.jumps++;
    if (!bot.playing && (pressed & (BTN_A | BTN_START))) bot.menu_pokes++;
    bot.prev_buttons = b;

    if (seconds(bot.last_report, now) >= 10.0) {
        report(now);
        bot.last_report = now;
    }

    *buttons = b;
    *x = sx;
    *y = sy;
    return true;
}
