#include "sp_recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_00242F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00242F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00242F34: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00242F38: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00242F3C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00242F40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00242F44: beq         $a2, $v0, L_00242F54
    if (ctx->r6 == ctx->r2) {
        // 0x00242F48: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00242F54;
    }
    // 0x00242F48: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00242F4C: bne         $a2, $v0, L_00242F58
    if (ctx->r6 != ctx->r2) {
        // 0x00242F50: nop
    
            goto L_00242F58;
    }
    // 0x00242F50: nop

L_00242F54:
    // 0x00242F54: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00242F58:
    // 0x00242F58: lhu         $a3, 0x4A($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4A);
    // 0x00242F5C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00242F60: addiu       $a2, $a2, -0x13C8
    ctx->r6 = ADD32(ctx->r6, -0X13C8);
    // 0x00242F64: jal         0x00241868
    // 0x00242F68: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00242F68: nop

    after_0:
    // 0x00242F6C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00242F70: jr          $ra
    // 0x00242F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00242F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00242F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00242F78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00242F7C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00242F80: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00242F84: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00242F88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00242F8C: beq         $a2, $v0, L_00242F9C
    if (ctx->r6 == ctx->r2) {
        // 0x00242F90: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00242F9C;
    }
    // 0x00242F90: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00242F94: bne         $a2, $v0, L_00242FA0
    if (ctx->r6 != ctx->r2) {
        // 0x00242F98: nop
    
            goto L_00242FA0;
    }
    // 0x00242F98: nop

L_00242F9C:
    // 0x00242F9C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00242FA0:
    // 0x00242FA0: lhu         $a3, 0x4A($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4A);
    // 0x00242FA4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00242FA8: addiu       $a2, $a2, -0x1398
    ctx->r6 = ADD32(ctx->r6, -0X1398);
    // 0x00242FAC: jal         0x00241868
    // 0x00242FB0: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00242FB0: nop

    after_0:
    // 0x00242FB4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00242FB8: jr          $ra
    // 0x00242FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00242FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00242FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00242FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00242FC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00242FC8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00242FCC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00242FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00242FD4: beq         $a2, $v0, L_00242FE4
    if (ctx->r6 == ctx->r2) {
        // 0x00242FD8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00242FE4;
    }
    // 0x00242FD8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00242FDC: bne         $a2, $v0, L_00242FE8
    if (ctx->r6 != ctx->r2) {
        // 0x00242FE0: nop
    
            goto L_00242FE8;
    }
    // 0x00242FE0: nop

L_00242FE4:
    // 0x00242FE4: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00242FE8:
    // 0x00242FE8: lhu         $a3, 0x4C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4C);
    // 0x00242FEC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00242FF0: addiu       $a2, $a2, -0x1368
    ctx->r6 = ADD32(ctx->r6, -0X1368);
    // 0x00242FF4: jal         0x00241868
    // 0x00242FF8: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00242FF8: nop

    after_0:
    // 0x00242FFC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243000: jr          $ra
    // 0x00243004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024300C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243010: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243014: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024301C: beq         $a2, $v0, L_0024302C
    if (ctx->r6 == ctx->r2) {
        // 0x00243020: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024302C;
    }
    // 0x00243020: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243024: bne         $a2, $v0, L_00243030
    if (ctx->r6 != ctx->r2) {
        // 0x00243028: nop
    
            goto L_00243030;
    }
    // 0x00243028: nop

L_0024302C:
    // 0x0024302C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243030:
    // 0x00243030: lhu         $a3, 0x4C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4C);
    // 0x00243034: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243038: addiu       $a2, $a2, -0x1338
    ctx->r6 = ADD32(ctx->r6, -0X1338);
    // 0x0024303C: jal         0x00241868
    // 0x00243040: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243040: nop

    after_0:
    // 0x00243044: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243048: jr          $ra
    // 0x0024304C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024304C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243054: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243058: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024305C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243064: beq         $a2, $v0, L_00243074
    if (ctx->r6 == ctx->r2) {
        // 0x00243068: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243074;
    }
    // 0x00243068: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024306C: bne         $a2, $v0, L_00243078
    if (ctx->r6 != ctx->r2) {
        // 0x00243070: nop
    
            goto L_00243078;
    }
    // 0x00243070: nop

L_00243074:
    // 0x00243074: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243078:
    // 0x00243078: lhu         $a3, 0x4C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4C);
    // 0x0024307C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243080: addiu       $a2, $a2, -0x1308
    ctx->r6 = ADD32(ctx->r6, -0X1308);
    // 0x00243084: jal         0x00241868
    // 0x00243088: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243088: nop

    after_0:
    // 0x0024308C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243090: jr          $ra
    // 0x00243094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024309C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002430A0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002430A4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002430A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002430AC: beq         $a2, $v0, L_002430BC
    if (ctx->r6 == ctx->r2) {
        // 0x002430B0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002430BC;
    }
    // 0x002430B0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002430B4: bne         $a2, $v0, L_002430C0
    if (ctx->r6 != ctx->r2) {
        // 0x002430B8: nop
    
            goto L_002430C0;
    }
    // 0x002430B8: nop

L_002430BC:
    // 0x002430BC: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002430C0:
    // 0x002430C0: lhu         $a3, 0x4E($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4E);
    // 0x002430C4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002430C8: addiu       $a2, $a2, -0x12D8
    ctx->r6 = ADD32(ctx->r6, -0X12D8);
    // 0x002430CC: jal         0x00241868
    // 0x002430D0: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002430D0: nop

    after_0:
    // 0x002430D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002430D8: jr          $ra
    // 0x002430DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002430DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002430E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002430E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002430E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002430E8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002430EC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002430F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002430F4: beq         $a2, $v0, L_00243104
    if (ctx->r6 == ctx->r2) {
        // 0x002430F8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243104;
    }
    // 0x002430F8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002430FC: bne         $a2, $v0, L_00243108
    if (ctx->r6 != ctx->r2) {
        // 0x00243100: nop
    
            goto L_00243108;
    }
    // 0x00243100: nop

L_00243104:
    // 0x00243104: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243108:
    // 0x00243108: lhu         $a3, 0x4E($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4E);
    // 0x0024310C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243110: addiu       $a2, $a2, -0x12A8
    ctx->r6 = ADD32(ctx->r6, -0X12A8);
    // 0x00243114: jal         0x00241868
    // 0x00243118: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243118: nop

    after_0:
    // 0x0024311C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243120: jr          $ra
    // 0x00243124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024312C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243130: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243134: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024313C: beq         $a2, $v0, L_0024314C
    if (ctx->r6 == ctx->r2) {
        // 0x00243140: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024314C;
    }
    // 0x00243140: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243144: bne         $a2, $v0, L_00243150
    if (ctx->r6 != ctx->r2) {
        // 0x00243148: nop
    
            goto L_00243150;
    }
    // 0x00243148: nop

L_0024314C:
    // 0x0024314C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243150:
    // 0x00243150: lhu         $a3, 0x4C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4C);
    // 0x00243154: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243158: addiu       $a2, $a2, -0x1308
    ctx->r6 = ADD32(ctx->r6, -0X1308);
    // 0x0024315C: jal         0x00241868
    // 0x00243160: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243160: nop

    after_0:
    // 0x00243164: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243168: jr          $ra
    // 0x0024316C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024316C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243174: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243178: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024317C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243184: beq         $a2, $v0, L_00243194
    if (ctx->r6 == ctx->r2) {
        // 0x00243188: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243194;
    }
    // 0x00243188: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024318C: bne         $a2, $v0, L_00243198
    if (ctx->r6 != ctx->r2) {
        // 0x00243190: nop
    
            goto L_00243198;
    }
    // 0x00243190: nop

L_00243194:
    // 0x00243194: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243198:
    // 0x00243198: lhu         $a3, 0x50($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X50);
    // 0x0024319C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002431A0: addiu       $a2, $a2, -0x1248
    ctx->r6 = ADD32(ctx->r6, -0X1248);
    // 0x002431A4: jal         0x00241868
    // 0x002431A8: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002431A8: nop

    after_0:
    // 0x002431AC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002431B0: jr          $ra
    // 0x002431B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002431B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002431B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002431B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002431BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002431C0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002431C4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002431C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002431CC: beq         $a2, $v0, L_002431DC
    if (ctx->r6 == ctx->r2) {
        // 0x002431D0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002431DC;
    }
    // 0x002431D0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002431D4: bne         $a2, $v0, L_002431E0
    if (ctx->r6 != ctx->r2) {
        // 0x002431D8: nop
    
            goto L_002431E0;
    }
    // 0x002431D8: nop

L_002431DC:
    // 0x002431DC: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002431E0:
    // 0x002431E0: lhu         $a3, 0x50($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X50);
    // 0x002431E4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002431E8: addiu       $a2, $a2, -0x1218
    ctx->r6 = ADD32(ctx->r6, -0X1218);
    // 0x002431EC: jal         0x00241868
    // 0x002431F0: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002431F0: nop

    after_0:
    // 0x002431F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002431F8: jr          $ra
    // 0x002431FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002431FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243204: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243208: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024320C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243214: beq         $a2, $v0, L_00243224
    if (ctx->r6 == ctx->r2) {
        // 0x00243218: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243224;
    }
    // 0x00243218: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024321C: bne         $a2, $v0, L_00243228
    if (ctx->r6 != ctx->r2) {
        // 0x00243220: nop
    
            goto L_00243228;
    }
    // 0x00243220: nop

L_00243224:
    // 0x00243224: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243228:
    // 0x00243228: lhu         $a3, 0x4C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X4C);
    // 0x0024322C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243230: addiu       $a2, $a2, -0x1308
    ctx->r6 = ADD32(ctx->r6, -0X1308);
    // 0x00243234: jal         0x00241868
    // 0x00243238: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243238: nop

    after_0:
    // 0x0024323C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243240: jr          $ra
    // 0x00243244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024324C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243250: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243254: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024325C: beq         $a2, $v0, L_0024326C
    if (ctx->r6 == ctx->r2) {
        // 0x00243260: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024326C;
    }
    // 0x00243260: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243264: bne         $a2, $v0, L_00243270
    if (ctx->r6 != ctx->r2) {
        // 0x00243268: nop
    
            goto L_00243270;
    }
    // 0x00243268: nop

L_0024326C:
    // 0x0024326C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243270:
    // 0x00243270: lhu         $a3, 0x52($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X52);
    // 0x00243274: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243278: addiu       $a2, $a2, -0x11B8
    ctx->r6 = ADD32(ctx->r6, -0X11B8);
    // 0x0024327C: jal         0x00241868
    // 0x00243280: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243280: nop

    after_0:
    // 0x00243284: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243288: jr          $ra
    // 0x0024328C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024328C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243294: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243298: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024329C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002432A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002432A4: beq         $a2, $v0, L_002432B4
    if (ctx->r6 == ctx->r2) {
        // 0x002432A8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002432B4;
    }
    // 0x002432A8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002432AC: bne         $a2, $v0, L_002432B8
    if (ctx->r6 != ctx->r2) {
        // 0x002432B0: nop
    
            goto L_002432B8;
    }
    // 0x002432B0: nop

L_002432B4:
    // 0x002432B4: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002432B8:
    // 0x002432B8: lhu         $a3, 0x52($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X52);
    // 0x002432BC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002432C0: addiu       $a2, $a2, -0x1160
    ctx->r6 = ADD32(ctx->r6, -0X1160);
    // 0x002432C4: jal         0x00241868
    // 0x002432C8: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002432C8: nop

    after_0:
    // 0x002432CC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002432D0: jr          $ra
    // 0x002432D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002432D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002432D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002432D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002432DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002432E0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002432E4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002432E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002432EC: beq         $a2, $v0, L_002432FC
    if (ctx->r6 == ctx->r2) {
        // 0x002432F0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002432FC;
    }
    // 0x002432F0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002432F4: bne         $a2, $v0, L_00243300
    if (ctx->r6 != ctx->r2) {
        // 0x002432F8: nop
    
            goto L_00243300;
    }
    // 0x002432F8: nop

L_002432FC:
    // 0x002432FC: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243300:
    // 0x00243300: lhu         $a3, 0x52($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X52);
    // 0x00243304: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243308: addiu       $a2, $a2, -0x1130
    ctx->r6 = ADD32(ctx->r6, -0X1130);
    // 0x0024330C: jal         0x00241868
    // 0x00243310: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243310: nop

    after_0:
    // 0x00243314: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243318: jr          $ra
    // 0x0024331C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024331C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243324: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243328: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024332C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243334: beq         $a2, $v0, L_00243344
    if (ctx->r6 == ctx->r2) {
        // 0x00243338: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243344;
    }
    // 0x00243338: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024333C: bne         $a2, $v0, L_00243348
    if (ctx->r6 != ctx->r2) {
        // 0x00243340: nop
    
            goto L_00243348;
    }
    // 0x00243340: nop

L_00243344:
    // 0x00243344: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243348:
    // 0x00243348: lhu         $a3, 0x56($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X56);
    // 0x0024334C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243350: addiu       $a2, $a2, -0x1100
    ctx->r6 = ADD32(ctx->r6, -0X1100);
    // 0x00243354: jal         0x00241868
    // 0x00243358: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243358: nop

    after_0:
    // 0x0024335C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243360: jr          $ra
    // 0x00243364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024336C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243370: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243374: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024337C: beq         $a2, $v0, L_0024338C
    if (ctx->r6 == ctx->r2) {
        // 0x00243380: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024338C;
    }
    // 0x00243380: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243384: bne         $a2, $v0, L_00243390
    if (ctx->r6 != ctx->r2) {
        // 0x00243388: nop
    
            goto L_00243390;
    }
    // 0x00243388: nop

L_0024338C:
    // 0x0024338C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243390:
    // 0x00243390: lhu         $a3, 0x56($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X56);
    // 0x00243394: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243398: addiu       $a2, $a2, -0x10D0
    ctx->r6 = ADD32(ctx->r6, -0X10D0);
    // 0x0024339C: jal         0x00241868
    // 0x002433A0: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002433A0: nop

    after_0:
    // 0x002433A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002433A8: jr          $ra
    // 0x002433AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002433AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002433B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002433B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002433B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002433B8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002433BC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002433C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002433C4: beq         $a2, $v0, L_002433D4
    if (ctx->r6 == ctx->r2) {
        // 0x002433C8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002433D4;
    }
    // 0x002433C8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002433CC: bne         $a2, $v0, L_002433D8
    if (ctx->r6 != ctx->r2) {
        // 0x002433D0: nop
    
            goto L_002433D8;
    }
    // 0x002433D0: nop

L_002433D4:
    // 0x002433D4: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002433D8:
    // 0x002433D8: lhu         $a3, 0x56($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X56);
    // 0x002433DC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002433E0: addiu       $a2, $a2, -0x10A0
    ctx->r6 = ADD32(ctx->r6, -0X10A0);
    // 0x002433E4: jal         0x00241868
    // 0x002433E8: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002433E8: nop

    after_0:
    // 0x002433EC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002433F0: jr          $ra
    // 0x002433F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002433F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002433F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002433F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002433FC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243400: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243404: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024340C: beq         $a2, $v0, L_0024341C
    if (ctx->r6 == ctx->r2) {
        // 0x00243410: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024341C;
    }
    // 0x00243410: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243414: bne         $a2, $v0, L_00243420
    if (ctx->r6 != ctx->r2) {
        // 0x00243418: nop
    
            goto L_00243420;
    }
    // 0x00243418: nop

L_0024341C:
    // 0x0024341C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243420:
    // 0x00243420: lhu         $a3, 0x58($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X58);
    // 0x00243424: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243428: addiu       $a2, $a2, -0x1070
    ctx->r6 = ADD32(ctx->r6, -0X1070);
    // 0x0024342C: jal         0x00241868
    // 0x00243430: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243430: nop

    after_0:
    // 0x00243434: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243438: jr          $ra
    // 0x0024343C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024343C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243444: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243448: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024344C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243454: beq         $a2, $v0, L_00243464
    if (ctx->r6 == ctx->r2) {
        // 0x00243458: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243464;
    }
    // 0x00243458: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024345C: bne         $a2, $v0, L_00243468
    if (ctx->r6 != ctx->r2) {
        // 0x00243460: nop
    
            goto L_00243468;
    }
    // 0x00243460: nop

L_00243464:
    // 0x00243464: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243468:
    // 0x00243468: lhu         $a3, 0x58($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X58);
    // 0x0024346C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243470: addiu       $a2, $a2, -0x1040
    ctx->r6 = ADD32(ctx->r6, -0X1040);
    // 0x00243474: jal         0x00241868
    // 0x00243478: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243478: nop

    after_0:
    // 0x0024347C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243480: jr          $ra
    // 0x00243484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024348C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243490: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243494: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024349C: beq         $a2, $v0, L_002434AC
    if (ctx->r6 == ctx->r2) {
        // 0x002434A0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002434AC;
    }
    // 0x002434A0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002434A4: bne         $a2, $v0, L_002434B0
    if (ctx->r6 != ctx->r2) {
        // 0x002434A8: nop
    
            goto L_002434B0;
    }
    // 0x002434A8: nop

L_002434AC:
    // 0x002434AC: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002434B0:
    // 0x002434B0: lhu         $a3, 0x58($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X58);
    // 0x002434B4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002434B8: addiu       $a2, $a2, -0x1010
    ctx->r6 = ADD32(ctx->r6, -0X1010);
    // 0x002434BC: jal         0x00241868
    // 0x002434C0: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002434C0: nop

    after_0:
    // 0x002434C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002434C8: jr          $ra
    // 0x002434CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002434CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002434D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002434D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002434D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002434D8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002434DC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002434E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002434E4: beq         $a2, $v0, L_002434F4
    if (ctx->r6 == ctx->r2) {
        // 0x002434E8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002434F4;
    }
    // 0x002434E8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002434EC: bne         $a2, $v0, L_002434F8
    if (ctx->r6 != ctx->r2) {
        // 0x002434F0: nop
    
            goto L_002434F8;
    }
    // 0x002434F0: nop

L_002434F4:
    // 0x002434F4: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002434F8:
    // 0x002434F8: lhu         $a3, 0x5A($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X5A);
    // 0x002434FC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243500: addiu       $a2, $a2, -0xFE0
    ctx->r6 = ADD32(ctx->r6, -0XFE0);
    // 0x00243504: jal         0x00241868
    // 0x00243508: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243508: nop

    after_0:
    // 0x0024350C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243510: jr          $ra
    // 0x00243514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024351C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243520: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243524: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024352C: beq         $a2, $v0, L_0024353C
    if (ctx->r6 == ctx->r2) {
        // 0x00243530: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024353C;
    }
    // 0x00243530: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243534: bne         $a2, $v0, L_00243540
    if (ctx->r6 != ctx->r2) {
        // 0x00243538: nop
    
            goto L_00243540;
    }
    // 0x00243538: nop

L_0024353C:
    // 0x0024353C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243540:
    // 0x00243540: lhu         $a3, 0x5A($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X5A);
    // 0x00243544: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243548: addiu       $a2, $a2, -0xFB0
    ctx->r6 = ADD32(ctx->r6, -0XFB0);
    // 0x0024354C: jal         0x00241868
    // 0x00243550: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243550: nop

    after_0:
    // 0x00243554: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243558: jr          $ra
    // 0x0024355C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024355C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243564: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243568: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024356C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243574: beq         $a2, $v0, L_00243584
    if (ctx->r6 == ctx->r2) {
        // 0x00243578: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243584;
    }
    // 0x00243578: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024357C: bne         $a2, $v0, L_00243588
    if (ctx->r6 != ctx->r2) {
        // 0x00243580: nop
    
            goto L_00243588;
    }
    // 0x00243580: nop

L_00243584:
    // 0x00243584: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243588:
    // 0x00243588: lhu         $a3, 0x5A($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X5A);
    // 0x0024358C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243590: addiu       $a2, $a2, -0xF80
    ctx->r6 = ADD32(ctx->r6, -0XF80);
    // 0x00243594: jal         0x00241868
    // 0x00243598: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243598: nop

    after_0:
    // 0x0024359C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002435A0: jr          $ra
    // 0x002435A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002435A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002435A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002435A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002435AC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002435B0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002435B4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002435B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002435BC: beq         $a2, $v0, L_002435CC
    if (ctx->r6 == ctx->r2) {
        // 0x002435C0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002435CC;
    }
    // 0x002435C0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002435C4: bne         $a2, $v0, L_002435D0
    if (ctx->r6 != ctx->r2) {
        // 0x002435C8: nop
    
            goto L_002435D0;
    }
    // 0x002435C8: nop

L_002435CC:
    // 0x002435CC: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002435D0:
    // 0x002435D0: lhu         $a3, 0x5C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X5C);
    // 0x002435D4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002435D8: addiu       $a2, $a2, -0xF50
    ctx->r6 = ADD32(ctx->r6, -0XF50);
    // 0x002435DC: jal         0x00241868
    // 0x002435E0: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002435E0: nop

    after_0:
    // 0x002435E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002435E8: jr          $ra
    // 0x002435EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002435EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002435F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002435F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002435F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002435F8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002435FC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243604: beq         $a2, $v0, L_00243614
    if (ctx->r6 == ctx->r2) {
        // 0x00243608: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243614;
    }
    // 0x00243608: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024360C: bne         $a2, $v0, L_00243618
    if (ctx->r6 != ctx->r2) {
        // 0x00243610: nop
    
            goto L_00243618;
    }
    // 0x00243610: nop

L_00243614:
    // 0x00243614: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243618:
    // 0x00243618: lhu         $a3, 0x5C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X5C);
    // 0x0024361C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243620: addiu       $a2, $a2, -0xF20
    ctx->r6 = ADD32(ctx->r6, -0XF20);
    // 0x00243624: jal         0x00241868
    // 0x00243628: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243628: nop

    after_0:
    // 0x0024362C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243630: jr          $ra
    // 0x00243634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024363C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243640: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243644: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024364C: beq         $a2, $v0, L_0024365C
    if (ctx->r6 == ctx->r2) {
        // 0x00243650: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024365C;
    }
    // 0x00243650: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243654: bne         $a2, $v0, L_00243660
    if (ctx->r6 != ctx->r2) {
        // 0x00243658: nop
    
            goto L_00243660;
    }
    // 0x00243658: nop

L_0024365C:
    // 0x0024365C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243660:
    // 0x00243660: lhu         $a3, 0x5C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X5C);
    // 0x00243664: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243668: addiu       $a2, $a2, -0xEF0
    ctx->r6 = ADD32(ctx->r6, -0XEF0);
    // 0x0024366C: jal         0x00241868
    // 0x00243670: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243670: nop

    after_0:
    // 0x00243674: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243678: jr          $ra
    // 0x0024367C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024367C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243684: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243688: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024368C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243694: beq         $a2, $v0, L_002436A4
    if (ctx->r6 == ctx->r2) {
        // 0x00243698: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002436A4;
    }
    // 0x00243698: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024369C: bne         $a2, $v0, L_002436A8
    if (ctx->r6 != ctx->r2) {
        // 0x002436A0: nop
    
            goto L_002436A8;
    }
    // 0x002436A0: nop

L_002436A4:
    // 0x002436A4: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002436A8:
    // 0x002436A8: lhu         $a3, 0x48($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X48);
    // 0x002436AC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002436B0: addiu       $a2, $a2, -0xEC0
    ctx->r6 = ADD32(ctx->r6, -0XEC0);
    // 0x002436B4: jal         0x00241868
    // 0x002436B8: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002436B8: nop

    after_0:
    // 0x002436BC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002436C0: jr          $ra
    // 0x002436C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002436C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002436C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002436C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002436CC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002436D0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002436D4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002436D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002436DC: beq         $a2, $v0, L_002436EC
    if (ctx->r6 == ctx->r2) {
        // 0x002436E0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002436EC;
    }
    // 0x002436E0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002436E4: bne         $a2, $v0, L_002436F0
    if (ctx->r6 != ctx->r2) {
        // 0x002436E8: nop
    
            goto L_002436F0;
    }
    // 0x002436E8: nop

L_002436EC:
    // 0x002436EC: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002436F0:
    // 0x002436F0: lhu         $a3, 0x48($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X48);
    // 0x002436F4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002436F8: addiu       $a2, $a2, -0xE90
    ctx->r6 = ADD32(ctx->r6, -0XE90);
    // 0x002436FC: jal         0x00241868
    // 0x00243700: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243700: nop

    after_0:
    // 0x00243704: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243708: jr          $ra
    // 0x0024370C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024370C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243714: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243718: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024371C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243724: beq         $a2, $v0, L_00243734
    if (ctx->r6 == ctx->r2) {
        // 0x00243728: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243734;
    }
    // 0x00243728: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024372C: bne         $a2, $v0, L_00243738
    if (ctx->r6 != ctx->r2) {
        // 0x00243730: nop
    
            goto L_00243738;
    }
    // 0x00243730: nop

L_00243734:
    // 0x00243734: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243738:
    // 0x00243738: lhu         $a3, 0x48($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X48);
    // 0x0024373C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243740: addiu       $a2, $a2, -0xE60
    ctx->r6 = ADD32(ctx->r6, -0XE60);
    // 0x00243744: jal         0x00241868
    // 0x00243748: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243748: nop

    after_0:
    // 0x0024374C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243750: jr          $ra
    // 0x00243754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024375C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243760: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243764: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243768: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024376C: beq         $a2, $v0, L_0024377C
    if (ctx->r6 == ctx->r2) {
        // 0x00243770: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024377C;
    }
    // 0x00243770: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243774: bne         $a2, $v0, L_00243780
    if (ctx->r6 != ctx->r2) {
        // 0x00243778: nop
    
            goto L_00243780;
    }
    // 0x00243778: nop

L_0024377C:
    // 0x0024377C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243780:
    // 0x00243780: lhu         $a3, 0x48($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X48);
    // 0x00243784: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243788: addiu       $a2, $a2, -0xE30
    ctx->r6 = ADD32(ctx->r6, -0XE30);
    // 0x0024378C: jal         0x00241868
    // 0x00243790: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243790: nop

    after_0:
    // 0x00243794: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243798: jr          $ra
    // 0x0024379C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024379C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002437A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002437A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002437A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002437A8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002437AC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002437B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002437B4: beq         $a2, $v0, L_002437C4
    if (ctx->r6 == ctx->r2) {
        // 0x002437B8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002437C4;
    }
    // 0x002437B8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002437BC: bne         $a2, $v0, L_002437C8
    if (ctx->r6 != ctx->r2) {
        // 0x002437C0: nop
    
            goto L_002437C8;
    }
    // 0x002437C0: nop

L_002437C4:
    // 0x002437C4: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002437C8:
    // 0x002437C8: lhu         $a3, 0x48($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X48);
    // 0x002437CC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002437D0: addiu       $a2, $a2, -0xE00
    ctx->r6 = ADD32(ctx->r6, -0XE00);
    // 0x002437D4: jal         0x00241868
    // 0x002437D8: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002437D8: nop

    after_0:
    // 0x002437DC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002437E0: jr          $ra
    // 0x002437E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002437E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002437E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002437E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002437EC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002437F0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002437F4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002437F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002437FC: beq         $a2, $v0, L_0024380C
    if (ctx->r6 == ctx->r2) {
        // 0x00243800: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024380C;
    }
    // 0x00243800: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243804: bne         $a2, $v0, L_00243810
    if (ctx->r6 != ctx->r2) {
        // 0x00243808: nop
    
            goto L_00243810;
    }
    // 0x00243808: nop

L_0024380C:
    // 0x0024380C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243810:
    // 0x00243810: lhu         $a3, 0x48($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X48);
    // 0x00243814: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243818: addiu       $a2, $a2, -0xDD0
    ctx->r6 = ADD32(ctx->r6, -0XDD0);
    // 0x0024381C: jal         0x00241868
    // 0x00243820: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243820: nop

    after_0:
    // 0x00243824: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243828: jr          $ra
    // 0x0024382C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024382C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243834: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243838: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024383C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243844: beq         $a2, $v0, L_00243854
    if (ctx->r6 == ctx->r2) {
        // 0x00243848: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243854;
    }
    // 0x00243848: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024384C: bne         $a2, $v0, L_00243858
    if (ctx->r6 != ctx->r2) {
        // 0x00243850: nop
    
            goto L_00243858;
    }
    // 0x00243850: nop

L_00243854:
    // 0x00243854: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243858:
    // 0x00243858: lhu         $a3, 0x46($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X46);
    // 0x0024385C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243860: addiu       $a2, $a2, -0xDA0
    ctx->r6 = ADD32(ctx->r6, -0XDA0);
    // 0x00243864: jal         0x00241868
    // 0x00243868: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243868: nop

    after_0:
    // 0x0024386C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243870: jr          $ra
    // 0x00243874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024387C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243880: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243884: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024388C: beq         $a2, $v0, L_0024389C
    if (ctx->r6 == ctx->r2) {
        // 0x00243890: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024389C;
    }
    // 0x00243890: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243894: bne         $a2, $v0, L_002438A0
    if (ctx->r6 != ctx->r2) {
        // 0x00243898: nop
    
            goto L_002438A0;
    }
    // 0x00243898: nop

L_0024389C:
    // 0x0024389C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002438A0:
    // 0x002438A0: lhu         $a3, 0x46($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X46);
    // 0x002438A4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002438A8: addiu       $a2, $a2, -0xD70
    ctx->r6 = ADD32(ctx->r6, -0XD70);
    // 0x002438AC: jal         0x00241868
    // 0x002438B0: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002438B0: nop

    after_0:
    // 0x002438B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002438B8: jr          $ra
    // 0x002438BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002438BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002438C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002438C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002438C4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002438C8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002438CC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002438D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002438D4: beq         $a2, $v0, L_002438E4
    if (ctx->r6 == ctx->r2) {
        // 0x002438D8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002438E4;
    }
    // 0x002438D8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002438DC: bne         $a2, $v0, L_002438E8
    if (ctx->r6 != ctx->r2) {
        // 0x002438E0: nop
    
            goto L_002438E8;
    }
    // 0x002438E0: nop

L_002438E4:
    // 0x002438E4: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002438E8:
    // 0x002438E8: lhu         $a3, 0x46($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X46);
    // 0x002438EC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002438F0: addiu       $a2, $a2, -0xD40
    ctx->r6 = ADD32(ctx->r6, -0XD40);
    // 0x002438F4: jal         0x00241868
    // 0x002438F8: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002438F8: nop

    after_0:
    // 0x002438FC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243900: jr          $ra
    // 0x00243904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024390C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243910: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00243914: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024391C: beq         $a2, $v0, L_0024392C
    if (ctx->r6 == ctx->r2) {
        // 0x00243920: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024392C;
    }
    // 0x00243920: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243924: bne         $a2, $v0, L_00243930
    if (ctx->r6 != ctx->r2) {
        // 0x00243928: nop
    
            goto L_00243930;
    }
    // 0x00243928: nop

L_0024392C:
    // 0x0024392C: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243930:
    // 0x00243930: lhu         $a3, 0x46($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X46);
    // 0x00243934: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243938: addiu       $a2, $a2, -0xD10
    ctx->r6 = ADD32(ctx->r6, -0XD10);
    // 0x0024393C: jal         0x00241868
    // 0x00243940: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243940: nop

    after_0:
    // 0x00243944: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243948: jr          $ra
    // 0x0024394C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024394C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00243954: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00243958: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024395C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00243960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243964: beq         $a2, $v0, L_00243974
    if (ctx->r6 == ctx->r2) {
        // 0x00243968: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243974;
    }
    // 0x00243968: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024396C: bne         $a2, $v0, L_00243978
    if (ctx->r6 != ctx->r2) {
        // 0x00243970: nop
    
            goto L_00243978;
    }
    // 0x00243970: nop

L_00243974:
    // 0x00243974: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00243978:
    // 0x00243978: lhu         $a3, 0x46($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X46);
    // 0x0024397C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243980: addiu       $a2, $a2, -0xCE0
    ctx->r6 = ADD32(ctx->r6, -0XCE0);
    // 0x00243984: jal         0x00241868
    // 0x00243988: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x00243988: nop

    after_0:
    // 0x0024398C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00243990: jr          $ra
    // 0x00243994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00243994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00243998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024399C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002439A0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002439A4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002439A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002439AC: beq         $a2, $v0, L_002439BC
    if (ctx->r6 == ctx->r2) {
        // 0x002439B0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002439BC;
    }
    // 0x002439B0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002439B4: bne         $a2, $v0, L_002439C0
    if (ctx->r6 != ctx->r2) {
        // 0x002439B8: nop
    
            goto L_002439C0;
    }
    // 0x002439B8: nop

L_002439BC:
    // 0x002439BC: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002439C0:
    // 0x002439C0: lhu         $a3, 0x46($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X46);
    // 0x002439C4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x002439C8: addiu       $a2, $a2, -0xCB0
    ctx->r6 = ADD32(ctx->r6, -0XCB0);
    // 0x002439CC: jal         0x00241868
    // 0x002439D0: nop

    func_00241868(rdram, ctx);
        goto after_0;
    // 0x002439D0: nop

    after_0:
    // 0x002439D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002439D8: jr          $ra
    // 0x002439DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002439DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002439E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002439E0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x002439E4: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x002439E8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x002439EC: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x002439F0: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x002439F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x002439F8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x002439FC: addiu       $v0, $v0, -0x7598
    ctx->r2 = ADD32(ctx->r2, -0X7598);
    // 0x00243A00: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00243A04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00243A08: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x00243A0C: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x00243A10: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x00243A14: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x00243A18: sdc1        $f23, 0x88($sp)
    CHECK_FR(ctx, 23);
    SD(ctx->f23.u64, 0X88, ctx->r29);
    // 0x00243A1C: sdc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X80, ctx->r29);
    // 0x00243A20: sdc1        $f21, 0x78($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X78, ctx->r29);
    // 0x00243A24: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x00243A28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00243A2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00243A30: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x00243A34: lw          $a1, 0xC4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC4);
    // 0x00243A38: lw          $a2, 0xD0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XD0);
    // 0x00243A3C: jal         0x0021FB70
    // 0x00243A40: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    func_0021FB70(rdram, ctx);
        goto after_0;
    // 0x00243A40: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    after_0:
    // 0x00243A44: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x00243A48: beq         $s3, $zero, L_00243CB8
    if (ctx->r19 == 0) {
        // 0x00243A4C: nop
    
            goto L_00243CB8;
    }
    // 0x00243A4C: nop

    // 0x00243A50: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x00243A54: jal         0x0021098C
    // 0x00243A58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x00243A58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x00243A5C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00243A60: lb          $v0, 0x19($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X19);
    // 0x00243A64: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x00243A68: beql        $v0, $a0, L_00243CB0
    if (ctx->r2 == ctx->r4) {
        // 0x00243A6C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00243CB0;
    }
    goto skip_0;
    // 0x00243A6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x00243A70: lb          $v0, 0x18($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X18);
    // 0x00243A74: beql        $v0, $a0, L_00243CB0
    if (ctx->r2 == ctx->r4) {
        // 0x00243A78: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00243CB0;
    }
    goto skip_1;
    // 0x00243A78: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_1:
    // 0x00243A7C: lb          $s4, 0x1A($v1)
    ctx->r20 = MEM_B(ctx->r3, 0X1A);
    // 0x00243A80: beql        $s4, $zero, L_00243CB0
    if (ctx->r20 == 0) {
        // 0x00243A84: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00243CB0;
    }
    goto skip_2;
    // 0x00243A84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_2:
    // 0x00243A88: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x00243A8C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x00243A90: beq         $v0, $zero, L_00243C40
    if (ctx->r2 == 0) {
        // 0x00243A94: nop
    
            goto L_00243C40;
    }
    // 0x00243A94: nop

    // 0x00243A98: lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4);
    // 0x00243A9C: beq         $v0, $zero, L_00243C40
    if (ctx->r2 == 0) {
        // 0x00243AA0: nop
    
            goto L_00243C40;
    }
    // 0x00243AA0: nop

    // 0x00243AA4: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x00243AA8: bne         $v0, $zero, L_00243ABC
    if (ctx->r2 != 0) {
        // 0x00243AAC: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_00243ABC;
    }
    // 0x00243AAC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x00243AB0: lb          $v1, 0x30($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X30);
    // 0x00243AB4: bne         $v1, $v0, L_00243C40
    if (ctx->r3 != ctx->r2) {
        // 0x00243AB8: nop
    
            goto L_00243C40;
    }
    // 0x00243AB8: nop

L_00243ABC:
    // 0x00243ABC: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x00243AC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00243AC4: lwc1        $f20, -0x7584($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7584);
    // 0x00243AC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00243ACC: jal         0x00227FEC
    // 0x00243AD0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_00227FEC(rdram, ctx);
        goto after_2;
    // 0x00243AD0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x00243AD4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x00243AD8: lwc1        $f1, 0x8($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X8);
    // 0x00243ADC: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00243AE0: swc1        $f1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x00243AE4: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x00243AE8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x00243AEC: lb          $v1, 0x30($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X30);
    // 0x00243AF0: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x00243AF4: bne         $v1, $v0, L_00243B24
    if (ctx->r3 != ctx->r2) {
        // 0x00243AF8: nop
    
            goto L_00243B24;
    }
    // 0x00243AF8: nop

    // 0x00243AFC: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x00243B00: addiu       $t3, $t3, -0xC80
    ctx->r11 = ADD32(ctx->r11, -0XC80);
    // 0x00243B04: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x00243B08: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x00243B0C: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x00243B10: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x00243B14: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x00243B18: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x00243B1C: j           L_00243B5C
    // 0x00243B20: nop

        goto L_00243B5C;
    // 0x00243B20: nop

L_00243B24:
    // 0x00243B24: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x00243B28: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x00243B2C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x00243B30: lw          $a0, 0x74($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X74);
    // 0x00243B34: jal         0x00227FEC
    // 0x00243B38: nop

    func_00227FEC(rdram, ctx);
        goto after_3;
    // 0x00243B38: nop

    after_3:
    // 0x00243B3C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x00243B40: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x00243B44: lwc1        $f1, 0x8($v0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r2, 0X8);
    // 0x00243B48: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00243B4C: swc1        $f1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x00243B50: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x00243B54: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x00243B58: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_00243B5C:
    // 0x00243B5C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x00243B60: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x00243B64: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x00243B68: jal         0x00241D2C
    // 0x00243B6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00241D2C(rdram, ctx);
        goto after_4;
    // 0x00243B6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x00243B70: addiu       $v0, $zero, 0x7D3
    ctx->r2 = ADD32(0, 0X7D3);
    // 0x00243B74: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00243B78: beq         $v1, $v0, L_00243BB4
    if (ctx->r3 == ctx->r2) {
        // 0x00243B7C: neg.s       $f23, $f0
        CHECK_FR(ctx, 23);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f23.fl = -ctx->f0.fl;
            goto L_00243BB4;
    }
    // 0x00243B7C: neg.s       $f23, $f0
    CHECK_FR(ctx, 23);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f23.fl = -ctx->f0.fl;
    // 0x00243B80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00243B84: lwc1        $f0, -0x7580($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7580);
    // 0x00243B88: c.lt.s      $f23, $f0
    CHECK_FR(ctx, 23);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f23.fl < ctx->f0.fl;
    // 0x00243B8C: nop

    // 0x00243B90: bc1tl       L_00243BB4
    if (c1cs) {
        // 0x00243B94: mov.s       $f23, $f0
        CHECK_FR(ctx, 23);
    CHECK_FR(ctx, 0);
    ctx->f23.fl = ctx->f0.fl;
            goto L_00243BB4;
    }
    goto skip_3;
    // 0x00243B94: mov.s       $f23, $f0
    CHECK_FR(ctx, 23);
    CHECK_FR(ctx, 0);
    ctx->f23.fl = ctx->f0.fl;
    skip_3:
    // 0x00243B98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00243B9C: lwc1        $f0, -0x757C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X757C);
    // 0x00243BA0: c.lt.s      $f0, $f23
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 23);
    c1cs = ctx->f0.fl < ctx->f23.fl;
    // 0x00243BA4: nop

    // 0x00243BA8: bc1f        L_00243BB8
    if (!c1cs) {
        // 0x00243BAC: addiu       $s0, $sp, 0x40
        ctx->r16 = ADD32(ctx->r29, 0X40);
            goto L_00243BB8;
    }
    // 0x00243BAC: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x00243BB0: mov.s       $f23, $f0
    CHECK_FR(ctx, 23);
    CHECK_FR(ctx, 0);
    ctx->f23.fl = ctx->f0.fl;
L_00243BB4:
    // 0x00243BB4: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
L_00243BB8:
    // 0x00243BB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00243BBC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x00243BC0: jal         0x00213074
    // 0x00243BC4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_00213074(rdram, ctx);
        goto after_5;
    // 0x00243BC4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x00243BC8: jal         0x00213708
    // 0x00243BCC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00213708(rdram, ctx);
        goto after_6;
    // 0x00243BCC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x00243BD0: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00243BD4: addiu       $v0, $zero, 0x7D3
    ctx->r2 = ADD32(0, 0X7D3);
    // 0x00243BD8: bne         $v1, $v0, L_00243C08
    if (ctx->r3 != ctx->r2) {
        // 0x00243BDC: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_00243C08;
    }
    // 0x00243BDC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x00243BE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00243BE4: lwc1        $f0, -0x7578($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7578);
    // 0x00243BE8: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x00243BEC: nop

    // 0x00243BF0: bc1tl       L_00243C48
    if (c1cs) {
        // 0x00243BF4: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_00243C48;
    }
    goto skip_4;
    // 0x00243BF4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_4:
    // 0x00243BF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00243BFC: lwc1        $f0, -0x7574($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7574);
    // 0x00243C00: j           L_00243C28
    // 0x00243C04: nop

        goto L_00243C28;
    // 0x00243C04: nop

L_00243C08:
    // 0x00243C08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00243C0C: lwc1        $f0, -0x7570($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7570);
    // 0x00243C10: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x00243C14: nop

    // 0x00243C18: bc1tl       L_00243C48
    if (c1cs) {
        // 0x00243C1C: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_00243C48;
    }
    goto skip_5;
    // 0x00243C1C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_5:
    // 0x00243C20: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00243C24: lwc1        $f0, -0x756C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X756C);
L_00243C28:
    // 0x00243C28: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x00243C2C: nop

    // 0x00243C30: bc1f        L_00243C48
    if (!c1cs) {
        // 0x00243C34: nop
    
            goto L_00243C48;
    }
    // 0x00243C34: nop

    // 0x00243C38: j           L_00243C48
    // 0x00243C3C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_00243C48;
    // 0x00243C3C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_00243C40:
    // 0x00243C40: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x00243C44: mov.s       $f23, $f22
    CHECK_FR(ctx, 23);
    CHECK_FR(ctx, 22);
    ctx->f23.fl = ctx->f22.fl;
L_00243C48:
    // 0x00243C48: mtc1        $s4, $f20
    ctx->f20.u32l = ctx->r20;
    // 0x00243C4C: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x00243C50: lwc1        $f0, 0x20($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X20);
    // 0x00243C54: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x00243C58: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x00243C5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00243C60: lwc1        $f21, -0x7568($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X7568);
    // 0x00243C64: mfc1        $a1, $f23
    ctx->r5 = (int32_t)ctx->f_odd[(23 - 1) * 2];
    // 0x00243C68: mfc1        $a2, $f21
    ctx->r6 = (int32_t)ctx->f_odd[(21 - 1) * 2];
    // 0x00243C6C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00243C70: jal         0x0021587C
    // 0x00243C74: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_0021587C(rdram, ctx);
        goto after_7;
    // 0x00243C74: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x00243C78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00243C7C: lwc1        $f1, 0x24($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X24);
    // 0x00243C80: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x00243C84: mul.s       $f1, $f1, $f20
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f20.fl);
    // 0x00243C88: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x00243C8C: mfc1        $a2, $f21
    ctx->r6 = (int32_t)ctx->f_odd[(21 - 1) * 2];
    // 0x00243C90: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x00243C94: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x00243C98: jal         0x0021587C
    // 0x00243C9C: swc1        $f1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    func_0021587C(rdram, ctx);
        goto after_8;
    // 0x00243C9C: swc1        $f1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    after_8:
    // 0x00243CA0: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x00243CA4: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x00243CA8: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x00243CAC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_00243CB0:
    // 0x00243CB0: jal         0x0022170C
    // 0x00243CB4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_0022170C(rdram, ctx);
        goto after_9;
    // 0x00243CB4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_9:
L_00243CB8:
    // 0x00243CB8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x00243CBC: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x00243CC0: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x00243CC4: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x00243CC8: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x00243CCC: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x00243CD0: ldc1        $f23, 0x88($sp)
    CHECK_FR(ctx, 23);
    ctx->f23.u64 = LD(ctx->r29, 0X88);
    // 0x00243CD4: ldc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X80);
    // 0x00243CD8: ldc1        $f21, 0x78($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X78);
    // 0x00243CDC: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x00243CE0: jr          $ra
    // 0x00243CE4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x00243CE4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_00243CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00243CE8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x00243CEC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x00243CF0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00243CF4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x00243CF8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00243CFC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x00243D00: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x00243D04: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x00243D08: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x00243D0C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x00243D10: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x00243D14: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x00243D18: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x00243D1C: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x00243D20: sdc1        $f21, 0x50($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X50, ctx->r29);
    // 0x00243D24: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x00243D28: jal         0x0021AACC
    // 0x00243D2C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_0021AACC(rdram, ctx);
        goto after_0;
    // 0x00243D2C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // 0x00243D30: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00243D34: addiu       $v0, $zero, 0x1C84
    ctx->r2 = ADD32(0, 0X1C84);
    // 0x00243D38: beq         $v1, $v0, L_00243D9C
    if (ctx->r3 == ctx->r2) {
        // 0x00243D3C: addiu       $v0, $zero, 0x7D5
        ctx->r2 = ADD32(0, 0X7D5);
            goto L_00243D9C;
    }
    // 0x00243D3C: addiu       $v0, $zero, 0x7D5
    ctx->r2 = ADD32(0, 0X7D5);
    // 0x00243D40: beq         $v1, $v0, L_00243E04
    if (ctx->r3 == ctx->r2) {
        // 0x00243D44: addiu       $v0, $zero, 0x4B1
        ctx->r2 = ADD32(0, 0X4B1);
            goto L_00243E04;
    }
    // 0x00243D44: addiu       $v0, $zero, 0x4B1
    ctx->r2 = ADD32(0, 0X4B1);
    // 0x00243D48: beq         $v1, $v0, L_00243D9C
    if (ctx->r3 == ctx->r2) {
        // 0x00243D4C: addiu       $v0, $zero, 0x4B5
        ctx->r2 = ADD32(0, 0X4B5);
            goto L_00243D9C;
    }
    // 0x00243D4C: addiu       $v0, $zero, 0x4B5
    ctx->r2 = ADD32(0, 0X4B5);
    // 0x00243D50: beq         $v1, $v0, L_00243D9C
    if (ctx->r3 == ctx->r2) {
        // 0x00243D54: addiu       $v0, $zero, 0x4B6
        ctx->r2 = ADD32(0, 0X4B6);
            goto L_00243D9C;
    }
    // 0x00243D54: addiu       $v0, $zero, 0x4B6
    ctx->r2 = ADD32(0, 0X4B6);
    // 0x00243D58: beq         $v1, $v0, L_00243D9C
    if (ctx->r3 == ctx->r2) {
        // 0x00243D5C: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00243D9C;
    }
    // 0x00243D5C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00243D60: lb          $v1, 0x174($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X174);
    // 0x00243D64: beq         $v1, $v0, L_00243D98
    if (ctx->r3 == ctx->r2) {
        // 0x00243D68: nop
    
            goto L_00243D98;
    }
    // 0x00243D68: nop

    // 0x00243D6C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x00243D70: beq         $a2, $zero, L_00243D84
    if (ctx->r6 == 0) {
        // 0x00243D74: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00243D84;
    }
    // 0x00243D74: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00243D78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00243D7C: j           L_00243D90
    // 0x00243D80: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
        goto L_00243D90;
    // 0x00243D80: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_00243D84:
    // 0x00243D84: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00243D88: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00243D8C: addiu       $a2, $a2, -0xC80
    ctx->r6 = ADD32(ctx->r6, -0XC80);
L_00243D90:
    // 0x00243D90: jal         0x00246878
    // 0x00243D94: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_00246878(rdram, ctx);
        goto after_1;
    // 0x00243D94: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
L_00243D98:
    // 0x00243D98: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
L_00243D9C:
    // 0x00243D9C: addiu       $v0, $zero, 0x7D5
    ctx->r2 = ADD32(0, 0X7D5);
    // 0x00243DA0: beq         $v1, $v0, L_00243E00
    if (ctx->r3 == ctx->r2) {
        // 0x00243DA4: addiu       $v0, $zero, 0x4B5
        ctx->r2 = ADD32(0, 0X4B5);
            goto L_00243E00;
    }
    // 0x00243DA4: addiu       $v0, $zero, 0x4B5
    ctx->r2 = ADD32(0, 0X4B5);
    // 0x00243DA8: beq         $v1, $v0, L_00243E00
    if (ctx->r3 == ctx->r2) {
        // 0x00243DAC: addiu       $v0, $zero, 0x4B6
        ctx->r2 = ADD32(0, 0X4B6);
            goto L_00243E00;
    }
    // 0x00243DAC: addiu       $v0, $zero, 0x4B6
    ctx->r2 = ADD32(0, 0X4B6);
    // 0x00243DB0: beq         $v1, $v0, L_00243E00
    if (ctx->r3 == ctx->r2) {
        // 0x00243DB4: addiu       $v0, $zero, 0x67
        ctx->r2 = ADD32(0, 0X67);
            goto L_00243E00;
    }
    // 0x00243DB4: addiu       $v0, $zero, 0x67
    ctx->r2 = ADD32(0, 0X67);
    // 0x00243DB8: beq         $v1, $v0, L_00243E00
    if (ctx->r3 == ctx->r2) {
        // 0x00243DBC: addiu       $v0, $zero, 0x66
        ctx->r2 = ADD32(0, 0X66);
            goto L_00243E00;
    }
    // 0x00243DBC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x00243DC0: beq         $v1, $v0, L_00243E00
    if (ctx->r3 == ctx->r2) {
        // 0x00243DC4: addiu       $v0, $zero, 0x65
        ctx->r2 = ADD32(0, 0X65);
            goto L_00243E00;
    }
    // 0x00243DC4: addiu       $v0, $zero, 0x65
    ctx->r2 = ADD32(0, 0X65);
    // 0x00243DC8: beq         $v1, $v0, L_00243E00
    if (ctx->r3 == ctx->r2) {
        // 0x00243DCC: addiu       $v0, $zero, 0x68
        ctx->r2 = ADD32(0, 0X68);
            goto L_00243E00;
    }
    // 0x00243DCC: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // 0x00243DD0: beq         $v1, $v0, L_00243E00
    if (ctx->r3 == ctx->r2) {
        // 0x00243DD4: addiu       $v0, $zero, 0x4B1
        ctx->r2 = ADD32(0, 0X4B1);
            goto L_00243E00;
    }
    // 0x00243DD4: addiu       $v0, $zero, 0x4B1
    ctx->r2 = ADD32(0, 0X4B1);
    // 0x00243DD8: beq         $v1, $v0, L_00243E08
    if (ctx->r3 == ctx->r2) {
        // 0x00243DDC: addiu       $v0, $zero, 0x1C84
        ctx->r2 = ADD32(0, 0X1C84);
            goto L_00243E08;
    }
    // 0x00243DDC: addiu       $v0, $zero, 0x1C84
    ctx->r2 = ADD32(0, 0X1C84);
    // 0x00243DE0: lhu         $s3, 0x4($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X4);
    // 0x00243DE4: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x00243DE8: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x00243DEC: bltzl       $v0, L_00243DFC
    if (SIGNED(ctx->r2) < 0) {
        // 0x00243DF0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_00243DFC;
    }
    goto skip_0;
    // 0x00243DF0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x00243DF4: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x00243DF8: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
L_00243DFC:
    // 0x00243DFC: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_00243E00:
    // 0x00243E00: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
L_00243E04:
    // 0x00243E04: addiu       $v0, $zero, 0x1C84
    ctx->r2 = ADD32(0, 0X1C84);
L_00243E08:
    // 0x00243E08: beq         $v1, $v0, L_00243E5C
    if (ctx->r3 == ctx->r2) {
        // 0x00243E0C: addiu       $v0, $zero, 0x7D5
        ctx->r2 = ADD32(0, 0X7D5);
            goto L_00243E5C;
    }
    // 0x00243E0C: addiu       $v0, $zero, 0x7D5
    ctx->r2 = ADD32(0, 0X7D5);
    // 0x00243E10: beq         $v1, $v0, L_00243E5C
    if (ctx->r3 == ctx->r2) {
        // 0x00243E14: addiu       $v0, $zero, 0x4B5
        ctx->r2 = ADD32(0, 0X4B5);
            goto L_00243E5C;
    }
    // 0x00243E14: addiu       $v0, $zero, 0x4B5
    ctx->r2 = ADD32(0, 0X4B5);
    // 0x00243E18: beq         $v1, $v0, L_00243E5C
    if (ctx->r3 == ctx->r2) {
        // 0x00243E1C: addiu       $v0, $zero, 0x4B6
        ctx->r2 = ADD32(0, 0X4B6);
            goto L_00243E5C;
    }
    // 0x00243E1C: addiu       $v0, $zero, 0x4B6
    ctx->r2 = ADD32(0, 0X4B6);
    // 0x00243E20: beq         $v1, $v0, L_00243E5C
    if (ctx->r3 == ctx->r2) {
        // 0x00243E24: addiu       $v0, $zero, 0x67
        ctx->r2 = ADD32(0, 0X67);
            goto L_00243E5C;
    }
    // 0x00243E24: addiu       $v0, $zero, 0x67
    ctx->r2 = ADD32(0, 0X67);
    // 0x00243E28: beq         $v1, $v0, L_00243E5C
    if (ctx->r3 == ctx->r2) {
        // 0x00243E2C: addiu       $v0, $zero, 0x66
        ctx->r2 = ADD32(0, 0X66);
            goto L_00243E5C;
    }
    // 0x00243E2C: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x00243E30: beq         $v1, $v0, L_00243E5C
    if (ctx->r3 == ctx->r2) {
        // 0x00243E34: addiu       $v0, $zero, 0x65
        ctx->r2 = ADD32(0, 0X65);
            goto L_00243E5C;
    }
    // 0x00243E34: addiu       $v0, $zero, 0x65
    ctx->r2 = ADD32(0, 0X65);
    // 0x00243E38: beq         $v1, $v0, L_00243E5C
    if (ctx->r3 == ctx->r2) {
        // 0x00243E3C: addiu       $v0, $zero, 0x68
        ctx->r2 = ADD32(0, 0X68);
            goto L_00243E5C;
    }
    // 0x00243E3C: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // 0x00243E40: beq         $v1, $v0, L_00243E5C
    if (ctx->r3 == ctx->r2) {
        // 0x00243E44: addiu       $v0, $zero, 0x4B1
        ctx->r2 = ADD32(0, 0X4B1);
            goto L_00243E5C;
    }
    // 0x00243E44: addiu       $v0, $zero, 0x4B1
    ctx->r2 = ADD32(0, 0X4B1);
    // 0x00243E48: beq         $v1, $v0, L_00243E60
    if (ctx->r3 == ctx->r2) {
        // 0x00243E4C: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_00243E60;
    }
    // 0x00243E4C: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x00243E50: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x00243E54: j           L_00243E60
    // 0x00243E58: sltiu       $s5, $v0, 0x1
    ctx->r21 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_00243E60;
    // 0x00243E58: sltiu       $s5, $v0, 0x1
    ctx->r21 = ctx->r2 < 0X1 ? 1 : 0;
L_00243E5C:
    // 0x00243E5C: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
L_00243E60:
    // 0x00243E60: beq         $s5, $zero, L_00243E6C
    if (ctx->r21 == 0) {
        // 0x00243E64: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_00243E6C;
    }
    // 0x00243E64: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x00243E68: sltu        $s4, $s4, $s3
    ctx->r20 = ctx->r20 < ctx->r19 ? 1 : 0;
L_00243E6C:
    // 0x00243E6C: bne         $s4, $zero, L_00243E8C
    if (ctx->r20 != 0) {
        // 0x00243E70: addiu       $v0, $zero, 0x2F
        ctx->r2 = ADD32(0, 0X2F);
            goto L_00243E8C;
    }
    // 0x00243E70: addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    // 0x00243E74: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x00243E78: beq         $v1, $v0, L_00243ED0
    if (ctx->r3 == ctx->r2) {
        // 0x00243E7C: nop
    
            goto L_00243ED0;
    }
    // 0x00243E7C: nop

    // 0x00243E80: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x00243E84: bne         $v0, $zero, L_00243ED0
    if (ctx->r2 != 0) {
        // 0x00243E88: nop
    
            goto L_00243ED0;
    }
    // 0x00243E88: nop

L_00243E8C:
    // 0x00243E8C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x00243E90: lhu         $a0, 0x3A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X3A);
    // 0x00243E94: beq         $a0, $zero, L_00243ED0
    if (ctx->r4 == 0) {
        // 0x00243E98: nop
    
            goto L_00243ED0;
    }
    // 0x00243E98: nop

    // 0x00243E9C: lb          $v0, 0x1C4($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C4);
    // 0x00243EA0: slti        $v0, $v0, 0xB
    ctx->r2 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x00243EA4: bne         $v0, $zero, L_00243ED0
    if (ctx->r2 != 0) {
        // 0x00243EA8: nop
    
            goto L_00243ED0;
    }
    // 0x00243EA8: nop

    // 0x00243EAC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x00243EB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00243EB4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00243EB8: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x00243EBC: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x00243EC0: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x00243EC4: jal         0x00273AC4
    // 0x00243EC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_00273AC4(rdram, ctx);
        goto after_2;
    // 0x00243EC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x00243ECC: sb          $zero, 0x1C4($s0)
    MEM_B(0X1C4, ctx->r16) = 0;
L_00243ED0:
    // 0x00243ED0: lbu         $v1, 0xB4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XB4);
    // 0x00243ED4: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x00243ED8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x00243EDC: slti        $v0, $v0, 0xFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x00243EE0: bnel        $v0, $zero, L_00243EF0
    if (ctx->r2 != 0) {
        // 0x00243EE4: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_00243EF0;
    }
    goto skip_1;
    // 0x00243EE4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    skip_1:
    // 0x00243EE8: lbu         $v0, 0x7($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X7);
    // 0x00243EEC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_00243EF0:
    // 0x00243EF0: sb          $v0, 0xB4($s0)
    MEM_B(0XB4, ctx->r16) = ctx->r2;
    // 0x00243EF4: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x00243EF8: lui         $v1, 0x20
    ctx->r3 = S32(0X20 << 16);
    // 0x00243EFC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00243F00: beq         $v0, $zero, L_00243F54
    if (ctx->r2 == 0) {
        // 0x00243F04: nop
    
            goto L_00243F54;
    }
    // 0x00243F04: nop

    // 0x00243F08: jal         0x002154EC
    // 0x00243F0C: nop

    func_002154EC(rdram, ctx);
        goto after_3;
    // 0x00243F0C: nop

    after_3:
    // 0x00243F10: lui         $v1, 0x1062
    ctx->r3 = S32(0X1062 << 16);
    // 0x00243F14: ori         $v1, $v1, 0x4DD3
    ctx->r3 = ctx->r3 | 0X4DD3;
    // 0x00243F18: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x00243F1C: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x00243F20: mfhi        $t0
    ctx->r8 = hi;
    // 0x00243F24: sra         $a0, $t0, 6
    ctx->r4 = S32(SIGNED(ctx->r8) >> 6);
    // 0x00243F28: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x00243F2C: sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4 << 5);
    // 0x00243F30: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x00243F34: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x00243F38: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x00243F3C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x00243F40: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x00243F44: slti        $v0, $v0, 0x1F4
    ctx->r2 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x00243F48: beq         $v0, $zero, L_00243F54
    if (ctx->r2 == 0) {
        // 0x00243F4C: lui         $v0, 0x40
        ctx->r2 = S32(0X40 << 16);
            goto L_00243F54;
    }
    // 0x00243F4C: lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // 0x00243F50: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
L_00243F54:
    // 0x00243F54: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x00243F58: lui         $v1, 0x8
    ctx->r3 = S32(0X8 << 16);
    // 0x00243F5C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00243F60: beq         $v0, $zero, L_00243FB8
    if (ctx->r2 == 0) {
        // 0x00243F64: lui         $v0, 0xFF87
        ctx->r2 = S32(0XFF87 << 16);
            goto L_00243FB8;
    }
    // 0x00243F64: lui         $v0, 0xFF87
    ctx->r2 = S32(0XFF87 << 16);
    // 0x00243F68: jal         0x002154EC
    // 0x00243F6C: nop

    func_002154EC(rdram, ctx);
        goto after_4;
    // 0x00243F6C: nop

    after_4:
    // 0x00243F70: lui         $v1, 0x1062
    ctx->r3 = S32(0X1062 << 16);
    // 0x00243F74: ori         $v1, $v1, 0x4DD3
    ctx->r3 = ctx->r3 | 0X4DD3;
    // 0x00243F78: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x00243F7C: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x00243F80: mfhi        $t0
    ctx->r8 = hi;
    // 0x00243F84: sra         $a0, $t0, 6
    ctx->r4 = S32(SIGNED(ctx->r8) >> 6);
    // 0x00243F88: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x00243F8C: sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4 << 5);
    // 0x00243F90: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x00243F94: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x00243F98: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x00243F9C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x00243FA0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x00243FA4: slti        $v0, $v0, 0x1F4
    ctx->r2 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x00243FA8: beq         $v0, $zero, L_00243FB4
    if (ctx->r2 == 0) {
        // 0x00243FAC: lui         $v0, 0x10
        ctx->r2 = S32(0X10 << 16);
            goto L_00243FB4;
    }
    // 0x00243FAC: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x00243FB0: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
L_00243FB4:
    // 0x00243FB4: lui         $v0, 0xFF87
    ctx->r2 = S32(0XFF87 << 16);
L_00243FB8:
    // 0x00243FB8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x00243FBC: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x00243FC0: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x00243FC4: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x00243FC8: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x00243FCC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x00243FD0: beq         $s4, $zero, L_002440D4
    if (ctx->r20 == 0) {
        // 0x00243FD4: sw          $v1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r3;
            goto L_002440D4;
    }
    // 0x00243FD4: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x00243FD8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00243FDC: jal         0x00242140
    // 0x00243FE0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00242140(rdram, ctx);
        goto after_5;
    // 0x00243FE0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x00243FE4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x00243FE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x00243FEC: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x00243FF0: lui         $v1, 0x20
    ctx->r3 = S32(0X20 << 16);
    // 0x00243FF4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00243FF8: bnel        $v0, $zero, L_00244000
    if (ctx->r2 != 0) {
        // 0x00243FFC: addiu       $s6, $zero, 0x1
        ctx->r22 = ADD32(0, 0X1);
            goto L_00244000;
    }
    goto skip_2;
    // 0x00243FFC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    skip_2:
L_00244000:
    // 0x00244000: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x00244004: lbu         $v0, -0x2DC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2DC8);
    // 0x00244008: bne         $v0, $zero, L_002440C0
    if (ctx->r2 != 0) {
        // 0x0024400C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002440C0;
    }
    // 0x0024400C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00244010: lw          $a0, 0x108($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X108);
    // 0x00244014: beq         $a0, $zero, L_002440BC
    if (ctx->r4 == 0) {
        // 0x00244018: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_002440BC;
    }
    // 0x00244018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024401C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x00244020: bnel        $v1, $v0, L_002440C0
    if (ctx->r3 != ctx->r2) {
        // 0x00244024: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002440C0;
    }
    goto skip_3;
    // 0x00244024: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    skip_3:
    // 0x00244028: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x0024402C: lui         $v1, 0x1800
    ctx->r3 = S32(0X1800 << 16);
    // 0x00244030: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00244034: beql        $v0, $zero, L_002440C0
    if (ctx->r2 == 0) {
        // 0x00244038: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002440C0;
    }
    goto skip_4;
    // 0x00244038: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    skip_4:
    // 0x0024403C: lw          $a0, 0x1CC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1CC);
    // 0x00244040: lw          $v0, 0xA7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA7C);
    // 0x00244044: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x00244048: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x0024404C: bgez        $v0, L_00244060
    if (SIGNED(ctx->r2) >= 0) {
        // 0x00244050: nop
    
            goto L_00244060;
    }
    // 0x00244050: nop

    // 0x00244054: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244058: ldc1        $f0, -0x7560($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X7560);
    // 0x0024405C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_00244060:
    // 0x00244060: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x00244064: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244068: lwc1        $f1, -0x7558($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7558);
    // 0x0024406C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x00244070: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x00244074: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00244078: cvt.s.d     $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f1.fl = CVT_S_D(ctx->f2.d);
    // 0x0024407C: add.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00244080: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244084: lwc1        $f1, -0x7554($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7554);
    // 0x00244088: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x0024408C: nop

    // 0x00244090: bc1tl       L_002440A8
    if (c1cs) {
        // 0x00244094: sub.s       $f0, $f0, $f1
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
            goto L_002440A8;
    }
    goto skip_5;
    // 0x00244094: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    skip_5:
    // 0x00244098: trunc.w.s   $f3, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f0.fl);
    // 0x0024409C: mfc1        $v1, $f3
    ctx->r3 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x002440A0: j           L_002440BC
    // 0x002440A4: sw          $v1, 0xA7C($a0)
    MEM_W(0XA7C, ctx->r4) = ctx->r3;
        goto L_002440BC;
    // 0x002440A4: sw          $v1, 0xA7C($a0)
    MEM_W(0XA7C, ctx->r4) = ctx->r3;
L_002440A8:
    // 0x002440A8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x002440AC: trunc.w.s   $f3, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f0.fl);
    // 0x002440B0: mfc1        $v1, $f3
    ctx->r3 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x002440B4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x002440B8: sw          $v1, 0xA7C($a0)
    MEM_W(0XA7C, ctx->r4) = ctx->r3;
L_002440BC:
    // 0x002440BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_002440C0:
    // 0x002440C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x002440C4: jal         0x0023E684
    // 0x002440C8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    func_0023E684(rdram, ctx);
        goto after_6;
    // 0x002440C8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_6:
    // 0x002440CC: j           L_0024414C
    // 0x002440D0: nop

        goto L_0024414C;
    // 0x002440D0: nop

L_002440D4:
    // 0x002440D4: bne         $s5, $zero, L_0024414C
    if (ctx->r21 != 0) {
        // 0x002440D8: nop
    
            goto L_0024414C;
    }
    // 0x002440D8: nop

    // 0x002440DC: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x002440E0: beq         $v0, $zero, L_00244108
    if (ctx->r2 == 0) {
        // 0x002440E4: nop
    
            goto L_00244108;
    }
    // 0x002440E4: nop

    // 0x002440E8: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x002440EC: addiu       $v0, $v0, -0x12
    ctx->r2 = ADD32(ctx->r2, -0X12);
    // 0x002440F0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x002440F4: beq         $v0, $zero, L_00244108
    if (ctx->r2 == 0) {
        // 0x002440F8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00244108;
    }
    // 0x002440F8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002440FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00244100: jal         0x0023E684
    // 0x00244104: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_7;
    // 0x00244104: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
L_00244108:
    // 0x00244108: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x0024410C: lbu         $v0, -0x2DC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2DC8);
    // 0x00244110: bne         $v0, $zero, L_0024414C
    if (ctx->r2 != 0) {
        // 0x00244114: nop
    
            goto L_0024414C;
    }
    // 0x00244114: nop

    // 0x00244118: lw          $a1, 0x108($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X108);
    // 0x0024411C: beq         $a1, $zero, L_0024414C
    if (ctx->r5 == 0) {
        // 0x00244120: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_0024414C;
    }
    // 0x00244120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00244124: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x00244128: bne         $v1, $v0, L_0024414C
    if (ctx->r3 != ctx->r2) {
        // 0x0024412C: lui         $v1, 0x1800
        ctx->r3 = S32(0X1800 << 16);
            goto L_0024414C;
    }
    // 0x0024412C: lui         $v1, 0x1800
    ctx->r3 = S32(0X1800 << 16);
    // 0x00244130: lw          $v0, 0xF4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XF4);
    // 0x00244134: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00244138: beq         $v0, $zero, L_0024414C
    if (ctx->r2 == 0) {
        // 0x0024413C: nop
    
            goto L_0024414C;
    }
    // 0x0024413C: nop

    // 0x00244140: lw          $a0, 0x1CC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1CC);
    // 0x00244144: jal         0x0023B378
    // 0x00244148: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0023B378(rdram, ctx);
        goto after_8;
    // 0x00244148: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_8:
L_0024414C:
    // 0x0024414C: beq         $s6, $zero, L_00244234
    if (ctx->r22 == 0) {
        // 0x00244150: nop
    
            goto L_00244234;
    }
    // 0x00244150: nop

    // 0x00244154: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x00244158: beq         $a2, $zero, L_00244234
    if (ctx->r6 == 0) {
        // 0x0024415C: nop
    
            goto L_00244234;
    }
    // 0x0024415C: nop

    // 0x00244160: lwc1        $f1, 0x8($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X8);
    // 0x00244164: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00244168: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x0024416C: nop

    // 0x00244170: bc1f        L_00244234
    if (!c1cs) {
        // 0x00244174: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_00244234;
    }
    // 0x00244174: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x00244178: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x0024417C: jal         0x00213074
    // 0x00244180: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_00213074(rdram, ctx);
        goto after_9;
    // 0x00244180: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_9:
    // 0x00244184: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x00244188: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x0024418C: lwc1        $f1, 0x1C($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X1C);
    // 0x00244190: mul.s       $f1, $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f1.fl);
    // 0x00244194: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x00244198: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x0024419C: add.s       $f12, $f12, $f1
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f1.fl;
    // 0x002441A0: jal         0x0029A6F0
    // 0x002441A4: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    func_0029A6F0(rdram, ctx);
        goto after_10;
    // 0x002441A4: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    after_10:
    // 0x002441A8: lwc1        $f1, 0x8($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X8);
    // 0x002441AC: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x002441B0: nop

    // 0x002441B4: bc1f        L_00244234
    if (!c1cs) {
        // 0x002441B8: nop
    
            goto L_00244234;
    }
    // 0x002441B8: nop

    // 0x002441BC: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x002441C0: sub.s       $f20, $f1, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x002441C4: sra         $v0, $v0, 8
    ctx->r2 = S32(SIGNED(ctx->r2) >> 8);
    // 0x002441C8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x002441CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x002441D0: div.s       $f20, $f20, $f1
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f1.fl);
    // 0x002441D4: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x002441D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002441DC: lwc1        $f21, -0x7550($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X7550);
    // 0x002441E0: mul.s       $f21, $f20, $f21
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f21.fl = MUL_S(ctx->f20.fl, ctx->f21.fl);
    // 0x002441E4: jal         0x00212BF8
    // 0x002441E8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_00212BF8(rdram, ctx);
        goto after_11;
    // 0x002441E8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_11:
    // 0x002441EC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x002441F0: jal         0x00299758
    // 0x002441F4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_00299758(rdram, ctx);
        goto after_12;
    // 0x002441F4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_12:
    // 0x002441F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002441FC: lwc1        $f1, -0x754C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X754C);
    // 0x00244200: mul.s       $f20, $f20, $f1
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f1.fl);
    // 0x00244204: nop

    // 0x00244208: mul.s       $f0, $f21, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f21.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f21.fl, ctx->f0.fl);
    // 0x0024420C: lwc1        $f1, 0x18($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X18);
    // 0x00244210: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00244214: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x00244218: swc1        $f20, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f20.u32l;
    // 0x0024421C: jal         0x0029A570
    // 0x00244220: swc1        $f1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    func_0029A570(rdram, ctx);
        goto after_13;
    // 0x00244220: swc1        $f1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    after_13:
    // 0x00244224: mul.s       $f21, $f21, $f0
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f21.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f21.fl = MUL_S(ctx->f21.fl, ctx->f0.fl);
    // 0x00244228: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x0024422C: add.s       $f0, $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f21.fl;
    // 0x00244230: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_00244234:
    // 0x00244234: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x00244238: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x0024423C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x00244240: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x00244244: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x00244248: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x0024424C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x00244250: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x00244254: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x00244258: ldc1        $f21, 0x50($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X50);
    // 0x0024425C: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x00244260: jr          $ra
    // 0x00244264: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x00244264: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_00244268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00244268: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x0024426C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x00244270: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00244274: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x00244278: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x0024427C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x00244280: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x00244284: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x00244288: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x0024428C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x00244290: lwc1        $f1, 0x180($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X180);
    // 0x00244294: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x00244298: c.eq.s      $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f1.fl == ctx->f2.fl;
    // 0x0024429C: nop

    // 0x002442A0: bc1t        L_002442C8
    if (c1cs) {
        // 0x002442A4: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_002442C8;
    }
    // 0x002442A4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x002442A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002442AC: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x002442B0: sub.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x002442B4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x002442B8: nop

    // 0x002442BC: bc1f        L_002442C8
    if (!c1cs) {
        // 0x002442C0: swc1        $f0, 0x180($s2)
        MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
            goto L_002442C8;
    }
    // 0x002442C0: swc1        $f0, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
    // 0x002442C4: swc1        $f2, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f2.u32l;
L_002442C8:
    // 0x002442C8: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x002442CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002442D0: lwc1        $f0, -0x7548($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7548);
    // 0x002442D4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x002442D8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x002442DC: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x002442E0: lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4);
    // 0x002442E4: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x002442E8: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x002442EC: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x002442F0: nop

    // 0x002442F4: bc1f        L_00244464
    if (!c1cs) {
        // 0x002442F8: lui         $v0, 0xFF7F
        ctx->r2 = S32(0XFF7F << 16);
            goto L_00244464;
    }
    // 0x002442F8: lui         $v0, 0xFF7F
    ctx->r2 = S32(0XFF7F << 16);
    // 0x002442FC: lw          $v1, 0xF4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XF4);
    // 0x00244300: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x00244304: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x00244308: sw          $v1, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r3;
    // 0x0024430C: lw          $v0, 0x17C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X17C);
    // 0x00244310: bne         $v0, $zero, L_00244580
    if (ctx->r2 != 0) {
        // 0x00244314: addiu       $s3, $zero, 0x2
        ctx->r19 = ADD32(0, 0X2);
            goto L_00244580;
    }
    // 0x00244314: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x00244318: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x0024431C: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x00244320: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x00244324: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00244328: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x0024432C: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x00244330: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x00244334: jal         0x002421C4
    // 0x00244338: addiu       $a1, $a1, 0x7D0
    ctx->r5 = ADD32(ctx->r5, 0X7D0);
    func_002421C4(rdram, ctx);
        goto after_0;
    // 0x00244338: addiu       $a1, $a1, 0x7D0
    ctx->r5 = ADD32(ctx->r5, 0X7D0);
    after_0:
    // 0x0024433C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x00244340: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x00244344: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    // 0x00244348: bnel        $v1, $v0, L_00244374
    if (ctx->r3 != ctx->r2) {
        // 0x0024434C: addiu       $v0, $zero, 0x4D
        ctx->r2 = ADD32(0, 0X4D);
            goto L_00244374;
    }
    goto skip_0;
    // 0x0024434C: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    skip_0:
    // 0x00244350: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244354: lwc1        $f0, -0x7544($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7544);
    // 0x00244358: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x0024435C: swc1        $f0, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
    // 0x00244360: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x00244364: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x00244368: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x0024436C: j           L_002443BC
    // 0x00244370: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
        goto L_002443BC;
    // 0x00244370: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_00244374:
    // 0x00244374: bnel        $v1, $v0, L_002443A0
    if (ctx->r3 != ctx->r2) {
        // 0x00244378: addiu       $v0, $zero, 0xDC
        ctx->r2 = ADD32(0, 0XDC);
            goto L_002443A0;
    }
    goto skip_1;
    // 0x00244378: addiu       $v0, $zero, 0xDC
    ctx->r2 = ADD32(0, 0XDC);
    skip_1:
    // 0x0024437C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244380: lwc1        $f0, -0x7540($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7540);
    // 0x00244384: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
    // 0x00244388: swc1        $f0, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
    // 0x0024438C: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x00244390: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x00244394: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x00244398: j           L_002443BC
    // 0x0024439C: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
        goto L_002443BC;
    // 0x0024439C: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
L_002443A0:
    // 0x002443A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002443A4: lwc1        $f0, -0x753C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X753C);
    // 0x002443A8: swc1        $f0, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
    // 0x002443AC: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x002443B0: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x002443B4: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x002443B8: addiu       $v0, $zero, 0x320
    ctx->r2 = ADD32(0, 0X320);
L_002443BC:
    // 0x002443BC: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x002443C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002443C4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x002443C8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x002443CC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x002443D0: sw          $s0, 0x17C($s2)
    MEM_W(0X17C, ctx->r18) = ctx->r16;
    // 0x002443D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002443D8: sw          $s0, -0xC68($at)
    MEM_W(-0XC68, ctx->r1) = ctx->r16;
    // 0x002443DC: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x002443E0: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x002443E4: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x002443E8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x002443EC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x002443F0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x002443F4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x002443F8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x002443FC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x00244400: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x00244404: jal         0x00262DC8
    // 0x00244408: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_00262DC8(rdram, ctx);
        goto after_1;
    // 0x00244408: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_1:
    // 0x0024440C: lw          $a0, 0x108($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X108);
    // 0x00244410: beq         $a0, $zero, L_00244450
    if (ctx->r4 == 0) {
        // 0x00244414: nop
    
            goto L_00244450;
    }
    // 0x00244414: nop

    // 0x00244418: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x0024441C: bne         $v0, $s0, L_00244450
    if (ctx->r2 != ctx->r16) {
        // 0x00244420: lui         $v1, 0x4000
        ctx->r3 = S32(0X4000 << 16);
            goto L_00244450;
    }
    // 0x00244420: lui         $v1, 0x4000
    ctx->r3 = S32(0X4000 << 16);
    // 0x00244424: lw          $v0, 0x168($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X168);
    // 0x00244428: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0024442C: sw          $v0, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r2;
    // 0x00244430: lw          $v0, 0x108($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X108);
    // 0x00244434: lw          $a1, 0x268($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X268);
    // 0x00244438: beq         $a1, $zero, L_00244450
    if (ctx->r5 == 0) {
        // 0x0024443C: nop
    
            goto L_00244450;
    }
    // 0x0024443C: nop

    // 0x00244440: jal         0x002217F0
    // 0x00244444: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_2;
    // 0x00244444: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x00244448: lw          $v0, 0x108($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X108);
    // 0x0024444C: sw          $zero, 0x268($v0)
    MEM_W(0X268, ctx->r2) = 0;
L_00244450:
    // 0x00244450: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x00244454: jal         0x0026DE30
    // 0x00244458: nop

    func_0026DE30(rdram, ctx);
        goto after_3;
    // 0x00244458: nop

    after_3:
    // 0x0024445C: j           L_00244580
    // 0x00244460: nop

        goto L_00244580;
    // 0x00244460: nop

L_00244464:
    // 0x00244464: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244468: lwc1        $f0, -0x7538($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7538);
    // 0x0024446C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x00244470: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x00244474: nop

    // 0x00244478: bc1f        L_00244580
    if (!c1cs) {
        // 0x0024447C: nop
    
            goto L_00244580;
    }
    // 0x0024447C: nop

    // 0x00244480: lw          $v0, 0x178($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X178);
    // 0x00244484: bne         $v0, $zero, L_00244580
    if (ctx->r2 != 0) {
        // 0x00244488: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_00244580;
    }
    // 0x00244488: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x0024448C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x00244490: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x00244494: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x00244498: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024449C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x002444A0: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x002444A4: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x002444A8: jal         0x002421C4
    // 0x002444AC: addiu       $a1, $a1, 0x7D0
    ctx->r5 = ADD32(ctx->r5, 0X7D0);
    func_002421C4(rdram, ctx);
        goto after_4;
    // 0x002444AC: addiu       $a1, $a1, 0x7D0
    ctx->r5 = ADD32(ctx->r5, 0X7D0);
    after_4:
    // 0x002444B0: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x002444B4: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x002444B8: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    // 0x002444BC: bnel        $v1, $v0, L_002444E8
    if (ctx->r3 != ctx->r2) {
        // 0x002444C0: addiu       $v0, $zero, 0x4D
        ctx->r2 = ADD32(0, 0X4D);
            goto L_002444E8;
    }
    goto skip_2;
    // 0x002444C0: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    skip_2:
    // 0x002444C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002444C8: lwc1        $f0, -0x7534($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7534);
    // 0x002444CC: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x002444D0: swc1        $f0, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
    // 0x002444D4: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x002444D8: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x002444DC: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x002444E0: j           L_00244530
    // 0x002444E4: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
        goto L_00244530;
    // 0x002444E4: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_002444E8:
    // 0x002444E8: bnel        $v1, $v0, L_00244514
    if (ctx->r3 != ctx->r2) {
        // 0x002444EC: addiu       $v0, $zero, 0x78
        ctx->r2 = ADD32(0, 0X78);
            goto L_00244514;
    }
    goto skip_3;
    // 0x002444EC: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    skip_3:
    // 0x002444F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002444F4: lwc1        $f0, -0x7530($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7530);
    // 0x002444F8: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x002444FC: swc1        $f0, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
    // 0x00244500: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x00244504: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x00244508: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x0024450C: j           L_00244530
    // 0x00244510: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
        goto L_00244530;
    // 0x00244510: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_00244514:
    // 0x00244514: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244518: lwc1        $f0, -0x752C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X752C);
    // 0x0024451C: swc1        $f0, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
    // 0x00244520: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x00244524: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x00244528: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x0024452C: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
L_00244530:
    // 0x00244530: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x00244534: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00244538: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0024453C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x00244540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00244544: sw          $v0, 0x178($s2)
    MEM_W(0X178, ctx->r18) = ctx->r2;
    // 0x00244548: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024454C: sw          $v0, -0xC68($at)
    MEM_W(-0XC68, ctx->r1) = ctx->r2;
    // 0x00244550: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x00244554: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x00244558: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x0024455C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x00244560: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x00244564: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x00244568: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x0024456C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x00244570: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x00244574: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x00244578: jal         0x00262DC8
    // 0x0024457C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_00262DC8(rdram, ctx);
        goto after_5;
    // 0x0024457C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_5:
L_00244580:
    // 0x00244580: lwc1        $f1, 0x180($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X180);
    // 0x00244584: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00244588: c.eq.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl == ctx->f0.fl;
    // 0x0024458C: nop

    // 0x00244590: bc1t        L_002445A8
    if (c1cs) {
        // 0x00244594: nop
    
            goto L_002445A8;
    }
    // 0x00244594: nop

    // 0x00244598: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x0024459C: lb          $v0, 0xE($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XE);
    // 0x002445A0: j           L_002445B0
    // 0x002445A4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_002445B0;
    // 0x002445A4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_002445A8:
    // 0x002445A8: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x002445AC: lb          $v0, 0xE($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XE);
L_002445B0:
    // 0x002445B0: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x002445B4: sw          $v0, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r2;
    // 0x002445B8: lw          $v0, 0x18($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X18);
    // 0x002445BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x002445C0: sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3 << (ctx->r2 & 31));
    // 0x002445C4: sw          $v1, 0x170($s1)
    MEM_W(0X170, ctx->r17) = ctx->r3;
    // 0x002445C8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x002445CC: beq         $v0, $zero, L_00244624
    if (ctx->r2 == 0) {
        // 0x002445D0: lui         $v1, 0x2000
        ctx->r3 = S32(0X2000 << 16);
            goto L_00244624;
    }
    // 0x002445D0: lui         $v1, 0x2000
    ctx->r3 = S32(0X2000 << 16);
    // 0x002445D4: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x002445D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x002445DC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002445E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x002445E4: lb          $v0, 0x1B($s4)
    ctx->r2 = MEM_B(ctx->r20, 0X1B);
    // 0x002445E8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x002445EC: lb          $v0, 0x174($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X174);
    // 0x002445F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x002445F4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x002445F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x002445FC: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x00244600: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00244604: lw          $v0, -0x496C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X496C);
    // 0x00244608: lw          $a1, 0xB8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XB8);
    // 0x0024460C: sllv        $a3, $v0, $a2
    ctx->r7 = S32(ctx->r2 << (ctx->r6 & 31));
    // 0x00244610: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x00244614: sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7 << 3);
    // 0x00244618: addiu       $a3, $a3, 0x138
    ctx->r7 = ADD32(ctx->r7, 0X138);
    // 0x0024461C: jal         0x0021013C
    // 0x00244620: addu        $a3, $s1, $a3
    ctx->r7 = ADD32(ctx->r17, ctx->r7);
    func_0021013C(rdram, ctx);
        goto after_6;
    // 0x00244620: addu        $a3, $s1, $a3
    ctx->r7 = ADD32(ctx->r17, ctx->r7);
    after_6:
L_00244624:
    // 0x00244624: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x00244628: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x0024462C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x00244630: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x00244634: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x00244638: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x0024463C: jr          $ra
    // 0x00244640: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x00244640: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_00244644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00244644: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00244648: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x0024464C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00244650: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00244654: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00244658: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024465C: lwc1        $f0, -0x7528($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7528);
    // 0x00244660: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244664: lwc1        $f12, -0x7524($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7524);
    // 0x00244668: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024466C: lwc1        $f14, -0x7520($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7520);
    // 0x00244670: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00244674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x00244678: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024467C: sb          $v0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r2;
    // 0x00244680: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // 0x00244684: sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // 0x00244688: sb          $v0, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r2;
    // 0x0024468C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x00244690: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x00244694: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x00244698: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x0024469C: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x002446A0: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x002446A4: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x002446A8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x002446AC: addiu       $v0, $v0, -0x91C
    ctx->r2 = ADD32(ctx->r2, -0X91C);
    // 0x002446B0: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x002446B4: lui         $v0, 0x24
    ctx->r2 = S32(0X24 << 16);
    // 0x002446B8: addiu       $v0, $v0, 0x4A6C
    ctx->r2 = ADD32(ctx->r2, 0X4A6C);
    // 0x002446BC: sw          $v0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->r2;
    // 0x002446C0: lui         $v0, 0x24
    ctx->r2 = S32(0X24 << 16);
    // 0x002446C4: addiu       $v0, $v0, 0x72F4
    ctx->r2 = ADD32(ctx->r2, 0X72F4);
    // 0x002446C8: sw          $v0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r2;
    // 0x002446CC: lui         $v0, 0x24
    ctx->r2 = S32(0X24 << 16);
    // 0x002446D0: addiu       $v0, $v0, 0x72EC
    ctx->r2 = ADD32(ctx->r2, 0X72EC);
    // 0x002446D4: sw          $v0, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r2;
    // 0x002446D8: lui         $v0, 0x24
    ctx->r2 = S32(0X24 << 16);
    // 0x002446DC: addiu       $v0, $v0, 0x71A0
    ctx->r2 = ADD32(ctx->r2, 0X71A0);
    // 0x002446E0: sw          $v0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->r2;
    // 0x002446E4: lui         $v0, 0x24
    ctx->r2 = S32(0X24 << 16);
    // 0x002446E8: addiu       $v0, $v0, 0x3CE8
    ctx->r2 = ADD32(ctx->r2, 0X3CE8);
    // 0x002446EC: sw          $v0, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->r2;
    // 0x002446F0: sw          $zero, 0x154($s0)
    MEM_W(0X154, ctx->r16) = 0;
    // 0x002446F4: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
    // 0x002446F8: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x002446FC: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x00244700: swc1        $f0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f0.u32l;
    // 0x00244704: sw          $zero, 0x168($s0)
    MEM_W(0X168, ctx->r16) = 0;
    // 0x00244708: sw          $zero, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = 0;
    // 0x0024470C: jal         0x00215A90
    // 0x00244710: addiu       $s1, $v1, 0x14
    ctx->r17 = ADD32(ctx->r3, 0X14);
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x00244710: addiu       $s1, $v1, 0x14
    ctx->r17 = ADD32(ctx->r3, 0X14);
    after_0:
    // 0x00244714: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x00244718: sw          $zero, 0x178($s0)
    MEM_W(0X178, ctx->r16) = 0;
    // 0x0024471C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    // 0x00244720: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x00244724: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x00244728: lbu         $v0, 0x40($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X40);
    // 0x0024472C: sb          $v0, 0x174($s0)
    MEM_B(0X174, ctx->r16) = ctx->r2;
    // 0x00244730: lbu         $v0, 0x41($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X41);
    // 0x00244734: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x00244738: sb          $v0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r2;
    // 0x0024473C: lbu         $a0, 0x42($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X42);
    // 0x00244740: lb          $v0, 0x174($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X174);
    // 0x00244744: bne         $v0, $zero, L_00244770
    if (ctx->r2 != 0) {
        // 0x00244748: sb          $a0, 0x176($s0)
        MEM_B(0X176, ctx->r16) = ctx->r4;
            goto L_00244770;
    }
    // 0x00244748: sb          $a0, 0x176($s0)
    MEM_B(0X176, ctx->r16) = ctx->r4;
    // 0x0024474C: lb          $v0, 0x174($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X174);
    // 0x00244750: beq         $v0, $zero, L_00244760
    if (ctx->r2 == 0) {
        // 0x00244754: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00244760;
    }
    // 0x00244754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00244758: j           L_00244774
    // 0x0024475C: sb          $v0, 0x177($s0)
    MEM_B(0X177, ctx->r16) = ctx->r2;
        goto L_00244774;
    // 0x0024475C: sb          $v0, 0x177($s0)
    MEM_B(0X177, ctx->r16) = ctx->r2;
L_00244760:
    // 0x00244760: beq         $a0, $zero, L_00244770
    if (ctx->r4 == 0) {
        // 0x00244764: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00244770;
    }
    // 0x00244764: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00244768: j           L_00244774
    // 0x0024476C: sb          $v0, 0x177($s0)
    MEM_B(0X177, ctx->r16) = ctx->r2;
        goto L_00244774;
    // 0x0024476C: sb          $v0, 0x177($s0)
    MEM_B(0X177, ctx->r16) = ctx->r2;
L_00244770:
    // 0x00244770: sb          $zero, 0x177($s0)
    MEM_B(0X177, ctx->r16) = 0;
L_00244774:
    // 0x00244774: lui         $v0, 0x24
    ctx->r2 = S32(0X24 << 16);
    // 0x00244778: addiu       $v0, $v0, 0x6804
    ctx->r2 = ADD32(ctx->r2, 0X6804);
    // 0x0024477C: sw          $v0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->r2;
    // 0x00244780: lw          $a0, 0xF4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XF4);
    // 0x00244784: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x00244788: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x0024478C: bne         $v0, $zero, L_002447DC
    if (ctx->r2 != 0) {
        // 0x00244790: nop
    
            goto L_002447DC;
    }
    // 0x00244790: nop

    // 0x00244794: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x00244798: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x0024479C: beq         $v0, $zero, L_002447BC
    if (ctx->r2 == 0) {
        // 0x002447A0: lui         $v0, 0xFFEF
        ctx->r2 = S32(0XFFEF << 16);
            goto L_002447BC;
    }
    // 0x002447A0: lui         $v0, 0xFFEF
    ctx->r2 = S32(0XFFEF << 16);
    // 0x002447A4: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x002447A8: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x002447AC: ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // 0x002447B0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x002447B4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002447B8: sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
L_002447BC:
    // 0x002447BC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x002447C0: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x002447C4: beq         $v0, $zero, L_002447DC
    if (ctx->r2 == 0) {
        // 0x002447C8: lui         $v1, 0xFFFF
        ctx->r3 = S32(0XFFFF << 16);
            goto L_002447DC;
    }
    // 0x002447C8: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x002447CC: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x002447D0: ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // 0x002447D4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002447D8: sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
L_002447DC:
    // 0x002447DC: lhu         $v1, 0xD8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XD8);
    // 0x002447E0: addiu       $v0, $zero, 0x67
    ctx->r2 = ADD32(0, 0X67);
    // 0x002447E4: beq         $v1, $v0, L_00244804
    if (ctx->r3 == ctx->r2) {
        // 0x002447E8: addiu       $v0, $zero, 0x65
        ctx->r2 = ADD32(0, 0X65);
            goto L_00244804;
    }
    // 0x002447E8: addiu       $v0, $zero, 0x65
    ctx->r2 = ADD32(0, 0X65);
    // 0x002447EC: beq         $v1, $v0, L_00244804
    if (ctx->r3 == ctx->r2) {
        // 0x002447F0: addiu       $v0, $zero, 0x66
        ctx->r2 = ADD32(0, 0X66);
            goto L_00244804;
    }
    // 0x002447F0: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x002447F4: beq         $v1, $v0, L_00244804
    if (ctx->r3 == ctx->r2) {
        // 0x002447F8: addiu       $v0, $zero, 0x68
        ctx->r2 = ADD32(0, 0X68);
            goto L_00244804;
    }
    // 0x002447F8: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // 0x002447FC: bne         $v1, $v0, L_00244820
    if (ctx->r3 != ctx->r2) {
        // 0x00244800: nop
    
            goto L_00244820;
    }
    // 0x00244800: nop

L_00244804:
    // 0x00244804: lb          $v1, 0x174($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X174);
    // 0x00244808: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x0024480C: beq         $v1, $v0, L_00244820
    if (ctx->r3 == ctx->r2) {
        // 0x00244810: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00244820;
    }
    // 0x00244810: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00244814: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00244818: j           L_00244848
    // 0x0024481C: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
        goto L_00244848;
    // 0x0024481C: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
L_00244820:
    // 0x00244820: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x00244824: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x00244828: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024482C: beq         $v0, $zero, L_00244840
    if (ctx->r2 == 0) {
        // 0x00244830: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00244840;
    }
    // 0x00244830: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00244834: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00244838: j           L_00244848
    // 0x0024483C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_00244848;
    // 0x0024483C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_00244840:
    // 0x00244840: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00244844: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_00244848:
    // 0x00244848: jal         0x0023E684
    // 0x0024484C: nop

    func_0023E684(rdram, ctx);
        goto after_1;
    // 0x0024484C: nop

    after_1:
    // 0x00244850: sb          $zero, 0x33($s0)
    MEM_B(0X33, ctx->r16) = 0;
    // 0x00244854: lhu         $v1, 0xD8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XD8);
    // 0x00244858: addiu       $v0, $zero, 0x1C84
    ctx->r2 = ADD32(0, 0X1C84);
    // 0x0024485C: bne         $v1, $v0, L_00244874
    if (ctx->r3 != ctx->r2) {
        // 0x00244860: addiu       $v0, $zero, 0x3F1
        ctx->r2 = ADD32(0, 0X3F1);
            goto L_00244874;
    }
    // 0x00244860: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00244864: lui         $v0, 0x24
    ctx->r2 = S32(0X24 << 16);
    // 0x00244868: addiu       $v0, $v0, 0x4268
    ctx->r2 = ADD32(ctx->r2, 0X4268);
    // 0x0024486C: j           L_00244898
    // 0x00244870: sw          $v0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r2;
        goto L_00244898;
    // 0x00244870: sw          $v0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r2;
L_00244874:
    // 0x00244874: beq         $v1, $v0, L_0024488C
    if (ctx->r3 == ctx->r2) {
        // 0x00244878: addiu       $v0, $zero, 0x7D4
        ctx->r2 = ADD32(0, 0X7D4);
            goto L_0024488C;
    }
    // 0x00244878: addiu       $v0, $zero, 0x7D4
    ctx->r2 = ADD32(0, 0X7D4);
    // 0x0024487C: beq         $v1, $v0, L_0024488C
    if (ctx->r3 == ctx->r2) {
        // 0x00244880: addiu       $v0, $zero, 0x3EC
        ctx->r2 = ADD32(0, 0X3EC);
            goto L_0024488C;
    }
    // 0x00244880: addiu       $v0, $zero, 0x3EC
    ctx->r2 = ADD32(0, 0X3EC);
    // 0x00244884: bne         $v1, $v0, L_00244898
    if (ctx->r3 != ctx->r2) {
        // 0x00244888: nop
    
            goto L_00244898;
    }
    // 0x00244888: nop

L_0024488C:
    // 0x0024488C: lui         $v0, 0x24
    ctx->r2 = S32(0X24 << 16);
    // 0x00244890: addiu       $v0, $v0, 0x6ED4
    ctx->r2 = ADD32(ctx->r2, 0X6ED4);
    // 0x00244894: sw          $v0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r2;
L_00244898:
    // 0x00244898: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024489C: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x002448A0: jal         0x00200528
    // 0x002448A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_00200528(rdram, ctx);
        goto after_2;
    // 0x002448A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_2:
    // 0x002448A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x002448AC: bne         $v0, $a0, L_002448C4
    if (ctx->r2 != ctx->r4) {
        // 0x002448B0: lui         $v1, 0xFFFF
        ctx->r3 = S32(0XFFFF << 16);
            goto L_002448C4;
    }
    // 0x002448B0: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x002448B4: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x002448B8: ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // 0x002448BC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002448C0: sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
L_002448C4:
    // 0x002448C4: lhu         $v0, 0x4A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4A);
    // 0x002448C8: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x002448CC: bne         $v0, $zero, L_002448E0
    if (ctx->r2 != 0) {
        // 0x002448D0: nop
    
            goto L_002448E0;
    }
    // 0x002448D0: nop

    // 0x002448D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x002448D8: ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    // 0x002448DC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_002448E0:
    // 0x002448E0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x002448E4: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x002448E8: bne         $v0, $zero, L_00244930
    if (ctx->r2 != 0) {
        // 0x002448EC: addiu       $v0, $zero, 0x1C84
        ctx->r2 = ADD32(0, 0X1C84);
            goto L_00244930;
    }
    // 0x002448EC: addiu       $v0, $zero, 0x1C84
    ctx->r2 = ADD32(0, 0X1C84);
    // 0x002448F0: lhu         $v1, 0xD8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XD8);
    // 0x002448F4: beq         $v1, $v0, L_00244930
    if (ctx->r3 == ctx->r2) {
        // 0x002448F8: addiu       $v0, $zero, 0x4B5
        ctx->r2 = ADD32(0, 0X4B5);
            goto L_00244930;
    }
    // 0x002448F8: addiu       $v0, $zero, 0x4B5
    ctx->r2 = ADD32(0, 0X4B5);
    // 0x002448FC: beq         $v1, $v0, L_00244930
    if (ctx->r3 == ctx->r2) {
        // 0x00244900: addiu       $v0, $zero, 0x4B6
        ctx->r2 = ADD32(0, 0X4B6);
            goto L_00244930;
    }
    // 0x00244900: addiu       $v0, $zero, 0x4B6
    ctx->r2 = ADD32(0, 0X4B6);
    // 0x00244904: beq         $v1, $v0, L_00244930
    if (ctx->r3 == ctx->r2) {
        // 0x00244908: addiu       $v0, $zero, 0x4B1
        ctx->r2 = ADD32(0, 0X4B1);
            goto L_00244930;
    }
    // 0x00244908: addiu       $v0, $zero, 0x4B1
    ctx->r2 = ADD32(0, 0X4B1);
    // 0x0024490C: beq         $v1, $v0, L_00244930
    if (ctx->r3 == ctx->r2) {
        // 0x00244910: addiu       $v0, $zero, 0x7D5
        ctx->r2 = ADD32(0, 0X7D5);
            goto L_00244930;
    }
    // 0x00244910: addiu       $v0, $zero, 0x7D5
    ctx->r2 = ADD32(0, 0X7D5);
    // 0x00244914: beq         $v1, $v0, L_00244930
    if (ctx->r3 == ctx->r2) {
        // 0x00244918: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_00244930;
    }
    // 0x00244918: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024491C: sb          $a0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r4;
    // 0x00244920: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00244924: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    // 0x00244928: jal         0x00246878
    // 0x0024492C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_00246878(rdram, ctx);
        goto after_3;
    // 0x0024492C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
L_00244930:
    // 0x00244930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x00244934: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00244938: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0024493C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00244940: jr          $ra
    // 0x00244944: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00244944: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00244948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00244948: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0024494C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00244950: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00244954: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x00244958: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024495C: lwc1        $f0, 0x170($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X170);
    // 0x00244960: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244964: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00244968: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x0024496C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00244970: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00244974: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00244978: nop

    // 0x0024497C: bc1f        L_00244988
    if (!c1cs) {
        // 0x00244980: swc1        $f0, 0x170($s0)
        MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
            goto L_00244988;
    }
    // 0x00244980: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x00244984: swc1        $f1, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
L_00244988:
    // 0x00244988: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x0024498C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x00244990: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00244994: bne         $v0, $zero, L_002449AC
    if (ctx->r2 != 0) {
        // 0x00244998: lui         $v1, 0x2
        ctx->r3 = S32(0X2 << 16);
            goto L_002449AC;
    }
    // 0x00244998: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x0024499C: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x002449A0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002449A4: bne         $v0, $zero, L_00244A58
    if (ctx->r2 != 0) {
        // 0x002449A8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_00244A58;
    }
    // 0x002449A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_002449AC:
    // 0x002449AC: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x002449B0: beq         $v0, $zero, L_00244A54
    if (ctx->r2 == 0) {
        // 0x002449B4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_00244A54;
    }
    // 0x002449B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x002449B8: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x002449BC: bne         $v1, $v0, L_00244A54
    if (ctx->r3 != ctx->r2) {
        // 0x002449C0: nop
    
            goto L_00244A54;
    }
    // 0x002449C0: nop

    // 0x002449C4: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x002449C8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x002449CC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002449D0: beq         $v1, $v0, L_00244A54
    if (ctx->r3 == ctx->r2) {
        // 0x002449D4: nop
    
            goto L_00244A54;
    }
    // 0x002449D4: nop

    // 0x002449D8: lwc1        $f1, 0x170($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X170);
    // 0x002449DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x002449E0: c.eq.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl == ctx->f0.fl;
    // 0x002449E4: nop

    // 0x002449E8: bc1f        L_00244A54
    if (!c1cs) {
        // 0x002449EC: nop
    
            goto L_00244A54;
    }
    // 0x002449EC: nop

    // 0x002449F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002449F4: lwc1        $f12, -0x751C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X751C);
    // 0x002449F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002449FC: lwc1        $f14, -0x7518($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7518);
    // 0x00244A00: jal         0x00215A90
    // 0x00244A04: nop

    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x00244A04: nop

    after_0:
    // 0x00244A08: lb          $v1, 0x177($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X177);
    // 0x00244A0C: bne         $v1, $zero, L_00244A2C
    if (ctx->r3 != 0) {
        // 0x00244A10: swc1        $f0, 0x170($s0)
        MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
            goto L_00244A2C;
    }
    // 0x00244A10: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x00244A14: lb          $v0, 0x175($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X175);
    // 0x00244A18: beq         $v0, $zero, L_00244A54
    if (ctx->r2 == 0) {
        // 0x00244A1C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00244A54;
    }
    // 0x00244A1C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00244A20: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00244A24: j           L_00244A4C
    // 0x00244A28: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
        goto L_00244A4C;
    // 0x00244A28: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
L_00244A2C:
    // 0x00244A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00244A30: bne         $v1, $v0, L_00244A54
    if (ctx->r3 != ctx->r2) {
        // 0x00244A34: nop
    
            goto L_00244A54;
    }
    // 0x00244A34: nop

    // 0x00244A38: lb          $v0, 0x174($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X174);
    // 0x00244A3C: beq         $v0, $zero, L_00244A54
    if (ctx->r2 == 0) {
        // 0x00244A40: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00244A54;
    }
    // 0x00244A40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00244A44: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00244A48: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
L_00244A4C:
    // 0x00244A4C: jal         0x0023E684
    // 0x00244A50: nop

    func_0023E684(rdram, ctx);
        goto after_1;
    // 0x00244A50: nop

    after_1:
L_00244A54:
    // 0x00244A54: lb          $v0, 0x177($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X177);
L_00244A58:
    // 0x00244A58: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00244A5C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00244A60: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00244A64: jr          $ra
    // 0x00244A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00244A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00244A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00244A6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x00244A70: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x00244A74: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x00244A78: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00244A7C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x00244A80: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x00244A84: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x00244A88: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00244A8C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00244A90: lw          $v1, 0xF4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XF4);
    // 0x00244A94: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x00244A98: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00244A9C: bne         $v0, $zero, L_00244AB8
    if (ctx->r2 != 0) {
        // 0x00244AA0: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_00244AB8;
    }
    // 0x00244AA0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00244AA4: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x00244AA8: ori         $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 | 0X7FFF;
    // 0x00244AAC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00244AB0: j           L_00244FF8
    // 0x00244AB4: sw          $v0, 0xF4($s3)
    MEM_W(0XF4, ctx->r19) = ctx->r2;
        goto L_00244FF8;
    // 0x00244AB4: sw          $v0, 0xF4($s3)
    MEM_W(0XF4, ctx->r19) = ctx->r2;
L_00244AB8:
    // 0x00244AB8: lhu         $v1, 0xD8($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XD8);
    // 0x00244ABC: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00244AC0: beq         $v1, $v0, L_00244AD8
    if (ctx->r3 == ctx->r2) {
        // 0x00244AC4: addiu       $v0, $zero, 0x7D4
        ctx->r2 = ADD32(0, 0X7D4);
            goto L_00244AD8;
    }
    // 0x00244AC4: addiu       $v0, $zero, 0x7D4
    ctx->r2 = ADD32(0, 0X7D4);
    // 0x00244AC8: beq         $v1, $v0, L_00244AD8
    if (ctx->r3 == ctx->r2) {
        // 0x00244ACC: addiu       $v0, $zero, 0x3EC
        ctx->r2 = ADD32(0, 0X3EC);
            goto L_00244AD8;
    }
    // 0x00244ACC: addiu       $v0, $zero, 0x3EC
    ctx->r2 = ADD32(0, 0X3EC);
    // 0x00244AD0: bne         $v1, $v0, L_00244B98
    if (ctx->r3 != ctx->r2) {
        // 0x00244AD4: nop
    
            goto L_00244B98;
    }
    // 0x00244AD4: nop

L_00244AD8:
    // 0x00244AD8: lw          $v0, 0x10C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10C);
    // 0x00244ADC: beq         $v0, $zero, L_00244B98
    if (ctx->r2 == 0) {
        // 0x00244AE0: nop
    
            goto L_00244B98;
    }
    // 0x00244AE0: nop

    // 0x00244AE4: lw          $v0, 0x108($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X108);
    // 0x00244AE8: beq         $v0, $zero, L_00244B98
    if (ctx->r2 == 0) {
        // 0x00244AEC: sw          $zero, 0x10C($s1)
        MEM_W(0X10C, ctx->r17) = 0;
            goto L_00244B98;
    }
    // 0x00244AEC: sw          $zero, 0x10C($s1)
    MEM_W(0X10C, ctx->r17) = 0;
    // 0x00244AF0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x00244AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00244AF8: bne         $v1, $v0, L_00244B98
    if (ctx->r3 != ctx->r2) {
        // 0x00244AFC: nop
    
            goto L_00244B98;
    }
    // 0x00244AFC: nop

    // 0x00244B00: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x00244B04: addiu       $v1, $v1, -0x41B0
    ctx->r3 = ADD32(ctx->r3, -0X41B0);
    // 0x00244B08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x00244B0C: blez        $v0, L_00244B98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x00244B10: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_00244B98;
    }
    // 0x00244B10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00244B14: addiu       $a3, $v1, -0x4
    ctx->r7 = ADD32(ctx->r3, -0X4);
    // 0x00244B18: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x00244B1C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x00244B20: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244B24: lwc1        $f0, -0x7514($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7514);
    // 0x00244B28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244B2C: lwc1        $f1, -0x7510($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7510);
    // 0x00244B30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244B34: lwc1        $f2, -0x750C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X750C);
L_00244B38:
    // 0x00244B38: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x00244B3C: lw          $v1, 0x108($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X108);
    // 0x00244B40: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // 0x00244B44: beq         $a0, $v1, L_00244B54
    if (ctx->r4 == ctx->r3) {
        // 0x00244B48: addiu       $v0, $a0, 0x368
        ctx->r2 = ADD32(ctx->r4, 0X368);
            goto L_00244B54;
    }
    // 0x00244B48: addiu       $v0, $a0, 0x368
    ctx->r2 = ADD32(ctx->r4, 0X368);
    // 0x00244B4C: bnel        $v0, $v1, L_00244B88
    if (ctx->r2 != ctx->r3) {
        // 0x00244B50: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_00244B88;
    }
    goto skip_0;
    // 0x00244B50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
L_00244B54:
    // 0x00244B54: sw          $t0, 0xC40($a0)
    MEM_W(0XC40, ctx->r4) = ctx->r8;
    // 0x00244B58: swc1        $f0, 0xC44($a0)
    MEM_W(0XC44, ctx->r4) = ctx->f0.u32l;
    // 0x00244B5C: swc1        $f1, 0xC54($a0)
    MEM_W(0XC54, ctx->r4) = ctx->f_odd[(1 - 1) * 2];
    // 0x00244B60: swc1        $f2, 0xC58($a0)
    MEM_W(0XC58, ctx->r4) = ctx->f2.u32l;
    // 0x00244B64: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x00244B68: lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X6);
    // 0x00244B6C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x00244B70: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x00244B74: mtc1        $v1, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r3;
    // 0x00244B78: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00244B7C: div.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00244B80: j           L_00244B98
    // 0x00244B84: swc1        $f0, 0xC48($a0)
    MEM_W(0XC48, ctx->r4) = ctx->f0.u32l;
        goto L_00244B98;
    // 0x00244B84: swc1        $f0, 0xC48($a0)
    MEM_W(0XC48, ctx->r4) = ctx->f0.u32l;
L_00244B88:
    // 0x00244B88: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x00244B8C: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00244B90: bne         $v0, $zero, L_00244B38
    if (ctx->r2 != 0) {
        // 0x00244B94: addiu       $a2, $a2, 0x15C0
        ctx->r6 = ADD32(ctx->r6, 0X15C0);
            goto L_00244B38;
    }
    // 0x00244B94: addiu       $a2, $a2, 0x15C0
    ctx->r6 = ADD32(ctx->r6, 0X15C0);
L_00244B98:
    // 0x00244B98: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
    // 0x00244B9C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x00244BA0: beq         $v1, $v0, L_00244BD0
    if (ctx->r3 == ctx->r2) {
        // 0x00244BA4: nop
    
            goto L_00244BD0;
    }
    // 0x00244BA4: nop

    // 0x00244BA8: lwc1        $f1, 0x168($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X168);
    // 0x00244BAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00244BB0: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x00244BB4: nop

    // 0x00244BB8: bc1f        L_00244BD0
    if (!c1cs) {
        // 0x00244BBC: lui         $v1, 0xF7FF
        ctx->r3 = S32(0XF7FF << 16);
            goto L_00244BD0;
    }
    // 0x00244BBC: lui         $v1, 0xF7FF
    ctx->r3 = S32(0XF7FF << 16);
    // 0x00244BC0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x00244BC4: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00244BC8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00244BCC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_00244BD0:
    // 0x00244BD0: lb          $v0, 0x1C4($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1C4);
    // 0x00244BD4: lbu         $v1, 0x1C4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1C4);
    // 0x00244BD8: slti        $v0, $v0, 0x64
    ctx->r2 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x00244BDC: beq         $v0, $zero, L_00244BE8
    if (ctx->r2 == 0) {
        // 0x00244BE0: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_00244BE8;
    }
    // 0x00244BE0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x00244BE4: sb          $v0, 0x1C4($s1)
    MEM_B(0X1C4, ctx->r17) = ctx->r2;
L_00244BE8:
    // 0x00244BE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244BEC: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00244BF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244BF4: lwc1        $f0, -0x4964($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4964);
    // 0x00244BF8: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00244BFC: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x00244C00: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x00244C04: lw          $a3, 0xC($s3)
    ctx->r7 = MEM_W(ctx->r19, 0XC);
    // 0x00244C08: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x00244C0C: addiu       $a0, $a0, -0x41B8
    ctx->r4 = ADD32(ctx->r4, -0X41B8);
    // 0x00244C10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244C14: swc1        $f1, -0x4968($at)
    MEM_W(-0X4968, ctx->r1) = ctx->f_odd[(1 - 1) * 2];
    // 0x00244C18: jal         0x00236B1C
    // 0x00244C1C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    func_00236B1C(rdram, ctx);
        goto after_0;
    // 0x00244C1C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    after_0:
    // 0x00244C20: jal         0x00219A04
    // 0x00244C24: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00219A04(rdram, ctx);
        goto after_1;
    // 0x00244C24: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_1:
    // 0x00244C28: lb          $v0, 0x177($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X177);
    // 0x00244C2C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00244C30: addu        $v0, $s1, $s0
    ctx->r2 = ADD32(ctx->r17, ctx->r16);
    // 0x00244C34: lb          $v0, 0x174($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X174);
    // 0x00244C38: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x00244C3C: xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // 0x00244C40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244C44: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x00244C48: lw          $s2, 0x170($at)
    ctx->r18 = MEM_W(ctx->r1, 0X170);
    // 0x00244C4C: beq         $s2, $zero, L_00244CD8
    if (ctx->r18 == 0) {
        // 0x00244C50: sltu        $s5, $v0, $s4
        ctx->r21 = ctx->r2 < ctx->r20 ? 1 : 0;
            goto L_00244CD8;
    }
    // 0x00244C50: sltu        $s5, $v0, $s4
    ctx->r21 = ctx->r2 < ctx->r20 ? 1 : 0;
    // 0x00244C54: beq         $s0, $s4, L_00244C90
    if (ctx->r16 == ctx->r20) {
        // 0x00244C58: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_00244C90;
    }
    // 0x00244C58: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x00244C5C: beq         $v0, $zero, L_00244C74
    if (ctx->r2 == 0) {
        // 0x00244C60: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00244C74;
    }
    // 0x00244C60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00244C64: beq         $s0, $zero, L_00244C84
    if (ctx->r16 == 0) {
        // 0x00244C68: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_00244C84;
    }
    // 0x00244C68: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x00244C6C: j           L_00244CA0
    // 0x00244C70: nop

        goto L_00244CA0;
    // 0x00244C70: nop

L_00244C74:
    // 0x00244C74: beq         $s0, $v0, L_00244C9C
    if (ctx->r16 == ctx->r2) {
        // 0x00244C78: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_00244C9C;
    }
    // 0x00244C78: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x00244C7C: j           L_00244CA0
    // 0x00244C80: nop

        goto L_00244CA0;
    // 0x00244C80: nop

L_00244C84:
    // 0x00244C84: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x00244C88: j           L_00244CA0
    // 0x00244C8C: nop

        goto L_00244CA0;
    // 0x00244C8C: nop

L_00244C90:
    // 0x00244C90: lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC);
    // 0x00244C94: j           L_00244CA0
    // 0x00244C98: nop

        goto L_00244CA0;
    // 0x00244C98: nop

L_00244C9C:
    // 0x00244C9C: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
L_00244CA0:
    // 0x00244CA0: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x00244CA4: beq         $v0, $v1, L_00244CC4
    if (ctx->r2 == ctx->r3) {
        // 0x00244CA8: nop
    
            goto L_00244CC4;
    }
    // 0x00244CA8: nop

    // 0x00244CAC: sw          $v1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r3;
    // 0x00244CB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x00244CB4: beq         $v0, $zero, L_00244CC4
    if (ctx->r2 == 0) {
        // 0x00244CB8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00244CC4;
    }
    // 0x00244CB8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244CBC: jalr        $v0
    // 0x00244CC0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x00244CC0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
L_00244CC4:
    // 0x00244CC4: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x00244CC8: beq         $v0, $zero, L_00244CD8
    if (ctx->r2 == 0) {
        // 0x00244CCC: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00244CD8;
    }
    // 0x00244CCC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244CD0: jalr        $v0
    // 0x00244CD4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x00244CD4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_00244CD8:
    // 0x00244CD8: lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X30);
    // 0x00244CDC: addiu       $v0, $v0, -0x12
    ctx->r2 = ADD32(ctx->r2, -0X12);
    // 0x00244CE0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00244CE4: bne         $v0, $zero, L_00244D18
    if (ctx->r2 != 0) {
        // 0x00244CE8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00244D18;
    }
    // 0x00244CE8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244CEC: lwc1        $f0, 0x168($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X168);
    // 0x00244CF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244CF4: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00244CF8: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00244CFC: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00244D00: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00244D04: nop

    // 0x00244D08: bc1f        L_00244D18
    if (!c1cs) {
        // 0x00244D0C: swc1        $f0, 0x168($s1)
        MEM_W(0X168, ctx->r17) = ctx->f0.u32l;
            goto L_00244D18;
    }
    // 0x00244D0C: swc1        $f0, 0x168($s1)
    MEM_W(0X168, ctx->r17) = ctx->f0.u32l;
    // 0x00244D10: swc1        $f1, 0x168($s1)
    MEM_W(0X168, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    // 0x00244D14: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_00244D18:
    // 0x00244D18: jal         0x00244948
    // 0x00244D1C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_00244948(rdram, ctx);
        goto after_4;
    // 0x00244D1C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x00244D20: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x00244D24: beq         $v1, $zero, L_00244DE8
    if (ctx->r3 == 0) {
        // 0x00244D28: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_00244DE8;
    }
    // 0x00244D28: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00244D2C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00244D30: beq         $s0, $v0, L_00244D98
    if (ctx->r16 == ctx->r2) {
        // 0x00244D34: nop
    
            goto L_00244D98;
    }
    // 0x00244D34: nop

    // 0x00244D38: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x00244D3C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x00244D40: beq         $v0, $zero, L_00244D98
    if (ctx->r2 == 0) {
        // 0x00244D44: addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
            goto L_00244D98;
    }
    // 0x00244D44: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x00244D48: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
    // 0x00244D4C: beq         $v1, $v0, L_00244D98
    if (ctx->r3 == ctx->r2) {
        // 0x00244D50: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_00244D98;
    }
    // 0x00244D50: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x00244D54: beq         $v1, $v0, L_00244D98
    if (ctx->r3 == ctx->r2) {
        // 0x00244D58: nop
    
            goto L_00244D98;
    }
    // 0x00244D58: nop

    // 0x00244D5C: lb          $v0, 0x176($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X176);
    // 0x00244D60: beq         $v0, $zero, L_00244D98
    if (ctx->r2 == 0) {
        // 0x00244D64: nop
    
            goto L_00244D98;
    }
    // 0x00244D64: nop

    // 0x00244D68: bne         $s0, $zero, L_00244D80
    if (ctx->r16 != 0) {
        // 0x00244D6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00244D80;
    }
    // 0x00244D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00244D70: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244D74: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00244D78: j           L_00244D90
    // 0x00244D7C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
        goto L_00244D90;
    // 0x00244D7C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
L_00244D80:
    // 0x00244D80: bne         $s0, $v0, L_00244D98
    if (ctx->r16 != ctx->r2) {
        // 0x00244D84: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00244D98;
    }
    // 0x00244D84: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244D88: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00244D8C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_00244D90:
    // 0x00244D90: jal         0x0023E684
    // 0x00244D94: nop

    func_0023E684(rdram, ctx);
        goto after_5;
    // 0x00244D94: nop

    after_5:
L_00244D98:
    // 0x00244D98: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x00244D9C: beq         $v0, $zero, L_00244DE8
    if (ctx->r2 == 0) {
        // 0x00244DA0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00244DE8;
    }
    // 0x00244DA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00244DA4: bne         $s0, $v0, L_00244DE8
    if (ctx->r16 != ctx->r2) {
        // 0x00244DA8: nop
    
            goto L_00244DE8;
    }
    // 0x00244DA8: nop

    // 0x00244DAC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x00244DB0: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x00244DB4: bne         $v0, $zero, L_00244DE8
    if (ctx->r2 != 0) {
        // 0x00244DB8: addiu       $v0, $zero, 0x21
        ctx->r2 = ADD32(0, 0X21);
            goto L_00244DE8;
    }
    // 0x00244DB8: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // 0x00244DBC: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
    // 0x00244DC0: beq         $v1, $v0, L_00244DEC
    if (ctx->r3 == ctx->r2) {
        // 0x00244DC4: addiu       $v0, $zero, 0x22
        ctx->r2 = ADD32(0, 0X22);
            goto L_00244DEC;
    }
    // 0x00244DC4: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x00244DC8: beq         $v1, $v0, L_00244DF0
    if (ctx->r3 == ctx->r2) {
        // 0x00244DCC: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_00244DF0;
    }
    // 0x00244DCC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x00244DD0: lb          $v0, 0x174($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X174);
    // 0x00244DD4: beq         $v0, $zero, L_00244DEC
    if (ctx->r2 == 0) {
        // 0x00244DD8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00244DEC;
    }
    // 0x00244DD8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244DDC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00244DE0: jal         0x0023E684
    // 0x00244DE4: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    func_0023E684(rdram, ctx);
        goto after_6;
    // 0x00244DE4: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    after_6:
L_00244DE8:
    // 0x00244DE8: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
L_00244DEC:
    // 0x00244DEC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_00244DF0:
    // 0x00244DF0: bne         $v1, $v0, L_00244E04
    if (ctx->r3 != ctx->r2) {
        // 0x00244DF4: lui         $v1, 0x800
        ctx->r3 = S32(0X800 << 16);
            goto L_00244E04;
    }
    // 0x00244DF4: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x00244DF8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x00244DFC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00244E00: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_00244E04:
    // 0x00244E04: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x00244E08: beq         $v0, $zero, L_00244E24
    if (ctx->r2 == 0) {
        // 0x00244E0C: nop
    
            goto L_00244E24;
    }
    // 0x00244E0C: nop

    // 0x00244E10: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x00244E14: beq         $v0, $zero, L_00244E24
    if (ctx->r2 == 0) {
        // 0x00244E18: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00244E24;
    }
    // 0x00244E18: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244E1C: jalr        $v0
    // 0x00244E20: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_7;
    // 0x00244E20: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
L_00244E24:
    // 0x00244E24: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x00244E28: beq         $v0, $zero, L_00244E58
    if (ctx->r2 == 0) {
        // 0x00244E2C: nop
    
            goto L_00244E58;
    }
    // 0x00244E2C: nop

    // 0x00244E30: beq         $s5, $zero, L_00244E58
    if (ctx->r21 == 0) {
        // 0x00244E34: lui         $v1, 0xFEFF
        ctx->r3 = S32(0XFEFF << 16);
            goto L_00244E58;
    }
    // 0x00244E34: lui         $v1, 0xFEFF
    ctx->r3 = S32(0XFEFF << 16);
    // 0x00244E38: lwc1        $f0, 0x88($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X88);
    // 0x00244E3C: lwc1        $f1, 0x90($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X90);
    // 0x00244E40: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x00244E44: swc1        $f1, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    // 0x00244E48: lw          $v0, 0xF4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XF4);
    // 0x00244E4C: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00244E50: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00244E54: sw          $v0, 0xF4($s3)
    MEM_W(0XF4, ctx->r19) = ctx->r2;
L_00244E58:
    // 0x00244E58: lhu         $v1, 0xD8($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XD8);
    // 0x00244E5C: addiu       $v0, $zero, 0x1C84
    ctx->r2 = ADD32(0, 0X1C84);
    // 0x00244E60: beq         $v1, $v0, L_00244EC4
    if (ctx->r3 == ctx->r2) {
        // 0x00244E64: addiu       $v0, $zero, 0x7D5
        ctx->r2 = ADD32(0, 0X7D5);
            goto L_00244EC4;
    }
    // 0x00244E64: addiu       $v0, $zero, 0x7D5
    ctx->r2 = ADD32(0, 0X7D5);
    // 0x00244E68: beq         $v1, $v0, L_00244EC4
    if (ctx->r3 == ctx->r2) {
        // 0x00244E6C: addiu       $v0, $zero, 0x4B5
        ctx->r2 = ADD32(0, 0X4B5);
            goto L_00244EC4;
    }
    // 0x00244E6C: addiu       $v0, $zero, 0x4B5
    ctx->r2 = ADD32(0, 0X4B5);
    // 0x00244E70: beq         $v1, $v0, L_00244EC4
    if (ctx->r3 == ctx->r2) {
        // 0x00244E74: addiu       $v0, $zero, 0x4B6
        ctx->r2 = ADD32(0, 0X4B6);
            goto L_00244EC4;
    }
    // 0x00244E74: addiu       $v0, $zero, 0x4B6
    ctx->r2 = ADD32(0, 0X4B6);
    // 0x00244E78: beq         $v1, $v0, L_00244EC4
    if (ctx->r3 == ctx->r2) {
        // 0x00244E7C: addiu       $v0, $zero, 0x4B1
        ctx->r2 = ADD32(0, 0X4B1);
            goto L_00244EC4;
    }
    // 0x00244E7C: addiu       $v0, $zero, 0x4B1
    ctx->r2 = ADD32(0, 0X4B1);
    // 0x00244E80: beq         $v1, $v0, L_00244EC4
    if (ctx->r3 == ctx->r2) {
        // 0x00244E84: addiu       $v0, $zero, 0x7D3
        ctx->r2 = ADD32(0, 0X7D3);
            goto L_00244EC4;
    }
    // 0x00244E84: addiu       $v0, $zero, 0x7D3
    ctx->r2 = ADD32(0, 0X7D3);
    // 0x00244E88: bne         $v1, $v0, L_00244E9C
    if (ctx->r3 != ctx->r2) {
        // 0x00244E8C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_00244E9C;
    }
    // 0x00244E8C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x00244E90: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
    // 0x00244E94: beq         $v1, $v0, L_00244EC4
    if (ctx->r3 == ctx->r2) {
        // 0x00244E98: nop
    
            goto L_00244EC4;
    }
    // 0x00244E98: nop

L_00244E9C:
    // 0x00244E9C: lb          $v1, 0x174($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X174);
    // 0x00244EA0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00244EA4: bne         $v1, $v0, L_00244EBC
    if (ctx->r3 != ctx->r2) {
        // 0x00244EA8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00244EBC;
    }
    // 0x00244EA8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244EAC: lw          $v0, 0x188($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X188);
    // 0x00244EB0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x00244EB4: beq         $v0, $zero, L_00244EC4
    if (ctx->r2 == 0) {
        // 0x00244EB8: nop
    
            goto L_00244EC4;
    }
    // 0x00244EB8: nop

L_00244EBC:
    // 0x00244EBC: jal         0x002439E0
    // 0x00244EC0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_002439E0(rdram, ctx);
        goto after_8;
    // 0x00244EC0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_8:
L_00244EC4:
    // 0x00244EC4: lwc1        $f1, 0xBC($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0XBC);
    // 0x00244EC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00244ECC: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00244ED0: nop

    // 0x00244ED4: bc1f        L_00244EF8
    if (!c1cs) {
        // 0x00244ED8: nop
    
            goto L_00244EF8;
    }
    // 0x00244ED8: nop

    // 0x00244EDC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244EE0: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x00244EE4: sub.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x00244EE8: swc1        $f0, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->f0.u32l;
    // 0x00244EEC: lhu         $v0, 0x330($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X330);
    // 0x00244EF0: j           L_00244F00
    // 0x00244EF4: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
        goto L_00244F00;
    // 0x00244EF4: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_00244EF8:
    // 0x00244EF8: lhu         $v0, 0x330($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X330);
    // 0x00244EFC: andi        $v0, $v0, 0xFFFD
    ctx->r2 = ctx->r2 & 0XFFFD;
L_00244F00:
    // 0x00244F00: sh          $v0, 0x330($s3)
    MEM_H(0X330, ctx->r19) = ctx->r2;
    // 0x00244F04: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x00244F08: beq         $v0, $zero, L_00244FF8
    if (ctx->r2 == 0) {
        // 0x00244F0C: nop
    
            goto L_00244FF8;
    }
    // 0x00244F0C: nop

    // 0x00244F10: lb          $v1, 0x33($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X33);
    // 0x00244F14: beq         $v1, $zero, L_00244F2C
    if (ctx->r3 == 0) {
        // 0x00244F18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00244F2C;
    }
    // 0x00244F18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00244F1C: beq         $v1, $v0, L_00244FB0
    if (ctx->r3 == ctx->r2) {
        // 0x00244F20: nop
    
            goto L_00244FB0;
    }
    // 0x00244F20: nop

    // 0x00244F24: j           L_00244FF8
    // 0x00244F28: nop

        goto L_00244FF8;
    // 0x00244F28: nop

L_00244F2C:
    // 0x00244F2C: lwc1        $f1, 0x40($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X40);
    // 0x00244F30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244F34: lwc1        $f0, -0x7508($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7508);
    // 0x00244F38: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00244F3C: nop

    // 0x00244F40: bc1f        L_00244F88
    if (!c1cs) {
        // 0x00244F44: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00244F88;
    }
    // 0x00244F44: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00244F48: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00244F4C: jal         0x0023E684
    // 0x00244F50: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_0023E684(rdram, ctx);
        goto after_9;
    // 0x00244F50: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_9:
    // 0x00244F54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00244F58: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x00244F5C: addiu       $t4, $t4, -0xC74
    ctx->r12 = ADD32(ctx->r12, -0XC74);
    // 0x00244F60: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x00244F64: addiu       $t3, $t3, -0xC80
    ctx->r11 = ADD32(ctx->r11, -0XC80);
    // 0x00244F68: lw          $t1, 0x0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X0);
    // 0x00244F6C: lw          $t2, 0x4($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X4);
    // 0x00244F70: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x00244F74: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x00244F78: lw          $t1, 0x8($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X8);
    // 0x00244F7C: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x00244F80: j           L_00244FF8
    // 0x00244F84: sb          $v0, 0x33($s1)
    MEM_B(0X33, ctx->r17) = ctx->r2;
        goto L_00244FF8;
    // 0x00244F84: sb          $v0, 0x33($s1)
    MEM_B(0X33, ctx->r17) = ctx->r2;
L_00244F88:
    // 0x00244F88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00244F8C: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00244F90: nop

    // 0x00244F94: bc1f        L_00244FF8
    if (!c1cs) {
        // 0x00244F98: nop
    
            goto L_00244FF8;
    }
    // 0x00244F98: nop

    // 0x00244F9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244FA0: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x00244FA4: sub.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x00244FA8: j           L_00244FF8
    // 0x00244FAC: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
        goto L_00244FF8;
    // 0x00244FAC: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
L_00244FB0:
    // 0x00244FB0: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x00244FB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00244FB8: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00244FBC: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00244FC0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00244FC4: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00244FC8: nop

    // 0x00244FCC: bc1f        L_00244FF8
    if (!c1cs) {
        // 0x00244FD0: swc1        $f0, 0x40($s1)
        MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
            goto L_00244FF8;
    }
    // 0x00244FD0: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x00244FD4: lb          $v0, 0x80($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X80);
    // 0x00244FD8: beq         $v0, $zero, L_00244FF8
    if (ctx->r2 == 0) {
        // 0x00244FDC: sb          $zero, 0x33($s1)
        MEM_B(0X33, ctx->r17) = 0;
            goto L_00244FF8;
    }
    // 0x00244FDC: sb          $zero, 0x33($s1)
    MEM_B(0X33, ctx->r17) = 0;
    // 0x00244FE0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x00244FE4: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x00244FE8: lbu         $a1, 0x81($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X81);
    // 0x00244FEC: jal         0x00205774
    // 0x00244FF0: addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    func_00205774(rdram, ctx);
        goto after_10;
    // 0x00244FF0: addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    after_10:
    // 0x00244FF4: sh          $v0, 0x82($s1)
    MEM_H(0X82, ctx->r17) = ctx->r2;
L_00244FF8:
    // 0x00244FF8: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x00244FFC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x00245000: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x00245004: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x00245008: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x0024500C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00245010: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00245014: jr          $ra
    // 0x00245018: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x00245018: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_0024501C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024501C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x00245020: sw          $fp, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r30;
    // 0x00245024: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x00245028: sw          $s7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r23;
    // 0x0024502C: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x00245030: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x00245034: sw          $s6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r22;
    // 0x00245038: sw          $s5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r21;
    // 0x0024503C: sw          $s4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r20;
    // 0x00245040: sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // 0x00245044: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x00245048: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x0024504C: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x00245050: lw          $v1, 0x14($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X14);
    // 0x00245054: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x00245058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024505C: beq         $a0, $v0, L_00245070
    if (ctx->r4 == ctx->r2) {
        // 0x00245060: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_00245070;
    }
    // 0x00245060: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x00245064: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00245068: bne         $a0, $v0, L_00245074
    if (ctx->r4 != ctx->r2) {
        // 0x0024506C: nop
    
            goto L_00245074;
    }
    // 0x0024506C: nop

L_00245070:
    // 0x00245070: addiu       $s0, $v1, 0x14
    ctx->r16 = ADD32(ctx->r3, 0X14);
L_00245074:
    // 0x00245074: lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X44);
    // 0x00245078: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x0024507C: beq         $v1, $v0, L_0024535C
    if (ctx->r3 == ctx->r2) {
        // 0x00245080: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_0024535C;
    }
    // 0x00245080: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00245084: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    // 0x00245088: addu        $s4, $s1, $zero
    ctx->r20 = ADD32(ctx->r17, 0);
    // 0x0024508C: addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    // 0x00245090: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x00245094: lb          $a0, 0x177($s7)
    ctx->r4 = MEM_B(ctx->r23, 0X177);
    // 0x00245098: beq         $v1, $zero, L_00245158
    if (ctx->r3 == 0) {
        // 0x0024509C: addu        $s6, $s1, $zero
        ctx->r22 = ADD32(ctx->r17, 0);
            goto L_00245158;
    }
    // 0x0024509C: addu        $s6, $s1, $zero
    ctx->r22 = ADD32(ctx->r17, 0);
    // 0x002450A0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x002450A4: bne         $v0, $zero, L_00245158
    if (ctx->r2 != 0) {
        // 0x002450A8: nop
    
            goto L_00245158;
    }
    // 0x002450A8: nop

    // 0x002450AC: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x002450B0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x002450B4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x002450B8: beq         $v1, $v0, L_00245158
    if (ctx->r3 == ctx->r2) {
        // 0x002450BC: nop
    
            goto L_00245158;
    }
    // 0x002450BC: nop

    // 0x002450C0: bne         $a0, $zero, L_002450F4
    if (ctx->r4 != 0) {
        // 0x002450C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_002450F4;
    }
    // 0x002450C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002450C8: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x002450CC: lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4E);
    // 0x002450D0: andi        $s1, $v0, 0x1F
    ctx->r17 = ctx->r2 & 0X1F;
    // 0x002450D4: andi        $s4, $v1, 0x1F
    ctx->r20 = ctx->r3 & 0X1F;
    // 0x002450D8: lhu         $v0, 0x4C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4C);
    // 0x002450DC: lhu         $v1, 0x52($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X52);
    // 0x002450E0: andi        $s3, $v0, 0x1F
    ctx->r19 = ctx->r2 & 0X1F;
    // 0x002450E4: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
    // 0x002450E8: andi        $s6, $v1, 0x1F
    ctx->r22 = ctx->r3 & 0X1F;
    // 0x002450EC: j           L_00245158
    // 0x002450F0: andi        $s5, $v0, 0x1F
    ctx->r21 = ctx->r2 & 0X1F;
        goto L_00245158;
    // 0x002450F0: andi        $s5, $v0, 0x1F
    ctx->r21 = ctx->r2 & 0X1F;
L_002450F4:
    // 0x002450F4: bne         $a0, $v0, L_00245128
    if (ctx->r4 != ctx->r2) {
        // 0x002450F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00245128;
    }
    // 0x002450F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x002450FC: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x00245100: lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4E);
    // 0x00245104: andi        $s1, $v0, 0x3E0
    ctx->r17 = ctx->r2 & 0X3E0;
    // 0x00245108: andi        $s4, $v1, 0x3E0
    ctx->r20 = ctx->r3 & 0X3E0;
    // 0x0024510C: lhu         $v0, 0x4C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4C);
    // 0x00245110: lhu         $v1, 0x52($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X52);
    // 0x00245114: andi        $s3, $v0, 0x3E0
    ctx->r19 = ctx->r2 & 0X3E0;
    // 0x00245118: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
    // 0x0024511C: andi        $s6, $v1, 0x3E0
    ctx->r22 = ctx->r3 & 0X3E0;
    // 0x00245120: j           L_00245158
    // 0x00245124: andi        $s5, $v0, 0x3E0
    ctx->r21 = ctx->r2 & 0X3E0;
        goto L_00245158;
    // 0x00245124: andi        $s5, $v0, 0x3E0
    ctx->r21 = ctx->r2 & 0X3E0;
L_00245128:
    // 0x00245128: bne         $a0, $v0, L_00245158
    if (ctx->r4 != ctx->r2) {
        // 0x0024512C: nop
    
            goto L_00245158;
    }
    // 0x0024512C: nop

    // 0x00245130: lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4A);
    // 0x00245134: lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4E);
    // 0x00245138: andi        $s1, $v0, 0x7C00
    ctx->r17 = ctx->r2 & 0X7C00;
    // 0x0024513C: andi        $s4, $v1, 0x7C00
    ctx->r20 = ctx->r3 & 0X7C00;
    // 0x00245140: lhu         $v0, 0x4C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4C);
    // 0x00245144: lhu         $v1, 0x52($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X52);
    // 0x00245148: andi        $s3, $v0, 0x7C00
    ctx->r19 = ctx->r2 & 0X7C00;
    // 0x0024514C: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
    // 0x00245150: andi        $s6, $v1, 0x7C00
    ctx->r22 = ctx->r3 & 0X7C00;
    // 0x00245154: andi        $s5, $v0, 0x7C00
    ctx->r21 = ctx->r2 & 0X7C00;
L_00245158:
    // 0x00245158: jal         0x00262C94
    // 0x0024515C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_00262C94(rdram, ctx);
        goto after_0;
    // 0x0024515C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x00245160: lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X44);
    // 0x00245164: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x00245168: beq         $v1, $v0, L_00245290
    if (ctx->r3 == ctx->r2) {
        // 0x0024516C: nop
    
            goto L_00245290;
    }
    // 0x0024516C: nop

    // 0x00245170: beq         $s1, $zero, L_002451E0
    if (ctx->r17 == 0) {
        // 0x00245174: nop
    
            goto L_002451E0;
    }
    // 0x00245174: nop

    // 0x00245178: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x0024517C: beq         $v0, $zero, L_0024519C
    if (ctx->r2 == 0) {
        // 0x00245180: nop
    
            goto L_0024519C;
    }
    // 0x00245180: nop

    // 0x00245184: lwc1        $f1, 0x68($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X68);
    // 0x00245188: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x0024518C: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x00245190: nop

    // 0x00245194: bc1tl       L_002451D4
    if (c1cs) {
        // 0x00245198: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_002451D4;
    }
    goto skip_0;
    // 0x00245198: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    skip_0:
L_0024519C:
    // 0x0024519C: lw          $v0, 0x14($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X14);
    // 0x002451A0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x002451A4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002451A8: bne         $v1, $v0, L_002451E0
    if (ctx->r3 != ctx->r2) {
        // 0x002451AC: nop
    
            goto L_002451E0;
    }
    // 0x002451AC: nop

    // 0x002451B0: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x002451B4: beq         $v0, $zero, L_002451E0
    if (ctx->r2 == 0) {
        // 0x002451B8: nop
    
            goto L_002451E0;
    }
    // 0x002451B8: nop

    // 0x002451BC: lwc1        $f1, 0x24($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X24);
    // 0x002451C0: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x002451C4: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x002451C8: nop

    // 0x002451CC: bc1f        L_002451E0
    if (!c1cs) {
        // 0x002451D0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_002451E0;
    }
    // 0x002451D0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_002451D4:
    // 0x002451D4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x002451D8: jal         0x00262C9C
    // 0x002451DC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_00262C9C(rdram, ctx);
        goto after_1;
    // 0x002451DC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
L_002451E0:
    // 0x002451E0: beq         $s3, $zero, L_00245238
    if (ctx->r19 == 0) {
        // 0x002451E4: nop
    
            goto L_00245238;
    }
    // 0x002451E4: nop

    // 0x002451E8: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x002451EC: beq         $v0, $zero, L_00245238
    if (ctx->r2 == 0) {
        // 0x002451F0: nop
    
            goto L_00245238;
    }
    // 0x002451F0: nop

    // 0x002451F4: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    // 0x002451F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002451FC: lwc1        $f3, -0x7504($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, -0X7504);
    // 0x00245200: sub.s       $f0, $f2, $f3
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f3.fl;
    // 0x00245204: lwc1        $f1, 0x68($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X68);
    // 0x00245208: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x0024520C: nop

    // 0x00245210: bc1f        L_00245238
    if (!c1cs) {
        // 0x00245214: nop
    
            goto L_00245238;
    }
    // 0x00245214: nop

    // 0x00245218: add.s       $f0, $f2, $f3
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f3.fl;
    // 0x0024521C: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x00245220: nop

    // 0x00245224: bc1f        L_00245238
    if (!c1cs) {
        // 0x00245228: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_00245238;
    }
    // 0x00245228: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x0024522C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x00245230: jal         0x00262C9C
    // 0x00245234: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_00262C9C(rdram, ctx);
        goto after_2;
    // 0x00245234: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_2:
L_00245238:
    // 0x00245238: beq         $s4, $zero, L_00245290
    if (ctx->r20 == 0) {
        // 0x0024523C: nop
    
            goto L_00245290;
    }
    // 0x0024523C: nop

    // 0x00245240: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x00245244: beq         $v0, $zero, L_00245290
    if (ctx->r2 == 0) {
        // 0x00245248: nop
    
            goto L_00245290;
    }
    // 0x00245248: nop

    // 0x0024524C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x00245250: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245254: lwc1        $f3, -0x7500($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, -0X7500);
    // 0x00245258: sub.s       $f0, $f2, $f3
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f3.fl;
    // 0x0024525C: lwc1        $f1, 0x68($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X68);
    // 0x00245260: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00245264: nop

    // 0x00245268: bc1f        L_00245290
    if (!c1cs) {
        // 0x0024526C: nop
    
            goto L_00245290;
    }
    // 0x0024526C: nop

    // 0x00245270: add.s       $f0, $f2, $f3
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f3.fl;
    // 0x00245274: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x00245278: nop

    // 0x0024527C: bc1f        L_00245290
    if (!c1cs) {
        // 0x00245280: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_00245290;
    }
    // 0x00245280: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x00245284: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x00245288: jal         0x00262C9C
    // 0x0024528C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_00262C9C(rdram, ctx);
        goto after_3;
    // 0x0024528C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_3:
L_00245290:
    // 0x00245290: beq         $s5, $zero, L_002452D4
    if (ctx->r21 == 0) {
        // 0x00245294: nop
    
            goto L_002452D4;
    }
    // 0x00245294: nop

    // 0x00245298: lwc1        $f1, 0x168($s7)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r23, 0X168);
    // 0x0024529C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x002452A0: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x002452A4: nop

    // 0x002452A8: bc1f        L_002452D4
    if (!c1cs) {
        // 0x002452AC: nop
    
            goto L_002452D4;
    }
    // 0x002452AC: nop

    // 0x002452B0: lwc1        $f1, 0x24($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X24);
    // 0x002452B4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x002452B8: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x002452BC: nop

    // 0x002452C0: bc1f        L_002452D4
    if (!c1cs) {
        // 0x002452C4: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_002452D4;
    }
    // 0x002452C4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x002452C8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x002452CC: jal         0x00262C9C
    // 0x002452D0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_00262C9C(rdram, ctx);
        goto after_4;
    // 0x002452D0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_4:
L_002452D4:
    // 0x002452D4: beq         $s6, $zero, L_00245350
    if (ctx->r22 == 0) {
        // 0x002452D8: nop
    
            goto L_00245350;
    }
    // 0x002452D8: nop

    // 0x002452DC: lwc1        $f1, 0x168($s7)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r23, 0X168);
    // 0x002452E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x002452E4: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x002452E8: nop

    // 0x002452EC: bc1f        L_00245350
    if (!c1cs) {
        // 0x002452F0: nop
    
            goto L_00245350;
    }
    // 0x002452F0: nop

    // 0x002452F4: lwc1        $f1, 0x24($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X24);
    // 0x002452F8: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x002452FC: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x00245300: nop

    // 0x00245304: bc1f        L_00245350
    if (!c1cs) {
        // 0x00245308: nop
    
            goto L_00245350;
    }
    // 0x00245308: nop

    // 0x0024530C: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x00245310: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00245314: nop

    // 0x00245318: bc1f        L_00245350
    if (!c1cs) {
        // 0x0024531C: addiu       $v0, $zero, 0x3F1
        ctx->r2 = ADD32(0, 0X3F1);
            goto L_00245350;
    }
    // 0x0024531C: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00245320: lhu         $v1, 0xD8($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0XD8);
    // 0x00245324: bne         $v1, $v0, L_00245344
    if (ctx->r3 != ctx->r2) {
        // 0x00245328: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_00245344;
    }
    // 0x00245328: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x0024532C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245330: lwc1        $f0, -0x74FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74FC);
    // 0x00245334: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00245338: nop

    // 0x0024533C: bc1f        L_00245350
    if (!c1cs) {
        // 0x00245340: nop
    
            goto L_00245350;
    }
    // 0x00245340: nop

L_00245344:
    // 0x00245344: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x00245348: jal         0x00262C9C
    // 0x0024534C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_00262C9C(rdram, ctx);
        goto after_5;
    // 0x0024534C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_5:
L_00245350:
    // 0x00245350: lh          $v0, 0x10($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X10);
    // 0x00245354: bne         $v0, $zero, L_00245364
    if (ctx->r2 != 0) {
        // 0x00245358: nop
    
            goto L_00245364;
    }
    // 0x00245358: nop

L_0024535C:
    // 0x0024535C: j           L_00245374
    // 0x00245360: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_00245374;
    // 0x00245360: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00245364:
    // 0x00245364: jal         0x00262CE0
    // 0x00245368: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_00262CE0(rdram, ctx);
        goto after_6;
    // 0x00245368: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x0024536C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x00245370: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_00245374:
    // 0x00245374: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x00245378: lw          $fp, 0x98($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X98);
    // 0x0024537C: lw          $s7, 0x94($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X94);
    // 0x00245380: lw          $s6, 0x90($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X90);
    // 0x00245384: lw          $s5, 0x8C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X8C);
    // 0x00245388: lw          $s4, 0x88($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X88);
    // 0x0024538C: lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X84);
    // 0x00245390: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x00245394: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x00245398: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x0024539C: jr          $ra
    // 0x002453A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x002453A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_002453A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002453A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x002453A8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x002453AC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x002453B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x002453B4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002453B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002453BC: lb          $v1, 0x177($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X177);
    // 0x002453C0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x002453C4: bne         $v1, $zero, L_002453E0
    if (ctx->r3 != 0) {
        // 0x002453C8: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_002453E0;
    }
    // 0x002453C8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x002453CC: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x002453D0: lhu         $v0, 0x5C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5C);
    // 0x002453D4: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x002453D8: bne         $v0, $zero, L_0024541C
    if (ctx->r2 != 0) {
        // 0x002453DC: nop
    
            goto L_0024541C;
    }
    // 0x002453DC: nop

L_002453E0:
    // 0x002453E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002453E4: bne         $v1, $v0, L_00245400
    if (ctx->r3 != ctx->r2) {
        // 0x002453E8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00245400;
    }
    // 0x002453E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x002453EC: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x002453F0: lhu         $v0, 0x5C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5C);
    // 0x002453F4: andi        $v0, $v0, 0x3E0
    ctx->r2 = ctx->r2 & 0X3E0;
    // 0x002453F8: bne         $v0, $zero, L_0024541C
    if (ctx->r2 != 0) {
        // 0x002453FC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_0024541C;
    }
    // 0x002453FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_00245400:
    // 0x00245400: bne         $a0, $v0, L_002454F8
    if (ctx->r4 != ctx->r2) {
        // 0x00245404: nop
    
            goto L_002454F8;
    }
    // 0x00245404: nop

    // 0x00245408: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x0024540C: lhu         $v0, 0x5C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5C);
    // 0x00245410: andi        $v0, $v0, 0x7C00
    ctx->r2 = ctx->r2 & 0X7C00;
    // 0x00245414: beq         $v0, $zero, L_002454F8
    if (ctx->r2 == 0) {
        // 0x00245418: nop
    
            goto L_002454F8;
    }
    // 0x00245418: nop

L_0024541C:
    // 0x0024541C: lbu         $v0, 0xB4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XB4);
    // 0x00245420: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245424: lwc1        $f0, -0x74F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74F8);
    // 0x00245428: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x0024542C: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00245430: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00245434: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245438: lwc1        $f0, -0x74F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74F4);
    // 0x0024543C: mul.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00245440: nop

    // 0x00245444: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00245448: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024544C: lwc1        $f0, -0x74F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74F0);
    // 0x00245450: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00245454: trunc.w.s   $f2, $f1
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 1);
    ctx->f2.u32l = TRUNC_W_S(ctx->f1.fl);
    // 0x00245458: mfc1        $s0, $f2
    ctx->r16 = (int32_t)ctx->f2.u32l;
    // 0x0024545C: jal         0x002154EC
    // 0x00245460: nop

    func_002154EC(rdram, ctx);
        goto after_0;
    // 0x00245460: nop

    after_0:
    // 0x00245464: lui         $v1, 0x68DB
    ctx->r3 = S32(0X68DB << 16);
    // 0x00245468: ori         $v1, $v1, 0x8BAD
    ctx->r3 = ctx->r3 | 0X8BAD;
    // 0x0024546C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x00245470: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x00245474: mfhi        $t0
    ctx->r8 = hi;
    // 0x00245478: sra         $a0, $t0, 12
    ctx->r4 = S32(SIGNED(ctx->r8) >> 12);
    // 0x0024547C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x00245480: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x00245484: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x00245488: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x0024548C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x00245490: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x00245494: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x00245498: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x0024549C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x002454A0: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x002454A4: beq         $v0, $zero, L_002454F8
    if (ctx->r2 == 0) {
        // 0x002454A8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002454F8;
    }
    // 0x002454A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002454AC: lw          $a2, 0x74($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X74);
    // 0x002454B0: lui         $a3, 0x3E86
    ctx->r7 = S32(0X3E86 << 16);
    // 0x002454B4: ori         $a3, $a3, 0xA93
    ctx->r7 = ctx->r7 | 0XA93;
    // 0x002454B8: jal         0x00240FA0
    // 0x002454BC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_00240FA0(rdram, ctx);
        goto after_1;
    // 0x002454BC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x002454C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x002454C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x002454C8: bne         $v1, $v0, L_002454E0
    if (ctx->r3 != ctx->r2) {
        // 0x002454CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_002454E0;
    }
    // 0x002454CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002454D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002454D4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x002454D8: j           L_002454F0
    // 0x002454DC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
        goto L_002454F0;
    // 0x002454DC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
L_002454E0:
    // 0x002454E0: bne         $v1, $v0, L_002454F8
    if (ctx->r3 != ctx->r2) {
        // 0x002454E4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002454F8;
    }
    // 0x002454E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002454E8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x002454EC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_002454F0:
    // 0x002454F0: jal         0x0023E684
    // 0x002454F4: nop

    func_0023E684(rdram, ctx);
        goto after_2;
    // 0x002454F4: nop

    after_2:
L_002454F8:
    // 0x002454F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x002454FC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00245500: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00245504: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00245508: jr          $ra
    // 0x0024550C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0024550C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00245510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00245510: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x00245514: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x00245518: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x0024551C: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x00245520: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00245524: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00245528: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x0024552C: sw          $ra, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r31;
    // 0x00245530: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x00245534: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x00245538: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x0024553C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00245540: sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
    // 0x00245544: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x00245548: jal         0x00241C14
    // 0x0024554C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x0024554C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x00245550: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00245554: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00245558: jal         0x0024176C
    // 0x0024555C: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    func_0024176C(rdram, ctx);
        goto after_1;
    // 0x0024555C: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    after_1:
    // 0x00245560: lb          $v1, 0x177($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X177);
    // 0x00245564: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00245568: bne         $v1, $v0, L_002456BC
    if (ctx->r3 != ctx->r2) {
        // 0x0024556C: nop
    
            goto L_002456BC;
    }
    // 0x0024556C: nop

    // 0x00245570: lwc1        $f1, 0x80($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X80);
    // 0x00245574: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245578: lwc1        $f0, -0x74EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74EC);
    // 0x0024557C: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00245580: nop

    // 0x00245584: bc1f        L_002455D8
    if (!c1cs) {
        // 0x00245588: addiu       $v0, $zero, 0x3F1
        ctx->r2 = ADD32(0, 0X3F1);
            goto L_002455D8;
    }
    // 0x00245588: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x0024558C: lhu         $v1, 0xD8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XD8);
    // 0x00245590: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245594: lwc1        $f1, -0x74E8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X74E8);
    // 0x00245598: bne         $v1, $v0, L_002455A8
    if (ctx->r3 != ctx->r2) {
        // 0x0024559C: nop
    
            goto L_002455A8;
    }
    // 0x0024559C: nop

    // 0x002455A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002455A4: lwc1        $f1, -0x74E4($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X74E4);
L_002455A8:
    // 0x002455A8: lbu         $v0, 0x32($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X32);
    // 0x002455AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x002455B0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x002455B4: beq         $v0, $zero, L_002455C8
    if (ctx->r2 == 0) {
        // 0x002455B8: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_002455C8;
    }
    // 0x002455B8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x002455BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002455C0: lwc1        $f0, -0x74E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74E0);
    // 0x002455C4: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
L_002455C8:
    // 0x002455C8: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x002455CC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x002455D0: jal         0x0024197C
    // 0x002455D4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0024197C(rdram, ctx);
        goto after_2;
    // 0x002455D4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
L_002455D8:
    // 0x002455D8: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x002455DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x002455E0: bne         $v1, $v0, L_002455F4
    if (ctx->r3 != ctx->r2) {
        // 0x002455E4: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_002455F4;
    }
    // 0x002455E4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x002455E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x002455EC: j           L_002455FC
    // 0x002455F0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
        goto L_002455FC;
    // 0x002455F0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_002455F4:
    // 0x002455F4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x002455F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_002455FC:
    // 0x002455FC: jal         0x0023E684
    // 0x00245600: nop

    func_0023E684(rdram, ctx);
        goto after_3;
    // 0x00245600: nop

    after_3:
    // 0x00245604: lwc1        $f1, 0xB8($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0XB8);
    // 0x00245608: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024560C: lwc1        $f0, -0x74DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74DC);
    // 0x00245610: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00245614: lwc1        $f12, 0x1C($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x00245618: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x0024561C: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x00245620: jal         0x002156AC
    // 0x00245624: nop

    func_002156AC(rdram, ctx);
        goto after_4;
    // 0x00245624: nop

    after_4:
    // 0x00245628: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024562C: lwc1        $f1, -0x74D8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X74D8);
    // 0x00245630: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00245634: nop

    // 0x00245638: bc1t        L_00245658
    if (c1cs) {
        // 0x0024563C: swc1        $f0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
            goto L_00245658;
    }
    // 0x0024563C: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x00245640: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245644: lwc1        $f1, -0x74D4($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X74D4);
    // 0x00245648: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x0024564C: nop

    // 0x00245650: bc1f        L_0024565C
    if (!c1cs) {
        // 0x00245654: nop
    
            goto L_0024565C;
    }
    // 0x00245654: nop

L_00245658:
    // 0x00245658: swc1        $f1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f_odd[(1 - 1) * 2];
L_0024565C:
    // 0x0024565C: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x00245660: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245664: lwc1        $f1, -0x74D0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X74D0);
    // 0x00245668: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x0024566C: mul.s       $f14, $f0, $f1
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00245670: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245674: lwc1        $f0, -0x74CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74CC);
    // 0x00245678: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x0024567C: nop

    // 0x00245680: bc1tl       L_002456A0
    if (c1cs) {
        // 0x00245684: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_002456A0;
    }
    goto skip_0;
    // 0x00245684: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    skip_0:
    // 0x00245688: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024568C: lwc1        $f0, -0x74C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74C8);
    // 0x00245690: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x00245694: nop

    // 0x00245698: bc1tl       L_002456A0
    if (c1cs) {
        // 0x0024569C: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_002456A0;
    }
    goto skip_1;
    // 0x0024569C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    skip_1:
L_002456A0:
    // 0x002456A0: lwc1        $f12, 0x154($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X154);
    // 0x002456A4: lui         $a2, 0x3D8E
    ctx->r6 = S32(0X3D8E << 16);
    // 0x002456A8: ori         $a2, $a2, 0xFA36
    ctx->r6 = ctx->r6 | 0XFA36;
    // 0x002456AC: jal         0x00215814
    // 0x002456B0: nop

    func_00215814(rdram, ctx);
        goto after_5;
    // 0x002456B0: nop

    after_5:
    // 0x002456B4: j           L_002457A8
    // 0x002456B8: swc1        $f0, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f0.u32l;
        goto L_002457A8;
    // 0x002456B8: swc1        $f0, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f0.u32l;
L_002456BC:
    // 0x002456BC: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x002456C0: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x002456C4: bne         $v0, $zero, L_0024575C
    if (ctx->r2 != 0) {
        // 0x002456C8: addiu       $v0, $zero, 0x3F1
        ctx->r2 = ADD32(0, 0X3F1);
            goto L_0024575C;
    }
    // 0x002456C8: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x002456CC: lhu         $v1, 0xD8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XD8);
    // 0x002456D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002456D4: lwc1        $f2, -0x74C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X74C4);
    // 0x002456D8: bne         $v1, $v0, L_002456E8
    if (ctx->r3 != ctx->r2) {
        // 0x002456DC: nop
    
            goto L_002456E8;
    }
    // 0x002456DC: nop

    // 0x002456E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002456E4: lwc1        $f2, -0x74C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X74C0);
L_002456E8:
    // 0x002456E8: lbu         $v0, 0x32($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X32);
    // 0x002456EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x002456F0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x002456F4: beq         $v0, $zero, L_00245708
    if (ctx->r2 == 0) {
        // 0x002456F8: nop
    
            goto L_00245708;
    }
    // 0x002456F8: nop

    // 0x002456FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245700: lwc1        $f0, -0x74BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74BC);
    // 0x00245704: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
L_00245708:
    // 0x00245708: lwc1        $f1, 0x80($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X80);
    // 0x0024570C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245710: lwc1        $f0, -0x74B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74B8);
    // 0x00245714: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00245718: nop

    // 0x0024571C: bc1f        L_00245730
    if (!c1cs) {
        // 0x00245720: nop
    
            goto L_00245730;
    }
    // 0x00245720: nop

    // 0x00245724: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245728: lwc1        $f0, -0x74B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74B4);
    // 0x0024572C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
L_00245730:
    // 0x00245730: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
    // 0x00245734: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00245738: bne         $v1, $v0, L_0024574C
    if (ctx->r3 != ctx->r2) {
        // 0x0024573C: nop
    
            goto L_0024574C;
    }
    // 0x0024573C: nop

    // 0x00245740: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245744: lwc1        $f0, -0x74B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74B0);
    // 0x00245748: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
L_0024574C:
    // 0x0024574C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x00245750: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x00245754: j           L_002457A0
    // 0x00245758: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_002457A0;
    // 0x00245758: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_0024575C:
    // 0x0024575C: lhu         $v1, 0xD8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XD8);
    // 0x00245760: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245764: lwc1        $f1, -0x74AC($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X74AC);
    // 0x00245768: bne         $v1, $v0, L_00245778
    if (ctx->r3 != ctx->r2) {
        // 0x0024576C: nop
    
            goto L_00245778;
    }
    // 0x0024576C: nop

    // 0x00245770: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245774: lwc1        $f1, -0x74A8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X74A8);
L_00245778:
    // 0x00245778: lbu         $v0, 0x32($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X32);
    // 0x0024577C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00245780: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00245784: beq         $v0, $zero, L_00245798
    if (ctx->r2 == 0) {
        // 0x00245788: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00245798;
    }
    // 0x00245788: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x0024578C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245790: lwc1        $f0, -0x74A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74A4);
    // 0x00245794: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
L_00245798:
    // 0x00245798: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x0024579C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_002457A0:
    // 0x002457A0: jal         0x0024197C
    // 0x002457A4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0024197C(rdram, ctx);
        goto after_6;
    // 0x002457A4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_6:
L_002457A8:
    // 0x002457A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x002457AC: beq         $v0, $zero, L_00245854
    if (ctx->r2 == 0) {
        // 0x002457B0: addiu       $v0, $zero, 0x3F1
        ctx->r2 = ADD32(0, 0X3F1);
            goto L_00245854;
    }
    // 0x002457B0: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x002457B4: lhu         $v1, 0xD8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XD8);
    // 0x002457B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002457BC: lwc1        $f2, -0x74A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X74A0);
    // 0x002457C0: bne         $v1, $v0, L_002457D0
    if (ctx->r3 != ctx->r2) {
        // 0x002457C4: nop
    
            goto L_002457D0;
    }
    // 0x002457C4: nop

    // 0x002457C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002457CC: lwc1        $f2, -0x749C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X749C);
L_002457D0:
    // 0x002457D0: lwc1        $f1, 0x20($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x002457D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x002457D8: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x002457DC: nop

    // 0x002457E0: bc1f        L_00245804
    if (!c1cs) {
        // 0x002457E4: nop
    
            goto L_00245804;
    }
    // 0x002457E4: nop

    // 0x002457E8: neg.s       $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = -ctx->f1.fl;
    // 0x002457EC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x002457F0: nop

    // 0x002457F4: bc1t        L_00245814
    if (c1cs) {
        // 0x002457F8: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00245814;
    }
    // 0x002457F8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x002457FC: j           L_00245854
    // 0x00245800: nop

        goto L_00245854;
    // 0x00245800: nop

L_00245804:
    // 0x00245804: c.le.s      $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f1.fl <= ctx->f2.fl;
    // 0x00245808: nop

    // 0x0024580C: bc1f        L_00245854
    if (!c1cs) {
        // 0x00245810: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00245854;
    }
    // 0x00245810: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_00245814:
    // 0x00245814: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00245818: jal         0x0024501C
    // 0x0024581C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_0024501C(rdram, ctx);
        goto after_7;
    // 0x0024581C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_7:
    // 0x00245820: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x00245824: beq         $a2, $zero, L_00245854
    if (ctx->r6 == 0) {
        // 0x00245828: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00245854;
    }
    // 0x00245828: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0024582C: lb          $v1, 0x174($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X174);
    // 0x00245830: bne         $v1, $v0, L_00245844
    if (ctx->r3 != ctx->r2) {
        // 0x00245834: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00245844;
    }
    // 0x00245834: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00245838: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x0024583C: beq         $a2, $v0, L_002459D0
    if (ctx->r6 == ctx->r2) {
        // 0x00245840: nop
    
            goto L_002459D0;
    }
    // 0x00245840: nop

L_00245844:
    // 0x00245844: jal         0x0023E684
    // 0x00245848: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0023E684(rdram, ctx);
        goto after_8;
    // 0x00245848: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_8:
    // 0x0024584C: j           L_002459D0
    // 0x00245850: nop

        goto L_002459D0;
    // 0x00245850: nop

L_00245854:
    // 0x00245854: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x00245858: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x0024585C: beq         $v1, $v0, L_0024586C
    if (ctx->r3 == ctx->r2) {
        // 0x00245860: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_0024586C;
    }
    // 0x00245860: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x00245864: bne         $v1, $v0, L_0024587C
    if (ctx->r3 != ctx->r2) {
        // 0x00245868: nop
    
            goto L_0024587C;
    }
    // 0x00245868: nop

L_0024586C:
    // 0x0024586C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245870: lwc1        $f1, -0x7498($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7498);
    // 0x00245874: j           L_00245884
    // 0x00245878: nop

        goto L_00245884;
    // 0x00245878: nop

L_0024587C:
    // 0x0024587C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245880: lwc1        $f1, -0x7494($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7494);
L_00245884:
    // 0x00245884: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x00245888: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x0024588C: beq         $v0, $zero, L_002458A0
    if (ctx->r2 == 0) {
        // 0x00245890: nop
    
            goto L_002458A0;
    }
    // 0x00245890: nop

    // 0x00245894: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245898: lwc1        $f0, -0x7490($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7490);
    // 0x0024589C: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
L_002458A0:
    // 0x002458A0: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
    // 0x002458A4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x002458A8: bne         $v1, $v0, L_002458BC
    if (ctx->r3 != ctx->r2) {
        // 0x002458AC: nop
    
            goto L_002458BC;
    }
    // 0x002458AC: nop

    // 0x002458B0: lb          $v0, 0xB3($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XB3);
    // 0x002458B4: beq         $v0, $zero, L_002459C8
    if (ctx->r2 == 0) {
        // 0x002458B8: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_002459C8;
    }
    // 0x002458B8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_002458BC:
    // 0x002458BC: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x002458C0: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x002458C4: nop

    // 0x002458C8: bc1f        L_0024593C
    if (!c1cs) {
        // 0x002458CC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0024593C;
    }
    // 0x002458CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x002458D0: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x002458D4: beq         $v1, $v0, L_002458EC
    if (ctx->r3 == ctx->r2) {
        // 0x002458D8: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_002458EC;
    }
    // 0x002458D8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x002458DC: beq         $v1, $v0, L_00245928
    if (ctx->r3 == ctx->r2) {
        // 0x002458E0: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00245928;
    }
    // 0x002458E0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x002458E4: j           L_00245934
    // 0x002458E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
        goto L_00245934;
    // 0x002458E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_002458EC:
    // 0x002458EC: addiu       $s0, $s1, 0x80
    ctx->r16 = ADD32(ctx->r17, 0X80);
    // 0x002458F0: jal         0x00283210
    // 0x002458F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00283210(rdram, ctx);
        goto after_9;
    // 0x002458F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x002458F8: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x002458FC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x00245900: beq         $v0, $zero, L_00245914
    if (ctx->r2 == 0) {
        // 0x00245904: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00245914;
    }
    // 0x00245904: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00245908: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0024590C: j           L_002459BC
    // 0x00245910: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
        goto L_002459BC;
    // 0x00245910: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
L_00245914:
    // 0x00245914: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00245918: jal         0x002830A8
    // 0x0024591C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_002830A8(rdram, ctx);
        goto after_10;
    // 0x0024591C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_10:
    // 0x00245920: j           L_002459C8
    // 0x00245924: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_002459C8;
    // 0x00245924: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_00245928:
    // 0x00245928: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0024592C: j           L_002459BC
    // 0x00245930: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
        goto L_002459BC;
    // 0x00245930: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
L_00245934:
    // 0x00245934: j           L_002459BC
    // 0x00245938: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
        goto L_002459BC;
    // 0x00245938: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_0024593C:
    // 0x0024593C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x00245940: bne         $v1, $v0, L_00245954
    if (ctx->r3 != ctx->r2) {
        // 0x00245944: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00245954;
    }
    // 0x00245944: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00245948: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0024594C: j           L_002459BC
    // 0x00245950: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
        goto L_002459BC;
    // 0x00245950: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_00245954:
    // 0x00245954: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x00245958: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x0024595C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x00245960: nop

    // 0x00245964: bc1f        L_00245990
    if (!c1cs) {
        // 0x00245968: nop
    
            goto L_00245990;
    }
    // 0x00245968: nop

    // 0x0024596C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245970: lwc1        $f1, -0x748C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X748C);
    // 0x00245974: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x00245978: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x0024597C: nop

    // 0x00245980: bc1t        L_002459A8
    if (c1cs) {
        // 0x00245984: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_002459A8;
    }
    // 0x00245984: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00245988: j           L_002459B8
    // 0x0024598C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
        goto L_002459B8;
    // 0x0024598C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_00245990:
    // 0x00245990: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245994: lwc1        $f0, -0x7488($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7488);
    // 0x00245998: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x0024599C: nop

    // 0x002459A0: bc1f        L_002459B4
    if (!c1cs) {
        // 0x002459A4: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_002459B4;
    }
    // 0x002459A4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_002459A8:
    // 0x002459A8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x002459AC: j           L_002459BC
    // 0x002459B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
        goto L_002459BC;
    // 0x002459B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_002459B4:
    // 0x002459B4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_002459B8:
    // 0x002459B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_002459BC:
    // 0x002459BC: jal         0x0023E684
    // 0x002459C0: nop

    func_0023E684(rdram, ctx);
        goto after_11;
    // 0x002459C0: nop

    after_11:
    // 0x002459C4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_002459C8:
    // 0x002459C8: jal         0x002453A4
    // 0x002459CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_002453A4(rdram, ctx);
        goto after_12;
    // 0x002459CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_12:
L_002459D0:
    // 0x002459D0: lw          $ra, 0xEC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XEC);
    // 0x002459D4: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x002459D8: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x002459DC: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x002459E0: jr          $ra
    // 0x002459E4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x002459E4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_002459E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002459E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x002459EC: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x002459F0: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x002459F4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x002459F8: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x002459FC: addiu       $a0, $s4, 0x80
    ctx->r4 = ADD32(ctx->r20, 0X80);
    // 0x00245A00: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x00245A04: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x00245A08: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00245A0C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00245A10: jal         0x00283210
    // 0x00245A14: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_00283210(rdram, ctx);
        goto after_0;
    // 0x00245A14: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x00245A18: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x00245A1C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x00245A20: lhu         $v0, 0x16($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X16);
    // 0x00245A24: lb          $s0, 0x177($s4)
    ctx->r16 = MEM_B(ctx->r20, 0X177);
    // 0x00245A28: beq         $v0, $zero, L_00245AAC
    if (ctx->r2 == 0) {
        // 0x00245A2C: addu        $s3, $s2, $zero
        ctx->r19 = ADD32(ctx->r18, 0);
            goto L_00245AAC;
    }
    // 0x00245A2C: addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
    // 0x00245A30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00245A34: beq         $s0, $v0, L_00245A78
    if (ctx->r16 == ctx->r2) {
        // 0x00245A38: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_00245A78;
    }
    // 0x00245A38: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x00245A3C: beq         $v0, $zero, L_00245A54
    if (ctx->r2 == 0) {
        // 0x00245A40: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00245A54;
    }
    // 0x00245A40: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00245A44: beq         $s0, $zero, L_00245A64
    if (ctx->r16 == 0) {
        // 0x00245A48: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_00245A64;
    }
    // 0x00245A48: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x00245A4C: j           L_00245AAC
    // 0x00245A50: nop

        goto L_00245AAC;
    // 0x00245A50: nop

L_00245A54:
    // 0x00245A54: beq         $s0, $v0, L_00245A90
    if (ctx->r16 == ctx->r2) {
        // 0x00245A58: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_00245A90;
    }
    // 0x00245A58: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x00245A5C: j           L_00245AAC
    // 0x00245A60: nop

        goto L_00245AAC;
    // 0x00245A60: nop

L_00245A64:
    // 0x00245A64: lhu         $a3, 0x16($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X16);
    // 0x00245A68: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00245A6C: addiu       $a2, $a2, -0x1A90
    ctx->r6 = ADD32(ctx->r6, -0X1A90);
    // 0x00245A70: j           L_00245AA0
    // 0x00245A74: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
        goto L_00245AA0;
    // 0x00245A74: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
L_00245A78:
    // 0x00245A78: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x00245A7C: lhu         $a3, 0x16($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X16);
    // 0x00245A80: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00245A84: addiu       $a2, $a2, -0x1A60
    ctx->r6 = ADD32(ctx->r6, -0X1A60);
    // 0x00245A88: j           L_00245AA0
    // 0x00245A8C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
        goto L_00245AA0;
    // 0x00245A8C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
L_00245A90:
    // 0x00245A90: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x00245A94: lhu         $a3, 0x16($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X16);
    // 0x00245A98: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00245A9C: addiu       $a2, $a2, -0x1A30
    ctx->r6 = ADD32(ctx->r6, -0X1A30);
L_00245AA0:
    // 0x00245AA0: jal         0x00241868
    // 0x00245AA4: nop

    func_00241868(rdram, ctx);
        goto after_1;
    // 0x00245AA4: nop

    after_1:
    // 0x00245AA8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_00245AAC:
    // 0x00245AAC: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x00245AB0: beq         $v0, $zero, L_00245B38
    if (ctx->r2 == 0) {
        // 0x00245AB4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00245B38;
    }
    // 0x00245AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00245AB8: beq         $s0, $v0, L_00245B00
    if (ctx->r16 == ctx->r2) {
        // 0x00245ABC: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_00245B00;
    }
    // 0x00245ABC: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x00245AC0: beq         $v0, $zero, L_00245AD8
    if (ctx->r2 == 0) {
        // 0x00245AC4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00245AD8;
    }
    // 0x00245AC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00245AC8: beq         $s0, $zero, L_00245AE8
    if (ctx->r16 == 0) {
        // 0x00245ACC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_00245AE8;
    }
    // 0x00245ACC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00245AD0: j           L_00245B3C
    // 0x00245AD4: nop

        goto L_00245B3C;
    // 0x00245AD4: nop

L_00245AD8:
    // 0x00245AD8: beq         $s0, $v0, L_00245B18
    if (ctx->r16 == ctx->r2) {
        // 0x00245ADC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_00245B18;
    }
    // 0x00245ADC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00245AE0: j           L_00245B3C
    // 0x00245AE4: nop

        goto L_00245B3C;
    // 0x00245AE4: nop

L_00245AE8:
    // 0x00245AE8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x00245AEC: lhu         $a3, 0x18($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X18);
    // 0x00245AF0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00245AF4: addiu       $a2, $a2, -0x1A00
    ctx->r6 = ADD32(ctx->r6, -0X1A00);
    // 0x00245AF8: j           L_00245B2C
    // 0x00245AFC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
        goto L_00245B2C;
    // 0x00245AFC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
L_00245B00:
    // 0x00245B00: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x00245B04: lhu         $a3, 0x18($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X18);
    // 0x00245B08: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00245B0C: addiu       $a2, $a2, -0x19D0
    ctx->r6 = ADD32(ctx->r6, -0X19D0);
    // 0x00245B10: j           L_00245B2C
    // 0x00245B14: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
        goto L_00245B2C;
    // 0x00245B14: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
L_00245B18:
    // 0x00245B18: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x00245B1C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x00245B20: lhu         $a3, 0x18($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X18);
    // 0x00245B24: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x00245B28: addiu       $a2, $a2, -0x19A0
    ctx->r6 = ADD32(ctx->r6, -0X19A0);
L_00245B2C:
    // 0x00245B2C: jal         0x00241868
    // 0x00245B30: nop

    func_00241868(rdram, ctx);
        goto after_2;
    // 0x00245B30: nop

    after_2:
    // 0x00245B34: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_00245B38:
    // 0x00245B38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_00245B3C:
    // 0x00245B3C: beq         $s2, $v0, L_00245BAC
    if (ctx->r18 == ctx->r2) {
        // 0x00245B40: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_00245BAC;
    }
    // 0x00245B40: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x00245B44: beq         $s3, $v0, L_00245BA0
    if (ctx->r19 == ctx->r2) {
        // 0x00245B48: nop
    
            goto L_00245BA0;
    }
    // 0x00245B48: nop

    // 0x00245B4C: jal         0x002154EC
    // 0x00245B50: nop

    func_002154EC(rdram, ctx);
        goto after_3;
    // 0x00245B50: nop

    after_3:
    // 0x00245B54: lui         $v1, 0x1062
    ctx->r3 = S32(0X1062 << 16);
    // 0x00245B58: ori         $v1, $v1, 0x4DD3
    ctx->r3 = ctx->r3 | 0X4DD3;
    // 0x00245B5C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x00245B60: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x00245B64: sra         $v1, $a1, 31
    ctx->r3 = S32(SIGNED(ctx->r5) >> 31);
    // 0x00245B68: mfhi        $t0
    ctx->r8 = hi;
    // 0x00245B6C: sra         $a0, $t0, 6
    ctx->r4 = S32(SIGNED(ctx->r8) >> 6);
    // 0x00245B70: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x00245B74: sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4 << 5);
    // 0x00245B78: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x00245B7C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x00245B80: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x00245B84: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x00245B88: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x00245B8C: slti        $a1, $a1, 0x1F5
    ctx->r5 = SIGNED(ctx->r5) < 0X1F5 ? 1 : 0;
    // 0x00245B90: beq         $a1, $zero, L_00245BB8
    if (ctx->r5 == 0) {
        // 0x00245B94: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_00245BB8;
    }
    // 0x00245B94: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x00245B98: j           L_00245BB8
    // 0x00245B9C: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
        goto L_00245BB8;
    // 0x00245B9C: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
L_00245BA0:
    // 0x00245BA0: bne         $s2, $s3, L_00245BB8
    if (ctx->r18 != ctx->r19) {
        // 0x00245BA4: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_00245BB8;
    }
    // 0x00245BA4: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x00245BA8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_00245BAC:
    // 0x00245BAC: bne         $s3, $v1, L_00245BB8
    if (ctx->r19 != ctx->r3) {
        // 0x00245BB0: addu        $v0, $s3, $zero
        ctx->r2 = ADD32(ctx->r19, 0);
            goto L_00245BB8;
    }
    // 0x00245BB0: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x00245BB4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00245BB8:
    // 0x00245BB8: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x00245BBC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x00245BC0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x00245BC4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x00245BC8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00245BCC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00245BD0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00245BD4: jr          $ra
    // 0x00245BD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x00245BD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_00245BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00245BDC: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x00245BE0: sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // 0x00245BE4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00245BE8: sw          $ra, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r31;
    // 0x00245BEC: sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // 0x00245BF0: sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // 0x00245BF4: sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // 0x00245BF8: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x00245BFC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x00245C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00245C04: beq         $a0, $v0, L_00245C18
    if (ctx->r4 == ctx->r2) {
        // 0x00245C08: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_00245C18;
    }
    // 0x00245C08: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00245C0C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00245C10: bne         $a0, $v0, L_00245C20
    if (ctx->r4 != ctx->r2) {
        // 0x00245C14: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00245C20;
    }
    // 0x00245C14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_00245C18:
    // 0x00245C18: addiu       $s3, $v1, 0x14
    ctx->r19 = ADD32(ctx->r3, 0X14);
    // 0x00245C1C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_00245C20:
    // 0x00245C20: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00245C24: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00245C28: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x00245C2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00245C30: jal         0x00241C14
    // 0x00245C34: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x00245C34: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x00245C38: lbu         $v0, 0x174($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X174);
    // 0x00245C3C: addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // 0x00245C40: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00245C44: beq         $v0, $zero, L_00245CC0
    if (ctx->r2 == 0) {
        // 0x00245C48: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_00245CC0;
    }
    // 0x00245C48: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x00245C4C: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x00245C50: bne         $v1, $v0, L_00245CC0
    if (ctx->r3 != ctx->r2) {
        // 0x00245C54: addiu       $a0, $sp, 0xA0
        ctx->r4 = ADD32(ctx->r29, 0XA0);
            goto L_00245CC0;
    }
    // 0x00245C54: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x00245C58: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x00245C5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245C60: lwc1        $f1, -0x7484($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7484);
    // 0x00245C64: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00245C68: jal         0x00215038
    // 0x00245C6C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    func_00215038(rdram, ctx);
        goto after_1;
    // 0x00245C6C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x00245C70: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00245C74: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00245C78: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245C7C: lwc1        $f1, -0x7480($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7480);
    // 0x00245C80: bne         $v1, $v0, L_00245C90
    if (ctx->r3 != ctx->r2) {
        // 0x00245C84: nop
    
            goto L_00245C90;
    }
    // 0x00245C84: nop

    // 0x00245C88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245C8C: lwc1        $f1, -0x747C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X747C);
L_00245C90:
    // 0x00245C90: lbu         $v0, 0x32($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X32);
    // 0x00245C94: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00245C98: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00245C9C: beq         $v0, $zero, L_00245CB0
    if (ctx->r2 == 0) {
        // 0x00245CA0: nop
    
            goto L_00245CB0;
    }
    // 0x00245CA0: nop

    // 0x00245CA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245CA8: lwc1        $f0, -0x7478($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7478);
    // 0x00245CAC: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
L_00245CB0:
    // 0x00245CB0: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x00245CB4: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x00245CB8: j           L_00245D30
    // 0x00245CBC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_00245D30;
    // 0x00245CBC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_00245CC0:
    // 0x00245CC0: lb          $v1, 0x174($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X174);
    // 0x00245CC4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00245CC8: beq         $v1, $v0, L_00245D38
    if (ctx->r3 == ctx->r2) {
        // 0x00245CCC: addiu       $v0, $zero, 0x3FA
        ctx->r2 = ADD32(0, 0X3FA);
            goto L_00245D38;
    }
    // 0x00245CCC: addiu       $v0, $zero, 0x3FA
    ctx->r2 = ADD32(0, 0X3FA);
    // 0x00245CD0: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00245CD4: bne         $v1, $v0, L_00245CF0
    if (ctx->r3 != ctx->r2) {
        // 0x00245CD8: addiu       $v0, $zero, 0x3F1
        ctx->r2 = ADD32(0, 0X3F1);
            goto L_00245CF0;
    }
    // 0x00245CD8: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00245CDC: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x00245CE0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x00245CE4: beq         $v1, $v0, L_00245D38
    if (ctx->r3 == ctx->r2) {
        // 0x00245CE8: addiu       $v0, $zero, 0x3F1
        ctx->r2 = ADD32(0, 0X3F1);
            goto L_00245D38;
    }
    // 0x00245CE8: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00245CEC: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
L_00245CF0:
    // 0x00245CF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245CF4: lwc1        $f1, -0x7474($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7474);
    // 0x00245CF8: bne         $v1, $v0, L_00245D08
    if (ctx->r3 != ctx->r2) {
        // 0x00245CFC: nop
    
            goto L_00245D08;
    }
    // 0x00245CFC: nop

    // 0x00245D00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245D04: lwc1        $f1, -0x7470($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7470);
L_00245D08:
    // 0x00245D08: lbu         $v0, 0x32($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X32);
    // 0x00245D0C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00245D10: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00245D14: beq         $v0, $zero, L_00245D28
    if (ctx->r2 == 0) {
        // 0x00245D18: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00245D28;
    }
    // 0x00245D18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00245D1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245D20: lwc1        $f0, -0x746C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X746C);
    // 0x00245D24: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
L_00245D28:
    // 0x00245D28: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x00245D2C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_00245D30:
    // 0x00245D30: jal         0x0024197C
    // 0x00245D34: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0024197C(rdram, ctx);
        goto after_2;
    // 0x00245D34: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_00245D38:
    // 0x00245D38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00245D3C: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x00245D40: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00245D44: beq         $v0, $zero, L_00245DFC
    if (ctx->r2 == 0) {
        // 0x00245D48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00245DFC;
    }
    // 0x00245D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00245D4C: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x00245D50: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x00245D54: beq         $a0, $v0, L_00245D64
    if (ctx->r4 == ctx->r2) {
        // 0x00245D58: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00245D64;
    }
    // 0x00245D58: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00245D5C: bne         $a0, $v0, L_00245D68
    if (ctx->r4 != ctx->r2) {
        // 0x00245D60: nop
    
            goto L_00245D68;
    }
    // 0x00245D60: nop

L_00245D64:
    // 0x00245D64: addiu       $s2, $v1, 0x14
    ctx->r18 = ADD32(ctx->r3, 0X14);
L_00245D68:
    // 0x00245D68: lb          $v0, 0x174($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X174);
    // 0x00245D6C: beq         $v0, $zero, L_00245D84
    if (ctx->r2 == 0) {
        // 0x00245D70: nop
    
            goto L_00245D84;
    }
    // 0x00245D70: nop

    // 0x00245D74: lhu         $v0, 0x54($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X54);
    // 0x00245D78: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x00245D7C: bne         $v0, $zero, L_00245DC0
    if (ctx->r2 != 0) {
        // 0x00245D80: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00245DC0;
    }
    // 0x00245D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_00245D84:
    // 0x00245D84: lb          $v0, 0x175($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X175);
    // 0x00245D88: beq         $v0, $zero, L_00245DA0
    if (ctx->r2 == 0) {
        // 0x00245D8C: nop
    
            goto L_00245DA0;
    }
    // 0x00245D8C: nop

    // 0x00245D90: lhu         $v0, 0x54($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X54);
    // 0x00245D94: andi        $v0, $v0, 0x3E0
    ctx->r2 = ctx->r2 & 0X3E0;
    // 0x00245D98: bne         $v0, $zero, L_00245DC0
    if (ctx->r2 != 0) {
        // 0x00245D9C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00245DC0;
    }
    // 0x00245D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_00245DA0:
    // 0x00245DA0: lb          $v0, 0x176($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X176);
    // 0x00245DA4: beq         $v0, $zero, L_00245DC0
    if (ctx->r2 == 0) {
        // 0x00245DA8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_00245DC0;
    }
    // 0x00245DA8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x00245DAC: lhu         $v0, 0x54($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X54);
    // 0x00245DB0: andi        $v0, $v0, 0x7C00
    ctx->r2 = ctx->r2 & 0X7C00;
    // 0x00245DB4: bne         $v0, $zero, L_00245DC0
    if (ctx->r2 != 0) {
        // 0x00245DB8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00245DC0;
    }
    // 0x00245DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00245DBC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00245DC0:
    // 0x00245DC0: beq         $v0, $zero, L_00245DFC
    if (ctx->r2 == 0) {
        // 0x00245DC4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00245DFC;
    }
    // 0x00245DC4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00245DC8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00245DCC: jal         0x0023E684
    // 0x00245DD0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_0023E684(rdram, ctx);
        goto after_3;
    // 0x00245DD0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_3:
    // 0x00245DD4: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x00245DD8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00245DDC: lbu         $a0, 0x30($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X30);
    // 0x00245DE0: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x00245DE4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00245DE8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x00245DEC: sb          $a0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r4;
    // 0x00245DF0: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x00245DF4: j           L_00245F7C
    // 0x00245DF8: swc1        $f0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f0.u32l;
        goto L_00245F7C;
    // 0x00245DF8: swc1        $f0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f0.u32l;
L_00245DFC:
    // 0x00245DFC: lhu         $v0, 0xB0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XB0);
    // 0x00245E00: addiu       $v0, $v0, -0x1194
    ctx->r2 = ADD32(ctx->r2, -0X1194);
    // 0x00245E04: sltiu       $v0, $v0, 0x37
    ctx->r2 = ctx->r2 < 0X37 ? 1 : 0;
    // 0x00245E08: beq         $v0, $zero, L_00245E94
    if (ctx->r2 == 0) {
        // 0x00245E0C: addiu       $v0, $zero, 0x7D3
        ctx->r2 = ADD32(0, 0X7D3);
            goto L_00245E94;
    }
    // 0x00245E0C: addiu       $v0, $zero, 0x7D3
    ctx->r2 = ADD32(0, 0X7D3);
    // 0x00245E10: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00245E14: bne         $v1, $v0, L_00245E44
    if (ctx->r3 != ctx->r2) {
        // 0x00245E18: nop
    
            goto L_00245E44;
    }
    // 0x00245E18: nop

    // 0x00245E1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245E20: lwc1        $f12, -0x7468($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7468);
    // 0x00245E24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245E28: lwc1        $f14, -0x7464($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7464);
    // 0x00245E2C: jal         0x00215A90
    // 0x00245E30: nop

    func_00215A90(rdram, ctx);
        goto after_4;
    // 0x00245E30: nop

    after_4:
    // 0x00245E34: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x00245E38: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x00245E3C: j           L_00245E7C
    // 0x00245E40: nop

        goto L_00245E7C;
    // 0x00245E40: nop

L_00245E44:
    // 0x00245E44: lbu         $v0, 0xB4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB4);
    // 0x00245E48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245E4C: lwc1        $f0, -0x7460($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7460);
    // 0x00245E50: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x00245E54: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00245E58: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00245E5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245E60: lwc1        $f0, -0x745C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X745C);
    // 0x00245E64: mul.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00245E68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245E6C: lwc1        $f1, -0x7458($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7458);
    // 0x00245E70: add.s       $f1, $f0, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00245E74: trunc.w.s   $f2, $f1
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 1);
    ctx->f2.u32l = TRUNC_W_S(ctx->f1.fl);
    // 0x00245E78: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
L_00245E7C:
    // 0x00245E7C: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x00245E80: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x00245E84: bne         $v0, $zero, L_00245F80
    if (ctx->r2 != 0) {
        // 0x00245E88: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00245F80;
    }
    // 0x00245E88: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00245E8C: j           L_00245F70
    // 0x00245E90: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
        goto L_00245F70;
    // 0x00245E90: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_00245E94:
    // 0x00245E94: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x00245E98: beq         $v0, $zero, L_00245F7C
    if (ctx->r2 == 0) {
        // 0x00245E9C: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00245F7C;
    }
    // 0x00245E9C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00245EA0: lb          $v1, 0x174($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X174);
    // 0x00245EA4: bne         $v1, $v0, L_00245EC8
    if (ctx->r3 != ctx->r2) {
        // 0x00245EA8: nop
    
            goto L_00245EC8;
    }
    // 0x00245EA8: nop

    // 0x00245EAC: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x00245EB0: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x00245EB4: beq         $v0, $zero, L_00245EC8
    if (ctx->r2 == 0) {
        // 0x00245EB8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00245EC8;
    }
    // 0x00245EB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00245EBC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00245EC0: j           L_00245F74
    // 0x00245EC4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
        goto L_00245F74;
    // 0x00245EC4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
L_00245EC8:
    // 0x00245EC8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x00245ECC: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x00245ED0: beq         $v0, $zero, L_00245F0C
    if (ctx->r2 == 0) {
        // 0x00245ED4: lui         $v1, 0xF7FF
        ctx->r3 = S32(0XF7FF << 16);
            goto L_00245F0C;
    }
    // 0x00245ED4: lui         $v1, 0xF7FF
    ctx->r3 = S32(0XF7FF << 16);
    // 0x00245ED8: lwc1        $f1, 0x3C($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X3C);
    // 0x00245EDC: lwc1        $f0, 0x3C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x00245EE0: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00245EE4: nop

    // 0x00245EE8: bc1f        L_00245F0C
    if (!c1cs) {
        // 0x00245EEC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00245F0C;
    }
    // 0x00245EEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00245EF0: lb          $v1, 0x174($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X174);
    // 0x00245EF4: beq         $v1, $v0, L_00245F08
    if (ctx->r3 == ctx->r2) {
        // 0x00245EF8: lui         $v1, 0x800
        ctx->r3 = S32(0X800 << 16);
            goto L_00245F08;
    }
    // 0x00245EF8: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x00245EFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00245F00: j           L_00245F18
    // 0x00245F04: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_00245F18;
    // 0x00245F04: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_00245F08:
    // 0x00245F08: lui         $v1, 0xF7FF
    ctx->r3 = S32(0XF7FF << 16);
L_00245F0C:
    // 0x00245F0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00245F10: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00245F14: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_00245F18:
    // 0x00245F18: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x00245F1C: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00245F20: addiu       $v0, $zero, 0x7D4
    ctx->r2 = ADD32(0, 0X7D4);
    // 0x00245F24: bne         $v1, $v0, L_00245F3C
    if (ctx->r3 != ctx->r2) {
        // 0x00245F28: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00245F3C;
    }
    // 0x00245F28: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00245F2C: jal         0x0028B288
    // 0x00245F30: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0028B288(rdram, ctx);
        goto after_5;
    // 0x00245F30: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x00245F34: j           L_00245F80
    // 0x00245F38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_00245F80;
    // 0x00245F38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_00245F3C:
    // 0x00245F3C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x00245F40: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x00245F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00245F48: bne         $v1, $v0, L_00245F64
    if (ctx->r3 != ctx->r2) {
        // 0x00245F4C: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00245F64;
    }
    // 0x00245F4C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00245F50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00245F54: jal         0x00245510
    // 0x00245F58: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00245510(rdram, ctx);
        goto after_6;
    // 0x00245F58: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // 0x00245F5C: j           L_00245F80
    // 0x00245F60: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_00245F80;
    // 0x00245F60: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_00245F64:
    // 0x00245F64: bne         $v1, $v0, L_00245F80
    if (ctx->r3 != ctx->r2) {
        // 0x00245F68: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00245F80;
    }
    // 0x00245F68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00245F6C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_00245F70:
    // 0x00245F70: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_00245F74:
    // 0x00245F74: jal         0x0023E684
    // 0x00245F78: nop

    func_0023E684(rdram, ctx);
        goto after_7;
    // 0x00245F78: nop

    after_7:
L_00245F7C:
    // 0x00245F7C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_00245F80:
    // 0x00245F80: jal         0x002453A4
    // 0x00245F84: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_002453A4(rdram, ctx);
        goto after_8;
    // 0x00245F84: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_8:
    // 0x00245F88: lw          $ra, 0xB8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XB8);
    // 0x00245F8C: lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XB4);
    // 0x00245F90: lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB0);
    // 0x00245F94: lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XAC);
    // 0x00245F98: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x00245F9C: jr          $ra
    // 0x00245FA0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x00245FA0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_00245FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00245FA4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x00245FA8: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x00245FAC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00245FB0: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x00245FB4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00245FB8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00245FBC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x00245FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00245FC4: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x00245FC8: jal         0x00241C14
    // 0x00245FCC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x00245FCC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x00245FD0: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00245FD4: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00245FD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245FDC: lwc1        $f1, -0x7454($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7454);
    // 0x00245FE0: bne         $v1, $v0, L_00245FF0
    if (ctx->r3 != ctx->r2) {
        // 0x00245FE4: nop
    
            goto L_00245FF0;
    }
    // 0x00245FE4: nop

    // 0x00245FE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00245FEC: lwc1        $f1, -0x7450($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7450);
L_00245FF0:
    // 0x00245FF0: lbu         $v0, 0x32($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X32);
    // 0x00245FF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00245FF8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00245FFC: beql        $v0, $zero, L_00246014
    if (ctx->r2 == 0) {
        // 0x00246000: add.s       $f1, $f1, $f1
        CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f1.fl;
            goto L_00246014;
    }
    goto skip_0;
    // 0x00246000: add.s       $f1, $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f1.fl;
    skip_0:
    // 0x00246004: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246008: lwc1        $f0, -0x744C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X744C);
    // 0x0024600C: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00246010: add.s       $f1, $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f1.fl;
L_00246014:
    // 0x00246014: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00246018: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x0024601C: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x00246020: jal         0x0024197C
    // 0x00246024: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0024197C(rdram, ctx);
        goto after_1;
    // 0x00246024: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x00246028: lhu         $v0, 0xB0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XB0);
    // 0x0024602C: addiu       $v0, $v0, -0x1130
    ctx->r2 = ADD32(ctx->r2, -0X1130);
    // 0x00246030: sltiu       $v0, $v0, 0x9B
    ctx->r2 = ctx->r2 < 0X9B ? 1 : 0;
    // 0x00246034: beq         $v0, $zero, L_00246048
    if (ctx->r2 == 0) {
        // 0x00246038: lui         $v1, 0x80
        ctx->r3 = S32(0X80 << 16);
            goto L_00246048;
    }
    // 0x00246038: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x0024603C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00246040: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00246044: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_00246048:
    // 0x00246048: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x0024604C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246050: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00246054: sub.s       $f1, $f0, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00246058: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x0024605C: beq         $v0, $zero, L_002460D0
    if (ctx->r2 == 0) {
        // 0x00246060: swc1        $f1, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
            goto L_002460D0;
    }
    // 0x00246060: swc1        $f1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
    // 0x00246064: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x00246068: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // 0x0024606C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00246070: bne         $v0, $zero, L_00246084
    if (ctx->r2 != 0) {
        // 0x00246074: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00246084;
    }
    // 0x00246074: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00246078: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024607C: j           L_0024609C
    // 0x00246080: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
        goto L_0024609C;
    // 0x00246080: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_00246084:
    // 0x00246084: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00246088: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x0024608C: nop

    // 0x00246090: bc1f        L_002460B8
    if (!c1cs) {
        // 0x00246094: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_002460B8;
    }
    // 0x00246094: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00246098: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
L_0024609C:
    // 0x0024609C: jal         0x0023E684
    // 0x002460A0: nop

    func_0023E684(rdram, ctx);
        goto after_2;
    // 0x002460A0: nop

    after_2:
    // 0x002460A4: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x002460A8: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x002460AC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x002460B0: j           L_002460D0
    // 0x002460B4: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
        goto L_002460D0;
    // 0x002460B4: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
L_002460B8:
    // 0x002460B8: lui         $v0, 0xFF7F
    ctx->r2 = S32(0XFF7F << 16);
    // 0x002460BC: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x002460C0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x002460C4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x002460C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x002460CC: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
L_002460D0:
    // 0x002460D0: lwc1        $f1, 0x60($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X60);
    // 0x002460D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002460D8: lwc1        $f0, -0x7448($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7448);
    // 0x002460DC: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x002460E0: nop

    // 0x002460E4: bc1f        L_002460F4
    if (!c1cs) {
        // 0x002460E8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002460F4;
    }
    // 0x002460E8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002460EC: jal         0x002453A4
    // 0x002460F0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_002453A4(rdram, ctx);
        goto after_3;
    // 0x002460F0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
L_002460F4:
    // 0x002460F4: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x002460F8: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x002460FC: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x00246100: jr          $ra
    // 0x00246104: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x00246104: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_00246108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246108: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x0024610C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x00246110: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x00246114: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x00246118: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x0024611C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00246120: lui         $a0, 0xFF87
    ctx->r4 = S32(0XFF87 << 16);
    // 0x00246124: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x00246128: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x0024612C: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x00246130: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x00246134: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00246138: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024613C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x00246140: lui         $v0, 0x78
    ctx->r2 = S32(0X78 << 16);
    // 0x00246144: and         $s5, $v1, $v0
    ctx->r21 = ctx->r3 & ctx->r2;
    // 0x00246148: and         $s6, $v1, $a0
    ctx->r22 = ctx->r3 & ctx->r4;
    // 0x0024614C: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
    // 0x00246150: lb          $s2, 0x177($s4)
    ctx->r18 = MEM_B(ctx->r20, 0X177);
    // 0x00246154: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x00246158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024615C: beq         $a0, $v0, L_00246170
    if (ctx->r4 == ctx->r2) {
        // 0x00246160: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_00246170;
    }
    // 0x00246160: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x00246164: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246168: bne         $a0, $v0, L_002463C4
    if (ctx->r4 != ctx->r2) {
        // 0x0024616C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_002463C4;
    }
    // 0x0024616C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00246170:
    // 0x00246170: lui         $v0, 0x60
    ctx->r2 = S32(0X60 << 16);
    // 0x00246174: and         $v0, $s5, $v0
    ctx->r2 = ctx->r21 & ctx->r2;
    // 0x00246178: beq         $v0, $zero, L_00246218
    if (ctx->r2 == 0) {
        // 0x0024617C: addiu       $s1, $v1, 0x14
        ctx->r17 = ADD32(ctx->r3, 0X14);
            goto L_00246218;
    }
    // 0x0024617C: addiu       $s1, $v1, 0x14
    ctx->r17 = ADD32(ctx->r3, 0X14);
    // 0x00246180: bne         $s2, $zero, L_002461AC
    if (ctx->r18 != 0) {
        // 0x00246184: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_002461AC;
    }
    // 0x00246184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246188: lhu         $v0, 0x5C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5C);
    // 0x0024618C: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x00246190: beq         $v0, $zero, L_002461A8
    if (ctx->r2 == 0) {
        // 0x00246194: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_002461A8;
    }
    // 0x00246194: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00246198: jal         0x002435A8
    // 0x0024619C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_002435A8(rdram, ctx);
        goto after_0;
    // 0x0024619C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_0:
    // 0x002461A0: j           L_002461FC
    // 0x002461A4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002461FC;
    // 0x002461A4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_002461A8:
    // 0x002461A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_002461AC:
    // 0x002461AC: bne         $s2, $v0, L_002461D8
    if (ctx->r18 != ctx->r2) {
        // 0x002461B0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_002461D8;
    }
    // 0x002461B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x002461B4: lhu         $v0, 0x5C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5C);
    // 0x002461B8: andi        $v0, $v0, 0x3E0
    ctx->r2 = ctx->r2 & 0X3E0;
    // 0x002461BC: beq         $v0, $zero, L_002461D4
    if (ctx->r2 == 0) {
        // 0x002461C0: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_002461D4;
    }
    // 0x002461C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x002461C4: jal         0x002435F0
    // 0x002461C8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_002435F0(rdram, ctx);
        goto after_1;
    // 0x002461C8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_1:
    // 0x002461CC: j           L_002461FC
    // 0x002461D0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002461FC;
    // 0x002461D0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_002461D4:
    // 0x002461D4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_002461D8:
    // 0x002461D8: bne         $s2, $v0, L_00246200
    if (ctx->r18 != ctx->r2) {
        // 0x002461DC: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00246200;
    }
    // 0x002461DC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x002461E0: lhu         $v0, 0x5C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5C);
    // 0x002461E4: andi        $v0, $v0, 0x7C00
    ctx->r2 = ctx->r2 & 0X7C00;
    // 0x002461E8: beq         $v0, $zero, L_00246204
    if (ctx->r2 == 0) {
        // 0x002461EC: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_00246204;
    }
    // 0x002461EC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x002461F0: jal         0x00243638
    // 0x002461F4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_00243638(rdram, ctx);
        goto after_2;
    // 0x002461F4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_2:
    // 0x002461F8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_002461FC:
    // 0x002461FC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_00246200:
    // 0x00246200: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_00246204:
    // 0x00246204: jal         0x00216D3C
    // 0x00246208: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_00216D3C(rdram, ctx);
        goto after_3;
    // 0x00246208: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x0024620C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x00246210: beql        $v0, $v1, L_00246218
    if (ctx->r2 == ctx->r3) {
        // 0x00246214: lui         $s5, 0x10
        ctx->r21 = S32(0X10 << 16);
            goto L_00246218;
    }
    goto skip_0;
    // 0x00246214: lui         $s5, 0x10
    ctx->r21 = S32(0X10 << 16);
    skip_0:
L_00246218:
    // 0x00246218: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x0024621C: and         $v0, $s5, $v0
    ctx->r2 = ctx->r21 & ctx->r2;
    // 0x00246220: beq         $v0, $zero, L_002462C4
    if (ctx->r2 == 0) {
        // 0x00246224: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_002462C4;
    }
    // 0x00246224: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00246228: bne         $s2, $zero, L_00246254
    if (ctx->r18 != 0) {
        // 0x0024622C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00246254;
    }
    // 0x0024622C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246230: lhu         $v0, 0x5A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5A);
    // 0x00246234: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x00246238: beq         $v0, $zero, L_00246250
    if (ctx->r2 == 0) {
        // 0x0024623C: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00246250;
    }
    // 0x0024623C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00246240: jal         0x002434D0
    // 0x00246244: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_002434D0(rdram, ctx);
        goto after_4;
    // 0x00246244: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_4:
    // 0x00246248: j           L_002462A4
    // 0x0024624C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002462A4;
    // 0x0024624C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_00246250:
    // 0x00246250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_00246254:
    // 0x00246254: bne         $s2, $v0, L_00246280
    if (ctx->r18 != ctx->r2) {
        // 0x00246258: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00246280;
    }
    // 0x00246258: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x0024625C: lhu         $v0, 0x5A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5A);
    // 0x00246260: andi        $v0, $v0, 0x3E0
    ctx->r2 = ctx->r2 & 0X3E0;
    // 0x00246264: beq         $v0, $zero, L_0024627C
    if (ctx->r2 == 0) {
        // 0x00246268: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0024627C;
    }
    // 0x00246268: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0024626C: jal         0x00243518
    // 0x00246270: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_00243518(rdram, ctx);
        goto after_5;
    // 0x00246270: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_5:
    // 0x00246274: j           L_002462A4
    // 0x00246278: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002462A4;
    // 0x00246278: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_0024627C:
    // 0x0024627C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_00246280:
    // 0x00246280: bne         $s2, $v0, L_002462A8
    if (ctx->r18 != ctx->r2) {
        // 0x00246284: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_002462A8;
    }
    // 0x00246284: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00246288: lhu         $v0, 0x5A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5A);
    // 0x0024628C: andi        $v0, $v0, 0x7C00
    ctx->r2 = ctx->r2 & 0X7C00;
    // 0x00246290: beq         $v0, $zero, L_002462AC
    if (ctx->r2 == 0) {
        // 0x00246294: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_002462AC;
    }
    // 0x00246294: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00246298: jal         0x00243560
    // 0x0024629C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_00243560(rdram, ctx);
        goto after_6;
    // 0x0024629C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_6:
    // 0x002462A0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_002462A4:
    // 0x002462A4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_002462A8:
    // 0x002462A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_002462AC:
    // 0x002462AC: jal         0x00216D3C
    // 0x002462B0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_00216D3C(rdram, ctx);
        goto after_7;
    // 0x002462B0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_7:
    // 0x002462B4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x002462B8: beql        $v0, $v1, L_002462C0
    if (ctx->r2 == ctx->r3) {
        // 0x002462BC: lui         $s5, 0x8
        ctx->r21 = S32(0X8 << 16);
            goto L_002462C0;
    }
    goto skip_1;
    // 0x002462BC: lui         $s5, 0x8
    ctx->r21 = S32(0X8 << 16);
    skip_1:
L_002462C0:
    // 0x002462C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_002462C4:
    // 0x002462C4: bne         $s0, $v0, L_002463BC
    if (ctx->r16 != ctx->r2) {
        // 0x002462C8: or          $v0, $s6, $s5
        ctx->r2 = ctx->r22 | ctx->r21;
            goto L_002463BC;
    }
    // 0x002462C8: or          $v0, $s6, $s5
    ctx->r2 = ctx->r22 | ctx->r21;
    // 0x002462CC: bne         $s2, $zero, L_0024631C
    if (ctx->r18 != 0) {
        // 0x002462D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_0024631C;
    }
    // 0x002462D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002462D4: lhu         $v0, 0x58($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X58);
    // 0x002462D8: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x002462DC: beq         $v0, $zero, L_0024630C
    if (ctx->r2 == 0) {
        // 0x002462E0: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0024630C;
    }
    // 0x002462E0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x002462E4: lh          $v1, 0xB0($s4)
    ctx->r3 = MEM_H(ctx->r20, 0XB0);
    // 0x002462E8: slti        $v0, $v1, 0x7D0
    ctx->r2 = SIGNED(ctx->r3) < 0X7D0 ? 1 : 0;
    // 0x002462EC: bne         $v0, $zero, L_0024630C
    if (ctx->r2 != 0) {
        // 0x002462F0: slti        $v0, $v1, 0x7E9
        ctx->r2 = SIGNED(ctx->r3) < 0X7E9 ? 1 : 0;
            goto L_0024630C;
    }
    // 0x002462F0: slti        $v0, $v1, 0x7E9
    ctx->r2 = SIGNED(ctx->r3) < 0X7E9 ? 1 : 0;
    // 0x002462F4: beq         $v0, $zero, L_0024630C
    if (ctx->r2 == 0) {
        // 0x002462F8: nop
    
            goto L_0024630C;
    }
    // 0x002462F8: nop

    // 0x002462FC: jal         0x002433F8
    // 0x00246300: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_002433F8(rdram, ctx);
        goto after_8;
    // 0x00246300: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_8:
    // 0x00246304: j           L_002463B8
    // 0x00246308: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002463B8;
    // 0x00246308: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_0024630C:
    // 0x0024630C: jal         0x00243320
    // 0x00246310: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_00243320(rdram, ctx);
        goto after_9;
    // 0x00246310: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_9:
    // 0x00246314: j           L_002463B8
    // 0x00246318: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002463B8;
    // 0x00246318: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_0024631C:
    // 0x0024631C: bne         $s2, $v0, L_0024636C
    if (ctx->r18 != ctx->r2) {
        // 0x00246320: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_0024636C;
    }
    // 0x00246320: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00246324: lhu         $v0, 0x58($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X58);
    // 0x00246328: andi        $v0, $v0, 0x3E0
    ctx->r2 = ctx->r2 & 0X3E0;
    // 0x0024632C: beq         $v0, $zero, L_0024635C
    if (ctx->r2 == 0) {
        // 0x00246330: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0024635C;
    }
    // 0x00246330: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00246334: lh          $v1, 0xB0($s4)
    ctx->r3 = MEM_H(ctx->r20, 0XB0);
    // 0x00246338: slti        $v0, $v1, 0x834
    ctx->r2 = SIGNED(ctx->r3) < 0X834 ? 1 : 0;
    // 0x0024633C: bne         $v0, $zero, L_0024635C
    if (ctx->r2 != 0) {
        // 0x00246340: slti        $v0, $v1, 0x84D
        ctx->r2 = SIGNED(ctx->r3) < 0X84D ? 1 : 0;
            goto L_0024635C;
    }
    // 0x00246340: slti        $v0, $v1, 0x84D
    ctx->r2 = SIGNED(ctx->r3) < 0X84D ? 1 : 0;
    // 0x00246344: beq         $v0, $zero, L_0024635C
    if (ctx->r2 == 0) {
        // 0x00246348: nop
    
            goto L_0024635C;
    }
    // 0x00246348: nop

    // 0x0024634C: jal         0x00243440
    // 0x00246350: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_00243440(rdram, ctx);
        goto after_10;
    // 0x00246350: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_10:
    // 0x00246354: j           L_002463B8
    // 0x00246358: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002463B8;
    // 0x00246358: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_0024635C:
    // 0x0024635C: jal         0x00243368
    // 0x00246360: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_00243368(rdram, ctx);
        goto after_11;
    // 0x00246360: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_11:
    // 0x00246364: j           L_002463B8
    // 0x00246368: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002463B8;
    // 0x00246368: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_0024636C:
    // 0x0024636C: bne         $s2, $v0, L_002463BC
    if (ctx->r18 != ctx->r2) {
        // 0x00246370: or          $v0, $s6, $s5
        ctx->r2 = ctx->r22 | ctx->r21;
            goto L_002463BC;
    }
    // 0x00246370: or          $v0, $s6, $s5
    ctx->r2 = ctx->r22 | ctx->r21;
    // 0x00246374: lhu         $v0, 0x58($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X58);
    // 0x00246378: andi        $v0, $v0, 0x7C00
    ctx->r2 = ctx->r2 & 0X7C00;
    // 0x0024637C: beq         $v0, $zero, L_002463AC
    if (ctx->r2 == 0) {
        // 0x00246380: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_002463AC;
    }
    // 0x00246380: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00246384: lh          $v1, 0xB0($s4)
    ctx->r3 = MEM_H(ctx->r20, 0XB0);
    // 0x00246388: slti        $v0, $v1, 0x898
    ctx->r2 = SIGNED(ctx->r3) < 0X898 ? 1 : 0;
    // 0x0024638C: bne         $v0, $zero, L_002463AC
    if (ctx->r2 != 0) {
        // 0x00246390: slti        $v0, $v1, 0x8B1
        ctx->r2 = SIGNED(ctx->r3) < 0X8B1 ? 1 : 0;
            goto L_002463AC;
    }
    // 0x00246390: slti        $v0, $v1, 0x8B1
    ctx->r2 = SIGNED(ctx->r3) < 0X8B1 ? 1 : 0;
    // 0x00246394: beq         $v0, $zero, L_002463AC
    if (ctx->r2 == 0) {
        // 0x00246398: nop
    
            goto L_002463AC;
    }
    // 0x00246398: nop

    // 0x0024639C: jal         0x00243488
    // 0x002463A0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_00243488(rdram, ctx);
        goto after_12;
    // 0x002463A0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_12:
    // 0x002463A4: j           L_002463B8
    // 0x002463A8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_002463B8;
    // 0x002463A8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_002463AC:
    // 0x002463AC: jal         0x002433B0
    // 0x002463B0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_002433B0(rdram, ctx);
        goto after_13;
    // 0x002463B0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_13:
    // 0x002463B4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_002463B8:
    // 0x002463B8: or          $v0, $s6, $s5
    ctx->r2 = ctx->r22 | ctx->r21;
L_002463BC:
    // 0x002463BC: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x002463C0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_002463C4:
    // 0x002463C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x002463C8: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x002463CC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x002463D0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x002463D4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x002463D8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x002463DC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x002463E0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002463E4: jr          $ra
    // 0x002463E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x002463E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_002463EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002463EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x002463F0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002463F4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x002463F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002463FC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00246400: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00246404: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x00246408: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024640C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x00246410: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
    // 0x00246414: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x00246418: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x0024641C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00246420: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
    // 0x00246424: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x00246428: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024642C: beq         $a0, $v0, L_00246444
    if (ctx->r4 == ctx->r2) {
        // 0x00246430: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00246444;
    }
    // 0x00246430: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246434: beq         $a0, $v0, L_00246444
    if (ctx->r4 == ctx->r2) {
        // 0x00246438: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_00246444;
    }
    // 0x00246438: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x0024643C: bne         $a0, $v0, L_00246454
    if (ctx->r4 != ctx->r2) {
        // 0x00246440: nop
    
            goto L_00246454;
    }
    // 0x00246440: nop

L_00246444:
    // 0x00246444: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00246448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x0024644C: jal         0x0021B680
    // 0x00246450: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_0021B680(rdram, ctx);
        goto after_0;
    // 0x00246450: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
L_00246454:
    // 0x00246454: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x00246458: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024645C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00246460: jal         0x00203F6C
    // 0x00246464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_00203F6C(rdram, ctx);
        goto after_1;
    // 0x00246464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x00246468: lw          $v1, 0xF0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XF0);
    // 0x0024646C: beq         $v1, $zero, L_002464F8
    if (ctx->r3 == 0) {
        // 0x00246470: nop
    
            goto L_002464F8;
    }
    // 0x00246470: nop

    // 0x00246474: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x00246478: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x0024647C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246480: bne         $a0, $v0, L_002464C0
    if (ctx->r4 != ctx->r2) {
        // 0x00246484: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_002464C0;
    }
    // 0x00246484: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00246488: lbu         $a0, 0xFC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XFC);
    // 0x0024648C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00246490: bne         $a0, $v0, L_002464A8
    if (ctx->r4 != ctx->r2) {
        // 0x00246494: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_002464A8;
    }
    // 0x00246494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246498: lw          $v0, 0x2FC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2FC);
    // 0x0024649C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x002464A0: j           L_002464F8
    // 0x002464A4: sw          $v0, 0x2FC($v1)
    MEM_W(0X2FC, ctx->r3) = ctx->r2;
        goto L_002464F8;
    // 0x002464A4: sw          $v0, 0x2FC($v1)
    MEM_W(0X2FC, ctx->r3) = ctx->r2;
L_002464A8:
    // 0x002464A8: bne         $a0, $v0, L_002464F8
    if (ctx->r4 != ctx->r2) {
        // 0x002464AC: nop
    
            goto L_002464F8;
    }
    // 0x002464AC: nop

    // 0x002464B0: lw          $v0, 0x2F8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2F8);
    // 0x002464B4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x002464B8: j           L_002464F8
    // 0x002464BC: sw          $v0, 0x2F8($v1)
    MEM_W(0X2F8, ctx->r3) = ctx->r2;
        goto L_002464F8;
    // 0x002464BC: sw          $v0, 0x2F8($v1)
    MEM_W(0X2F8, ctx->r3) = ctx->r2;
L_002464C0:
    // 0x002464C0: bne         $a0, $v0, L_002464F8
    if (ctx->r4 != ctx->r2) {
        // 0x002464C4: nop
    
            goto L_002464F8;
    }
    // 0x002464C4: nop

    // 0x002464C8: lw          $v0, 0x2C4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C4);
    // 0x002464CC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x002464D0: sw          $v0, 0x2C4($v1)
    MEM_W(0X2C4, ctx->r3) = ctx->r2;
    // 0x002464D4: lw          $a0, 0xF0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF0);
    // 0x002464D8: lw          $v0, 0x2C0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C0);
    // 0x002464DC: bgtz        $v0, L_002464F8
    if (SIGNED(ctx->r2) > 0) {
        // 0x002464E0: nop
    
            goto L_002464F8;
    }
    // 0x002464E0: nop

    // 0x002464E4: lw          $v0, 0x2C4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C4);
    // 0x002464E8: bgtz        $v0, L_002464F8
    if (SIGNED(ctx->r2) > 0) {
        // 0x002464EC: lui         $a1, 0x40
        ctx->r5 = S32(0X40 << 16);
            goto L_002464F8;
    }
    // 0x002464EC: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x002464F0: jal         0x0021B680
    // 0x002464F4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    func_0021B680(rdram, ctx);
        goto after_2;
    // 0x002464F4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_2:
L_002464F8:
    // 0x002464F8: lw          $a1, 0x100($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X100);
    // 0x002464FC: beq         $a1, $zero, L_00246510
    if (ctx->r5 == 0) {
        // 0x00246500: nop
    
            goto L_00246510;
    }
    // 0x00246500: nop

    // 0x00246504: jal         0x002217F0
    // 0x00246508: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_3;
    // 0x00246508: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x0024650C: sw          $zero, 0x100($s0)
    MEM_W(0X100, ctx->r16) = 0;
L_00246510:
    // 0x00246510: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00246514: addiu       $v0, $zero, 0x7D4
    ctx->r2 = ADD32(0, 0X7D4);
    // 0x00246518: bne         $v1, $v0, L_00246524
    if (ctx->r3 != ctx->r2) {
        // 0x0024651C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_00246524;
    }
    // 0x0024651C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00246520: sw          $v0, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->r2;
L_00246524:
    // 0x00246524: lw          $v0, 0x108($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X108);
    // 0x00246528: beq         $v0, $zero, L_00246548
    if (ctx->r2 == 0) {
        // 0x0024652C: nop
    
            goto L_00246548;
    }
    // 0x0024652C: nop

    // 0x00246530: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x00246534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246538: bne         $v1, $v0, L_00246548
    if (ctx->r3 != ctx->r2) {
        // 0x0024653C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00246548;
    }
    // 0x0024653C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00246540: jal         0x002365EC
    // 0x00246544: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_002365EC(rdram, ctx);
        goto after_4;
    // 0x00246544: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
L_00246548:
    // 0x00246548: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x0024654C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00246550: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00246554: jr          $ra
    // 0x00246558: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00246558: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_0024655C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024655C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x00246560: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00246564: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00246568: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024656C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00246570: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x00246574: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x00246578: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x0024657C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246580: bne         $a0, $v0, L_00246590
    if (ctx->r4 != ctx->r2) {
        // 0x00246584: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00246590;
    }
    // 0x00246584: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246588: j           L_00246598
    // 0x0024658C: addiu       $s1, $v1, 0x14
    ctx->r17 = ADD32(ctx->r3, 0X14);
        goto L_00246598;
    // 0x0024658C: addiu       $s1, $v1, 0x14
    ctx->r17 = ADD32(ctx->r3, 0X14);
L_00246590:
    // 0x00246590: beql        $a0, $v0, L_00246598
    if (ctx->r4 == ctx->r2) {
        // 0x00246594: addiu       $s1, $v1, 0x14
        ctx->r17 = ADD32(ctx->r3, 0X14);
            goto L_00246598;
    }
    goto skip_0;
    // 0x00246594: addiu       $s1, $v1, 0x14
    ctx->r17 = ADD32(ctx->r3, 0X14);
    skip_0:
L_00246598:
    // 0x00246598: sw          $zero, 0xBC($a1)
    MEM_W(0XBC, ctx->r5) = 0;
    // 0x0024659C: lhu         $v0, 0x330($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X330);
    // 0x002465A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x002465A4: andi        $v0, $v0, 0xFFFD
    ctx->r2 = ctx->r2 & 0XFFFD;
    // 0x002465A8: jal         0x00242140
    // 0x002465AC: sh          $v0, 0x330($s0)
    MEM_H(0X330, ctx->r16) = ctx->r2;
    func_00242140(rdram, ctx);
        goto after_0;
    // 0x002465AC: sh          $v0, 0x330($s0)
    MEM_H(0X330, ctx->r16) = ctx->r2;
    after_0:
    // 0x002465B0: lwc1        $f3, 0x1A4($s0)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r16, 0X1A4);
    // 0x002465B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002465B8: lwc1        $f0, -0x7444($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7444);
    // 0x002465BC: c.lt.s      $f0, $f3
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 3);
    c1cs = ctx->f0.fl < ctx->f3.fl;
    // 0x002465C0: nop

    // 0x002465C4: bc1f        L_0024671C
    if (!c1cs) {
        // 0x002465C8: lui         $a0, 0xFFEF
        ctx->r4 = S32(0XFFEF << 16);
            goto L_0024671C;
    }
    // 0x002465C8: lui         $a0, 0xFFEF
    ctx->r4 = S32(0XFFEF << 16);
    // 0x002465CC: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x002465D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002465D4: lwc1        $f20, -0x7440($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7440);
    // 0x002465D8: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x002465DC: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x002465E0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x002465E4: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
    // 0x002465E8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x002465EC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002465F0: bne         $v1, $v0, L_002466C4
    if (ctx->r3 != ctx->r2) {
        // 0x002465F4: addiu       $v0, $zero, 0x1F4
        ctx->r2 = ADD32(0, 0X1F4);
            goto L_002466C4;
    }
    // 0x002465F4: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
    // 0x002465F8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x002465FC: lw          $v1, 0x42FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X42FC);
    // 0x00246600: bne         $v1, $v0, L_002466C4
    if (ctx->r3 != ctx->r2) {
        // 0x00246604: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_002466C4;
    }
    // 0x00246604: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00246608: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x0024660C: lw          $a1, 0x3908($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3908);
    // 0x00246610: blez        $a1, L_00246664
    if (SIGNED(ctx->r5) <= 0) {
        // 0x00246614: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_00246664;
    }
    // 0x00246614: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x00246618: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x0024661C: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x00246620: addiu       $a3, $zero, 0x2F
    ctx->r7 = ADD32(0, 0X2F);
    // 0x00246624: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
L_00246628:
    // 0x00246628: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0024662C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x00246630: lw          $v1, 0x3708($at)
    ctx->r3 = MEM_W(ctx->r1, 0X3708);
    // 0x00246634: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x00246638: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x0024663C: bne         $v0, $t1, L_00246658
    if (ctx->r2 != ctx->r9) {
        // 0x00246640: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00246658;
    }
    // 0x00246640: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00246644: lb          $v0, 0x198($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X198);
    // 0x00246648: beq         $v0, $t0, L_00246658
    if (ctx->r2 == ctx->r8) {
        // 0x0024664C: nop
    
            goto L_00246658;
    }
    // 0x0024664C: nop

    // 0x00246650: bnel        $v0, $a3, L_00246664
    if (ctx->r2 != ctx->r7) {
        // 0x00246654: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_00246664;
    }
    goto skip_1;
    // 0x00246654: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_1:
L_00246658:
    // 0x00246658: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x0024665C: bne         $v0, $zero, L_00246628
    if (ctx->r2 != 0) {
        // 0x00246660: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_00246628;
    }
    // 0x00246660: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
L_00246664:
    // 0x00246664: bne         $a2, $zero, L_002466C4
    if (ctx->r6 != 0) {
        // 0x00246668: nop
    
            goto L_002466C4;
    }
    // 0x00246668: nop

    // 0x0024666C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x00246670: lw          $v0, -0x41B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B0);
    // 0x00246674: blez        $v0, L_002466C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x00246678: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_002466C4;
    }
    // 0x00246678: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x0024667C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_00246680:
    // 0x00246680: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x00246684: lw          $v0, -0x41B4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B4);
    // 0x00246688: addu        $a0, $v0, $a1
    ctx->r4 = ADD32(ctx->r2, ctx->r5);
    // 0x0024668C: beql        $a0, $zero, L_002466B0
    if (ctx->r4 == 0) {
        // 0x00246690: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_002466B0;
    }
    goto skip_2;
    // 0x00246690: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x00246694: lbu         $v0, 0x1585($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1585);
    // 0x00246698: bne         $v0, $zero, L_002466C4
    if (ctx->r2 != 0) {
        // 0x0024669C: nop
    
            goto L_002466C4;
    }
    // 0x0024669C: nop

    // 0x002466A0: jal         0x004078AC
    // 0x002466A4: nop

    func_004078AC(rdram, ctx);
        goto after_1;
    // 0x002466A4: nop

    after_1:
    // 0x002466A8: j           L_002466C4
    // 0x002466AC: nop

        goto L_002466C4;
    // 0x002466AC: nop

L_002466B0:
    // 0x002466B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x002466B4: lw          $v0, -0x41B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B0);
    // 0x002466B8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x002466BC: bne         $v0, $zero, L_00246680
    if (ctx->r2 != 0) {
        // 0x002466C0: addiu       $a1, $a1, 0x15C0
        ctx->r5 = ADD32(ctx->r5, 0X15C0);
            goto L_00246680;
    }
    // 0x002466C0: addiu       $a1, $a1, 0x15C0
    ctx->r5 = ADD32(ctx->r5, 0X15C0);
L_002466C4:
    // 0x002466C4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x002466C8: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x002466CC: bne         $v0, $zero, L_002466E4
    if (ctx->r2 != 0) {
        // 0x002466D0: lui         $v1, 0xFFFF
        ctx->r3 = S32(0XFFFF << 16);
            goto L_002466E4;
    }
    // 0x002466D0: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x002466D4: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x002466D8: ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // 0x002466DC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002466E0: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
L_002466E4:
    // 0x002466E4: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x002466E8: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x002466EC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002466F0: beq         $v0, $zero, L_00246700
    if (ctx->r2 == 0) {
        // 0x002466F4: nop
    
            goto L_00246700;
    }
    // 0x002466F4: nop

    // 0x002466F8: jal         0x0025A26C
    // 0x002466FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_0025A26C(rdram, ctx);
        goto after_2;
    // 0x002466FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_00246700:
    // 0x00246700: lw          $v0, 0x334($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X334);
    // 0x00246704: beq         $v0, $zero, L_00246728
    if (ctx->r2 == 0) {
        // 0x00246708: nop
    
            goto L_00246728;
    }
    // 0x00246708: nop

    // 0x0024670C: jal         0x0023D1B0
    // 0x00246710: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_0023D1B0(rdram, ctx);
        goto after_3;
    // 0x00246710: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x00246714: j           L_00246728
    // 0x00246718: nop

        goto L_00246728;
    // 0x00246718: nop

L_0024671C:
    // 0x0024671C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246720: lwc1        $f0, -0x743C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X743C);
    // 0x00246724: mul.s       $f20, $f3, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f3.fl, ctx->f0.fl);
L_00246728:
    // 0x00246728: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024672C: lwc1        $f0, -0x7438($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7438);
    // 0x00246730: add.s       $f3, $f20, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f3.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x00246734: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x00246738: mul.s       $f2, $f2, $f3
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f3.fl);
    // 0x0024673C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x00246740: lwc1        $f1, 0x38($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X38);
    // 0x00246744: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00246748: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x0024674C: mul.s       $f0, $f0, $f3
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f3.fl);
    // 0x00246750: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x00246754: swc1        $f1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
    // 0x00246758: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x0024675C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00246760: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00246764: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00246768: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x0024676C: jr          $ra
    // 0x00246770: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x00246770: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_00246774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246774: lb          $v0, 0x177($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X177);
    // 0x00246778: jr          $ra
    // 0x0024677C: nop

    return;
    // 0x0024677C: nop

;}
RECOMP_FUNC void func_00246780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246780: jr          $ra
    // 0x00246784: sb          $a2, 0x177($a1)
    MEM_B(0X177, ctx->r5) = ctx->r6;
    return;
    // 0x00246784: sb          $a2, 0x177($a1)
    MEM_B(0X177, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_00246788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246788: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x0024678C: lb          $v0, 0x174($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X174);
    // 0x00246790: jr          $ra
    // 0x00246794: nop

    return;
    // 0x00246794: nop

;}
RECOMP_FUNC void func_00246798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246798: lb          $v0, 0x177($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X177);
    // 0x0024679C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x002467A0: lb          $v0, 0x174($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X174);
    // 0x002467A4: jr          $ra
    // 0x002467A8: nop

    return;
    // 0x002467A8: nop

;}
RECOMP_FUNC void func_002467AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002467AC: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x002467B0: jr          $ra
    // 0x002467B4: sb          $a3, 0x174($a1)
    MEM_B(0X174, ctx->r5) = ctx->r7;
    return;
    // 0x002467B4: sb          $a3, 0x174($a1)
    MEM_B(0X174, ctx->r5) = ctx->r7;
;}
RECOMP_FUNC void func_002467B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002467B8: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x002467BC: lb          $v0, 0x174($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X174);
    // 0x002467C0: jr          $ra
    // 0x002467C4: nop

    return;
    // 0x002467C4: nop

;}
RECOMP_FUNC void func_002467C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002467C8: lw          $v0, 0x15C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X15C);
    // 0x002467CC: jr          $ra
    // 0x002467D0: nop

    return;
    // 0x002467D0: nop

;}
RECOMP_FUNC void func_002467D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002467D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002467D8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x002467DC: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x002467E0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002467E4: beq         $a0, $zero, L_002467F8
    if (ctx->r4 == 0) {
        // 0x002467E8: sw          $a0, 0x15C($a1)
        MEM_W(0X15C, ctx->r5) = ctx->r4;
            goto L_002467F8;
    }
    // 0x002467E8: sw          $a0, 0x15C($a1)
    MEM_W(0X15C, ctx->r5) = ctx->r4;
    // 0x002467EC: addiu       $a1, $a0, 0x168
    ctx->r5 = ADD32(ctx->r4, 0X168);
    // 0x002467F0: jal         0x0024BE28
    // 0x002467F4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_0024BE28(rdram, ctx);
        goto after_0;
    // 0x002467F4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_0:
L_002467F8:
    // 0x002467F8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002467FC: jr          $ra
    // 0x00246800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00246800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00246804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246804: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00246808: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024680C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00246810: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00246814: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00246818: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024681C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x00246820: lw          $v1, 0x7C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7C);
    // 0x00246824: lb          $v0, 0x18($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X18);
    // 0x00246828: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0024682C: bne         $v0, $zero, L_00246864
    if (ctx->r2 != 0) {
        // 0x00246830: nop
    
            goto L_00246864;
    }
    // 0x00246830: nop

    // 0x00246834: lb          $v0, 0x19($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X19);
    // 0x00246838: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x0024683C: bne         $v0, $zero, L_00246864
    if (ctx->r2 != 0) {
        // 0x00246840: nop
    
            goto L_00246864;
    }
    // 0x00246840: nop

    // 0x00246844: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00246848: lw          $a1, 0x188($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X188);
    // 0x0024684C: jal         0x00214C80
    // 0x00246850: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214C80(rdram, ctx);
        goto after_0;
    // 0x00246850: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x00246854: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00246858: lw          $a1, 0x18C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18C);
    // 0x0024685C: jal         0x002148D8
    // 0x00246860: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_002148D8(rdram, ctx);
        goto after_1;
    // 0x00246860: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
L_00246864:
    // 0x00246864: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00246868: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0024686C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00246870: jr          $ra
    // 0x00246874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00246874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00246878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024687C: beq         $a3, $v0, L_002468A4
    if (ctx->r7 == ctx->r2) {
        // 0x00246880: slti        $v0, $a3, 0x2
        ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_002468A4;
    }
    // 0x00246880: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x00246884: bne         $v0, $zero, L_0024689C
    if (ctx->r2 != 0) {
        // 0x00246888: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_0024689C;
    }
    // 0x00246888: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x0024688C: beq         $a3, $v0, L_002468B4
    if (ctx->r7 == ctx->r2) {
        // 0x00246890: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_002468B4;
    }
    // 0x00246890: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00246894: beq         $a3, $v0, L_002468C4
    if (ctx->r7 == ctx->r2) {
        // 0x00246898: nop
    
            goto L_002468C4;
    }
    // 0x00246898: nop

L_0024689C:
    // 0x0024689C: jr          $ra
    // 0x002468A0: nop

    return;
    // 0x002468A0: nop

L_002468A4:
    // 0x002468A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002468A8: lwc1        $f1, -0x7434($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7434);
    // 0x002468AC: j           L_002468CC
    // 0x002468B0: nop

        goto L_002468CC;
    // 0x002468B0: nop

L_002468B4:
    // 0x002468B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002468B8: lwc1        $f1, -0x7430($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7430);
    // 0x002468BC: j           L_002468CC
    // 0x002468C0: nop

        goto L_002468CC;
    // 0x002468C0: nop

L_002468C4:
    // 0x002468C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002468C8: lwc1        $f1, -0x742C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X742C);
L_002468CC:
    // 0x002468CC: lwc1        $f0, 0x40($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X40);
    // 0x002468D0: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x002468D4: nop

    // 0x002468D8: bc1f        L_00246918
    if (!c1cs) {
        // 0x002468DC: nop
    
            goto L_00246918;
    }
    // 0x002468DC: nop

    // 0x002468E0: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x002468E4: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x002468E8: nop

    // 0x002468EC: bc1f        L_002468F8
    if (!c1cs) {
        // 0x002468F0: swc1        $f0, 0x40($a1)
        MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
            goto L_002468F8;
    }
    // 0x002468F0: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x002468F4: swc1        $f1, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
L_002468F8:
    // 0x002468F8: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x002468FC: addiu       $t1, $t1, -0xC74
    ctx->r9 = ADD32(ctx->r9, -0XC74);
    // 0x00246900: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x00246904: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x00246908: lw          $t0, 0x8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X8);
    // 0x0024690C: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x00246910: sw          $a0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r4;
    // 0x00246914: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_00246918:
    // 0x00246918: jr          $ra
    // 0x0024691C: nop

    return;
    // 0x0024691C: nop

;}
RECOMP_FUNC void func_00246920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246920: jr          $ra
    // 0x00246924: nop

    return;
    // 0x00246924: nop

;}
RECOMP_FUNC void func_00246928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024692C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00246930: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00246934: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00246938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024693C: beq         $a2, $v0, L_0024694C
    if (ctx->r6 == ctx->r2) {
        // 0x00246940: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_0024694C;
    }
    // 0x00246940: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246944: bne         $a2, $v0, L_00246964
    if (ctx->r6 != ctx->r2) {
        // 0x00246948: nop
    
            goto L_00246964;
    }
    // 0x00246948: nop

L_0024694C:
    // 0x0024694C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x00246950: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x00246954: bne         $v0, $zero, L_00246964
    if (ctx->r2 != 0) {
        // 0x00246958: nop
    
            goto L_00246964;
    }
    // 0x00246958: nop

    // 0x0024695C: jal         0x0023E684
    // 0x00246960: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00246960: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
L_00246964:
    // 0x00246964: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00246968: jr          $ra
    // 0x0024696C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024696C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00246970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246970: jr          $ra
    // 0x00246974: nop

    return;
    // 0x00246974: nop

;}
RECOMP_FUNC void func_00246978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024697C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00246980: lwc1        $f0, 0x60($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X60);
    // 0x00246984: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246988: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x0024698C: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00246990: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00246994: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00246998: nop

    // 0x0024699C: bc1f        L_002469AC
    if (!c1cs) {
        // 0x002469A0: swc1        $f0, 0x60($a1)
        MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
            goto L_002469AC;
    }
    // 0x002469A0: swc1        $f0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
    // 0x002469A4: jal         0x0023E684
    // 0x002469A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x002469A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
L_002469AC:
    // 0x002469AC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002469B0: jr          $ra
    // 0x002469B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002469B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002469B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002469B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002469BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002469C0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x002469C4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x002469C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002469CC: beq         $a2, $v0, L_002469DC
    if (ctx->r6 == ctx->r2) {
        // 0x002469D0: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002469DC;
    }
    // 0x002469D0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x002469D4: bne         $a2, $v0, L_002469E0
    if (ctx->r6 != ctx->r2) {
        // 0x002469D8: nop
    
            goto L_002469E0;
    }
    // 0x002469D8: nop

L_002469DC:
    // 0x002469DC: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_002469E0:
    // 0x002469E0: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x002469E4: bne         $v0, $zero, L_00246A2C
    if (ctx->r2 != 0) {
        // 0x002469E8: nop
    
            goto L_00246A2C;
    }
    // 0x002469E8: nop

    // 0x002469EC: lb          $v0, 0x174($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X174);
    // 0x002469F0: beq         $v0, $zero, L_00246A08
    if (ctx->r2 == 0) {
        // 0x002469F4: nop
    
            goto L_00246A08;
    }
    // 0x002469F4: nop

    // 0x002469F8: jal         0x00242688
    // 0x002469FC: nop

    func_00242688(rdram, ctx);
        goto after_0;
    // 0x002469FC: nop

    after_0:
    // 0x00246A00: j           L_00246A2C
    // 0x00246A04: nop

        goto L_00246A2C;
    // 0x00246A04: nop

L_00246A08:
    // 0x00246A08: lb          $v0, 0x175($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X175);
    // 0x00246A0C: bne         $v0, $zero, L_00246A24
    if (ctx->r2 != 0) {
        // 0x00246A10: nop
    
            goto L_00246A24;
    }
    // 0x00246A10: nop

    // 0x00246A14: jal         0x00242750
    // 0x00246A18: nop

    func_00242750(rdram, ctx);
        goto after_1;
    // 0x00246A18: nop

    after_1:
    // 0x00246A1C: j           L_00246A2C
    // 0x00246A20: nop

        goto L_00246A2C;
    // 0x00246A20: nop

L_00246A24:
    // 0x00246A24: jal         0x00242708
    // 0x00246A28: nop

    func_00242708(rdram, ctx);
        goto after_2;
    // 0x00246A28: nop

    after_2:
L_00246A2C:
    // 0x00246A2C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00246A30: jr          $ra
    // 0x00246A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00246A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00246A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00246A3C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x00246A40: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x00246A44: lw          $v1, 0x14($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X14);
    // 0x00246A48: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x00246A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246A50: beq         $a0, $v0, L_00246A60
    if (ctx->r4 == ctx->r2) {
        // 0x00246A54: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00246A60;
    }
    // 0x00246A54: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246A58: bne         $a0, $v0, L_00246A64
    if (ctx->r4 != ctx->r2) {
        // 0x00246A5C: nop
    
            goto L_00246A64;
    }
    // 0x00246A5C: nop

L_00246A60:
    // 0x00246A60: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
L_00246A64:
    // 0x00246A64: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x00246A68: beq         $v0, $zero, L_00246A90
    if (ctx->r2 == 0) {
        // 0x00246A6C: nop
    
            goto L_00246A90;
    }
    // 0x00246A6C: nop

    // 0x00246A70: lh          $a0, 0xA($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XA);
    // 0x00246A74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00246A78: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00246A7C: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x00246A80: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    // 0x00246A84: lw          $a3, 0xC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0XC);
    // 0x00246A88: jal         0x00273AC4
    // 0x00246A8C: nop

    func_00273AC4(rdram, ctx);
        goto after_0;
    // 0x00246A8C: nop

    after_0:
L_00246A90:
    // 0x00246A90: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00246A94: jr          $ra
    // 0x00246A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00246A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00246A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246A9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00246AA0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00246AA4: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00246AA8: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x00246AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246AB0: beq         $a2, $v0, L_00246AC0
    if (ctx->r6 == ctx->r2) {
        // 0x00246AB4: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00246AC0;
    }
    // 0x00246AB4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246AB8: bne         $a2, $v0, L_00246AC4
    if (ctx->r6 != ctx->r2) {
        // 0x00246ABC: nop
    
            goto L_00246AC4;
    }
    // 0x00246ABC: nop

L_00246AC0:
    // 0x00246AC0: addiu       $a3, $v1, 0x14
    ctx->r7 = ADD32(ctx->r3, 0X14);
L_00246AC4:
    // 0x00246AC4: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x00246AC8: beq         $v0, $zero, L_00246AE4
    if (ctx->r2 == 0) {
        // 0x00246ACC: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_00246AE4;
    }
    // 0x00246ACC: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x00246AD0: lb          $v0, 0xB3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB3);
    // 0x00246AD4: beq         $v0, $zero, L_00246B14
    if (ctx->r2 == 0) {
        // 0x00246AD8: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_00246B14;
    }
    // 0x00246AD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x00246ADC: j           L_00246B0C
    // 0x00246AE0: nop

        goto L_00246B0C;
    // 0x00246AE0: nop

L_00246AE4:
    // 0x00246AE4: lb          $v0, 0x174($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X174);
    // 0x00246AE8: beq         $v0, $v1, L_00246B0C
    if (ctx->r2 == ctx->r3) {
        // 0x00246AEC: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_00246B0C;
    }
    // 0x00246AEC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x00246AF0: lb          $v0, 0x175($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X175);
    // 0x00246AF4: beq         $v0, $v1, L_00246B0C
    if (ctx->r2 == ctx->r3) {
        // 0x00246AF8: nop
    
            goto L_00246B0C;
    }
    // 0x00246AF8: nop

    // 0x00246AFC: lb          $v0, 0x176($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X176);
    // 0x00246B00: bne         $v0, $v1, L_00246B0C
    if (ctx->r2 != ctx->r3) {
        // 0x00246B04: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_00246B0C;
    }
    // 0x00246B04: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x00246B08: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_00246B0C:
    // 0x00246B0C: jal         0x0023E684
    // 0x00246B10: nop

    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00246B10: nop

    after_0:
L_00246B14:
    // 0x00246B14: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00246B18: jr          $ra
    // 0x00246B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00246B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00246B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246B20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00246B24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00246B28: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00246B2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x00246B30: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00246B34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00246B38: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x00246B3C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x00246B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246B44: beq         $a0, $v0, L_00246B58
    if (ctx->r4 == ctx->r2) {
        // 0x00246B48: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_00246B58;
    }
    // 0x00246B48: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00246B4C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246B50: bne         $a0, $v0, L_00246B5C
    if (ctx->r4 != ctx->r2) {
        // 0x00246B54: nop
    
            goto L_00246B5C;
    }
    // 0x00246B54: nop

L_00246B58:
    // 0x00246B58: addiu       $s2, $v1, 0x14
    ctx->r18 = ADD32(ctx->r3, 0X14);
L_00246B5C:
    // 0x00246B5C: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x00246B60: beql        $v0, $zero, L_00246C1C
    if (ctx->r2 == 0) {
        // 0x00246B64: sw          $zero, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = 0;
            goto L_00246C1C;
    }
    goto skip_0;
    // 0x00246B64: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    skip_0:
    // 0x00246B68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00246B6C: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x00246B70: bne         $v0, $zero, L_00246BC4
    if (ctx->r2 != 0) {
        // 0x00246B74: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00246BC4;
    }
    // 0x00246B74: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00246B78: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x00246B7C: lbu         $v0, -0x2DC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2DC8);
    // 0x00246B80: bne         $v0, $zero, L_00246BC4
    if (ctx->r2 != 0) {
        // 0x00246B84: nop
    
            goto L_00246BC4;
    }
    // 0x00246B84: nop

    // 0x00246B88: lw          $a0, 0x108($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X108);
    // 0x00246B8C: beq         $a0, $zero, L_00246BC0
    if (ctx->r4 == 0) {
        // 0x00246B90: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00246BC0;
    }
    // 0x00246B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246B94: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x00246B98: bnel        $v1, $v0, L_00246BC4
    if (ctx->r3 != ctx->r2) {
        // 0x00246B9C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00246BC4;
    }
    goto skip_1;
    // 0x00246B9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    skip_1:
    // 0x00246BA0: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x00246BA4: lui         $v1, 0x1800
    ctx->r3 = S32(0X1800 << 16);
    // 0x00246BA8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00246BAC: beq         $v0, $zero, L_00246BC0
    if (ctx->r2 == 0) {
        // 0x00246BB0: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_00246BC0;
    }
    // 0x00246BB0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00246BB4: lw          $a0, 0x1CC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1CC);
    // 0x00246BB8: jal         0x0023B74C
    // 0x00246BBC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_0023B74C(rdram, ctx);
        goto after_0;
    // 0x00246BBC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
L_00246BC0:
    // 0x00246BC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_00246BC4:
    // 0x00246BC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00246BC8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00246BCC: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x00246BD0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x00246BD4: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    // 0x00246BD8: jal         0x00241E88
    // 0x00246BDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_00241E88(rdram, ctx);
        goto after_1;
    // 0x00246BDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x00246BE0: lui         $v1, 0xFEFF
    ctx->r3 = S32(0XFEFF << 16);
    // 0x00246BE4: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00246BE8: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x00246BEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246BF0: lwc1        $f0, -0x7428($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7428);
    // 0x00246BF4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00246BF8: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
    // 0x00246BFC: lwc1        $f1, 0x3C($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X3C);
    // 0x00246C00: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00246C04: nop

    // 0x00246C08: bc1f        L_00246C1C
    if (!c1cs) {
        // 0x00246C0C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00246C1C;
    }
    // 0x00246C0C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00246C10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00246C14: jal         0x0023E684
    // 0x00246C18: addiu       $a2, $zero, 0x2F
    ctx->r6 = ADD32(0, 0X2F);
    func_0023E684(rdram, ctx);
        goto after_2;
    // 0x00246C18: addiu       $a2, $zero, 0x2F
    ctx->r6 = ADD32(0, 0X2F);
    after_2:
L_00246C1C:
    // 0x00246C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x00246C20: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00246C24: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00246C28: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00246C2C: jr          $ra
    // 0x00246C30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00246C30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00246C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00246C38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00246C3C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00246C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00246C44: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x00246C48: lui         $v1, 0x25
    ctx->r3 = S32(0X25 << 16);
    // 0x00246C4C: addiu       $v1, $v1, -0x79EC
    ctx->r3 = ADD32(ctx->r3, -0X79EC);
    // 0x00246C50: sw          $v1, 0xC8($a1)
    MEM_W(0XC8, ctx->r5) = ctx->r3;
    // 0x00246C54: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x00246C58: jal         0x00242140
    // 0x00246C5C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_00242140(rdram, ctx);
        goto after_0;
    // 0x00246C5C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_0:
    // 0x00246C60: lui         $v1, 0xFF7F
    ctx->r3 = S32(0XFF7F << 16);
    // 0x00246C64: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x00246C68: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00246C6C: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x00246C70: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00246C74: lhu         $v1, 0xD8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD8);
    // 0x00246C78: sh          $zero, 0x330($s0)
    MEM_H(0X330, ctx->r16) = 0;
    // 0x00246C7C: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
    // 0x00246C80: addiu       $v0, $zero, 0x3F6
    ctx->r2 = ADD32(0, 0X3F6);
    // 0x00246C84: beq         $v1, $v0, L_00246C98
    if (ctx->r3 == ctx->r2) {
        // 0x00246C88: addiu       $a1, $zero, 0x80
        ctx->r5 = ADD32(0, 0X80);
            goto L_00246C98;
    }
    // 0x00246C88: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x00246C8C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x00246C90: jal         0x0021B6F4
    // 0x00246C94: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_0021B6F4(rdram, ctx);
        goto after_1;
    // 0x00246C94: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
L_00246C98:
    // 0x00246C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x00246C9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00246CA0: jr          $ra
    // 0x00246CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00246CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00246CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246CA8: lw          $v1, 0x28($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X28);
    // 0x00246CAC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00246CB0: addiu       $v0, $v0, 0x1C8
    ctx->r2 = ADD32(ctx->r2, 0X1C8);
    // 0x00246CB4: beq         $v1, $v0, L_00246CDC
    if (ctx->r3 == ctx->r2) {
        // 0x00246CB8: nop
    
            goto L_00246CDC;
    }
    // 0x00246CB8: nop

    // 0x00246CBC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00246CC0: addiu       $v0, $v0, 0x248
    ctx->r2 = ADD32(ctx->r2, 0X248);
    // 0x00246CC4: beq         $v1, $v0, L_00246CDC
    if (ctx->r3 == ctx->r2) {
        // 0x00246CC8: nop
    
            goto L_00246CDC;
    }
    // 0x00246CC8: nop

    // 0x00246CCC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00246CD0: addiu       $v0, $v0, 0x2C8
    ctx->r2 = ADD32(ctx->r2, 0X2C8);
    // 0x00246CD4: bne         $v1, $v0, L_00246CE4
    if (ctx->r3 != ctx->r2) {
        // 0x00246CD8: nop
    
            goto L_00246CE4;
    }
    // 0x00246CD8: nop

L_00246CDC:
    // 0x00246CDC: jr          $ra
    // 0x00246CE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x00246CE0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00246CE4:
    // 0x00246CE4: jr          $ra
    // 0x00246CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x00246CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_00246CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246CEC: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00246CF0: lhu         $v1, 0xD8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XD8);
    // 0x00246CF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246CF8: lwc1        $f0, -0x7424($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7424);
    // 0x00246CFC: bne         $v1, $v0, L_00246D0C
    if (ctx->r3 != ctx->r2) {
        // 0x00246D00: nop
    
            goto L_00246D0C;
    }
    // 0x00246D00: nop

    // 0x00246D04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246D08: lwc1        $f0, -0x7420($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7420);
L_00246D0C:
    // 0x00246D0C: jr          $ra
    // 0x00246D10: nop

    return;
    // 0x00246D10: nop

;}
RECOMP_FUNC void func_00246D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246D14: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00246D18: lhu         $v1, 0xD8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XD8);
    // 0x00246D1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246D20: lwc1        $f1, -0x741C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X741C);
    // 0x00246D24: bne         $v1, $v0, L_00246D34
    if (ctx->r3 != ctx->r2) {
        // 0x00246D28: nop
    
            goto L_00246D34;
    }
    // 0x00246D28: nop

    // 0x00246D2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246D30: lwc1        $f1, -0x7418($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7418);
L_00246D34:
    // 0x00246D34: lbu         $v0, 0x32($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X32);
    // 0x00246D38: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00246D3C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00246D40: beq         $v0, $zero, L_00246D54
    if (ctx->r2 == 0) {
        // 0x00246D44: nop
    
            goto L_00246D54;
    }
    // 0x00246D44: nop

    // 0x00246D48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246D4C: lwc1        $f0, -0x7414($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7414);
    // 0x00246D50: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
L_00246D54:
    // 0x00246D54: jr          $ra
    // 0x00246D58: mov.s       $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    ctx->f0.fl = ctx->f1.fl;
    return;
    // 0x00246D58: mov.s       $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    ctx->f0.fl = ctx->f1.fl;
;}
RECOMP_FUNC void func_00246D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00246D60: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00246D64: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x00246D68: lw          $a2, 0x3908($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3908);
    // 0x00246D6C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x00246D70: blez        $a2, L_00246DCC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x00246D74: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_00246DCC;
    }
    // 0x00246D74: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00246D78: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x00246D7C: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x00246D80: addiu       $a3, $zero, 0x2F
    ctx->r7 = ADD32(0, 0X2F);
    // 0x00246D84: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
L_00246D88:
    // 0x00246D88: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x00246D8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x00246D90: lw          $v1, 0x3708($at)
    ctx->r3 = MEM_W(ctx->r1, 0X3708);
    // 0x00246D94: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x00246D98: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00246D9C: bnel        $v0, $t1, L_00246DC0
    if (ctx->r2 != ctx->r9) {
        // 0x00246DA0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00246DC0;
    }
    goto skip_0;
    // 0x00246DA0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x00246DA4: lb          $v0, 0x198($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X198);
    // 0x00246DA8: beql        $v0, $t0, L_00246DC0
    if (ctx->r2 == ctx->r8) {
        // 0x00246DAC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00246DC0;
    }
    goto skip_1;
    // 0x00246DAC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x00246DB0: beql        $v0, $a3, L_00246DC0
    if (ctx->r2 == ctx->r7) {
        // 0x00246DB4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00246DC0;
    }
    goto skip_2;
    // 0x00246DB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x00246DB8: j           L_00246DCC
    // 0x00246DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_00246DCC;
    // 0x00246DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_00246DC0:
    // 0x00246DC0: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x00246DC4: bne         $v0, $zero, L_00246D88
    if (ctx->r2 != 0) {
        // 0x00246DC8: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_00246D88;
    }
    // 0x00246DC8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
L_00246DCC:
    // 0x00246DCC: bne         $a1, $zero, L_00246E2C
    if (ctx->r5 != 0) {
        // 0x00246DD0: nop
    
            goto L_00246E2C;
    }
    // 0x00246DD0: nop

    // 0x00246DD4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x00246DD8: addiu       $a0, $a0, -0x41B0
    ctx->r4 = ADD32(ctx->r4, -0X41B0);
    // 0x00246DDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x00246DE0: blez        $v0, L_00246E2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x00246DE4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_00246E2C;
    }
    // 0x00246DE4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x00246DE8: addiu       $a2, $a0, -0x4
    ctx->r6 = ADD32(ctx->r4, -0X4);
    // 0x00246DEC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_00246DF0:
    // 0x00246DF0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x00246DF4: addu        $a0, $v0, $a1
    ctx->r4 = ADD32(ctx->r2, ctx->r5);
    // 0x00246DF8: beql        $a0, $zero, L_00246E1C
    if (ctx->r4 == 0) {
        // 0x00246DFC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_00246E1C;
    }
    goto skip_3;
    // 0x00246DFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x00246E00: lbu         $v0, 0x1585($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1585);
    // 0x00246E04: bne         $v0, $zero, L_00246E2C
    if (ctx->r2 != 0) {
        // 0x00246E08: nop
    
            goto L_00246E2C;
    }
    // 0x00246E08: nop

    // 0x00246E0C: jal         0x004078AC
    // 0x00246E10: nop

    func_004078AC(rdram, ctx);
        goto after_0;
    // 0x00246E10: nop

    after_0:
    // 0x00246E14: j           L_00246E2C
    // 0x00246E18: nop

        goto L_00246E2C;
    // 0x00246E18: nop

L_00246E1C:
    // 0x00246E1C: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x00246E20: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00246E24: bne         $v0, $zero, L_00246DF0
    if (ctx->r2 != 0) {
        // 0x00246E28: addiu       $a1, $a1, 0x15C0
        ctx->r5 = ADD32(ctx->r5, 0X15C0);
            goto L_00246DF0;
    }
    // 0x00246E28: addiu       $a1, $a1, 0x15C0
    ctx->r5 = ADD32(ctx->r5, 0X15C0);
L_00246E2C:
    // 0x00246E2C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00246E30: jr          $ra
    // 0x00246E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00246E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00246E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246E38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00246E3C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00246E40: lw          $v1, 0xF0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XF0);
    // 0x00246E44: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x00246E48: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x00246E4C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00246E50: bne         $a2, $v0, L_00246E90
    if (ctx->r6 != ctx->r2) {
        // 0x00246E54: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_00246E90;
    }
    // 0x00246E54: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00246E58: lbu         $a1, 0xFC($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0XFC);
    // 0x00246E5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00246E60: bne         $a1, $v0, L_00246E78
    if (ctx->r5 != ctx->r2) {
        // 0x00246E64: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00246E78;
    }
    // 0x00246E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00246E68: lw          $v0, 0x2FC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2FC);
    // 0x00246E6C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00246E70: j           L_00246EC8
    // 0x00246E74: sw          $v0, 0x2FC($v1)
    MEM_W(0X2FC, ctx->r3) = ctx->r2;
        goto L_00246EC8;
    // 0x00246E74: sw          $v0, 0x2FC($v1)
    MEM_W(0X2FC, ctx->r3) = ctx->r2;
L_00246E78:
    // 0x00246E78: bne         $a1, $v0, L_00246EC8
    if (ctx->r5 != ctx->r2) {
        // 0x00246E7C: nop
    
            goto L_00246EC8;
    }
    // 0x00246E7C: nop

    // 0x00246E80: lw          $v0, 0x2F8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2F8);
    // 0x00246E84: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00246E88: j           L_00246EC8
    // 0x00246E8C: sw          $v0, 0x2F8($v1)
    MEM_W(0X2F8, ctx->r3) = ctx->r2;
        goto L_00246EC8;
    // 0x00246E8C: sw          $v0, 0x2F8($v1)
    MEM_W(0X2F8, ctx->r3) = ctx->r2;
L_00246E90:
    // 0x00246E90: bne         $a2, $v0, L_00246EC8
    if (ctx->r6 != ctx->r2) {
        // 0x00246E94: nop
    
            goto L_00246EC8;
    }
    // 0x00246E94: nop

    // 0x00246E98: lw          $v0, 0x2C4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C4);
    // 0x00246E9C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00246EA0: sw          $v0, 0x2C4($v1)
    MEM_W(0X2C4, ctx->r3) = ctx->r2;
    // 0x00246EA4: lw          $a0, 0xF0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XF0);
    // 0x00246EA8: lw          $v0, 0x2C0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C0);
    // 0x00246EAC: bgtz        $v0, L_00246EC8
    if (SIGNED(ctx->r2) > 0) {
        // 0x00246EB0: nop
    
            goto L_00246EC8;
    }
    // 0x00246EB0: nop

    // 0x00246EB4: lw          $v0, 0x2C4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C4);
    // 0x00246EB8: bgtz        $v0, L_00246EC8
    if (SIGNED(ctx->r2) > 0) {
        // 0x00246EBC: lui         $a1, 0x40
        ctx->r5 = S32(0X40 << 16);
            goto L_00246EC8;
    }
    // 0x00246EBC: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x00246EC0: jal         0x0021B680
    // 0x00246EC4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    func_0021B680(rdram, ctx);
        goto after_0;
    // 0x00246EC4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_0:
L_00246EC8:
    // 0x00246EC8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00246ECC: jr          $ra
    // 0x00246ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00246ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00246ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00246ED8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00246EDC: lwc1        $f0, 0x110($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X110);
    // 0x00246EE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x00246EE4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x00246EE8: nop

    // 0x00246EEC: bc1f        L_00246F54
    if (!c1cs) {
        // 0x00246EF0: nop
    
            goto L_00246F54;
    }
    // 0x00246EF0: nop

    // 0x00246EF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246EF8: lwc1        $f0, -0x7410($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7410);
    // 0x00246EFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246F00: lwc1        $f1, -0x740C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X740C);
    // 0x00246F04: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00246F08: addiu       $v0, $v0, -0x4734
    ctx->r2 = ADD32(ctx->r2, -0X4734);
    // 0x00246F0C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x00246F10: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x00246F14: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x00246F18: lwc1        $f0, 0x110($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X110);
    // 0x00246F1C: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00246F20: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x00246F24: lwc1        $f1, 0x110($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X110);
    // 0x00246F28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246F2C: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x00246F30: sub.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x00246F34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00246F38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246F3C: sw          $v0, -0x4738($at)
    MEM_W(-0X4738, ctx->r1) = ctx->r2;
    // 0x00246F40: c.le.s      $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f1.fl <= ctx->f2.fl;
    // 0x00246F44: nop

    // 0x00246F48: bc1f        L_00246F54
    if (!c1cs) {
        // 0x00246F4C: swc1        $f1, 0x110($a1)
        MEM_W(0X110, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
            goto L_00246F54;
    }
    // 0x00246F4C: swc1        $f1, 0x110($a1)
    MEM_W(0X110, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    // 0x00246F50: swc1        $f2, 0x110($a1)
    MEM_W(0X110, ctx->r5) = ctx->f2.u32l;
L_00246F54:
    // 0x00246F54: jal         0x00219304
    // 0x00246F58: nop

    func_00219304(rdram, ctx);
        goto after_0;
    // 0x00246F58: nop

    after_0:
    // 0x00246F5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00246F60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246F64: sw          $zero, -0x4738($at)
    MEM_W(-0X4738, ctx->r1) = 0;
    // 0x00246F68: jr          $ra
    // 0x00246F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00246F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00246F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246F70: lbu         $v0, 0xB4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XB4);
    // 0x00246F74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246F78: lwc1        $f2, -0x7408($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7408);
    // 0x00246F7C: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x00246F80: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00246F84: mul.s       $f1, $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f2.fl);
    // 0x00246F88: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x00246F8C: mtc1        $a3, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r7;
    // 0x00246F90: sub.s       $f2, $f3, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f3.fl - ctx->f0.fl;
    // 0x00246F94: mul.s       $f1, $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f2.fl);
    // 0x00246F98: jr          $ra
    // 0x00246F9C: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    return;
    // 0x00246F9C: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
;}
RECOMP_FUNC void func_00246FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00246FA0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x00246FA4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x00246FA8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00246FAC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x00246FB0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x00246FB4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x00246FB8: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x00246FBC: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x00246FC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00246FC4: lwc1        $f20, -0x7404($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7404);
    // 0x00246FC8: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x00246FCC: jal         0x0029A570
    // 0x00246FD0: nop

    func_0029A570(rdram, ctx);
        goto after_0;
    // 0x00246FD0: nop

    after_0:
    // 0x00246FD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00246FD8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x00246FDC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x00246FE0: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x00246FE4: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x00246FE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x00246FEC: swc1        $f0, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = ctx->f0.u32l;
    // 0x00246FF0: jal         0x00299758
    // 0x00246FF4: nop

    func_00299758(rdram, ctx);
        goto after_1;
    // 0x00246FF4: nop

    after_1:
    // 0x00246FF8: addiu       $s2, $sp, 0x20
    ctx->r18 = ADD32(ctx->r29, 0X20);
    // 0x00246FFC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00247000: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x00247004: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x00247008: jal         0x002150B0
    // 0x0024700C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_002150B0(rdram, ctx);
        goto after_2;
    // 0x0024700C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x00247010: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x00247014: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00247018: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x0024701C: jal         0x002150B0
    // 0x00247020: addiu       $a2, $s0, 0x50
    ctx->r6 = ADD32(ctx->r16, 0X50);
    func_002150B0(rdram, ctx);
        goto after_3;
    // 0x00247020: addiu       $a2, $s0, 0x50
    ctx->r6 = ADD32(ctx->r16, 0X50);
    after_3:
    // 0x00247024: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00247028: addiu       $s1, $s0, 0x78
    ctx->r17 = ADD32(ctx->r16, 0X78);
    // 0x0024702C: jal         0x0021525C
    // 0x00247030: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0021525C(rdram, ctx);
        goto after_4;
    // 0x00247030: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x00247034: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x00247038: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x0024703C: lw          $a3, 0x3C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X3C);
    // 0x00247040: jal         0x00214494
    // 0x00247044: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214494(rdram, ctx);
        goto after_5;
    // 0x00247044: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x00247048: lui         $a1, 0x469C
    ctx->r5 = S32(0X469C << 16);
    // 0x0024704C: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x00247050: jal         0x00213658
    // 0x00247054: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_00213658(rdram, ctx);
        goto after_6;
    // 0x00247054: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x00247058: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x0024705C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x00247060: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x00247064: jal         0x00214460
    // 0x00247068: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214460(rdram, ctx);
        goto after_7;
    // 0x00247068: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // 0x0024706C: jal         0x00214D84
    // 0x00247070: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214D84(rdram, ctx);
        goto after_8;
    // 0x00247070: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // 0x00247074: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x00247078: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x0024707C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x00247080: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x00247084: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x00247088: jr          $ra
    // 0x0024708C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x0024708C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_00247090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00247094: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00247098: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0024709C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002470A0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x002470A4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x002470A8: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x002470AC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x002470B0: jal         0x00200528
    // 0x002470B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00200528(rdram, ctx);
        goto after_0;
    // 0x002470B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x002470B8: bne         $v0, $zero, L_002470D0
    if (ctx->r2 != 0) {
        // 0x002470BC: lui         $v1, 0x10
        ctx->r3 = S32(0X10 << 16);
            goto L_002470D0;
    }
    // 0x002470BC: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x002470C0: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x002470C4: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // 0x002470C8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x002470CC: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
L_002470D0:
    // 0x002470D0: jal         0x0028E390
    // 0x002470D4: nop

    func_0028E390(rdram, ctx);
        goto after_1;
    // 0x002470D4: nop

    after_1:
    // 0x002470D8: beq         $v0, $zero, L_002470EC
    if (ctx->r2 == 0) {
        // 0x002470DC: nop
    
            goto L_002470EC;
    }
    // 0x002470DC: nop

    // 0x002470E0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x002470E4: ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
    // 0x002470E8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_002470EC:
    // 0x002470EC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x002470F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x002470F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002470F8: jr          $ra
    // 0x002470FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x002470FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00247100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00247104: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00247108: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0024710C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00247110: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00247114: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00247118: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x0024711C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x00247120: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x00247124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x00247128: jal         0x00200528
    // 0x0024712C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00200528(rdram, ctx);
        goto after_0;
    // 0x0024712C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x00247130: bne         $v0, $zero, L_00247160
    if (ctx->r2 != 0) {
        // 0x00247134: nop
    
            goto L_00247160;
    }
    // 0x00247134: nop

    // 0x00247138: lb          $v0, 0x30($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X30);
    // 0x0024713C: bne         $v0, $zero, L_00247160
    if (ctx->r2 != 0) {
        // 0x00247140: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00247160;
    }
    // 0x00247140: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247144: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00247148: jal         0x00247090
    // 0x0024714C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_00247090(rdram, ctx);
        goto after_1;
    // 0x0024714C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // 0x00247150: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247154: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00247158: jal         0x0023E684
    // 0x0024715C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_0023E684(rdram, ctx);
        goto after_2;
    // 0x0024715C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
L_00247160:
    // 0x00247160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x00247164: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00247168: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0024716C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00247170: jr          $ra
    // 0x00247174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00247174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00247178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024717C: sb          $v0, 0x174($a1)
    MEM_B(0X174, ctx->r5) = ctx->r2;
    // 0x00247180: sb          $v0, 0x175($a1)
    MEM_B(0X175, ctx->r5) = ctx->r2;
    // 0x00247184: jr          $ra
    // 0x00247188: sb          $v0, 0x176($a1)
    MEM_B(0X176, ctx->r5) = ctx->r2;
    return;
    // 0x00247188: sb          $v0, 0x176($a1)
    MEM_B(0X176, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_0024718C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024718C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00247190: sb          $v0, 0x174($a1)
    MEM_B(0X174, ctx->r5) = ctx->r2;
    // 0x00247194: sb          $v0, 0x175($a1)
    MEM_B(0X175, ctx->r5) = ctx->r2;
    // 0x00247198: jr          $ra
    // 0x0024719C: sb          $v0, 0x176($a1)
    MEM_B(0X176, ctx->r5) = ctx->r2;
    return;
    // 0x0024719C: sb          $v0, 0x176($a1)
    MEM_B(0X176, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_002471A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002471A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x002471A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x002471A8: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x002471AC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x002471B0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x002471B4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002471B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002471BC: lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4);
    // 0x002471C0: beq         $v0, $zero, L_002472D0
    if (ctx->r2 == 0) {
        // 0x002471C4: addu        $s3, $a0, $zero
        ctx->r19 = ADD32(ctx->r4, 0);
            goto L_002472D0;
    }
    // 0x002471C4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x002471C8: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x002471CC: lw          $s1, -0x5B38($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X5B38);
    // 0x002471D0: beq         $s1, $zero, L_002472D0
    if (ctx->r17 == 0) {
        // 0x002471D4: nop
    
            goto L_002472D0;
    }
    // 0x002471D4: nop

    // 0x002471D8: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x002471DC: lw          $v1, 0x78($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X78);
    // 0x002471E0: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x002471E4: bne         $v0, $zero, L_00247228
    if (ctx->r2 != 0) {
        // 0x002471E8: addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
            goto L_00247228;
    }
    // 0x002471E8: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x002471EC: bne         $s0, $v1, L_00247228
    if (ctx->r16 != ctx->r3) {
        // 0x002471F0: nop
    
            goto L_00247228;
    }
    // 0x002471F0: nop

    // 0x002471F4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x002471F8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x002471FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x00247200: bne         $v1, $v0, L_00247228
    if (ctx->r3 != ctx->r2) {
        // 0x00247204: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00247228;
    }
    // 0x00247204: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247208: sw          $s0, 0x15C($s2)
    MEM_W(0X15C, ctx->r18) = ctx->r16;
    // 0x0024720C: addiu       $a1, $s0, 0x168
    ctx->r5 = ADD32(ctx->r16, 0X168);
    // 0x00247210: jal         0x0024BE28
    // 0x00247214: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_0024BE28(rdram, ctx);
        goto after_0;
    // 0x00247214: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_0:
    // 0x00247218: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0024721C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x00247220: jal         0x0023E684
    // 0x00247224: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    func_0023E684(rdram, ctx);
        goto after_1;
    // 0x00247224: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_1:
L_00247228:
    // 0x00247228: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x0024722C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00247230: bne         $v1, $v0, L_002472D0
    if (ctx->r3 != ctx->r2) {
        // 0x00247234: addiu       $v0, $zero, 0x3EF
        ctx->r2 = ADD32(0, 0X3EF);
            goto L_002472D0;
    }
    // 0x00247234: addiu       $v0, $zero, 0x3EF
    ctx->r2 = ADD32(0, 0X3EF);
    // 0x00247238: lhu         $v1, 0xD8($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XD8);
    // 0x0024723C: beq         $v1, $v0, L_0024725C
    if (ctx->r3 == ctx->r2) {
        // 0x00247240: addiu       $v0, $zero, 0x3ED
        ctx->r2 = ADD32(0, 0X3ED);
            goto L_0024725C;
    }
    // 0x00247240: addiu       $v0, $zero, 0x3ED
    ctx->r2 = ADD32(0, 0X3ED);
    // 0x00247244: beq         $v1, $v0, L_0024725C
    if (ctx->r3 == ctx->r2) {
        // 0x00247248: addiu       $v0, $zero, 0x3EE
        ctx->r2 = ADD32(0, 0X3EE);
            goto L_0024725C;
    }
    // 0x00247248: addiu       $v0, $zero, 0x3EE
    ctx->r2 = ADD32(0, 0X3EE);
    // 0x0024724C: beq         $v1, $v0, L_0024725C
    if (ctx->r3 == ctx->r2) {
        // 0x00247250: addiu       $v0, $zero, 0x3F0
        ctx->r2 = ADD32(0, 0X3F0);
            goto L_0024725C;
    }
    // 0x00247250: addiu       $v0, $zero, 0x3F0
    ctx->r2 = ADD32(0, 0X3F0);
    // 0x00247254: bne         $v1, $v0, L_0024727C
    if (ctx->r3 != ctx->r2) {
        // 0x00247258: nop
    
            goto L_0024727C;
    }
    // 0x00247258: nop

L_0024725C:
    // 0x0024725C: lbu         $v0, 0x2DC($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X2DC);
    // 0x00247260: addiu       $v0, $v0, -0x7
    ctx->r2 = ADD32(ctx->r2, -0X7);
    // 0x00247264: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00247268: beq         $v0, $zero, L_0024727C
    if (ctx->r2 == 0) {
        // 0x0024726C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_0024727C;
    }
    // 0x0024726C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00247270: lw          $v1, 0x2EC($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X2EC);
    // 0x00247274: beq         $v1, $v0, L_002472D0
    if (ctx->r3 == ctx->r2) {
        // 0x00247278: nop
    
            goto L_002472D0;
    }
    // 0x00247278: nop

L_0024727C:
    // 0x0024727C: lhu         $v1, 0xD8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD8);
    // 0x00247280: addiu       $v0, $zero, 0x3EF
    ctx->r2 = ADD32(0, 0X3EF);
    // 0x00247284: beq         $v1, $v0, L_002472A4
    if (ctx->r3 == ctx->r2) {
        // 0x00247288: addiu       $v0, $zero, 0x3ED
        ctx->r2 = ADD32(0, 0X3ED);
            goto L_002472A4;
    }
    // 0x00247288: addiu       $v0, $zero, 0x3ED
    ctx->r2 = ADD32(0, 0X3ED);
    // 0x0024728C: beq         $v1, $v0, L_002472A4
    if (ctx->r3 == ctx->r2) {
        // 0x00247290: addiu       $v0, $zero, 0x3EE
        ctx->r2 = ADD32(0, 0X3EE);
            goto L_002472A4;
    }
    // 0x00247290: addiu       $v0, $zero, 0x3EE
    ctx->r2 = ADD32(0, 0X3EE);
    // 0x00247294: beq         $v1, $v0, L_002472A4
    if (ctx->r3 == ctx->r2) {
        // 0x00247298: addiu       $v0, $zero, 0x3F0
        ctx->r2 = ADD32(0, 0X3F0);
            goto L_002472A4;
    }
    // 0x00247298: addiu       $v0, $zero, 0x3F0
    ctx->r2 = ADD32(0, 0X3F0);
    // 0x0024729C: bne         $v1, $v0, L_002472C8
    if (ctx->r3 != ctx->r2) {
        // 0x002472A0: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_002472C8;
    }
    // 0x002472A0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_002472A4:
    // 0x002472A4: lbu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2DC);
    // 0x002472A8: addiu       $v0, $v0, -0x7
    ctx->r2 = ADD32(ctx->r2, -0X7);
    // 0x002472AC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x002472B0: beq         $v0, $zero, L_002472C4
    if (ctx->r2 == 0) {
        // 0x002472B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_002472C4;
    }
    // 0x002472B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002472B8: lw          $v1, 0x2EC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2EC);
    // 0x002472BC: beq         $v1, $v0, L_002472D0
    if (ctx->r3 == ctx->r2) {
        // 0x002472C0: nop
    
            goto L_002472D0;
    }
    // 0x002472C0: nop

L_002472C4:
    // 0x002472C4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_002472C8:
    // 0x002472C8: jal         0x0021A9CC
    // 0x002472CC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0021A9CC(rdram, ctx);
        goto after_2;
    // 0x002472CC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_002472D0:
    // 0x002472D0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x002472D4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x002472D8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x002472DC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x002472E0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002472E4: jr          $ra
    // 0x002472E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x002472E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_002472EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002472EC: jr          $ra
    // 0x002472F0: nop

    return;
    // 0x002472F0: nop

;}
RECOMP_FUNC void func_002472F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002472F4: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x002472F8: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x002472FC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00247300: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x00247304: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00247308: sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // 0x0024730C: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x00247310: sdc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD0, ctx->r29);
    // 0x00247314: lw          $a1, 0x158($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X158);
    // 0x00247318: jal         0x00214778
    // 0x0024731C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_00214778(rdram, ctx);
        goto after_0;
    // 0x0024731C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x00247320: lw          $a1, 0x154($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X154);
    // 0x00247324: jal         0x002148D8
    // 0x00247328: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_002148D8(rdram, ctx);
        goto after_1;
    // 0x00247328: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x0024732C: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x00247330: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247334: lwc1        $f20, -0x7400($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7400);
    // 0x00247338: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x0024733C: jal         0x0029A570
    // 0x00247340: nop

    func_0029A570(rdram, ctx);
        goto after_2;
    // 0x00247340: nop

    after_2:
    // 0x00247344: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x00247348: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x0024734C: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x00247350: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x00247354: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x00247358: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x0024735C: swc1        $f0, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = ctx->f0.u32l;
    // 0x00247360: jal         0x00299758
    // 0x00247364: nop

    func_00299758(rdram, ctx);
        goto after_3;
    // 0x00247364: nop

    after_3:
    // 0x00247368: addiu       $s2, $sp, 0xA0
    ctx->r18 = ADD32(ctx->r29, 0XA0);
    // 0x0024736C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00247370: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x00247374: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x00247378: jal         0x002150B0
    // 0x0024737C: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    func_002150B0(rdram, ctx);
        goto after_4;
    // 0x0024737C: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x00247380: addiu       $s1, $sp, 0xB0
    ctx->r17 = ADD32(ctx->r29, 0XB0);
    // 0x00247384: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00247388: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x0024738C: jal         0x002150B0
    // 0x00247390: addiu       $a2, $s0, 0x50
    ctx->r6 = ADD32(ctx->r16, 0X50);
    func_002150B0(rdram, ctx);
        goto after_5;
    // 0x00247390: addiu       $a2, $s0, 0x50
    ctx->r6 = ADD32(ctx->r16, 0X50);
    after_5:
    // 0x00247394: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00247398: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x0024739C: jal         0x0021525C
    // 0x002473A0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_0021525C(rdram, ctx);
        goto after_6;
    // 0x002473A0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_6:
    // 0x002473A4: addiu       $s1, $s0, 0x78
    ctx->r17 = ADD32(ctx->r16, 0X78);
    // 0x002473A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002473AC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x002473B0: jal         0x002110F0
    // 0x002473B4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_002110F0(rdram, ctx);
        goto after_7;
    // 0x002473B4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_7:
    // 0x002473B8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x002473BC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x002473C0: lw          $a3, 0x3C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X3C);
    // 0x002473C4: jal         0x00214494
    // 0x002473C8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214494(rdram, ctx);
        goto after_8;
    // 0x002473C8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // 0x002473CC: lui         $a1, 0x469C
    ctx->r5 = S32(0X469C << 16);
    // 0x002473D0: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x002473D4: jal         0x00213658
    // 0x002473D8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_00213658(rdram, ctx);
        goto after_9;
    // 0x002473D8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x002473DC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x002473E0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x002473E4: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x002473E8: jal         0x00214460
    // 0x002473EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214460(rdram, ctx);
        goto after_10;
    // 0x002473EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x002473F0: jal         0x00214D84
    // 0x002473F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214D84(rdram, ctx);
        goto after_11;
    // 0x002473F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_11:
    // 0x002473F8: lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XCC);
    // 0x002473FC: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x00247400: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x00247404: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x00247408: ldc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD0);
    // 0x0024740C: jr          $ra
    // 0x00247410: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x00247410: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_00247414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247414: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x00247418: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x0024741C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00247420: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x00247424: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00247428: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x0024742C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x00247430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00247434: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x00247438: jal         0x00241C14
    // 0x0024743C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x0024743C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x00247440: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00247444: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00247448: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024744C: lwc1        $f1, -0x73FC($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73FC);
    // 0x00247450: bne         $v1, $v0, L_00247460
    if (ctx->r3 != ctx->r2) {
        // 0x00247454: nop
    
            goto L_00247460;
    }
    // 0x00247454: nop

    // 0x00247458: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024745C: lwc1        $f1, -0x73F8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73F8);
L_00247460:
    // 0x00247460: lbu         $v0, 0x32($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X32);
    // 0x00247464: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00247468: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x0024746C: beq         $v0, $zero, L_00247480
    if (ctx->r2 == 0) {
        // 0x00247470: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00247480;
    }
    // 0x00247470: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00247474: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247478: lwc1        $f0, -0x73F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73F4);
    // 0x0024747C: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
L_00247480:
    // 0x00247480: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x00247484: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x00247488: jal         0x0024197C
    // 0x0024748C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0024197C(rdram, ctx);
        goto after_1;
    // 0x0024748C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x00247490: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x00247494: beq         $v0, $zero, L_002474B4
    if (ctx->r2 == 0) {
        // 0x00247498: addiu       $a0, $s0, 0x80
        ctx->r4 = ADD32(ctx->r16, 0X80);
            goto L_002474B4;
    }
    // 0x00247498: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x0024749C: jal         0x002830A8
    // 0x002474A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_002830A8(rdram, ctx);
        goto after_2;
    // 0x002474A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x002474A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002474A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x002474AC: jal         0x0023E684
    // 0x002474B0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_3;
    // 0x002474B0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_3:
L_002474B4:
    // 0x002474B4: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x002474B8: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x002474BC: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x002474C0: jr          $ra
    // 0x002474C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x002474C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_002474C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002474C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x002474CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002474D0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x002474D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002474D8: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x002474DC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x002474E0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x002474E4: lhu         $v1, 0xD8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD8);
    // 0x002474E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002474EC: lwc1        $f20, -0x73F0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X73F0);
    // 0x002474F0: bne         $v1, $v0, L_00247500
    if (ctx->r3 != ctx->r2) {
        // 0x002474F4: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_00247500;
    }
    // 0x002474F4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x002474F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002474FC: lwc1        $f20, -0x73EC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X73EC);
L_00247500:
    // 0x00247500: lbu         $v0, 0x32($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X32);
    // 0x00247504: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00247508: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x0024750C: beq         $v0, $zero, L_00247520
    if (ctx->r2 == 0) {
        // 0x00247510: nop
    
            goto L_00247520;
    }
    // 0x00247510: nop

    // 0x00247514: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247518: lwc1        $f0, -0x73E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73E8);
    // 0x0024751C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
L_00247520:
    // 0x00247520: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x00247524: lw          $a1, -0xC80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XC80);
    // 0x00247528: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x0024752C: lw          $a2, -0xC7C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XC7C);
    // 0x00247530: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x00247534: lw          $a3, -0xC78($a3)
    ctx->r7 = MEM_W(ctx->r7, -0XC78);
    // 0x00247538: jal         0x00241D2C
    // 0x0024753C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00241D2C(rdram, ctx);
        goto after_0;
    // 0x0024753C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x00247540: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247544: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x00247548: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x0024754C: jal         0x0024197C
    // 0x00247550: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0024197C(rdram, ctx);
        goto after_1;
    // 0x00247550: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x00247554: lb          $v0, 0xB3($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XB3);
    // 0x00247558: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x0024755C: bne         $v0, $zero, L_002475BC
    if (ctx->r2 != 0) {
        // 0x00247560: addiu       $v0, $zero, 0x7D4
        ctx->r2 = ADD32(0, 0X7D4);
            goto L_002475BC;
    }
    // 0x00247560: addiu       $v0, $zero, 0x7D4
    ctx->r2 = ADD32(0, 0X7D4);
    // 0x00247564: lhu         $v1, 0xD8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD8);
    // 0x00247568: bne         $v1, $v0, L_00247580
    if (ctx->r3 != ctx->r2) {
        // 0x0024756C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00247580;
    }
    // 0x0024756C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247570: jal         0x0028B288
    // 0x00247574: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0028B288(rdram, ctx);
        goto after_2;
    // 0x00247574: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x00247578: j           L_002475BC
    // 0x0024757C: nop

        goto L_002475BC;
    // 0x0024757C: nop

L_00247580:
    // 0x00247580: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x00247584: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x00247588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024758C: bne         $v1, $v0, L_002475A8
    if (ctx->r3 != ctx->r2) {
        // 0x00247590: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_002475A8;
    }
    // 0x00247590: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00247594: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247598: jal         0x00245510
    // 0x0024759C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_00245510(rdram, ctx);
        goto after_3;
    // 0x0024759C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x002475A0: j           L_002475BC
    // 0x002475A4: nop

        goto L_002475BC;
    // 0x002475A4: nop

L_002475A8:
    // 0x002475A8: bne         $v1, $v0, L_002475BC
    if (ctx->r3 != ctx->r2) {
        // 0x002475AC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_002475BC;
    }
    // 0x002475AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x002475B0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x002475B4: jal         0x0023E684
    // 0x002475B8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_4;
    // 0x002475B8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_4:
L_002475BC:
    // 0x002475BC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x002475C0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x002475C4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002475C8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x002475CC: jr          $ra
    // 0x002475D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x002475D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_002475D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002475D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002475D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002475DC: lhu         $v1, 0xD8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XD8);
    // 0x002475E0: addiu       $v0, $zero, 0x7D4
    ctx->r2 = ADD32(0, 0X7D4);
    // 0x002475E4: bne         $v1, $v0, L_002475FC
    if (ctx->r3 != ctx->r2) {
        // 0x002475E8: nop
    
            goto L_002475FC;
    }
    // 0x002475E8: nop

    // 0x002475EC: jal         0x0028B288
    // 0x002475F0: nop

    func_0028B288(rdram, ctx);
        goto after_0;
    // 0x002475F0: nop

    after_0:
    // 0x002475F4: j           L_00247630
    // 0x002475F8: nop

        goto L_00247630;
    // 0x002475F8: nop

L_002475FC:
    // 0x002475FC: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x00247600: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x00247604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00247608: bne         $v1, $v0, L_00247620
    if (ctx->r3 != ctx->r2) {
        // 0x0024760C: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00247620;
    }
    // 0x0024760C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00247610: jal         0x00245510
    // 0x00247614: nop

    func_00245510(rdram, ctx);
        goto after_1;
    // 0x00247614: nop

    after_1:
    // 0x00247618: j           L_00247630
    // 0x0024761C: nop

        goto L_00247630;
    // 0x0024761C: nop

L_00247620:
    // 0x00247620: bne         $v1, $v0, L_00247630
    if (ctx->r3 != ctx->r2) {
        // 0x00247624: nop
    
            goto L_00247630;
    }
    // 0x00247624: nop

    // 0x00247628: jal         0x0023E684
    // 0x0024762C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_2;
    // 0x0024762C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
L_00247630:
    // 0x00247630: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247634: jr          $ra
    // 0x00247638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024763C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024763C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00247640: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00247644: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00247648: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024764C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00247650: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x00247654: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x00247658: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x0024765C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00247660: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
    // 0x00247664: lhu         $v1, 0xB0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XB0);
    // 0x00247668: addiu       $v0, $v1, -0x206C
    ctx->r2 = ADD32(ctx->r3, -0X206C);
    // 0x0024766C: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x00247670: bne         $v0, $zero, L_00247694
    if (ctx->r2 != 0) {
        // 0x00247674: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00247694;
    }
    // 0x00247674: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00247678: addiu       $v0, $v1, -0x2076
    ctx->r2 = ADD32(ctx->r3, -0X2076);
    // 0x0024767C: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x00247680: bne         $v0, $zero, L_00247694
    if (ctx->r2 != 0) {
        // 0x00247684: addiu       $v0, $v1, -0x2080
        ctx->r2 = ADD32(ctx->r3, -0X2080);
            goto L_00247694;
    }
    // 0x00247684: addiu       $v0, $v1, -0x2080
    ctx->r2 = ADD32(ctx->r3, -0X2080);
    // 0x00247688: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x0024768C: beq         $v0, $zero, L_002476DC
    if (ctx->r2 == 0) {
        // 0x00247690: nop
    
            goto L_002476DC;
    }
    // 0x00247690: nop

L_00247694:
    // 0x00247694: lw          $a2, 0x74($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X74);
    // 0x00247698: lui         $a3, 0x3E86
    ctx->r7 = S32(0X3E86 << 16);
    // 0x0024769C: ori         $a3, $a3, 0xA93
    ctx->r7 = ctx->r7 | 0XA93;
    // 0x002476A0: jal         0x00240FA0
    // 0x002476A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00240FA0(rdram, ctx);
        goto after_0;
    // 0x002476A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x002476A8: beq         $v0, $zero, L_002476B8
    if (ctx->r2 == 0) {
        // 0x002476AC: nop
    
            goto L_002476B8;
    }
    // 0x002476AC: nop

    // 0x002476B0: j           L_002476F4
    // 0x002476B4: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
        goto L_002476F4;
    // 0x002476B4: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_002476B8:
    // 0x002476B8: lwc1        $f1, 0x3C($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X3C);
    // 0x002476BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002476C0: lwc1        $f0, -0x73E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73E4);
    // 0x002476C4: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x002476C8: nop

    // 0x002476CC: bc1f        L_002476F4
    if (!c1cs) {
        // 0x002476D0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002476F4;
    }
    // 0x002476D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002476D4: j           L_002476EC
    // 0x002476D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
        goto L_002476EC;
    // 0x002476D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_002476DC:
    // 0x002476DC: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x002476E0: beq         $v0, $zero, L_002476F4
    if (ctx->r2 == 0) {
        // 0x002476E4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002476F4;
    }
    // 0x002476E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002476E8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_002476EC:
    // 0x002476EC: jal         0x0023E684
    // 0x002476F0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_1;
    // 0x002476F0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_1:
L_002476F4:
    // 0x002476F4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x002476F8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x002476FC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00247700: jr          $ra
    // 0x00247704: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00247704: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00247708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024770C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00247710: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00247714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00247718: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x0024771C: addiu       $v0, $v0, -0x12
    ctx->r2 = ADD32(ctx->r2, -0X12);
    // 0x00247720: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00247724: beq         $v0, $zero, L_002477A4
    if (ctx->r2 == 0) {
        // 0x00247728: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_002477A4;
    }
    // 0x00247728: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x0024772C: lb          $v1, 0x174($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X174);
    // 0x00247730: beq         $v1, $v0, L_00247754
    if (ctx->r3 == ctx->r2) {
        // 0x00247734: addiu       $v0, $zero, 0x7D3
        ctx->r2 = ADD32(0, 0X7D3);
            goto L_00247754;
    }
    // 0x00247734: addiu       $v0, $zero, 0x7D3
    ctx->r2 = ADD32(0, 0X7D3);
    // 0x00247738: lhu         $v1, 0xD8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XD8);
    // 0x0024773C: beq         $v1, $v0, L_00247754
    if (ctx->r3 == ctx->r2) {
        // 0x00247740: addiu       $v0, $zero, 0x1F4
        ctx->r2 = ADD32(0, 0X1F4);
            goto L_00247754;
    }
    // 0x00247740: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
    // 0x00247744: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x00247748: lw          $v1, 0x42FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X42FC);
    // 0x0024774C: bne         $v1, $v0, L_00247770
    if (ctx->r3 != ctx->r2) {
        // 0x00247750: nop
    
            goto L_00247770;
    }
    // 0x00247750: nop

L_00247754:
    // 0x00247754: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x00247758: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024775C: lwc1        $f14, -0x73E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x00247760: jal         0x00215A90
    // 0x00247764: nop

    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x00247764: nop

    after_0:
    // 0x00247768: j           L_002477A4
    // 0x0024776C: swc1        $f0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f0.u32l;
        goto L_002477A4;
    // 0x0024776C: swc1        $f0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f0.u32l;
L_00247770:
    // 0x00247770: lbu         $v0, 0xB4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB4);
    // 0x00247774: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247778: lwc1        $f0, -0x73DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73DC);
    // 0x0024777C: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x00247780: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00247784: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247788: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024778C: lwc1        $f0, -0x73D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73D8);
    // 0x00247790: mul.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247794: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247798: lwc1        $f1, -0x73D4($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73D4);
    // 0x0024779C: add.s       $f1, $f0, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x002477A0: swc1        $f1, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
L_002477A4:
    // 0x002477A4: lui         $v1, 0xFF7F
    ctx->r3 = S32(0XFF7F << 16);
    // 0x002477A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x002477AC: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x002477B0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002477B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x002477B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x002477BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002477C0: jr          $ra
    // 0x002477C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002477C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002477C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002477C8: lui         $v1, 0xFF7F
    ctx->r3 = S32(0XFF7F << 16);
    // 0x002477CC: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x002477D0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x002477D4: lui         $a2, 0xFEFF
    ctx->r6 = S32(0XFEFF << 16);
    // 0x002477D8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002477DC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x002477E0: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x002477E4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x002477E8: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x002477EC: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    // 0x002477F0: lbu         $v0, 0xB4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XB4);
    // 0x002477F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002477F8: lwc1        $f0, -0x73D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73D0);
    // 0x002477FC: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x00247800: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00247804: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247808: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024780C: lwc1        $f0, -0x73CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73CC);
    // 0x00247810: mul.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247814: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247818: lwc1        $f1, -0x73C8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73C8);
    // 0x0024781C: add.s       $f1, $f0, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00247820: jr          $ra
    // 0x00247824: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    return;
    // 0x00247824: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
;}
RECOMP_FUNC void func_00247828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024782C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247830: lb          $v0, 0xB3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB3);
    // 0x00247834: beq         $v0, $zero, L_00247844
    if (ctx->r2 == 0) {
        // 0x00247838: nop
    
            goto L_00247844;
    }
    // 0x00247838: nop

    // 0x0024783C: jal         0x0023E684
    // 0x00247840: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247840: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
L_00247844:
    // 0x00247844: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247848: jr          $ra
    // 0x0024784C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024784C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247854: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247858: lw          $a0, 0x15C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X15C);
    // 0x0024785C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00247860: jal         0x0023E684
    // 0x00247864: addiu       $a1, $a0, 0x168
    ctx->r5 = ADD32(ctx->r4, 0X168);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247864: addiu       $a1, $a0, 0x168
    ctx->r5 = ADD32(ctx->r4, 0X168);
    after_0:
    // 0x00247868: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024786C: jr          $ra
    // 0x00247870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247874: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x00247878: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x0024787C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00247880: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x00247884: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00247888: addiu       $v1, $zero, 0x2710
    ctx->r3 = ADD32(0, 0X2710);
    // 0x0024788C: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x00247890: lh          $v0, 0xB0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB0);
    // 0x00247894: lw          $a0, 0x15C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X15C);
    // 0x00247898: bne         $v0, $v1, L_0024795C
    if (ctx->r2 != ctx->r3) {
        // 0x0024789C: nop
    
            goto L_0024795C;
    }
    // 0x0024789C: nop

    // 0x002478A0: beql        $a0, $zero, L_002478E4
    if (ctx->r4 == 0) {
        // 0x002478A4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002478E4;
    }
    goto skip_0;
    // 0x002478A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    skip_0:
    // 0x002478A8: lh          $v0, 0x100($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X100);
    // 0x002478AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002478B0: lwc1        $f1, -0x73C4($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73C4);
    // 0x002478B4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x002478B8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x002478BC: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x002478C0: lwc1        $f1, 0xF8($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0XF8);
    // 0x002478C4: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x002478C8: nop

    // 0x002478CC: bc1f        L_002478E0
    if (!c1cs) {
        // 0x002478D0: addiu       $a1, $a0, 0x168
        ctx->r5 = ADD32(ctx->r4, 0X168);
            goto L_002478E0;
    }
    // 0x002478D0: addiu       $a1, $a0, 0x168
    ctx->r5 = ADD32(ctx->r4, 0X168);
    // 0x002478D4: jal         0x0023E684
    // 0x002478D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x002478D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x002478DC: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_002478E0:
    // 0x002478E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_002478E4:
    // 0x002478E4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x002478E8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x002478EC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x002478F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002478F4: jal         0x00241C14
    // 0x002478F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_1;
    // 0x002478F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x002478FC: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00247900: lhu         $v1, 0xD8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XD8);
    // 0x00247904: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247908: lwc1        $f1, -0x73C0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73C0);
    // 0x0024790C: bne         $v1, $v0, L_0024791C
    if (ctx->r3 != ctx->r2) {
        // 0x00247910: nop
    
            goto L_0024791C;
    }
    // 0x00247910: nop

    // 0x00247914: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247918: lwc1        $f1, -0x73BC($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73BC);
L_0024791C:
    // 0x0024791C: lbu         $v0, 0x32($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X32);
    // 0x00247920: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00247924: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x00247928: beq         $v0, $zero, L_0024793C
    if (ctx->r2 == 0) {
        // 0x0024792C: nop
    
            goto L_0024793C;
    }
    // 0x0024792C: nop

    // 0x00247930: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247934: lwc1        $f0, -0x73B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73B8);
    // 0x00247938: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
L_0024793C:
    // 0x0024793C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247940: lwc1        $f0, -0x73B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73B4);
    // 0x00247944: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247948: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024794C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x00247950: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x00247954: jal         0x0024197C
    // 0x00247958: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0024197C(rdram, ctx);
        goto after_2;
    // 0x00247958: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_0024795C:
    // 0x0024795C: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x00247960: beq         $v0, $zero, L_00247974
    if (ctx->r2 == 0) {
        // 0x00247964: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00247974;
    }
    // 0x00247964: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00247968: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024796C: jal         0x0023E684
    // 0x00247970: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_3;
    // 0x00247970: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_3:
L_00247974:
    // 0x00247974: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x00247978: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x0024797C: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x00247980: jr          $ra
    // 0x00247984: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x00247984: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_00247988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247988: jr          $ra
    // 0x0024798C: nop

    return;
    // 0x0024798C: nop

;}
RECOMP_FUNC void func_00247990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247994: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247998: lb          $v0, 0xB3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB3);
    // 0x0024799C: beq         $v0, $zero, L_002479AC
    if (ctx->r2 == 0) {
        // 0x002479A0: nop
    
            goto L_002479AC;
    }
    // 0x002479A0: nop

    // 0x002479A4: jal         0x0023E684
    // 0x002479A8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x002479A8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
L_002479AC:
    // 0x002479AC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002479B0: jr          $ra
    // 0x002479B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002479B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002479B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002479B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002479BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002479C0: lb          $v1, 0xB3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0XB3);
    // 0x002479C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002479C8: beq         $v1, $zero, L_002479D8
    if (ctx->r3 == 0) {
        // 0x002479CC: sb          $v0, 0x177($a1)
        MEM_B(0X177, ctx->r5) = ctx->r2;
            goto L_002479D8;
    }
    // 0x002479CC: sb          $v0, 0x177($a1)
    MEM_B(0X177, ctx->r5) = ctx->r2;
    // 0x002479D0: jal         0x0023E684
    // 0x002479D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x002479D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
L_002479D8:
    // 0x002479D8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002479DC: jr          $ra
    // 0x002479E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002479E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002479E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002479E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002479E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002479EC: lb          $v1, 0xB3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0XB3);
    // 0x002479F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x002479F4: beq         $v1, $zero, L_00247A04
    if (ctx->r3 == 0) {
        // 0x002479F8: sb          $v0, 0x177($a1)
        MEM_B(0X177, ctx->r5) = ctx->r2;
            goto L_00247A04;
    }
    // 0x002479F8: sb          $v0, 0x177($a1)
    MEM_B(0X177, ctx->r5) = ctx->r2;
    // 0x002479FC: jal         0x0023E684
    // 0x00247A00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247A00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
L_00247A04:
    // 0x00247A04: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247A08: jr          $ra
    // 0x00247A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247A14: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247A18: lb          $v0, 0xB3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB3);
    // 0x00247A1C: beq         $v0, $zero, L_00247A2C
    if (ctx->r2 == 0) {
        // 0x00247A20: sb          $zero, 0x177($a1)
        MEM_B(0X177, ctx->r5) = 0;
            goto L_00247A2C;
    }
    // 0x00247A20: sb          $zero, 0x177($a1)
    MEM_B(0X177, ctx->r5) = 0;
    // 0x00247A24: jal         0x0023E684
    // 0x00247A28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247A28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
L_00247A2C:
    // 0x00247A2C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247A30: jr          $ra
    // 0x00247A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247A38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247A3C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247A40: lb          $v1, 0xB3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0XB3);
    // 0x00247A44: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00247A48: beq         $v1, $zero, L_00247A58
    if (ctx->r3 == 0) {
        // 0x00247A4C: sb          $v0, 0x177($a1)
        MEM_B(0X177, ctx->r5) = ctx->r2;
            goto L_00247A58;
    }
    // 0x00247A4C: sb          $v0, 0x177($a1)
    MEM_B(0X177, ctx->r5) = ctx->r2;
    // 0x00247A50: jal         0x0023E684
    // 0x00247A54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247A54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
L_00247A58:
    // 0x00247A58: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247A5C: jr          $ra
    // 0x00247A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247A68: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247A6C: lb          $v0, 0xB3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB3);
    // 0x00247A70: beq         $v0, $zero, L_00247A80
    if (ctx->r2 == 0) {
        // 0x00247A74: sb          $zero, 0x177($a1)
        MEM_B(0X177, ctx->r5) = 0;
            goto L_00247A80;
    }
    // 0x00247A74: sb          $zero, 0x177($a1)
    MEM_B(0X177, ctx->r5) = 0;
    // 0x00247A78: jal         0x0023E684
    // 0x00247A7C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247A7C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
L_00247A80:
    // 0x00247A80: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247A84: jr          $ra
    // 0x00247A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247A90: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247A94: lb          $v1, 0xB3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0XB3);
    // 0x00247A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00247A9C: beq         $v1, $zero, L_00247AAC
    if (ctx->r3 == 0) {
        // 0x00247AA0: sb          $v0, 0x177($a1)
        MEM_B(0X177, ctx->r5) = ctx->r2;
            goto L_00247AAC;
    }
    // 0x00247AA0: sb          $v0, 0x177($a1)
    MEM_B(0X177, ctx->r5) = ctx->r2;
    // 0x00247AA4: jal         0x0023E684
    // 0x00247AA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247AA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
L_00247AAC:
    // 0x00247AAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247AB0: jr          $ra
    // 0x00247AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247AB8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x00247ABC: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x00247AC0: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x00247AC4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00247AC8: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x00247ACC: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
    // 0x00247AD0: addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    // 0x00247AD4: bne         $v1, $v0, L_00247AE4
    if (ctx->r3 != ctx->r2) {
        // 0x00247AD8: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_00247AE4;
    }
    // 0x00247AD8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00247ADC: jal         0x0024655C
    // 0x00247AE0: nop

    func_0024655C(rdram, ctx);
        goto after_0;
    // 0x00247AE0: nop

    after_0:
L_00247AE4:
    // 0x00247AE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247AE8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00247AEC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00247AF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x00247AF4: jal         0x00241C14
    // 0x00247AF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_00241C14(rdram, ctx);
        goto after_1;
    // 0x00247AF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x00247AFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247B00: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00247B04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247B08: lwc1        $f0, -0x73B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X73B0);
    // 0x00247B0C: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247B10: lwc1        $f0, 0x60($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X60);
    // 0x00247B14: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00247B18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247B1C: lwc1        $f12, -0x73AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73AC);
    // 0x00247B20: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x00247B24: jal         0x0029A570
    // 0x00247B28: swc1        $f0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
    func_0029A570(rdram, ctx);
        goto after_2;
    // 0x00247B28: swc1        $f0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x00247B2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247B30: lwc1        $f1, -0x73A8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73A8);
    // 0x00247B34: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00247B38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247B3C: lwc1        $f1, -0x73A4($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73A4);
    // 0x00247B40: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00247B44: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x00247B48: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x00247B4C: lui         $a2, 0x4123
    ctx->r6 = S32(0X4123 << 16);
    // 0x00247B50: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x00247B54: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x00247B58: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x00247B5C: jal         0x00215814
    // 0x00247B60: nop

    func_00215814(rdram, ctx);
        goto after_3;
    // 0x00247B60: nop

    after_3:
    // 0x00247B64: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247B68: lwc1        $f1, -0x73A0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X73A0);
    // 0x00247B6C: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00247B70: nop

    // 0x00247B74: bc1t        L_00247B94
    if (c1cs) {
        // 0x00247B78: swc1        $f0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
            goto L_00247B94;
    }
    // 0x00247B78: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x00247B7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247B80: lwc1        $f1, -0x739C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X739C);
    // 0x00247B84: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00247B88: nop

    // 0x00247B8C: bc1f        L_00247B98
    if (!c1cs) {
        // 0x00247B90: nop
    
            goto L_00247B98;
    }
    // 0x00247B90: nop

L_00247B94:
    // 0x00247B94: swc1        $f1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
L_00247B98:
    // 0x00247B98: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x00247B9C: lwc1        $f1, 0x1C($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X1C);
    // 0x00247BA0: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00247BA4: lwc1        $f1, 0x6C($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X6C);
    // 0x00247BA8: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x00247BAC: nop

    // 0x00247BB0: bc1f        L_00247BD8
    if (!c1cs) {
        // 0x00247BB4: addiu       $v0, $zero, 0x2F
        ctx->r2 = ADD32(0, 0X2F);
            goto L_00247BD8;
    }
    // 0x00247BB4: addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    // 0x00247BB8: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x00247BBC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x00247BC0: lb          $v1, 0x30($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X30);
    // 0x00247BC4: beq         $v1, $v0, L_00247BD8
    if (ctx->r3 == ctx->r2) {
        // 0x00247BC8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00247BD8;
    }
    // 0x00247BC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247BCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00247BD0: jal         0x0023E684
    // 0x00247BD4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_0023E684(rdram, ctx);
        goto after_4;
    // 0x00247BD4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_4:
L_00247BD8:
    // 0x00247BD8: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x00247BDC: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x00247BE0: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x00247BE4: jr          $ra
    // 0x00247BE8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x00247BE8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_00247BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247BEC: lbu         $v1, 0xB4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XB4);
    // 0x00247BF0: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x00247BF4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x00247BF8: beql        $v0, $zero, L_00247C00
    if (ctx->r2 == 0) {
        // 0x00247BFC: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_00247C00;
    }
    goto skip_0;
    // 0x00247BFC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    skip_0:
L_00247C00:
    // 0x00247C00: sb          $v1, 0xB4($a1)
    MEM_B(0XB4, ctx->r5) = ctx->r3;
    // 0x00247C04: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x00247C08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247C0C: lwc1        $f0, -0x7398($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7398);
    // 0x00247C10: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x00247C14: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00247C18: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247C1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247C20: lwc1        $f0, -0x7394($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7394);
    // 0x00247C24: mul.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247C28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247C2C: lwc1        $f1, -0x7390($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7390);
    // 0x00247C30: add.s       $f1, $f0, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00247C34: jr          $ra
    // 0x00247C38: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    return;
    // 0x00247C38: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
;}
RECOMP_FUNC void func_00247C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247C3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247C40: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247C44: lwc1        $f0, 0x60($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X60);
    // 0x00247C48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247C4C: lwc1        $f1, -0x738C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X738C);
    // 0x00247C50: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00247C54: nop

    // 0x00247C58: bc1tl       L_00247C60
    if (c1cs) {
        // 0x00247C5C: swc1        $f1, 0x60($a1)
        MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
            goto L_00247C60;
    }
    goto skip_0;
    // 0x00247C5C: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    skip_0:
L_00247C60:
    // 0x00247C60: lwc1        $f0, 0x60($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X60);
    // 0x00247C64: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247C68: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00247C6C: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00247C70: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00247C74: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00247C78: nop

    // 0x00247C7C: bc1f        L_00247C8C
    if (!c1cs) {
        // 0x00247C80: swc1        $f0, 0x60($a1)
        MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
            goto L_00247C8C;
    }
    // 0x00247C80: swc1        $f0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
    // 0x00247C84: jal         0x0023E684
    // 0x00247C88: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247C88: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
L_00247C8C:
    // 0x00247C8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247C90: jr          $ra
    // 0x00247C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247C98: lbu         $v1, 0xB4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XB4);
    // 0x00247C9C: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x00247CA0: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x00247CA4: beql        $v0, $zero, L_00247CAC
    if (ctx->r2 == 0) {
        // 0x00247CA8: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_00247CAC;
    }
    goto skip_0;
    // 0x00247CA8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    skip_0:
L_00247CAC:
    // 0x00247CAC: sb          $v1, 0xB4($a1)
    MEM_B(0XB4, ctx->r5) = ctx->r3;
    // 0x00247CB0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x00247CB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247CB8: lwc1        $f0, -0x7388($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7388);
    // 0x00247CBC: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x00247CC0: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00247CC4: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247CC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247CCC: lwc1        $f0, -0x7384($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7384);
    // 0x00247CD0: mul.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247CD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247CD8: lwc1        $f1, -0x7380($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7380);
    // 0x00247CDC: add.s       $f1, $f0, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00247CE0: jr          $ra
    // 0x00247CE4: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    return;
    // 0x00247CE4: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
;}
RECOMP_FUNC void func_00247CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247CEC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247CF0: lwc1        $f0, 0x60($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X60);
    // 0x00247CF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247CF8: lwc1        $f1, -0x737C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X737C);
    // 0x00247CFC: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00247D00: nop

    // 0x00247D04: bc1tl       L_00247D0C
    if (c1cs) {
        // 0x00247D08: swc1        $f1, 0x60($a1)
        MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
            goto L_00247D0C;
    }
    goto skip_0;
    // 0x00247D08: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    skip_0:
L_00247D0C:
    // 0x00247D0C: lwc1        $f0, 0x60($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X60);
    // 0x00247D10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247D14: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00247D18: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00247D1C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00247D20: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00247D24: nop

    // 0x00247D28: bc1f        L_00247D38
    if (!c1cs) {
        // 0x00247D2C: swc1        $f0, 0x60($a1)
        MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
            goto L_00247D38;
    }
    // 0x00247D2C: swc1        $f0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
    // 0x00247D30: jal         0x0023E684
    // 0x00247D34: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247D34: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
L_00247D38:
    // 0x00247D38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247D3C: jr          $ra
    // 0x00247D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247D44: lbu         $v1, 0xB4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XB4);
    // 0x00247D48: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x00247D4C: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x00247D50: beql        $v0, $zero, L_00247D58
    if (ctx->r2 == 0) {
        // 0x00247D54: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_00247D58;
    }
    goto skip_0;
    // 0x00247D54: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    skip_0:
L_00247D58:
    // 0x00247D58: sb          $v1, 0xB4($a1)
    MEM_B(0XB4, ctx->r5) = ctx->r3;
    // 0x00247D5C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x00247D60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247D64: lwc1        $f0, -0x7378($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7378);
    // 0x00247D68: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x00247D6C: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00247D70: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247D74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247D78: lwc1        $f0, -0x7374($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7374);
    // 0x00247D7C: mul.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00247D80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247D84: lwc1        $f1, -0x7370($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7370);
    // 0x00247D88: add.s       $f1, $f0, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00247D8C: jr          $ra
    // 0x00247D90: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    return;
    // 0x00247D90: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
;}
RECOMP_FUNC void func_00247D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247D98: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247D9C: lwc1        $f0, 0x60($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X60);
    // 0x00247DA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247DA4: lwc1        $f1, -0x736C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X736C);
    // 0x00247DA8: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00247DAC: nop

    // 0x00247DB0: bc1tl       L_00247DB8
    if (c1cs) {
        // 0x00247DB4: swc1        $f1, 0x60($a1)
        MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
            goto L_00247DB8;
    }
    goto skip_0;
    // 0x00247DB4: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    skip_0:
L_00247DB8:
    // 0x00247DB8: lwc1        $f0, 0x60($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X60);
    // 0x00247DBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247DC0: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00247DC4: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00247DC8: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00247DCC: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00247DD0: nop

    // 0x00247DD4: bc1f        L_00247DE4
    if (!c1cs) {
        // 0x00247DD8: swc1        $f0, 0x60($a1)
        MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
            goto L_00247DE4;
    }
    // 0x00247DD8: swc1        $f0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
    // 0x00247DDC: jal         0x0023E684
    // 0x00247DE0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247DE0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
L_00247DE4:
    // 0x00247DE4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00247DE8: jr          $ra
    // 0x00247DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247DF0: lw          $v0, 0x188($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X188);
    // 0x00247DF4: lui         $v1, 0xFF7F
    ctx->r3 = S32(0XFF7F << 16);
    // 0x00247DF8: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x00247DFC: sw          $v0, 0x188($a1)
    MEM_W(0X188, ctx->r5) = ctx->r2;
    // 0x00247E00: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x00247E04: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00247E08: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00247E0C: jr          $ra
    // 0x00247E10: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    return;
    // 0x00247E10: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_00247E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247E14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00247E18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00247E1C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00247E20: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x00247E24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00247E28: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x00247E2C: beq         $v0, $zero, L_00247E78
    if (ctx->r2 == 0) {
        // 0x00247E30: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_00247E78;
    }
    // 0x00247E30: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00247E34: lb          $v1, 0x174($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X174);
    // 0x00247E38: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00247E3C: bnel        $v1, $v0, L_00247E4C
    if (ctx->r3 != ctx->r2) {
        // 0x00247E40: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00247E4C;
    }
    goto skip_0;
    // 0x00247E40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    skip_0:
    // 0x00247E44: j           L_00247E54
    // 0x00247E48: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
        goto L_00247E54;
    // 0x00247E48: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
L_00247E4C:
    // 0x00247E4C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00247E50: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_00247E54:
    // 0x00247E54: jal         0x0023E684
    // 0x00247E58: nop

    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247E58: nop

    after_0:
    // 0x00247E5C: lb          $v1, 0x174($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X174);
    // 0x00247E60: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x00247E64: beq         $v1, $v0, L_00247E78
    if (ctx->r3 == ctx->r2) {
        // 0x00247E68: lui         $v1, 0x80
        ctx->r3 = S32(0X80 << 16);
            goto L_00247E78;
    }
    // 0x00247E68: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x00247E6C: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x00247E70: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00247E74: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
L_00247E78:
    // 0x00247E78: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00247E7C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00247E80: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00247E84: jr          $ra
    // 0x00247E88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00247E88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00247E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247E8C: lw          $v0, 0x188($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X188);
    // 0x00247E90: lui         $v1, 0xFF7F
    ctx->r3 = S32(0XFF7F << 16);
    // 0x00247E94: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x00247E98: sw          $v0, 0x188($a1)
    MEM_W(0X188, ctx->r5) = ctx->r2;
    // 0x00247E9C: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x00247EA0: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00247EA4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00247EA8: jr          $ra
    // 0x00247EAC: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    return;
    // 0x00247EAC: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_00247EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00247EB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00247EBC: lb          $v0, 0xB3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB3);
    // 0x00247EC0: beq         $v0, $zero, L_00247EFC
    if (ctx->r2 == 0) {
        // 0x00247EC4: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_00247EFC;
    }
    // 0x00247EC4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00247EC8: lb          $v1, 0x174($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X174);
    // 0x00247ECC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00247ED0: bnel        $v1, $v0, L_00247EE0
    if (ctx->r3 != ctx->r2) {
        // 0x00247ED4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00247EE0;
    }
    goto skip_0;
    // 0x00247ED4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x00247ED8: j           L_00247EE4
    // 0x00247EDC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
        goto L_00247EE4;
    // 0x00247EDC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
L_00247EE0:
    // 0x00247EE0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_00247EE4:
    // 0x00247EE4: jal         0x0023E684
    // 0x00247EE8: nop

    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00247EE8: nop

    after_0:
    // 0x00247EEC: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x00247EF0: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x00247EF4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00247EF8: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
L_00247EFC:
    // 0x00247EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x00247F00: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00247F04: jr          $ra
    // 0x00247F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00247F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00247F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247F0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00247F10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00247F14: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00247F18: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00247F1C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x00247F20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x00247F24: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x00247F28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00247F2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x00247F30: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00247F34: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x00247F38: sb          $v0, 0x31($s2)
    MEM_B(0X31, ctx->r18) = ctx->r2;
    // 0x00247F3C: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x00247F40: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x00247F44: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00247F48: jal         0x0021B680
    // 0x00247F4C: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
    func_0021B680(rdram, ctx);
        goto after_0;
    // 0x00247F4C: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
    after_0:
    // 0x00247F50: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x00247F54: addiu       $s0, $s0, 0x2A80
    ctx->r16 = ADD32(ctx->r16, 0X2A80);
    // 0x00247F58: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00247F5C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00247F60: jal         0x00203F6C
    // 0x00247F64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_00203F6C(rdram, ctx);
        goto after_1;
    // 0x00247F64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x00247F68: lw          $v0, 0x18B0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18B0);
    // 0x00247F6C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00247F70: sw          $v0, 0x18B0($s0)
    MEM_W(0X18B0, ctx->r16) = ctx->r2;
    // 0x00247F74: lw          $a1, 0x100($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X100);
    // 0x00247F78: beq         $a1, $zero, L_00247F8C
    if (ctx->r5 == 0) {
        // 0x00247F7C: nop
    
            goto L_00247F8C;
    }
    // 0x00247F7C: nop

    // 0x00247F80: jal         0x002217F0
    // 0x00247F84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_2;
    // 0x00247F84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x00247F88: sw          $zero, 0x100($s2)
    MEM_W(0X100, ctx->r18) = 0;
L_00247F8C:
    // 0x00247F8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247F90: lwc1        $f0, -0x7368($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7368);
    // 0x00247F94: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x00247F98: swc1        $f0, 0x1B0($s2)
    MEM_W(0X1B0, ctx->r18) = ctx->f0.u32l;
    // 0x00247F9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x00247FA0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00247FA4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00247FA8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00247FAC: jr          $ra
    // 0x00247FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00247FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00247FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00247FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00247FB8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00247FBC: lwc1        $f0, 0x1B0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X1B0);
    // 0x00247FC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247FC4: lwc1        $f1, -0x7364($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7364);
    // 0x00247FC8: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00247FCC: nop

    // 0x00247FD0: bc1fl       L_00247FE4
    if (!c1cs) {
        // 0x00247FD4: swc1        $f1, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->f_odd[(1 - 1) * 2];
            goto L_00247FE4;
    }
    goto skip_0;
    // 0x00247FD4: swc1        $f1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f_odd[(1 - 1) * 2];
    skip_0:
    // 0x00247FD8: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x00247FDC: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x00247FE0: swc1        $f0, 0x1B0($a1)
    MEM_W(0X1B0, ctx->r5) = ctx->f0.u32l;
L_00247FE4:
    // 0x00247FE4: lwc1        $f1, 0x3C($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X3C);
    // 0x00247FE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00247FEC: lwc1        $f0, -0x7360($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7360);
    // 0x00247FF0: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00247FF4: nop

    // 0x00247FF8: bc1f        L_00248024
    if (!c1cs) {
        // 0x00247FFC: lui         $v1, 0xFEFF
        ctx->r3 = S32(0XFEFF << 16);
            goto L_00248024;
    }
    // 0x00247FFC: lui         $v1, 0xFEFF
    ctx->r3 = S32(0XFEFF << 16);
    // 0x00248000: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x00248004: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00248008: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x0024800C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x00248010: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x00248014: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x00248018: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024801C: jal         0x0023E684
    // 0x00248020: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x00248020: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    after_0:
L_00248024:
    // 0x00248024: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00248028: jr          $ra
    // 0x0024802C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024802C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00248030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248030: lui         $a2, 0xFF7F
    ctx->r6 = S32(0XFF7F << 16);
    // 0x00248034: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x00248038: lui         $v1, 0x25
    ctx->r3 = S32(0X25 << 16);
    // 0x0024803C: addiu       $v1, $v1, -0x798C
    ctx->r3 = ADD32(ctx->r3, -0X798C);
    // 0x00248040: sw          $v1, 0xC8($a1)
    MEM_W(0XC8, ctx->r5) = ctx->r3;
    // 0x00248044: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x00248048: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x0024804C: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x00248050: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x00248054: sh          $zero, 0x330($a0)
    MEM_H(0X330, ctx->r4) = 0;
    // 0x00248058: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x0024805C: jr          $ra
    // 0x00248060: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    return;
    // 0x00248060: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_00248064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00248068: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x0024806C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x00248070: sw          $zero, 0xBC($a1)
    MEM_W(0XBC, ctx->r5) = 0;
    // 0x00248074: lhu         $v0, 0x330($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X330);
    // 0x00248078: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024807C: lwc1        $f0, -0x735C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X735C);
    // 0x00248080: andi        $v0, $v0, 0xFFFD
    ctx->r2 = ctx->r2 & 0XFFFD;
    // 0x00248084: sh          $v0, 0x330($a2)
    MEM_H(0X330, ctx->r6) = ctx->r2;
    // 0x00248088: lwc1        $f1, 0x3C($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X3C);
    // 0x0024808C: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00248090: nop

    // 0x00248094: bc1f        L_002480D0
    if (!c1cs) {
        // 0x00248098: lui         $v1, 0xFFFF
        ctx->r3 = S32(0XFFFF << 16);
            goto L_002480D0;
    }
    // 0x00248098: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x0024809C: lui         $a0, 0xFFEF
    ctx->r4 = S32(0XFFEF << 16);
    // 0x002480A0: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x002480A4: lw          $v0, 0xF4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XF4);
    // 0x002480A8: ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // 0x002480AC: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x002480B0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002480B4: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x002480B8: sw          $v0, 0xF4($a2)
    MEM_W(0XF4, ctx->r6) = ctx->r2;
    // 0x002480BC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002480C0: beq         $v0, $zero, L_002480D0
    if (ctx->r2 == 0) {
        // 0x002480C4: nop
    
            goto L_002480D0;
    }
    // 0x002480C4: nop

    // 0x002480C8: jal         0x0025A26C
    // 0x002480CC: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    func_0025A26C(rdram, ctx);
        goto after_0;
    // 0x002480CC: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    after_0:
L_002480D0:
    // 0x002480D0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002480D4: jr          $ra
    // 0x002480D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002480D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002480DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002480DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x002480E0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002480E4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x002480E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002480EC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x002480F0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x002480F4: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x002480F8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x002480FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248100: lwc1        $f14, -0x7358($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7358);
    // 0x00248104: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x00248108: jal         0x00215A90
    // 0x0024810C: sw          $v0, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->r2;
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x0024810C: sw          $v0, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->r2;
    after_0:
    // 0x00248110: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x00248114: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x00248118: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024811C: lwc1        $f0, -0x7354($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7354);
    // 0x00248120: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x00248124: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x00248128: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x0024812C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00248130: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00248134: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00248138: jr          $ra
    // 0x0024813C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0024813C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00248140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248140: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x00248144: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x00248148: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x0024814C: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x00248150: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00248154: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00248158: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x0024815C: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x00248160: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x00248164: jal         0x00241C14
    // 0x00248168: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x00248168: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x0024816C: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x00248170: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // 0x00248174: bne         $v1, $v0, L_002481B4
    if (ctx->r3 != ctx->r2) {
        // 0x00248178: nop
    
            goto L_002481B4;
    }
    // 0x00248178: nop

    // 0x0024817C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x00248180: beq         $v0, $zero, L_0024819C
    if (ctx->r2 == 0) {
        // 0x00248184: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_0024819C;
    }
    // 0x00248184: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00248188: lui         $a2, 0x3E05
    ctx->r6 = S32(0X3E05 << 16);
    // 0x0024818C: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x00248190: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x00248194: jal         0x0024197C
    // 0x00248198: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0024197C(rdram, ctx);
        goto after_1;
    // 0x00248198: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
L_0024819C:
    // 0x0024819C: lb          $v0, 0xB3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XB3);
    // 0x002481A0: beq         $v0, $zero, L_00248240
    if (ctx->r2 == 0) {
        // 0x002481A4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00248240;
    }
    // 0x002481A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002481A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x002481AC: j           L_00248238
    // 0x002481B0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
        goto L_00248238;
    // 0x002481B0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
L_002481B4:
    // 0x002481B4: lwc1        $f1, 0x16C($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X16C);
    // 0x002481B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x002481BC: c.lt.s      $f12, $f1
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f12.fl < ctx->f1.fl;
    // 0x002481C0: nop

    // 0x002481C4: bc1f        L_00248240
    if (!c1cs) {
        // 0x002481C8: nop
    
            goto L_00248240;
    }
    // 0x002481C8: nop

    // 0x002481CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002481D0: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x002481D4: sub.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x002481D8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x002481DC: nop

    // 0x002481E0: bc1f        L_00248240
    if (!c1cs) {
        // 0x002481E4: swc1        $f0, 0x16C($s0)
        MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
            goto L_00248240;
    }
    // 0x002481E4: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x002481E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002481EC: lwc1        $f14, -0x7350($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7350);
    // 0x002481F0: jal         0x00215A90
    // 0x002481F4: nop

    func_00215A90(rdram, ctx);
        goto after_2;
    // 0x002481F4: nop

    after_2:
    // 0x002481F8: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x002481FC: beq         $a1, $zero, L_00248240
    if (ctx->r5 == 0) {
        // 0x00248200: swc1        $f0, 0x16C($s0)
        MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
            goto L_00248240;
    }
    // 0x00248200: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x00248204: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x00248208: lui         $a3, 0x3FF5
    ctx->r7 = S32(0X3FF5 << 16);
    // 0x0024820C: ori         $a3, $a3, 0xBE0D
    ctx->r7 = ctx->r7 | 0XBE0D;
    // 0x00248210: lw          $a2, 0x50($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X50);
    // 0x00248214: jal         0x0023E834
    // 0x00248218: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0023E834(rdram, ctx);
        goto after_3;
    // 0x00248218: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x0024821C: beq         $v0, $zero, L_00248230
    if (ctx->r2 == 0) {
        // 0x00248220: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00248230;
    }
    // 0x00248220: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00248224: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00248228: j           L_00248238
    // 0x0024822C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
        goto L_00248238;
    // 0x0024822C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
L_00248230:
    // 0x00248230: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00248234: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
L_00248238:
    // 0x00248238: jal         0x0023E684
    // 0x0024823C: nop

    func_0023E684(rdram, ctx);
        goto after_4;
    // 0x0024823C: nop

    after_4:
L_00248240:
    // 0x00248240: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x00248244: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x00248248: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x0024824C: jr          $ra
    // 0x00248250: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x00248250: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_00248254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248254: jr          $ra
    // 0x00248258: nop

    return;
    // 0x00248258: nop

;}
RECOMP_FUNC void func_0024825C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024825C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00248260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00248264: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248268: lw          $v0, 0x334($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X334);
    // 0x0024826C: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x00248270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00248274: beq         $v1, $v0, L_002482B8
    if (ctx->r3 == ctx->r2) {
        // 0x00248278: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_002482B8;
    }
    // 0x00248278: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x0024827C: lhu         $v1, 0xD8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XD8);
    // 0x00248280: addiu       $v0, $zero, 0x3F9
    ctx->r2 = ADD32(0, 0X3F9);
    // 0x00248284: bnel        $v1, $v0, L_002482B0
    if (ctx->r3 != ctx->r2) {
        // 0x00248288: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_002482B0;
    }
    goto skip_0;
    // 0x00248288: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x0024828C: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x00248290: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x00248294: beql        $v0, $zero, L_002482B0
    if (ctx->r2 == 0) {
        // 0x00248298: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_002482B0;
    }
    goto skip_1;
    // 0x00248298: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_1:
    // 0x0024829C: jal         0x0023E684
    // 0x002482A0: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x002482A0: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    after_0:
    // 0x002482A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x002482A8: j           L_002482B8
    // 0x002482AC: sw          $v0, 0x1AC($s0)
    MEM_W(0X1AC, ctx->r16) = ctx->r2;
        goto L_002482B8;
    // 0x002482AC: sw          $v0, 0x1AC($s0)
    MEM_W(0X1AC, ctx->r16) = ctx->r2;
L_002482B0:
    // 0x002482B0: jal         0x0023E684
    // 0x002482B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_1;
    // 0x002482B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
L_002482B8:
    // 0x002482B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x002482BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002482C0: jr          $ra
    // 0x002482C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002482C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002482C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002482C8: jr          $ra
    // 0x002482CC: nop

    return;
    // 0x002482CC: nop

;}
RECOMP_FUNC void func_002482D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002482D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002482D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x002482D8: lb          $v0, 0xB3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB3);
    // 0x002482DC: beq         $v0, $zero, L_002482EC
    if (ctx->r2 == 0) {
        // 0x002482E0: nop
    
            goto L_002482EC;
    }
    // 0x002482E0: nop

    // 0x002482E4: jal         0x0023E684
    // 0x002482E8: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x002482E8: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_0:
L_002482EC:
    // 0x002482EC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002482F0: jr          $ra
    // 0x002482F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002482F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002482F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002482F8: jr          $ra
    // 0x002482FC: nop

    return;
    // 0x002482FC: nop

;}
RECOMP_FUNC void func_00248300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248300: jr          $ra
    // 0x00248304: nop

    return;
    // 0x00248304: nop

;}
RECOMP_FUNC void func_00248308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248308: jr          $ra
    // 0x0024830C: nop

    return;
    // 0x0024830C: nop

;}
RECOMP_FUNC void func_00248310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248310: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x00248314: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x00248318: jr          $ra
    // 0x0024831C: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x0024831C: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_00248320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248320: lbu         $v1, 0xB4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XB4);
    // 0x00248324: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x00248328: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x0024832C: beql        $v0, $zero, L_00248334
    if (ctx->r2 == 0) {
        // 0x00248330: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_00248334;
    }
    goto skip_0;
    // 0x00248330: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    skip_0:
L_00248334:
    // 0x00248334: jr          $ra
    // 0x00248338: sb          $v1, 0xB4($a1)
    MEM_B(0XB4, ctx->r5) = ctx->r3;
    return;
    // 0x00248338: sb          $v1, 0xB4($a1)
    MEM_B(0XB4, ctx->r5) = ctx->r3;
;}
RECOMP_FUNC void func_0024833C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024833C: lbu         $v0, 0xB4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XB4);
    // 0x00248340: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x00248344: bltzl       $v0, L_0024834C
    if (SIGNED(ctx->r2) < 0) {
        // 0x00248348: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0024834C;
    }
    goto skip_0;
    // 0x00248348: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
L_0024834C:
    // 0x0024834C: jr          $ra
    // 0x00248350: sb          $v0, 0xB4($a1)
    MEM_B(0XB4, ctx->r5) = ctx->r2;
    return;
    // 0x00248350: sb          $v0, 0xB4($a1)
    MEM_B(0XB4, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void func_00248354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248354: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x00248358: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x0024835C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00248360: beq         $a0, $v0, L_00248370
    if (ctx->r4 == ctx->r2) {
        // 0x00248364: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_00248370;
    }
    // 0x00248364: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x00248368: bne         $a0, $v0, L_00248374
    if (ctx->r4 != ctx->r2) {
        // 0x0024836C: nop
    
            goto L_00248374;
    }
    // 0x0024836C: nop

L_00248370:
    // 0x00248370: addiu       $a2, $v1, 0x14
    ctx->r6 = ADD32(ctx->r3, 0X14);
L_00248374:
    // 0x00248374: lb          $v0, 0x174($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X174);
    // 0x00248378: beq         $v0, $zero, L_00248390
    if (ctx->r2 == 0) {
        // 0x0024837C: nop
    
            goto L_00248390;
    }
    // 0x0024837C: nop

    // 0x00248380: lhu         $v0, 0x54($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X54);
    // 0x00248384: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x00248388: bne         $v0, $zero, L_002483C8
    if (ctx->r2 != 0) {
        // 0x0024838C: nop
    
            goto L_002483C8;
    }
    // 0x0024838C: nop

L_00248390:
    // 0x00248390: lb          $v0, 0x175($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X175);
    // 0x00248394: beq         $v0, $zero, L_002483AC
    if (ctx->r2 == 0) {
        // 0x00248398: nop
    
            goto L_002483AC;
    }
    // 0x00248398: nop

    // 0x0024839C: lhu         $v0, 0x54($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X54);
    // 0x002483A0: andi        $v0, $v0, 0x3E0
    ctx->r2 = ctx->r2 & 0X3E0;
    // 0x002483A4: bne         $v0, $zero, L_002483C8
    if (ctx->r2 != 0) {
        // 0x002483A8: nop
    
            goto L_002483C8;
    }
    // 0x002483A8: nop

L_002483AC:
    // 0x002483AC: lb          $v0, 0x176($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X176);
    // 0x002483B0: beq         $v0, $zero, L_002483D0
    if (ctx->r2 == 0) {
        // 0x002483B4: nop
    
            goto L_002483D0;
    }
    // 0x002483B4: nop

    // 0x002483B8: lhu         $v0, 0x54($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X54);
    // 0x002483BC: andi        $v0, $v0, 0x7C00
    ctx->r2 = ctx->r2 & 0X7C00;
    // 0x002483C0: beq         $v0, $zero, L_002483D0
    if (ctx->r2 == 0) {
        // 0x002483C4: nop
    
            goto L_002483D0;
    }
    // 0x002483C4: nop

L_002483C8:
    // 0x002483C8: jr          $ra
    // 0x002483CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x002483CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_002483D0:
    // 0x002483D0: jr          $ra
    // 0x002483D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x002483D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_002483D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002483D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x002483DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002483E0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x002483E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x002483E8: lb          $v1, 0x33($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X33);
    // 0x002483EC: beq         $v1, $zero, L_00248408
    if (ctx->r3 == 0) {
        // 0x002483F0: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_00248408;
    }
    // 0x002483F0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x002483F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002483F8: beq         $v1, $v0, L_0024848C
    if (ctx->r3 == ctx->r2) {
        // 0x002483FC: nop
    
            goto L_0024848C;
    }
    // 0x002483FC: nop

    // 0x00248400: j           L_002484D4
    // 0x00248404: nop

        goto L_002484D4;
    // 0x00248404: nop

L_00248408:
    // 0x00248408: lwc1        $f1, 0x40($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X40);
    // 0x0024840C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248410: lwc1        $f0, -0x734C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X734C);
    // 0x00248414: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00248418: nop

    // 0x0024841C: bc1f        L_00248464
    if (!c1cs) {
        // 0x00248420: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_00248464;
    }
    // 0x00248420: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x00248424: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00248428: jal         0x0023E684
    // 0x0024842C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024842C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_0:
    // 0x00248430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00248434: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x00248438: addiu       $t2, $t2, -0xC74
    ctx->r10 = ADD32(ctx->r10, -0XC74);
    // 0x0024843C: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x00248440: addiu       $t1, $t1, -0xC80
    ctx->r9 = ADD32(ctx->r9, -0XC80);
    // 0x00248444: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x00248448: lw          $t0, 0x4($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4);
    // 0x0024844C: sw          $a3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r7;
    // 0x00248450: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x00248454: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x00248458: sw          $a3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r7;
    // 0x0024845C: j           L_002484D4
    // 0x00248460: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
        goto L_002484D4;
    // 0x00248460: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
L_00248464:
    // 0x00248464: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00248468: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x0024846C: nop

    // 0x00248470: bc1f        L_002484D4
    if (!c1cs) {
        // 0x00248474: nop
    
            goto L_002484D4;
    }
    // 0x00248474: nop

    // 0x00248478: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024847C: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x00248480: sub.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x00248484: j           L_002484D4
    // 0x00248488: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
        goto L_002484D4;
    // 0x00248488: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_0024848C:
    // 0x0024848C: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x00248490: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248494: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00248498: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x0024849C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x002484A0: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x002484A4: nop

    // 0x002484A8: bc1f        L_002484D4
    if (!c1cs) {
        // 0x002484AC: swc1        $f0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
            goto L_002484D4;
    }
    // 0x002484AC: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x002484B0: lb          $v0, 0x80($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X80);
    // 0x002484B4: beq         $v0, $zero, L_002484D4
    if (ctx->r2 == 0) {
        // 0x002484B8: sb          $zero, 0x33($s0)
        MEM_B(0X33, ctx->r16) = 0;
            goto L_002484D4;
    }
    // 0x002484B8: sb          $zero, 0x33($s0)
    MEM_B(0X33, ctx->r16) = 0;
    // 0x002484BC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x002484C0: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x002484C4: lbu         $a1, 0x81($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X81);
    // 0x002484C8: jal         0x00205774
    // 0x002484CC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_00205774(rdram, ctx);
        goto after_1;
    // 0x002484CC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x002484D0: sh          $v0, 0x82($s0)
    MEM_H(0X82, ctx->r16) = ctx->r2;
L_002484D4:
    // 0x002484D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x002484D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002484DC: jr          $ra
    // 0x002484E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002484E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002484E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002484E4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x002484E8: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x002484EC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x002484F0: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x002484F4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x002484F8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x002484FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x00248500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00248504: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x00248508: jal         0x00241C14
    // 0x0024850C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x0024850C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x00248510: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00248514: lhu         $v1, 0xD8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD8);
    // 0x00248518: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024851C: lwc1        $f1, -0x7348($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7348);
    // 0x00248520: bne         $v1, $v0, L_00248530
    if (ctx->r3 != ctx->r2) {
        // 0x00248524: nop
    
            goto L_00248530;
    }
    // 0x00248524: nop

    // 0x00248528: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024852C: lwc1        $f1, -0x7344($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7344);
L_00248530:
    // 0x00248530: lbu         $v0, 0x32($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X32);
    // 0x00248534: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00248538: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x0024853C: beq         $v0, $zero, L_00248550
    if (ctx->r2 == 0) {
        // 0x00248540: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00248550;
    }
    // 0x00248540: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00248544: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248548: lwc1        $f0, -0x7340($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7340);
    // 0x0024854C: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
L_00248550:
    // 0x00248550: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x00248554: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x00248558: jal         0x0024197C
    // 0x0024855C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0024197C(rdram, ctx);
        goto after_1;
    // 0x0024855C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x00248560: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x00248564: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x00248568: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x0024856C: jr          $ra
    // 0x00248570: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x00248570: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_00248574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248574: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x00248578: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024857C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00248580: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00248584: addiu       $v0, $zero, 0x3F1
    ctx->r2 = ADD32(0, 0X3F1);
    // 0x00248588: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024858C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x00248590: lhu         $v1, 0xD8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD8);
    // 0x00248594: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248598: lwc1        $f20, -0x733C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X733C);
    // 0x0024859C: bne         $v1, $v0, L_002485AC
    if (ctx->r3 != ctx->r2) {
        // 0x002485A0: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_002485AC;
    }
    // 0x002485A0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x002485A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002485A8: lwc1        $f20, -0x7338($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7338);
L_002485AC:
    // 0x002485AC: lbu         $v0, 0x32($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X32);
    // 0x002485B0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x002485B4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x002485B8: beq         $v0, $zero, L_002485CC
    if (ctx->r2 == 0) {
        // 0x002485BC: nop
    
            goto L_002485CC;
    }
    // 0x002485BC: nop

    // 0x002485C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002485C4: lwc1        $f0, -0x7334($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7334);
    // 0x002485C8: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
L_002485CC:
    // 0x002485CC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x002485D0: addiu       $v0, $v0, -0xC80
    ctx->r2 = ADD32(ctx->r2, -0XC80);
    // 0x002485D4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x002485D8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x002485DC: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x002485E0: jal         0x00241D2C
    // 0x002485E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00241D2C(rdram, ctx);
        goto after_0;
    // 0x002485E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x002485E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x002485EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x002485F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x002485F4: jal         0x0024197C
    // 0x002485F8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0024197C(rdram, ctx);
        goto after_1;
    // 0x002485F8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x002485FC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00248600: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00248604: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00248608: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x0024860C: jr          $ra
    // 0x00248610: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x00248610: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_00248614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00248618: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024861C: lwc1        $f0, 0x3C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x00248620: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248624: lwc1        $f1, -0x7330($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7330);
    // 0x00248628: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x0024862C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248630: lwc1        $f1, -0x732C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X732C);
    // 0x00248634: sub.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x00248638: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x0024863C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00248640: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248644: sw          $v0, -0x4738($at)
    MEM_W(-0X4738, ctx->r1) = ctx->r2;
    // 0x00248648: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x0024864C: nop

    // 0x00248650: bc1tl       L_00248658
    if (c1cs) {
        // 0x00248654: mov.s       $f1, $f0
        CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    ctx->f1.fl = ctx->f0.fl;
            goto L_00248658;
    }
    goto skip_0;
    // 0x00248654: mov.s       $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    ctx->f1.fl = ctx->f0.fl;
    skip_0:
L_00248658:
    // 0x00248658: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024865C: swc1        $f1, -0x4728($at)
    MEM_W(-0X4728, ctx->r1) = ctx->f_odd[(1 - 1) * 2];
    // 0x00248660: jal         0x00219304
    // 0x00248664: nop

    func_00219304(rdram, ctx);
        goto after_0;
    // 0x00248664: nop

    after_0:
    // 0x00248668: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024866C: jr          $ra
    // 0x00248670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00248670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00248674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00248678: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024867C: lwc1        $f0, 0x3C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x00248680: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248684: lwc1        $f1, -0x7328($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7328);
    // 0x00248688: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x0024868C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248690: lwc1        $f1, -0x7324($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7324);
    // 0x00248694: sub.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x00248698: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x0024869C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x002486A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002486A4: sw          $v0, -0x4738($at)
    MEM_W(-0X4738, ctx->r1) = ctx->r2;
    // 0x002486A8: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x002486AC: nop

    // 0x002486B0: bc1tl       L_002486B8
    if (c1cs) {
        // 0x002486B4: mov.s       $f1, $f0
        CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    ctx->f1.fl = ctx->f0.fl;
            goto L_002486B8;
    }
    goto skip_0;
    // 0x002486B4: mov.s       $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    ctx->f1.fl = ctx->f0.fl;
    skip_0:
L_002486B8:
    // 0x002486B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002486BC: swc1        $f1, -0x4728($at)
    MEM_W(-0X4728, ctx->r1) = ctx->f_odd[(1 - 1) * 2];
    // 0x002486C0: jal         0x00219304
    // 0x002486C4: nop

    func_00219304(rdram, ctx);
        goto after_0;
    // 0x002486C4: nop

    after_0:
    // 0x002486C8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x002486CC: jr          $ra
    // 0x002486D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002486D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
// Entry point after a return; the word before it (0x002486D4) is a stray instruction the
// game never executes. Reached through a function table.
RECOMP_FUNC void func_002486D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002486D8: lui         $v1, 0xFEFF
    ctx->r3 = S32(0XFEFF << 16);
    // 0x002486DC: sw          $zero, 0x68($a1)
    MEM_W(0X68, ctx->r5) = 0;
    // 0x002486E0: sw          $zero, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = 0;
    // 0x002486E4: sw          $zero, 0x70($a1)
    MEM_W(0X70, ctx->r5) = 0;
    // 0x002486E8: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x002486EC: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x002486F0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x002486F4: jr          $ra
    // 0x002486F8: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    return;
    // 0x002486F8: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_002486FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002486FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248700: lwc1        $f0, -0x7320($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7320);
    // 0x00248704: jr          $ra
    // 0x00248708: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    return;
    // 0x00248708: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_0024870C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024870C: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x00248710: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x00248714: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00248718: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x0024871C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00248720: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00248724: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x00248728: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x0024872C: sw          $ra, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r31;
    // 0x00248730: jal         0x00241C14
    // 0x00248734: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x00248734: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x00248738: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024873C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00248740: jal         0x0024176C
    // 0x00248744: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    func_0024176C(rdram, ctx);
        goto after_1;
    // 0x00248744: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    after_1:
    // 0x00248748: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024874C: jal         0x00246D14
    // 0x00248750: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00246D14(rdram, ctx);
        goto after_2;
    // 0x00248750: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x00248754: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00248758: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x0024875C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x00248760: jal         0x0024197C
    // 0x00248764: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0024197C(rdram, ctx);
        goto after_3;
    // 0x00248764: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // 0x00248768: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024876C: jal         0x00246CEC
    // 0x00248770: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00246CEC(rdram, ctx);
        goto after_4;
    // 0x00248770: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // 0x00248774: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x00248778: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x0024877C: c.lt.s      $f2, $f1
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f2.fl < ctx->f1.fl;
    // 0x00248780: nop

    // 0x00248784: bc1f        L_002487A8
    if (!c1cs) {
        // 0x00248788: mov.s       $f1, $f0
        CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    ctx->f1.fl = ctx->f0.fl;
            goto L_002487A8;
    }
    // 0x00248788: mov.s       $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    ctx->f1.fl = ctx->f0.fl;
    // 0x0024878C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x00248790: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00248794: nop

    // 0x00248798: bc1t        L_002487B8
    if (c1cs) {
        // 0x0024879C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002487B8;
    }
    // 0x0024879C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002487A0: j           L_002487F4
    // 0x002487A4: nop

        goto L_002487F4;
    // 0x002487A4: nop

L_002487A8:
    // 0x002487A8: c.le.s      $f2, $f1
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f2.fl <= ctx->f1.fl;
    // 0x002487AC: nop

    // 0x002487B0: bc1f        L_002487F4
    if (!c1cs) {
        // 0x002487B4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002487F4;
    }
    // 0x002487B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_002487B8:
    // 0x002487B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x002487BC: jal         0x0024501C
    // 0x002487C0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_0024501C(rdram, ctx);
        goto after_5;
    // 0x002487C0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_5:
    // 0x002487C4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x002487C8: beq         $a2, $zero, L_002487E0
    if (ctx->r6 == 0) {
        // 0x002487CC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_002487E0;
    }
    // 0x002487CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x002487D0: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
    // 0x002487D4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002487D8: j           L_002487EC
    // 0x002487DC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
        goto L_002487EC;
    // 0x002487DC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_002487E0:
    // 0x002487E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x002487E4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x002487E8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_002487EC:
    // 0x002487EC: jal         0x0023E684
    // 0x002487F0: nop

    func_0023E684(rdram, ctx);
        goto after_6;
    // 0x002487F0: nop

    after_6:
L_002487F4:
    // 0x002487F4: lw          $ra, 0xE8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE8);
    // 0x002487F8: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x002487FC: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x00248800: jr          $ra
    // 0x00248804: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x00248804: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_00248808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248808: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x0024880C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248810: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00248814: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00248818: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0024881C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00248820: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x00248824: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x00248828: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x0024882C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x00248830: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x00248834: lw          $s3, 0x48($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X48);
    // 0x00248838: jal         0x00246774
    // 0x0024883C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    func_00246774(rdram, ctx);
        goto after_0;
    // 0x0024883C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    after_0:
    // 0x00248840: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x00248844: bne         $v0, $v1, L_0024895C
    if (ctx->r2 != ctx->r3) {
        // 0x00248848: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_0024895C;
    }
    // 0x00248848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024884C: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x00248850: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248854: lwc1        $f1, -0x7318($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7318);
    // 0x00248858: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x0024885C: mul.s       $f14, $f0, $f1
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00248860: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248864: lwc1        $f0, -0x7314($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7314);
    // 0x00248868: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x0024886C: nop

    // 0x00248870: bc1tl       L_00248890
    if (c1cs) {
        // 0x00248874: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_00248890;
    }
    goto skip_0;
    // 0x00248874: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    skip_0:
    // 0x00248878: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024887C: lwc1        $f0, -0x7310($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7310);
    // 0x00248880: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x00248884: nop

    // 0x00248888: bc1tl       L_00248890
    if (c1cs) {
        // 0x0024888C: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_00248890;
    }
    goto skip_1;
    // 0x0024888C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    skip_1:
L_00248890:
    // 0x00248890: lwc1        $f12, 0x154($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X154);
    // 0x00248894: lui         $a2, 0x3DB2
    ctx->r6 = S32(0X3DB2 << 16);
    // 0x00248898: ori         $a2, $a2, 0xB8C4
    ctx->r6 = ctx->r6 | 0XB8C4;
    // 0x0024889C: jal         0x00215814
    // 0x002488A0: nop

    func_00215814(rdram, ctx);
        goto after_1;
    // 0x002488A0: nop

    after_1:
    // 0x002488A4: swc1        $f0, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f0.u32l;
    // 0x002488A8: lwc1        $f1, 0x4C($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X4C);
    // 0x002488AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002488B0: lwc1        $f0, -0x730C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X730C);
    // 0x002488B4: mul.s       $f14, $f1, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x002488B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002488BC: lwc1        $f0, -0x7308($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7308);
    // 0x002488C0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x002488C4: nop

    // 0x002488C8: bc1tl       L_002488E8
    if (c1cs) {
        // 0x002488CC: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_002488E8;
    }
    goto skip_2;
    // 0x002488CC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    skip_2:
    // 0x002488D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002488D4: lwc1        $f0, -0x7304($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7304);
    // 0x002488D8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x002488DC: nop

    // 0x002488E0: bc1tl       L_002488E8
    if (c1cs) {
        // 0x002488E4: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_002488E8;
    }
    goto skip_3;
    // 0x002488E4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    skip_3:
L_002488E8:
    // 0x002488E8: lwc1        $f12, 0x158($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X158);
    // 0x002488EC: lui         $a2, 0x3E32
    ctx->r6 = S32(0X3E32 << 16);
    // 0x002488F0: ori         $a2, $a2, 0xB8C4
    ctx->r6 = ctx->r6 | 0XB8C4;
    // 0x002488F4: jal         0x00215814
    // 0x002488F8: nop

    func_00215814(rdram, ctx);
        goto after_2;
    // 0x002488F8: nop

    after_2:
    // 0x002488FC: swc1        $f0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->f0.u32l;
    // 0x00248900: lwc1        $f1, 0x18($s4)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r20, 0X18);
    // 0x00248904: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248908: lwc1        $f0, -0x7300($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7300);
    // 0x0024890C: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00248910: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x00248914: lwc1        $f14, 0x60($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X60);
    // 0x00248918: mfc1        $a2, $f1
    ctx->r6 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x0024891C: jal         0x002156AC
    // 0x00248920: nop

    func_002156AC(rdram, ctx);
        goto after_3;
    // 0x00248920: nop

    after_3:
    // 0x00248924: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248928: lwc1        $f1, -0x72FC($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72FC);
    // 0x0024892C: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00248930: nop

    // 0x00248934: bc1t        L_00248954
    if (c1cs) {
        // 0x00248938: swc1        $f0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
            goto L_00248954;
    }
    // 0x00248938: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x0024893C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248940: lwc1        $f1, -0x72F8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72F8);
    // 0x00248944: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00248948: nop

    // 0x0024894C: bc1f        L_0024895C
    if (!c1cs) {
        // 0x00248950: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_0024895C;
    }
    // 0x00248950: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_00248954:
    // 0x00248954: swc1        $f1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
    // 0x00248958: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_0024895C:
    // 0x0024895C: lui         $a2, 0x3E56
    ctx->r6 = S32(0X3E56 << 16);
    // 0x00248960: ori         $a2, $a2, 0x7751
    ctx->r6 = ctx->r6 | 0X7751;
    // 0x00248964: lw          $a3, 0x4C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4C);
    // 0x00248968: jal         0x0024197C
    // 0x0024896C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0024197C(rdram, ctx);
        goto after_4;
    // 0x0024896C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x00248970: lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X44);
    // 0x00248974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00248978: bne         $v1, $v0, L_002489D4
    if (ctx->r3 != ctx->r2) {
        // 0x0024897C: nop
    
            goto L_002489D4;
    }
    // 0x0024897C: nop

    // 0x00248980: beq         $s3, $zero, L_002489D4
    if (ctx->r19 == 0) {
        // 0x00248984: nop
    
            goto L_002489D4;
    }
    // 0x00248984: nop

    // 0x00248988: lwc1        $f0, 0x170($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X170);
    // 0x0024898C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248990: lwc1        $f20, -0x72F4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X72F4);
    // 0x00248994: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x00248998: nop

    // 0x0024899C: bc1f        L_002489D4
    if (!c1cs) {
        // 0x002489A0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_002489D4;
    }
    // 0x002489A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x002489A4: jal         0x00246774
    // 0x002489A8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_00246774(rdram, ctx);
        goto after_5;
    // 0x002489A8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // 0x002489AC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x002489B0: addiu       $a1, $a0, 0x168
    ctx->r5 = ADD32(ctx->r4, 0X168);
    // 0x002489B4: jal         0x00246774
    // 0x002489B8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_00246774(rdram, ctx);
        goto after_6;
    // 0x002489B8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_6:
    // 0x002489BC: beq         $s0, $v0, L_002489D4
    if (ctx->r16 == ctx->r2) {
        // 0x002489C0: nop
    
            goto L_002489D4;
    }
    // 0x002489C0: nop

    // 0x002489C4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x002489C8: jal         0x00215A90
    // 0x002489CC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_00215A90(rdram, ctx);
        goto after_7;
    // 0x002489CC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_7:
    // 0x002489D0: swc1        $f0, 0x170($s1)
    MEM_W(0X170, ctx->r17) = ctx->f0.u32l;
L_002489D4:
    // 0x002489D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x002489D8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x002489DC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x002489E0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x002489E4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x002489E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002489EC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x002489F0: jr          $ra
    // 0x002489F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x002489F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_002489F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002489F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x002489FC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x00248A00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248A04: lwc1        $f20, -0x72F0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X72F0);
    // 0x00248A08: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248A0C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00248A10: sdc1        $f21, 0x20($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X20, ctx->r29);
    // 0x00248A14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248A18: lwc1        $f21, -0x72EC($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X72EC);
    // 0x00248A1C: lui         $v0, 0x25
    ctx->r2 = S32(0X25 << 16);
    // 0x00248A20: addiu       $v0, $v0, -0x752C
    ctx->r2 = ADD32(ctx->r2, -0X752C);
    // 0x00248A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00248A28: sw          $v0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->r2;
    // 0x00248A2C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248A30: jal         0x00215A90
    // 0x00248A34: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x00248A34: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    after_0:
    // 0x00248A38: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248A3C: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x00248A40: jal         0x00215A90
    // 0x00248A44: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_1;
    // 0x00248A44: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x00248A48: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248A4C: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x00248A50: jal         0x00215A90
    // 0x00248A54: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_2;
    // 0x00248A54: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x00248A58: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x00248A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x00248A60: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00248A64: ldc1        $f21, 0x20($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X20);
    // 0x00248A68: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x00248A6C: jr          $ra
    // 0x00248A70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x00248A70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_00248A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00248A78: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00248A80: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x00248A84: jal         0x00246774
    // 0x00248A88: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_00246774(rdram, ctx);
        goto after_0;
    // 0x00248A88: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x00248A8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x00248A90: beq         $v0, $v1, L_00248AC0
    if (ctx->r2 == ctx->r3) {
        // 0x00248A94: nop
    
            goto L_00248AC0;
    }
    // 0x00248A94: nop

    // 0x00248A98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248A9C: lwc1        $f20, -0x72E8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X72E8);
    // 0x00248AA0: lwc1        $f12, 0x158($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X158);
    // 0x00248AA4: jal         0x002157AC
    // 0x00248AA8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_002157AC(rdram, ctx);
        goto after_1;
    // 0x00248AA8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x00248AAC: lwc1        $f12, 0x154($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X154);
    // 0x00248AB0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x00248AB4: jal         0x002157AC
    // 0x00248AB8: swc1        $f0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f0.u32l;
    func_002157AC(rdram, ctx);
        goto after_2;
    // 0x00248AB8: swc1        $f0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x00248ABC: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
L_00248AC0:
    // 0x00248AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x00248AC4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00248AC8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x00248ACC: jr          $ra
    // 0x00248AD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00248AD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00248AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248AD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00248AD8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00248ADC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00248AE0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248AE4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x00248AE8: jal         0x00246774
    // 0x00248AEC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_00246774(rdram, ctx);
        goto after_0;
    // 0x00248AEC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x00248AF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x00248AF4: bne         $v0, $v1, L_00248B24
    if (ctx->r2 != ctx->r3) {
        // 0x00248AF8: nop
    
            goto L_00248B24;
    }
    // 0x00248AF8: nop

    // 0x00248AFC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x00248B00: lw          $v0, -0x5B38($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B38);
    // 0x00248B04: beq         $v0, $zero, L_00248B24
    if (ctx->r2 == 0) {
        // 0x00248B08: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_00248B24;
    }
    // 0x00248B08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x00248B0C: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x00248B10: bne         $v1, $v0, L_00248B24
    if (ctx->r3 != ctx->r2) {
        // 0x00248B14: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00248B24;
    }
    // 0x00248B14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00248B18: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00248B1C: jal         0x0023E684
    // 0x00248B20: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_0023E684(rdram, ctx);
        goto after_1;
    // 0x00248B20: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_1:
L_00248B24:
    // 0x00248B24: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00248B28: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00248B2C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00248B30: jr          $ra
    // 0x00248B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00248B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00248B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248B38: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x00248B3C: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x00248B40: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00248B44: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x00248B48: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00248B4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00248B50: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00248B54: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x00248B58: sw          $ra, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r31;
    // 0x00248B5C: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x00248B60: jal         0x00241C14
    // 0x00248B64: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x00248B64: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x00248B68: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00248B6C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00248B70: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x00248B74: jal         0x0024176C
    // 0x00248B78: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_0024176C(rdram, ctx);
        goto after_1;
    // 0x00248B78: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x00248B7C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00248B80: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00248B84: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00248B88: jal         0x00248808
    // 0x00248B8C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00248808(rdram, ctx);
        goto after_2;
    // 0x00248B8C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_2:
    // 0x00248B90: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00248B94: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00248B98: jal         0x0024501C
    // 0x00248B9C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_0024501C(rdram, ctx);
        goto after_3;
    // 0x00248B9C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x00248BA0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x00248BA4: beq         $a2, $zero, L_00248BBC
    if (ctx->r6 == 0) {
        // 0x00248BA8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_00248BBC;
    }
    // 0x00248BA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00248BAC: sb          $v0, 0x31($s1)
    MEM_B(0X31, ctx->r17) = ctx->r2;
    // 0x00248BB0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00248BB4: jal         0x0023E684
    // 0x00248BB8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0023E684(rdram, ctx);
        goto after_4;
    // 0x00248BB8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
L_00248BBC:
    // 0x00248BBC: lw          $ra, 0xEC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XEC);
    // 0x00248BC0: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x00248BC4: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x00248BC8: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x00248BCC: jr          $ra
    // 0x00248BD0: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x00248BD0: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_00248BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00248BD8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248BDC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00248BE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248BE4: lwc1        $f12, -0x72E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X72E4);
    // 0x00248BE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248BEC: lwc1        $f14, -0x72E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X72E0);
    // 0x00248BF0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x00248BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00248BF8: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x00248BFC: lui         $v0, 0x25
    ctx->r2 = S32(0X25 << 16);
    // 0x00248C00: addiu       $v0, $v0, -0x752C
    ctx->r2 = ADD32(ctx->r2, -0X752C);
    // 0x00248C04: jal         0x00215A90
    // 0x00248C08: sw          $v0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->r2;
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x00248C08: sw          $v0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->r2;
    after_0:
    // 0x00248C0C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248C10: lwc1        $f12, -0x72DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X72DC);
    // 0x00248C14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248C18: lwc1        $f14, -0x72D8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X72D8);
    // 0x00248C1C: jal         0x00215A90
    // 0x00248C20: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_1;
    // 0x00248C20: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x00248C24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248C28: lwc1        $f12, -0x72D4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X72D4);
    // 0x00248C2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248C30: lwc1        $f14, -0x72D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X72D0);
    // 0x00248C34: jal         0x00215A90
    // 0x00248C38: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_2;
    // 0x00248C38: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x00248C3C: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x00248C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x00248C44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00248C48: jr          $ra
    // 0x00248C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00248C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00248C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248C50: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x00248C54: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x00248C58: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00248C5C: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x00248C60: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00248C64: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00248C68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x00248C6C: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x00248C70: sw          $ra, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r31;
    // 0x00248C74: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x00248C78: jal         0x00241C14
    // 0x00248C7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x00248C7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x00248C80: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00248C84: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00248C88: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x00248C8C: jal         0x0024176C
    // 0x00248C90: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_0024176C(rdram, ctx);
        goto after_1;
    // 0x00248C90: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x00248C94: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00248C98: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00248C9C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00248CA0: jal         0x00248808
    // 0x00248CA4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00248808(rdram, ctx);
        goto after_2;
    // 0x00248CA4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_2:
    // 0x00248CA8: lwc1        $f1, 0x80($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X80);
    // 0x00248CAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248CB0: lwc1        $f0, -0x72CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72CC);
    // 0x00248CB4: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x00248CB8: nop

    // 0x00248CBC: bc1t        L_00248CE0
    if (c1cs) {
        // 0x00248CC0: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00248CE0;
    }
    // 0x00248CC0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00248CC4: lwc1        $f1, 0x3C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X3C);
    // 0x00248CC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248CCC: lwc1        $f0, -0x72C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72C8);
    // 0x00248CD0: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00248CD4: nop

    // 0x00248CD8: bc1f        L_00248CEC
    if (!c1cs) {
        // 0x00248CDC: nop
    
            goto L_00248CEC;
    }
    // 0x00248CDC: nop

L_00248CE0:
    // 0x00248CE0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00248CE4: jal         0x0023E684
    // 0x00248CE8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_3;
    // 0x00248CE8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
L_00248CEC:
    // 0x00248CEC: lw          $ra, 0xEC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XEC);
    // 0x00248CF0: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x00248CF4: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x00248CF8: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x00248CFC: jr          $ra
    // 0x00248D00: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x00248D00: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_00248D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248D04: div.s       $f12, $f12, $f1
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f1.fl);
    // 0x00248D08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x00248D0C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00248D10: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00248D14: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x00248D18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248D1C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x00248D20: sdc1        $f21, 0x28($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X28, ctx->r29);
    // 0x00248D24: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x00248D28: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x00248D2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248D30: lwc1        $f1, -0x72C0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72C0);
    // 0x00248D34: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x00248D38: mul.s       $f14, $f0, $f1
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00248D3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248D40: lwc1        $f0, -0x72BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72BC);
    // 0x00248D44: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x00248D48: nop

    // 0x00248D4C: bc1t        L_00248D6C
    if (c1cs) {
        // 0x00248D50: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_00248D6C;
    }
    // 0x00248D50: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00248D54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248D58: lwc1        $f0, -0x72B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72B8);
    // 0x00248D5C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x00248D60: nop

    // 0x00248D64: bc1f        L_00248D70
    if (!c1cs) {
        // 0x00248D68: nop
    
            goto L_00248D70;
    }
    // 0x00248D68: nop

L_00248D6C:
    // 0x00248D6C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_00248D70:
    // 0x00248D70: lwc1        $f12, 0x154($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X154);
    // 0x00248D74: lui         $a2, 0x3D8E
    ctx->r6 = S32(0X3D8E << 16);
    // 0x00248D78: ori         $a2, $a2, 0xFA36
    ctx->r6 = ctx->r6 | 0XFA36;
    // 0x00248D7C: jal         0x00215814
    // 0x00248D80: nop

    func_00215814(rdram, ctx);
        goto after_0;
    // 0x00248D80: nop

    after_0:
    // 0x00248D84: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x00248D88: beq         $v0, $zero, L_00248E90
    if (ctx->r2 == 0) {
        // 0x00248D8C: swc1        $f0, 0x154($s0)
        MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
            goto L_00248E90;
    }
    // 0x00248D8C: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    // 0x00248D90: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x00248D94: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x00248D98: bne         $v1, $v0, L_00248E40
    if (ctx->r3 != ctx->r2) {
        // 0x00248D9C: nop
    
            goto L_00248E40;
    }
    // 0x00248D9C: nop

    // 0x00248DA0: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x00248DA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DA8: lwc1        $f12, -0x72B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X72B4);
    // 0x00248DAC: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x00248DB0: jal         0x00299758
    // 0x00248DB4: nop

    func_00299758(rdram, ctx);
        goto after_1;
    // 0x00248DB4: nop

    after_1:
    // 0x00248DB8: lwc1        $f20, 0x164($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X164);
    // 0x00248DBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DC0: lwc1        $f22, -0x72B0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X72B0);
    // 0x00248DC4: mul.s       $f1, $f20, $f22
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f1.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x00248DC8: sub.s       $f1, $f1, $f20
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f1.fl = ctx->f1.fl - ctx->f20.fl;
    // 0x00248DCC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DD0: lwc1        $f2, -0x72AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72AC);
    // 0x00248DD4: mul.s       $f1, $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f2.fl);
    // 0x00248DD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DDC: lwc1        $f2, -0x72A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72A8);
    // 0x00248DE0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x00248DE4: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00248DE8: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x00248DEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DF0: lwc1        $f14, -0x72A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X72A4);
    // 0x00248DF4: mul.s       $f14, $f20, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x00248DF8: lwc1        $f12, 0x34($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X34);
    // 0x00248DFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248E00: lwc1        $f21, -0x72A0($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X72A0);
    // 0x00248E04: mfc1        $a2, $f21
    ctx->r6 = (int32_t)ctx->f_odd[(21 - 1) * 2];
    // 0x00248E08: jal         0x00215814
    // 0x00248E0C: add.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
    func_00215814(rdram, ctx);
        goto after_2;
    // 0x00248E0C: add.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
    after_2:
    // 0x00248E10: mul.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x00248E14: lwc1        $f12, 0x38($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X38);
    // 0x00248E18: mfc1        $a2, $f21
    ctx->r6 = (int32_t)ctx->f_odd[(21 - 1) * 2];
    // 0x00248E1C: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x00248E20: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x00248E24: jal         0x00215814
    // 0x00248E28: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_00215814(rdram, ctx);
        goto after_3;
    // 0x00248E28: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_3:
    // 0x00248E2C: lwc1        $f12, 0x3C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x00248E30: mfc1        $a2, $f21
    ctx->r6 = (int32_t)ctx->f_odd[(21 - 1) * 2];
    // 0x00248E34: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x00248E38: j           L_00248E84
    // 0x00248E3C: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
        goto L_00248E84;
    // 0x00248E3C: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
L_00248E40:
    // 0x00248E40: lwc1        $f12, 0x34($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X34);
    // 0x00248E44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248E48: lwc1        $f20, -0x729C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X729C);
    // 0x00248E4C: lwc1        $f14, 0x164($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X164);
    // 0x00248E50: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x00248E54: jal         0x00215814
    // 0x00248E58: nop

    func_00215814(rdram, ctx);
        goto after_4;
    // 0x00248E58: nop

    after_4:
    // 0x00248E5C: lwc1        $f12, 0x38($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X38);
    // 0x00248E60: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x00248E64: lwc1        $f14, 0x164($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X164);
    // 0x00248E68: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x00248E6C: jal         0x00215814
    // 0x00248E70: nop

    func_00215814(rdram, ctx);
        goto after_5;
    // 0x00248E70: nop

    after_5:
    // 0x00248E74: lwc1        $f12, 0x3C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x00248E78: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x00248E7C: lwc1        $f14, 0x164($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X164);
    // 0x00248E80: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_00248E84:
    // 0x00248E84: jal         0x00215814
    // 0x00248E88: nop

    func_00215814(rdram, ctx);
        goto after_6;
    // 0x00248E88: nop

    after_6:
    // 0x00248E8C: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
L_00248E90:
    // 0x00248E90: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x00248E94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248E98: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00248E9C: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00248EA0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00248EA4: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00248EA8: nop

    // 0x00248EAC: bc1f        L_00248F10
    if (!c1cs) {
        // 0x00248EB0: swc1        $f0, 0x16C($s0)
        MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
            goto L_00248F10;
    }
    // 0x00248EB0: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x00248EB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248EB8: lwc1        $f12, -0x7298($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7298);
    // 0x00248EBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248EC0: lwc1        $f14, -0x7294($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7294);
    // 0x00248EC4: jal         0x00215A90
    // 0x00248EC8: nop

    func_00215A90(rdram, ctx);
        goto after_7;
    // 0x00248EC8: nop

    after_7:
    // 0x00248ECC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248ED0: lwc1        $f20, -0x7290($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7290);
    // 0x00248ED4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248ED8: lwc1        $f21, -0x728C($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X728C);
    // 0x00248EDC: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x00248EE0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248EE4: jal         0x00215A90
    // 0x00248EE8: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    func_00215A90(rdram, ctx);
        goto after_8;
    // 0x00248EE8: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    after_8:
    // 0x00248EEC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248EF0: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x00248EF4: jal         0x00215A90
    // 0x00248EF8: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_9;
    // 0x00248EF8: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    after_9:
    // 0x00248EFC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248F00: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x00248F04: jal         0x00215A90
    // 0x00248F08: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_10;
    // 0x00248F08: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    after_10:
    // 0x00248F0C: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
L_00248F10:
    // 0x00248F10: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00248F14: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00248F18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00248F1C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x00248F20: ldc1        $f21, 0x28($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X28);
    // 0x00248F24: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x00248F28: jr          $ra
    // 0x00248F2C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x00248F2C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_00248D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248D08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x00248D0C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00248D10: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00248D14: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x00248D18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248D1C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x00248D20: sdc1        $f21, 0x28($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X28, ctx->r29);
    // 0x00248D24: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x00248D28: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x00248D2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248D30: lwc1        $f1, -0x72C0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X72C0);
    // 0x00248D34: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x00248D38: mul.s       $f14, $f0, $f1
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00248D3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248D40: lwc1        $f0, -0x72BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72BC);
    // 0x00248D44: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x00248D48: nop

    // 0x00248D4C: bc1t        L_00248D6C
    if (c1cs) {
        // 0x00248D50: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_00248D6C;
    }
    // 0x00248D50: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00248D54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248D58: lwc1        $f0, -0x72B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72B8);
    // 0x00248D5C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x00248D60: nop

    // 0x00248D64: bc1f        L_00248D70
    if (!c1cs) {
        // 0x00248D68: nop
    
            goto L_00248D70;
    }
    // 0x00248D68: nop

L_00248D6C:
    // 0x00248D6C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_00248D70:
    // 0x00248D70: lwc1        $f12, 0x154($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X154);
    // 0x00248D74: lui         $a2, 0x3D8E
    ctx->r6 = S32(0X3D8E << 16);
    // 0x00248D78: ori         $a2, $a2, 0xFA36
    ctx->r6 = ctx->r6 | 0XFA36;
    // 0x00248D7C: jal         0x00215814
    // 0x00248D80: nop

    func_00215814(rdram, ctx);
        goto after_0;
    // 0x00248D80: nop

    after_0:
    // 0x00248D84: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x00248D88: beq         $v0, $zero, L_00248E90
    if (ctx->r2 == 0) {
        // 0x00248D8C: swc1        $f0, 0x154($s0)
        MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
            goto L_00248E90;
    }
    // 0x00248D8C: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    // 0x00248D90: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x00248D94: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x00248D98: bne         $v1, $v0, L_00248E40
    if (ctx->r3 != ctx->r2) {
        // 0x00248D9C: nop
    
            goto L_00248E40;
    }
    // 0x00248D9C: nop

    // 0x00248DA0: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x00248DA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DA8: lwc1        $f12, -0x72B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X72B4);
    // 0x00248DAC: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x00248DB0: jal         0x00299758
    // 0x00248DB4: nop

    func_00299758(rdram, ctx);
        goto after_1;
    // 0x00248DB4: nop

    after_1:
    // 0x00248DB8: lwc1        $f20, 0x164($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X164);
    // 0x00248DBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DC0: lwc1        $f22, -0x72B0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X72B0);
    // 0x00248DC4: mul.s       $f1, $f20, $f22
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f1.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x00248DC8: sub.s       $f1, $f1, $f20
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f1.fl = ctx->f1.fl - ctx->f20.fl;
    // 0x00248DCC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DD0: lwc1        $f2, -0x72AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72AC);
    // 0x00248DD4: mul.s       $f1, $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f2.fl);
    // 0x00248DD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DDC: lwc1        $f2, -0x72A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X72A8);
    // 0x00248DE0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x00248DE4: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00248DE8: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x00248DEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248DF0: lwc1        $f14, -0x72A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X72A4);
    // 0x00248DF4: mul.s       $f14, $f20, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x00248DF8: lwc1        $f12, 0x34($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X34);
    // 0x00248DFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248E00: lwc1        $f21, -0x72A0($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X72A0);
    // 0x00248E04: mfc1        $a2, $f21
    ctx->r6 = (int32_t)ctx->f_odd[(21 - 1) * 2];
    // 0x00248E08: jal         0x00215814
    // 0x00248E0C: add.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
    func_00215814(rdram, ctx);
        goto after_2;
    // 0x00248E0C: add.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
    after_2:
    // 0x00248E10: mul.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x00248E14: lwc1        $f12, 0x38($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X38);
    // 0x00248E18: mfc1        $a2, $f21
    ctx->r6 = (int32_t)ctx->f_odd[(21 - 1) * 2];
    // 0x00248E1C: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x00248E20: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x00248E24: jal         0x00215814
    // 0x00248E28: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_00215814(rdram, ctx);
        goto after_3;
    // 0x00248E28: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_3:
    // 0x00248E2C: lwc1        $f12, 0x3C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x00248E30: mfc1        $a2, $f21
    ctx->r6 = (int32_t)ctx->f_odd[(21 - 1) * 2];
    // 0x00248E34: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x00248E38: j           L_00248E84
    // 0x00248E3C: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
        goto L_00248E84;
    // 0x00248E3C: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
L_00248E40:
    // 0x00248E40: lwc1        $f12, 0x34($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X34);
    // 0x00248E44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248E48: lwc1        $f20, -0x729C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X729C);
    // 0x00248E4C: lwc1        $f14, 0x164($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X164);
    // 0x00248E50: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x00248E54: jal         0x00215814
    // 0x00248E58: nop

    func_00215814(rdram, ctx);
        goto after_4;
    // 0x00248E58: nop

    after_4:
    // 0x00248E5C: lwc1        $f12, 0x38($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X38);
    // 0x00248E60: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x00248E64: lwc1        $f14, 0x164($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X164);
    // 0x00248E68: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x00248E6C: jal         0x00215814
    // 0x00248E70: nop

    func_00215814(rdram, ctx);
        goto after_5;
    // 0x00248E70: nop

    after_5:
    // 0x00248E74: lwc1        $f12, 0x3C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x00248E78: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x00248E7C: lwc1        $f14, 0x164($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X164);
    // 0x00248E80: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_00248E84:
    // 0x00248E84: jal         0x00215814
    // 0x00248E88: nop

    func_00215814(rdram, ctx);
        goto after_6;
    // 0x00248E88: nop

    after_6:
    // 0x00248E8C: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
L_00248E90:
    // 0x00248E90: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x00248E94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248E98: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00248E9C: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00248EA0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00248EA4: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00248EA8: nop

    // 0x00248EAC: bc1f        L_00248F10
    if (!c1cs) {
        // 0x00248EB0: swc1        $f0, 0x16C($s0)
        MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
            goto L_00248F10;
    }
    // 0x00248EB0: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x00248EB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248EB8: lwc1        $f12, -0x7298($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7298);
    // 0x00248EBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248EC0: lwc1        $f14, -0x7294($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7294);
    // 0x00248EC4: jal         0x00215A90
    // 0x00248EC8: nop

    func_00215A90(rdram, ctx);
        goto after_7;
    // 0x00248EC8: nop

    after_7:
    // 0x00248ECC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248ED0: lwc1        $f20, -0x7290($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7290);
    // 0x00248ED4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248ED8: lwc1        $f21, -0x728C($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X728C);
    // 0x00248EDC: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x00248EE0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248EE4: jal         0x00215A90
    // 0x00248EE8: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    func_00215A90(rdram, ctx);
        goto after_8;
    // 0x00248EE8: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    after_8:
    // 0x00248EEC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248EF0: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x00248EF4: jal         0x00215A90
    // 0x00248EF8: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_9;
    // 0x00248EF8: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    after_9:
    // 0x00248EFC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00248F00: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x00248F04: jal         0x00215A90
    // 0x00248F08: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_10;
    // 0x00248F08: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    after_10:
    // 0x00248F0C: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
L_00248F10:
    // 0x00248F10: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00248F14: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00248F18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00248F1C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x00248F20: ldc1        $f21, 0x28($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X28);
    // 0x00248F24: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x00248F28: jr          $ra
    // 0x00248F2C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x00248F2C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_00248F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00248F30: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x00248F34: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x00248F38: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00248F3C: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x00248F40: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00248F44: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00248F48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x00248F4C: sw          $ra, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r31;
    // 0x00248F50: sw          $s3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r19;
    // 0x00248F54: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x00248F58: sdc1        $f22, 0x108($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X108, ctx->r29);
    // 0x00248F5C: sdc1        $f21, 0x100($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X100, ctx->r29);
    // 0x00248F60: sdc1        $f20, 0xF8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XF8, ctx->r29);
    // 0x00248F64: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x00248F68: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x00248F6C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00248F70: jal         0x00241C14
    // 0x00248F74: addiu       $s3, $v0, 0x14
    ctx->r19 = ADD32(ctx->r2, 0X14);
    func_00241C14(rdram, ctx);
        goto after_0;
    // 0x00248F74: addiu       $s3, $v0, 0x14
    ctx->r19 = ADD32(ctx->r2, 0X14);
    after_0:
    // 0x00248F78: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00248F7C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00248F80: jal         0x0024176C
    // 0x00248F84: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    func_0024176C(rdram, ctx);
        goto after_1;
    // 0x00248F84: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    after_1:
    // 0x00248F88: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x00248F8C: bne         $v0, $s0, L_00248FC4
    if (ctx->r2 != ctx->r16) {
        // 0x00248F90: nop
    
            goto L_00248FC4;
    }
    // 0x00248F90: nop

    // 0x00248F94: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x00248F98: lb          $v1, 0x198($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X198);
    // 0x00248F9C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x00248FA0: bne         $v1, $v0, L_00248FC0
    if (ctx->r3 != ctx->r2) {
        // 0x00248FA4: nop
    
            goto L_00248FC0;
    }
    // 0x00248FA4: nop

    // 0x00248FA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248FAC: lwc1        $f22, -0x7288($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X7288);
    // 0x00248FB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248FB4: lwc1        $f14, -0x7284($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7284);
    // 0x00248FB8: j           L_00249044
    // 0x00248FBC: nop

        goto L_00249044;
    // 0x00248FBC: nop

L_00248FC0:
    // 0x00248FC0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_00248FC4:
    // 0x00248FC4: bne         $v0, $zero, L_00248FE4
    if (ctx->r2 != 0) {
        // 0x00248FC8: nop
    
            goto L_00248FE4;
    }
    // 0x00248FC8: nop

    // 0x00248FCC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248FD0: lwc1        $f22, -0x7280($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X7280);
    // 0x00248FD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248FD8: lwc1        $f14, -0x727C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X727C);
    // 0x00248FDC: j           L_00249044
    // 0x00248FE0: nop

        goto L_00249044;
    // 0x00248FE0: nop

L_00248FE4:
    // 0x00248FE4: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x00248FE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00248FEC: lwc1        $f12, -0x7278($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7278);
    // 0x00248FF0: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x00248FF4: jal         0x00299758
    // 0x00248FF8: nop

    func_00299758(rdram, ctx);
        goto after_2;
    // 0x00248FF8: nop

    after_2:
    // 0x00248FFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249000: lwc1        $f20, -0x7274($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7274);
    // 0x00249004: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x00249008: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024900C: lwc1        $f1, -0x7270($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7270);
    // 0x00249010: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00249014: lwc1        $f12, 0x3C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x00249018: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x0024901C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249020: lwc1        $f21, -0x726C($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X726C);
    // 0x00249024: mul.s       $f12, $f12, $f21
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f21.fl);
    // 0x00249028: jal         0x00299758
    // 0x0024902C: add.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f0.fl + ctx->f20.fl;
    func_00299758(rdram, ctx);
        goto after_3;
    // 0x0024902C: add.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f0.fl + ctx->f20.fl;
    after_3:
    // 0x00249030: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x00249034: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249038: lwc1        $f1, -0x7268($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7268);
    // 0x0024903C: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x00249040: add.s       $f14, $f0, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f21.fl;
L_00249044:
    // 0x00249044: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249048: lwc1        $f20, -0x7264($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7264);
    // 0x0024904C: lwc1        $f12, 0x160($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X160);
    // 0x00249050: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x00249054: jal         0x00215814
    // 0x00249058: nop

    func_00215814(rdram, ctx);
        goto after_4;
    // 0x00249058: nop

    after_4:
    // 0x0024905C: lwc1        $f12, 0xA8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x00249060: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x00249064: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x00249068: jal         0x00215814
    // 0x0024906C: swc1        $f0, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->f0.u32l;
    func_00215814(rdram, ctx);
        goto after_5;
    // 0x0024906C: swc1        $f0, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->f0.u32l;
    after_5:
    // 0x00249070: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00249074: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00249078: jal         0x00229894
    // 0x0024907C: swc1        $f0, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f0.u32l;
    func_00229894(rdram, ctx);
        goto after_6;
    // 0x0024907C: swc1        $f0, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f0.u32l;
    after_6:
    // 0x00249080: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00249084: jal         0x00229BC4
    // 0x00249088: mov.s       $f21, $f0
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    ctx->f21.fl = ctx->f0.fl;
    func_00229BC4(rdram, ctx);
        goto after_7;
    // 0x00249088: mov.s       $f21, $f0
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    ctx->f21.fl = ctx->f0.fl;
    after_7:
    // 0x0024908C: lwc1        $f1, 0x3C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X3C);
    // 0x00249090: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249094: lwc1        $f12, -0x7260($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7260);
    // 0x00249098: mul.s       $f12, $f1, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f1.fl, ctx->f12.fl);
    // 0x0024909C: jal         0x00299758
    // 0x002490A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_00299758(rdram, ctx);
        goto after_8;
    // 0x002490A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_8:
    // 0x002490A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002490A8: lwc1        $f2, -0x725C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X725C);
    // 0x002490AC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x002490B0: lwc1        $f1, 0x8C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X8C);
    // 0x002490B4: add.s       $f14, $f1, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x002490B8: c.lt.s      $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    c1cs = ctx->f14.fl < ctx->f21.fl;
    // 0x002490BC: nop

    // 0x002490C0: bc1tl       L_002490C8
    if (c1cs) {
        // 0x002490C4: add.s       $f14, $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
            goto L_002490C8;
    }
    goto skip_0;
    // 0x002490C4: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    skip_0:
L_002490C8:
    // 0x002490C8: c.lt.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
    // 0x002490CC: nop

    // 0x002490D0: bc1tl       L_002490D8
    if (c1cs) {
        // 0x002490D4: sub.s       $f14, $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
            goto L_002490D8;
    }
    goto skip_1;
    // 0x002490D4: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    skip_1:
L_002490D8:
    // 0x002490D8: c.lt.s      $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    c1cs = ctx->f14.fl < ctx->f21.fl;
    // 0x002490DC: nop

    // 0x002490E0: bc1f        L_002490F0
    if (!c1cs) {
        // 0x002490E4: nop
    
            goto L_002490F0;
    }
    // 0x002490E4: nop

    // 0x002490E8: j           L_00249100
    // 0x002490EC: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
        goto L_00249100;
    // 0x002490EC: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
L_002490F0:
    // 0x002490F0: c.lt.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
    // 0x002490F4: nop

    // 0x002490F8: bc1tl       L_00249100
    if (c1cs) {
        // 0x002490FC: mov.s       $f14, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
            goto L_00249100;
    }
    goto skip_2;
    // 0x002490FC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    skip_2:
L_00249100:
    // 0x00249100: lwc1        $f12, 0x9C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x00249104: lui         $a2, 0x40A3
    ctx->r6 = S32(0X40A3 << 16);
    // 0x00249108: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x0024910C: jal         0x00215814
    // 0x00249110: nop

    func_00215814(rdram, ctx);
        goto after_9;
    // 0x00249110: nop

    after_9:
    // 0x00249114: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    // 0x00249118: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x0024911C: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x00249120: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x00249124: lwc1        $f12, 0x1C($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x00249128: lwc1        $f14, 0x60($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X60);
    // 0x0024912C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x00249130: jal         0x002156AC
    // 0x00249134: nop

    func_002156AC(rdram, ctx);
        goto after_10;
    // 0x00249134: nop

    after_10:
    // 0x00249138: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024913C: lwc1        $f1, -0x7258($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7258);
    // 0x00249140: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00249144: nop

    // 0x00249148: bc1t        L_00249168
    if (c1cs) {
        // 0x0024914C: swc1        $f0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
            goto L_00249168;
    }
    // 0x0024914C: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x00249150: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249154: lwc1        $f1, -0x7254($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7254);
    // 0x00249158: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x0024915C: nop

    // 0x00249160: bc1f        L_00249170
    if (!c1cs) {
        // 0x00249164: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00249170;
    }
    // 0x00249164: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_00249168:
    // 0x00249168: swc1        $f1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f_odd[(1 - 1) * 2];
    // 0x0024916C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_00249170:
    // 0x00249170: lw          $a2, 0x160($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X160);
    // 0x00249174: lw          $a3, 0x4C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4C);
    // 0x00249178: jal         0x0024197C
    // 0x0024917C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_0024197C(rdram, ctx);
        goto after_11;
    // 0x0024917C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_11:
    // 0x00249180: lwc1        $f1, 0x3C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X3C);
    // 0x00249184: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249188: lwc1        $f0, -0x7250($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7250);
    // 0x0024918C: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00249190: nop

    // 0x00249194: bc1f        L_00249264
    if (!c1cs) {
        // 0x00249198: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_00249264;
    }
    // 0x00249198: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0024919C: lbu         $v1, 0x42($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X42);
    // 0x002491A0: beq         $v1, $v0, L_00249230
    if (ctx->r3 == ctx->r2) {
        // 0x002491A4: nop
    
            goto L_00249230;
    }
    // 0x002491A4: nop

    // 0x002491A8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x002491AC: bne         $v0, $zero, L_00249264
    if (ctx->r2 != 0) {
        // 0x002491B0: nop
    
            goto L_00249264;
    }
    // 0x002491B0: nop

    // 0x002491B4: lwc1        $f1, 0x80($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X80);
    // 0x002491B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002491BC: lwc1        $f0, -0x724C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X724C);
    // 0x002491C0: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x002491C4: nop

    // 0x002491C8: bc1f        L_00249264
    if (!c1cs) {
        // 0x002491CC: nop
    
            goto L_00249264;
    }
    // 0x002491CC: nop

    // 0x002491D0: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x002491D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x002491D8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x002491DC: nop

    // 0x002491E0: bc1f        L_0024920C
    if (!c1cs) {
        // 0x002491E4: nop
    
            goto L_0024920C;
    }
    // 0x002491E4: nop

    // 0x002491E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002491EC: lwc1        $f1, -0x7248($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7248);
    // 0x002491F0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x002491F4: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x002491F8: nop

    // 0x002491FC: bc1t        L_00249224
    if (c1cs) {
        // 0x00249200: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00249224;
    }
    // 0x00249200: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00249204: j           L_00249264
    // 0x00249208: nop

        goto L_00249264;
    // 0x00249208: nop

L_0024920C:
    // 0x0024920C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249210: lwc1        $f0, -0x7244($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7244);
    // 0x00249214: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x00249218: nop

    // 0x0024921C: bc1f        L_00249264
    if (!c1cs) {
        // 0x00249220: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00249264;
    }
    // 0x00249220: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_00249224:
    // 0x00249224: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00249228: j           L_0024925C
    // 0x0024922C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
        goto L_0024925C;
    // 0x0024922C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
L_00249230:
    // 0x00249230: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x00249234: bne         $v0, $zero, L_00249264
    if (ctx->r2 != 0) {
        // 0x00249238: nop
    
            goto L_00249264;
    }
    // 0x00249238: nop

    // 0x0024923C: lwc1        $f1, 0x80($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X80);
    // 0x00249240: lwc1        $f0, 0x34($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X34);
    // 0x00249244: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00249248: nop

    // 0x0024924C: bc1f        L_00249264
    if (!c1cs) {
        // 0x00249250: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00249264;
    }
    // 0x00249250: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00249254: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00249258: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
L_0024925C:
    // 0x0024925C: jal         0x0023E684
    // 0x00249260: nop

    func_0023E684(rdram, ctx);
        goto after_12;
    // 0x00249260: nop

    after_12:
L_00249264:
    // 0x00249264: lw          $ra, 0xF0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF0);
    // 0x00249268: lw          $s3, 0xEC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XEC);
    // 0x0024926C: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x00249270: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x00249274: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x00249278: ldc1        $f22, 0x108($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X108);
    // 0x0024927C: ldc1        $f21, 0x100($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X100);
    // 0x00249280: ldc1        $f20, 0xF8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XF8);
    // 0x00249284: jr          $ra
    // 0x00249288: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x00249288: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_0024928C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024928C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x00249290: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x00249294: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x00249298: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024929C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x002492A0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x002492A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x002492A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002492AC: sdc1        $f21, 0x30($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X30, ctx->r29);
    // 0x002492B0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x002492B4: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x002492B8: lw          $s0, 0x78($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X78);
    // 0x002492BC: beq         $s0, $zero, L_00249384
    if (ctx->r16 == 0) {
        // 0x002492C0: addiu       $s2, $v0, 0x14
        ctx->r18 = ADD32(ctx->r2, 0X14);
            goto L_00249384;
    }
    // 0x002492C0: addiu       $s2, $v0, 0x14
    ctx->r18 = ADD32(ctx->r2, 0X14);
    // 0x002492C4: lbu         $v1, 0x42($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X42);
    // 0x002492C8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x002492CC: beq         $v1, $v0, L_0024938C
    if (ctx->r3 == ctx->r2) {
        // 0x002492D0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_0024938C;
    }
    // 0x002492D0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x002492D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002492D8: lwc1        $f12, -0x7240($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7240);
    // 0x002492DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002492E0: lwc1        $f14, -0x723C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X723C);
    // 0x002492E4: jal         0x00215A90
    // 0x002492E8: nop

    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x002492E8: nop

    after_0:
    // 0x002492EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002492F0: lwc1        $f12, -0x7238($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7238);
    // 0x002492F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002492F8: lwc1        $f1, -0x7234($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7234);
    // 0x002492FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249300: lwc1        $f14, -0x7230($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7230);
    // 0x00249304: jal         0x00215A90
    // 0x00249308: add.s       $f21, $f0, $f1
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f21.fl = ctx->f0.fl + ctx->f1.fl;
    func_00215A90(rdram, ctx);
        goto after_1;
    // 0x00249308: add.s       $f21, $f0, $f1
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f21.fl = ctx->f0.fl + ctx->f1.fl;
    after_1:
    // 0x0024930C: lwc1        $f20, 0x70($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X70);
    // 0x00249310: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249314: lwc1        $f1, -0x722C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X722C);
    // 0x00249318: add.s       $f20, $f20, $f1
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f1.fl;
    // 0x0024931C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x00249320: jal         0x0029A570
    // 0x00249324: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_0029A570(rdram, ctx);
        goto after_2;
    // 0x00249324: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x00249328: mul.s       $f0, $f21, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f21.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f21.fl, ctx->f0.fl);
    // 0x0024932C: lwc1        $f1, 0x4($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X4);
    // 0x00249330: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249334: lwc1        $f12, -0x7228($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7228);
    // 0x00249338: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x0024933C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249340: lwc1        $f14, -0x7224($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7224);
    // 0x00249344: jal         0x00215A90
    // 0x00249348: swc1        $f1, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    func_00215A90(rdram, ctx);
        goto after_3;
    // 0x00249348: swc1        $f1, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    after_3:
    // 0x0024934C: lwc1        $f1, 0x9C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X9C);
    // 0x00249350: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x00249354: add.s       $f1, $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f2.fl;
    // 0x00249358: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024935C: lwc1        $f2, -0x7220($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7220);
    // 0x00249360: mul.s       $f1, $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f2.fl);
    // 0x00249364: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00249368: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x0024936C: jal         0x00299758
    // 0x00249370: swc1        $f1, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    func_00299758(rdram, ctx);
        goto after_4;
    // 0x00249370: swc1        $f1, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    after_4:
    // 0x00249374: mul.s       $f21, $f21, $f0
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f21.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f21.fl = MUL_S(ctx->f21.fl, ctx->f0.fl);
    // 0x00249378: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x0024937C: add.s       $f0, $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f21.fl;
    // 0x00249380: swc1        $f0, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->f0.u32l;
L_00249384:
    // 0x00249384: lbu         $v1, 0x42($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X42);
    // 0x00249388: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_0024938C:
    // 0x0024938C: bne         $v1, $v0, L_002493A0
    if (ctx->r3 != ctx->r2) {
        // 0x00249390: addiu       $v0, $zero, 0x19
        ctx->r2 = ADD32(0, 0X19);
            goto L_002493A0;
    }
    // 0x00249390: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x00249394: lb          $v1, 0x32($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X32);
    // 0x00249398: bne         $v1, $v0, L_002493BC
    if (ctx->r3 != ctx->r2) {
        // 0x0024939C: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_002493BC;
    }
    // 0x0024939C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_002493A0:
    // 0x002493A0: lbu         $v1, 0x42($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X42);
    // 0x002493A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x002493A8: bne         $v1, $v0, L_002493C8
    if (ctx->r3 != ctx->r2) {
        // 0x002493AC: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_002493C8;
    }
    // 0x002493AC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x002493B0: lb          $v1, 0x32($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X32);
    // 0x002493B4: beq         $v1, $v0, L_002493C8
    if (ctx->r3 == ctx->r2) {
        // 0x002493B8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_002493C8;
    }
    // 0x002493B8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_002493BC:
    // 0x002493BC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x002493C0: jal         0x0023E684
    // 0x002493C4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_0023E684(rdram, ctx);
        goto after_5;
    // 0x002493C4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_5:
L_002493C8:
    // 0x002493C8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x002493CC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x002493D0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x002493D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x002493D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002493DC: ldc1        $f21, 0x30($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X30);
    // 0x002493E0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x002493E4: jr          $ra
    // 0x002493E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x002493E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_002493EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002493EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x002493F0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x002493F4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x002493F8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x002493FC: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x00249400: addiu       $s1, $s1, -0x5AA0
    ctx->r17 = ADD32(ctx->r17, -0X5AA0);
    // 0x00249404: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x00249408: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x0024940C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x00249410: beq         $v0, $zero, L_00249430
    if (ctx->r2 == 0) {
        // 0x00249414: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_00249430;
    }
    // 0x00249414: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00249418: lw          $t0, 0x88($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X88);
    // 0x0024941C: lw          $t1, 0x8C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8C);
    // 0x00249420: lw          $t2, 0x90($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X90);
    // 0x00249424: sw          $t0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r8;
    // 0x00249428: sw          $t1, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r9;
    // 0x0024942C: sw          $t2, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r10;
L_00249430:
    // 0x00249430: lw          $a0, -0x98($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X98);
    // 0x00249434: beq         $a0, $zero, L_00249494
    if (ctx->r4 == 0) {
        // 0x00249438: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_00249494;
    }
    // 0x00249438: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x0024943C: lb          $v1, 0x30($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X30);
    // 0x00249440: bne         $v1, $v0, L_00249494
    if (ctx->r3 != ctx->r2) {
        // 0x00249444: nop
    
            goto L_00249494;
    }
    // 0x00249444: nop

    // 0x00249448: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x0024944C: bne         $a0, $v0, L_00249494
    if (ctx->r4 != ctx->r2) {
        // 0x00249450: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_00249494;
    }
    // 0x00249450: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x00249454: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x00249458: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x0024945C: lui         $a3, 0x41CC
    ctx->r7 = S32(0X41CC << 16);
    // 0x00249460: ori         $a3, $a3, 0xCCCC
    ctx->r7 = ctx->r7 | 0XCCCC;
    // 0x00249464: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x00249468: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x0024946C: jal         0x00241518
    // 0x00249470: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_00241518(rdram, ctx);
        goto after_0;
    // 0x00249470: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x00249474: lw          $a0, -0x98($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X98);
    // 0x00249478: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x0024947C: jal         0x00241F34
    // 0x00249480: addiu       $a1, $a0, 0x168
    ctx->r5 = ADD32(ctx->r4, 0X168);
    func_00241F34(rdram, ctx);
        goto after_1;
    // 0x00249480: addiu       $a1, $a0, 0x168
    ctx->r5 = ADD32(ctx->r4, 0X168);
    after_1:
    // 0x00249484: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00249488: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024948C: jal         0x0023E684
    // 0x00249490: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_0023E684(rdram, ctx);
        goto after_2;
    // 0x00249490: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
L_00249494:
    // 0x00249494: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x00249498: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x0024949C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x002494A0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x002494A4: jr          $ra
    // 0x002494A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x002494A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_002494AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002494AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x002494B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002494B4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x002494B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002494BC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x002494C0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x002494C4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x002494C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002494CC: lwc1        $f14, -0x721C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X721C);
    // 0x002494D0: lui         $v0, 0x25
    ctx->r2 = S32(0X25 << 16);
    // 0x002494D4: addiu       $v0, $v0, -0x6C14
    ctx->r2 = ADD32(ctx->r2, -0X6C14);
    // 0x002494D8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x002494DC: sw          $v0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->r2;
    // 0x002494E0: jal         0x00215A90
    // 0x002494E4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x002494E4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x002494E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002494EC: lwc1        $f1, -0x7218($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7218);
    // 0x002494F0: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x002494F4: swc1        $f20, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f20.u32l;
    // 0x002494F8: swc1        $f1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
    // 0x002494FC: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x00249500: swc1        $f20, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f20.u32l;
    // 0x00249504: swc1        $f0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f0.u32l;
    // 0x00249508: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x0024950C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00249510: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00249514: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x00249518: jr          $ra
    // 0x0024951C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x0024951C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_00249520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00249520: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x00249524: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x00249528: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x0024952C: sw          $ra, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r31;
    // 0x00249530: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x00249534: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x00249538: sdc1        $f20, 0xF0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XF0, ctx->r29);
    // 0x0024953C: lwc1        $f12, 0x160($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X160);
    // 0x00249540: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249544: lwc1        $f20, -0x7214($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7214);
    // 0x00249548: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024954C: lwc1        $f14, -0x7210($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7210);
    // 0x00249550: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x00249554: jal         0x00215814
    // 0x00249558: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    func_00215814(rdram, ctx);
        goto after_0;
    // 0x00249558: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    after_0:
    // 0x0024955C: lwc1        $f12, 0xA8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x00249560: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249564: lwc1        $f14, -0x720C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X720C);
    // 0x00249568: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x0024956C: jal         0x00215814
    // 0x00249570: swc1        $f0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f0.u32l;
    func_00215814(rdram, ctx);
        goto after_1;
    // 0x00249570: swc1        $f0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x00249574: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00249578: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024957C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00249580: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x00249584: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x00249588: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    // 0x0024958C: jal         0x00241C14
    // 0x00249590: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_2;
    // 0x00249590: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x00249594: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00249598: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024959C: jal         0x0024176C
    // 0x002495A0: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    func_0024176C(rdram, ctx);
        goto after_3;
    // 0x002495A0: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    after_3:
    // 0x002495A4: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x002495A8: addiu       $s2, $sp, 0x18
    ctx->r18 = ADD32(ctx->r29, 0X18);
    // 0x002495AC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x002495B0: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x002495B4: lwc1        $f14, 0x60($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X60);
    // 0x002495B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x002495BC: jal         0x002156AC
    // 0x002495C0: nop

    func_002156AC(rdram, ctx);
        goto after_4;
    // 0x002495C0: nop

    after_4:
    // 0x002495C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002495C8: lwc1        $f1, -0x7208($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7208);
    // 0x002495CC: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x002495D0: nop

    // 0x002495D4: bc1t        L_002495F4
    if (c1cs) {
        // 0x002495D8: swc1        $f0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
            goto L_002495F4;
    }
    // 0x002495D8: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x002495DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002495E0: lwc1        $f1, -0x7204($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7204);
    // 0x002495E4: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x002495E8: nop

    // 0x002495EC: bc1f        L_002495FC
    if (!c1cs) {
        // 0x002495F0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_002495FC;
    }
    // 0x002495F0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_002495F4:
    // 0x002495F4: swc1        $f1, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    // 0x002495F8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_002495FC:
    // 0x002495FC: lw          $a2, 0x160($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X160);
    // 0x00249600: lw          $a3, 0x4C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4C);
    // 0x00249604: jal         0x0024197C
    // 0x00249608: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0024197C(rdram, ctx);
        goto after_5;
    // 0x00249608: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x0024960C: lwc1        $f2, 0x3C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x00249610: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249614: lwc1        $f0, -0x7200($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7200);
    // 0x00249618: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x0024961C: nop

    // 0x00249620: bc1f        L_00249668
    if (!c1cs) {
        // 0x00249624: nop
    
            goto L_00249668;
    }
    // 0x00249624: nop

    // 0x00249628: lwc1        $f1, 0x9C($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X9C);
    // 0x0024962C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249630: lwc1        $f0, -0x71FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71FC);
    // 0x00249634: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00249638: nop

    // 0x0024963C: bc1t        L_0024965C
    if (c1cs) {
        // 0x00249640: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_0024965C;
    }
    // 0x00249640: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00249644: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249648: lwc1        $f0, -0x71F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71F8);
    // 0x0024964C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x00249650: nop

    // 0x00249654: bc1f        L_00249668
    if (!c1cs) {
        // 0x00249658: nop
    
            goto L_00249668;
    }
    // 0x00249658: nop

L_0024965C:
    // 0x0024965C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00249660: jal         0x0023E684
    // 0x00249664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0023E684(rdram, ctx);
        goto after_6;
    // 0x00249664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
L_00249668:
    // 0x00249668: lw          $ra, 0xEC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XEC);
    // 0x0024966C: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x00249670: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x00249674: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x00249678: ldc1        $f20, 0xF0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XF0);
    // 0x0024967C: jr          $ra
    // 0x00249680: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x00249680: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_00249684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00249684: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x00249688: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024968C: lwc1        $f14, -0x71F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X71F4);
    // 0x00249690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00249694: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00249698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x0024969C: jal         0x00215A90
    // 0x002496A0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x002496A0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x002496A4: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
    // 0x002496A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x002496AC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002496B0: jr          $ra
    // 0x002496B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x002496B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_002496B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002496B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x002496BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002496C0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x002496C4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x002496C8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002496CC: lwc1        $f12, 0xA8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x002496D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002496D4: lwc1        $f14, -0x71F0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X71F0);
    // 0x002496D8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x002496DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x002496E0: jal         0x00215814
    // 0x002496E4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    func_00215814(rdram, ctx);
        goto after_0;
    // 0x002496E4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    after_0:
    // 0x002496E8: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    // 0x002496EC: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x002496F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x002496F4: lui         $a2, 0x3F83
    ctx->r6 = S32(0X3F83 << 16);
    // 0x002496F8: ori         $a2, $a2, 0x126F
    ctx->r6 = ctx->r6 | 0X126F;
    // 0x002496FC: jal         0x00215814
    // 0x00249700: nop

    func_00215814(rdram, ctx);
        goto after_1;
    // 0x00249700: nop

    after_1:
    // 0x00249704: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x00249708: lwc1        $f1, 0x3C($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X3C);
    // 0x0024970C: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x00249710: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00249714: nop

    // 0x00249718: bc1f        L_0024972C
    if (!c1cs) {
        // 0x0024971C: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_0024972C;
    }
    // 0x0024971C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x00249720: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00249724: jal         0x0023E684
    // 0x00249728: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0023E684(rdram, ctx);
        goto after_2;
    // 0x00249728: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_0024972C:
    // 0x0024972C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00249730: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00249734: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00249738: jr          $ra
    // 0x0024973C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0024973C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00249740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00249740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00249744: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00249748: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x0024974C: lui         $v1, 0xFEFF
    ctx->r3 = S32(0XFEFF << 16);
    // 0x00249750: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00249754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00249758: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x0024975C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249760: lwc1        $f12, -0x71EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X71EC);
    // 0x00249764: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249768: lwc1        $f14, -0x71E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X71E8);
    // 0x0024976C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249770: jal         0x00215A90
    // 0x00249774: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x00249774: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    after_0:
    // 0x00249778: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
    // 0x0024977C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x00249780: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00249784: jr          $ra
    // 0x00249788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00249788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024978C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024978C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x00249790: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00249794: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00249798: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024979C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002497A0: lwc1        $f12, 0xA8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x002497A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002497A8: lwc1        $f14, -0x71E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X71E4);
    // 0x002497AC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x002497B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x002497B4: jal         0x00215814
    // 0x002497B8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_00215814(rdram, ctx);
        goto after_0;
    // 0x002497B8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x002497BC: swc1        $f0, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f0.u32l;
    // 0x002497C0: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x002497C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x002497C8: lui         $a2, 0x3F83
    ctx->r6 = S32(0X3F83 << 16);
    // 0x002497CC: ori         $a2, $a2, 0x126F
    ctx->r6 = ctx->r6 | 0X126F;
    // 0x002497D0: jal         0x00215814
    // 0x002497D4: nop

    func_00215814(rdram, ctx);
        goto after_1;
    // 0x002497D4: nop

    after_1:
    // 0x002497D8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x002497DC: lwc1        $f1, 0x3C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X3C);
    // 0x002497E0: lwc1        $f0, 0x60($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X60);
    // 0x002497E4: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x002497E8: nop

    // 0x002497EC: bc1f        L_00249810
    if (!c1cs) {
        // 0x002497F0: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_00249810;
    }
    // 0x002497F0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x002497F4: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x002497F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x002497FC: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x00249800: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00249804: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x00249808: jal         0x0023E684
    // 0x0024980C: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
    func_0023E684(rdram, ctx);
        goto after_2;
    // 0x0024980C: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
    after_2:
L_00249810:
    // 0x00249810: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x00249814: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00249818: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024981C: jr          $ra
    // 0x00249820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x00249820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00249824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00249824: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x00249828: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x0024982C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00249830: sw          $ra, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r31;
    // 0x00249834: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x00249838: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x0024983C: lwc1        $f12, 0xA8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x00249840: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249844: lwc1        $f14, -0x71E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X71E0);
    // 0x00249848: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x0024984C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x00249850: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00249854: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x00249858: jal         0x00215814
    // 0x0024985C: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    func_00215814(rdram, ctx);
        goto after_0;
    // 0x0024985C: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    after_0:
    // 0x00249860: lwc1        $f12, 0x160($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X160);
    // 0x00249864: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249868: lwc1        $f14, -0x71DC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X71DC);
    // 0x0024986C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x00249870: jal         0x00215814
    // 0x00249874: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    func_00215814(rdram, ctx);
        goto after_1;
    // 0x00249874: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x00249878: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024987C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00249880: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00249884: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x00249888: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x0024988C: swc1        $f0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f0.u32l;
    // 0x00249890: jal         0x00241C14
    // 0x00249894: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_2;
    // 0x00249894: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x00249898: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024989C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x002498A0: jal         0x0024176C
    // 0x002498A4: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    func_0024176C(rdram, ctx);
        goto after_3;
    // 0x002498A4: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    after_3:
    // 0x002498A8: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x002498AC: addiu       $s2, $sp, 0x18
    ctx->r18 = ADD32(ctx->r29, 0X18);
    // 0x002498B0: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x002498B4: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x002498B8: lwc1        $f14, 0x60($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X60);
    // 0x002498BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x002498C0: jal         0x002156AC
    // 0x002498C4: nop

    func_002156AC(rdram, ctx);
        goto after_4;
    // 0x002498C4: nop

    after_4:
    // 0x002498C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002498CC: lwc1        $f1, -0x71D8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X71D8);
    // 0x002498D0: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x002498D4: nop

    // 0x002498D8: bc1t        L_002498F8
    if (c1cs) {
        // 0x002498DC: swc1        $f0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
            goto L_002498F8;
    }
    // 0x002498DC: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x002498E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x002498E4: lwc1        $f1, -0x71D4($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X71D4);
    // 0x002498E8: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x002498EC: nop

    // 0x002498F0: bc1f        L_00249900
    if (!c1cs) {
        // 0x002498F4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00249900;
    }
    // 0x002498F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_002498F8:
    // 0x002498F8: swc1        $f1, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    // 0x002498FC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_00249900:
    // 0x00249900: lw          $a2, 0x160($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X160);
    // 0x00249904: lw          $a3, 0x4C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4C);
    // 0x00249908: jal         0x0024197C
    // 0x0024990C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0024197C(rdram, ctx);
        goto after_5;
    // 0x0024990C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x00249910: lw          $ra, 0xEC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XEC);
    // 0x00249914: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x00249918: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x0024991C: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x00249920: jr          $ra
    // 0x00249924: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x00249924: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_00249928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00249928: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0024992C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00249930: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00249934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x00249938: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x0024993C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00249940: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x00249944: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x00249948: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x0024994C: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x00249950: lwc1        $f14, 0x60($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X60);
    // 0x00249954: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x00249958: jal         0x002156AC
    // 0x0024995C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    func_002156AC(rdram, ctx);
        goto after_0;
    // 0x0024995C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    after_0:
    // 0x00249960: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249964: lwc1        $f1, -0x71D0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X71D0);
    // 0x00249968: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x0024996C: nop

    // 0x00249970: bc1t        L_00249990
    if (c1cs) {
        // 0x00249974: swc1        $f0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
            goto L_00249990;
    }
    // 0x00249974: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x00249978: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024997C: lwc1        $f1, -0x71CC($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X71CC);
    // 0x00249980: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00249984: nop

    // 0x00249988: bc1f        L_00249998
    if (!c1cs) {
        // 0x0024998C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00249998;
    }
    // 0x0024998C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_00249990:
    // 0x00249990: swc1        $f1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
    // 0x00249994: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_00249998:
    // 0x00249998: lw          $a2, 0x160($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X160);
    // 0x0024999C: lw          $a3, 0x4C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4C);
    // 0x002499A0: jal         0x0024197C
    // 0x002499A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_0024197C(rdram, ctx);
        goto after_1;
    // 0x002499A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x002499A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x002499AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x002499B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x002499B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x002499B8: jr          $ra
    // 0x002499BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x002499BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_002499C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x002499C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x002499C4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x002499C8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x002499CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x002499D0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x002499D4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x002499D8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x002499DC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x002499E0: sdc1        $f21, 0x30($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X30, ctx->r29);
    // 0x002499E4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x002499E8: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x002499EC: lb          $s3, 0x33($s0)
    ctx->r19 = MEM_B(ctx->r16, 0X33);
    // 0x002499F0: addiu       $s1, $v0, 0x14
    ctx->r17 = ADD32(ctx->r2, 0X14);
    // 0x002499F4: sltiu       $v0, $s3, 0x5
    ctx->r2 = ctx->r19 < 0X5 ? 1 : 0;
    // 0x002499F8: beq         $v0, $zero, L_00249D4C
    if (ctx->r2 == 0) {
        // 0x002499FC: sll         $v0, $s3, 2
        ctx->r2 = S32(ctx->r19 << 2);
            goto L_00249D4C;
    }
    // 0x002499FC: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x00249A00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249A04: addu        $at, $at, $v0
    gpr jr_addend_00249A0C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x00249A08: lw          $v0, -0x71C8($at)
    ctx->r2 = ADD32(ctx->r1, -0X71C8);
    // 0x00249A0C: jr          $v0
    // 0x00249A10: nop

    switch (jr_addend_00249A0C >> 2) {
        case 0: goto L_00249A14; break;
        case 1: goto L_00249B7C; break;
        case 2: goto L_00249C44; break;
        case 3: goto L_00249ADC; break;
        case 4: goto L_00249CBC; break;
        default: switch_error(__func__, 0x00249A0C, 0x800A8E38);
    }
    // 0x00249A10: nop

L_00249A14:
    // 0x00249A14: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x00249A18: lui         $v0, 0xC0
    ctx->r2 = S32(0XC0 << 16);
    // 0x00249A1C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00249A20: beq         $v0, $zero, L_00249D4C
    if (ctx->r2 == 0) {
        // 0x00249A24: lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
            goto L_00249D4C;
    }
    // 0x00249A24: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x00249A28: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00249A2C: beq         $v0, $zero, L_00249A58
    if (ctx->r2 == 0) {
        // 0x00249A30: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_00249A58;
    }
    // 0x00249A30: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x00249A34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00249A38: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249A3C: beql        $v0, $zero, L_00249D4C
    if (ctx->r2 == 0) {
        // 0x00249A40: sw          $zero, 0x154($s0)
        MEM_W(0X154, ctx->r16) = 0;
            goto L_00249D4C;
    }
    goto skip_0;
    // 0x00249A40: sw          $zero, 0x154($s0)
    MEM_W(0X154, ctx->r16) = 0;
    skip_0:
    // 0x00249A44: lwc1        $f0, 0x154($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X154);
    // 0x00249A48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249A4C: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00249A50: j           L_00249A8C
    // 0x00249A54: add.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl + ctx->f0.fl;
        goto L_00249A8C;
    // 0x00249A54: add.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl + ctx->f0.fl;
L_00249A58:
    // 0x00249A58: lwc1        $f1, 0x154($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X154);
    // 0x00249A5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00249A60: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00249A64: nop

    // 0x00249A68: bc1t        L_00249A80
    if (c1cs) {
        // 0x00249A6C: nop
    
            goto L_00249A80;
    }
    // 0x00249A6C: nop

    // 0x00249A70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00249A74: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x00249A78: beq         $v0, $zero, L_00249A94
    if (ctx->r2 == 0) {
        // 0x00249A7C: nop
    
            goto L_00249A94;
    }
    // 0x00249A7C: nop

L_00249A80:
    // 0x00249A80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249A84: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x00249A88: add.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl + ctx->f0.fl;
L_00249A8C:
    // 0x00249A8C: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    // 0x00249A90: lwc1        $f1, 0x154($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X154);
L_00249A94:
    // 0x00249A94: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x00249A98: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x00249A9C: nop

    // 0x00249AA0: bc1f        L_00249D4C
    if (!c1cs) {
        // 0x00249AA4: lui         $v0, 0x100
        ctx->r2 = S32(0X100 << 16);
            goto L_00249D4C;
    }
    // 0x00249AA4: lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // 0x00249AA8: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x00249AAC: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x00249AB0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00249AB4: beq         $v0, $zero, L_00249AC4
    if (ctx->r2 == 0) {
        // 0x00249AB8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_00249AC4;
    }
    // 0x00249AB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00249ABC: j           L_00249D4C
    // 0x00249AC0: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
        goto L_00249D4C;
    // 0x00249AC0: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
L_00249AC4:
    // 0x00249AC4: lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // 0x00249AC8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00249ACC: bne         $v0, $zero, L_00249B5C
    if (ctx->r2 != 0) {
        // 0x00249AD0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00249B5C;
    }
    // 0x00249AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00249AD4: j           L_00249B68
    // 0x00249AD8: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
        goto L_00249B68;
    // 0x00249AD8: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
L_00249ADC:
    // 0x00249ADC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249AE0: lwc1        $f20, -0x71B4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X71B4);
    // 0x00249AE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249AE8: lwc1        $f21, -0x71B0($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X71B0);
    // 0x00249AEC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00249AF0: jal         0x00215A90
    // 0x00249AF4: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x00249AF4: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    after_0:
    // 0x00249AF8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00249AFC: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x00249B00: jal         0x00215A90
    // 0x00249B04: swc1        $f0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_1;
    // 0x00249B04: swc1        $f0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x00249B08: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x00249B0C: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x00249B10: jal         0x00215A90
    // 0x00249B14: swc1        $f0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f0.u32l;
    func_00215A90(rdram, ctx);
        goto after_2;
    // 0x00249B14: swc1        $f0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x00249B18: lwc1        $f2, 0x40($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X40);
    // 0x00249B1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249B20: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x00249B24: add.s       $f2, $f2, $f1
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f1.fl;
    // 0x00249B28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249B2C: lwc1        $f1, -0x71AC($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X71AC);
    // 0x00249B30: swc1        $f0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f0.u32l;
    // 0x00249B34: c.lt.s      $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f1.fl < ctx->f2.fl;
    // 0x00249B38: nop

    // 0x00249B3C: bc1f        L_00249D4C
    if (!c1cs) {
        // 0x00249B40: swc1        $f2, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
            goto L_00249D4C;
    }
    // 0x00249B40: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    // 0x00249B44: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x00249B48: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x00249B4C: lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // 0x00249B50: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00249B54: beq         $v0, $zero, L_00249B64
    if (ctx->r2 == 0) {
        // 0x00249B58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00249B64;
    }
    // 0x00249B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_00249B5C:
    // 0x00249B5C: j           L_00249D4C
    // 0x00249B60: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
        goto L_00249D4C;
    // 0x00249B60: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
L_00249B64:
    // 0x00249B64: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
L_00249B68:
    // 0x00249B68: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x00249B6C: beq         $v0, $zero, L_00249D4C
    if (ctx->r2 == 0) {
        // 0x00249B70: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_00249D4C;
    }
    // 0x00249B70: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x00249B74: j           L_00249D4C
    // 0x00249B78: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
        goto L_00249D4C;
    // 0x00249B78: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
L_00249B7C:
    // 0x00249B7C: lwc1        $f1, 0x40($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X40);
    // 0x00249B80: lwc1        $f0, 0x5C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x00249B84: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00249B88: nop

    // 0x00249B8C: bc1f        L_00249BA8
    if (!c1cs) {
        // 0x00249B90: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_00249BA8;
    }
    // 0x00249B90: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x00249B94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249B98: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x00249B9C: add.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00249BA0: j           L_00249C24
    // 0x00249BA4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
        goto L_00249C24;
    // 0x00249BA4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_00249BA8:
    // 0x00249BA8: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x00249BAC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249BB0: beq         $v0, $zero, L_00249BCC
    if (ctx->r2 == 0) {
        // 0x00249BB4: lui         $v1, 0xFFEF
        ctx->r3 = S32(0XFFEF << 16);
            goto L_00249BCC;
    }
    // 0x00249BB4: lui         $v1, 0xFFEF
    ctx->r3 = S32(0XFFEF << 16);
    // 0x00249BB8: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x00249BBC: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00249BC0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249BC4: j           L_00249C24
    // 0x00249BC8: sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
        goto L_00249C24;
    // 0x00249BC8: sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
L_00249BCC:
    // 0x00249BCC: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x00249BD0: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x00249BD4: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x00249BD8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249BDC: beq         $v0, $zero, L_00249BF4
    if (ctx->r2 == 0) {
        // 0x00249BE0: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_00249BF4;
    }
    // 0x00249BE0: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x00249BE4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00249BE8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249BEC: beq         $v0, $zero, L_00249C18
    if (ctx->r2 == 0) {
        // 0x00249BF0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00249C18;
    }
    // 0x00249BF0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_00249BF4:
    // 0x00249BF4: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x00249BF8: lui         $v1, 0x1000
    ctx->r3 = S32(0X1000 << 16);
    // 0x00249BFC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249C00: beq         $v0, $zero, L_00249C18
    if (ctx->r2 == 0) {
        // 0x00249C04: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_00249C18;
    }
    // 0x00249C04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x00249C08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00249C0C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x00249C10: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249C14: sltu        $a0, $v0, $a0
    ctx->r4 = ctx->r2 < ctx->r4 ? 1 : 0;
L_00249C18:
    // 0x00249C18: beq         $a0, $zero, L_00249C24
    if (ctx->r4 == 0) {
        // 0x00249C1C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00249C24;
    }
    // 0x00249C1C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00249C20: sb          $v0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r2;
L_00249C24:
    // 0x00249C24: lwc1        $f1, 0x5C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X5C);
    // 0x00249C28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00249C2C: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00249C30: nop

    // 0x00249C34: bc1f        L_00249CAC
    if (!c1cs) {
        // 0x00249C38: nop
    
            goto L_00249CAC;
    }
    // 0x00249C38: nop

    // 0x00249C3C: j           L_00249C8C
    // 0x00249C40: nop

        goto L_00249C8C;
    // 0x00249C40: nop

L_00249C44:
    // 0x00249C44: lwc1        $f1, 0x40($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X40);
    // 0x00249C48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00249C4C: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00249C50: nop

    // 0x00249C54: bc1fl       L_00249C70
    if (!c1cs) {
        // 0x00249C58: sb          $zero, 0x33($s0)
        MEM_B(0X33, ctx->r16) = 0;
            goto L_00249C70;
    }
    goto skip_1;
    // 0x00249C58: sb          $zero, 0x33($s0)
    MEM_B(0X33, ctx->r16) = 0;
    skip_1:
    // 0x00249C5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249C60: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x00249C64: sub.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x00249C68: j           L_00249C74
    // 0x00249C6C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
        goto L_00249C74;
    // 0x00249C6C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_00249C70:
    // 0x00249C70: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
L_00249C74:
    // 0x00249C74: lwc1        $f1, 0x5C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X5C);
    // 0x00249C78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00249C7C: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00249C80: nop

    // 0x00249C84: bc1f        L_00249CAC
    if (!c1cs) {
        // 0x00249C88: nop
    
            goto L_00249CAC;
    }
    // 0x00249C88: nop

L_00249C8C:
    // 0x00249C8C: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    // 0x00249C90: jal         0x0026AB94
    // 0x00249C94: div.s       $f12, $f12, $f1
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f1.fl);
    func_0026AB94(rdram, ctx);
        goto after_3;
    // 0x00249C94: div.s       $f12, $f12, $f1
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f1.fl);
    after_3:
    // 0x00249C98: lwc1        $f1, 0x58($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X58);
    // 0x00249C9C: neg.s       $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = -ctx->f1.fl;
    // 0x00249CA0: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00249CA4: j           L_00249D4C
    // 0x00249CA8: swc1        $f1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
        goto L_00249D4C;
    // 0x00249CA8: swc1        $f1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
L_00249CAC:
    // 0x00249CAC: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
    // 0x00249CB0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x00249CB4: j           L_00249D4C
    // 0x00249CB8: swc1        $f0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f0.u32l;
        goto L_00249D4C;
    // 0x00249CB8: swc1        $f0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f0.u32l;
L_00249CBC:
    // 0x00249CBC: lwc1        $f1, 0x40($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X40);
    // 0x00249CC0: lwc1        $f0, 0x5C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x00249CC4: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x00249CC8: nop

    // 0x00249CCC: bc1f        L_00249CE4
    if (!c1cs) {
        // 0x00249CD0: nop
    
            goto L_00249CE4;
    }
    // 0x00249CD0: nop

    // 0x00249CD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249CD8: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x00249CDC: add.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00249CE0: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_00249CE4:
    // 0x00249CE4: lwc1        $f1, 0x5C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X5C);
    // 0x00249CE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00249CEC: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x00249CF0: nop

    // 0x00249CF4: bc1f        L_00249D1C
    if (!c1cs) {
        // 0x00249CF8: nop
    
            goto L_00249D1C;
    }
    // 0x00249CF8: nop

    // 0x00249CFC: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    // 0x00249D00: jal         0x0026AB94
    // 0x00249D04: div.s       $f12, $f12, $f1
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f1.fl);
    func_0026AB94(rdram, ctx);
        goto after_4;
    // 0x00249D04: div.s       $f12, $f12, $f1
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f1.fl);
    after_4:
    // 0x00249D08: lwc1        $f1, 0x58($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X58);
    // 0x00249D0C: neg.s       $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = -ctx->f1.fl;
    // 0x00249D10: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00249D14: j           L_00249D28
    // 0x00249D18: swc1        $f1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
        goto L_00249D28;
    // 0x00249D18: swc1        $f1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f_odd[(1 - 1) * 2];
L_00249D1C:
    // 0x00249D1C: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
    // 0x00249D20: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x00249D24: swc1        $f0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f0.u32l;
L_00249D28:
    // 0x00249D28: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x00249D2C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x00249D30: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249D34: beq         $v0, $zero, L_00249D4C
    if (ctx->r2 == 0) {
        // 0x00249D38: lui         $v1, 0xFFEF
        ctx->r3 = S32(0XFFEF << 16);
            goto L_00249D4C;
    }
    // 0x00249D38: lui         $v1, 0xFFEF
    ctx->r3 = S32(0XFFEF << 16);
    // 0x00249D3C: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x00249D40: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x00249D44: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00249D48: sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
L_00249D4C:
    // 0x00249D4C: lb          $v0, 0x33($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X33);
    // 0x00249D50: beq         $s3, $v0, L_00249D5C
    if (ctx->r19 == ctx->r2) {
        // 0x00249D54: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_00249D5C;
    }
    // 0x00249D54: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00249D58: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
L_00249D5C:
    // 0x00249D5C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x00249D60: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x00249D64: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00249D68: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00249D6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00249D70: ldc1        $f21, 0x30($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X30);
    // 0x00249D74: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x00249D78: jr          $ra
    // 0x00249D7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x00249D7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_00249D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00249D80: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x00249D84: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x00249D88: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00249D8C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x00249D90: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00249D94: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x00249D98: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x00249D9C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x00249DA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x00249DA4: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x00249DA8: sdc1        $f21, 0x40($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X40, ctx->r29);
    // 0x00249DAC: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x00249DB0: lwc1        $f22, 0x60($s1)
    ctx->f22.u32l = MEM_W(ctx->r17, 0X60);
    // 0x00249DB4: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x00249DB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x00249DBC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x00249DC0: nop

    // 0x00249DC4: bc1t        L_00249DE4
    if (c1cs) {
        // 0x00249DC8: addiu       $s0, $v0, 0x14
        ctx->r16 = ADD32(ctx->r2, 0X14);
            goto L_00249DE4;
    }
    // 0x00249DC8: addiu       $s0, $v0, 0x14
    ctx->r16 = ADD32(ctx->r2, 0X14);
    // 0x00249DCC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249DD0: lwc1        $f0, -0x71A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X71A8);
    // 0x00249DD4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x00249DD8: nop

    // 0x00249DDC: bc1f        L_00249DE8
    if (!c1cs) {
        // 0x00249DE0: nop
    
            goto L_00249DE8;
    }
    // 0x00249DE0: nop

L_00249DE4:
    // 0x00249DE4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_00249DE8:
    // 0x00249DE8: lbu         $v0, 0x29($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X29);
    // 0x00249DEC: bne         $v0, $zero, L_00249E00
    if (ctx->r2 != 0) {
        // 0x00249DF0: nop
    
            goto L_00249E00;
    }
    // 0x00249DF0: nop

    // 0x00249DF4: jal         0x0026AB94
    // 0x00249DF8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_0026AB94(rdram, ctx);
        goto after_0;
    // 0x00249DF8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x00249DFC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_00249E00:
    // 0x00249E00: lw          $t0, 0x88($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X88);
    // 0x00249E04: lw          $t1, 0x8C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8C);
    // 0x00249E08: lw          $t2, 0x90($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X90);
    // 0x00249E0C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x00249E10: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x00249E14: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x00249E18: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x00249E1C: lwc1        $f1, 0x2C($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X2C);
    // 0x00249E20: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00249E24: addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
    // 0x00249E28: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x00249E2C: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x00249E30: beq         $v0, $zero, L_00249E78
    if (ctx->r2 == 0) {
        // 0x00249E34: addiu       $s3, $s1, 0x88
        ctx->r19 = ADD32(ctx->r17, 0X88);
            goto L_00249E78;
    }
    // 0x00249E34: addiu       $s3, $s1, 0x88
    ctx->r19 = ADD32(ctx->r17, 0X88);
    // 0x00249E38: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x00249E3C: jal         0x0029A570
    // 0x00249E40: nop

    func_0029A570(rdram, ctx);
        goto after_1;
    // 0x00249E40: nop

    after_1:
    // 0x00249E44: lwc1        $f1, 0x30($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X30);
    // 0x00249E48: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00249E4C: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x00249E50: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00249E54: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x00249E58: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x00249E5C: jal         0x00299758
    // 0x00249E60: nop

    func_00299758(rdram, ctx);
        goto after_2;
    // 0x00249E60: nop

    after_2:
    // 0x00249E64: lwc1        $f1, 0x30($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X30);
    // 0x00249E68: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00249E6C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x00249E70: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00249E74: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_00249E78:
    // 0x00249E78: addiu       $a0, $s1, 0x50
    ctx->r4 = ADD32(ctx->r17, 0X50);
    // 0x00249E7C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x00249E80: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x00249E84: jal         0x002130D4
    // 0x00249E88: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_002130D4(rdram, ctx);
        goto after_3;
    // 0x00249E88: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_3:
    // 0x00249E8C: lbu         $v1, 0x28($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X28);
    // 0x00249E90: beq         $v1, $zero, L_00249EA8
    if (ctx->r3 == 0) {
        // 0x00249E94: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00249EA8;
    }
    // 0x00249E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00249E98: beq         $v1, $v0, L_00249EBC
    if (ctx->r3 == ctx->r2) {
        // 0x00249E9C: nop
    
            goto L_00249EBC;
    }
    // 0x00249E9C: nop

    // 0x00249EA0: j           L_00249F60
    // 0x00249EA4: nop

        goto L_00249F60;
    // 0x00249EA4: nop

L_00249EA8:
    // 0x00249EA8: lwc1        $f12, 0x16C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X16C);
    // 0x00249EAC: jal         0x0029A570
    // 0x00249EB0: nop

    func_0029A570(rdram, ctx);
        goto after_4;
    // 0x00249EB0: nop

    after_4:
    // 0x00249EB4: j           L_00249F4C
    // 0x00249EB8: nop

        goto L_00249F4C;
    // 0x00249EB8: nop

L_00249EBC:
    // 0x00249EBC: lwc1        $f20, 0x16C($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X16C);
    // 0x00249EC0: jal         0x0029A570
    // 0x00249EC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_0029A570(rdram, ctx);
        goto after_5;
    // 0x00249EC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_5:
    // 0x00249EC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249ECC: lwc1        $f12, -0x71A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X71A4);
    // 0x00249ED0: mul.s       $f12, $f20, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x00249ED4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249ED8: lwc1        $f21, -0x71A0($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X71A0);
    // 0x00249EDC: mul.s       $f0, $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f21.fl);
    // 0x00249EE0: lwc1        $f1, 0x44($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X44);
    // 0x00249EE4: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00249EE8: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x00249EEC: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00249EF0: jal         0x0029A570
    // 0x00249EF4: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    func_0029A570(rdram, ctx);
        goto after_6;
    // 0x00249EF4: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    after_6:
    // 0x00249EF8: mul.s       $f0, $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f21.fl);
    // 0x00249EFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249F00: lwc1        $f12, -0x719C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X719C);
    // 0x00249F04: mul.s       $f12, $f20, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x00249F08: lwc1        $f1, 0x44($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X44);
    // 0x00249F0C: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00249F10: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x00249F14: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00249F18: jal         0x0029A570
    // 0x00249F1C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    func_0029A570(rdram, ctx);
        goto after_7;
    // 0x00249F1C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    after_7:
    // 0x00249F20: mul.s       $f0, $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f21.fl);
    // 0x00249F24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249F28: lwc1        $f12, -0x7198($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7198);
    // 0x00249F2C: mul.s       $f12, $f20, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x00249F30: lwc1        $f1, 0x44($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X44);
    // 0x00249F34: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00249F38: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x00249F3C: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00249F40: jal         0x0029A570
    // 0x00249F44: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    func_0029A570(rdram, ctx);
        goto after_8;
    // 0x00249F44: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    after_8:
    // 0x00249F48: mul.s       $f0, $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f21.fl);
L_00249F4C:
    // 0x00249F4C: lwc1        $f1, 0x44($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X44);
    // 0x00249F50: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x00249F54: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x00249F58: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x00249F5C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
L_00249F60:
    // 0x00249F60: lwc1        $f3, 0x50($s1)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r17, 0X50);
    // 0x00249F64: lwc1        $f0, 0x158($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X158);
    // 0x00249F68: lwc1        $f2, 0x54($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X54);
    // 0x00249F6C: add.s       $f3, $f3, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f3.fl = ctx->f3.fl + ctx->f0.fl;
    // 0x00249F70: lwc1        $f0, 0x15C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X15C);
    // 0x00249F74: lwc1        $f1, 0x58($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X58);
    // 0x00249F78: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x00249F7C: lwc1        $f0, 0x160($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X160);
    // 0x00249F80: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00249F84: swc1        $f3, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f_odd[(3 - 1) * 2];
    // 0x00249F88: swc1        $f2, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f2.u32l;
    // 0x00249F8C: swc1        $f1, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    // 0x00249F90: lbu         $v1, 0x2A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2A);
    // 0x00249F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00249F98: beq         $v1, $v0, L_00249FE4
    if (ctx->r3 == ctx->r2) {
        // 0x00249F9C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_00249FE4;
    }
    // 0x00249F9C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x00249FA0: beq         $v0, $zero, L_00249FB8
    if (ctx->r2 == 0) {
        // 0x00249FA4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00249FB8;
    }
    // 0x00249FA4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00249FA8: beq         $v1, $zero, L_00249FC8
    if (ctx->r3 == 0) {
        // 0x00249FAC: nop
    
            goto L_00249FC8;
    }
    // 0x00249FAC: nop

    // 0x00249FB0: j           L_0024A010
    // 0x00249FB4: nop

        goto L_0024A010;
    // 0x00249FB4: nop

L_00249FB8:
    // 0x00249FB8: beq         $v1, $v0, L_00249FF4
    if (ctx->r3 == ctx->r2) {
        // 0x00249FBC: nop
    
            goto L_00249FF4;
    }
    // 0x00249FBC: nop

    // 0x00249FC0: j           L_0024A010
    // 0x00249FC4: nop

        goto L_0024A010;
    // 0x00249FC4: nop

L_00249FC8:
    // 0x00249FC8: lwc1        $f1, 0x84($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X84);
    // 0x00249FCC: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x00249FD0: add.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00249FD4: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x00249FD8: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x00249FDC: j           L_0024A00C
    // 0x00249FE0: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
        goto L_0024A00C;
    // 0x00249FE0: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
L_00249FE4:
    // 0x00249FE4: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x00249FE8: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x00249FEC: bne         $v0, $zero, L_0024A010
    if (ctx->r2 != 0) {
        // 0x00249FF0: nop
    
            goto L_0024A010;
    }
    // 0x00249FF0: nop

L_00249FF4:
    // 0x00249FF4: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x00249FF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00249FFC: lwc1        $f1, -0x7194($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7194);
    // 0x0024A000: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x0024A004: lwc1        $f1, 0x70($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X70);
    // 0x0024A008: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
L_0024A00C:
    // 0x0024A00C: swc1        $f1, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f_odd[(1 - 1) * 2];
L_0024A010:
    // 0x0024A010: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x0024A014: bne         $v0, $zero, L_0024A050
    if (ctx->r2 != 0) {
        // 0x0024A018: nop
    
            goto L_0024A050;
    }
    // 0x0024A018: nop

    // 0x0024A01C: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x0024A020: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x0024A024: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x0024A028: jal         0x0026D334
    // 0x0024A02C: nop

    func_0026D334(rdram, ctx);
        goto after_9;
    // 0x0024A02C: nop

    after_9:
    // 0x0024A030: lwc1        $f1, 0x54($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X54);
    // 0x0024A034: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x0024A038: lwc1        $f1, 0x8($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X8);
    // 0x0024A03C: sub.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f1.fl;
    // 0x0024A040: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x0024A044: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x0024A048: jal         0x0026DA98
    // 0x0024A04C: nop

    func_0026DA98(rdram, ctx);
        goto after_10;
    // 0x0024A04C: nop

    after_10:
L_0024A050:
    // 0x0024A050: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x0024A054: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x0024A058: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x0024A05C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x0024A060: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x0024A064: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x0024A068: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x0024A06C: ldc1        $f21, 0x40($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X40);
    // 0x0024A070: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x0024A074: jr          $ra
    // 0x0024A078: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x0024A078: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_0024A07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A07C: jr          $ra
    // 0x0024A080: nop

    return;
    // 0x0024A080: nop

;}
RECOMP_FUNC void func_0024A084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A084: lb          $v1, 0x33($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X33);
    // 0x0024A088: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x0024A08C: beq         $v0, $zero, L_0024A0F8
    if (ctx->r2 == 0) {
        // 0x0024A090: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_0024A0F8;
    }
    // 0x0024A090: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x0024A094: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A098: addu        $at, $at, $v0
    gpr jr_addend_0024A0A0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0024A09C: lw          $v0, -0x7190($at)
    ctx->r2 = ADD32(ctx->r1, -0X7190);
    // 0x0024A0A0: jr          $v0
    // 0x0024A0A4: nop

    switch (jr_addend_0024A0A0 >> 2) {
        case 0: goto L_0024A0B8; break;
        case 1: goto L_0024A0B0; break;
        case 2: goto L_0024A0B0; break;
        case 3: goto L_0024A0A8; break;
        case 4: goto L_0024A108; break;
        default: switch_error(__func__, 0x0024A0A0, 0x800A8E70);
    }
    // 0x0024A0A4: nop

L_0024A0A8:
    // 0x0024A0A8: jr          $ra
    // 0x0024A0AC: addiu       $v0, $zero, 0x5280
    ctx->r2 = ADD32(0, 0X5280);
    return;
    // 0x0024A0AC: addiu       $v0, $zero, 0x5280
    ctx->r2 = ADD32(0, 0X5280);
L_0024A0B0:
    // 0x0024A0B0: jr          $ra
    // 0x0024A0B4: addiu       $v0, $zero, 0x5294
    ctx->r2 = ADD32(0, 0X5294);
    return;
    // 0x0024A0B4: addiu       $v0, $zero, 0x5294
    ctx->r2 = ADD32(0, 0X5294);
L_0024A0B8:
    // 0x0024A0B8: lb          $a1, 0x30($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X30);
    // 0x0024A0BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024A0C0: beq         $a1, $v0, L_0024A100
    if (ctx->r5 == ctx->r2) {
        // 0x0024A0C4: slti        $v0, $a1, 0x2
        ctx->r2 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
            goto L_0024A100;
    }
    // 0x0024A0C4: slti        $v0, $a1, 0x2
    ctx->r2 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x0024A0C8: beq         $v0, $zero, L_0024A0E0
    if (ctx->r2 == 0) {
        // 0x0024A0CC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_0024A0E0;
    }
    // 0x0024A0CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x0024A0D0: beq         $a1, $zero, L_0024A0F8
    if (ctx->r5 == 0) {
        // 0x0024A0D4: addiu       $v0, $zero, 0x526C
        ctx->r2 = ADD32(0, 0X526C);
            goto L_0024A0F8;
    }
    // 0x0024A0D4: addiu       $v0, $zero, 0x526C
    ctx->r2 = ADD32(0, 0X526C);
    // 0x0024A0D8: j           L_0024A110
    // 0x0024A0DC: nop

        goto L_0024A110;
    // 0x0024A0DC: nop

L_0024A0E0:
    // 0x0024A0E0: beq         $a1, $v0, L_0024A0F8
    if (ctx->r5 == ctx->r2) {
        // 0x0024A0E4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0024A0F8;
    }
    // 0x0024A0E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x0024A0E8: beq         $a1, $v0, L_0024A100
    if (ctx->r5 == ctx->r2) {
        // 0x0024A0EC: addiu       $v0, $zero, 0x526C
        ctx->r2 = ADD32(0, 0X526C);
            goto L_0024A100;
    }
    // 0x0024A0EC: addiu       $v0, $zero, 0x526C
    ctx->r2 = ADD32(0, 0X526C);
    // 0x0024A0F0: j           L_0024A110
    // 0x0024A0F4: nop

        goto L_0024A110;
    // 0x0024A0F4: nop

L_0024A0F8:
    // 0x0024A0F8: jr          $ra
    // 0x0024A0FC: addiu       $v0, $zero, 0x526C
    ctx->r2 = ADD32(0, 0X526C);
    return;
    // 0x0024A0FC: addiu       $v0, $zero, 0x526C
    ctx->r2 = ADD32(0, 0X526C);
L_0024A100:
    // 0x0024A100: jr          $ra
    // 0x0024A104: addiu       $v0, $zero, 0x5276
    ctx->r2 = ADD32(0, 0X5276);
    return;
    // 0x0024A104: addiu       $v0, $zero, 0x5276
    ctx->r2 = ADD32(0, 0X5276);
L_0024A108:
    // 0x0024A108: jr          $ra
    // 0x0024A10C: addiu       $v0, $zero, 0x528A
    ctx->r2 = ADD32(0, 0X528A);
    return;
    // 0x0024A10C: addiu       $v0, $zero, 0x528A
    ctx->r2 = ADD32(0, 0X528A);
L_0024A110:
    // 0x0024A110: jr          $ra
    // 0x0024A114: nop

    return;
    // 0x0024A114: nop

;}
RECOMP_FUNC void func_0024A118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A11C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x0024A120: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024A124: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024A128: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A12C: jal         0x00200528
    // 0x0024A130: nop

    func_00200528(rdram, ctx);
        goto after_0;
    // 0x0024A130: nop

    after_0:
    // 0x0024A134: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A138: jr          $ra
    // 0x0024A13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A140: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0024A144: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024A148: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x0024A14C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024A150: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024A154: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x0024A158: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A15C: lwc1        $f1, -0x717C($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X717C);
    // 0x0024A160: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x0024A164: addiu       $v0, $v0, 0x690
    ctx->r2 = ADD32(ctx->r2, 0X690);
    // 0x0024A168: sw          $v0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r2;
    // 0x0024A16C: lui         $v0, 0x25
    ctx->r2 = S32(0X25 << 16);
    // 0x0024A170: addiu       $v0, $v0, -0x5CEC
    ctx->r2 = ADD32(ctx->r2, -0X5CEC);
    // 0x0024A174: sw          $v0, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->r2;
    // 0x0024A178: lui         $v0, 0x25
    ctx->r2 = S32(0X25 << 16);
    // 0x0024A17C: addiu       $v0, $v0, -0x5E0C
    ctx->r2 = ADD32(ctx->r2, -0X5E0C);
    // 0x0024A180: sw          $v0, 0xD8($a1)
    MEM_W(0XD8, ctx->r5) = ctx->r2;
    // 0x0024A184: sw          $zero, 0x164($a1)
    MEM_W(0X164, ctx->r5) = 0;
    // 0x0024A188: sw          $zero, 0x168($a1)
    MEM_W(0X168, ctx->r5) = 0;
    // 0x0024A18C: addiu       $v0, $s0, 0x14
    ctx->r2 = ADD32(ctx->r16, 0X14);
    // 0x0024A190: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x0024A194: sw          $zero, 0x154($a1)
    MEM_W(0X154, ctx->r5) = 0;
    // 0x0024A198: sw          $zero, 0x158($a1)
    MEM_W(0X158, ctx->r5) = 0;
    // 0x0024A19C: sw          $zero, 0x15C($a1)
    MEM_W(0X15C, ctx->r5) = 0;
    // 0x0024A1A0: sw          $zero, 0x160($a1)
    MEM_W(0X160, ctx->r5) = 0;
    // 0x0024A1A4: swc1        $f0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f0.u32l;
    // 0x0024A1A8: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x0024A1AC: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x0024A1B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0024A1B4: sb          $zero, 0x33($a1)
    MEM_B(0X33, ctx->r5) = 0;
    // 0x0024A1B8: jal         0x0023E684
    // 0x0024A1BC: swc1        $f0, 0x16C($a1)
    MEM_W(0X16C, ctx->r5) = ctx->f0.u32l;
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024A1BC: swc1        $f0, 0x16C($a1)
    MEM_W(0X16C, ctx->r5) = ctx->f0.u32l;
    after_0:
    // 0x0024A1C0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x0024A1C4: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x0024A1C8: beq         $v0, $zero, L_0024A1E0
    if (ctx->r2 == 0) {
        // 0x0024A1CC: lui         $v1, 0xFFEF
        ctx->r3 = S32(0XFFEF << 16);
            goto L_0024A1E0;
    }
    // 0x0024A1CC: lui         $v1, 0xFFEF
    ctx->r3 = S32(0XFFEF << 16);
    // 0x0024A1D0: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x0024A1D4: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x0024A1D8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A1DC: sw          $v0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r2;
L_0024A1E0:
    // 0x0024A1E0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x0024A1E4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0024A1E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024A1EC: jr          $ra
    // 0x0024A1F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0024A1F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_0024A1F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A1F4: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x0024A1F8: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x0024A1FC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0024A200: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x0024A204: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0024A208: sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // 0x0024A20C: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x0024A210: sdc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD0, ctx->r29);
    // 0x0024A214: lw          $a1, 0x168($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X168);
    // 0x0024A218: jal         0x00214778
    // 0x0024A21C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_00214778(rdram, ctx);
        goto after_0;
    // 0x0024A21C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x0024A220: lw          $a1, 0x164($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X164);
    // 0x0024A224: jal         0x002148D8
    // 0x0024A228: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_002148D8(rdram, ctx);
        goto after_1;
    // 0x0024A228: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x0024A22C: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x0024A230: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A234: lwc1        $f20, -0x7178($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7178);
    // 0x0024A238: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x0024A23C: jal         0x0029A570
    // 0x0024A240: nop

    func_0029A570(rdram, ctx);
        goto after_2;
    // 0x0024A240: nop

    after_2:
    // 0x0024A244: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x0024A248: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x0024A24C: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x0024A250: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x0024A254: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x0024A258: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x0024A25C: swc1        $f0, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = ctx->f0.u32l;
    // 0x0024A260: jal         0x00299758
    // 0x0024A264: nop

    func_00299758(rdram, ctx);
        goto after_3;
    // 0x0024A264: nop

    after_3:
    // 0x0024A268: addiu       $s2, $sp, 0xA0
    ctx->r18 = ADD32(ctx->r29, 0XA0);
    // 0x0024A26C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x0024A270: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x0024A274: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x0024A278: jal         0x002150B0
    // 0x0024A27C: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    func_002150B0(rdram, ctx);
        goto after_4;
    // 0x0024A27C: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x0024A280: addiu       $s1, $sp, 0xB0
    ctx->r17 = ADD32(ctx->r29, 0XB0);
    // 0x0024A284: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024A288: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x0024A28C: jal         0x002150B0
    // 0x0024A290: addiu       $a2, $s0, 0x50
    ctx->r6 = ADD32(ctx->r16, 0X50);
    func_002150B0(rdram, ctx);
        goto after_5;
    // 0x0024A290: addiu       $a2, $s0, 0x50
    ctx->r6 = ADD32(ctx->r16, 0X50);
    after_5:
    // 0x0024A294: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024A298: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x0024A29C: jal         0x0021525C
    // 0x0024A2A0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_0021525C(rdram, ctx);
        goto after_6;
    // 0x0024A2A0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_6:
    // 0x0024A2A4: addiu       $s1, $s0, 0x78
    ctx->r17 = ADD32(ctx->r16, 0X78);
    // 0x0024A2A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024A2AC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x0024A2B0: jal         0x002110F0
    // 0x0024A2B4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_002110F0(rdram, ctx);
        goto after_7;
    // 0x0024A2B4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_7:
    // 0x0024A2B8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x0024A2BC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x0024A2C0: lw          $a3, 0x3C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X3C);
    // 0x0024A2C4: jal         0x00214494
    // 0x0024A2C8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214494(rdram, ctx);
        goto after_8;
    // 0x0024A2C8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // 0x0024A2CC: lui         $a1, 0x469C
    ctx->r5 = S32(0X469C << 16);
    // 0x0024A2D0: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x0024A2D4: jal         0x00213658
    // 0x0024A2D8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_00213658(rdram, ctx);
        goto after_9;
    // 0x0024A2D8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x0024A2DC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x0024A2E0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x0024A2E4: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x0024A2E8: jal         0x00214460
    // 0x0024A2EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214460(rdram, ctx);
        goto after_10;
    // 0x0024A2EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x0024A2F0: jal         0x00214D84
    // 0x0024A2F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00214D84(rdram, ctx);
        goto after_11;
    // 0x0024A2F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_11:
    // 0x0024A2F8: lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XCC);
    // 0x0024A2FC: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x0024A300: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x0024A304: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x0024A308: ldc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD0);
    // 0x0024A30C: jr          $ra
    // 0x0024A310: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x0024A310: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_0024A314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0024A318: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024A31C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0024A320: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024A324: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0024A328: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024A32C: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024A330: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x0024A334: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x0024A338: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x0024A33C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024A340: jal         0x00200528
    // 0x0024A344: addiu       $s2, $v0, 0x14
    ctx->r18 = ADD32(ctx->r2, 0X14);
    func_00200528(rdram, ctx);
        goto after_0;
    // 0x0024A344: addiu       $s2, $v0, 0x14
    ctx->r18 = ADD32(ctx->r2, 0X14);
    after_0:
    // 0x0024A348: beq         $v0, $zero, L_0024A35C
    if (ctx->r2 == 0) {
        // 0x0024A34C: lui         $v1, 0x80
        ctx->r3 = S32(0X80 << 16);
            goto L_0024A35C;
    }
    // 0x0024A34C: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x0024A350: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x0024A354: j           L_0024A378
    // 0x0024A358: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_0024A378;
    // 0x0024A358: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_0024A35C:
    // 0x0024A35C: lui         $a0, 0xFF7F
    ctx->r4 = S32(0XFF7F << 16);
    // 0x0024A360: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x0024A364: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x0024A368: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x0024A36C: ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // 0x0024A370: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x0024A374: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_0024A378:
    // 0x0024A378: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
    // 0x0024A37C: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x0024A380: beq         $v0, $zero, L_0024A39C
    if (ctx->r2 == 0) {
        // 0x0024A384: nop
    
            goto L_0024A39C;
    }
    // 0x0024A384: nop

    // 0x0024A388: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x0024A38C: beq         $v0, $zero, L_0024A39C
    if (ctx->r2 == 0) {
        // 0x0024A390: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_0024A39C;
    }
    // 0x0024A390: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024A394: jalr        $v0
    // 0x0024A398: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x0024A398: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
L_0024A39C:
    // 0x0024A39C: lwc1        $f0, 0x48($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X48);
    // 0x0024A3A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A3A4: lwc1        $f1, -0x4968($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X4968);
    // 0x0024A3A8: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x0024A3AC: lwc1        $f1, 0x16C($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X16C);
    // 0x0024A3B0: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x0024A3B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024A3B8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0024A3BC: jal         0x002499C0
    // 0x0024A3C0: swc1        $f1, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    func_002499C0(rdram, ctx);
        goto after_2;
    // 0x0024A3C0: swc1        $f1, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f_odd[(1 - 1) * 2];
    after_2:
    // 0x0024A3C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024A3C8: jal         0x00249D80
    // 0x0024A3CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_00249D80(rdram, ctx);
        goto after_3;
    // 0x0024A3CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x0024A3D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x0024A3D4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x0024A3D8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0024A3DC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024A3E0: jr          $ra
    // 0x0024A3E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0024A3E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_0024A3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A3E8: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x0024A3EC: lw          $v0, 0x38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X38);
    // 0x0024A3F0: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x0024A3F4: bne         $v0, $zero, L_0024A40C
    if (ctx->r2 != 0) {
        // 0x0024A3F8: lui         $v1, 0xFEFF
        ctx->r3 = S32(0XFEFF << 16);
            goto L_0024A40C;
    }
    // 0x0024A3F8: lui         $v1, 0xFEFF
    ctx->r3 = S32(0XFEFF << 16);
    // 0x0024A3FC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A400: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x0024A404: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A408: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_0024A40C:
    // 0x0024A40C: jr          $ra
    // 0x0024A410: nop

    return;
    // 0x0024A410: nop

;}
RECOMP_FUNC void func_0024A414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A418: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A41C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x0024A420: addiu       $t0, $v0, 0x14
    ctx->r8 = ADD32(ctx->r2, 0X14);
    // 0x0024A424: lw          $a3, 0x24($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X24);
    // 0x0024A428: andi        $v0, $a3, 0x10
    ctx->r2 = ctx->r7 & 0X10;
    // 0x0024A42C: beq         $v0, $zero, L_0024A444
    if (ctx->r2 == 0) {
        // 0x0024A430: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_0024A444;
    }
    // 0x0024A430: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0024A434: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A438: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x0024A43C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A440: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
L_0024A444:
    // 0x0024A444: andi        $v0, $a3, 0x100
    ctx->r2 = ctx->r7 & 0X100;
    // 0x0024A448: beq         $v0, $zero, L_0024A460
    if (ctx->r2 == 0) {
        // 0x0024A44C: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_0024A460;
    }
    // 0x0024A44C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x0024A450: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A454: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A458: beql        $v0, $zero, L_0024A460
    if (ctx->r2 == 0) {
        // 0x0024A45C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_0024A460;
    }
    goto skip_0;
    // 0x0024A45C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_0:
L_0024A460:
    // 0x0024A460: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x0024A464: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x0024A468: beq         $v0, $zero, L_0024A480
    if (ctx->r2 == 0) {
        // 0x0024A46C: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_0024A480;
    }
    // 0x0024A46C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x0024A470: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A474: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A478: bnel        $v0, $zero, L_0024A480
    if (ctx->r2 != 0) {
        // 0x0024A47C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_0024A480;
    }
    goto skip_1;
    // 0x0024A47C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_1:
L_0024A480:
    // 0x0024A480: beql        $a2, $zero, L_0024A4A8
    if (ctx->r6 == 0) {
        // 0x0024A484: sw          $zero, 0x3C($a1)
        MEM_W(0X3C, ctx->r5) = 0;
            goto L_0024A4A8;
    }
    goto skip_2;
    // 0x0024A484: sw          $zero, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = 0;
    skip_2:
    // 0x0024A488: lwc1        $f1, 0x3C($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X3C);
    // 0x0024A48C: lwc1        $f0, 0x4C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x0024A490: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x0024A494: nop

    // 0x0024A498: bc1f        L_0024A4A8
    if (!c1cs) {
        // 0x0024A49C: nop
    
            goto L_0024A4A8;
    }
    // 0x0024A49C: nop

    // 0x0024A4A0: jal         0x0023E684
    // 0x0024A4A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024A4A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
L_0024A4A8:
    // 0x0024A4A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A4AC: jr          $ra
    // 0x0024A4B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A4B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A4B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A4B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0024A4B8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024A4BC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0024A4C0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x0024A4C4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024A4C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024A4CC: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x0024A4D0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x0024A4D4: jal         0x0021B680
    // 0x0024A4D8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    func_0021B680(rdram, ctx);
        goto after_0;
    // 0x0024A4D8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    after_0:
    // 0x0024A4DC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x0024A4E0: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x0024A4E4: bne         $v0, $zero, L_0024A4FC
    if (ctx->r2 != 0) {
        // 0x0024A4E8: lui         $v1, 0xFEFF
        ctx->r3 = S32(0XFEFF << 16);
            goto L_0024A4FC;
    }
    // 0x0024A4E8: lui         $v1, 0xFEFF
    ctx->r3 = S32(0XFEFF << 16);
    // 0x0024A4EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x0024A4F0: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x0024A4F4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A4F8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_0024A4FC:
    // 0x0024A4FC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x0024A500: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0024A504: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024A508: jr          $ra
    // 0x0024A50C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0024A50C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_0024A510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A514: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A518: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x0024A51C: addiu       $t0, $v0, 0x14
    ctx->r8 = ADD32(ctx->r2, 0X14);
    // 0x0024A520: lw          $a3, 0x24($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X24);
    // 0x0024A524: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x0024A528: and         $v0, $a3, $a2
    ctx->r2 = ctx->r7 & ctx->r6;
    // 0x0024A52C: beq         $v0, $zero, L_0024A540
    if (ctx->r2 == 0) {
        // 0x0024A530: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_0024A540;
    }
    // 0x0024A530: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x0024A534: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A538: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x0024A53C: sltu        $v1, $v0, $v1
    ctx->r3 = ctx->r2 < ctx->r3 ? 1 : 0;
L_0024A540:
    // 0x0024A540: andi        $v0, $a3, 0x4000
    ctx->r2 = ctx->r7 & 0X4000;
    // 0x0024A544: beq         $v0, $zero, L_0024A55C
    if (ctx->r2 == 0) {
        // 0x0024A548: nop
    
            goto L_0024A55C;
    }
    // 0x0024A548: nop

    // 0x0024A54C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A550: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x0024A554: beql        $v0, $zero, L_0024A55C
    if (ctx->r2 == 0) {
        // 0x0024A558: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_0024A55C;
    }
    goto skip_0;
    // 0x0024A558: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    skip_0:
L_0024A55C:
    // 0x0024A55C: beq         $v1, $zero, L_0024A580
    if (ctx->r3 == 0) {
        // 0x0024A560: nop
    
            goto L_0024A580;
    }
    // 0x0024A560: nop

    // 0x0024A564: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A568: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x0024A56C: lwc1        $f2, 0x38($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X38);
    // 0x0024A570: lwc1        $f1, 0x60($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X60);
    // 0x0024A574: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x0024A578: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x0024A57C: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
L_0024A580:
    // 0x0024A580: lwc1        $f1, 0x60($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X60);
    // 0x0024A584: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A588: lwc1        $f0, -0x7174($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7174);
    // 0x0024A58C: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x0024A590: nop

    // 0x0024A594: bc1f        L_0024A5A4
    if (!c1cs) {
        // 0x0024A598: nop
    
            goto L_0024A5A4;
    }
    // 0x0024A598: nop

    // 0x0024A59C: jal         0x0023E684
    // 0x0024A5A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024A5A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
L_0024A5A4:
    // 0x0024A5A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A5A8: jr          $ra
    // 0x0024A5AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A5AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A5B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A5B0: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x0024A5B4: lw          $v0, 0x38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X38);
    // 0x0024A5B8: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x0024A5BC: bne         $v0, $zero, L_0024A5D4
    if (ctx->r2 != 0) {
        // 0x0024A5C0: lui         $v1, 0xFDFF
        ctx->r3 = S32(0XFDFF << 16);
            goto L_0024A5D4;
    }
    // 0x0024A5C0: lui         $v1, 0xFDFF
    ctx->r3 = S32(0XFDFF << 16);
    // 0x0024A5C4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A5C8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x0024A5CC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A5D0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_0024A5D4:
    // 0x0024A5D4: jr          $ra
    // 0x0024A5D8: nop

    return;
    // 0x0024A5D8: nop

;}
RECOMP_FUNC void func_0024A5DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A5DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A5E0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A5E4: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x0024A5E8: addiu       $t0, $v0, 0x14
    ctx->r8 = ADD32(ctx->r2, 0X14);
    // 0x0024A5EC: lw          $a3, 0x24($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X24);
    // 0x0024A5F0: andi        $v0, $a3, 0x20
    ctx->r2 = ctx->r7 & 0X20;
    // 0x0024A5F4: beq         $v0, $zero, L_0024A60C
    if (ctx->r2 == 0) {
        // 0x0024A5F8: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_0024A60C;
    }
    // 0x0024A5F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0024A5FC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A600: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x0024A604: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A608: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
L_0024A60C:
    // 0x0024A60C: andi        $v0, $a3, 0x200
    ctx->r2 = ctx->r7 & 0X200;
    // 0x0024A610: beq         $v0, $zero, L_0024A628
    if (ctx->r2 == 0) {
        // 0x0024A614: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_0024A628;
    }
    // 0x0024A614: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x0024A618: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A61C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A620: beql        $v0, $zero, L_0024A628
    if (ctx->r2 == 0) {
        // 0x0024A624: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_0024A628;
    }
    goto skip_0;
    // 0x0024A624: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_0:
L_0024A628:
    // 0x0024A628: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x0024A62C: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x0024A630: beq         $v0, $zero, L_0024A648
    if (ctx->r2 == 0) {
        // 0x0024A634: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_0024A648;
    }
    // 0x0024A634: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x0024A638: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A63C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A640: bnel        $v0, $zero, L_0024A648
    if (ctx->r2 != 0) {
        // 0x0024A644: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_0024A648;
    }
    goto skip_1;
    // 0x0024A644: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_1:
L_0024A648:
    // 0x0024A648: beql        $a2, $zero, L_0024A670
    if (ctx->r6 == 0) {
        // 0x0024A64C: sw          $zero, 0x3C($a1)
        MEM_W(0X3C, ctx->r5) = 0;
            goto L_0024A670;
    }
    goto skip_2;
    // 0x0024A64C: sw          $zero, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = 0;
    skip_2:
    // 0x0024A650: lwc1        $f1, 0x3C($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X3C);
    // 0x0024A654: lwc1        $f0, 0x50($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X50);
    // 0x0024A658: c.le.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl <= ctx->f1.fl;
    // 0x0024A65C: nop

    // 0x0024A660: bc1f        L_0024A670
    if (!c1cs) {
        // 0x0024A664: nop
    
            goto L_0024A670;
    }
    // 0x0024A664: nop

    // 0x0024A668: jal         0x0023E684
    // 0x0024A66C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024A66C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
L_0024A670:
    // 0x0024A670: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A674: jr          $ra
    // 0x0024A678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A67C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0024A680: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024A684: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0024A688: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x0024A68C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024A690: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024A694: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x0024A698: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x0024A69C: jal         0x0021B680
    // 0x0024A6A0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    func_0021B680(rdram, ctx);
        goto after_0;
    // 0x0024A6A0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    after_0:
    // 0x0024A6A4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x0024A6A8: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x0024A6AC: bne         $v0, $zero, L_0024A6C4
    if (ctx->r2 != 0) {
        // 0x0024A6B0: lui         $v1, 0xFDFF
        ctx->r3 = S32(0XFDFF << 16);
            goto L_0024A6C4;
    }
    // 0x0024A6B0: lui         $v1, 0xFDFF
    ctx->r3 = S32(0XFDFF << 16);
    // 0x0024A6B4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x0024A6B8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x0024A6BC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A6C0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_0024A6C4:
    // 0x0024A6C4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x0024A6C8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0024A6CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024A6D0: jr          $ra
    // 0x0024A6D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0024A6D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_0024A6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A6D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A6DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A6E0: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x0024A6E4: addiu       $t0, $v0, 0x14
    ctx->r8 = ADD32(ctx->r2, 0X14);
    // 0x0024A6E8: lw          $a3, 0x24($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X24);
    // 0x0024A6EC: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x0024A6F0: and         $v0, $a3, $v0
    ctx->r2 = ctx->r7 & ctx->r2;
    // 0x0024A6F4: beq         $v0, $zero, L_0024A70C
    if (ctx->r2 == 0) {
        // 0x0024A6F8: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_0024A70C;
    }
    // 0x0024A6F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0024A6FC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A700: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x0024A704: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A708: sltu        $a2, $v0, $a2
    ctx->r6 = ctx->r2 < ctx->r6 ? 1 : 0;
L_0024A70C:
    // 0x0024A70C: andi        $v0, $a3, 0x8000
    ctx->r2 = ctx->r7 & 0X8000;
    // 0x0024A710: beq         $v0, $zero, L_0024A728
    if (ctx->r2 == 0) {
        // 0x0024A714: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_0024A728;
    }
    // 0x0024A714: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x0024A718: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A71C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A720: beql        $v0, $zero, L_0024A728
    if (ctx->r2 == 0) {
        // 0x0024A724: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_0024A728;
    }
    goto skip_0;
    // 0x0024A724: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_0:
L_0024A728:
    // 0x0024A728: beq         $a2, $zero, L_0024A74C
    if (ctx->r6 == 0) {
        // 0x0024A72C: nop
    
            goto L_0024A74C;
    }
    // 0x0024A72C: nop

    // 0x0024A730: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A734: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x0024A738: lwc1        $f2, 0x38($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X38);
    // 0x0024A73C: lwc1        $f1, 0x60($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X60);
    // 0x0024A740: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x0024A744: sub.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x0024A748: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
L_0024A74C:
    // 0x0024A74C: lwc1        $f1, 0x60($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X60);
    // 0x0024A750: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x0024A754: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x0024A758: nop

    // 0x0024A75C: bc1f        L_0024A76C
    if (!c1cs) {
        // 0x0024A760: nop
    
            goto L_0024A76C;
    }
    // 0x0024A760: nop

    // 0x0024A764: jal         0x0023E684
    // 0x0024A768: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024A768: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
L_0024A76C:
    // 0x0024A76C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A770: jr          $ra
    // 0x0024A774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A77C: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x0024A780: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // 0x0024A784: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A788: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x0024A78C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0024A790: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0024A794: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    // 0x0024A798: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A79C: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x0024A7A0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0024A7A4: jal         0x0023E684
    // 0x0024A7A8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024A7A8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_0:
    // 0x0024A7AC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A7B0: jr          $ra
    // 0x0024A7B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A7B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A7B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A7BC: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x0024A7C0: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // 0x0024A7C4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A7C8: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x0024A7CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x0024A7D0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0024A7D4: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    // 0x0024A7D8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A7DC: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x0024A7E0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0024A7E4: jal         0x0023E684
    // 0x0024A7E8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024A7E8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_0:
    // 0x0024A7EC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A7F0: jr          $ra
    // 0x0024A7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A7F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A7FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024A800: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0024A804: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024A808: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024A80C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024A810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x0024A814: jal         0x00203F6C
    // 0x0024A818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_00203F6C(rdram, ctx);
        goto after_0;
    // 0x0024A818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x0024A81C: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x0024A820: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x0024A824: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
    // 0x0024A828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x0024A82C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024A830: jr          $ra
    // 0x0024A834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A838: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A83C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x0024A840: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024A844: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024A848: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A84C: lhu         $a1, 0xA($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XA);
    // 0x0024A850: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x0024A854: jal         0x00203E94
    // 0x0024A858: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_00203E94(rdram, ctx);
        goto after_0;
    // 0x0024A858: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x0024A85C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A860: jr          $ra
    // 0x0024A864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A86C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024A870: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0024A874: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024A878: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024A87C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024A880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x0024A884: jal         0x00203F6C
    // 0x0024A888: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00203F6C(rdram, ctx);
        goto after_0;
    // 0x0024A888: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x0024A88C: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x0024A890: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x0024A894: ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // 0x0024A898: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024A89C: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
    // 0x0024A8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x0024A8A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024A8A8: jr          $ra
    // 0x0024A8AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A8AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024A8B4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x0024A8B8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024A8BC: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024A8C0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024A8C4: lhu         $a1, 0xA($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XA);
    // 0x0024A8C8: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x0024A8CC: jal         0x00203E94
    // 0x0024A8D0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_00203E94(rdram, ctx);
        goto after_0;
    // 0x0024A8D0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x0024A8D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024A8D8: jr          $ra
    // 0x0024A8DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024A8DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024A8E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A8E0: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x0024A8E4: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x0024A8E8: ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // 0x0024A8EC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0024A8F0: jr          $ra
    // 0x0024A8F4: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    return;
    // 0x0024A8F4: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_0024A8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A8F8: lui         $a2, 0x10
    ctx->r6 = S32(0X10 << 16);
    // 0x0024A8FC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A900: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x0024A904: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0024A908: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x0024A90C: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x0024A910: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x0024A914: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x0024A918: jr          $ra
    // 0x0024A91C: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    return;
    // 0x0024A91C: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_0024A920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A920: lui         $a2, 0x10
    ctx->r6 = S32(0X10 << 16);
    // 0x0024A924: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x0024A928: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x0024A92C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0024A930: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x0024A934: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x0024A938: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x0024A93C: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x0024A940: jr          $ra
    // 0x0024A944: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
    return;
    // 0x0024A944: sw          $v0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_0024A948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024A948: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x0024A94C: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x0024A950: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0024A954: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x0024A958: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x0024A95C: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x0024A960: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x0024A964: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x0024A968: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x0024A96C: sdc1        $f21, 0xA0($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0XA0, ctx->r29);
    // 0x0024A970: sdc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X98, ctx->r29);
    // 0x0024A974: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x0024A978: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x0024A97C: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x0024A980: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x0024A984: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x0024A988: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x0024A98C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x0024A990: addiu       $s2, $v0, 0x14
    ctx->r18 = ADD32(ctx->r2, 0X14);
    // 0x0024A994: lhu         $v0, 0xD8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XD8);
    // 0x0024A998: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x0024A99C: addiu       $v0, $v0, -0xFB2
    ctx->r2 = ADD32(ctx->r2, -0XFB2);
    // 0x0024A9A0: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x0024A9A4: beq         $v0, $zero, L_0024AA00
    if (ctx->r2 == 0) {
        // 0x0024A9A8: addiu       $s4, $sp, 0x60
        ctx->r20 = ADD32(ctx->r29, 0X60);
            goto L_0024AA00;
    }
    // 0x0024A9A8: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
    // 0x0024A9AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A9B0: lwc1        $f20, -0x7170($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7170);
    // 0x0024A9B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024A9B8: lwc1        $f21, -0x716C($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X716C);
    // 0x0024A9BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x0024A9C0: jal         0x00215A90
    // 0x0024A9C4: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x0024A9C4: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    after_0:
    // 0x0024A9C8: lwc1        $f1, 0x60($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X60);
    // 0x0024A9CC: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x0024A9D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x0024A9D4: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x0024A9D8: jal         0x00215A90
    // 0x0024A9DC: swc1        $f1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    func_00215A90(rdram, ctx);
        goto after_1;
    // 0x0024A9DC: swc1        $f1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    after_1:
    // 0x0024A9E0: lwc1        $f1, 0x68($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X68);
    // 0x0024A9E4: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x0024A9E8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024A9EC: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024A9F0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x0024A9F4: jal         0x00200C94
    // 0x0024A9F8: swc1        $f1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    func_00200C94(rdram, ctx);
        goto after_2;
    // 0x0024A9F8: swc1        $f1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    after_2:
    // 0x0024A9FC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_0024AA00:
    // 0x0024AA00: bne         $s1, $zero, L_0024AA2C
    if (ctx->r17 != 0) {
        // 0x0024AA04: nop
    
            goto L_0024AA2C;
    }
    // 0x0024AA04: nop

    // 0x0024AA08: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x0024AA0C: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x0024AA10: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x0024AA14: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x0024AA18: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x0024AA1C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x0024AA20: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x0024AA24: beq         $s1, $zero, L_0024AA50
    if (ctx->r17 == 0) {
        // 0x0024AA28: nop
    
            goto L_0024AA50;
    }
    // 0x0024AA28: nop

L_0024AA2C:
    // 0x0024AA2C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x0024AA30: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x0024AA34: jal         0x0026D334
    // 0x0024AA38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0026D334(rdram, ctx);
        goto after_3;
    // 0x0024AA38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x0024AA3C: lwc1        $f1, 0x64($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X64);
    // 0x0024AA40: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x0024AA44: nop

    // 0x0024AA48: bc1tl       L_0024AA50
    if (c1cs) {
        // 0x0024AA4C: swc1        $f0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
            goto L_0024AA50;
    }
    goto skip_0;
    // 0x0024AA4C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    skip_0:
L_0024AA50:
    // 0x0024AA50: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x0024AA54: beq         $v1, $zero, L_0024AA6C
    if (ctx->r3 == 0) {
        // 0x0024AA58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_0024AA6C;
    }
    // 0x0024AA58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024AA5C: beq         $v1, $v0, L_0024ACF8
    if (ctx->r3 == ctx->r2) {
        // 0x0024AA60: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_0024ACF8;
    }
    // 0x0024AA60: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0024AA64: j           L_0024AD88
    // 0x0024AA68: nop

        goto L_0024AD88;
    // 0x0024AA68: nop

L_0024AA6C:
    // 0x0024AA6C: lh          $a1, 0x16($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X16);
    // 0x0024AA70: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024AA74: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024AA78: jal         0x0020542C
    // 0x0024AA7C: nop

    func_0020542C(rdram, ctx);
        goto after_4;
    // 0x0024AA7C: nop

    after_4:
    // 0x0024AA80: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x0024AA84: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x0024AA88: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x0024AA8C: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x0024AA90: beq         $v0, $zero, L_0024AD88
    if (ctx->r2 == 0) {
        // 0x0024AA94: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_0024AD88;
    }
    // 0x0024AA94: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x0024AA98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024AA9C: addu        $at, $at, $v0
    gpr jr_addend_0024AAA4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0024AAA0: lw          $v0, -0x7168($at)
    ctx->r2 = ADD32(ctx->r1, -0X7168);
    // 0x0024AAA4: jr          $v0
    // 0x0024AAA8: nop

    switch (jr_addend_0024AAA4 >> 2) {
        case 0: goto L_0024AB84; break;
        case 1: goto L_0024AB84; break;
        case 2: goto L_0024AB84; break;
        case 3: goto L_0024AB84; break;
        case 4: goto L_0024AB84; break;
        case 5: goto L_0024AB84; break;
        case 6: goto L_0024AB84; break;
        case 7: goto L_0024AAAC; break;
        case 8: goto L_0024AB84; break;
        case 9: goto L_0024AB84; break;
        default: switch_error(__func__, 0x0024AAA4, 0x800A8E98);
    }
    // 0x0024AAA8: nop

L_0024AAAC:
    // 0x0024AAAC: lwc1        $f1, 0x18($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X18);
    // 0x0024AAB0: mul.s       $f1, $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f1.fl);
    // 0x0024AAB4: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x0024AAB8: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x0024AABC: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x0024AAC0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x0024AAC4: add.s       $f1, $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f2.fl;
    // 0x0024AAC8: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x0024AACC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024AAD0: lwc1        $f0, -0x7140($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7140);
    // 0x0024AAD4: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x0024AAD8: nop

    // 0x0024AADC: bc1f        L_0024AAFC
    if (!c1cs) {
        // 0x0024AAE0: nop
    
            goto L_0024AAFC;
    }
    // 0x0024AAE0: nop

    // 0x0024AAE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024AAE8: lwc1        $f0, -0x713C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X713C);
    // 0x0024AAEC: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x0024AAF0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x0024AAF4: j           L_0024AB14
    // 0x0024AAF8: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
        goto L_0024AB14;
    // 0x0024AAF8: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
L_0024AAFC:
    // 0x0024AAFC: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
    // 0x0024AB00: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x0024AB04: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x0024AB08: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x0024AB0C: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x0024AB10: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
L_0024AB14:
    // 0x0024AB14: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x0024AB18: addiu       $s0, $s0, 0x2A80
    ctx->r16 = ADD32(ctx->r16, 0X2A80);
    // 0x0024AB1C: lh          $a1, 0x14($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X14);
    // 0x0024AB20: jal         0x00203ACC
    // 0x0024AB24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00203ACC(rdram, ctx);
        goto after_5;
    // 0x0024AB24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x0024AB28: addiu       $a0, $s0, 0x16EC
    ctx->r4 = ADD32(ctx->r16, 0X16EC);
    // 0x0024AB2C: addiu       $a1, $s3, 0x154
    ctx->r5 = ADD32(ctx->r19, 0X154);
    // 0x0024AB30: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x0024AB34: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x0024AB38: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x0024AB3C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x0024AB40: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x0024AB44: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x0024AB48: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x0024AB4C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x0024AB50: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x0024AB54: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x0024AB58: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x0024AB5C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x0024AB60: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x0024AB64: jal         0x00259810
    // 0x0024AB68: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_00259810(rdram, ctx);
        goto after_6;
    // 0x0024AB68: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_6:
    // 0x0024AB6C: beq         $v0, $zero, L_0024AD88
    if (ctx->r2 == 0) {
        // 0x0024AB70: nop
    
            goto L_0024AD88;
    }
    // 0x0024AB70: nop

    // 0x0024AB74: lw          $v0, 0x158($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X158);
    // 0x0024AB78: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x0024AB7C: j           L_0024AD88
    // 0x0024AB80: sw          $v0, 0x158($s3)
    MEM_W(0X158, ctx->r19) = ctx->r2;
        goto L_0024AD88;
    // 0x0024AB80: sw          $v0, 0x158($s3)
    MEM_W(0X158, ctx->r19) = ctx->r2;
L_0024AB84:
    // 0x0024AB84: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x0024AB88: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x0024AB8C: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x0024AB90: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x0024AB94: lwc1        $f0, 0x20($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X20);
    // 0x0024AB98: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024AB9C: addiu       $a0, $a0, 0x419C
    ctx->r4 = ADD32(ctx->r4, 0X419C);
    // 0x0024ABA0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x0024ABA4: lh          $a1, 0x14($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X14);
    // 0x0024ABA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0024ABAC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x0024ABB0: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x0024ABB4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x0024ABB8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x0024ABBC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x0024ABC0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x0024ABC4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x0024ABC8: lwc1        $f0, 0x70($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X70);
    // 0x0024ABCC: addiu       $v0, $s3, 0x154
    ctx->r2 = ADD32(ctx->r19, 0X154);
    // 0x0024ABD0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x0024ABD4: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
    // 0x0024ABD8: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x0024ABDC: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x0024ABE0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x0024ABE4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x0024ABE8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x0024ABEC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x0024ABF0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x0024ABF4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x0024ABF8: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x0024ABFC: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x0024AC00: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x0024AC04: jal         0x0025A3A0
    // 0x0024AC08: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_0025A3A0(rdram, ctx);
        goto after_7;
    // 0x0024AC08: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_7:
    // 0x0024AC0C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x0024AC10: beq         $a0, $zero, L_0024AD88
    if (ctx->r4 == 0) {
        // 0x0024AC14: nop
    
            goto L_0024AD88;
    }
    // 0x0024AC14: nop

    // 0x0024AC18: lw          $v0, 0x158($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X158);
    // 0x0024AC1C: lw          $v1, 0x15C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X15C);
    // 0x0024AC20: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x0024AC24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x0024AC28: sw          $v0, 0x158($s3)
    MEM_W(0X158, ctx->r19) = ctx->r2;
    // 0x0024AC2C: sw          $v1, 0x15C($s3)
    MEM_W(0X15C, ctx->r19) = ctx->r3;
    // 0x0024AC30: sw          $s0, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->r16;
    // 0x0024AC34: lhu         $v0, 0xD8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XD8);
    // 0x0024AC38: addiu       $v1, $v0, -0xFAA
    ctx->r3 = ADD32(ctx->r2, -0XFAA);
    // 0x0024AC3C: sltiu       $v0, $v1, 0xD
    ctx->r2 = ctx->r3 < 0XD ? 1 : 0;
    // 0x0024AC40: beq         $v0, $zero, L_0024AD88
    if (ctx->r2 == 0) {
        // 0x0024AC44: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_0024AD88;
    }
    // 0x0024AC44: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x0024AC48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024AC4C: addu        $at, $at, $v0
    gpr jr_addend_0024AC54 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0024AC50: lw          $v0, -0x7138($at)
    ctx->r2 = ADD32(ctx->r1, -0X7138);
    // 0x0024AC54: jr          $v0
    // 0x0024AC58: nop

    switch (jr_addend_0024AC54 >> 2) {
        case 0: goto L_0024AC5C; break;
        case 1: goto L_0024AC68; break;
        case 2: goto L_0024AC74; break;
        case 3: goto L_0024AC80; break;
        case 4: goto L_0024AC8C; break;
        case 5: goto L_0024AC98; break;
        case 6: goto L_0024ACA4; break;
        case 7: goto L_0024ACB0; break;
        case 8: goto L_0024ACBC; break;
        case 9: goto L_0024ACC8; break;
        case 10: goto L_0024ACD4; break;
        case 11: goto L_0024ACE0; break;
        case 12: goto L_0024ACEC; break;
        default: switch_error(__func__, 0x0024AC54, 0x800A8EC8);
    }
    // 0x0024AC58: nop

L_0024AC5C:
    // 0x0024AC5C: addiu       $v0, $zero, 0x3EA
    ctx->r2 = ADD32(0, 0X3EA);
    // 0x0024AC60: j           L_0024AD88
    // 0x0024AC64: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024AC64: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024AC68:
    // 0x0024AC68: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x0024AC6C: j           L_0024AD88
    // 0x0024AC70: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024AC70: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024AC74:
    // 0x0024AC74: addiu       $v0, $zero, 0x3E9
    ctx->r2 = ADD32(0, 0X3E9);
    // 0x0024AC78: j           L_0024AD88
    // 0x0024AC7C: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024AC7C: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024AC80:
    // 0x0024AC80: addiu       $v0, $zero, 0x3ED
    ctx->r2 = ADD32(0, 0X3ED);
    // 0x0024AC84: j           L_0024AD88
    // 0x0024AC88: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024AC88: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024AC8C:
    // 0x0024AC8C: addiu       $v0, $zero, 0x3EE
    ctx->r2 = ADD32(0, 0X3EE);
    // 0x0024AC90: j           L_0024AD88
    // 0x0024AC94: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024AC94: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024AC98:
    // 0x0024AC98: addiu       $v0, $zero, 0x3EF
    ctx->r2 = ADD32(0, 0X3EF);
    // 0x0024AC9C: j           L_0024AD88
    // 0x0024ACA0: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024ACA0: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024ACA4:
    // 0x0024ACA4: addiu       $v0, $zero, 0x3F0
    ctx->r2 = ADD32(0, 0X3F0);
    // 0x0024ACA8: j           L_0024AD88
    // 0x0024ACAC: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024ACAC: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024ACB0:
    // 0x0024ACB0: addiu       $v0, $zero, 0x3F3
    ctx->r2 = ADD32(0, 0X3F3);
    // 0x0024ACB4: j           L_0024AD88
    // 0x0024ACB8: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024ACB8: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024ACBC:
    // 0x0024ACBC: addiu       $v0, $zero, 0x3F5
    ctx->r2 = ADD32(0, 0X3F5);
    // 0x0024ACC0: j           L_0024AD88
    // 0x0024ACC4: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024ACC4: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024ACC8:
    // 0x0024ACC8: addiu       $v0, $zero, 0x3F7
    ctx->r2 = ADD32(0, 0X3F7);
    // 0x0024ACCC: j           L_0024AD88
    // 0x0024ACD0: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024ACD0: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024ACD4:
    // 0x0024ACD4: addiu       $v0, $zero, 0x3F8
    ctx->r2 = ADD32(0, 0X3F8);
    // 0x0024ACD8: j           L_0024AD88
    // 0x0024ACDC: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024ACDC: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024ACE0:
    // 0x0024ACE0: addiu       $v0, $zero, 0x3F6
    ctx->r2 = ADD32(0, 0X3F6);
    // 0x0024ACE4: j           L_0024AD88
    // 0x0024ACE8: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024ACE8: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024ACEC:
    // 0x0024ACEC: addiu       $v0, $zero, 0x3FF
    ctx->r2 = ADD32(0, 0X3FF);
    // 0x0024ACF0: j           L_0024AD88
    // 0x0024ACF4: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
        goto L_0024AD88;
    // 0x0024ACF4: sh          $v0, 0xD8($a0)
    MEM_H(0XD8, ctx->r4) = ctx->r2;
L_0024ACF8:
    // 0x0024ACF8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024ACFC: addiu       $a0, $a0, 0x40FC
    ctx->r4 = ADD32(ctx->r4, 0X40FC);
    // 0x0024AD00: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x0024AD04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0024AD08: lh          $v0, 0x24($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X24);
    // 0x0024AD0C: addiu       $a3, $s3, 0x154
    ctx->r7 = ADD32(ctx->r19, 0X154);
    // 0x0024AD10: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x0024AD14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0024AD18: lw          $t0, 0x18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X18);
    // 0x0024AD1C: lw          $t1, 0x1C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1C);
    // 0x0024AD20: lw          $t2, 0x20($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X20);
    // 0x0024AD24: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x0024AD28: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x0024AD2C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x0024AD30: lw          $t0, 0x50($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X50);
    // 0x0024AD34: lw          $t1, 0x54($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X54);
    // 0x0024AD38: lw          $t2, 0x58($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X58);
    // 0x0024AD3C: lw          $t3, 0x5C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X5C);
    // 0x0024AD40: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x0024AD44: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x0024AD48: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x0024AD4C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x0024AD50: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x0024AD54: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x0024AD58: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x0024AD5C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x0024AD60: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x0024AD64: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x0024AD68: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x0024AD6C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x0024AD70: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x0024AD74: jal         0x00253BC8
    // 0x0024AD78: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    func_00253BC8(rdram, ctx);
        goto after_8;
    // 0x0024AD78: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_8:
    // 0x0024AD7C: lw          $v1, 0x158($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X158);
    // 0x0024AD80: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x0024AD84: sw          $v1, 0x158($s3)
    MEM_W(0X158, ctx->r19) = ctx->r3;
L_0024AD88:
    // 0x0024AD88: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x0024AD8C: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x0024AD90: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x0024AD94: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x0024AD98: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x0024AD9C: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x0024ADA0: ldc1        $f21, 0xA0($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0XA0);
    // 0x0024ADA4: ldc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X98);
    // 0x0024ADA8: jr          $ra
    // 0x0024ADAC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x0024ADAC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_0024ADB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024ADB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024ADB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024ADB8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x0024ADBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x0024ADC0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x0024ADC4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x0024ADC8: addiu       $v0, $v0, 0x798
    ctx->r2 = ADD32(ctx->r2, 0X798);
    // 0x0024ADCC: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x0024ADD0: lui         $v0, 0x25
    ctx->r2 = S32(0X25 << 16);
    // 0x0024ADD4: addiu       $v0, $v0, -0x51F8
    ctx->r2 = ADD32(ctx->r2, -0X51F8);
    // 0x0024ADD8: sw          $v0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->r2;
    // 0x0024ADDC: sw          $zero, 0x154($s0)
    MEM_W(0X154, ctx->r16) = 0;
    // 0x0024ADE0: lh          $v0, 0x1C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X1C);
    // 0x0024ADE4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0024ADE8: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x0024ADEC: jal         0x0023E684
    // 0x0024ADF0: sw          $v0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->r2;
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024ADF0: sw          $v0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->r2;
    after_0:
    // 0x0024ADF4: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x0024ADF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x0024ADFC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024AE00: jr          $ra
    // 0x0024AE04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024AE04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024AE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024AE08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0024AE0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024AE10: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0024AE14: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0024AE18: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0024AE1C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024AE20: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024AE24: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0024AE28: jal         0x00200528
    // 0x0024AE2C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00200528(rdram, ctx);
        goto after_0;
    // 0x0024AE2C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x0024AE30: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x0024AE34: bne         $v0, $zero, L_0024AE5C
    if (ctx->r2 != 0) {
        // 0x0024AE38: nop
    
            goto L_0024AE5C;
    }
    // 0x0024AE38: nop

    // 0x0024AE3C: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x0024AE40: beq         $v0, $zero, L_0024AE5C
    if (ctx->r2 == 0) {
        // 0x0024AE44: nop
    
            goto L_0024AE5C;
    }
    // 0x0024AE44: nop

    // 0x0024AE48: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x0024AE4C: beq         $v0, $zero, L_0024AE5C
    if (ctx->r2 == 0) {
        // 0x0024AE50: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_0024AE5C;
    }
    // 0x0024AE50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024AE54: jalr        $v0
    // 0x0024AE58: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x0024AE58: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
L_0024AE5C:
    // 0x0024AE5C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x0024AE60: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0024AE64: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024AE68: jr          $ra
    // 0x0024AE6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0024AE6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_0024AE70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024AE70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024AE74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x0024AE78: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0024AE7C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x0024AE80: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x0024AE84: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x0024AE88: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x0024AE8C: jal         0x00215A90
    // 0x0024AE90: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_00215A90(rdram, ctx);
        goto after_0;
    // 0x0024AE90: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x0024AE94: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
    // 0x0024AE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x0024AE9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0024AEA0: jr          $ra
    // 0x0024AEA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024AEA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024AEA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024AEA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024AEAC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024AEB0: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x0024AEB4: addiu       $v1, $a3, 0x14
    ctx->r3 = ADD32(ctx->r7, 0X14);
    // 0x0024AEB8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x0024AEBC: bne         $v0, $zero, L_0024AEDC
    if (ctx->r2 != 0) {
        // 0x0024AEC0: addiu       $a2, $zero, -0x1
        ctx->r6 = ADD32(0, -0X1);
            goto L_0024AEDC;
    }
    // 0x0024AEC0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x0024AEC4: lh          $v0, 0x14($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X14);
    // 0x0024AEC8: beq         $v0, $a2, L_0024AF58
    if (ctx->r2 == ctx->r6) {
        // 0x0024AECC: nop
    
            goto L_0024AF58;
    }
    // 0x0024AECC: nop

    // 0x0024AED0: lh          $v0, 0x16($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X16);
    // 0x0024AED4: beq         $v0, $a2, L_0024AF58
    if (ctx->r2 == ctx->r6) {
        // 0x0024AED8: nop
    
            goto L_0024AF58;
    }
    // 0x0024AED8: nop

L_0024AEDC:
    // 0x0024AEDC: lh          $v1, 0xA($v1)
    ctx->r3 = MEM_H(ctx->r3, 0XA);
    // 0x0024AEE0: lw          $v0, 0x154($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X154);
    // 0x0024AEE4: beq         $v0, $v1, L_0024AF58
    if (ctx->r2 == ctx->r3) {
        // 0x0024AEE8: nop
    
            goto L_0024AF58;
    }
    // 0x0024AEE8: nop

    // 0x0024AEEC: lw          $v0, 0x14($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X14);
    // 0x0024AEF0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0024AEF4: bne         $v0, $zero, L_0024AF08
    if (ctx->r2 != 0) {
        // 0x0024AEF8: nop
    
            goto L_0024AF08;
    }
    // 0x0024AEF8: nop

    // 0x0024AEFC: lw          $v0, 0x158($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X158);
    // 0x0024AF00: beq         $v0, $zero, L_0024AF58
    if (ctx->r2 == 0) {
        // 0x0024AF04: nop
    
            goto L_0024AF58;
    }
    // 0x0024AF04: nop

L_0024AF08:
    // 0x0024AF08: lwc1        $f1, 0x60($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X60);
    // 0x0024AF0C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024AF10: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x0024AF14: sub.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x0024AF18: swc1        $f1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f_odd[(1 - 1) * 2];
    // 0x0024AF1C: lw          $v0, 0x14($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X14);
    // 0x0024AF20: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x0024AF24: beq         $v0, $zero, L_0024AF3C
    if (ctx->r2 == 0) {
        // 0x0024AF28: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_0024AF3C;
    }
    // 0x0024AF28: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x0024AF2C: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x0024AF30: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0024AF34: bne         $v0, $zero, L_0024AF58
    if (ctx->r2 != 0) {
        // 0x0024AF38: nop
    
            goto L_0024AF58;
    }
    // 0x0024AF38: nop

L_0024AF3C:
    // 0x0024AF3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x0024AF40: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x0024AF44: nop

    // 0x0024AF48: bc1f        L_0024AF58
    if (!c1cs) {
        // 0x0024AF4C: nop
    
            goto L_0024AF58;
    }
    // 0x0024AF4C: nop

    // 0x0024AF50: jal         0x0023E684
    // 0x0024AF54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024AF54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
L_0024AF58:
    // 0x0024AF58: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024AF5C: jr          $ra
    // 0x0024AF60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024AF60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024AF64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024AF64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024AF68: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024AF6C: lb          $v0, 0xB3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB3);
    // 0x0024AF70: beq         $v0, $zero, L_0024AF80
    if (ctx->r2 == 0) {
        // 0x0024AF74: nop
    
            goto L_0024AF80;
    }
    // 0x0024AF74: nop

    // 0x0024AF78: jal         0x0023E684
    // 0x0024AF7C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_0023E684(rdram, ctx);
        goto after_0;
    // 0x0024AF7C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
L_0024AF80:
    // 0x0024AF80: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024AF84: jr          $ra
    // 0x0024AF88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024AF88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024AF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024AF8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024AF90: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x0024AF94: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024AF98: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024AF9C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024AFA0: jal         0x00200528
    // 0x0024AFA4: nop

    func_00200528(rdram, ctx);
        goto after_0;
    // 0x0024AFA4: nop

    after_0:
    // 0x0024AFA8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x0024AFAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024AFB0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x0024AFB4: jr          $ra
    // 0x0024AFB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024AFB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024AFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024AFBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024AFC0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x0024AFC4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024AFC8: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024AFCC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024AFD0: jal         0x00203F6C
    // 0x0024AFD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_00203F6C(rdram, ctx);
        goto after_0;
    // 0x0024AFD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x0024AFD8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024AFDC: jr          $ra
    // 0x0024AFE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024AFE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024AFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024AFE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024AFE8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x0024AFEC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024AFF0: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024AFF4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024AFF8: lhu         $a1, 0xA($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XA);
    // 0x0024AFFC: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x0024B000: jal         0x00203E94
    // 0x0024B004: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_00203E94(rdram, ctx);
        goto after_0;
    // 0x0024B004: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x0024B008: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024B00C: jr          $ra
    // 0x0024B010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024B010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024B014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024B014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024B018: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x0024B01C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024B020: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024B024: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024B028: jal         0x00203F6C
    // 0x0024B02C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00203F6C(rdram, ctx);
        goto after_0;
    // 0x0024B02C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x0024B030: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024B034: jr          $ra
    // 0x0024B038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024B038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024B03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024B03C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0024B040: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x0024B044: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0024B048: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0024B04C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0024B050: lhu         $a1, 0xA($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XA);
    // 0x0024B054: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x0024B058: jal         0x00203E94
    // 0x0024B05C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_00203E94(rdram, ctx);
        goto after_0;
    // 0x0024B05C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x0024B060: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0024B064: jr          $ra
    // 0x0024B068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0024B068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0024B06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024B06C: lwc1        $f1, 0xF8($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0XF8);
    // 0x0024B070: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x0024B074: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x0024B078: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x0024B07C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x0024B080: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x0024B084: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x0024B088: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x0024B08C: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x0024B090: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x0024B094: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0024B098: bne         $v1, $v0, L_0024B0E4
    if (ctx->r3 != ctx->r2) {
        // 0x0024B09C: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_0024B0E4;
    }
    // 0x0024B09C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x0024B0A0: lwc1        $f12, 0x70($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X70);
    // 0x0024B0A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B0A8: lwc1        $f20, -0x7100($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7100);
    // 0x0024B0AC: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x0024B0B0: jal         0x0029A570
    // 0x0024B0B4: nop

    func_0029A570(rdram, ctx);
        goto after_0;
    // 0x0024B0B4: nop

    after_0:
    // 0x0024B0B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0024B0BC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x0024B0C0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x0024B0C4: lwc1        $f12, 0x70($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X70);
    // 0x0024B0C8: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x0024B0CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x0024B0D0: swc1        $f0, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = ctx->f0.u32l;
    // 0x0024B0D4: jal         0x00299758
    // 0x0024B0D8: nop

    func_00299758(rdram, ctx);
        goto after_1;
    // 0x0024B0D8: nop

    after_1:
    // 0x0024B0DC: j           L_0024B104
    // 0x0024B0E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_0024B104;
    // 0x0024B0E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_0024B0E4:
    // 0x0024B0E4: lwc1        $f0, 0x84($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X84);
    // 0x0024B0E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B0EC: lwc1        $f12, -0x70FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X70FC);
    // 0x0024B0F0: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x0024B0F4: jal         0x0029A570
    // 0x0024B0F8: nop

    func_0029A570(rdram, ctx);
        goto after_2;
    // 0x0024B0F8: nop

    after_2:
    // 0x0024B0FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x0024B100: swc1        $f0, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = ctx->f0.u32l;
L_0024B104:
    // 0x0024B104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x0024B108: lwc1        $f0, 0x33C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X33C4);
    // 0x0024B10C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B110: lwc1        $f12, -0x70F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X70F8);
    // 0x0024B114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0024B118: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x0024B11C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x0024B120: lwc1        $f0, 0x84($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X84);
    // 0x0024B124: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x0024B128: jal         0x00299758
    // 0x0024B12C: nop

    func_00299758(rdram, ctx);
        goto after_3;
    // 0x0024B12C: nop

    after_3:
    // 0x0024B130: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x0024B134: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024B138: addiu       $a1, $s2, 0x40
    ctx->r5 = ADD32(ctx->r18, 0X40);
    // 0x0024B13C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x0024B140: jal         0x002150B0
    // 0x0024B144: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_002150B0(rdram, ctx);
        goto after_4;
    // 0x0024B144: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x0024B148: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x0024B14C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024B150: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0024B154: jal         0x002150B0
    // 0x0024B158: addiu       $a2, $s2, 0x50
    ctx->r6 = ADD32(ctx->r18, 0X50);
    func_002150B0(rdram, ctx);
        goto after_5;
    // 0x0024B158: addiu       $a2, $s2, 0x50
    ctx->r6 = ADD32(ctx->r18, 0X50);
    after_5:
    // 0x0024B15C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024B160: addiu       $s0, $s2, 0x78
    ctx->r16 = ADD32(ctx->r18, 0X78);
    // 0x0024B164: jal         0x0021525C
    // 0x0024B168: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0021525C(rdram, ctx);
        goto after_6;
    // 0x0024B168: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // 0x0024B16C: lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X34);
    // 0x0024B170: lw          $a2, 0x38($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X38);
    // 0x0024B174: lw          $a3, 0x3C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X3C);
    // 0x0024B178: jal         0x00214494
    // 0x0024B17C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00214494(rdram, ctx);
        goto after_7;
    // 0x0024B17C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x0024B180: lui         $a1, 0x469C
    ctx->r5 = S32(0X469C << 16);
    // 0x0024B184: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x0024B188: jal         0x00213658
    // 0x0024B18C: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_00213658(rdram, ctx);
        goto after_8;
    // 0x0024B18C: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_8:
    // 0x0024B190: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x0024B194: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x0024B198: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    // 0x0024B19C: jal         0x00214460
    // 0x0024B1A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00214460(rdram, ctx);
        goto after_9;
    // 0x0024B1A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x0024B1A4: jal         0x00214D84
    // 0x0024B1A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00214D84(rdram, ctx);
        goto after_10;
    // 0x0024B1A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x0024B1AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x0024B1B0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x0024B1B4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x0024B1B8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x0024B1BC: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x0024B1C0: jr          $ra
    // 0x0024B1C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x0024B1C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_0024B070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024B070: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x0024B074: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x0024B078: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x0024B07C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x0024B080: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x0024B084: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x0024B088: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x0024B08C: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x0024B090: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x0024B094: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0024B098: bne         $v1, $v0, L_0024B0E4
    if (ctx->r3 != ctx->r2) {
        // 0x0024B09C: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_0024B0E4;
    }
    // 0x0024B09C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x0024B0A0: lwc1        $f12, 0x70($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X70);
    // 0x0024B0A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B0A8: lwc1        $f20, -0x7100($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7100);
    // 0x0024B0AC: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x0024B0B0: jal         0x0029A570
    // 0x0024B0B4: nop

    func_0029A570(rdram, ctx);
        goto after_0;
    // 0x0024B0B4: nop

    after_0:
    // 0x0024B0B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0024B0BC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x0024B0C0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x0024B0C4: lwc1        $f12, 0x70($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X70);
    // 0x0024B0C8: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x0024B0CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x0024B0D0: swc1        $f0, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = ctx->f0.u32l;
    // 0x0024B0D4: jal         0x00299758
    // 0x0024B0D8: nop

    func_00299758(rdram, ctx);
        goto after_1;
    // 0x0024B0D8: nop

    after_1:
    // 0x0024B0DC: j           L_0024B104
    // 0x0024B0E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_0024B104;
    // 0x0024B0E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_0024B0E4:
    // 0x0024B0E4: lwc1        $f0, 0x84($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X84);
    // 0x0024B0E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B0EC: lwc1        $f12, -0x70FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X70FC);
    // 0x0024B0F0: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x0024B0F4: jal         0x0029A570
    // 0x0024B0F8: nop

    func_0029A570(rdram, ctx);
        goto after_2;
    // 0x0024B0F8: nop

    after_2:
    // 0x0024B0FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x0024B100: swc1        $f0, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = ctx->f0.u32l;
L_0024B104:
    // 0x0024B104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x0024B108: lwc1        $f0, 0x33C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X33C4);
    // 0x0024B10C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B110: lwc1        $f12, -0x70F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X70F8);
    // 0x0024B114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0024B118: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x0024B11C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x0024B120: lwc1        $f0, 0x84($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X84);
    // 0x0024B124: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x0024B128: jal         0x00299758
    // 0x0024B12C: nop

    func_00299758(rdram, ctx);
        goto after_3;
    // 0x0024B12C: nop

    after_3:
    // 0x0024B130: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x0024B134: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024B138: addiu       $a1, $s2, 0x40
    ctx->r5 = ADD32(ctx->r18, 0X40);
    // 0x0024B13C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x0024B140: jal         0x002150B0
    // 0x0024B144: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_002150B0(rdram, ctx);
        goto after_4;
    // 0x0024B144: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x0024B148: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x0024B14C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024B150: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0024B154: jal         0x002150B0
    // 0x0024B158: addiu       $a2, $s2, 0x50
    ctx->r6 = ADD32(ctx->r18, 0X50);
    func_002150B0(rdram, ctx);
        goto after_5;
    // 0x0024B158: addiu       $a2, $s2, 0x50
    ctx->r6 = ADD32(ctx->r18, 0X50);
    after_5:
    // 0x0024B15C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024B160: addiu       $s0, $s2, 0x78
    ctx->r16 = ADD32(ctx->r18, 0X78);
    // 0x0024B164: jal         0x0021525C
    // 0x0024B168: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0021525C(rdram, ctx);
        goto after_6;
    // 0x0024B168: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // 0x0024B16C: lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X34);
    // 0x0024B170: lw          $a2, 0x38($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X38);
    // 0x0024B174: lw          $a3, 0x3C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X3C);
    // 0x0024B178: jal         0x00214494
    // 0x0024B17C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00214494(rdram, ctx);
        goto after_7;
    // 0x0024B17C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x0024B180: lui         $a1, 0x469C
    ctx->r5 = S32(0X469C << 16);
    // 0x0024B184: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x0024B188: jal         0x00213658
    // 0x0024B18C: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_00213658(rdram, ctx);
        goto after_8;
    // 0x0024B18C: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_8:
    // 0x0024B190: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x0024B194: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x0024B198: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    // 0x0024B19C: jal         0x00214460
    // 0x0024B1A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00214460(rdram, ctx);
        goto after_9;
    // 0x0024B1A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x0024B1A4: jal         0x00214D84
    // 0x0024B1A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00214D84(rdram, ctx);
        goto after_10;
    // 0x0024B1A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x0024B1AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x0024B1B0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x0024B1B4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x0024B1B8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x0024B1BC: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x0024B1C0: jr          $ra
    // 0x0024B1C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x0024B1C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_0024B1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024B1C8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x0024B1CC: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x0024B1D0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x0024B1D4: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x0024B1D8: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x0024B1DC: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x0024B1E0: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x0024B1E4: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x0024B1E8: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x0024B1EC: sdc1        $f21, 0xA0($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0XA0, ctx->r29);
    // 0x0024B1F0: sdc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X98, ctx->r29);
    // 0x0024B1F4: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x0024B1F8: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x0024B1FC: addiu       $s2, $v0, 0x14
    ctx->r18 = ADD32(ctx->r2, 0X14);
    // 0x0024B200: lwc1        $f2, 0x50($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X50);
    // 0x0024B204: lwc1        $f20, 0x60($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X60);
    // 0x0024B208: c.eq.s      $f2, $f1
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f2.fl == ctx->f1.fl;
    // 0x0024B20C: nop

    // 0x0024B210: bc1f        L_0024B22C
    if (!c1cs) {
        // 0x0024B214: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_0024B22C;
    }
    // 0x0024B214: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x0024B218: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x0024B21C: c.eq.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl == ctx->f1.fl;
    // 0x0024B220: nop

    // 0x0024B224: bc1t        L_0024B248
    if (c1cs) {
        // 0x0024B228: mov.s       $f21, $f1
        CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 1);
    ctx->f21.fl = ctx->f1.fl;
            goto L_0024B248;
    }
    // 0x0024B228: mov.s       $f21, $f1
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 1);
    ctx->f21.fl = ctx->f1.fl;
L_0024B22C:
    // 0x0024B22C: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x0024B230: lwc1        $f12, 0x4C($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x0024B234: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x0024B238: jal         0x0029A6F0
    // 0x0024B23C: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    func_0029A6F0(rdram, ctx);
        goto after_0;
    // 0x0024B23C: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    after_0:
    // 0x0024B240: lwc1        $f1, 0x58($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X58);
    // 0x0024B244: div.s       $f21, $f1, $f0
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f21.fl = DIV_S(ctx->f1.fl, ctx->f0.fl);
L_0024B248:
    // 0x0024B248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024B24C: beq         $s0, $v0, L_0024B26C
    if (ctx->r16 == ctx->r2) {
        // 0x0024B250: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_0024B26C;
    }
    // 0x0024B250: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x0024B254: bne         $v0, $zero, L_0024B38C
    if (ctx->r2 != 0) {
        // 0x0024B258: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_0024B38C;
    }
    // 0x0024B258: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x0024B25C: beq         $s0, $v0, L_0024B2E0
    if (ctx->r16 == ctx->r2) {
        // 0x0024B260: nop
    
            goto L_0024B2E0;
    }
    // 0x0024B260: nop

    // 0x0024B264: j           L_0024B38C
    // 0x0024B268: nop

        goto L_0024B38C;
    // 0x0024B268: nop

L_0024B26C:
    // 0x0024B26C: lb          $v0, 0x33($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X33);
    // 0x0024B270: bne         $v0, $s0, L_0024B27C
    if (ctx->r2 != ctx->r16) {
        // 0x0024B274: mov.s       $f14, $f21
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
            goto L_0024B27C;
    }
    // 0x0024B274: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
    // 0x0024B278: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_0024B27C:
    // 0x0024B27C: lwc1        $f12, 0x158($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X158);
    // 0x0024B280: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x0024B284: jal         0x00215814
    // 0x0024B288: nop

    func_00215814(rdram, ctx);
        goto after_1;
    // 0x0024B288: nop

    after_1:
    // 0x0024B28C: lb          $v0, 0x33($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X33);
    // 0x0024B290: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x0024B294: bne         $v0, $zero, L_0024B2C0
    if (ctx->r2 != 0) {
        // 0x0024B298: swc1        $f0, 0x158($s3)
        MEM_W(0X158, ctx->r19) = ctx->f0.u32l;
            goto L_0024B2C0;
    }
    // 0x0024B298: swc1        $f0, 0x158($s3)
    MEM_W(0X158, ctx->r19) = ctx->f0.u32l;
    // 0x0024B29C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B2A0: lwc1        $f0, -0x70F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70F4);
    // 0x0024B2A4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x0024B2A8: nop

    // 0x0024B2AC: bc1f        L_0024B398
    if (!c1cs) {
        // 0x0024B2B0: nop
    
            goto L_0024B398;
    }
    // 0x0024B2B0: nop

    // 0x0024B2B4: sw          $zero, 0x158($s3)
    MEM_W(0X158, ctx->r19) = 0;
    // 0x0024B2B8: j           L_0024B398
    // 0x0024B2BC: sb          $s0, 0x33($s3)
    MEM_B(0X33, ctx->r19) = ctx->r16;
        goto L_0024B398;
    // 0x0024B2BC: sb          $s0, 0x33($s3)
    MEM_B(0X33, ctx->r19) = ctx->r16;
L_0024B2C0:
    // 0x0024B2C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x0024B2C4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x0024B2C8: nop

    // 0x0024B2CC: bc1f        L_0024B38C
    if (!c1cs) {
        // 0x0024B2D0: nop
    
            goto L_0024B38C;
    }
    // 0x0024B2D0: nop

    // 0x0024B2D4: swc1        $f0, 0x158($s3)
    MEM_W(0X158, ctx->r19) = ctx->f0.u32l;
    // 0x0024B2D8: j           L_0024B38C
    // 0x0024B2DC: sb          $zero, 0x33($s3)
    MEM_B(0X33, ctx->r19) = 0;
        goto L_0024B38C;
    // 0x0024B2DC: sb          $zero, 0x33($s3)
    MEM_B(0X33, ctx->r19) = 0;
L_0024B2E0:
    // 0x0024B2E0: beq         $s4, $zero, L_0024B38C
    if (ctx->r20 == 0) {
        // 0x0024B2E4: nop
    
            goto L_0024B38C;
    }
    // 0x0024B2E4: nop

    // 0x0024B2E8: lwc1        $f0, 0x54($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X54);
    // 0x0024B2EC: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x0024B2F0: c.eq.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl == ctx->f1.fl;
    // 0x0024B2F4: nop

    // 0x0024B2F8: bc1tl       L_0024B34C
    if (c1cs) {
        // 0x0024B2FC: sub.s       $f14, $f1, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f1.fl - ctx->f20.fl;
            goto L_0024B34C;
    }
    goto skip_0;
    // 0x0024B2FC: sub.s       $f14, $f1, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f1.fl - ctx->f20.fl;
    skip_0:
    // 0x0024B300: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x0024B304: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0024B308: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x0024B30C: jal         0x00213074
    // 0x0024B310: addiu       $a2, $s3, 0x88
    ctx->r6 = ADD32(ctx->r19, 0X88);
    func_00213074(rdram, ctx);
        goto after_2;
    // 0x0024B310: addiu       $a2, $s3, 0x88
    ctx->r6 = ADD32(ctx->r19, 0X88);
    after_2:
    // 0x0024B314: lwc1        $f0, 0x54($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X54);
    // 0x0024B318: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x0024B31C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x0024B320: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x0024B324: jal         0x002146EC
    // 0x0024B328: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_002146EC(rdram, ctx);
        goto after_3;
    // 0x0024B328: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x0024B32C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024B330: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0024B334: jal         0x002139A4
    // 0x0024B338: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_002139A4(rdram, ctx);
        goto after_4;
    // 0x0024B338: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x0024B33C: lwc1        $f1, 0x38($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x0024B340: lwc1        $f0, 0x50($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X50);
    // 0x0024B344: div.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = DIV_S(ctx->f1.fl, ctx->f0.fl);
    // 0x0024B348: sub.s       $f14, $f1, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f1.fl - ctx->f20.fl;
L_0024B34C:
    // 0x0024B34C: c.lt.s      $f21, $f14
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f21.fl < ctx->f14.fl;
    // 0x0024B350: nop

    // 0x0024B354: bc1fl       L_0024B364
    if (!c1cs) {
        // 0x0024B358: neg.s       $f1, $f21
        CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f21.fl); 
    ctx->f1.fl = -ctx->f21.fl;
            goto L_0024B364;
    }
    goto skip_1;
    // 0x0024B358: neg.s       $f1, $f21
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f21.fl); 
    ctx->f1.fl = -ctx->f21.fl;
    skip_1:
    // 0x0024B35C: j           L_0024B374
    // 0x0024B360: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
        goto L_0024B374;
    // 0x0024B360: mov.s       $f14, $f21
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 21);
    ctx->f14.fl = ctx->f21.fl;
L_0024B364:
    // 0x0024B364: c.lt.s      $f14, $f1
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f14.fl < ctx->f1.fl;
    // 0x0024B368: nop

    // 0x0024B36C: bc1tl       L_0024B374
    if (c1cs) {
        // 0x0024B370: mov.s       $f14, $f1
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 1);
    ctx->f14.fl = ctx->f1.fl;
            goto L_0024B374;
    }
    goto skip_2;
    // 0x0024B370: mov.s       $f14, $f1
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 1);
    ctx->f14.fl = ctx->f1.fl;
    skip_2:
L_0024B374:
    // 0x0024B374: lwc1        $f12, 0x158($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X158);
    // 0x0024B378: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x0024B37C: jal         0x00215814
    // 0x0024B380: nop

    func_00215814(rdram, ctx);
        goto after_5;
    // 0x0024B380: nop

    after_5:
    // 0x0024B384: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x0024B388: swc1        $f0, 0x158($s3)
    MEM_W(0X158, ctx->r19) = ctx->f0.u32l;
L_0024B38C:
    // 0x0024B38C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B390: lwc1        $f0, -0x70F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70F0);
    // 0x0024B394: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_0024B398:
    // 0x0024B398: nop

    // 0x0024B39C: bc1tl       L_0024B3BC
    if (c1cs) {
        // 0x0024B3A0: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_0024B3BC;
    }
    goto skip_3;
    // 0x0024B3A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_3:
    // 0x0024B3A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x0024B3A8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x0024B3AC: nop

    // 0x0024B3B0: bc1fl       L_0024B3C0
    if (!c1cs) {
        // 0x0024B3B4: swc1        $f20, 0x60($s3)
        MEM_W(0X60, ctx->r19) = ctx->f20.u32l;
            goto L_0024B3C0;
    }
    goto skip_4;
    // 0x0024B3B4: swc1        $f20, 0x60($s3)
    MEM_W(0X60, ctx->r19) = ctx->f20.u32l;
    skip_4:
    // 0x0024B3B8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_0024B3BC:
    // 0x0024B3BC: swc1        $f20, 0x60($s3)
    MEM_W(0X60, ctx->r19) = ctx->f20.u32l;
L_0024B3C0:
    // 0x0024B3C0: lw          $v1, 0x88($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X88);
    // 0x0024B3C4: lw          $t0, 0x8C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X8C);
    // 0x0024B3C8: lw          $t1, 0x90($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X90);
    // 0x0024B3CC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x0024B3D0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x0024B3D4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x0024B3D8: lwc1        $f12, 0x54($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X54);
    // 0x0024B3DC: jal         0x0029A570
    // 0x0024B3E0: addiu       $s0, $s3, 0x88
    ctx->r16 = ADD32(ctx->r19, 0X88);
    func_0029A570(rdram, ctx);
        goto after_6;
    // 0x0024B3E0: addiu       $s0, $s3, 0x88
    ctx->r16 = ADD32(ctx->r19, 0X88);
    after_6:
    // 0x0024B3E4: lwc1        $f1, 0x50($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X50);
    // 0x0024B3E8: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x0024B3EC: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x0024B3F0: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x0024B3F4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x0024B3F8: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x0024B3FC: lwc1        $f1, 0x4C($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X4C);
    // 0x0024B400: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x0024B404: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x0024B408: lwc1        $f12, 0x54($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X54);
    // 0x0024B40C: jal         0x00299758
    // 0x0024B410: nop

    func_00299758(rdram, ctx);
        goto after_7;
    // 0x0024B410: nop

    after_7:
    // 0x0024B414: lwc1        $f1, 0x50($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, 0X50);
    // 0x0024B418: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x0024B41C: addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    // 0x0024B420: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x0024B424: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x0024B428: add.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f1.fl;
    // 0x0024B42C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x0024B430: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x0024B434: jal         0x002130D4
    // 0x0024B438: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_002130D4(rdram, ctx);
        goto after_8;
    // 0x0024B438: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x0024B43C: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x0024B440: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x0024B444: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x0024B448: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x0024B44C: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x0024B450: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x0024B454: ldc1        $f21, 0xA0($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0XA0);
    // 0x0024B458: ldc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X98);
    // 0x0024B45C: jr          $ra
    // 0x0024B460: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x0024B460: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_0024B464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0024B464: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x0024B468: sw          $s3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r19;
    // 0x0024B46C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x0024B470: sw          $s4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r20;
    // 0x0024B474: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x0024B478: sw          $ra, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r31;
    // 0x0024B47C: sw          $s5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r21;
    // 0x0024B480: sw          $s2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r18;
    // 0x0024B484: sw          $s1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r17;
    // 0x0024B488: sw          $s0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r16;
    // 0x0024B48C: sdc1        $f22, 0x108($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X108, ctx->r29);
    // 0x0024B490: sdc1        $f21, 0x100($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X100, ctx->r29);
    // 0x0024B494: sdc1        $f20, 0xF8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XF8, ctx->r29);
    // 0x0024B498: lwc1        $f1, 0x70($s3)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r19, 0X70);
    // 0x0024B49C: lwc1        $f0, 0x84($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X84);
    // 0x0024B4A0: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x0024B4A4: sub.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x0024B4A8: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x0024B4AC: addiu       $s1, $v0, 0x14
    ctx->r17 = ADD32(ctx->r2, 0X14);
    // 0x0024B4B0: jal         0x00215038
    // 0x0024B4B4: swc1        $f1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    func_00215038(rdram, ctx);
        goto after_0;
    // 0x0024B4B4: swc1        $f1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    after_0:
    // 0x0024B4B8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0024B4BC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x0024B4C0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x0024B4C4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x0024B4C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0024B4CC: jal         0x00241C14
    // 0x0024B4D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00241C14(rdram, ctx);
        goto after_1;
    // 0x0024B4D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x0024B4D4: lw          $s2, 0x74($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X74);
    // 0x0024B4D8: beq         $s2, $zero, L_0024B6A0
    if (ctx->r18 == 0) {
        // 0x0024B4DC: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_0024B6A0;
    }
    // 0x0024B4DC: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x0024B4E0: lwc1        $f1, 0x58($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X58);
    // 0x0024B4E4: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x0024B4E8: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x0024B4EC: nop

    // 0x0024B4F0: bc1f        L_0024B6A4
    if (!c1cs) {
        // 0x0024B4F4: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0024B6A4;
    }
    // 0x0024B4F4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0024B4F8: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x0024B4FC: lwc1        $f3, 0x20($sp)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x0024B500: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x0024B504: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B508: lwc1        $f2, -0x70EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70EC);
    // 0x0024B50C: c.lt.s      $f3, $f1
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f3.fl < ctx->f1.fl;
    // 0x0024B510: mul.s       $f1, $f0, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x0024B514: bc1f        L_0024B538
    if (!c1cs) {
        // 0x0024B518: nop
    
            goto L_0024B538;
    }
    // 0x0024B518: nop

    // 0x0024B51C: neg.s       $f0, $f3
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f3.fl); 
    ctx->f0.fl = -ctx->f3.fl;
    // 0x0024B520: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x0024B524: nop

    // 0x0024B528: bc1f        L_0024B6A8
    if (!c1cs) {
        // 0x0024B52C: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_0024B6A8;
    }
    // 0x0024B52C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x0024B530: j           L_0024B548
    // 0x0024B534: nop

        goto L_0024B548;
    // 0x0024B534: nop

L_0024B538:
    // 0x0024B538: c.lt.s      $f3, $f1
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f3.fl < ctx->f1.fl;
    // 0x0024B53C: nop

    // 0x0024B540: bc1f        L_0024B6A4
    if (!c1cs) {
        // 0x0024B544: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0024B6A4;
    }
    // 0x0024B544: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0024B548:
    // 0x0024B548: lwc1        $f1, 0x58($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X58);
    // 0x0024B54C: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    // 0x0024B550: c.le.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl <= ctx->f0.fl;
    // 0x0024B554: nop

    // 0x0024B558: bc1f        L_0024B5B0
    if (!c1cs) {
        // 0x0024B55C: nop
    
            goto L_0024B5B0;
    }
    // 0x0024B55C: nop

    // 0x0024B560: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x0024B564: lwc1        $f3, 0x20($sp)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x0024B568: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x0024B56C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B570: lwc1        $f2, -0x70E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X70E8);
    // 0x0024B574: c.lt.s      $f3, $f1
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f3.fl < ctx->f1.fl;
    // 0x0024B578: mul.s       $f1, $f0, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f1.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x0024B57C: bc1f        L_0024B5A0
    if (!c1cs) {
        // 0x0024B580: nop
    
            goto L_0024B5A0;
    }
    // 0x0024B580: nop

    // 0x0024B584: neg.s       $f0, $f3
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f3.fl); 
    ctx->f0.fl = -ctx->f3.fl;
    // 0x0024B588: c.lt.s      $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f0.fl < ctx->f1.fl;
    // 0x0024B58C: nop

    // 0x0024B590: bc1tl       L_0024B5B0
    if (c1cs) {
        // 0x0024B594: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_0024B5B0;
    }
    goto skip_0;
    // 0x0024B594: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    skip_0:
    // 0x0024B598: j           L_0024B5B0
    // 0x0024B59C: nop

        goto L_0024B5B0;
    // 0x0024B59C: nop

L_0024B5A0:
    // 0x0024B5A0: c.lt.s      $f3, $f1
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f3.fl < ctx->f1.fl;
    // 0x0024B5A4: nop

    // 0x0024B5A8: bc1tl       L_0024B5B0
    if (c1cs) {
        // 0x0024B5AC: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_0024B5B0;
    }
    goto skip_1;
    // 0x0024B5AC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    skip_1:
L_0024B5B0:
    // 0x0024B5B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B5B4: lwc1        $f21, -0x70E4($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X70E4);
    // 0x0024B5B8: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x0024B5BC: lw          $t0, 0x8($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X8);
    // 0x0024B5C0: lw          $t1, 0xC($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XC);
    // 0x0024B5C4: sw          $v1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r3;
    // 0x0024B5C8: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    // 0x0024B5CC: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x0024B5D0: jal         0x00227FEC
    // 0x0024B5D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00227FEC(rdram, ctx);
        goto after_2;
    // 0x0024B5D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_2:
    // 0x0024B5D8: mul.s       $f0, $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f21.fl);
    // 0x0024B5DC: lwc1        $f1, 0xA4($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0XA4);
    // 0x0024B5E0: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x0024B5E4: swc1        $f1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x0024B5E8: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x0024B5EC: lw          $t0, 0x8($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X8);
    // 0x0024B5F0: lw          $t1, 0xC($s2)
    ctx->r9 = MEM_W(ctx->r18, 0XC);
    // 0x0024B5F4: sw          $v1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r3;
    // 0x0024B5F8: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x0024B5FC: sw          $t1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r9;
    // 0x0024B600: jal         0x00227FEC
    // 0x0024B604: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_00227FEC(rdram, ctx);
        goto after_3;
    // 0x0024B604: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x0024B608: mul.s       $f0, $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f21.fl);
    // 0x0024B60C: addiu       $s0, $sp, 0xC0
    ctx->r16 = ADD32(ctx->r29, 0XC0);
    // 0x0024B610: lwc1        $f1, 0xB4($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0XB4);
    // 0x0024B614: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0024B618: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x0024B61C: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x0024B620: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x0024B624: jal         0x00213074
    // 0x0024B628: swc1        $f1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    func_00213074(rdram, ctx);
        goto after_4;
    // 0x0024B628: swc1        $f1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    after_4:
    // 0x0024B62C: jal         0x00213708
    // 0x0024B630: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00213708(rdram, ctx);
        goto after_5;
    // 0x0024B630: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x0024B634: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x0024B638: lwc1        $f1, 0x38($s1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r17, 0X38);
    // 0x0024B63C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0024B640: lwc1        $f0, -0x70E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X70E0);
    // 0x0024B644: lwc1        $f20, 0x20($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X20);
    // 0x0024B648: c.lt.s      $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f1.fl < ctx->f0.fl;
    // 0x0024B64C: nop

    // 0x0024B650: bc1fl       L_0024B690
    if (!c1cs) {
        // 0x0024B654: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0024B690;
    }
    goto skip_2;
    // 0x0024B654: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    skip_2:
    // 0x0024B658: mul.s       $f0, $f1, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f0.fl = MUL_S(ctx->f1.fl, ctx->f21.fl);
    // 0x0024B65C: lwc1        $f1, 0xD0($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x0024B660: add.s       $f2, $f1, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f1.fl + ctx->f20.fl;
    // 0x0024B664: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x0024B668: nop

    // 0x0024B66C: bc1tl       L_0024B68C
    if (c1cs) {
        // 0x0024B670: sub.s       $f20, $f0, $f1
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f1.fl;
            goto L_0024B68C;
    }
    goto skip_3;
    // 0x0024B670: sub.s       $f20, $f0, $f1
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f1.fl;
    skip_3:
    // 0x0024B674: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x0024B678: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x0024B67C: nop

    // 0x0024B680: bc1f        L_0024B690
    if (!c1cs) {
        // 0x0024B684: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0024B690;
    }
    // 0x0024B684: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0024B688: sub.s       $f20, $f0, $f1
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f1.fl;
L_0024B68C:
    // 0x0024B68C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0024B690:
    // 0x0024B690: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x0024B694: lbu         $a2, 0x60($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X60);
    // 0x0024B698: j           L_0024B6BC
    // 0x0024B69C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
        goto L_0024B6BC;
    // 0x0024B69C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
L_0024B6A0:
    // 0x0024B6A0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0024B6A4:
    // 0x0024B6A4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
L_0024B6A8:
    // 0x0024B6A8: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x0024B6AC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x0024B6B0: lwc1        $f0, 0xD0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x0024B6B4: lbu         $a2, 0x61($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X61);
    // 0x0024B6B8: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_0024B6BC:
    // 0x0024B6BC: jal         0x0024B1C8
    // 0x0024B6C0: nop

    func_0024B1C8(rdram, ctx);
        goto after_6;
    // 0x0024B6C0: nop

    after_6:
    // 0x0024B6C4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0024B6C8: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x0024B6CC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x0024B6D0: jal         0x0024197C
    // 0x0024B6D4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_0024197C(rdram, ctx);
        goto after_7;
    // 0x0024B6D4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_7:
    // 0x0024B6D8: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x0024B6DC: lwc1        $f12, 0x154($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X154);
    // 0x0024B6E0: jal         0x00215814
    // 0x0024B6E4: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_00215814(rdram, ctx);
        goto after_8;
    // 0x0024B6E4: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_8:
    // 0x0024B6E8: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x0024B6EC: swc1        $f0, 0x154($s4)
    MEM_W(0X154, ctx->r20) = ctx->f0.u32l;
    // 0x0024B6F0: lw          $ra, 0xF0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF0);
    // 0x0024B6F4: lw          $s5, 0xEC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XEC);
    // 0x0024B6F8: lw          $s4, 0xE8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XE8);
    // 0x0024B6FC: lw          $s3, 0xE4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XE4);
    // 0x0024B700: lw          $s2, 0xE0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE0);
    // 0x0024B704: lw          $s1, 0xDC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XDC);
    // 0x0024B708: lw          $s0, 0xD8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD8);
    // 0x0024B70C: ldc1        $f22, 0x108($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X108);
    // 0x0024B710: ldc1        $f21, 0x100($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X100);
    // 0x0024B714: ldc1        $f20, 0xF8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XF8);
    // 0x0024B718: jr          $ra
    // 0x0024B71C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x0024B71C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
