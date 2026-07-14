void TIM1_UP_TIM10() { 
    /*
    .text:0x00014D14    2DE9F04F             push.w {r4, r5, r6, r7, r8, sb, sl, fp, lr}
    .text:0x00014D18    2DED068B             vpush {d8, d9, d10}
    .text:0x00014D1C    81B0                 sub sp, #0x4
    .text:0x00014D1E    0121                 movs r1, #0x1
    .text:0x00014D20    FE4C                 ldr r4, [_0x40014400_3]
    .text:0x00014D22    2046                 mov r0, r4
    .text:0x00014D24    01F0D6FC             bl func_0x166D4; int __cdecl( int p1, int p2 )
    .text:0x00014D28    DFF8F483             ldr.w r8, [_0x457FE000]
    .text:0x00014D2C    4FF00209             mov.w sb, #0x2
    .text:0x00014D30    F7EE008A             vmov.f32 s17, #1.000000e+00
    .text:0x00014D34    9FEDFB8A             vldr s16, [_0xBF7CD6EA]
    .text:0x00014D38    FB4E                 ldr r6, [_0x20004BDC]
    .text:0x00014D3A    0327                 movs r7, #0x3
    .text:0x00014D3C    4FF0040A             mov.w sl, #0x4
    .text:0x00014D40    9FEDFAAA             vldr s20, [_0x00000000]
    .text:0x00014D44    0025                 movs r5, #0x0
    .text:0x00014D46    4FF0010B             mov.w fp, #0x1
    .text:0x00014D4A    0028                 cmp r0, #0x0
    .text:0x00014D4C    00F06084             beq.w code_0x15610
    */
sp = sp - 0x4;
r1 = 0x1;
r4 = *( _0x40014400_3 );
r0 = r4;
r0 = func_0x166D4(r0,r1);
r8 = *( _0x457FE000 );
sb = 0x2;
s17 = 1.000000e+00;
s16 = *( _0xBF7CD6EA );
r6 = *( _0x20004BDC );
r7 = 0x3;
sl = 0x4;
s20 = *( _0x00000000 );
r5 = 0x0;
fp = 0x1;

    cond1 = r0 != 0;

    /*    
    .text:0x00014D50 code_0x14D50:
    .text:0x00014D50    0121                 movs r1, #0x1
    .text:0x00014D52    2046                 mov r0, r4
    .text:0x00014D54    01F0D4FB             bl func_0x16500; inline void __cdecl( int p1, int p2 )
    .text:0x00014D58    0095                 str r5, [local_0x28]
    .text:0x00014D5A    F6F73DFE             bl two_or_four_or_with_20000F30; int __cdecl( void )
    .text:0x00014D5E    9DF80010             ldrb.w r1, [local_0x28]
    .text:0x00014D62    8842                 cmp r0, r1
    .text:0x00014D64    40F25484             bls.w code_0x15610
    */
r1 = 0x1;
r0 = r4;
func_0x16500(r0,r1,r2);
*( local_0x28 ) = r5;
r0 = two_or_four_or_with_20000F30(r0);
r1 = *( local_0x28 );

    cond2 = r0 > r1;

    if ( cond1 && cond2 ) {
        /*
        .text:0x00014D68 code_0x14D68:
        .text:0x00014D68    9FEDF19A             vldr s18, [_0x3C4A458F]
        .text:0x00014D6C    DFEDF19A             vldr s19, [_0x41CA2C46]
        .text:0x00014D70    DFEDF1AA             vldr s21, [_0x457FF000]
        .text:0x00014D74    F14C                 ldr r4, [_0x2000501C]
        */
s18 = *( _0x3C4A458F );
s19 = *( _0x41CA2C46 );
s21 = *( _0x457FF000 );
r4 = *( _0x2000501C );
        while (1) {
            /*
            .text:0x00014D76 code_0x14D76:
            .text:0x00014D76    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x00014D7A    00EB4001             add.w r1, r0, r0, lsl #0x1
            .text:0x00014D7E    01EBC000             add.w r0, r1, r0, lsl #0x3
            .text:0x00014D82    EF49                 ldr r1, [_0x20001FD4_7]
            .text:0x00014D84    01EB8000             add.w r0, r1, r0, lsl #0x2
            .text:0x00014D88    407A                 ldrb r0, [r0, #0x9]
            .text:0x00014D8A    0128                 cmp r0, #0x1
            .text:0x00014D8C    40F0FD81             bne.w code_0x1518A
            */
r0 = *( local_0x28 );
r1 = r0 + (r0 << 0x1);
r0 = r1 + (r0 << 0x3);
r1 = *( _0x20001FD4_7 );
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x9 );
            if (r0 == 1) {
                /*
                .text:0x00014D90 code_0x14D90:
                .text:0x00014D90    9DF80000             ldrb.w r0, [local_0x28]
                .text:0x00014D94    00EB4002             add.w r2, r0, r0, lsl #0x1
                .text:0x00014D98    02EBC000             add.w r0, r2, r0, lsl #0x3
                .text:0x00014D9C    01EB8000             add.w r0, r1, r0, lsl #0x2
                .text:0x00014DA0    007A                 ldrb r0, [r0, #0x8]
                .text:0x00014DA2    48B1                 cbz r0, code_0x14DB8
                */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x8 );
                if (r0 != 0) {
                    /*
                    .text:0x00014DA4 code_0x14DA4:
                    .text:0x00014DA4    0128                 cmp r0, #0x1
                    .text:0x00014DA6    7CD0                 beq code_0x14EA2
                    */
                    if (r0 != 1) {
                        /*
                        .text:0x00014DA8 code_0x14DA8:
                        .text:0x00014DA8    0228                 cmp r0, #0x2
                        .text:0x00014DAA    00F06781             beq.w code_0x1507C
                        */
                        if (r0 != 2) {
                          /*
                          .text:0x00014DAE code_0x14DAE:
                          .text:0x00014DAE    0328                 cmp r0, #0x3
                          .text:0x00014DB0    40F0EB81             bne.w code_0x1518A
                          */
                          if (r0 == 3) {
                            /*
                            .text:0x00014DB4 code_0x14DB4:
                            .text:0x00014DB4    00F08AB9             b.w code_0x150CC
                            */
                            /*
                            .text:0x000150CC code_0x150CC:
                            .text:0x000150CC    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x000150D0    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x000150D4    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x000150D8    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x000150DC    F26D                 ldr r2, [r6, #0x5C]
                            .text:0x000150DE    C068                 ldr r0, [r0, #0xC]
                            .text:0x000150E0    9042                 cmp r0, r2
                            .text:0x000150E2    31D3                 blo code_0x15148
                            */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0x5C );
r0 = *( r0 + 0xC );
                            if (r0 >= r2) {
                              /*
                              .text:0x000150E4 code_0x150E4:
                              .text:0x000150E4    9DF80000             ldrb.w r0, [local_0x28]
                              .text:0x000150E8    00EB4002             add.w r2, r0, r0, lsl #0x1
                              .text:0x000150EC    02EBC000             add.w r0, r2, r0, lsl #0x3
                              .text:0x000150F0    01EB8000             add.w r0, r1, r0, lsl #0x2
                              .text:0x000150F4    C560                 str r5, [r0, #0xC]
                              .text:0x000150F6    9DF80000             ldrb.w r0, [local_0x28]
                              .text:0x000150FA    00EB4002             add.w r2, r0, r0, lsl #0x1
                              .text:0x000150FE    02EBC000             add.w r0, r2, r0, lsl #0x3
                              .text:0x00015102    01EB8000             add.w r0, r1, r0, lsl #0x2
                              .text:0x00015106    80F808A0             strb.w sl, [r0, #0x8]
                              .text:0x0001510A    9DF80000             ldrb.w r0, [local_0x28]
                              .text:0x0001510E    00EB4002             add.w r2, r0, r0, lsl #0x1
                              .text:0x00015112    02EBC000             add.w r0, r2, r0, lsl #0x3
                              .text:0x00015116    01EB8000             add.w r0, r1, r0, lsl #0x2
                              .text:0x0001511A    13E0                 b code_0x15144
                              */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0xC ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x8 ) = sl;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
                              /*
                              .text:0x00015144 code_0x15144:
                              .text:0x00015144    4572                 strb r5, [r0, #0x9]
                              .text:0x00015146    20E0                 b code_0x1518A
                              */
*( r0 + 0x9 ) = r5;
                            } else {
                              /*
                              .text:0x00015148 code_0x15148:
                              .text:0x00015148    9DF80000             ldrb.w r0, [local_0x28]
                              .text:0x0001514C    06EB8000             add.w r0, r6, r0, lsl #0x2
                              .text:0x00015150    90ED190A             vldr s0, [r0, #0x64]
                              .text:0x00015154    9DF80000             ldrb.w r0, [local_0x28]
                              .text:0x00015158    96ED181A             vldr s2, [r6, #0x60]
                              .text:0x0001515C    04EB8000             add.w r0, r4, r0, lsl #0x2
                              .text:0x00015160    D0ED000A             vldr s1, [r0]
                              .text:0x00015164    9DF80000             ldrb.w r0, [local_0x28]
                              .text:0x00015168    00EE810A             vmla.f32 s0, s1, s2
                              .text:0x0001516C    04EB8000             add.w r0, r4, r0, lsl #0x2
                              .text:0x00015170    80ED000A             vstr s0, [r0]
                              .text:0x00015174    9DF80000             ldrb.w r0, [local_0x28]
                              .text:0x00015178    00EB4002             add.w r2, r0, r0, lsl #0x1
                              .text:0x0001517C    02EBC000             add.w r0, r2, r0, lsl #0x3
                              .text:0x00015180    01EB8000             add.w r0, r1, r0, lsl #0x2
                              .text:0x00015184    C268                 ldr r2, [r0, #0xC]
                              .text:0x00015186    521C                 adds r2, r2, #0x1
                              .text:0x00015188    C260                 str r2, [r0, #0xC]
                              */
r0 = *( local_0x28 );
r0 = r6 + (r0 << 0x2);
s0 = *( r0 + 0x64 );
r0 = *( local_0x28 );
s2 = *( r6 + 0x60 );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 );
r0 = *( local_0x28 );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0xC );
r2 = r2 + 0x1;
*( r0 + 0xC ) = r2;
                            }
                          }
                        } else {
                            /*
                            .text:0x0001507C code_0x1507C:
                            .text:0x0001507C    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015080    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015084    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015088    11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                            .text:0x0001508C    0128                 cmp r0, #0x1
                            .text:0x0001508E    7CD0                 beq code_0x1518A
                            */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );

                        }
                    } else {
                        /*
                        .text:0x00014EA2 code_0x14EA2:
                        .text:0x00014EA2    54E0                 b code_0x14F4E
                        .text:0x00014F4E code_0x14F4E:
                        .text:0x00014F4E    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00014F52    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00014F56    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00014F5A    11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                        .text:0x00014F5E    48B9                 cbnz r0, code_0x14F74
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                        cond1 = r0 == 0;
                        
                        /*
                        .text:0x00014F60 code_0x14F60:
                        .text:0x00014F60    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00014F64    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00014F68    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00014F6C    01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00014F70    0079                 ldrb r0, [r0, #0x4]
                        .text:0x00014F72    A8B3                 cbz r0, code_0x14FE0
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x4 );

                        cond2 = r0 == 0;
                        if (cond1 && cond2) {
                            /*
                            .text:0x00014FE0 code_0x14FE0:
                            .text:0x00014FE0    FFE7                 b code_0x14FE2
                            .text:0x00014FE2 code_0x14FE2:
                            .text:0x00014FE2    B6F88800             ldrh.w r0, [r6, #0x88]
                            .text:0x00014FE6    00EE100A             vmov s0, r0
                            .text:0x00014FEA    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014FEE    B8EE400A             vcvt.f32.u32 s0, s0
                            .text:0x00014FF2    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00014FF6    D0ED000A             vldr s1, [r0]
                            .text:0x00014FFA    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014FFE    00EEC90A             vmls.f32 s0, s1, s18
                            .text:0x00015002    D6ED180A             vldr s1, [r6, #0x60]
                            .text:0x00015006    70EEE80A             vsub.f32 s1, s1, s17
                            .text:0x0001500A    60EE200A             vmul.f32 s1, s0, s1
                            .text:0x0001500E    80EE880A             vdiv.f32 s0, s1, s16
                            .text:0x00015012    06EB8000             add.w r0, r6, r0, lsl #0x2
                            .text:0x00015016    80ED190A             vstr s0, [r0, #0x64]
                            .text:0x0001501A    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x0001501E    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015022    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015026    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x0001502A    C560                 str r5, [r0, #0xC]
                            .text:0x0001502C    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015030    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015034    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015038    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x0001503C    0772                 strb r7, [r0, #0x8]
                            .text:0x0001503E    A4E0                 b code_0x1518A
                            */
r0 = *( r6 + 0x88 );
s0 = r0;
r0 = *( local_0x28 );
s0 = (float) s0;
r0 = r4 + (r0 << 0x2);
s1 = *( r0 );
r0 = *( local_0x28 );
s0 =  (s0 - s1 * s18 );
s1 = *( r6 + 0x60 );
s1 = s1 - s17;
s1 = s0 * s1;
s0 = s1 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0x64 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0xC ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x8 ) = r7;
                        } else {
                            /*
                            .text:0x00014F74 code_0x14F74:
                            .text:0x00014F74    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014F78    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00014F7C    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00014F80    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00014F84    326D                 ldr r2, [r6, #0x50]
                            .text:0x00014F86    C068                 ldr r0, [r0, #0xC]
                            .text:0x00014F88    9042                 cmp r0, r2
                            .text:0x00014F8A    59D3                 blo code_0x15040
                            */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0x50 );
