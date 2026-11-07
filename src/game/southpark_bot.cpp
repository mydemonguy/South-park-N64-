// Bots that play South Park through its controllers.
//
// * Autoplay Test (General tab, always Off at launch): a bot plays controller 1 so a
//   session can be soak-tested on a phone without anyone holding it.
// * Multiplayer Bots (General tab, Off/1/2/3, saved): that many extra controllers (2, 3, 4)
//   are reported connected -- South Park only offers Multiplayer with more than one -- and
//   each is played by a bot that hunts the nearest other player.
//
// How a bot sees the game: a hook in the camera update (southpark.us.toml, func_0025B68C)
// reports every camera each frame. In split-screen there is one per player; they are told
// apart by address (allocated in player order). A camera's view frustum, transformed to
// world space, sits at +0x26C: the apex (the player's eye) and the four far corners after
// it, so the player's position is the apex and the direction they face is the middle of
// the far corners minus the apex.
//
// Two modes. In menu mode (menus, cutscenes, dialogue) a bot leaves the stick alone and
// presses A (and, on controller 1, Start; the main menu is a list with Story Mode first, and
// the stick would wander into Enter Cheat). Every few seconds it probes by holding C-Right
// (a sidestep in play, nothing in menus): if its camera then moves smoothly, it is in play
// mode. In play mode, with other players about, it turns toward the nearest one, closes in,
// strafes, and throws once its aim is close; alone, it explores (walk, turn, throw, jump).
// Nothing moving for 12 s puts it back in menu mode.
//
// Which way the stick turns and tilts the view is learned on the fly from how the camera
// responds, so it does not depend on the control scheme's inversion settings.
//
// Controls used (the game's default "Turok" scheme): C-Up/C-Down walk forward/back,
// C-Left/C-Right step sideways, the stick aims, Z fires, R jumps, A/Start confirm and skip,
// B backs out.

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <mutex>

#include "goemon_config.h"

namespace {
    using Clock = std::chrono::steady_clock;

    constexpr uint16_t BTN_A = 0x8000;
    constexpr uint16_t BTN_B = 0x4000;
    constexpr uint16_t BTN_Z = 0x2000;
    constexpr uint16_t BTN_START = 0x1000;
    constexpr uint16_t BTN_R = 0x0010;
    constexpr uint16_t BTN_C_UP = 0x0008;
    constexpr uint16_t BTN_C_DOWN = 0x0004;
    constexpr uint16_t BTN_C_LEFT = 0x0002;
    constexpr uint16_t BTN_C_RIGHT = 0x0001;

    constexpr int MaxPlayers = 4;
    constexpr float Pi = 3.14159265f;

