void func_0x9498( int p1 ) {

  r1 = p1;
  /*
     .text:0x00009498 code_0x9498:
     .text:0x00009498    2DE9F04F             push.w {r4, r5, r6, r7, r8, sb, sl, fp, lr}
     .text:0x0000949C    A9B0                 sub sp, #0xA4
     .text:0x0000949E    0646                 mov r6, r0
     .text:0x000094A0    02F088FA             bl func_0xB9B4; inline int __cdecl( void )
     .text:0x000094A4    0146                 mov r1, r0
     .text:0x000094A6    06EB4600             add.w r0, r6, r6, lsl #0x1
     .text:0x000094AA    FE4A                 ldr r2, [data_0x98A4]
     .text:0x000094AC    FC4C                 ldr r4, [data_0x98A0]
     .text:0x000094AE    00EBC600             add.w r0, r0, r6, lsl #0x3
     .text:0x000094B2    02EB8008             add.w r8, r2, r0, lsl #0x2
     .text:0x000094B6    0229                 cmp r1, #0x2
     .text:0x000094B8    69D0                 beq code_0x958E
     */
sp = sp - 0xA4;
r6 = r0;
r0 = func_0xB9B4(r0);
r1 = r0;
r0 = r6 + (r6 << 0x1);
r2 = *( data_0x98A4);
r4 = *( data_0x98A0);
r0 = r0 + (r6 << 0x3);
r8 = r2 + (r0 << 0x2);
  if (r1 != 2) {
    /*
       .text:0x000094BA code_0x94BA:
       .text:0x000094BA    02F07BFA             bl func_0xB9B4; inline int __cdecl( void )
       .text:0x000094BE    0028                 cmp r0, #0x0
       .text:0x000094C0    69D0                 beq code_0x9596
       */
r0 = func_0xB9B4(r0);
    if (r0 != 0) {
      /*
         .text:0x000094C2 code_0x94C2:
         .text:0x000094C2    98F80700             ldrb.w r0, [r8, #0x7]
         .text:0x000094C6    A055                 strb r0, [r4, r6]
         */
r0 = *( r8 + 0x7);
*( r4 + r6 ) = r0;
    } else {
      /*
         .text:0x00009596 code_0x9596:
         .text:0x00009596    C948                 ldr r0, [data_0x98BC]
         .text:0x00009598    0078                 ldrb r0, [r0]
         .text:0x0000959A    A055                 strb r0, [r4, r6]
         .text:0x0000959C    94E7                 b code_0x94C8
         */
r0 = *( data_0x98BC);
r0 = *( r0);
*( r4 + r6 ) = r0;

    }
  } else {
    /*
       .text:0x0000958E code_0x958E:
       .text:0x0000958E    98F80700             ldrb.w r0, [r8, #0x7]
       .text:0x00009592    A055                 strb r0, [r4, r6]
       .text:0x00009594    98E7                 b code_0x94C8
       */
r0 = *( r8 + 0x7);
*( r4 + r6 ) = r0;
  }
  /*
     .text:0x000094C8 code_0x94C8:
     .text:0x000094C8    3D20                 movs r0, #0x3D
     .text:0x000094CA    13F05BFE             bl func_0x1D184; int __cdecl( int p1, int p2, int p3 )
     .text:0x000094CE    F649                 ldr r1, [data_0x98A8]
     .text:0x000094D0    C0F1FF00             rsb.w r0, r0, #0xFF
     .text:0x000094D4    01EBC000             add.w r0, r1, r0, lsl #0x3
     .text:0x000094D8    F54A                 ldr r2, [data_0x98B0]
     .text:0x000094DA    90ED000A             vldr s0, [r0]
     .text:0x000094DE    F348                 ldr r0, [data_0x98AC]
     .text:0x000094E0    02EB4601             add.w r1, r2, r6, lsl #0x1
     .text:0x000094E4    00EB8600             add.w r0, r0, r6, lsl #0x2
     .text:0x000094E8    2790                 str r0, [local_0x2C]
     .text:0x000094EA    D0ED000A             vldr s1, [r0]
     .text:0x000094EE    2691                 str r1, [local_0x30]
     .text:0x000094F0    20EE200A             vmul.f32 s0, s0, s1
     .text:0x000094F4    BDEEC00A             vcvt.s32.f32 s0, s0
     .text:0x000094F8    10EE100A             vmov r0, s0
     .text:0x000094FC    00B2                 sxth r0, r0
     .text:0x000094FE    A1F84C00             strh.w r0, [r1, #0x4C]
     .text:0x00009502    B0F5007F             cmp.w r0, #0x200
     .text:0x00009506    04DB                 blt code_0x9512
     */
r0 = 0x3D;
r0 = func_0x1D184(r0,r1,r2);
r1 = *( data_0x98A8);
r0 = 0xFF - r0;
r0 = r1 + (r0 << 0x3);
r2 = *( data_0x98B0);
s0 = *( r0);
r0 = *( data_0x98AC);
r1 = r2 + (r6 << 0x1);
r0 = r0 + (r6 << 0x2);
*( local_0x2C ) = r0;
s1 = *( r0);
*( local_0x30 ) = r1;
s0 = s0 * s1;
s0 = (int) s0;
r0 = s0;
r0 = (int) r0;
*( r1 + 0x4C ) = r0;
  if (r0 >= 0x200) {
    /*
       .text:0x00009508 code_0x9508:
       .text:0x00009508    2698                 ldr r0, [local_0x30]
       .text:0x0000950A    40F2FF11             movw r1, #0x1FF
       .text:0x0000950E    A0F84C10             strh.w r1, [r0, #0x4C]
       */
r0 = *( local_0x30);
r1 = 0x1FF;
*( r0 + 0x4C ) = r1;
  }
  /*
     .text:0x00009512 code_0x9512:
     .text:0x00009512    0024                 movs r4, #0x0
     .text:0x00009514    E748                 ldr r0, [string_tR_1]; "tR"
     .text:0x00009516    0022                 movs r2, #0x0
     .text:0x00009518    00EB8609             add.w sb, r0, r6, lsl #0x2
     .text:0x0000951C    00F5D870             add.w r0, r0, #0x1B0
     .text:0x00009520    00EBC600             add.w r0, r0, r6, lsl #0x3
     .text:0x00009524    2590                 str r0, [local_0x34]
     .text:0x00009526    06F00300             and r0, r6, #0x3
     .text:0x0000952A    2190                 str r0, [local_0x44]
     .text:0x0000952C    02EB4000             add.w r0, r2, r0, lsl #0x1
     .text:0x00009530    2490                 str r0, [local_0x38]
     .text:0x00009532    2198                 ldr r0, [local_0x44]
     .text:0x00009534    0122                 movs r2, #0x1
     .text:0x00009536    E049                 ldr r1, [data_0x98B8]
     .text:0x00009538    02EB4000             add.w r0, r2, r0, lsl #0x1
     .text:0x0000953C    2390                 str r0, [local_0x3C]
     .text:0x0000953E    01F1E400             add.w r0, r1, #0xE4
     .text:0x00009542    00EB8600             add.w r0, r0, r6, lsl #0x2
     .text:0x00009546    2290                 str r0, [local_0x40]
     .text:0x00009548    0420                 movs r0, #0x4
     .text:0x0000954A    00EB9600             add.w r0, r0, r6, lsr #0x2
     .text:0x0000954E    2090                 str r0, [local_0x48]
     .text:0x00009550    01EB4600             add.w r0, r1, r6, lsl #0x1
     .text:0x00009554    1F90                 str r0, [local_0x4C]
     .text:0x00009556    01EB8600             add.w r0, r1, r6, lsl #0x2
     .text:0x0000955A    1E90                 str r0, [local_0x50]
     .text:0x0000955C    0AA8                 add r0, sp, #0x28
     .text:0x0000955E    00EBC600             add.w r0, r0, r6, lsl #0x3
     .text:0x00009562    1D90                 str r0, [local_0x54]
     .text:0x00009564    A1F58670             sub.w r0, r1, #0x10C
     .text:0x00009568    02AB                 add r3, sp, #0x8
     .text:0x0000956A    00EBC600             add.w r0, r0, r6, lsl #0x3
     .text:0x0000956E    03EB860A             add.w sl, r3, r6, lsl #0x2
     .text:0x00009572    1C90                 str r0, [local_0x58]
     */
r4 = 0x0;
r0 = *( string_tR_1);
r2 = 0x0;
sb = r0 + (r6 << 0x2);
r0 = r0 + 0x1B0;
r0 = r0 + (r6 << 0x3);
*( local_0x34 ) = r0;
r0 = r6 & 0x3;
*( local_0x44 ) = r0;
r0 = r2 + (r0 << 0x1);
*( local_0x38 ) = r0;
r0 = *( local_0x44);
r2 = 0x1;
r1 = *( data_0x98B8);
r0 = r2 + (r0 << 0x1);
*( local_0x3C ) = r0;
r0 = r1 + 0xE4;
r0 = r0 + (r6 << 0x2);
*( local_0x40 ) = r0;
r0 = 0x4;
r0 = r0 + (r6 >> 0x2);
*( local_0x48 ) = r0;
r0 = r1 + (r6 << 0x1);
*( local_0x4C ) = r0;
r0 = r1 + (r6 << 0x2);
*( local_0x50 ) = r0;
r0 = sp + 0x28;
r0 = r0 + (r6 << 0x3);
*( local_0x54 ) = r0;
r0 = r1 - 0x10C;
r3 = sp + 0x8;
r0 = r0 + (r6 << 0x3);
sl = r3 + (r6 << 0x2);
*( local_0x58 ) = r0;
  while (1) {
    /*
       .text:0x00009574 code_0x9574:
       .text:0x00009574    07F010FA             bl func_0x10998; inline int __cdecl( void )
       .text:0x00009578    88B1                 cbz r0, code_0x959E
       */
r0 = func_0x10998(r0);
    if (r0 != 0) {
      /*
         .text:0x0000957A code_0x957A:
         .text:0x0000957A    0627                 movs r7, #0x6
         */
r7 = 0x6;
    } else {
      /*
         .text:0x0000959E code_0x959E:
         .text:0x0000959E    0427                 movs r7, #0x4
         .text:0x000095A0    ECE7                 b code_0x957C
         */
r7 = 0x4;
    }
    /*
       .text:0x0000957C code_0x957C:
       .text:0x0000957C    DFF830B3             ldr.w fp, [data_0x98B0]
       .text:0x00009580    BBF94A50             ldrsh.w r5, [fp, #0x4A]
       .text:0x00009584    F9F768FB             bl func_0x2C58; inline int __cdecl( void )
       .text:0x00009588    0328                 cmp r0, #0x3
       .text:0x0000958A    0AD0                 beq code_0x95A2
       */
fp = *( data_0x98B0);
r5 = *( fp + 0x4A);
r0 = func_0x2C58(r0);
    if (r0 != 3) {
      /*
         .text:0x0000958C code_0x958C:
         .text:0x0000958C    1BE0                 b code_0x95C6
         */
    } else {
      /*
         .text:0x000095A2 code_0x95A2:
         .text:0x000095A2    02F007FA             bl func_0xB9B4; inline int __cdecl( void )
         .text:0x000095A6    0228                 cmp r0, #0x2
         .text:0x000095A8    0DD1                 bne code_0x95C6
         */
r0 = func_0xB9B4(r0);
      if ( r0 == 2 ) {
        /*
           .text:0x000095AA code_0x95AA:
           .text:0x000095AA    3046                 mov r0, r6
           .text:0x000095AC    F9F75AFB             bl func_0x2C64; int __cdecl( int p1 )
           .text:0x000095B0    05EB4000             add.w r0, r5, r0, lsl #0x1
           .text:0x000095B4    05B2                 sxth r5, r0
           .text:0x000095B6    B5F5007F             cmp.w r5, #0x200
           .text:0x000095BA    01DB                 blt code_0x95C0
           */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = r5 + (r0 << 0x1);
r5 = (int) r0;
        if (r5 >= 0x200) {
          /*
             .text:0x000095BC code_0x95BC:
             .text:0x000095BC    40F2FF15             movw r5, #0x1FF
             */
r5 = 0x1FF;
        }
        /*
           .text:0x000095C0 code_0x95C0:
           .text:0x000095C0    002D                 cmp r5, #0x0
           .text:0x000095C2    00DA                 bge code_0x95C6
           */
        if (r5 < 0) {
          /*
             .text:0x000095C4 code_0x95C4:
             .text:0x000095C4    0025                 movs r5, #0x0
             */
r5 = 0x0;
        }
      }
    }
    /*
       .text:0x000095C6 code_0x95C6:
       .text:0x000095C6    3046                 mov r0, r6
       .text:0x000095C8    FEF758FD             bl func_0x807C; int __cdecl( int p1 )
       .text:0x000095CC    20F00301             bic r1, r0, #0x3
       .text:0x000095D0    BB48                 ldr r0, [data_0x98C0]
       .text:0x000095D2    00EE107A             vmov s0, r7
       .text:0x000095D6    0844                 add r0, r1
       .text:0x000095D8    269A                 ldr r2, [local_0x30]
       .text:0x000095DA    D0ED000A             vldr s1, [r0]
       .text:0x000095DE    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x000095E2    B848                 ldr r0, [data_0x98C4]
       .text:0x000095E4    B2F94C20             ldrsh.w r2, [r2, #0x4C]
       .text:0x000095E8    00EB8501             add.w r1, r0, r5, lsl #0x2
       .text:0x000095EC    00EB8200             add.w r0, r0, r2, lsl #0x2
       .text:0x000095F0    20EE800A             vmul.f32 s0, s1, s0
       .text:0x000095F4    D1ED000A             vldr s1, [r1]
       .text:0x000095F8    90ED001A             vldr s2, [r0]
       .text:0x000095FC    AC49                 ldr r1, [data_0x98B0]
       .text:0x000095FE    70EE810A             vadd.f32 s1, s1, s2
       .text:0x00009602    01F5167B             add.w fp, r1, #0x258
       .text:0x00009606    20EE200A             vmul.f32 s0, s0, s1
       .text:0x0000960A    BDEEC00A             vcvt.s32.f32 s0, s0
       .text:0x0000960E    10EE100A             vmov r0, s0
       .text:0x00009612    A9F84C00             strh.w r0, [sb, #0x4C]
       .text:0x00009616    01EB4400             add.w r0, r1, r4, lsl #0x1
       .text:0x0000961A    1B90                 str r0, [local_0x5C]
       .text:0x0000961C    B0F96000             ldrsh.w r0, [r0, #0x60]
       .text:0x00009620    C110                 asrs r1, r0, #0x3
       .text:0x00009622    A948                 ldr r0, [data_0x98C8]
       .text:0x00009624    30F81100             ldrh.w r0, [r0, r1, lsl #0x1]
       .text:0x00009628    1C99                 ldr r1, [local_0x58]
       .text:0x0000962A    00EE100A             vmov s0, r0
       .text:0x0000962E    2798                 ldr r0, [local_0x2C]
       .text:0x00009630    01EB8407             add.w r7, r1, r4, lsl #0x2
       .text:0x00009634    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x00009638    D0ED000A             vldr s1, [r0]
       .text:0x0000963C    20EE200A             vmul.f32 s0, s0, s1
       .text:0x00009640    BDEEC00A             vcvt.s32.f32 s0, s0
       .text:0x00009644    10EE100A             vmov r0, s0
       .text:0x00009648    A7F8AC00             strh.w r0, [r7, #0xAC]
       .text:0x0000964C    0BEB8400             add.w r0, fp, r4, lsl #0x2
       .text:0x00009650    1A90                 str r0, [local_0x60]
       .text:0x00009652    B0F94050             ldrsh.w r5, [r0, #0x40]
       .text:0x00009656    F9F7FFFA             bl func_0x2C58; inline int __cdecl( void )
       .text:0x0000965A    0828                 cmp r0, #0x8
       .text:0x0000965C    04D1                 bne code_0x9668
       */
r0 = r6;
r0 = func_0x807C(r0);
r1 = r0 & ~0x3;
r0 = *( data_0x98C0);
s0 = r7;
r0 = r0 + r1;
r2 = *( local_0x30);
s1 = *( r0);
s0 = (float) s0;
r0 = *( data_0x98C4);
r2 = *( r2 + 0x4C);
r1 = r0 + (r5 << 0x2);
r0 = r0 + (r2 << 0x2);
s0 = s1 * s0;
s1 = *( r1);
s2 = *( r0);
r1 = *( data_0x98B0);
s1 = s1 + s2;
fp = r1 + 0x258;
s0 = s0 * s1;
s0 = (int) s0;
r0 = s0;
*( sb + 0x4C ) = r0;
r0 = r1 + (r4 << 0x1);
*( local_0x5C ) = r0;
r0 = *( r0 + 0x60);
r1 = r0 >> 0x3;
r0 = *( data_0x98C8);
r0 = *( r0 + r1 << 0x1);
r1 = *( local_0x58);
s0 = r0;
r0 = *( local_0x2C);
r7 = r1 + (r4 << 0x2);
s0 = (float) s0;
s1 = *( r0);
s0 = s0 * s1;
s0 = (int) s0;
r0 = s0;
*( r7 + 0xAC ) = r0;
r0 = fp + (r4 << 0x2);
*( local_0x60 ) = r0;
r5 = *( r0 + 0x40);
r0 = func_0x2C58(r0);
    /*
       .text:0x0000965E code_0x965E:
       .text:0x0000965E    1CB9                 cbnz r4, code_0x9668
       */
    /*
       .text:0x00009660 code_0x9660:
       .text:0x00009660    02F0A8F9             bl func_0xB9B4; inline int __cdecl( void )
       .text:0x00009664    0228                 cmp r0, #0x2
       .text:0x00009666    04D0                 beq code_0x9672
       */
r0 = func_0xB9B4(r0);
    if (r0 == 8 && r4 == 0 && func_0xB9B4() != 2 ) {
      /*
         .text:0x00009672 code_0x9672:
         .text:0x00009672    3046                 mov r0, r6
         .text:0x00009674    F9F7F6FA             bl func_0x2C64; int __cdecl( int p1 )
         .text:0x00009678    05EB0010             add.w r0, r5, r0, lsl #0x4
         .text:0x0000967C    05B2                 sxth r5, r0
         .text:0x0000967E    B5F5805F             cmp.w r5, #0x1000
         .text:0x00009682    01DB                 blt code_0x9688
         */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = r5 + (r0 << 0x4);
r5 = (int) r0;
      if (r5 > 0x1000) {
        /*
           .text:0x00009684 code_0x9684:
           .text:0x00009684    40F6FF75             movw r5, #0xFFF
           */
r5 = 0xFFF;
      }
      /*
        .text:0x00009688 code_0x9688:
        .text:0x00009688    002D                 cmp r5, #0x0
        .text:0x0000968A    15DA                 bge code_0x96B8
        */
      if (r5 < 0) {
        /*
          .text:0x0000968C code_0x968C:
          .text:0x0000968C    0025                 movs r5, #0x0
          .text:0x0000968E    13E0                 b code_0x96B8
          */
r5 = 0x0;
      }
    } else {
      /*
         .text:0x00009668 code_0x9668:
         .text:0x00009668    F9F7F6FA             bl func_0x2C58; inline int __cdecl( void )
         .text:0x0000966C    0928                 cmp r0, #0x9
         .text:0x0000966E    0FD0                 beq code_0x9690
         */
r0 = func_0x2C58(r0);
      /*
         .text:0x00009670 code_0x9670:
         .text:0x00009670    22E0                 b code_0x96B8
         */
      if (r0 == 9) {
        /*
           .text:0x00009690 code_0x9690:
           .text:0x00009690    012C                 cmp r4, #0x1
           .text:0x00009692    11D1                 bne code_0x96B8
           */
        if (r4 == 1) {
          /*
             .text:0x0000969C code_0x969C:
             .text:0x0000969C    3046                 mov r0, r6
             .text:0x0000969E    F9F7E1FA             bl func_0x2C64; int __cdecl( int p1 )
             .text:0x000096A2    05EB0010             add.w r0, r5, r0, lsl #0x4
             .text:0x000096A6    05B2                 sxth r5, r0
             .text:0x000096A8    B5F5805F             cmp.w r5, #0x1000
             .text:0x000096AC    01DB                 blt code_0x96B2
             */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = r5 + (r0 << 0x4);
r5 = (int) r0;
          if (r5 < 0x1000) {
            /*
               .text:0x000096AE code_0x96AE:
               .text:0x000096AE    40F6FF75             movw r5, #0xFFF
               */
r5 = 0xFFF;
          }
          /*
             .text:0x000096B2 code_0x96B2:
             .text:0x000096B2    002D                 cmp r5, #0x0
             .text:0x000096B4    00DA                 bge code_0x96B8
             */
          if (r5 < 0) {
            /*
               .text:0x000096B6 code_0x96B6:
               .text:0x000096B6    0025                 movs r5, #0x0
               */
r5 = 0x0;
          }
        }
      }
    }
    /*
       .text:0x000096B8 code_0x96B8:
       .text:0x000096B8    7E48                 ldr r0, [string_tR_1]; "tR"
       .text:0x000096BA    B0F948B0             ldrsh.w fp, [r0, #0x48]
       .text:0x000096BE    F9F7CBFA             bl func_0x2C58; inline int __cdecl( void )
       .text:0x000096C2    0528                 cmp r0, #0x5
       .text:0x000096C4    14D1                 bne code_0x96F0
       */
r0 = *( string_tR_1);
fp = *( r0 + 0x48);
r0 = func_0x2C58(r0);
    if (r0 == 5) {
      /*
         .text:0x000096C6 code_0x96C6:
         .text:0x000096C6    02F075F9             bl func_0xB9B4; inline int __cdecl( void )
         .text:0x000096CA    0228                 cmp r0, #0x2
         .text:0x000096CC    10D1                 bne code_0x96F0
         */
r0 = func_0xB9B4(r0);
      if (r0 == 2) {
        /*
           .text:0x000096CE code_0x96CE:
           .text:0x000096CE    3046                 mov r0, r6
           .text:0x000096D0    F9F7C8FA             bl func_0x2C64; int __cdecl( int p1 )
           .text:0x000096D4    0BEB0010             add.w r0, fp, r0, lsl #0x4
           .text:0x000096D8    0FFA80FB             sxth.w fp, r0
           .text:0x000096DC    BBF5805F             cmp.w fp, #0x1000
           .text:0x000096E0    01DB                 blt code_0x96E6
           */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = fp + (r0 << 0x4);
fp = (int) r0;
        if (fp > 0x1000) {
          /*
             .text:0x000096E2 code_0x96E2:
             .text:0x000096E2    40F6FF7B             movw fp, #0xFFF
             */
fp = 0xFFF;
        }
        /*
           .text:0x000096E6 code_0x96E6:
           .text:0x000096E6    BBF1000F             cmp.w fp, #0x0
           .text:0x000096EA    01DA                 bge code_0x96F0
           */
        if (fp < 0) {
          /*
             .text:0x000096EC code_0x96EC:
             .text:0x000096EC    4FF0000B             mov.w fp, #0x0
             */
fp = 0x0;
        }
      }
    }
    /*
       .text:0x000096F0 code_0x96F0:
       .text:0x000096F0    FEF77AFD             bl func_0x81E8; inline int __cdecl( void )
       .text:0x000096F4    20B3                 cbz r0, code_0x9740
       */
r0 = func_0x81E8(r0);
    if (r0 == 0) {
      /*
         .text:0x00009740 code_0x9740:
         .text:0x00009740    98F80500             ldrb.w r0, [r8, #0x5]
         .text:0x00009744    FEF74EFF             bl func_0x85E4; inline int __cdecl( int p1 )
         .text:0x00009748    B7F86C10             ldrh.w r1, [r7, #0x6C]
         .text:0x0000974C    B7F8AC20             ldrh.w r2, [r7, #0xAC]
         .text:0x00009750    691A                 subs r1, r5, r1
         .text:0x00009752    891A                 subs r1, r1, r2
         .text:0x00009754    B9F84C20             ldrh.w r2, [sb, #0x4C]
         .text:0x00009758    891A                 subs r1, r1, r2
         .text:0x0000975A    A1EB0B01             sub.w r1, r1, fp
         .text:0x0000975E    081A                 subs r0, r1, r0
         .text:0x00009760    1D99                 ldr r1, [local_0x54]
         .text:0x00009762    21F82400             strh.w r0, [r1, r4, lsl #0x2]
         .text:0x00009766    D8E7                 b code_0x971A
         */
r0 = *( r8 + 0x5);
r0 = func_0x85E4(r0);
r1 = *( r7 + 0x6C);
r2 = *( r7 + 0xAC);
r1 = r5 - r1;
r1 = r1 - r2;
r2 = *( sb + 0x4C);
r1 = r1 - r2;
r1 = r1 - fp;
r0 = r1 - r0;
r1 = *( local_0x54);
*( r1 + r4 << 0x2 ) = r0;
    } else {
      /*
         .text:0x000096F6 code_0x96F6:
         .text:0x000096F6    98F80500             ldrb.w r0, [r8, #0x5]
         .text:0x000096FA    FEF773FF             bl func_0x85E4; inline int __cdecl( int p1 )
         .text:0x000096FE    B7F86C10             ldrh.w r1, [r7, #0x6C]
         .text:0x00009702    B7F8AC20             ldrh.w r2, [r7, #0xAC]
         .text:0x00009706    1144                 add r1, r2
         .text:0x00009708    B9F84C20             ldrh.w r2, [sb, #0x4C]
         .text:0x0000970C    2A44                 add r2, r5
         .text:0x0000970E    1144                 add r1, r2
         .text:0x00009710    5944                 add r1, fp
         .text:0x00009712    0844                 add r0, r1
         .text:0x00009714    1D99                 ldr r1, [local_0x54]
         .text:0x00009716    21F82400             strh.w r0, [r1, r4, lsl #0x2]
         */
r0 = *( r8 + 0x5);
r0 = func_0x85E4(r0);
r1 = *( r7 + 0x6C);
r2 = *( r7 + 0xAC);
r1 = r1 + r2;
r2 = *( sb + 0x4C);
r2 = r2 + r5;
r1 = r1 + r2;
r1 = r1 + fp;
r0 = r0 + r1;
r1 = *( local_0x54);
*( r1 + r4 << 0x2 ) = r0;
    }
    /*
       .text:0x0000971A code_0x971A:
       .text:0x0000971A    1D98                 ldr r0, [local_0x54]
       .text:0x0000971C    30F82410             ldrh.w r1, [r0, r4, lsl #0x2]
       .text:0x00009720    2598                 ldr r0, [local_0x34]
       .text:0x00009722    20F82410             strh.w r1, [r0, r4, lsl #0x2]
       .text:0x00009726    07F037F9             bl func_0x10998; inline int __cdecl( void )
       .text:0x0000972A    E8B1                 cbz r0, code_0x9768
       */
r0 = *( local_0x54);
r1 = *( r0 + r4 << 0x2);
r0 = *( local_0x34);
*( r0 + r4 << 0x2 ) = r1;
r0 = func_0x10998(r0);
    if (r0 == 0) {
      /*
         .text:0x00009768 code_0x9768:
         .text:0x00009768    0620                 movs r0, #0x6
         .text:0x0000976A    0190                 str r0, [local_0xC4]
         .text:0x0000976C    E0E7                 b code_0x9730
         */
r0 = 0x6;
*( local_0xC4 ) = r0;
    } else {
      /*
         .text:0x0000972C code_0x972C:
         .text:0x0000972C    0820                 movs r0, #0x8
         .text:0x0000972E    0190                 str r0, [local_0xC4]
         */
r0 = 0x8;
*( local_0xC4 ) = r0;
    }
    /*
       .text:0x00009730 code_0x9730:
       .text:0x00009730    5F48                 ldr r0, [data_0x98B0]
       .text:0x00009732    B0F94A50             ldrsh.w r5, [r0, #0x4A]
       .text:0x00009736    F9F78FFA             bl func_0x2C58; inline int __cdecl( void )
       .text:0x0000973A    0328                 cmp r0, #0x3
       .text:0x0000973C    17D0                 beq code_0x976E
       */
r0 = *( data_0x98B0);
r5 = *( r0 + 0x4A);
r0 = func_0x2C58(r0);
    if (r0 != 3) {
      /*
         .text:0x0000973E code_0x973E:
         .text:0x0000973E    28E0                 b code_0x9792
         */
    } else {
      /*
         .text:0x0000976E code_0x976E:
         .text:0x0000976E    02F021F9             bl func_0xB9B4; inline int __cdecl( void )
         .text:0x00009772    0228                 cmp r0, #0x2
         .text:0x00009774    0DD1                 bne code_0x9792
         */
r0 = func_0xB9B4(r0);
      if (r0 == 2) {
        /*
          .text:0x00009776 code_0x9776:
          .text:0x00009776    3046                 mov r0, r6
          .text:0x00009778    F9F774FA             bl func_0x2C64; int __cdecl( int p1 )
          .text:0x0000977C    05EB4000             add.w r0, r5, r0, lsl #0x1
          .text:0x00009780    05B2                 sxth r5, r0
          .text:0x00009782    B5F5007F             cmp.w r5, #0x200
          .text:0x00009786    01DB                 blt code_0x978C
          */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = r5 + (r0 << 0x1);
r5 = (int) r0;
        if (r5 > 0x200) {
          /*
            .text:0x00009788 code_0x9788:
            .text:0x00009788    40F2FF15             movw r5, #0x1FF
            */
r5 = 0x1FF;
          /*
            .text:0x0000978C code_0x978C:
            .text:0x0000978C    002D                 cmp r5, #0x0
            .text:0x0000978E    00DA                 bge code_0x9792
            */
          if (r0 < 0) {
            /*
              .text:0x00009790 code_0x9790:
              .text:0x00009790    0025                 movs r5, #0x0
              */
r5 = 0x0;
          }
        }
      }
    }
    /*
       .text:0x00009792 code_0x9792:
       .text:0x00009792    3046                 mov r0, r6
       .text:0x00009794    FEF772FC             bl func_0x807C; int __cdecl( int p1 )
       .text:0x00009798    20F00301             bic r1, r0, #0x3
       .text:0x0000979C    4B48                 ldr r0, [data_0x98CC]
       .text:0x0000979E    DFF814B1             ldr.w fp, [string_tR_1]; "tR"
       .text:0x000097A2    0844                 add r0, r1
       .text:0x000097A4    D0ED000A             vldr s1, [r0]
       .text:0x000097A8    0198                 ldr r0, [local_0xC4]
       .text:0x000097AA    00EE100A             vmov s0, r0
       .text:0x000097AE    4548                 ldr r0, [data_0x98C4]
       .text:0x000097B0    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x000097B4    00EB8501             add.w r1, r0, r5, lsl #0x2
       .text:0x000097B8    20EE800A             vmul.f32 s0, s1, s0
       .text:0x000097BC    D1ED000A             vldr s1, [r1]
       .text:0x000097C0    2699                 ldr r1, [local_0x30]
       .text:0x000097C2    B1F94C10             ldrsh.w r1, [r1, #0x4C]
       .text:0x000097C6    00EB8100             add.w r0, r0, r1, lsl #0x2
       .text:0x000097CA    90ED001A             vldr s2, [r0]
       .text:0x000097CE    70EE810A             vadd.f32 s1, s1, s2
       .text:0x000097D2    20EE200A             vmul.f32 s0, s0, s1
       .text:0x000097D6    BDEEC00A             vcvt.s32.f32 s0, s0
       .text:0x000097DA    10EE100A             vmov r0, s0
       .text:0x000097DE    A9F84E00             strh.w r0, [sb, #0x4E]
       .text:0x000097E2    1B98                 ldr r0, [local_0x5C]
       .text:0x000097E4    B0F96000             ldrsh.w r0, [r0, #0x60]
       .text:0x000097E8    C110                 asrs r1, r0, #0x3
       .text:0x000097EA    3948                 ldr r0, [data_0x98D0]
       .text:0x000097EC    30F81100             ldrh.w r0, [r0, r1, lsl #0x1]
       .text:0x000097F0    00EE100A             vmov s0, r0
       .text:0x000097F4    2798                 ldr r0, [local_0x2C]
       .text:0x000097F6    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x000097FA    D0ED000A             vldr s1, [r0]
       .text:0x000097FE    20EE200A             vmul.f32 s0, s0, s1
       .text:0x00009802    BDEEC00A             vcvt.s32.f32 s0, s0
       .text:0x00009806    10EE100A             vmov r0, s0
       .text:0x0000980A    A7F8AE00             strh.w r0, [r7, #0xAE]
       .text:0x0000980E    1A98                 ldr r0, [local_0x60]
       .text:0x00009810    B0F94250             ldrsh.w r5, [r0, #0x42]
       .text:0x00009814    F9F720FA             bl func_0x2C58; inline int __cdecl( void )
       .text:0x00009818    0628                 cmp r0, #0x6
       .text:0x0000981A    04D1                 bne code_0x9826
       */
r0 = r6;
r0 = func_0x807C(r0);
r1 = r0 & ~0x3;
r0 = *( data_0x98CC);
fp = *( string_tR_1);
r0 = r0 + r1;
s1 = *( r0);
r0 = *( local_0xC4);
s0 = r0;
r0 = *( data_0x98C4);
s0 = (float) s0;
r1 = r0 + (r5 << 0x2);
s0 = s1 * s0;
s1 = *( r1);
r1 = *( local_0x30);
r1 = *( r1 + 0x4C);
r0 = r0 + (r1 << 0x2);
s2 = *( r0);
s1 = s1 + s2;
s0 = s0 * s1;
s0 = (int) s0;
r0 = s0;
*( sb + 0x4E ) = r0;
r0 = *( local_0x5C);
r0 = *( r0 + 0x60);
r1 = r0 >> 0x3;
r0 = *( data_0x98D0);
r0 = *( r0 + r1 << 0x1);
s0 = r0;
r0 = *( local_0x2C);
s0 = (float) s0;
s1 = *( r0);
s0 = s0 * s1;
s0 = (int) s0;
r0 = s0;
*( r7 + 0xAE ) = r0;
r0 = *( local_0x60);
r5 = *( r0 + 0x42);
r0 = func_0x2C58(r0);
    cond = r0 == 6;
    /*
       .text:0x0000981C code_0x981C:
       .text:0x0000981C    1CB9                 cbnz r4, code_0x9826
       */
    /*
       .text:0x0000981E code_0x981E:
       .text:0x0000981E    02F0C9F8             bl func_0xB9B4; inline int __cdecl( void )
       .text:0x00009822    0228                 cmp r0, #0x2
       .text:0x00009824    04D0                 beq code_0x9830
       */
r0 = func_0xB9B4(r0);
    if (cond && r4 == 0 && func_0xB9B4() == 2) {
      /*
         .text:0x00009830 code_0x9830:
         .text:0x00009830    3046                 mov r0, r6
         .text:0x00009832    F9F717FA             bl func_0x2C64; int __cdecl( int p1 )
         .text:0x00009836    05EB0010             add.w r0, r5, r0, lsl #0x4
         .text:0x0000983A    05B2                 sxth r5, r0
         .text:0x0000983C    B5F5805F             cmp.w r5, #0x1000
         .text:0x00009840    01DB                 blt code_0x9846
         */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = r5 + (r0 << 0x4);
r5 = (int) r0;
      if (r5 >= 0x1000) {
        /*
           .text:0x00009842 code_0x9842:
           .text:0x00009842    40F6FF75             movw r5, #0xFFF
           */
r5 = 0xFFF;
      }
      /*
         .text:0x00009846 code_0x9846:
         .text:0x00009846    002D                 cmp r5, #0x0
         .text:0x00009848    15DA                 bge code_0x9876
         */
      if (r5 < 0) {
        /*
           .text:0x0000984A code_0x984A:
           .text:0x0000984A    0025                 movs r5, #0x0
           .text:0x0000984C    13E0                 b code_0x9876
           */
r5 = 0x0;
      }
    } else {
      /*
         .text:0x00009826 code_0x9826:
         .text:0x00009826    F9F717FA             bl func_0x2C58; inline int __cdecl( void )
         .text:0x0000982A    0728                 cmp r0, #0x7
         .text:0x0000982C    0FD0                 beq code_0x984E
         */
r0 = func_0x2C58(r0);
      if (func_0x2C58() != 7) {
        /*
           .text:0x0000982E code_0x982E:
           .text:0x0000982E    22E0                 b code_0x9876
           */
      } else {
        /*
           .text:0x0000984E code_0x984E:
           .text:0x0000984E    012C                 cmp r4, #0x1
           .text:0x00009850    11D1                 bne code_0x9876
           */
        if (r4 == 1) {
          /*
             .text:0x00009852 code_0x9852:
             .text:0x00009852    02F0AFF8             bl func_0xB9B4; inline int __cdecl( void )
             .text:0x00009856    0228                 cmp r0, #0x2
             .text:0x00009858    0DD1                 bne code_0x9876
             */
r0 = func_0xB9B4(r0);
          if (r0 == 2) {
            /*
               .text:0x0000985A code_0x985A:
               .text:0x0000985A    3046                 mov r0, r6
               .text:0x0000985C    F9F702FA             bl func_0x2C64; int __cdecl( int p1 )
               .text:0x00009860    05EB0010             add.w r0, r5, r0, lsl #0x4
               .text:0x00009864    05B2                 sxth r5, r0
               .text:0x00009866    B5F5805F             cmp.w r5, #0x1000
               .text:0x0000986A    01DB                 blt code_0x9870
               */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = r5 + (r0 << 0x4);
r5 = (int) r0;
            if (r5 > 0x1000) {
              /*
                 .text:0x0000986C code_0x986C:
                 .text:0x0000986C    40F6FF75             movw r5, #0xFFF
                 */
r5 = 0xFFF;
            }
            /*
               .text:0x00009870 code_0x9870:
               .text:0x00009870    002D                 cmp r5, #0x0
               .text:0x00009872    00DA                 bge code_0x9876
               */
            if (r5 < 0) {
              /*
                 .text:0x00009874 code_0x9874:
                 .text:0x00009874    0025                 movs r5, #0x0
                 */
r5 = 0x0;
            }
          }
        }
      }
    }
    /*
       .text:0x00009876 code_0x9876:
       .text:0x00009876    BBF94AB0             ldrsh.w fp, [fp, #0x4A]
       .text:0x0000987A    F9F7EDF9             bl func_0x2C58; inline int __cdecl( void )
       .text:0x0000987E    0528                 cmp r0, #0x5
       .text:0x00009880    2FD1                 bne code_0x98E2
       */
fp = *( fp + 0x4A);
r0 = func_0x2C58(r0);
    cond = r0 == 5;
    /*
       .text:0x00009882 code_0x9882:
       .text:0x00009882    02F097F8             bl func_0xB9B4; inline int __cdecl( void )
       .text:0x00009886    0228                 cmp r0, #0x2
       .text:0x00009888    2BD1                 bne code_0x98E2
       */
r0 = func_0xB9B4(r0);
    if (cond && func_0xB9B4() == 2) {
      /*
         .text:0x0000988A code_0x988A:
         .text:0x0000988A    3046                 mov r0, r6
         .text:0x0000988C    F9F7EAF9             bl func_0x2C64; int __cdecl( int p1 )
         .text:0x00009890    0BEB0010             add.w r0, fp, r0, lsl #0x4
         .text:0x00009894    0FFA80FB             sxth.w fp, r0
         .text:0x00009898    BBF5805F             cmp.w fp, #0x1000
         .text:0x0000989C    1CDB                 blt code_0x98D8
         */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = fp + (r0 << 0x4);
fp = (int) r0;
      if (fp > 0x1000) {
        /*
           .text:0x0000989E code_0x989E:
           .text:0x0000989E    19E0                 b code_0x98D4
           */
        /*
           .text:0x000098D4 code_0x98D4:
           .text:0x000098D4    40F6FF7B             movw fp, #0xFFF
           */
fp = 0xFFF;
      }
      /*
         .text:0x000098D8 code_0x98D8:
         .text:0x000098D8    BBF1000F             cmp.w fp, #0x0
         .text:0x000098DC    01DA                 bge code_0x98E2
         */
      if (fp < 0) {
        /*
           .text:0x000098DE code_0x98DE:
           .text:0x000098DE    4FF0000B             mov.w fp, #0x0
           */
fp = 0x0;
      }
    }
    /*
       .text:0x000098E2 code_0x98E2:
       .text:0x000098E2    98F80500             ldrb.w r0, [r8, #0x5]
       .text:0x000098E6    FEF78BFE             bl func_0x8600; inline int __cdecl( int p1 )
       .text:0x000098EA    B7F86E10             ldrh.w r1, [r7, #0x6E]
       .text:0x000098EE    B7F8AE20             ldrh.w r2, [r7, #0xAE]
       .text:0x000098F2    1144                 add r1, r2
       .text:0x000098F4    B9F84E20             ldrh.w r2, [sb, #0x4E]
       .text:0x000098F8    2A44                 add r2, r5
       .text:0x000098FA    1144                 add r1, r2
       .text:0x000098FC    5944                 add r1, fp
       .text:0x000098FE    0844                 add r0, r1
       .text:0x00009900    1D99                 ldr r1, [local_0x54]
       .text:0x00009902    01EB8401             add.w r1, r1, r4, lsl #0x2
       .text:0x00009906    4880                 strh r0, [r1, #0x2]
       .text:0x00009908    2599                 ldr r1, [local_0x34]
       .text:0x0000990A    01EB8401             add.w r1, r1, r4, lsl #0x2
       .text:0x0000990E    4880                 strh r0, [r1, #0x2]
       .text:0x00009910    5C4F                 ldr r7, [data_0x9A84]
       .text:0x00009912    B7F9E450             ldrsh.w r5, [r7, #0xE4]
       .text:0x00009916    F9F79FF9             bl func_0x2C58; inline int __cdecl( void )
       .text:0x0000991A    0428                 cmp r0, #0x4
       .text:0x0000991C    09D1                 bne code_0x9932
       */
r0 = *( r8 + 0x5);
r0 = func_0x8600(r0);
r1 = *( r7 + 0x6E);
r2 = *( r7 + 0xAE);
r1 = r1 + r2;
r2 = *( sb + 0x4E);
r2 = r2 + r5;
r1 = r1 + r2;
r1 = r1 + fp;
r0 = r0 + r1;
r1 = *( local_0x54);
r1 = r1 + (r4 << 0x2);
*( r1 + 0x2 ) = r0;
r1 = *( local_0x34);
r1 = r1 + (r4 << 0x2);
*( r1 + 0x2 ) = r0;
r7 = *( data_0x9A84);
r5 = *( r7 + 0xE4);
r0 = func_0x2C58(r0);
    if (r0 == 4) {
      /*
         .text:0x0000991E code_0x991E:
         .text:0x0000991E    02F049F8             bl func_0xB9B4; inline int __cdecl( void )
         .text:0x00009922    0228                 cmp r0, #0x2
         .text:0x00009924    05D1                 bne code_0x9932
         */
r0 = func_0xB9B4(r0);
      if (r0 == 2) {
        /*
           .text:0x00009926 code_0x9926:
           .text:0x00009926    3046                 mov r0, r6
           .text:0x00009928    F9F79CF9             bl func_0x2C64; int __cdecl( int p1 )
           .text:0x0000992C    05EB4000             add.w r0, r5, r0, lsl #0x1
           .text:0x00009930    05B2                 sxth r5, r0
           */
r0 = r6;
r0 = func_0x2C64(r0);
r0 = r5 + (r0 << 0x1);
r5 = (int) r0;
      }
    }
    /*
       .text:0x00009932 code_0x9932:
       .text:0x00009932    B5F5007F             cmp.w r5, #0x200
       .text:0x00009936    02DB                 blt code_0x993E
       */
    if (r5 > 0x200) {
      /*
         .text:0x00009938 code_0x9938:
         .text:0x00009938    40F2FF15             movw r5, #0x1FF
         .text:0x0000993C    02E0                 b code_0x9944
         */
r5 = 0x1FF;
    } else {
      /*
        .text:0x0000993E code_0x993E:
        .text:0x0000993E    002D                 cmp r5, #0x0
        .text:0x00009940    00DA                 bge code_0x9944
        */
      if (r5 < 0) {
        /*
          .text:0x00009942 code_0x9942:
          .text:0x00009942    0025                 movs r5, #0x0
          */
r5 = 0x0;
      }
    }
    /*
       .text:0x00009944 code_0x9944:
       .text:0x00009944    3046                 mov r0, r6
       .text:0x00009946    FEF799FB             bl func_0x807C; int __cdecl( int p1 )
       .text:0x0000994A    8008                 lsrs r0, r0, #0x2
       .text:0x0000994C    B0F5806F             cmp.w r0, #0x400
       .text:0x00009950    01DB                 blt code_0x9956
       */
r0 = r6;
r0 = func_0x807C(r0);
r0 = r0 >> 0x2;
    if (r0 >= 0x400) {
      /*
         .text:0x00009952 code_0x9952:
         .text:0x00009952    40F2FF30             movw r0, #0x3FF
         */
r0 = 0x3FF;
    }
    /*
       .text:0x00009956 code_0x9956:
       .text:0x00009956    4C49                 ldr r1, [data_0x9A88]
       .text:0x00009958    01EB8000             add.w r0, r1, r0, lsl #0x2
       .text:0x0000995C    1F99                 ldr r1, [local_0x4C]
       .text:0x0000995E    D0ED000A             vldr s1, [r0]
       .text:0x00009962    0198                 ldr r0, [local_0xC4]
       .text:0x00009964    00EE100A             vmov s0, r0
       .text:0x00009968    4848                 ldr r0, [data_0x9A8C]
       .text:0x0000996A    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000996E    00EB8500             add.w r0, r0, r5, lsl #0x2
       .text:0x00009972    20EE800A             vmul.f32 s0, s1, s0
       .text:0x00009976    D0ED000A             vldr s1, [r0]
       .text:0x0000997A    20EE200A             vmul.f32 s0, s0, s1
       .text:0x0000997E    BDEEC00A             vcvt.s32.f32 s0, s0
       .text:0x00009982    10EE100A             vmov r0, s0
       .text:0x00009986    A1F84400             strh.w r0, [r1, #0x44]
       .text:0x0000998A    07EB4407             add.w r7, r7, r4, lsl #0x1
       .text:0x0000998E    1E99                 ldr r1, [local_0x50]
       .text:0x00009990    B7F9EA00             ldrsh.w r0, [r7, #0xEA]
       .text:0x00009994    01EB4405             add.w r5, r1, r4, lsl #0x1
       .text:0x00009998    00EE100A             vmov s0, r0
       .text:0x0000999C    2798                 ldr r0, [local_0x2C]
       .text:0x0000999E    B8EEC00A             vcvt.f32.s32 s0, s0
       .text:0x000099A2    D0ED000A             vldr s1, [r0]
       .text:0x000099A6    20EE200A             vmul.f32 s0, s0, s1
       .text:0x000099AA    BDEEC00A             vcvt.s32.f32 s0, s0
       .text:0x000099AE    10EE100A             vmov r0, s0
       .text:0x000099B2    A5F87400             strh.w r0, [r5, #0x74]
       .text:0x000099B6    98F80500             ldrb.w r0, [r8, #0x5]
       .text:0x000099BA    FEF735FE             bl func_0x8628; inline int __cdecl( int p1 )
       .text:0x000099BE    B5F85410             ldrh.w r1, [r5, #0x54]
       .text:0x000099C2    B7F8E020             ldrh.w r2, [r7, #0xE0]
       .text:0x000099C6    B5F87430             ldrh.w r3, [r5, #0x74]
       .text:0x000099CA    0A44                 add r2, r1
       .text:0x000099CC    1F99                 ldr r1, [local_0x4C]
       .text:0x000099CE    B1F84410             ldrh.w r1, [r1, #0x44]
       .text:0x000099D2    1944                 add r1, r3
       .text:0x000099D4    1144                 add r1, r2
       .text:0x000099D6    0844                 add r0, r1
       .text:0x000099D8    00B2                 sxth r0, r0
       .text:0x000099DA    2AF81400             strh.w r0, [sl, r4, lsl #0x1]
       .text:0x000099DE    B0F5805F             cmp.w r0, #0x1000
       .text:0x000099E2    03DB                 blt code_0x99EC
       */
r1 = *( data_0x9A88);
r0 = r1 + (r0 << 0x2);
r1 = *( local_0x4C);
s1 = *( r0);
r0 = *( local_0xC4);
s0 = r0;
r0 = *( data_0x9A8C);
s0 = (float) s0;
r0 = r0 + (r5 << 0x2);
s0 = s1 * s0;
s1 = *( r0);
s0 = s0 * s1;
s0 = (int) s0;
r0 = s0;
*( r1 + 0x44 ) = r0;
r7 = r7 + (r4 << 0x1);
r1 = *( local_0x50);
r0 = *( r7 + 0xEA);
r5 = r1 + (r4 << 0x1);
s0 = r0;
r0 = *( local_0x2C);
s0 = (float) s0;
s1 = *( r0);
s0 = s0 * s1;
s0 = (int) s0;
r0 = s0;
*( r5 + 0x74 ) = r0;
r0 = *( r8 + 0x5);
r0 = func_0x8628(r0);
r1 = *( r5 + 0x54);
r2 = *( r7 + 0xE0);
r3 = *( r5 + 0x74);
r2 = r2 + r1;
r1 = *( local_0x4C);
r1 = *( r1 + 0x44);
r1 = r1 + r3;
r1 = r1 + r2;
r0 = r0 + r1;
r0 = (int) r0;
*( sl + r4 << 0x1 ) = r0;
    if (r0 > 0x1000) {
      /*
         .text:0x000099E4 code_0x99E4:
         .text:0x000099E4    40F6FF70             movw r0, #0xFFF
         .text:0x000099E8    2AF81400             strh.w r0, [sl, r4, lsl #0x1]
         */
r0 = 0xFFF;
*( sl + r4 << 0x1 ) = r0;
    }
    /*
       .text:0x000099EC code_0x99EC:
       .text:0x000099EC    3AF91400             ldrsh.w r0, [sl, r4, lsl #0x1]
       .text:0x000099F0    0028                 cmp r0, #0x0
       .text:0x000099F2    02DA                 bge code_0x99FA
       */
r0 = *( sl + r4 << 0x1);
    if (r0 < 0) {
      /*
         .text:0x000099F4 code_0x99F4:
         .text:0x000099F4    0020                 movs r0, #0x0
         .text:0x000099F6    2AF81400             strh.w r0, [sl, r4, lsl #0x1]
         */
r0 = 0x0;
*( sl + r4 << 0x1 ) = r0;
    }
    /*
       .text:0x000099FA code_0x99FA:
       .text:0x000099FA    2298                 ldr r0, [local_0x40]
       .text:0x000099FC    3AF81410             ldrh.w r1, [sl, r4, lsl #0x1]
       .text:0x00009A00    20F81410             strh.w r1, [r0, r4, lsl #0x1]
       .text:0x00009A04    FEF78AF9             bl func_0x7D1C; inline int __cdecl( void )
       .text:0x00009A08    0128                 cmp r0, #0x1
       .text:0x00009A0A    11D0                 beq code_0x9A30
       */
r0 = *( local_0x40);
r1 = *( sl + r4 << 0x1);
*( r0 + r4 << 0x1 ) = r1;
r0 = func_0x7D1C(r0);
    if (r0 == 1) {
      /*
         .text:0x00009A30 code_0x9A30:
         .text:0x00009A30    1CB9                 cbnz r4, code_0x9A3A
         */
      if (r4 == 0) {
        /*
           .text:0x00009A32 code_0x9A32:
           .text:0x00009A32    98F81000             ldrb.w r0, [r8, #0x10]
           .text:0x00009A36    0428                 cmp r0, #0x4
           .text:0x00009A38    02D0                 beq code_0x9A40
           */
r0 = *( r8 + 0x10);
        if (r0 == 4) {
          /*
             .text:0x00009A56 code_0x9A56:
             .text:0x00009A56    2298                 ldr r0, [local_0x40]
             .text:0x00009A58    30F81400             ldrh.w r0, [r0, r4, lsl #0x1]
             .text:0x00009A5C    8008                 lsrs r0, r0, #0x2
             .text:0x00009A5E    FEF765F9             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
             .text:0x00009A62    0246                 mov r2, r0
             .text:0x00009A64    2198                 ldr r0, [local_0x44]
             .text:0x00009A66    04EB4000             add.w r0, r4, r0, lsl #0x1
             .text:0x00009A6A    C1B2                 uxtb r1, r0
             .text:0x00009A6C    2098                 ldr r0, [local_0x48]
             .text:0x00009A6E    00F0D3FA             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
             .text:0x00009A72    D3E7                 b code_0x9A1C
             */
r0 = *( local_0x40);
r0 = *( r0 + r4 << 0x1);
r0 = r0 >> 0x2;
r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
r2 = r0;
r0 = *( local_0x44);
r0 = r4 + (r0 << 0x1);
r1 = (unsigned int) r0;
r0 = *( local_0x48);
set_2000xxB4(r0,r1,r2);
        } else {
          /*
            .text:0x00009A40 code_0x9A40:
            .text:0x00009A40    2498                 ldr r0, [local_0x38]
            .text:0x00009A42    0022                 movs r2, #0x0
            .text:0x00009A44    C1B2                 uxtb r1, r0
            .text:0x00009A46    2098                 ldr r0, [local_0x48]
            .text:0x00009A48    00F0E6FA             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
            .text:0x00009A4C    E6E7                 b code_0x9A1C
            */
r0 = *( local_0x38);
r2 = 0x0;
r1 = (unsigned int) r0;
r0 = *( local_0x48);
set_2000xxB4(r0,r1,r2);
        }
      } else {
        /*
           .text:0x00009A3A code_0x9A3A:
           .text:0x00009A3A    012C                 cmp r4, #0x1
           .text:0x00009A3C    07D0                 beq code_0x9A4E
           */
        /*
           .text:0x00009A3E code_0x9A3E:
           .text:0x00009A3E    0AE0                 b code_0x9A56
           */
        /*
           .text:0x00009A4E code_0x9A4E:
           .text:0x00009A4E    98F82000             ldrb.w r0, [r8, #0x20]
           .text:0x00009A52    0428                 cmp r0, #0x4
           .text:0x00009A54    0ED0                 beq code_0x9A74
           */
r0 = *( r8 + 0x20);
        if ( r4 != 1 && r0 != 4 ) {
          /*
             .text:0x00009A56 code_0x9A56:
             .text:0x00009A56    2298                 ldr r0, [local_0x40]
             .text:0x00009A58    30F81400             ldrh.w r0, [r0, r4, lsl #0x1]
             .text:0x00009A5C    8008                 lsrs r0, r0, #0x2
             .text:0x00009A5E    FEF765F9             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
             .text:0x00009A62    0246                 mov r2, r0
             .text:0x00009A64    2198                 ldr r0, [local_0x44]
             .text:0x00009A66    04EB4000             add.w r0, r4, r0, lsl #0x1
             .text:0x00009A6A    C1B2                 uxtb r1, r0
             .text:0x00009A6C    2098                 ldr r0, [local_0x48]
             .text:0x00009A6E    00F0D3FA             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
             .text:0x00009A72    D3E7                 b code_0x9A1C
             */
r0 = *( local_0x40);
r0 = *( r0 + r4 << 0x1);
r0 = r0 >> 0x2;
r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
r2 = r0;
r0 = *( local_0x44);
r0 = r4 + (r0 << 0x1);
r1 = (unsigned int) r0;
r0 = *( local_0x48);
set_2000xxB4(r0,r1,r2);
        } else {
          /*
            .text:0x00009A74 code_0x9A74:
            .text:0x00009A74    2398                 ldr r0, [local_0x3C]
            .text:0x00009A76    0022                 movs r2, #0x0
            .text:0x00009A78    C1B2                 uxtb r1, r0
            .text:0x00009A7A    2098                 ldr r0, [local_0x48]
            .text:0x00009A7C    00F0CCFA             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
            .text:0x00009A80    CCE7                 b code_0x9A1C
            */
r0 = *( local_0x3C);
r2 = 0x0;
r1 = (unsigned int) r0;
r0 = *( local_0x48);
set_2000xxB4(r0,r1,r2);
        }
      }
    } else {
      /*
         .text:0x00009A0C code_0x9A0C:
         .text:0x00009A0C    2198                 ldr r0, [local_0x44]
         .text:0x00009A0E    0022                 movs r2, #0x0
         .text:0x00009A10    04EB4000             add.w r0, r4, r0, lsl #0x1
         .text:0x00009A14    C1B2                 uxtb r1, r0
         .text:0x00009A16    2098                 ldr r0, [local_0x48]
         .text:0x00009A18    00F0FEFA             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
         */
r0 = *( local_0x44);
r2 = 0x0;
r0 = r4 + (r0 << 0x1);
r1 = (unsigned int) r0;
r0 = *( local_0x48);
set_2000xxB4(r0,r1,r2);
    }
    /*
       .text:0x00009A1C code_0x9A1C:
       .text:0x00009A1C    641C                 adds r4, r4, #0x1
       .text:0x00009A1E    022C                 cmp r4, #0x2
       .text:0x00009A20    FFF6A8AD             blt.w code_0x9574
       */
r4 = r4 + 0x1;
    if (r4 >= 2) {
      break;
    }
  }
  /*
     .text:0x00009A24 code_0x9A24:
     .text:0x00009A24    29B0                 add sp, #0xA4
     .text:0x00009A26    3046                 mov r0, r6
     .text:0x00009A28    BDE8F04F             pop.w {r4, r5, r6, r7, r8, sb, sl, fp, lr}
     .text:0x00009A2C    10F03EB9             b.w func_0x19CAC; void __cdecl( int p1 )
     */
sp = sp + 0xA4;
r0 = r6;
}