r0 = *( r0 + 0xC );
                            if (r0 >= r2) {
                                /*
                                .text:0x00014F8C code_0x14F8C:
                                .text:0x00014F8C    B6F88800             ldrh.w r0, [r6, #0x88]
                                .text:0x00014F90    D6ED180A             vldr s1, [r6, #0x60]
                                .text:0x00014F94    00EE100A             vmov s0, r0
                                .text:0x00014F98    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014F9C    70EEE80A             vsub.f32 s1, s1, s17
                                .text:0x00014FA0    B8EE400A             vcvt.f32.u32 s0, s0
                                .text:0x00014FA4    30EE690A             vsub.f32 s0, s0, s19
                                .text:0x00014FA8    20EE200A             vmul.f32 s0, s0, s1
                                .text:0x00014FAC    C0EE080A             vdiv.f32 s1, s0, s16
                                .text:0x00014FB0    06EB8000             add.w r0, r6, r0, lsl #0x2
                                .text:0x00014FB4    C0ED190A             vstr s1, [r0, #0x64]
                                .text:0x00014FB8    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014FBC    00EB4002             add.w r2, r0, r0, lsl #0x1
                                .text:0x00014FC0    02EBC000             add.w r0, r2, r0, lsl #0x3
                                .text:0x00014FC4    01EB8000             add.w r0, r1, r0, lsl #0x2
                                .text:0x00014FC8    C560                 str r5, [r0, #0xC]
                                .text:0x00014FCA    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014FCE    00EB4002             add.w r2, r0, r0, lsl #0x1
                                .text:0x00014FD2    02EBC000             add.w r0, r2, r0, lsl #0x3
                                .text:0x00014FD6    01EB8000             add.w r0, r1, r0, lsl #0x2
                                .text:0x00014FDA    80F80890             strb.w sb, [r0, #0x8]
                                .text:0x00014FDE    D4E0                 b code_0x1518A
                                */
r0 = *( r6 + 0x88 );
s1 = *( r6 + 0x60 );
s0 = r0;
r0 = *( local_0x28 );
s1 = s1 - s17;
s0 = (float) s0;
s0 = s0 - s19;
s0 = s0 * s1;
s1 = s0 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0x64 ) = s1;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0xC ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x8 ) = sb;

                            } else {
                                /*
                                .text:0x00015040 code_0x15040:
                                .text:0x00015040    96ED160A             vldr s0, [r6, #0x58]
                                .text:0x00015044    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00015048    96ED151A             vldr s2, [r6, #0x54]
                                .text:0x0001504C    04EB8000             add.w r0, r4, r0, lsl #0x2
                                .text:0x00015050    D0ED000A             vldr s1, [r0]
                                .text:0x00015054    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00015058    00EE810A             vmla.f32 s0, s1, s2
                                .text:0x0001505C    04EB8000             add.w r0, r4, r0, lsl #0x2
                                .text:0x00015060    80ED000A             vstr s0, [r0]
                                .text:0x00015064    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00015068    00EB4002             add.w r2, r0, r0, lsl #0x1
                                .text:0x0001506C    02EBC000             add.w r0, r2, r0, lsl #0x3
                                .text:0x00015070    01EB8000             add.w r0, r1, r0, lsl #0x2
                                .text:0x00015074    C268                 ldr r2, [r0, #0xC]
                                .text:0x00015076    521C                 adds r2, r2, #0x1
                                .text:0x00015078    C260                 str r2, [r0, #0xC]
                                .text:0x0001507A    86E0                 b code_0x1518A
                                */
s0 = *( r6 + 0x58 );
r0 = *( local_0x28 );
s2 = *( r6 + 0x54 );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 );
r0 = *( local_0x28 );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0xC );
r2 = r2 + 0x1;
*( r0 + 0xC ) = r2;

                            }

                        }
                    }
                } else {
                    /*
                    .text:0x00014DB8 code_0x14DB8:
                    .text:0x00014DB8    9DF80000             ldrb.w r0, [local_0x28]
                    .text:0x00014DBC    00EB4002             add.w r2, r0, r0, lsl #0x1
                    .text:0x00014DC0    02EBC000             add.w r0, r2, r0, lsl #0x3
                    .text:0x00014DC4    11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                    .text:0x00014DC8    48B9                 cbnz r0, code_0x14DDE
                    */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                    cond1 = r0 == 0;
                
                    /*
                    .text:0x00014DCA code_0x14DCA:
                    .text:0x00014DCA    9DF80000             ldrb.w r0, [local_0x28]
                    .text:0x00014DCE    00EB4002             add.w r2, r0, r0, lsl #0x1
                    .text:0x00014DD2    02EBC000             add.w r0, r2, r0, lsl #0x3
                    .text:0x00014DD6    01EB8000             add.w r0, r1, r0, lsl #0x2
                    .text:0x00014DDA    0079                 ldrb r0, [r0, #0x4]
                    .text:0x00014DDC    E8B3                 cbz r0, code_0x14E5A
                    */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x4 );
                    cond2 = r0 == 0;
                    if (cond1 && cond2) {
                            /*
                            .text:0x00014E5A code_0x14E5A:
                            .text:0x00014E5A    FFE7                 b code_0x14E5C
                            .text:0x00014E5C code_0x14E5C:
                            .text:0x00014E5C    B6F88800             ldrh.w r0, [r6, #0x88]
                            .text:0x00014E60    00EE100A             vmov s0, r0
                            .text:0x00014E64    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014E68    B8EE400A             vcvt.f32.u32 s0, s0
                            .text:0x00014E6C    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00014E70    D0ED000A             vldr s1, [r0]
                            .text:0x00014E74    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014E78    00EEC90A             vmls.f32 s0, s1, s18
                            .text:0x00014E7C    D6ED180A             vldr s1, [r6, #0x60]
                            .text:0x00014E80    70EEE80A             vsub.f32 s1, s1, s17
                            .text:0x00014E84    60EE200A             vmul.f32 s1, s0, s1
                            .text:0x00014E88    80EE880A             vdiv.f32 s0, s1, s16
                            .text:0x00014E8C    06EB8000             add.w r0, r6, r0, lsl #0x2
                            .text:0x00014E90    80ED190A             vstr s0, [r0, #0x64]
                            .text:0x00014E94    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014E98    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00014E9C    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00014EA0    00E0                 b code_0x14EA4
                            .text:0x00014EA4 code_0x14EA4:
                            .text:0x00014EA4    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00014EA8    C560                 str r5, [r0, #0xC]
                            .text:0x00014EAA    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014EAE    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00014EB2    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00014EB6    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00014EBA    0772                 strb r7, [r0, #0x8]
                            .text:0x00014EBC    00F065B9             b.w code_0x1518A
                            */                        
r0 = *( r6 + 0x88 );
s0 = r0;
r0 = *( local_0x28 );
s0 = (float) s0;
r0 = r4 + (r0 << 0x2);
s1 = *( r0 );
r0 = *( local_0x28 );
s0 =  (s0 - s1 * s18 );
s1 = *( r6 + 0x60 );
s1 = s1 - s17;
s1 = s0 * s1;
s0 = s1 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0x64 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0xC ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x8 ) = r7;
                    } else {
                        /*
                        .text:0x00014DDE code_0x14DDE:
                        .text:0x00014DDE    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00014DE2    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00014DE6    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00014DEA    01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00014DEE    C068                 ldr r0, [r0, #0xC]
                        .text:0x00014DF0    0028                 cmp r0, #0x0
                        .text:0x00014DF2    65D0                 beq code_0x14EC0
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0xC );


                        if (r0 != 0) {
                        /*
                            .text:0x00014DF4 code_0x14DF4:
                            .text:0x00014DF4    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014DF8    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00014DFC    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00014E00    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00014E04    726C                 ldr r2, [r6, #0x44]
                            .text:0x00014E06    C068                 ldr r0, [r0, #0xC]
                            .text:0x00014E08    9042                 cmp r0, r2
                            .text:0x00014E0A    05D2                 bhs code_0x14E18
                            */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0x44 );
r0 = *( r0 + 0xC );

                            if (r0 < r2) {
                                /*
                                .text:0x00014E0C code_0x14E0C:
                                .text:0x00014E0C    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014E10    54F82000             ldr.w r0, [r4, r0, lsl #0x2]
                                .text:0x00014E14    4045                 cmp r0, r8
                                .text:0x00014E16    7CDB                 blt code_0x14F12
                                */
r0 = *( local_0x28 );
r0 = *( r4 + r0 << 0x2 );
                                if (r0 >= r8) {
                                    /*
                                    .text:0x00014E18 code_0x14E18:
                                    .text:0x00014E18    B6F88A00             ldrh.w r0, [r6, #0x8A]
                                    .text:0x00014E1C    00EE100A             vmov s0, r0
                                    .text:0x00014E20    9DF80000             ldrb.w r0, [local_0x28]
                                    .text:0x00014E24    B8EE400A             vcvt.f32.u32 s0, s0
                                    .text:0x00014E28    04EB8000             add.w r0, r4, r0, lsl #0x2
                                    .text:0x00014E2C    80ED000A             vstr s0, [r0]
                                    .text:0x00014E30    9DF80000             ldrb.w r0, [local_0x28]
                                    .text:0x00014E34    00EB4002             add.w r2, r0, r0, lsl #0x1
                                    .text:0x00014E38    02EBC000             add.w r0, r2, r0, lsl #0x3
                                    .text:0x00014E3C    01EB8000             add.w r0, r1, r0, lsl #0x2
                                    .text:0x00014E40    C560                 str r5, [r0, #0xC]
                                    .text:0x00014E42    9DF80000             ldrb.w r0, [local_0x28]
                                    .text:0x00014E46    00EB4002             add.w r2, r0, r0, lsl #0x1
                                    .text:0x00014E4A    02EBC000             add.w r0, r2, r0, lsl #0x3
                                    .text:0x00014E4E    01EB8000             add.w r0, r1, r0, lsl #0x2
                                    .text:0x00014E52    80F808B0             strb.w fp, [r0, #0x8]
                                    .text:0x00014E56    00F098B9             b.w code_0x1518A
                                    */
r0 = *( r6 + 0x8A );
s0 = r0;
r0 = *( local_0x28 );
s0 = (float) s0;
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0xC ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x8 ) = fp;

                                } else {
                                    /*
                                    .text:0x00014F12 code_0x14F12:
                                    .text:0x00014F12    96ED130A             vldr s0, [r6, #0x4C]
                                    .text:0x00014F16    9DF80000             ldrb.w r0, [local_0x28]
                                    .text:0x00014F1A    96ED121A             vldr s2, [r6, #0x48]
                                    .text:0x00014F1E    04EB8000             add.w r0, r4, r0, lsl #0x2
                                    .text:0x00014F22    D0ED000A             vldr s1, [r0]
                                    .text:0x00014F26    9DF80000             ldrb.w r0, [local_0x28]
                                    .text:0x00014F2A    00EE810A             vmla.f32 s0, s1, s2
                                    .text:0x00014F2E    04EB8000             add.w r0, r4, r0, lsl #0x2
                                    .text:0x00014F32    80ED000A             vstr s0, [r0]
                                    .text:0x00014F36    9DF80000             ldrb.w r0, [local_0x28]
                                    .text:0x00014F3A    00EB4002             add.w r2, r0, r0, lsl #0x1
                                    .text:0x00014F3E    02EBC000             add.w r0, r2, r0, lsl #0x3
                                    .text:0x00014F42    01EB8000             add.w r0, r1, r0, lsl #0x2
                                    .text:0x00014F46    C268                 ldr r2, [r0, #0xC]
                                    .text:0x00014F48    521C                 adds r2, r2, #0x1
                                    .text:0x00014F4A    C260                 str r2, [r0, #0xC]
                                    .text:0x00014F4C    1DE1                 b code_0x1518A
                                    */
s0 = *( r6 + 0x4C );
r0 = *( local_0x28 );
s2 = *( r6 + 0x48 );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 );
r0 = *( local_0x28 );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0xC );
r2 = r2 + 0x1;
*( r0 + 0xC ) = r2;

                                }
                                
                            } else {
                                /*
                                .text:0x00014E18 code_0x14E18:
                                .text:0x00014E18    B6F88A00             ldrh.w r0, [r6, #0x8A]
                                .text:0x00014E1C    00EE100A             vmov s0, r0
                                .text:0x00014E20    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014E24    B8EE400A             vcvt.f32.u32 s0, s0
                                .text:0x00014E28    04EB8000             add.w r0, r4, r0, lsl #0x2
                                .text:0x00014E2C    80ED000A             vstr s0, [r0]
                                .text:0x00014E30    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014E34    00EB4002             add.w r2, r0, r0, lsl #0x1
                                .text:0x00014E38    02EBC000             add.w r0, r2, r0, lsl #0x3
                                .text:0x00014E3C    01EB8000             add.w r0, r1, r0, lsl #0x2
                                .text:0x00014E40    C560                 str r5, [r0, #0xC]
                                .text:0x00014E42    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014E46    00EB4002             add.w r2, r0, r0, lsl #0x1
                                .text:0x00014E4A    02EBC000             add.w r0, r2, r0, lsl #0x3
                                .text:0x00014E4E    01EB8000             add.w r0, r1, r0, lsl #0x2
                                .text:0x00014E52    80F808B0             strb.w fp, [r0, #0x8]
                                .text:0x00014E56    00F098B9             b.w code_0x1518A
                                */
r0 = *( r6 + 0x8A );
s0 = r0;
r0 = *( local_0x28 );
s0 = (float) s0;
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0xC ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x8 ) = fp;

                            }
                        
                        } else {
                            /*
                            .text:0x00014EC0 code_0x14EC0:
                            .text:0x00014EC0    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00014EC4    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00014EC8    D0ED000A             vldr s1, [r0]
                            .text:0x00014ECC    B6F88800             ldrh.w r0, [r6, #0x88]
                            .text:0x00014ED0    00EE100A             vmov s0, r0
                            .text:0x00014ED4    B8EE400A             vcvt.f32.u32 s0, s0
                            .text:0x00014ED8    F4EEC00A             vcmpe.f32 s1, s0
                            .text:0x00014EDC    F1EE10FA             vmrs APSR_nzcv, fpscr
                            .text:0x00014EE0    09D8                 bhi code_0x14EF6
                            */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 );
