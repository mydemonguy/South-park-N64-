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

#endif
