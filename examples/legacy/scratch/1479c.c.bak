void TIM1_TRG_COM_TIM11 () { 
    /*
    .text:0x0001479C    2DE9F05F             push.w {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
    .text:0x000147A0    2DED028B             vpush {d8}
    .text:0x000147A4    0121                 movs r1, #0x1
    .text:0x000147A6    F94C                 ldr r4, [_0x40014800_3]
    .text:0x000147A8    2046                 mov r0, r4
    .text:0x000147AA    01F093FF             bl func_0x166D4; int __cdecl( int p1, int p2 )
    .text:0x000147AE    0028                 cmp r0, #0x0
    .text:0x000147B0    75D0                 beq code_0x1489E
    */   
    if (func_0x166D4(0x40014800, 1) == 0) {
        return;
    }
    /*
    .text:0x000147B2 code_0x147B2:
    .text:0x000147B2    0121                 movs r1, #0x1
    .text:0x000147B4    2046                 mov r0, r4
    .text:0x000147B6    01F0A3FE             bl func_0x16500; inline void __cdecl( int p1, int p2 )
    .text:0x000147BA    0024                 movs r4, #0x0
    .text:0x000147BC    F7F70CF9             bl two_or_four_or_with_20000F30; int __cdecl( void )
    .text:0x000147C0    0028                 cmp r0, #0x0
    .text:0x000147C2    40F29182             bls.w code_0x14CE8
    */
    
    if (two_or_four_or_with_20000F30() > 0) {
            /*
            .text:0x000147C6 code_0x147C6:
            .text:0x000147C6    DFF8C8A3             ldr.w sl, [_0x2000561C]
            .text:0x000147CA    DFEDF28A             vldr s17, [_0x440F0000]
            .text:0x000147CE    DFF8C8B3             ldr.w fp, [_0x20001FD4_9]
            .text:0x000147D2    F24F                 ldr r7, [_0x2000877C_2]
            .text:0x000147D4    0126                 movs r6, #0x1
            */

            while (1) {
                /*
                .text:0x000147D6 code_0x147D6:
                .text:0x000147D6    F248                 ldr r0, [_0x20000B78]; "x"
                .text:0x000147D8    4078                 ldrb r0, [r0, #0x1]
                .text:0x000147DA    0128                 cmp r0, #0x1
                .text:0x000147DC    7ED1                 bne code_0x148DC
                */
                cond1 = r0 == 1;
                /*    
                .text:0x000147DE code_0x147DE:
                .text:0x000147DE    DFF8C493             ldr.w sb, [_0x2000562C]; ",V"
                .text:0x000147E2    3AF81410             ldrh.w r1, [sl, r4, lsl #0x1]
                .text:0x000147E6    39F81420             ldrh.w r2, [sb, r4, lsl #0x1]
                .text:0x000147EA    9142                 cmp r1, r2
                .text:0x000147EC    76D8                 bhi code_0x148DC
                */
                cond2 = r1 <= r2;

                if (cond1 && cond2) {
                    /*
                    .text:0x000147EE code_0x147EE:
                    .text:0x000147EE    04EB4400             add.w r0, r4, r4, lsl #0x1
                    .text:0x000147F2    00EBC400             add.w r0, r0, r4, lsl #0x3
                    .text:0x000147F6    0BEB8005             add.w r5, fp, r0, lsl #0x2
                    .text:0x000147FA    6879                 ldrb r0, [r5, #0x5]
                    .text:0x000147FC    F3F72AFC             bl func_0x8054; inline void __cdecl( int p1 )
                    */

                    /*
                    .text:0x00014800    0021                 movs r1, #0x0
                    .text:0x00014802    2046                 mov r0, r4
                    .text:0x00014804    05F03CFB             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                    */
                    s0 = func_0x19E80(r4, 0);
                    /*
                    .text:0x00014808    B0EE408A             vmov.f32 s16, s0
                    .text:0x0001480C    E648                 ldr r0, [_0x20000B8B]
                    .text:0x0001480E    005D                 ldrb r0, [r0, r4]
                    .text:0x00014810    F3F720FC             bl func_0x8054; inline void __cdecl( int p1 )
                    .text:0x00014814    0021                 movs r1, #0x0
                    .text:0x00014816    2046                 mov r0, r4
                    .text:0x00014818    05F032FB             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                    */
                    s0 = func_0x19E80(0, r4);
                    /*
                    .text:0x0001481C    78EE400A             vsub.f32 s1, s16, s0
                    .text:0x00014820    A9F13000             sub.w r0, sb, #0x30
                    .text:0x00014824    00EB8408             add.w r8, r0, r4, lsl #0x2
                    .text:0x00014828    3030                 adds r0, #0x30
                    .text:0x0001482A    98ED002A             vldr s4, [r8]
                    .text:0x0001482E    30F81400             ldrh.w r0, [r0, r4, lsl #0x1]
                    .text:0x00014832    3AF81410             ldrh.w r1, [sl, r4, lsl #0x1]
                    .text:0x00014836    01EE100A             vmov s2, r0
                    .text:0x0001483A    DB4A                 ldr r2, [_0x20000B8B]
                    .text:0x0001483C    B8EE411A             vcvt.f32.u32 s2, s2
                    .text:0x00014840    125D                 ldrb r2, [r2, r4]
                    .text:0x00014842    C2EE011A             vdiv.f32 s3, s4, s2
                    .text:0x00014846    01EE101A             vmov s2, r1
                    .text:0x0001484A    B8EE411A             vcvt.f32.u32 s2, s2
                    .text:0x0001484E    21EE811A             vmul.f32 s2, s3, s2
                    .text:0x00014852    BDEEC11A             vcvt.s32.f32 s2, s2
                    .text:0x00014856    11EE103A             vmov r3, s2
                    .text:0x0001485A    42FA83F2             sxtab r2, r2, r3
                    .text:0x0001485E    D34B                 ldr r3, [_0x20000B83]
                    .text:0x00014860    1A55                 strb r2, [r3, r4]
                    .text:0x00014862    58B1                 cbz r0, code_0x1487C
                    */

                    if (r0 != 0) {
                        /*
                        .text:0x00014864 code_0x14864:
                        .text:0x00014864    01EE100A             vmov s2, r0
                        .text:0x00014868    F8EE411A             vcvt.f32.u32 s3, s2
                        .text:0x0001486C    80EEA11A             vdiv.f32 s2, s1, s3
                        .text:0x00014870    00EE901A             vmov s1, r1
                        .text:0x00014874    F8EE600A             vcvt.f32.u32 s1, s1
                        .text:0x00014878    01EE200A             vmla.f32 s0, s2, s1
                        */
                    }
                    /*
                    .text:0x0001487C code_0x1487C:
                    .text:0x0001487C    CC48                 ldr r0, [_0x20005088_1]
                    .text:0x0001487E    00EB8409             add.w sb, r0, r4, lsl #0x2
                    .text:0x00014882    D9ED000A             vldr s1, [sb]
                    .text:0x00014886    F5EEC00A             vcmpe.f32 s1, #0x0
                    .text:0x0001488A    F1EE10FA             vmrs APSR_nzcv, fpscr
                    .text:0x0001488E    07D1                 bne code_0x148A0
                    */

                    if (s1 == 0.0) {
                        /*
                        .text:0x00014890 code_0x14890:
                        .text:0x00014890    E007                 lsls r0, r4, #0x1F
                        .text:0x00014892    810F                 lsrs r1, r0, #0x1E
                        .text:0x00014894    6008                 lsrs r0, r4, #0x1
                        .text:0x00014896    0022                 movs r2, #0x0
                        .text:0x00014898    F5F7ECF9             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                        .text:0x0001489C    0CE0                 b code_0x148B8
                        */
                    } else {
                        /*
                        .text:0x000148A0 code_0x148A0:
                        .text:0x000148A0    6006                 lsls r0, r4, #0x19
                        .text:0x000148A2    000E                 lsrs r0, r0, #0x18
                        .text:0x000148A4    08F088FD             bl func_0x1D3B8; int __cdecl( int p1 )
                        .text:0x000148A8    37F92410             ldrsh.w r1, [r7, r4, lsl #0x2]
                        .text:0x000148AC    4218                 adds r2, r0, r1
                        .text:0x000148AE    E007                 lsls r0, r4, #0x1F
                        .text:0x000148B0    810F                 lsrs r1, r0, #0x1E
                        .text:0x000148B2    6008                 lsrs r0, r4, #0x1
                        .text:0x000148B4    F5F7DEF9             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                        */
                    }
                    /*
                    .text:0x000148B8 code_0x148B8:
                    .text:0x000148B8    6879                 ldrb r0, [r5, #0x5]
                    .text:0x000148BA    F3F7CBFB             bl func_0x8054; inline void __cdecl( int p1 )
                    .text:0x000148BE    0121                 movs r1, #0x1
                    .text:0x000148C0    2046                 mov r0, r4
                    .text:0x000148C2    05F0DDFA             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                    .text:0x000148C6    B0EE408A             vmov.f32 s16, s0
                    .text:0x000148CA    B74D                 ldr r5, [_0x20000B8B]
                    .text:0x000148CC    285D                 ldrb r0, [r5, r4]
                    .text:0x000148CE    F3F7C1FB             bl func_0x8054; inline void __cdecl( int p1 )
                    .text:0x000148D2    0121                 movs r1, #0x1
                    .text:0x000148D4    2046                 mov r0, r4
                    .text:0x000148D6    05F0D3FA             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                    .text:0x000148DA    00E0                 b code_0x148DE
                    */
                    /*
                    .text:0x000148DE code_0x148DE:
                    .text:0x000148DE    78EE400A             vsub.f32 s1, s16, s0
                    .text:0x000148E2    B048                 ldr r0, [_0x2000562C]; ",V"
                    .text:0x000148E4    D8ED001A             vldr s3, [r8]
                    .text:0x000148E8    3AF81410             ldrh.w r1, [sl, r4, lsl #0x1]
                    .text:0x000148EC    30F81400             ldrh.w r0, [r0, r4, lsl #0x1]
                    .text:0x000148F0    2B5D                 ldrb r3, [r5, r4]
                    .text:0x000148F2    01EE100A             vmov s2, r0
                    .text:0x000148F6    B8EE411A             vcvt.f32.u32 s2, s2
                    .text:0x000148FA    81EE812A             vdiv.f32 s4, s3, s2
                    .text:0x000148FE    01EE101A             vmov s2, r1
                    .text:0x00014902    B8EE411A             vcvt.f32.u32 s2, s2
                    .text:0x00014906    22EE011A             vmul.f32 s2, s4, s2
                    .text:0x0001490A    BDEEC11A             vcvt.s32.f32 s2, s2
                    .text:0x0001490E    11EE102A             vmov r2, s2
                    .text:0x00014912    43FA82F2             sxtab r2, r3, r2
                    .text:0x00014916    A5F10803             sub.w r3, r5, #0x8
                    .text:0x0001491A    1A55                 strb r2, [r3, r4]
                    .text:0x0001491C    58B1                 cbz r0, code_0x14936
                    */

                    if (r0 != 0) {
                        /*
                        .text:0x0001491E code_0x1491E:
                        .text:0x0001491E    01EE100A             vmov s2, r0
                        .text:0x00014922    F8EE411A             vcvt.f32.u32 s3, s2
                        .text:0x00014926    80EEA11A             vdiv.f32 s2, s1, s3
                        .text:0x0001492A    00EE901A             vmov s1, r1
                        .text:0x0001492E    F8EE600A             vcvt.f32.u32 s1, s1
                        .text:0x00014932    01EE200A             vmla.f32 s0, s2, s1
                        */
                    }
                    /*
                    .text:0x00014936 code_0x14936:
                    .text:0x00014936    D9ED080A             vldr s1, [sb, #0x20]
                    .text:0x0001493A    F5EEC00A             vcmpe.f32 s1, #0x0
                    .text:0x0001493E    F1EE10FA             vmrs APSR_nzcv, fpscr
                    .text:0x00014942    08D1                 bne code_0x14956
                    */

                    if (s1 == 0) {
                        /*
                        .text:0x00014944 code_0x14944:
                        .text:0x00014944    04F00100             and r0, r4, #0x1
                        .text:0x00014948    06EB4001             add.w r1, r6, r0, lsl #0x1
                        .text:0x0001494C    6008                 lsrs r0, r4, #0x1
                        .text:0x0001494E    0022                 movs r2, #0x0
                        .text:0x00014950    F5F790F9             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                        .text:0x00014954    0EE0                 b code_0x14974
                        */
                    } else {
                        /*
                        .text:0x00014956 code_0x14956:
                        .text:0x00014956    06EB4403             add.w r3, r6, r4, lsl #0x1
                        .text:0x0001495A    D8B2                 uxtb r0, r3
                        .text:0x0001495C    08F02CFD             bl func_0x1D3B8; int __cdecl( int p1 )
                        .text:0x00014960    37F91310             ldrsh.w r1, [r7, r3, lsl #0x1]
                        .text:0x00014964    4218                 adds r2, r0, r1
                        .text:0x00014966    04F00100             and r0, r4, #0x1
                        .text:0x0001496A    06EB4001             add.w r1, r6, r0, lsl #0x1
                        .text:0x0001496E    6008                 lsrs r0, r4, #0x1
                        .text:0x00014970    F5F780F9             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                        */
                    }
                    /*
                    .text:0x00014974 code_0x14974:
                    .text:0x00014974    3AF81400             ldrh.w r0, [sl, r4, lsl #0x1]
                    .text:0x00014978    401C                 adds r0, r0, #0x1
                    .text:0x0001497A    2AF81400             strh.w r0, [sl, r4, lsl #0x1]
                    .text:0x0001497E    00F0ACB9             b.w code_0x14CDA
                    */
                } else {
                    /*
                    .text:0x000148DC code_0x148DC:
                    .text:0x000148DC    51E0                 b code_0x14982
                    .text:0x00014982 code_0x14982:
                    .text:0x00014982    0228                 cmp r0, #0x2
                    .text:0x00014984    7ED1                 bne code_0x14A84
                    */
                    cond1 = r0 == 2;
                    /*
                    .text:0x00014986 code_0x14986:
                    .text:0x00014986    874A                 ldr r2, [_0x2000562C]; ",V"
                    .text:0x00014988    3AF81400             ldrh.w r0, [sl, r4, lsl #0x1]
                    .text:0x0001498C    32F81410             ldrh.w r1, [r2, r4, lsl #0x1]
                    .text:0x00014990    8842                 cmp r0, r1
                    .text:0x00014992    77D8                 bhi code_0x14A84
                    */
                    cond2 = r0 <= r1;
                    if (cond1 && cond2) {
                        /*
                        .text:0x00014994 code_0x14994:
                        .text:0x00014994    00EE101A             vmov s0, r1
                        .text:0x00014998    A2F13003             sub.w r3, r2, #0x30
                        .text:0x0001499C    03EB8405             add.w r5, r3, r4, lsl #0x2
                        .text:0x000149A0    B8EE400A             vcvt.f32.u32 s0, s0
                        .text:0x000149A4    D5ED000A             vldr s1, [r5]
                        .text:0x000149A8    DFF8FC91             ldr.w sb, [_0x20000B8B]
                        .text:0x000149AC    80EE801A             vdiv.f32 s2, s1, s0
                        .text:0x000149B0    00EE100A             vmov s0, r0
                        .text:0x000149B4    19F80410             ldrb.w r1, [sb, r4]
                        .text:0x000149B8    B8EE400A             vcvt.f32.u32 s0, s0
                        .text:0x000149BC    21EE000A             vmul.f32 s0, s2, s0
                        .text:0x000149C0    BDEEC00A             vcvt.s32.f32 s0, s0
                        .text:0x000149C4    10EE100A             vmov r0, s0
                        .text:0x000149C8    41FA80F0             sxtab r0, r1, r0
                        .text:0x000149CC    A9F10801             sub.w r1, sb, #0x8
                        .text:0x000149D0    0855                 strb r0, [r1, r4]
                        .text:0x000149D2    04EB4400             add.w r0, r4, r4, lsl #0x1
                        .text:0x000149D6    00EBC400             add.w r0, r0, r4, lsl #0x3
                        .text:0x000149DA    0BEB8008             add.w r8, fp, r0, lsl #0x2
                        .text:0x000149DE    98F80500             ldrb.w r0, [r8, #0x5]
                        .text:0x000149E2    F3F737FB             bl func_0x8054; inline void __cdecl( int p1 )
                        .text:0x000149E6    0021                 movs r1, #0x0
                        .text:0x000149E8    2046                 mov r0, r4
                        .text:0x000149EA    05F049FA             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                        .text:0x000149EE    19F80400             ldrb.w r0, [sb, r4]
                        .text:0x000149F2    F3F72FFB             bl func_0x8054; inline void __cdecl( int p1 )
                        .text:0x000149F6    0021                 movs r1, #0x0
                        .text:0x000149F8    2046                 mov r0, r4
                        .text:0x000149FA    05F041FA             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                        .text:0x000149FE    6948                 ldr r0, [_0x2000562C]; ",V"
                        .text:0x00014A00    30F81400             ldrh.w r0, [r0, r4, lsl #0x1]
                        .text:0x00014A04    D0B1                 cbz r0, code_0x14A3C
                        */

                        if (r0 != 0) {
                            /*
                            .text:0x00014A06 code_0x14A06:
                            .text:0x00014A06    00EE900A             vmov s1, r0
                            .text:0x00014A0A    95ED001A             vldr s2, [r5]
                            .text:0x00014A0E    3AF81400             ldrh.w r0, [sl, r4, lsl #0x1]
                            .text:0x00014A12    F8EE600A             vcvt.f32.u32 s1, s1
                            .text:0x00014A16    C1EE201A             vdiv.f32 s3, s2, s1
                            .text:0x00014A1A    00EE900A             vmov s1, r0
                            .text:0x00014A1E    F8EE600A             vcvt.f32.u32 s1, s1
                            .text:0x00014A22    61EEA00A             vmul.f32 s1, s3, s1
                            .text:0x00014A26    FDEEE00A             vcvt.s32.f32 s1, s1
                            .text:0x00014A2A    10EE900A             vmov r0, s1
                            .text:0x00014A2E    40B2                 sxtb r0, r0
                            .text:0x00014A30    00EE900A             vmov s1, r0
                            .text:0x00014A34    F8EEE00A             vcvt.f32.s32 s1, s1
                            .text:0x00014A38    30EE800A             vadd.f32 s0, s1, s0
                            */
                        }
                        /*
                        .text:0x00014A3C code_0x14A3C:
                        .text:0x00014A3C    5C48                 ldr r0, [_0x20005088_1]
                        .text:0x00014A3E    00EB8409             add.w sb, r0, r4, lsl #0x2
                        .text:0x00014A42    D9ED000A             vldr s1, [sb]
                        .text:0x00014A46    F5EEC00A             vcmpe.f32 s1, #0x0
                        .text:0x00014A4A    F1EE10FA             vmrs APSR_nzcv, fpscr
                        .text:0x00014A4E    06D1                 bne code_0x14A5E
                        */

                        if (s1 == 0.0) {
                            /*
                            .text:0x00014A50 code_0x14A50:
                            .text:0x00014A50    E007                 lsls r0, r4, #0x1F
                            .text:0x00014A52    810F                 lsrs r1, r0, #0x1E
                            .text:0x00014A54    6008                 lsrs r0, r4, #0x1
                            .text:0x00014A56    0022                 movs r2, #0x0
                            .text:0x00014A58    F5F70CF9             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                            .text:0x00014A5C    0BE0                 b code_0x14A76
                            */
                        } else {
                            /*
                            .text:0x00014A5E code_0x14A5E:
                            .text:0x00014A5E    6006                 lsls r0, r4, #0x19
                            .text:0x00014A60    000E                 lsrs r0, r0, #0x18
                            .text:0x00014A62    08F0A9FC             bl func_0x1D3B8; int __cdecl( int p1 )
                            .text:0x00014A66    37F92410             ldrsh.w r1, [r7, r4, lsl #0x2]
                            .text:0x00014A6A    4218                 adds r2, r0, r1
                            .text:0x00014A6C    E007                 lsls r0, r4, #0x1F
                            .text:0x00014A6E    810F                 lsrs r1, r0, #0x1E
                            .text:0x00014A70    6008                 lsrs r0, r4, #0x1
                            .text:0x00014A72    F5F7FFF8             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                            */
                        }
                        /*
                        .text:0x00014A76 code_0x14A76:
                        .text:0x00014A76    98F80500             ldrb.w r0, [r8, #0x5]
                        .text:0x00014A7A    F3F7EBFA             bl func_0x8054; inline void __cdecl( int p1 )
                        .text:0x00014A7E    0121                 movs r1, #0x1
                        .text:0x00014A80    2046                 mov r0, r4
                        .text:0x00014A82    00E0                 b code_0x14A86
                        .text:0x00014A86 code_0x14A86:
                        .text:0x00014A86    05F0FBF9             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                        .text:0x00014A8A    4748                 ldr r0, [_0x20000B8B]
                        .text:0x00014A8C    005D                 ldrb r0, [r0, r4]
                        .text:0x00014A8E    F3F7E1FA             bl func_0x8054; inline void __cdecl( int p1 )
                        .text:0x00014A92    0121                 movs r1, #0x1
                        .text:0x00014A94    2046                 mov r0, r4
                        .text:0x00014A96    05F0F3F9             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                        .text:0x00014A9A    4248                 ldr r0, [_0x2000562C]; ",V"
                        .text:0x00014A9C    30F81400             ldrh.w r0, [r0, r4, lsl #0x1]
                        .text:0x00014AA0    D0B1                 cbz r0, code_0x14AD8
                        */

                        if (r0 != 0) {
                            /*
                            .text:0x00014AA2 code_0x14AA2:
                            .text:0x00014AA2    00EE900A             vmov s1, r0
                            .text:0x00014AA6    D5ED001A             vldr s3, [r5]
                            .text:0x00014AAA    3AF81400             ldrh.w r0, [sl, r4, lsl #0x1]
                            .text:0x00014AAE    F8EE600A             vcvt.f32.u32 s1, s1
                            .text:0x00014AB2    81EEA01A             vdiv.f32 s2, s3, s1
                            .text:0x00014AB6    00EE900A             vmov s1, r0
                            .text:0x00014ABA    F8EE600A             vcvt.f32.u32 s1, s1
                            .text:0x00014ABE    61EE200A             vmul.f32 s1, s2, s1
                            .text:0x00014AC2    FDEEE00A             vcvt.s32.f32 s1, s1
                            .text:0x00014AC6    10EE900A             vmov r0, s1
                            .text:0x00014ACA    40B2                 sxtb r0, r0
                            .text:0x00014ACC    00EE900A             vmov s1, r0
                            .text:0x00014AD0    F8EEE00A             vcvt.f32.s32 s1, s1
                            .text:0x00014AD4    30EE800A             vadd.f32 s0, s1, s0
                            */
                        }
                        /*
                        .text:0x00014AD8 code_0x14AD8:
                        .text:0x00014AD8    D9ED080A             vldr s1, [sb, #0x20]
                        .text:0x00014ADC    F5EEC00A             vcmpe.f32 s1, #0x0
                        .text:0x00014AE0    F1EE10FA             vmrs APSR_nzcv, fpscr
                        .text:0x00014AE4    08D1                 bne code_0x14AF8
                        */
                        if (s1 == 0.0) {
                            /*
                            .text:0x00014AE6 code_0x14AE6:
                            .text:0x00014AE6    04F00100             and r0, r4, #0x1
                            .text:0x00014AEA    06EB4001             add.w r1, r6, r0, lsl #0x1
                            .text:0x00014AEE    6008                 lsrs r0, r4, #0x1
                            .text:0x00014AF0    0022                 movs r2, #0x0
                            .text:0x00014AF2    F5F7BFF8             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                            .text:0x00014AF6    0EE0                 b code_0x14B16
                            */
                        } else {
                            /*
                            .text:0x00014AF8 code_0x14AF8:
                            .text:0x00014AF8    06EB4403             add.w r3, r6, r4, lsl #0x1
                            .text:0x00014AFC    D8B2                 uxtb r0, r3
                            .text:0x00014AFE    08F05BFC             bl func_0x1D3B8; int __cdecl( int p1 )
                            .text:0x00014B02    37F91310             ldrsh.w r1, [r7, r3, lsl #0x1]
                            .text:0x00014B06    4218                 adds r2, r0, r1
                            .text:0x00014B08    04F00100             and r0, r4, #0x1
                            .text:0x00014B0C    06EB4001             add.w r1, r6, r0, lsl #0x1
                            .text:0x00014B10    6008                 lsrs r0, r4, #0x1
                            .text:0x00014B12    F5F7AFF8             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                            */
                        }

                        /*
                        .text:0x00014B16 code_0x14B16:
                        .text:0x00014B16    3AF81400             ldrh.w r0, [sl, r4, lsl #0x1]
                        .text:0x00014B1A    401C                 adds r0, r0, #0x1
                        .text:0x00014B1C    2AF81400             strh.w r0, [sl, r4, lsl #0x1]
                        .text:0x00014B20    DBE0                 b code_0x14CDA
                        */
                    } else {
                        /*
                        .text:0x00014A84 code_0x14A84:
                        .text:0x00014A84    4DE0                 b code_0x14B22
                        .text:0x00014B22 code_0x14B22:
                        .text:0x00014B22    DFF89080             ldr.w r8, [data_0x14BB4]
                        .text:0x00014B26    38F81410             ldrh.w r1, [r8, r4, lsl #0x1]
                        .text:0x00014B2A    0029                 cmp r1, #0x0
                        .text:0x00014B2C    72D0                 beq code_0x14C14
                        */
                        if (r1 != 0) {
                            /*
                            .text:0x00014B2E code_0x14B2E:
                            .text:0x00014B2E    04EB4400             add.w r0, r4, r4, lsl #0x1
                            .text:0x00014B32    00EBC400             add.w r0, r0, r4, lsl #0x3
                            .text:0x00014B36    0BEB8009             add.w sb, fp, r0, lsl #0x2
                            .text:0x00014B3A    1C4A                 ldr r2, [_0x20000B83]
                            .text:0x00014B3C    99F80500             ldrb.w r0, [sb, #0x5]
                            .text:0x00014B40    1055                 strb r0, [r2, r4]
                            .text:0x00014B42    491E                 subs r1, r1, #0x1
                            .text:0x00014B44    28F81410             strh.w r1, [r8, r4, lsl #0x1]
                            .text:0x00014B48    F3F784FA             bl func_0x8054; inline void __cdecl( int p1 )
                            .text:0x00014B4C    0021                 movs r1, #0x0
                            .text:0x00014B4E    2046                 mov r0, r4
                            .text:0x00014B50    05F096F9             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                            .text:0x00014B54    38F81400             ldrh.w r0, [r8, r4, lsl #0x1]
                            .text:0x00014B58    00EE900A             vmov s1, r0
                            .text:0x00014B5C    B8EE601A             vcvt.f32.u32 s2, s1
                            .text:0x00014B60    C1EE280A             vdiv.f32 s1, s2, s17
                            .text:0x00014B64    30EE600A             vsub.f32 s0, s0, s1
                            .text:0x00014B68    1148                 ldr r0, [_0x20005088_1]
                            .text:0x00014B6A    00EB8405             add.w r5, r0, r4, lsl #0x2
                            .text:0x00014B6E    D5ED000A             vldr s1, [r5]
                            .text:0x00014B72    F5EEC00A             vcmpe.f32 s1, #0x0
                            .text:0x00014B76    F1EE10FA             vmrs APSR_nzcv, fpscr
                            .text:0x00014B7A    1DD1                 bne code_0x14BB8
                            */
                            if (s1 == 0.0) {
                                /*
                                .text:0x00014B7C code_0x14B7C:
                                .text:0x00014B7C    E007                 lsls r0, r4, #0x1F
                                .text:0x00014B7E    810F                 lsrs r1, r0, #0x1E
                                .text:0x00014B80    6008                 lsrs r0, r4, #0x1
                                .text:0x00014B82    0022                 movs r2, #0x0
                                .text:0x00014B84    F5F776F8             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                                .text:0x00014B88    22E0                 b code_0x14BD0
                                */
                            } else {
                                /*
                                .text:0x00014BB8 code_0x14BB8:
                                .text:0x00014BB8    6006                 lsls r0, r4, #0x19
                                .text:0x00014BBA    000E                 lsrs r0, r0, #0x18
                                .text:0x00014BBC    08F0FCFB             bl func_0x1D3B8; int __cdecl( int p1 )
                                .text:0x00014BC0    37F92410             ldrsh.w r1, [r7, r4, lsl #0x2]
                                .text:0x00014BC4    4218                 adds r2, r0, r1
                                .text:0x00014BC6    E007                 lsls r0, r4, #0x1F
                                .text:0x00014BC8    810F                 lsrs r1, r0, #0x1E
                                .text:0x00014BCA    6008                 lsrs r0, r4, #0x1
                                .text:0x00014BCC    F5F752F8             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                                */
                            }
                            /*
                            .text:0x00014BD0 code_0x14BD0:
                            .text:0x00014BD0    99F80500             ldrb.w r0, [sb, #0x5]
                            .text:0x00014BD4    F3F73EFA             bl func_0x8054; inline void __cdecl( int p1 )
                            .text:0x00014BD8    0121                 movs r1, #0x1
                            .text:0x00014BDA    2046                 mov r0, r4
                            .text:0x00014BDC    05F050F9             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                            .text:0x00014BE0    38F81400             ldrh.w r0, [r8, r4, lsl #0x1]
                            .text:0x00014BE4    00EE900A             vmov s1, r0
                            .text:0x00014BE8    B8EE601A             vcvt.f32.u32 s2, s1
                            .text:0x00014BEC    C1EE280A             vdiv.f32 s1, s2, s17
                            .text:0x00014BF0    30EE600A             vsub.f32 s0, s0, s1
                            .text:0x00014BF4    D5ED080A             vldr s1, [r5, #0x20]
                            .text:0x00014BF8    F5EEC00A             vcmpe.f32 s1, #0x0
                            .text:0x00014BFC    F1EE10FA             vmrs APSR_nzcv, fpscr
                            .text:0x00014C00    09D1                 bne code_0x14C16
                            */

                            if (s1 == 0.0) {
                                /*
                                .text:0x00014C02 code_0x14C02:
                                .text:0x00014C02    04F00100             and r0, r4, #0x1
                                .text:0x00014C06    06EB4001             add.w r1, r6, r0, lsl #0x1
                                .text:0x00014C0A    6008                 lsrs r0, r4, #0x1
                                .text:0x00014C0C    0022                 movs r2, #0x0
                                .text:0x00014C0E    F5F731F8             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                                .text:0x00014C12    62E0                 b code_0x14CDA
                                */
                            } else {
                                /*
                                .text:0x00014C16 code_0x14C16:
                                .text:0x00014C16    06EB4403             add.w r3, r6, r4, lsl #0x1
                                .text:0x00014C1A    D8B2                 uxtb r0, r3
                                .text:0x00014C1C    08F0CCFB             bl func_0x1D3B8; int __cdecl( int p1 )
                                .text:0x00014C20    37F91310             ldrsh.w r1, [r7, r3, lsl #0x1]
                                .text:0x00014C24    4218                 adds r2, r0, r1
                                .text:0x00014C26    04F00100             and r0, r4, #0x1
                                .text:0x00014C2A    06EB4001             add.w r1, r6, r0, lsl #0x1
                                .text:0x00014C2E    6008                 lsrs r0, r4, #0x1
                                .text:0x00014C30    F5F720F8             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                                .text:0x00014C34    51E0                 b code_0x14CDA
                                */ 
                            }
                        } else {
                            /*
                            .text:0x00014C14 code_0x14C14:
                            .text:0x00014C14    0FE0                 b code_0x14C36
                            .text:0x00014C36 code_0x14C36:
                            .text:0x00014C36    04EB4400             add.w r0, r4, r4, lsl #0x1
                            .text:0x00014C3A    00EBC400             add.w r0, r0, r4, lsl #0x3
                            .text:0x00014C3E    0BEB8005             add.w r5, fp, r0, lsl #0x2
                            .text:0x00014C42    3249                 ldr r1, [_0x20000B83_1]
                            .text:0x00014C44    6879                 ldrb r0, [r5, #0x5]
                            .text:0x00014C46    0855                 strb r0, [r1, r4]
                            .text:0x00014C48    F3F704FA             bl func_0x8054; inline void __cdecl( int p1 )
                            .text:0x00014C4C    0021                 movs r1, #0x0
                            .text:0x00014C4E    2046                 mov r0, r4
                            .text:0x00014C50    05F016F9             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                            .text:0x00014C54    2E48                 ldr r0, [_0x20005088_2]
                            .text:0x00014C56    00EB8408             add.w r8, r0, r4, lsl #0x2
                            .text:0x00014C5A    D8ED000A             vldr s1, [r8]
                            .text:0x00014C5E    F5EEC00A             vcmpe.f32 s1, #0x0
                            .text:0x00014C62    F1EE10FA             vmrs APSR_nzcv, fpscr
                            .text:0x00014C66    06D1                 bne code_0x14C76
                            */

                            if (s1 == 0.0) {
                                /*
                                .text:0x00014C68 code_0x14C68:
                                .text:0x00014C68    E007                 lsls r0, r4, #0x1F
                                .text:0x00014C6A    810F                 lsrs r1, r0, #0x1E
                                .text:0x00014C6C    6008                 lsrs r0, r4, #0x1
                                .text:0x00014C6E    0022                 movs r2, #0x0
                                .text:0x00014C70    F5F700F8             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                                .text:0x00014C74    0BE0                 b code_0x14C8E
                                */

                            } else {
                                /*
                                .text:0x00014C76    6006                 lsls r0, r4, #0x19
                                .text:0x00014C78    000E                 lsrs r0, r0, #0x18
                                .text:0x00014C7A    08F09DFB             bl func_0x1D3B8; int __cdecl( int p1 )
                                .text:0x00014C7E    37F92410             ldrsh.w r1, [r7, r4, lsl #0x2]
                                .text:0x00014C82    4218                 adds r2, r0, r1
                                .text:0x00014C84    E007                 lsls r0, r4, #0x1F
                                .text:0x00014C86    810F                 lsrs r1, r0, #0x1E
                                .text:0x00014C88    6008                 lsrs r0, r4, #0x1
                                .text:0x00014C8A    F4F7F3FF             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                                */
                            }
                            /*
                            .text:0x00014C8E code_0x14C8E:
                            .text:0x00014C8E    6879                 ldrb r0, [r5, #0x5]
                            .text:0x00014C90    F3F7E0F9             bl func_0x8054; inline void __cdecl( int p1 )
                            .text:0x00014C94    0121                 movs r1, #0x1
                            .text:0x00014C96    2046                 mov r0, r4
                            .text:0x00014C98    05F0F2F8             bl func_0x19E80; void __cdecl( int p1, int p2, int p3 )
                            .text:0x00014C9C    D8ED080A             vldr s1, [r8, #0x20]
                            .text:0x00014CA0    F5EEC00A             vcmpe.f32 s1, #0x0
                            .text:0x00014CA4    F1EE10FA             vmrs APSR_nzcv, fpscr
                            .text:0x00014CA8    08D1                 bne code_0x14CBC
                            */

                            if (s1 == 0.0) {
                                /*
                                .text:0x00014CAA code_0x14CAA:
                                .text:0x00014CAA    04F00100             and r0, r4, #0x1
                                .text:0x00014CAE    06EB4001             add.w r1, r6, r0, lsl #0x1
                                .text:0x00014CB2    6008                 lsrs r0, r4, #0x1
                                .text:0x00014CB4    0022                 movs r2, #0x0
                                .text:0x00014CB6    F4F7DDFF             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                                .text:0x00014CBA    0EE0                 b code_0x14CDA
                                */
                            } else {
                                /*
                                .text:0x00014CBC code_0x14CBC:
                                .text:0x00014CBC    06EB4403             add.w r3, r6, r4, lsl #0x1
                                .text:0x00014CC0    D8B2                 uxtb r0, r3
                                .text:0x00014CC2    08F079FB             bl func_0x1D3B8; int __cdecl( int p1 )
                                .text:0x00014CC6    37F91310             ldrsh.w r1, [r7, r3, lsl #0x1]
                                .text:0x00014CCA    4218                 adds r2, r0, r1
                                .text:0x00014CCC    04F00100             and r0, r4, #0x1
                                .text:0x00014CD0    06EB4001             add.w r1, r6, r0, lsl #0x1
                                .text:0x00014CD4    6008                 lsrs r0, r4, #0x1
                                .text:0x00014CD6    F4F7CDFF             bl func_0x9C74; inline void __cdecl( int p1, int p2, int p3 )
                                */
                            }
                        }
                    }
                }
                /*
                .text:0x00014CDA code_0x14CDA:
                .text:0x00014CDA    601C                 adds r0, r4, #0x1
                .text:0x00014CDC    C4B2                 uxtb r4, r0
                .text:0x00014CDE    F6F77BFE             bl two_or_four_or_with_20000F30; int __cdecl( void )
                .text:0x00014CE2    A042                 cmp r0, r4
                .text:0x00014CE4    3FF677AD             bhi.w code_0x147D6
                */
            }
    }
    /*
    .text:0x00014CE8 code_0x14CE8:
    .text:0x00014CE8    0848                 ldr r0, [_0x20000B83_1]
    .text:0x00014CEA    A0F10B01             sub.w r1, r0, #0xB
    .text:0x00014CEE    0A78                 ldrb r2, [r1]
    .text:0x00014CF0    805C                 ldrb r0, [r0, r2]
    .text:0x00014CF2    4871                 strb r0, [r1, #0x5]
    .text:0x00014CF4    0020                 movs r0, #0x0
    .text:0x00014CF6    BDEC028B             vpop {d8}
    .text:0x00014CFA    BDE8F05F             pop.w {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
    .text:0x00014CFE    F5F79FB8             b.w func_0x9E40; void __cdecl( int p1 )
    */
    return r0;
}