r0 = *( r6 + 0x88 );
s0 = r0;
s0 = (float) s0;
                            if (s1 <= s0) {
                                /*
                                .text:0x00014EE2 code_0x14EE2:
                                .text:0x00014EE2    00EE100A             vmov s0, r0
                                .text:0x00014EE6    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014EEA    B8EE400A             vcvt.f32.u32 s0, s0
                                .text:0x00014EEE    04EB8000             add.w r0, r4, r0, lsl #0x2
                                .text:0x00014EF2    80ED000A             vstr s0, [r0]
                                .text:0x00014EF6 code_0x14EF6:
                                .text:0x00014EF6    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014EFA    00EB4002             add.w r2, r0, r0, lsl #0x1
                                .text:0x00014EFE    02EBC000             add.w r0, r2, r0, lsl #0x3
                                .text:0x00014F02    01EB8000             add.w r0, r1, r0, lsl #0x2
                                .text:0x00014F06    C268                 ldr r2, [r0, #0xC]
                                .text:0x00014F08    521C                 adds r2, r2, #0x1
                                .text:0x00014F0A    C260                 str r2, [r0, #0xC]
                                .text:0x00014F0C    00F03DB9             b.w code_0x1518A
                                */
s0 = r0;
r0 = *( local_0x28 );
s0 = (float) s0;
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0xC );
r2 = r2 + 0x1;
*( r0 + 0xC ) = r2;

                            } else {
                                /*
                                .text:0x00014EF6 code_0x14EF6:
                                .text:0x00014EF6    9DF80000             ldrb.w r0, [local_0x28]
                                .text:0x00014EFA    00EB4002             add.w r2, r0, r0, lsl #0x1
                                .text:0x00014EFE    02EBC000             add.w r0, r2, r0, lsl #0x3
                                .text:0x00014F02    01EB8000             add.w r0, r1, r0, lsl #0x2
                                .text:0x00014F06    C268                 ldr r2, [r0, #0xC]
                                .text:0x00014F08    521C                 adds r2, r2, #0x1
                                .text:0x00014F0A    C260                 str r2, [r0, #0xC]
                                .text:0x00014F0C    00F03DB9             b.w code_0x1518A
                                */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0xC );
r2 = r2 + 0x1;
*( r0 + 0xC ) = r2;
                            
                            }
                        }
                    }
                }
            }

            /*
            .text:0x0001518A code_0x1518A:
            .text:0x0001518A    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x0001518E    00EB4002             add.w r2, r0, r0, lsl #0x1
            .text:0x00015192    02EBC000             add.w r0, r2, r0, lsl #0x3
            .text:0x00015196    01EB8000             add.w r0, r1, r0, lsl #0x2
            .text:0x0001519A    407E                 ldrb r0, [r0, #0x19]
            .text:0x0001519C    0128                 cmp r0, #0x1
            .text:0x0001519E    40F0EC81             bne.w code_0x1557A
            */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x19 );
        
            if (r0 == 1) {
                /*
                .text:0x000151A2 code_0x151A2:
                .text:0x000151A2    9DF80000             ldrb.w r0, [local_0x28]
                .text:0x000151A6    00EB4002             add.w r2, r0, r0, lsl #0x1
                .text:0x000151AA    02EBC000             add.w r0, r2, r0, lsl #0x3
                .text:0x000151AE    01EB8000             add.w r0, r1, r0, lsl #0x2
                .text:0x000151B2    007E                 ldrb r0, [r0, #0x18]
                .text:0x000151B4    48B1                 cbz r0, code_0x151CA
                */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x18 );
                switch (r0) {
                    case 0:
                        break;

                    /*
                    .text:0x000151B6 code_0x151B6:
                    .text:0x000151B6    0128                 cmp r0, #0x1
                    .text:0x000151B8    7DD0                 beq code_0x152B6
                    */
                    case 1:
                        /*
                        .text:0x000152B6 code_0x152B6:
                        .text:0x000152B6    55E0                 b code_0x15364
                        */
                        /*
                        .text:0x00015364 code_0x15364:
                        .text:0x00015364    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00015368    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x0001536C    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015370    11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                        .text:0x00015374    48B9                 cbnz r0, code_0x1538A
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                        cond1 = r0 == 0;
                        /*
                        .text:0x00015376 code_0x15376:
                        .text:0x00015376    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x0001537A    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x0001537E    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015382    01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015386    0079                 ldrb r0, [r0, #0x4]
                        .text:0x00015388    B0B3                 cbz r0, code_0x153F8
                        .text:0x000153F8 code_0x153F8:
                        .text:0x000153F8    FFE7                 b code_0x153FA
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x4 );
                        cond2 = r0 == 0;

                        if (cond1 && cond2) {
                            /*
                            .text:0x000153FA code_0x153FA:
                            .text:0x000153FA    B6F81801             ldrh.w r0, [r6, #0x118]
                            .text:0x000153FE    00EE100A             vmov s0, r0
                            .text:0x00015402    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015406    B8EE400A             vcvt.f32.u32 s0, s0
                            .text:0x0001540A    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x0001540E    D0ED080A             vldr s1, [r0, #0x20]
                            .text:0x00015412    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015416    00EEC90A             vmls.f32 s0, s1, s18
                            .text:0x0001541A    D6ED3C0A             vldr s1, [r6, #0xF0]
                            .text:0x0001541E    70EEE80A             vsub.f32 s1, s1, s17
                            .text:0x00015422    20EE200A             vmul.f32 s0, s0, s1
                            .text:0x00015426    C0EE080A             vdiv.f32 s1, s0, s16
                            .text:0x0001542A    06EB8000             add.w r0, r6, r0, lsl #0x2
                            .text:0x0001542E    C0ED3D0A             vstr s1, [r0, #0xF4]
                            .text:0x00015432    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015436    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x0001543A    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x0001543E    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015442    C561                 str r5, [r0, #0x1C]
                            .text:0x00015444    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015448    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x0001544C    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015450    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015454    0776                 strb r7, [r0, #0x18]
                            .text:0x00015456    90E0                 b code_0x1557A
                            */
r0 = *( r6 + 0x118 );
s0 = r0;
r0 = *( local_0x28 );
s0 = (float) s0;
r0 = r4 + (r0 << 0x2);
s1 = *( r0 + 0x20 );
r0 = *( local_0x28 );
s0 =  (s0 - s1 * s18 );
s1 = *( r6 + 0xF0 );
s1 = s1 - s17;
s0 = s0 * s1;
s1 = s0 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0xF4 ) = s1;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x1C ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x18 ) = r7;
                        } else {
                          /*
                          .text:0x0001538A code_0x1538A:
                          .text:0x0001538A    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x0001538E    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015392    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015396    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x0001539A    D6F8E020             ldr.w r2, [r6, #0xE0]
                          .text:0x0001539E    C069                 ldr r0, [r0, #0x1C]
                          .text:0x000153A0    9042                 cmp r0, r2
                          .text:0x000153A2    59D3                 blo code_0x15458
                          */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0xE0 );
r0 = *( r0 + 0x1C );
                          if (r0 >= r2) {
                            /*
                            .text:0x000153A4 code_0x153A4:
                            .text:0x000153A4    B6F81801             ldrh.w r0, [r6, #0x118]
                            .text:0x000153A8    D6ED3C0A             vldr s1, [r6, #0xF0]
                            .text:0x000153AC    00EE100A             vmov s0, r0
                            .text:0x000153B0    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x000153B4    70EEE80A             vsub.f32 s1, s1, s17
                            .text:0x000153B8    B8EE400A             vcvt.f32.u32 s0, s0
                            .text:0x000153BC    30EE690A             vsub.f32 s0, s0, s19
                            .text:0x000153C0    20EE200A             vmul.f32 s0, s0, s1
                            .text:0x000153C4    C0EE080A             vdiv.f32 s1, s0, s16
                            .text:0x000153C8    06EB8000             add.w r0, r6, r0, lsl #0x2
                            .text:0x000153CC    C0ED3D0A             vstr s1, [r0, #0xF4]
                            .text:0x000153D0    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x000153D4    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x000153D8    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x000153DC    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x000153E0    C561                 str r5, [r0, #0x1C]
                            .text:0x000153E2    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x000153E6    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x000153EA    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x000153EE    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x000153F2    80F81890             strb.w sb, [r0, #0x18]
                            .text:0x000153F6    C0E0                 b code_0x1557A
                            */
r0 = *( r6 + 0x118 );
s1 = *( r6 + 0xF0 );
s0 = r0;
r0 = *( local_0x28 );
s1 = s1 - s17;
s0 = (float) s0;
s0 = s0 - s19;
s0 = s0 * s1;
s1 = s0 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0xF4 ) = s1;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x1C ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x18 ) = sb;
                          }
                          /*
                          .text:0x00015458 code_0x15458:
                          .text:0x00015458    96ED3A0A             vldr s0, [r6, #0xE8]
                          .text:0x0001545C    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015460    96ED391A             vldr s2, [r6, #0xE4]
                          .text:0x00015464    04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x00015468    D0ED080A             vldr s1, [r0, #0x20]
                          .text:0x0001546C    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015470    00EE810A             vmla.f32 s0, s1, s2
                          .text:0x00015474    04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x00015478    80ED080A             vstr s0, [r0, #0x20]
                          .text:0x0001547C    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015480    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015484    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015488    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x0001548C    C169                 ldr r1, [r0, #0x1C]
                          .text:0x0001548E    491C                 adds r1, r1, #0x1
                          .text:0x00015490    C161                 str r1, [r0, #0x1C]
                          .text:0x00015492    72E0                 b code_0x1557A
                          */
s0 = *( r6 + 0xE8 );
r0 = *( local_0x28 );
s2 = *( r6 + 0xE4 );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 + 0x20 );
r0 = *( local_0x28 );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r1 = *( r0 + 0x1C );
r1 = r1 + 0x1;
*( r0 + 0x1C ) = r1;
                        }
                        break;


                    /*
                    .text:0x000151BA code_0x151BA:
                    .text:0x000151BA    0228                 cmp r0, #0x2
                    .text:0x000151BC    00F06A81             beq.w code_0x15494
                    */
                    case 2:
                        /*
                        .text:0x00015494 code_0x15494:
                        .text:0x00015494    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00015498    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x0001549C    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x000154A0    11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                        .text:0x000154A4    0128                 cmp r0, #0x1
                        .text:0x000154A6    68D0                 beq code_0x1557A
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                        break;
                    /*
                    .text:0x000151C0 code_0x151C0:
                    .text:0x000151C0    0328                 cmp r0, #0x3
                    .text:0x000151C2    40F0DA81             bne.w code_0x1557A
                    */
                    case 3:
                        break;

                    default:

                        /*
                        .text:0x000151C6 code_0x151C6:
                        .text:0x000151C6    00F08DB9             b.w code_0x154E4
                        .text:0x000154E4 code_0x154E4:
                        .text:0x000154E4    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x000154E8    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x000154EC    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x000154F0    01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x000154F4    D6F8EC20             ldr.w r2, [r6, #0xEC]
                        .text:0x000154F8    C069                 ldr r0, [r0, #0x1C]
                        .text:0x000154FA    9042                 cmp r0, r2
                        .text:0x000154FC    1CD3                 blo code_0x15538
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0xEC );
r0 = *( r0 + 0x1C );
                        if (r0 >= r2) {
                            /*
                            .text:0x000154FE code_0x154FE:
                            .text:0x000154FE    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015502    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015506    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x0001550A    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x0001550E    C561                 str r5, [r0, #0x1C]
                            .text:0x00015510    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015514    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015518    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x0001551C    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015520    80F818A0             strb.w sl, [r0, #0x18]
                            .text:0x00015524    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015528    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x0001552C    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015530    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015534    4576                 strb r5, [r0, #0x19]
                            .text:0x00015536    20E0                 b code_0x1557A
                            */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x1C ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x18 ) = sl;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x19 ) = r5;
                        } else {
                            /*
                            .text:0x00015538 code_0x15538:
                            .text:0x00015538    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x0001553C    06EB8000             add.w r0, r6, r0, lsl #0x2
                            .text:0x00015540    90ED3D0A             vldr s0, [r0, #0xF4]
                            .text:0x00015544    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015548    96ED3C1A             vldr s2, [r6, #0xF0]
                            .text:0x0001554C    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00015550    D0ED080A             vldr s1, [r0, #0x20]
                            .text:0x00015554    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015558    00EE810A             vmla.f32 s0, s1, s2
                            .text:0x0001555C    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00015560    80ED080A             vstr s0, [r0, #0x20]
                            .text:0x00015564    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015568    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x0001556C    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015570    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015574    C169                 ldr r1, [r0, #0x1C]
                            .text:0x00015576    491C                 adds r1, r1, #0x1
                            .text:0x00015578    C161                 str r1, [r0, #0x1C]
                            */
r0 = *( local_0x28 );
r0 = r6 + (r0 << 0x2);
s0 = *( r0 + 0xF4 );
r0 = *( local_0x28 );
s2 = *( r6 + 0xF0 );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 + 0x20 );
r0 = *( local_0x28 );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r1 = *( r0 + 0x1C );
r1 = r1 + 0x1;
*( r0 + 0x1C ) = r1;
                        }
                }           
            }
            /*
            .text:0x0001557A code_0x1557A:
            .text:0x0001557A    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x0001557E    FE49                 ldr r1, [_0x457FF000_1]
            .text:0x00015580    54F82000             ldr.w r0, [r4, r0, lsl #0x2]
            .text:0x00015584    8842                 cmp r0, r1
            .text:0x00015586    05DD                 ble code_0x15594
            */
r0 = *( local_0x28 );
r1 = *( _0x457FF000_1 );
r0 = *( r4 + r0 << 0x2 );

            if (r0 > r1) {
                /*
                .text:0x00015588 code_0x15588:
                .text:0x00015588    9DF80000             ldrb.w r0, [local_0x28]
                .text:0x0001558C    04EB8000             add.w r0, r4, r0, lsl #0x2
                .text:0x00015590 code_0x15590:
                .text:0x00015590    C0ED00AA             vstr s21, [r0]
                */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
*( r0 ) = s21;

            }
            /*
            .text:0x00015594 code_0x15594:
            .text:0x00015594    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x00015598    04EB8000             add.w r0, r4, r0, lsl #0x2
            .text:0x0001559C    006A                 ldr r0, [r0, #0x20]
            .text:0x0001559E    8842                 cmp r0, r1
            .text:0x000155A0    05DD                 ble code_0x155AE
            */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