    struct Vec3 { float x, y, z; };
    Vec3 operator-(const Vec3& a, const Vec3& b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }
    float length(const Vec3& v) { return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
    float distance(const Vec3& a, const Vec3& b) { return length(a - b); }
    float wrap_angle(float a) {
        while (a > Pi) a -= 2 * Pi;
        while (a < -Pi) a += 2 * Pi;
        return a;
    }

    // ---- Cameras, as reported by the hook ----

    struct CameraSlot {
        uint32_t addr = 0;
        uint64_t last_seen = 0;   // hook call count when last reported
    };

    std::mutex camera_mutex;
    std::array<CameraSlot, 8> camera_slots{};
    uint64_t camera_calls = 0;
    std::atomic<uint8_t*> camera_rdram{ nullptr };

    struct View {
        Vec3 pos;      // eye
        Vec3 fwd;      // facing (not normalised)
        float aspect;  // far plane width / height
    };

    bool read_floats(uint8_t* rdram, uint32_t addr, float* out, int count) {
        if ((rdram == nullptr) || (addr < 0x80000000u) || (addr + count * 4 > 0x80800000u)) {
            return false;
        }
        // Recompiled RDRAM keeps each aligned 32-bit word in host order.
        const uint32_t offset = addr - 0x80000000u;
        for (int i = 0; i < count; i++) {
            uint32_t word;
            std::memcpy(&word, rdram + offset + i * 4, sizeof(word));
            std::memcpy(&out[i], &word, sizeof(float));
            if (!std::isfinite(out[i])) {
                return false;
            }
        }
        return true;
    }

    bool read_view(uint32_t camera, View& view) {
        float f[15];   // apex, then the four far corners
        if (!read_floats(camera_rdram.load(std::memory_order_relaxed), camera + 0x26C, f, 15)) {
            return false;
        }
        view.pos = { f[0], f[1], f[2] };
        Vec3 mid{ 0, 0, 0 };
        for (int c = 1; c <= 4; c++) {
            mid.x += f[c * 3] * 0.25f; mid.y += f[c * 3 + 1] * 0.25f; mid.z += f[c * 3 + 2] * 0.25f;
        }
        view.fwd = mid - view.pos;
        // The far plane's shape: width over height, telling a split-screen view from a
        // full-screen one. Of the sides from the first corner, the height is the one that
        // runs most along the world's up axis.
        const Vec3 c0{ f[3], f[4], f[5] };
        float side_len[3]{}, side_up[3]{};
        for (int c = 2; c <= 4; c++) {
            const Vec3 d = Vec3{ f[c * 3], f[c * 3 + 1], f[c * 3 + 2] } - c0;
            side_len[c - 2] = length(d);
            side_up[c - 2] = (side_len[c - 2] > 0) ? std::fabs(d.y) / side_len[c - 2] : 0.0f;
        }
        // The diagonal is the longest; the other two are the sides.
        int diag = 0;
        for (int i = 1; i < 3; i++) if (side_len[i] > side_len[diag]) diag = i;
        const int a = (diag + 1) % 3, b = (diag + 2) % 3;
        const int up = (side_up[a] > side_up[b]) ? a : b, across = (up == a) ? b : a;
        view.aspect = (side_len[up] > 1e-3f) ? side_len[across] / side_len[up] : 0.0f;
        return length(view.fwd) > 1e-3f;
    }

    // The cameras updated in the last few frames, in address order: index = player.
    int active_cameras(std::array<uint32_t, MaxPlayers>& out) {
        std::lock_guard lock{ camera_mutex };
        // The game also runs a camera of its own in static memory (0x800CBF88, for the HUD
        // and menus); the views people play in are allocated on the heap. Leave the static
        // ones out unless nothing else is live.
        std::array<uint32_t, 8> found{};
        int n = 0;
        for (const bool heap : { true, false }) {
            for (const CameraSlot& slot : camera_slots) {
                if ((slot.addr != 0) && ((camera_calls - slot.last_seen) <= 16) && ((slot.addr >= 0x80200000u) == heap)) {
                    found[n++] = slot.addr;
                }
            }
            if (n > 0) break;
        }
        std::sort(found.begin(), found.begin() + n);
        n = std::min(n, MaxPlayers);
        for (int i = 0; i < n; i++) {
            out[i] = found[i];
        }
        return n;
    }

    float yaw_of(const Vec3& v) { return std::atan2(v.x, v.z); }
    float pitch_of(const Vec3& v) { return std::atan2(v.y, std::sqrt(v.x * v.x + v.z * v.z)); }

    // ---- Per-controller bots ----

    uint32_t rng_state = 0x12345678u;
    uint32_t rng() {
        rng_state ^= rng_state << 13;
        rng_state ^= rng_state >> 17;
        rng_state ^= rng_state << 5;
        return rng_state;
    }
    float rng_unit() { return float(rng() & 0xFFFF) / 65535.0f; }

    enum class Action { Walk, Turn, Unstick, Hunt, Menu, Probe };
    const char* action_name(Action a) {
        switch (a) {
        case Action::Walk: return "playing: exploring";
        case Action::Turn: return "playing: turning";
        case Action::Unstick: return "playing: unsticking";
        case Action::Hunt: return "playing: hunting";
        case Action::Menu: return "menus: pressing A";
        case Action::Probe: return "menus: checking for play";
        }
        return "?";
    }

    double seconds(Clock::time_point a, Clock::time_point b) {
        return std::chrono::duration<double>(b - a).count();
    }

    struct Bot {
        int controller = 0;
        bool active = false;
        Clock::time_point start, action_start, last_check, last_moved, last_report, menu_since, split_seen;
        double action_length = 0.0;
        Action action = Action::Walk;
        float turn_dir = 1.0f;
        float strafe_dir = 1.0f;
        bool playing = false;

        bool have_pos = false;
        Vec3 last_pos{}, report_pos{};
        bool probe_have_mid = false;
        // The probe watches every camera: its own is the one that holds still with no input
        // and then moves with the sidestep.
        std::array<uint32_t, MaxPlayers> probe_cams{};
        std::array<Vec3, MaxPlayers> probe_cam_start{}, probe_cam_mid{};
        int probe_cam_count = 0;
        double distance_total = 0.0;

        // Finding its own camera: for each live camera, the facing at the previous poll and
        // the running correlation of its turning (and tilting) with this bot's stick. The
        // camera that follows the stick is its own, and the sign says which way the stick
        // turns the view, so this does not depend on the control scheme's inversion settings.
        struct CamTrack {
            uint32_t addr = 0;
            bool have_prev = false;
            float prev_yaw = 0.0f, prev_pitch = 0.0f;
            double yaw_corr = 0.0, pitch_corr = 0.0;
        };
        std::array<CamTrack, MaxPlayers> tracks{};
        uint32_t own_cam = 0;     // 0 until found
        double own_corr = 0.0;    // how clearly it follows this bot's stick
        uint32_t guess_cam = 0;   // until then: the camera its probe sidestep moved
        uint32_t tracked_polls = 0;
        int turn_sign = 0;        // +1/-1: the yaw change a positive stick X makes
        int pitch_sign = 0;       // +1/-1: the pitch change a positive stick Y makes
        float prev_sx = 0.0f, prev_sy = 0.0f;   // the stick it last sent (smoothed)
        uint32_t aimed_throws = 0;
        // Getting closer? The closest it has come to its target lately, and when.
        float hunt_best = 1e30f;
        Clock::time_point hunt_best_time{};
        Clock::time_point roam_until{};
        uint32_t detours = 0;
        // How much its view turned: to tell a steady bot from a twitchy one in logs.
        bool have_yaw = false;
        float last_yaw = 0.0f;
        double yaw_travel = 0.0;

        uint32_t stuck_count = 0, menu_presses = 0, area_changes = 0, play_entries = 0;
        uint32_t fires = 0, jumps = 0, hunts = 0;
        uint16_t prev_buttons = 0;
    };

    std::mutex bots_mutex;   // held while any bot runs, so bots can look at each other
    std::array<Bot, MaxPlayers> bots{};

    void begin(Bot& bot, Action a, double length, Clock::time_point now) {
        bot.action = a;
        bot.action_start = now;
        bot.action_length = length;
    }

    // Its own camera once found; before that, a guess by address order.
    bool own_view(const Bot& bot, View& view, std::array<uint32_t, MaxPlayers>& cams, int& count) {
        count = active_cameras(cams);
        for (const uint32_t want : { bot.own_cam, bot.guess_cam }) {
            if (want == 0) continue;
            for (int i = 0; i < count; i++) {
                if (cams[i] == want) {
                    return read_view(cams[i], view);
                }
            }
        }
        if (bot.controller >= count) {
            return false;
        }
        return read_view(cams[bot.controller], view);
    }

    // Probe snapshots of every live camera's position.
    void probe_snapshot(Bot& bot, bool mid) {
        if (!mid) {
            bot.probe_cam_count = active_cameras(bot.probe_cams);
        }
        for (int i = 0; i < bot.probe_cam_count; i++) {
            View v{};
            const bool ok = read_view(bot.probe_cams[i], v);
            (mid ? bot.probe_cam_mid : bot.probe_cam_start)[i] = ok ? v.pos : Vec3{ 1e30f, 1e30f, 1e30f };
        }
    }

    // After a probe: the camera that held still and then moved with the sidestep, or 0.
    uint32_t probe_result(const Bot& bot) {
        uint32_t found = 0;
        int matches = 0;
        for (int i = 0; i < bot.probe_cam_count; i++) {
            View v{};
            if (!read_view(bot.probe_cams[i], v)) continue;
            const float still = distance(bot.probe_cam_mid[i], bot.probe_cam_start[i]);
            const float moved = distance(v.pos, bot.probe_cam_mid[i]);
            if ((still < 1.0f) && (moved > 3.0f) && (moved < 400.0f)) {
                found = bot.probe_cams[i];
                matches++;
            }
        }
        // Several matches (bots probing together): any of them proves play; the guess is
        // just the first, to be corrected by track_cameras.
        return (matches > 0) ? found : 0;
    }

    void report(Bot& bot, Clock::time_point now) {
        std::array<uint32_t, MaxPlayers> cams{};
        int count = 0;
        View view{};
        const double t = seconds(bot.start, now);
        if (bot.controller == 1) {
            std::array<uint32_t, MaxPlayers> all{};
            const int n = active_cameras(all);
            std::fprintf(stderr, "[bot] cameras:");
            for (int i = 0; i < n; i++) {
                View v{};
                if (read_view(all[i], v)) std::fprintf(stderr, " %08X shape %.2f at (%.0f, %.0f, %.0f);", all[i], double(v.aspect), double(v.pos.x), double(v.pos.y), double(v.pos.z));
            }
            std::fprintf(stderr, "\n");
        }
        if (own_view(bot, view, cams, count)) {
            std::fprintf(stderr,
                "[bot %d] %.0fs %s, at (%.0f, %.0f, %.0f), moved %.0f since last line, %.0f total; players seen %d, "
                "times in play %u, hunts %u, stuck %u, menu presses %u, area changes %u, throws %u (%u lined up), jumps %u, detours %u, view turned %.0f deg/s\n",
                bot.controller + 1, t, action_name(bot.action), double(view.pos.x), double(view.pos.y), double(view.pos.z),
                bot.have_pos ? double(distance(view.pos, bot.report_pos)) : 0.0, bot.distance_total, count,
                bot.play_entries, bot.hunts, bot.stuck_count, bot.menu_presses, bot.area_changes, bot.fires, bot.aimed_throws, bot.jumps, bot.detours,
                bot.yaw_travel * 57.2958 / std::max(1.0, seconds(bot.last_report, now)));
            bot.yaw_travel = 0.0;
            bot.report_pos = view.pos;
        }
        else {
            std::fprintf(stderr, "[bot %d] %.0fs %s, no camera of its own yet (%d in use); menu presses %u\n",
                bot.controller + 1, t, (bot.controller != 0) ? "waiting for a match" : action_name(bot.action), count, bot.menu_presses);
        }
    }

    void start_bot(Bot& bot, int controller, Clock::time_point now) {
        bot = Bot{};
        bot.controller = controller;
        bot.active = true;
        bot.start = bot.last_check = bot.last_moved = bot.last_report = bot.menu_since = now;
        rng_state ^= uint32_t(now.time_since_epoch().count()) + uint32_t(controller) * 0x9E3779B9u;
        if (rng_state == 0) rng_state = 1;
        begin(bot, Action::Menu, 6.0, now);
        std::fprintf(stderr, "[bot %d] started in menu mode\n", controller + 1);
    }

    // Update the stick/camera correlations and, from them, the bot's own camera and stick
    // directions. Called every poll in play.
    void track_cameras(Bot& bot, const std::array<uint32_t, MaxPlayers>& cams, int count) {
        for (int i = 0; i < count; i++) {
            View v{};
            if (!read_view(cams[i], v)) continue;
            Bot::CamTrack* t = nullptr;
            for (Bot::CamTrack& c : bot.tracks) {
                if (c.addr == cams[i]) { t = &c; break; }
            }
            if (t == nullptr) {
                // Take over the slot of a camera that is no longer live.
                for (Bot::CamTrack& c : bot.tracks) {
                    bool live = false;
                    for (int j = 0; j < count; j++) live |= (c.addr == cams[j]);
                    if (!live) { c = Bot::CamTrack{}; c.addr = cams[i]; t = &c; break; }
                }
                if (t == nullptr) continue;
            }
            const float yaw = yaw_of(v.fwd), pitch = pitch_of(v.fwd);
            if (t->have_prev) {
                const float dyaw = wrap_angle(yaw - t->prev_yaw);
                const float dpitch = pitch - t->prev_pitch;
                if (std::fabs(dyaw) < 0.5f) t->yaw_corr = t->yaw_corr * 0.995 + double(dyaw) * bot.prev_sx;
                if (std::fabs(dpitch) < 0.5f) t->pitch_corr = t->pitch_corr * 0.995 + double(dpitch) * bot.prev_sy;
            }
            t->prev_yaw = yaw;
            t->prev_pitch = pitch;
            t->have_prev = true;
        }

        // Its own camera: the one whose turning follows the stick, well ahead of the rest.
        const Bot::CamTrack* best = nullptr;
        double best_abs = 0.0, second_abs = 0.0;
        for (const Bot::CamTrack& c : bot.tracks) {
            if (c.addr == 0) continue;
            const double a = std::fabs(c.yaw_corr);
            if (a > best_abs) { second_abs = best_abs; best_abs = a; best = &c; }
            else if (a > second_abs) { second_abs = a; }
        }
        bot.tracked_polls++;
        if ((best != nullptr) && (bot.tracked_polls > 90) && (best_abs > 0.5) && (best_abs > 3.0 * second_abs)) {
            // A camera another bot already holds goes to whichever follows it more clearly.
            for (Bot& other : bots) {
                if ((&other == &bot) || !other.active || (other.own_cam != best->addr)) continue;
                if (best_abs < 1.5 * other.own_corr) {
                    return;
                }
                std::fprintf(stderr, "[bot %d] camera %08X follows bot %d more closely\n",
                    other.controller + 1, best->addr, bot.controller + 1);
                other.own_cam = 0;
                other.own_corr = 0.0;
                other.turn_sign = 0;
            }
            const int sign = (best->yaw_corr > 0) ? 1 : -1;
            if ((bot.own_cam != best->addr) || (bot.turn_sign != sign)) {
                std::fprintf(stderr, "[bot %d] found its camera (%08X); stick right turns %s\n",
                    bot.controller + 1, best->addr, (sign > 0) ? "one way" : "the other way");
            }
            bot.own_cam = best->addr;
            bot.own_corr = best_abs;
            bot.guess_cam = 0;
            bot.turn_sign = sign;
            if (std::fabs(best->pitch_corr) > 0.05) {
                const int psign = (best->pitch_corr > 0) ? 1 : -1;
                if (bot.pitch_sign != psign) {
                    std::fprintf(stderr, "[bot %d] stick up looks %s\n", bot.controller + 1, (psign > 0) ? "up" : "down");
                }
                bot.pitch_sign = psign;
            }
        }
    }

    // The nearest other player's eye, if any other player's camera is live.
    bool nearest_opponent(const Bot& bot, const View& self, const std::array<uint32_t, MaxPlayers>& cams, int count, Vec3& target) {
        float best = 1e30f;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if ((bot.own_cam != 0) ? (cams[i] == bot.own_cam) : (i == bot.controller)) continue;
            View other{};
            if (!read_view(cams[i], other)) continue;
            // Nearest counting height difference extra: a player on a ledge right above or
            // below is not one to chase (the bot ends up circling under them).
            const Vec3 to = other.pos - self.pos;
            const float d = std::sqrt(to.x * to.x + to.z * to.z) + 2.0f * std::fabs(to.y);
            if ((d > 1.0f) && (d < best)) {
                best = d;
                target = other.pos;
                found = true;
            }
        }
        return found;
    }

