#include "sp_recomp.h"
#include "funcs.h"

extern uint32_t builtin_base_event_index;
#define base_event_index builtin_base_event_index

RECOMP_FUNC void sp_patches_placeholder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801000: jr          $ra
    // 0x80801004: nop

    return;
    // 0x80801004: nop

;}