r0 = *( r0 + 0x20 );
            if (r0 > r1) {
                /*
                .text:0x000155A2 code_0x155A2:
                .text:0x000155A2    9DF80000             ldrb.w r0, [local_0x28]
                .text:0x000155A6    04EB8000             add.w r0, r4, r0, lsl #0x2
                .text:0x000155AA    C0ED08AA             vstr s21, [r0, #0x20]
                */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s21;
            }
            /*
            .text:0x000155AE code_0x155AE:
            .text:0x000155AE    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x000155B2    04EB8000             add.w r0, r4, r0, lsl #0x2
            .text:0x000155B6    90ED000A             vldr s0, [r0]
            .text:0x000155BA    B5EEC00A             vcmpe.f32 s0, #0x0
            .text:0x000155BE    F1EE10FA             vmrs APSR_nzcv, fpscr
            .text:0x000155C2    05D2                 bhs code_0x155D0
            */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 );
            if (s0 < 0.0) {
                /*
                .text:0x000155C4 code_0x155C4:
                .text:0x000155C4    9DF80000             ldrb.w r0, [local_0x28]
                .text:0x000155C8    04EB8000             add.w r0, r4, r0, lsl #0x2
                .text:0x000155CC    80ED00AA             vstr s20, [r0]
                */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
*( r0 ) = s20;

            }
            /*
            .text:0x000155D0 code_0x155D0:
            .text:0x000155D0    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x000155D4    04EB8000             add.w r0, r4, r0, lsl #0x2
            .text:0x000155D8    90ED080A             vldr s0, [r0, #0x20]
            .text:0x000155DC    B5EEC00A             vcmpe.f32 s0, #0x0
            .text:0x000155E0    F1EE10FA             vmrs APSR_nzcv, fpscr
            .text:0x000155E4    05D2                 bhs code_0x155F2
            */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 + 0x20 );
            if (s0 < 0.0) {
                /*
                .text:0x000155E6 code_0x155E6:
                .text:0x000155E6    9DF80000             ldrb.w r0, [local_0x28]
                .text:0x000155EA    04EB8000             add.w r0, r4, r0, lsl #0x2
                .text:0x000155EE    80ED08AA             vstr s20, [r0, #0x20]
                */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s20;
            }
            /*
            .text:0x000155F2 code_0x155F2:
            .text:0x000155F2    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x000155F6    04F059FB             bl func_0x19CAC; void __cdecl( int p1 )
            .text:0x000155FA    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x000155FE    401C                 adds r0, r0, #0x1
            .text:0x00015600    0090                 str r0, [local_0x28]
            .text:0x00015602    F6F7E9F9             bl two_or_four_or_with_20000F30; int __cdecl( void )
            .text:0x00015606    9DF80010             ldrb.w r1, [local_0x28]
            .text:0x0001560A    8842                 cmp r0, r1
            .text:0x0001560C    3FF6B3AB             bhi.w code_0x14D76
            */
r0 = *( local_0x28 );
func_0x19CAC(r0);
r0 = *( local_0x28 );
r0 = r0 + 0x1;
*( local_0x28 ) = r0;
r0 = two_or_four_or_with_20000F30(r0);
r1 = *( local_0x28 );
            if (r0 <= r1) {
                break;
            }
        }
    } 
    /*
    .text:0x00015610 code_0x15610:
    .text:0x00015610    DA4C                 ldr r4, [_0x40010000_3]
    .text:0x00015612    0121                 movs r1, #0x1
    .text:0x00015614    2046                 mov r0, r4
    .text:0x00015616    01F05DF8             bl func_0x166D4; int __cdecl( int p1, int p2 )
    .text:0x0001561A    0028                 cmp r0, #0x0
    .text:0x0001561C    00F0BF85             beq.w code_0x1619E
    */
r4 = *( _0x40010000_3 );
r1 = 0x1;
r0 = r4;
r0 = func_0x166D4(r0,r1);
    cond1 = r0 != 0;
    /*
    .text:0x00015620 code_0x15620:
    .text:0x00015620    0121                 movs r1, #0x1
    .text:0x00015622    2046                 mov r0, r4
    .text:0x00015624    00F06CFF             bl func_0x16500; inline void __cdecl( int p1, int p2 )
    .text:0x00015628    0095                 str r5, [local_0x28]
    .text:0x0001562A    F6F7D5F9             bl two_or_four_or_with_20000F30; int __cdecl( void )
    .text:0x0001562E    9DF80010             ldrb.w r1, [local_0x28]
    .text:0x00015632    8842                 cmp r0, r1
    .text:0x00015634    40F2B385             bls.w code_0x1619E
    */
r1 = 0x1;
r0 = r4;
func_0x16500(r0,r1,r2);
*( local_0x28 ) = r5;
r0 = two_or_four_or_with_20000F30(r0);
r1 = *( local_0x28 );
    cond2 = r0 > r1;
    if (cond1 && cond2) {
        /*
        .text:0x00015638 code_0x15638:
        .text:0x00015638    9FEDD19A             vldr s18, [_0xBC4A458F]
        .text:0x0001563C    D146                 mov sb, sl
        .text:0x0001563E    D14C                 ldr r4, [_0x20005088]
        .text:0x00015640    F3EE049A             vmov.f32 s19, #2.000000e+01
        .text:0x00015644    DA46                 mov sl, fp
        .text:0x00015646    4FF00608             mov.w r8, #0x6
        */
s18 = *( _0xBC4A458F );
sb = sl;
r4 = *( _0x20005088 );
s19 = 2.000000e+01;
sl = fp;
r8 = 0x6;
        while (1) {
          /*
          .text:0x0001564A code_0x1564A:
          .text:0x0001564A    9DF80000             ldrb.w r0, [local_0x28]
          .text:0x0001564E    00EB4001             add.w r1, r0, r0, lsl #0x1
          .text:0x00015652    01EBC000             add.w r0, r1, r0, lsl #0x3
          .text:0x00015656    CC49                 ldr r1, [_0x20001FD4_8]
          .text:0x00015658    01EB8000             add.w r0, r1, r0, lsl #0x2
          .text:0x0001565C    407C                 ldrb r0, [r0, #0x11]
          .text:0x0001565E    0128                 cmp r0, #0x1
          .text:0x00015660    40F04682             bne.w code_0x15AF0
          */
r0 = *( local_0x28 );
r1 = r0 + (r0 << 0x1);
r0 = r1 + (r0 << 0x3);
r1 = *( _0x20001FD4_8 );
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x11 );
          cond1 = r0 == 1;
          /*
          .text:0x00015664 code_0x15664:
          .text:0x00015664    9DF80000             ldrb.w r0, [local_0x28]
          .text:0x00015668    00EB4002             add.w r2, r0, r0, lsl #0x1
          .text:0x0001566C    02EBC000             add.w r0, r2, r0, lsl #0x3
          .text:0x00015670    01EB8000             add.w r0, r1, r0, lsl #0x2
          .text:0x00015674    007C                 ldrb r0, [r0, #0x10]
          .text:0x00015676 code_0x15676:
          .text:0x00015676    0728                 cmp r0, #0x7
          .text:0x00015678 code_0x15678:
          .text:0x00015678    80F03A82             bhs.w code_0x15AF0
          */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x10 );
          cond2 = r0 < 7;

          if (cond1 && cond2) {
                /*
                .text:0x0001567C code_0x1567C:
                .text:0x0001567C    DFE800F0             tbb [jump_table_6, r0]; 6 indirect references.
                .text:0x00015680        db [ 0x04, 0x88, 0xFD, 0xFC, 0xD0, 0xD0, 0xFB ]
                */
                switch(r0) { 
                    case 0:
                        /*
                        .text:0x00015688 code_0x15688:
                        .text:0x00015688    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x0001568C    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015690    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015694    11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                        .text:0x00015698    48B9                 cbnz r0, code_0x156AE
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                        cond1 = r0 == 0;
                        /*
                        .text:0x0001569A code_0x1569A:
                        .text:0x0001569A    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x0001569E    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x000156A2    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x000156A6    01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x000156AA    0079                 ldrb r0, [r0, #0x4]
                        .text:0x000156AC    38B3                 cbz r0, code_0x156FE
                        */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x4 );
                        cond2 = r0 != 0;
                        if (cond1 && cond2) {
                          /*
                          .text:0x000156AE code_0x156AE:
                          .text:0x000156AE    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x000156B2    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x000156B6    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x000156BA    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x000156BE    4269                 ldr r2, [r0, #0x14]
                          .text:0x000156C0    3068                 ldr r0, [r6]
                          .text:0x000156C2    8242                 cmp r2, r0
                          .text:0x000156C4    06D2                 bhs code_0x156D4
                          */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0x14 );
r0 = *( r6 );
                          if (r0 > r2) {
                            /*
                            .text:0x000156C6 code_0x156C6:
                            .text:0x000156C6    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x000156CA    B04A                 ldr r2, [_457FE000]
                            .text:0x000156CC    54F82000             ldr.w r0, [r4, r0, lsl #0x2]
                            .text:0x000156D0    9042                 cmp r0, r2
                            .text:0x000156D2    3EDB                 blt code_0x15752
                            */
r0 = *( local_0x28 );
r2 = *( _457FE000 );
r0 = *( r4 + r0 << 0x2 );
                          }
                          /*
                          .text:0x000156D4 code_0x156D4:
                          .text:0x000156D4    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x000156D8    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x000156DC    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x000156E0    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x000156E4    4561                 str r5, [r0, #0x14]
                          .text:0x000156E6    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x000156EA    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x000156EE    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x000156F2    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x000156F6    80F810A0             strb.w sl, [r0, #0x10]
                          .text:0x000156FA    00F0F9B9             b.w code_0x15AF0
                          */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x14 ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x10 ) = sl;
                        } else {
                          /*
                          .text:0x000156FE code_0x156FE:
                          .text:0x000156FE    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015702    D6ED070A             vldr s1, [r6, #0x1C]
                          .text:0x00015706    04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x0001570A    90ED000A             vldr s0, [r0]
                          .text:0x0001570E    70EEE80A             vsub.f32 s1, s1, s17
                          .text:0x00015712    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015716    20EE090A             vmul.f32 s0, s0, s18
                          .text:0x0001571A    20EE200A             vmul.f32 s0, s0, s1
                          .text:0x0001571E    C0EE080A             vdiv.f32 s1, s0, s16
                          .text:0x00015722    06EB8000             add.w r0, r6, r0, lsl #0x2
                          .text:0x00015726    C0ED080A             vstr s1, [r0, #0x20]
                          .text:0x0001572A    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x0001572E    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015732    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015736    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x0001573A    4561                 str r5, [r0, #0x14]
                          .text:0x0001573C    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015740    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015744    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015748    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x0001574C    0774                 strb r7, [r0, #0x10]
                          .text:0x0001574E    00F0CFB9             b.w code_0x15AF0
                          */
r0 = *( local_0x28 );
s1 = *( r6 + 0x1C );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 );
s1 = s1 - s17;
r0 = *( local_0x28 );
s0 = s0 * s18;
s0 = s0 * s1;
s1 = s0 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0x20 ) = s1;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x14 ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x10 ) = r7;
                        }
                        break;
                    case 1:
                        /*
                        .text:0x00015790    9DF80000             ldrb.w r0, [stack_0x0]
                        .text:0x00015794    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015798    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x0001579C    11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                        .text:0x000157A0    48B9                 cbnz r0, code_0x157B6
                        */
