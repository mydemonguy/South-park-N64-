#include "sp_recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_0040E3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040E3C8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x0040E3CC: lw          $v0, 0x1DF0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1DF0);
    // 0x0040E3D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0040E3D4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0040E3D8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0040E3DC: bne         $v0, $zero, L_0040E4B4
    if (ctx->r2 != 0) {
        // 0x0040E3E0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_0040E4B4;
    }
    // 0x0040E3E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0040E3E4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x0040E3E8: lw          $v0, 0x40CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40CC);
    // 0x0040E3EC: beq         $v0, $zero, L_0040E410
    if (ctx->r2 == 0) {
        // 0x0040E3F0: nop
    
            goto L_0040E410;
    }
    // 0x0040E3F0: nop

    // 0x0040E3F4: lw          $v0, 0x334($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X334);
    // 0x0040E3F8: beq         $v0, $zero, L_0040E410
    if (ctx->r2 == 0) {
        // 0x0040E3FC: nop
    
            goto L_0040E410;
    }
    // 0x0040E3FC: nop

    // 0x0040E400: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x0040E404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040E408: beq         $v1, $v0, L_0040E4B8
    if (ctx->r3 == ctx->r2) {
        // 0x0040E40C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0040E4B8;
    }
    // 0x0040E40C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040E410:
    // 0x0040E410: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x0040E414: lw          $a0, 0x40CC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40CC);
    // 0x0040E418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040E41C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E420: sw          $v0, 0x1DF0($at)
    MEM_W(0X1DF0, ctx->r1) = ctx->r2;
    // 0x0040E424: beq         $a0, $zero, L_0040E4B4
    if (ctx->r4 == 0) {
        // 0x0040E428: addiu       $a2, $zero, -0x1
        ctx->r6 = ADD32(0, -0X1);
            goto L_0040E4B4;
    }
    // 0x0040E428: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x0040E42C: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x0040E430: jal         0x0023CF9C
    // 0x0040E434: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_0023CF9C(rdram, ctx);
        goto after_0;
    // 0x0040E434: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x0040E438: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x0040E43C: addiu       $v1, $v1, 0x2A80
    ctx->r3 = ADD32(ctx->r3, 0X2A80);
    // 0x0040E440: lw          $v0, 0xF4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XF4);
    // 0x0040E444: blez        $v0, L_0040E4B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x0040E448: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_0040E4B4;
    }
    // 0x0040E448: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x0040E44C: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
L_0040E450:
    // 0x0040E450: lw          $v0, 0xEC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XEC);
    // 0x0040E454: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x0040E458: beq         $v1, $zero, L_0040E498
    if (ctx->r3 == 0) {
        // 0x0040E45C: nop
    
            goto L_0040E498;
    }
    // 0x0040E45C: nop

    // 0x0040E460: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x0040E464: lw          $v0, 0x40CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40CC);
    // 0x0040E468: beq         $v1, $v0, L_0040E498
    if (ctx->r3 == ctx->r2) {
        // 0x0040E46C: nop
    
            goto L_0040E498;
    }
    // 0x0040E46C: nop

    // 0x0040E470: lhu         $v0, 0xD8($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XD8);
    // 0x0040E474: addiu       $v0, $v0, -0x65
    ctx->r2 = ADD32(ctx->r2, -0X65);
    // 0x0040E478: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x0040E47C: beq         $v0, $zero, L_0040E498
    if (ctx->r2 == 0) {
        // 0x0040E480: nop
    
            goto L_0040E498;
    }
    // 0x0040E480: nop

    // 0x0040E484: lw          $a0, 0x334($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X334);
    // 0x0040E488: lui         $a2, 0x466A
    ctx->r6 = S32(0X466A << 16);
    // 0x0040E48C: ori         $a2, $a2, 0x2400
    ctx->r6 = ctx->r6 | 0X2400;
    // 0x0040E490: jal         0x0023D1F0
    // 0x0040E494: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_0023D1F0(rdram, ctx);
        goto after_1;
    // 0x0040E494: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
L_0040E498:
    // 0x0040E498: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x0040E49C: addiu       $v1, $v1, 0x2A80
    ctx->r3 = ADD32(ctx->r3, 0X2A80);
    // 0x0040E4A0: lw          $v0, 0xF4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XF4);
    // 0x0040E4A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x0040E4A8: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040E4AC: bne         $v0, $zero, L_0040E450
    if (ctx->r2 != 0) {
        // 0x0040E4B0: addiu       $s1, $s1, 0x368
        ctx->r17 = ADD32(ctx->r17, 0X368);
            goto L_0040E450;
    }
    // 0x0040E4B0: addiu       $s1, $s1, 0x368
    ctx->r17 = ADD32(ctx->r17, 0X368);
L_0040E4B4:
    // 0x0040E4B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040E4B8:
    // 0x0040E4B8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x0040E4BC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0040E4C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0040E4C4: jr          $ra
    // 0x0040E4C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0040E4C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_0040E4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040E4CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E4D0: lwc1        $f0, -0x29A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X29A8);
    // 0x0040E4D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040E4D8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E4DC: sw          $zero, 0x1DF0($at)
    MEM_W(0X1DF0, ctx->r1) = 0;
    // 0x0040E4E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E4E4: sw          $zero, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = 0;
    // 0x0040E4E8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E4EC: sw          $v0, 0x40C8($at)
    MEM_W(0X40C8, ctx->r1) = ctx->r2;
    // 0x0040E4F0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E4F4: swc1        $f0, 0x1DF4($at)
    MEM_W(0X1DF4, ctx->r1) = ctx->f0.u32l;
    // 0x0040E4F8: jr          $ra
    // 0x0040E4FC: nop

    return;
    // 0x0040E4FC: nop

;}
RECOMP_FUNC void func_0040E500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040E500: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x0040E504: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x0040E508: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x0040E50C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x0040E510: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x0040E514: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x0040E518: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x0040E51C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x0040E520: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x0040E524: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x0040E528: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x0040E52C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x0040E530: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x0040E534: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x0040E538: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x0040E53C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
L_0040E540:
    // 0x0040E540: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x0040E544: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x0040E548: lw          $v0, 0x3EB0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X3EB0);
    // 0x0040E54C: beql        $v0, $zero, L_0040E560
    if (ctx->r2 == 0) {
        // 0x0040E550: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_0040E560;
    }
    goto skip_0;
    // 0x0040E550: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x0040E554: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x0040E558: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x0040E55C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_0040E560:
    // 0x0040E560: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x0040E564: bne         $v0, $zero, L_0040E540
    if (ctx->r2 != 0) {
        // 0x0040E568: addiu       $a1, $a1, 0x230
        ctx->r5 = ADD32(ctx->r5, 0X230);
            goto L_0040E540;
    }
    // 0x0040E568: addiu       $a1, $a1, 0x230
    ctx->r5 = ADD32(ctx->r5, 0X230);
    // 0x0040E56C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x0040E570: lw          $v0, 0x1DF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1DF8);
    // 0x0040E574: beq         $v0, $zero, L_0040E5D4
    if (ctx->r2 == 0) {
        // 0x0040E578: nop
    
            goto L_0040E5D4;
    }
    // 0x0040E578: nop

    // 0x0040E57C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E580: lwc1        $f1, 0x1DFC($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X1DFC);
    // 0x0040E584: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x0040E588: c.eq.s      $f1, $f2
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f1.fl == ctx->f2.fl;
    // 0x0040E58C: nop

    // 0x0040E590: bc1t        L_0040E8A0
    if (c1cs) {
        // 0x0040E594: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0040E8A0;
    }
    // 0x0040E594: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x0040E598: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0040E59C: lwc1        $f0, -0x4968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4968);
    // 0x0040E5A0: sub.s       $f0, $f1, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f1.fl - ctx->f0.fl;
    // 0x0040E5A4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E5A8: swc1        $f0, 0x1DFC($at)
    MEM_W(0X1DFC, ctx->r1) = ctx->f0.u32l;
    // 0x0040E5AC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x0040E5B0: nop

    // 0x0040E5B4: bc1f        L_0040E8A0
    if (!c1cs) {
        // 0x0040E5B8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_0040E8A0;
    }
    // 0x0040E5B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0040E5BC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E5C0: swc1        $f2, 0x1DFC($at)
    MEM_W(0X1DFC, ctx->r1) = ctx->f2.u32l;
    // 0x0040E5C4: jal         0x004036A4
    // 0x0040E5C8: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    func_004036A4(rdram, ctx);
        goto after_0;
    // 0x0040E5C8: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    after_0:
    // 0x0040E5CC: j           L_0040E8A0
    // 0x0040E5D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_0040E8A0;
    // 0x0040E5D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_0040E5D4:
    // 0x0040E5D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x0040E5D8: lb          $v0, -0x2DC2($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2DC2);
    // 0x0040E5DC: blez        $v0, L_0040E89C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x0040E5E0: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_0040E89C;
    }
    // 0x0040E5E0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x0040E5E4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x0040E5E8: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x0040E5EC: lui         $s3, 0x8010
    ctx->r19 = S32(0X8010 << 16);
    // 0x0040E5F0: addiu       $s3, $s3, 0x40D0
    ctx->r19 = ADD32(ctx->r19, 0X40D0);
    // 0x0040E5F4: lui         $s4, 0x8010
    ctx->r20 = S32(0X8010 << 16);
    // 0x0040E5F8: addiu       $s4, $s4, 0x40D4
    ctx->r20 = ADD32(ctx->r20, 0X40D4);
    // 0x0040E5FC: addu        $s7, $s2, $zero
    ctx->r23 = ADD32(ctx->r18, 0);
L_0040E600:
    // 0x0040E600: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x0040E604: addiu       $a0, $a0, -0x2DAF
    ctx->r4 = ADD32(ctx->r4, -0X2DAF);
    // 0x0040E608: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x0040E60C: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x0040E610: addu        $s0, $s7, $a0
    ctx->r16 = ADD32(ctx->r23, ctx->r4);
    // 0x0040E614: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x0040E618: lb          $a0, 0x0($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X0);
    // 0x0040E61C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x0040E620: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x0040E624: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x0040E628: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x0040E62C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x0040E630: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x0040E634: addiu       $v1, $v1, 0x3EB0
    ctx->r3 = ADD32(ctx->r3, 0X3EB0);
    // 0x0040E638: bne         $a0, $zero, L_0040E7DC
    if (ctx->r4 != 0) {
        // 0x0040E63C: addu        $s1, $v0, $v1
        ctx->r17 = ADD32(ctx->r2, ctx->r3);
            goto L_0040E7DC;
    }
    // 0x0040E63C: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x0040E640: lb          $s6, 0x3($s0)
    ctx->r22 = MEM_B(ctx->r16, 0X3);
    // 0x0040E644: jal         0x0022CE74
    // 0x0040E648: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0022CE74(rdram, ctx);
        goto after_1;
    // 0x0040E648: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x0040E64C: beq         $v0, $zero, L_0040E6FC
    if (ctx->r2 == 0) {
        // 0x0040E650: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_0040E6FC;
    }
    // 0x0040E650: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x0040E654: lb          $v0, 0x3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X3);
    // 0x0040E658: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x0040E65C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x0040E660: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E664: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040E668: sb          $t0, 0x40E0($at)
    MEM_B(0X40E0, ctx->r1) = ctx->r8;
    // 0x0040E66C: lb          $a1, 0x3($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X3);
L_0040E670:
    // 0x0040E670: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E674: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040E678: lb          $v0, 0x1E64($at)
    ctx->r2 = MEM_B(ctx->r1, 0X1E64);
    // 0x0040E67C: beql        $v0, $a1, L_0040E694
    if (ctx->r2 == ctx->r5) {
        // 0x0040E680: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_0040E694;
    }
    goto skip_1;
    // 0x0040E680: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    skip_1:
    // 0x0040E684: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x0040E688: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x0040E68C: bne         $v0, $zero, L_0040E670
    if (ctx->r2 != 0) {
        // 0x0040E690: nop
    
            goto L_0040E670;
    }
    // 0x0040E690: nop

L_0040E694:
    // 0x0040E694: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0040E698: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x0040E69C: lw          $a1, -0x2DD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2DD8);
    // 0x0040E6A0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_0040E6A4:
    // 0x0040E6A4: bltzl       $a0, L_0040E6AC
    if (SIGNED(ctx->r4) < 0) {
        // 0x0040E6A8: addiu       $a0, $zero, 0x13
        ctx->r4 = ADD32(0, 0X13);
            goto L_0040E6AC;
    }
    goto skip_2;
    // 0x0040E6A8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    skip_2:
L_0040E6AC:
    // 0x0040E6AC: slti        $v0, $a0, 0x14
    ctx->r2 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x0040E6B0: beql        $v0, $zero, L_0040E6B8
    if (ctx->r2 == 0) {
        // 0x0040E6B4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_0040E6B8;
    }
    goto skip_3;
    // 0x0040E6B4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_3:
L_0040E6B8:
    // 0x0040E6B8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E6BC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x0040E6C0: lb          $v1, 0x1E64($at)
    ctx->r3 = MEM_B(ctx->r1, 0X1E64);
    // 0x0040E6C4: sllv        $v0, $s5, $v1
    ctx->r2 = S32(ctx->r21 << (ctx->r3 & 31));
    // 0x0040E6C8: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x0040E6CC: beq         $v0, $zero, L_0040E6E8
    if (ctx->r2 == 0) {
        // 0x0040E6D0: nop
    
            goto L_0040E6E8;
    }
    // 0x0040E6D0: nop

    // 0x0040E6D4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E6D8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040E6DC: lb          $v0, 0x40E0($at)
    ctx->r2 = MEM_B(ctx->r1, 0X40E0);
    // 0x0040E6E0: beq         $v0, $fp, L_0040E6F4
    if (ctx->r2 == ctx->r30) {
        // 0x0040E6E4: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040E6F4;
    }
    // 0x0040E6E4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0040E6E8:
    // 0x0040E6E8: beql        $a2, $zero, L_0040E6A4
    if (ctx->r6 == 0) {
        // 0x0040E6EC: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_0040E6A4;
    }
    goto skip_4;
    // 0x0040E6EC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    skip_4:
    // 0x0040E6F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040E6F4:
    // 0x0040E6F4: j           L_0040E7B8
    // 0x0040E6F8: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
        goto L_0040E7B8;
    // 0x0040E6F8: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_0040E6FC:
    // 0x0040E6FC: jal         0x0022CE8C
    // 0x0040E700: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0022CE8C(rdram, ctx);
        goto after_2;
    // 0x0040E700: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x0040E704: beq         $v0, $zero, L_0040E7C8
    if (ctx->r2 == 0) {
        // 0x0040E708: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_0040E7C8;
    }
    // 0x0040E708: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x0040E70C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x0040E710: lb          $v0, 0x3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X3);
    // 0x0040E714: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x0040E718: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E71C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040E720: sb          $t0, 0x40E0($at)
    MEM_B(0X40E0, ctx->r1) = ctx->r8;
    // 0x0040E724: lb          $a1, 0x3($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X3);
L_0040E728:
    // 0x0040E728: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E72C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040E730: lb          $v0, 0x1E64($at)
    ctx->r2 = MEM_B(ctx->r1, 0X1E64);
    // 0x0040E734: beql        $v0, $a1, L_0040E74C
    if (ctx->r2 == ctx->r5) {
        // 0x0040E738: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_0040E74C;
    }
    goto skip_5;
    // 0x0040E738: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    skip_5:
    // 0x0040E73C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x0040E740: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x0040E744: bne         $v0, $zero, L_0040E728
    if (ctx->r2 != 0) {
        // 0x0040E748: nop
    
            goto L_0040E728;
    }
    // 0x0040E748: nop

L_0040E74C:
    // 0x0040E74C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0040E750: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x0040E754: lw          $a1, -0x2DD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2DD8);
    // 0x0040E758: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_0040E75C:
    // 0x0040E75C: bltzl       $a0, L_0040E764
    if (SIGNED(ctx->r4) < 0) {
        // 0x0040E760: addiu       $a0, $zero, 0x13
        ctx->r4 = ADD32(0, 0X13);
            goto L_0040E764;
    }
    goto skip_6;
    // 0x0040E760: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    skip_6:
L_0040E764:
    // 0x0040E764: slti        $v0, $a0, 0x14
    ctx->r2 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x0040E768: beql        $v0, $zero, L_0040E770
    if (ctx->r2 == 0) {
        // 0x0040E76C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_0040E770;
    }
    goto skip_7;
    // 0x0040E76C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_7:
L_0040E770:
    // 0x0040E770: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E774: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x0040E778: lb          $v1, 0x1E64($at)
    ctx->r3 = MEM_B(ctx->r1, 0X1E64);
    // 0x0040E77C: sllv        $v0, $s5, $v1
    ctx->r2 = S32(ctx->r21 << (ctx->r3 & 31));
    // 0x0040E780: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x0040E784: beq         $v0, $zero, L_0040E7A0
    if (ctx->r2 == 0) {
        // 0x0040E788: nop
    
            goto L_0040E7A0;
    }
    // 0x0040E788: nop

    // 0x0040E78C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E790: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040E794: lb          $v0, 0x40E0($at)
    ctx->r2 = MEM_B(ctx->r1, 0X40E0);
    // 0x0040E798: beq         $v0, $fp, L_0040E7AC
    if (ctx->r2 == ctx->r30) {
        // 0x0040E79C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040E7AC;
    }
    // 0x0040E79C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0040E7A0:
    // 0x0040E7A0: beql        $a2, $zero, L_0040E75C
    if (ctx->r6 == 0) {
        // 0x0040E7A4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_0040E75C;
    }
    goto skip_8;
    // 0x0040E7A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_8:
    // 0x0040E7A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040E7AC:
    // 0x0040E7AC: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x0040E7B0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x0040E7B4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
L_0040E7B8:
    // 0x0040E7B8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E7BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040E7C0: sb          $s2, 0x40E0($at)
    MEM_B(0X40E0, ctx->r1) = ctx->r18;
    // 0x0040E7C4: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
L_0040E7C8:
    // 0x0040E7C8: lb          $v0, 0x3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X3);
    // 0x0040E7CC: beq         $v0, $s6, L_0040E7DC
    if (ctx->r2 == ctx->r22) {
        // 0x0040E7D0: addiu       $a0, $zero, 0x2EF
        ctx->r4 = ADD32(0, 0X2EF);
            goto L_0040E7DC;
    }
    // 0x0040E7D0: addiu       $a0, $zero, 0x2EF
    ctx->r4 = ADD32(0, 0X2EF);
    // 0x0040E7D4: jal         0x00273BFC
    // 0x0040E7D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_00273BFC(rdram, ctx);
        goto after_3;
    // 0x0040E7D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
L_0040E7DC:
    // 0x0040E7DC: jal         0x0022CE64
    // 0x0040E7E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0022CE64(rdram, ctx);
        goto after_4;
    // 0x0040E7E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x0040E7E4: beq         $v0, $zero, L_0040E80C
    if (ctx->r2 == 0) {
        // 0x0040E7E8: addiu       $a0, $zero, 0x2EE
        ctx->r4 = ADD32(0, 0X2EE);
            goto L_0040E80C;
    }
    // 0x0040E7E8: addiu       $a0, $zero, 0x2EE
    ctx->r4 = ADD32(0, 0X2EE);
    // 0x0040E7EC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E7F0: lwc1        $f0, -0x299C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X299C);
    // 0x0040E7F4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E7F8: sw          $s5, 0x1DF8($at)
    MEM_W(0X1DF8, ctx->r1) = ctx->r21;
    // 0x0040E7FC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E800: swc1        $f0, 0x1DFC($at)
    MEM_W(0X1DFC, ctx->r1) = ctx->f0.u32l;
    // 0x0040E804: jal         0x00273BFC
    // 0x0040E808: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_00273BFC(rdram, ctx);
        goto after_5;
    // 0x0040E808: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
L_0040E80C:
    // 0x0040E80C: jal         0x0022CE54
    // 0x0040E810: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0022CE54(rdram, ctx);
        goto after_6;
    // 0x0040E810: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x0040E814: beql        $v0, $zero, L_0040E880
    if (ctx->r2 == 0) {
        // 0x0040E818: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_0040E880;
    }
    goto skip_9;
    // 0x0040E818: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_9:
    // 0x0040E81C: lb          $v0, 0x0($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X0);
    // 0x0040E820: bne         $v0, $zero, L_0040E85C
    if (ctx->r2 != 0) {
        // 0x0040E824: addiu       $a0, $zero, 0x2EE
        ctx->r4 = ADD32(0, 0X2EE);
            goto L_0040E85C;
    }
    // 0x0040E824: addiu       $a0, $zero, 0x2EE
    ctx->r4 = ADD32(0, 0X2EE);
    // 0x0040E828: sb          $s5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r21;
    // 0x0040E82C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x0040E830: lbu         $v0, 0x40F4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40F4);
    // 0x0040E834: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x0040E838: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E83C: sb          $v0, 0x40F4($at)
    MEM_B(0X40F4, ctx->r1) = ctx->r2;
    // 0x0040E840: jal         0x00273BFC
    // 0x0040E844: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_00273BFC(rdram, ctx);
        goto after_7;
    // 0x0040E844: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x0040E848: lb          $a0, 0x3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X3);
    // 0x0040E84C: jal         0x0023D66C
    // 0x0040E850: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    func_0023D66C(rdram, ctx);
        goto after_8;
    // 0x0040E850: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    after_8:
    // 0x0040E854: j           L_0040E880
    // 0x0040E858: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_0040E880;
    // 0x0040E858: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_0040E85C:
    // 0x0040E85C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x0040E860: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x0040E864: lbu         $v0, 0x40F4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40F4);
    // 0x0040E868: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x0040E86C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040E870: sb          $v0, 0x40F4($at)
    MEM_B(0X40F4, ctx->r1) = ctx->r2;
    // 0x0040E874: jal         0x00273BFC
    // 0x0040E878: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_00273BFC(rdram, ctx);
        goto after_9;
    // 0x0040E878: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_9:
    // 0x0040E87C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_0040E880:
    // 0x0040E880: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x0040E884: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x0040E888: lb          $v0, -0x2DC2($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2DC2);
    // 0x0040E88C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x0040E890: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040E894: bne         $v0, $zero, L_0040E600
    if (ctx->r2 != 0) {
        // 0x0040E898: addiu       $s7, $s7, 0x12
        ctx->r23 = ADD32(ctx->r23, 0X12);
            goto L_0040E600;
    }
    // 0x0040E898: addiu       $s7, $s7, 0x12
    ctx->r23 = ADD32(ctx->r23, 0X12);
L_0040E89C:
    // 0x0040E89C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040E8A0:
    // 0x0040E8A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x0040E8A4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x0040E8A8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x0040E8AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x0040E8B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x0040E8B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x0040E8B8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x0040E8BC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x0040E8C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x0040E8C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x0040E8C8: jr          $ra
    // 0x0040E8CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x0040E8CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_0040E8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040E8D0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x0040E8D4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x0040E8D8: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x0040E8DC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x0040E8E0: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x0040E8E4: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x0040E8E8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x0040E8EC: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x0040E8F0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x0040E8F4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x0040E8F8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x0040E8FC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x0040E900: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x0040E904: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x0040E908: lw          $s3, 0x3C($t0)
    ctx->r19 = MEM_W(ctx->r8, 0X3C);
    // 0x0040E90C: jal         0x00268D1C
    // 0x0040E910: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    func_00268D1C(rdram, ctx);
        goto after_0;
    // 0x0040E910: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_0:
    // 0x0040E914: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040E918: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x0040E91C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x0040E920: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0040E924: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x0040E928: addiu       $s4, $s4, -0x2648
    ctx->r20 = ADD32(ctx->r20, -0X2648);
    // 0x0040E92C: lui         $s5, 0xFB00
    ctx->r21 = S32(0XFB00 << 16);
    // 0x0040E930: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x0040E934: lb          $a0, 0x40D8($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X40D8);
    // 0x0040E938: lwc1        $f0, 0xB0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB0);
    // 0x0040E93C: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x0040E940: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x0040E944: lwc1        $f0, 0xB4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB4);
    // 0x0040E948: addiu       $a0, $a0, 0x168
    ctx->r4 = ADD32(ctx->r4, 0X168);
    // 0x0040E94C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x0040E950: jal         0x00267680
    // 0x0040E954: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_00267680(rdram, ctx);
        goto after_1;
    // 0x0040E954: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_1:
L_0040E958:
    // 0x0040E958: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E95C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x0040E960: lb          $a1, 0x1E50($at)
    ctx->r5 = MEM_B(ctx->r1, 0X1E50);
    // 0x0040E964: lwc1        $f0, 0xB0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB0);
    // 0x0040E968: lwc1        $f2, 0xB4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XB4);
    // 0x0040E96C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x0040E970: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x0040E974: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x0040E978: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E97C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040E980: lh          $v0, 0x1E00($at)
    ctx->r2 = MEM_H(ctx->r1, 0X1E00);
    // 0x0040E984: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x0040E988: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x0040E98C: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x0040E990: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x0040E994: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0040E998: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x0040E99C: lhu         $a2, -0x259A($at)
    ctx->r6 = MEM_HU(ctx->r1, -0X259A);
    // 0x0040E9A0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040E9A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040E9A8: lh          $v0, 0x1E02($at)
    ctx->r2 = MEM_H(ctx->r1, 0X1E02);
    // 0x0040E9AC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x0040E9B0: lw          $v1, -0x2DD8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2DD8);
    // 0x0040E9B4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x0040E9B8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x0040E9BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x0040E9C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040E9C4: sllv        $v0, $v0, $a1
    ctx->r2 = S32(ctx->r2 << (ctx->r5 & 31));
    // 0x0040E9C8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x0040E9CC: trunc.w.s   $f3, $f1
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 1);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f1.fl);
    // 0x0040E9D0: mfc1        $s2, $f3
    ctx->r18 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x0040E9D4: trunc.w.s   $f3, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f0.fl);
    // 0x0040E9D8: mfc1        $s0, $f3
    ctx->r16 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x0040E9DC: bne         $v1, $zero, L_0040EA04
    if (ctx->r3 != 0) {
        // 0x0040E9E0: nop
    
            goto L_0040EA04;
    }
    // 0x0040E9E0: nop

    // 0x0040E9E4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x0040E9E8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040E9EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x0040E9F0: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x0040E9F4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x0040E9F8: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x0040E9FC: j           L_0040EA50
    // 0x0040EA00: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_0040EA50;
    // 0x0040EA00: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_0040EA04:
    // 0x0040EA04: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EA08: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x0040EA0C: lb          $v0, 0x40E0($at)
    ctx->r2 = MEM_B(ctx->r1, 0X40E0);
    // 0x0040EA10: beq         $v0, $s6, L_0040EA34
    if (ctx->r2 == ctx->r22) {
        // 0x0040EA14: lui         $v0, 0x7D7D
        ctx->r2 = S32(0X7D7D << 16);
            goto L_0040EA34;
    }
    // 0x0040EA14: lui         $v0, 0x7D7D
    ctx->r2 = S32(0X7D7D << 16);
    // 0x0040EA18: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x0040EA1C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040EA20: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x0040EA24: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x0040EA28: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x0040EA2C: j           L_0040EA50
    // 0x0040EA30: sw          $s6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r22;
        goto L_0040EA50;
    // 0x0040EA30: sw          $s6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r22;
L_0040EA34:
    // 0x0040EA34: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x0040EA38: ori         $v0, $v0, 0x7DFF
    ctx->r2 = ctx->r2 | 0X7DFF;
    // 0x0040EA3C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x0040EA40: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x0040EA44: sw          $v1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r3;
    // 0x0040EA48: sw          $s5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r21;
    // 0x0040EA4C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_0040EA50:
    // 0x0040EA50: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x0040EA54: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040EA58: sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18 << 16);
    // 0x0040EA5C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x0040EA60: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x0040EA64: lwc1        $f0, 0xB0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB0);
    // 0x0040EA68: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x0040EA6C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x0040EA70: lwc1        $f0, 0xB4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB4);
    // 0x0040EA74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x0040EA78: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x0040EA7C: jal         0x00267680
    // 0x0040EA80: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_00267680(rdram, ctx);
        goto after_2;
    // 0x0040EA80: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x0040EA84: slti        $v0, $s1, 0x14
    ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // 0x0040EA88: bne         $v0, $zero, L_0040E958
    if (ctx->r2 != 0) {
        // 0x0040EA8C: nop
    
            goto L_0040E958;
    }
    // 0x0040EA8C: nop

    // 0x0040EA90: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x0040EA94: lb          $v0, -0x2DC2($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2DC2);
    // 0x0040EA98: blez        $v0, L_0040ECD0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x0040EA9C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_0040ECD0;
    }
    // 0x0040EA9C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x0040EAA0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x0040EAA4: addu        $s4, $fp, $zero
    ctx->r20 = ADD32(ctx->r30, 0);
    // 0x0040EAA8: addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    // 0x0040EAAC: addu        $s7, $s1, $zero
    ctx->r23 = ADD32(ctx->r17, 0);
L_0040EAB0:
    // 0x0040EAB0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EAB4: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x0040EAB8: lbu         $v0, 0x40D3($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X40D3);
    // 0x0040EABC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EAC0: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x0040EAC4: lb          $v1, 0x40CF($at)
    ctx->r3 = MEM_B(ctx->r1, 0X40CF);
    // 0x0040EAC8: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x0040EACC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x0040EAD0: addiu       $v0, $v0, -0x2DAF
    ctx->r2 = ADD32(ctx->r2, -0X2DAF);
    // 0x0040EAD4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EAD8: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x0040EADC: sb          $a0, 0x40D3($at)
    MEM_B(0X40D3, ctx->r1) = ctx->r4;
    // 0x0040EAE0: bne         $v1, $zero, L_0040EBC4
    if (ctx->r3 != 0) {
        // 0x0040EAE4: addu        $s6, $s7, $v0
        ctx->r22 = ADD32(ctx->r23, ctx->r2);
            goto L_0040EBC4;
    }
    // 0x0040EAE4: addu        $s6, $s7, $v0
    ctx->r22 = ADD32(ctx->r23, ctx->r2);
    // 0x0040EAE8: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x0040EAEC: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x0040EAF0: beql        $v0, $zero, L_0040ECB4
    if (ctx->r2 == 0) {
        // 0x0040EAF4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_0040ECB4;
    }
    goto skip_0;
    // 0x0040EAF4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x0040EAF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040EAFC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x0040EB00: lb          $v1, 0x3($s6)
    ctx->r3 = MEM_B(ctx->r22, 0X3);
    // 0x0040EB04: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x0040EB08: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EB0C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040EB10: lh          $s2, 0x1E00($at)
    ctx->r18 = MEM_H(ctx->r1, 0X1E00);
    // 0x0040EB14: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EB18: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040EB1C: lh          $v0, 0x1E02($at)
    ctx->r2 = MEM_H(ctx->r1, 0X1E02);
    // 0x0040EB20: lwc1        $f0, 0xB4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB4);
    // 0x0040EB24: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x0040EB28: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x0040EB2C: mul.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f0.fl);
    // 0x0040EB30: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x0040EB34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x0040EB38: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x0040EB3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0040EB40: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040EB44: lhu         $a0, -0x259A($at)
    ctx->r4 = MEM_HU(ctx->r1, -0X259A);
    // 0x0040EB48: trunc.w.s   $f3, $f1
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 1);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f1.fl);
    // 0x0040EB4C: mfc1        $s0, $f3
    ctx->r16 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x0040EB50: jal         0x00268B0C
    // 0x0040EB54: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    func_00268B0C(rdram, ctx);
        goto after_3;
    // 0x0040EB54: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x0040EB58: jal         0x00268D1C
    // 0x0040EB5C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    func_00268D1C(rdram, ctx);
        goto after_4;
    // 0x0040EB5C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_4:
    // 0x0040EB60: addiu       $a0, $zero, 0x12D
    ctx->r4 = ADD32(0, 0X12D);
    // 0x0040EB64: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x0040EB68: addiu       $a3, $s0, -0xA
    ctx->r7 = ADD32(ctx->r16, -0XA);
    // 0x0040EB6C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x0040EB70: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x0040EB74: lwc1        $f1, 0xB0($s3)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r19, 0XB0);
    // 0x0040EB78: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x0040EB7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x0040EB80: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x0040EB84: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x0040EB88: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x0040EB8C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x0040EB90: mul.s       $f0, $f0, $f1
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f1.fl);
    // 0x0040EB94: swc1        $f1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x0040EB98: lwc1        $f1, 0xB4($s3)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r19, 0XB4);
    // 0x0040EB9C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x0040EBA0: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x0040EBA4: swc1        $f1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x0040EBA8: trunc.w.s   $f3, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f0.fl);
    // 0x0040EBAC: mfc1        $a2, $f3
    ctx->r6 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x0040EBB0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x0040EBB4: jal         0x00267680
    // 0x0040EBB8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    func_00267680(rdram, ctx);
        goto after_5;
    // 0x0040EBB8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_5:
    // 0x0040EBBC: j           L_0040ECB4
    // 0x0040EBC0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_0040ECB4;
    // 0x0040EBC0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_0040EBC4:
    // 0x0040EBC4: jal         0x00265F44
    // 0x0040EBC8: nop

    func_00265F44(rdram, ctx);
        goto after_6;
    // 0x0040EBC8: nop

    after_6:
    // 0x0040EBCC: lwc1        $f0, 0xB0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB0);
    // 0x0040EBD0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EBD4: lwc1        $f12, -0x298C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X298C);
    // 0x0040EBD8: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x0040EBDC: lwc1        $f14, 0xB4($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0XB4);
    // 0x0040EBE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x0040EBE4: sw          $fp, 0x6F0C($at)
    MEM_W(0X6F0C, ctx->r1) = ctx->r30;
    // 0x0040EBE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x0040EBEC: sw          $fp, 0x6EF0($at)
    MEM_W(0X6EF0, ctx->r1) = ctx->r30;
    // 0x0040EBF0: jal         0x00268D04
    // 0x0040EBF4: nop

    func_00268D04(rdram, ctx);
        goto after_7;
    // 0x0040EBF4: nop

    after_7:
    // 0x0040EBF8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EBFC: addu        $at, $at, $s5
    ctx->r1 = ADD32(ctx->r1, ctx->r21);
    // 0x0040EC00: lb          $a0, 0x1E78($at)
    ctx->r4 = MEM_B(ctx->r1, 0X1E78);
    // 0x0040EC04: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EC08: addu        $at, $at, $s5
    ctx->r1 = ADD32(ctx->r1, ctx->r21);
    // 0x0040EC0C: lb          $a1, 0x1E79($at)
    ctx->r5 = MEM_B(ctx->r1, 0X1E79);
    // 0x0040EC10: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EC14: addu        $at, $at, $s5
    ctx->r1 = ADD32(ctx->r1, ctx->r21);
    // 0x0040EC18: lb          $a2, 0x1E7A($at)
    ctx->r6 = MEM_B(ctx->r1, 0X1E7A);
    // 0x0040EC1C: jal         0x00268CEC
    // 0x0040EC20: nop

    func_00268CEC(rdram, ctx);
        goto after_8;
    // 0x0040EC20: nop

    after_8:
    // 0x0040EC24: andi        $v0, $s1, 0x1
    ctx->r2 = ctx->r17 & 0X1;
    // 0x0040EC28: beq         $v0, $zero, L_0040EC48
    if (ctx->r2 == 0) {
        // 0x0040EC2C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_0040EC48;
    }
    // 0x0040EC2C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x0040EC30: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x0040EC34: lw          $v1, -0x2960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2960);
    // 0x0040EC38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x0040EC3C: sw          $v0, 0x6F08($at)
    MEM_W(0X6F08, ctx->r1) = ctx->r2;
    // 0x0040EC40: j           L_0040EC54
    // 0x0040EC44: addiu       $s2, $v1, -0x14
    ctx->r18 = ADD32(ctx->r3, -0X14);
        goto L_0040EC54;
    // 0x0040EC44: addiu       $s2, $v1, -0x14
    ctx->r18 = ADD32(ctx->r3, -0X14);
L_0040EC48:
    // 0x0040EC48: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x0040EC4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x0040EC50: sw          $zero, 0x6F08($at)
    MEM_W(0X6F08, ctx->r1) = 0;
L_0040EC54:
    // 0x0040EC54: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x0040EC58: bne         $v0, $zero, L_0040EC6C
    if (ctx->r2 != 0) {
        // 0x0040EC5C: addiu       $s0, $zero, 0x10
        ctx->r16 = ADD32(0, 0X10);
            goto L_0040EC6C;
    }
    // 0x0040EC5C: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x0040EC60: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x0040EC64: lw          $v0, -0x295C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X295C);
    // 0x0040EC68: addiu       $s0, $v0, -0x18
    ctx->r16 = ADD32(ctx->r2, -0X18);
L_0040EC6C:
    // 0x0040EC6C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x0040EC70: lb          $v1, 0x3($s6)
    ctx->r3 = MEM_B(ctx->r22, 0X3);
    // 0x0040EC74: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x0040EC78: addiu       $a1, $a1, -0x2998
    ctx->r5 = ADD32(ctx->r5, -0X2998);
    // 0x0040EC7C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x0040EC80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x0040EC84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x0040EC88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0040EC8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040EC90: lw          $a3, -0x2594($at)
    ctx->r7 = MEM_W(ctx->r1, -0X2594);
    // 0x0040EC94: jal         0x002A0528
    // 0x0040EC98: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_002A0528(rdram, ctx);
        goto after_9;
    // 0x0040EC98: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_9:
    // 0x0040EC9C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x0040ECA0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x0040ECA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x0040ECA8: jal         0x00266828
    // 0x0040ECAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_00266828(rdram, ctx);
        goto after_10;
    // 0x0040ECAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_10:
    // 0x0040ECB0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_0040ECB4:
    // 0x0040ECB4: addiu       $s5, $s5, 0x3
    ctx->r21 = ADD32(ctx->r21, 0X3);
    // 0x0040ECB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x0040ECBC: lb          $v0, -0x2DC2($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2DC2);
    // 0x0040ECC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x0040ECC4: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040ECC8: bne         $v0, $zero, L_0040EAB0
    if (ctx->r2 != 0) {
        // 0x0040ECCC: addiu       $s7, $s7, 0x12
        ctx->r23 = ADD32(ctx->r23, 0X12);
            goto L_0040EAB0;
    }
    // 0x0040ECCC: addiu       $s7, $s7, 0x12
    ctx->r23 = ADD32(ctx->r23, 0X12);
L_0040ECD0:
    // 0x0040ECD0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x0040ECD4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x0040ECD8: jal         0x004027A0
    // 0x0040ECDC: nop

    func_004027A0(rdram, ctx);
        goto after_11;
    // 0x0040ECDC: nop

    after_11:
    // 0x0040ECE0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x0040ECE4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x0040ECE8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x0040ECEC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x0040ECF0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x0040ECF4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x0040ECF8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x0040ECFC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x0040ED00: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x0040ED04: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x0040ED08: jr          $ra
    // 0x0040ED0C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x0040ED0C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_0040ED10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040ED10: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x0040ED14: lb          $v1, 0x40F4($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X40F4);
    // 0x0040ED18: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x0040ED1C: lb          $v0, -0x2DC2($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2DC2);
    // 0x0040ED20: bne         $v1, $v0, L_0040ED50
    if (ctx->r3 != ctx->r2) {
        // 0x0040ED24: nop
    
            goto L_0040ED50;
    }
    // 0x0040ED24: nop

    // 0x0040ED28: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x0040ED2C: lw          $v0, 0x1DF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1DF8);
    // 0x0040ED30: bne         $v0, $zero, L_0040ED50
    if (ctx->r2 != 0) {
        // 0x0040ED34: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_0040ED50;
    }
    // 0x0040ED34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040ED38: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040ED3C: lwc1        $f0, -0x2988($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2988);
    // 0x0040ED40: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040ED44: sw          $v0, 0x1DF8($at)
    MEM_W(0X1DF8, ctx->r1) = ctx->r2;
    // 0x0040ED48: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040ED4C: swc1        $f0, 0x1DFC($at)
    MEM_W(0X1DFC, ctx->r1) = ctx->f0.u32l;
L_0040ED50:
    // 0x0040ED50: jr          $ra
    // 0x0040ED54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x0040ED54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_0040ED58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040ED58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0040ED5C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x0040ED60: addiu       $v1, $v1, -0x2DE0
    ctx->r3 = ADD32(ctx->r3, -0X2DE0);
    // 0x0040ED64: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0040ED68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x0040ED6C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x0040ED70: beq         $v0, $zero, L_0040ED80
    if (ctx->r2 == 0) {
        // 0x0040ED74: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_0040ED80;
    }
    // 0x0040ED74: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x0040ED78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040ED7C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_0040ED80:
    // 0x0040ED80: addiu       $v1, $zero, 0x13
    ctx->r3 = ADD32(0, 0X13);
    // 0x0040ED84: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x0040ED88: addiu       $v0, $v0, 0x40F3
    ctx->r2 = ADD32(ctx->r2, 0X40F3);
L_0040ED8C:
    // 0x0040ED8C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x0040ED90: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x0040ED94: bgez        $v1, L_0040ED8C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x0040ED98: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_0040ED8C;
    }
    // 0x0040ED98: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x0040ED9C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x0040EDA0: addiu       $a0, $a0, -0x2DC2
    ctx->r4 = ADD32(ctx->r4, -0X2DC2);
    // 0x0040EDA4: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x0040EDA8: blez        $v0, L_0040EDDC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x0040EDAC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_0040EDDC;
    }
    // 0x0040EDAC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x0040EDB0: addiu       $a1, $a0, 0x13
    ctx->r5 = ADD32(ctx->r4, 0X13);
    // 0x0040EDB4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_0040EDB8:
    // 0x0040EDB8: lb          $v0, 0x3($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3);
    // 0x0040EDBC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EDC0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040EDC4: sb          $v1, 0x40E0($at)
    MEM_B(0X40E0, ctx->r1) = ctx->r3;
    // 0x0040EDC8: lb          $v0, -0x13($a1)
    ctx->r2 = MEM_B(ctx->r5, -0X13);
    // 0x0040EDCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x0040EDD0: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040EDD4: bne         $v0, $zero, L_0040EDB8
    if (ctx->r2 != 0) {
        // 0x0040EDD8: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_0040EDB8;
    }
    // 0x0040EDD8: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
L_0040EDDC:
    // 0x0040EDDC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_0040EDE0:
    // 0x0040EDE0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EDE4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040EDE8: sb          $zero, 0x40D0($at)
    MEM_B(0X40D0, ctx->r1) = 0;
    // 0x0040EDEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EDF0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040EDF4: sb          $zero, 0x40D4($at)
    MEM_B(0X40D4, ctx->r1) = 0;
    // 0x0040EDF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x0040EDFC: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x0040EE00: bne         $v0, $zero, L_0040EDE0
    if (ctx->r2 != 0) {
        // 0x0040EE04: nop
    
            goto L_0040EDE0;
    }
    // 0x0040EE04: nop

    // 0x0040EE08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EE0C: sb          $zero, 0x40F4($at)
    MEM_B(0X40F4, ctx->r1) = 0;
    // 0x0040EE10: jal         0x002154EC
    // 0x0040EE14: nop

    func_002154EC(rdram, ctx);
        goto after_0;
    // 0x0040EE14: nop

    after_0:
    // 0x0040EE18: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040EE1C: bltzl       $v1, L_0040EE24
    if (SIGNED(ctx->r3) < 0) {
        // 0x0040EE20: addiu       $v0, $v1, 0x3
        ctx->r2 = ADD32(ctx->r3, 0X3);
            goto L_0040EE24;
    }
    goto skip_0;
    // 0x0040EE20: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    skip_0:
L_0040EE24:
    // 0x0040EE24: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0040EE28: addiu       $a0, $a0, 0x2760
    ctx->r4 = ADD32(ctx->r4, 0X2760);
    // 0x0040EE2C: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x0040EE30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x0040EE34: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x0040EE38: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EE3C: sb          $v0, 0x40D8($at)
    MEM_B(0X40D8, ctx->r1) = ctx->r2;
    // 0x0040EE40: jal         0x00209710
    // 0x0040EE44: nop

    func_00209710(rdram, ctx);
        goto after_1;
    // 0x0040EE44: nop

    after_1:
    // 0x0040EE48: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x0040EE4C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x0040EE50: jal         0x0025F59C
    // 0x0040EE54: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_0025F59C(rdram, ctx);
        goto after_2;
    // 0x0040EE54: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_2:
    // 0x0040EE58: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0040EE5C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EE60: sw          $zero, 0x1DF8($at)
    MEM_W(0X1DF8, ctx->r1) = 0;
    // 0x0040EE64: jr          $ra
    // 0x0040EE68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0040EE68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0040EE6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040EE6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0040EE70: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0040EE74: addiu       $a0, $a0, 0x2760
    ctx->r4 = ADD32(ctx->r4, 0X2760);
    // 0x0040EE78: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0040EE7C: jal         0x00209710
    // 0x0040EE80: nop

    func_00209710(rdram, ctx);
        goto after_0;
    // 0x0040EE80: nop

    after_0:
    // 0x0040EE84: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x0040EE88: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x0040EE8C: jal         0x0025F58C
    // 0x0040EE90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_0025F58C(rdram, ctx);
        goto after_1;
    // 0x0040EE90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x0040EE94: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0040EE98: jr          $ra
    // 0x0040EE9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0040EE9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0040EEA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040EEA0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x0040EEA4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x0040EEA8: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_0040EEAC:
    // 0x0040EEAC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EEB0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x0040EEB4: lb          $v0, 0x1E64($at)
    ctx->r2 = MEM_B(ctx->r1, 0X1E64);
    // 0x0040EEB8: bne         $v0, $a0, L_0040EEC8
    if (ctx->r2 != ctx->r4) {
        // 0x0040EEBC: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_0040EEC8;
    }
    // 0x0040EEBC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x0040EEC0: j           L_0040EED4
    // 0x0040EEC4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
        goto L_0040EED4;
    // 0x0040EEC4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_0040EEC8:
    // 0x0040EEC8: slti        $v0, $a3, 0x14
    ctx->r2 = SIGNED(ctx->r7) < 0X14 ? 1 : 0;
    // 0x0040EECC: bne         $v0, $zero, L_0040EEAC
    if (ctx->r2 != 0) {
        // 0x0040EED0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_0040EEAC;
    }
    // 0x0040EED0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_0040EED4:
    // 0x0040EED4: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x0040EED8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x0040EEDC: addiu       $t1, $t1, -0x2DD8
    ctx->r9 = ADD32(ctx->r9, -0X2DD8);
    // 0x0040EEE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x0040EEE4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x0040EEE8: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
L_0040EEEC:
    // 0x0040EEEC: bltzl       $a2, L_0040EEF4
    if (SIGNED(ctx->r6) < 0) {
        // 0x0040EEF0: addiu       $a2, $zero, 0x13
        ctx->r6 = ADD32(0, 0X13);
            goto L_0040EEF4;
    }
    goto skip_0;
    // 0x0040EEF0: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    skip_0:
L_0040EEF4:
    // 0x0040EEF4: slti        $v0, $a2, 0x14
    ctx->r2 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
    // 0x0040EEF8: beql        $v0, $zero, L_0040EF00
    if (ctx->r2 == 0) {
        // 0x0040EEFC: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_0040EF00;
    }
    goto skip_1;
    // 0x0040EEFC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_1:
L_0040EF00:
    // 0x0040EF00: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040EF04: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x0040EF08: lb          $a0, 0x1E64($at)
    ctx->r4 = MEM_B(ctx->r1, 0X1E64);
    // 0x0040EF0C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x0040EF10: sllv        $v1, $t0, $a0
    ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
    // 0x0040EF14: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x0040EF18: beq         $v0, $zero, L_0040EF34
    if (ctx->r2 == 0) {
        // 0x0040EF1C: nop
    
            goto L_0040EF34;
    }
    // 0x0040EF1C: nop

    // 0x0040EF20: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040EF24: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x0040EF28: lb          $v0, 0x40E0($at)
    ctx->r2 = MEM_B(ctx->r1, 0X40E0);
    // 0x0040EF2C: beq         $v0, $a3, L_0040EF44
    if (ctx->r2 == ctx->r7) {
        // 0x0040EF30: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_0040EF44;
    }
    // 0x0040EF30: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_0040EF34:
    // 0x0040EF34: beq         $t2, $zero, L_0040EEEC
    if (ctx->r10 == 0) {
        // 0x0040EF38: addu        $a2, $a2, $a1
        ctx->r6 = ADD32(ctx->r6, ctx->r5);
            goto L_0040EEEC;
    }
    // 0x0040EF38: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x0040EF3C: jr          $ra
    // 0x0040EF40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x0040EF40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040EF44:
    // 0x0040EF44: jr          $ra
    // 0x0040EF48: nop

    return;
    // 0x0040EF48: nop

;}
RECOMP_FUNC void func_0040EF4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040EF4C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x0040EF50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x0040EF54: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x0040EF58: addiu       $a0, $a0, -0x2CC0
    ctx->r4 = ADD32(ctx->r4, -0X2CC0);
    // 0x0040EF5C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x0040EF60: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x0040EF64: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x0040EF68: bne         $v1, $v0, L_0040EF8C
    if (ctx->r3 != ctx->r2) {
        // 0x0040EF6C: addiu       $a0, $a0, -0xE90
        ctx->r4 = ADD32(ctx->r4, -0XE90);
            goto L_0040EF8C;
    }
    // 0x0040EF6C: addiu       $a0, $a0, -0xE90
    ctx->r4 = ADD32(ctx->r4, -0XE90);
    // 0x0040EF70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0040EF74: lui         $a1, 0x41
    ctx->r5 = S32(0X41 << 16);
    // 0x0040EF78: addiu       $a1, $a1, 0x6E20
    ctx->r5 = ADD32(ctx->r5, 0X6E20);
    // 0x0040EF7C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x0040EF80: addiu       $a3, $a3, 0x3C60
    ctx->r7 = ADD32(ctx->r7, 0X3C60);
    // 0x0040EF84: jal         0x00403894
    // 0x0040EF88: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00403894(rdram, ctx);
        goto after_0;
    // 0x0040EF88: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
L_0040EF8C:
    // 0x0040EF8C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x0040EF90: jr          $ra
    // 0x0040EF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0040EF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_0040EF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040EF98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0040EF9C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x0040EFA0: addiu       $a0, $a0, -0x41B0
    ctx->r4 = ADD32(ctx->r4, -0X41B0);
    // 0x0040EFA4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0040EFA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x0040EFAC: blez        $v0, L_0040EFEC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x0040EFB0: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_0040EFEC;
    }
    // 0x0040EFB0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x0040EFB4: addiu       $a2, $a0, -0x4
    ctx->r6 = ADD32(ctx->r4, -0X4);
    // 0x0040EFB8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_0040EFBC:
    // 0x0040EFBC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x0040EFC0: addu        $a0, $v0, $a1
    ctx->r4 = ADD32(ctx->r2, ctx->r5);
    // 0x0040EFC4: beq         $a0, $zero, L_0040EFDC
    if (ctx->r4 == 0) {
        // 0x0040EFC8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_0040EFDC;
    }
    // 0x0040EFC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x0040EFCC: jal         0x004078AC
    // 0x0040EFD0: nop

    func_004078AC(rdram, ctx);
        goto after_0;
    // 0x0040EFD0: nop

    after_0:
    // 0x0040EFD4: j           L_0040EFEC
    // 0x0040EFD8: nop

        goto L_0040EFEC;
    // 0x0040EFD8: nop

L_0040EFDC:
    // 0x0040EFDC: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x0040EFE0: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040EFE4: bne         $v0, $zero, L_0040EFBC
    if (ctx->r2 != 0) {
        // 0x0040EFE8: addiu       $a1, $a1, 0x15C0
        ctx->r5 = ADD32(ctx->r5, 0X15C0);
            goto L_0040EFBC;
    }
    // 0x0040EFE8: addiu       $a1, $a1, 0x15C0
    ctx->r5 = ADD32(ctx->r5, 0X15C0);
L_0040EFEC:
    // 0x0040EFEC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0040EFF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040EFF4: jr          $ra
    // 0x0040EFF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0040EFF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0040EFFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040EFFC: jr          $ra
    // 0x0040F000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x0040F000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_0040F004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F004: jr          $ra
    // 0x0040F008: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x0040F008: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_0040F00C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F00C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0040F010: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0040F014: jal         0x004027A0
    // 0x0040F018: nop

    func_004027A0(rdram, ctx);
        goto after_0;
    // 0x0040F018: nop

    after_0:
    // 0x0040F01C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0040F020: jr          $ra
    // 0x0040F024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0040F024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0040F028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F028: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x0040F02C: lw          $v0, -0x4198($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4198);
    // 0x0040F030: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x0040F034: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x0040F038: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x0040F03C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x0040F040: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x0040F044: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x0040F048: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x0040F04C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0040F050: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0040F054: lh          $v1, 0xA4C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA4C);
    // 0x0040F058: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x0040F05C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F060: sw          $zero, 0x3DD0($at)
    MEM_W(0X3DD0, ctx->r1) = 0;
    // 0x0040F064: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x0040F068: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x0040F06C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x0040F070: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x0040F074: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x0040F078: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x0040F07C: addiu       $v1, $v1, 0x3EB0
    ctx->r3 = ADD32(ctx->r3, 0X3EB0);
    // 0x0040F080: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x0040F084: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F088: sw          $v0, 0x3DD0($at)
    MEM_W(0X3DD0, ctx->r1) = ctx->r2;
    // 0x0040F08C: bne         $s0, $zero, L_0040F09C
    if (ctx->r16 != 0) {
        // 0x0040F090: addu        $s5, $a1, $zero
        ctx->r21 = ADD32(ctx->r5, 0);
            goto L_0040F09C;
    }
    // 0x0040F090: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x0040F094: j           L_0040F0A8
    // 0x0040F098: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
        goto L_0040F0A8;
    // 0x0040F098: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
L_0040F09C:
    // 0x0040F09C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x0040F0A0: beql        $s0, $v0, L_0040F0A8
    if (ctx->r16 == ctx->r2) {
        // 0x0040F0A4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_0040F0A8;
    }
    goto skip_0;
    // 0x0040F0A4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    skip_0:
L_0040F0A8:
    // 0x0040F0A8: slti        $v0, $s0, 0x10
    ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x0040F0AC: beq         $v0, $zero, L_0040F170
    if (ctx->r2 == 0) {
        // 0x0040F0B0: sll         $s1, $s0, 3
        ctx->r17 = S32(ctx->r16 << 3);
            goto L_0040F170;
    }
    // 0x0040F0B0: sll         $s1, $s0, 3
    ctx->r17 = S32(ctx->r16 << 3);
    // 0x0040F0B4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x0040F0B8: addiu       $s2, $s2, -0x2DD8
    ctx->r18 = ADD32(ctx->r18, -0X2DD8);
    // 0x0040F0BC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x0040F0C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0040F0C4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x0040F0C8: lw          $v0, -0x4A30($at)
    ctx->r2 = MEM_W(ctx->r1, -0X4A30);
    // 0x0040F0CC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x0040F0D0: sllv        $v0, $s3, $v0
    ctx->r2 = S32(ctx->r19 << (ctx->r2 & 31));
    // 0x0040F0D4: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x0040F0D8: bne         $v1, $zero, L_0040F170
    if (ctx->r3 != 0) {
        // 0x0040F0DC: nop
    
            goto L_0040F170;
    }
    // 0x0040F0DC: nop

    // 0x0040F0E0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x0040F0E4: addiu       $a0, $a0, 0x4118
    ctx->r4 = ADD32(ctx->r4, 0X4118);
    // 0x0040F0E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0040F0EC: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x0040F0F0: lw          $a2, -0x4A2C($at)
    ctx->r6 = MEM_W(ctx->r1, -0X4A2C);
    // 0x0040F0F4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x0040F0F8: addiu       $a1, $a1, -0x2970
    ctx->r5 = ADD32(ctx->r5, -0X2970);
    // 0x0040F0FC: jal         0x002A0528
    // 0x0040F100: nop

    func_002A0528(rdram, ctx);
        goto after_0;
    // 0x0040F100: nop

    after_0:
    // 0x0040F104: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x0040F108: addiu       $a0, $a0, 0x40F8
    ctx->r4 = ADD32(ctx->r4, 0X40F8);
    // 0x0040F10C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x0040F110: addiu       $a1, $a1, -0x296C
    ctx->r5 = ADD32(ctx->r5, -0X296C);
    // 0x0040F114: addiu       $v1, $s0, 0x7
    ctx->r3 = ADD32(ctx->r16, 0X7);
    // 0x0040F118: sllv        $v0, $v1, $s3
    ctx->r2 = S32(ctx->r3 << (ctx->r19 & 31));
    // 0x0040F11C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x0040F120: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x0040F124: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x0040F128: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x0040F12C: lw          $a3, -0x26A8($at)
    ctx->r7 = MEM_W(ctx->r1, -0X26A8);
    // 0x0040F130: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x0040F134: addiu       $a2, $a2, -0x1258
    ctx->r6 = ADD32(ctx->r6, -0X1258);
    // 0x0040F138: jal         0x002A0528
    // 0x0040F13C: nop

    func_002A0528(rdram, ctx);
        goto after_1;
    // 0x0040F13C: nop

    after_1:
    // 0x0040F140: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x0040F144: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x0040F148: lui         $a2, 0x41
    ctx->r6 = S32(0X41 << 16);
    // 0x0040F14C: addiu       $a2, $a2, 0x6EE8
    ctx->r6 = ADD32(ctx->r6, 0X6EE8);
    // 0x0040F150: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x0040F154: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x0040F158: lw          $v0, -0x4A30($at)
    ctx->r2 = MEM_W(ctx->r1, -0X4A30);
    // 0x0040F15C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x0040F160: sllv        $v0, $s3, $v0
    ctx->r2 = S32(ctx->r19 << (ctx->r2 & 31));
    // 0x0040F164: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x0040F168: j           L_0040F1D0
    // 0x0040F16C: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
        goto L_0040F1D0;
    // 0x0040F16C: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
L_0040F170:
    // 0x0040F170: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x0040F174: lw          $v1, 0x2A8C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2A8C);
    // 0x0040F178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040F17C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F180: sw          $v0, 0x3BCC($at)
    MEM_W(0X3BCC, ctx->r1) = ctx->r2;
    // 0x0040F184: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0040F188: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F18C: sw          $v0, 0x3DBC($at)
    MEM_W(0X3DBC, ctx->r1) = ctx->r2;
    // 0x0040F190: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F194: sw          $v0, 0x3DD8($at)
    MEM_W(0X3DD8, ctx->r1) = ctx->r2;
    // 0x0040F198: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F19C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F1A0: sw          $zero, 0x3DC8($at)
    MEM_W(0X3DC8, ctx->r1) = 0;
    // 0x0040F1A4: bne         $v1, $v0, L_0040F1C4
    if (ctx->r3 != ctx->r2) {
        // 0x0040F1A8: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_0040F1C4;
    }
    // 0x0040F1A8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x0040F1AC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0040F1B0: addiu       $a0, $a0, 0x2760
    ctx->r4 = ADD32(ctx->r4, 0X2760);
    // 0x0040F1B4: jal         0x00209B5C
    // 0x0040F1B8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_00209B5C(rdram, ctx);
        goto after_2;
    // 0x0040F1B8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x0040F1BC: j           L_0040F1D8
    // 0x0040F1C0: nop

        goto L_0040F1D8;
    // 0x0040F1C0: nop

L_0040F1C4:
    // 0x0040F1C4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x0040F1C8: lui         $a2, 0x41
    ctx->r6 = S32(0X41 << 16);
    // 0x0040F1CC: addiu       $a2, $a2, 0x6A60
    ctx->r6 = ADD32(ctx->r6, 0X6A60);
L_0040F1D0:
    // 0x0040F1D0: jal         0x00403AFC
    // 0x0040F1D4: nop

    func_00403AFC(rdram, ctx);
        goto after_3;
    // 0x0040F1D4: nop

    after_3:
L_0040F1D8:
    // 0x0040F1D8: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x0040F1DC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x0040F1E0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x0040F1E4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x0040F1E8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x0040F1EC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0040F1F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0040F1F4: jr          $ra
    // 0x0040F1F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x0040F1F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_0040F1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F1FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0040F200: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x0040F204: lw          $v1, 0x2A8C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2A8C);
    // 0x0040F208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040F20C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F210: sw          $v0, 0x3BCC($at)
    MEM_W(0X3BCC, ctx->r1) = ctx->r2;
    // 0x0040F214: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0040F218: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F21C: sw          $v0, 0x3DBC($at)
    MEM_W(0X3DBC, ctx->r1) = ctx->r2;
    // 0x0040F220: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F224: sw          $v0, 0x3DD8($at)
    MEM_W(0X3DD8, ctx->r1) = ctx->r2;
    // 0x0040F228: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F22C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0040F230: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F234: sw          $zero, 0x3DC8($at)
    MEM_W(0X3DC8, ctx->r1) = 0;
    // 0x0040F238: bne         $v1, $v0, L_0040F258
    if (ctx->r3 != ctx->r2) {
        // 0x0040F23C: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_0040F258;
    }
    // 0x0040F23C: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x0040F240: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0040F244: addiu       $a0, $a0, 0x2760
    ctx->r4 = ADD32(ctx->r4, 0X2760);
    // 0x0040F248: jal         0x00209B5C
    // 0x0040F24C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_00209B5C(rdram, ctx);
        goto after_0;
    // 0x0040F24C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x0040F250: j           L_0040F268
    // 0x0040F254: nop

        goto L_0040F268;
    // 0x0040F254: nop

L_0040F258:
    // 0x0040F258: lui         $a2, 0x41
    ctx->r6 = S32(0X41 << 16);
    // 0x0040F25C: addiu       $a2, $a2, 0x6A60
    ctx->r6 = ADD32(ctx->r6, 0X6A60);
    // 0x0040F260: jal         0x00403AFC
    // 0x0040F264: nop

    func_00403AFC(rdram, ctx);
        goto after_1;
    // 0x0040F264: nop

    after_1:
L_0040F268:
    // 0x0040F268: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0040F26C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040F270: jr          $ra
    // 0x0040F274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0040F274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0040F278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0040F27C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0040F280: jal         0x004027A0
    // 0x0040F284: nop

    func_004027A0(rdram, ctx);
        goto after_0;
    // 0x0040F284: nop

    after_0:
    // 0x0040F288: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0040F28C: jr          $ra
    // 0x0040F290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0040F290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0040F294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0040F298: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x0040F29C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x0040F2A0: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x0040F2A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0040F2A8: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x0040F2AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040F2B0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F2B4: sw          $v0, 0x3BCC($at)
    MEM_W(0X3BCC, ctx->r1) = ctx->r2;
    // 0x0040F2B8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x0040F2BC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F2C0: sw          $v0, 0x3DBC($at)
    MEM_W(0X3DBC, ctx->r1) = ctx->r2;
    // 0x0040F2C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F2C8: sw          $v0, 0x3DD8($at)
    MEM_W(0X3DD8, ctx->r1) = ctx->r2;
    // 0x0040F2CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F2D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x0040F2D4: sw          $zero, 0x3DC8($at)
    MEM_W(0X3DC8, ctx->r1) = 0;
    // 0x0040F2D8: bnel        $v1, $v0, L_0040F2F4
    if (ctx->r3 != ctx->r2) {
        // 0x0040F2DC: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_0040F2F4;
    }
    goto skip_0;
    // 0x0040F2DC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    skip_0:
    // 0x0040F2E0: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    // 0x0040F2E4: jal         0x00209B5C
    // 0x0040F2E8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_00209B5C(rdram, ctx);
        goto after_0;
    // 0x0040F2E8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x0040F2EC: j           L_0040F308
    // 0x0040F2F0: nop

        goto L_0040F308;
    // 0x0040F2F0: nop

L_0040F2F4:
    // 0x0040F2F4: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x0040F2F8: lui         $a2, 0x41
    ctx->r6 = S32(0X41 << 16);
    // 0x0040F2FC: addiu       $a2, $a2, 0x6A60
    ctx->r6 = ADD32(ctx->r6, 0X6A60);
    // 0x0040F300: jal         0x00403AFC
    // 0x0040F304: nop

    func_00403AFC(rdram, ctx);
        goto after_1;
    // 0x0040F304: nop

    after_1:
L_0040F308:
    // 0x0040F308: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x0040F30C: jr          $ra
    // 0x0040F310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0040F310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_0040F314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F314: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x0040F318: addiu       $sp, $sp, -0x298
    ctx->r29 = ADD32(ctx->r29, -0X298);
    // 0x0040F31C: sw          $s7, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = ctx->r23;
    // 0x0040F320: lw          $s7, 0x2A8($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2A8);
    // 0x0040F324: sw          $s1, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r17;
    // 0x0040F328: lw          $s1, 0x2AC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2AC);
    // 0x0040F32C: sw          $s3, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r19;
    // 0x0040F330: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x0040F334: sw          $s6, 0x288($sp)
    MEM_W(0X288, ctx->r29) = ctx->r22;
    // 0x0040F338: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x0040F33C: sw          $fp, 0x290($sp)
    MEM_W(0X290, ctx->r29) = ctx->r30;
    // 0x0040F340: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x0040F344: sw          $s0, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->r16;
    // 0x0040F348: sh          $a1, 0x250($sp)
    MEM_H(0X250, ctx->r29) = ctx->r5;
    // 0x0040F34C: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x0040F350: sw          $ra, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r31;
    // 0x0040F354: sw          $s5, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r21;
    // 0x0040F358: sw          $s4, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r20;
    // 0x0040F35C: sw          $s2, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->r18;
    // 0x0040F360: sw          $zero, 0x254($sp)
    MEM_W(0X254, ctx->r29) = 0;
    // 0x0040F364: sb          $zero, 0x258($sp)
    MEM_B(0X258, ctx->r29) = 0;
    // 0x0040F368: beq         $s0, $zero, L_0040F688
    if (ctx->r16 == 0) {
        // 0x0040F36C: sw          $a2, 0x2A0($sp)
        MEM_W(0X2A0, ctx->r29) = ctx->r6;
            goto L_0040F688;
    }
    // 0x0040F36C: sw          $a2, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = ctx->r6;
    // 0x0040F370: beq         $a2, $zero, L_0040F688
    if (ctx->r6 == 0) {
        // 0x0040F374: addiu       $a2, $s1, 0xFF
        ctx->r6 = ADD32(ctx->r17, 0XFF);
            goto L_0040F688;
    }
    // 0x0040F374: addiu       $a2, $s1, 0xFF
    ctx->r6 = ADD32(ctx->r17, 0XFF);
    // 0x0040F378: bltzl       $a2, L_0040F380
    if (SIGNED(ctx->r6) < 0) {
        // 0x0040F37C: addiu       $a2, $s1, 0x1FE
        ctx->r6 = ADD32(ctx->r17, 0X1FE);
            goto L_0040F380;
    }
    goto skip_0;
    // 0x0040F37C: addiu       $a2, $s1, 0x1FE
    ctx->r6 = ADD32(ctx->r17, 0X1FE);
    skip_0:
L_0040F380:
    // 0x0040F380: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x0040F384: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0040F388: beq         $v0, $zero, L_0040F688
    if (ctx->r2 == 0) {
        // 0x0040F38C: sra         $s2, $a2, 8
        ctx->r18 = S32(SIGNED(ctx->r6) >> 8);
            goto L_0040F688;
    }
    // 0x0040F38C: sra         $s2, $a2, 8
    ctx->r18 = S32(SIGNED(ctx->r6) >> 8);
    // 0x0040F390: jal         0x00411F74
    // 0x0040F394: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x0040F394: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x0040F398: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x0040F39C: beq         $v0, $v1, L_0040F680
    if (ctx->r2 == ctx->r3) {
        // 0x0040F3A0: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040F680;
    }
    // 0x0040F3A0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F3A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0040F3A8: lw          $a2, 0x2A0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2A0);
    // 0x0040F3AC: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F3B0: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // 0x0040F3B4: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x0040F3B8: jal         0x00411460
    // 0x0040F3BC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_00411460(rdram, ctx);
        goto after_1;
    // 0x0040F3BC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_1:
    // 0x0040F3C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F3C4: beq         $v1, $zero, L_0040F3D4
    if (ctx->r3 == 0) {
        // 0x0040F3C8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040F3D4;
    }
    // 0x0040F3C8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040F3CC: bne         $v1, $v0, L_0040F68C
    if (ctx->r3 != ctx->r2) {
        // 0x0040F3D0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040F68C;
    }
    // 0x0040F3D0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0040F3D4:
    // 0x0040F3D4: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F3D8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x0040F3DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F3E0: bne         $v1, $v0, L_0040F68C
    if (ctx->r3 != ctx->r2) {
        // 0x0040F3E4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_0040F68C;
    }
    // 0x0040F3E4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x0040F3E8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F3EC: jal         0x0040FFF8
    // 0x0040F3F0: addiu       $a1, $sp, 0x240
    ctx->r5 = ADD32(ctx->r29, 0X240);
    func_0040FFF8(rdram, ctx);
        goto after_2;
    // 0x0040F3F0: addiu       $a1, $sp, 0x240
    ctx->r5 = ADD32(ctx->r29, 0X240);
    after_2:
    // 0x0040F3F4: lw          $v0, 0x240($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X240);
    // 0x0040F3F8: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x0040F3FC: bne         $v0, $zero, L_0040F68C
    if (ctx->r2 != 0) {
        // 0x0040F400: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_0040F68C;
    }
    // 0x0040F400: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x0040F404: beq         $s2, $zero, L_0040F688
    if (ctx->r18 == 0) {
        // 0x0040F408: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040F688;
    }
    // 0x0040F408: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F40C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040F410: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x0040F414: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F418: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x0040F41C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0040F420: jal         0x00411460
    // 0x0040F424: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_00411460(rdram, ctx);
        goto after_3;
    // 0x0040F424: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x0040F428: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F42C: beq         $v1, $zero, L_0040F43C
    if (ctx->r3 == 0) {
        // 0x0040F430: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040F43C;
    }
    // 0x0040F430: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040F434: bne         $v1, $v0, L_0040F68C
    if (ctx->r3 != ctx->r2) {
        // 0x0040F438: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040F68C;
    }
    // 0x0040F438: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0040F43C:
    // 0x0040F43C: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F440: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x0040F444: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F448: bne         $v1, $v0, L_0040F460
    if (ctx->r3 != ctx->r2) {
        // 0x0040F44C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_0040F460;
    }
    // 0x0040F44C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x0040F450: j           L_0040F68C
    // 0x0040F454: nop

        goto L_0040F68C;
    // 0x0040F454: nop

L_0040F458:
    // 0x0040F458: j           L_0040F590
    // 0x0040F45C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
        goto L_0040F590;
    // 0x0040F45C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_0040F460:
    // 0x0040F460: lbu         $v0, 0x64($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X64);
    // 0x0040F464: beq         $v0, $zero, L_0040F590
    if (ctx->r2 == 0) {
        // 0x0040F468: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_0040F590;
    }
    // 0x0040F468: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x0040F46C: addiu       $s5, $sp, 0x244
    ctx->r21 = ADD32(ctx->r29, 0X244);
    // 0x0040F470: addiu       $s4, $sp, 0x120
    ctx->r20 = ADD32(ctx->r29, 0X120);
    // 0x0040F474: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x0040F478: sw          $t0, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r8;
    // 0x0040F47C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0040F480:
    // 0x0040F480: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x0040F484: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0040F488: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x0040F48C: jal         0x00411C1C
    // 0x0040F490: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00411C1C(rdram, ctx);
        goto after_4;
    // 0x0040F490: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_4:
    // 0x0040F494: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F498: bne         $v1, $zero, L_0040F680
    if (ctx->r3 != 0) {
        // 0x0040F49C: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040F680;
    }
    // 0x0040F49C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F4A0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x0040F4A4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x0040F4A8: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x0040F4AC: addiu       $v0, $sp, 0x248
    ctx->r2 = ADD32(ctx->r29, 0X248);
    // 0x0040F4B0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x0040F4B4: addiu       $v0, $sp, 0x24C
    ctx->r2 = ADD32(ctx->r29, 0X24C);
    // 0x0040F4B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0040F4BC: jal         0x0040F6BC
    // 0x0040F4C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_0040F6BC(rdram, ctx);
        goto after_5;
    // 0x0040F4C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x0040F4C4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F4C8: bne         $v1, $zero, L_0040F680
    if (ctx->r3 != 0) {
        // 0x0040F4CC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_0040F680;
    }
    // 0x0040F4CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F4D0: lw          $v1, 0x244($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X244);
    // 0x0040F4D4: beql        $v1, $v0, L_0040F57C
    if (ctx->r3 == ctx->r2) {
        // 0x0040F4D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_0040F57C;
    }
    goto skip_1;
    // 0x0040F4D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x0040F4DC: beq         $fp, $zero, L_0040F520
    if (ctx->r30 == 0) {
        // 0x0040F4E0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_0040F520;
    }
    // 0x0040F4E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0040F4E4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F4E8: lw          $t0, 0x254($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X254);
    // 0x0040F4EC: sllv        $v0, $t0, $a2
    ctx->r2 = S32(ctx->r8 << (ctx->r6 & 31));
    // 0x0040F4F0: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x0040F4F4: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x0040F4F8: lbu         $v1, 0x3($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X3);
    // 0x0040F4FC: lbu         $a3, 0x258($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X258);
    // 0x0040F500: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x0040F504: jal         0x00411C1C
    // 0x0040F508: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    func_00411C1C(rdram, ctx);
        goto after_6;
    // 0x0040F508: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    after_6:
    // 0x0040F50C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F510: beq         $v1, $zero, L_0040F534
    if (ctx->r3 == 0) {
        // 0x0040F514: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_0040F534;
    }
    // 0x0040F514: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040F518: j           L_0040F68C
    // 0x0040F51C: nop

        goto L_0040F68C;
    // 0x0040F51C: nop

L_0040F520:
    // 0x0040F520: lbu         $v1, 0x3($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X3);
    // 0x0040F524: sll         $v0, $s1, 8
    ctx->r2 = S32(ctx->r17 << 8);
    // 0x0040F528: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0040F52C: sh          $v0, 0x266($sp)
    MEM_H(0X266, ctx->r29) = ctx->r2;
    // 0x0040F530: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_0040F534:
    // 0x0040F534: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x0040F538: lw          $v1, 0x26C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X26C);
L_0040F53C:
    // 0x0040F53C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x0040F540: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x0040F544: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x0040F548: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x0040F54C: slti        $v0, $a1, 0x80
    ctx->r2 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x0040F550: bne         $v0, $zero, L_0040F53C
    if (ctx->r2 != 0) {
        // 0x0040F554: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_0040F53C;
    }
    // 0x0040F554: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x0040F558: lw          $v1, 0x248($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X248);
    // 0x0040F55C: lw          $t0, 0x24C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24C);
    // 0x0040F560: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x0040F564: sb          $s1, 0x258($sp)
    MEM_B(0X258, ctx->r29) = ctx->r17;
    // 0x0040F568: slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x0040F56C: beq         $v0, $zero, L_0040F458
    if (ctx->r2 == 0) {
        // 0x0040F570: sw          $t0, 0x254($sp)
        MEM_W(0X254, ctx->r29) = ctx->r8;
            goto L_0040F458;
    }
    // 0x0040F570: sw          $t0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r8;
    // 0x0040F574: subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
    // 0x0040F578: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_0040F57C:
    // 0x0040F57C: lbu         $v1, 0x64($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X64);
    // 0x0040F580: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x0040F584: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x0040F588: bnel        $v0, $zero, L_0040F480
    if (ctx->r2 != 0) {
        // 0x0040F58C: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040F480;
    }
    goto skip_2;
    // 0x0040F58C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    skip_2:
L_0040F590:
    // 0x0040F590: bgtz        $s2, L_0040F68C
    if (SIGNED(ctx->r18) > 0) {
        // 0x0040F594: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0040F68C;
    }
    // 0x0040F594: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x0040F598: lw          $v1, 0x244($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X244);
    // 0x0040F59C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F5A0: bne         $v1, $v0, L_0040F5B0
    if (ctx->r3 != ctx->r2) {
        // 0x0040F5A4: addiu       $a1, $sp, 0x120
        ctx->r5 = ADD32(ctx->r29, 0X120);
            goto L_0040F5B0;
    }
    // 0x0040F5A4: addiu       $a1, $sp, 0x120
    ctx->r5 = ADD32(ctx->r29, 0X120);
    // 0x0040F5A8: j           L_0040F68C
    // 0x0040F5AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_0040F68C;
    // 0x0040F5AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_0040F5B0:
    // 0x0040F5B0: lw          $t0, 0x254($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X254);
    // 0x0040F5B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0040F5B8: sllv        $v0, $t0, $a2
    ctx->r2 = S32(ctx->r8 << (ctx->r6 & 31));
    // 0x0040F5BC: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x0040F5C0: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    // 0x0040F5C4: lbu         $v0, 0x247($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X247);
    // 0x0040F5C8: lbu         $a3, 0x258($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X258);
    // 0x0040F5CC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F5D0: jal         0x00411C1C
    // 0x0040F5D4: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    func_00411C1C(rdram, ctx);
        goto after_7;
    // 0x0040F5D4: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    after_7:
    // 0x0040F5D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F5DC: bne         $v1, $zero, L_0040F68C
    if (ctx->r3 != 0) {
        // 0x0040F5E0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_0040F68C;
    }
    // 0x0040F5E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040F5E4: lhu         $t0, 0x266($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X266);
    // 0x0040F5E8: sh          $t0, 0x226($sp)
    MEM_H(0X226, ctx->r29) = ctx->r8;
    // 0x0040F5EC: lhu         $t0, 0x250($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X250);
    // 0x0040F5F0: sh          $t0, 0x224($sp)
    MEM_H(0X224, ctx->r29) = ctx->r8;
    // 0x0040F5F4: lw          $t0, 0x2A0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2A0);
    // 0x0040F5F8: addiu       $a0, $sp, 0x220
    ctx->r4 = ADD32(ctx->r29, 0X220);
    // 0x0040F5FC: sh          $zero, 0x22A($sp)
    MEM_H(0X22A, ctx->r29) = 0;
    // 0x0040F600: sw          $t0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r8;
L_0040F604:
    // 0x0040F604: lbu         $v1, 0x0($s6)
    ctx->r3 = MEM_BU(ctx->r22, 0X0);
    // 0x0040F608: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x0040F60C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x0040F610: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x0040F614: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x0040F618: bne         $v0, $zero, L_0040F604
    if (ctx->r2 != 0) {
        // 0x0040F61C: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_0040F604;
    }
    // 0x0040F61C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x0040F620: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040F624: addiu       $a0, $sp, 0x220
    ctx->r4 = ADD32(ctx->r29, 0X220);
L_0040F628:
    // 0x0040F628: lbu         $v1, 0x0($s7)
    ctx->r3 = MEM_BU(ctx->r23, 0X0);
    // 0x0040F62C: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x0040F630: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x0040F634: sb          $v1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r3;
    // 0x0040F638: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x0040F63C: bne         $v0, $zero, L_0040F628
    if (ctx->r2 != 0) {
        // 0x0040F640: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_0040F628;
    }
    // 0x0040F640: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x0040F644: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F648: lhu         $a2, 0x5E($s3)
    ctx->r6 = MEM_HU(ctx->r19, 0X5E);
    // 0x0040F64C: lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X2);
    // 0x0040F650: addiu       $a3, $sp, 0x220
    ctx->r7 = ADD32(ctx->r29, 0X220);
    // 0x0040F654: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0040F658: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x0040F65C: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x0040F660: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x0040F664: jal         0x0029BC88
    // 0x0040F668: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_8;
    // 0x0040F668: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_8:
    // 0x0040F66C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F670: beql        $v1, $zero, L_0040F68C
    if (ctx->r3 == 0) {
        // 0x0040F674: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0040F68C;
    }
    goto skip_3;
    // 0x0040F674: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_3:
    // 0x0040F678: j           L_0040F68C
    // 0x0040F67C: nop

        goto L_0040F68C;
    // 0x0040F67C: nop

L_0040F680:
    // 0x0040F680: j           L_0040F68C
    // 0x0040F684: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_0040F68C;
    // 0x0040F684: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0040F688:
    // 0x0040F688: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_0040F68C:
    // 0x0040F68C: lw          $ra, 0x294($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X294);
    // 0x0040F690: lw          $fp, 0x290($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X290);
    // 0x0040F694: lw          $s7, 0x28C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X28C);
    // 0x0040F698: lw          $s6, 0x288($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X288);
    // 0x0040F69C: lw          $s5, 0x284($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X284);
    // 0x0040F6A0: lw          $s4, 0x280($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X280);
    // 0x0040F6A4: lw          $s3, 0x27C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X27C);
    // 0x0040F6A8: lw          $s2, 0x278($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X278);
    // 0x0040F6AC: lw          $s1, 0x274($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X274);
    // 0x0040F6B0: lw          $s0, 0x270($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X270);
    // 0x0040F6B4: jr          $ra
    // 0x0040F6B8: addiu       $sp, $sp, 0x298
    ctx->r29 = ADD32(ctx->r29, 0X298);
    return;
    // 0x0040F6B8: addiu       $sp, $sp, 0x298
    ctx->r29 = ADD32(ctx->r29, 0X298);
;}
RECOMP_FUNC void func_0040F318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F318: addiu       $sp, $sp, -0x298
    ctx->r29 = ADD32(ctx->r29, -0X298);
    // 0x0040F31C: sw          $s7, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = ctx->r23;
    // 0x0040F320: lw          $s7, 0x2A8($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2A8);
    // 0x0040F324: sw          $s1, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r17;
    // 0x0040F328: lw          $s1, 0x2AC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2AC);
    // 0x0040F32C: sw          $s3, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r19;
    // 0x0040F330: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x0040F334: sw          $s6, 0x288($sp)
    MEM_W(0X288, ctx->r29) = ctx->r22;
    // 0x0040F338: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x0040F33C: sw          $fp, 0x290($sp)
    MEM_W(0X290, ctx->r29) = ctx->r30;
    // 0x0040F340: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x0040F344: sw          $s0, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->r16;
    // 0x0040F348: sh          $a1, 0x250($sp)
    MEM_H(0X250, ctx->r29) = ctx->r5;
    // 0x0040F34C: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x0040F350: sw          $ra, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r31;
    // 0x0040F354: sw          $s5, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r21;
    // 0x0040F358: sw          $s4, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r20;
    // 0x0040F35C: sw          $s2, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->r18;
    // 0x0040F360: sw          $zero, 0x254($sp)
    MEM_W(0X254, ctx->r29) = 0;
    // 0x0040F364: sb          $zero, 0x258($sp)
    MEM_B(0X258, ctx->r29) = 0;
    // 0x0040F368: beq         $s0, $zero, L_0040F688
    if (ctx->r16 == 0) {
        // 0x0040F36C: sw          $a2, 0x2A0($sp)
        MEM_W(0X2A0, ctx->r29) = ctx->r6;
            goto L_0040F688;
    }
    // 0x0040F36C: sw          $a2, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = ctx->r6;
    // 0x0040F370: beq         $a2, $zero, L_0040F688
    if (ctx->r6 == 0) {
        // 0x0040F374: addiu       $a2, $s1, 0xFF
        ctx->r6 = ADD32(ctx->r17, 0XFF);
            goto L_0040F688;
    }
    // 0x0040F374: addiu       $a2, $s1, 0xFF
    ctx->r6 = ADD32(ctx->r17, 0XFF);
    // 0x0040F378: bltzl       $a2, L_0040F380
    if (SIGNED(ctx->r6) < 0) {
        // 0x0040F37C: addiu       $a2, $s1, 0x1FE
        ctx->r6 = ADD32(ctx->r17, 0X1FE);
            goto L_0040F380;
    }
    goto skip_0;
    // 0x0040F37C: addiu       $a2, $s1, 0x1FE
    ctx->r6 = ADD32(ctx->r17, 0X1FE);
    skip_0:
L_0040F380:
    // 0x0040F380: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x0040F384: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0040F388: beq         $v0, $zero, L_0040F688
    if (ctx->r2 == 0) {
        // 0x0040F38C: sra         $s2, $a2, 8
        ctx->r18 = S32(SIGNED(ctx->r6) >> 8);
            goto L_0040F688;
    }
    // 0x0040F38C: sra         $s2, $a2, 8
    ctx->r18 = S32(SIGNED(ctx->r6) >> 8);
    // 0x0040F390: jal         0x00411F74
    // 0x0040F394: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x0040F394: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x0040F398: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x0040F39C: beq         $v0, $v1, L_0040F680
    if (ctx->r2 == ctx->r3) {
        // 0x0040F3A0: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040F680;
    }
    // 0x0040F3A0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F3A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0040F3A8: lw          $a2, 0x2A0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2A0);
    // 0x0040F3AC: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F3B0: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // 0x0040F3B4: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x0040F3B8: jal         0x00411460
    // 0x0040F3BC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_00411460(rdram, ctx);
        goto after_1;
    // 0x0040F3BC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_1:
    // 0x0040F3C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F3C4: beq         $v1, $zero, L_0040F3D4
    if (ctx->r3 == 0) {
        // 0x0040F3C8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040F3D4;
    }
    // 0x0040F3C8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040F3CC: bne         $v1, $v0, L_0040F68C
    if (ctx->r3 != ctx->r2) {
        // 0x0040F3D0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040F68C;
    }
    // 0x0040F3D0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0040F3D4:
    // 0x0040F3D4: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F3D8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x0040F3DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F3E0: bne         $v1, $v0, L_0040F68C
    if (ctx->r3 != ctx->r2) {
        // 0x0040F3E4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_0040F68C;
    }
    // 0x0040F3E4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x0040F3E8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F3EC: jal         0x0040FFF8
    // 0x0040F3F0: addiu       $a1, $sp, 0x240
    ctx->r5 = ADD32(ctx->r29, 0X240);
    func_0040FFF8(rdram, ctx);
        goto after_2;
    // 0x0040F3F0: addiu       $a1, $sp, 0x240
    ctx->r5 = ADD32(ctx->r29, 0X240);
    after_2:
    // 0x0040F3F4: lw          $v0, 0x240($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X240);
    // 0x0040F3F8: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x0040F3FC: bne         $v0, $zero, L_0040F68C
    if (ctx->r2 != 0) {
        // 0x0040F400: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_0040F68C;
    }
    // 0x0040F400: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x0040F404: beq         $s2, $zero, L_0040F688
    if (ctx->r18 == 0) {
        // 0x0040F408: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040F688;
    }
    // 0x0040F408: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F40C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040F410: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x0040F414: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F418: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x0040F41C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0040F420: jal         0x00411460
    // 0x0040F424: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_00411460(rdram, ctx);
        goto after_3;
    // 0x0040F424: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x0040F428: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F42C: beq         $v1, $zero, L_0040F43C
    if (ctx->r3 == 0) {
        // 0x0040F430: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040F43C;
    }
    // 0x0040F430: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040F434: bne         $v1, $v0, L_0040F68C
    if (ctx->r3 != ctx->r2) {
        // 0x0040F438: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040F68C;
    }
    // 0x0040F438: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0040F43C:
    // 0x0040F43C: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F440: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x0040F444: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F448: bne         $v1, $v0, L_0040F460
    if (ctx->r3 != ctx->r2) {
        // 0x0040F44C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_0040F460;
    }
    // 0x0040F44C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x0040F450: j           L_0040F68C
    // 0x0040F454: nop

        goto L_0040F68C;
    // 0x0040F454: nop

L_0040F458:
    // 0x0040F458: j           L_0040F590
    // 0x0040F45C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
        goto L_0040F590;
    // 0x0040F45C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_0040F460:
    // 0x0040F460: lbu         $v0, 0x64($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X64);
    // 0x0040F464: beq         $v0, $zero, L_0040F590
    if (ctx->r2 == 0) {
        // 0x0040F468: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_0040F590;
    }
    // 0x0040F468: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x0040F46C: addiu       $s5, $sp, 0x244
    ctx->r21 = ADD32(ctx->r29, 0X244);
    // 0x0040F470: addiu       $s4, $sp, 0x120
    ctx->r20 = ADD32(ctx->r29, 0X120);
    // 0x0040F474: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x0040F478: sw          $t0, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r8;
    // 0x0040F47C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0040F480:
    // 0x0040F480: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x0040F484: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0040F488: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x0040F48C: jal         0x00411C1C
    // 0x0040F490: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00411C1C(rdram, ctx);
        goto after_4;
    // 0x0040F490: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_4:
    // 0x0040F494: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F498: bne         $v1, $zero, L_0040F680
    if (ctx->r3 != 0) {
        // 0x0040F49C: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040F680;
    }
    // 0x0040F49C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F4A0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x0040F4A4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x0040F4A8: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x0040F4AC: addiu       $v0, $sp, 0x248
    ctx->r2 = ADD32(ctx->r29, 0X248);
    // 0x0040F4B0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x0040F4B4: addiu       $v0, $sp, 0x24C
    ctx->r2 = ADD32(ctx->r29, 0X24C);
    // 0x0040F4B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0040F4BC: jal         0x0040F6BC
    // 0x0040F4C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_0040F6BC(rdram, ctx);
        goto after_5;
    // 0x0040F4C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x0040F4C4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F4C8: bne         $v1, $zero, L_0040F680
    if (ctx->r3 != 0) {
        // 0x0040F4CC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_0040F680;
    }
    // 0x0040F4CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F4D0: lw          $v1, 0x244($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X244);
    // 0x0040F4D4: beql        $v1, $v0, L_0040F57C
    if (ctx->r3 == ctx->r2) {
        // 0x0040F4D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_0040F57C;
    }
    goto skip_1;
    // 0x0040F4D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x0040F4DC: beq         $fp, $zero, L_0040F520
    if (ctx->r30 == 0) {
        // 0x0040F4E0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_0040F520;
    }
    // 0x0040F4E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0040F4E4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F4E8: lw          $t0, 0x254($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X254);
    // 0x0040F4EC: sllv        $v0, $t0, $a2
    ctx->r2 = S32(ctx->r8 << (ctx->r6 & 31));
    // 0x0040F4F0: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x0040F4F4: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x0040F4F8: lbu         $v1, 0x3($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X3);
    // 0x0040F4FC: lbu         $a3, 0x258($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X258);
    // 0x0040F500: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x0040F504: jal         0x00411C1C
    // 0x0040F508: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    func_00411C1C(rdram, ctx);
        goto after_6;
    // 0x0040F508: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    after_6:
    // 0x0040F50C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F510: beq         $v1, $zero, L_0040F534
    if (ctx->r3 == 0) {
        // 0x0040F514: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_0040F534;
    }
    // 0x0040F514: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040F518: j           L_0040F68C
    // 0x0040F51C: nop

        goto L_0040F68C;
    // 0x0040F51C: nop

L_0040F520:
    // 0x0040F520: lbu         $v1, 0x3($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X3);
    // 0x0040F524: sll         $v0, $s1, 8
    ctx->r2 = S32(ctx->r17 << 8);
    // 0x0040F528: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x0040F52C: sh          $v0, 0x266($sp)
    MEM_H(0X266, ctx->r29) = ctx->r2;
    // 0x0040F530: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_0040F534:
    // 0x0040F534: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x0040F538: lw          $v1, 0x26C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X26C);
L_0040F53C:
    // 0x0040F53C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x0040F540: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x0040F544: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x0040F548: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x0040F54C: slti        $v0, $a1, 0x80
    ctx->r2 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x0040F550: bne         $v0, $zero, L_0040F53C
    if (ctx->r2 != 0) {
        // 0x0040F554: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_0040F53C;
    }
    // 0x0040F554: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x0040F558: lw          $v1, 0x248($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X248);
    // 0x0040F55C: lw          $t0, 0x24C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24C);
    // 0x0040F560: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x0040F564: sb          $s1, 0x258($sp)
    MEM_B(0X258, ctx->r29) = ctx->r17;
    // 0x0040F568: slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x0040F56C: beq         $v0, $zero, L_0040F458
    if (ctx->r2 == 0) {
        // 0x0040F570: sw          $t0, 0x254($sp)
        MEM_W(0X254, ctx->r29) = ctx->r8;
            goto L_0040F458;
    }
    // 0x0040F570: sw          $t0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r8;
    // 0x0040F574: subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
    // 0x0040F578: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_0040F57C:
    // 0x0040F57C: lbu         $v1, 0x64($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X64);
    // 0x0040F580: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x0040F584: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x0040F588: bnel        $v0, $zero, L_0040F480
    if (ctx->r2 != 0) {
        // 0x0040F58C: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040F480;
    }
    goto skip_2;
    // 0x0040F58C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    skip_2:
L_0040F590:
    // 0x0040F590: bgtz        $s2, L_0040F68C
    if (SIGNED(ctx->r18) > 0) {
        // 0x0040F594: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0040F68C;
    }
    // 0x0040F594: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x0040F598: lw          $v1, 0x244($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X244);
    // 0x0040F59C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F5A0: bne         $v1, $v0, L_0040F5B0
    if (ctx->r3 != ctx->r2) {
        // 0x0040F5A4: addiu       $a1, $sp, 0x120
        ctx->r5 = ADD32(ctx->r29, 0X120);
            goto L_0040F5B0;
    }
    // 0x0040F5A4: addiu       $a1, $sp, 0x120
    ctx->r5 = ADD32(ctx->r29, 0X120);
    // 0x0040F5A8: j           L_0040F68C
    // 0x0040F5AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_0040F68C;
    // 0x0040F5AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_0040F5B0:
    // 0x0040F5B0: lw          $t0, 0x254($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X254);
    // 0x0040F5B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0040F5B8: sllv        $v0, $t0, $a2
    ctx->r2 = S32(ctx->r8 << (ctx->r6 & 31));
    // 0x0040F5BC: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x0040F5C0: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    // 0x0040F5C4: lbu         $v0, 0x247($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X247);
    // 0x0040F5C8: lbu         $a3, 0x258($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X258);
    // 0x0040F5CC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x0040F5D0: jal         0x00411C1C
    // 0x0040F5D4: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    func_00411C1C(rdram, ctx);
        goto after_7;
    // 0x0040F5D4: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    after_7:
    // 0x0040F5D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F5DC: bne         $v1, $zero, L_0040F68C
    if (ctx->r3 != 0) {
        // 0x0040F5E0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_0040F68C;
    }
    // 0x0040F5E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040F5E4: lhu         $t0, 0x266($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X266);
    // 0x0040F5E8: sh          $t0, 0x226($sp)
    MEM_H(0X226, ctx->r29) = ctx->r8;
    // 0x0040F5EC: lhu         $t0, 0x250($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X250);
    // 0x0040F5F0: sh          $t0, 0x224($sp)
    MEM_H(0X224, ctx->r29) = ctx->r8;
    // 0x0040F5F4: lw          $t0, 0x2A0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2A0);
    // 0x0040F5F8: addiu       $a0, $sp, 0x220
    ctx->r4 = ADD32(ctx->r29, 0X220);
    // 0x0040F5FC: sh          $zero, 0x22A($sp)
    MEM_H(0X22A, ctx->r29) = 0;
    // 0x0040F600: sw          $t0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r8;
L_0040F604:
    // 0x0040F604: lbu         $v1, 0x0($s6)
    ctx->r3 = MEM_BU(ctx->r22, 0X0);
    // 0x0040F608: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x0040F60C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x0040F610: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x0040F614: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x0040F618: bne         $v0, $zero, L_0040F604
    if (ctx->r2 != 0) {
        // 0x0040F61C: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_0040F604;
    }
    // 0x0040F61C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x0040F620: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0040F624: addiu       $a0, $sp, 0x220
    ctx->r4 = ADD32(ctx->r29, 0X220);
L_0040F628:
    // 0x0040F628: lbu         $v1, 0x0($s7)
    ctx->r3 = MEM_BU(ctx->r23, 0X0);
    // 0x0040F62C: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x0040F630: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x0040F634: sb          $v1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r3;
    // 0x0040F638: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x0040F63C: bne         $v0, $zero, L_0040F628
    if (ctx->r2 != 0) {
        // 0x0040F640: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_0040F628;
    }
    // 0x0040F640: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x0040F644: lw          $t0, 0x2B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2B0);
    // 0x0040F648: lhu         $a2, 0x5E($s3)
    ctx->r6 = MEM_HU(ctx->r19, 0X5E);
    // 0x0040F64C: lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X2);
    // 0x0040F650: addiu       $a3, $sp, 0x220
    ctx->r7 = ADD32(ctx->r29, 0X220);
    // 0x0040F654: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0040F658: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x0040F65C: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x0040F660: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x0040F664: jal         0x0029BC88
    // 0x0040F668: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_8;
    // 0x0040F668: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_8:
    // 0x0040F66C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040F670: beql        $v1, $zero, L_0040F68C
    if (ctx->r3 == 0) {
        // 0x0040F674: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0040F68C;
    }
    goto skip_3;
    // 0x0040F674: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_3:
    // 0x0040F678: j           L_0040F68C
    // 0x0040F67C: nop

        goto L_0040F68C;
    // 0x0040F67C: nop

L_0040F680:
    // 0x0040F680: j           L_0040F68C
    // 0x0040F684: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_0040F68C;
    // 0x0040F684: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0040F688:
    // 0x0040F688: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_0040F68C:
    // 0x0040F68C: lw          $ra, 0x294($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X294);
    // 0x0040F690: lw          $fp, 0x290($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X290);
    // 0x0040F694: lw          $s7, 0x28C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X28C);
    // 0x0040F698: lw          $s6, 0x288($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X288);
    // 0x0040F69C: lw          $s5, 0x284($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X284);
    // 0x0040F6A0: lw          $s4, 0x280($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X280);
    // 0x0040F6A4: lw          $s3, 0x27C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X27C);
    // 0x0040F6A8: lw          $s2, 0x278($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X278);
    // 0x0040F6AC: lw          $s1, 0x274($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X274);
    // 0x0040F6B0: lw          $s0, 0x270($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X270);
    // 0x0040F6B4: jr          $ra
    // 0x0040F6B8: addiu       $sp, $sp, 0x298
    ctx->r29 = ADD32(ctx->r29, 0X298);
    return;
    // 0x0040F6B8: addiu       $sp, $sp, 0x298
    ctx->r29 = ADD32(ctx->r29, 0X298);
;}
RECOMP_FUNC void func_0040F6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F6BC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x0040F6C0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x0040F6C4: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x0040F6C8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x0040F6CC: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x0040F6D0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x0040F6D4: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x0040F6D8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x0040F6DC: lw          $s2, 0x6C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X6C);
    // 0x0040F6E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0040F6E4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x0040F6E8: lbu         $s3, 0x6B($sp)
    ctx->r19 = MEM_BU(ctx->r29, 0X6B);
    // 0x0040F6EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040F6F0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x0040F6F4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x0040F6F8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x0040F6FC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x0040F700: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x0040F704: bne         $s3, $zero, L_0040F710
    if (ctx->r19 != 0) {
        // 0x0040F708: sw          $a3, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r7;
            goto L_0040F710;
    }
    // 0x0040F708: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x0040F70C: lw          $v0, 0x60($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X60);
L_0040F710:
    // 0x0040F710: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x0040F714: slti        $v0, $s0, 0x80
    ctx->r2 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x0040F718: beq         $v0, $zero, L_0040F744
    if (ctx->r2 == 0) {
        // 0x0040F71C: sll         $v0, $s0, 1
        ctx->r2 = S32(ctx->r16 << 1);
            goto L_0040F744;
    }
    // 0x0040F71C: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x0040F720: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x0040F724: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
L_0040F728:
    // 0x0040F728: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x0040F72C: beq         $v0, $a1, L_0040F748
    if (ctx->r2 == ctx->r5) {
        // 0x0040F730: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_0040F748;
    }
    // 0x0040F730: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x0040F734: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x0040F738: slti        $v0, $s0, 0x80
    ctx->r2 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x0040F73C: bne         $v0, $zero, L_0040F728
    if (ctx->r2 != 0) {
        // 0x0040F740: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_0040F728;
    }
    // 0x0040F740: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_0040F744:
    // 0x0040F744: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_0040F748:
    // 0x0040F748: bne         $s0, $v0, L_0040F764
    if (ctx->r16 != ctx->r2) {
        // 0x0040F74C: addiu       $v1, $zero, 0x1F
        ctx->r3 = ADD32(0, 0X1F);
            goto L_0040F764;
    }
    // 0x0040F74C: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x0040F750: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x0040F754: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F758: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
L_0040F75C:
    // 0x0040F75C: j           L_0040F858
    // 0x0040F760: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
        goto L_0040F858;
    // 0x0040F760: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_0040F764:
    // 0x0040F764: addiu       $v0, $sp, 0x2F
    ctx->r2 = ADD32(ctx->r29, 0X2F);
L_0040F768:
    // 0x0040F768: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x0040F76C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x0040F770: bgez        $v1, L_0040F768
    if (SIGNED(ctx->r3) >= 0) {
        // 0x0040F774: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_0040F768;
    }
    // 0x0040F774: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x0040F778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040F77C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x0040F780: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0040F784: addu        $s0, $a1, $v0
    ctx->r16 = ADD32(ctx->r5, ctx->r2);
    // 0x0040F788: slt         $v0, $v0, $s5
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x0040F78C: beq         $v0, $zero, L_0040F804
    if (ctx->r2 == 0) {
        // 0x0040F790: addu        $s7, $a1, $zero
        ctx->r23 = ADD32(ctx->r5, 0);
            goto L_0040F804;
    }
    // 0x0040F790: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x0040F794: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x0040F798: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x0040F79C: addu        $s1, $v0, $s4
    ctx->r17 = ADD32(ctx->r2, ctx->r20);
L_0040F7A0:
    // 0x0040F7A0: slti        $v0, $s0, 0x80
    ctx->r2 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x0040F7A4: beq         $v0, $zero, L_0040F804
    if (ctx->r2 == 0) {
        // 0x0040F7A8: nop
    
            goto L_0040F804;
    }
    // 0x0040F7A8: nop

    // 0x0040F7AC: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x0040F7B0: bnel        $v0, $fp, L_0040F7F4
    if (ctx->r2 != ctx->r30) {
        // 0x0040F7B4: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_0040F7F4;
    }
    goto skip_0;
    // 0x0040F7B4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    skip_0:
    // 0x0040F7B8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x0040F7BC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x0040F7C0: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    // 0x0040F7C4: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x0040F7C8: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x0040F7CC: sb          $s3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r19;
    // 0x0040F7D0: jal         0x0040F888
    // 0x0040F7D4: sb          $s0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r16;
    func_0040F888(rdram, ctx);
        goto after_0;
    // 0x0040F7D4: sb          $s0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r16;
    after_0:
    // 0x0040F7D8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x0040F7DC: bne         $a0, $zero, L_0040F75C
    if (ctx->r4 != 0) {
        // 0x0040F7E0: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_0040F75C;
    }
    // 0x0040F7E0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0040F7E4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x0040F7E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x0040F7EC: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x0040F7F0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_0040F7F4:
    // 0x0040F7F4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x0040F7F8: slt         $v0, $v0, $s5
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x0040F7FC: bne         $v0, $zero, L_0040F7A0
    if (ctx->r2 != 0) {
        // 0x0040F800: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_0040F7A0;
    }
    // 0x0040F800: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_0040F804:
    // 0x0040F804: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x0040F808: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x0040F80C: bne         $s0, $v0, L_0040F830
    if (ctx->r16 != ctx->r2) {
        // 0x0040F810: sw          $s7, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r23;
            goto L_0040F830;
    }
    // 0x0040F810: sw          $s7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r23;
    // 0x0040F814: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x0040F818: slt         $v0, $v0, $s5
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x0040F81C: beql        $v0, $zero, L_0040F834
    if (ctx->r2 == 0) {
        // 0x0040F820: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_0040F834;
    }
    goto skip_1;
    // 0x0040F820: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    skip_1:
    // 0x0040F824: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x0040F828: j           L_0040F75C
    // 0x0040F82C: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
        goto L_0040F75C;
    // 0x0040F82C: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
L_0040F830:
    // 0x0040F830: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_0040F834:
    // 0x0040F834: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x0040F838: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    // 0x0040F83C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x0040F840: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x0040F844: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x0040F848: jal         0x0040F888
    // 0x0040F84C: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    func_0040F888(rdram, ctx);
        goto after_1;
    // 0x0040F84C: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    after_1:
    // 0x0040F850: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x0040F854: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_0040F858:
    // 0x0040F858: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x0040F85C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x0040F860: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x0040F864: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x0040F868: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x0040F86C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x0040F870: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x0040F874: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x0040F878: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x0040F87C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x0040F880: jr          $ra
    // 0x0040F884: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x0040F884: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_0040F888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F888: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x0040F88C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x0040F890: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x0040F894: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x0040F898: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x0040F89C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x0040F8A0: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x0040F8A4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x0040F8A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x0040F8AC: jal         0x0041203C
    // 0x0040F8B0: sb          $a3, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r7;
    func_0041203C(rdram, ctx);
        goto after_0;
    // 0x0040F8B0: sb          $a3, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r7;
    after_0:
    // 0x0040F8B4: bne         $v0, $zero, L_0040F8FC
    if (ctx->r2 != 0) {
        // 0x0040F8B8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_0040F8FC;
    }
    // 0x0040F8B8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x0040F8BC: sll         $s2, $s2, 3
    ctx->r18 = S32(ctx->r18 << 3);
    // 0x0040F8C0: addu        $a2, $s2, $s0
    ctx->r6 = ADD32(ctx->r18, ctx->r16);
L_0040F8C4:
    // 0x0040F8C4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x0040F8C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0040F8CC: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x0040F8D0: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x0040F8D4: jal         0x0029BC88
    // 0x0040F8D8: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_0029BC88(rdram, ctx);
        goto after_1;
    // 0x0040F8D8: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
    // 0x0040F8DC: bne         $v0, $zero, L_0040F8F0
    if (ctx->r2 != 0) {
        // 0x0040F8E0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_0040F8F0;
    }
    // 0x0040F8E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x0040F8E4: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x0040F8E8: bne         $v0, $zero, L_0040F8C4
    if (ctx->r2 != 0) {
        // 0x0040F8EC: addu        $a2, $s2, $s0
        ctx->r6 = ADD32(ctx->r18, ctx->r16);
            goto L_0040F8C4;
    }
    // 0x0040F8EC: addu        $a2, $s2, $s0
    ctx->r6 = ADD32(ctx->r18, ctx->r16);
L_0040F8F0:
    // 0x0040F8F0: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    // 0x0040F8F4: jal         0x0041203C
    // 0x0040F8F8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0041203C(rdram, ctx);
        goto after_2;
    // 0x0040F8F8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
L_0040F8FC:
    // 0x0040F8FC: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x0040F900: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x0040F904: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x0040F908: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x0040F90C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x0040F910: jr          $ra
    // 0x0040F914: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x0040F914: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_0040F918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040F918: addiu       $sp, $sp, -0x168
    ctx->r29 = ADD32(ctx->r29, -0X168);
    // 0x0040F91C: sw          $s2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r18;
    // 0x0040F920: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x0040F924: sw          $s1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r17;
    // 0x0040F928: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x0040F92C: sw          $s3, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r19;
    // 0x0040F930: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x0040F934: sw          $s0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r16;
    // 0x0040F938: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x0040F93C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x0040F940: sw          $ra, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r31;
    // 0x0040F944: sw          $s5, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r21;
    // 0x0040F948: sw          $s4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r20;
    // 0x0040F94C: beq         $v0, $zero, L_0040F9D8
    if (ctx->r2 == 0) {
        // 0x0040F950: sh          $zero, 0x144($sp)
        MEM_H(0X144, ctx->r29) = 0;
            goto L_0040F9D8;
    }
    // 0x0040F950: sh          $zero, 0x144($sp)
    MEM_H(0X144, ctx->r29) = 0;
    // 0x0040F954: beq         $s1, $zero, L_0040FB20
    if (ctx->r17 == 0) {
        // 0x0040F958: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040FB20;
    }
    // 0x0040F958: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040F95C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x0040F960: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0040F964: beq         $v0, $zero, L_0040FB20
    if (ctx->r2 == 0) {
        // 0x0040F968: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040FB20;
    }
    // 0x0040F968: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040F96C: jal         0x00411F74
    // 0x0040F970: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x0040F970: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x0040F974: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x0040F978: beq         $v0, $v1, L_0040FB20
    if (ctx->r2 == ctx->r3) {
        // 0x0040F97C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040FB20;
    }
    // 0x0040F97C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x0040F980: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x0040F984: beq         $v0, $zero, L_0040F9A0
    if (ctx->r2 == 0) {
        // 0x0040F988: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_0040F9A0;
    }
    // 0x0040F988: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x0040F98C: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    // 0x0040F990: jal         0x0041203C
    // 0x0040F994: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_1;
    // 0x0040F994: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x0040F998: bne         $v0, $zero, L_0040FB20
    if (ctx->r2 != 0) {
        // 0x0040F99C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_0040FB20;
    }
    // 0x0040F99C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_0040F9A0:
    // 0x0040F9A0: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x0040F9A4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x0040F9A8: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x0040F9AC: lw          $v0, 0x178($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X178);
    // 0x0040F9B0: addiu       $s0, $sp, 0x140
    ctx->r16 = ADD32(ctx->r29, 0X140);
    // 0x0040F9B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x0040F9B8: jal         0x00411460
    // 0x0040F9BC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_00411460(rdram, ctx);
        goto after_2;
    // 0x0040F9BC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x0040F9C0: bne         $v0, $zero, L_0040FB20
    if (ctx->r2 != 0) {
        // 0x0040F9C4: nop
    
            goto L_0040FB20;
    }
    // 0x0040F9C4: nop

    // 0x0040F9C8: lw          $v1, 0x140($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X140);
    // 0x0040F9CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0040F9D0: bne         $v1, $v0, L_0040F9E0
    if (ctx->r3 != ctx->r2) {
        // 0x0040F9D4: addiu       $a3, $sp, 0x120
        ctx->r7 = ADD32(ctx->r29, 0X120);
            goto L_0040F9E0;
    }
    // 0x0040F9D4: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
L_0040F9D8:
    // 0x0040F9D8: j           L_0040FB20
    // 0x0040F9DC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_0040FB20;
    // 0x0040F9DC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_0040F9E0:
    // 0x0040F9E0: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x0040F9E4: lhu         $a2, 0x5E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5E);
    // 0x0040F9E8: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x0040F9EC: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x0040F9F0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x0040F9F4: jal         0x0029B8D0
    // 0x0040F9F8: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_3;
    // 0x0040F9F8: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_3:
    // 0x0040F9FC: bne         $v0, $zero, L_0040FB20
    if (ctx->r2 != 0) {
        // 0x0040FA00: nop
    
            goto L_0040FB20;
    }
    // 0x0040FA00: nop

    // 0x0040FA04: lbu         $s1, 0x127($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X127);
    // 0x0040FA08: lbu         $s3, 0x126($sp)
    ctx->r19 = MEM_BU(ctx->r29, 0X126);
    // 0x0040FA0C: lbu         $v0, 0x64($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X64);
    // 0x0040FA10: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    // 0x0040FA14: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x0040FA18: beq         $v0, $zero, L_0040FAB4
    if (ctx->r2 == 0) {
        // 0x0040FA1C: addiu       $s4, $sp, 0x146
        ctx->r20 = ADD32(ctx->r29, 0X146);
            goto L_0040FAB4;
    }
    // 0x0040FA1C: addiu       $s4, $sp, 0x146
    ctx->r20 = ADD32(ctx->r29, 0X146);
    // 0x0040FA20: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x0040FA24: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_0040FA28:
    // 0x0040FA28: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x0040FA2C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0040FA30: jal         0x00411C1C
    // 0x0040FA34: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00411C1C(rdram, ctx);
        goto after_4;
    // 0x0040FA34: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_4:
    // 0x0040FA38: bne         $v0, $zero, L_0040FB20
    if (ctx->r2 != 0) {
        // 0x0040FA3C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_0040FB20;
    }
    // 0x0040FA3C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x0040FA40: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x0040FA44: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x0040FA48: addiu       $a3, $sp, 0x144
    ctx->r7 = ADD32(ctx->r29, 0X144);
    // 0x0040FA4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0040FA50: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x0040FA54: jal         0x0040FB44
    // 0x0040FA58: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    func_0040FB44(rdram, ctx);
        goto after_5;
    // 0x0040FA58: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    after_5:
    // 0x0040FA5C: bne         $v0, $zero, L_0040FB20
    if (ctx->r2 != 0) {
        // 0x0040FA60: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_0040FB20;
    }
    // 0x0040FA60: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x0040FA64: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x0040FA68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x0040FA6C: jal         0x00411C1C
    // 0x0040FA70: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00411C1C(rdram, ctx);
        goto after_6;
    // 0x0040FA70: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_6:
    // 0x0040FA74: bne         $v0, $zero, L_0040FB20
    if (ctx->r2 != 0) {
        // 0x0040FA78: nop
    
            goto L_0040FB20;
    }
    // 0x0040FA78: nop

    // 0x0040FA7C: lhu         $v0, 0x146($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X146);
    // 0x0040FA80: beq         $v0, $s5, L_0040FAA4
    if (ctx->r2 == ctx->r21) {
        // 0x0040FA84: nop
    
            goto L_0040FAA4;
    }
    // 0x0040FA84: nop

    // 0x0040FA88: lbu         $s3, 0x146($sp)
    ctx->r19 = MEM_BU(ctx->r29, 0X146);
    // 0x0040FA8C: lbu         $s1, 0x1($s4)
    ctx->r17 = MEM_BU(ctx->r20, 0X1);
    // 0x0040FA90: lbu         $v0, 0x64($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X64);
    // 0x0040FA94: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    // 0x0040FA98: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x0040FA9C: bne         $v0, $zero, L_0040FA28
    if (ctx->r2 != 0) {
        // 0x0040FAA0: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_0040FA28;
    }
    // 0x0040FAA0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_0040FAA4:
    // 0x0040FAA4: lbu         $v0, 0x64($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X64);
    // 0x0040FAA8: sltu        $v0, $s3, $v0
    ctx->r2 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x0040FAAC: bne         $v0, $zero, L_0040FABC
    if (ctx->r2 != 0) {
        // 0x0040FAB0: addiu       $v1, $zero, 0xF
        ctx->r3 = ADD32(0, 0XF);
            goto L_0040FABC;
    }
    // 0x0040FAB0: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_0040FAB4:
    // 0x0040FAB4: j           L_0040FB20
    // 0x0040FAB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_0040FB20;
    // 0x0040FAB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_0040FABC:
    // 0x0040FABC: addiu       $v0, $sp, 0x12F
    ctx->r2 = ADD32(ctx->r29, 0X12F);
    // 0x0040FAC0: sw          $zero, 0x120($sp)
    MEM_W(0X120, ctx->r29) = 0;
    // 0x0040FAC4: sh          $zero, 0x124($sp)
    MEM_H(0X124, ctx->r29) = 0;
    // 0x0040FAC8: sh          $zero, 0x126($sp)
    MEM_H(0X126, ctx->r29) = 0;
    // 0x0040FACC: sh          $zero, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = 0;
L_0040FAD0:
    // 0x0040FAD0: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x0040FAD4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x0040FAD8: bgez        $v1, L_0040FAD0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x0040FADC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_0040FAD0;
    }
    // 0x0040FADC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x0040FAE0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x0040FAE4: addiu       $v0, $sp, 0x123
    ctx->r2 = ADD32(ctx->r29, 0X123);
L_0040FAE8:
    // 0x0040FAE8: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x0040FAEC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x0040FAF0: bgez        $v1, L_0040FAE8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x0040FAF4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_0040FAE8;
    }
    // 0x0040FAF4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x0040FAF8: sb          $zero, 0x128($sp)
    MEM_B(0X128, ctx->r29) = 0;
    // 0x0040FAFC: lhu         $a2, 0x5E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5E);
    // 0x0040FB00: lhu         $v0, 0x142($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X142);
    // 0x0040FB04: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    // 0x0040FB08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0040FB0C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x0040FB10: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x0040FB14: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x0040FB18: jal         0x0029BC88
    // 0x0040FB1C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_7;
    // 0x0040FB1C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_7:
L_0040FB20:
    // 0x0040FB20: lw          $ra, 0x160($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X160);
    // 0x0040FB24: lw          $s5, 0x15C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X15C);
    // 0x0040FB28: lw          $s4, 0x158($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X158);
    // 0x0040FB2C: lw          $s3, 0x154($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X154);
    // 0x0040FB30: lw          $s2, 0x150($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X150);
    // 0x0040FB34: lw          $s1, 0x14C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14C);
    // 0x0040FB38: lw          $s0, 0x148($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X148);
    // 0x0040FB3C: jr          $ra
    // 0x0040FB40: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
    return;
    // 0x0040FB40: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
;}
RECOMP_FUNC void func_0040FB44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040FB44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x0040FB48: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x0040FB4C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x0040FB50: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x0040FB54: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x0040FB58: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x0040FB5C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x0040FB60: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x0040FB64: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x0040FB68: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x0040FB6C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x0040FB70: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x0040FB74: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x0040FB78: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x0040FB7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0040FB80: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x0040FB84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040FB88: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x0040FB8C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x0040FB90: lbu         $a3, 0x43($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X43);
    // 0x0040FB94: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x0040FB98: beq         $a0, $v0, L_0040FBB4
    if (ctx->r4 == ctx->r2) {
        // 0x0040FB9C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_0040FBB4;
    }
    // 0x0040FB9C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0040FBA0: srl         $v0, $a0, 8
    ctx->r2 = S32(U32(ctx->r4) >> 8);
    // 0x0040FBA4: bne         $v0, $zero, L_0040FBC4
    if (ctx->r2 != 0) {
        // 0x0040FBA8: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_0040FBC4;
    }
    // 0x0040FBA8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x0040FBAC: j           L_0040FBBC
    // 0x0040FBB0: nop

        goto L_0040FBBC;
    // 0x0040FBB0: nop

L_0040FBB4:
    // 0x0040FBB4: bne         $a3, $zero, L_0040FBC0
    if (ctx->r7 != 0) {
        // 0x0040FBB8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_0040FBC0;
    }
    // 0x0040FBB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_0040FBBC:
    // 0x0040FBBC: lw          $v1, 0x60($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X60);
L_0040FBC0:
    // 0x0040FBC0: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_0040FBC4:
    // 0x0040FBC4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x0040FBC8: beq         $v0, $zero, L_0040FBD8
    if (ctx->r2 == 0) {
        // 0x0040FBCC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_0040FBD8;
    }
    // 0x0040FBCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040FBD0: bne         $s0, $v0, L_0040FCBC
    if (ctx->r16 != ctx->r2) {
        // 0x0040FBD4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0040FCBC;
    }
    // 0x0040FBD4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_0040FBD8:
    // 0x0040FBD8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x0040FBDC: bne         $a1, $s4, L_0040FBF8
    if (ctx->r5 != ctx->r20) {
        // 0x0040FBE0: sh          $s0, 0x0($s6)
        MEM_H(0X0, ctx->r22) = ctx->r16;
            goto L_0040FBF8;
    }
    // 0x0040FBE0: sh          $s0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r16;
    // 0x0040FBE4: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x0040FBE8: sllv        $v0, $v0, $s4
    ctx->r2 = S32(ctx->r2 << (ctx->r20 & 31));
    // 0x0040FBEC: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x0040FBF0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x0040FBF4: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_0040FBF8:
    // 0x0040FBF8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x0040FBFC: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x0040FC00: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x0040FC04: andi        $s1, $a3, 0xFF
    ctx->r17 = ctx->r7 & 0XFF;
    // 0x0040FC08: jal         0x0040FCE4
    // 0x0040FC0C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_0040FCE4(rdram, ctx);
        goto after_0;
    // 0x0040FC0C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_0:
    // 0x0040FC10: bne         $v0, $zero, L_0040FCBC
    if (ctx->r2 != 0) {
        // 0x0040FC14: andi        $v1, $s0, 0xFFFF
        ctx->r3 = ctx->r16 & 0XFFFF;
            goto L_0040FCBC;
    }
    // 0x0040FC14: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x0040FC18: beq         $v1, $s4, L_0040FCBC
    if (ctx->r3 == ctx->r20) {
        // 0x0040FC1C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0040FCBC;
    }
    // 0x0040FC1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x0040FC20: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x0040FC24: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040FC28: bnel        $v0, $zero, L_0040FCB8
    if (ctx->r2 != 0) {
        // 0x0040FC2C: sh          $s0, 0x0($s6)
        MEM_H(0X0, ctx->r22) = ctx->r16;
            goto L_0040FCB8;
    }
    goto skip_0;
    // 0x0040FC2C: sh          $s0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r16;
    skip_0:
    // 0x0040FC30: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x0040FC34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_0040FC38:
    // 0x0040FC38: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x0040FC3C: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x0040FC40: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x0040FC44: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x0040FC48: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x0040FC4C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x0040FC50: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x0040FC54: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x0040FC58: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x0040FC5C: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x0040FC60: jal         0x0040FCE4
    // 0x0040FC64: sh          $s4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r20;
    func_0040FCE4(rdram, ctx);
        goto after_1;
    // 0x0040FC64: sh          $s4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r20;
    after_1:
    // 0x0040FC68: bne         $v0, $zero, L_0040FCBC
    if (ctx->r2 != 0) {
        // 0x0040FC6C: andi        $v1, $s0, 0xFFFF
        ctx->r3 = ctx->r16 & 0XFFFF;
            goto L_0040FCBC;
    }
    // 0x0040FC6C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x0040FC70: srl         $a0, $v1, 8
    ctx->r4 = S32(U32(ctx->r3) >> 8);
    // 0x0040FC74: bne         $a0, $s1, L_0040FC8C
    if (ctx->r4 != ctx->r17) {
        // 0x0040FC78: nop
    
            goto L_0040FC8C;
    }
    // 0x0040FC78: nop

    // 0x0040FC7C: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x0040FC80: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040FC84: beql        $v0, $zero, L_0040FC38
    if (ctx->r2 == 0) {
        // 0x0040FC88: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_0040FC38;
    }
    goto skip_1;
    // 0x0040FC88: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    skip_1:
L_0040FC8C:
    // 0x0040FC8C: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x0040FC90: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040FC94: bnel        $v0, $zero, L_0040FCB8
    if (ctx->r2 != 0) {
        // 0x0040FC98: sh          $s0, 0x0($s6)
        MEM_H(0X0, ctx->r22) = ctx->r16;
            goto L_0040FCB8;
    }
    goto skip_2;
    // 0x0040FC98: sh          $s0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r16;
    skip_2:
    // 0x0040FC9C: bnel        $a0, $s1, L_0040FCB8
    if (ctx->r4 != ctx->r17) {
        // 0x0040FCA0: sh          $s0, 0x0($s6)
        MEM_H(0X0, ctx->r22) = ctx->r16;
            goto L_0040FCB8;
    }
    goto skip_3;
    // 0x0040FCA0: sh          $s0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r16;
    skip_3:
    // 0x0040FCA4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x0040FCA8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x0040FCAC: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x0040FCB0: sh          $s4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r20;
    // 0x0040FCB4: sh          $s0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r16;
L_0040FCB8:
    // 0x0040FCB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040FCBC:
    // 0x0040FCBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x0040FCC0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x0040FCC4: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x0040FCC8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x0040FCCC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x0040FCD0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x0040FCD4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x0040FCD8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0040FCDC: jr          $ra
    // 0x0040FCE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x0040FCE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_0040FCE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040FCE4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x0040FCE8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x0040FCEC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x0040FCF0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x0040FCF4: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x0040FCF8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x0040FCFC: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x0040FD00: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x0040FD04: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x0040FD08: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x0040FD0C: jal         0x0041203C
    // 0x0040FD10: sb          $a3, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r7;
    func_0041203C(rdram, ctx);
        goto after_0;
    // 0x0040FD10: sb          $a3, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r7;
    after_0:
    // 0x0040FD14: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x0040FD18: beq         $s0, $zero, L_0040FD3C
    if (ctx->r16 == 0) {
        // 0x0040FD1C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_0040FD3C;
    }
    // 0x0040FD1C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x0040FD20: j           L_0040FD94
    // 0x0040FD24: nop

        goto L_0040FD94;
    // 0x0040FD24: nop

L_0040FD28:
    // 0x0040FD28: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    // 0x0040FD2C: jal         0x0041203C
    // 0x0040FD30: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_1;
    // 0x0040FD30: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x0040FD34: j           L_0040FD94
    // 0x0040FD38: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
        goto L_0040FD94;
    // 0x0040FD38: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_0040FD3C:
    // 0x0040FD3C: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x0040FD40: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
L_0040FD44:
    // 0x0040FD44: addu        $a2, $s3, $s1
    ctx->r6 = ADD32(ctx->r19, ctx->r17);
    // 0x0040FD48: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x0040FD4C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x0040FD50: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x0040FD54: jal         0x0029B8D0
    // 0x0040FD58: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_0029B8D0(rdram, ctx);
        goto after_2;
    // 0x0040FD58: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x0040FD5C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x0040FD60: bne         $s0, $zero, L_0040FD28
    if (ctx->r16 != 0) {
        // 0x0040FD64: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_0040FD28;
    }
    // 0x0040FD64: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x0040FD68: jal         0x00411EFC
    // 0x0040FD6C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_00411EFC(rdram, ctx);
        goto after_3;
    // 0x0040FD6C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x0040FD70: lhu         $v1, 0x0($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X0);
    // 0x0040FD74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x0040FD78: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x0040FD7C: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x0040FD80: bne         $v0, $zero, L_0040FD44
    if (ctx->r2 != 0) {
        // 0x0040FD84: sh          $v1, 0x0($s4)
        MEM_H(0X0, ctx->r20) = ctx->r3;
            goto L_0040FD44;
    }
    // 0x0040FD84: sh          $v1, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r3;
    // 0x0040FD88: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    // 0x0040FD8C: jal         0x0041203C
    // 0x0040FD90: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_4;
    // 0x0040FD90: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_4:
L_0040FD94:
    // 0x0040FD94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x0040FD98: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x0040FD9C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x0040FDA0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x0040FDA4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x0040FDA8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x0040FDAC: jr          $ra
    // 0x0040FDB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x0040FDB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_0040FDB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040FDB4: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x0040FDB8: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x0040FDBC: sw          $s3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r19;
    // 0x0040FDC0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x0040FDC4: sw          $s1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r17;
    // 0x0040FDC8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0040FDCC: sw          $ra, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r31;
    // 0x0040FDD0: sw          $s7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r23;
    // 0x0040FDD4: sw          $s6, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r22;
    // 0x0040FDD8: sw          $s5, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r21;
    // 0x0040FDDC: sw          $s4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r20;
    // 0x0040FDE0: sw          $s2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r18;
    // 0x0040FDE4: sw          $s0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r16;
    // 0x0040FDE8: lw          $v0, 0x50($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X50);
    // 0x0040FDEC: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040FDF0: beq         $v0, $zero, L_0040FE7C
    if (ctx->r2 == 0) {
        // 0x0040FDF4: addu        $s6, $a2, $zero
        ctx->r22 = ADD32(ctx->r6, 0);
            goto L_0040FE7C;
    }
    // 0x0040FDF4: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x0040FDF8: bltz        $s1, L_0040FFC8
    if (SIGNED(ctx->r17) < 0) {
        // 0x0040FDFC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040FFC8;
    }
    // 0x0040FDFC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040FE00: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x0040FE04: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0040FE08: beq         $v0, $zero, L_0040FFC8
    if (ctx->r2 == 0) {
        // 0x0040FE0C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040FFC8;
    }
    // 0x0040FE0C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040FE10: jal         0x00411F74
    // 0x0040FE14: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x0040FE14: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x0040FE18: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x0040FE1C: beq         $v0, $v1, L_0040FFC8
    if (ctx->r2 == ctx->r3) {
        // 0x0040FE20: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040FFC8;
    }
    // 0x0040FE20: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x0040FE24: lbu         $v0, 0x65($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X65);
    // 0x0040FE28: beq         $v0, $zero, L_0040FE44
    if (ctx->r2 == 0) {
        // 0x0040FE2C: addiu       $a3, $sp, 0x110
        ctx->r7 = ADD32(ctx->r29, 0X110);
            goto L_0040FE44;
    }
    // 0x0040FE2C: addiu       $a3, $sp, 0x110
    ctx->r7 = ADD32(ctx->r29, 0X110);
    // 0x0040FE30: sb          $zero, 0x65($s3)
    MEM_B(0X65, ctx->r19) = 0;
    // 0x0040FE34: jal         0x0041203C
    // 0x0040FE38: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_0041203C(rdram, ctx);
        goto after_1;
    // 0x0040FE38: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_1:
    // 0x0040FE3C: bne         $v0, $zero, L_0040FFC8
    if (ctx->r2 != 0) {
        // 0x0040FE40: addiu       $a3, $sp, 0x110
        ctx->r7 = ADD32(ctx->r29, 0X110);
            goto L_0040FFC8;
    }
    // 0x0040FE40: addiu       $a3, $sp, 0x110
    ctx->r7 = ADD32(ctx->r29, 0X110);
L_0040FE44:
    // 0x0040FE44: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x0040FE48: lhu         $a2, 0x5E($s3)
    ctx->r6 = MEM_HU(ctx->r19, 0X5E);
    // 0x0040FE4C: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x0040FE50: addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // 0x0040FE54: jal         0x0029B8D0
    // 0x0040FE58: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_2;
    // 0x0040FE58: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_2:
    // 0x0040FE5C: bne         $v0, $zero, L_0040FFC8
    if (ctx->r2 != 0) {
        // 0x0040FE60: nop
    
            goto L_0040FFC8;
    }
    // 0x0040FE60: nop

    // 0x0040FE64: lhu         $v0, 0x114($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X114);
    // 0x0040FE68: beq         $v0, $zero, L_0040FFC8
    if (ctx->r2 == 0) {
        // 0x0040FE6C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040FFC8;
    }
    // 0x0040FE6C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040FE70: lw          $v0, 0x110($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X110);
    // 0x0040FE74: bne         $v0, $zero, L_0040FE84
    if (ctx->r2 != 0) {
        // 0x0040FE78: nop
    
            goto L_0040FE84;
    }
    // 0x0040FE78: nop

L_0040FE7C:
    // 0x0040FE7C: j           L_0040FFC8
    // 0x0040FE80: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_0040FFC8;
    // 0x0040FE80: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_0040FE84:
    // 0x0040FE84: lhu         $v0, 0x116($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X116);
    // 0x0040FE88: lw          $v1, 0x60($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X60);
    // 0x0040FE8C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x0040FE90: bne         $v0, $zero, L_0040FFC8
    if (ctx->r2 != 0) {
        // 0x0040FE94: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0040FFC8;
    }
    // 0x0040FE94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x0040FE98: lbu         $s5, 0x117($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0X117);
    // 0x0040FE9C: lbu         $s2, 0x116($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X116);
    // 0x0040FEA0: lbu         $v0, 0x64($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X64);
    // 0x0040FEA4: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // 0x0040FEA8: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x0040FEAC: beq         $v0, $zero, L_0040FF4C
    if (ctx->r2 == 0) {
        // 0x0040FEB0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_0040FF4C;
    }
    // 0x0040FEB0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x0040FEB4: addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
    // 0x0040FEB8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x0040FEBC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0040FEC0:
    // 0x0040FEC0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x0040FEC4: jal         0x00411C1C
    // 0x0040FEC8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00411C1C(rdram, ctx);
        goto after_3;
    // 0x0040FEC8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // 0x0040FECC: bne         $v0, $zero, L_0040FFC8
    if (ctx->r2 != 0) {
        // 0x0040FED0: nop
    
            goto L_0040FFC8;
    }
    // 0x0040FED0: nop

    // 0x0040FED4: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x0040FED8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x0040FEDC: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x0040FEE0: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x0040FEE4: lw          $v1, 0x60($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X60);
    // 0x0040FEE8: slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x0040FEEC: bne         $v0, $zero, L_0040FF30
    if (ctx->r2 != 0) {
        // 0x0040FEF0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_0040FF30;
    }
    // 0x0040FEF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x0040FEF4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x0040FEF8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_0040FEFC:
    // 0x0040FEFC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x0040FF00: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x0040FF04: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x0040FF08: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x0040FF0C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x0040FF10: beq         $v1, $s2, L_0040FF24
    if (ctx->r3 == ctx->r18) {
        // 0x0040FF14: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_0040FF24;
    }
    // 0x0040FF14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x0040FF18: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x0040FF1C: j           L_0040FF34
    // 0x0040FF20: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
        goto L_0040FF34;
    // 0x0040FF20: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
L_0040FF24:
    // 0x0040FF24: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x0040FF28: beq         $v0, $zero, L_0040FEFC
    if (ctx->r2 == 0) {
        // 0x0040FF2C: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_0040FEFC;
    }
    // 0x0040FF2C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_0040FF30:
    // 0x0040FF30: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_0040FF34:
    // 0x0040FF34: beq         $v0, $s7, L_0040FF5C
    if (ctx->r2 == ctx->r23) {
        // 0x0040FF38: andi        $a3, $s2, 0xFF
        ctx->r7 = ctx->r18 & 0XFF;
            goto L_0040FF5C;
    }
    // 0x0040FF38: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // 0x0040FF3C: lbu         $v0, 0x64($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X64);
    // 0x0040FF40: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x0040FF44: bnel        $v0, $zero, L_0040FEC0
    if (ctx->r2 != 0) {
        // 0x0040FF48: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040FEC0;
    }
    goto skip_0;
    // 0x0040FF48: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    skip_0:
L_0040FF4C:
    // 0x0040FF4C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x0040FF50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040FF54: bne         $v1, $v0, L_0040FFC8
    if (ctx->r3 != ctx->r2) {
        // 0x0040FF58: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0040FFC8;
    }
    // 0x0040FF58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_0040FF5C:
    // 0x0040FF5C: sll         $v0, $s1, 8
    ctx->r2 = S32(ctx->r17 << 8);
    // 0x0040FF60: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x0040FF64: lhu         $v0, 0x114($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X114);
    // 0x0040FF68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0040FF6C: sh          $v0, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r2;
    // 0x0040FF70: lw          $v0, 0x110($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X110);
    // 0x0040FF74: addiu       $a1, $sp, 0x110
    ctx->r5 = ADD32(ctx->r29, 0X110);
    // 0x0040FF78: sw          $v0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r2;
    // 0x0040FF7C: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
L_0040FF80:
    // 0x0040FF80: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x0040FF84: lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X10);
    // 0x0040FF88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x0040FF8C: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x0040FF90: slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x0040FF94: bne         $v0, $zero, L_0040FF80
    if (ctx->r2 != 0) {
        // 0x0040FF98: addu        $v1, $s6, $a0
        ctx->r3 = ADD32(ctx->r22, ctx->r4);
            goto L_0040FF80;
    }
    // 0x0040FF98: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
    // 0x0040FF9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0040FFA0: addiu       $a1, $sp, 0x110
    ctx->r5 = ADD32(ctx->r29, 0X110);
    // 0x0040FFA4: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
L_0040FFA8:
    // 0x0040FFA8: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x0040FFAC: lbu         $v0, 0xC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XC);
    // 0x0040FFB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x0040FFB4: sb          $v0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r2;
    // 0x0040FFB8: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x0040FFBC: bne         $v0, $zero, L_0040FFA8
    if (ctx->r2 != 0) {
        // 0x0040FFC0: addu        $v1, $s6, $a0
        ctx->r3 = ADD32(ctx->r22, ctx->r4);
            goto L_0040FFA8;
    }
    // 0x0040FFC0: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
    // 0x0040FFC4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040FFC8:
    // 0x0040FFC8: lw          $ra, 0x150($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X150);
    // 0x0040FFCC: lw          $s7, 0x14C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X14C);
    // 0x0040FFD0: lw          $s6, 0x148($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X148);
    // 0x0040FFD4: lw          $s5, 0x144($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X144);
    // 0x0040FFD8: lw          $s4, 0x140($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X140);
    // 0x0040FFDC: lw          $s3, 0x13C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X13C);
    // 0x0040FFE0: lw          $s2, 0x138($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X138);
    // 0x0040FFE4: lw          $s1, 0x134($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X134);
    // 0x0040FFE8: lw          $s0, 0x130($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X130);
    // 0x0040FFEC: jr          $ra
    // 0x0040FFF0: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x0040FFF0: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void func_0040FDB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040FDB8: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x0040FDBC: sw          $s3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r19;
    // 0x0040FDC0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x0040FDC4: sw          $s1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r17;
    // 0x0040FDC8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x0040FDCC: sw          $ra, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r31;
    // 0x0040FDD0: sw          $s7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r23;
    // 0x0040FDD4: sw          $s6, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r22;
    // 0x0040FDD8: sw          $s5, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r21;
    // 0x0040FDDC: sw          $s4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r20;
    // 0x0040FDE0: sw          $s2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r18;
    // 0x0040FDE4: sw          $s0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r16;
    // 0x0040FDE8: lw          $v0, 0x50($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X50);
    // 0x0040FDEC: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0040FDF0: beq         $v0, $zero, L_0040FE7C
    if (ctx->r2 == 0) {
        // 0x0040FDF4: addu        $s6, $a2, $zero
        ctx->r22 = ADD32(ctx->r6, 0);
            goto L_0040FE7C;
    }
    // 0x0040FDF4: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x0040FDF8: bltz        $s1, L_0040FFC8
    if (SIGNED(ctx->r17) < 0) {
        // 0x0040FDFC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040FFC8;
    }
    // 0x0040FDFC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040FE00: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x0040FE04: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0040FE08: beq         $v0, $zero, L_0040FFC8
    if (ctx->r2 == 0) {
        // 0x0040FE0C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040FFC8;
    }
    // 0x0040FE0C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040FE10: jal         0x00411F74
    // 0x0040FE14: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x0040FE14: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x0040FE18: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x0040FE1C: beq         $v0, $v1, L_0040FFC8
    if (ctx->r2 == ctx->r3) {
        // 0x0040FE20: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0040FFC8;
    }
    // 0x0040FE20: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x0040FE24: lbu         $v0, 0x65($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X65);
    // 0x0040FE28: beq         $v0, $zero, L_0040FE44
    if (ctx->r2 == 0) {
        // 0x0040FE2C: addiu       $a3, $sp, 0x110
        ctx->r7 = ADD32(ctx->r29, 0X110);
            goto L_0040FE44;
    }
    // 0x0040FE2C: addiu       $a3, $sp, 0x110
    ctx->r7 = ADD32(ctx->r29, 0X110);
    // 0x0040FE30: sb          $zero, 0x65($s3)
    MEM_B(0X65, ctx->r19) = 0;
    // 0x0040FE34: jal         0x0041203C
    // 0x0040FE38: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_0041203C(rdram, ctx);
        goto after_1;
    // 0x0040FE38: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_1:
    // 0x0040FE3C: bne         $v0, $zero, L_0040FFC8
    if (ctx->r2 != 0) {
        // 0x0040FE40: addiu       $a3, $sp, 0x110
        ctx->r7 = ADD32(ctx->r29, 0X110);
            goto L_0040FFC8;
    }
    // 0x0040FE40: addiu       $a3, $sp, 0x110
    ctx->r7 = ADD32(ctx->r29, 0X110);
L_0040FE44:
    // 0x0040FE44: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x0040FE48: lhu         $a2, 0x5E($s3)
    ctx->r6 = MEM_HU(ctx->r19, 0X5E);
    // 0x0040FE4C: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x0040FE50: addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // 0x0040FE54: jal         0x0029B8D0
    // 0x0040FE58: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_2;
    // 0x0040FE58: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_2:
    // 0x0040FE5C: bne         $v0, $zero, L_0040FFC8
    if (ctx->r2 != 0) {
        // 0x0040FE60: nop
    
            goto L_0040FFC8;
    }
    // 0x0040FE60: nop

    // 0x0040FE64: lhu         $v0, 0x114($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X114);
    // 0x0040FE68: beq         $v0, $zero, L_0040FFC8
    if (ctx->r2 == 0) {
        // 0x0040FE6C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0040FFC8;
    }
    // 0x0040FE6C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x0040FE70: lw          $v0, 0x110($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X110);
    // 0x0040FE74: bne         $v0, $zero, L_0040FE84
    if (ctx->r2 != 0) {
        // 0x0040FE78: nop
    
            goto L_0040FE84;
    }
    // 0x0040FE78: nop

L_0040FE7C:
    // 0x0040FE7C: j           L_0040FFC8
    // 0x0040FE80: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_0040FFC8;
    // 0x0040FE80: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_0040FE84:
    // 0x0040FE84: lhu         $v0, 0x116($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X116);
    // 0x0040FE88: lw          $v1, 0x60($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X60);
    // 0x0040FE8C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x0040FE90: bne         $v0, $zero, L_0040FFC8
    if (ctx->r2 != 0) {
        // 0x0040FE94: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0040FFC8;
    }
    // 0x0040FE94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x0040FE98: lbu         $s5, 0x117($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0X117);
    // 0x0040FE9C: lbu         $s2, 0x116($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X116);
    // 0x0040FEA0: lbu         $v0, 0x64($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X64);
    // 0x0040FEA4: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // 0x0040FEA8: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x0040FEAC: beq         $v0, $zero, L_0040FF4C
    if (ctx->r2 == 0) {
        // 0x0040FEB0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_0040FF4C;
    }
    // 0x0040FEB0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x0040FEB4: addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
    // 0x0040FEB8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x0040FEBC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0040FEC0:
    // 0x0040FEC0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x0040FEC4: jal         0x00411C1C
    // 0x0040FEC8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00411C1C(rdram, ctx);
        goto after_3;
    // 0x0040FEC8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // 0x0040FECC: bne         $v0, $zero, L_0040FFC8
    if (ctx->r2 != 0) {
        // 0x0040FED0: nop
    
            goto L_0040FFC8;
    }
    // 0x0040FED0: nop

    // 0x0040FED4: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x0040FED8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x0040FEDC: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x0040FEE0: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x0040FEE4: lw          $v1, 0x60($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X60);
    // 0x0040FEE8: slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x0040FEEC: bne         $v0, $zero, L_0040FF30
    if (ctx->r2 != 0) {
        // 0x0040FEF0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_0040FF30;
    }
    // 0x0040FEF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x0040FEF4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x0040FEF8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_0040FEFC:
    // 0x0040FEFC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x0040FF00: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x0040FF04: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
    // 0x0040FF08: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x0040FF0C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x0040FF10: beq         $v1, $s2, L_0040FF24
    if (ctx->r3 == ctx->r18) {
        // 0x0040FF14: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_0040FF24;
    }
    // 0x0040FF14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x0040FF18: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x0040FF1C: j           L_0040FF34
    // 0x0040FF20: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
        goto L_0040FF34;
    // 0x0040FF20: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
L_0040FF24:
    // 0x0040FF24: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x0040FF28: beq         $v0, $zero, L_0040FEFC
    if (ctx->r2 == 0) {
        // 0x0040FF2C: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_0040FEFC;
    }
    // 0x0040FF2C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_0040FF30:
    // 0x0040FF30: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_0040FF34:
    // 0x0040FF34: beq         $v0, $s7, L_0040FF5C
    if (ctx->r2 == ctx->r23) {
        // 0x0040FF38: andi        $a3, $s2, 0xFF
        ctx->r7 = ctx->r18 & 0XFF;
            goto L_0040FF5C;
    }
    // 0x0040FF38: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // 0x0040FF3C: lbu         $v0, 0x64($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X64);
    // 0x0040FF40: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x0040FF44: bnel        $v0, $zero, L_0040FEC0
    if (ctx->r2 != 0) {
        // 0x0040FF48: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0040FEC0;
    }
    goto skip_0;
    // 0x0040FF48: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    skip_0:
L_0040FF4C:
    // 0x0040FF4C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x0040FF50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0040FF54: bne         $v1, $v0, L_0040FFC8
    if (ctx->r3 != ctx->r2) {
        // 0x0040FF58: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_0040FFC8;
    }
    // 0x0040FF58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_0040FF5C:
    // 0x0040FF5C: sll         $v0, $s1, 8
    ctx->r2 = S32(ctx->r17 << 8);
    // 0x0040FF60: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x0040FF64: lhu         $v0, 0x114($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X114);
    // 0x0040FF68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0040FF6C: sh          $v0, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r2;
    // 0x0040FF70: lw          $v0, 0x110($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X110);
    // 0x0040FF74: addiu       $a1, $sp, 0x110
    ctx->r5 = ADD32(ctx->r29, 0X110);
    // 0x0040FF78: sw          $v0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r2;
    // 0x0040FF7C: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
L_0040FF80:
    // 0x0040FF80: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x0040FF84: lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X10);
    // 0x0040FF88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x0040FF8C: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x0040FF90: slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x0040FF94: bne         $v0, $zero, L_0040FF80
    if (ctx->r2 != 0) {
        // 0x0040FF98: addu        $v1, $s6, $a0
        ctx->r3 = ADD32(ctx->r22, ctx->r4);
            goto L_0040FF80;
    }
    // 0x0040FF98: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
    // 0x0040FF9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0040FFA0: addiu       $a1, $sp, 0x110
    ctx->r5 = ADD32(ctx->r29, 0X110);
    // 0x0040FFA4: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
L_0040FFA8:
    // 0x0040FFA8: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x0040FFAC: lbu         $v0, 0xC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XC);
    // 0x0040FFB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x0040FFB4: sb          $v0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r2;
    // 0x0040FFB8: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x0040FFBC: bne         $v0, $zero, L_0040FFA8
    if (ctx->r2 != 0) {
        // 0x0040FFC0: addu        $v1, $s6, $a0
        ctx->r3 = ADD32(ctx->r22, ctx->r4);
            goto L_0040FFA8;
    }
    // 0x0040FFC0: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
    // 0x0040FFC4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0040FFC8:
    // 0x0040FFC8: lw          $ra, 0x150($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X150);
    // 0x0040FFCC: lw          $s7, 0x14C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X14C);
    // 0x0040FFD0: lw          $s6, 0x148($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X148);
    // 0x0040FFD4: lw          $s5, 0x144($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X144);
    // 0x0040FFD8: lw          $s4, 0x140($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X140);
    // 0x0040FFDC: lw          $s3, 0x13C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X13C);
    // 0x0040FFE0: lw          $s2, 0x138($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X138);
    // 0x0040FFE4: lw          $s1, 0x134($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X134);
    // 0x0040FFE8: lw          $s0, 0x130($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X130);
    // 0x0040FFEC: jr          $ra
    // 0x0040FFF0: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x0040FFF0: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void func_0040FFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040FFF4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x0040FFF8: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x0040FFFC: sw          $s3, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r19;
    // 0x00410000: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x00410004: sw          $s6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r22;
    // 0x00410008: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x0041000C: sw          $ra, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r31;
    // 0x00410010: sw          $s5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r21;
    // 0x00410014: sw          $s4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r20;
    // 0x00410018: sw          $s2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r18;
    // 0x0041001C: sw          $s1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r17;
    // 0x00410020: sw          $s0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r16;
    // 0x00410024: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x00410028: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0041002C: bne         $v0, $zero, L_0041003C
    if (ctx->r2 != 0) {
        // 0x00410030: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_0041003C;
    }
    // 0x00410030: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x00410034: j           L_004100E8
    // 0x00410038: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_004100E8;
    // 0x00410038: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_0041003C:
    // 0x0041003C: jal         0x00411F74
    // 0x00410040: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x00410040: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x00410044: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x00410048: beq         $v0, $v1, L_004100E8
    if (ctx->r2 == ctx->r3) {
        // 0x0041004C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_004100E8;
    }
    // 0x0041004C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x00410050: lbu         $v0, 0x64($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X64);
    // 0x00410054: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x00410058: beq         $v0, $zero, L_004100DC
    if (ctx->r2 == 0) {
        // 0x0041005C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_004100DC;
    }
    // 0x0041005C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00410060: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x00410064: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x00410068: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0041006C:
    // 0x0041006C: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x00410070: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x00410074: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00410078: jal         0x00411C1C
    // 0x0041007C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00411C1C(rdram, ctx);
        goto after_1;
    // 0x0041007C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_1:
    // 0x00410080: bne         $v0, $zero, L_004100E8
    if (ctx->r2 != 0) {
        // 0x00410084: nop
    
            goto L_004100E8;
    }
    // 0x00410084: nop

    // 0x00410088: bne         $s0, $zero, L_00410094
    if (ctx->r16 != 0) {
        // 0x0041008C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00410094;
    }
    // 0x0041008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00410090: lw          $v0, 0x60($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X60);
L_00410094:
    // 0x00410094: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00410098: slti        $v0, $a0, 0x80
    ctx->r2 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x0041009C: beq         $v0, $zero, L_004100C4
    if (ctx->r2 == 0) {
        // 0x004100A0: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_004100C4;
    }
    // 0x004100A0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x004100A4: addu        $v1, $v0, $s5
    ctx->r3 = ADD32(ctx->r2, ctx->r21);
L_004100A8:
    // 0x004100A8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x004100AC: beql        $v0, $s4, L_004100B4
    if (ctx->r2 == ctx->r20) {
        // 0x004100B0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_004100B4;
    }
    goto skip_0;
    // 0x004100B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
L_004100B4:
    // 0x004100B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x004100B8: slti        $v0, $a0, 0x80
    ctx->r2 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x004100BC: bne         $v0, $zero, L_004100A8
    if (ctx->r2 != 0) {
        // 0x004100C0: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_004100A8;
    }
    // 0x004100C0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_004100C4:
    // 0x004100C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x004100C8: lbu         $v1, 0x64($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X64);
    // 0x004100CC: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x004100D0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x004100D4: bnel        $v0, $zero, L_0041006C
    if (ctx->r2 != 0) {
        // 0x004100D8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0041006C;
    }
    goto skip_1;
    // 0x004100D8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    skip_1:
L_004100DC:
    // 0x004100DC: sll         $v0, $s2, 8
    ctx->r2 = S32(ctx->r18 << 8);
    // 0x004100E0: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x004100E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_004100E8:
    // 0x004100E8: lw          $ra, 0x12C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X12C);
    // 0x004100EC: lw          $s6, 0x128($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X128);
    // 0x004100F0: lw          $s5, 0x124($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X124);
    // 0x004100F4: lw          $s4, 0x120($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X120);
    // 0x004100F8: lw          $s3, 0x11C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X11C);
    // 0x004100FC: lw          $s2, 0x118($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X118);
    // 0x00410100: lw          $s1, 0x114($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X114);
    // 0x00410104: lw          $s0, 0x110($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X110);
    // 0x00410108: jr          $ra
    // 0x0041010C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x0041010C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_0040FFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0040FFF8: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x0040FFFC: sw          $s3, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r19;
    // 0x00410000: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x00410004: sw          $s6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r22;
    // 0x00410008: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x0041000C: sw          $ra, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r31;
    // 0x00410010: sw          $s5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r21;
    // 0x00410014: sw          $s4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r20;
    // 0x00410018: sw          $s2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r18;
    // 0x0041001C: sw          $s1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r17;
    // 0x00410020: sw          $s0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r16;
    // 0x00410024: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x00410028: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0041002C: bne         $v0, $zero, L_0041003C
    if (ctx->r2 != 0) {
        // 0x00410030: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_0041003C;
    }
    // 0x00410030: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x00410034: j           L_004100E8
    // 0x00410038: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_004100E8;
    // 0x00410038: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_0041003C:
    // 0x0041003C: jal         0x00411F74
    // 0x00410040: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x00410040: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x00410044: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x00410048: beq         $v0, $v1, L_004100E8
    if (ctx->r2 == ctx->r3) {
        // 0x0041004C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_004100E8;
    }
    // 0x0041004C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x00410050: lbu         $v0, 0x64($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X64);
    // 0x00410054: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x00410058: beq         $v0, $zero, L_004100DC
    if (ctx->r2 == 0) {
        // 0x0041005C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_004100DC;
    }
    // 0x0041005C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00410060: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x00410064: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x00410068: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0041006C:
    // 0x0041006C: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x00410070: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x00410074: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00410078: jal         0x00411C1C
    // 0x0041007C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00411C1C(rdram, ctx);
        goto after_1;
    // 0x0041007C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_1:
    // 0x00410080: bne         $v0, $zero, L_004100E8
    if (ctx->r2 != 0) {
        // 0x00410084: nop
    
            goto L_004100E8;
    }
    // 0x00410084: nop

    // 0x00410088: bne         $s0, $zero, L_00410094
    if (ctx->r16 != 0) {
        // 0x0041008C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00410094;
    }
    // 0x0041008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00410090: lw          $v0, 0x60($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X60);
L_00410094:
    // 0x00410094: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00410098: slti        $v0, $a0, 0x80
    ctx->r2 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x0041009C: beq         $v0, $zero, L_004100C4
    if (ctx->r2 == 0) {
        // 0x004100A0: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_004100C4;
    }
    // 0x004100A0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x004100A4: addu        $v1, $v0, $s5
    ctx->r3 = ADD32(ctx->r2, ctx->r21);
L_004100A8:
    // 0x004100A8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x004100AC: beql        $v0, $s4, L_004100B4
    if (ctx->r2 == ctx->r20) {
        // 0x004100B0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_004100B4;
    }
    goto skip_0;
    // 0x004100B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
L_004100B4:
    // 0x004100B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x004100B8: slti        $v0, $a0, 0x80
    ctx->r2 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x004100BC: bne         $v0, $zero, L_004100A8
    if (ctx->r2 != 0) {
        // 0x004100C0: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_004100A8;
    }
    // 0x004100C0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_004100C4:
    // 0x004100C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x004100C8: lbu         $v1, 0x64($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X64);
    // 0x004100CC: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x004100D0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x004100D4: bnel        $v0, $zero, L_0041006C
    if (ctx->r2 != 0) {
        // 0x004100D8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_0041006C;
    }
    goto skip_1;
    // 0x004100D8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    skip_1:
L_004100DC:
    // 0x004100DC: sll         $v0, $s2, 8
    ctx->r2 = S32(ctx->r18 << 8);
    // 0x004100E0: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x004100E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_004100E8:
    // 0x004100E8: lw          $ra, 0x12C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X12C);
    // 0x004100EC: lw          $s6, 0x128($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X128);
    // 0x004100F0: lw          $s5, 0x124($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X124);
    // 0x004100F4: lw          $s4, 0x120($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X120);
    // 0x004100F8: lw          $s3, 0x11C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X11C);
    // 0x004100FC: lw          $s2, 0x118($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X118);
    // 0x00410100: lw          $s1, 0x114($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X114);
    // 0x00410104: lw          $s0, 0x110($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X110);
    // 0x00410108: jr          $ra
    // 0x0041010C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x0041010C: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_00410110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00410110: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x00410114: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x00410118: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x0041011C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x00410120: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x00410124: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00410128: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x0041012C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x00410130: jal         0x004101E8
    // 0x00410134: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_004101E8(rdram, ctx);
        goto after_0;
    // 0x00410134: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x00410138: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x0041013C: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x00410140: addiu       $s1, $s1, 0x4138
    ctx->r17 = ADD32(ctx->r17, 0X4138);
    // 0x00410144: jal         0x0029C2A8
    // 0x00410148: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    __osSiRawStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x00410148: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x0041014C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00410150: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x00410154: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00410158: jal         0x0029D8E8
    // 0x0041015C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x0041015C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x00410160: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00410164: jal         0x0029C2A8
    // 0x00410168: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    __osSiRawStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x00410168: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x0041016C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00410170: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00410174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00410178: jal         0x0029D8E8
    // 0x0041017C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x0041017C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_4:
    // 0x00410180: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00410184: jal         0x00410274
    // 0x00410188: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_00410274(rdram, ctx);
        goto after_5;
    // 0x00410188: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x0041018C: lbu         $v1, 0x12($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X12);
    // 0x00410190: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x00410194: beq         $v0, $zero, L_004101A4
    if (ctx->r2 == 0) {
        // 0x00410198: andi        $v0, $v1, 0x2
        ctx->r2 = ctx->r3 & 0X2;
            goto L_004101A4;
    }
    // 0x00410198: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x0041019C: bne         $v0, $zero, L_004101CC
    if (ctx->r2 != 0) {
        // 0x004101A0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_004101CC;
    }
    // 0x004101A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_004101A4:
    // 0x004101A4: lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X12);
    // 0x004101A8: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x004101AC: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x004101B0: bne         $v0, $v1, L_004101CC
    if (ctx->r2 != ctx->r3) {
        // 0x004101B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_004101CC;
    }
    // 0x004101B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x004101B8: lbu         $v1, 0x12($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X12);
    // 0x004101BC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x004101C0: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x004101C4: beql        $v1, $zero, L_004101CC
    if (ctx->r3 == 0) {
        // 0x004101C8: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_004101CC;
    }
    goto skip_0;
    // 0x004101C8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    skip_0:
L_004101CC:
    // 0x004101CC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x004101D0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x004101D4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x004101D8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x004101DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x004101E0: jr          $ra
    // 0x004101E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x004101E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_004101E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004101E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x004101EC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x004101F0: addiu       $v0, $v0, 0x4138
    ctx->r2 = ADD32(ctx->r2, 0X4138);
    // 0x004101F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004101F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x004101FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00410200: sw          $v0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r2;
    // 0x00410204: sb          $v0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r2;
    // 0x00410208: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x0041020C: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x00410210: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x00410214: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x00410218: sb          $zero, -0x4570($at)
    MEM_B(-0X4570, ctx->r1) = 0;
    // 0x0041021C: sb          $zero, 0x2($sp)
    MEM_B(0X2, ctx->r29) = 0;
    // 0x00410220: sb          $v0, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r2;
    // 0x00410224: sb          $v0, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r2;
    // 0x00410228: blez        $a0, L_00410244
    if (SIGNED(ctx->r4) <= 0) {
        // 0x0041022C: sb          $v0, 0x5($sp)
        MEM_B(0X5, ctx->r29) = ctx->r2;
            goto L_00410244;
    }
    // 0x0041022C: sb          $v0, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r2;
L_00410230:
    // 0x00410230: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x00410234: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x00410238: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x0041023C: bne         $v0, $zero, L_00410230
    if (ctx->r2 != 0) {
        // 0x00410240: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_00410230;
    }
    // 0x00410240: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_00410244:
    // 0x00410244: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x00410248: lwl         $a2, 0x0($sp)
    ctx->r6 = do_lwl(rdram, ctx->r6, ctx->r29, 0X0);
    // 0x0041024C: lwr         $a2, 0x3($sp)
    ctx->r6 = do_lwr(rdram, ctx->r6, ctx->r29, 0X3);
    // 0x00410250: lb          $a3, 0x4($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X4);
    // 0x00410254: lb          $t0, 0x5($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X5);
    // 0x00410258: swl         $a2, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r6);
    // 0x0041025C: swr         $a2, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r6);
    // 0x00410260: sb          $a3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r7;
    // 0x00410264: sb          $t0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r8;
    // 0x00410268: sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // 0x0041026C: jr          $ra
    // 0x00410270: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x00410270: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_00410274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00410274: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x00410278: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x0041027C: addiu       $a2, $a2, 0x4138
    ctx->r6 = ADD32(ctx->r6, 0X4138);
    // 0x00410280: blez        $a0, L_00410298
    if (SIGNED(ctx->r4) <= 0) {
        // 0x00410284: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_00410298;
    }
    // 0x00410284: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_00410288:
    // 0x00410288: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x0041028C: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x00410290: bne         $v0, $zero, L_00410288
    if (ctx->r2 != 0) {
        // 0x00410294: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_00410288;
    }
    // 0x00410294: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_00410298:
    // 0x00410298: lwl         $a3, 0x0($a2)
    ctx->r7 = do_lwl(rdram, ctx->r7, ctx->r6, 0X0);
    // 0x0041029C: lwr         $a3, 0x3($a2)
    ctx->r7 = do_lwr(rdram, ctx->r7, ctx->r6, 0X3);
    // 0x004102A0: lb          $t0, 0x4($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X4);
    // 0x004102A4: lb          $t1, 0x5($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X5);
    // 0x004102A8: swl         $a3, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r7);
    // 0x004102AC: swr         $a3, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r7);
    // 0x004102B0: sb          $t0, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r8;
    // 0x004102B4: sb          $t1, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r9;
    // 0x004102B8: lbu         $v0, 0x1($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1);
    // 0x004102BC: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x004102C0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x004102C4: bne         $v0, $zero, L_004102E8
    if (ctx->r2 != 0) {
        // 0x004102C8: sb          $v0, 0x3($a1)
        MEM_B(0X3, ctx->r5) = ctx->r2;
            goto L_004102E8;
    }
    // 0x004102C8: sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
    // 0x004102CC: lbu         $v0, 0x4($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X4);
    // 0x004102D0: lbu         $v1, 0x3($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3);
    // 0x004102D4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x004102D8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x004102DC: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x004102E0: lbu         $v0, 0x5($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5);
    // 0x004102E4: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
L_004102E8:
    // 0x004102E8: jr          $ra
    // 0x004102EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x004102EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_004102F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004102F0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x004102F4: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x004102F8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x004102FC: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x00410300: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x00410304: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x00410308: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x0041030C: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // 0x00410310: jal         0x0029C214
    // 0x00410314: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    __osSiGetAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x00410314: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    after_0:
    // 0x00410318: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x0041031C: jal         0x00410110
    // 0x00410320: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_00410110(rdram, ctx);
        goto after_1;
    // 0x00410320: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_1:
    // 0x00410324: jal         0x0029C280
    // 0x00410328: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    __osSiRelAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x00410328: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
    // 0x0041032C: bne         $s0, $zero, L_004104A4
    if (ctx->r16 != 0) {
        // 0x00410330: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_004104A4;
    }
    // 0x00410330: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x00410334: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00410338: sw          $s1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r17;
    // 0x0041033C: sw          $s3, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r19;
    // 0x00410340: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x00410344: jal         0x0041203C
    // 0x00410348: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    func_0041203C(rdram, ctx);
        goto after_3;
    // 0x00410348: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    after_3:
    // 0x0041034C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00410350: bne         $s0, $zero, L_004104A4
    if (ctx->r16 != 0) {
        // 0x00410354: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_004104A4;
    }
    // 0x00410354: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00410358: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x0041035C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00410360: jal         0x0029B8D0
    // 0x00410364: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_0029B8D0(rdram, ctx);
        goto after_4;
    // 0x00410364: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x00410368: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x0041036C: bne         $s0, $zero, L_004104A4
    if (ctx->r16 != 0) {
        // 0x00410370: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_004104A4;
    }
    // 0x00410370: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x00410374: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x00410378: jal         0x00411F2C
    // 0x0041037C: addiu       $a2, $sp, 0x52
    ctx->r6 = ADD32(ctx->r29, 0X52);
    func_00411F2C(rdram, ctx);
        goto after_5;
    // 0x0041037C: addiu       $a2, $sp, 0x52
    ctx->r6 = ADD32(ctx->r29, 0X52);
    after_5:
    // 0x00410380: lhu         $v1, 0x2C($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2C);
    // 0x00410384: lhu         $v0, 0x50($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X50);
    // 0x00410388: bne         $v1, $v0, L_004103A0
    if (ctx->r3 != ctx->r2) {
        // 0x0041038C: addiu       $s1, $sp, 0x10
        ctx->r17 = ADD32(ctx->r29, 0X10);
            goto L_004103A0;
    }
    // 0x0041038C: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // 0x00410390: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x00410394: lhu         $v0, 0x52($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X52);
    // 0x00410398: beq         $v1, $v0, L_004103B8
    if (ctx->r3 == ctx->r2) {
        // 0x0041039C: nop
    
            goto L_004103B8;
    }
    // 0x0041039C: nop

L_004103A0:
    // 0x004103A0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x004103A4: jal         0x004118C0
    // 0x004103A8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_004118C0(rdram, ctx);
        goto after_6;
    // 0x004103A8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_6:
    // 0x004103AC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x004103B0: bne         $s0, $zero, L_004104A4
    if (ctx->r16 != 0) {
        // 0x004103B4: nop
    
            goto L_004104A4;
    }
    // 0x004103B4: nop

L_004103B8:
    // 0x004103B8: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x004103BC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x004103C0: bne         $v0, $zero, L_00410400
    if (ctx->r2 != 0) {
        // 0x004103C4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00410400;
    }
    // 0x004103C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004103C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x004103CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x004103D0: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x004103D4: jal         0x004115D8
    // 0x004103D8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_004115D8(rdram, ctx);
        goto after_7;
    // 0x004103D8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_7:
    // 0x004103DC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x004103E0: bne         $s0, $zero, L_004104A4
    if (ctx->r16 != 0) {
        // 0x004103E4: nop
    
            goto L_004104A4;
    }
    // 0x004103E4: nop

    // 0x004103E8: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x004103EC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x004103F0: bne         $v0, $zero, L_00410400
    if (ctx->r2 != 0) {
        // 0x004103F4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00410400;
    }
    // 0x004103F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004103F8: j           L_004104A4
    // 0x004103FC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_004104A4;
    // 0x004103FC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_00410400:
    // 0x00410400: addu        $v1, $s2, $a0
    ctx->r3 = ADD32(ctx->r18, ctx->r4);
L_00410404:
    // 0x00410404: addu        $v0, $s1, $a0
    ctx->r2 = ADD32(ctx->r17, ctx->r4);
    // 0x00410408: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x0041040C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00410410: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x00410414: slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x00410418: bne         $v0, $zero, L_00410404
    if (ctx->r2 != 0) {
        // 0x0041041C: addu        $v1, $s2, $a0
        ctx->r3 = ADD32(ctx->r18, ctx->r4);
            goto L_00410404;
    }
    // 0x0041041C: addu        $v1, $s2, $a0
    ctx->r3 = ADD32(ctx->r18, ctx->r4);
    // 0x00410420: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x00410424: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00410428: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x0041042C: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x00410430: addiu       $a3, $s2, 0x2C
    ctx->r7 = ADD32(ctx->r18, 0X2C);
    // 0x00410434: sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
    // 0x00410438: lbu         $v1, 0x1A($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1A);
    // 0x0041043C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x00410440: sw          $v0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r2;
    // 0x00410444: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x00410448: sw          $v0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->r2;
    // 0x0041044C: sb          $v1, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r3;
    // 0x00410450: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x00410454: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x00410458: lbu         $v0, 0x64($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X64);
    // 0x0041045C: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x00410460: sw          $v1, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->r3;
    // 0x00410464: lbu         $v1, 0x64($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X64);
    // 0x00410468: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x0041046C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x00410470: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x00410474: sw          $v0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r2;
    // 0x00410478: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x0041047C: jal         0x0029B8D0
    // 0x00410480: sw          $v0, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->r2;
    func_0029B8D0(rdram, ctx);
        goto after_8;
    // 0x00410480: sw          $v0, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->r2;
    after_8:
    // 0x00410484: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00410488: bne         $s0, $zero, L_004104A4
    if (ctx->r16 != 0) {
        // 0x0041048C: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_004104A4;
    }
    // 0x0041048C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x00410490: jal         0x004104C0
    // 0x00410494: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_004104C0(rdram, ctx);
        goto after_9;
    // 0x00410494: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_9:
    // 0x00410498: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x0041049C: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x004104A0: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
L_004104A4:
    // 0x004104A4: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x004104A8: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x004104AC: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x004104B0: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x004104B4: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x004104B8: jr          $ra
    // 0x004104BC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x004104BC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_004104C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004104C0: addiu       $sp, $sp, -0x488
    ctx->r29 = ADD32(ctx->r29, -0X488);
    // 0x004104C4: sw          $s2, 0x468($sp)
    MEM_W(0X468, ctx->r29) = ctx->r18;
    // 0x004104C8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x004104CC: sw          $s7, 0x47C($sp)
    MEM_W(0X47C, ctx->r29) = ctx->r23;
    // 0x004104D0: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x004104D4: sw          $ra, 0x484($sp)
    MEM_W(0X484, ctx->r29) = ctx->r31;
    // 0x004104D8: sw          $fp, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r30;
    // 0x004104DC: sw          $s6, 0x478($sp)
    MEM_W(0X478, ctx->r29) = ctx->r22;
    // 0x004104E0: sw          $s5, 0x474($sp)
    MEM_W(0X474, ctx->r29) = ctx->r21;
    // 0x004104E4: sw          $s4, 0x470($sp)
    MEM_W(0X470, ctx->r29) = ctx->r20;
    // 0x004104E8: sw          $s3, 0x46C($sp)
    MEM_W(0X46C, ctx->r29) = ctx->r19;
    // 0x004104EC: sw          $s1, 0x464($sp)
    MEM_W(0X464, ctx->r29) = ctx->r17;
    // 0x004104F0: jal         0x00411F74
    // 0x004104F4: sw          $s0, 0x460($sp)
    MEM_W(0X460, ctx->r29) = ctx->r16;
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x004104F4: sw          $s0, 0x460($sp)
    MEM_W(0X460, ctx->r29) = ctx->r16;
    after_0:
    // 0x004104F8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004104FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00410500: bne         $v1, $v0, L_00410514
    if (ctx->r3 != ctx->r2) {
        // 0x00410504: nop
    
            goto L_00410514;
    }
    // 0x00410504: nop

    // 0x00410508: jal         0x00411A30
    // 0x0041050C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_00411A30(rdram, ctx);
        goto after_1;
    // 0x0041050C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x00410510: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_00410514:
    // 0x00410514: beq         $v1, $zero, L_00410524
    if (ctx->r3 == 0) {
        // 0x00410518: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00410524;
    }
    // 0x00410518: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_0041051C:
    // 0x0041051C: j           L_004108CC
    // 0x00410520: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_004108CC;
    // 0x00410520: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_00410524:
    // 0x00410524: jal         0x004108FC
    // 0x00410528: addiu       $a1, $sp, 0x258
    ctx->r5 = ADD32(ctx->r29, 0X258);
    func_004108FC(rdram, ctx);
        goto after_2;
    // 0x00410528: addiu       $a1, $sp, 0x258
    ctx->r5 = ADD32(ctx->r29, 0X258);
    after_2:
    // 0x0041052C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00410530: bne         $v1, $zero, L_004108CC
    if (ctx->r3 != 0) {
        // 0x00410534: nop
    
            goto L_004108CC;
    }
    // 0x00410534: nop

    // 0x00410538: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x0041053C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00410540: beq         $v0, $zero, L_004106D8
    if (ctx->r2 == 0) {
        // 0x00410544: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_004106D8;
    }
    // 0x00410544: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00410548: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x0041054C: addiu       $s5, $sp, 0x118
    ctx->r21 = ADD32(ctx->r29, 0X118);
    // 0x00410550: addiu       $a3, $sp, 0x218
    ctx->r7 = ADD32(ctx->r29, 0X218);
L_00410554:
    // 0x00410554: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00410558: lhu         $a2, 0x5E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5E);
    // 0x0041055C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00410560: addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // 0x00410564: jal         0x0029B8D0
    // 0x00410568: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_3;
    // 0x00410568: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_3:
    // 0x0041056C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00410570: bne         $v1, $zero, L_004108CC
    if (ctx->r3 != 0) {
        // 0x00410574: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_004108CC;
    }
    // 0x00410574: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x00410578: lhu         $v0, 0x21C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X21C);
    // 0x0041057C: beq         $v0, $zero, L_00410654
    if (ctx->r2 == 0) {
        // 0x00410580: nop
    
            goto L_00410654;
    }
    // 0x00410580: nop

    // 0x00410584: lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X218);
    // 0x00410588: beq         $v0, $zero, L_00410660
    if (ctx->r2 == 0) {
        // 0x0041058C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_00410660;
    }
    // 0x0041058C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00410590: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x00410594: lhu         $s0, 0x21E($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X21E);
    // 0x00410598: j           L_0041060C
    // 0x0041059C: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
        goto L_0041060C;
    // 0x0041059C: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_004105A0:
    // 0x004105A0: bltz        $v0, L_00410638
    if (SIGNED(ctx->r2) < 0) {
        // 0x004105A4: srl         $v1, $a0, 8
        ctx->r3 = S32(U32(ctx->r4) >> 8);
            goto L_00410638;
    }
    // 0x004105A4: srl         $v1, $a0, 8
    ctx->r3 = S32(U32(ctx->r4) >> 8);
    // 0x004105A8: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x004105AC: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x004105B0: beq         $v0, $a3, L_004105DC
    if (ctx->r2 == ctx->r7) {
        // 0x004105B4: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_004105DC;
    }
    // 0x004105B4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x004105B8: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // 0x004105BC: addiu       $a1, $sp, 0x118
    ctx->r5 = ADD32(ctx->r29, 0X118);
    // 0x004105C0: jal         0x00411C1C
    // 0x004105C4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00411C1C(rdram, ctx);
        goto after_4;
    // 0x004105C4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x004105C8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004105CC: beq         $v1, $zero, L_004105E0
    if (ctx->r3 == 0) {
        // 0x004105D0: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_004105E0;
    }
    // 0x004105D0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x004105D4: bne         $v1, $s6, L_004108CC
    if (ctx->r3 != ctx->r22) {
        // 0x004105D8: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_004108CC;
    }
    // 0x004105D8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_004105DC:
    // 0x004105DC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_004105E0:
    // 0x004105E0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x004105E4: addiu       $a2, $sp, 0x258
    ctx->r6 = ADD32(ctx->r29, 0X258);
    // 0x004105E8: jal         0x00410A48
    // 0x004105EC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    func_00410A48(rdram, ctx);
        goto after_5;
    // 0x004105EC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    after_5:
    // 0x004105F0: subu        $a1, $v0, $s4
    ctx->r5 = SUB32(ctx->r2, ctx->r20);
    // 0x004105F4: bne         $a1, $zero, L_00410660
    if (ctx->r5 != 0) {
        // 0x004105F8: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_00410660;
    }
    // 0x004105F8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x004105FC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x00410600: sllv        $v0, $v0, $s4
    ctx->r2 = S32(ctx->r2 << (ctx->r20 & 31));
    // 0x00410604: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x00410608: lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X0);
L_0041060C:
    // 0x0041060C: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x00410610: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x00410614: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00410618: bne         $v0, $zero, L_00410638
    if (ctx->r2 != 0) {
        // 0x0041061C: srl         $v0, $a0, 8
        ctx->r2 = S32(U32(ctx->r4) >> 8);
            goto L_00410638;
    }
    // 0x0041061C: srl         $v0, $a0, 8
    ctx->r2 = S32(U32(ctx->r4) >> 8);
    // 0x00410620: lbu         $v1, 0x64($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X64);
    // 0x00410624: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x00410628: beq         $v0, $zero, L_00410638
    if (ctx->r2 == 0) {
        // 0x0041062C: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_00410638;
    }
    // 0x0041062C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x00410630: bne         $v0, $zero, L_004105A0
    if (ctx->r2 != 0) {
        // 0x00410634: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_004105A0;
    }
    // 0x00410634: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_00410638:
    // 0x00410638: bnel        $a1, $zero, L_00410664
    if (ctx->r5 != 0) {
        // 0x0041063C: sh          $zero, 0x21C($sp)
        MEM_H(0X21C, ctx->r29) = 0;
            goto L_00410664;
    }
    goto skip_0;
    // 0x0041063C: sh          $zero, 0x21C($sp)
    MEM_H(0X21C, ctx->r29) = 0;
    skip_0:
    // 0x00410640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00410644: beq         $s0, $v0, L_004106C4
    if (ctx->r16 == ctx->r2) {
        // 0x00410648: nop
    
            goto L_004106C4;
    }
    // 0x00410648: nop

    // 0x0041064C: j           L_00410664
    // 0x00410650: sh          $zero, 0x21C($sp)
    MEM_H(0X21C, ctx->r29) = 0;
        goto L_00410664;
    // 0x00410650: sh          $zero, 0x21C($sp)
    MEM_H(0X21C, ctx->r29) = 0;
L_00410654:
    // 0x00410654: lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X218);
    // 0x00410658: beq         $v0, $zero, L_004106C4
    if (ctx->r2 == 0) {
        // 0x0041065C: nop
    
            goto L_004106C4;
    }
    // 0x0041065C: nop

L_00410660:
    // 0x00410660: sh          $zero, 0x21C($sp)
    MEM_H(0X21C, ctx->r29) = 0;
L_00410664:
    // 0x00410664: sw          $zero, 0x218($sp)
    MEM_W(0X218, ctx->r29) = 0;
    // 0x00410668: sh          $zero, 0x21E($sp)
    MEM_H(0X21E, ctx->r29) = 0;
    // 0x0041066C: sb          $zero, 0x220($sp)
    MEM_B(0X220, ctx->r29) = 0;
    // 0x00410670: sh          $zero, 0x222($sp)
    MEM_H(0X222, ctx->r29) = 0;
    // 0x00410674: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x00410678: beq         $v0, $zero, L_00410698
    if (ctx->r2 == 0) {
        // 0x0041067C: nop
    
            goto L_00410698;
    }
    // 0x0041067C: nop

    // 0x00410680: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    // 0x00410684: jal         0x0041203C
    // 0x00410688: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_6;
    // 0x00410688: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_6:
    // 0x0041068C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00410690: bne         $v1, $zero, L_004108CC
    if (ctx->r3 != 0) {
        // 0x00410694: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_004108CC;
    }
    // 0x00410694: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_00410698:
    // 0x00410698: lhu         $a2, 0x5E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5E);
    // 0x0041069C: addiu       $a3, $sp, 0x218
    ctx->r7 = ADD32(ctx->r29, 0X218);
    // 0x004106A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x004106A4: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004106A8: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004106AC: addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // 0x004106B0: jal         0x0029BC88
    // 0x004106B4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_7;
    // 0x004106B4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_7:
    // 0x004106B8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004106BC: bne         $v1, $zero, L_0041051C
    if (ctx->r3 != 0) {
        // 0x004106C0: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_0041051C;
    }
    // 0x004106C0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_004106C4:
    // 0x004106C4: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x004106C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x004106CC: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x004106D0: bne         $v0, $zero, L_00410554
    if (ctx->r2 != 0) {
        // 0x004106D4: addiu       $a3, $sp, 0x218
        ctx->r7 = ADD32(ctx->r29, 0X218);
            goto L_00410554;
    }
    // 0x004106D4: addiu       $a3, $sp, 0x218
    ctx->r7 = ADD32(ctx->r29, 0X218);
L_004106D8:
    // 0x004106D8: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x004106DC: blez        $v0, L_00410754
    if (SIGNED(ctx->r2) <= 0) {
        // 0x004106E0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_00410754;
    }
    // 0x004106E0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x004106E4: addiu       $s0, $sp, 0x238
    ctx->r16 = ADD32(ctx->r29, 0X238);
L_004106E8:
    // 0x004106E8: addiu       $a3, $sp, 0x218
    ctx->r7 = ADD32(ctx->r29, 0X218);
    // 0x004106EC: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004106F0: lhu         $a2, 0x5E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5E);
    // 0x004106F4: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004106F8: addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // 0x004106FC: jal         0x0029B8D0
    // 0x00410700: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_8;
    // 0x00410700: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_8:
    // 0x00410704: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00410708: bne         $v1, $zero, L_004108CC
    if (ctx->r3 != 0) {
        // 0x0041070C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_004108CC;
    }
    // 0x0041070C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x00410710: lhu         $v0, 0x21C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X21C);
    // 0x00410714: beql        $v0, $zero, L_00410740
    if (ctx->r2 == 0) {
        // 0x00410718: sh          $zero, 0x0($s0)
        MEM_H(0X0, ctx->r16) = 0;
            goto L_00410740;
    }
    goto skip_1;
    // 0x00410718: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    skip_1:
    // 0x0041071C: lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X218);
    // 0x00410720: beql        $v0, $zero, L_00410740
    if (ctx->r2 == 0) {
        // 0x00410724: sh          $zero, 0x0($s0)
        MEM_H(0X0, ctx->r16) = 0;
            goto L_00410740;
    }
    goto skip_2;
    // 0x00410724: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    skip_2:
    // 0x00410728: lhu         $v1, 0x21E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X21E);
    // 0x0041072C: lhu         $v0, 0x62($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X62);
    // 0x00410730: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x00410734: bnel        $v0, $zero, L_00410740
    if (ctx->r2 != 0) {
        // 0x00410738: sh          $zero, 0x0($s0)
        MEM_H(0X0, ctx->r16) = 0;
            goto L_00410740;
    }
    goto skip_3;
    // 0x00410738: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    skip_3:
    // 0x0041073C: sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
L_00410740:
    // 0x00410740: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x00410744: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x00410748: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0041074C: bne         $v0, $zero, L_004106E8
    if (ctx->r2 != 0) {
        // 0x00410750: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_004106E8;
    }
    // 0x00410750: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_00410754:
    // 0x00410754: lbu         $v0, 0x64($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X64);
    // 0x00410758: beq         $v0, $zero, L_004108A8
    if (ctx->r2 == 0) {
        // 0x0041075C: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_004108A8;
    }
    // 0x0041075C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x00410760: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x00410764: addiu       $s4, $sp, 0x18
    ctx->r20 = ADD32(ctx->r29, 0X18);
    // 0x00410768: addiu       $s5, $sp, 0x118
    ctx->r21 = ADD32(ctx->r29, 0X118);
    // 0x0041076C: addiu       $s6, $sp, 0x238
    ctx->r22 = ADD32(ctx->r29, 0X238);
    // 0x00410770: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_00410774:
    // 0x00410774: addiu       $a1, $sp, 0x118
    ctx->r5 = ADD32(ctx->r29, 0X118);
    // 0x00410778: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0041077C: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    // 0x00410780: jal         0x00411C1C
    // 0x00410784: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00411C1C(rdram, ctx);
        goto after_9;
    // 0x00410784: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_9:
    // 0x00410788: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041078C: beq         $v1, $zero, L_0041079C
    if (ctx->r3 == 0) {
        // 0x00410790: nop
    
            goto L_0041079C;
    }
    // 0x00410790: nop

    // 0x00410794: bne         $v1, $fp, L_004108CC
    if (ctx->r3 != ctx->r30) {
        // 0x00410798: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_004108CC;
    }
    // 0x00410798: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_0041079C:
    // 0x0041079C: bne         $s0, $zero, L_004107A8
    if (ctx->r16 != 0) {
        // 0x004107A0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_004107A8;
    }
    // 0x004107A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x004107A4: lw          $a1, 0x60($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X60);
L_004107A8:
    // 0x004107A8: blez        $a1, L_004107D4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x004107AC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_004107D4;
    }
    // 0x004107AC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x004107B0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x004107B4: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
L_004107B8:
    // 0x004107B8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x004107BC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x004107C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x004107C4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x004107C8: slt         $v0, $s1, $a1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x004107CC: bne         $v0, $zero, L_004107B8
    if (ctx->r2 != 0) {
        // 0x004107D0: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_004107B8;
    }
    // 0x004107D0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_004107D4:
    // 0x004107D4: slti        $v0, $s1, 0x80
    ctx->r2 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x004107D8: beq         $v0, $zero, L_004107F8
    if (ctx->r2 == 0) {
        // 0x004107DC: sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17 << 1);
            goto L_004107F8;
    }
    // 0x004107DC: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x004107E0: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
L_004107E4:
    // 0x004107E4: sh          $fp, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r30;
    // 0x004107E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x004107EC: slti        $v0, $s1, 0x80
    ctx->r2 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x004107F0: bne         $v0, $zero, L_004107E4
    if (ctx->r2 != 0) {
        // 0x004107F4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_004107E4;
    }
    // 0x004107F4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_004107F8:
    // 0x004107F8: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x004107FC: blez        $v0, L_00410874
    if (SIGNED(ctx->r2) <= 0) {
        // 0x00410800: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_00410874;
    }
    // 0x00410800: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00410804: andi        $t0, $s3, 0xFF
    ctx->r8 = ctx->r19 & 0XFF;
    // 0x00410808: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x0041080C: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
L_00410810:
    // 0x00410810: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x00410814: bne         $v0, $t0, L_0041085C
    if (ctx->r2 != ctx->r8) {
        // 0x00410818: addu        $a1, $s6, $zero
        ctx->r5 = ADD32(ctx->r22, 0);
            goto L_0041085C;
    }
    // 0x00410818: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
L_0041081C:
    // 0x0041081C: addu        $a0, $a1, $a2
    ctx->r4 = ADD32(ctx->r5, ctx->r6);
    // 0x00410820: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x00410824: lhu         $v0, 0x62($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X62);
    // 0x00410828: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x0041082C: bnel        $v1, $zero, L_00410860
    if (ctx->r3 != 0) {
        // 0x00410830: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_00410860;
    }
    goto skip_4;
    // 0x00410830: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_4:
    // 0x00410834: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x00410838: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x0041083C: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x00410840: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x00410844: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x00410848: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x0041084C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x00410850: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x00410854: beq         $v0, $t0, L_0041081C
    if (ctx->r2 == ctx->r8) {
        // 0x00410858: nop
    
            goto L_0041081C;
    }
    // 0x00410858: nop

L_0041085C:
    // 0x0041085C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_00410860:
    // 0x00410860: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x00410864: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x00410868: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0041086C: bne         $v0, $zero, L_00410810
    if (ctx->r2 != 0) {
        // 0x00410870: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_00410810;
    }
    // 0x00410870: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
L_00410874:
    // 0x00410874: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00410878: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x0041087C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00410880: jal         0x00411C1C
    // 0x00410884: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    func_00411C1C(rdram, ctx);
        goto after_10;
    // 0x00410884: andi        $a3, $s3, 0xFF
    ctx->r7 = ctx->r19 & 0XFF;
    after_10:
    // 0x00410888: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041088C: bne         $v1, $zero, L_0041051C
    if (ctx->r3 != 0) {
        // 0x00410890: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_0041051C;
    }
    // 0x00410890: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x00410894: lbu         $v1, 0x64($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X64);
    // 0x00410898: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x0041089C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x004108A0: bne         $v0, $zero, L_00410774
    if (ctx->r2 != 0) {
        // 0x004108A4: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00410774;
    }
    // 0x004108A4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_004108A8:
    // 0x004108A8: beq         $s7, $zero, L_004108BC
    if (ctx->r23 == 0) {
        // 0x004108AC: addiu       $v1, $zero, -0x3
        ctx->r3 = ADD32(0, -0X3);
            goto L_004108BC;
    }
    // 0x004108AC: addiu       $v1, $zero, -0x3
    ctx->r3 = ADD32(0, -0X3);
    // 0x004108B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x004108B4: j           L_004108C4
    // 0x004108B8: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
        goto L_004108C4;
    // 0x004108B8: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_004108BC:
    // 0x004108BC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x004108C0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_004108C4:
    // 0x004108C4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x004108C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_004108CC:
    // 0x004108CC: lw          $ra, 0x484($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X484);
    // 0x004108D0: lw          $fp, 0x480($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X480);
    // 0x004108D4: lw          $s7, 0x47C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X47C);
    // 0x004108D8: lw          $s6, 0x478($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X478);
    // 0x004108DC: lw          $s5, 0x474($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X474);
    // 0x004108E0: lw          $s4, 0x470($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X470);
    // 0x004108E4: lw          $s3, 0x46C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X46C);
    // 0x004108E8: lw          $s2, 0x468($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X468);
    // 0x004108EC: lw          $s1, 0x464($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X464);
    // 0x004108F0: lw          $s0, 0x460($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X460);
    // 0x004108F4: jr          $ra
    // 0x004108F8: addiu       $sp, $sp, 0x488
    ctx->r29 = ADD32(ctx->r29, 0X488);
    return;
    // 0x004108F8: addiu       $sp, $sp, 0x488
    ctx->r29 = ADD32(ctx->r29, 0X488);
;}
RECOMP_FUNC void func_004108FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004108FC: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x00410900: sw          $s2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r18;
    // 0x00410904: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00410908: sw          $s3, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r19;
    // 0x0041090C: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x00410910: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x00410914: addu        $v0, $s3, $a1
    ctx->r2 = ADD32(ctx->r19, ctx->r5);
    // 0x00410918: sw          $ra, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r31;
    // 0x0041091C: sw          $s6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r22;
    // 0x00410920: sw          $s5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r21;
    // 0x00410924: sw          $s4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r20;
    // 0x00410928: sw          $s1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r17;
    // 0x0041092C: sw          $s0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r16;
L_00410930:
    // 0x00410930: sb          $zero, 0x101($v0)
    MEM_B(0X101, ctx->r2) = 0;
    // 0x00410934: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x00410938: bgez        $a1, L_00410930
    if (SIGNED(ctx->r5) >= 0) {
        // 0x0041093C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_00410930;
    }
    // 0x0041093C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x00410940: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x00410944: sb          $v0, 0x100($s3)
    MEM_B(0X100, ctx->r19) = ctx->r2;
    // 0x00410948: lbu         $v0, 0x64($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X64);
    // 0x0041094C: beq         $v0, $zero, L_00410A1C
    if (ctx->r2 == 0) {
        // 0x00410950: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_00410A1C;
    }
    // 0x00410950: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00410954: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x00410958: addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
    // 0x0041095C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x00410960: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
L_00410964:
    // 0x00410964: bne         $a3, $zero, L_00410970
    if (ctx->r7 != 0) {
        // 0x00410968: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_00410970;
    }
    // 0x00410968: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x0041096C: lw          $s0, 0x60($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X60);
L_00410970:
    // 0x00410970: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00410974: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x00410978: jal         0x00411C1C
    // 0x0041097C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00411C1C(rdram, ctx);
        goto after_0;
    // 0x0041097C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x00410980: beq         $v0, $zero, L_00410990
    if (ctx->r2 == 0) {
        // 0x00410984: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_00410990;
    }
    // 0x00410984: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00410988: bne         $v0, $s6, L_00410A20
    if (ctx->r2 != ctx->r22) {
        // 0x0041098C: nop
    
            goto L_00410A20;
    }
    // 0x0041098C: nop

L_00410990:
    // 0x00410990: slti        $v0, $a1, 0x80
    ctx->r2 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x00410994: beql        $v0, $zero, L_00410A08
    if (ctx->r2 == 0) {
        // 0x00410998: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_00410A08;
    }
    goto skip_0;
    // 0x00410998: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x0041099C: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    // 0x004109A0: andi        $v0, $a3, 0x7
    ctx->r2 = ctx->r7 & 0X7;
    // 0x004109A4: sllv        $t0, $s5, $v0
    ctx->r8 = S32(ctx->r21 << (ctx->r2 & 31));
    // 0x004109A8: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x004109AC: addu        $a2, $v0, $s4
    ctx->r6 = ADD32(ctx->r2, ctx->r20);
L_004109B0:
    // 0x004109B0: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x004109B4: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x004109B8: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x004109BC: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x004109C0: bne         $v0, $zero, L_004109F8
    if (ctx->r2 != 0) {
        // 0x004109C4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_004109F8;
    }
    // 0x004109C4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x004109C8: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x004109CC: beq         $v1, $a3, L_004109F8
    if (ctx->r3 == ctx->r7) {
        // 0x004109D0: nop
    
            goto L_004109F8;
    }
    // 0x004109D0: nop

    // 0x004109D4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x004109D8: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x004109DC: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x004109E0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x004109E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x004109E8: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x004109EC: lbu         $v1, 0x101($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X101);
    // 0x004109F0: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x004109F4: sb          $v1, 0x101($v0)
    MEM_B(0X101, ctx->r2) = ctx->r3;
L_004109F8:
    // 0x004109F8: slti        $v0, $a1, 0x80
    ctx->r2 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x004109FC: bne         $v0, $zero, L_004109B0
    if (ctx->r2 != 0) {
        // 0x00410A00: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_004109B0;
    }
    // 0x00410A00: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x00410A04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_00410A08:
    // 0x00410A08: lbu         $v1, 0x64($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X64);
    // 0x00410A0C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x00410A10: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x00410A14: bnel        $v0, $zero, L_00410964
    if (ctx->r2 != 0) {
        // 0x00410A18: andi        $a3, $s1, 0xFF
        ctx->r7 = ctx->r17 & 0XFF;
            goto L_00410964;
    }
    goto skip_1;
    // 0x00410A18: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    skip_1:
L_00410A1C:
    // 0x00410A1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00410A20:
    // 0x00410A20: lw          $ra, 0x12C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X12C);
    // 0x00410A24: lw          $s6, 0x128($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X128);
    // 0x00410A28: lw          $s5, 0x124($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X124);
    // 0x00410A2C: lw          $s4, 0x120($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X120);
    // 0x00410A30: lw          $s3, 0x11C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X11C);
    // 0x00410A34: lw          $s2, 0x118($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X118);
    // 0x00410A38: lw          $s1, 0x114($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X114);
    // 0x00410A3C: lw          $s0, 0x110($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X110);
    // 0x00410A40: jr          $ra
    // 0x00410A44: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x00410A44: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_00410A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00410A48: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x00410A4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x00410A50: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x00410A54: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x00410A58: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x00410A5C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x00410A60: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00410A64: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00410A68: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00410A6C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x00410A70: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x00410A74: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x00410A78: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x00410A7C: srl         $a2, $a1, 8
    ctx->r6 = S32(U32(ctx->r5) >> 8);
    // 0x00410A80: andi        $v0, $a2, 0x7
    ctx->r2 = ctx->r6 & 0X7;
    // 0x00410A84: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x00410A88: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x00410A8C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x00410A90: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x00410A94: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x00410A98: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00410A9C: lbu         $a0, 0x64($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X64);
    // 0x00410AA0: beq         $a0, $zero, L_00410B78
    if (ctx->r4 == 0) {
        // 0x00410AA4: addu        $s7, $v1, $v0
        ctx->r23 = ADD32(ctx->r3, ctx->r2);
            goto L_00410B78;
    }
    // 0x00410AA4: addu        $s7, $v1, $v0
    ctx->r23 = ADD32(ctx->r3, ctx->r2);
    // 0x00410AA8: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x00410AAC: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x00410AB0: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
L_00410AB4:
    // 0x00410AB4: bne         $a3, $zero, L_00410AC0
    if (ctx->r7 != 0) {
        // 0x00410AB8: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_00410AC0;
    }
    // 0x00410AB8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x00410ABC: lw          $s2, 0x60($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X60);
L_00410AC0:
    // 0x00410AC0: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x00410AC4: beq         $v1, $s6, L_00410AE4
    if (ctx->r3 == ctx->r22) {
        // 0x00410AC8: addu        $v0, $s3, $s7
        ctx->r2 = ADD32(ctx->r19, ctx->r23);
            goto L_00410AE4;
    }
    // 0x00410AC8: addu        $v0, $s3, $s7
    ctx->r2 = ADD32(ctx->r19, ctx->r23);
    // 0x00410ACC: lbu         $v0, 0x101($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X101);
    // 0x00410AD0: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x00410AD4: srav        $v0, $v0, $v1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r3 & 31));
    // 0x00410AD8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x00410ADC: beql        $v0, $zero, L_00410B64
    if (ctx->r2 == 0) {
        // 0x00410AE0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_00410B64;
    }
    goto skip_0;
    // 0x00410AE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
L_00410AE4:
    // 0x00410AE4: lbu         $v0, 0x100($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X100);
    // 0x00410AE8: beq         $a3, $v0, L_00410B14
    if (ctx->r7 == ctx->r2) {
        // 0x00410AEC: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_00410B14;
    }
    // 0x00410AEC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x00410AF0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x00410AF4: jal         0x00411C1C
    // 0x00410AF8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00411C1C(rdram, ctx);
        goto after_0;
    // 0x00410AF8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x00410AFC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00410B00: beq         $v1, $zero, L_00410B10
    if (ctx->r3 == 0) {
        // 0x00410B04: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_00410B10;
    }
    // 0x00410B04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00410B08: bne         $v1, $v0, L_00410B7C
    if (ctx->r3 != ctx->r2) {
        // 0x00410B0C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_00410B7C;
    }
    // 0x00410B0C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_00410B10:
    // 0x00410B10: sb          $s1, 0x100($s3)
    MEM_B(0X100, ctx->r19) = ctx->r17;
L_00410B14:
    // 0x00410B14: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x00410B18: beq         $v0, $zero, L_00410B5C
    if (ctx->r2 == 0) {
        // 0x00410B1C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00410B5C;
    }
    // 0x00410B1C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00410B20: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x00410B24: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
L_00410B28:
    // 0x00410B28: slti        $v0, $a0, 0x80
    ctx->r2 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x00410B2C: beq         $v0, $zero, L_00410B54
    if (ctx->r2 == 0) {
        // 0x00410B30: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_00410B54;
    }
    // 0x00410B30: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x00410B34: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x00410B38: beql        $v0, $s5, L_00410B40
    if (ctx->r2 == ctx->r21) {
        // 0x00410B3C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_00410B40;
    }
    goto skip_1;
    // 0x00410B3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
L_00410B40:
    // 0x00410B40: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x00410B44: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x00410B48: bne         $v0, $zero, L_00410B28
    if (ctx->r2 != 0) {
        // 0x00410B4C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00410B28;
    }
    // 0x00410B4C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00410B50: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
L_00410B54:
    // 0x00410B54: bne         $v0, $zero, L_00410B64
    if (ctx->r2 != 0) {
        // 0x00410B58: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_00410B64;
    }
    // 0x00410B58: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_00410B5C:
    // 0x00410B5C: j           L_00410B7C
    // 0x00410B60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_00410B7C;
    // 0x00410B60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_00410B64:
    // 0x00410B64: lbu         $v1, 0x64($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X64);
    // 0x00410B68: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x00410B6C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x00410B70: bne         $v0, $zero, L_00410AB4
    if (ctx->r2 != 0) {
        // 0x00410B74: andi        $a3, $s1, 0xFF
        ctx->r7 = ctx->r17 & 0XFF;
            goto L_00410AB4;
    }
    // 0x00410B74: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
L_00410B78:
    // 0x00410B78: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_00410B7C:
    // 0x00410B7C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x00410B80: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x00410B84: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x00410B88: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x00410B8C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x00410B90: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x00410B94: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00410B98: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00410B9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00410BA0: jr          $ra
    // 0x00410BA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x00410BA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_00410BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00410BA8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x00410BAC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x00410BB0: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x00410BB4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x00410BB8: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x00410BBC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x00410BC0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x00410BC4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x00410BC8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x00410BCC: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x00410BD0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x00410BD4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x00410BD8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x00410BDC: jal         0x0029C214
    // 0x00410BE0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    __osSiGetAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x00410BE0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    after_0:
    // 0x00410BE4: lui         $s3, 0x8010
    ctx->r19 = S32(0X8010 << 16);
    // 0x00410BE8: addiu       $s3, $s3, 0x4138
    ctx->r19 = ADD32(ctx->r19, 0X4138);
    // 0x00410BEC: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x00410BF0: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
L_00410BF4:
    // 0x00410BF4: jal         0x00410D24
    // 0x00410BF8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_00410D24(rdram, ctx);
        goto after_1;
    // 0x00410BF8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x00410BFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x00410C00: jal         0x0029C2A8
    // 0x00410C04: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    __osSiRawStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x00410C04: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_2:
    // 0x00410C08: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x00410C0C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00410C10: jal         0x0029D8E8
    // 0x00410C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x00410C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x00410C18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00410C1C: jal         0x0029C2A8
    // 0x00410C20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    __osSiRawStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x00410C20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_4:
    // 0x00410C24: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x00410C28: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00410C2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00410C30: jal         0x0029D8E8
    // 0x00410C34: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x00410C34: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    after_5:
    // 0x00410C38: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x00410C3C: jal         0x00410DC0
    // 0x00410C40: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_00410DC0(rdram, ctx);
        goto after_6;
    // 0x00410C40: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x00410C44: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x00410C48: lbu         $v0, -0x45B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X45B4);
    // 0x00410C4C: beq         $v0, $zero, L_00410C88
    if (ctx->r2 == 0) {
        // 0x00410C50: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00410C88;
    }
    // 0x00410C50: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00410C54: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x00410C58: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
L_00410C5C:
    // 0x00410C5C: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x00410C60: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x00410C64: bnel        $v0, $zero, L_00410C74
    if (ctx->r2 != 0) {
        // 0x00410C68: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00410C74;
    }
    goto skip_0;
    // 0x00410C68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x00410C6C: j           L_00410C80
    // 0x00410C70: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_00410C80;
    // 0x00410C70: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_00410C74:
    // 0x00410C74: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x00410C78: bne         $v0, $zero, L_00410C5C
    if (ctx->r2 != 0) {
        // 0x00410C7C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_00410C5C;
    }
    // 0x00410C7C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_00410C80:
    // 0x00410C80: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x00410C84: lbu         $v0, -0x45B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X45B4);
L_00410C88:
    // 0x00410C88: beql        $a0, $v0, L_00410C90
    if (ctx->r4 == ctx->r2) {
        // 0x00410C8C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_00410C90;
    }
    goto skip_1;
    // 0x00410C8C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    skip_1:
L_00410C90:
    // 0x00410C90: bgtz        $s0, L_00410BF4
    if (SIGNED(ctx->r16) > 0) {
        // 0x00410C94: nop
    
            goto L_00410BF4;
    }
    // 0x00410C94: nop

    // 0x00410C98: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x00410C9C: lbu         $v0, -0x45B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X45B4);
    // 0x00410CA0: beq         $v0, $zero, L_00410CE8
    if (ctx->r2 == 0) {
        // 0x00410CA4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00410CE8;
    }
    // 0x00410CA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00410CA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00410CAC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x00410CB0: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
L_00410CB4:
    // 0x00410CB4: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x00410CB8: bnel        $v0, $zero, L_00410CDC
    if (ctx->r2 != 0) {
        // 0x00410CBC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00410CDC;
    }
    goto skip_2;
    // 0x00410CBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x00410CC0: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x00410CC4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x00410CC8: beql        $v0, $zero, L_00410CDC
    if (ctx->r2 == 0) {
        // 0x00410CCC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00410CDC;
    }
    goto skip_3;
    // 0x00410CCC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_3:
    // 0x00410CD0: sllv        $v0, $a2, $a0
    ctx->r2 = S32(ctx->r6 << (ctx->r4 & 31));
    // 0x00410CD4: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x00410CD8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_00410CDC:
    // 0x00410CDC: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x00410CE0: bne         $v0, $zero, L_00410CB4
    if (ctx->r2 != 0) {
        // 0x00410CE4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_00410CB4;
    }
    // 0x00410CE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_00410CE8:
    // 0x00410CE8: jal         0x0029C280
    // 0x00410CEC: nop

    __osSiRelAccess_recomp(rdram, ctx);
        goto after_7;
    // 0x00410CEC: nop

    after_7:
    // 0x00410CF0: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // 0x00410CF4: sb          $s2, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r18;
    // 0x00410CF8: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x00410CFC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x00410D00: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x00410D04: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x00410D08: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x00410D0C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x00410D10: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x00410D14: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x00410D18: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x00410D1C: jr          $ra
    // 0x00410D20: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x00410D20: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_00410D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00410D24: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x00410D28: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x00410D2C: addiu       $a3, $a3, 0x4138
    ctx->r7 = ADD32(ctx->r7, 0X4138);
    // 0x00410D30: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00410D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00410D38: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x00410D3C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x00410D40: addiu       $t0, $t0, -0x45B4
    ctx->r8 = ADD32(ctx->r8, -0X45B4);
    // 0x00410D44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x00410D48: sb          $a0, -0x4570($at)
    MEM_B(-0X4570, ctx->r1) = ctx->r4;
    // 0x00410D4C: sw          $v0, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r2;
    // 0x00410D50: sb          $v1, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r3;
    // 0x00410D54: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x00410D58: lbu         $a1, 0x0($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X0);
    // 0x00410D5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00410D60: sb          $v0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r2;
    // 0x00410D64: sb          $a0, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r4;
    // 0x00410D68: sb          $v1, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r3;
    // 0x00410D6C: sb          $v1, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r3;
    // 0x00410D70: sb          $v1, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r3;
    // 0x00410D74: beq         $a1, $zero, L_00410DB0
    if (ctx->r5 == 0) {
        // 0x00410D78: sb          $v1, 0x7($sp)
        MEM_B(0X7, ctx->r29) = ctx->r3;
            goto L_00410DB0;
    }
    // 0x00410D78: sb          $v1, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r3;
L_00410D7C:
    // 0x00410D7C: lwl         $t1, 0x0($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r29, 0X0);
    // 0x00410D80: lwr         $t1, 0x3($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r29, 0X3);
    // 0x00410D84: lwl         $t2, 0x4($sp)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r29, 0X4);
    // 0x00410D88: lwr         $t2, 0x7($sp)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r29, 0X7);
    // 0x00410D8C: swl         $t1, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r9);
    // 0x00410D90: swr         $t1, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r9);
    // 0x00410D94: swl         $t2, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r10);
    // 0x00410D98: swr         $t2, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r10);
    // 0x00410D9C: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x00410DA0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x00410DA4: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00410DA8: bne         $v0, $zero, L_00410D7C
    if (ctx->r2 != 0) {
        // 0x00410DAC: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_00410D7C;
    }
    // 0x00410DAC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_00410DB0:
    // 0x00410DB0: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x00410DB4: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x00410DB8: jr          $ra
    // 0x00410DBC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x00410DBC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_00410DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00410DC0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x00410DC4: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x00410DC8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x00410DCC: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x00410DD0: addiu       $a3, $a3, 0x4138
    ctx->r7 = ADD32(ctx->r7, 0X4138);
    // 0x00410DD4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x00410DD8: addiu       $v1, $v1, -0x45B4
    ctx->r3 = ADD32(ctx->r3, -0X45B4);
    // 0x00410DDC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x00410DE0: beq         $v0, $zero, L_00410E68
    if (ctx->r2 == 0) {
        // 0x00410DE4: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_00410E68;
    }
    // 0x00410DE4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00410DE8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x00410DEC: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // 0x00410DF0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_00410DF4:
    // 0x00410DF4: lwl         $t4, 0x0($a3)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r7, 0X0);
    // 0x00410DF8: lwr         $t4, 0x3($a3)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r7, 0X3);
    // 0x00410DFC: lwl         $t5, 0x4($a3)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r7, 0X4);
    // 0x00410E00: lwr         $t5, 0x7($a3)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r7, 0X7);
    // 0x00410E04: swl         $t4, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r12);
    // 0x00410E08: swr         $t4, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r12);
    // 0x00410E0C: swl         $t5, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r13);
    // 0x00410E10: swr         $t5, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r13);
    // 0x00410E14: lbu         $v0, 0x2($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2);
    // 0x00410E18: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x00410E1C: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x00410E20: bne         $v0, $zero, L_00410E4C
    if (ctx->r2 != 0) {
        // 0x00410E24: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_00410E4C;
    }
    // 0x00410E24: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x00410E28: lbu         $v0, 0x5($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5);
    // 0x00410E2C: lbu         $v1, 0x4($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4);
    // 0x00410E30: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x00410E34: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x00410E38: sllv        $v0, $t3, $a2
    ctx->r2 = S32(ctx->r11 << (ctx->r6 & 31));
    // 0x00410E3C: sh          $v1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r3;
    // 0x00410E40: lbu         $v1, 0x6($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X6);
    // 0x00410E44: or          $t1, $t1, $v0
    ctx->r9 = ctx->r9 | ctx->r2;
    // 0x00410E48: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
L_00410E4C:
    // 0x00410E4C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x00410E50: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x00410E54: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x00410E58: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x00410E5C: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00410E60: bne         $v0, $zero, L_00410DF4
    if (ctx->r2 != 0) {
        // 0x00410E64: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_00410DF4;
    }
    // 0x00410E64: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_00410E68:
    // 0x00410E68: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    // 0x00410E6C: jr          $ra
    // 0x00410E70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x00410E70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_00410E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_00410E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00410E78: addiu       $sp, $sp, -0x168
    ctx->r29 = ADD32(ctx->r29, -0X168);
    // 0x00410E7C: sw          $s2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r18;
    // 0x00410E80: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00410E84: sw          $fp, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r30;
    // 0x00410E88: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x00410E8C: sw          $s0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r16;
    // 0x00410E90: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x00410E94: sw          $s5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r21;
    // 0x00410E98: sw          $ra, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r31;
    // 0x00410E9C: sw          $s7, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r23;
    // 0x00410EA0: sw          $s6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r22;
    // 0x00410EA4: sw          $s4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r20;
    // 0x00410EA8: sw          $s3, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r19;
    // 0x00410EAC: sw          $s1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r17;
    // 0x00410EB0: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x00410EB4: lw          $s6, 0x178($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X178);
    // 0x00410EB8: slt         $v0, $fp, $v0
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00410EBC: beq         $v0, $zero, L_00410F78
    if (ctx->r2 == 0) {
        // 0x00410EC0: addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
            goto L_00410F78;
    }
    // 0x00410EC0: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x00410EC4: bltz        $fp, L_0041127C
    if (SIGNED(ctx->r30) < 0) {
        // 0x00410EC8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0041127C;
    }
    // 0x00410EC8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x00410ECC: blez        $s6, L_00410F78
    if (SIGNED(ctx->r22) <= 0) {
        // 0x00410ED0: andi        $v0, $s6, 0x1F
        ctx->r2 = ctx->r22 & 0X1F;
            goto L_00410F78;
    }
    // 0x00410ED0: andi        $v0, $s6, 0x1F
    ctx->r2 = ctx->r22 & 0X1F;
    // 0x00410ED4: bne         $v0, $zero, L_0041127C
    if (ctx->r2 != 0) {
        // 0x00410ED8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0041127C;
    }
    // 0x00410ED8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x00410EDC: bltz        $s0, L_00410F78
    if (SIGNED(ctx->r16) < 0) {
        // 0x00410EE0: andi        $v0, $s0, 0x1F
        ctx->r2 = ctx->r16 & 0X1F;
            goto L_00410F78;
    }
    // 0x00410EE0: andi        $v0, $s0, 0x1F
    ctx->r2 = ctx->r16 & 0X1F;
    // 0x00410EE4: bne         $v0, $zero, L_0041127C
    if (ctx->r2 != 0) {
        // 0x00410EE8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0041127C;
    }
    // 0x00410EE8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x00410EEC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x00410EF0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x00410EF4: beq         $v0, $zero, L_0041127C
    if (ctx->r2 == 0) {
        // 0x00410EF8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0041127C;
    }
    // 0x00410EF8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x00410EFC: jal         0x00411F74
    // 0x00410F00: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x00410F00: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x00410F04: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x00410F08: bne         $v0, $v1, L_00410F18
    if (ctx->r2 != ctx->r3) {
        // 0x00410F0C: nop
    
            goto L_00410F18;
    }
    // 0x00410F0C: nop

L_00410F10:
    // 0x00410F10: j           L_0041127C
    // 0x00410F14: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_0041127C;
    // 0x00410F14: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_00410F18:
    // 0x00410F18: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x00410F1C: beq         $v0, $zero, L_00410F3C
    if (ctx->r2 == 0) {
        // 0x00410F20: addiu       $a3, $sp, 0x18
        ctx->r7 = ADD32(ctx->r29, 0X18);
            goto L_00410F3C;
    }
    // 0x00410F20: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x00410F24: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    // 0x00410F28: jal         0x0041203C
    // 0x00410F2C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_1;
    // 0x00410F2C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x00410F30: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00410F34: bne         $v1, $zero, L_0041127C
    if (ctx->r3 != 0) {
        // 0x00410F38: addiu       $a3, $sp, 0x18
        ctx->r7 = ADD32(ctx->r29, 0X18);
            goto L_0041127C;
    }
    // 0x00410F38: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
L_00410F3C:
    // 0x00410F3C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00410F40: lhu         $a2, 0x5E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5E);
    // 0x00410F44: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00410F48: addu        $a2, $a2, $fp
    ctx->r6 = ADD32(ctx->r6, ctx->r30);
    // 0x00410F4C: jal         0x0029B8D0
    // 0x00410F50: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_2;
    // 0x00410F50: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_2:
    // 0x00410F54: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00410F58: bne         $v1, $zero, L_0041127C
    if (ctx->r3 != 0) {
        // 0x00410F5C: nop
    
            goto L_0041127C;
    }
    // 0x00410F5C: nop

    // 0x00410F60: lhu         $v0, 0x1C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1C);
    // 0x00410F64: beq         $v0, $zero, L_0041127C
    if (ctx->r2 == 0) {
        // 0x00410F68: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0041127C;
    }
    // 0x00410F68: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x00410F6C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x00410F70: bne         $v0, $zero, L_00410F80
    if (ctx->r2 != 0) {
        // 0x00410F74: nop
    
            goto L_00410F80;
    }
    // 0x00410F74: nop

L_00410F78:
    // 0x00410F78: j           L_0041127C
    // 0x00410F7C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_0041127C;
    // 0x00410F7C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_00410F80:
    // 0x00410F80: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x00410F84: lw          $v1, 0x60($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X60);
    // 0x00410F88: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x00410F8C: bne         $v0, $zero, L_00410FBC
    if (ctx->r2 != 0) {
        // 0x00410F90: nop
    
            goto L_00410FBC;
    }
    // 0x00410F90: nop

    // 0x00410F94: lbu         $v0, 0x1E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1E);
    // 0x00410F98: lbu         $v1, 0x64($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X64);
    // 0x00410F9C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x00410FA0: beq         $v0, $zero, L_00410FBC
    if (ctx->r2 == 0) {
        // 0x00410FA4: nop
    
            goto L_00410FBC;
    }
    // 0x00410FA4: nop

    // 0x00410FA8: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x00410FAC: beq         $v0, $zero, L_00410FBC
    if (ctx->r2 == 0) {
        // 0x00410FB0: sll         $v0, $v0, 24
        ctx->r2 = S32(ctx->r2 << 24);
            goto L_00410FBC;
    }
    // 0x00410FB0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x00410FB4: bgez        $v0, L_00410FD4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x00410FB8: andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
            goto L_00410FD4;
    }
    // 0x00410FB8: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
L_00410FBC:
    // 0x00410FBC: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x00410FC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x00410FC4: beq         $a0, $v1, L_0041127C
    if (ctx->r4 == ctx->r3) {
        // 0x00410FC8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_0041127C;
    }
    // 0x00410FC8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x00410FCC: j           L_0041127C
    // 0x00410FD0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_0041127C;
    // 0x00410FD0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_00410FD4:
    // 0x00410FD4: bne         $v0, $zero, L_00410FF4
    if (ctx->r2 != 0) {
        // 0x00410FD8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_00410FF4;
    }
    // 0x00410FD8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x00410FDC: lbu         $v0, 0x20($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X20);
    // 0x00410FE0: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x00410FE4: bne         $v0, $zero, L_00410FF4
    if (ctx->r2 != 0) {
        // 0x00410FE8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_00410FF4;
    }
    // 0x00410FE8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x00410FEC: j           L_0041127C
    // 0x00410FF0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_0041127C;
    // 0x00410FF0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_00410FF4:
    // 0x00410FF4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x00410FF8: bgez        $a3, L_00411004
    if (SIGNED(ctx->r7) >= 0) {
        // 0x00410FFC: sb          $v0, 0x138($sp)
        MEM_B(0X138, ctx->r29) = ctx->r2;
            goto L_00411004;
    }
    // 0x00410FFC: sb          $v0, 0x138($sp)
    MEM_B(0X138, ctx->r29) = ctx->r2;
    // 0x00411000: addiu       $a3, $a3, 0x1F
    ctx->r7 = ADD32(ctx->r7, 0X1F);
L_00411004:
    // 0x00411004: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x00411008: sra         $s1, $a3, 5
    ctx->r17 = S32(SIGNED(ctx->r7) >> 5);
    // 0x0041100C: sh          $v0, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r2;
    // 0x00411010: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x00411014: bne         $v0, $zero, L_004110CC
    if (ctx->r2 != 0) {
        // 0x00411018: addu        $v0, $s6, $zero
        ctx->r2 = ADD32(ctx->r22, 0);
            goto L_004110CC;
    }
    // 0x00411018: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // 0x0041101C: addiu       $s3, $sp, 0x138
    ctx->r19 = ADD32(ctx->r29, 0X138);
    // 0x00411020: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
    // 0x00411024: addiu       $s0, $sp, 0x13A
    ctx->r16 = ADD32(ctx->r29, 0X13A);
    // 0x00411028: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_0041102C:
    // 0x0041102C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x00411030: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x00411034: beq         $v1, $v0, L_00411058
    if (ctx->r3 == ctx->r2) {
        // 0x00411038: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_00411058;
    }
    // 0x00411038: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x0041103C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x00411040: sb          $v1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r3;
    // 0x00411044: andi        $a3, $v1, 0xFF
    ctx->r7 = ctx->r3 & 0XFF;
    // 0x00411048: jal         0x00411C1C
    // 0x0041104C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00411C1C(rdram, ctx);
        goto after_3;
    // 0x0041104C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // 0x00411050: bne         $v0, $zero, L_004110B8
    if (ctx->r2 != 0) {
        // 0x00411054: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_004110B8;
    }
    // 0x00411054: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_00411058:
    // 0x00411058: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x0041105C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x00411060: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x00411064: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x00411068: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x0041106C: lw          $v1, 0x60($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X60);
    // 0x00411070: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x00411074: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x00411078: bne         $v0, $zero, L_004110A8
    if (ctx->r2 != 0) {
        // 0x0041107C: nop
    
            goto L_004110A8;
    }
    // 0x0041107C: nop

    // 0x00411080: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x00411084: lbu         $v1, 0x64($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X64);
    // 0x00411088: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x0041108C: beq         $v0, $zero, L_004110A8
    if (ctx->r2 == 0) {
        // 0x00411090: nop
    
            goto L_004110A8;
    }
    // 0x00411090: nop

    // 0x00411094: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x00411098: beq         $v0, $zero, L_004110A8
    if (ctx->r2 == 0) {
        // 0x0041109C: sll         $v0, $v0, 24
        ctx->r2 = S32(ctx->r2 << 24);
            goto L_004110A8;
    }
    // 0x0041109C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x004110A0: bgez        $v0, L_004110B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x004110A4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_004110B8;
    }
    // 0x004110A4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_004110A8:
    // 0x004110A8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x004110AC: bne         $v0, $s7, L_004110B8
    if (ctx->r2 != ctx->r23) {
        // 0x004110B0: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_004110B8;
    }
    // 0x004110B0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x004110B4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_004110B8:
    // 0x004110B8: bne         $v1, $zero, L_00410F10
    if (ctx->r3 != 0) {
        // 0x004110BC: addiu       $s1, $s1, -0x8
        ctx->r17 = ADD32(ctx->r17, -0X8);
            goto L_00410F10;
    }
    // 0x004110BC: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
    // 0x004110C0: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x004110C4: beq         $v0, $zero, L_0041102C
    if (ctx->r2 == 0) {
        // 0x004110C8: addu        $v0, $s6, $zero
        ctx->r2 = ADD32(ctx->r22, 0);
            goto L_0041102C;
    }
    // 0x004110C8: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
L_004110CC:
    // 0x004110CC: bltzl       $v0, L_004110D4
    if (SIGNED(ctx->r2) < 0) {
        // 0x004110D0: addiu       $v0, $v0, 0x1F
        ctx->r2 = ADD32(ctx->r2, 0X1F);
            goto L_004110D4;
    }
    goto skip_0;
    // 0x004110D0: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    skip_0:
L_004110D4:
    // 0x004110D4: sra         $s4, $v0, 5
    ctx->r20 = S32(SIGNED(ctx->r2) >> 5);
    // 0x004110D8: lw          $s3, 0x17C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X17C);
    // 0x004110DC: blez        $s4, L_00411218
    if (SIGNED(ctx->r20) <= 0) {
        // 0x004110E0: andi        $v1, $s5, 0xFF
        ctx->r3 = ctx->r21 & 0XFF;
            goto L_00411218;
    }
    // 0x004110E0: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x004110E4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_004110E8:
    // 0x004110E8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x004110EC: bne         $s1, $v0, L_00411190
    if (ctx->r17 != ctx->r2) {
        // 0x004110F0: nop
    
            goto L_00411190;
    }
    // 0x004110F0: nop

    // 0x004110F4: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x004110F8: lbu         $v1, 0x13A($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X13A);
    // 0x004110FC: lbu         $v0, 0x138($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X138);
    // 0x00411100: beq         $v1, $v0, L_00411128
    if (ctx->r3 == ctx->r2) {
        // 0x00411104: addiu       $s0, $sp, 0x13A
        ctx->r16 = ADD32(ctx->r29, 0X13A);
            goto L_00411128;
    }
    // 0x00411104: addiu       $s0, $sp, 0x13A
    ctx->r16 = ADD32(ctx->r29, 0X13A);
    // 0x00411108: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x0041110C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00411110: sb          $v1, 0x138($sp)
    MEM_B(0X138, ctx->r29) = ctx->r3;
    // 0x00411114: andi        $a3, $v1, 0xFF
    ctx->r7 = ctx->r3 & 0XFF;
    // 0x00411118: jal         0x00411C1C
    // 0x0041111C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00411C1C(rdram, ctx);
        goto after_4;
    // 0x0041111C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x00411120: bne         $v0, $zero, L_00411188
    if (ctx->r2 != 0) {
        // 0x00411124: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_00411188;
    }
    // 0x00411124: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_00411128:
    // 0x00411128: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x0041112C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x00411130: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x00411134: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x00411138: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x0041113C: lw          $v1, 0x60($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X60);
    // 0x00411140: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x00411144: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x00411148: bne         $v0, $zero, L_00411178
    if (ctx->r2 != 0) {
        // 0x0041114C: nop
    
            goto L_00411178;
    }
    // 0x0041114C: nop

    // 0x00411150: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x00411154: lbu         $v1, 0x64($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X64);
    // 0x00411158: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x0041115C: beq         $v0, $zero, L_00411178
    if (ctx->r2 == 0) {
        // 0x00411160: nop
    
            goto L_00411178;
    }
    // 0x00411160: nop

    // 0x00411164: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x00411168: beq         $v0, $zero, L_00411178
    if (ctx->r2 == 0) {
        // 0x0041116C: sll         $v0, $v0, 24
        ctx->r2 = S32(ctx->r2 << 24);
            goto L_00411178;
    }
    // 0x0041116C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x00411170: bgez        $v0, L_00411188
    if (SIGNED(ctx->r2) >= 0) {
        // 0x00411174: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_00411188;
    }
    // 0x00411174: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_00411178:
    // 0x00411178: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x0041117C: bne         $v0, $s6, L_00411188
    if (ctx->r2 != ctx->r22) {
        // 0x00411180: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_00411188;
    }
    // 0x00411180: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x00411184: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_00411188:
    // 0x00411188: bne         $v1, $zero, L_00410F10
    if (ctx->r3 != 0) {
        // 0x0041118C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_00410F10;
    }
    // 0x0041118C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_00411190:
    // 0x00411190: lbu         $v1, 0x13A($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X13A);
    // 0x00411194: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x00411198: beq         $v0, $v1, L_004111B8
    if (ctx->r2 == ctx->r3) {
        // 0x0041119C: nop
    
            goto L_004111B8;
    }
    // 0x0041119C: nop

    // 0x004111A0: sb          $v1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r3;
    // 0x004111A4: jal         0x0041203C
    // 0x004111A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_5;
    // 0x004111A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_5:
    // 0x004111AC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004111B0: bne         $v1, $zero, L_0041127C
    if (ctx->r3 != 0) {
        // 0x004111B4: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0041127C;
    }
    // 0x004111B4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_004111B8:
    // 0x004111B8: lbu         $v0, 0x13B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X13B);
    // 0x004111BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x004111C0: addu        $a2, $v0, $s1
    ctx->r6 = ADD32(ctx->r2, ctx->r17);
    // 0x004111C4: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x004111C8: bne         $v0, $zero, L_004111E8
    if (ctx->r2 != 0) {
        // 0x004111CC: andi        $a2, $a2, 0xFFFF
        ctx->r6 = ctx->r6 & 0XFFFF;
            goto L_004111E8;
    }
    // 0x004111CC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x004111D0: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004111D4: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004111D8: jal         0x0029B8D0
    // 0x004111DC: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_0029B8D0(rdram, ctx);
        goto after_6;
    // 0x004111DC: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_6:
    // 0x004111E0: j           L_00411200
    // 0x004111E4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
        goto L_00411200;
    // 0x004111E4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_004111E8:
    // 0x004111E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x004111EC: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004111F0: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004111F4: jal         0x0029BC88
    // 0x004111F8: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_0029BC88(rdram, ctx);
        goto after_7;
    // 0x004111F8: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_7:
    // 0x004111FC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_00411200:
    // 0x00411200: bne         $v1, $zero, L_00410F10
    if (ctx->r3 != 0) {
        // 0x00411204: addiu       $s3, $s3, 0x20
        ctx->r19 = ADD32(ctx->r19, 0X20);
            goto L_00410F10;
    }
    // 0x00411204: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x00411208: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x0041120C: bgtz        $s4, L_004110E8
    if (SIGNED(ctx->r20) > 0) {
        // 0x00411210: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_004110E8;
    }
    // 0x00411210: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x00411214: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
L_00411218:
    // 0x00411218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0041121C: bne         $v1, $v0, L_0041127C
    if (ctx->r3 != ctx->r2) {
        // 0x00411220: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0041127C;
    }
    // 0x00411220: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x00411224: lbu         $v1, 0x20($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X20);
    // 0x00411228: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x0041122C: bne         $v0, $zero, L_0041127C
    if (ctx->r2 != 0) {
        // 0x00411230: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0041127C;
    }
    // 0x00411230: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x00411234: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00411238: ori         $v0, $v1, 0x2
    ctx->r2 = ctx->r3 | 0X2;
    // 0x0041123C: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    // 0x00411240: jal         0x0041203C
    // 0x00411244: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    func_0041203C(rdram, ctx);
        goto after_8;
    // 0x00411244: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    after_8:
    // 0x00411248: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041124C: bne         $v1, $zero, L_0041127C
    if (ctx->r3 != 0) {
        // 0x00411250: addiu       $a3, $sp, 0x18
        ctx->r7 = ADD32(ctx->r29, 0X18);
            goto L_0041127C;
    }
    // 0x00411250: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x00411254: lhu         $a2, 0x5E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5E);
    // 0x00411258: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0041125C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411260: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411264: addu        $a2, $a2, $fp
    ctx->r6 = ADD32(ctx->r6, ctx->r30);
    // 0x00411268: jal         0x0029BC88
    // 0x0041126C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_9;
    // 0x0041126C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_9:
    // 0x00411270: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411274: beql        $v1, $zero, L_0041127C
    if (ctx->r3 == 0) {
        // 0x00411278: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0041127C;
    }
    goto skip_1;
    // 0x00411278: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
L_0041127C:
    // 0x0041127C: lw          $ra, 0x164($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X164);
    // 0x00411280: lw          $fp, 0x160($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X160);
    // 0x00411284: lw          $s7, 0x15C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X15C);
    // 0x00411288: lw          $s6, 0x158($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X158);
    // 0x0041128C: lw          $s5, 0x154($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X154);
    // 0x00411290: lw          $s4, 0x150($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X150);
    // 0x00411294: lw          $s3, 0x14C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14C);
    // 0x00411298: lw          $s2, 0x148($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X148);
    // 0x0041129C: lw          $s1, 0x144($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X144);
    // 0x004112A0: lw          $s0, 0x140($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X140);
    // 0x004112A4: jr          $ra
    // 0x004112A8: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
    return;
    // 0x004112A8: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
    // 0x004112AC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x004112B0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x004112B4: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x004112B8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x004112BC: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x004112C0: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x004112C4: lbu         $v0, 0x65($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X65);
    // 0x004112C8: beq         $v0, $zero, L_004112E4
    if (ctx->r2 == 0) {
        // 0x004112CC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_004112E4;
    }
    // 0x004112CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x004112D0: jal         0x0041203C
    // 0x004112D4: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    func_0041203C(rdram, ctx);
        goto after_10;
    // 0x004112D4: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    after_10:
    // 0x004112D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004112DC: bne         $v1, $zero, L_0041144C
    if (ctx->r3 != 0) {
        // 0x004112E0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_0041144C;
    }
    // 0x004112E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_004112E4:
    // 0x004112E4: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x004112E8: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x004112EC: jal         0x0029B8D0
    // 0x004112F0: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_0029B8D0(rdram, ctx);
        goto after_11;
    // 0x004112F0: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_11:
    // 0x004112F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004112F8: bne         $v1, $zero, L_0041144C
    if (ctx->r3 != 0) {
        // 0x004112FC: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_0041144C;
    }
    // 0x004112FC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x00411300: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x00411304: jal         0x00411F2C
    // 0x00411308: addiu       $a2, $sp, 0x52
    ctx->r6 = ADD32(ctx->r29, 0X52);
    func_00411F2C(rdram, ctx);
        goto after_12;
    // 0x00411308: addiu       $a2, $sp, 0x52
    ctx->r6 = ADD32(ctx->r29, 0X52);
    after_12:
    // 0x0041130C: lhu         $v1, 0x2C($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2C);
    // 0x00411310: lhu         $v0, 0x50($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X50);
    // 0x00411314: bne         $v1, $v0, L_0041132C
    if (ctx->r3 != ctx->r2) {
        // 0x00411318: addiu       $s0, $sp, 0x10
        ctx->r16 = ADD32(ctx->r29, 0X10);
            goto L_0041132C;
    }
    // 0x00411318: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x0041131C: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x00411320: lhu         $v0, 0x52($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X52);
    // 0x00411324: beq         $v1, $v0, L_00411374
    if (ctx->r3 == ctx->r2) {
        // 0x00411328: nop
    
            goto L_00411374;
    }
    // 0x00411328: nop

L_0041132C:
    // 0x0041132C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411330: jal         0x004118C0
    // 0x00411334: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_004118C0(rdram, ctx);
        goto after_13;
    // 0x00411334: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_13:
    // 0x00411338: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041133C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x00411340: bne         $v1, $v0, L_0041136C
    if (ctx->r3 != ctx->r2) {
        // 0x00411344: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_0041136C;
    }
    // 0x00411344: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411348: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0041134C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x00411350: jal         0x004115D8
    // 0x00411354: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_004115D8(rdram, ctx);
        goto after_14;
    // 0x00411354: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_14:
    // 0x00411358: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041135C: beq         $v1, $zero, L_00411374
    if (ctx->r3 == 0) {
        // 0x00411360: nop
    
            goto L_00411374;
    }
    // 0x00411360: nop

    // 0x00411364: j           L_0041144C
    // 0x00411368: nop

        goto L_0041144C;
    // 0x00411368: nop

L_0041136C:
    // 0x0041136C: bne         $v1, $zero, L_0041144C
    if (ctx->r3 != 0) {
        // 0x00411370: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0041144C;
    }
    // 0x00411370: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_00411374:
    // 0x00411374: lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18);
    // 0x00411378: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0041137C: bne         $v0, $zero, L_004113BC
    if (ctx->r2 != 0) {
        // 0x00411380: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_004113BC;
    }
    // 0x00411380: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00411384: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411388: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0041138C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x00411390: jal         0x004115D8
    // 0x00411394: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_004115D8(rdram, ctx);
        goto after_15;
    // 0x00411394: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_15:
    // 0x00411398: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041139C: bne         $v1, $zero, L_0041144C
    if (ctx->r3 != 0) {
        // 0x004113A0: nop
    
            goto L_0041144C;
    }
    // 0x004113A0: nop

    // 0x004113A4: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x004113A8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x004113AC: bne         $v0, $zero, L_004113BC
    if (ctx->r2 != 0) {
        // 0x004113B0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_004113BC;
    }
    // 0x004113B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004113B4: j           L_0041144C
    // 0x004113B8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_0041144C;
    // 0x004113B8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_004113BC:
    // 0x004113BC: addu        $v1, $s1, $a0
    ctx->r3 = ADD32(ctx->r17, ctx->r4);
L_004113C0:
    // 0x004113C0: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x004113C4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x004113C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x004113CC: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x004113D0: slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x004113D4: bne         $v0, $zero, L_004113C0
    if (ctx->r2 != 0) {
        // 0x004113D8: addu        $v1, $s1, $a0
        ctx->r3 = ADD32(ctx->r17, ctx->r4);
            goto L_004113C0;
    }
    // 0x004113D8: addu        $v1, $s1, $a0
    ctx->r3 = ADD32(ctx->r17, ctx->r4);
    // 0x004113DC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x004113E0: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x004113E4: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x004113E8: lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1B);
    // 0x004113EC: addiu       $a3, $s1, 0x2C
    ctx->r7 = ADD32(ctx->r17, 0X2C);
    // 0x004113F0: sw          $v0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r2;
    // 0x004113F4: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x004113F8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x004113FC: sw          $v0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r2;
    // 0x00411400: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x00411404: sw          $v0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r2;
    // 0x00411408: sb          $v1, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r3;
    // 0x0041140C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x00411410: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x00411414: lbu         $v0, 0x64($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X64);
    // 0x00411418: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x0041141C: sw          $v1, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r3;
    // 0x00411420: lbu         $v1, 0x64($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X64);
    // 0x00411424: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x00411428: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x0041142C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x00411430: sw          $v0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r2;
    // 0x00411434: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411438: jal         0x0029B8D0
    // 0x0041143C: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
    func_0029B8D0(rdram, ctx);
        goto after_16;
    // 0x0041143C: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
    after_16:
    // 0x00411440: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411444: beql        $v1, $zero, L_0041144C
    if (ctx->r3 == 0) {
        // 0x00411448: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0041144C;
    }
    goto skip_2;
    // 0x00411448: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_2:
L_0041144C:
    // 0x0041144C: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x00411450: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x00411454: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x00411458: jr          $ra
    // 0x0041145C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x0041145C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_004112B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004112B0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x004112B4: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x004112B8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x004112BC: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x004112C0: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x004112C4: lbu         $v0, 0x65($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X65);
    // 0x004112C8: beq         $v0, $zero, L_004112E4
    if (ctx->r2 == 0) {
        // 0x004112CC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_004112E4;
    }
    // 0x004112CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x004112D0: jal         0x0041203C
    // 0x004112D4: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    func_0041203C(rdram, ctx);
        goto after_0;
    // 0x004112D4: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    after_0:
    // 0x004112D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004112DC: bne         $v1, $zero, L_0041144C
    if (ctx->r3 != 0) {
        // 0x004112E0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_0041144C;
    }
    // 0x004112E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_004112E4:
    // 0x004112E4: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x004112E8: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x004112EC: jal         0x0029B8D0
    // 0x004112F0: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_0029B8D0(rdram, ctx);
        goto after_1;
    // 0x004112F0: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x004112F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x004112F8: bne         $v1, $zero, L_0041144C
    if (ctx->r3 != 0) {
        // 0x004112FC: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_0041144C;
    }
    // 0x004112FC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x00411300: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x00411304: jal         0x00411F2C
    // 0x00411308: addiu       $a2, $sp, 0x52
    ctx->r6 = ADD32(ctx->r29, 0X52);
    func_00411F2C(rdram, ctx);
        goto after_2;
    // 0x00411308: addiu       $a2, $sp, 0x52
    ctx->r6 = ADD32(ctx->r29, 0X52);
    after_2:
    // 0x0041130C: lhu         $v1, 0x2C($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2C);
    // 0x00411310: lhu         $v0, 0x50($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X50);
    // 0x00411314: bne         $v1, $v0, L_0041132C
    if (ctx->r3 != ctx->r2) {
        // 0x00411318: addiu       $s0, $sp, 0x10
        ctx->r16 = ADD32(ctx->r29, 0X10);
            goto L_0041132C;
    }
    // 0x00411318: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x0041131C: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x00411320: lhu         $v0, 0x52($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X52);
    // 0x00411324: beq         $v1, $v0, L_00411374
    if (ctx->r3 == ctx->r2) {
        // 0x00411328: nop
    
            goto L_00411374;
    }
    // 0x00411328: nop

L_0041132C:
    // 0x0041132C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411330: jal         0x004118C0
    // 0x00411334: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_004118C0(rdram, ctx);
        goto after_3;
    // 0x00411334: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // 0x00411338: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041133C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x00411340: bne         $v1, $v0, L_0041136C
    if (ctx->r3 != ctx->r2) {
        // 0x00411344: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_0041136C;
    }
    // 0x00411344: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411348: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0041134C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x00411350: jal         0x004115D8
    // 0x00411354: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_004115D8(rdram, ctx);
        goto after_4;
    // 0x00411354: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // 0x00411358: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041135C: beq         $v1, $zero, L_00411374
    if (ctx->r3 == 0) {
        // 0x00411360: nop
    
            goto L_00411374;
    }
    // 0x00411360: nop

    // 0x00411364: j           L_0041144C
    // 0x00411368: nop

        goto L_0041144C;
    // 0x00411368: nop

L_0041136C:
    // 0x0041136C: bne         $v1, $zero, L_0041144C
    if (ctx->r3 != 0) {
        // 0x00411370: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0041144C;
    }
    // 0x00411370: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_00411374:
    // 0x00411374: lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18);
    // 0x00411378: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x0041137C: bne         $v0, $zero, L_004113BC
    if (ctx->r2 != 0) {
        // 0x00411380: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_004113BC;
    }
    // 0x00411380: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00411384: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411388: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x0041138C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x00411390: jal         0x004115D8
    // 0x00411394: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_004115D8(rdram, ctx);
        goto after_5;
    // 0x00411394: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // 0x00411398: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041139C: bne         $v1, $zero, L_0041144C
    if (ctx->r3 != 0) {
        // 0x004113A0: nop
    
            goto L_0041144C;
    }
    // 0x004113A0: nop

    // 0x004113A4: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x004113A8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x004113AC: bne         $v0, $zero, L_004113BC
    if (ctx->r2 != 0) {
        // 0x004113B0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_004113BC;
    }
    // 0x004113B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004113B4: j           L_0041144C
    // 0x004113B8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_0041144C;
    // 0x004113B8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_004113BC:
    // 0x004113BC: addu        $v1, $s1, $a0
    ctx->r3 = ADD32(ctx->r17, ctx->r4);
L_004113C0:
    // 0x004113C0: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x004113C4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x004113C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x004113CC: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x004113D0: slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x004113D4: bne         $v0, $zero, L_004113C0
    if (ctx->r2 != 0) {
        // 0x004113D8: addu        $v1, $s1, $a0
        ctx->r3 = ADD32(ctx->r17, ctx->r4);
            goto L_004113C0;
    }
    // 0x004113D8: addu        $v1, $s1, $a0
    ctx->r3 = ADD32(ctx->r17, ctx->r4);
    // 0x004113DC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x004113E0: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x004113E4: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x004113E8: lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1B);
    // 0x004113EC: addiu       $a3, $s1, 0x2C
    ctx->r7 = ADD32(ctx->r17, 0X2C);
    // 0x004113F0: sw          $v0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r2;
    // 0x004113F4: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x004113F8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x004113FC: sw          $v0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r2;
    // 0x00411400: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x00411404: sw          $v0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r2;
    // 0x00411408: sb          $v1, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r3;
    // 0x0041140C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x00411410: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x00411414: lbu         $v0, 0x64($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X64);
    // 0x00411418: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x0041141C: sw          $v1, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r3;
    // 0x00411420: lbu         $v1, 0x64($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X64);
    // 0x00411424: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x00411428: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x0041142C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x00411430: sw          $v0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r2;
    // 0x00411434: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411438: jal         0x0029B8D0
    // 0x0041143C: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
    func_0029B8D0(rdram, ctx);
        goto after_6;
    // 0x0041143C: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
    after_6:
    // 0x00411440: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411444: beql        $v1, $zero, L_0041144C
    if (ctx->r3 == 0) {
        // 0x00411448: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_0041144C;
    }
    goto skip_0;
    // 0x00411448: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
L_0041144C:
    // 0x0041144C: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x00411450: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x00411454: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x00411458: jr          $ra
    // 0x0041145C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x0041145C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_00411460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00411460: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x00411464: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x00411468: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x0041146C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x00411470: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00411474: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x00411478: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x0041147C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x00411480: addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // 0x00411484: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x00411488: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x0041148C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x00411490: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00411494: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x00411498: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x0041149C: jal         0x00411F74
    // 0x004114A0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    func_00411F74(rdram, ctx);
        goto after_0;
    // 0x004114A0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    after_0:
    // 0x004114A4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x004114A8: beq         $v0, $v1, L_004115A8
    if (ctx->r2 == ctx->r3) {
        // 0x004114AC: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_004115A8;
    }
    // 0x004114AC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x004114B0: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x004114B4: blez        $v0, L_0041159C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x004114B8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_0041159C;
    }
    // 0x004114B8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x004114BC: andi        $s6, $s1, 0xFFFF
    ctx->r22 = ctx->r17 & 0XFFFF;
    // 0x004114C0: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // 0x004114C4: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
L_004114C8:
    // 0x004114C8: lhu         $a2, 0x5E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5E);
    // 0x004114CC: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004114D0: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004114D4: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x004114D8: jal         0x0029B8D0
    // 0x004114DC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_1;
    // 0x004114DC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_1:
    // 0x004114E0: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x004114E4: bne         $a3, $zero, L_004115A8
    if (ctx->r7 != 0) {
        // 0x004114E8: addu        $v0, $a3, $zero
        ctx->r2 = ADD32(ctx->r7, 0);
            goto L_004115A8;
    }
    // 0x004114E8: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x004114EC: lhu         $v0, 0x14($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X14);
    // 0x004114F0: bne         $v0, $s6, L_00411588
    if (ctx->r2 != ctx->r22) {
        // 0x004114F4: nop
    
            goto L_00411588;
    }
    // 0x004114F4: nop

    // 0x004114F8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x004114FC: bne         $v0, $s7, L_00411588
    if (ctx->r2 != ctx->r23) {
        // 0x00411500: nop
    
            goto L_00411588;
    }
    // 0x00411500: nop

    // 0x00411504: beq         $s4, $zero, L_00411534
    if (ctx->r20 == 0) {
        // 0x00411508: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_00411534;
    }
    // 0x00411508: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x0041150C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x00411510: addu        $v0, $s1, $a1
    ctx->r2 = ADD32(ctx->r17, ctx->r5);
L_00411514:
    // 0x00411514: addu        $v1, $s4, $a1
    ctx->r3 = ADD32(ctx->r20, ctx->r5);
    // 0x00411518: lbu         $a0, 0x10($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X10);
    // 0x0041151C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x00411520: bne         $a0, $v0, L_00411580
    if (ctx->r4 != ctx->r2) {
        // 0x00411524: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_00411580;
    }
    // 0x00411524: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x00411528: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x0041152C: bne         $v0, $zero, L_00411514
    if (ctx->r2 != 0) {
        // 0x00411530: addu        $v0, $s1, $a1
        ctx->r2 = ADD32(ctx->r17, ctx->r5);
            goto L_00411514;
    }
    // 0x00411530: addu        $v0, $s1, $a1
    ctx->r2 = ADD32(ctx->r17, ctx->r5);
L_00411534:
    // 0x00411534: beq         $s3, $zero, L_00411568
    if (ctx->r19 == 0) {
        // 0x00411538: nop
    
            goto L_00411568;
    }
    // 0x00411538: nop

    // 0x0041153C: bne         $a2, $zero, L_00411588
    if (ctx->r6 != 0) {
        // 0x00411540: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_00411588;
    }
    // 0x00411540: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00411544: addu        $v0, $s1, $a1
    ctx->r2 = ADD32(ctx->r17, ctx->r5);
L_00411548:
    // 0x00411548: addu        $v1, $s3, $a1
    ctx->r3 = ADD32(ctx->r19, ctx->r5);
    // 0x0041154C: lbu         $a0, 0xC($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XC);
    // 0x00411550: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x00411554: bne         $a0, $v0, L_00411578
    if (ctx->r4 != ctx->r2) {
        // 0x00411558: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_00411578;
    }
    // 0x00411558: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x0041155C: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x00411560: bne         $v0, $zero, L_00411548
    if (ctx->r2 != 0) {
        // 0x00411564: addu        $v0, $s1, $a1
        ctx->r2 = ADD32(ctx->r17, ctx->r5);
            goto L_00411548;
    }
    // 0x00411564: addu        $v0, $s1, $a1
    ctx->r2 = ADD32(ctx->r17, ctx->r5);
L_00411568:
    // 0x00411568: bne         $a2, $zero, L_00411588
    if (ctx->r6 != 0) {
        // 0x0041156C: addu        $v0, $a3, $zero
        ctx->r2 = ADD32(ctx->r7, 0);
            goto L_00411588;
    }
    // 0x0041156C: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x00411570: j           L_004115A8
    // 0x00411574: sw          $s0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r16;
        goto L_004115A8;
    // 0x00411574: sw          $s0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r16;
L_00411578:
    // 0x00411578: j           L_00411568
    // 0x0041157C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_00411568;
    // 0x0041157C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_00411580:
    // 0x00411580: j           L_00411534
    // 0x00411584: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_00411534;
    // 0x00411584: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_00411588:
    // 0x00411588: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x0041158C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411590: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00411594: bne         $v0, $zero, L_004114C8
    if (ctx->r2 != 0) {
        // 0x00411598: addiu       $a3, $sp, 0x10
        ctx->r7 = ADD32(ctx->r29, 0X10);
            goto L_004114C8;
    }
    // 0x00411598: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
L_0041159C:
    // 0x0041159C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x004115A0: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x004115A4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_004115A8:
    // 0x004115A8: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x004115AC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x004115B0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x004115B4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x004115B8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x004115BC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x004115C0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x004115C4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x004115C8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x004115CC: jr          $ra
    // 0x004115D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x004115D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x004115D4: jal         0x0021098C
    // 0x004115D8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    func_0021098C(rdram, ctx);
        goto after_2;
    // 0x004115D8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    after_2:
    // 0x004115DC: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x004115E0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x004115E4: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x004115E8: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x004115EC: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x004115F0: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x004115F4: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x004115F8: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x004115FC: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x00411600: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x00411604: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x00411608: beq         $v0, $zero, L_00411620
    if (ctx->r2 == 0) {
        // 0x0041160C: addu        $s4, $a2, $zero
        ctx->r20 = ADD32(ctx->r6, 0);
            goto L_00411620;
    }
    // 0x0041160C: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x00411610: jal         0x0041203C
    // 0x00411614: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    func_0041203C(rdram, ctx);
        goto after_3;
    // 0x00411614: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    after_3:
    // 0x00411618: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x0041161C: nop
    
            goto L_00411898;
    }
    // 0x0041161C: nop

L_00411620:
    // 0x00411620: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00411624: jal         0x002A0140
    // 0x00411628: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_4;
    // 0x00411628: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    after_4:
    // 0x0041162C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00411630: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x00411634: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x00411638: lw          $v1, 0xC($s6)
    ctx->r3 = MEM_W(ctx->r22, 0XC);
    // 0x0041163C: addiu       $s3, $sp, 0x18
    ctx->r19 = ADD32(ctx->r29, 0X18);
    // 0x00411640: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x00411644: sw          $v1, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r3;
    // 0x00411648: lw          $v0, 0x10($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X10);
    // 0x0041164C: lw          $v1, 0x14($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X14);
    // 0x00411650: addiu       $s5, $sp, 0x38
    ctx->r21 = ADD32(ctx->r29, 0X38);
    // 0x00411654: sw          $v0, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r2;
    // 0x00411658: sw          $v1, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r3;
    // 0x0041165C: sb          $s1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r17;
L_00411660:
    // 0x00411660: jal         0x0041203C
    // 0x00411664: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_5;
    // 0x00411664: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_5:
    // 0x00411668: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x0041166C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_00411898;
    }
    // 0x0041166C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00411670: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411674: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411678: jal         0x0029B8D0
    // 0x0041167C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_0029B8D0(rdram, ctx);
        goto after_6;
    // 0x0041167C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_6:
    // 0x00411680: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x00411684: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_00411898;
    }
    // 0x00411684: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x00411688: ori         $v0, $s1, 0x80
    ctx->r2 = ctx->r17 | 0X80;
    // 0x0041168C: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // 0x00411690: addu        $v0, $s3, $s0
    ctx->r2 = ADD32(ctx->r19, ctx->r16);
L_00411694:
    // 0x00411694: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x00411698: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x0041169C: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x004116A0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x004116A4: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x004116A8: bne         $v0, $zero, L_00411694
    if (ctx->r2 != 0) {
        // 0x004116AC: addu        $v0, $s3, $s0
        ctx->r2 = ADD32(ctx->r19, ctx->r16);
            goto L_00411694;
    }
    // 0x004116AC: addu        $v0, $s3, $s0
    ctx->r2 = ADD32(ctx->r19, ctx->r16);
    // 0x004116B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x004116B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x004116B8: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004116BC: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004116C0: jal         0x0029BC88
    // 0x004116C4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_0029BC88(rdram, ctx);
        goto after_7;
    // 0x004116C4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_7:
    // 0x004116C8: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x004116CC: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_00411898;
    }
    // 0x004116CC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x004116D0: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004116D4: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004116D8: jal         0x0029B8D0
    // 0x004116DC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    func_0029B8D0(rdram, ctx);
        goto after_8;
    // 0x004116DC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x004116E0: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x004116E4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_00411898;
    }
    // 0x004116E4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x004116E8: addu        $v0, $s5, $s0
    ctx->r2 = ADD32(ctx->r21, ctx->r16);
L_004116EC:
    // 0x004116EC: addu        $v1, $s3, $s0
    ctx->r3 = ADD32(ctx->r19, ctx->r16);
    // 0x004116F0: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x004116F4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x004116F8: bne         $a0, $v0, L_00411714
    if (ctx->r4 != ctx->r2) {
        // 0x004116FC: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_00411714;
    }
    // 0x004116FC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x00411700: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411704: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x00411708: bne         $v0, $zero, L_004116EC
    if (ctx->r2 != 0) {
        // 0x0041170C: addu        $v0, $s5, $s0
        ctx->r2 = ADD32(ctx->r21, ctx->r16);
            goto L_004116EC;
    }
    // 0x0041170C: addu        $v0, $s5, $s0
    ctx->r2 = ADD32(ctx->r21, ctx->r16);
    // 0x00411710: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_00411714:
    // 0x00411714: bnel        $s0, $v0, L_00411774
    if (ctx->r16 != ctx->r2) {
        // 0x00411718: sb          $zero, 0x65($s2)
        MEM_B(0X65, ctx->r18) = 0;
            goto L_00411774;
    }
    goto skip_0;
    // 0x00411718: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    skip_0:
    // 0x0041171C: blezl       $s1, L_00411764
    if (SIGNED(ctx->r17) <= 0) {
        // 0x00411720: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_00411764;
    }
    goto skip_1;
    // 0x00411720: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x00411724: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    // 0x00411728: jal         0x0041203C
    // 0x0041172C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_9;
    // 0x0041172C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_9:
    // 0x00411730: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x00411734: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_00411898;
    }
    // 0x00411734: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00411738: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x0041173C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411740: jal         0x0029B8D0
    // 0x00411744: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_0029B8D0(rdram, ctx);
        goto after_10;
    // 0x00411744: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_10:
    // 0x00411748: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x0041174C: nop
    
            goto L_00411898;
    }
    // 0x0041174C: nop

    // 0x00411750: lbu         $v1, 0x18($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X18);
    // 0x00411754: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x00411758: bnel        $v1, $v0, L_00411774
    if (ctx->r3 != ctx->r2) {
        // 0x0041175C: sb          $zero, 0x65($s2)
        MEM_B(0X65, ctx->r18) = 0;
            goto L_00411774;
    }
    goto skip_2;
    // 0x0041175C: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    skip_2:
    // 0x00411760: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_00411764:
    // 0x00411764: slti        $v0, $s1, 0x3E
    ctx->r2 = SIGNED(ctx->r17) < 0X3E ? 1 : 0;
    // 0x00411768: bnel        $v0, $zero, L_00411660
    if (ctx->r2 != 0) {
        // 0x0041176C: sb          $s1, 0x65($s2)
        MEM_B(0X65, ctx->r18) = ctx->r17;
            goto L_00411660;
    }
    goto skip_3;
    // 0x0041176C: sb          $s1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r17;
    skip_3:
    // 0x00411770: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
L_00411774:
    // 0x00411774: jal         0x0041203C
    // 0x00411778: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_11;
    // 0x00411778: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_11:
    // 0x0041177C: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x00411780: addiu       $a2, $s4, 0x1C
        ctx->r6 = ADD32(ctx->r20, 0X1C);
            goto L_00411898;
    }
    // 0x00411780: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    // 0x00411784: addiu       $a1, $s4, 0x1E
    ctx->r5 = ADD32(ctx->r20, 0X1E);
    // 0x00411788: lhu         $v0, 0x18($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X18);
    // 0x0041178C: slt         $v1, $zero, $s1
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x00411790: sb          $s1, 0x1A($s4)
    MEM_B(0X1A, ctx->r20) = ctx->r17;
    // 0x00411794: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x00411798: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x0041179C: sh          $v1, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r3;
    // 0x004117A0: lbu         $v0, 0x1B($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1B);
    // 0x004117A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004117A8: sh          $zero, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = 0;
    // 0x004117AC: sh          $zero, 0x1C($s4)
    MEM_H(0X1C, ctx->r20) = 0;
    // 0x004117B0: sb          $v0, 0x1B($s4)
    MEM_B(0X1B, ctx->r20) = ctx->r2;
    // 0x004117B4: addu        $v0, $s4, $a0
    ctx->r2 = ADD32(ctx->r20, ctx->r4);
L_004117B8:
    // 0x004117B8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x004117BC: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x004117C0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x004117C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x004117C8: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x004117CC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x004117D0: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x004117D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x004117D8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x004117DC: sltiu       $v0, $a0, 0x1C
    ctx->r2 = ctx->r4 < 0X1C ? 1 : 0;
    // 0x004117E0: bne         $v0, $zero, L_004117B8
    if (ctx->r2 != 0) {
        // 0x004117E4: addu        $v0, $s4, $a0
        ctx->r2 = ADD32(ctx->r20, ctx->r4);
            goto L_004117B8;
    }
    // 0x004117E4: addu        $v0, $s4, $a0
    ctx->r2 = ADD32(ctx->r20, ctx->r4);
    // 0x004117E8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x004117EC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x004117F0: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x004117F4: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x004117F8: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x004117FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00411800: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x00411804: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x00411808: sh          $v0, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r2;
    // 0x0041180C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x00411810: sh          $v0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r2;
L_00411814:
    // 0x00411814: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x00411818: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x0041181C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411820: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411824: jal         0x0029BC88
    // 0x00411828: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_0029BC88(rdram, ctx);
        goto after_12;
    // 0x00411828: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_12:
    // 0x0041182C: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x00411830: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_00411898;
    }
    // 0x00411830: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411834: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x00411838: bne         $v0, $zero, L_00411814
    if (ctx->r2 != 0) {
        // 0x0041183C: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_00411814;
    }
    // 0x0041183C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x00411840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00411844: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411848: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x0041184C: jal         0x0029B8D0
    // 0x00411850: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_0029B8D0(rdram, ctx);
        goto after_13;
    // 0x00411850: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_13:
    // 0x00411854: beq         $v0, $zero, L_0041186C
    if (ctx->r2 == 0) {
        // 0x00411858: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_0041186C;
    }
    // 0x00411858: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x0041185C: j           L_00411898
    // 0x00411860: nop

        goto L_00411898;
    // 0x00411860: nop

L_00411864:
    // 0x00411864: j           L_00411898
    // 0x00411868: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_00411898;
    // 0x00411868: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_0041186C:
    // 0x0041186C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x00411870: addu        $v0, $a1, $s0
    ctx->r2 = ADD32(ctx->r5, ctx->r16);
L_00411874:
    // 0x00411874: addu        $v1, $s4, $s0
    ctx->r3 = ADD32(ctx->r20, ctx->r16);
    // 0x00411878: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x0041187C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x00411880: bne         $a0, $v0, L_00411864
    if (ctx->r4 != ctx->r2) {
        // 0x00411884: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_00411864;
    }
    // 0x00411884: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411888: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x0041188C: bne         $v0, $zero, L_00411874
    if (ctx->r2 != 0) {
        // 0x00411890: addu        $v0, $a1, $s0
        ctx->r2 = ADD32(ctx->r5, ctx->r16);
            goto L_00411874;
    }
    // 0x00411890: addu        $v0, $a1, $s0
    ctx->r2 = ADD32(ctx->r5, ctx->r16);
    // 0x00411894: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00411898:
    // 0x00411898: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x0041189C: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x004118A0: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x004118A4: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x004118A8: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x004118AC: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x004118B0: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x004118B4: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x004118B8: jr          $ra
    // 0x004118BC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x004118BC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_004115D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004115D8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x004115DC: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x004115E0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x004115E4: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x004115E8: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x004115EC: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x004115F0: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x004115F4: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x004115F8: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x004115FC: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x00411600: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x00411604: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x00411608: beq         $v0, $zero, L_00411620
    if (ctx->r2 == 0) {
        // 0x0041160C: addu        $s4, $a2, $zero
        ctx->r20 = ADD32(ctx->r6, 0);
            goto L_00411620;
    }
    // 0x0041160C: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x00411610: jal         0x0041203C
    // 0x00411614: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    func_0041203C(rdram, ctx);
        goto after_0;
    // 0x00411614: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    after_0:
    // 0x00411618: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x0041161C: nop
    
            goto L_00411898;
    }
    // 0x0041161C: nop

L_00411620:
    // 0x00411620: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00411624: jal         0x002A0140
    // 0x00411628: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x00411628: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    after_1:
    // 0x0041162C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00411630: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x00411634: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x00411638: lw          $v1, 0xC($s6)
    ctx->r3 = MEM_W(ctx->r22, 0XC);
    // 0x0041163C: addiu       $s3, $sp, 0x18
    ctx->r19 = ADD32(ctx->r29, 0X18);
    // 0x00411640: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x00411644: sw          $v1, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r3;
    // 0x00411648: lw          $v0, 0x10($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X10);
    // 0x0041164C: lw          $v1, 0x14($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X14);
    // 0x00411650: addiu       $s5, $sp, 0x38
    ctx->r21 = ADD32(ctx->r29, 0X38);
    // 0x00411654: sw          $v0, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r2;
    // 0x00411658: sw          $v1, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r3;
    // 0x0041165C: sb          $s1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r17;
L_00411660:
    // 0x00411660: jal         0x0041203C
    // 0x00411664: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_2;
    // 0x00411664: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_2:
    // 0x00411668: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x0041166C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_00411898;
    }
    // 0x0041166C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00411670: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411674: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411678: jal         0x0029B8D0
    // 0x0041167C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_0029B8D0(rdram, ctx);
        goto after_3;
    // 0x0041167C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x00411680: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x00411684: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_00411898;
    }
    // 0x00411684: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x00411688: ori         $v0, $s1, 0x80
    ctx->r2 = ctx->r17 | 0X80;
    // 0x0041168C: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // 0x00411690: addu        $v0, $s3, $s0
    ctx->r2 = ADD32(ctx->r19, ctx->r16);
L_00411694:
    // 0x00411694: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x00411698: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x0041169C: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x004116A0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x004116A4: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x004116A8: bne         $v0, $zero, L_00411694
    if (ctx->r2 != 0) {
        // 0x004116AC: addu        $v0, $s3, $s0
        ctx->r2 = ADD32(ctx->r19, ctx->r16);
            goto L_00411694;
    }
    // 0x004116AC: addu        $v0, $s3, $s0
    ctx->r2 = ADD32(ctx->r19, ctx->r16);
    // 0x004116B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x004116B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x004116B8: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004116BC: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004116C0: jal         0x0029BC88
    // 0x004116C4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_0029BC88(rdram, ctx);
        goto after_4;
    // 0x004116C4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x004116C8: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x004116CC: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_00411898;
    }
    // 0x004116CC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x004116D0: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x004116D4: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x004116D8: jal         0x0029B8D0
    // 0x004116DC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    func_0029B8D0(rdram, ctx);
        goto after_5;
    // 0x004116DC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x004116E0: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x004116E4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_00411898;
    }
    // 0x004116E4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x004116E8: addu        $v0, $s5, $s0
    ctx->r2 = ADD32(ctx->r21, ctx->r16);
L_004116EC:
    // 0x004116EC: addu        $v1, $s3, $s0
    ctx->r3 = ADD32(ctx->r19, ctx->r16);
    // 0x004116F0: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x004116F4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x004116F8: bne         $a0, $v0, L_00411714
    if (ctx->r4 != ctx->r2) {
        // 0x004116FC: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_00411714;
    }
    // 0x004116FC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x00411700: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411704: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x00411708: bne         $v0, $zero, L_004116EC
    if (ctx->r2 != 0) {
        // 0x0041170C: addu        $v0, $s5, $s0
        ctx->r2 = ADD32(ctx->r21, ctx->r16);
            goto L_004116EC;
    }
    // 0x0041170C: addu        $v0, $s5, $s0
    ctx->r2 = ADD32(ctx->r21, ctx->r16);
    // 0x00411710: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_00411714:
    // 0x00411714: bnel        $s0, $v0, L_00411774
    if (ctx->r16 != ctx->r2) {
        // 0x00411718: sb          $zero, 0x65($s2)
        MEM_B(0X65, ctx->r18) = 0;
            goto L_00411774;
    }
    goto skip_0;
    // 0x00411718: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    skip_0:
    // 0x0041171C: blezl       $s1, L_00411764
    if (SIGNED(ctx->r17) <= 0) {
        // 0x00411720: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_00411764;
    }
    goto skip_1;
    // 0x00411720: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x00411724: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    // 0x00411728: jal         0x0041203C
    // 0x0041172C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_6;
    // 0x0041172C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_6:
    // 0x00411730: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x00411734: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_00411898;
    }
    // 0x00411734: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00411738: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x0041173C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411740: jal         0x0029B8D0
    // 0x00411744: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_0029B8D0(rdram, ctx);
        goto after_7;
    // 0x00411744: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_7:
    // 0x00411748: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x0041174C: nop
    
            goto L_00411898;
    }
    // 0x0041174C: nop

    // 0x00411750: lbu         $v1, 0x18($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X18);
    // 0x00411754: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x00411758: bnel        $v1, $v0, L_00411774
    if (ctx->r3 != ctx->r2) {
        // 0x0041175C: sb          $zero, 0x65($s2)
        MEM_B(0X65, ctx->r18) = 0;
            goto L_00411774;
    }
    goto skip_2;
    // 0x0041175C: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    skip_2:
    // 0x00411760: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_00411764:
    // 0x00411764: slti        $v0, $s1, 0x3E
    ctx->r2 = SIGNED(ctx->r17) < 0X3E ? 1 : 0;
    // 0x00411768: bnel        $v0, $zero, L_00411660
    if (ctx->r2 != 0) {
        // 0x0041176C: sb          $s1, 0x65($s2)
        MEM_B(0X65, ctx->r18) = ctx->r17;
            goto L_00411660;
    }
    goto skip_3;
    // 0x0041176C: sb          $s1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r17;
    skip_3:
    // 0x00411770: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
L_00411774:
    // 0x00411774: jal         0x0041203C
    // 0x00411778: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0041203C(rdram, ctx);
        goto after_8;
    // 0x00411778: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
    // 0x0041177C: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x00411780: addiu       $a2, $s4, 0x1C
        ctx->r6 = ADD32(ctx->r20, 0X1C);
            goto L_00411898;
    }
    // 0x00411780: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    // 0x00411784: addiu       $a1, $s4, 0x1E
    ctx->r5 = ADD32(ctx->r20, 0X1E);
    // 0x00411788: lhu         $v0, 0x18($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X18);
    // 0x0041178C: slt         $v1, $zero, $s1
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x00411790: sb          $s1, 0x1A($s4)
    MEM_B(0X1A, ctx->r20) = ctx->r17;
    // 0x00411794: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x00411798: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x0041179C: sh          $v1, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r3;
    // 0x004117A0: lbu         $v0, 0x1B($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1B);
    // 0x004117A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004117A8: sh          $zero, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = 0;
    // 0x004117AC: sh          $zero, 0x1C($s4)
    MEM_H(0X1C, ctx->r20) = 0;
    // 0x004117B0: sb          $v0, 0x1B($s4)
    MEM_B(0X1B, ctx->r20) = ctx->r2;
    // 0x004117B4: addu        $v0, $s4, $a0
    ctx->r2 = ADD32(ctx->r20, ctx->r4);
L_004117B8:
    // 0x004117B8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x004117BC: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x004117C0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x004117C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x004117C8: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x004117CC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x004117D0: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x004117D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x004117D8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x004117DC: sltiu       $v0, $a0, 0x1C
    ctx->r2 = ctx->r4 < 0X1C ? 1 : 0;
    // 0x004117E0: bne         $v0, $zero, L_004117B8
    if (ctx->r2 != 0) {
        // 0x004117E4: addu        $v0, $s4, $a0
        ctx->r2 = ADD32(ctx->r20, ctx->r4);
            goto L_004117B8;
    }
    // 0x004117E4: addu        $v0, $s4, $a0
    ctx->r2 = ADD32(ctx->r20, ctx->r4);
    // 0x004117E8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x004117EC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x004117F0: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x004117F4: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x004117F8: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x004117FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00411800: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x00411804: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x00411808: sh          $v0, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r2;
    // 0x0041180C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x00411810: sh          $v0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r2;
L_00411814:
    // 0x00411814: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x00411818: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x0041181C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411820: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411824: jal         0x0029BC88
    // 0x00411828: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_0029BC88(rdram, ctx);
        goto after_9;
    // 0x00411828: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_9:
    // 0x0041182C: bne         $v0, $zero, L_00411898
    if (ctx->r2 != 0) {
        // 0x00411830: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_00411898;
    }
    // 0x00411830: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411834: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x00411838: bne         $v0, $zero, L_00411814
    if (ctx->r2 != 0) {
        // 0x0041183C: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_00411814;
    }
    // 0x0041183C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x00411840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00411844: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411848: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x0041184C: jal         0x0029B8D0
    // 0x00411850: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_0029B8D0(rdram, ctx);
        goto after_10;
    // 0x00411850: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_10:
    // 0x00411854: beq         $v0, $zero, L_0041186C
    if (ctx->r2 == 0) {
        // 0x00411858: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_0041186C;
    }
    // 0x00411858: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x0041185C: j           L_00411898
    // 0x00411860: nop

        goto L_00411898;
    // 0x00411860: nop

L_00411864:
    // 0x00411864: j           L_00411898
    // 0x00411868: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_00411898;
    // 0x00411868: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_0041186C:
    // 0x0041186C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x00411870: addu        $v0, $a1, $s0
    ctx->r2 = ADD32(ctx->r5, ctx->r16);
L_00411874:
    // 0x00411874: addu        $v1, $s4, $s0
    ctx->r3 = ADD32(ctx->r20, ctx->r16);
    // 0x00411878: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x0041187C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x00411880: bne         $a0, $v0, L_00411864
    if (ctx->r4 != ctx->r2) {
        // 0x00411884: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_00411864;
    }
    // 0x00411884: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411888: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x0041188C: bne         $v0, $zero, L_00411874
    if (ctx->r2 != 0) {
        // 0x00411890: addu        $v0, $a1, $s0
        ctx->r2 = ADD32(ctx->r5, ctx->r16);
            goto L_00411874;
    }
    // 0x00411890: addu        $v0, $a1, $s0
    ctx->r2 = ADD32(ctx->r5, ctx->r16);
    // 0x00411894: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00411898:
    // 0x00411898: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x0041189C: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x004118A0: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x004118A4: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x004118A8: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x004118AC: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x004118B0: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x004118B4: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x004118B8: jr          $ra
    // 0x004118BC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x004118BC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_004118C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004118C0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x004118C4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x004118C8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x004118CC: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x004118D0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x004118D4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x004118D8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x004118DC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x004118E0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x004118E4: lbu         $v0, 0x65($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X65);
    // 0x004118E8: beq         $v0, $zero, L_00411900
    if (ctx->r2 == 0) {
        // 0x004118EC: addu        $s4, $a1, $zero
        ctx->r20 = ADD32(ctx->r5, 0);
            goto L_00411900;
    }
    // 0x004118EC: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x004118F0: jal         0x0041203C
    // 0x004118F4: sb          $zero, 0x65($s3)
    MEM_B(0X65, ctx->r19) = 0;
    func_0041203C(rdram, ctx);
        goto after_0;
    // 0x004118F4: sb          $zero, 0x65($s3)
    MEM_B(0X65, ctx->r19) = 0;
    after_0:
    // 0x004118F8: bne         $v0, $zero, L_00411A0C
    if (ctx->r2 != 0) {
        // 0x004118FC: nop
    
            goto L_00411A0C;
    }
    // 0x004118FC: nop

L_00411900:
    // 0x00411900: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x00411904: addiu       $s0, $sp, 0x1A
    ctx->r16 = ADD32(ctx->r29, 0X1A);
    // 0x00411908: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x0041190C: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x00411910: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00411914: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x00411918: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x0041191C: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x00411920: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x00411924: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_00411928:
    // 0x00411928: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x0041192C: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x00411930: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    // 0x00411934: jal         0x0029B8D0
    // 0x00411938: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_0029B8D0(rdram, ctx);
        goto after_1;
    // 0x00411938: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
    // 0x0041193C: bne         $v0, $zero, L_00411A0C
    if (ctx->r2 != 0) {
        // 0x00411940: addiu       $a2, $sp, 0x20
        ctx->r6 = ADD32(ctx->r29, 0X20);
            goto L_00411A0C;
    }
    // 0x00411940: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x00411944: addiu       $a1, $sp, 0x22
    ctx->r5 = ADD32(ctx->r29, 0X22);
    // 0x00411948: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041194C: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // 0x00411950: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x00411954: addu        $v0, $s4, $a0
    ctx->r2 = ADD32(ctx->r20, ctx->r4);
L_00411958:
    // 0x00411958: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x0041195C: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x00411960: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x00411964: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411968: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x0041196C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x00411970: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x00411974: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411978: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x0041197C: sltiu       $v0, $a0, 0x1C
    ctx->r2 = ctx->r4 < 0X1C ? 1 : 0;
    // 0x00411980: bne         $v0, $zero, L_00411958
    if (ctx->r2 != 0) {
        // 0x00411984: addu        $v0, $s4, $a0
        ctx->r2 = ADD32(ctx->r20, ctx->r4);
            goto L_00411958;
    }
    // 0x00411984: addu        $v0, $s4, $a0
    ctx->r2 = ADD32(ctx->r20, ctx->r4);
    // 0x00411988: lhu         $v1, 0x1C($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X1C);
    // 0x0041198C: lhu         $v0, 0x20($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X20);
    // 0x00411990: bnel        $v1, $v0, L_004119AC
    if (ctx->r3 != ctx->r2) {
        // 0x00411994: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_004119AC;
    }
    goto skip_0;
    // 0x00411994: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x00411998: lhu         $v1, 0x1E($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X1E);
    // 0x0041199C: lhu         $v0, 0x22($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X22);
    // 0x004119A0: beq         $v1, $v0, L_004119BC
    if (ctx->r3 == ctx->r2) {
        // 0x004119A4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_004119BC;
    }
    // 0x004119A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x004119A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_004119AC:
    // 0x004119AC: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x004119B0: bne         $v0, $zero, L_00411928
    if (ctx->r2 != 0) {
        // 0x004119B4: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_00411928;
    }
    // 0x004119B4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x004119B8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_004119BC:
    // 0x004119BC: bne         $s2, $v0, L_004119CC
    if (ctx->r18 != ctx->r2) {
        // 0x004119C0: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_004119CC;
    }
    // 0x004119C0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x004119C4: j           L_00411A0C
    // 0x004119C8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_00411A0C;
    // 0x004119C8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_004119CC:
    // 0x004119CC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x004119D0: addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
L_004119D4:
    // 0x004119D4: beql        $s0, $s2, L_004119FC
    if (ctx->r16 == ctx->r18) {
        // 0x004119D8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_004119FC;
    }
    goto skip_1;
    // 0x004119D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x004119DC: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x004119E0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x004119E4: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x004119E8: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x004119EC: jal         0x0029BC88
    // 0x004119F0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_0029BC88(rdram, ctx);
        goto after_2;
    // 0x004119F0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_2:
    // 0x004119F4: bne         $v0, $zero, L_00411A0C
    if (ctx->r2 != 0) {
        // 0x004119F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_00411A0C;
    }
    // 0x004119F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_004119FC:
    // 0x004119FC: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x00411A00: bne         $v0, $zero, L_004119D4
    if (ctx->r2 != 0) {
        // 0x00411A04: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_004119D4;
    }
    // 0x00411A04: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x00411A08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00411A0C:
    // 0x00411A0C: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x00411A10: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x00411A14: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x00411A18: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x00411A1C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x00411A20: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x00411A24: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x00411A28: jr          $ra
    // 0x00411A2C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x00411A2C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_00411A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00411A30: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x00411A34: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x00411A38: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x00411A3C: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x00411A40: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x00411A44: lbu         $v0, 0x65($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X65);
    // 0x00411A48: beq         $v0, $zero, L_00411A64
    if (ctx->r2 == 0) {
        // 0x00411A4C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_00411A64;
    }
    // 0x00411A4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00411A50: jal         0x0041203C
    // 0x00411A54: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    func_0041203C(rdram, ctx);
        goto after_0;
    // 0x00411A54: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    after_0:
    // 0x00411A58: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411A5C: bne         $v1, $zero, L_00411C08
    if (ctx->r3 != 0) {
        // 0x00411A60: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_00411C08;
    }
    // 0x00411A60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_00411A64:
    // 0x00411A64: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x00411A68: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x00411A6C: jal         0x0029B8D0
    // 0x00411A70: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_0029B8D0(rdram, ctx);
        goto after_1;
    // 0x00411A70: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x00411A74: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411A78: bne         $v1, $zero, L_00411C08
    if (ctx->r3 != 0) {
        // 0x00411A7C: addiu       $a3, $sp, 0x10
        ctx->r7 = ADD32(ctx->r29, 0X10);
            goto L_00411C08;
    }
    // 0x00411A7C: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x00411A80: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x00411A84: addiu       $a1, $sp, 0x52
    ctx->r5 = ADD32(ctx->r29, 0X52);
    // 0x00411A88: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00411A8C: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x00411A90: sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
    // 0x00411A94: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
L_00411A98:
    // 0x00411A98: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x00411A9C: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x00411AA0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x00411AA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411AA8: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x00411AAC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x00411AB0: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x00411AB4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411AB8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x00411ABC: sltiu       $v0, $a0, 0x1C
    ctx->r2 = ctx->r4 < 0X1C ? 1 : 0;
    // 0x00411AC0: bne         $v0, $zero, L_00411A98
    if (ctx->r2 != 0) {
        // 0x00411AC4: addu        $v0, $a3, $a0
        ctx->r2 = ADD32(ctx->r7, ctx->r4);
            goto L_00411A98;
    }
    // 0x00411AC4: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
    // 0x00411AC8: lhu         $v1, 0x2C($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2C);
    // 0x00411ACC: lhu         $v0, 0x50($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X50);
    // 0x00411AD0: bne         $v1, $v0, L_00411AE8
    if (ctx->r3 != ctx->r2) {
        // 0x00411AD4: addiu       $s0, $sp, 0x10
        ctx->r16 = ADD32(ctx->r29, 0X10);
            goto L_00411AE8;
    }
    // 0x00411AD4: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x00411AD8: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x00411ADC: lhu         $v0, 0x52($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X52);
    // 0x00411AE0: beq         $v1, $v0, L_00411B30
    if (ctx->r3 == ctx->r2) {
        // 0x00411AE4: nop
    
            goto L_00411B30;
    }
    // 0x00411AE4: nop

L_00411AE8:
    // 0x00411AE8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411AEC: jal         0x004118C0
    // 0x00411AF0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_004118C0(rdram, ctx);
        goto after_2;
    // 0x00411AF0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x00411AF4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411AF8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x00411AFC: bne         $v1, $v0, L_00411B28
    if (ctx->r3 != ctx->r2) {
        // 0x00411B00: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_00411B28;
    }
    // 0x00411B00: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411B04: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00411B08: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x00411B0C: jal         0x004115D8
    // 0x00411B10: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_004115D8(rdram, ctx);
        goto after_3;
    // 0x00411B10: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x00411B14: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411B18: beq         $v1, $zero, L_00411B30
    if (ctx->r3 == 0) {
        // 0x00411B1C: nop
    
            goto L_00411B30;
    }
    // 0x00411B1C: nop

    // 0x00411B20: j           L_00411C08
    // 0x00411B24: nop

        goto L_00411C08;
    // 0x00411B24: nop

L_00411B28:
    // 0x00411B28: bne         $v1, $zero, L_00411C08
    if (ctx->r3 != 0) {
        // 0x00411B2C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_00411C08;
    }
    // 0x00411B2C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_00411B30:
    // 0x00411B30: lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18);
    // 0x00411B34: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x00411B38: bne         $v0, $zero, L_00411B78
    if (ctx->r2 != 0) {
        // 0x00411B3C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00411B78;
    }
    // 0x00411B3C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00411B40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00411B44: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00411B48: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x00411B4C: jal         0x004115D8
    // 0x00411B50: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_004115D8(rdram, ctx);
        goto after_4;
    // 0x00411B50: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // 0x00411B54: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411B58: bne         $v1, $zero, L_00411C08
    if (ctx->r3 != 0) {
        // 0x00411B5C: nop
    
            goto L_00411C08;
    }
    // 0x00411B5C: nop

    // 0x00411B60: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x00411B64: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x00411B68: bne         $v0, $zero, L_00411B78
    if (ctx->r2 != 0) {
        // 0x00411B6C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00411B78;
    }
    // 0x00411B6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00411B70: j           L_00411C08
    // 0x00411B74: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_00411C08;
    // 0x00411B74: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_00411B78:
    // 0x00411B78: addu        $v1, $s1, $a0
    ctx->r3 = ADD32(ctx->r17, ctx->r4);
L_00411B7C:
    // 0x00411B7C: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x00411B80: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x00411B84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00411B88: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x00411B8C: slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x00411B90: bne         $v0, $zero, L_00411B7C
    if (ctx->r2 != 0) {
        // 0x00411B94: addu        $v1, $s1, $a0
        ctx->r3 = ADD32(ctx->r17, ctx->r4);
            goto L_00411B7C;
    }
    // 0x00411B94: addu        $v1, $s1, $a0
    ctx->r3 = ADD32(ctx->r17, ctx->r4);
    // 0x00411B98: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x00411B9C: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x00411BA0: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x00411BA4: lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1B);
    // 0x00411BA8: addiu       $a3, $s1, 0x2C
    ctx->r7 = ADD32(ctx->r17, 0X2C);
    // 0x00411BAC: sw          $v0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r2;
    // 0x00411BB0: lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1A);
    // 0x00411BB4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x00411BB8: sw          $v0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r2;
    // 0x00411BBC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x00411BC0: sw          $v0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r2;
    // 0x00411BC4: sb          $v1, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r3;
    // 0x00411BC8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x00411BCC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x00411BD0: lbu         $v0, 0x64($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X64);
    // 0x00411BD4: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x00411BD8: sw          $v1, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r3;
    // 0x00411BDC: lbu         $v1, 0x64($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X64);
    // 0x00411BE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x00411BE4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x00411BE8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x00411BEC: sw          $v0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r2;
    // 0x00411BF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411BF4: jal         0x0029B8D0
    // 0x00411BF8: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
    func_0029B8D0(rdram, ctx);
        goto after_5;
    // 0x00411BF8: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
    after_5:
    // 0x00411BFC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411C00: beql        $v1, $zero, L_00411C08
    if (ctx->r3 == 0) {
        // 0x00411C04: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_00411C08;
    }
    goto skip_0;
    // 0x00411C04: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
L_00411C08:
    // 0x00411C08: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x00411C0C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x00411C10: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x00411C14: jr          $ra
    // 0x00411C18: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x00411C18: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_00411C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00411C1C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x00411C20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x00411C24: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00411C28: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x00411C2C: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x00411C30: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x00411C34: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x00411C38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x00411C3C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x00411C40: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x00411C44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x00411C48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x00411C4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x00411C50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x00411C54: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x00411C58: beq         $v0, $zero, L_00411C74
    if (ctx->r2 == 0) {
        // 0x00411C5C: addu        $s7, $a3, $zero
        ctx->r23 = ADD32(ctx->r7, 0);
            goto L_00411C74;
    }
    // 0x00411C5C: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x00411C60: jal         0x0041203C
    // 0x00411C64: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    func_0041203C(rdram, ctx);
        goto after_0;
    // 0x00411C64: sb          $zero, 0x65($s2)
    MEM_B(0X65, ctx->r18) = 0;
    after_0:
    // 0x00411C68: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00411C6C: bne         $a0, $zero, L_00411ECC
    if (ctx->r4 != 0) {
        // 0x00411C70: nop
    
            goto L_00411ECC;
    }
    // 0x00411C70: nop

L_00411C74:
    // 0x00411C74: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x00411C78: bne         $v0, $zero, L_00411C84
    if (ctx->r2 != 0) {
        // 0x00411C7C: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_00411C84;
    }
    // 0x00411C7C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x00411C80: lw          $s4, 0x60($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X60);
L_00411C84:
    // 0x00411C84: andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // 0x00411C88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00411C8C: bne         $v1, $v0, L_00411CD8
    if (ctx->r3 != ctx->r2) {
        // 0x00411C90: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_00411CD8;
    }
    // 0x00411C90: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x00411C94: sllv        $v0, $s4, $v0
    ctx->r2 = S32(ctx->r20 << (ctx->r2 & 31));
    // 0x00411C98: addu        $a1, $v0, $s5
    ctx->r5 = ADD32(ctx->r2, ctx->r21);
    // 0x00411C9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00411CA0: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x00411CA4: subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // 0x00411CA8: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
    // 0x00411CAC: blez        $a2, L_00411CD0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x00411CB0: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_00411CD0;
    }
    // 0x00411CB0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_00411CB4:
    // 0x00411CB4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x00411CB8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x00411CBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00411CC0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x00411CC4: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x00411CC8: bne         $v0, $zero, L_00411CB4
    if (ctx->r2 != 0) {
        // 0x00411CCC: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_00411CB4;
    }
    // 0x00411CCC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_00411CD0:
    // 0x00411CD0: sb          $v1, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r3;
    // 0x00411CD4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_00411CD8:
    // 0x00411CD8: andi        $fp, $s6, 0xFF
    ctx->r30 = ctx->r22 & 0XFF;
    // 0x00411CDC: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x00411CE0: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x00411CE4: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
L_00411CE8:
    // 0x00411CE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x00411CEC: bne         $fp, $t0, L_00411D44
    if (ctx->r30 != ctx->r8) {
        // 0x00411CF0: addu        $s1, $s5, $v0
        ctx->r17 = ADD32(ctx->r21, ctx->r2);
            goto L_00411D44;
    }
    // 0x00411CF0: addu        $s1, $s5, $v0
    ctx->r17 = ADD32(ctx->r21, ctx->r2);
    // 0x00411CF4: lhu         $a2, 0x56($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X56);
    // 0x00411CF8: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x00411CFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00411D00: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411D04: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411D08: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x00411D0C: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x00411D10: jal         0x0029BC88
    // 0x00411D14: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_1;
    // 0x00411D14: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_1:
    // 0x00411D18: lhu         $a2, 0x5A($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5A);
    // 0x00411D1C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x00411D20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00411D24: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411D28: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411D2C: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x00411D30: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x00411D34: jal         0x0029BC88
    // 0x00411D38: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_2;
    // 0x00411D38: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_2:
    // 0x00411D3C: j           L_00411D68
    // 0x00411D40: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_00411D68;
    // 0x00411D40: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_00411D44:
    // 0x00411D44: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x00411D48: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411D4C: lhu         $a2, 0x56($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X56);
    // 0x00411D50: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411D54: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x00411D58: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x00411D5C: jal         0x0029B8D0
    // 0x00411D60: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_3;
    // 0x00411D60: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_3:
    // 0x00411D64: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_00411D68:
    // 0x00411D68: bne         $a0, $zero, L_00411E7C
    if (ctx->r4 != 0) {
        // 0x00411D6C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_00411E7C;
    }
    // 0x00411D6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411D70: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x00411D74: bne         $v0, $zero, L_00411CE8
    if (ctx->r2 != 0) {
        // 0x00411D78: sll         $v0, $s0, 5
        ctx->r2 = S32(ctx->r16 << 5);
            goto L_00411CE8;
    }
    // 0x00411D78: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
    // 0x00411D7C: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x00411D80: bne         $v0, $zero, L_00411ECC
    if (ctx->r2 != 0) {
        // 0x00411D84: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_00411ECC;
    }
    // 0x00411D84: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x00411D88: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x00411D8C: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x00411D90: addu        $a2, $v0, $s5
    ctx->r6 = ADD32(ctx->r2, ctx->r21);
    // 0x00411D94: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x00411D98: subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // 0x00411D9C: sll         $a3, $v0, 1
    ctx->r7 = S32(ctx->r2 << 1);
    // 0x00411DA0: slt         $v0, $a0, $a3
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x00411DA4: beq         $v0, $zero, L_00411DC8
    if (ctx->r2 == 0) {
        // 0x00411DA8: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_00411DC8;
    }
    // 0x00411DA8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_00411DAC:
    // 0x00411DAC: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x00411DB0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x00411DB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x00411DB8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x00411DBC: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x00411DC0: bne         $v0, $zero, L_00411DAC
    if (ctx->r2 != 0) {
        // 0x00411DC4: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_00411DAC;
    }
    // 0x00411DC4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_00411DC8:
    // 0x00411DC8: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
    // 0x00411DCC: lbu         $v1, 0x1($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X1);
    // 0x00411DD0: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x00411DD4: beq         $v0, $v1, L_00411E84
    if (ctx->r2 == ctx->r3) {
        // 0x00411DD8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_00411E84;
    }
    // 0x00411DD8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x00411DDC: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x00411DE0: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x00411DE4: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    // 0x00411DE8: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
L_00411DEC:
    // 0x00411DEC: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x00411DF0: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411DF4: lhu         $a2, 0x5A($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5A);
    // 0x00411DF8: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411DFC: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x00411E00: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x00411E04: jal         0x0029B8D0
    // 0x00411E08: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029B8D0(rdram, ctx);
        goto after_4;
    // 0x00411E08: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_4:
    // 0x00411E0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411E10: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x00411E14: bne         $v0, $zero, L_00411DEC
    if (ctx->r2 != 0) {
        // 0x00411E18: addu        $a3, $s1, $zero
        ctx->r7 = ADD32(ctx->r17, 0);
            goto L_00411DEC;
    }
    // 0x00411E18: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x00411E1C: lbu         $v1, 0x1($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X1);
    // 0x00411E20: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x00411E24: bne         $v0, $v1, L_00411ECC
    if (ctx->r2 != ctx->r3) {
        // 0x00411E28: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_00411ECC;
    }
    // 0x00411E28: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00411E2C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x00411E30: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x00411E34: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x00411E38: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    // 0x00411E3C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
L_00411E40:
    // 0x00411E40: lhu         $a2, 0x56($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X56);
    // 0x00411E44: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x00411E48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00411E4C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411E50: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411E54: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x00411E58: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x00411E5C: jal         0x0029BC88
    // 0x00411E60: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_5;
    // 0x00411E60: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_5:
    // 0x00411E64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411E68: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x00411E6C: bne         $v0, $zero, L_00411E40
    if (ctx->r2 != 0) {
        // 0x00411E70: addu        $a3, $s1, $zero
        ctx->r7 = ADD32(ctx->r17, 0);
            goto L_00411E40;
    }
    // 0x00411E70: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x00411E74: j           L_00411ECC
    // 0x00411E78: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_00411ECC;
    // 0x00411E78: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00411E7C:
    // 0x00411E7C: j           L_00411ECC
    // 0x00411E80: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
        goto L_00411ECC;
    // 0x00411E80: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_00411E84:
    // 0x00411E84: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x00411E88: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x00411E8C: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    // 0x00411E90: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
L_00411E94:
    // 0x00411E94: lhu         $a2, 0x5A($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X5A);
    // 0x00411E98: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x00411E9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00411EA0: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x00411EA4: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x00411EA8: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x00411EAC: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x00411EB0: jal         0x0029BC88
    // 0x00411EB4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_0029BC88(rdram, ctx);
        goto after_6;
    // 0x00411EB4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_6:
    // 0x00411EB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00411EBC: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x00411EC0: bne         $v0, $zero, L_00411E94
    if (ctx->r2 != 0) {
        // 0x00411EC4: addu        $a3, $s1, $zero
        ctx->r7 = ADD32(ctx->r17, 0);
            goto L_00411E94;
    }
    // 0x00411EC4: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x00411EC8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00411ECC:
    // 0x00411ECC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x00411ED0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x00411ED4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x00411ED8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x00411EDC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x00411EE0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x00411EE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x00411EE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x00411EEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x00411EF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x00411EF4: jr          $ra
    // 0x00411EF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x00411EF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_00411EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00411EFC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00411F00: blez        $a1, L_00411F24
    if (SIGNED(ctx->r5) <= 0) {
        // 0x00411F04: addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
            goto L_00411F24;
    }
    // 0x00411F04: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_00411F08:
    // 0x00411F08: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x00411F0C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00411F10: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x00411F14: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x00411F18: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x00411F1C: bne         $v0, $zero, L_00411F08
    if (ctx->r2 != 0) {
        // 0x00411F20: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_00411F08;
    }
    // 0x00411F20: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_00411F24:
    // 0x00411F24: jr          $ra
    // 0x00411F28: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // 0x00411F28: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
;}
RECOMP_FUNC void func_00411F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00411F2C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x00411F30: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x00411F34: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x00411F38: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
L_00411F3C:
    // 0x00411F3C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x00411F40: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x00411F44: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x00411F48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411F4C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x00411F50: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x00411F54: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x00411F58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x00411F5C: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x00411F60: sltiu       $v0, $a3, 0x1C
    ctx->r2 = ctx->r7 < 0X1C ? 1 : 0;
    // 0x00411F64: bne         $v0, $zero, L_00411F3C
    if (ctx->r2 != 0) {
        // 0x00411F68: addu        $v0, $a0, $a3
        ctx->r2 = ADD32(ctx->r4, ctx->r7);
            goto L_00411F3C;
    }
    // 0x00411F68: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x00411F6C: jr          $ra
    // 0x00411F70: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x00411F70: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_00411F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00411F74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x00411F78: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x00411F7C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00411F80: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x00411F84: lbu         $v0, 0x65($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X65);
    // 0x00411F88: beq         $v0, $zero, L_00411FA8
    if (ctx->r2 == 0) {
        // 0x00411F8C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_00411FA8;
    }
    // 0x00411F8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00411F90: jal         0x0041203C
    // 0x00411F94: sb          $zero, 0x65($s0)
    MEM_B(0X65, ctx->r16) = 0;
    func_0041203C(rdram, ctx);
        goto after_0;
    // 0x00411F94: sb          $zero, 0x65($s0)
    MEM_B(0X65, ctx->r16) = 0;
    after_0:
    // 0x00411F98: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411F9C: bne         $v1, $zero, L_0041202C
    if (ctx->r3 != 0) {
        // 0x00411FA0: nop
    
            goto L_0041202C;
    }
    // 0x00411FA0: nop

    // 0x00411FA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_00411FA8:
    // 0x00411FA8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x00411FAC: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x00411FB0: jal         0x0029B8D0
    // 0x00411FB4: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_0029B8D0(rdram, ctx);
        goto after_1;
    // 0x00411FB4: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x00411FB8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411FBC: beq         $v1, $zero, L_00411FFC
    if (ctx->r3 == 0) {
        // 0x00411FC0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00411FFC;
    }
    // 0x00411FC0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00411FC4: bne         $v1, $v0, L_0041202C
    if (ctx->r3 != ctx->r2) {
        // 0x00411FC8: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_0041202C;
    }
    // 0x00411FC8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x00411FCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00411FD0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x00411FD4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x00411FD8: jal         0x0029B8D0
    // 0x00411FDC: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_0029B8D0(rdram, ctx);
        goto after_2;
    // 0x00411FDC: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x00411FE0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00411FE4: beq         $v1, $zero, L_00412000
    if (ctx->r3 == 0) {
        // 0x00411FE8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_00412000;
    }
    // 0x00411FE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00411FEC: j           L_0041202C
    // 0x00411FF0: nop

        goto L_0041202C;
    // 0x00411FF0: nop

L_00411FF4:
    // 0x00411FF4: j           L_0041202C
    // 0x00411FF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_0041202C;
    // 0x00411FF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_00411FFC:
    // 0x00411FFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_00412000:
    // 0x00412000: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x00412004: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
L_00412008:
    // 0x00412008: addu        $v1, $a2, $a1
    ctx->r3 = ADD32(ctx->r6, ctx->r5);
    // 0x0041200C: lbu         $a0, 0xC($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XC);
    // 0x00412010: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x00412014: bne         $a0, $v0, L_00411FF4
    if (ctx->r4 != ctx->r2) {
        // 0x00412018: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_00411FF4;
    }
    // 0x00412018: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x0041201C: slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x00412020: bne         $v0, $zero, L_00412008
    if (ctx->r2 != 0) {
        // 0x00412024: addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
            goto L_00412008;
    }
    // 0x00412024: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x00412028: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_0041202C:
    // 0x0041202C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x00412030: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x00412034: jr          $ra
    // 0x00412038: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x00412038: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_0041203C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0041203C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x00412040: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x00412044: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x00412048: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041204C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x00412050: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
L_00412054:
    // 0x00412054: lbu         $v0, 0x65($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X65);
    // 0x00412058: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x0041205C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x00412060: slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x00412064: bne         $v0, $zero, L_00412054
    if (ctx->r2 != 0) {
        // 0x00412068: addu        $v1, $a1, $a0
        ctx->r3 = ADD32(ctx->r5, ctx->r4);
            goto L_00412054;
    }
    // 0x00412068: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x0041206C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x00412070: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00412074: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x00412078: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x0041207C: jal         0x0029BC88
    // 0x00412080: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_0029BC88(rdram, ctx);
        goto after_0;
    // 0x00412080: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x00412084: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x00412088: jr          $ra
    // 0x0041208C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x0041208C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_00412090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00412090: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x00412094: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x00412098: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x0041209C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x004120A0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x004120A4: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x004120A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x004120AC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x004120B0: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x004120B4: jal         0x0020557C
    // 0x004120B8: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    func_0020557C(rdram, ctx);
        goto after_0;
    // 0x004120B8: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    after_0:
    // 0x004120BC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x004120C0: addiu       $a0, $a0, -0x41B8
    ctx->r4 = ADD32(ctx->r4, -0X41B8);
    // 0x004120C4: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x004120C8: sw          $zero, 0x8($s3)
    MEM_W(0X8, ctx->r19) = 0;
    // 0x004120CC: sw          $s2, 0x1774($s3)
    MEM_W(0X1774, ctx->r19) = ctx->r18;
    // 0x004120D0: sw          $zero, 0xC($s3)
    MEM_W(0XC, ctx->r19) = 0;
    // 0x004120D4: sw          $zero, 0x1778($s3)
    MEM_W(0X1778, ctx->r19) = 0;
    // 0x004120D8: sw          $zero, 0x177C($s3)
    MEM_W(0X177C, ctx->r19) = 0;
    // 0x004120DC: sw          $zero, 0x1780($s3)
    MEM_W(0X1780, ctx->r19) = 0;
    // 0x004120E0: sw          $zero, 0x1784($s3)
    MEM_W(0X1784, ctx->r19) = 0;
    // 0x004120E4: sw          $zero, 0x1788($s3)
    MEM_W(0X1788, ctx->r19) = 0;
    // 0x004120E8: jal         0x002354A8
    // 0x004120EC: sw          $zero, 0x1760($s3)
    MEM_W(0X1760, ctx->r19) = 0;
    func_002354A8(rdram, ctx);
        goto after_1;
    // 0x004120EC: sw          $zero, 0x1760($s3)
    MEM_W(0X1760, ctx->r19) = 0;
    after_1:
    // 0x004120F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004120F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x004120F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x004120FC: lwc1        $f1, 0x7424($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X7424);
    // 0x00412100: addiu       $v0, $s3, 0x1764
    ctx->r2 = ADD32(ctx->r19, 0X1764);
    // 0x00412104: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x00412108: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x0041210C: swc1        $f0, 0x1764($s3)
    MEM_W(0X1764, ctx->r19) = ctx->f0.u32l;
    // 0x00412110: jal         0x002218C0
    // 0x00412114: swc1        $f1, 0x1770($s3)
    MEM_W(0X1770, ctx->r19) = ctx->f_odd[(1 - 1) * 2];
    func_002218C0(rdram, ctx);
        goto after_2;
    // 0x00412114: swc1        $f1, 0x1770($s3)
    MEM_W(0X1770, ctx->r19) = ctx->f_odd[(1 - 1) * 2];
    after_2:
    // 0x00412118: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041211C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x00412120: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x00412124: addiu       $a3, $a3, 0x72F4
    ctx->r7 = ADD32(ctx->r7, 0X72F4);
    // 0x00412128: jal         0x002220AC
    // 0x0041212C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_002220AC(rdram, ctx);
        goto after_3;
    // 0x0041212C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x00412130: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412134: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x00412138: jal         0x00210A00
    // 0x0041213C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_00210A00(rdram, ctx);
        goto after_4;
    // 0x0041213C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
    // 0x00412140: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412144: addiu       $a1, $s3, 0x38
    ctx->r5 = ADD32(ctx->r19, 0X38);
    // 0x00412148: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x0041214C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x00412150: addiu       $a3, $a3, 0x7304
    ctx->r7 = ADD32(ctx->r7, 0X7304);
    // 0x00412154: jal         0x002220AC
    // 0x00412158: sw          $a2, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r6;
    func_002220AC(rdram, ctx);
        goto after_5;
    // 0x00412158: sw          $a2, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r6;
    after_5:
    // 0x0041215C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412160: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x00412164: jal         0x00210A00
    // 0x00412168: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_00210A00(rdram, ctx);
        goto after_6;
    // 0x00412168: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x0041216C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412170: addiu       $a1, $s3, 0x3C
    ctx->r5 = ADD32(ctx->r19, 0X3C);
    // 0x00412174: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x00412178: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x0041217C: addiu       $a3, $a3, 0x7314
    ctx->r7 = ADD32(ctx->r7, 0X7314);
    // 0x00412180: jal         0x002220AC
    // 0x00412184: sw          $a2, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r6;
    func_002220AC(rdram, ctx);
        goto after_7;
    // 0x00412184: sw          $a2, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r6;
    after_7:
    // 0x00412188: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041218C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x00412190: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x00412194: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x00412198: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x0041219C: addiu       $s1, $s1, 0x7328
    ctx->r17 = ADD32(ctx->r17, 0X7328);
    // 0x004121A0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x004121A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x004121A8: jal         0x00222224
    // 0x004121AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_00222224(rdram, ctx);
        goto after_8;
    // 0x004121AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_8:
    // 0x004121B0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x004121B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x004121B8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x004121BC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x004121C0: jal         0x00210A00
    // 0x004121C4: sw          $v0, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->r2;
    func_00210A00(rdram, ctx);
        goto after_9;
    // 0x004121C4: sw          $v0, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->r2;
    after_9:
    // 0x004121C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004121CC: addiu       $a1, $s3, 0x40
    ctx->r5 = ADD32(ctx->r19, 0X40);
    // 0x004121D0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x004121D4: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x004121D8: addiu       $a3, $a3, 0x7338
    ctx->r7 = ADD32(ctx->r7, 0X7338);
    // 0x004121DC: jal         0x002220AC
    // 0x004121E0: sw          $a2, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r6;
    func_002220AC(rdram, ctx);
        goto after_10;
    // 0x004121E0: sw          $a2, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r6;
    after_10:
    // 0x004121E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004121E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x004121EC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x004121F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x004121F4: lui         $v0, 0x41
    ctx->r2 = S32(0X41 << 16);
    // 0x004121F8: addiu       $v0, $v0, 0x47AC
    ctx->r2 = ADD32(ctx->r2, 0X47AC);
    // 0x004121FC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x00412200: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412204: addiu       $v0, $v0, 0x7348
    ctx->r2 = ADD32(ctx->r2, 0X7348);
    // 0x00412208: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x0041220C: jal         0x00222224
    // 0x00412210: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_11;
    // 0x00412210: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_11:
    // 0x00412214: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412218: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x0041221C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x00412220: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00412224: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x00412228: sw          $v0, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->r2;
    // 0x0041222C: lui         $v0, 0x41
    ctx->r2 = S32(0X41 << 16);
    // 0x00412230: addiu       $v0, $v0, 0x467C
    ctx->r2 = ADD32(ctx->r2, 0X467C);
    // 0x00412234: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x00412238: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x0041223C: addiu       $v0, $v0, 0x7358
    ctx->r2 = ADD32(ctx->r2, 0X7358);
    // 0x00412240: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x00412244: jal         0x00222224
    // 0x00412248: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_12;
    // 0x00412248: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_12:
    // 0x0041224C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412250: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x00412254: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x00412258: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x0041225C: sw          $v0, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r2;
    // 0x00412260: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x00412264: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00412268: jal         0x00222224
    // 0x0041226C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_00222224(rdram, ctx);
        goto after_13;
    // 0x0041226C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_13:
    // 0x00412270: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x00412278: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x0041227C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x00412280: jal         0x00210A00
    // 0x00412284: sw          $v0, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->r2;
    func_00210A00(rdram, ctx);
        goto after_14;
    // 0x00412284: sw          $v0, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->r2;
    after_14:
    // 0x00412288: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041228C: addiu       $a1, $s3, 0x48
    ctx->r5 = ADD32(ctx->r19, 0X48);
    // 0x00412290: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x00412294: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x00412298: addiu       $a3, $a3, 0x736C
    ctx->r7 = ADD32(ctx->r7, 0X736C);
    // 0x0041229C: jal         0x002220AC
    // 0x004122A0: sw          $a2, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r6;
    func_002220AC(rdram, ctx);
        goto after_15;
    // 0x004122A0: sw          $a2, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r6;
    after_15:
    // 0x004122A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004122A8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x004122AC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x004122B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x004122B4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x004122B8: addiu       $v0, $v0, 0x737C
    ctx->r2 = ADD32(ctx->r2, 0X737C);
    // 0x004122BC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x004122C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x004122C4: jal         0x00222224
    // 0x004122C8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_16;
    // 0x004122C8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_16:
    // 0x004122CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004122D0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x004122D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x004122D8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x004122DC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x004122E0: sw          $v0, 0x60($s3)
    MEM_W(0X60, ctx->r19) = ctx->r2;
    // 0x004122E4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x004122E8: addiu       $v0, $v0, 0x7388
    ctx->r2 = ADD32(ctx->r2, 0X7388);
    // 0x004122EC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x004122F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x004122F4: jal         0x00222224
    // 0x004122F8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_17;
    // 0x004122F8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_17:
    // 0x004122FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412300: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x00412304: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x00412308: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x0041230C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x00412310: sw          $v0, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->r2;
    // 0x00412314: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412318: addiu       $v0, $v0, 0x739C
    ctx->r2 = ADD32(ctx->r2, 0X739C);
    // 0x0041231C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x00412320: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00412324: jal         0x00222224
    // 0x00412328: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_18;
    // 0x00412328: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_18:
    // 0x0041232C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412330: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x00412334: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x00412338: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x0041233C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x00412340: sw          $v0, 0x84($s3)
    MEM_W(0X84, ctx->r19) = ctx->r2;
    // 0x00412344: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412348: addiu       $v0, $v0, 0x73AC
    ctx->r2 = ADD32(ctx->r2, 0X73AC);
    // 0x0041234C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x00412350: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00412354: jal         0x00222224
    // 0x00412358: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_19;
    // 0x00412358: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_19:
    // 0x0041235C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412360: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x00412364: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x00412368: sw          $v0, 0xD4($s3)
    MEM_W(0XD4, ctx->r19) = ctx->r2;
    // 0x0041236C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00412370: addiu       $a3, $s3, 0x34
    ctx->r7 = ADD32(ctx->r19, 0X34);
    // 0x00412374: jal         0x00210A14
    // 0x00412378: sw          $v0, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->r2;
    func_00210A14(rdram, ctx);
        goto after_20;
    // 0x00412378: sw          $v0, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->r2;
    after_20:
    // 0x0041237C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412380: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x00412384: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x00412388: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x0041238C: lui         $s1, 0x22
    ctx->r17 = S32(0X22 << 16);
    // 0x00412390: addiu       $s1, $s1, 0x2E28
    ctx->r17 = ADD32(ctx->r17, 0X2E28);
    // 0x00412394: sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
    // 0x00412398: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x0041239C: addiu       $v0, $v0, 0x73BC
    ctx->r2 = ADD32(ctx->r2, 0X73BC);
    // 0x004123A0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x004123A4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x004123A8: jal         0x00222224
    // 0x004123AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_21;
    // 0x004123AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_21:
    // 0x004123B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004123B4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x004123B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x004123BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x004123C0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x004123C4: sw          $v0, 0x88($s3)
    MEM_W(0X88, ctx->r19) = ctx->r2;
    // 0x004123C8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x004123CC: addiu       $v0, $v0, 0x73C4
    ctx->r2 = ADD32(ctx->r2, 0X73C4);
    // 0x004123D0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x004123D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x004123D8: jal         0x00222224
    // 0x004123DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_22;
    // 0x004123DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_22:
    // 0x004123E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004123E4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x004123E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x004123EC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x004123F0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x004123F4: sw          $v0, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->r2;
    // 0x004123F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x004123FC: addiu       $v0, $v0, 0x73CC
    ctx->r2 = ADD32(ctx->r2, 0X73CC);
    // 0x00412400: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x00412404: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00412408: jal         0x00222224
    // 0x0041240C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_23;
    // 0x0041240C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_23:
    // 0x00412410: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412414: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x00412418: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x0041241C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00412420: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x00412424: sw          $v0, 0x8C($s3)
    MEM_W(0X8C, ctx->r19) = ctx->r2;
    // 0x00412428: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x0041242C: addiu       $v0, $v0, 0x73DC
    ctx->r2 = ADD32(ctx->r2, 0X73DC);
    // 0x00412430: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x00412434: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00412438: jal         0x00222224
    // 0x0041243C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_00222224(rdram, ctx);
        goto after_24;
    // 0x0041243C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_24:
    // 0x00412440: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x00412448: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x0041244C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x00412450: jal         0x00210A00
    // 0x00412454: sw          $v0, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->r2;
    func_00210A00(rdram, ctx);
        goto after_25;
    // 0x00412454: sw          $v0, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->r2;
    after_25:
    // 0x00412458: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041245C: addiu       $a1, $s3, 0x4C
    ctx->r5 = ADD32(ctx->r19, 0X4C);
    // 0x00412460: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x00412464: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x00412468: addiu       $a3, $a3, 0x73EC
    ctx->r7 = ADD32(ctx->r7, 0X73EC);
    // 0x0041246C: jal         0x002220AC
    // 0x00412470: sw          $a2, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r6;
    func_002220AC(rdram, ctx);
        goto after_26;
    // 0x00412470: sw          $a2, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r6;
    after_26:
    // 0x00412474: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412478: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x0041247C: jal         0x00210A00
    // 0x00412480: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    func_00210A00(rdram, ctx);
        goto after_27;
    // 0x00412480: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_27:
    // 0x00412484: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412488: addiu       $a1, $s3, 0x68
    ctx->r5 = ADD32(ctx->r19, 0X68);
    // 0x0041248C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x00412490: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x00412494: addiu       $a3, $a3, 0x7400
    ctx->r7 = ADD32(ctx->r7, 0X7400);
    // 0x00412498: jal         0x002220AC
    // 0x0041249C: sw          $a2, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->r6;
    func_002220AC(rdram, ctx);
        goto after_28;
    // 0x0041249C: sw          $a2, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->r6;
    after_28:
    // 0x004124A0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x004124A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x004124A8: jal         0x00210A00
    // 0x004124AC: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    func_00210A00(rdram, ctx);
        goto after_29;
    // 0x004124AC: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_29:
    // 0x004124B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004124B4: addiu       $a1, $s3, 0x70
    ctx->r5 = ADD32(ctx->r19, 0X70);
    // 0x004124B8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x004124BC: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x004124C0: addiu       $a3, $a3, 0x7410
    ctx->r7 = ADD32(ctx->r7, 0X7410);
    // 0x004124C4: jal         0x002220AC
    // 0x004124C8: sw          $a2, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r6;
    func_002220AC(rdram, ctx);
        goto after_30;
    // 0x004124C8: sw          $a2, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r6;
    after_30:
    // 0x004124CC: jal         0x00256698
    // 0x004124D0: addiu       $a0, $s3, 0x167C
    ctx->r4 = ADD32(ctx->r19, 0X167C);
    func_00256698(rdram, ctx);
        goto after_31;
    // 0x004124D0: addiu       $a0, $s3, 0x167C
    ctx->r4 = ADD32(ctx->r19, 0X167C);
    after_31:
    // 0x004124D4: jal         0x002596EC
    // 0x004124D8: addiu       $a0, $s3, 0x16EC
    ctx->r4 = ADD32(ctx->r19, 0X16EC);
    func_002596EC(rdram, ctx);
        goto after_32;
    // 0x004124D8: addiu       $a0, $s3, 0x16EC
    ctx->r4 = ADD32(ctx->r19, 0X16EC);
    after_32:
    // 0x004124DC: jal         0x0025A2D8
    // 0x004124E0: addiu       $a0, $s3, 0x171C
    ctx->r4 = ADD32(ctx->r19, 0X171C);
    func_0025A2D8(rdram, ctx);
        goto after_33;
    // 0x004124E0: addiu       $a0, $s3, 0x171C
    ctx->r4 = ADD32(ctx->r19, 0X171C);
    after_33:
    // 0x004124E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x004124E8: addiu       $a0, $a0, 0x6BC0
    ctx->r4 = ADD32(ctx->r4, 0X6BC0);
    // 0x004124EC: jal         0x0023D2FC
    // 0x004124F0: nop

    func_0023D2FC(rdram, ctx);
        goto after_34;
    // 0x004124F0: nop

    after_34:
    // 0x004124F4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x004124F8: jal         0x00414228
    // 0x004124FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_00414228(rdram, ctx);
        goto after_35;
    // 0x004124FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_35:
    // 0x00412500: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00412504: addiu       $a1, $zero, 0x1838
    ctx->r5 = ADD32(0, 0X1838);
    // 0x00412508: jal         0x00203A8C
    // 0x0041250C: addiu       $s0, $s3, 0x18B4
    ctx->r16 = ADD32(ctx->r19, 0X18B4);
    func_00203A8C(rdram, ctx);
        goto after_36;
    // 0x0041250C: addiu       $s0, $s3, 0x18B4
    ctx->r16 = ADD32(ctx->r19, 0X18B4);
    after_36:
    // 0x00412510: bne         $v0, $s2, L_00412520
    if (ctx->r2 != ctx->r18) {
        // 0x00412514: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_00412520;
    }
    // 0x00412514: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00412518: j           L_0041263C
    // 0x0041251C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
        goto L_0041263C;
    // 0x0041251C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_00412520:
    // 0x00412520: jal         0x00204850
    // 0x00412524: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_00204850(rdram, ctx);
        goto after_37;
    // 0x00412524: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_37:
    // 0x00412528: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041252C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00412530: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412534: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x00412538: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x0041253C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412540: addiu       $v0, $v0, 0x72D8
    ctx->r2 = ADD32(ctx->r2, 0X72D8);
    // 0x00412544: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x00412548: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0041254C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00412550: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412554: jal         0x0021FB70
    // 0x00412558: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    func_0021FB70(rdram, ctx);
        goto after_38;
    // 0x00412558: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_38:
    // 0x0041255C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x00412560: beq         $s1, $zero, L_00412638
    if (ctx->r17 == 0) {
        // 0x00412564: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_00412638;
    }
    // 0x00412564: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412568: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x0041256C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x00412570: jal         0x00210A14
    // 0x00412574: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_00210A14(rdram, ctx);
        goto after_39;
    // 0x00412574: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_39:
    // 0x00412578: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041257C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x00412580: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x00412584: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x00412588: lui         $v0, 0x21
    ctx->r2 = S32(0X21 << 16);
    // 0x0041258C: addiu       $v0, $v0, -0x2A60
    ctx->r2 = ADD32(ctx->r2, -0X2A60);
    // 0x00412590: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x00412594: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412598: addiu       $v0, $v0, 0x72E8
    ctx->r2 = ADD32(ctx->r2, 0X72E8);
    // 0x0041259C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x004125A0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x004125A4: jal         0x0021FB70
    // 0x004125A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    func_0021FB70(rdram, ctx);
        goto after_40;
    // 0x004125A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_40:
    // 0x004125AC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x004125B0: beq         $s0, $zero, L_00412630
    if (ctx->r16 == 0) {
        // 0x004125B4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00412630;
    }
    // 0x004125B4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004125B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x004125BC: jal         0x0021098C
    // 0x004125C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_0021098C(rdram, ctx);
        goto after_41;
    // 0x004125C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_41:
    // 0x004125C4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x004125C8: jal         0x0021098C
    // 0x004125CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_42;
    // 0x004125CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_42:
    // 0x004125D0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x004125D4: jal         0x0021098C
    // 0x004125D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_43;
    // 0x004125D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_43:
    // 0x004125DC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x004125E0: jal         0x0021098C
    // 0x004125E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_44;
    // 0x004125E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_44:
    // 0x004125E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004125EC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x004125F0: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x004125F4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x004125F8: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x004125FC: sw          $v1, 0x18B4($s3)
    MEM_W(0X18B4, ctx->r19) = ctx->r3;
    // 0x00412600: sw          $t0, 0x18B8($s3)
    MEM_W(0X18B8, ctx->r19) = ctx->r8;
    // 0x00412604: sw          $t1, 0x18BC($s3)
    MEM_W(0X18BC, ctx->r19) = ctx->r9;
    // 0x00412608: sw          $t2, 0x18C0($s3)
    MEM_W(0X18C0, ctx->r19) = ctx->r10;
    // 0x0041260C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x00412610: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x00412614: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x00412618: sw          $v1, 0x18C4($s3)
    MEM_W(0X18C4, ctx->r19) = ctx->r3;
    // 0x0041261C: sw          $t0, 0x18C8($s3)
    MEM_W(0X18C8, ctx->r19) = ctx->r8;
    // 0x00412620: sw          $t1, 0x18CC($s3)
    MEM_W(0X18CC, ctx->r19) = ctx->r9;
    // 0x00412624: jal         0x002217F0
    // 0x00412628: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_002217F0(rdram, ctx);
        goto after_45;
    // 0x00412628: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_45:
    // 0x0041262C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_00412630:
    // 0x00412630: jal         0x002217F0
    // 0x00412634: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_002217F0(rdram, ctx);
        goto after_46;
    // 0x00412634: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_46:
L_00412638:
    // 0x00412638: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_0041263C:
    // 0x0041263C: addiu       $a1, $zero, 0x183A
    ctx->r5 = ADD32(0, 0X183A);
    // 0x00412640: jal         0x00203A8C
    // 0x00412644: addiu       $s0, $s3, 0x18D0
    ctx->r16 = ADD32(ctx->r19, 0X18D0);
    func_00203A8C(rdram, ctx);
        goto after_47;
    // 0x00412644: addiu       $s0, $s3, 0x18D0
    ctx->r16 = ADD32(ctx->r19, 0X18D0);
    after_47:
    // 0x00412648: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x0041264C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00412650: bne         $a1, $v0, L_00412660
    if (ctx->r5 != ctx->r2) {
        // 0x00412654: nop
    
            goto L_00412660;
    }
    // 0x00412654: nop

    // 0x00412658: j           L_00412778
    // 0x0041265C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
        goto L_00412778;
    // 0x0041265C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_00412660:
    // 0x00412660: jal         0x00204850
    // 0x00412664: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_00204850(rdram, ctx);
        goto after_48;
    // 0x00412664: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_48:
    // 0x00412668: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041266C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00412670: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412674: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x00412678: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x0041267C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412680: addiu       $v0, $v0, 0x72D8
    ctx->r2 = ADD32(ctx->r2, 0X72D8);
    // 0x00412684: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x00412688: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x0041268C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00412690: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412694: jal         0x0021FB70
    // 0x00412698: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    func_0021FB70(rdram, ctx);
        goto after_49;
    // 0x00412698: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_49:
    // 0x0041269C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x004126A0: beq         $s1, $zero, L_00412778
    if (ctx->r17 == 0) {
        // 0x004126A4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_00412778;
    }
    // 0x004126A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x004126A8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x004126AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x004126B0: jal         0x00210A14
    // 0x004126B4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_00210A14(rdram, ctx);
        goto after_50;
    // 0x004126B4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_50:
    // 0x004126B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004126BC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x004126C0: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x004126C4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x004126C8: lui         $v0, 0x21
    ctx->r2 = S32(0X21 << 16);
    // 0x004126CC: addiu       $v0, $v0, -0x2A60
    ctx->r2 = ADD32(ctx->r2, -0X2A60);
    // 0x004126D0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x004126D4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x004126D8: addiu       $v0, $v0, 0x72E8
    ctx->r2 = ADD32(ctx->r2, 0X72E8);
    // 0x004126DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x004126E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x004126E4: jal         0x0021FB70
    // 0x004126E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    func_0021FB70(rdram, ctx);
        goto after_51;
    // 0x004126E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_51:
    // 0x004126EC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x004126F0: beq         $s0, $zero, L_00412770
    if (ctx->r16 == 0) {
        // 0x004126F4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00412770;
    }
    // 0x004126F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004126F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x004126FC: jal         0x0021098C
    // 0x00412700: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_0021098C(rdram, ctx);
        goto after_52;
    // 0x00412700: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_52:
    // 0x00412704: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00412708: jal         0x0021098C
    // 0x0041270C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_53;
    // 0x0041270C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_53:
    // 0x00412710: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00412714: jal         0x0021098C
    // 0x00412718: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_54;
    // 0x00412718: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_54:
    // 0x0041271C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00412720: jal         0x0021098C
    // 0x00412724: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_55;
    // 0x00412724: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_55:
    // 0x00412728: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041272C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x00412730: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x00412734: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x00412738: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x0041273C: sw          $v1, 0x18D0($s3)
    MEM_W(0X18D0, ctx->r19) = ctx->r3;
    // 0x00412740: sw          $t0, 0x18D4($s3)
    MEM_W(0X18D4, ctx->r19) = ctx->r8;
    // 0x00412744: sw          $t1, 0x18D8($s3)
    MEM_W(0X18D8, ctx->r19) = ctx->r9;
    // 0x00412748: sw          $t2, 0x18DC($s3)
    MEM_W(0X18DC, ctx->r19) = ctx->r10;
    // 0x0041274C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x00412750: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x00412754: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x00412758: sw          $v1, 0x18E0($s3)
    MEM_W(0X18E0, ctx->r19) = ctx->r3;
    // 0x0041275C: sw          $t0, 0x18E4($s3)
    MEM_W(0X18E4, ctx->r19) = ctx->r8;
    // 0x00412760: sw          $t1, 0x18E8($s3)
    MEM_W(0X18E8, ctx->r19) = ctx->r9;
    // 0x00412764: jal         0x002217F0
    // 0x00412768: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_002217F0(rdram, ctx);
        goto after_56;
    // 0x00412768: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_56:
    // 0x0041276C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_00412770:
    // 0x00412770: jal         0x002217F0
    // 0x00412774: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_002217F0(rdram, ctx);
        goto after_57;
    // 0x00412774: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_57:
L_00412778:
    // 0x00412778: jal         0x00284870
    // 0x0041277C: nop

    func_00284870(rdram, ctx);
        goto after_58;
    // 0x0041277C: nop

    after_58:
    // 0x00412780: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00412784: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00412788: jal         0x00412C40
    // 0x0041278C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_00412C40(rdram, ctx);
        goto after_59;
    // 0x0041278C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_59:
    // 0x00412790: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x00412794: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x00412798: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x0041279C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x004127A0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x004127A4: jr          $ra
    // 0x004127A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x004127A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_004127AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004127AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x004127B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x004127B4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x004127B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004127BC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x004127C0: addiu       $a1, $a1, 0xFD0
    ctx->r5 = ADD32(ctx->r5, 0XFD0);
    // 0x004127C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_004127C8:
    // 0x004127C8: lw          $v0, 0x174C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174C);
    // 0x004127CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x004127D0: lbu         $v0, 0xD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XD);
    // 0x004127D4: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x004127D8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x004127DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x004127E0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x004127E4: sb          $v0, 0xFD4($at)
    MEM_B(0XFD4, ctx->r1) = ctx->r2;
    // 0x004127E8: lw          $v0, 0x174C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174C);
    // 0x004127EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x004127F0: lbu         $v0, 0xA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XA);
    // 0x004127F4: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // 0x004127F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x004127FC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x00412800: sb          $v0, 0xFDC($at)
    MEM_B(0XFDC, ctx->r1) = ctx->r2;
    // 0x00412804: lw          $v0, 0x174C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174C);
    // 0x00412808: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x0041280C: lbu         $v0, 0x11($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X11);
    // 0x00412810: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00412814: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x00412818: sb          $v0, 0xFE0($at)
    MEM_B(0XFE0, ctx->r1) = ctx->r2;
    // 0x0041281C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00412820: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x00412824: bne         $v0, $zero, L_004127C8
    if (ctx->r2 != 0) {
        // 0x00412828: nop
    
            goto L_004127C8;
    }
    // 0x00412828: nop

    // 0x0041282C: lw          $v0, 0x174C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174C);
    // 0x00412830: lb          $v0, 0x11($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X11);
    // 0x00412834: mtc1        $v0, $f12
    ctx->f12.u32l = ctx->r2;
    // 0x00412838: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x0041283C: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x00412840: lw          $v0, 0x174C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174C);
    // 0x00412844: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x00412848: lb          $v0, 0x12($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X12);
    // 0x0041284C: mtc1        $v0, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r2;
    // 0x00412850: cvt.s.w     $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    ctx->f1.fl = CVT_S_W(ctx->f_odd[(1 - 1) * 2]);
    // 0x00412854: swc1        $f1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x00412858: lw          $v0, 0x174C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174C);
    // 0x0041285C: mul.s       $f1, $f1, $f1
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f1.fl);
    // 0x00412860: lb          $v0, 0x13($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X13);
    // 0x00412864: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x00412868: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x0041286C: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x00412870: add.s       $f12, $f12, $f1
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f1.fl;
    // 0x00412874: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x00412878: jal         0x0029A6F0
    // 0x0041287C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_0029A6F0(rdram, ctx);
        goto after_0;
    // 0x0041287C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x00412880: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x00412884: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x00412888: c.eq.s      $f2, $f1
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 1);
    c1cs = ctx->f2.fl == ctx->f1.fl;
    // 0x0041288C: nop

    // 0x00412890: bc1t        L_004128E0
    if (c1cs) {
        // 0x00412894: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_004128E0;
    }
    // 0x00412894: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x00412898: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x0041289C: lwc1        $f0, 0x7440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7440);
    // 0x004128A0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x004128A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x004128A8: jal         0x002130A8
    // 0x004128AC: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    func_002130A8(rdram, ctx);
        goto after_1;
    // 0x004128AC: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_1:
    // 0x004128B0: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x004128B4: trunc.w.s   $f3, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f0.fl);
    // 0x004128B8: mfc1        $v0, $f3
    ctx->r2 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x004128BC: sh          $v0, 0x1750($s0)
    MEM_H(0X1750, ctx->r16) = ctx->r2;
    // 0x004128C0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x004128C4: trunc.w.s   $f3, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f0.fl);
    // 0x004128C8: mfc1        $v0, $f3
    ctx->r2 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x004128CC: sh          $v0, 0x1752($s0)
    MEM_H(0X1752, ctx->r16) = ctx->r2;
    // 0x004128D0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x004128D4: trunc.w.s   $f3, $f0
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 0);
    ctx->f_odd[(3 - 1) * 2] = TRUNC_W_S(ctx->f0.fl);
    // 0x004128D8: mfc1        $v0, $f3
    ctx->r2 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x004128DC: sh          $v0, 0x1754($s0)
    MEM_H(0X1754, ctx->r16) = ctx->r2;
L_004128E0:
    // 0x004128E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x004128E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x004128E8: jr          $ra
    // 0x004128EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x004128EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_004128F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004128F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x004128F4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x004128F8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x004128FC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x00412900: lw          $a0, -0x4198($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4198);
    // 0x00412904: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x00412908: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x0041290C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00412910: beq         $a0, $zero, L_00412920
    if (ctx->r4 == 0) {
        // 0x00412914: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_00412920;
    }
    // 0x00412914: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00412918: jal         0x0023781C
    // 0x0041291C: nop

    func_0023781C(rdram, ctx);
        goto after_0;
    // 0x0041291C: nop

    after_0:
L_00412920:
    // 0x00412920: jal         0x00274524
    // 0x00412924: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_00274524(rdram, ctx);
        goto after_1;
    // 0x00412924: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_1:
    // 0x00412928: jal         0x002744A4
    // 0x0041292C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_002744A4(rdram, ctx);
        goto after_2;
    // 0x0041292C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_2:
    // 0x00412930: jal         0x002740FC
    // 0x00412934: nop

    func_002740FC(rdram, ctx);
        goto after_3;
    // 0x00412934: nop

    after_3:
    // 0x00412938: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x0041293C: lw          $s0, 0xEC($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XEC);
    // 0x00412940: blez        $v0, L_00412978
    if (SIGNED(ctx->r2) <= 0) {
        // 0x00412944: nop
    
            goto L_00412978;
    }
    // 0x00412944: nop

    // 0x00412948: lui         $s3, 0x200
    ctx->r19 = S32(0X200 << 16);
L_0041294C:
    // 0x0041294C: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x00412950: and         $v0, $v0, $s3
    ctx->r2 = ctx->r2 & ctx->r19;
    // 0x00412954: beq         $v0, $zero, L_00412964
    if (ctx->r2 == 0) {
        // 0x00412958: nop
    
            goto L_00412964;
    }
    // 0x00412958: nop

    // 0x0041295C: jal         0x00219C3C
    // 0x00412960: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00219C3C(rdram, ctx);
        goto after_4;
    // 0x00412960: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_00412964:
    // 0x00412964: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x00412968: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x0041296C: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00412970: bne         $v0, $zero, L_0041294C
    if (ctx->r2 != 0) {
        // 0x00412974: addiu       $s0, $s0, 0x368
        ctx->r16 = ADD32(ctx->r16, 0X368);
            goto L_0041294C;
    }
    // 0x00412974: addiu       $s0, $s0, 0x368
    ctx->r16 = ADD32(ctx->r16, 0X368);
L_00412978:
    // 0x00412978: lw          $s0, 0x1738($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X1738);
    // 0x0041297C: beq         $s0, $zero, L_004129A8
    if (ctx->r16 == 0) {
        // 0x00412980: lui         $s1, 0x200
        ctx->r17 = S32(0X200 << 16);
            goto L_004129A8;
    }
    // 0x00412980: lui         $s1, 0x200
    ctx->r17 = S32(0X200 << 16);
L_00412984:
    // 0x00412984: lw          $v0, 0xF4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF4);
    // 0x00412988: and         $v0, $v0, $s1
    ctx->r2 = ctx->r2 & ctx->r17;
    // 0x0041298C: beq         $v0, $zero, L_0041299C
    if (ctx->r2 == 0) {
        // 0x00412990: nop
    
            goto L_0041299C;
    }
    // 0x00412990: nop

    // 0x00412994: jal         0x00219C3C
    // 0x00412998: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00219C3C(rdram, ctx);
        goto after_5;
    // 0x00412998: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_0041299C:
    // 0x0041299C: lw          $s0, 0x36C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X36C);
    // 0x004129A0: bne         $s0, $zero, L_00412984
    if (ctx->r16 != 0) {
        // 0x004129A4: nop
    
            goto L_00412984;
    }
    // 0x004129A4: nop

L_004129A8:
    // 0x004129A8: jal         0x00284890
    // 0x004129AC: nop

    func_00284890(rdram, ctx);
        goto after_6;
    // 0x004129AC: nop

    after_6:
    // 0x004129B0: lw          $a1, 0x98($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X98);
    // 0x004129B4: jal         0x002217F0
    // 0x004129B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_7;
    // 0x004129B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // 0x004129BC: lw          $a1, 0x9C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X9C);
    // 0x004129C0: jal         0x002217F0
    // 0x004129C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_8;
    // 0x004129C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_8:
    // 0x004129C8: lw          $a1, 0xA0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XA0);
    // 0x004129CC: jal         0x002217F0
    // 0x004129D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_9;
    // 0x004129D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_9:
    // 0x004129D4: lw          $a1, 0xA4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XA4);
    // 0x004129D8: jal         0x002217F0
    // 0x004129DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_10;
    // 0x004129DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_10:
    // 0x004129E0: lw          $a1, 0xA8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XA8);
    // 0x004129E4: jal         0x002217F0
    // 0x004129E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_11;
    // 0x004129E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // 0x004129EC: lw          $a1, 0xB0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XB0);
    // 0x004129F0: jal         0x002217F0
    // 0x004129F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_12;
    // 0x004129F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
    // 0x004129F8: lw          $a1, 0xB4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XB4);
    // 0x004129FC: jal         0x002217F0
    // 0x00412A00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_13;
    // 0x00412A00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // 0x00412A04: lw          $a1, 0xD0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XD0);
    // 0x00412A08: jal         0x002217F0
    // 0x00412A0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_14;
    // 0x00412A0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_14:
    // 0x00412A10: lw          $a1, 0xAC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XAC);
    // 0x00412A14: jal         0x002217F0
    // 0x00412A18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_15;
    // 0x00412A18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // 0x00412A1C: lw          $a1, 0xC8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC8);
    // 0x00412A20: jal         0x002217F0
    // 0x00412A24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002217F0(rdram, ctx);
        goto after_16;
    // 0x00412A24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_16:
    // 0x00412A28: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x00412A2C: addiu       $a0, $a0, 0x6BC0
    ctx->r4 = ADD32(ctx->r4, 0X6BC0);
    // 0x00412A30: jal         0x0023D348
    // 0x00412A34: nop

    func_0023D348(rdram, ctx);
        goto after_17;
    // 0x00412A34: nop

    after_17:
    // 0x00412A38: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x00412A3C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x00412A40: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00412A44: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00412A48: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00412A4C: jr          $ra
    // 0x00412A50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x00412A50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_00412A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00412A54: lw          $v0, 0x1780($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1780);
    // 0x00412A58: bnel        $v0, $zero, L_00412A60
    if (ctx->r2 != 0) {
        // 0x00412A5C: sw          $v0, 0x177C($a0)
        MEM_W(0X177C, ctx->r4) = ctx->r2;
            goto L_00412A60;
    }
    goto skip_0;
    // 0x00412A5C: sw          $v0, 0x177C($a0)
    MEM_W(0X177C, ctx->r4) = ctx->r2;
    skip_0:
L_00412A60:
    // 0x00412A60: addiu       $v0, $zero, 0x2EE0
    ctx->r2 = ADD32(0, 0X2EE0);
    // 0x00412A64: beq         $a1, $v0, L_00412C00
    if (ctx->r5 == ctx->r2) {
        // 0x00412A68: slti        $v0, $a1, 0x2EE1
        ctx->r2 = SIGNED(ctx->r5) < 0X2EE1 ? 1 : 0;
            goto L_00412C00;
    }
    // 0x00412A68: slti        $v0, $a1, 0x2EE1
    ctx->r2 = SIGNED(ctx->r5) < 0X2EE1 ? 1 : 0;
    // 0x00412A6C: beq         $v0, $zero, L_00412B00
    if (ctx->r2 == 0) {
        // 0x00412A70: addiu       $v0, $zero, 0x28A0
        ctx->r2 = ADD32(0, 0X28A0);
            goto L_00412B00;
    }
    // 0x00412A70: addiu       $v0, $zero, 0x28A0
    ctx->r2 = ADD32(0, 0X28A0);
    // 0x00412A74: beq         $a1, $v0, L_00412B98
    if (ctx->r5 == ctx->r2) {
        // 0x00412A78: slti        $v0, $a1, 0x28A1
        ctx->r2 = SIGNED(ctx->r5) < 0X28A1 ? 1 : 0;
            goto L_00412B98;
    }
    // 0x00412A78: slti        $v0, $a1, 0x28A1
    ctx->r2 = SIGNED(ctx->r5) < 0X28A1 ? 1 : 0;
    // 0x00412A7C: beq         $v0, $zero, L_00412AC0
    if (ctx->r2 == 0) {
        // 0x00412A80: addiu       $v0, $zero, 0x2774
        ctx->r2 = ADD32(0, 0X2774);
            goto L_00412AC0;
    }
    // 0x00412A80: addiu       $v0, $zero, 0x2774
    ctx->r2 = ADD32(0, 0X2774);
    // 0x00412A84: beq         $a1, $v0, L_00412BA8
    if (ctx->r5 == ctx->r2) {
        // 0x00412A88: slti        $v0, $a1, 0x2775
        ctx->r2 = SIGNED(ctx->r5) < 0X2775 ? 1 : 0;
            goto L_00412BA8;
    }
    // 0x00412A88: slti        $v0, $a1, 0x2775
    ctx->r2 = SIGNED(ctx->r5) < 0X2775 ? 1 : 0;
    // 0x00412A8C: beq         $v0, $zero, L_00412AA4
    if (ctx->r2 == 0) {
        // 0x00412A90: addiu       $v0, $zero, 0x2710
        ctx->r2 = ADD32(0, 0X2710);
            goto L_00412AA4;
    }
    // 0x00412A90: addiu       $v0, $zero, 0x2710
    ctx->r2 = ADD32(0, 0X2710);
    // 0x00412A94: beq         $a1, $v0, L_00412B9C
    if (ctx->r5 == ctx->r2) {
        // 0x00412A98: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00412B9C;
    }
    // 0x00412A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00412A9C: j           L_00412C38
    // 0x00412AA0: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
        goto L_00412C38;
    // 0x00412AA0: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
L_00412AA4:
    // 0x00412AA4: addiu       $v0, $zero, 0x27D8
    ctx->r2 = ADD32(0, 0X27D8);
    // 0x00412AA8: beq         $a1, $v0, L_00412BBC
    if (ctx->r5 == ctx->r2) {
        // 0x00412AAC: addiu       $v0, $zero, 0x283C
        ctx->r2 = ADD32(0, 0X283C);
            goto L_00412BBC;
    }
    // 0x00412AAC: addiu       $v0, $zero, 0x283C
    ctx->r2 = ADD32(0, 0X283C);
    // 0x00412AB0: beq         $a1, $v0, L_00412BD0
    if (ctx->r5 == ctx->r2) {
        // 0x00412AB4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_00412BD0;
    }
    // 0x00412AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00412AB8: j           L_00412C38
    // 0x00412ABC: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
        goto L_00412C38;
    // 0x00412ABC: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
L_00412AC0:
    // 0x00412AC0: addiu       $v0, $zero, 0x2B5C
    ctx->r2 = ADD32(0, 0X2B5C);
    // 0x00412AC4: beq         $a1, $v0, L_00412BF0
    if (ctx->r5 == ctx->r2) {
        // 0x00412AC8: slti        $v0, $a1, 0x2B5D
        ctx->r2 = SIGNED(ctx->r5) < 0X2B5D ? 1 : 0;
            goto L_00412BF0;
    }
    // 0x00412AC8: slti        $v0, $a1, 0x2B5D
    ctx->r2 = SIGNED(ctx->r5) < 0X2B5D ? 1 : 0;
    // 0x00412ACC: beq         $v0, $zero, L_00412AE4
    if (ctx->r2 == 0) {
        // 0x00412AD0: addiu       $v0, $zero, 0x2AF8
        ctx->r2 = ADD32(0, 0X2AF8);
            goto L_00412AE4;
    }
    // 0x00412AD0: addiu       $v0, $zero, 0x2AF8
    ctx->r2 = ADD32(0, 0X2AF8);
    // 0x00412AD4: beq         $a1, $v0, L_00412BE0
    if (ctx->r5 == ctx->r2) {
        // 0x00412AD8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00412BE0;
    }
    // 0x00412AD8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00412ADC: j           L_00412C38
    // 0x00412AE0: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
        goto L_00412C38;
    // 0x00412AE0: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
L_00412AE4:
    // 0x00412AE4: addiu       $v0, $zero, 0x2BC0
    ctx->r2 = ADD32(0, 0X2BC0);
    // 0x00412AE8: beq         $a1, $v0, L_00412BF8
    if (ctx->r5 == ctx->r2) {
        // 0x00412AEC: addiu       $v0, $zero, 0x2C24
        ctx->r2 = ADD32(0, 0X2C24);
            goto L_00412BF8;
    }
    // 0x00412AEC: addiu       $v0, $zero, 0x2C24
    ctx->r2 = ADD32(0, 0X2C24);
    // 0x00412AF0: beq         $a1, $v0, L_00412BC0
    if (ctx->r5 == ctx->r2) {
        // 0x00412AF4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_00412BC0;
    }
    // 0x00412AF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00412AF8: j           L_00412C38
    // 0x00412AFC: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
        goto L_00412C38;
    // 0x00412AFC: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
L_00412B00:
    // 0x00412B00: addiu       $v0, $zero, 0x332C
    ctx->r2 = ADD32(0, 0X332C);
    // 0x00412B04: beq         $a1, $v0, L_00412C18
    if (ctx->r5 == ctx->r2) {
        // 0x00412B08: slti        $v0, $a1, 0x332D
        ctx->r2 = SIGNED(ctx->r5) < 0X332D ? 1 : 0;
            goto L_00412C18;
    }
    // 0x00412B08: slti        $v0, $a1, 0x332D
    ctx->r2 = SIGNED(ctx->r5) < 0X332D ? 1 : 0;
    // 0x00412B0C: beq         $v0, $zero, L_00412B50
    if (ctx->r2 == 0) {
        // 0x00412B10: addiu       $v0, $zero, 0x2FA8
        ctx->r2 = ADD32(0, 0X2FA8);
            goto L_00412B50;
    }
    // 0x00412B10: addiu       $v0, $zero, 0x2FA8
    ctx->r2 = ADD32(0, 0X2FA8);
    // 0x00412B14: beq         $a1, $v0, L_00412C08
    if (ctx->r5 == ctx->r2) {
        // 0x00412B18: slti        $v0, $a1, 0x2FA9
        ctx->r2 = SIGNED(ctx->r5) < 0X2FA9 ? 1 : 0;
            goto L_00412C08;
    }
    // 0x00412B18: slti        $v0, $a1, 0x2FA9
    ctx->r2 = SIGNED(ctx->r5) < 0X2FA9 ? 1 : 0;
    // 0x00412B1C: beq         $v0, $zero, L_00412B34
    if (ctx->r2 == 0) {
        // 0x00412B20: addiu       $v0, $zero, 0x2F44
        ctx->r2 = ADD32(0, 0X2F44);
            goto L_00412B34;
    }
    // 0x00412B20: addiu       $v0, $zero, 0x2F44
    ctx->r2 = ADD32(0, 0X2F44);
    // 0x00412B24: beq         $a1, $v0, L_00412BAC
    if (ctx->r5 == ctx->r2) {
        // 0x00412B28: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_00412BAC;
    }
    // 0x00412B28: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00412B2C: j           L_00412C38
    // 0x00412B30: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
        goto L_00412C38;
    // 0x00412B30: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
L_00412B34:
    // 0x00412B34: addiu       $v0, $zero, 0x300C
    ctx->r2 = ADD32(0, 0X300C);
    // 0x00412B38: beq         $a1, $v0, L_00412C10
    if (ctx->r5 == ctx->r2) {
        // 0x00412B3C: addiu       $v0, $zero, 0x32C8
        ctx->r2 = ADD32(0, 0X32C8);
            goto L_00412C10;
    }
    // 0x00412B3C: addiu       $v0, $zero, 0x32C8
    ctx->r2 = ADD32(0, 0X32C8);
    // 0x00412B40: beq         $a1, $v0, L_00412BE0
    if (ctx->r5 == ctx->r2) {
        // 0x00412B44: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_00412BE0;
    }
    // 0x00412B44: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x00412B48: j           L_00412C38
    // 0x00412B4C: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
        goto L_00412C38;
    // 0x00412B4C: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
L_00412B50:
    // 0x00412B50: addiu       $v0, $zero, 0x36B0
    ctx->r2 = ADD32(0, 0X36B0);
    // 0x00412B54: beq         $a1, $v0, L_00412C28
    if (ctx->r5 == ctx->r2) {
        // 0x00412B58: slti        $v0, $a1, 0x36B1
        ctx->r2 = SIGNED(ctx->r5) < 0X36B1 ? 1 : 0;
            goto L_00412C28;
    }
    // 0x00412B58: slti        $v0, $a1, 0x36B1
    ctx->r2 = SIGNED(ctx->r5) < 0X36B1 ? 1 : 0;
    // 0x00412B5C: beq         $v0, $zero, L_00412B7C
    if (ctx->r2 == 0) {
        // 0x00412B60: addiu       $v0, $zero, 0x3390
        ctx->r2 = ADD32(0, 0X3390);
            goto L_00412B7C;
    }
    // 0x00412B60: addiu       $v0, $zero, 0x3390
    ctx->r2 = ADD32(0, 0X3390);
    // 0x00412B64: beq         $a1, $v0, L_00412C20
    if (ctx->r5 == ctx->r2) {
        // 0x00412B68: addiu       $v0, $zero, 0x33F4
        ctx->r2 = ADD32(0, 0X33F4);
            goto L_00412C20;
    }
    // 0x00412B68: addiu       $v0, $zero, 0x33F4
    ctx->r2 = ADD32(0, 0X33F4);
    // 0x00412B6C: beq         $a1, $v0, L_00412BC0
    if (ctx->r5 == ctx->r2) {
        // 0x00412B70: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_00412BC0;
    }
    // 0x00412B70: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x00412B74: j           L_00412C38
    // 0x00412B78: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
        goto L_00412C38;
    // 0x00412B78: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
L_00412B7C:
    // 0x00412B7C: addiu       $v0, $zero, 0x3714
    ctx->r2 = ADD32(0, 0X3714);
    // 0x00412B80: beq         $a1, $v0, L_00412C30
    if (ctx->r5 == ctx->r2) {
        // 0x00412B84: addiu       $v0, $zero, 0x3778
        ctx->r2 = ADD32(0, 0X3778);
            goto L_00412C30;
    }
    // 0x00412B84: addiu       $v0, $zero, 0x3778
    ctx->r2 = ADD32(0, 0X3778);
    // 0x00412B88: beq         $a1, $v0, L_00412BC0
    if (ctx->r5 == ctx->r2) {
        // 0x00412B8C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_00412BC0;
    }
    // 0x00412B8C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x00412B90: j           L_00412C38
    // 0x00412B94: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
        goto L_00412C38;
    // 0x00412B94: sw          $zero, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = 0;
L_00412B98:
    // 0x00412B98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_00412B9C:
    // 0x00412B9C: sw          $v0, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = ctx->r2;
    // 0x00412BA0: jr          $ra
    // 0x00412BA4: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
    return;
    // 0x00412BA4: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
L_00412BA8:
    // 0x00412BA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_00412BAC:
    // 0x00412BAC: sw          $v0, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = ctx->r2;
    // 0x00412BB0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00412BB4: jr          $ra
    // 0x00412BB8: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
    return;
    // 0x00412BB8: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
L_00412BBC:
    // 0x00412BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_00412BC0:
    // 0x00412BC0: sw          $v0, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = ctx->r2;
    // 0x00412BC4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00412BC8: jr          $ra
    // 0x00412BCC: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
    return;
    // 0x00412BCC: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
L_00412BD0:
    // 0x00412BD0: sw          $v0, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = ctx->r2;
    // 0x00412BD4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x00412BD8: jr          $ra
    // 0x00412BDC: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
    return;
    // 0x00412BDC: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
L_00412BE0:
    // 0x00412BE0: sw          $v0, 0x1780($a0)
    MEM_W(0X1780, ctx->r4) = ctx->r2;
    // 0x00412BE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00412BE8: jr          $ra
    // 0x00412BEC: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
    return;
    // 0x00412BEC: sw          $v0, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = ctx->r2;
L_00412BF0:
    // 0x00412BF0: j           L_00412B9C
    // 0x00412BF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_00412B9C;
    // 0x00412BF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_00412BF8:
    // 0x00412BF8: j           L_00412BC0
    // 0x00412BFC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_00412BC0;
    // 0x00412BFC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_00412C00:
    // 0x00412C00: j           L_00412BE0
    // 0x00412C04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_00412BE0;
    // 0x00412C04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_00412C08:
    // 0x00412C08: j           L_00412B9C
    // 0x00412C0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_00412B9C;
    // 0x00412C0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_00412C10:
    // 0x00412C10: j           L_00412BD0
    // 0x00412C14: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_00412BD0;
    // 0x00412C14: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_00412C18:
    // 0x00412C18: j           L_00412BAC
    // 0x00412C1C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_00412BAC;
    // 0x00412C1C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_00412C20:
    // 0x00412C20: j           L_00412BC0
    // 0x00412C24: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_00412BC0;
    // 0x00412C24: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_00412C28:
    // 0x00412C28: j           L_00412BE0
    // 0x00412C2C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_00412BE0;
    // 0x00412C2C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_00412C30:
    // 0x00412C30: j           L_00412BAC
    // 0x00412C34: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_00412BAC;
    // 0x00412C34: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_00412C38:
    // 0x00412C38: jr          $ra
    // 0x00412C3C: sw          $zero, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = 0;
    return;
    // 0x00412C3C: sw          $zero, 0x1784($a0)
    MEM_W(0X1784, ctx->r4) = 0;
;}
RECOMP_FUNC void func_00412C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00412C40: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x00412C44: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x00412C48: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x00412C4C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x00412C50: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x00412C54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x00412C58: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x00412C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00412C60: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x00412C64: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x00412C68: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x00412C6C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x00412C70: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x00412C74: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x00412C78: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x00412C7C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x00412C80: jal         0x00205F78
    // 0x00412C84: sw          $zero, 0x4($s2)
    MEM_W(0X4, ctx->r18) = 0;
    func_00205F78(rdram, ctx);
        goto after_0;
    // 0x00412C84: sw          $zero, 0x4($s2)
    MEM_W(0X4, ctx->r18) = 0;
    after_0:
    // 0x00412C88: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x00412C8C: addiu       $a0, $a0, 0x1AB0
    ctx->r4 = ADD32(ctx->r4, 0X1AB0);
    // 0x00412C90: jal         0x0021F1A4
    // 0x00412C94: nop

    func_0021F1A4(rdram, ctx);
        goto after_1;
    // 0x00412C94: nop

    after_1:
    // 0x00412C98: jal         0x002218C0
    // 0x00412C9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002218C0(rdram, ctx);
        goto after_2;
    // 0x00412C9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x00412CA0: lw          $v1, 0x1774($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1774);
    // 0x00412CA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00412CA8: beq         $v1, $v0, L_00412CB8
    if (ctx->r3 == ctx->r2) {
        // 0x00412CAC: nop
    
            goto L_00412CB8;
    }
    // 0x00412CAC: nop

    // 0x00412CB0: jal         0x004128F0
    // 0x00412CB4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_004128F0(rdram, ctx);
        goto after_3;
    // 0x00412CB4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
L_00412CB8:
    // 0x00412CB8: jal         0x002218C0
    // 0x00412CBC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002218C0(rdram, ctx);
        goto after_4;
    // 0x00412CBC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x00412CC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00412CC4: sw          $zero, -0x4970($at)
    MEM_W(-0X4970, ctx->r1) = 0;
    // 0x00412CC8: jal         0x00222580
    // 0x00412CCC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_00222580(rdram, ctx);
        goto after_5;
    // 0x00412CCC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_5:
    // 0x00412CD0: jal         0x00205C14
    // 0x00412CD4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_00205C14(rdram, ctx);
        goto after_6;
    // 0x00412CD4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_6:
    // 0x00412CD8: lw          $v0, 0x94($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X94);
    // 0x00412CDC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x00412CE0: jal         0x002538A8
    // 0x00412CE4: addiu       $a0, $s2, 0x167C
    ctx->r4 = ADD32(ctx->r18, 0X167C);
    func_002538A8(rdram, ctx);
        goto after_7;
    // 0x00412CE4: addiu       $a0, $s2, 0x167C
    ctx->r4 = ADD32(ctx->r18, 0X167C);
    after_7:
    // 0x00412CE8: jal         0x0025973C
    // 0x00412CEC: addiu       $a0, $s2, 0x16EC
    ctx->r4 = ADD32(ctx->r18, 0X16EC);
    func_0025973C(rdram, ctx);
        goto after_8;
    // 0x00412CEC: addiu       $a0, $s2, 0x16EC
    ctx->r4 = ADD32(ctx->r18, 0X16EC);
    after_8:
    // 0x00412CF0: jal         0x0025A328
    // 0x00412CF4: addiu       $a0, $s2, 0x171C
    ctx->r4 = ADD32(ctx->r18, 0X171C);
    func_0025A328(rdram, ctx);
        goto after_9;
    // 0x00412CF4: addiu       $a0, $s2, 0x171C
    ctx->r4 = ADD32(ctx->r18, 0X171C);
    after_9:
    // 0x00412CF8: jal         0x0027D118
    // 0x00412CFC: nop

    func_0027D118(rdram, ctx);
        goto after_10;
    // 0x00412CFC: nop

    after_10:
    // 0x00412D00: jal         0x00216678
    // 0x00412D04: addiu       $a0, $s2, 0x178C
    ctx->r4 = ADD32(ctx->r18, 0X178C);
    func_00216678(rdram, ctx);
        goto after_11;
    // 0x00412D04: addiu       $a0, $s2, 0x178C
    ctx->r4 = ADD32(ctx->r18, 0X178C);
    after_11:
    // 0x00412D08: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x00412D0C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x00412D10: slt         $v0, $v1, $s1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x00412D14: beq         $v0, $zero, L_00412D24
    if (ctx->r2 == 0) {
        // 0x00412D18: nop
    
            goto L_00412D24;
    }
    // 0x00412D18: nop

    // 0x00412D1C: addiu       $s1, $v1, -0x1
    ctx->r17 = ADD32(ctx->r3, -0X1);
    // 0x00412D20: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_00412D24:
    // 0x00412D24: lw          $a1, 0x187C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X187C);
    // 0x00412D28: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00412D2C: jal         0x00412A54
    // 0x00412D30: sw          $s1, 0x1774($s2)
    MEM_W(0X1774, ctx->r18) = ctx->r17;
    func_00412A54(rdram, ctx);
        goto after_12;
    // 0x00412D30: sw          $s1, 0x1774($s2)
    MEM_W(0X1774, ctx->r18) = ctx->r17;
    after_12:
    // 0x00412D34: beql        $s0, $zero, L_00412D3C
    if (ctx->r16 == 0) {
        // 0x00412D38: sw          $zero, 0x1864($s2)
        MEM_W(0X1864, ctx->r18) = 0;
            goto L_00412D3C;
    }
    goto skip_0;
    // 0x00412D38: sw          $zero, 0x1864($s2)
    MEM_W(0X1864, ctx->r18) = 0;
    skip_0:
L_00412D3C:
    // 0x00412D3C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x00412D40: lbu         $v0, -0x2DC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2DC8);
    // 0x00412D44: bne         $v0, $zero, L_00412D50
    if (ctx->r2 != 0) {
        // 0x00412D48: addiu       $s0, $zero, 0x4B0
        ctx->r16 = ADD32(0, 0X4B0);
            goto L_00412D50;
    }
    // 0x00412D48: addiu       $s0, $zero, 0x4B0
    ctx->r16 = ADD32(0, 0X4B0);
    // 0x00412D4C: addiu       $s0, $zero, 0x320
    ctx->r16 = ADD32(0, 0X320);
L_00412D50:
    // 0x00412D50: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412D54: sll         $a1, $s0, 6
    ctx->r5 = S32(ctx->r16 << 6);
    // 0x00412D58: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x00412D5C: addiu       $a3, $a3, 0x7480
    ctx->r7 = ADD32(ctx->r7, 0X7480);
    // 0x00412D60: jal         0x002213F4
    // 0x00412D64: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_002213F4(rdram, ctx);
        goto after_13;
    // 0x00412D64: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_13:
    // 0x00412D68: addiu       $a0, $s2, 0xDC
    ctx->r4 = ADD32(ctx->r18, 0XDC);
    // 0x00412D6C: sw          $v0, 0xC8($s2)
    MEM_W(0XC8, ctx->r18) = ctx->r2;
    // 0x00412D70: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x00412D74: jal         0x002594E0
    // 0x00412D78: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_002594E0(rdram, ctx);
        goto after_14;
    // 0x00412D78: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_14:
    // 0x00412D7C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x00412D80: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x00412D84: jal         0x00210A00
    // 0x00412D88: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_00210A00(rdram, ctx);
        goto after_15;
    // 0x00412D88: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_15:
    // 0x00412D8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412D90: addiu       $a1, $s2, 0x50
    ctx->r5 = ADD32(ctx->r18, 0X50);
    // 0x00412D94: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00412D98: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x00412D9C: addiu       $a3, $a3, 0x748C
    ctx->r7 = ADD32(ctx->r7, 0X748C);
    // 0x00412DA0: jal         0x002220AC
    // 0x00412DA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_002220AC(rdram, ctx);
        goto after_16;
    // 0x00412DA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // 0x00412DA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412DAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00412DB0: sw          $v0, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->r2;
    // 0x00412DB4: lui         $v0, 0x41
    ctx->r2 = S32(0X41 << 16);
    // 0x00412DB8: addiu       $v0, $v0, 0x331C
    ctx->r2 = ADD32(ctx->r2, 0X331C);
    // 0x00412DBC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x00412DC0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412DC4: addiu       $v0, $v0, 0x7498
    ctx->r2 = ADD32(ctx->r2, 0X7498);
    // 0x00412DC8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x00412DCC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412DD0: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x00412DD4: jal         0x00222224
    // 0x00412DD8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00222224(rdram, ctx);
        goto after_17;
    // 0x00412DD8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_17:
    // 0x00412DDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412DE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x00412DE4: sw          $v0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->r2;
    // 0x00412DE8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00412DEC: lui         $s1, 0x22
    ctx->r17 = S32(0X22 << 16);
    // 0x00412DF0: addiu       $s1, $s1, 0x2E28
    ctx->r17 = ADD32(ctx->r17, 0X2E28);
    // 0x00412DF4: sw          $v0, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->r2;
    // 0x00412DF8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412DFC: addiu       $v0, $v0, 0x74A4
    ctx->r2 = ADD32(ctx->r2, 0X74A4);
    // 0x00412E00: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x00412E04: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00412E08: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412E0C: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x00412E10: jal         0x00222224
    // 0x00412E14: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00222224(rdram, ctx);
        goto after_18;
    // 0x00412E14: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_18:
    // 0x00412E18: lw          $a0, 0x50($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X50);
    // 0x00412E1C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00412E20: sw          $v0, 0xA0($s2)
    MEM_W(0XA0, ctx->r18) = ctx->r2;
    // 0x00412E24: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00412E28: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x00412E2C: jal         0x00210A00
    // 0x00412E30: sw          $v0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r2;
    func_00210A00(rdram, ctx);
        goto after_19;
    // 0x00412E30: sw          $v0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r2;
    after_19:
    // 0x00412E34: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412E38: addiu       $a1, $s2, 0x54
    ctx->r5 = ADD32(ctx->r18, 0X54);
    // 0x00412E3C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x00412E40: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x00412E44: addiu       $a3, $a3, 0x74B0
    ctx->r7 = ADD32(ctx->r7, 0X74B0);
    // 0x00412E48: jal         0x002220AC
    // 0x00412E4C: sw          $a2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r6;
    func_002220AC(rdram, ctx);
        goto after_20;
    // 0x00412E4C: sw          $a2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r6;
    after_20:
    // 0x00412E50: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412E54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x00412E58: sw          $v0, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->r2;
    // 0x00412E5C: lui         $v0, 0x41
    ctx->r2 = S32(0X41 << 16);
    // 0x00412E60: addiu       $v0, $v0, 0x4820
    ctx->r2 = ADD32(ctx->r2, 0X4820);
    // 0x00412E64: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x00412E68: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412E6C: addiu       $v0, $v0, 0x74C4
    ctx->r2 = ADD32(ctx->r2, 0X74C4);
    // 0x00412E70: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x00412E74: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412E78: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x00412E7C: jal         0x00222224
    // 0x00412E80: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00222224(rdram, ctx);
        goto after_21;
    // 0x00412E80: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_21:
    // 0x00412E84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412E88: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x00412E8C: sw          $v0, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->r2;
    // 0x00412E90: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412E94: addiu       $v0, $v0, 0x74D0
    ctx->r2 = ADD32(ctx->r2, 0X74D0);
    // 0x00412E98: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x00412E9C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x00412EA0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412EA4: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x00412EA8: jal         0x00222224
    // 0x00412EAC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00222224(rdram, ctx);
        goto after_22;
    // 0x00412EAC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_22:
    // 0x00412EB0: sw          $v0, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = ctx->r2;
    // 0x00412EB4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00412EB8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00412EBC: jal         0x004127AC
    // 0x00412EC0: sw          $v0, 0x174C($s2)
    MEM_W(0X174C, ctx->r18) = ctx->r2;
    func_004127AC(rdram, ctx);
        goto after_23;
    // 0x00412EC0: sw          $v0, 0x174C($s2)
    MEM_W(0X174C, ctx->r18) = ctx->r2;
    after_23:
    // 0x00412EC4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412EC8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x00412ECC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412ED0: addiu       $v0, $v0, 0x74DC
    ctx->r2 = ADD32(ctx->r2, 0X74DC);
    // 0x00412ED4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x00412ED8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00412EDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412EE0: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x00412EE4: jal         0x00222224
    // 0x00412EE8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00222224(rdram, ctx);
        goto after_24;
    // 0x00412EE8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_24:
    // 0x00412EEC: sw          $v0, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->r2;
    // 0x00412EF0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x00412EF4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x00412EF8: sw          $v0, 0x1758($s2)
    MEM_W(0X1758, ctx->r18) = ctx->r2;
    // 0x00412EFC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x00412F00: jal         0x00283C68
    // 0x00412F04: sw          $v0, 0x175C($s2)
    MEM_W(0X175C, ctx->r18) = ctx->r2;
    func_00283C68(rdram, ctx);
        goto after_25;
    // 0x00412F04: sw          $v0, 0x175C($s2)
    MEM_W(0X175C, ctx->r18) = ctx->r2;
    after_25:
    // 0x00412F08: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412F0C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x00412F10: lui         $v0, 0x41
    ctx->r2 = S32(0X41 << 16);
    // 0x00412F14: addiu       $v0, $v0, 0x35F8
    ctx->r2 = ADD32(ctx->r2, 0X35F8);
    // 0x00412F18: sw          $zero, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = 0;
    // 0x00412F1C: sw          $zero, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = 0;
    // 0x00412F20: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x00412F24: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412F28: addiu       $v0, $v0, 0x74E8
    ctx->r2 = ADD32(ctx->r2, 0X74E8);
    // 0x00412F2C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x00412F30: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412F34: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x00412F38: jal         0x00222224
    // 0x00412F3C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00222224(rdram, ctx);
        goto after_26;
    // 0x00412F3C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_26:
    // 0x00412F40: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412F44: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x00412F48: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    // 0x00412F4C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x00412F50: addiu       $v0, $v0, 0x74FC
    ctx->r2 = ADD32(ctx->r2, 0X74FC);
    // 0x00412F54: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x00412F58: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x00412F5C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x00412F60: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x00412F64: jal         0x00222224
    // 0x00412F68: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_00222224(rdram, ctx);
        goto after_27;
    // 0x00412F68: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_27:
    // 0x00412F6C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00412F70: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x00412F74: lw          $a1, 0xEC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XEC);
    // 0x00412F78: addiu       $v1, $s2, 0x7C
    ctx->r3 = ADD32(ctx->r18, 0X7C);
    // 0x00412F7C: sw          $v0, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->r2;
    // 0x00412F80: sw          $zero, 0x178($s2)
    MEM_W(0X178, ctx->r18) = 0;
L_00412F84:
    // 0x00412F84: sw          $zero, 0xF8($v1)
    MEM_W(0XF8, ctx->r3) = 0;
    // 0x00412F88: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x00412F8C: bgez        $a0, L_00412F84
    if (SIGNED(ctx->r4) >= 0) {
        // 0x00412F90: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_00412F84;
    }
    // 0x00412F90: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x00412F94: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x00412F98: blez        $v0, L_00412FE4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x00412F9C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00412FE4;
    }
    // 0x00412F9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412FA0: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x00412FA4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x00412FA8: addu        $v1, $v0, $s2
    ctx->r3 = ADD32(ctx->r2, ctx->r18);
L_00412FAC:
    // 0x00412FAC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x00412FB0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00412FB4: bne         $v0, $a3, L_00412FCC
    if (ctx->r2 != ctx->r7) {
        // 0x00412FB8: slti        $v0, $a2, 0x20
        ctx->r2 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
            goto L_00412FCC;
    }
    // 0x00412FB8: slti        $v0, $a2, 0x20
    ctx->r2 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x00412FBC: sw          $a1, 0xF8($v1)
    MEM_W(0XF8, ctx->r3) = ctx->r5;
    // 0x00412FC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x00412FC4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x00412FC8: slti        $v0, $a2, 0x20
    ctx->r2 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
L_00412FCC:
    // 0x00412FCC: beq         $v0, $zero, L_00412FE4
    if (ctx->r2 == 0) {
        // 0x00412FD0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00412FE4;
    }
    // 0x00412FD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00412FD4: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x00412FD8: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00412FDC: bne         $v0, $zero, L_00412FAC
    if (ctx->r2 != 0) {
        // 0x00412FE0: addiu       $a1, $a1, 0x368
        ctx->r5 = ADD32(ctx->r5, 0X368);
            goto L_00412FAC;
    }
    // 0x00412FE0: addiu       $a1, $a1, 0x368
    ctx->r5 = ADD32(ctx->r5, 0X368);
L_00412FE4:
    // 0x00412FE4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00412FE8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_00412FEC:
    // 0x00412FEC: lw          $v1, 0xF8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XF8);
    // 0x00412FF0: beq         $v1, $zero, L_00413010
    if (ctx->r3 == 0) {
        // 0x00412FF4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_00413010;
    }
    // 0x00412FF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00412FF8: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x00412FFC: lh          $v0, 0xC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0XC);
    // 0x00413000: bne         $v0, $zero, L_00413014
    if (ctx->r2 != 0) {
        // 0x00413004: slti        $v0, $a0, 0x20
        ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
            goto L_00413014;
    }
    // 0x00413004: slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x00413008: j           L_0041301C
    // 0x0041300C: sw          $v1, 0x178($s2)
    MEM_W(0X178, ctx->r18) = ctx->r3;
        goto L_0041301C;
    // 0x0041300C: sw          $v1, 0x178($s2)
    MEM_W(0X178, ctx->r18) = ctx->r3;
L_00413010:
    // 0x00413010: slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
L_00413014:
    // 0x00413014: bne         $v0, $zero, L_00412FEC
    if (ctx->r2 != 0) {
        // 0x00413018: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_00412FEC;
    }
    // 0x00413018: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_0041301C:
    // 0x0041301C: lw          $v0, 0xB4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XB4);
    // 0x00413020: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x00413024: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x00413028: jal         0x00414580
    // 0x0041302C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_00414580(rdram, ctx);
        goto after_28;
    // 0x0041302C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_28:
    // 0x00413030: lw          $a0, 0xF0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XF0);
    // 0x00413034: lw          $v1, 0xF4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XF4);
    // 0x00413038: lw          $a3, 0xEC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XEC);
    // 0x0041303C: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x00413040: beq         $v0, $zero, L_00413090
    if (ctx->r2 == 0) {
        // 0x00413044: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_00413090;
    }
    // 0x00413044: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00413048: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x0041304C: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x00413050: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x00413054: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x00413058: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x0041305C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x00413060: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413064: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x00413068: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x0041306C: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
L_00413070:
    // 0x00413070: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x00413074: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00413078: beql        $v0, $t0, L_00413080
    if (ctx->r2 == ctx->r8) {
        // 0x0041307C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_00413080;
    }
    goto skip_1;
    // 0x0041307C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
L_00413080:
    // 0x00413080: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x00413084: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x00413088: bne         $v0, $zero, L_00413070
    if (ctx->r2 != 0) {
        // 0x0041308C: addiu       $v1, $v1, 0x368
        ctx->r3 = ADD32(ctx->r3, 0X368);
            goto L_00413070;
    }
    // 0x0041308C: addiu       $v1, $v1, 0x368
    ctx->r3 = ADD32(ctx->r3, 0X368);
L_00413090:
    // 0x00413090: lw          $v0, 0x187C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X187C);
    // 0x00413094: addiu       $s0, $zero, 0x1F4
    ctx->r16 = ADD32(0, 0X1F4);
    // 0x00413098: sw          $a1, 0x18B0($s2)
    MEM_W(0X18B0, ctx->r18) = ctx->r5;
    // 0x0041309C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x004130A0: sw          $zero, -0x4AC8($at)
    MEM_W(-0X4AC8, ctx->r1) = 0;
    // 0x004130A4: bne         $v0, $s0, L_004130B4
    if (ctx->r2 != ctx->r16) {
        // 0x004130A8: nop
    
            goto L_004130B4;
    }
    // 0x004130A8: nop

    // 0x004130AC: jal         0x00200E54
    // 0x004130B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_00200E54(rdram, ctx);
        goto after_29;
    // 0x004130B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_29:
L_004130B4:
    // 0x004130B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x004130B8: lbu         $v0, -0x2DC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2DC8);
    // 0x004130BC: bne         $v0, $zero, L_00413114
    if (ctx->r2 != 0) {
        // 0x004130C0: nop
    
            goto L_00413114;
    }
    // 0x004130C0: nop

    // 0x004130C4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x004130C8: lw          $v0, 0x42FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X42FC);
    // 0x004130CC: beq         $v0, $s0, L_00413114
    if (ctx->r2 == ctx->r16) {
        // 0x004130D0: nop
    
            goto L_00413114;
    }
    // 0x004130D0: nop

    // 0x004130D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x004130D8: lw          $v0, -0x41B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B0);
    // 0x004130DC: blez        $v0, L_00413114
    if (SIGNED(ctx->r2) <= 0) {
        // 0x004130E0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00413114;
    }
    // 0x004130E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004130E4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_004130E8:
    // 0x004130E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x004130EC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x004130F0: lw          $v0, -0x41B4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B4);
    // 0x004130F4: lbu         $v1, 0x18B3($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X18B3);
    // 0x004130F8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x004130FC: sb          $v1, 0x1585($v0)
    MEM_B(0X1585, ctx->r2) = ctx->r3;
    // 0x00413100: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x00413104: lw          $v0, -0x41B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B0);
    // 0x00413108: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x0041310C: bne         $v0, $zero, L_004130E8
    if (ctx->r2 != 0) {
        // 0x00413110: addiu       $a1, $a1, 0x15C0
        ctx->r5 = ADD32(ctx->r5, 0X15C0);
            goto L_004130E8;
    }
    // 0x00413110: addiu       $a1, $a1, 0x15C0
    ctx->r5 = ADD32(ctx->r5, 0X15C0);
L_00413114:
    // 0x00413114: lw          $s0, 0xF0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XF0);
    // 0x00413118: lw          $s3, 0xF4($s2)
    ctx->r19 = MEM_W(ctx->r18, 0XF4);
    // 0x0041311C: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x00413120: beq         $v0, $zero, L_00413168
    if (ctx->r2 == 0) {
        // 0x00413124: sll         $v0, $s0, 3
        ctx->r2 = S32(ctx->r16 << 3);
            goto L_00413168;
    }
    // 0x00413124: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x00413128: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x0041312C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413130: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x00413134: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413138: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x0041313C: sll         $s1, $v0, 3
    ctx->r17 = S32(ctx->r2 << 3);
L_00413140:
    // 0x00413140: lw          $v0, 0xEC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XEC);
    // 0x00413144: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00413148: addu        $a0, $v0, $s1
    ctx->r4 = ADD32(ctx->r2, ctx->r17);
    // 0x0041314C: addiu       $a1, $a0, 0x168
    ctx->r5 = ADD32(ctx->r4, 0X168);
    // 0x00413150: lb          $a2, 0x198($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X198);
    // 0x00413154: jal         0x0023E684
    // 0x00413158: addiu       $s1, $s1, 0x368
    ctx->r17 = ADD32(ctx->r17, 0X368);
    func_0023E684(rdram, ctx);
        goto after_30;
    // 0x00413158: addiu       $s1, $s1, 0x368
    ctx->r17 = ADD32(ctx->r17, 0X368);
    after_30:
    // 0x0041315C: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x00413160: bne         $v0, $zero, L_00413140
    if (ctx->r2 != 0) {
        // 0x00413164: nop
    
            goto L_00413140;
    }
    // 0x00413164: nop

L_00413168:
    // 0x00413168: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x0041316C: lw          $s0, -0x4198($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4198);
    // 0x00413170: beq         $s0, $zero, L_004131A0
    if (ctx->r16 == 0) {
        // 0x00413174: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_004131A0;
    }
    // 0x00413174: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_00413178:
    // 0x00413178: lb          $a2, 0x198($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X198);
    // 0x0041317C: jal         0x0023E684
    // 0x00413180: addiu       $a1, $s0, 0x168
    ctx->r5 = ADD32(ctx->r16, 0X168);
    func_0023E684(rdram, ctx);
        goto after_31;
    // 0x00413180: addiu       $a1, $s0, 0x168
    ctx->r5 = ADD32(ctx->r16, 0X168);
    after_31:
    // 0x00413184: addiu       $a0, $s0, 0x368
    ctx->r4 = ADD32(ctx->r16, 0X368);
    // 0x00413188: lb          $a2, 0x198($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X198);
    // 0x0041318C: jal         0x0023E684
    // 0x00413190: addiu       $a1, $s0, 0x4D0
    ctx->r5 = ADD32(ctx->r16, 0X4D0);
    func_0023E684(rdram, ctx);
        goto after_32;
    // 0x00413190: addiu       $a1, $s0, 0x4D0
    ctx->r5 = ADD32(ctx->r16, 0X4D0);
    after_32:
    // 0x00413194: lw          $s0, 0x159C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X159C);
    // 0x00413198: bne         $s0, $zero, L_00413178
    if (ctx->r16 != 0) {
        // 0x0041319C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00413178;
    }
    // 0x0041319C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_004131A0:
    // 0x004131A0: lw          $s1, 0xF0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0XF0);
    // 0x004131A4: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x004131A8: lw          $a0, 0xEC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XEC);
    // 0x004131AC: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x004131B0: beq         $v0, $zero, L_0041328C
    if (ctx->r2 == 0) {
        // 0x004131B4: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_0041328C;
    }
    // 0x004131B4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x004131B8: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x004131BC: addiu       $s6, $zero, 0x67
    ctx->r22 = ADD32(0, 0X67);
    // 0x004131C0: addiu       $s5, $zero, 0x66
    ctx->r21 = ADD32(0, 0X66);
    // 0x004131C4: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
    // 0x004131C8: addiu       $s3, $zero, 0x68
    ctx->r19 = ADD32(0, 0X68);
    // 0x004131CC: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x004131D0: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x004131D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x004131D8: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x004131DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x004131E0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x004131E4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x004131E8: addu        $s0, $v0, $a0
    ctx->r16 = ADD32(ctx->r2, ctx->r4);
L_004131EC:
    // 0x004131EC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x004131F0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x004131F4: bne         $v0, $fp, L_00413278
    if (ctx->r2 != ctx->r30) {
        // 0x004131F8: nop
    
            goto L_00413278;
    }
    // 0x004131F8: nop

    // 0x004131FC: lb          $v0, 0x2DC($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X2DC);
    // 0x00413200: bne         $v0, $s7, L_00413278
    if (ctx->r2 != ctx->r23) {
        // 0x00413204: nop
    
            goto L_00413278;
    }
    // 0x00413204: nop

    // 0x00413208: lhu         $v1, 0xD8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD8);
    // 0x0041320C: bne         $v1, $s6, L_00413224
    if (ctx->r3 != ctx->r22) {
        // 0x00413210: nop
    
            goto L_00413224;
    }
    // 0x00413210: nop

    // 0x00413214: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00413218: lw          $v0, 0x2FA8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FA8);
    // 0x0041321C: bne         $v0, $zero, L_0041326C
    if (ctx->r2 != 0) {
        // 0x00413220: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_0041326C;
    }
    // 0x00413220: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_00413224:
    // 0x00413224: bne         $v1, $s5, L_0041323C
    if (ctx->r3 != ctx->r21) {
        // 0x00413228: nop
    
            goto L_0041323C;
    }
    // 0x00413228: nop

    // 0x0041322C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00413230: lw          $v0, 0x2FB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FB0);
    // 0x00413234: bne         $v0, $zero, L_0041326C
    if (ctx->r2 != 0) {
        // 0x00413238: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_0041326C;
    }
    // 0x00413238: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_0041323C:
    // 0x0041323C: bne         $v1, $s4, L_00413254
    if (ctx->r3 != ctx->r20) {
        // 0x00413240: nop
    
            goto L_00413254;
    }
    // 0x00413240: nop

    // 0x00413244: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00413248: lw          $v0, 0x2FAC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FAC);
    // 0x0041324C: bne         $v0, $zero, L_0041326C
    if (ctx->r2 != 0) {
        // 0x00413250: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_0041326C;
    }
    // 0x00413250: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_00413254:
    // 0x00413254: bne         $v1, $s3, L_00413278
    if (ctx->r3 != ctx->r19) {
        // 0x00413258: nop
    
            goto L_00413278;
    }
    // 0x00413258: nop

    // 0x0041325C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x00413260: lw          $v0, 0x2FB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FB4);
    // 0x00413264: beq         $v0, $zero, L_00413278
    if (ctx->r2 == 0) {
        // 0x00413268: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00413278;
    }
    // 0x00413268: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_0041326C:
    // 0x0041326C: addiu       $a1, $s0, 0x168
    ctx->r5 = ADD32(ctx->r16, 0X168);
    // 0x00413270: jal         0x00287E14
    // 0x00413274: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_00287E14(rdram, ctx);
        goto after_33;
    // 0x00413274: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_33:
L_00413278:
    // 0x00413278: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x0041327C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x00413280: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x00413284: bne         $v0, $zero, L_004131EC
    if (ctx->r2 != 0) {
        // 0x00413288: addiu       $s0, $s0, 0x368
        ctx->r16 = ADD32(ctx->r16, 0X368);
            goto L_004131EC;
    }
    // 0x00413288: addiu       $s0, $s0, 0x368
    ctx->r16 = ADD32(ctx->r16, 0X368);
L_0041328C:
    // 0x0041328C: jal         0x002012E0
    // 0x00413290: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_002012E0(rdram, ctx);
        goto after_34;
    // 0x00413290: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_34:
    // 0x00413294: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x00413298: addiu       $a0, $a0, 0x2238
    ctx->r4 = ADD32(ctx->r4, 0X2238);
    // 0x0041329C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x004132A0: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x004132A4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x004132A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x004132AC: jal         0x00274180
    // 0x004132B0: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    func_00274180(rdram, ctx);
        goto after_35;
    // 0x004132B0: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    after_35:
    // 0x004132B4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x004132B8: addiu       $s0, $s0, -0x41B8
    ctx->r16 = ADD32(ctx->r16, -0X41B8);
    // 0x004132BC: jal         0x002354A8
    // 0x004132C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_002354A8(rdram, ctx);
        goto after_36;
    // 0x004132C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_36:
    // 0x004132C4: addiu       $s1, $s0, 0x100
    ctx->r17 = ADD32(ctx->r16, 0X100);
    // 0x004132C8: jal         0x0025F644
    // 0x004132CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0025F644(rdram, ctx);
        goto after_37;
    // 0x004132CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_37:
    // 0x004132D0: jal         0x0025D638
    // 0x004132D4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_0025D638(rdram, ctx);
        goto after_38;
    // 0x004132D4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_38:
    // 0x004132D8: lbu         $v0, 0x13F0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X13F0);
    // 0x004132DC: beq         $v0, $zero, L_004132EC
    if (ctx->r2 == 0) {
        // 0x004132E0: nop
    
            goto L_004132EC;
    }
    // 0x004132E0: nop

    // 0x004132E4: jal         0x00413FC4
    // 0x004132E8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_00413FC4(rdram, ctx);
        goto after_39;
    // 0x004132E8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_39:
L_004132EC:
    // 0x004132EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x004132F0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x004132F4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x004132F8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x004132FC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x00413300: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x00413304: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x00413308: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x0041330C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x00413310: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x00413314: jr          $ra
    // 0x00413318: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x00413318: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_0041331C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0041331C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x00413320: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x00413324: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x00413328: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x0041332C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x00413330: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x00413334: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x00413338: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x0041333C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x00413340: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x00413344: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x00413348: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x0041334C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x00413350: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x00413354: jal         0x00222E48
    // 0x00413358: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    func_00222E48(rdram, ctx);
        goto after_0;
    // 0x00413358: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // 0x0041335C: beq         $v0, $zero, L_004135C8
    if (ctx->r2 == 0) {
        // 0x00413360: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_004135C8;
    }
    // 0x00413360: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00413364: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x00413368: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x0041336C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x00413370: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x00413374: jal         0x002109A0
    // 0x00413378: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_002109A0(rdram, ctx);
        goto after_1;
    // 0x00413378: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x0041337C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x00413384: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x00413388: jal         0x002109A0
    // 0x0041338C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    func_002109A0(rdram, ctx);
        goto after_2;
    // 0x0041338C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_2:
    // 0x00413390: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413394: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x00413398: jal         0x0021098C
    // 0x0041339C: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    func_0021098C(rdram, ctx);
        goto after_3;
    // 0x0041339C: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    after_3:
    // 0x004133A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x004133A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x004133A8: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x004133AC: lw          $s6, 0x4($s5)
    ctx->r22 = MEM_W(ctx->r21, 0X4);
    // 0x004133B0: jal         0x002109A0
    // 0x004133B4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_002109A0(rdram, ctx);
        goto after_4;
    // 0x004133B4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x004133B8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x004133BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x004133C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004133C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x004133C8: sll         $v1, $s6, 5
    ctx->r3 = S32(ctx->r22 << 5);
    // 0x004133CC: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x004133D0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x004133D4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x004133D8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x004133DC: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x004133E0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x004133E4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x004133E8: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x004133EC: jal         0x00222294
    // 0x004133F0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    func_00222294(rdram, ctx);
        goto after_5;
    // 0x004133F0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    after_5:
    // 0x004133F4: beq         $v0, $zero, L_004135B8
    if (ctx->r2 == 0) {
        // 0x004133F8: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_004135B8;
    }
    // 0x004133F8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x004133FC: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x00413400: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00413404: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00413408: lw          $s4, 0x0($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X0);
    // 0x0041340C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x00413410: addu        $a1, $s4, $s3
    ctx->r5 = ADD32(ctx->r20, ctx->r19);
    // 0x00413414: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x00413418: jal         0x00210AE4
    // 0x0041341C: sw          $s3, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r19;
    func_00210AE4(rdram, ctx);
        goto after_6;
    // 0x0041341C: sw          $s3, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r19;
    after_6:
    // 0x00413420: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x00413424: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00413428: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x0041342C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00413430: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x00413434: addu        $s3, $v1, $s3
    ctx->r19 = ADD32(ctx->r3, ctx->r19);
    // 0x00413438: addu        $s1, $s4, $s3
    ctx->r17 = ADD32(ctx->r20, ctx->r19);
    // 0x0041343C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00413440: jal         0x00210AE4
    // 0x00413444: sw          $s3, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r19;
    func_00210AE4(rdram, ctx);
        goto after_7;
    // 0x00413444: sw          $s3, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r19;
    after_7:
    // 0x00413448: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x0041344C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00413450: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x00413454: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x00413458: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x0041345C: addu        $s3, $s3, $v1
    ctx->r19 = ADD32(ctx->r19, ctx->r3);
    // 0x00413460: addu        $s0, $s4, $s3
    ctx->r16 = ADD32(ctx->r20, ctx->r19);
    // 0x00413464: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00413468: jal         0x00210AE4
    // 0x0041346C: sw          $s3, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r19;
    func_00210AE4(rdram, ctx);
        goto after_8;
    // 0x0041346C: sw          $s3, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r19;
    after_8:
    // 0x00413470: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x00413474: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x00413478: addiu       $fp, $s0, 0x8
    ctx->r30 = ADD32(ctx->r16, 0X8);
    // 0x0041347C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x00413480: sw          $s6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r22;
    // 0x00413484: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x00413488: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    // 0x0041348C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x00413490: blez        $s7, L_004134B4
    if (SIGNED(ctx->r23) <= 0) {
        // 0x00413494: sw          $s1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r17;
            goto L_004134B4;
    }
    // 0x00413494: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x00413498: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_0041349C:
    // 0x0041349C: jal         0x0026CFB4
    // 0x004134A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_0026CFB4(rdram, ctx);
        goto after_9;
    // 0x004134A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x004134A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x004134A8: slt         $v0, $s2, $s7
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x004134AC: bne         $v0, $zero, L_0041349C
    if (ctx->r2 != 0) {
        // 0x004134B0: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_0041349C;
    }
    // 0x004134B0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_004134B4:
    // 0x004134B4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x004134B8: sw          $fp, 0x2268($at)
    MEM_W(0X2268, ctx->r1) = ctx->r30;
    // 0x004134BC: blez        $s6, L_0041357C
    if (SIGNED(ctx->r22) <= 0) {
        // 0x004134C0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_0041357C;
    }
    // 0x004134C0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x004134C4: addu        $s2, $fp, $zero
    ctx->r18 = ADD32(ctx->r30, 0);
L_004134C8:
    // 0x004134C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x004134CC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x004134D0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x004134D4: addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // 0x004134D8: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x004134DC: jal         0x0026D000
    // 0x004134E0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    func_0026D000(rdram, ctx);
        goto after_10;
    // 0x004134E0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_10:
    // 0x004134E4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x004134E8: lw          $a0, 0x74($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X74);
    // 0x004134EC: lw          $s0, 0x1774($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X1774);
    // 0x004134F0: jal         0x0021098C
    // 0x004134F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_11;
    // 0x004134F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_11:
    // 0x004134F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x004134FC: jal         0x0021098C
    // 0x00413500: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0021098C(rdram, ctx);
        goto after_12;
    // 0x00413500: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_12:
    // 0x00413504: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00413508: jal         0x0021098C
    // 0x0041350C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_13;
    // 0x0041350C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_13:
    // 0x00413510: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00413514: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413518: jal         0x0021098C
    // 0x0041351C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_14;
    // 0x0041351C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_14:
    // 0x00413520: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413524: jal         0x0021098C
    // 0x00413528: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_0021098C(rdram, ctx);
        goto after_15;
    // 0x00413528: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x0041352C: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x00413530: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00413534: andi        $v0, $s1, 0x7
    ctx->r2 = ctx->r17 & 0X7;
    // 0x00413538: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x0041353C: bgez        $s1, L_00413548
    if (SIGNED(ctx->r17) >= 0) {
        // 0x00413540: sllv        $a1, $t0, $v0
        ctx->r5 = S32(ctx->r8 << (ctx->r2 & 31));
            goto L_00413548;
    }
    // 0x00413540: sllv        $a1, $t0, $v0
    ctx->r5 = S32(ctx->r8 << (ctx->r2 & 31));
    // 0x00413544: addiu       $v1, $s1, 0x7
    ctx->r3 = ADD32(ctx->r17, 0X7);
L_00413548:
    // 0x00413548: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x0041354C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x00413550: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x00413554: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x00413558: beq         $v0, $zero, L_0041356C
    if (ctx->r2 == 0) {
        // 0x0041355C: addiu       $s5, $s5, 0x14
        ctx->r21 = ADD32(ctx->r21, 0X14);
            goto L_0041356C;
    }
    // 0x0041355C: addiu       $s5, $s5, 0x14
    ctx->r21 = ADD32(ctx->r21, 0X14);
    // 0x00413560: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x00413564: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x00413568: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_0041356C:
    // 0x0041356C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x00413570: slt         $v0, $s1, $s6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x00413574: bne         $v0, $zero, L_004134C8
    if (ctx->r2 != 0) {
        // 0x00413578: addiu       $s2, $s2, 0x20
        ctx->r18 = ADD32(ctx->r18, 0X20);
            goto L_004134C8;
    }
    // 0x00413578: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
L_0041357C:
    // 0x0041357C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x00413580: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x00413584: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x00413588: addu        $s3, $s3, $t0
    ctx->r19 = ADD32(ctx->r19, ctx->r8);
    // 0x0041358C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x00413590: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x00413594: addu        $a1, $t0, $s3
    ctx->r5 = ADD32(ctx->r8, ctx->r19);
    // 0x00413598: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x0041359C: jal         0x00210AE4
    // 0x004135A0: sw          $s3, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r19;
    func_00210AE4(rdram, ctx);
        goto after_16;
    // 0x004135A0: sw          $s3, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r19;
    after_16:
    // 0x004135A4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x004135A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x004135AC: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x004135B0: addu        $s3, $s3, $v1
    ctx->r19 = ADD32(ctx->r19, ctx->r3);
    // 0x004135B4: sw          $s3, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r19;
L_004135B8:
    // 0x004135B8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x004135BC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x004135C0: jal         0x00221CC8
    // 0x004135C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_00221CC8(rdram, ctx);
        goto after_17;
    // 0x004135C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_17:
L_004135C8:
    // 0x004135C8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x004135CC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x004135D0: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x004135D4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x004135D8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x004135DC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x004135E0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x004135E4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x004135E8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x004135EC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x004135F0: jr          $ra
    // 0x004135F4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x004135F4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_004135F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004135F8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x004135FC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x00413600: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x00413604: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x00413608: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x0041360C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x00413610: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x00413614: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x00413618: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x0041361C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x00413620: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x00413624: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x00413628: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x0041362C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x00413630: sdc1        $f23, 0x58($sp)
    CHECK_FR(ctx, 23);
    SD(ctx->f23.u64, 0X58, ctx->r29);
    // 0x00413634: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x00413638: sdc1        $f21, 0x48($sp)
    CHECK_FR(ctx, 21);
    SD(ctx->f21.u64, 0X48, ctx->r29);
    // 0x0041363C: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x00413640: jal         0x00222E48
    // 0x00413644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_00222E48(rdram, ctx);
        goto after_0;
    // 0x00413644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x00413648: beq         $v0, $zero, L_00413A44
    if (ctx->r2 == 0) {
        // 0x0041364C: nop
    
            goto L_00413A44;
    }
    // 0x0041364C: nop

    // 0x00413650: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x00413654: jal         0x00203C04
    // 0x00413658: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_00203C04(rdram, ctx);
        goto after_1;
    // 0x00413658: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x0041365C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x00413660: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x00413664: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x00413668: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x0041366C: lw          $s4, 0x4($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X4);
    // 0x00413670: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x00413674: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x00413678: sll         $a2, $s4, 3
    ctx->r6 = S32(ctx->r20 << 3);
    // 0x0041367C: subu        $a2, $a2, $s4
    ctx->r6 = SUB32(ctx->r6, ctx->r20);
    // 0x00413680: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x00413684: subu        $a2, $a2, $s4
    ctx->r6 = SUB32(ctx->r6, ctx->r20);
    // 0x00413688: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x0041368C: addu        $a2, $a2, $s4
    ctx->r6 = ADD32(ctx->r6, ctx->r20);
    // 0x00413690: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x00413694: jal         0x00222294
    // 0x00413698: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    func_00222294(rdram, ctx);
        goto after_2;
    // 0x00413698: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    after_2:
    // 0x0041369C: beq         $v0, $zero, L_004139CC
    if (ctx->r2 == 0) {
        // 0x004136A0: sw          $v0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r2;
            goto L_004139CC;
    }
    // 0x004136A0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x004136A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x004136A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x004136AC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x004136B0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x004136B4: jal         0x00210AE4
    // 0x004136B8: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    func_00210AE4(rdram, ctx);
        goto after_3;
    // 0x004136B8: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    after_3:
    // 0x004136BC: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x004136C0: addiu       $v1, $zero, 0x368
    ctx->r3 = ADD32(0, 0X368);
    // 0x004136C4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x004136C8: addiu       $s2, $s0, 0x8
    ctx->r18 = ADD32(ctx->r16, 0X8);
    // 0x004136CC: addiu       $fp, $v0, 0x8
    ctx->r30 = ADD32(ctx->r2, 0X8);
    // 0x004136D0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x004136D4: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x004136D8: sw          $fp, 0xEC($s7)
    MEM_W(0XEC, ctx->r23) = ctx->r30;
    // 0x004136DC: blez        $s4, L_00413718
    if (SIGNED(ctx->r20) <= 0) {
        // 0x004136E0: sw          $s4, 0xF4($s7)
        MEM_W(0XF4, ctx->r23) = ctx->r20;
            goto L_00413718;
    }
    // 0x004136E0: sw          $s4, 0xF4($s7)
    MEM_W(0XF4, ctx->r23) = ctx->r20;
    // 0x004136E4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_004136E8:
    // 0x004136E8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x004136EC: lhu         $a1, 0x22($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X22);
    // 0x004136F0: jal         0x0020542C
    // 0x004136F4: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_0020542C(rdram, ctx);
        goto after_4;
    // 0x004136F4: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_4:
    // 0x004136F8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x004136FC: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x00413700: bnel        $v0, $zero, L_00413708
    if (ctx->r2 != 0) {
        // 0x00413704: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_00413708;
    }
    goto skip_0;
    // 0x00413704: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
L_00413708:
    // 0x00413708: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x0041370C: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x00413710: bne         $v0, $zero, L_004136E8
    if (ctx->r2 != 0) {
        // 0x00413714: addiu       $a1, $s0, 0x28
        ctx->r5 = ADD32(ctx->r16, 0X28);
            goto L_004136E8;
    }
    // 0x00413714: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
L_00413718:
    // 0x00413718: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x0041371C: addiu       $a0, $a0, 0x6BC0
    ctx->r4 = ADD32(ctx->r4, 0X6BC0);
    // 0x00413720: jal         0x0023AA80
    // 0x00413724: addiu       $a1, $s1, 0x21
    ctx->r5 = ADD32(ctx->r17, 0X21);
    func_0023AA80(rdram, ctx);
        goto after_5;
    // 0x00413724: addiu       $a1, $s1, 0x21
    ctx->r5 = ADD32(ctx->r17, 0X21);
    after_5:
    // 0x00413728: blez        $s4, L_00413768
    if (SIGNED(ctx->r20) <= 0) {
        // 0x0041372C: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_00413768;
    }
    // 0x0041372C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x00413730: addu        $v1, $fp, $zero
    ctx->r3 = ADD32(ctx->r30, 0);
    // 0x00413734: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_00413738:
    // 0x00413738: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x0041373C: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // 0x00413740: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x00413744: lhu         $a1, 0x22($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X22);
    // 0x00413748: jal         0x0020542C
    // 0x0041374C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    func_0020542C(rdram, ctx);
        goto after_6;
    // 0x0041374C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_6:
    // 0x00413750: addiu       $v1, $s1, 0x368
    ctx->r3 = ADD32(ctx->r17, 0X368);
    // 0x00413754: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x00413758: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x0041375C: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x00413760: bne         $v0, $zero, L_00413738
    if (ctx->r2 != 0) {
        // 0x00413764: sw          $zero, 0xF4($s1)
        MEM_W(0XF4, ctx->r17) = 0;
            goto L_00413738;
    }
    // 0x00413764: sw          $zero, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = 0;
L_00413768:
    // 0x00413768: sw          $zero, 0xF0($s7)
    MEM_W(0XF0, ctx->r23) = 0;
    // 0x0041376C: blez        $s4, L_004137CC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x00413770: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_004137CC;
    }
    // 0x00413770: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x00413774: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x00413778: addu        $s1, $fp, $zero
    ctx->r17 = ADD32(ctx->r30, 0);
    // 0x0041377C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_00413780:
    // 0x00413780: lhu         $a1, 0x22($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X22);
    // 0x00413784: jal         0x0020542C
    // 0x00413788: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_0020542C(rdram, ctx);
        goto after_7;
    // 0x00413788: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_7:
    // 0x0041378C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x00413790: bne         $v0, $s5, L_004137A8
    if (ctx->r2 != ctx->r21) {
        // 0x00413794: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_004137A8;
    }
    // 0x00413794: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00413798: lw          $v0, 0xF0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0XF0);
    // 0x0041379C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x004137A0: j           L_004137B8
    // 0x004137A4: sw          $v0, 0xF0($s7)
    MEM_W(0XF0, ctx->r23) = ctx->r2;
        goto L_004137B8;
    // 0x004137A4: sw          $v0, 0xF0($s7)
    MEM_W(0XF0, ctx->r23) = ctx->r2;
L_004137A8:
    // 0x004137A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x004137AC: lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X10);
    // 0x004137B0: jal         0x00219C88
    // 0x004137B4: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_00219C88(rdram, ctx);
        goto after_8;
    // 0x004137B4: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_8:
L_004137B8:
    // 0x004137B8: addiu       $s1, $s1, 0x368
    ctx->r17 = ADD32(ctx->r17, 0X368);
    // 0x004137BC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x004137C0: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x004137C4: bne         $v0, $zero, L_00413780
    if (ctx->r2 != 0) {
        // 0x004137C8: addiu       $s0, $s0, 0x28
        ctx->r16 = ADD32(ctx->r16, 0X28);
            goto L_00413780;
    }
    // 0x004137C8: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
L_004137CC:
    // 0x004137CC: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x004137D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x004137D4: lw          $v0, -0x41B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B0);
    // 0x004137D8: blez        $v0, L_004138B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x004137DC: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_004138B4;
    }
    // 0x004137DC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x004137E0: addu        $s5, $s2, $zero
    ctx->r21 = ADD32(ctx->r18, 0);
    // 0x004137E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x004137E8: lwc1        $f20, 0x7520($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7520);
    // 0x004137EC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x004137F0: lwc1        $f23, 0x7524($at)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r1, 0X7524);
    // 0x004137F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x004137F8: lwc1        $f22, 0x7528($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7528);
L_004137FC:
    // 0x004137FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x00413800: lw          $v0, -0x41B4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B4);
    // 0x00413804: lw          $v1, 0x1864($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X1864);
    // 0x00413808: beq         $v1, $zero, L_00413888
    if (ctx->r3 == 0) {
        // 0x0041380C: addu        $s6, $v0, $s5
        ctx->r22 = ADD32(ctx->r2, ctx->r21);
            goto L_00413888;
    }
    // 0x0041380C: addu        $s6, $v0, $s5
    ctx->r22 = ADD32(ctx->r2, ctx->r21);
    // 0x00413810: addiu       $s1, $s7, 0x1868
    ctx->r17 = ADD32(ctx->r23, 0X1868);
    // 0x00413814: lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X12);
    // 0x00413818: addiu       $a0, $s7, 0x1874
    ctx->r4 = ADD32(ctx->r23, 0X1874);
    // 0x0041381C: jal         0x00215038
    // 0x00413820: sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    func_00215038(rdram, ctx);
        goto after_9;
    // 0x00413820: sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    after_9:
    // 0x00413824: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x00413828: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x0041382C: nop

    // 0x00413830: bc1t        L_0041386C
    if (c1cs) {
        // 0x00413834: addiu       $v0, $zero, 0x7FFF
        ctx->r2 = ADD32(0, 0X7FFF);
            goto L_0041386C;
    }
    // 0x00413834: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x00413838: c.lt.s      $f0, $f23
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 23);
    c1cs = ctx->f0.fl < ctx->f23.fl;
    // 0x0041383C: nop

    // 0x00413840: bc1t        L_0041386C
    if (c1cs) {
        // 0x00413844: addiu       $v0, $zero, -0x7FFF
        ctx->r2 = ADD32(0, -0X7FFF);
            goto L_0041386C;
    }
    // 0x00413844: addiu       $v0, $zero, -0x7FFF
    ctx->r2 = ADD32(0, -0X7FFF);
    // 0x00413848: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x0041384C: nop

    // 0x00413850: bc1t        L_0041386C
    if (c1cs) {
        // 0x00413854: addiu       $v0, $zero, 0x7FFF
        ctx->r2 = ADD32(0, 0X7FFF);
            goto L_0041386C;
    }
    // 0x00413854: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x00413858: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x0041385C: trunc.w.s   $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    ctx->f_odd[(1 - 1) * 2] = TRUNC_W_S(ctx->f0.fl);
    // 0x00413860: mfc1        $v0, $f1
    ctx->r2 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x00413864: j           L_00413870
    // 0x00413868: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
        goto L_00413870;
    // 0x00413868: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
L_0041386C:
    // 0x0041386C: sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
L_00413870:
    // 0x00413870: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x00413874: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x00413878: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x0041387C: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x00413880: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x00413884: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
L_00413888:
    // 0x00413888: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x0041388C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00413890: lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X10);
    // 0x00413894: jal         0x0022D870
    // 0x00413898: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_0022D870(rdram, ctx);
        goto after_10;
    // 0x00413898: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_10:
    // 0x0041389C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x004138A0: lw          $v0, -0x41B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X41B0);
    // 0x004138A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x004138A8: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x004138AC: bne         $v0, $zero, L_004137FC
    if (ctx->r2 != 0) {
        // 0x004138B0: addiu       $s5, $s5, 0x15C0
        ctx->r21 = ADD32(ctx->r21, 0X15C0);
            goto L_004137FC;
    }
    // 0x004138B0: addiu       $s5, $s5, 0x15C0
    ctx->r21 = ADD32(ctx->r21, 0X15C0);
L_004138B4:
    // 0x004138B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x004138B8: sw          $zero, -0x4034($at)
    MEM_W(-0X4034, ctx->r1) = 0;
    // 0x004138BC: lw          $s3, 0xF0($s7)
    ctx->r19 = MEM_W(ctx->r23, 0XF0);
    // 0x004138C0: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x004138C4: beq         $v0, $zero, L_004139CC
    if (ctx->r2 == 0) {
        // 0x004138C8: sll         $v0, $s3, 3
        ctx->r2 = S32(ctx->r19 << 3);
            goto L_004139CC;
    }
    // 0x004138C8: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x004138CC: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x004138D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x004138D4: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x004138D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x004138DC: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x004138E0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x004138E4: addu        $s5, $v0, $fp
    ctx->r21 = ADD32(ctx->r2, ctx->r30);
L_004138E8:
    // 0x004138E8: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    // 0x004138EC: sw          $zero, 0x1CC($s1)
    MEM_W(0X1CC, ctx->r17) = 0;
    // 0x004138F0: jal         0x00228DBC
    // 0x004138F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00228DBC(rdram, ctx);
        goto after_11;
    // 0x004138F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_11:
    // 0x004138F8: beql        $v0, $zero, L_004139C0
    if (ctx->r2 == 0) {
        // 0x004138FC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_004139C0;
    }
    goto skip_1;
    // 0x004138FC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x00413900: lw          $s2, 0xF0($s7)
    ctx->r18 = MEM_W(ctx->r23, 0XF0);
    // 0x00413904: slt         $v0, $s2, $s4
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x00413908: beq         $v0, $zero, L_004139BC
    if (ctx->r2 == 0) {
        // 0x0041390C: sll         $v0, $s2, 3
        ctx->r2 = S32(ctx->r18 << 3);
            goto L_004139BC;
    }
    // 0x0041390C: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x00413910: subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // 0x00413914: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413918: subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // 0x0041391C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413920: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x00413924: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x00413928: addu        $s0, $v0, $fp
    ctx->r16 = ADD32(ctx->r2, ctx->r30);
L_0041392C:
    // 0x0041392C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x00413930: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x00413934: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x00413938: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x0041393C: bnel        $a0, $v0, L_004139B0
    if (ctx->r4 != ctx->r2) {
        // 0x00413940: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_004139B0;
    }
    goto skip_2;
    // 0x00413940: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x00413944: jal         0x00228D7C
    // 0x00413948: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00228D7C(rdram, ctx);
        goto after_12;
    // 0x00413948: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x0041394C: beql        $v0, $zero, L_004139B0
    if (ctx->r2 == 0) {
        // 0x00413950: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_004139B0;
    }
    goto skip_3;
    // 0x00413950: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x00413954: beql        $s1, $s0, L_004139B0
    if (ctx->r17 == ctx->r16) {
        // 0x00413958: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_004139B0;
    }
    goto skip_4;
    // 0x00413958: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x0041395C: lw          $v0, 0x1CC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1CC);
    // 0x00413960: beql        $v0, $zero, L_00413994
    if (ctx->r2 == 0) {
        // 0x00413964: sw          $s0, 0x1CC($s1)
        MEM_W(0X1CC, ctx->r17) = ctx->r16;
            goto L_00413994;
    }
    goto skip_5;
    // 0x00413964: sw          $s0, 0x1CC($s1)
    MEM_W(0X1CC, ctx->r17) = ctx->r16;
    skip_5:
    // 0x00413968: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x0041396C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x00413970: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x00413974: jal         0x00241F5C
    // 0x00413978: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00241F5C(rdram, ctx);
        goto after_13;
    // 0x00413978: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // 0x0041397C: c.lt.s      $f0, $f21
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    c1cs = ctx->f0.fl < ctx->f21.fl;
    // 0x00413980: nop

    // 0x00413984: bc1fl       L_004139B0
    if (!c1cs) {
        // 0x00413988: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_004139B0;
    }
    goto skip_6;
    // 0x00413988: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x0041398C: j           L_004139A8
    // 0x00413990: sw          $s0, 0x1CC($s1)
    MEM_W(0X1CC, ctx->r17) = ctx->r16;
        goto L_004139A8;
    // 0x00413990: sw          $s0, 0x1CC($s1)
    MEM_W(0X1CC, ctx->r17) = ctx->r16;
L_00413994:
    // 0x00413994: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x00413998: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x0041399C: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x004139A0: jal         0x00241F5C
    // 0x004139A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00241F5C(rdram, ctx);
        goto after_14;
    // 0x004139A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_14:
L_004139A8:
    // 0x004139A8: mov.s       $f21, $f0
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 0);
    ctx->f21.fl = ctx->f0.fl;
    // 0x004139AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_004139B0:
    // 0x004139B0: slt         $v0, $s2, $s4
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x004139B4: bne         $v0, $zero, L_0041392C
    if (ctx->r2 != 0) {
        // 0x004139B8: addiu       $s0, $s0, 0x368
        ctx->r16 = ADD32(ctx->r16, 0X368);
            goto L_0041392C;
    }
    // 0x004139B8: addiu       $s0, $s0, 0x368
    ctx->r16 = ADD32(ctx->r16, 0X368);
L_004139BC:
    // 0x004139BC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_004139C0:
    // 0x004139C0: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x004139C4: bne         $v0, $zero, L_004138E8
    if (ctx->r2 != 0) {
        // 0x004139C8: addiu       $s5, $s5, 0x368
        ctx->r21 = ADD32(ctx->r21, 0X368);
            goto L_004138E8;
    }
    // 0x004139C8: addiu       $s5, $s5, 0x368
    ctx->r21 = ADD32(ctx->r21, 0X368);
L_004139CC:
    // 0x004139CC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x004139D0: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x004139D4: jal         0x00221CC8
    // 0x004139D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_00221CC8(rdram, ctx);
        goto after_15;
    // 0x004139D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // 0x004139DC: sw          $zero, 0xF14($s7)
    MEM_W(0XF14, ctx->r23) = 0;
    // 0x004139E0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x004139E4: lw          $v1, -0x2CC0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2CC0);
    // 0x004139E8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x004139EC: bne         $v1, $v0, L_00413A44
    if (ctx->r3 != ctx->r2) {
        // 0x004139F0: nop
    
            goto L_00413A44;
    }
    // 0x004139F0: nop

    // 0x004139F4: lw          $s3, 0xF0($s7)
    ctx->r19 = MEM_W(ctx->r23, 0XF0);
    // 0x004139F8: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x004139FC: beq         $v0, $zero, L_00413A44
    if (ctx->r2 == 0) {
        // 0x00413A00: sll         $v0, $s3, 3
        ctx->r2 = S32(ctx->r19 << 3);
            goto L_00413A44;
    }
    // 0x00413A00: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x00413A04: lui         $a0, 0xFFEF
    ctx->r4 = S32(0XFFEF << 16);
    // 0x00413A08: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x00413A0C: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x00413A10: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413A14: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x00413A18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413A1C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x00413A20: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x00413A24: addu        $v1, $v0, $fp
    ctx->r3 = ADD32(ctx->r2, ctx->r30);
L_00413A28:
    // 0x00413A28: lw          $v0, 0xF4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XF4);
    // 0x00413A2C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x00413A30: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x00413A34: sw          $v0, 0xF4($v1)
    MEM_W(0XF4, ctx->r3) = ctx->r2;
    // 0x00413A38: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x00413A3C: bne         $v0, $zero, L_00413A28
    if (ctx->r2 != 0) {
        // 0x00413A40: addiu       $v1, $v1, 0x368
        ctx->r3 = ADD32(ctx->r3, 0X368);
            goto L_00413A28;
    }
    // 0x00413A40: addiu       $v1, $v1, 0x368
    ctx->r3 = ADD32(ctx->r3, 0X368);
L_00413A44:
    // 0x00413A44: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x00413A48: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x00413A4C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x00413A50: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x00413A54: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x00413A58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x00413A5C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x00413A60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x00413A64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x00413A68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x00413A6C: ldc1        $f23, 0x58($sp)
    CHECK_FR(ctx, 23);
    ctx->f23.u64 = LD(ctx->r29, 0X58);
    // 0x00413A70: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x00413A74: ldc1        $f21, 0x48($sp)
    CHECK_FR(ctx, 21);
    ctx->f21.u64 = LD(ctx->r29, 0X48);
    // 0x00413A78: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x00413A7C: jr          $ra
    // 0x00413A80: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x00413A80: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_00413A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00413A84: addiu       $sp, $sp, -0x290
    ctx->r29 = ADD32(ctx->r29, -0X290);
    // 0x00413A88: sw          $s7, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r23;
    // 0x00413A8C: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x00413A90: sw          $a1, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r5;
    // 0x00413A94: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x00413A98: sw          $ra, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r31;
    // 0x00413A9C: sw          $fp, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r30;
    // 0x00413AA0: sw          $s6, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->r22;
    // 0x00413AA4: sw          $s5, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r21;
    // 0x00413AA8: sw          $s4, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->r20;
    // 0x00413AAC: sw          $s3, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r19;
    // 0x00413AB0: sw          $s2, 0x268($sp)
    MEM_W(0X268, ctx->r29) = ctx->r18;
    // 0x00413AB4: sw          $s1, 0x264($sp)
    MEM_W(0X264, ctx->r29) = ctx->r17;
    // 0x00413AB8: sw          $s0, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r16;
    // 0x00413ABC: sdc1        $f20, 0x288($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X288, ctx->r29);
    // 0x00413AC0: jal         0x00222E48
    // 0x00413AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_00222E48(rdram, ctx);
        goto after_0;
    // 0x00413AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x00413AC8: beq         $v0, $zero, L_00413F90
    if (ctx->r2 == 0) {
        // 0x00413ACC: nop
    
            goto L_00413F90;
    }
    // 0x00413ACC: nop

    // 0x00413AD0: lw          $t0, 0x294($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X294);
    // 0x00413AD4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x00413AD8: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x00413ADC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x00413AE0: beq         $v0, $zero, L_00413F90
    if (ctx->r2 == 0) {
        // 0x00413AE4: nop
    
            goto L_00413F90;
    }
    // 0x00413AE4: nop

    // 0x00413AE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413AEC: jal         0x0021098C
    // 0x00413AF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x00413AF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x00413AF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413AF8: sw          $v0, 0x228($sp)
    MEM_W(0X228, ctx->r29) = ctx->r2;
    // 0x00413AFC: lw          $s4, 0x4($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X4);
    // 0x00413B00: jal         0x0021098C
    // 0x00413B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_0021098C(rdram, ctx);
        goto after_2;
    // 0x00413B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x00413B08: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413B0C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x00413B10: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x00413B14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x00413B18: addu        $s1, $s4, $t1
    ctx->r17 = ADD32(ctx->r20, ctx->r9);
    // 0x00413B1C: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x00413B20: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x00413B24: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x00413B28: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x00413B2C: sw          $t1, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->r9;
    // 0x00413B30: jal         0x0021098C
    // 0x00413B34: sw          $v0, 0x240($sp)
    MEM_W(0X240, ctx->r29) = ctx->r2;
    func_0021098C(rdram, ctx);
        goto after_3;
    // 0x00413B34: sw          $v0, 0x240($sp)
    MEM_W(0X240, ctx->r29) = ctx->r2;
    after_3:
    // 0x00413B38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413B3C: sw          $v0, 0x22C($sp)
    MEM_W(0X22C, ctx->r29) = ctx->r2;
    // 0x00413B40: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x00413B44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x00413B48: sllv        $v0, $t2, $a1
    ctx->r2 = S32(ctx->r10 << (ctx->r5 & 31));
    // 0x00413B4C: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x00413B50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413B54: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x00413B58: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x00413B5C: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x00413B60: sw          $t2, 0x23C($sp)
    MEM_W(0X23C, ctx->r29) = ctx->r10;
    // 0x00413B64: jal         0x0021098C
    // 0x00413B68: sw          $v0, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r2;
    func_0021098C(rdram, ctx);
        goto after_4;
    // 0x00413B68: sw          $v0, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r2;
    after_4:
    // 0x00413B6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00413B70: lw          $a1, 0x294($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X294);
    // 0x00413B74: addiu       $v1, $zero, -0x8
    ctx->r3 = ADD32(0, -0X8);
    // 0x00413B78: sw          $v0, 0x230($sp)
    MEM_W(0X230, ctx->r29) = ctx->r2;
    // 0x00413B7C: lw          $fp, 0x4($v0)
    ctx->r30 = MEM_W(ctx->r2, 0X4);
    // 0x00413B80: lw          $t3, 0x244($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X244);
    // 0x00413B84: lw          $t0, 0x240($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X240);
    // 0x00413B88: sll         $v0, $fp, 1
    ctx->r2 = S32(ctx->r30 << 1);
    // 0x00413B8C: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x00413B90: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x00413B94: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x00413B98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413B9C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x00413BA0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x00413BA4: addiu       $a2, $t3, 0x18
    ctx->r6 = ADD32(ctx->r11, 0X18);
    // 0x00413BA8: addu        $a2, $t0, $a2
    ctx->r6 = ADD32(ctx->r8, ctx->r6);
    // 0x00413BAC: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x00413BB0: jal         0x00222294
    // 0x00413BB4: sw          $v0, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r2;
    func_00222294(rdram, ctx);
        goto after_5;
    // 0x00413BB4: sw          $v0, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r2;
    after_5:
    // 0x00413BB8: beq         $v0, $zero, L_00413F80
    if (ctx->r2 == 0) {
        // 0x00413BBC: sw          $v0, 0x25C($sp)
        MEM_W(0X25C, ctx->r29) = ctx->r2;
            goto L_00413F80;
    }
    // 0x00413BBC: sw          $v0, 0x25C($sp)
    MEM_W(0X25C, ctx->r29) = ctx->r2;
    // 0x00413BC0: addiu       $s6, $zero, 0x18
    ctx->r22 = ADD32(0, 0X18);
    // 0x00413BC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x00413BC8: addu        $a2, $t1, $zero
    ctx->r6 = ADD32(ctx->r9, 0);
    // 0x00413BCC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x00413BD0: sw          $t1, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = ctx->r9;
    // 0x00413BD4: lw          $s5, 0x0($v0)
    ctx->r21 = MEM_W(ctx->r2, 0X0);
    // 0x00413BD8: lw          $a0, 0x228($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X228);
    // 0x00413BDC: addu        $s0, $s5, $s6
    ctx->r16 = ADD32(ctx->r21, ctx->r22);
    // 0x00413BE0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00413BE4: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x00413BE8: jal         0x00210AE4
    // 0x00413BEC: sw          $s6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r22;
    func_00210AE4(rdram, ctx);
        goto after_6;
    // 0x00413BEC: sw          $s6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r22;
    after_6:
    // 0x00413BF0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x00413BF4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00413BF8: jal         0x00210AE4
    // 0x00413BFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_00210AE4(rdram, ctx);
        goto after_7;
    // 0x00413BFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x00413C00: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // 0x00413C04: sw          $v0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r2;
    // 0x00413C08: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x00413C0C: lw          $a0, 0x5C($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X5C);
    // 0x00413C10: jal         0x0021098C
    // 0x00413C14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_0021098C(rdram, ctx);
        goto after_8;
    // 0x00413C14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x00413C18: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x00413C1C: sw          $s3, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r19;
    // 0x00413C20: addiu       $s3, $s5, 0x20
    ctx->r19 = ADD32(ctx->r21, 0X20);
    // 0x00413C24: lw          $t2, 0x228($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X228);
    // 0x00413C28: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x00413C2C: sw          $s5, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->r21;
    // 0x00413C30: sw          $v0, 0x258($sp)
    MEM_W(0X258, ctx->r29) = ctx->r2;
    // 0x00413C34: blez        $s4, L_00413C88
    if (SIGNED(ctx->r20) <= 0) {
        // 0x00413C38: addiu       $s0, $t2, 0x8
        ctx->r16 = ADD32(ctx->r10, 0X8);
            goto L_00413C88;
    }
    // 0x00413C38: addiu       $s0, $t2, 0x8
    ctx->r16 = ADD32(ctx->r10, 0X8);
    // 0x00413C3C: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
L_00413C40:
    // 0x00413C40: lw          $a0, 0x40($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X40);
    // 0x00413C44: lw          $a1, 0x18($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X18);
    // 0x00413C48: lhu         $a2, 0x8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X8);
    // 0x00413C4C: jal         0x00210A00
    // 0x00413C50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    func_00210A00(rdram, ctx);
        goto after_9;
    // 0x00413C50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_9:
    // 0x00413C54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00413C58: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00413C5C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x00413C60: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
    // 0x00413C64: lw          $v0, 0x174C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X174C);
    // 0x00413C68: lw          $a3, 0x258($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X258);
    // 0x00413C6C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x00413C70: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x00413C74: jal         0x002271D8
    // 0x00413C78: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_002271D8(rdram, ctx);
        goto after_10;
    // 0x00413C78: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x00413C7C: slt         $v0, $s2, $s4
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x00413C80: bne         $v0, $zero, L_00413C40
    if (ctx->r2 != 0) {
        // 0x00413C84: nop
    
            goto L_00413C40;
    }
    // 0x00413C84: nop

L_00413C88:
    // 0x00413C88: lw          $t3, 0x238($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X238);
    // 0x00413C8C: blez        $t3, L_00413CE4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x00413C90: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_00413CE4;
    }
    // 0x00413C90: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x00413C94: lw          $s1, 0x250($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X250);
L_00413C98:
    // 0x00413C98: lw          $a0, 0x40($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X40);
    // 0x00413C9C: lw          $a1, 0x18($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X18);
    // 0x00413CA0: lhu         $a2, 0x28($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X28);
    // 0x00413CA4: jal         0x00210A00
    // 0x00413CA8: nop

    func_00210A00(rdram, ctx);
        goto after_11;
    // 0x00413CA8: nop

    after_11:
    // 0x00413CAC: addu        $v1, $s0, $s4
    ctx->r3 = ADD32(ctx->r16, ctx->r20);
    // 0x00413CB0: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    // 0x00413CB4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x00413CB8: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x00413CBC: addu        $a0, $s3, $a0
    ctx->r4 = ADD32(ctx->r19, ctx->r4);
    // 0x00413CC0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00413CC4: lw          $a3, 0x258($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X258);
    // 0x00413CC8: jal         0x002274D0
    // 0x00413CCC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_002274D0(rdram, ctx);
        goto after_12;
    // 0x00413CCC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_12:
    // 0x00413CD0: lw          $t0, 0x238($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X238);
    // 0x00413CD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x00413CD8: slt         $v0, $s0, $t0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x00413CDC: bne         $v0, $zero, L_00413C98
    if (ctx->r2 != 0) {
        // 0x00413CE0: addiu       $s1, $s1, 0x34
        ctx->r17 = ADD32(ctx->r17, 0X34);
            goto L_00413C98;
    }
    // 0x00413CE0: addiu       $s1, $s1, 0x34
    ctx->r17 = ADD32(ctx->r17, 0X34);
L_00413CE4:
    // 0x00413CE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00413CE8: lw          $t1, 0x240($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X240);
    // 0x00413CEC: lw          $t2, 0x24C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24C);
    // 0x00413CF0: addu        $s6, $s6, $t1
    ctx->r22 = ADD32(ctx->r22, ctx->r9);
    // 0x00413CF4: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    // 0x00413CF8: lw          $a0, 0x22C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X22C);
    // 0x00413CFC: lw          $t3, 0x234($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X234);
    // 0x00413D00: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x00413D04: sw          $t2, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = ctx->r10;
    // 0x00413D08: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x00413D0C: addu        $s0, $t3, $s6
    ctx->r16 = ADD32(ctx->r11, ctx->r22);
    // 0x00413D10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00413D14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413D18: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x00413D1C: jal         0x00210AE4
    // 0x00413D20: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    func_00210AE4(rdram, ctx);
        goto after_13;
    // 0x00413D20: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    after_13:
    // 0x00413D24: addiu       $v0, $zero, 0x1B0
    ctx->r2 = ADD32(0, 0X1B0);
    // 0x00413D28: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x00413D2C: lw          $t0, 0x23C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X23C);
    // 0x00413D30: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x00413D34: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x00413D38: lw          $t1, 0x22C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X22C);
    // 0x00413D3C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x00413D40: sw          $s0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r16;
    // 0x00413D44: blez        $t0, L_00413E18
    if (SIGNED(ctx->r8) <= 0) {
        // 0x00413D48: addiu       $a1, $t1, 0x8
        ctx->r5 = ADD32(ctx->r9, 0X8);
            goto L_00413E18;
    }
    // 0x00413D48: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x00413D4C: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x00413D50: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
L_00413D54:
    // 0x00413D54: lw          $a0, 0x40($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X40);
    // 0x00413D58: lw          $a1, 0x18($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X18);
    // 0x00413D5C: lhu         $a2, 0x14($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0X14);
    // 0x00413D60: jal         0x00210A00
    // 0x00413D64: nop

    func_00210A00(rdram, ctx);
        goto after_14;
    // 0x00413D64: nop

    after_14:
    // 0x00413D68: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x00413D6C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x00413D70: lw          $a3, 0x258($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X258);
    // 0x00413D74: jal         0x0022A588
    // 0x00413D78: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_0022A588(rdram, ctx);
        goto after_15;
    // 0x00413D78: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_15:
    // 0x00413D7C: lw          $a0, 0x74($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X74);
    // 0x00413D80: lhu         $s1, 0x16E($s2)
    ctx->r17 = MEM_HU(ctx->r18, 0X16E);
    // 0x00413D84: lw          $s0, 0x1774($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X1774);
    // 0x00413D88: jal         0x0021098C
    // 0x00413D8C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_16;
    // 0x00413D8C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_16:
    // 0x00413D90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00413D94: jal         0x0021098C
    // 0x00413D98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0021098C(rdram, ctx);
        goto after_17;
    // 0x00413D98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_17:
    // 0x00413D9C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00413DA0: jal         0x0021098C
    // 0x00413DA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_0021098C(rdram, ctx);
        goto after_18;
    // 0x00413DA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x00413DA8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00413DAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413DB0: jal         0x0021098C
    // 0x00413DB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_19;
    // 0x00413DB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_19:
    // 0x00413DB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413DBC: jal         0x0021098C
    // 0x00413DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_0021098C(rdram, ctx);
        goto after_20;
    // 0x00413DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x00413DC4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x00413DC8: andi        $v0, $s1, 0x7
    ctx->r2 = ctx->r17 & 0X7;
    // 0x00413DCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x00413DD0: bgez        $s1, L_00413DDC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x00413DD4: sllv        $a0, $t2, $v0
        ctx->r4 = S32(ctx->r10 << (ctx->r2 & 31));
            goto L_00413DDC;
    }
    // 0x00413DD4: sllv        $a0, $t2, $v0
    ctx->r4 = S32(ctx->r10 << (ctx->r2 & 31));
    // 0x00413DD8: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
L_00413DDC:
    // 0x00413DDC: sra         $v0, $s1, 3
    ctx->r2 = S32(SIGNED(ctx->r17) >> 3);
    // 0x00413DE0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x00413DE4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x00413DE8: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x00413DEC: beql        $v0, $zero, L_00413E04
    if (ctx->r2 == 0) {
        // 0x00413DF0: addiu       $s2, $s2, 0x1B0
        ctx->r18 = ADD32(ctx->r18, 0X1B0);
            goto L_00413E04;
    }
    goto skip_0;
    // 0x00413DF0: addiu       $s2, $s2, 0x1B0
    ctx->r18 = ADD32(ctx->r18, 0X1B0);
    skip_0:
    // 0x00413DF4: lhu         $v0, 0x16C($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X16C);
    // 0x00413DF8: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x00413DFC: sh          $v0, 0x16C($s2)
    MEM_H(0X16C, ctx->r18) = ctx->r2;
    // 0x00413E00: addiu       $s2, $s2, 0x1B0
    ctx->r18 = ADD32(ctx->r18, 0X1B0);
L_00413E04:
    // 0x00413E04: lw          $t3, 0x23C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X23C);
    // 0x00413E08: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x00413E0C: slt         $v0, $s3, $t3
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x00413E10: bne         $v0, $zero, L_00413D54
    if (ctx->r2 != 0) {
        // 0x00413E14: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_00413D54;
    }
    // 0x00413E14: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
L_00413E18:
    // 0x00413E18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x00413E1C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00413E20: lw          $t0, 0x244($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X244);
    // 0x00413E24: lw          $t1, 0x24C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24C);
    // 0x00413E28: addu        $s6, $s6, $t0
    ctx->r22 = ADD32(ctx->r22, ctx->r8);
    // 0x00413E2C: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x00413E30: lw          $a0, 0x230($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X230);
    // 0x00413E34: lw          $t2, 0x234($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X234);
    // 0x00413E38: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x00413E3C: sw          $t1, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = ctx->r9;
    // 0x00413E40: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x00413E44: addu        $s0, $t2, $s6
    ctx->r16 = ADD32(ctx->r10, ctx->r22);
    // 0x00413E48: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00413E4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413E50: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x00413E54: jal         0x00210AE4
    // 0x00413E58: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    func_00210AE4(rdram, ctx);
        goto after_21;
    // 0x00413E58: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    after_21:
    // 0x00413E5C: addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
    // 0x00413E60: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x00413E64: sw          $fp, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r30;
    // 0x00413E68: lw          $t3, 0x230($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X230);
    // 0x00413E6C: addiu       $s3, $s0, 0x8
    ctx->r19 = ADD32(ctx->r16, 0X8);
    // 0x00413E70: blez        $fp, L_00413EA0
    if (SIGNED(ctx->r30) <= 0) {
        // 0x00413E74: addiu       $a1, $t3, 0x8
        ctx->r5 = ADD32(ctx->r11, 0X8);
            goto L_00413EA0;
    }
    // 0x00413E74: addiu       $a1, $t3, 0x8
    ctx->r5 = ADD32(ctx->r11, 0X8);
    // 0x00413E78: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x00413E7C: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_00413E80:
    // 0x00413E80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413E84: jal         0x0021BEB8
    // 0x00413E88: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_0021BEB8(rdram, ctx);
        goto after_22;
    // 0x00413E88: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_22:
    // 0x00413E8C: addiu       $s2, $s2, 0x48
    ctx->r18 = ADD32(ctx->r18, 0X48);
    // 0x00413E90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x00413E94: slt         $v0, $s1, $fp
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x00413E98: bne         $v0, $zero, L_00413E80
    if (ctx->r2 != 0) {
        // 0x00413E9C: addiu       $s0, $s0, 0xC4
        ctx->r16 = ADD32(ctx->r16, 0XC4);
            goto L_00413E80;
    }
    // 0x00413E9C: addiu       $s0, $s0, 0xC4
    ctx->r16 = ADD32(ctx->r16, 0XC4);
L_00413EA0:
    // 0x00413EA0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00413EA4: lw          $t0, 0x248($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X248);
    // 0x00413EA8: lw          $t1, 0x24C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24C);
    // 0x00413EAC: addu        $s6, $s6, $t0
    ctx->r22 = ADD32(ctx->r22, ctx->r8);
    // 0x00413EB0: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x00413EB4: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // 0x00413EB8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00413EBC: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x00413EC0: blez        $fp, L_00413EE8
    if (SIGNED(ctx->r30) <= 0) {
        // 0x00413EC4: sw          $s6, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r22;
            goto L_00413EE8;
    }
    // 0x00413EC4: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x00413EC8: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x00413ECC: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_00413ED0:
    // 0x00413ED0: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x00413ED4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x00413ED8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x00413EDC: slt         $v0, $s1, $fp
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x00413EE0: bne         $v0, $zero, L_00413ED0
    if (ctx->r2 != 0) {
        // 0x00413EE4: addiu       $s0, $s0, 0xC4
        ctx->r16 = ADD32(ctx->r16, 0XC4);
            goto L_00413ED0;
    }
    // 0x00413EE4: addiu       $s0, $s0, 0xC4
    ctx->r16 = ADD32(ctx->r16, 0XC4);
L_00413EE8:
    // 0x00413EE8: lw          $t2, 0x23C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X23C);
    // 0x00413EEC: blez        $t2, L_00413F80
    if (SIGNED(ctx->r10) <= 0) {
        // 0x00413EF0: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_00413F80;
    }
    // 0x00413EF0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x00413EF4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x00413EF8: lwc1        $f20, 0x752C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X752C);
    // 0x00413EFC: lw          $s0, 0x254($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X254);
L_00413F00:
    // 0x00413F00: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x00413F04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00413F08: jal         0x00227FEC
    // 0x00413F0C: swc1        $f0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->f0.u32l;
    func_00227FEC(rdram, ctx);
        goto after_23;
    // 0x00413F0C: swc1        $f0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x00413F10: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x00413F14: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x00413F18: lwc1        $f1, 0x8($s0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r16, 0X8);
    // 0x00413F1C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x00413F20: add.s       $f1, $f1, $f0
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f1.fl = ctx->f1.fl + ctx->f0.fl;
    // 0x00413F24: addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // 0x00413F28: addiu       $a2, $sp, 0x218
    ctx->r6 = ADD32(ctx->r29, 0X218);
    // 0x00413F2C: swc1        $f1, 0x21C($sp)
    MEM_W(0X21C, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x00413F30: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x00413F34: addiu       $a3, $s0, 0x178
    ctx->r7 = ADD32(ctx->r16, 0X178);
    // 0x00413F38: jal         0x00202B50
    // 0x00413F3C: swc1        $f0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->f0.u32l;
    func_00202B50(rdram, ctx);
        goto after_24;
    // 0x00413F3C: swc1        $f0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->f0.u32l;
    after_24:
    // 0x00413F40: lw          $t3, 0x178($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X178);
    // 0x00413F44: lw          $t0, 0x17C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X17C);
    // 0x00413F48: lw          $t1, 0x180($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X180);
    // 0x00413F4C: lw          $t2, 0x184($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X184);
    // 0x00413F50: sw          $t3, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->r11;
    // 0x00413F54: sw          $t0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->r8;
    // 0x00413F58: sw          $t1, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->r9;
    // 0x00413F5C: sw          $t2, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = ctx->r10;
    // 0x00413F60: lw          $t3, 0x188($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X188);
    // 0x00413F64: lw          $t0, 0x18C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18C);
    // 0x00413F68: sw          $t3, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->r11;
    // 0x00413F6C: sw          $t0, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = ctx->r8;
    // 0x00413F70: lw          $t3, 0x23C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X23C);
    // 0x00413F74: slt         $v0, $s3, $t3
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x00413F78: bne         $v0, $zero, L_00413F00
    if (ctx->r2 != 0) {
        // 0x00413F7C: addiu       $s0, $s0, 0x1B0
        ctx->r16 = ADD32(ctx->r16, 0X1B0);
            goto L_00413F00;
    }
    // 0x00413F7C: addiu       $s0, $s0, 0x1B0
    ctx->r16 = ADD32(ctx->r16, 0X1B0);
L_00413F80:
    // 0x00413F80: lw          $a1, 0x294($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X294);
    // 0x00413F84: lw          $a2, 0x25C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X25C);
    // 0x00413F88: jal         0x00221CC8
    // 0x00413F8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_00221CC8(rdram, ctx);
        goto after_25;
    // 0x00413F8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_25:
L_00413F90:
    // 0x00413F90: lw          $ra, 0x284($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X284);
    // 0x00413F94: lw          $fp, 0x280($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X280);
    // 0x00413F98: lw          $s7, 0x27C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X27C);
    // 0x00413F9C: lw          $s6, 0x278($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X278);
    // 0x00413FA0: lw          $s5, 0x274($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X274);
    // 0x00413FA4: lw          $s4, 0x270($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X270);
    // 0x00413FA8: lw          $s3, 0x26C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X26C);
    // 0x00413FAC: lw          $s2, 0x268($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X268);
    // 0x00413FB0: lw          $s1, 0x264($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X264);
    // 0x00413FB4: lw          $s0, 0x260($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X260);
    // 0x00413FB8: ldc1        $f20, 0x288($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X288);
    // 0x00413FBC: jr          $ra
    // 0x00413FC0: addiu       $sp, $sp, 0x290
    ctx->r29 = ADD32(ctx->r29, 0X290);
    return;
    // 0x00413FC0: addiu       $sp, $sp, 0x290
    ctx->r29 = ADD32(ctx->r29, 0X290);
;}
RECOMP_FUNC void func_00413FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00413FC4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x00413FC8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x00413FCC: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x00413FD0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x00413FD4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x00413FD8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x00413FDC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x00413FE0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x00413FE4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x00413FE8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x00413FEC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x00413FF0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x00413FF4: lw          $a0, 0x58($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X58);
    // 0x00413FF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00413FFC: jal         0x0021098C
    // 0x00414000: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    func_0021098C(rdram, ctx);
        goto after_0;
    // 0x00414000: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_0:
    // 0x00414004: lw          $a0, 0x58($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X58);
    // 0x00414008: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x0041400C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x00414010: jal         0x0021098C
    // 0x00414014: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x00414014: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x00414018: lw          $a0, 0x58($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X58);
    // 0x0041401C: lw          $s0, 0x4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X4);
    // 0x00414020: jal         0x0021098C
    // 0x00414024: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_0021098C(rdram, ctx);
        goto after_2;
    // 0x00414024: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x00414028: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x0041402C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x00414030: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x00414034: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x00414038: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x0041403C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x00414040: bltz        $s0, L_004141F8
    if (SIGNED(ctx->r16) < 0) {
        // 0x00414044: sw          $v1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r3;
            goto L_004141F8;
    }
    // 0x00414044: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x00414048: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
L_0041404C:
    // 0x0041404C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x00414050: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x00414054: slt         $v0, $t0, $s6
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x00414058: bne         $v0, $zero, L_004141D8
    if (ctx->r2 != 0) {
        // 0x0041405C: addu        $a2, $s6, $s7
        ctx->r6 = ADD32(ctx->r22, ctx->r23);
            goto L_004141D8;
    }
    // 0x0041405C: addu        $a2, $s6, $s7
    ctx->r6 = ADD32(ctx->r22, ctx->r23);
L_00414060:
    // 0x00414060: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x00414064: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x00414068: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x0041406C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00414070: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x00414074: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x00414078: bne         $v0, $zero, L_004141C4
    if (ctx->r2 != 0) {
        // 0x0041407C: nop
    
            goto L_004141C4;
    }
    // 0x0041407C: nop

    // 0x00414080: lw          $a0, 0x54($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X54);
    // 0x00414084: lw          $a1, 0x24($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X24);
    // 0x00414088: jal         0x00210A14
    // 0x0041408C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_00210A14(rdram, ctx);
        goto after_3;
    // 0x0041408C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x00414090: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00414094: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x00414098: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x0041409C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x004140A0: lui         $v0, 0x41
    ctx->r2 = S32(0X41 << 16);
    // 0x004140A4: addiu       $v0, $v0, 0x3A84
    ctx->r2 = ADD32(ctx->r2, 0X3A84);
    // 0x004140A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x004140AC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x004140B0: addiu       $v0, $v0, 0x7530
    ctx->r2 = ADD32(ctx->r2, 0X7530);
    // 0x004140B4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x004140B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x004140BC: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x004140C0: jal         0x0021FB70
    // 0x004140C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_0021FB70(rdram, ctx);
        goto after_4;
    // 0x004140C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
    // 0x004140C8: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x004140CC: beq         $s5, $zero, L_004141B4
    if (ctx->r21 == 0) {
        // 0x004140D0: nop
    
            goto L_004141B4;
    }
    // 0x004140D0: nop

    // 0x004140D4: lw          $s4, 0x0($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X0);
    // 0x004140D8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x004140DC: beq         $v0, $zero, L_004141A0
    if (ctx->r2 == 0) {
        // 0x004140E0: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_004141A0;
    }
    // 0x004140E0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x004140E4: jal         0x0021098C
    // 0x004140E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_5;
    // 0x004140E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x004140EC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x004140F0: lw          $s3, 0x4($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X4);
    // 0x004140F4: blez        $s3, L_00414148
    if (SIGNED(ctx->r19) <= 0) {
        // 0x004140F8: addiu       $a0, $v0, 0x8
        ctx->r4 = ADD32(ctx->r2, 0X8);
            goto L_00414148;
    }
    // 0x004140F8: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x004140FC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
L_00414100:
    // 0x00414100: sw          $s5, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r21;
    // 0x00414104: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x00414108: jal         0x00227BA0
    // 0x0041410C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_00227BA0(rdram, ctx);
        goto after_6;
    // 0x0041410C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // 0x00414110: jal         0x00227C2C
    // 0x00414114: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_00227C2C(rdram, ctx);
        goto after_7;
    // 0x00414114: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // 0x00414118: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x0041411C: beq         $s0, $zero, L_00414138
    if (ctx->r16 == 0) {
        // 0x00414120: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00414138;
    }
    // 0x00414120: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00414124: jal         0x002106EC
    // 0x00414128: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_002106EC(rdram, ctx);
        goto after_8;
    // 0x00414128: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x0041412C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00414130: jal         0x0022170C
    // 0x00414134: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0022170C(rdram, ctx);
        goto after_9;
    // 0x00414134: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_9:
L_00414138:
    // 0x00414138: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x0041413C: slt         $v0, $s2, $s3
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x00414140: bne         $v0, $zero, L_00414100
    if (ctx->r2 != 0) {
        // 0x00414144: addiu       $s1, $s1, 0x90
        ctx->r17 = ADD32(ctx->r17, 0X90);
            goto L_00414100;
    }
    // 0x00414144: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
L_00414148:
    // 0x00414148: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x0041414C: jal         0x0021098C
    // 0x00414150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_0021098C(rdram, ctx);
        goto after_10;
    // 0x00414150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x00414154: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x00414158: lw          $s3, 0x4($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X4);
    // 0x0041415C: blez        $s3, L_004141A0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x00414160: addiu       $a0, $v0, 0x8
        ctx->r4 = ADD32(ctx->r2, 0X8);
            goto L_004141A0;
    }
    // 0x00414160: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x00414164: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
L_00414168:
    // 0x00414168: jal         0x0022AD98
    // 0x0041416C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_0022AD98(rdram, ctx);
        goto after_11;
    // 0x0041416C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_11:
    // 0x00414170: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00414174: beq         $s0, $zero, L_00414190
    if (ctx->r16 == 0) {
        // 0x00414178: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_00414190;
    }
    // 0x00414178: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x0041417C: jal         0x002106EC
    // 0x00414180: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_002106EC(rdram, ctx);
        goto after_12;
    // 0x00414180: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x00414184: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00414188: jal         0x0022170C
    // 0x0041418C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0022170C(rdram, ctx);
        goto after_13;
    // 0x0041418C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_13:
L_00414190:
    // 0x00414190: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x00414194: slt         $v0, $s1, $s3
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x00414198: bne         $v0, $zero, L_00414168
    if (ctx->r2 != 0) {
        // 0x0041419C: addiu       $s2, $s2, 0x1B0
        ctx->r18 = ADD32(ctx->r18, 0X1B0);
            goto L_00414168;
    }
    // 0x0041419C: addiu       $s2, $s2, 0x1B0
    ctx->r18 = ADD32(ctx->r18, 0X1B0);
L_004141A0:
    // 0x004141A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004141A4: jal         0x0022170C
    // 0x004141A8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_0022170C(rdram, ctx);
        goto after_14;
    // 0x004141A8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_14:
    // 0x004141AC: j           L_004141C4
    // 0x004141B0: nop

        goto L_004141C4;
    // 0x004141B0: nop

L_004141B4:
    // 0x004141B4: jal         0x002218C0
    // 0x004141B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_002218C0(rdram, ctx);
        goto after_15;
    // 0x004141B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // 0x004141BC: j           L_004141F8
    // 0x004141C0: nop

        goto L_004141F8;
    // 0x004141C0: nop

L_004141C4:
    // 0x004141C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x004141C8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x004141CC: slt         $v0, $t0, $s6
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x004141D0: beq         $v0, $zero, L_00414060
    if (ctx->r2 == 0) {
        // 0x004141D4: addu        $a2, $s6, $s7
        ctx->r6 = ADD32(ctx->r22, ctx->r23);
            goto L_00414060;
    }
    // 0x004141D4: addu        $a2, $s6, $s7
    ctx->r6 = ADD32(ctx->r22, ctx->r23);
L_004141D8:
    // 0x004141D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x004141DC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x004141E0: addu        $s7, $s7, $v1
    ctx->r23 = ADD32(ctx->r23, ctx->r3);
    // 0x004141E4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x004141E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x004141EC: slt         $v0, $v1, $t0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x004141F0: beq         $v0, $zero, L_0041404C
    if (ctx->r2 == 0) {
        // 0x004141F4: sw          $t0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r8;
            goto L_0041404C;
    }
    // 0x004141F4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_004141F8:
    // 0x004141F8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x004141FC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x00414200: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x00414204: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x00414208: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x0041420C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x00414210: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x00414214: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x00414218: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x0041421C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x00414220: jr          $ra
    // 0x00414224: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x00414224: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_00414228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00414228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x0041422C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00414230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00414234: jal         0x00414250
    // 0x00414238: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_00414250(rdram, ctx);
        goto after_0;
    // 0x00414238: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x0041423C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x00414240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x00414244: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00414248: jr          $ra
    // 0x0041424C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0041424C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00414250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00414250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00414254: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00414258: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x0041425C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x00414260: lw          $v0, 0xD4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD4);
    // 0x00414264: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x00414268: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x0041426C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x00414270: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x00414274: addiu       $a0, $a0, -0x35E8
    ctx->r4 = ADD32(ctx->r4, -0X35E8);
    // 0x00414278: jal         0x0021ED2C
    // 0x0041427C: nop

    func_0021ED2C(rdram, ctx);
        goto after_0;
    // 0x0041427C: nop

    after_0:
    // 0x00414280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x00414284: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x00414288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x0041428C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00414290: jr          $ra
    // 0x00414294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00414294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00414298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00414298: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x0041429C: sw          $zero, 0x1864($a0)
    MEM_W(0X1864, ctx->r4) = 0;
    // 0x004142A0: sw          $zero, 0x1858($a0)
    MEM_W(0X1858, ctx->r4) = 0;
    // 0x004142A4: sw          $v0, 0x185C($a0)
    MEM_W(0X185C, ctx->r4) = ctx->r2;
    // 0x004142A8: jr          $ra
    // 0x004142AC: sw          $a1, 0x1774($a0)
    MEM_W(0X1774, ctx->r4) = ctx->r5;
    return;
    // 0x004142AC: sw          $a1, 0x1774($a0)
    MEM_W(0X1774, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_004142B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004142B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x004142B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x004142B8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x004142BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x004142C0: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x004142C4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x004142C8: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x004142CC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x004142D0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x004142D4: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    // 0x004142D8: jal         0x0021098C
    // 0x004142DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_0;
    // 0x004142DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x004142E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x004142E4: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    // 0x004142E8: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    // 0x004142EC: jal         0x0021098C
    // 0x004142F0: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x004142F0: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    after_1:
    // 0x004142F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x004142F8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x004142FC: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x00414300: addiu       $s1, $v0, 0x8
    ctx->r17 = ADD32(ctx->r2, 0X8);
    // 0x00414304: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x00414308: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x0041430C: jal         0x0026A9D0
    // 0x00414310: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_0026A9D0(rdram, ctx);
        goto after_2;
    // 0x00414310: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_2:
    // 0x00414314: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x00414318: beq         $s0, $zero, L_004143A4
    if (ctx->r16 == 0) {
        // 0x0041431C: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_004143A4;
    }
    // 0x0041431C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x00414320: jal         0x002154EC
    // 0x00414324: nop

    func_002154EC(rdram, ctx);
        goto after_3;
    // 0x00414324: nop

    after_3:
    // 0x00414328: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x0041432C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x00414330: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x00414334: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x00414338: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x0041433C: bne         $v1, $zero, L_00414348
    if (ctx->r3 != 0) {
        // 0x00414340: nop
    
            goto L_00414348;
    }
    // 0x00414340: nop

    // 0x00414344: break       7
    do_break(4277060);
L_00414348:
    // 0x00414348: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x0041434C: bne         $v1, $at, L_00414360
    if (ctx->r3 != ctx->r1) {
        // 0x00414350: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_00414360;
    }
    // 0x00414350: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x00414354: bne         $v0, $at, L_00414360
    if (ctx->r2 != ctx->r1) {
        // 0x00414358: nop
    
            goto L_00414360;
    }
    // 0x00414358: nop

    // 0x0041435C: break       6
    do_break(4277084);
L_00414360:
    // 0x00414360: mfhi        $v1
    ctx->r3 = hi;
    // 0x00414364: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x00414368: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x0041436C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x00414370: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x00414374: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x00414378: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x0041437C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x00414380: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x00414384: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x00414388: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x0041438C: sw          $t1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r9;
    // 0x00414390: sw          $t2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r10;
    // 0x00414394: sw          $t3, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r11;
    // 0x00414398: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x0041439C: sw          $t0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r8;
    // 0x004143A0: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_004143A4:
    // 0x004143A4: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x004143A8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x004143AC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x004143B0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x004143B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x004143B8: jr          $ra
    // 0x004143BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x004143BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_004143C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004143C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x004143C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x004143C8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x004143CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x004143D0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x004143D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x004143D8: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x004143DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x004143E0: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x004143E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x004143E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x004143EC: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    // 0x004143F0: jal         0x0021098C
    // 0x004143F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_0;
    // 0x004143F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x004143F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x004143FC: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    // 0x00414400: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    // 0x00414404: jal         0x0021098C
    // 0x00414408: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x00414408: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    after_1:
    // 0x0041440C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00414410: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x00414414: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x00414418: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x0041441C: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x00414420: jal         0x0026A9D0
    // 0x00414424: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_0026A9D0(rdram, ctx);
        goto after_2;
    // 0x00414424: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_2:
    // 0x00414428: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x0041442C: bne         $v1, $zero, L_00414438
    if (ctx->r3 != 0) {
        // 0x00414430: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_00414438;
    }
    // 0x00414430: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x00414434: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_00414438:
    // 0x00414438: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x0041443C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x00414440: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x00414444: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x00414448: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x0041444C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x00414450: jr          $ra
    // 0x00414454: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x00414454: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_00414458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00414458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x0041445C: sw          $a2, 0x1858($a0)
    MEM_W(0X1858, ctx->r4) = ctx->r6;
    // 0x00414460: sw          $v0, 0x185C($a0)
    MEM_W(0X185C, ctx->r4) = ctx->r2;
    // 0x00414464: jr          $ra
    // 0x00414468: sw          $a1, 0x1880($a0)
    MEM_W(0X1880, ctx->r4) = ctx->r5;
    return;
    // 0x00414468: sw          $a1, 0x1880($a0)
    MEM_W(0X1880, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_0041446C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0041446C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x00414470: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x00414474: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x00414478: slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x0041447C: bne         $v0, $zero, L_00414488
    if (ctx->r2 != 0) {
        // 0x00414480: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_00414488;
    }
    // 0x00414480: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x00414484: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
L_00414488:
    // 0x00414488: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x0041448C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x00414490: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00414494: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x00414498: lh          $v0, -0x4ABC($at)
    ctx->r2 = MEM_H(ctx->r1, -0X4ABC);
    // 0x0041449C: jr          $ra
    // 0x004144A0: sw          $v0, 0x187C($a0)
    MEM_W(0X187C, ctx->r4) = ctx->r2;
    return;
    // 0x004144A0: sw          $v0, 0x187C($a0)
    MEM_W(0X187C, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_004144A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004144A4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x004144A8: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x004144AC: beql        $v0, $zero, L_004144B4
    if (ctx->r2 == 0) {
        // 0x004144B0: sw          $zero, 0xC($a0)
        MEM_W(0XC, ctx->r4) = 0;
            goto L_004144B4;
    }
    goto skip_0;
    // 0x004144B0: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    skip_0:
L_004144B4:
    // 0x004144B4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x004144B8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x004144BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x004144C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x004144C4: lh          $v0, -0x4ABC($at)
    ctx->r2 = MEM_H(ctx->r1, -0X4ABC);
    // 0x004144C8: jr          $ra
    // 0x004144CC: nop

    return;
    // 0x004144CC: nop

;}
RECOMP_FUNC void func_004144D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004144D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x004144D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x004144D8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x004144DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x004144E0: bne         $a1, $v0, L_00414518
    if (ctx->r5 != ctx->r2) {
        // 0x004144E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_00414518;
    }
    // 0x004144E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x004144E8: jal         0x002154EC
    // 0x004144EC: nop

    func_002154EC(rdram, ctx);
        goto after_0;
    // 0x004144EC: nop

    after_0:
    // 0x004144F0: lui         $v1, 0x7878
    ctx->r3 = S32(0X7878 << 16);
    // 0x004144F4: ori         $v1, $v1, 0x7879
    ctx->r3 = ctx->r3 | 0X7879;
    // 0x004144F8: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x004144FC: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x00414500: mfhi        $a2
    ctx->r6 = hi;
    // 0x00414504: sra         $a0, $a2, 3
    ctx->r4 = S32(SIGNED(ctx->r6) >> 3);
    // 0x00414508: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
    // 0x0041450C: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x00414510: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x00414514: subu        $a1, $v0, $v1
    ctx->r5 = SUB32(ctx->r2, ctx->r3);
L_00414518:
    // 0x00414518: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x0041451C: beql        $v0, $zero, L_00414524
    if (ctx->r2 == 0) {
        // 0x00414520: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_00414524;
    }
    goto skip_0;
    // 0x00414520: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_0:
L_00414524:
    // 0x00414524: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00414528: jal         0x00414548
    // 0x0041452C: sw          $a1, 0x1778($s0)
    MEM_W(0X1778, ctx->r16) = ctx->r5;
    func_00414548(rdram, ctx);
        goto after_1;
    // 0x0041452C: sw          $a1, 0x1778($s0)
    MEM_W(0X1778, ctx->r16) = ctx->r5;
    after_1:
    // 0x00414530: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x00414534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x00414538: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x0041453C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x00414540: jr          $ra
    // 0x00414544: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x00414544: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00414548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00414548: lw          $v0, 0x1778($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1778);
    // 0x0041454C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x00414550: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x00414554: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x00414558: lh          $v0, -0x4A98($at)
    ctx->r2 = MEM_H(ctx->r1, -0X4A98);
    // 0x0041455C: jr          $ra
    // 0x00414560: nop

    return;
    // 0x00414560: nop

;}
RECOMP_FUNC void func_00414564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00414564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x00414568: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x0041456C: jal         0x004127AC
    // 0x00414570: nop

    func_004127AC(rdram, ctx);
        goto after_0;
    // 0x00414570: nop

    after_0:
    // 0x00414574: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x00414578: jr          $ra
    // 0x0041457C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x0041457C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_00414580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00414580: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x00414584: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x00414588: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x0041458C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00414590: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00414594: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00414598: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0041459C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x004145A0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x004145A4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x004145A8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x004145AC: jal         0x0021098C
    // 0x004145B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_0021098C(rdram, ctx);
        goto after_0;
    // 0x004145B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x004145B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x004145B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x004145BC: jal         0x0021098C
    // 0x004145C0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x004145C0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_1:
    // 0x004145C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x004145C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x004145CC: jal         0x0021098C
    // 0x004145D0: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    func_0021098C(rdram, ctx);
        goto after_2;
    // 0x004145D0: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_2:
    // 0x004145D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x004145D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x004145DC: jal         0x0021098C
    // 0x004145E0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_0021098C(rdram, ctx);
        goto after_3;
    // 0x004145E0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_3:
    // 0x004145E4: addiu       $a0, $s5, 0x1050
    ctx->r4 = ADD32(ctx->r21, 0X1050);
    // 0x004145E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x004145EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x004145F0: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x004145F4: addiu       $s3, $zero, 0x1078
    ctx->r19 = ADD32(0, 0X1078);
    // 0x004145F8: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x004145FC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x00414600: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x00414604: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x00414608: sw          $s1, 0x1040($s5)
    MEM_W(0X1040, ctx->r21) = ctx->r17;
    // 0x0041460C: sw          $s2, 0x1048($s5)
    MEM_W(0X1048, ctx->r21) = ctx->r18;
    // 0x00414610: sw          $v1, 0x1038($s5)
    MEM_W(0X1038, ctx->r21) = ctx->r3;
    // 0x00414614: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x00414618: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x0041461C: sw          $s0, 0x1044($s5)
    MEM_W(0X1044, ctx->r21) = ctx->r16;
    // 0x00414620: sw          $v0, 0x104C($s5)
    MEM_W(0X104C, ctx->r21) = ctx->r2;
    // 0x00414624: jal         0x0021E590
    // 0x00414628: sw          $v1, 0x103C($s5)
    MEM_W(0X103C, ctx->r21) = ctx->r3;
    func_0021E590(rdram, ctx);
        goto after_4;
    // 0x00414628: sw          $v1, 0x103C($s5)
    MEM_W(0X103C, ctx->r21) = ctx->r3;
    after_4:
    // 0x0041462C: addiu       $a0, $s5, 0x1064
    ctx->r4 = ADD32(ctx->r21, 0X1064);
    // 0x00414630: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00414634: jal         0x0021E590
    // 0x00414638: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_0021E590(rdram, ctx);
        goto after_5;
    // 0x00414638: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_0041463C:
    // 0x0041463C: addiu       $a0, $s5, 0x1064
    ctx->r4 = ADD32(ctx->r21, 0X1064);
    // 0x00414640: jal         0x0021E604
    // 0x00414644: addu        $a1, $s5, $s3
    ctx->r5 = ADD32(ctx->r21, ctx->r19);
    func_0021E604(rdram, ctx);
        goto after_6;
    // 0x00414644: addu        $a1, $s5, $s3
    ctx->r5 = ADD32(ctx->r21, ctx->r19);
    after_6:
    // 0x00414648: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x0041464C: slti        $v0, $s4, 0x20
    ctx->r2 = SIGNED(ctx->r20) < 0X20 ? 1 : 0;
    // 0x00414650: bne         $v0, $zero, L_0041463C
    if (ctx->r2 != 0) {
        // 0x00414654: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_0041463C;
    }
    // 0x00414654: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x00414658: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x0041465C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x00414660: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x00414664: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x00414668: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x0041466C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00414670: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00414674: jr          $ra
    // 0x00414678: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x00414678: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_0041467C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0041467C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x00414680: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x00414684: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x00414688: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x0041468C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00414690: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00414694: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x00414698: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x0041469C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x004146A0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x004146A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x004146A8: jal         0x00222E48
    // 0x004146AC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_00222E48(rdram, ctx);
        goto after_0;
    // 0x004146AC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x004146B0: beq         $v0, $zero, L_00414788
    if (ctx->r2 == 0) {
        // 0x004146B4: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_00414788;
    }
    // 0x004146B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x004146B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x004146BC: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x004146C0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x004146C4: jal         0x0021098C
    // 0x004146C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x004146C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x004146CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x004146D0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x004146D4: lw          $s3, 0x4($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X4);
    // 0x004146D8: jal         0x0021098C
    // 0x004146DC: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    func_0021098C(rdram, ctx);
        goto after_2;
    // 0x004146DC: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    after_2:
    // 0x004146E0: blez        $s3, L_00414788
    if (SIGNED(ctx->r19) <= 0) {
        // 0x004146E4: addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
            goto L_00414788;
    }
    // 0x004146E4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x004146E8: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_004146EC:
    // 0x004146EC: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x004146F0: bne         $a1, $s4, L_00414700
    if (ctx->r5 != ctx->r20) {
        // 0x004146F4: nop
    
            goto L_00414700;
    }
    // 0x004146F4: nop

    // 0x004146F8: j           L_0041470C
    // 0x004146FC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
        goto L_0041470C;
    // 0x004146FC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
L_00414700:
    // 0x00414700: jal         0x00204850
    // 0x00414704: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_00204850(rdram, ctx);
        goto after_3;
    // 0x00414704: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_3:
    // 0x00414708: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
L_0041470C:
    // 0x0041470C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x00414710: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x00414714: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x00414718: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x0041471C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x00414720: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x00414724: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x00414728: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x0041472C: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x00414730: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x00414734: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x00414738: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x0041473C: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x00414740: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
    // 0x00414744: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x00414748: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x0041474C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x00414750: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x00414754: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x00414758: sw          $v1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r3;
    // 0x0041475C: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x00414760: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x00414764: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x00414768: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x0041476C: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x00414770: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x00414774: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x00414778: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x0041477C: slt         $v0, $s2, $s3
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x00414780: bne         $v0, $zero, L_004146EC
    if (ctx->r2 != 0) {
        // 0x00414784: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_004146EC;
    }
    // 0x00414784: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
L_00414788:
    // 0x00414788: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x0041478C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x00414790: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x00414794: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x00414798: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x0041479C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x004147A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x004147A4: jr          $ra
    // 0x004147A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x004147A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_004147AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x004147AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x004147B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x004147B4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x004147B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x004147BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x004147C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x004147C4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x004147C8: jal         0x00222E48
    // 0x004147CC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_00222E48(rdram, ctx);
        goto after_0;
    // 0x004147CC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x004147D0: beq         $v0, $zero, L_00414808
    if (ctx->r2 == 0) {
        // 0x004147D4: nop
    
            goto L_00414808;
    }
    // 0x004147D4: nop

    // 0x004147D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x004147DC: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x004147E0: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x004147E4: blez        $s1, L_00414808
    if (SIGNED(ctx->r17) <= 0) {
        // 0x004147E8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_00414808;
    }
    // 0x004147E8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x004147EC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_004147F0:
    // 0x004147F0: jal         0x0021098C
    // 0x004147F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x004147F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x004147F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x004147FC: slt         $v0, $s0, $s1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x00414800: bne         $v0, $zero, L_004147F0
    if (ctx->r2 != 0) {
        // 0x00414804: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_004147F0;
    }
    // 0x00414804: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_00414808:
    // 0x00414808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x0041480C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x00414810: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00414814: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00414818: jr          $ra
    // 0x0041481C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x0041481C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_00414820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x00414820: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x00414824: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x00414828: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x0041482C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x00414830: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x00414834: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x00414838: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x0041483C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x00414840: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x00414844: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x00414848: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x0041484C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x00414850: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x00414854: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x00414858: jal         0x00222E48
    // 0x0041485C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_00222E48(rdram, ctx);
        goto after_0;
    // 0x0041485C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x00414860: beq         $v0, $zero, L_004148FC
    if (ctx->r2 == 0) {
        // 0x00414864: nop
    
            goto L_004148FC;
    }
    // 0x00414864: nop

    // 0x00414868: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x0041486C: lw          $s5, 0x0($v0)
    ctx->r21 = MEM_W(ctx->r2, 0X0);
    // 0x00414870: lw          $s6, 0x0($s5)
    ctx->r22 = MEM_W(ctx->r21, 0X0);
    // 0x00414874: blez        $s6, L_004148F8
    if (SIGNED(ctx->r22) <= 0) {
        // 0x00414878: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_004148F8;
    }
    // 0x00414878: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x0041487C: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x00414880: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
L_00414884:
    // 0x00414884: jal         0x0021098C
    // 0x00414888: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_0021098C(rdram, ctx);
        goto after_1;
    // 0x00414888: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_1:
    // 0x0041488C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00414890: jal         0x0021098C
    // 0x00414894: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_0021098C(rdram, ctx);
        goto after_2;
    // 0x00414894: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x00414898: lw          $s4, 0x4($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X4);
    // 0x0041489C: blez        $s4, L_004148E8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x004148A0: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_004148E8;
    }
    // 0x004148A0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x004148A4: addiu       $s0, $v0, 0x18
    ctx->r16 = ADD32(ctx->r2, 0X18);
L_004148A8:
    // 0x004148A8: lw          $s1, -0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, -0X4);
    // 0x004148AC: beql        $s1, $s7, L_004148D0
    if (ctx->r17 == ctx->r23) {
        // 0x004148B0: sw          $zero, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = 0;
            goto L_004148D0;
    }
    goto skip_0;
    // 0x004148B0: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    skip_0:
    // 0x004148B4: lw          $a0, 0x5C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X5C);
    // 0x004148B8: jal         0x0021098C
    // 0x004148BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_0021098C(rdram, ctx);
        goto after_3;
    // 0x004148BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x004148C0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x004148C4: sll         $v1, $s1, 5
    ctx->r3 = S32(ctx->r17 << 5);
    // 0x004148C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x004148CC: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
L_004148D0:
    // 0x004148D0: jal         0x00215038
    // 0x004148D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00215038(rdram, ctx);
        goto after_4;
    // 0x004148D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x004148D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x004148DC: slt         $v0, $s2, $s4
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x004148E0: bne         $v0, $zero, L_004148A8
    if (ctx->r2 != 0) {
        // 0x004148E4: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_004148A8;
    }
    // 0x004148E4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_004148E8:
    // 0x004148E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x004148EC: slt         $v0, $s3, $s6
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x004148F0: bnel        $v0, $zero, L_00414884
    if (ctx->r2 != 0) {
        // 0x004148F4: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_00414884;
    }
    goto skip_1;
    // 0x004148F4: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    skip_1:
L_004148F8:
    // 0x004148F8: sw          $s5, 0x6C($fp)
    MEM_W(0X6C, ctx->r30) = ctx->r21;
L_004148FC:
    // 0x004148FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x00414900: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x00414904: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x00414908: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x0041490C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x00414910: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x00414914: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x00414918: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x0041491C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x00414920: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x00414924: jr          $ra
    // 0x00414928: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x00414928: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_0041492C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x0041492C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x00414930: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x00414934: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x00414938: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x0041493C: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x00414940: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x00414944: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x00414948: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x0041494C: jal         0x00203A8C
    // 0x00414950: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    func_00203A8C(rdram, ctx);
        goto after_0;
    // 0x00414950: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    after_0:
    // 0x00414954: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x00414958: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x0041495C: bne         $a1, $v0, L_0041496C
    if (ctx->r5 != ctx->r2) {
        // 0x00414960: nop
    
            goto L_0041496C;
    }
    // 0x00414960: nop

    // 0x00414964: j           L_00414A84
    // 0x00414968: sw          $zero, 0x8($s3)
    MEM_W(0X8, ctx->r19) = 0;
        goto L_00414A84;
    // 0x00414968: sw          $zero, 0x8($s3)
    MEM_W(0X8, ctx->r19) = 0;
L_0041496C:
    // 0x0041496C: jal         0x00204850
    // 0x00414970: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_00204850(rdram, ctx);
        goto after_1;
    // 0x00414970: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x00414974: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00414978: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x0041497C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00414980: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x00414984: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x00414988: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x0041498C: addiu       $v0, $v0, 0x72D8
    ctx->r2 = ADD32(ctx->r2, 0X72D8);
    // 0x00414990: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x00414994: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x00414998: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x0041499C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x004149A0: jal         0x0021FB70
    // 0x004149A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    func_0021FB70(rdram, ctx);
        goto after_2;
    // 0x004149A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_2:
    // 0x004149A8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x004149AC: beq         $s1, $zero, L_00414A84
    if (ctx->r17 == 0) {
        // 0x004149B0: addu        $a2, $s2, $zero
        ctx->r6 = ADD32(ctx->r18, 0);
            goto L_00414A84;
    }
    // 0x004149B0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x004149B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x004149B8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x004149BC: jal         0x00210A14
    // 0x004149C0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_00210A14(rdram, ctx);
        goto after_3;
    // 0x004149C0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x004149C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x004149C8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x004149CC: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x004149D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x004149D4: lui         $v0, 0x21
    ctx->r2 = S32(0X21 << 16);
    // 0x004149D8: addiu       $v0, $v0, -0x2A60
    ctx->r2 = ADD32(ctx->r2, -0X2A60);
    // 0x004149DC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x004149E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x004149E4: addiu       $v0, $v0, 0x72E8
    ctx->r2 = ADD32(ctx->r2, 0X72E8);
    // 0x004149E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x004149EC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x004149F0: jal         0x0021FB70
    // 0x004149F4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    func_0021FB70(rdram, ctx);
        goto after_4;
    // 0x004149F4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_4:
    // 0x004149F8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x004149FC: beq         $s0, $zero, L_00414A7C
    if (ctx->r16 == 0) {
        // 0x00414A00: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_00414A7C;
    }
    // 0x00414A00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00414A04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x00414A08: jal         0x0021098C
    // 0x00414A0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_0021098C(rdram, ctx);
        goto after_5;
    // 0x00414A0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x00414A10: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00414A14: jal         0x0021098C
    // 0x00414A18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_6;
    // 0x00414A18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // 0x00414A1C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00414A20: jal         0x0021098C
    // 0x00414A24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_7;
    // 0x00414A24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x00414A28: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x00414A2C: jal         0x0021098C
    // 0x00414A30: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_0021098C(rdram, ctx);
        goto after_8;
    // 0x00414A30: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_8:
    // 0x00414A34: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x00414A38: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x00414A3C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x00414A40: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x00414A44: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x00414A48: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x00414A4C: sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
    // 0x00414A50: sw          $t0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r8;
    // 0x00414A54: sw          $t1, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r9;
    // 0x00414A58: sw          $t2, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r10;
    // 0x00414A5C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x00414A60: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x00414A64: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x00414A68: sw          $v1, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r3;
    // 0x00414A6C: sw          $t0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r8;
    // 0x00414A70: jal         0x002217F0
    // 0x00414A74: sw          $t1, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r9;
    func_002217F0(rdram, ctx);
        goto after_9;
    // 0x00414A74: sw          $t1, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r9;
    after_9:
    // 0x00414A78: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_00414A7C:
    // 0x00414A7C: jal         0x002217F0
    // 0x00414A80: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_002217F0(rdram, ctx);
        goto after_10;
    // 0x00414A80: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_10:
L_00414A84:
    // 0x00414A84: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x00414A88: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x00414A8C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x00414A90: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x00414A94: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x00414A98: jr          $ra
    // 0x00414A9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x00414A9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