    bool run_bot(Bot& bot, int controller, uint16_t* buttons, float* x, float* y) {
        const Clock::time_point now = Clock::now();
        if (!bot.active) {
            start_bot(bot, controller, now);
        }

        std::array<uint32_t, MaxPlayers> cams{};
        int camera_count = 0;
        View view{};
        const bool have_view = own_view(bot, view, cams, camera_count);
        if (have_view && bot.playing && (bot.own_cam != 0)) {
            const float yaw = yaw_of(view.fwd);
            if (bot.have_yaw) {
                const float d = std::fabs(wrap_angle(yaw - bot.last_yaw));
                if (d < 1.0f) bot.yaw_travel += d;
            }
            bot.last_yaw = yaw;
            bot.have_yaw = true;
        }

        // Progress check twice a second: movement, area changes (a big jump), being stuck.
        if (seconds(bot.last_check, now) >= 0.5) {
            if (have_view) {
                if (bot.have_pos) {
                    const float d = distance(view.pos, bot.last_pos);
                    if (d > 600.0f) {
                        bot.area_changes++;
                        std::fprintf(stderr, "[bot %d] %.0fs camera jumped %.0f units to (%.0f, %.0f, %.0f): new area, respawn or cutscene\n",
                            controller + 1, seconds(bot.start, now), double(d), double(view.pos.x), double(view.pos.y), double(view.pos.z));
                    }
                    else {
                        bot.distance_total += d;
                    }
                    if (d > 2.0f) {
                        bot.last_moved = now;
                    }
                }
                else {
                    bot.report_pos = view.pos;
                    bot.last_moved = now;
                }
                bot.last_pos = view.pos;
                bot.have_pos = true;
            }
            bot.last_check = now;
        }

        // Controllers 2-4 play exactly while the screen is split with a view for them: the
        // menus and story mode have one view, a multiplayer match one per player. They never
        // press anything outside a match, so they cannot disturb the player's menus.
        if (controller != 0) {
            const bool split = (camera_count >= 2) && (controller < camera_count);
            if (split) {
                bot.split_seen = now;
                if (!bot.playing) {
                    bot.playing = true;
                    bot.play_entries++;
                    bot.last_moved = now;
                    bot.own_cam = 0; bot.own_corr = 0.0; bot.guess_cam = 0; bot.turn_sign = 0; bot.pitch_sign = 0;
                    bot.tracks = {};
                    bot.tracked_polls = 0;
                    std::fprintf(stderr, "[bot %d] %.0fs split screen with %d views: playing\n", controller + 1, seconds(bot.start, now), camera_count);
                    begin(bot, Action::Walk, 2.0, now);
                }
            }
            else if (bot.playing && (seconds(bot.split_seen, now) > 2.0)) {
                bot.playing = false;
                bot.menu_since = now;
                std::fprintf(stderr, "[bot %d] %.0fs match over: waiting\n", controller + 1, seconds(bot.start, now));
                begin(bot, Action::Menu, 6.0, now);
            }
        }

        // Pick the next action.
        const double idle = seconds(bot.last_moved, now);
        if ((controller == 0) && bot.playing && (idle > 12.0)) {
            bot.playing = false;
            bot.menu_since = now;
            std::fprintf(stderr, "[bot %d] %.0fs nothing moved for 12s: back to menu mode\n", controller + 1, seconds(bot.start, now));
            begin(bot, Action::Menu, 6.0, now);
        }
        else if (seconds(bot.action_start, now) >= bot.action_length) {
            if (!bot.playing && (controller != 0)) {
                begin(bot, Action::Menu, 6.0, now);
            }
            else if (!bot.playing) {
                if (bot.action == Action::Probe) {
                    // In play the camera holds still with no input, then the sidestep moves it
                    // smoothly; an intro flythrough moves it either way, a menu not at all.
                    const uint32_t moved_cam = bot.probe_have_mid ? probe_result(bot) : 0;
                    if (moved_cam != 0) {
                        if (bot.own_cam == 0) bot.guess_cam = moved_cam;
                        bot.playing = true;
                        bot.play_entries++;
                        bot.last_moved = now;
                        std::fprintf(stderr, "[bot %d] %.0fs in play (the sidestep moved its camera): play mode\n", controller + 1, seconds(bot.start, now));
                        begin(bot, Action::Walk, 2.0, now);
                    }
                    else {
                        begin(bot, Action::Menu, 6.0, now);
                    }
                }
                else {
                    probe_snapshot(bot, false);
                    bot.probe_have_mid = false;
                    begin(bot, Action::Probe, 1.5, now);
                }
            }
            else if ((idle > 3.0) && (bot.action != Action::Unstick)) {
                bot.stuck_count++;
                bot.turn_dir = (rng() & 1) ? 1.0f : -1.0f;
                begin(bot, Action::Unstick, 1.2 + rng_unit(), now);
            }
            else {
                Vec3 target{};
                if (have_view && (bot.own_cam != 0) && (now >= bot.roam_until) && nearest_opponent(bot, view, cams, camera_count, target)) {
                    if (bot.action != Action::Hunt) {
                        bot.hunts++;
                        bot.hunt_best = 1e30f;
                        bot.hunt_best_time = now;
                    }
                    bot.strafe_dir = (rng() & 1) ? 1.0f : -1.0f;
                    begin(bot, Action::Hunt, 1.0 + rng_unit(), now);
                }
                else if (bot.action == Action::Walk) {
                    bot.turn_dir = (rng() & 1) ? 1.0f : -1.0f;
                    begin(bot, Action::Turn, 0.3 + 0.9 * rng_unit(), now);
                }
                else {
                    begin(bot, Action::Walk, 2.0 + 3.0 * rng_unit(), now);
                }
            }
        }

        // Produce this poll's input.
        const double t_action = seconds(bot.action_start, now);
        const double t_total = seconds(bot.start, now);
        uint16_t b = 0;
        float sx = 0.0f, sy = 0.0f;
        bool aimed = false;
        switch (bot.action) {
        case Action::Walk:
            b |= BTN_C_UP;
            // A slow weave, each controller at its own rate so the bots' sticks are not in
            // step (that is how each tells its own view from the others).
            sx = 0.12f * std::sin(float(t_total) * (0.7f + 0.23f * controller) + 1.9f * controller);
            if ((bot.own_cam != 0) && (bot.pitch_sign == 0)) {
                // One short look up and back down to learn which way the stick tilts the view.
                sy = (t_action < 0.25) ? 0.5f : (t_action < 0.5) ? -0.5f : 0.0f;
            }
            else if (have_view && (bot.pitch_sign != 0)) {
                sy = std::clamp(-pitch_of(view.fwd) * 1.5f * float(bot.pitch_sign), -0.4f, 0.4f);   // keep level
                if (std::fabs(sy) < 0.05f) sy = 0.0f;
            }
            break;
        case Action::Turn:
            b |= BTN_C_UP;
            sx = 0.5f * bot.turn_dir;
            break;
        case Action::Unstick:
            b |= (t_action < 0.5) ? BTN_C_DOWN : BTN_C_UP;
            b |= (bot.turn_dir > 0) ? BTN_C_RIGHT : BTN_C_LEFT;
            sx = 1.0f * bot.turn_dir;
            if ((t_action > 0.4) && (t_action < 0.6)) b |= BTN_R;
            break;
        case Action::Hunt: {
            Vec3 target{};
            if (have_view && nearest_opponent(bot, view, cams, camera_count, target)) {
                const Vec3 to = target - view.pos;
                const float yaw_err = wrap_angle(yaw_of(to) - yaw_of(view.fwd));
                const float pitch_err = pitch_of(to) - pitch_of(view.fwd);
                const float range = length(to);
                const float flat = std::sqrt(to.x * to.x + to.z * to.z);   // across the ground
                const bool other_level = std::fabs(to.y) > 200.0f;
                // Turn toward the target. Until the turn direction is known, sweep one way:
                // track_cameras picks the sign up from the response.
                // Proportional, gentle, with a dead zone once on target so the view settles
                // instead of hunting back and forth.
                const int ts = bot.turn_sign;
                sx = (ts != 0) ? std::clamp(yaw_err * 1.4f * float(ts), -0.75f, 0.75f) : 0.5f;
                if (std::fabs(yaw_err) < 0.04f) sx = 0.0f;
                if (flat < 150.0f) sx = 0.0f;   // nearly overhead: the direction is meaningless
                const int ps = bot.pitch_sign;
                if ((ps != 0) && (std::fabs(yaw_err) < 0.4f)) {
                    sy = std::clamp(pitch_err * 1.2f * float(ps), -0.4f, 0.4f);
                    if (std::fabs(pitch_err) < 0.05f) sy = 0.0f;
                }
                // Throw only when lined up and close: further off there is usually a wall or
                // a building in the way, and the bot cannot see those.
                aimed = (ts != 0) && (std::fabs(yaw_err) < 0.07f) && (range < 700.0f) &&
                    ((ps == 0) || (std::fabs(pitch_err) < 0.15f));
                // No closer in 6 s while still far off: something is in the way. Roam for a
                // few seconds to find another way round.
                if (flat < bot.hunt_best - 80.0f) {
                    bot.hunt_best = flat;
                    bot.hunt_best_time = now;
                }
                else if ((flat > 500.0f) && (seconds(bot.hunt_best_time, now) > 6.0)) {
                    bot.detours++;
                    bot.roam_until = now + std::chrono::milliseconds(3000 + int(rng_unit() * 3000.0));
                    bot.turn_dir = (rng() & 1) ? 1.0f : -1.0f;
                    begin(bot, Action::Turn, 0.6 + 0.6 * rng_unit(), now);
                }
                // Close in across the ground; keep a distance from someone on another level
                // rather than walking underneath them.
                const float near_limit = other_level ? 600.0f : 120.0f;
                const float far_limit = other_level ? 900.0f : 350.0f;
                if ((flat > far_limit) && (std::fabs(yaw_err) < 1.2f)) {
                    b |= BTN_C_UP;
                }
                else if (flat < near_limit) {
                    b |= BTN_C_DOWN;
                }
                if (!other_level && (range < 900.0f) && (std::fmod(t_total + controller * 0.9, 3.2) < 0.9)) {
                    b |= (bot.strafe_dir > 0) ? BTN_C_RIGHT : BTN_C_LEFT;   // dodge while fighting
                }
            }
            else {
                b |= BTN_C_UP;
            }
            break;
        }
        case Action::Menu: {
            // Controller 1 (the Autoplay Test): stick untouched, A every 1.5 s, Start once in a
            // while, and after 90 s in menus B now and then to back out of a screen it should
            // not be on. The extra controllers press nothing: the game's menus answer every
            // controller, and their presses would change the multiplayer rules under the player.
            const double a_phase = std::fmod(t_action, 1.5);
            if ((a_phase < 0.15) && (controller == 0)) b |= BTN_A;
            if (controller == 0) {
                if ((t_action > 3.0) && (t_action < 3.15)) b |= BTN_START;
                if ((seconds(bot.menu_since, now) > 90.0) && (std::fmod(seconds(bot.menu_since, now), 30.0) < 0.15)) {
                    b = BTN_B;
                }
            }
            break;
        }
        case Action::Probe:
            if (t_action >= 0.6) {
                if (!bot.probe_have_mid) {
                    probe_snapshot(bot, true);
                    bot.probe_have_mid = true;
                }
                b |= BTN_C_RIGHT;
            }
            break;
        }

        // Ease the stick toward what was asked for, like a thumb would, so the view turns
        // smoothly instead of snapping.
        sx = bot.prev_sx + (sx - bot.prev_sx) * 0.35f;
        sy = bot.prev_sy + (sy - bot.prev_sy) * 0.35f;
        if (std::fabs(sx) < 0.02f) sx = 0.0f;
        if (std::fabs(sy) < 0.02f) sy = 0.0f;

        if (bot.playing) {
            // Throw only at a target it is lined up on, about once every 0.7 s.
            if (aimed && (std::fmod(t_total + controller * 0.3, 0.7) < 0.12)) {
                b |= BTN_Z;
                if (!(bot.prev_buttons & BTN_Z)) bot.aimed_throws++;
            }
            track_cameras(bot, cams, camera_count);
        }
        else {
            for (Bot::CamTrack& c : bot.tracks) c.have_prev = false;
        }
        bot.prev_sx = sx;
        bot.prev_sy = sy;

        // Count presses (new this poll), not polls.
        const uint16_t pressed = uint16_t(b & ~bot.prev_buttons);
        if (pressed & BTN_Z) bot.fires++;
        if (pressed & BTN_R) bot.jumps++;
        if (!bot.playing && (pressed & (BTN_A | BTN_START))) bot.menu_presses++;
        bot.prev_buttons = b;

        if (seconds(bot.last_report, now) >= 10.0) {
            report(bot, now);
            bot.last_report = now;
        }

        *buttons = b;
        *x = sx;
        *y = sy;
        return true;
    }
}