r0 = *( stack_0x0 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                        cond1 = r0 == 0;
                        /*
                        .text:0x000157A2 code_0x157A2:
                        .text:0x000157A2    9DF80000             ldrb.w r0, [stack_0x0]
                        .text:0x000157A6    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x000157AA    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x000157AE    01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x000157B2    0079                 ldrb r0, [r0, #0x4]
                        .text:0x000157B4    A8B3                 cbz r0, code_0x15822
                        */
r0 = *( stack_0x0 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x4 );
                        cond2 = r0 != 0;
                        if (cond1 && cond2) {
                            /*
                            .text:0x00015822 code_0x15822:
                            .text:0x00015822    FFE7                 b code_0x15824
                            .text:0x00015824 code_0x15824:
                            .text:0x00015824    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x00015828    D6ED070A             vldr s1, [r6, #0x1C]
                            .text:0x0001582C    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00015830    90ED000A             vldr s0, [r0]
                            .text:0x00015834    70EEE80A             vsub.f32 s1, s1, s17
                            .text:0x00015838    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x0001583C    20EE090A             vmul.f32 s0, s0, s18
                            .text:0x00015840    20EE200A             vmul.f32 s0, s0, s1
                            .text:0x00015844    C0EE080A             vdiv.f32 s1, s0, s16
                            .text:0x00015848    06EB8000             add.w r0, r6, r0, lsl #0x2
                            .text:0x0001584C    C0ED080A             vstr s1, [r0, #0x20]
                            .text:0x00015850    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x00015854    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015858    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x0001585C    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015860    4561                 str r5, [r0, #0x14]
                            .text:0x00015862    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x00015866    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x0001586A    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x0001586E    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015872    0774                 strb r7, [r0, #0x10]
                            .text:0x00015874    3CE1                 b code_0x15AF0
                            */
r0 = *( stack_0x0 );
s1 = *( r6 + 0x1C );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 );
s1 = s1 - s17;
r0 = *( stack_0x0 );
s0 = s0 * s18;
s0 = s0 * s1;
s1 = s0 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0x20 ) = s1;
r0 = *( stack_0x0 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x14 ) = r5;
r0 = *( stack_0x0 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x10 ) = r7;
                        } else {
                          /*
                          .text:0x000157B6 code_0x157B6:
                          .text:0x000157B6    9DF80000             ldrb.w r0, [stack_0x0]
                          .text:0x000157BA    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x000157BE    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x000157C2    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x000157C6    F268                 ldr r2, [r6, #0xC]
                          .text:0x000157C8    4069                 ldr r0, [r0, #0x14]
                          .text:0x000157CA    9042                 cmp r0, r2
                          .text:0x000157CC    56D3                 blo code_0x1587C
                          */
r0 = *( stack_0x0 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0xC );
r0 = *( r0 + 0x14 );
                          if (r0 >= r2) {
                            /*
                            .text:0x000157CE code_0x157CE:
                            .text:0x000157CE    B6F84000             ldrh.w r0, [r6, #0x40]
                            .text:0x000157D2    D6ED070A             vldr s1, [r6, #0x1C]
                            .text:0x000157D6    00EE100A             vmov s0, r0
                            .text:0x000157DA    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x000157DE    70EEE80A             vsub.f32 s1, s1, s17
                            .text:0x000157E2    B8EE400A             vcvt.f32.u32 s0, s0
                            .text:0x000157E6    20EE090A             vmul.f32 s0, s0, s18
                            .text:0x000157EA    20EE200A             vmul.f32 s0, s0, s1
                            .text:0x000157EE    C0EE080A             vdiv.f32 s1, s0, s16
                            .text:0x000157F2    06EB8000             add.w r0, r6, r0, lsl #0x2
                            .text:0x000157F6    C0ED080A             vstr s1, [r0, #0x20]
                            .text:0x000157FA    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x000157FE    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015802    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015806    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x0001580A    4561                 str r5, [r0, #0x14]
                            .text:0x0001580C    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x00015810    0222                 movs r2, #0x2
                            .text:0x00015812    00EB4003             add.w r3, r0, r0, lsl #0x1
                            .text:0x00015816    03EBC000             add.w r0, r3, r0, lsl #0x3
                            .text:0x0001581A    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x0001581E    0274                 strb r2, [r0, #0x10]
                            .text:0x00015820    66E1                 b code_0x15AF0
                            */
r0 = *( r6 + 0x40 );
s1 = *( r6 + 0x1C );
s0 = r0;
r0 = *( stack_0x0 );
s1 = s1 - s17;
s0 = (float) s0;
s0 = s0 * s18;
s0 = s0 * s1;
s1 = s0 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0x20 ) = s1;
r0 = *( stack_0x0 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x14 ) = r5;
r0 = *( stack_0x0 );
r2 = 0x2;
r3 = r0 + (r0 << 0x1);
r0 = r3 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x10 ) = r2;
                          } else {
                            /*
                            .text:0x0001587C code_0x1587C:
                            .text:0x0001587C    96ED050A             vldr s0, [r6, #0x14]
                            .text:0x00015880    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x00015884    96ED041A             vldr s2, [r6, #0x10]
                            .text:0x00015888    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x0001588C    D0ED000A             vldr s1, [r0]
                            .text:0x00015890    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x00015894    00EE810A             vmla.f32 s0, s1, s2
                            .text:0x00015898    04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x0001589C    80ED000A             vstr s0, [r0]
                            .text:0x000158A0    9DF80000             ldrb.w r0, [stack_0x0]
                            .text:0x000158A4    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x000158A8    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x000158AC    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x000158B0    4269                 ldr r2, [r0, #0x14]
                            .text:0x000158B2    521C                 adds r2, r2, #0x1
                            .text:0x000158B4    4261                 str r2, [r0, #0x14]
                            .text:0x000158B6    1BE1                 b code_0x15AF0
                            */
s0 = *( r6 + 0x14 );
r0 = *( stack_0x0 );
s2 = *( r6 + 0x10 );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 );
r0 = *( stack_0x0 );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
r0 = *( stack_0x0 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0x14 );
r2 = r2 + 0x1;
*( r0 + 0x14 ) = r2;
                          }
                        }
                        break;
                    case 2:
                        /*   
                        .text:0x0001587A code_0x1587A:
                        .text:0x0001587A        1DE0             b code_0x158B8
                        */
                        /*
                        .text:0x000158B8 code_0x158B8:
                        .text:0x000158B8        9DF80000             ldrb.w r0, [sp]
                        .text:0x000158BC        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x000158C0        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x000158C4        11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                        .text:0x000158C8        0128                 cmp r0, #0x1
                        .text:0x000158CA        1DD0                 beq code_0x15908
                        */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                        cond1 = r0 != 1;
                        /*
                        .text:0x000158CC code_0x158CC:
                        .text:0x000158CC        9DF80000             ldrb.w r0, [sp]
                        .text:0x000158D0        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x000158D4        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x000158D8        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x000158DC        0079                 ldrb r0, [r0, #0x4]
                        .text:0x000158DE        0128                 cmp r0, #0x1
                        .text:0x000158E0        12D0                 beq code_0x15908
                        */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x4 );
                        cond2 = r0 != 1;
                        if (cond1 && cond2) {
                            /*
                            .text:0x000158E2 code_0x158E2:
                            .text:0x000158E2        9DF80000             ldrb.w r0, [sp]
                            .text:0x000158E6        00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x000158EA        02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x000158EE        01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x000158F2        4561                 str r5, [r0, #0x14]
                            .text:0x000158F4        9DF80000             ldrb.w r0, [sp]
                            .text:0x000158F8        00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x000158FC        02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015900        01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015904        0774                 strb r7, [r0, #0x10]
                            .text:0x00015906        F3E0                 b code_0x15AF0
                            */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x14 ) = r5;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x10 ) = r7;
                        } else {
                            /*
                            .text:0x00015908 code_0x15908:
                            .text:0x00015908        B6F84000             ldrh.w r0, [r6, #0x40]
                            .text:0x0001590C        00EE100A             vmov s0, r0
                            .text:0x00015910        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015914        B8EE400A             vcvt.f32.u32 s0, s0
                            .text:0x00015918        04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x0001591C        80ED000A             vstr s0, [r0]
                            .text:0x00015920        E6E0                 b code_0x15AF0
                            */
r0 = *( r6 + 0x40 );
s0 = r0;
r0 = *( sp );
s0 = (float) s0;
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
                        }
                        break;
                    case 3:
                        /*
                        .text:0x00015878 code_0x15878:
                        .text:0x00015878        53E0                 b code_0x15922
                        */
                        /*
                        .text:0x00015922 code_0x15922:
                        .text:0x00015922        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015926        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x0001592A        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x0001592E        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015932        B269                 ldr r2, [r6, #0x18]
                        .text:0x00015934        4069                 ldr r0, [r0, #0x14]
                        .text:0x00015936        9042                 cmp r0, r2
                        .text:0x00015938        3ED3                 blo code_0x159B8
                        */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0x18 );
