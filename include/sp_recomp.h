// sp_recomp.h: recomp.h plus portable float-to-int conversions.
//
// recomp.h converts with plain C casts and lrint(). When the value doesn't fit, C leaves
// the result undefined, and in practice x86 returns 0x80000000 while ARM64 saturates
// (0x7FFFFFFF / 0). lrint() also returns `long`, which is 64-bit on Linux/Android and
// 32-bit on Windows. On real hardware these cases raise an FPU exception, so a working
// game shouldn't hit them; this header makes every platform agree with the Windows PC
// build anyway: out of range or NaN gives the most negative integer.
#ifndef SP_RECOMP_H
#define SP_RECOMP_H

#include "recomp.h"

static inline int32_t sp_to_w(double v) {
    return (v > -2147483649.0 && v < 2147483648.0) ? (int32_t)v : INT32_MIN;
}

static inline int64_t sp_to_l(double v) {
    return (v >= -9223372036854775808.0 && v < 9223372036854775808.0) ? (int64_t)v : INT64_MIN;
}

#undef TRUNC_W_S
#undef TRUNC_W_D
#undef TRUNC_L_S
#undef TRUNC_L_D
#define TRUNC_W_S(val) sp_to_w((double)(val))
#define TRUNC_W_D(val) sp_to_w((double)(val))
#define TRUNC_L_S(val) sp_to_l((double)(val))
#define TRUNC_L_D(val) sp_to_l((double)(val))

// Rounding-mode-aware conversions: rint() honors the current rounding mode.
#undef CVT_W_S
#undef CVT_W_D
#undef CVT_L_S
#undef CVT_L_D
#define CVT_W_S(val) sp_to_w(rint((double)(val)))
#define CVT_W_D(val) sp_to_w(rint((double)(val)))
#define CVT_L_S(val) sp_to_l(rint((double)(val)))
#define CVT_L_D(val) sp_to_l(rint((double)(val)))

// VM region create/free hook (southpark.us.toml [[patches.hook]], src/game/southpark_os.cpp).
#ifdef __cplusplus
extern "C"
#endif
void southpark_vm_region_changed(uint8_t* rdram, uint32_t node, int freed);

// Scheduler RSP/RDP-done guard (southpark.us.toml [[patches.hook]], src/game/southpark_os.cpp).
#ifdef __cplusplus
extern "C"
#endif
int southpark_sched_guard(uint8_t* rdram, recomp_context* ctx, int which);
#ifdef __cplusplus
extern "C"
#endif
void southpark_sched_trace(uint8_t* rdram, recomp_context* ctx);

// View Distance setting (southpark.us.toml [[patches.hook]], src/ui/ui_config.cpp): the
// factor the game's own draw distance (camera +0x4F0) is multiplied by where it is used
// for drawing -- 1.0 for Original.
#ifdef __cplusplus
extern "C"
#endif
float southpark_view_distance_scale(void);

// Widescreen (src/main/rt64_render_context.cpp): how many times wider than 4:3 RT64 shows
// the 3D view -- 1.0 at Original. The game's camera code builds its culling frustum and the
// box of level blocks around the camera from one horizontal half-angle; the hook in
// southpark.us.toml widens that angle so its tangent grows by the same factor as the view.
#ifdef __cplusplus
extern "C"
#endif
float southpark_widescreen_scale(void);

// Autoplay test (src/game/southpark_bot.cpp): the hook in the camera update (func_0025B68C,
// $s3 = the camera) reports the camera each frame.
#ifdef __cplusplus
extern "C"
#endif
void southpark_bot_camera(uint8_t* rdram, uint64_t camera);

static inline float sp_widen_half_angle(float half_angle) {
    const float scale = southpark_widescreen_scale();
    return (scale > 1.0f) ? atanf(tanf(half_angle) * scale) : half_angle;
}

#endif