// Hook (southpark.us.toml, func_0025B68C): the game's per-frame camera update, once per
// camera (one per player in split-screen).
extern "C" void southpark_bot_camera(uint8_t* rdram, uint64_t camera) {
    camera_rdram.store(rdram, std::memory_order_relaxed);
    const uint32_t addr = uint32_t(camera);
    std::lock_guard lock{ camera_mutex };
    camera_calls++;
    CameraSlot* oldest = &camera_slots[0];
    for (CameraSlot& slot : camera_slots) {
        if (slot.addr == addr) {
            slot.last_seen = camera_calls;
            return;
        }
        if (slot.last_seen < oldest->last_seen) {
            oldest = &slot;
        }
    }
    oldest->addr = addr;
    oldest->last_seen = camera_calls;
}

// How many extra controllers (2, 3, 4) the game should see (src/game/input.cpp).
int southpark_bot_controllers() {
    switch (goemon64::get_multiplayer_bots()) {
    case goemon64::MultiplayerBots::One: return 1;
    case goemon64::MultiplayerBots::Two: return 2;
    case goemon64::MultiplayerBots::Three: return 3;
    default: return 0;
    }
}

#if !defined(__ANDROID__)
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

// Desktop test runs: when SOUTHPARK_TEST_INPUT names a file, controller 1 holds whatever
// that file lists (button names A B Z L R START CU CD CL CR DU DD DL DR, and X=<f> Y=<f> for
// the stick), so a script can drive the menus. An empty or missing file is no input.
static bool test_input(uint16_t* buttons, float* x, float* y) {
    static const char* path = std::getenv("SOUTHPARK_TEST_INPUT");
    if (path == nullptr) {
        return false;
    }
    std::ifstream in(path);
    std::string token;
    uint16_t b = 0;
    float sx = 0.0f, sy = 0.0f;
    while (in >> token) {
        static const std::pair<const char*, uint16_t> names[] = {
            { "A", 0x8000 }, { "B", 0x4000 }, { "Z", 0x2000 }, { "START", 0x1000 },
            { "DU", 0x0800 }, { "DD", 0x0400 }, { "DL", 0x0200 }, { "DR", 0x0100 },
            { "L", 0x0020 }, { "R", 0x0010 }, { "CU", 0x0008 }, { "CD", 0x0004 }, { "CL", 0x0002 }, { "CR", 0x0001 },
        };
        for (const auto& [name, bit] : names) {
            if (token == name) b |= bit;
        }
        if (token.rfind("X=", 0) == 0) sx = std::strtof(token.c_str() + 2, nullptr);
        if (token.rfind("Y=", 0) == 0) sy = std::strtof(token.c_str() + 2, nullptr);
        if (token.rfind("BOTS=", 0) == 0) {   // change the Multiplayer Bots setting live
            const int n = std::atoi(token.c_str() + 5);
            goemon64::set_multiplayer_bots((n >= 3) ? goemon64::MultiplayerBots::Three : (n == 2) ? goemon64::MultiplayerBots::Two :
                (n == 1) ? goemon64::MultiplayerBots::One : goemon64::MultiplayerBots::Off);
        }
    }
    *buttons = b;
    *x = sx;
    *y = sy;
    return true;
}
#endif

// Called from recomp::get_n64_input. For controller 1, after the player's own input is
// read, replaces it while the Autoplay Test is on. For controllers 2-4, supplies their input
// while Multiplayer Bots gives them a bot. Returns false (leaving the input alone, or the
// controller absent) otherwise.
bool southpark_bot_input(int controller, uint16_t* buttons, float* x, float* y) {
    if ((controller < 0) || (controller >= MaxPlayers)) {
        return false;
    }
#if !defined(__ANDROID__)
    if ((controller == 0) && (goemon64::get_autoplay_mode() != goemon64::AutoplayMode::On) && test_input(buttons, x, y)) {
        return true;
    }
#endif
    const bool enabled = (controller == 0)
        ? (goemon64::get_autoplay_mode() == goemon64::AutoplayMode::On)
        : (controller <= southpark_bot_controllers());

    std::lock_guard lock{ bots_mutex };
    Bot& bot = bots[controller];
    if (!enabled) {
        if (bot.active) {
            bot.active = false;
            const Clock::time_point now = Clock::now();
            report(bot, now);
            std::fprintf(stderr, "[bot %d] stopped after %.0fs\n", controller + 1, seconds(bot.start, now));
        }
        return false;
    }
    return run_bot(bot, controller, buttons, x, y);
}