r0 = *( r0 + 0x14 );
                        if (r0 >= r2) {
                          /*
                          .text:0x0001593A code_0x1593A:
                          .text:0x0001593A        9DF80000             ldrb.w r0, [sp]
                          .text:0x0001593E        00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015942        02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015946        01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x0001594A        4561                 str r5, [r0, #0x14]
                          .text:0x0001594C        9DF80000             ldrb.w r0, [sp]
                          .text:0x00015950        04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x00015954        90ED000A             vldr s0, [r0]
                          .text:0x00015958        B5EEC00A             vcmpe.f32 s0, #0x0
                          .text:0x0001595C        F1EE10FA             vmrs APSR_nzcv, fpscr
                          .text:0x00015960        16DD                 ble code_0x15990
                          */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x14 ) = r5;
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 );
                          if (s0 <= 0.0) { 
                            /*
                            .text:0x00015990 code_0x15990:
                            .text:0x00015990        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015994        00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015998        02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x0001599C        01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x000159A0        80F81090             strb.w sb, [r0, #0x10]
                            .text:0x000159A4        9DF80000             ldrb.w r0, [sp]
                            .text:0x000159A8        00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x000159AC        02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x000159B0        01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x000159B4        4574                 strb r5, [r0, #0x11]
                            .text:0x000159B6        9BE0                 b code_0x15AF0
                            */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x10 ) = sb;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x11 ) = r5;
                          } else {
                            /*
                            .text:0x00015962 code_0x15962:
                            .text:0x00015962        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015966        00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x0001596A        02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x0001596E        01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015972        80F81080             strb.w r8, [r0, #0x10]
                            .text:0x00015976        BBE0                 b code_0x15AF0
                            */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x10 ) = r8;
                          }
                        } else {
                          /*
                          .text:0x000159B8 code_0x159B8:
                          .text:0x000159B8        9DF80000             ldrb.w r0, [sp]
                          .text:0x000159BC        06EB8000             add.w r0, r6, r0, lsl #0x2
                          .text:0x000159C0        90ED080A             vldr s0, [r0, #0x20]
                          .text:0x000159C4        9DF80000             ldrb.w r0, [sp]
                          .text:0x000159C8        96ED071A             vldr s2, [r6, #0x1C]
                          .text:0x000159CC        04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x000159D0        D0ED000A             vldr s1, [r0]
                          .text:0x000159D4        9DF80000             ldrb.w r0, [sp]
                          .text:0x000159D8        00EE810A             vmla.f32 s0, s1, s2
                          .text:0x000159DC        04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x000159E0        80ED000A             vstr s0, [r0]
                          .text:0x000159E4        9DF80000             ldrb.w r0, [sp]
                          .text:0x000159E8        00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x000159EC        02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x000159F0        01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x000159F4        4269                 ldr r2, [r0, #0x14]
                          .text:0x000159F6        521C                 adds r2, r2, #0x1
                          .text:0x000159F8        4261                 str r2, [r0, #0x14]
                          .text:0x000159FA        79E0                 b code_0x15AF0
                          */
r0 = *( sp );
r0 = r6 + (r0 << 0x2);
s0 = *( r0 + 0x20 );
r0 = *( sp );
s2 = *( r6 + 0x1C );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 );
r0 = *( sp );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 ) = s0;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0x14 );
r2 = r2 + 0x1;
*( r0 + 0x14 ) = r2;
                        }
                        break;
                    case 4:
                        /*
                        .text:0x00015820    66E1                 b code_0x15AF0
                        */
                        break;
                    case 5:
                        /*
                        .text:0x00015820    66E1                 b code_0x15AF0
                        */
                        break;
                    case 6:
                        /*
                        .text:0x00015876 code_0x15876:
                        .text:0x00015876        C1E0                 b code_0x159FC
                        .text:0x000159FC code_0x159FC:
                        .text:0x000159FC        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015A00        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015A04        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015A08        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015A0C        4069                 ldr r0, [r0, #0x14]
                        .text:0x00015A0E        68B3                 cbz r0, code_0x15A6C
                        */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x14 );
                        if (r0 != 0) {
                          /*
                          .text:0x00015A10 code_0x15A10:
                          .text:0x00015A10        9DF80000             ldrb.w r0, [sp]
                          .text:0x00015A14        00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015A18        02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015A1C        01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x00015A20        4069                 ldr r0, [r0, #0x14]
                          .text:0x00015A22        1428                 cmp r0, #0x14
                          .text:0x00015A24        3AD3                 blo code_0x15A9C
                          */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x14 );
                          if (r0 >= 0x14) {
                            /*
                            .text:0x00015A26 code_0x15A26:
                            .text:0x00015A26        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015A2A        04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00015A2E        80ED00AA             vstr s20, [r0]
                            .text:0x00015A32        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015A36        00EB4002             add.w r2, r0, r0, lsl #0x1
                            */
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
*( r0 ) = s20;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
                            /*
                            .text:0x00015A3A code_0x15A3A:
                            .text:0x00015A3A    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015A3E    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015A42    4561                 str r5, [r0, #0x14]
                            .text:0x00015A44    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015A48    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015A4C    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015A50    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015A54    80F81090             strb.w sb, [r0, #0x10]
                            .text:0x00015A58    9DF80000             ldrb.w r0, [local_0x28]
                            .text:0x00015A5C    00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015A60    02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015A64    01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015A68    4574                 strb r5, [r0, #0x11]
                            .text:0x00015A6A    41E0                 b code_0x15AF0
                            */
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x14 ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x10 ) = sb;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x11 ) = r5;
                          } else {
                            /*
                            .text:0x00015A9C code_0x15A9C:
                            .text:0x00015A9C        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015AA0        04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00015AA4        D0ED100A             vldr s1, [r0, #0x40]
                            .text:0x00015AA8        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015AAC        00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015AB0        02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015AB4        01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015AB8        4069                 ldr r0, [r0, #0x14]
                            .text:0x00015ABA        C0F11400             rsb.w r0, r0, #0x14
                            .text:0x00015ABE        00EE100A             vmov s0, r0
                            .text:0x00015AC2        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015AC6        B8EE400A             vcvt.f32.u32 s0, s0
                            .text:0x00015ACA        20EE800A             vmul.f32 s0, s1, s0
                            .text:0x00015ACE        C0EE290A             vdiv.f32 s1, s0, s19
                            .text:0x00015AD2        04EB8000             add.w r0, r4, r0, lsl #0x2
                            .text:0x00015AD6        C0ED000A             vstr s1, [r0]
                            .text:0x00015ADA        9DF80000             ldrb.w r0, [sp]
                            .text:0x00015ADE        00EB4002             add.w r2, r0, r0, lsl #0x1
                            .text:0x00015AE2        02EBC000             add.w r0, r2, r0, lsl #0x3
                            .text:0x00015AE6        01EB8000             add.w r0, r1, r0, lsl #0x2
                            .text:0x00015AEA        4269                 ldr r2, [r0, #0x14]
                            .text:0x00015AEC        521C                 adds r2, r2, #0x1
                            .text:0x00015AEE        4261                 str r2, [r0, #0x14]
                            */
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 + 0x40 );
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x14 );
r0 = 0x14 - r0;
s0 = r0;
r0 = *( sp );
s0 = (float) s0;
s0 = s1 * s0;
s1 = s0 / s19;
r0 = r4 + (r0 << 0x2);
*( r0 ) = s1;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0x14 );
r2 = r2 + 0x1;
*( r0 + 0x14 ) = r2;
                          }
                        } else {
                          /*
                          .text:0x00015A6C code_0x15A6C:
                          .text:0x00015A6C        9DF80000             ldrb.w r0, [sp]
                          .text:0x00015A70        04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x00015A74        90ED000A             vldr s0, [r0]
                          .text:0x00015A78        9DF80000             ldrb.w r0, [sp]
                          .text:0x00015A7C        04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x00015A80        80ED100A             vstr s0, [r0, #0x40]
                          .text:0x00015A84        9DF80000             ldrb.w r0, [sp]
                          .text:0x00015A88        00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015A8C        02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015A90        01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x00015A94        4269                 ldr r2, [r0, #0x14]
                          .text:0x00015A96        521C                 adds r2, r2, #0x1
                          .text:0x00015A98        4261                 str r2, [r0, #0x14]
                          .text:0x00015A9A        29E0                 b code_0x15AF0
                          */
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 );
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x40 ) = s0;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r0 + 0x14 );
r2 = r2 + 0x1;
*( r0 + 0x14 ) = r2;
                        }
                        break;
                }
          }

          /*
          .text:0x00015AF0 code_0x15AF0:
          .text:0x00015AF0    9DF80000             ldrb.w r0, [local_0x28]
          .text:0x00015AF4    00EB4002             add.w r2, r0, r0, lsl #0x1
          .text:0x00015AF8    02EBC000             add.w r0, r2, r0, lsl #0x3
          .text:0x00015AFC    01EB8000             add.w r0, r1, r0, lsl #0x2
          .text:0x00015B00    90F82100             ldrb.w r0, [r0, #0x21]
          .text:0x00015B04    0128                 cmp r0, #0x1
          .text:0x00015B06    40F04882             bne.w code_0x15F9A
          */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x21 );
          cond1 = r0 == 1;
          /*
          .text:0x00015B0A code_0x15B0A:
          .text:0x00015B0A    9DF80000             ldrb.w r0, [local_0x28]
          .text:0x00015B0E    00EB4002             add.w r2, r0, r0, lsl #0x1
          .text:0x00015B12    02EBC000             add.w r0, r2, r0, lsl #0x3
          .text:0x00015B16    01EB8000             add.w r0, r1, r0, lsl #0x2
          .text:0x00015B1A    90F82000             ldrb.w r0, [r0, #0x20]
          .text:0x00015B1E    0728                 cmp r0, #0x7
          .text:0x00015B20    80F03B82             bhs.w code_0x15F9A
          */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x20 );
          cond2 = r0 < 7;
          if (cond1 && cond2) {
            /*
            .text:0x00015B24 code_0x15B24:
            .text:0x00015B24    DFE800F0             tbb [jump_table_7, r0]; 6 indirect references.
            .text:0x00015B28                         db [ 0x04, 0x8A, 0xFE, 0xFD, 0x89, 0x89, 0xFC ]
            */
            switch (r0) {
                case 0:
                    /*
                    .text:0x00015B30 code_0x15B30:
                    .text:0x00015B30    9DF80000             ldrb.w r0, [local_0x28]
                    .text:0x00015B34    00EB4002             add.w r2, r0, r0, lsl #0x1
                    .text:0x00015B38    02EBC000             add.w r0, r2, r0, lsl #0x3
                    .text:0x00015B3C    11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                    .text:0x00015B40    48B9                 cbnz r0, code_0x15B56
                    */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                    cond1 = r0 == 0;
                    /*
                    .text:0x00015B42 code_0x15B42:
                    .text:0x00015B42    9DF80000             ldrb.w r0, [local_0x28]
                    .text:0x00015B46    00EB4002             add.w r2, r0, r0, lsl #0x1
                    .text:0x00015B4A    02EBC000             add.w r0, r2, r0, lsl #0x3
                    .text:0x00015B4E    01EB8000             add.w r0, r1, r0, lsl #0x2
                    .text:0x00015B52    0079                 ldrb r0, [r0, #0x4]
                    .text:0x00015B54    48B3                 cbz r0, code_0x15BAA
                    */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x4 );
                    cond2 = r0 == 0;

                    if (cond1 && cond2) {
                        /*
                        .text:0x00015BAA code_0x15BAA:
                        .text:0x00015BAA    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00015BAE    D6ED2B0A             vldr s1, [r6, #0xAC]
                        .text:0x00015BB2    04EB8000             add.w r0, r4, r0, lsl #0x2
                        .text:0x00015BB6    90ED080A             vldr s0, [r0, #0x20]
                        .text:0x00015BBA    70EEE80A             vsub.f32 s1, s1, s17
                        .text:0x00015BBE    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00015BC2    20EE090A             vmul.f32 s0, s0, s18
                        .text:0x00015BC6    20EE200A             vmul.f32 s0, s0, s1
                        .text:0x00015BCA    C0EE080A             vdiv.f32 s1, s0, s16
                        .text:0x00015BCE    06EB8000             add.w r0, r6, r0, lsl #0x2
                        .text:0x00015BD2    C0ED2C0A             vstr s1, [r0, #0xB0]
                        .text:0x00015BD6    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00015BDA    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015BDE    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015BE2    01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015BE6    4562                 str r5, [r0, #0x24]
                        .text:0x00015BE8    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00015BEC    00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015BF0    02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015BF4    01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015BF8    80F82070             strb.w r7, [r0, #0x20]
                        .text:0x00015BFC    00F0CDB9             b.w code_0x15F9A
                        */
r0 = *( local_0x28 );
s1 = *( r6 + 0xAC );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 + 0x20 );
s1 = s1 - s17;
r0 = *( local_0x28 );
s0 = s0 * s18;
s0 = s0 * s1;
s1 = s0 / s16;
r0 = r6 + (r0 << 0x2);
*( r0 + 0xB0 ) = s1;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x24 ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x20 ) = r7;
                    } else {
                      /*
                      .text:0x00015B56 code_0x15B56:
                      .text:0x00015B56    9DF80000             ldrb.w r0, [local_0x28]
                      .text:0x00015B5A    00EB4002             add.w r2, r0, r0, lsl #0x1
                      .text:0x00015B5E    02EBC000             add.w r0, r2, r0, lsl #0x3
                      .text:0x00015B62    01EB8000             add.w r0, r1, r0, lsl #0x2
                      .text:0x00015B66    D6F89020             ldr.w r2, [r6, #0x90]
                      .text:0x00015B6A    406A                 ldr r0, [r0, #0x24]
                      .text:0x00015B6C    9042                 cmp r0, r2
                      .text:0x00015B6E    07D2                 bhs code_0x15B80
                      */
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0x90 );
r0 = *( r0 + 0x24 );
                      if (r0 < r2) {
                        /*
                        .text:0x00015B70 code_0x15B70:
                        .text:0x00015B70    9DF80000             ldrb.w r0, [local_0x28]
                        .text:0x00015B74    FF4A                 ldr r2, [_0x457FE000_1]
                        .text:0x00015B76    04EB8000             add.w r0, r4, r0, lsl #0x2
                        .text:0x00015B7A    006A                 ldr r0, [r0, #0x20]
                        .text:0x00015B7C    9042                 cmp r0, r2
                        .text:0x00015B7E    3FDB                 blt code_0x15C00
                        */
r0 = *( local_0x28 );
r2 = *( _0x457FE000_1 );
r0 = r4 + (r0 << 0x2);
r0 = *( r0 + 0x20 );
                        if (r0 < r2) {
                          /*
                          .text:0x00015C00 code_0x15C00:
                          .text:0x00015C00    96ED260A             vldr s0, [r6, #0x98]
                          .text:0x00015C04    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015C08    96ED251A             vldr s2, [r6, #0x94]
                          .text:0x00015C0C    04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x00015C10    D0ED080A             vldr s1, [r0, #0x20]
                          .text:0x00015C14    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015C18    00EE810A             vmla.f32 s0, s1, s2
                          .text:0x00015C1C    04EB8000             add.w r0, r4, r0, lsl #0x2
                          .text:0x00015C20    80ED080A             vstr s0, [r0, #0x20]
                          .text:0x00015C24    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015C28    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015C2C    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015C30    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x00015C34    416A                 ldr r1, [r0, #0x24]
                          .text:0x00015C36    491C                 adds r1, r1, #0x1
                          .text:0x00015C38    4162                 str r1, [r0, #0x24]
                          .text:0x00015C3A    AEE1                 b code_0x15F9A
                          */
s0 = *( r6 + 0x98 );
r0 = *( local_0x28 );
s2 = *( r6 + 0x94 );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 + 0x20 );
r0 = *( local_0x28 );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s0;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r1 = *( r0 + 0x24 );
r1 = r1 + 0x1;
*( r0 + 0x24 ) = r1;
                        } else {
                          /*
                          .text:0x00015B80 code_0x15B80:
                          .text:0x00015B80    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015B84    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015B88    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015B8C    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x00015B90    4562                 str r5, [r0, #0x24]
                          .text:0x00015B92    9DF80000             ldrb.w r0, [local_0x28]
                          .text:0x00015B96    00EB4002             add.w r2, r0, r0, lsl #0x1
                          .text:0x00015B9A    02EBC000             add.w r0, r2, r0, lsl #0x3
                          .text:0x00015B9E    01EB8000             add.w r0, r1, r0, lsl #0x2
                          .text:0x00015BA2    80F820A0             strb.w sl, [r0, #0x20]
                          .text:0x00015BA6    00F0F8B9             b.w code_0x15F9A
                          */ 
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x24 ) = r5;
r0 = *( local_0x28 );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x20 ) = sl;
                        }
                      }
                    }
                  break;
                case 1:
                    /*
                    .text:0x00015C38    4162                 str r1, [r0, #0x24]
                    .text:0x00015C3A    AEE1                 b code_0x15F9A
                    */
*( r0 + 0x24 ) = r1;
                    break;
                case 2:
                    /*
                    .text:0x00015D24 code_0x15D24:
                    .text:0x00015D24        22E0                 b code_0x15D6C
                    */
                    /*
                    .text:0x00015D6C code_0x15D6C:
                    .text:0x00015D6C        9DF80000             ldrb.w r0, [sp]
                    .text:0x00015D70        00EB4002             add.w r2, r0, r0, lsl #0x1
                    .text:0x00015D74        02EBC000             add.w r0, r2, r0, lsl #0x3
                    .text:0x00015D78        11F82000             ldrb.w r0, [r1, r0, lsl #0x2]
                    .text:0x00015D7C        0128                 cmp r0, #0x1
                    .text:0x00015D7E        1ED0                 beq code_0x15DBE
                    */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = *( r1 + r0 << 0x2 );
                    cond1 = r0 != 1;
                    /*
                    .text:0x00015D80 code_0x15D80:
                    .text:0x00015D80        9DF80000             ldrb.w r0, [sp]
                    .text:0x00015D84        00EB4002             add.w r2, r0, r0, lsl #0x1
                    .text:0x00015D88        02EBC000             add.w r0, r2, r0, lsl #0x3
                    .text:0x00015D8C        01EB8000             add.w r0, r1, r0, lsl #0x2
                    .text:0x00015D90        0079                 ldrb r0, [r0, #0x4]
                    .text:0x00015D92        0128                 cmp r0, #0x1
                    .text:0x00015D94        13D0                 beq code_0x15DBE
                    */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x4 );
                    cond2 = r0 != 1;
                    if (cond1 && cond2) {
                      /*
                      .text:0x00015D96 code_0x15D96:
                      .text:0x00015D96        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015D9A        00EB4002             add.w r2, r0, r0, lsl #0x1
                      .text:0x00015D9E        02EBC000             add.w r0, r2, r0, lsl #0x3
                      .text:0x00015DA2        01EB8000             add.w r0, r1, r0, lsl #0x2
                      .text:0x00015DA6        4562                 str r5, [r0, #0x24]
                      .text:0x00015DA8        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015DAC        00EB4002             add.w r2, r0, r0, lsl #0x1
                      .text:0x00015DB0        02EBC000             add.w r0, r2, r0, lsl #0x3
                      .text:0x00015DB4        01EB8000             add.w r0, r1, r0, lsl #0x2
                      .text:0x00015DB8        80F82070             strb.w r7, [r0, #0x20]
                      .text:0x00015DBC        EDE0                 b code_0x15F9A
                      */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x24 ) = r5;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x20 ) = r7;
                    } else {
                      /*
                      .text:0x00015DBE code_0x15DBE:
                      .text:0x00015DBE        B6F8D000             ldrh.w r0, [r6, #0xD0]
                      .text:0x00015DC2        00EE100A             vmov s0, r0
                      .text:0x00015DC6        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015DCA        B8EE400A             vcvt.f32.u32 s0, s0
                      .text:0x00015DCE        04EB8000             add.w r0, r4, r0, lsl #0x2
                      .text:0x00015DD2        80ED080A             vstr s0, [r0, #0x20]
                      .text:0x00015DD6        E0E0                 b code_0x15F9A
                      */
r0 = *( r6 + 0xD0 );
s0 = r0;
r0 = *( sp );
s0 = (float) s0;
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s0;
                    }
                    break;
                case 3:
                    /*
                    .text:0x00015D22 code_0x15D22:
                    .text:0x00015D22        59E0                 b code_0x15DD8 
                    */
                    /*
                    .text:0x00015DD8 code_0x15DD8:
                    .text:0x00015DD8        9DF80000             ldrb.w r0, [sp]
                    .text:0x00015DDC        00EB4002             add.w r2, r0, r0, lsl #0x1
                    .text:0x00015DE0        02EBC000             add.w r0, r2, r0, lsl #0x3
                    .text:0x00015DE4        01EB8000             add.w r0, r1, r0, lsl #0x2
                    .text:0x00015DE8        D6F8A820             ldr.w r2, [r6, #0xA8]
                    .text:0x00015DEC        406A                 ldr r0, [r0, #0x24]
                    .text:0x00015DEE        9042                 cmp r0, r2
                    .text:0x00015DF0        33D3                 blo code_0x15E5A
                    */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r2 = *( r6 + 0xA8 );
