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
#include <functional>
#include <mutex>
#include <queue>
#include <vector>

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
        // A camera being torn down (end of a match) can still be reported with garbage in
        // it: reject anything that is not a sensible position.
        for (float v : f) {
            if (!std::isfinite(v) || (std::fabs(v) > 500000.0f)) {
                return false;
            }
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
        // Only cameras with a sensible view.
        int valid = 0;
        for (int i = 0; i < n; i++) {
            View v{};
            if (read_view(found[i], v)) found[valid++] = found[i];
        }
        n = valid;
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
        Clock::time_point split_since{};   // the screen has been split since (0: not split)
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
        // Following a route through the learned map.
        std::vector<int> route;
        size_t route_step = 0;
        uint32_t route_generation = 0;
        Clock::time_point route_time{};
        uint32_t routes_found = 0;
        uint32_t target_cam = 0;
        // Blocked: walking forward most of the last 4 s but no more than 60 units from where
        // it was. (Sliding along a wall still counts as moving to the half-second check.)
        std::array<Vec3, 8> recent{};
        int recent_count = 0;
        float forward_share = 0.0f;   // running share of polls with forward held
        bool blocked = false;
        // Pitched far up or down, since when: a wrongly learned tilt direction pins the view
        // at the floor or sky, where it cannot learn better.
        Clock::time_point pitch_extreme_since{};
        bool pitch_extreme = false;
        uint32_t pitch_flips = 0;
        uint32_t respawn_presses = 0;
        // Route points that led into a wall, avoided for a while.
        std::vector<std::pair<int, Clock::time_point>> avoid;
        Clock::time_point target_since{};
        uint32_t target_changes = 0;
        double play_seconds = 0.0;   // time in matches this session
        double near_human_seconds = 0.0;   // ...of which within 800 units of the person playing
        Clock::time_point last_poll{};
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

    // ---- Learned paths ----
    //
    // The bots cannot see walls, but every place a player has walked is walkable. So each
    // live view's position is sampled as it moves, building a shared map of points joined in
    // the direction they were walked (a drop off a ledge is one way). To reach a player a bot
    // looks for a route through that map and follows it, rather than walking straight into a
    // wall. The map starts empty each match and fills in as everyone moves around.

    struct NavNode {
        Vec3 pos;
        std::array<uint16_t, 8> out;
        uint8_t out_count;
    };

    struct NavMap {
        std::vector<NavNode> nodes;
        std::array<uint32_t, MaxPlayers> cam{};
        std::array<int, MaxPlayers> last_node{};
        std::array<Vec3, MaxPlayers> last_pos{};
        Clock::time_point last_update{};
        uint32_t generation = 0;   // bumped when the map is cleared
    };
    NavMap nav;

    constexpr size_t NavMaxNodes = 4000;
    constexpr float NavSpacing = 90.0f;   // a new point every this far
    constexpr float NavMerge = 70.0f;     // closer than this to an old point: the same point

    float flat_distance(const Vec3& a, const Vec3& b) {
        const float dx = a.x - b.x, dz = a.z - b.z;
        return std::sqrt(dx * dx + dz * dz);
    }

    // The point nearest pos (on about the same level), or -1.
    int nav_nearest(const Vec3& pos, float max_dist) {
        int best = -1;
        float best_d = max_dist;
        for (size_t i = 0; i < nav.nodes.size(); i++) {
            const NavNode& n = nav.nodes[i];
            if (std::fabs(n.pos.y - pos.y) > 120.0f) continue;
            const float d = flat_distance(n.pos, pos);
            if (d < best_d) {
                best_d = d;
                best = int(i);
            }
        }
        return best;
    }

    void nav_link(int from, int to) {
        if ((from < 0) || (to < 0) || (from == to)) return;
        NavNode& n = nav.nodes[size_t(from)];
        for (uint8_t i = 0; i < n.out_count; i++) {
            if (n.out[i] == uint16_t(to)) return;
        }
        if (n.out_count < n.out.size()) {
            n.out[n.out_count++] = uint16_t(to);
        }
    }

    void nav_clear() {
        nav.nodes.clear();
        nav.cam = {};
        nav.last_node.fill(-1);
        nav.generation++;
        std::fprintf(stderr, "[bot] path map cleared for a new match\n");
    }

    // Sample every live view, ten times a second.
    void nav_update(const std::array<uint32_t, MaxPlayers>& cams, int count, Clock::time_point now) {
        if (seconds(nav.last_update, now) < 0.1) return;
        nav.last_update = now;
        for (int i = 0; i < count; i++) {
            View v{};
            if (!read_view(cams[i], v)) continue;
            int slot = -1;
            for (int s = 0; s < MaxPlayers; s++) if (nav.cam[s] == cams[i]) slot = s;
            if (slot < 0) {
                for (int s = 0; s < MaxPlayers; s++) {
                    bool live = false;
                    for (int j = 0; j < count; j++) live |= (nav.cam[s] == cams[j]);
                    if (!live) { slot = s; break; }
                }
                if (slot < 0) continue;
                nav.cam[slot] = cams[i];
                nav.last_node[slot] = -1;
            }
            const float moved = distance(v.pos, nav.last_pos[slot]);
            if ((nav.last_node[slot] >= 0) && (moved < NavSpacing)) continue;
            int node = nav_nearest(v.pos, NavMerge);
            if ((node < 0) && (nav.nodes.size() < NavMaxNodes)) {
                nav.nodes.push_back(NavNode{ v.pos, {}, 0 });
                node = int(nav.nodes.size()) - 1;
            }
            if (node < 0) continue;
            // Walked here from the last point: joined. A big jump is a respawn, not a path.
            if ((nav.last_node[slot] >= 0) && (moved < 300.0f)) {
                nav_link(nav.last_node[slot], node);
            }
            nav.last_node[slot] = node;
            nav.last_pos[slot] = v.pos;
        }
    }

    // A route of points from near `from` to near `to`, or empty. Works backwards from the
    // target: every point from which the target can be reached gets its distance to go and
    // the next point on the way. The route then starts at whichever such point is best to
    // walk to first (near the bot and close to the target), so a bot that has never been on
    // a known path still heads for the nearest one that leads where it wants to go.
    std::vector<int> nav_route(const Vec3& from, const Vec3& to, const std::vector<uint8_t>& blocked) {
        std::vector<int> route;
        const int goal = nav_nearest(to, 300.0f);
        if (goal < 0) return route;
        const size_t n = nav.nodes.size();
        auto usable = [&](size_t a) { return (a >= blocked.size()) || !blocked[a]; };
        std::vector<std::vector<uint16_t>> into(n);   // edges reversed
        for (size_t a = 0; a < n; a++) {
            for (uint8_t e = 0; e < nav.nodes[a].out_count; e++) into[nav.nodes[a].out[e]].push_back(uint16_t(a));
        }
        std::vector<float> to_go(n, 1e30f);
        std::vector<int> next(n, -1);
        using Entry = std::pair<float, int>;
        std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> open;
        to_go[size_t(goal)] = 0.0f;
        open.push({ 0.0f, goal });
        while (!open.empty()) {
            const auto [d, cur] = open.top();
            open.pop();
            if (d > to_go[size_t(cur)]) continue;
            for (const uint16_t a : into[size_t(cur)]) {
                if (!usable(a)) continue;
                const float c = d + distance(nav.nodes[a].pos, nav.nodes[size_t(cur)].pos);
                if (c < to_go[a]) {
                    to_go[a] = c;
                    next[a] = cur;
                    open.push({ c, int(a) });
                }
            }
        }
        // Where to join: walking there straight counts extra, it may not be clear.
        int start = -1;
        float best = 1e30f;
        for (size_t a = 0; a < n; a++) {
            if ((to_go[a] >= 1e29f) || !usable(a) || (std::fabs(nav.nodes[a].pos.y - from.y) > 120.0f)) continue;
            const float score = 2.0f * flat_distance(nav.nodes[a].pos, from) + to_go[a];
            if (score < best) {
                best = score;
                start = int(a);
            }
        }
        if ((start < 0) || (start == goal)) return route;
        // Only worth it if it beats walking straight at the target.
        if (best > 4.0f * distance(from, to)) return route;
        for (int c = start; c >= 0; c = next[size_t(c)]) route.push_back(c);
        return route;
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
                "times in play %u, hunts %u, stuck %u, menu presses %u, area changes %u, throws %u (%u lined up), jumps %u, detours %u, routes %u (map %zu points), target changes %u, near you %.0fs, view turned %.0f deg/s\n",
                bot.controller + 1, t, action_name(bot.action), double(view.pos.x), double(view.pos.y), double(view.pos.z),
                bot.have_pos ? double(distance(view.pos, bot.report_pos)) : 0.0, bot.distance_total, count,
                bot.play_entries, bot.hunts, bot.stuck_count, bot.menu_presses, bot.area_changes, bot.fires, bot.aimed_throws, bot.jumps, bot.detours, bot.routes_found, nav.nodes.size(), bot.target_changes, bot.near_human_seconds,
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
        // A camera it already has and that is still live is kept unless another follows the
        // stick far more clearly (its own may just be still, e.g. while respawning).
        double own_abs = -1.0;
        for (const Bot::CamTrack& c : bot.tracks) {
            if ((bot.own_cam != 0) && (c.addr == bot.own_cam)) own_abs = std::fabs(c.yaw_corr);
        }
        if ((best != nullptr) && (own_abs >= 0.0) && (best->addr != bot.own_cam) && (best_abs < 3.0 * own_abs + 1.0)) {
            best = nullptr;
        }
        if ((best != nullptr) && (bot.tracked_polls > 90) && (best_abs > 0.5) && (best_abs > 3.0 * second_abs)) {
            // A camera another bot already holds goes to whichever follows it more clearly.
            for (Bot& other : bots) {
                if ((&other == &bot) || !other.active || (other.own_cam != best->addr)) continue;
                if (best_abs < 3.0 * other.own_corr) {
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

    // The person playing: player 1, whose view is the first one the game allocates (the
    // lowest address) and which no bot has claimed as its own.
    uint32_t human_camera(const std::array<uint32_t, MaxPlayers>& cams, int count) {
        for (int i = 0; i < count; i++) {
            bool claimed = false;
            for (const Bot& b : bots) claimed |= (b.active && (b.controller != 0) && (b.own_cam == cams[i]));
            if (!claimed) return cams[i];   // cams are sorted by address
        }
        return 0;
    }

    // Who to go after. Mostly the nearest player (a player on another level counts as
    // further), but: the person playing counts as nearer, so the bots come for them and do
    // not only fight each other; a bot sticks with its target for a while rather than
    // flipping between two; and after half a minute on the same one it gets restless and
    // looks for someone else, so the bots move around the map instead of pairing off.
    bool choose_target(Bot& bot, const View& self, const std::array<uint32_t, MaxPlayers>& cams, int count,
                       Clock::time_point now, Vec3& target) {
        float best = 1e30f;
        uint32_t best_cam = 0;
        for (int i = 0; i < count; i++) {
            if ((bot.own_cam != 0) ? (cams[i] == bot.own_cam) : (i == bot.controller)) continue;
            View other{};
            if (!read_view(cams[i], other)) continue;
            const Vec3 to = other.pos - self.pos;
            float cost = std::sqrt(to.x * to.x + to.z * to.z) + 2.0f * std::fabs(to.y);
            if (cost < 1.0f) continue;
            const bool human = (cams[i] == human_camera(cams, count));
            if (human) {
                // The bots are there for the person playing: go for them unless another
                // player is right in the way, and never get bored of them.
                cost *= 0.5f;
                if (cams[i] == bot.target_cam) cost *= 0.8f;
            }
            else {
                // Another bot only when it is close and the person is far: otherwise two
                // bots that meet keep fighting each other and never come looking.
                cost += 600.0f;
                if (cams[i] == bot.target_cam) {
                    const double on = seconds(bot.target_since, now);
                    cost *= (on < 20.0) ? 0.8f : float(1.0 + (on - 20.0) / 10.0);
                }
            }
            if (cost < best) {
                best = cost;
                best_cam = cams[i];
                target = other.pos;
            }
        }
        if (best_cam == 0) return false;
        if (best_cam != bot.target_cam) {
            bot.target_cam = best_cam;
            bot.target_since = now;
            bot.target_changes++;
        }
        return true;
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

        if (bot.playing && (controller != 0)) {
            const double dt = seconds(bot.last_poll, now);
            if (dt < 1.0) {
                bot.play_seconds += dt;
                View h{};
                const uint32_t hc = human_camera(cams, camera_count);
                if (have_view && (hc != 0) && (hc != bot.own_cam) && read_view(hc, h) && (distance(h.pos, view.pos) < 800.0f)) {
                    bot.near_human_seconds += dt;
                }
            }
        }
        bot.last_poll = now;
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
                // Blocked check over the last 4 s.
                if (bot.recent_count == int(bot.recent.size())) {
                    bot.blocked = (distance(view.pos, bot.recent[0]) < 60.0f) && (bot.forward_share > 0.6f);
                    std::rotate(bot.recent.begin(), bot.recent.begin() + 1, bot.recent.end());
                    bot.recent.back() = view.pos;
                }
                else {
                    bot.recent[size_t(bot.recent_count++)] = view.pos;
                }
                bot.have_pos = true;
            }
            bot.last_check = now;
        }

        // Controllers 2-4 play exactly while the screen is split with a view for them: the
        // menus and story mode have one view, a multiplayer match one per player. They never
        // press anything outside a match, so they cannot disturb the player's menus.
        if (controller != 0) {
            const bool split_now = (camera_count >= 2) && (controller < camera_count);
            if (!split_now) bot.split_since = Clock::time_point{};
            else if (bot.split_since == Clock::time_point{}) bot.split_since = now;
            // Split for a full second: a match, not a menu changing over.
            const bool split = split_now && (seconds(bot.split_since, now) >= 1.0);
            if (split_now && bot.playing) bot.split_seen = now;
            if (split) {
                bot.split_seen = now;
                if (!bot.playing) {
                    bool any_playing = false;
                    for (const Bot& other : bots) any_playing |= (other.active && other.playing && (other.controller != 0));
                    if (!any_playing) nav_clear();
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
            else if (((idle > 3.0) || bot.blocked) && (bot.action != Action::Unstick)) {
                // A route point that walked it into a wall is skipped for 20 s.
                if (bot.blocked && (bot.route_step < bot.route.size())) {
                    bot.avoid.push_back({ bot.route[bot.route_step], now + std::chrono::seconds(20) });
                }
                bot.route.clear();
                bot.route_time = Clock::time_point{};
                bot.blocked = false;
                bot.recent_count = 0;
                bot.stuck_count++;
                bot.turn_dir = (rng() & 1) ? 1.0f : -1.0f;
                begin(bot, Action::Unstick, 1.2 + rng_unit(), now);
            }
            else {
                Vec3 target{};
                if (have_view && (bot.own_cam != 0) && (now >= bot.roam_until) && choose_target(bot, view, cams, camera_count, now, target)) {
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
            if (have_view && choose_target(bot, view, cams, camera_count, now, target)) {
                const Vec3 to = target - view.pos;
                const float yaw_err = wrap_angle(yaw_of(to) - yaw_of(view.fwd));
                const float pitch_err = pitch_of(to) - pitch_of(view.fwd);
                const float range = length(to);
                const float flat = std::sqrt(to.x * to.x + to.z * to.z);   // across the ground
                const bool other_level = std::fabs(to.y) > 200.0f;

                // Far off or on another level: find a way there through the places players
                // have walked, refreshed every second, and head for the next point on it.
                bool following = false;
                Vec3 waypoint{};
                if ((flat > 500.0f) || other_level) {
                    // Keep a route while it still leads to the target: replanning every second
                    // let the bot flip between two ways round and spin on the spot.
                    const bool target_moved = !bot.route.empty() &&
                        (flat_distance(nav.nodes[size_t(bot.route.back())].pos, target) > 400.0f) &&
                        (seconds(bot.route_time, now) > 0.5);
                    if ((bot.route_generation != nav.generation) || (seconds(bot.route_time, now) > (bot.route.empty() ? 1.0 : 5.0)) || target_moved) {
                        std::vector<uint8_t> blocked_points(nav.nodes.size(), 0);
                        bot.avoid.erase(std::remove_if(bot.avoid.begin(), bot.avoid.end(),
                            [&](const auto& a) { return now >= a.second; }), bot.avoid.end());
                        for (const auto& a : bot.avoid) {
                            if (size_t(a.first) < blocked_points.size()) blocked_points[size_t(a.first)] = 1;
                        }
                        bot.route = nav_route(view.pos, target, blocked_points);
                        bot.route_step = 0;
                        bot.route_time = now;
                        bot.route_generation = nav.generation;
                        if (!bot.route.empty()) bot.routes_found++;
                    }
                    // Skip points already reached; aim a little ahead for smoother turns.
                    while ((bot.route_step + 1 < bot.route.size()) &&
                           (flat_distance(nav.nodes[size_t(bot.route[bot.route_step])].pos, view.pos) < 110.0f)) {
                        bot.route_step++;
                    }
                    if (bot.route_step < bot.route.size()) {
                        size_t ahead = bot.route_step;
                        if ((ahead + 1 < bot.route.size()) &&
                            (flat_distance(nav.nodes[size_t(bot.route[ahead + 1])].pos, view.pos) < 220.0f)) {
                            ahead++;
                        }
                        waypoint = nav.nodes[size_t(bot.route[ahead])].pos;
                        following = flat_distance(waypoint, view.pos) > 40.0f;
                    }
                }
                else {
                    bot.route.clear();
                }
                if (following) {
                    const Vec3 to_wp = waypoint - view.pos;
                    const float wp_err = wrap_angle(yaw_of(to_wp) - yaw_of(view.fwd));
                    const int ts = bot.turn_sign;
                    sx = (ts != 0) ? std::clamp(wp_err * 1.4f * float(ts), -0.75f, 0.75f) : 0.5f;
                    if (std::fabs(wp_err) < 0.05f) sx = 0.0f;
                    if (bot.pitch_sign != 0) {   // keep level while travelling
                        sy = std::clamp(-pitch_of(view.fwd) * 1.5f * float(bot.pitch_sign), -0.4f, 0.4f);
                        if (std::fabs(sy) < 0.05f) sy = 0.0f;
                    }
                    if (std::fabs(wp_err) < 1.0f) b |= BTN_C_UP;
                    // Progress along the route is judged by the blocked check instead.
                    bot.hunt_best = flat;
                    bot.hunt_best_time = now;
                    break;
                }
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
            if (controller != 0) nav_update(cams, camera_count, now);
        }
        else {
            for (Bot::CamTrack& c : bot.tracks) c.have_prev = false;
        }
        bot.prev_sx = sx;
        bot.prev_sy = sy;

        if (bot.playing) {
            bot.forward_share = bot.forward_share * 0.97f + ((b & BTN_C_UP) ? 0.03f : 0.0f);

            // Trying to walk but the view not moving at all for 4 s: probably knocked out and
            // waiting to respawn, which can take a button. Press fire, and A now and then.
            if ((controller != 0) && (seconds(bot.last_moved, now) > 4.0) && (bot.forward_share > 0.5f)) {
                const double t = std::fmod(t_total, 2.0);
                if (t < 0.12) b |= BTN_Z;
                else if ((t > 1.0) && (t < 1.12)) b |= BTN_A;
                if ((b & (BTN_Z | BTN_A)) && !(bot.prev_buttons & (BTN_Z | BTN_A))) bot.respawn_presses++;
            }

            // Looking hard at the floor or sky for 2 s: the tilt direction it learned is
            // probably backwards. Flip it (if that is wrong, it flips back 2 s later).
            if (have_view && (bot.pitch_sign != 0)) {
                const bool extreme = std::fabs(pitch_of(view.fwd)) > 0.7f;
                if (extreme && !bot.pitch_extreme) bot.pitch_extreme_since = now;
                bot.pitch_extreme = extreme;
                if (extreme && (seconds(bot.pitch_extreme_since, now) > 2.0)) {
                    bot.pitch_sign = -bot.pitch_sign;
                    bot.pitch_flips++;
                    bot.pitch_extreme_since = now;
                    for (Bot::CamTrack& c : bot.tracks) if (c.addr == bot.own_cam) c.pitch_corr = 0.0;
                    std::fprintf(stderr, "[bot %d] view stuck looking %s: flipping tilt direction\n", controller + 1,
                        (pitch_of(view.fwd) > 0) ? "up" : "down");
                }
            }
        }

        // Count presses (new this poll), not polls.
        const uint16_t pressed = uint16_t(b & ~bot.prev_buttons);
        if (pressed & BTN_Z) bot.fires++;
        if (pressed & BTN_R) bot.jumps++;
        if (!bot.playing && (pressed & (BTN_A | BTN_START))) bot.menu_presses++;
        bot.prev_buttons = b;

        // Every 10 s in a match; while waiting, once a minute (the shared log keeps only
        // its start and end, so idle lines would push the useful ones out).
        if (seconds(bot.last_report, now) >= ((bot.playing || (controller == 0)) ? 10.0 : 60.0)) {
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
int southpark_bot_controllers();

// A summary of the bots' matches this session, for the end of the session log (the log
// shared from the app keeps only its start and end, so the match lines are often cut).
void southpark_bot_summary() {
    std::lock_guard lock{ bots_mutex };
    int shown = 0;
    for (const Bot& bot : bots) {
        if (!bot.active || (bot.controller == 0) || (bot.play_entries == 0)) continue;
        shown++;
        std::fprintf(stderr,
            "[match] bot %d this session: %u matches, %.0fs playing (%.0fs near you), walked %.0f, throws %u (%u lined up), respawns/area changes %u, "
            "stuck %u, detours %u, routes followed %u, target changes %u, tilt flips %u, respawn presses %u, own view %s, now %s\n",
            bot.controller + 1, bot.play_entries, bot.play_seconds, bot.near_human_seconds, bot.distance_total, bot.fires, bot.aimed_throws, bot.area_changes,
            bot.stuck_count, bot.detours, bot.routes_found, bot.target_changes, bot.pitch_flips, bot.respawn_presses, (bot.own_cam != 0) ? "found" : "not found",
            bot.playing ? "in a match" : "waiting");
    }
    if (shown == 0) {
        std::fprintf(stderr, "[match] no multiplayer match with bots this session (bots: %d)\n", southpark_bot_controllers());
    }
}

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