r0 = *( r0 + 0x24 );
                    if (r0 >= r2) {
                      /*
                      .text:0x00015DF2 code_0x15DF2:
                      .text:0x00015DF2        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015DF6        00EB4002             add.w r2, r0, r0, lsl #0x1
                      .text:0x00015DFA        02EBC000             add.w r0, r2, r0, lsl #0x3
                      .text:0x00015DFE        01EB8000             add.w r0, r1, r0, lsl #0x2
                      .text:0x00015E02        4562                 str r5, [r0, #0x24]
                      .text:0x00015E04        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015E08        04EB8000             add.w r0, r4, r0, lsl #0x2
                      .text:0x00015E0C        90ED080A             vldr s0, [r0, #0x20]
                      .text:0x00015E10        B5EEC00A             vcmpe.f32 s0, #0x0
                      .text:0x00015E14        F1EE10FA             vmrs APSR_nzcv, fpscr
                      .text:0x00015E18        0ADD                 ble code_0x15E30
                      */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x24 ) = r5;
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 + 0x20 );
                      if (s0 > 0.0) {
                        /*
                        .text:0x00015E1A code_0x15E1A:
                        .text:0x00015E1A        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015E1E        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015E22        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015E26        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015E2A        80F82080             strb.w r8, [r0, #0x20]
                        .text:0x00015E2E        B4E0                 b code_0x15F9A
                        */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x20 ) = r8;
                      } else {
                        /*
                        .text:0x00015E30 code_0x15E30:
                        .text:0x00015E30        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015E34        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015E38        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015E3C        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015E40        80F82090             strb.w sb, [r0, #0x20]
                        .text:0x00015E44        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015E48        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015E4C        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015E50        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015E54        80F82150             strb.w r5, [r0, #0x21]
                        .text:0x00015E58        9FE0                 b code_0x15F9A
                        */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x20 ) = sb;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x21 ) = r5;
                      }
                    } else {
                      /*
                      .text:0x00015E5A code_0x15E5A:
                      .text:0x00015E5A        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015E5E        06EB8000             add.w r0, r6, r0, lsl #0x2
                      .text:0x00015E62        90ED2C0A             vldr s0, [r0, #0xB0]
                      .text:0x00015E66        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015E6A        96ED2B1A             vldr s2, [r6, #0xAC]
                      .text:0x00015E6E        04EB8000             add.w r0, r4, r0, lsl #0x2
                      .text:0x00015E72        D0ED080A             vldr s1, [r0, #0x20]
                      .text:0x00015E76        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015E7A        00EE810A             vmla.f32 s0, s1, s2
                      .text:0x00015E7E        04EB8000             add.w r0, r4, r0, lsl #0x2
                      .text:0x00015E82        80ED080A             vstr s0, [r0, #0x20]
                      .text:0x00015E86        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015E8A        00EB4002             add.w r2, r0, r0, lsl #0x1
                      .text:0x00015E8E        02EBC000             add.w r0, r2, r0, lsl #0x3
                      .text:0x00015E92        01EB8000             add.w r0, r1, r0, lsl #0x2
                      .text:0x00015E96        416A                 ldr r1, [r0, #0x24]
                      .text:0x00015E98        491C                 adds r1, r1, #0x1
                      .text:0x00015E9A        4162                 str r1, [r0, #0x24]
                      .text:0x00015E9C        7DE0                 b code_0x15F9A
                      */
r0 = *( sp );
r0 = r6 + (r0 << 0x2);
s0 = *( r0 + 0xB0 );
r0 = *( sp );
s2 = *( r6 + 0xAC );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 + 0x20 );
r0 = *( sp );
s0 =  (s0 + s1 * s2 );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s0;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r1 = *( r0 + 0x24 );
r1 = r1 + 0x1;
*( r0 + 0x24 ) = r1;
                    }
                    break;
                case 4:
                    /*
                    .text:0x00015C34    416A                 ldr r1, [r0, #0x24]
                    .text:0x00015C36    491C                 adds r1, r1, #0x1
                    .text:0x00015C38    4162                 str r1, [r0, #0x24]
                    .text:0x00015C3A    AEE1                 b code_0x15F9A
                    */
r1 = *( r0 + 0x24 );
r1 = r1 + 0x1;
*( r0 + 0x24 ) = r1;
                    break;
                case 5:
                    /*
                    .text:0x00015C34    416A                 ldr r1, [r0, #0x24]
                    .text:0x00015C36    491C                 adds r1, r1, #0x1
                    .text:0x00015C38    4162                 str r1, [r0, #0x24]
                    .text:0x00015C3A    AEE1                 b code_0x15F9A
                    */
r1 = *( r0 + 0x24 );
r1 = r1 + 0x1;
*( r0 + 0x24 ) = r1;
                    break;
                case 6:
                    /*
                    .text:0x00015D20 code_0x15D20:
                    .text:0x00015D20        BDE0                 b code_0x15E9E
                    */
                    /*
                    .text:0x00015E9E code_0x15E9E:
                    .text:0x00015E9E        9DF80000             ldrb.w r0, [sp]
                    .text:0x00015EA2        00EB4002             add.w r2, r0, r0, lsl #0x1
                    .text:0x00015EA6        02EBC000             add.w r0, r2, r0, lsl #0x3
                    .text:0x00015EAA        01EB8000             add.w r0, r1, r0, lsl #0x2
                    .text:0x00015EAE        406A                 ldr r0, [r0, #0x24]
                    .text:0x00015EB0        70B3                 cbz r0, code_0x15F10
                    */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x24 );
                    if (r0 != 0) {
                      /*
                      .text:0x00015EB2 code_0x15EB2:
                      .text:0x00015EB2        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015EB6        00EB4002             add.w r2, r0, r0, lsl #0x1
                      .text:0x00015EBA        02EBC000             add.w r0, r2, r0, lsl #0x3
                      .text:0x00015EBE        01EB8000             add.w r0, r1, r0, lsl #0x2
                      .text:0x00015EC2        406A                 ldr r0, [r0, #0x24]
                      .text:0x00015EC4        1428                 cmp r0, #0x14
                      .text:0x00015EC6        3BD3                 blo code_0x15F40
                      */
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x24 );
                      if (r0 < 0x14) {
                        /*
                        .text:0x00015F40 code_0x15F40:
                        .text:0x00015F40        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015F44        04EB8000             add.w r0, r4, r0, lsl #0x2
                        .text:0x00015F48        D0ED180A             vldr s1, [r0, #0x60]
                        .text:0x00015F4C        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015F50        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015F54        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015F58        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015F5C        406A                 ldr r0, [r0, #0x24]
                        .text:0x00015F5E        C0F11400             rsb.w r0, r0, #0x14
                        .text:0x00015F62        00EE100A             vmov s0, r0
                        .text:0x00015F66        B8EE400A             vcvt.f32.u32 s0, s0
                        .text:0x00015F6A        20EE800A             vmul.f32 s0, s1, s0
                        .text:0x00015F6E        C0EE290A             vdiv.f32 s1, s0, s19
                        .text:0x00015F72        01E0                 b code_0x15F78
                        */
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
s1 = *( r0 + 0x60 );
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r0 = *( r0 + 0x24 );
r0 = 0x14 - r0;
s0 = r0;
s0 = (float) s0;
s0 = s1 * s0;
s1 = s0 / s19;
                        /*
                        .text:0x00015F78 code_0x15F78:
                        .text:0x00015F78        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015F7C        04EB8000             add.w r0, r4, r0, lsl #0x2
                        .text:0x00015F80        C0ED080A             vstr s1, [r0, #0x20]
                        .text:0x00015F84        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015F88        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015F8C        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015F90        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015F94        416A                 ldr r1, [r0, #0x24]
                        .text:0x00015F96        491C                 adds r1, r1, #0x1
                        .text:0x00015F98        4162                 str r1, [r0, #0x24]
                        */
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s1;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r1 = *( r0 + 0x24 );
r1 = r1 + 0x1;
*( r0 + 0x24 ) = r1;
                      } else {
                        /*
                        .text:0x00015EC8 code_0x15EC8:
                        .text:0x00015EC8        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015ECC        04EB8000             add.w r0, r4, r0, lsl #0x2
                        .text:0x00015ED0        80ED08AA             vstr s20, [r0, #0x20]
                        .text:0x00015ED4        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015ED8        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015EDC        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015EE0        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015EE4        4562                 str r5, [r0, #0x24]
                        .text:0x00015EE6        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015EEA        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015EEE        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015EF2        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015EF6        80F82090             strb.w sb, [r0, #0x20]
                        .text:0x00015EFA        9DF80000             ldrb.w r0, [sp]
                        .text:0x00015EFE        00EB4002             add.w r2, r0, r0, lsl #0x1
                        .text:0x00015F02        02EBC000             add.w r0, r2, r0, lsl #0x3
                        .text:0x00015F06        01EB8000             add.w r0, r1, r0, lsl #0x2
                        .text:0x00015F0A        80F82150             strb.w r5, [r0, #0x21]
                        .text:0x00015F0E        44E0                 b code_0x15F9A
                        */
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x20 ) = s20;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x24 ) = r5;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x20 ) = sb;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
*( r0 + 0x21 ) = r5;
                      }
                    } else {
                      /*
                      .text:0x00015F10 code_0x15F10:
                      .text:0x00015F10        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015F14        04EB8000             add.w r0, r4, r0, lsl #0x2
                      .text:0x00015F18        90ED080A             vldr s0, [r0, #0x20]
                      .text:0x00015F1C        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015F20        04EB8000             add.w r0, r4, r0, lsl #0x2
                      .text:0x00015F24        80ED180A             vstr s0, [r0, #0x60]
                      .text:0x00015F28        9DF80000             ldrb.w r0, [sp]
                      .text:0x00015F2C        00EB4002             add.w r2, r0, r0, lsl #0x1
                      .text:0x00015F30        02EBC000             add.w r0, r2, r0, lsl #0x3
                      .text:0x00015F34        01EB8000             add.w r0, r1, r0, lsl #0x2
                      .text:0x00015F38        416A                 ldr r1, [r0, #0x24]
                      .text:0x00015F3A        491C                 adds r1, r1, #0x1
                      .text:0x00015F3C        4162                 str r1, [r0, #0x24]
                      .text:0x00015F3E        2CE0                 b code_0x15F9A
                      */
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 + 0x20 );
r0 = *( sp );
r0 = r4 + (r0 << 0x2);
*( r0 + 0x60 ) = s0;
r0 = *( sp );
r2 = r0 + (r0 << 0x1);
r0 = r2 + (r0 << 0x3);
r0 = r1 + (r0 << 0x2);
r1 = *( r0 + 0x24 );
r1 = r1 + 0x1;
*( r0 + 0x24 ) = r1;
                    }
                    break;
            }
          }

          /*
          .text:0x00015F9A code_0x15F9A:
          .text:0x00015F9A    F1F7BFFE             bl func_0x7D1C; inline int __cdecl( void )
          .text:0x00015F9E    E8B3                 cbz r0, code_0x1601C
          .text:0x0001601C code_0x1601C:
          .text:0x0001601C    1AE0                 b code_0x16054
          */
r0 = func_0x7D1C(r0);
          if (r0 != 0) {
            /*
            .text:0x00015FA0 code_0x15FA0:
            .text:0x00015FA0    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x00015FA4    DFF800B2             ldr.w fp, [string_h_6]; "h"
            .text:0x00015FA8    04EB8000             add.w r0, r4, r0, lsl #0x2
            .text:0x00015FAC    90ED000A             vldr s0, [r0]
            .text:0x00015FB0    DBED020A             vldr s1, [fp, #0x8]
            .text:0x00015FB4    BCEEC00A             vcvt.u32.f32 s0, s0
            .text:0x00015FB8    10EE100A             vmov r0, s0
            .text:0x00015FBC    C0F38D00             ubfx r0, r0, #0x2, #0xE
            .text:0x00015FC0    00EE100A             vmov s0, r0
            .text:0x00015FC4    B8EE400A             vcvt.f32.u32 s0, s0
            .text:0x00015FC8    20EE200A             vmul.f32 s0, s0, s1
            .text:0x00015FCC    BCEEC00A             vcvt.u32.f32 s0, s0
            .text:0x00015FD0    10EE100A             vmov r0, s0
            .text:0x00015FD4    80B2                 uxth r0, r0
            .text:0x00015FD6    F1F7A9FE             bl get_point_on_2A024_curve; int __cdecl( int p1 )
            .text:0x00015FDA    9DF80010             ldrb.w r1, [local_0x28]
            .text:0x00015FDE    9DF80020             ldrb.w r2, [local_0x28]
            .text:0x00015FE2    8907                 lsls r1, r1, #0x1E
            .text:0x00015FE4    490F                 lsrs r1, r1, #0x1D
            .text:0x00015FE6    08EB9203             add.w r3, r8, r2, lsr #0x2
            .text:0x00015FEA    0246                 mov r2, r0
            .text:0x00015FEC    1846                 mov r0, r3
            .text:0x00015FEE    F4F713F8             bl play_note_in_mem_on_voice_p1_note_p2_vol_p3; void __cdecl( int p1, int p2, int p3 )
            .text:0x00015FF2    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x00015FF6    DBED020A             vldr s1, [fp, #0x8]
            .text:0x00015FFA    04EB8000             add.w r0, r4, r0, lsl #0x2
            .text:0x00015FFE    90ED080A             vldr s0, [r0, #0x20]
            .text:0x00016002    BCEEC00A             vcvt.u32.f32 s0, s0
            .text:0x00016006    10EE100A             vmov r0, s0
            .text:0x0001600A    C0F38D00             ubfx r0, r0, #0x2, #0xE
            .text:0x0001600E    00EE100A             vmov s0, r0
            .text:0x00016012    B8EE400A             vcvt.f32.u32 s0, s0
            .text:0x00016016    20EE200A             vmul.f32 s0, s0, s1
            .text:0x0001601A    00E0                 b code_0x1601E
            */
r0 = *( local_0x28 );
fp = *( string_h_6 + "h" );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 );
s1 = *( fp + 0x8 );
s0 = (unsigned int) s0;
r0 = s0;
r0 = (unsigned int) r0;
s0 = r0;
s0 = (float) s0;
s0 = s0 * s1;
s0 = (unsigned int) s0;
r0 = s0;
r0 = (unsigned int) r0;
r0 = get_point_on_2A024_curve(r0);
r1 = *( local_0x28 );
r2 = *( local_0x28 );
r1 = r1 << 0x1E;
r1 = r1 >> 0x1D;
r3 = r8 + (r2 >> 0x2);
r2 = r0;
r0 = r3;
play_note_in_mem_on_voice_p1_note_p2_vol_p3(r0,r1,r2);
r0 = *( local_0x28 );
s1 = *( fp + 0x8 );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 + 0x20 );
s0 = (unsigned int) s0;
r0 = s0;
r0 = (unsigned int) r0;
s0 = r0;
s0 = (float) s0;
s0 = s0 * s1;
            /*
            .text:0x0001601E code_0x1601E:
            .text:0x0001601E    BCEEC00A             vcvt.u32.f32 s0, s0
            .text:0x00016022    10EE100A             vmov r0, s0
            .text:0x00016026    80B2                 uxth r0, r0
            .text:0x00016028    F1F780FE             bl get_point_on_2A024_curve; int __cdecl( int p1 )
            .text:0x0001602C    0246                 mov r2, r0
            .text:0x0001602E    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x00016032    00F00300             and r0, r0, #0x3
            .text:0x00016036    0AEB4001             add.w r1, sl, r0, lsl #0x1
            .text:0x0001603A    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x0001603E    08EB9000             add.w r0, r8, r0, lsr #0x2
            .text:0x00016042    F3F7E9FF             bl play_note_in_mem_on_voice_p1_note_p2_vol_p3; void __cdecl( int p1, int p2, int p3 )
            */
s0 = (unsigned int) s0;
r0 = s0;
r0 = (unsigned int) r0;
r0 = get_point_on_2A024_curve(r0);
r2 = r0;
r0 = *( local_0x28 );
r0 = r0 & 0x3;
r1 = sl + (r0 << 0x1);
r0 = *( local_0x28 );
r0 = r8 + (r0 >> 0x2);
play_note_in_mem_on_voice_p1_note_p2_vol_p3(r0,r1,r2);
          } else {
            /* 
            .text:0x00016054 code_0x16054:
            .text:0x00016054    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x00016058    04EB8000             add.w r0, r4, r0, lsl #0x2
            .text:0x0001605C    90ED000A             vldr s0, [r0]
            .text:0x00016060    BCEEC00A             vcvt.u32.f32 s0, s0
            .text:0x00016064    10EE100A             vmov r0, s0
            .text:0x00016068    80B2                 uxth r0, r0
            .text:0x0001606A    B0F5805F             cmp.w r0, #0x1000
            .text:0x0001606E    01D3                 blo code_0x16074
            */
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 );
s0 = (unsigned int) s0;
r0 = s0;
r0 = (unsigned int) r0;
            if (r0 >= 0x1000) {
              /* 
              .text:0x00016070 code_0x16070:
              .text:0x00016070    40F6FF70             movw r0, #0xFFF
              */
r0 = 0xFFF;
            }
            /* 
            .text:0x00016074 code_0x16074:
            .text:0x00016074    DFF838B1             ldr.w fp, [string_dT]; "dT"
            .text:0x00016078    9DF80010             ldrb.w r1, [local_0x28]
            .text:0x0001607C    3BF82110             ldrh.w r1, [fp, r1, lsl #0x2]
            .text:0x00016080    00EE101A             vmov s0, r1
            .text:0x00016084    4849                 ldr r1, [string_h_6]; "h"
            .text:0x00016086    B8EE400A             vcvt.f32.u32 s0, s0
            .text:0x0001608A    D1ED020A             vldr s1, [r1, #0x8]
            .text:0x0001608E    4949                 ldr r1, [_0x0803E4DC]
            .text:0x00016090    01EB8000             add.w r0, r1, r0, lsl #0x2
            .text:0x00016094    20EE200A             vmul.f32 s0, s0, s1
            .text:0x00016098    D0ED000A             vldr s1, [r0]
            .text:0x0001609C    20EE200A             vmul.f32 s0, s0, s1
            .text:0x000160A0    BCEEC00A             vcvt.u32.f32 s0, s0
            .text:0x000160A4    10EE100A             vmov r0, s0
            .text:0x000160A8    80B2                 uxth r0, r0
            .text:0x000160AA    B0F5805F             cmp.w r0, #0x1000
            .text:0x000160AE    01D3                 blo code_0x160B4
            */
fp = *( string_dT + "dT" );
r1 = *( local_0x28 );
r1 = *( fp + r1 << 0x2 );
s0 = r1;
r1 = *( string_h_6 + "h" );
s0 = (float) s0;
s1 = *( r1 + 0x8 );
r1 = *( _0x0803E4DC );
r0 = r1 + (r0 << 0x2);
s0 = s0 * s1;
s1 = *( r0 );
s0 = s0 * s1;
s0 = (unsigned int) s0;
r0 = s0;
r0 = (unsigned int) r0;
            if (r0 >= 0x1000) {
              /* 
              .text:0x000160B0 code_0x160B0:
              .text:0x000160B0    40F6FF70             movw r0, #0xFFF
              */
r0 = 0xFFF;
            }
            /* 
            .text:0x000160B4 code_0x160B4:
            .text:0x000160B4    8008                 lsrs r0, r0, #0x2
            .text:0x000160B6    F1F739FE             bl get_point_on_2A024_curve; int __cdecl( int p1 )
            .text:0x000160BA    9DF80010             ldrb.w r1, [local_0x28]
            .text:0x000160BE    9DF80020             ldrb.w r2, [local_0x28]
            .text:0x000160C2    8907                 lsls r1, r1, #0x1E
            .text:0x000160C4    490F                 lsrs r1, r1, #0x1D
            .text:0x000160C6    08EB9203             add.w r3, r8, r2, lsr #0x2
            .text:0x000160CA    0246                 mov r2, r0
            .text:0x000160CC    1846                 mov r0, r3
            .text:0x000160CE    F3F7A3FF             bl play_note_in_mem_on_voice_p1_note_p2_vol_p3; void __cdecl( int p1, int p2, int p3 )
            .text:0x000160D2    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x000160D6    04EB8000             add.w r0, r4, r0, lsl #0x2
            .text:0x000160DA    90ED080A             vldr s0, [r0, #0x20]
            .text:0x000160DE    BCEEC00A             vcvt.u32.f32 s0, s0
            .text:0x000160E2    10EE100A             vmov r0, s0
            .text:0x000160E6    80B2                 uxth r0, r0
            .text:0x000160E8    B0F5805F             cmp.w r0, #0x1000
            .text:0x000160EC    01D3                 blo code_0x160F2
            */
r0 = r0 >> 0x2;
r0 = get_point_on_2A024_curve(r0);
r1 = *( local_0x28 );
r2 = *( local_0x28 );
r1 = r1 << 0x1E;
r1 = r1 >> 0x1D;
r3 = r8 + (r2 >> 0x2);
r2 = r0;
r0 = r3;
play_note_in_mem_on_voice_p1_note_p2_vol_p3(r0,r1,r2);
r0 = *( local_0x28 );
r0 = r4 + (r0 << 0x2);
s0 = *( r0 + 0x20 );
s0 = (unsigned int) s0;
r0 = s0;
r0 = (unsigned int) r0;
            if (r0 >= 0x1000) {
              /* 
              .text:0x000160EE code_0x160EE:
              .text:0x000160EE    40F6FF70             movw r0, #0xFFF
              */
r0 = 0xFFF;
            }
            /* 
            .text:0x000160F2 code_0x160F2:
            .text:0x000160F2    9DF80010             ldrb.w r1, [local_0x28]
            .text:0x000160F6    0BEB8101             add.w r1, fp, r1, lsl #0x2
            .text:0x000160FA    4988                 ldrh r1, [r1, #0x2]
            .text:0x000160FC    00EE101A             vmov s0, r1
            .text:0x00016100    2949                 ldr r1, [string_h_6]; "h"
            .text:0x00016102    B8EE400A             vcvt.f32.u32 s0, s0
            .text:0x00016106    D1ED020A             vldr s1, [r1, #0x8]
            .text:0x0001610A    2A49                 ldr r1, [_0x0803E4DC]
            .text:0x0001610C    01EB8000             add.w r0, r1, r0, lsl #0x2
            .text:0x00016110    20EE200A             vmul.f32 s0, s0, s1
            .text:0x00016114    D0ED000A             vldr s1, [r0]
            .text:0x00016118    20EE200A             vmul.f32 s0, s0, s1
            .text:0x0001611C    BCEEC00A             vcvt.u32.f32 s0, s0
            .text:0x00016120    10EE100A             vmov r0, s0
            .text:0x00016124    80B2                 uxth r0, r0
            .text:0x00016126    B0F5805F             cmp.w r0, #0x1000
            .text:0x0001612A    01D3                 blo code_0x16130
            */
r1 = *( local_0x28 );
r1 = fp + (r1 << 0x2);
r1 = *( r1 + 0x2 );
s0 = r1;
r1 = *( string_h_6 + "h" );
s0 = (float) s0;
s1 = *( r1 + 0x8 );
r1 = *( _0x0803E4DC );
r0 = r1 + (r0 << 0x2);
s0 = s0 * s1;
s1 = *( r0 );
s0 = s0 * s1;
s0 = (unsigned int) s0;
r0 = s0;
r0 = (unsigned int) r0;
            if (r0 >= 0x1000) {
              /* 
              .text:0x0001612C code_0x1612C:
              .text:0x0001612C    40F6FF70             movw r0, #0xFFF
              */
r0 = 0xFFF;
            }
            /* 
            .text:0x00016130 code_0x16130:
            .text:0x00016130    8008                 lsrs r0, r0, #0x2
            .text:0x00016132    F1F7FBFD             bl get_point_on_2A024_curve; int __cdecl( int p1 )
            .text:0x00016136    0246                 mov r2, r0
            .text:0x00016138    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x0001613C    00F00300             and r0, r0, #0x3
            .text:0x00016140    0AEB4001             add.w r1, sl, r0, lsl #0x1
            .text:0x00016144    9DF80000             ldrb.w r0, [local_0x28]
            .text:0x00016148    08EB9000             add.w r0, r8, r0, lsr #0x2
            .text:0x0001614C    00E0                 b code_0x16150
            */
r0 = r0 >> 0x2;
r0 = get_point_on_2A024_curve(r0);
r2 = r0;
r0 = *( local_0x28 );
r0 = r0 & 0x3;
r1 = sl + (r0 << 0x1);
r0 = *( local_0x28 );
r0 = r8 + (r0 >> 0x2);
            /* 
            .text:0x00016150 code_0x16150:
            .text:0x00016150    F3F762FF             bl play_note_in_mem_on_voice_p1_note_p2_vol_p3; void __cdecl( int p1, int p2, int p3 )
            .text:0x00016154    77E7                 b code_0x16046
            */
play_note_in_mem_on_voice_p1_note_p2_vol_p3(r0,r1,r2);
          }
          /*
          .text:0x00016046 code_0x16046:
          .text:0x00016046    5948                 ldr r0, [data_0x161AC]
          .text:0x00016048    9DF80010             ldrb.w r1, [local_0x28]
          .text:0x0001604C    415C                 ldrb r1, [r0, r1]
          .text:0x0001604E    0129                 cmp r1, #0x1
          .text:0x00016050    7DD0                 beq code_0x1614E
          */
r0 = *( data_0x161AC );
r1 = *( local_0x28 );
r1 = *( r0 + r1 );
          /* 
          .text:0x00016052 code_0x16052:
          .text:0x00016052    83E0                 b code_0x1615C
          */
          if (r1 == 1) {
            /* 
            .text:0x0001614E code_0x1614E:
            .text:0x0001614E    02E0                 b code_0x16156
            */
            /* 
            .text:0x00016156 code_0x16156:
            .text:0x00016156    9DF80010             ldrb.w r1, [local_0x28]
            .text:0x0001615A    4554                 strb r5, [r0, r1]
            */
r1 = *( local_0x28 );
*( r0 + r1 ) = r5;
          }
          /* 
          .text:0x0001615C code_0x1615C:
          .text:0x0001615C    9DF80010             ldrb.w r1, [local_0x28]
          .text:0x00016160    405C                 ldrb r0, [r0, r1]
          .text:0x00016162    9DF80010             ldrb.w r1, [local_0x28]
          .text:0x00016166    ECF753FA             bl func_0x2610; __int64 __cdecl( int p1, int p2 )
          .text:0x0001616A    7F28                 cmp r0, #0x7F
          .text:0x0001616C    00D9                 bls code_0x16170
          */
r1 = *( local_0x28 );
r0 = *( r0 + r1 );
r1 = *( local_0x28 );
r0 = func_0x2610(r0,r1);
          if (r0 > 0x7F) {
            /* 
            .text:0x0001616E code_0x1616E:
            .text:0x0001616E    7F20                 movs r0, #0x7F
            */
r0 = 0x7F;
          }
          /*
          .text:0x00016170 code_0x16170:
          .text:0x00016170    1149                 ldr r1, [_0x08042D24]
          .text:0x00016172    01EB8000             add.w r0, r1, r0, lsl #0x2
          .text:0x00016176    9DF80010             ldrb.w r1, [local_0x28]
          .text:0x0001617A    90ED000A             vldr s0, [r0]
          .text:0x0001617E    0F48                 ldr r0, [_0x20005484]
          .text:0x00016180    00EB8100             add.w r0, r0, r1, lsl #0x2
          .text:0x00016184    80ED000A             vstr s0, [r0]
          .text:0x00016188    9DF80000             ldrb.w r0, [local_0x28]
          .text:0x0001618C    401C                 adds r0, r0, #0x1
          .text:0x0001618E    0090                 str r0, [local_0x28]
          .text:0x00016190    F5F722FC             bl two_or_four_or_with_20000F30; int __cdecl( void )
          .text:0x00016194    9DF80010             ldrb.w r1, [local_0x28]
          .text:0x00016198    8842                 cmp r0, r1
          .text:0x0001619A    3FF656AA             bhi.w code_0x1564A
          */
r1 = *( _0x08042D24 );
r0 = r1 + (r0 << 0x2);
r1 = *( local_0x28 );
s0 = *( r0 );
r0 = *( _0x20005484 );
r0 = r0 + (r1 << 0x2);
*( r0 ) = s0;
r0 = *( local_0x28 );
r0 = r0 + 0x1;
*( local_0x28 ) = r0;
r0 = two_or_four_or_with_20000F30(r0);
r1 = *( local_0x28 );
          if (r0 < r1) {
            break;
          }
        }
    }
    /*
    .text:0x0001619E code_0x1619E:
    .text:0x0001619E    01B0                 add sp, #0x4
    .text:0x000161A0    BDEC068B             vpop {d8, d9, d10}
    .text:0x000161A4    BDE8F08F             pop.w {r4, r5, r6, r7, r8, sb, sl, fp, pc}
    */
sp = sp + 0x4;
}
