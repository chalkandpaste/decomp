
void func_0xD630( int r0, int r1, int r2,  int r3 ) {
  r0 = p1;
  r1 = p2;
  r2 = p3;
  r3 = p4;
    /*
     .text:0x0000D630 {
     .text:0x0000D630    2DE9F05F             push.w {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
     .text:0x0000D634    2DED0E8B             vpush {d8, d9, d10, d11, d12, d13, d14}
     .text:0x0000D638    5120                 movs r0, #0x51
     .text:0x0000D63A    FAF7C5FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000D63E    DFF818B4             ldr.w fp, [_0x20004CFC_8]
     .text:0x0000D642    80B1                 cbz r0, code_0xD666
     */
  if (r0 != 0) {
    /*
       .text:0x0000D644 code_0xD644:
       .text:0x0000D644    5120                 movs r0, #0x51
       .text:0x0000D646    0FF09DFD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000D64A    04F0EDFE             bl func_0x12428; void __cdecl( int p1 )
       .text:0x0000D64E    0120                 movs r0, #0x1
       .text:0x0000D650    8BF82601             strb.w r0, [fp, #0x126]
       .text:0x0000D654    8BF8A602             strb.w r0, [fp, #0x2A6]
       .text:0x0000D658    8BF8C600             strb.w r0, [fp, #0xC6]
       .text:0x0000D65C    8BF8A601             strb.w r0, [fp, #0x1A6]
       .text:0x0000D660    5120                 movs r0, #0x51
       .text:0x0000D662    F5F781FC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*  
      .text:0x0000D666 code_0xD666:
      .text:0x0000D666    1120                 movs r0, #0x11
      .text:0x0000D668    FAF7AEFF             bl func_0x85C8; inline int __cdecl( int p1 )
      .text:0x0000D66C    9FEDFBDA             vldr s26, [data_0xDA5C]
      .text:0x0000D670    DFEDFB9A             vldr s19, [_0x424A38EB]
      .text:0x0000D674    FB4E                 ldr r6, [_0x200049DC]
      .text:0x0000D676    B7EE008A             vmov.f32 s16, #1.000000e+00
      .text:0x0000D67A    9FEDFB9A             vldr s18, [_0xBF7CD6EA]
      .text:0x0000D67E    18B3                 cbz r0, code_0xD6C8
      */
  if (r0 != 0) {
    /*
       .text:0x0000D680 code_0xD680:
       .text:0x0000D680    1120                 movs r0, #0x11
       .text:0x0000D682    0FF07FFD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000D686    0001                 lsls r0, r0, #0x4
       .text:0x0000D688    00EE100A             vmov s0, r0
       .text:0x0000D68C    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000D690    20EE0D0A             vmul.f32 s0, s0, s26
       .text:0x0000D694    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000D698    10EE100A             vmov r0, s0
       .text:0x0000D69C    80B2                 uxth r0, r0
       .text:0x0000D69E    A6F84000             strh.w r0, [r6, #0x40]
       .text:0x0000D6A2    00EE100A             vmov s0, r0
       .text:0x0000D6A6    D6ED040A             vldr s1, [r6, #0x10]
       .text:0x0000D6AA    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000D6AE    70EEC80A             vsub.f32 s1, s1, s16
       .text:0x0000D6B2    30EE690A             vsub.f32 s0, s0, s19
       .text:0x0000D6B6    20EE200A             vmul.f32 s0, s0, s1
       .text:0x0000D6BA    C0EE090A             vdiv.f32 s1, s0, s18
       .text:0x0000D6BE    C6ED050A             vstr s1, [r6, #0x14]
       .text:0x0000D6C2    1120                 movs r0, #0x11
       .text:0x0000D6C4    F5F750FC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000D6C8 code_0xD6C8:
     .text:0x0000D6C8    0F20                 movs r0, #0xF
     .text:0x0000D6CA    FAF77DFF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000D6CE    DFEDE7DA             vldr s27, [_0x457FF000]
     .text:0x0000D6D2    E74F                 ldr r7, [0x08046C24]
     .text:0x0000D6D4    9FEDE8BB             vldr d11, [_0x08047024_1]
     .text:0x0000D6D8    F0EE008A             vmov.f32 s17, #2.000000e+00
     .text:0x0000D6DC    FEEE0EAA             vmov.f32 s21, #-9.375000e-01
     .text:0x0000D6E0    C8B3                 cbz r0, code_0xD756
     */
  if (r0 != 0) {
    /*
       .text:0x0000D6E2 code_0xD6E2:
       .text:0x0000D6E2    0F20                 movs r0, #0xF
       .text:0x0000D6E4    0FF04EFD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000D6E8    A7F58061             sub.w r1, r7, #0x400
       .text:0x0000D6EC    01EBC000             add.w r0, r1, r0, lsl #0x3
       .text:0x0000D6F0    90ED00AA             vldr s20, [r0]
       .text:0x0000D6F4    F4F73EFA             bl func_0x1B74; inline void __cdecl( void )
       .text:0x0000D6F8    D7EDFF0A             vldr s1, [r7, #0x3FC]
       .text:0x0000D6FC    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000D700    2AEE010A             vmul.f32 s0, s20, s2
       .text:0x0000D704    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000D708    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000D70C    86ED000A             vstr s0, [r6]
       .text:0x0000D710    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000D714    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000D718    10EE100A             vmov r0, s0
       .text:0x0000D71C    10F0E8FD             bl func_0x1E2F0; __int64 __cdecl( int p1 )
       .text:0x0000D720    41EC110B             vmov d1, r0, r1
       .text:0x0000D724    B0EE4B0A             vmov.f32 s0, s22
       .text:0x0000D728    F0EE6B0A             vmov.f32 s1, s23
       .text:0x0000D72C    0CF024FD             bl func_0x1A178; void __cdecl( float p1, float p2 )
       .text:0x0000D730    51EC100B             vmov r0, r1, d0
       .text:0x0000D734    10F020F8             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000D738    00EE100A             vmov s0, r0
       .text:0x0000D73C    86ED010A             vstr s0, [r6, #0x4]
       .text:0x0000D740    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000D744    20EE2D0A             vmul.f32 s0, s0, s27
       .text:0x0000D748    C0EE2A0A             vdiv.f32 s1, s0, s21
       .text:0x0000D74C    C6ED020A             vstr s1, [r6, #0x8]
       .text:0x0000D750    0F20                 movs r0, #0xF
       .text:0x0000D752    F5F709FC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000D756 code_0xD756:
     .text:0x0000D756    1020                 movs r0, #0x10
     .text:0x0000D758    FAF736FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000D75C    DFF82093             ldr.w sb, [_0x08047024]
     .text:0x0000D760    09F58065             add.w r5, sb, #0x400
     .text:0x0000D764    9FEDC8CB             vldr d12, [data_0xDA88]
     .text:0x0000D768    F0B3                 cbz r0, code_0xD7E8
     */
  /*
     .text:0x0000D7E8 code_0xD7E8:
     .text:0x0000D7E8    01E0                 b code_0xD7EE
     */
  if (r0 != 0) {
    /*    
          .text:0x0000D76A code_0xD76A:
          .text:0x0000D76A    1020                 movs r0, #0x10
          .text:0x0000D76C    0FF00AFD             bl func_0x1D184; int __cdecl( int p1, int p2 )
          .text:0x0000D770    09EBC000             add.w r0, sb, r0, lsl #0x3
          .text:0x0000D774    90ED00AA             vldr s20, [r0]
          .text:0x0000D778    F6F72CFB             bl func_0x3DD4; inline void __cdecl( void )
          .text:0x0000D77C    D5EDFF0A             vldr s1, [r5, #0x3FC]
          .text:0x0000D780    80EE201A             vdiv.f32 s2, s0, s1
          .text:0x0000D784    2AEE010A             vmul.f32 s0, s20, s2
          .text:0x0000D788    20EE280A             vmul.f32 s0, s0, s17
          .text:0x0000D78C    BCEEC00A             vcvt.u32.f32 s0, s0
          .text:0x0000D790    86ED030A             vstr s0, [r6, #0xC]
          .text:0x0000D794    F8EE400A             vcvt.f32.u32 s1, s0
          .text:0x0000D798    88EEA00A             vdiv.f32 s0, s17, s1
          .text:0x0000D79C    10EE100A             vmov r0, s0
          .text:0x0000D7A0    10F0A6FD             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
          .text:0x0000D7A4    41EC110B             vmov d1, r0, r1
          .text:0x0000D7A8    B0EE4C0A             vmov.f32 s0, s24
          .text:0x0000D7AC    F0EE6C0A             vmov.f32 s1, s25
          .text:0x0000D7B0    0CF0E2FC             bl func_0x1A178; void __cdecl( int p1, int p2 )
          .text:0x0000D7B4    51EC100B             vmov r0, r1, d0
          .text:0x0000D7B8    0FF0DEFF             bl func_0x1D778; int __cdecl( int p1, int p2 )
          .text:0x0000D7BC    00EE100A             vmov s0, r0
          .text:0x0000D7C0    86ED040A             vstr s0, [r6, #0x10]
          .text:0x0000D7C4    B6F84000             ldrh.w r0, [r6, #0x40]
          .text:0x0000D7C8    30EE480A             vsub.f32 s0, s0, s16
          .text:0x0000D7CC    00EE900A             vmov s1, r0
          .text:0x0000D7D0    F8EE600A             vcvt.f32.u32 s1, s1
          .text:0x0000D7D4    70EEE90A             vsub.f32 s1, s1, s19
          .text:0x0000D7D8    20EE800A             vmul.f32 s0, s1, s0
          .text:0x0000D7DC    C0EE090A             vdiv.f32 s1, s0, s18
          .text:0x0000D7E0    C6ED050A             vstr s1, [r6, #0x14]
          .text:0x0000D7E4    1020                 movs r0, #0x10
          .text:0x0000D7E6    00E0                 b code_0xD7EA
          */
    /*
       .text:0x0000D7EA code_0xD7EA:
       .text:0x0000D7EA    F5F7BDFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000D7EE code_0xD7EE:
     .text:0x0000D7EE    1220                 movs r0, #0x12
     .text:0x0000D7F0    FAF7EAFE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000D7F4    9FEDA6AA             vldr s20, [data_0xDA90]
     .text:0x0000D7F8    A64C                 ldr r4, [_0x200004D8_2]
     .text:0x0000D7FA    0028                 cmp r0, #0x0
     .text:0x0000D7FC    47D0                 beq code_0xD88E
     */
  if (r0 != 0) {
    /*
       .text:0x0000D7FE code_0xD7FE:
       .text:0x0000D7FE    1220                 movs r0, #0x12
       .text:0x0000D800    0FF0C0FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000D804    09EBC000             add.w r0, sb, r0, lsl #0x3
       .text:0x0000D808    90ED00EA             vldr s28, [r0]
       .text:0x0000D80C    F6F7E2FA             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000D810    D5EDFF0A             vldr s1, [r5, #0x3FC]
       .text:0x0000D814    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000D818    2EEE010A             vmul.f32 s0, s28, s2
       .text:0x0000D81C    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000D820    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000D824    86ED060A             vstr s0, [r6, #0x18]
       .text:0x0000D828    F6F7D4FA             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000D82C    B0EE401A             vmov.f32 s2, s0
       .text:0x0000D830    96ED060A             vldr s0, [r6, #0x18]
       .text:0x0000D834    2079                 ldrb r0, [r4, #0x4]
       .text:0x0000D836    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000D83A    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000D83E    51EE280A             vnmls.f32 s1, s2, s17
       .text:0x0000D842    01EE100A             vmov s2, r0
       .text:0x0000D846    B8EE411A             vcvt.f32.u32 s2, s2
       .text:0x0000D84A    20EE811A             vmul.f32 s2, s1, s2
       .text:0x0000D84E    C1EE0A0A             vdiv.f32 s1, s2, s20
       .text:0x0000D852    30EE800A             vadd.f32 s0, s1, s0
       .text:0x0000D856    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000D85A    86ED060A             vstr s0, [r6, #0x18]
       .text:0x0000D85E    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000D862    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000D866    10EE100A             vmov r0, s0
       .text:0x0000D86A    10F041FD             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000D86E    41EC110B             vmov d1, r0, r1
       .text:0x0000D872    B0EE4C0A             vmov.f32 s0, s24
       .text:0x0000D876    F0EE6C0A             vmov.f32 s1, s25
       .text:0x0000D87A    0CF07DFC             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000D87E    51EC100B             vmov r0, r1, d0
       .text:0x0000D882    0FF079FF             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000D886    F061                 str r0, [r6, #0x1C]
       .text:0x0000D888    1220                 movs r0, #0x12
       .text:0x0000D88A    F5F76DFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000D88E code_0xD88E:
     .text:0x0000D88E    2920                 movs r0, #0x29
     .text:0x0000D890    FAF79AFE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000D894    18B3                 cbz r0, code_0xD8DE
     */
  if (r0 != 0 ) {
    /*   
         .text:0x0000D896 code_0xD896:
         .text:0x0000D896    2920                 movs r0, #0x29
         .text:0x0000D898    0FF074FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000D89C    0001                 lsls r0, r0, #0x4
         .text:0x0000D89E    00EE100A             vmov s0, r0
         .text:0x0000D8A2    B8EE400A             vcvt.f32.u32 s0, s0
         .text:0x0000D8A6    20EE0D0A             vmul.f32 s0, s0, s26
         .text:0x0000D8AA    BCEEC00A             vcvt.u32.f32 s0, s0
         .text:0x0000D8AE    10EE100A             vmov r0, s0
         .text:0x0000D8B2    80B2                 uxth r0, r0
         .text:0x0000D8B4    A6F8D000             strh.w r0, [r6, #0xD0]
         .text:0x0000D8B8    00EE100A             vmov s0, r0
         .text:0x0000D8BC    D6ED280A             vldr s1, [r6, #0xA0]
         .text:0x0000D8C0    B8EE400A             vcvt.f32.u32 s0, s0
         .text:0x0000D8C4    70EEC80A             vsub.f32 s1, s1, s16
         .text:0x0000D8C8    30EE690A             vsub.f32 s0, s0, s19
         .text:0x0000D8CC    20EE200A             vmul.f32 s0, s0, s1
         .text:0x0000D8D0    C0EE090A             vdiv.f32 s1, s0, s18
         .text:0x0000D8D4    C6ED290A             vstr s1, [r6, #0xA4]
         .text:0x0000D8D8    2920                 movs r0, #0x29
         .text:0x0000D8DA    F5F745FB             bl func_0x2F68; inline void __cdecl( int p1 )
         */
  }
  /*
     .text:0x0000D8DE code_0xD8DE:
     .text:0x0000D8DE    1D20                 movs r0, #0x1D
     .text:0x0000D8E0    FAF772FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000D8E4    C0B3                 cbz r0, code_0xD958
     */
  if (r0 != 0) {
    /*
       .text:0x0000D8E6 code_0xD8E6:
       .text:0x0000D8E6    1D20                 movs r0, #0x1D
       .text:0x0000D8E8    0FF04CFC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000D8EC    6A49                 ldr r1, [_0x08046824]
       .text:0x0000D8EE    01EBC000             add.w r0, r1, r0, lsl #0x3
       .text:0x0000D8F2    90ED00DA             vldr s26, [r0]
       .text:0x0000D8F6    F4F73DF9             bl func_0x1B74; inline void __cdecl( void )
       .text:0x0000D8FA    D7EDFF0A             vldr s1, [r7, #0x3FC]
       .text:0x0000D8FE    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000D902    2DEE010A             vmul.f32 s0, s26, s2
       .text:0x0000D906    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000D90A    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000D90E    86ED240A             vstr s0, [r6, #0x90]
       .text:0x0000D912    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000D916    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000D91A    10EE100A             vmov r0, s0
       .text:0x0000D91E    10F0E7FC             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000D922    41EC110B             vmov d1, r0, r1
       .text:0x0000D926    B0EE4B0A             vmov.f32 s0, s22
       .text:0x0000D92A    F0EE6B0A             vmov.f32 s1, s23
       .text:0x0000D92E    0CF023FC             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000D932    51EC100B             vmov r0, r1, d0
       .text:0x0000D936    0FF01FFF             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000D93A    00EE100A             vmov s0, r0
       .text:0x0000D93E    86ED250A             vstr s0, [r6, #0x94]
       .text:0x0000D942    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000D946    20EE2D0A             vmul.f32 s0, s0, s27
       .text:0x0000D94A    C0EE2A0A             vdiv.f32 s1, s0, s21
       .text:0x0000D94E    C6ED260A             vstr s1, [r6, #0x98]
       .text:0x0000D952    1D20                 movs r0, #0x1D
       .text:0x0000D954    F5F708FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000D958 code_0xD958:
     .text:0x0000D958    2820                 movs r0, #0x28
     .text:0x0000D95A    FAF735FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000D95E    D8B3                 cbz r0, code_0xD9D8
     */
  /*
     .text:0x0000D9D8 code_0xD9D8:
     .text:0x0000D9D8    04E0                 b code_0xD9E4
     */
  if (r0 != 0) {
    /*
       .text:0x0000D960 code_0xD960:
       .text:0x0000D960    2820                 movs r0, #0x28
       .text:0x0000D962    0FF00FFC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000D966    09EBC000             add.w r0, sb, r0, lsl #0x3
       .text:0x0000D96A    90ED00DA             vldr s26, [r0]
       .text:0x0000D96E    F6F731FA             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000D972    D5EDFF0A             vldr s1, [r5, #0x3FC]
       .text:0x0000D976    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000D97A    2DEE010A             vmul.f32 s0, s26, s2
       .text:0x0000D97E    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000D982    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000D986    86ED270A             vstr s0, [r6, #0x9C]
       .text:0x0000D98A    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000D98E    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000D992    10EE100A             vmov r0, s0
       .text:0x0000D996    10F0ABFC             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000D99A    41EC110B             vmov d1, r0, r1
       .text:0x0000D99E    B0EE4C0A             vmov.f32 s0, s24
       .text:0x0000D9A2    F0EE6C0A             vmov.f32 s1, s25
       .text:0x0000D9A6    0CF0E7FB             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000D9AA    51EC100B             vmov r0, r1, d0
       .text:0x0000D9AE    0FF0E3FE             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000D9B2    00EE100A             vmov s0, r0
       .text:0x0000D9B6    86ED280A             vstr s0, [r6, #0xA0]
       .text:0x0000D9BA    B6F8D000             ldrh.w r0, [r6, #0xD0]
       .text:0x0000D9BE    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000D9C2    00EE900A             vmov s1, r0
       .text:0x0000D9C6    F8EE600A             vcvt.f32.u32 s1, s1
       .text:0x0000D9CA    70EEE90A             vsub.f32 s1, s1, s19
       .text:0x0000D9CE    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000D9D2    C0EE090A             vdiv.f32 s1, s0, s18
       .text:0x0000D9D6    00E0                 b code_0xD9DA
       */
    /*
       .text:0x0000D9DA code_0xD9DA:
       .text:0x0000D9DA    C6ED290A             vstr s1, [r6, #0xA4]
       .text:0x0000D9DE    2820                 movs r0, #0x28
       .text:0x0000D9E0    F5F7C2FA             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000D9E4 code_0xD9E4:
     .text:0x0000D9E4    2A20                 movs r0, #0x2A
     .text:0x0000D9E6    FAF7EFFD             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000D9EA    A0B3                 cbz r0, code_0xDA56
     */
  /*
     .text:0x0000DA56 code_0xDA56:
     .text:0x0000DA56    36E0                 b code_0xDAC6
     */
  if (r0 != 0) {
    /*
       .text:0x0000D9EC code_0xD9EC:
       .text:0x0000D9EC    2A20                 movs r0, #0x2A
       .text:0x0000D9EE    0FF0C9FB             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000D9F2    09EBC000             add.w r0, sb, r0, lsl #0x3
       .text:0x0000D9F6    D0ED009A             vldr s19, [r0]
       .text:0x0000D9FA    F6F7EBF9             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000D9FE    D5EDFF0A             vldr s1, [r5, #0x3FC]
       .text:0x0000DA02    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000DA06    29EE810A             vmul.f32 s0, s19, s2
       .text:0x0000DA0A    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000DA0E    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000DA12    86ED2A0A             vstr s0, [r6, #0xA8]
       .text:0x0000DA16    F6F7DDF9             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000DA1A    F0EE400A             vmov.f32 s1, s0
       .text:0x0000DA1E    96ED2A0A             vldr s0, [r6, #0xA8]
       .text:0x0000DA22    2079                 ldrb r0, [r4, #0x4]
       .text:0x0000DA24    B8EE401A             vcvt.f32.u32 s2, s0
       .text:0x0000DA28    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000DA2C    10EEA81A             vnmls.f32 s2, s1, s17
       .text:0x0000DA30    00EE900A             vmov s1, r0
       .text:0x0000DA34    F8EE600A             vcvt.f32.u32 s1, s1
       .text:0x0000DA38    21EE201A             vmul.f32 s2, s2, s1
       .text:0x0000DA3C    C1EE0A0A             vdiv.f32 s1, s2, s20
       .text:0x0000DA40    30EE800A             vadd.f32 s0, s1, s0
       .text:0x0000DA44    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000DA48    86ED2A0A             vstr s0, [r6, #0xA8]
       .text:0x0000DA4C    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DA50    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000DA54    22E0                 b code_0xDA9C
       */
    /*
       .text:0x0000DA9C code_0xDA9C:
       .text:0x0000DA9C    10EE100A             vmov r0, s0
       .text:0x0000DAA0    10F026FC             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000DAA4    41EC110B             vmov d1, r0, r1
       .text:0x0000DAA8    B0EE4C0A             vmov.f32 s0, s24
       .text:0x0000DAAC    F0EE6C0A             vmov.f32 s1, s25
       .text:0x0000DAB0    0CF062FB             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000DAB4    51EC100B             vmov r0, r1, d0
       .text:0x0000DAB8    0FF05EFE             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000DABC    C6F8AC00             str.w r0, [r6, #0xAC]
       .text:0x0000DAC0    2A20                 movs r0, #0x2A
       .text:0x0000DAC2    F5F751FA             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000DAC6 code_0xDAC6:
     .text:0x0000DAC6    0A20                 movs r0, #0xA
     .text:0x0000DAC8    FAF77EFD             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000DACC    40F2FF7A             movw sl, #0x7FF
     .text:0x0000DAD0    DFEDFEDA             vldr s27, [data_0xDECC]
     .text:0x0000DAD4    0028                 cmp r0, #0x0
     .text:0x0000DAD6    54D0                 beq code_0xDB82
     */
  if (r0 != 0) {
    /*
       .text:0x0000DAD8 code_0xDAD8:
       .text:0x0000DAD8    0920                 movs r0, #0x9
       .text:0x0000DADA    0FF053FB             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DADE    0AEBC000             add.w r0, sl, r0, lsl #0x3
       .text:0x0000DAE2    A6F88A00             strh.w r0, [r6, #0x8A]
       .text:0x0000DAE6    0820                 movs r0, #0x8
       .text:0x0000DAE8    0FF04CFB             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DAEC    AAEBC000             sub.w r0, sl, r0, lsl #0x3
       .text:0x0000DAF0    A6F88800             strh.w r0, [r6, #0x88]
       .text:0x0000DAF4    0A20                 movs r0, #0xA
       .text:0x0000DAF6    0FF045FB             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DAFA    F549                 ldr r1, [_0x08046824_1]
       .text:0x0000DAFC    01EBC000             add.w r0, r1, r0, lsl #0x3
       .text:0x0000DB00    D0ED009A             vldr s19, [r0]
       .text:0x0000DB04    F4F736F8             bl func_0x1B74; inline void __cdecl( void )
       .text:0x0000DB08    D7EDFF0A             vldr s1, [r7, #0x3FC]
       .text:0x0000DB0C    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000DB10    29EE810A             vmul.f32 s0, s19, s2
       .text:0x0000DB14    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000DB18    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000DB1C    86ED110A             vstr s0, [r6, #0x44]
       .text:0x0000DB20    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DB24    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000DB28    10EE100A             vmov r0, s0
       .text:0x0000DB2C    10F0E0FB             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000DB30    41EC110B             vmov d1, r0, r1
       .text:0x0000DB34    B0EE4B0A             vmov.f32 s0, s22
       .text:0x0000DB38    F0EE6B0A             vmov.f32 s1, s23
       .text:0x0000DB3C    0CF01CFB             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000DB40    51EC100B             vmov r0, r1, d0
       .text:0x0000DB44    0FF018FE             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000DB48    00EE100A             vmov s0, r0
       .text:0x0000DB4C    86ED120A             vstr s0, [r6, #0x48]
       .text:0x0000DB50    B6F88A00             ldrh.w r0, [r6, #0x8A]
       .text:0x0000DB54    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000DB58    00EE900A             vmov s1, r0
       .text:0x0000DB5C    B6F88800             ldrh.w r0, [r6, #0x88]
       .text:0x0000DB60    01EE100A             vmov s2, r0
       .text:0x0000DB64    F8EE600A             vcvt.f32.u32 s1, s1
       .text:0x0000DB68    B8EE411A             vcvt.f32.u32 s2, s2
       .text:0x0000DB6C    41EE6D0A             vmls.f32 s1, s2, s27
       .text:0x0000DB70    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000DB74    C0EE2A0A             vdiv.f32 s1, s0, s21
       .text:0x0000DB78    C6ED130A             vstr s1, [r6, #0x4C]
       .text:0x0000DB7C    0A20                 movs r0, #0xA
       .text:0x0000DB7E    F5F7F3F9             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000DB82 code_0xDB82:
     .text:0x0000DB82    0B20                 movs r0, #0xB
     .text:0x0000DB84    FAF720FD             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000DB88    9FEDD2DA             vldr s26, [data_0xDED4]
     .text:0x0000DB8C    DFEDD29A             vldr s19, [data_0xDED8]
     .text:0x0000DB90    E8B3                 cbz r0, code_0xDC0E
     */
  /*
     .text:0x0000DC0E code_0xDC0E:
     .text:0x0000DC0E    12E0                 b code_0xDC36
     */
  if (r0 != 0) {
    /*
       .text:0x0000DB92 code_0xDB92:
       .text:0x0000DB92    0920                 movs r0, #0x9
       .text:0x0000DB94    0FF0F6FA             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DB98    0AEBC000             add.w r0, sl, r0, lsl #0x3
       .text:0x0000DB9C    A6F88A00             strh.w r0, [r6, #0x8A]
       .text:0x0000DBA0    0820                 movs r0, #0x8
       .text:0x0000DBA2    0FF0EFFA             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DBA6    AAEBC000             sub.w r0, sl, r0, lsl #0x3
       .text:0x0000DBAA    A6F88800             strh.w r0, [r6, #0x88]
       .text:0x0000DBAE    0B20                 movs r0, #0xB
       .text:0x0000DBB0    0FF0E8FA             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DBB4    09EBC000             add.w r0, sb, r0, lsl #0x3
       .text:0x0000DBB8    90ED00EA             vldr s28, [r0]
       .text:0x0000DBBC    F6F70AF9             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000DBC0    D5EDFF0A             vldr s1, [r5, #0x3FC]
       .text:0x0000DBC4    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000DBC8    2EEE010A             vmul.f32 s0, s28, s2
       .text:0x0000DBCC    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000DBD0    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000DBD4    86ED140A             vstr s0, [r6, #0x50]
       .text:0x0000DBD8    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DBDC    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000DBE0    10EE100A             vmov r0, s0
       .text:0x0000DBE4    10F084FB             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000DBE8    41EC110B             vmov d1, r0, r1
       .text:0x0000DBEC    B0EE4C0A             vmov.f32 s0, s24
       .text:0x0000DBF0    F0EE6C0A             vmov.f32 s1, s25
       .text:0x0000DBF4    0CF0C0FA             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000DBF8    51EC100B             vmov r0, r1, d0
       .text:0x0000DBFC    0FF0BCFD             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000DC00    00EE100A             vmov s0, r0
       .text:0x0000DC04    86ED150A             vstr s0, [r6, #0x54]
       .text:0x0000DC08    B6F88A00             ldrh.w r0, [r6, #0x8A]
       .text:0x0000DC0C    00E0                 b code_0xDC10
       */
    /*
       .text:0x0000DC10 code_0xDC10:
       .text:0x0000DC10    00EE900A             vmov s1, r0
       .text:0x0000DC14    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000DC18    B8EE601A             vcvt.f32.u32 s2, s1
       .text:0x0000DC1C    F0EE4D0A             vmov.f32 s1, s26
       .text:0x0000DC20    41EE690A             vmls.f32 s1, s2, s19
       .text:0x0000DC24    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000DC28    C0EE090A             vdiv.f32 s1, s0, s18
       .text:0x0000DC2C    C6ED160A             vstr s1, [r6, #0x58]
       .text:0x0000DC30    0B20                 movs r0, #0xB
       .text:0x0000DC32    F5F799F9             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000DC36 code_0xDC36:
     .text:0x0000DC36    0C20                 movs r0, #0xC
     .text:0x0000DC38    FAF7C6FC             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000DC3C    DFF89C82             ldr.w r8, [_0x2000501C]
     .text:0x0000DC40    0028                 cmp r0, #0x0
     .text:0x0000DC42    6CD0                 beq code_0xDD1E
     */
  if (r0 != 0) {
    /*
       .text:0x0000DC44 code_0xDC44:
       .text:0x0000DC44    0C20                 movs r0, #0xC
       .text:0x0000DC46    0FF09DFA             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DC4A    09EBC000             add.w r0, sb, r0, lsl #0x3
       .text:0x0000DC4E    90ED00EA             vldr s28, [r0]
       .text:0x0000DC52    F6F7BFF8             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000DC56    D5EDFF0A             vldr s1, [r5, #0x3FC]
       .text:0x0000DC5A    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000DC5E    2EEE010A             vmul.f32 s0, s28, s2
       .text:0x0000DC62    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000DC66    BCEEC0EA             vcvt.u32.f32 s28, s0
       .text:0x0000DC6A    F6F7B3F8             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000DC6E    F0EE400A             vmov.f32 s1, s0
       .text:0x0000DC72    96ED170A             vldr s0, [r6, #0x5C]
       .text:0x0000DC76    2079                 ldrb r0, [r4, #0x4]
       .text:0x0000DC78    B8EE401A             vcvt.f32.u32 s2, s0
       .text:0x0000DC7C    10EEA81A             vnmls.f32 s2, s1, s17
       .text:0x0000DC80    00EE900A             vmov s1, r0
       .text:0x0000DC84    F8EE600A             vcvt.f32.u32 s1, s1
       .text:0x0000DC88    21EE201A             vmul.f32 s2, s2, s1
       .text:0x0000DC8C    C1EE0A0A             vdiv.f32 s1, s2, s20
       .text:0x0000DC90    B8EE4E1A             vcvt.f32.u32 s2, s28
       .text:0x0000DC94    70EE810A             vadd.f32 s1, s1, s2
       .text:0x0000DC98    BCEEE0EA             vcvt.u32.f32 s28, s1
       .text:0x0000DC9C    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DCA0    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000DCA4    10EE100A             vmov r0, s0
       .text:0x0000DCA8    10F022FB             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000DCAC    41EC110B             vmov d1, r0, r1
       .text:0x0000DCB0    B0EE4C0A             vmov.f32 s0, s24
       .text:0x0000DCB4    F0EE6C0A             vmov.f32 s1, s25
       .text:0x0000DCB8    0CF05EFA             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000DCBC    51EC100B             vmov r0, r1, d0
       .text:0x0000DCC0    0FF05AFD             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000DCC4    01EE900A             vmov s3, r0
       .text:0x0000DCC8    0020                 movs r0, #0x0
       .text:0x0000DCCA    8549                 ldr r1, [_0x20001FD4_3]
       .text:0x0000DCCC    71EEC80A             vsub.f32 s1, s3, s16
       */
    while (1) {
      /*
         .text:0x0000DCD0 code_0xDCD0:
         .text:0x0000DCD0    00EB4002             add.w r2, r0, r0, lsl #0x1
         .text:0x0000DCD4    02EBC002             add.w r2, r2, r0, lsl #0x3
         .text:0x0000DCD8    01EB8202             add.w r2, r1, r2, lsl #0x2
         .text:0x0000DCDC    127A                 ldrb r2, [r2, #0x8]
         .text:0x0000DCDE    032A                 cmp r2, #0x3
         .text:0x0000DCE0    13D1                 bne code_0xDD0A
         */
      if (r2 == 3) {
        /*
           .text:0x0000DCE2 code_0xDCE2:
           .text:0x0000DCE2    B6F88820             ldrh.w r2, [r6, #0x88]
           .text:0x0000DCE6    00EE102A             vmov s0, r2
           .text:0x0000DCEA    08EB8002             add.w r2, r8, r0, lsl #0x2
           .text:0x0000DCEE    B8EE400A             vcvt.f32.u32 s0, s0
           .text:0x0000DCF2    92ED001A             vldr s2, [r2]
           .text:0x0000DCF6    06EB8002             add.w r2, r6, r0, lsl #0x2
           .text:0x0000DCFA    01EE690A             vmls.f32 s0, s2, s19
           .text:0x0000DCFE    20EE200A             vmul.f32 s0, s0, s1
           .text:0x0000DD02    80EE091A             vdiv.f32 s2, s0, s18
           .text:0x0000DD06    82ED191A             vstr s2, [r2, #0x64]
           */
      }
      /*
         .text:0x0000DD0A code_0xDD0A:
         .text:0x0000DD0A    401C                 adds r0, r0, #0x1
         .text:0x0000DD0C    0828                 cmp r0, #0x8
         .text:0x0000DD0E    DFDB                 blt code_0xDCD0
         */
      if (r0 >= 8) {
        break;
      }
    }
    /*
       .text:0x0000DD10 code_0xDD10:
       .text:0x0000DD10    C6ED181A             vstr s3, [r6, #0x60]
       .text:0x0000DD14    86ED17EA             vstr s28, [r6, #0x5C]
       .text:0x0000DD18    0C20                 movs r0, #0xC
       .text:0x0000DD1A    F5F725F9             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000DD1E code_0xDD1E:
     .text:0x0000DD1E    0920                 movs r0, #0x9
     .text:0x0000DD20    FAF752FC             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000DD24    C0B3                 cbz r0, code_0xDD98
     */
  if (r0 != 0) {
    /*
       .text:0x0000DD26 code_0xDD26:
       .text:0x0000DD26    0920                 movs r0, #0x9
       .text:0x0000DD28    0FF02CFA             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DD2C    0AEBC000             add.w r0, sl, r0, lsl #0x3
       .text:0x0000DD30    A6F88A00             strh.w r0, [r6, #0x8A]
       .text:0x0000DD34    0820                 movs r0, #0x8
       .text:0x0000DD36    0FF025FA             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DD3A    AAEBC001             sub.w r1, sl, r0, lsl #0x3
       .text:0x0000DD3E    A6F88810             strh.w r1, [r6, #0x88]
       .text:0x0000DD42    B6F88A00             ldrh.w r0, [r6, #0x8A]
       .text:0x0000DD46    00EE100A             vmov s0, r0
       .text:0x0000DD4A    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DD4E    00EE101A             vmov s0, r1
       .text:0x0000DD52    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000DD56    40EE6D0A             vmls.f32 s1, s0, s27
       .text:0x0000DD5A    96ED120A             vldr s0, [r6, #0x48]
       .text:0x0000DD5E    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000DD62    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000DD66    C0EE2A0A             vdiv.f32 s1, s0, s21
       .text:0x0000DD6A    C6ED130A             vstr s1, [r6, #0x4C]
       .text:0x0000DD6E    00EE100A             vmov s0, r0
       .text:0x0000DD72    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DD76    B0EE4D0A             vmov.f32 s0, s26
       .text:0x0000DD7A    00EEE90A             vmls.f32 s0, s1, s19
       .text:0x0000DD7E    D6ED150A             vldr s1, [r6, #0x54]
       .text:0x0000DD82    70EEC80A             vsub.f32 s1, s1, s16
       .text:0x0000DD86    20EE200A             vmul.f32 s0, s0, s1
       .text:0x0000DD8A    C0EE090A             vdiv.f32 s1, s0, s18
       .text:0x0000DD8E    C6ED160A             vstr s1, [r6, #0x58]
       .text:0x0000DD92    0920                 movs r0, #0x9
       .text:0x0000DD94    F5F7E8F8             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000DD98 code_0xDD98:
     .text:0x0000DD98    0820                 movs r0, #0x8
     .text:0x0000DD9A    FAF715FC             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000DD9E    0028                 cmp r0, #0x0
     .text:0x0000DDA0    5ED0                 beq code_0xDE60
     */
  if (r0 != 0) {
    /*
       .text:0x0000DDA2 code_0xDDA2:
       .text:0x0000DDA2    0920                 movs r0, #0x9
       .text:0x0000DDA4    0FF0EEF9             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DDA8    0AEBC000             add.w r0, sl, r0, lsl #0x3
       .text:0x0000DDAC    A6F88A00             strh.w r0, [r6, #0x8A]
       .text:0x0000DDB0    0820                 movs r0, #0x8
       .text:0x0000DDB2    0FF0E7F9             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DDB6    AAEBC001             sub.w r1, sl, r0, lsl #0x3
       .text:0x0000DDBA    A6F88810             strh.w r1, [r6, #0x88]
       .text:0x0000DDBE    B6F88A00             ldrh.w r0, [r6, #0x8A]
       .text:0x0000DDC2    00EE100A             vmov s0, r0
       .text:0x0000DDC6    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DDCA    00EE101A             vmov s0, r1
       .text:0x0000DDCE    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000DDD2    40EE6D0A             vmls.f32 s1, s0, s27
       .text:0x0000DDD6    96ED120A             vldr s0, [r6, #0x48]
       .text:0x0000DDDA    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000DDDE    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000DDE2    C0EE2A0A             vdiv.f32 s1, s0, s21
       .text:0x0000DDE6    C6ED130A             vstr s1, [r6, #0x4C]
       .text:0x0000DDEA    00EE100A             vmov s0, r0
       .text:0x0000DDEE    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DDF2    B0EE4D0A             vmov.f32 s0, s26
       .text:0x0000DDF6    00EEE90A             vmls.f32 s0, s1, s19
       .text:0x0000DDFA    D6ED150A             vldr s1, [r6, #0x54]
       .text:0x0000DDFE    70EEC80A             vsub.f32 s1, s1, s16
       .text:0x0000DE02    20EE200A             vmul.f32 s0, s0, s1
       .text:0x0000DE06    C0EE090A             vdiv.f32 s1, s0, s18
       .text:0x0000DE0A    C6ED160A             vstr s1, [r6, #0x58]
       .text:0x0000DE0E    0020                 movs r0, #0x0
       .text:0x0000DE10    334A                 ldr r2, [_0x20001FD4_3]
       */
    while (1) {
      /*
         .text:0x0000DE12 code_0xDE12:
         .text:0x0000DE12    00EB4001             add.w r1, r0, r0, lsl #0x1
         .text:0x0000DE16    01EBC001             add.w r1, r1, r0, lsl #0x3
         .text:0x0000DE1A    02EB8101             add.w r1, r2, r1, lsl #0x2
         .text:0x0000DE1E    097A                 ldrb r1, [r1, #0x8]
         .text:0x0000DE20    0329                 cmp r1, #0x3
         .text:0x0000DE22    17D1                 bne code_0xDE54
         */
      if (r1 == 3) {
        /*
           .text:0x0000DE24 code_0xDE24:
           .text:0x0000DE24    B6F88810             ldrh.w r1, [r6, #0x88]
           .text:0x0000DE28    00EE101A             vmov s0, r1
           .text:0x0000DE2C    08EB8001             add.w r1, r8, r0, lsl #0x2
           .text:0x0000DE30    B8EE400A             vcvt.f32.u32 s0, s0
           .text:0x0000DE34    D1ED000A             vldr s1, [r1]
           .text:0x0000DE38    06EB8001             add.w r1, r6, r0, lsl #0x2
           .text:0x0000DE3C    00EEE90A             vmls.f32 s0, s1, s19
           .text:0x0000DE40    D6ED180A             vldr s1, [r6, #0x60]
           .text:0x0000DE44    70EEC80A             vsub.f32 s1, s1, s16
           .text:0x0000DE48    20EE200A             vmul.f32 s0, s0, s1
           .text:0x0000DE4C    C0EE090A             vdiv.f32 s1, s0, s18
           .text:0x0000DE50    C1ED190A             vstr s1, [r1, #0x64]
           */
      }
      /*
         .text:0x0000DE54 code_0xDE54:
         .text:0x0000DE54    401C                 adds r0, r0, #0x1
         .text:0x0000DE56    0828                 cmp r0, #0x8
         .text:0x0000DE58    DBDB                 blt code_0xDE12
         */
    }
    /*
       .text:0x0000DE5A code_0xDE5A:
       .text:0x0000DE5A    0820                 movs r0, #0x8
       .text:0x0000DE5C    F5F784F8             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000DE60 code_0xDE60:
     .text:0x0000DE60    1820                 movs r0, #0x18
     .text:0x0000DE62    FAF7B1FB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000DE66    80B3                 cbz r0, code_0xDECA
     .text:0x0000DECA code_0xDECA:
     .text:0x0000DECA    30E0                 b code_0xDF2E
     */
  if (r0 != 0) {
    /*
       .text:0x0000DE68 code_0xDE68:
       .text:0x0000DE68    2720                 movs r0, #0x27
       .text:0x0000DE6A    0FF08BF9             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DE6E    0AEBC000             add.w r0, sl, r0, lsl #0x3
       .text:0x0000DE72    A6F81A01             strh.w r0, [r6, #0x11A]
       .text:0x0000DE76    2620                 movs r0, #0x26
       .text:0x0000DE78    0FF084F9             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DE7C    AAEBC000             sub.w r0, sl, r0, lsl #0x3
       .text:0x0000DE80    A6F81801             strh.w r0, [r6, #0x118]
       .text:0x0000DE84    1820                 movs r0, #0x18
       .text:0x0000DE86    0FF07DF9             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DE8A    1149                 ldr r1, [_0x08046824_1]
       .text:0x0000DE8C    01EBC000             add.w r0, r1, r0, lsl #0x3
       .text:0x0000DE90    90ED00EA             vldr s28, [r0]
       .text:0x0000DE94    F3F76EFE             bl func_0x1B74; inline void __cdecl( void )
       .text:0x0000DE98    D7EDFF0A             vldr s1, [r7, #0x3FC]
       .text:0x0000DE9C    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000DEA0    2EEE010A             vmul.f32 s0, s28, s2
       .text:0x0000DEA4    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000DEA8    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000DEAC    86ED350A             vstr s0, [r6, #0xD4]
       .text:0x0000DEB0    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DEB4    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000DEB8    10EE100A             vmov r0, s0
       .text:0x0000DEBC    10F018FA             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000DEC0    41EC110B             vmov d1, r0, r1
       .text:0x0000DEC4    B0EE4B0A             vmov.f32 s0, s22
       .text:0x0000DEC8    0CE0                 b code_0xDEE4
       */
    /*
       .text:0x0000DEE4 code_0xDEE4:
       .text:0x0000DEE4    F0EE6B0A             vmov.f32 s1, s23
       .text:0x0000DEE8    0CF046F9             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000DEEC    51EC100B             vmov r0, r1, d0
       .text:0x0000DEF0    0FF042FC             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000DEF4    00EE100A             vmov s0, r0
       .text:0x0000DEF8    86ED360A             vstr s0, [r6, #0xD8]
       .text:0x0000DEFC    B6F81A01             ldrh.w r0, [r6, #0x11A]
       .text:0x0000DF00    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000DF04    00EE900A             vmov s1, r0
       .text:0x0000DF08    B6F81801             ldrh.w r0, [r6, #0x118]
       .text:0x0000DF0C    01EE100A             vmov s2, r0
       .text:0x0000DF10    F8EE600A             vcvt.f32.u32 s1, s1
       .text:0x0000DF14    B8EE411A             vcvt.f32.u32 s2, s2
       .text:0x0000DF18    41EE6D0A             vmls.f32 s1, s2, s27
       .text:0x0000DF1C    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000DF20    C0EE2A0A             vdiv.f32 s1, s0, s21
       .text:0x0000DF24    C6ED370A             vstr s1, [r6, #0xDC]
       .text:0x0000DF28    1820                 movs r0, #0x18
       .text:0x0000DF2A    F5F71DF8             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000DF2E code_0xDF2E:
     .text:0x0000DF2E    1920                 movs r0, #0x19
     .text:0x0000DF30    FAF74AFB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000DF34    E8B3                 cbz r0, code_0xDFB2
     .text:0x0000DFB2 code_0xDFB2:
     .text:0x0000DFB2    12E0                 b code_0xDFDA
     */
  if (r0 != 0) {
    /*
       .text:0x0000DF36 code_0xDF36:
       .text:0x0000DF36    2720                 movs r0, #0x27
       .text:0x0000DF38    0FF024F9             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DF3C    0AEBC000             add.w r0, sl, r0, lsl #0x3
       .text:0x0000DF40    A6F81A01             strh.w r0, [r6, #0x11A]
       .text:0x0000DF44    2620                 movs r0, #0x26
       .text:0x0000DF46    0FF01DF9             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DF4A    AAEBC000             sub.w r0, sl, r0, lsl #0x3
       .text:0x0000DF4E    A6F81801             strh.w r0, [r6, #0x118]
       .text:0x0000DF52    1920                 movs r0, #0x19
       .text:0x0000DF54    0FF016F9             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DF58    09EBC000             add.w r0, sb, r0, lsl #0x3
       .text:0x0000DF5C    90ED00BA             vldr s22, [r0]
       .text:0x0000DF60    F5F738FF             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000DF64    D5EDFF0A             vldr s1, [r5, #0x3FC]
       .text:0x0000DF68    80EE201A             vdiv.f32 s2, s0, s1
       .text:0x0000DF6C    2BEE010A             vmul.f32 s0, s22, s2
       .text:0x0000DF70    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000DF74    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000DF78    86ED380A             vstr s0, [r6, #0xE0]
       .text:0x0000DF7C    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000DF80    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000DF84    10EE100A             vmov r0, s0
       .text:0x0000DF88    10F0B2F9             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000DF8C    41EC110B             vmov d1, r0, r1
       .text:0x0000DF90    B0EE4C0A             vmov.f32 s0, s24
       .text:0x0000DF94    F0EE6C0A             vmov.f32 s1, s25
       .text:0x0000DF98    0CF0EEF8             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000DF9C    51EC100B             vmov r0, r1, d0
       .text:0x0000DFA0    0FF0EAFB             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000DFA4    00EE100A             vmov s0, r0
       .text:0x0000DFA8    86ED390A             vstr s0, [r6, #0xE4]
       .text:0x0000DFAC    B6F81A01             ldrh.w r0, [r6, #0x11A]
       .text:0x0000DFB0    00E0                 b code_0xDFB4
       */
    /*
       .text:0x0000DFB4 code_0xDFB4:
       .text:0x0000DFB4    00EE900A             vmov s1, r0
       .text:0x0000DFB8    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000DFBC    B8EE601A             vcvt.f32.u32 s2, s1
       .text:0x0000DFC0    F0EE4D0A             vmov.f32 s1, s26
       .text:0x0000DFC4    41EE690A             vmls.f32 s1, s2, s19
       .text:0x0000DFC8    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000DFCC    C0EE090A             vdiv.f32 s1, s0, s18
       .text:0x0000DFD0    C6ED3A0A             vstr s1, [r6, #0xE8]
       .text:0x0000DFD4    1920                 movs r0, #0x19
       .text:0x0000DFD6    F4F7C7FF             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000DFDA code_0xDFDA:
     .text:0x0000DFDA    1A20                 movs r0, #0x1A
     .text:0x0000DFDC    FAF7F4FA             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000DFE0    0028                 cmp r0, #0x0
     .text:0x0000DFE2    6CD0                 beq code_0xE0BE
     */
  if (r0 != 0) {
    /*
       .text:0x0000DFE4 code_0xDFE4:
       .text:0x0000DFE4    1A20                 movs r0, #0x1A
       .text:0x0000DFE6    0FF0CDF8             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000DFEA    09EBC000             add.w r0, sb, r0, lsl #0x3
       .text:0x0000DFEE    90ED00BA             vldr s22, [r0]
       .text:0x0000DFF2    F5F7EFFE             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000DFF6    D5EDFF0A             vldr s1, [r5, #0x3FC]
       .text:0x0000DFFA    80EE201A             vdiv.f32 s2, s0, s1
       */
    /*
       .text:0x0000DFFE code_0xDFFE:
       .text:0x0000DFFE    2BEE010A             vmul.f32 s0, s22, s2
       .text:0x0000E002    20EE280A             vmul.f32 s0, s0, s17
       .text:0x0000E006    BCEEC0BA             vcvt.u32.f32 s22, s0
       .text:0x0000E00A    F5F7E3FE             bl func_0x3DD4; inline void __cdecl( void )
       .text:0x0000E00E    F0EE400A             vmov.f32 s1, s0
       .text:0x0000E012    96ED3B0A             vldr s0, [r6, #0xEC]
       .text:0x0000E016    2079                 ldrb r0, [r4, #0x4]
       .text:0x0000E018    B8EE401A             vcvt.f32.u32 s2, s0
       .text:0x0000E01C    10EEA81A             vnmls.f32 s2, s1, s17
       .text:0x0000E020    00EE900A             vmov s1, r0
       .text:0x0000E024    F8EE600A             vcvt.f32.u32 s1, s1
       .text:0x0000E028    21EE201A             vmul.f32 s2, s2, s1
       .text:0x0000E02C    C1EE0A0A             vdiv.f32 s1, s2, s20
       .text:0x0000E030    B8EE4B1A             vcvt.f32.u32 s2, s22
       .text:0x0000E034    70EE810A             vadd.f32 s1, s1, s2
       .text:0x0000E038    BCEEE0BA             vcvt.u32.f32 s22, s1
       .text:0x0000E03C    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E040    88EEA00A             vdiv.f32 s0, s17, s1
       .text:0x0000E044    10EE100A             vmov r0, s0
       .text:0x0000E048    10F052F9             bl func_0x1E2F0; __int64 __cdecl( int p1, int p2 )
       .text:0x0000E04C    41EC110B             vmov d1, r0, r1
       .text:0x0000E050    B0EE4C0A             vmov.f32 s0, s24
       .text:0x0000E054    F0EE6C0A             vmov.f32 s1, s25
       .text:0x0000E058    0CF08EF8             bl func_0x1A178; void __cdecl( int p1, int p2 )
       .text:0x0000E05C    51EC100B             vmov r0, r1, d0
       .text:0x0000E060    0FF08AFB             bl func_0x1D778; int __cdecl( int p1, int p2 )
       .text:0x0000E064    00EE100A             vmov s0, r0
       .text:0x0000E068    86ED3C0A             vstr s0, [r6, #0xF0]
       .text:0x0000E06C    86ED3BBA             vstr s22, [r6, #0xEC]
       .text:0x0000E070    0020                 movs r0, #0x0
       .text:0x0000E072    70EE480A             vsub.f32 s1, s0, s16
       .text:0x0000E076    FE4A                 ldr r2, [_0x20001FD4_4]
       */
    while (1) {
      /*
         .text:0x0000E078 code_0xE078:
         .text:0x0000E078    00EB4001             add.w r1, r0, r0, lsl #0x1
         .text:0x0000E07C    01EBC001             add.w r1, r1, r0, lsl #0x3
         .text:0x0000E080    02EB8101             add.w r1, r2, r1, lsl #0x2
         .text:0x0000E084    097E                 ldrb r1, [r1, #0x18]
         .text:0x0000E086    0329                 cmp r1, #0x3
         .text:0x0000E088    13D1                 bne code_0xE0B2
         */
      if (r1 == 3) {
        /*
           .text:0x0000E08A code_0xE08A:
           .text:0x0000E08A    B6F81811             ldrh.w r1, [r6, #0x118]
           .text:0x0000E08E    00EE101A             vmov s0, r1
           .text:0x0000E092    08EB8001             add.w r1, r8, r0, lsl #0x2
           .text:0x0000E096    B8EE400A             vcvt.f32.u32 s0, s0
           .text:0x0000E09A    91ED081A             vldr s2, [r1, #0x20]
           .text:0x0000E09E    06EB8001             add.w r1, r6, r0, lsl #0x2
           .text:0x0000E0A2    01EE690A             vmls.f32 s0, s2, s19
           .text:0x0000E0A6    20EE201A             vmul.f32 s2, s0, s1
           .text:0x0000E0AA    81EE090A             vdiv.f32 s0, s2, s18
           .text:0x0000E0AE    81ED3D0A             vstr s0, [r1, #0xF4]
           */
      }
      /*
         .text:0x0000E0B2 code_0xE0B2:
         .text:0x0000E0B2    401C                 adds r0, r0, #0x1
         .text:0x0000E0B4    0828                 cmp r0, #0x8
         .text:0x0000E0B6    DFDB                 blt code_0xE078
         */
    }
    /*
       .text:0x0000E0B8 code_0xE0B8:
       .text:0x0000E0B8    1A20                 movs r0, #0x1A
       .text:0x0000E0BA    F4F755FF             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }

  /*
     .text:0x0000E0BE code_0xE0BE:
     .text:0x0000E0BE    2720                 movs r0, #0x27
     .text:0x0000E0C0    FAF782FA             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E0C4    C0B3                 cbz r0, code_0xE138
     */
  if (r0 != 0) {
    /*
       .text:0x0000E0C6 code_0xE0C6:
       .text:0x0000E0C6    2720                 movs r0, #0x27
       .text:0x0000E0C8    0FF05CF8             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E0CC    0AEBC000             add.w r0, sl, r0, lsl #0x3
       .text:0x0000E0D0    A6F81A01             strh.w r0, [r6, #0x11A]
       .text:0x0000E0D4    2620                 movs r0, #0x26
       .text:0x0000E0D6    0FF055F8             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E0DA    AAEBC001             sub.w r1, sl, r0, lsl #0x3
       .text:0x0000E0DE    A6F81811             strh.w r1, [r6, #0x118]
       .text:0x0000E0E2    B6F81A01             ldrh.w r0, [r6, #0x11A]
       .text:0x0000E0E6    00EE100A             vmov s0, r0
       .text:0x0000E0EA    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E0EE    00EE101A             vmov s0, r1
       .text:0x0000E0F2    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000E0F6    40EE6D0A             vmls.f32 s1, s0, s27
       .text:0x0000E0FA    96ED360A             vldr s0, [r6, #0xD8]
       .text:0x0000E0FE    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000E102    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000E106    C0EE2A0A             vdiv.f32 s1, s0, s21
       .text:0x0000E10A    C6ED370A             vstr s1, [r6, #0xDC]
       .text:0x0000E10E    00EE100A             vmov s0, r0
       .text:0x0000E112    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E116    B0EE4D0A             vmov.f32 s0, s26
       .text:0x0000E11A    00EEE90A             vmls.f32 s0, s1, s19
       .text:0x0000E11E    D6ED390A             vldr s1, [r6, #0xE4]
       .text:0x0000E122    70EEC80A             vsub.f32 s1, s1, s16
       .text:0x0000E126    60EE200A             vmul.f32 s1, s0, s1
       .text:0x0000E12A    80EE890A             vdiv.f32 s0, s1, s18
       .text:0x0000E12E    86ED3A0A             vstr s0, [r6, #0xE8]
       .text:0x0000E132    2720                 movs r0, #0x27
       .text:0x0000E134    F4F718FF             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E138 code_0xE138:
     .text:0x0000E138    2620                 movs r0, #0x26
     .text:0x0000E13A    FAF745FA             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E13E    E8B3                 cbz r0, code_0xE1BC
     .text:0x0000E1BC code_0xE1BC:
     .text:0x0000E1BC    1FE0                 b code_0xE1FE
     */
  if (r0 != 0) {
    /*
       .text:0x0000E140 code_0xE140:
       .text:0x0000E140    2720                 movs r0, #0x27
       .text:0x0000E142    0FF01FF8             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E146    0AEBC000             add.w r0, sl, r0, lsl #0x3
       .text:0x0000E14A    A6F81A01             strh.w r0, [r6, #0x11A]
       .text:0x0000E14E    2620                 movs r0, #0x26
       .text:0x0000E150    0FF018F8             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E154    AAEBC001             sub.w r1, sl, r0, lsl #0x3
       .text:0x0000E158    A6F81811             strh.w r1, [r6, #0x118]
       .text:0x0000E15C    B6F81A01             ldrh.w r0, [r6, #0x11A]
       .text:0x0000E160    00EE100A             vmov s0, r0
       .text:0x0000E164    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E168    00EE101A             vmov s0, r1
       .text:0x0000E16C    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000E170    40EE6D0A             vmls.f32 s1, s0, s27
       .text:0x0000E174    96ED360A             vldr s0, [r6, #0xD8]
       .text:0x0000E178    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000E17C    60EE800A             vmul.f32 s1, s1, s0
       .text:0x0000E180    80EEAA0A             vdiv.f32 s0, s1, s21
       .text:0x0000E184    86ED370A             vstr s0, [r6, #0xDC]
       .text:0x0000E188    00EE100A             vmov s0, r0
       .text:0x0000E18C    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000E190    00EE69DA             vmls.f32 s26, s0, s19
       .text:0x0000E194    96ED390A             vldr s0, [r6, #0xE4]
       .text:0x0000E198    30EE480A             vsub.f32 s0, s0, s16
       .text:0x0000E19C    2DEE000A             vmul.f32 s0, s26, s0
       .text:0x0000E1A0    C0EE090A             vdiv.f32 s1, s0, s18
       .text:0x0000E1A4    C6ED3A0A             vstr s1, [r6, #0xE8]
       .text:0x0000E1A8    0020                 movs r0, #0x0
       .text:0x0000E1AA    B14A                 ldr r2, [_0x20001FD4_4]
       */
    while (1) {
      /*
         .text:0x0000E1AC code_0xE1AC:
         .text:0x0000E1AC    00EB4001             add.w r1, r0, r0, lsl #0x1
         .text:0x0000E1B0    01EBC001             add.w r1, r1, r0, lsl #0x3
         .text:0x0000E1B4    02EB8101             add.w r1, r2, r1, lsl #0x2
         .text:0x0000E1B8    097E                 ldrb r1, [r1, #0x18]
         .text:0x0000E1BA    00E0                 b code_0xE1BE
         .text:0x0000E1BE code_0xE1BE:
         .text:0x0000E1BE    0329                 cmp r1, #0x3
         .text:0x0000E1C0    17D1                 bne code_0xE1F2

*/
      if (r1 == 3) {
        /*
           .text:0x0000E1C2 code_0xE1C2:
           .text:0x0000E1C2    B6F81811             ldrh.w r1, [r6, #0x118]
           .text:0x0000E1C6    00EE101A             vmov s0, r1
           .text:0x0000E1CA    08EB8001             add.w r1, r8, r0, lsl #0x2
           .text:0x0000E1CE    B8EE400A             vcvt.f32.u32 s0, s0
           .text:0x0000E1D2    D1ED080A             vldr s1, [r1, #0x20]
           .text:0x0000E1D6    06EB8001             add.w r1, r6, r0, lsl #0x2
           .text:0x0000E1DA    00EEE90A             vmls.f32 s0, s1, s19
           .text:0x0000E1DE    D6ED3C0A             vldr s1, [r6, #0xF0]
           .text:0x0000E1E2    70EEC80A             vsub.f32 s1, s1, s16
           .text:0x0000E1E6    20EE200A             vmul.f32 s0, s0, s1
           .text:0x0000E1EA    C0EE090A             vdiv.f32 s1, s0, s18
           .text:0x0000E1EE    C1ED3D0A             vstr s1, [r1, #0xF4]
           */
      }
      /*
         .text:0x0000E1F2 code_0xE1F2:
         .text:0x0000E1F2    401C                 adds r0, r0, #0x1
         .text:0x0000E1F4    0828                 cmp r0, #0x8
         .text:0x0000E1F6    D9DB                 blt code_0xE1AC
         */
    }
    /*
       .text:0x0000E1F8 code_0xE1F8:
       .text:0x0000E1F8    2620                 movs r0, #0x26
       .text:0x0000E1FA    F4F7B5FE             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E1FE code_0xE1FE:
     .text:0x0000E1FE    0320                 movs r0, #0x3
     .text:0x0000E200    FAF7E2F9             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E204    50B1                 cbz r0, code_0xE21C
     */
  if (r0 != 0) {
    /*
       .text:0x0000E206 code_0xE206:
       .text:0x0000E206    0320                 movs r0, #0x3
       .text:0x0000E208    0EF0BCFF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E20C    8200                 lsls r2, r0, #0x2
       .text:0x0000E20E    0221                 movs r1, #0x2
       .text:0x0000E210    0820                 movs r0, #0x8
       .text:0x0000E212    FBF701FF             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E216    0320                 movs r0, #0x3
       .text:0x0000E218    F4F7A6FE             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E21C code_0xE21C:
     .text:0x0000E21C    2120                 movs r0, #0x21
     .text:0x0000E21E    FAF7D3F9             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E222    50B1                 cbz r0, code_0xE23A
     */
  if (r0 != 0) {
    /*
       .text:0x0000E224 code_0xE224:
       .text:0x0000E224    2120                 movs r0, #0x21
       .text:0x0000E226    0EF0ADFF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E22A    8200                 lsls r2, r0, #0x2
       .text:0x0000E22C    0321                 movs r1, #0x3
       .text:0x0000E22E    0820                 movs r0, #0x8
       .text:0x0000E230    FBF7F2FE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E234    2120                 movs r0, #0x21
       .text:0x0000E236    F4F797FE             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E23A code_0xE23A:
     .text:0x0000E23A    3920                 movs r0, #0x39
     .text:0x0000E23C    FAF7C4F9             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E240    DFED8C8A             vldr s17, [data_0xE474]
     .text:0x0000E244    9FED8C9A             vldr s18, [data_0xE478]
     .text:0x0000E248    4FF6FF75             movw r5, #0xFFFF
     .text:0x0000E24C    0028                 cmp r0, #0x0
     .text:0x0000E24E    7CD0                 beq code_0xE34A
     */
  /*
     .text:0x0000E34A code_0xE34A:
     .text:0x0000E34A    10E0                 b code_0xE36E
     */
  if (r0 != 0) {
    /*
       .text:0x0000E250 code_0xE250:
       .text:0x0000E250    3920                 movs r0, #0x39
       .text:0x0000E252    0EF097FF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E256    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000E25A    A081                 strh r0, [r4, #0xC]
       .text:0x0000E25C    0D20                 movs r0, #0xD
       .text:0x0000E25E    0EF091FF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E262    00EE100A             vmov s0, r0
       .text:0x0000E266    0720                 movs r0, #0x7
       .text:0x0000E268    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E26C    0EF08AFF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E270    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E274    01EBD171             add.w r1, r1, r1, lsr #0x1F
       .text:0x0000E278    4910                 asrs r1, r1, #0x1
       .text:0x0000E27A    C1F58071             rsb.w r1, r1, #0x100
       .text:0x0000E27E    A1EB5000             sub.w r0, r1, r0, lsr #0x1
       .text:0x0000E282    00EE100A             vmov s0, r0
       .text:0x0000E286    B8EEC01A             vcvt.f32.s32 s2, s0
       .text:0x0000E28A    81EE280A             vdiv.f32 s0, s2, s17
       .text:0x0000E28E    30EE090A             vadd.f32 s0, s0, s18
       .text:0x0000E292    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000E296    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000E29A    10EE100A             vmov r0, s0
       .text:0x0000E29E    05EA8000             and.w r0, r5, r0, lsl #0x2
       .text:0x0000E2A2    F9F743FD             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
       .text:0x0000E2A6    0246                 mov r2, r0
       .text:0x0000E2A8    0021                 movs r1, #0x0
       .text:0x0000E2AA    0920                 movs r0, #0x9
       .text:0x0000E2AC    FBF7B4FE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E2B0    1B20                 movs r0, #0x1B
       .text:0x0000E2B2    0EF067FF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E2B6    00EE100A             vmov s0, r0
       .text:0x0000E2BA    2520                 movs r0, #0x25
       .text:0x0000E2BC    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E2C0    0EF060FF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E2C4    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E2C8    01EBD171             add.w r1, r1, r1, lsr #0x1F
       .text:0x0000E2CC    4910                 asrs r1, r1, #0x1
       .text:0x0000E2CE    C1F58071             rsb.w r1, r1, #0x100
       .text:0x0000E2D2    A1EB5000             sub.w r0, r1, r0, lsr #0x1
       .text:0x0000E2D6    00EE100A             vmov s0, r0
       .text:0x0000E2DA    B8EEC00A             vcvt.f32.s32 s0, s0
       .text:0x0000E2DE    80EE281A             vdiv.f32 s2, s0, s17
       .text:0x0000E2E2    31EE090A             vadd.f32 s0, s2, s18
       .text:0x0000E2E6    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000E2EA    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000E2EE    10EE100A             vmov r0, s0
       .text:0x0000E2F2    05EA8000             and.w r0, r5, r0, lsl #0x2
       .text:0x0000E2F6    F9F719FD             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
       .text:0x0000E2FA    0246                 mov r2, r0
       .text:0x0000E2FC    0121                 movs r1, #0x1
       .text:0x0000E2FE    0920                 movs r0, #0x9
       .text:0x0000E300    FBF78AFE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E304    0720                 movs r0, #0x7
       .text:0x0000E306    0EF03DFF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E30A    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E30E    0844                 add r0, r1
       .text:0x0000E310    05EA4002             and.w r2, r5, r0, lsl #0x1
       .text:0x0000E314    0621                 movs r1, #0x6
       .text:0x0000E316    0820                 movs r0, #0x8
       .text:0x0000E318    FBF77EFE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E31C    2520                 movs r0, #0x25
       .text:0x0000E31E    0EF031FF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E322    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E326    0844                 add r0, r1
       .text:0x0000E328    05EA4002             and.w r2, r5, r0, lsl #0x1
       .text:0x0000E32C    0721                 movs r1, #0x7
       .text:0x0000E32E    0820                 movs r0, #0x8
       .text:0x0000E330    FBF772FE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E334    0520                 movs r0, #0x5
       .text:0x0000E336    0EF025FF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E33A    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E33E    0844                 add r0, r1
       .text:0x0000E340    05EA4002             and.w r2, r5, r0, lsl #0x1
       .text:0x0000E344    0421                 movs r1, #0x4
       .text:0x0000E346    0820                 movs r0, #0x8
       .text:0x0000E348    00E0                 b code_0xE34C
      */
      /*
         .text:0x0000E34C code_0xE34C:
         .text:0x0000E34C    FBF764FE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
         .text:0x0000E350    2320                 movs r0, #0x23
         .text:0x0000E352    0EF017FF             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000E356    B4F90C10             ldrsh.w r1, [r4, #0xC]
         .text:0x0000E35A    0844                 add r0, r1
         .text:0x0000E35C    05EA4002             and.w r2, r5, r0, lsl #0x1
         .text:0x0000E360    0521                 movs r1, #0x5
         .text:0x0000E362    0820                 movs r0, #0x8
         .text:0x0000E364    FBF758FE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
         .text:0x0000E368    3920                 movs r0, #0x39
         .text:0x0000E36A    F4F7FDFD             bl func_0x2F68; inline void __cdecl( int p1 )
         */
  }
  /*
     .text:0x0000E36E code_0xE36E:
     .text:0x0000E36E    0720                 movs r0, #0x7
     .text:0x0000E370    FAF72AF9             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E374    E8B3                 cbz r0, code_0xE3F2
     .text:0x0000E3F2 code_0xE3F2:
     .text:0x0000E3F2    01E0                 b code_0xE3F8
     */
  if (r0 != 0) {
    /*
       .text:0x0000E376 code_0xE376:
       .text:0x0000E376    3920                 movs r0, #0x39
       .text:0x0000E378    0EF004FF             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E37C    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000E380    A081                 strh r0, [r4, #0xC]
       .text:0x0000E382    0720                 movs r0, #0x7
       .text:0x0000E384    0EF0FEFE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E388    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E38C    0844                 add r0, r1
       .text:0x0000E38E    05EA4002             and.w r2, r5, r0, lsl #0x1
       .text:0x0000E392    0621                 movs r1, #0x6
       .text:0x0000E394    0820                 movs r0, #0x8
       .text:0x0000E396    FBF73FFE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E39A    0D20                 movs r0, #0xD
       .text:0x0000E39C    0EF0F2FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E3A0    00EE100A             vmov s0, r0
       .text:0x0000E3A4    0720                 movs r0, #0x7
       .text:0x0000E3A6    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E3AA    0EF0EBFE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E3AE    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E3B2    01EBD171             add.w r1, r1, r1, lsr #0x1F
       .text:0x0000E3B6    4910                 asrs r1, r1, #0x1
       .text:0x0000E3B8    C1F58071             rsb.w r1, r1, #0x100
       .text:0x0000E3BC    A1EB5000             sub.w r0, r1, r0, lsr #0x1
       .text:0x0000E3C0    00EE100A             vmov s0, r0
       .text:0x0000E3C4    B8EEC01A             vcvt.f32.s32 s2, s0
       .text:0x0000E3C8    81EE280A             vdiv.f32 s0, s2, s17
       .text:0x0000E3CC    30EE090A             vadd.f32 s0, s0, s18
       .text:0x0000E3D0    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000E3D4    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000E3D8    10EE100A             vmov r0, s0
       .text:0x0000E3DC    05EA8000             and.w r0, r5, r0, lsl #0x2
       .text:0x0000E3E0    F9F7A4FC             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
       .text:0x0000E3E4    0246                 mov r2, r0
       .text:0x0000E3E6    0021                 movs r1, #0x0
       .text:0x0000E3E8    0920                 movs r0, #0x9
       .text:0x0000E3EA    FBF715FE             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E3EE    0720                 movs r0, #0x7
       .text:0x0000E3F0    00E0                 b code_0xE3F4
       */
    /*
       .text:0x0000E3F4 code_0xE3F4:
       .text:0x0000E3F4    F4F7B8FD             bl func_0x2F68; inline void __cdecl( int p1 )

*/
  }
  /*
     .text:0x0000E3F8 code_0xE3F8:
     .text:0x0000E3F8    2520                 movs r0, #0x25
     .text:0x0000E3FA    FAF7E5F8             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E3FE    E8B3                 cbz r0, code_0xE47C
     */
  /*
     .text:0x0000E47C code_0xE47C:
     .text:0x0000E47C    07E0                 b code_0xE48E
     */
  if (r0 != 0) {
    /*
       .text:0x0000E400 code_0xE400:
       .text:0x0000E400    3920                 movs r0, #0x39
       .text:0x0000E402    0EF0BFFE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E406    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000E40A    A081                 strh r0, [r4, #0xC]
       .text:0x0000E40C    2520                 movs r0, #0x25
       .text:0x0000E40E    0EF0B9FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E412    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E416    0844                 add r0, r1
       .text:0x0000E418    05EA4002             and.w r2, r5, r0, lsl #0x1
       .text:0x0000E41C    0721                 movs r1, #0x7
       .text:0x0000E41E    0820                 movs r0, #0x8
       .text:0x0000E420    FBF7FAFD             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E424    1B20                 movs r0, #0x1B
       .text:0x0000E426    0EF0ADFE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E42A    00EE100A             vmov s0, r0
       .text:0x0000E42E    2520                 movs r0, #0x25
       .text:0x0000E430    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E434    0EF0A6FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E438    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E43C    01EBD171             add.w r1, r1, r1, lsr #0x1F
       .text:0x0000E440    4910                 asrs r1, r1, #0x1
       .text:0x0000E442    C1F58071             rsb.w r1, r1, #0x100
       .text:0x0000E446    A1EB5000             sub.w r0, r1, r0, lsr #0x1
       .text:0x0000E44A    00EE100A             vmov s0, r0
       .text:0x0000E44E    B8EEC01A             vcvt.f32.s32 s2, s0
       .text:0x0000E452    81EE280A             vdiv.f32 s0, s2, s17
       .text:0x0000E456    30EE090A             vadd.f32 s0, s0, s18
       .text:0x0000E45A    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000E45E    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000E462    10EE100A             vmov r0, s0
       .text:0x0000E466    05EA8000             and.w r0, r5, r0, lsl #0x2
       .text:0x0000E46A    F9F75FFC             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
       .text:0x0000E46E    06E0                 b code_0xE47E
       */
    /*
       .text:0x0000E47E code_0xE47E:
       .text:0x0000E47E    0246                 mov r2, r0
       .text:0x0000E480    0121                 movs r1, #0x1
       .text:0x0000E482    0920                 movs r0, #0x9
       .text:0x0000E484    FBF7C8FD             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E488    2520                 movs r0, #0x25
       .text:0x0000E48A    F4F76DFD             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E48E code_0xE48E:
     .text:0x0000E48E    0520                 movs r0, #0x5
     .text:0x0000E490    FAF79AF8             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E494    70B1                 cbz r0, code_0xE4B4
     */
  if (r0 != 0) {
    /*
       .text:0x0000E496 code_0xE496:
       .text:0x0000E496    0520                 movs r0, #0x5
       .text:0x0000E498    0EF074FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E49C    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E4A0    0844                 add r0, r1
       .text:0x0000E4A2    05EA4002             and.w r2, r5, r0, lsl #0x1
       .text:0x0000E4A6    0421                 movs r1, #0x4
       .text:0x0000E4A8    0820                 movs r0, #0x8
       .text:0x0000E4AA    FBF7B5FD             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E4AE    0520                 movs r0, #0x5
       .text:0x0000E4B0    F4F75AFD             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E4B4 code_0xE4B4:
     .text:0x0000E4B4    2320                 movs r0, #0x23
     .text:0x0000E4B6    FAF787F8             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E4BA    70B1                 cbz r0, code_0xE4DA
     */
  if (r0 != 0) {
    /*
       .text:0x0000E4BC code_0xE4BC:
       .text:0x0000E4BC    2320                 movs r0, #0x23
       .text:0x0000E4BE    0EF061FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E4C2    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E4C6    0844                 add r0, r1
       .text:0x0000E4C8    05EA4002             and.w r2, r5, r0, lsl #0x1
       .text:0x0000E4CC    0521                 movs r1, #0x5
       .text:0x0000E4CE    0820                 movs r0, #0x8
       .text:0x0000E4D0    FBF7A2FD             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E4D4    2320                 movs r0, #0x23
       .text:0x0000E4D6    F4F747FD             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E4DA code_0xE4DA:
     .text:0x0000E4DA    0D20                 movs r0, #0xD
     .text:0x0000E4DC    FAF774F8             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E4E0    90B3                 cbz r0, code_0xE548
     */
  if (r0 != 0) {
    /*
       .text:0x0000E4E2 code_0xE4E2:
       .text:0x0000E4E2    3920                 movs r0, #0x39
       .text:0x0000E4E4    0EF04EFE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E4E8    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000E4EC    A081                 strh r0, [r4, #0xC]
       .text:0x0000E4EE    0D20                 movs r0, #0xD
       .text:0x0000E4F0    0EF048FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E4F4    00EE100A             vmov s0, r0
       .text:0x0000E4F8    0720                 movs r0, #0x7
       .text:0x0000E4FA    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E4FE    0EF041FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E502    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E506    01EBD171             add.w r1, r1, r1, lsr #0x1F
       .text:0x0000E50A    4910                 asrs r1, r1, #0x1
       .text:0x0000E50C    C1F58071             rsb.w r1, r1, #0x100
       .text:0x0000E510    A1EB5000             sub.w r0, r1, r0, lsr #0x1
       .text:0x0000E514    00EE100A             vmov s0, r0
       .text:0x0000E518    B8EEC01A             vcvt.f32.s32 s2, s0
       .text:0x0000E51C    81EE280A             vdiv.f32 s0, s2, s17
       .text:0x0000E520    30EE090A             vadd.f32 s0, s0, s18
       .text:0x0000E524    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000E528    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000E52C    10EE100A             vmov r0, s0
       .text:0x0000E530    05EA8000             and.w r0, r5, r0, lsl #0x2
       .text:0x0000E534    F9F7FAFB             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
       .text:0x0000E538    0246                 mov r2, r0
       .text:0x0000E53A    0021                 movs r1, #0x0
       .text:0x0000E53C    0920                 movs r0, #0x9
       .text:0x0000E53E    FBF76BFD             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E542    0D20                 movs r0, #0xD
       .text:0x0000E544    F4F710FD             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E548 code_0xE548:
     .text:0x0000E548    1B20                 movs r0, #0x1B
     .text:0x0000E54A    FAF73DF8             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E54E    90B3                 cbz r0, code_0xE5B6
     */
  if (r0 !=0) {
    /*
       .text:0x0000E550 code_0xE550:
       .text:0x0000E550    3920                 movs r0, #0x39
       .text:0x0000E552    0EF017FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E556    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000E55A    A081                 strh r0, [r4, #0xC]
       .text:0x0000E55C    1B20                 movs r0, #0x1B
       .text:0x0000E55E    0EF011FE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E562    00EE100A             vmov s0, r0
       .text:0x0000E566    2520                 movs r0, #0x25
       .text:0x0000E568    F8EE400A             vcvt.f32.u32 s1, s0
       .text:0x0000E56C    0EF00AFE             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E570    B4F90C10             ldrsh.w r1, [r4, #0xC]
       .text:0x0000E574    01EBD171             add.w r1, r1, r1, lsr #0x1F
       .text:0x0000E578    4910                 asrs r1, r1, #0x1
       .text:0x0000E57A    C1F58071             rsb.w r1, r1, #0x100
       .text:0x0000E57E    A1EB5000             sub.w r0, r1, r0, lsr #0x1
       .text:0x0000E582    00EE100A             vmov s0, r0
       .text:0x0000E586    B8EEC00A             vcvt.f32.s32 s0, s0
       .text:0x0000E58A    80EE281A             vdiv.f32 s2, s0, s17
       .text:0x0000E58E    31EE090A             vadd.f32 s0, s2, s18
       .text:0x0000E592    20EE800A             vmul.f32 s0, s1, s0
       .text:0x0000E596    BCEEC00A             vcvt.u32.f32 s0, s0
       .text:0x0000E59A    10EE100A             vmov r0, s0
       .text:0x0000E59E    05EA8000             and.w r0, r5, r0, lsl #0x2
       .text:0x0000E5A2    F9F7C3FB             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
       .text:0x0000E5A6    0246                 mov r2, r0
       .text:0x0000E5A8    0121                 movs r1, #0x1
       .text:0x0000E5AA    0920                 movs r0, #0x9
       .text:0x0000E5AC    FBF734FD             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E5B0    1B20                 movs r0, #0x1B
       .text:0x0000E5B2    F4F7D9FC             bl func_0x2F68; inline void __cdecl( int p1 )

*/
  }
  /*
     .text:0x0000E5B6 code_0xE5B6:
     .text:0x0000E5B6    0E20                 movs r0, #0xE
     .text:0x0000E5B8    FAF706F8             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E5BC    68B1                 cbz r0, code_0xE5DA
     */
  if ( r0 != 0 ) {
    /*
       .text:0x0000E5BE code_0xE5BE:
       .text:0x0000E5BE    0E20                 movs r0, #0xE
       .text:0x0000E5C0    0EF0E0FD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E5C4    8000                 lsls r0, r0, #0x2
       .text:0x0000E5C6    F9F7B1FB             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
       .text:0x0000E5CA    0246                 mov r2, r0
       .text:0x0000E5CC    0221                 movs r1, #0x2
       .text:0x0000E5CE    0920                 movs r0, #0x9
       .text:0x0000E5D0    FBF722FD             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E5D4    0E20                 movs r0, #0xE
       .text:0x0000E5D6    F4F7C7FC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E5DA code_0xE5DA:
     .text:0x0000E5DA    1C20                 movs r0, #0x1C
     .text:0x0000E5DC    F9F7F4FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E5E0    68B1                 cbz r0, code_0xE5FE
     */
  if (r0 != 0) {
    /*
       .text:0x0000E5E2 code_0xE5E2:
       .text:0x0000E5E2    1C20                 movs r0, #0x1C
       .text:0x0000E5E4    0EF0CEFD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E5E8    8000                 lsls r0, r0, #0x2
       .text:0x0000E5EA    F9F79FFB             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
       .text:0x0000E5EE    0246                 mov r2, r0
       .text:0x0000E5F0    0321                 movs r1, #0x3
       .text:0x0000E5F2    0920                 movs r0, #0x9
       .text:0x0000E5F4    FBF710FD             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E5F8    1C20                 movs r0, #0x1C
       .text:0x0000E5FA    F4F7B5FC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E5FE code_0xE5FE:
     .text:0x0000E5FE    3720                 movs r0, #0x37
     .text:0x0000E600    F9F7E2FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E604    E8B3                 cbz r0, code_0xE682
     */
  /*
     .text:0x0000E682 code_0xE682:
     .text:0x0000E682    22E0                 b code_0xE6CA
     */
  if (r0 != 0) {
    /*
       .text:0x0000E606 code_0xE606:
       .text:0x0000E606    3720                 movs r0, #0x37
       .text:0x0000E608    0EF0BCFD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E60C    9BF87513             ldrb.w r1, [fp, #0x375]
       .text:0x0000E610    99B1                 cbz r1, code_0xE63A
       */
    if (r1 == 0) {
      /*
         .text:0x0000E63A code_0xE63A:
         .text:0x0000E63A    9BF87C13             ldrb.w r1, [fp, #0x37C]
         .text:0x0000E63E    E9E7                 b code_0xE614
         */
    } else {
      /*
         .text:0x0000E612 code_0xE612:
         .text:0x0000E612    7F21                 movs r1, #0x7F
         */
    }
    /*
       .text:0x0000E614 code_0xE614:
       .text:0x0000E614    401A                 subs r0, r0, r1
       .text:0x0000E616    00B2                 sxth r0, r0
       .text:0x0000E618    00F10902             add.w r2, r0, #0x9
       .text:0x0000E61C    132A                 cmp r2, #0x13
       .text:0x0000E61E    0FD2                 bhs code_0xE640
       */
    if (r2 < 0x13) {
      /*
         .text:0x0000E620 code_0xE620:
         .text:0x0000E620    40F2FF32             movw r2, #0x3FF
         .text:0x0000E624    0521                 movs r1, #0x5
         .text:0x0000E626    0920                 movs r0, #0x9
         .text:0x0000E628    FBF7F6FC             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
         .text:0x0000E62C    40F2FF32             movw r2, #0x3FF
         .text:0x0000E630    0421                 movs r1, #0x4
         .text:0x0000E632    0920                 movs r0, #0x9
         .text:0x0000E634    FBF7F0FC             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
         .text:0x0000E638    44E0                 b code_0xE6C4
         */
    } else {
      /*
         .text:0x0000E640 code_0xE640:
         .text:0x0000E640    4FF48066             mov.w r6, #0x400
         .text:0x0000E644    0028                 cmp r0, #0x0
         .text:0x0000E646    20DD                 ble code_0xE68A
         */
      if (r0 > 0) {
        /*
           .text:0x0000E648 code_0xE648:
           .text:0x0000E648    F229                 cmp r1, #0xF2
           .text:0x0000E64A    07D0                 beq code_0xE65C
           */
        if (r1 != 0xF2) {
          /*
             .text:0x0000E64C code_0xE64C:
             .text:0x0000E64C    0A38                 subs r0, #0xA
             .text:0x0000E64E    C001                 lsls r0, r0, #0x7
             .text:0x0000E650    C1F1F201             rsb.w r1, r1, #0xF2
             .text:0x0000E654    90FBF1F0             sdiv r0, r0, r1
             .text:0x0000E658    05B2                 sxth r5, r0
             .text:0x0000E65A    00E0                 b code_0xE65E
             */
        } else {
          /*
             .text:0x0000E65C code_0xE65C:
             .text:0x0000E65C    0025                 movs r5, #0x0
             */
        }
        /*
           .text:0x0000E65E code_0xE65E:
           .text:0x0000E65E    002D                 cmp r5, #0x0
           .text:0x0000E660    00DA                 bge code_0xE664
           */
        if (r5 < 0) {
          /*
             .text:0x0000E662 code_0xE662:
             .text:0x0000E662    0025                 movs r5, #0x0
             */
        }
        /*
           .text:0x0000E664 code_0xE664:
           .text:0x0000E664    40F2FF32             movw r2, #0x3FF
           .text:0x0000E668    0421                 movs r1, #0x4
           .text:0x0000E66A    0920                 movs r0, #0x9
           .text:0x0000E66C    FBF7D4FC             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
           .text:0x0000E670    A6EBC500             sub.w r0, r6, r5, lsl #0x3
           .text:0x0000E674    80B2                 uxth r0, r0
           .text:0x0000E676    F9F759FB             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
           .text:0x0000E67A    0246                 mov r2, r0
           .text:0x0000E67C    0521                 movs r1, #0x5
           .text:0x0000E67E    0920                 movs r0, #0x9
           .text:0x0000E680    00E0                 b code_0xE684
           */
        /*
           .text:0x0000E684 code_0xE684:
           .text:0x0000E684    FBF7C8FC             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
           .text:0x0000E688    1CE0                 b code_0xE6C4
           */
      } else {
        /*
           .text:0x0000E68A code_0xE68A:
           .text:0x0000E68A    0A29                 cmp r1, #0xA
           .text:0x0000E68C    06D0                 beq code_0xE69C
           */
        if (r1 != 0xA) {
          /*
             .text:0x0000E68E code_0xE68E:
             .text:0x0000E68E    0A30                 adds r0, #0xA
             .text:0x0000E690    C001                 lsls r0, r0, #0x7
             .text:0x0000E692    0A39                 subs r1, #0xA
             .text:0x0000E694    90FBF1F0             sdiv r0, r0, r1
             .text:0x0000E698    05B2                 sxth r5, r0
             .text:0x0000E69A    00E0                 b code_0xE69E
             */
        } else {
          /*
             .text:0x0000E69C code_0xE69C:
             .text:0x0000E69C    0025                 movs r5, #0x0
             */
        }
        /*
           .text:0x0000E69E code_0xE69E:
           .text:0x0000E69E    002D                 cmp r5, #0x0
           .text:0x0000E6A0    00DD                 ble code_0xE6A4
           */
        if (r5 > 0)  {
          /*
             .text:0x0000E6A2 code_0xE6A2:
             .text:0x0000E6A2    0025                 movs r5, #0x0      
             */
        }
        /*
           .text:0x0000E6A4 code_0xE6A4:
           .text:0x0000E6A4    40F2FF32             movw r2, #0x3FF
           .text:0x0000E6A8    0521                 movs r1, #0x5
           .text:0x0000E6AA    0920                 movs r0, #0x9
           .text:0x0000E6AC    FBF7B4FC             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
           .text:0x0000E6B0    06EBC500             add.w r0, r6, r5, lsl #0x3
           .text:0x0000E6B4    80B2                 uxth r0, r0
           .text:0x0000E6B6    F9F739FB             bl get_equiv_between_0_and_1023_times_two_plus_0804A024; int __cdecl( int p1 )
           .text:0x0000E6BA    0246                 mov r2, r0
           .text:0x0000E6BC    0421                 movs r1, #0x4
           .text:0x0000E6BE    0920                 movs r0, #0x9
           .text:0x0000E6C0    FBF7AAFC             bl set_2000xxB4; void __cdecl( int p1, int p2, int p3 )
           */
      }
    }
    /*
       .text:0x0000E6C4 code_0xE6C4:
       .text:0x0000E6C4    3720                 movs r0, #0x37
       .text:0x0000E6C6    F4F74FFC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E6CA code_0xE6CA:
     .text:0x0000E6CA    0420                 movs r0, #0x4
     .text:0x0000E6CC    F9F77CFF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E6D0    F74E                 ldr r6, [string_tR_2]; "tR"
     .text:0x0000E6D2    40B1                 cbz r0, code_0xE6E6
     */
  if (r0 != 0) {
    /*
       .text:0x0000E6D4 code_0xE6D4:
       .text:0x0000E6D4    0420                 movs r0, #0x4
       .text:0x0000E6D6    0EF055FD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E6DA    0001                 lsls r0, r0, #0x4
       .text:0x0000E6DC    A6F84000             strh.w r0, [r6, #0x40]
       .text:0x0000E6E0    0420                 movs r0, #0x4
       .text:0x0000E6E2    F4F741FC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E6E6 code_0xE6E6:
     .text:0x0000E6E6    0620                 movs r0, #0x6
     .text:0x0000E6E8    F9F76EFF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E6EC    40B1                 cbz r0, code_0xE700
     */
  if (r0 != 0) {
    /*
       .text:0x0000E6EE code_0xE6EE:
       .text:0x0000E6EE    0620                 movs r0, #0x6
       .text:0x0000E6F0    0EF048FD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E6F4    0001                 lsls r0, r0, #0x4
       .text:0x0000E6F6    A6F84200             strh.w r0, [r6, #0x42]
       .text:0x0000E6FA    0620                 movs r0, #0x6
       .text:0x0000E6FC    F4F734FC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E700 code_0xE700:
     .text:0x0000E700    2220                 movs r0, #0x22
     .text:0x0000E702    F9F761FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E706    40B1                 cbz r0, code_0xE71A
     */
  if (r0 != 0) {
    /*
       .text:0x0000E708 code_0xE708:
       .text:0x0000E708    2220                 movs r0, #0x22
       .text:0x0000E70A    0EF03BFD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E70E    0001                 lsls r0, r0, #0x4
       .text:0x0000E710    A6F84400             strh.w r0, [r6, #0x44]
       .text:0x0000E714    2220                 movs r0, #0x22
       .text:0x0000E716    F4F727FC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E71A code_0xE71A:
     .text:0x0000E71A    2420                 movs r0, #0x24
     .text:0x0000E71C    F9F754FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E720    40B1                 cbz r0, code_0xE734
     */
  if (r0 != 0) {
    /*
       .text:0x0000E722 code_0xE722:
       .text:0x0000E722    2420                 movs r0, #0x24
       .text:0x0000E724    0EF02EFD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E728    0001                 lsls r0, r0, #0x4
       .text:0x0000E72A    A6F84600             strh.w r0, [r6, #0x46]
       .text:0x0000E72E    2420                 movs r0, #0x24
       .text:0x0000E730    F4F71AFC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E734 code_0xE734:
     .text:0x0000E734    1320                 movs r0, #0x13
     .text:0x0000E736    F9F747FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E73A    DE4D                 ldr r5, [_0x20005088]
     .text:0x0000E73C    48B1                 cbz r0, code_0xE752
     */
  if (r0 != 0) {
    /*
       .text:0x0000E73E code_0xE73E:
       .text:0x0000E73E    1320                 movs r0, #0x13
       .text:0x0000E740    0EF020FD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E744    3730                 adds r0, #0x37
       .text:0x0000E746    C000                 lsls r0, r0, #0x3
       .text:0x0000E748    A5F8E000             strh.w r0, [r5, #0xE0]
       .text:0x0000E74C    1320                 movs r0, #0x13
       .text:0x0000E74E    F4F70BFC             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E752 code_0xE752:
     .text:0x0000E752    2B20                 movs r0, #0x2B
     .text:0x0000E754    F9F738FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E758    48B1                 cbz r0, code_0xE76E
     */
  if (r0 != 0) {
    /*
       .text:0x0000E75A code_0xE75A:
       .text:0x0000E75A    2B20                 movs r0, #0x2B
       .text:0x0000E75C    0EF012FD             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E760    3730                 adds r0, #0x37
       .text:0x0000E762    C000                 lsls r0, r0, #0x3
       .text:0x0000E764    A5F8E200             strh.w r0, [r5, #0xE2]
       .text:0x0000E768    2B20                 movs r0, #0x2B
       .text:0x0000E76A    F4F7FDFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E76E code_0xE76E:
     .text:0x0000E76E    3520                 movs r0, #0x35
     .text:0x0000E770    F9F72AFF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E774    70B1                 cbz r0, code_0xE794
     */
  if (r0 != 0) {
    /*
       .text:0x0000E776 code_0xE776:
       .text:0x0000E776    FDF7BFFA             bl func_0xBCF8; int __cdecl( void )
       .text:0x0000E77A    3528                 cmp r0, #0x35
       .text:0x0000E77C    7ED0                 beq code_0xE87C
       */
    if (r0 != 0x35) {
      /*
         .text:0x0000E77E code_0xE77E:
         .text:0x0000E77E    3520                 movs r0, #0x35
         .text:0x0000E780    0EF000FD             bl func_0x1D184; int __cdecl( int p1, int p2 )
         */
    } else {
      /*
         .text:0x0000E87C code_0xE87C:
         .text:0x0000E87C    5BE0                 b code_0xE936
         */
      /*
         .text:0x0000E936 code_0xE936:
         .text:0x0000E936    3520                 movs r0, #0x35
         .text:0x0000E938    0EF024FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000E93C    0746                 mov r7, r0
         .text:0x0000E93E    FDF7E3F9             bl func_0xBD08; inline int __cdecl( void )
         .text:0x0000E942    381A                 subs r0, r7, r0
         .text:0x0000E944    00B2                 sxth r0, r0
         .text:0x0000E946    FF28                 cmp r0, #0xFF
         .text:0x0000E948    01DD                 ble code_0xE94E
         */
      if (r0 > 0xFF) {
        /*
           .text:0x0000E94A code_0xE94A:
           .text:0x0000E94A    FF20                 movs r0, #0xFF
           .text:0x0000E94C    1AE7                 b code_0xE784
           */
      } else {
        /*
           .text:0x0000E94E code_0xE94E:
           .text:0x0000E94E    0028                 cmp r0, #0x0
           .text:0x0000E950    BFF618AF             bge.w code_0xE784
           */
        if (r0 < 0) {
          /*
             .text:0x0000E954 code_0xE954:
             .text:0x0000E954    0020                 movs r0, #0x0
             .text:0x0000E956    15E7                 b code_0xE784
             */
        }
      }
    }
    /*
       .text:0x0000E784 code_0xE784:
       .text:0x0000E784    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000E788    4000                 lsls r0, r0, #0x1
       .text:0x0000E78A    A8F84A00             strh.w r0, [r8, #0x4A]
       .text:0x0000E78E    3520                 movs r0, #0x35
       .text:0x0000E790    F4F7EAFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E794 code_0xE794:
     .text:0x0000E794    3620                 movs r0, #0x36
     .text:0x0000E796    F9F717FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E79A    70B1                 cbz r0, code_0xE7BA
     */
  if (r0 != 0) {
    /*
       .text:0x0000E79C code_0xE79C:
       .text:0x0000E79C    FDF7ACFA             bl func_0xBCF8; int __cdecl( void )
       .text:0x0000E7A0    3628                 cmp r0, #0x36
       .text:0x0000E7A2    6CD0                 beq code_0xE87E
       */
    if (r0 != 0x36) {
      /*
         .text:0x0000E7A4 code_0xE7A4:
         .text:0x0000E7A4    3620                 movs r0, #0x36
         .text:0x0000E7A6    0EF0EDFC             bl func_0x1D184; int __cdecl( int p1, int p2 )
         */
    } else {
      /*
         .text:0x0000E87E code_0xE87E:
         .text:0x0000E87E    6BE0                 b code_0xE958
         */
      /*
         .text:0x0000E958 code_0xE958:
         .text:0x0000E958    3620                 movs r0, #0x36
         .text:0x0000E95A    0EF013FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000E95E    0746                 mov r7, r0
         .text:0x0000E960    FDF7D2F9             bl func_0xBD08; inline int __cdecl( void )
         .text:0x0000E964    381A                 subs r0, r7, r0
         .text:0x0000E966    00B2                 sxth r0, r0
         .text:0x0000E968    FF28                 cmp r0, #0xFF
         .text:0x0000E96A    01DD                 ble code_0xE970
         */
      if (r0 > 0xFF) {
        /*
           .text:0x0000E96C code_0xE96C:
           .text:0x0000E96C    FF20                 movs r0, #0xFF
           .text:0x0000E96E    1CE7                 b code_0xE7AA
           */
      }
      /*
         .text:0x0000E970 code_0xE970:
         .text:0x0000E970    0028                 cmp r0, #0x0
         .text:0x0000E972    BFF61AAF             bge.w code_0xE7AA
         */
      if (r0 < 0x0) {
        /*
           .text:0x0000E976 code_0xE976:
           .text:0x0000E976    0020                 movs r0, #0x0
           .text:0x0000E978    17E7                 b code_0xE7AA
           */
      }
    }
    /*
       .text:0x0000E7AA code_0xE7AA:
       .text:0x0000E7AA    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000E7AE    4000                 lsls r0, r0, #0x1
       .text:0x0000E7B0    A5F8E400             strh.w r0, [r5, #0xE4]
       .text:0x0000E7B4    3620                 movs r0, #0x36
       .text:0x0000E7B6    F4F7D7FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E7BA code_0xE7BA:
     .text:0x0000E7BA    3820                 movs r0, #0x38
     .text:0x0000E7BC    F9F704FF             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E7C0    C8B1                 cbz r0, code_0xE7F6
     */
  if ( r0 != 0 ) {
    /*
       .text:0x0000E7C2 code_0xE7C2:
       .text:0x0000E7C2    FDF799FA             bl func_0xBCF8; int __cdecl( void )
       .text:0x0000E7C6    3828                 cmp r0, #0x38
       .text:0x0000E7C8    7ED0                 beq code_0xE8C8
       */
    if (r0 != 0x38) {
      /*
         .text:0x0000E7CA code_0xE7CA:
         .text:0x0000E7CA    3820                 movs r0, #0x38
         .text:0x0000E7CC    0EF0DAFC             bl func_0x1D184; int __cdecl( int p1, int p2 )
         */
    } else {
      /*
         .text:0x0000E8C8 code_0xE8C8:
         .text:0x0000E8C8    57E0                 b code_0xE97A
         */
      /*
         .text:0x0000E97A code_0xE97A:
         .text:0x0000E97A    3820                 movs r0, #0x38
         .text:0x0000E97C    0EF002FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000E980    0746                 mov r7, r0
         .text:0x0000E982    FDF7C1F9             bl func_0xBD08; inline int __cdecl( void )
         .text:0x0000E986    381A                 subs r0, r7, r0
         .text:0x0000E988    00B2                 sxth r0, r0
         .text:0x0000E98A    FF28                 cmp r0, #0xFF
         .text:0x0000E98C    02DD                 ble code_0xE994
         */
      if (r0 > 0xFF) {
        /*
           .text:0x0000E98E code_0xE98E:
           .text:0x0000E98E    FF20                 movs r0, #0xFF
           .text:0x0000E990    1EE7                 b code_0xE7D0
           */
      }
      /*
         .text:0x0000E994 code_0xE994:
         .text:0x0000E994    0028                 cmp r0, #0x0
         .text:0x0000E996    BFF61BAF             bge.w code_0xE7D0
         */
      if (r0 < 0) {
        /*
           .text:0x0000E99A code_0xE99A:
           .text:0x0000E99A    0020                 movs r0, #0x0
           .text:0x0000E99C    18E7                 b code_0xE7D0
           */
      }
    }
    /*
       .text:0x0000E7D0 code_0xE7D0:
       .text:0x0000E7D0    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000E7D4    4000                 lsls r0, r0, #0x1
       .text:0x0000E7D6    00B2                 sxth r0, r0
       .text:0x0000E7D8    A8F84800             strh.w r0, [r8, #0x48]
       .text:0x0000E7DC    B649                 ldr r1, [_0x0804D024]
       .text:0x0000E7DE    31F81010             ldrh.w r1, [r1, r0, lsl #0x1]
       .text:0x0000E7E2    A6F84810             strh.w r1, [r6, #0x48]
       .text:0x0000E7E6    B549                 ldr r1, [_0x0804D424]
       .text:0x0000E7E8    31F81000             ldrh.w r0, [r1, r0, lsl #0x1]
       .text:0x0000E7EC    A6F84A00             strh.w r0, [r6, #0x4A]
       .text:0x0000E7F0    3820                 movs r0, #0x38
       .text:0x0000E7F2    F4F7B9FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E7F6 code_0xE7F6:
     .text:0x0000E7F6    1420                 movs r0, #0x14
     .text:0x0000E7F8    F9F7E6FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E7FC    40B1                 cbz r0, code_0xE810
     */
  if (r0 != 0) {
    /*
       .text:0x0000E7FE code_0xE7FE:
       .text:0x0000E7FE    1420                 movs r0, #0x14
       .text:0x0000E800    0EF0C0FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E804    0001                 lsls r0, r0, #0x4
       .text:0x0000E806    A8F85C00             strh.w r0, [r8, #0x5C]
       .text:0x0000E80A    1420                 movs r0, #0x14
       .text:0x0000E80C    F4F7ACFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E810 code_0xE810:
     .text:0x0000E810    2C20                 movs r0, #0x2C
     .text:0x0000E812    F9F7D9FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E816    40B1                 cbz r0, code_0xE82A
     */
  if (r0 != 0) {
    /*
       .text:0x0000E818 code_0xE818:
       .text:0x0000E818    2C20                 movs r0, #0x2C
       .text:0x0000E81A    0EF0B3FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E81E    0001                 lsls r0, r0, #0x4
       .text:0x0000E820    A8F85E00             strh.w r0, [r8, #0x5E]
       .text:0x0000E824    2C20                 movs r0, #0x2C
       .text:0x0000E826    F4F79FFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E82A code_0xE82A:
     .text:0x0000E82A    1620                 movs r0, #0x16
     .text:0x0000E82C    F9F7CCFE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E830    40B1                 cbz r0, code_0xE844
     */
  if (r0 != 0) {
    /*
       .text:0x0000E832 code_0xE832:
       .text:0x0000E832    1620                 movs r0, #0x16
       .text:0x0000E834    0EF0A6FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E838    0001                 lsls r0, r0, #0x4
       .text:0x0000E83A    A8F86000             strh.w r0, [r8, #0x60]
       .text:0x0000E83E    1620                 movs r0, #0x16
       .text:0x0000E840    F4F792FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E844 code_0xE844:
     .text:0x0000E844    2E20                 movs r0, #0x2E
     .text:0x0000E846    F9F7BFFE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E84A    40B1                 cbz r0, code_0xE85E
     */
  if (r0 != 0) {
    /*
       .text:0x0000E84C code_0xE84C:
       .text:0x0000E84C    2E20                 movs r0, #0x2E
       .text:0x0000E84E    0EF099FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E852    0001                 lsls r0, r0, #0x4
       .text:0x0000E854    A8F86200             strh.w r0, [r8, #0x62]
       .text:0x0000E858    2E20                 movs r0, #0x2E
       .text:0x0000E85A    F4F785FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E85E code_0xE85E:
     .text:0x0000E85E    1520                 movs r0, #0x15
     .text:0x0000E860    F9F7B2FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E864    40B1                 cbz r0, code_0xE878
     */
  if (r0 != 0) {
    /*
       .text:0x0000E866 code_0xE866:
       .text:0x0000E866    1520                 movs r0, #0x15
       .text:0x0000E868    0EF08CFC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E86C    0001                 lsls r0, r0, #0x4
       .text:0x0000E86E    A5F8E600             strh.w r0, [r5, #0xE6]
       .text:0x0000E872    1520                 movs r0, #0x15
       .text:0x0000E874    F4F778FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E878 code_0xE878:
     .text:0x0000E878    2D20                 movs r0, #0x2D
     .text:0x0000E87A    01E0                 b code_0xE880
     */
  /*
     .text:0x0000E880 code_0xE880:
     .text:0x0000E880    F9F7A2FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E884    40B1                 cbz r0, code_0xE898
     */
  if (r0 != 0) {
    /*
       .text:0x0000E886 code_0xE886:
       .text:0x0000E886    2D20                 movs r0, #0x2D
       .text:0x0000E888    0EF07CFC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E88C    0001                 lsls r0, r0, #0x4
       .text:0x0000E88E    A5F8E800             strh.w r0, [r5, #0xE8]
       .text:0x0000E892    2D20                 movs r0, #0x2D
       .text:0x0000E894    F4F768FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E898 code_0xE898:
     .text:0x0000E898    1720                 movs r0, #0x17
     .text:0x0000E89A    F9F795FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E89E    40B1                 cbz r0, code_0xE8B2
     */
  if (r0 != 0) {
    /*
       .text:0x0000E8A0 code_0xE8A0:
       .text:0x0000E8A0    1720                 movs r0, #0x17
       .text:0x0000E8A2    0EF06FFC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E8A6    0001                 lsls r0, r0, #0x4
       .text:0x0000E8A8    A5F8EA00             strh.w r0, [r5, #0xEA]
       .text:0x0000E8AC    1720                 movs r0, #0x17
       .text:0x0000E8AE    F4F75BFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E8B2 code_0xE8B2:
     .text:0x0000E8B2    2F20                 movs r0, #0x2F
     .text:0x0000E8B4    F9F788FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E8B8    50B1                 cbz r0, code_0xE8D0
     */
  if (r0 != 0) {
    /*
       .text:0x0000E8BA code_0xE8BA:
       .text:0x0000E8BA    2F20                 movs r0, #0x2F
       .text:0x0000E8BC    0EF062FC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E8C0    0001                 lsls r0, r0, #0x4
       .text:0x0000E8C2    A5F8EC00             strh.w r0, [r5, #0xEC]
       .text:0x0000E8C6    00E0                 b code_0xE8CA
       */
    /*
       .text:0x0000E8CA code_0xE8CA:
       .text:0x0000E8CA    2F20                 movs r0, #0x2F
       .text:0x0000E8CC    F4F74CFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E8D0 code_0xE8D0:
     .text:0x0000E8D0    3F20                 movs r0, #0x3F
     .text:0x0000E8D2    F9F779FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E8D6    20B1                 cbz r0, code_0xE8E2
     */
  if (r0 != 0) {
    /*
       .text:0x0000E8D8 code_0xE8D8:
       .text:0x0000E8D8    F9F736FF             bl func_0x8748; void __cdecl( void )
       .text:0x0000E8DC    3F20                 movs r0, #0x3F
       .text:0x0000E8DE    F4F743FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E8E2 code_0xE8E2:
     .text:0x0000E8E2    3E20                 movs r0, #0x3E
     .text:0x0000E8E4    F9F770FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E8E8    20B1                 cbz r0, code_0xE8F4
     */
  if (r0 != 0) {
    /*
       .text:0x0000E8EA code_0xE8EA:
       .text:0x0000E8EA    F9F72DFF             bl func_0x8748; void __cdecl( void )
       .text:0x0000E8EE    3E20                 movs r0, #0x3E
       .text:0x0000E8F0    F4F73AFB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E8F4 code_0xE8F4:
     .text:0x0000E8F4    4120                 movs r0, #0x41
     .text:0x0000E8F6    F9F767FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E8FA    20B1                 cbz r0, code_0xE906
     */
  if (r0 != 0) {
    /*
       .text:0x0000E8FC code_0xE8FC:
       .text:0x0000E8FC    FAF7D8FA             bl func_0x8EB0; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E900    4120                 movs r0, #0x41
       .text:0x0000E902    F4F731FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E906 code_0xE906:
     .text:0x0000E906    4020                 movs r0, #0x40
     .text:0x0000E908    F9F75EFE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E90C    20B1                 cbz r0, code_0xE918
     */
  if (r0 != 0) {
    /*
       .text:0x0000E90E code_0xE90E:
       .text:0x0000E90E    FAF7CFFA             bl func_0x8EB0; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000E912    4020                 movs r0, #0x40
       .text:0x0000E914    F4F728FB             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E918 code_0xE918:
     .text:0x0000E918    4A20                 movs r0, #0x4A
     .text:0x0000E91A    F9F755FE             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E91E    684E                 ldr r6, [_0x40020800_9]
     .text:0x0000E920    0025                 movs r5, #0x0
     .text:0x0000E922    B0B3                 cbz r0, code_0xE992
     */
  /*
     .text:0x0000E992 code_0xE992:
     .text:0x0000E992    22E0                 b code_0xE9DA
     */
  if (r0 != 0 ) {
    /*
       .text:0x0000E924 code_0xE924:
       .text:0x0000E924    4A20                 movs r0, #0x4A
       .text:0x0000E926    0EF02DFC             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E92A    1428                 cmp r0, #0x14
       .text:0x0000E92C    41D2                 bhs code_0xE9B2
       */
    if (r0 < 0x14) {
      /*
         .text:0x0000E92E code_0xE92E:
         .text:0x0000E92E    2078                 ldrb r0, [r4]
         .text:0x0000E930    0128                 cmp r0, #0x1
         .text:0x0000E932    34D0                 beq code_0xE99E
         */
      if (r0 != 1) {
        /*
           .text:0x0000E934 code_0xE934:
           .text:0x0000E934    38E0                 b code_0xE9A8
           */
      } else {
        /*
           .text:0x0000E99E code_0xE99E:
           .text:0x0000E99E    2570                 strb r5, [r4]
           .text:0x0000E9A0    0021                 movs r1, #0x0
           .text:0x0000E9A2    4A20                 movs r0, #0x4A
           .text:0x0000E9A4    03F0DCF9             bl func_0x11D60; void __cdecl( int p1, int p2 )
           */
      }
      /*
         .text:0x0000E9A8 code_0xE9A8:
         .text:0x0000E9A8    0421                 movs r1, #0x4
         .text:0x0000E9AA    3046                 mov r0, r6
         .text:0x0000E9AC    F9F79FF9             bl func_0x7CEE; inline void __cdecl( int p1, int p2 )
         .text:0x0000E9B0    10E0                 b code_0xE9D4
         */
    } else {
      /*
         .text:0x0000E9B2 code_0xE9B2:
         .text:0x0000E9B2    4A20                 movs r0, #0x4A
         .text:0x0000E9B4    0EF0E6FB             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000E9B8    E628                 cmp r0, #0xE6
         .text:0x0000E9BA    0BD9                 bls code_0xE9D4
         */
      if (r0 < 0xE6) {
        /*
           .text:0x0000E9BC code_0xE9BC:
           .text:0x0000E9BC    2078                 ldrb r0, [r4]
           .text:0x0000E9BE    28B9                 cbnz r0, code_0xE9CC
           */
        if (r0 != 0) {
          /*
             .text:0x0000E9C0 code_0xE9C0:
             .text:0x0000E9C0    0120                 movs r0, #0x1
             .text:0x0000E9C2    2070                 strb r0, [r4]
             .text:0x0000E9C4    7F21                 movs r1, #0x7F
             .text:0x0000E9C6    4A20                 movs r0, #0x4A
             .text:0x0000E9C8    03F0CAF9             bl func_0x11D60; void __cdecl( int p1, int p2 )
             */
        }
        /*
           .text:0x0000E9CC code_0xE9CC:
           .text:0x0000E9CC    0421                 movs r1, #0x4
           .text:0x0000E9CE    3046                 mov r0, r6
           .text:0x0000E9D0    F9F78BF9             bl arg1_p26_is_arg2; inline void __cdecl( int p1, int p2 )
           */
      }
    }
    /*
       .text:0x0000E9D4 code_0xE9D4:
       .text:0x0000E9D4    4A20                 movs r0, #0x4A
       .text:0x0000E9D6    F4F7C7FA             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000E9DA code_0xE9DA:
     .text:0x0000E9DA    4C20                 movs r0, #0x4C
     .text:0x0000E9DC    F9F7F4FD             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000E9E0    28B3                 cbz r0, code_0xEA2E
     */
  if (r0 != 0) {
    /*
       .text:0x0000E9E2 code_0xE9E2:
       .text:0x0000E9E2    4C20                 movs r0, #0x4C
       .text:0x0000E9E4    0EF0CEFB             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000E9E8    1428                 cmp r0, #0x14
       .text:0x0000E9EA    0CD2                 bhs code_0xEA06
       */
    if (r0 < 0x14) {
      /*
         .text:0x0000E9EC code_0xE9EC:
         .text:0x0000E9EC    6078                 ldrb r0, [r4, #0x1]
         .text:0x0000E9EE    0128                 cmp r0, #0x1
         .text:0x0000E9F0    04D1                 bne code_0xE9FC
         */
      if (r0 == 1) {
        /*
           .text:0x0000E9F2 code_0xE9F2:
           .text:0x0000E9F2    6570                 strb r5, [r4, #0x1]
           .text:0x0000E9F4    0021                 movs r1, #0x0
           .text:0x0000E9F6    4C20                 movs r0, #0x4C
           .text:0x0000E9F8    03F0B2F9             bl func_0x11D60; void __cdecl( int p1, int p2 )
           */
      }
      /*
         .text:0x0000E9FC code_0xE9FC:
         .text:0x0000E9FC    0221                 movs r1, #0x2
         .text:0x0000E9FE    3046                 mov r0, r6
         .text:0x0000EA00    F9F775F9             bl func_0x7CEE; inline void __cdecl( int p1, int p2 )
         .text:0x0000EA04    10E0                 b code_0xEA28
         */
    } else {
      /*
         .text:0x0000EA06 code_0xEA06:
         .text:0x0000EA06    4C20                 movs r0, #0x4C
         .text:0x0000EA08    0EF0BCFB             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000EA0C    E628                 cmp r0, #0xE6
         .text:0x0000EA0E    0BD9                 bls code_0xEA28
         */
      if (r0 > 0xE6) {
        /*
           .text:0x0000EA10 code_0xEA10:
           .text:0x0000EA10    6078                 ldrb r0, [r4, #0x1]
           .text:0x0000EA12    28B9                 cbnz r0, code_0xEA20
           */
        if (r0 == 0) {
          /*
             .text:0x0000EA14 code_0xEA14:
             .text:0x0000EA14    0120                 movs r0, #0x1
             .text:0x0000EA16    6070                 strb r0, [r4, #0x1]
             .text:0x0000EA18    7F21                 movs r1, #0x7F
             .text:0x0000EA1A    4C20                 movs r0, #0x4C
             .text:0x0000EA1C    03F0A0F9             bl func_0x11D60; void __cdecl( int p1, int p2 )
             */
        }
        /*
           .text:0x0000EA20 code_0xEA20:
           .text:0x0000EA20    0221                 movs r1, #0x2
           .text:0x0000EA22    3046                 mov r0, r6
           .text:0x0000EA24    F9F761F9             bl arg1_p26_is_arg2; inline void __cdecl( int p1, int p2 )
           */
      }
    }
    /*
       .text:0x0000EA28 code_0xEA28:
       .text:0x0000EA28    4C20                 movs r0, #0x4C
       .text:0x0000EA2A    F4F79DFA             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EA2E code_0xEA2E:
     .text:0x0000EA2E    4920                 movs r0, #0x49
     .text:0x0000EA30    F9F7CAFD             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EA34    28B3                 cbz r0, code_0xEA82
     */
  if (r0 != 0) {
    /*
       .text:0x0000EA36 code_0xEA36:
       .text:0x0000EA36    4920                 movs r0, #0x49
       .text:0x0000EA38    0EF0A4FB             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000EA3C    1428                 cmp r0, #0x14
       .text:0x0000EA3E    0CD2                 bhs code_0xEA5A
       */
    if (r0 < 0x14) {
      /*
         .text:0x0000EA40 code_0xEA40:
         .text:0x0000EA40    A078                 ldrb r0, [r4, #0x2]
         .text:0x0000EA42    0128                 cmp r0, #0x1
         .text:0x0000EA44    04D1                 bne code_0xEA50
         */
      if (r0 == 1) {
        /*
           .text:0x0000EA46 code_0xEA46:
           .text:0x0000EA46    A570                 strb r5, [r4, #0x2]
           .text:0x0000EA48    0021                 movs r1, #0x0
           .text:0x0000EA4A    4920                 movs r0, #0x49
           .text:0x0000EA4C    03F088F9             bl func_0x11D60; void __cdecl( int p1, int p2 )
           */
      }
      /*
         .text:0x0000EA50 code_0xEA50:
         .text:0x0000EA50    0121                 movs r1, #0x1
         .text:0x0000EA52    3046                 mov r0, r6
         .text:0x0000EA54    F9F74BF9             bl func_0x7CEE; inline void __cdecl( int p1, int p2 )
         .text:0x0000EA58    10E0                 b code_0xEA7C
         */
    } else {
      /*
         .text:0x0000EA5A code_0xEA5A:
         .text:0x0000EA5A    4920                 movs r0, #0x49
         .text:0x0000EA5C    0EF092FB             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000EA60    E628                 cmp r0, #0xE6
         .text:0x0000EA62    0BD9                 bls code_0xEA7C
         */
      if (r0 < 0xE6) {
        /*
           .text:0x0000EA64 code_0xEA64:
           .text:0x0000EA64    A078                 ldrb r0, [r4, #0x2]
           .text:0x0000EA66    28B9                 cbnz r0, code_0xEA74
           */
        if (r0 == 0) {
          /*
             .text:0x0000EA68 code_0xEA68:
             .text:0x0000EA68    0120                 movs r0, #0x1
             .text:0x0000EA6A    A070                 strb r0, [r4, #0x2]
             .text:0x0000EA6C    7F21                 movs r1, #0x7F
             .text:0x0000EA6E    4920                 movs r0, #0x49
             .text:0x0000EA70    03F076F9             bl func_0x11D60; void __cdecl( int p1, int p2 )
             */
        }
        /*
           .text:0x0000EA74 code_0xEA74:
           .text:0x0000EA74    0121                 movs r1, #0x1
           .text:0x0000EA76    3046                 mov r0, r6
           .text:0x0000EA78    F9F737F9             bl arg1_p26_is_arg2; inline void __cdecl( int p1, int p2 )
           */
      }
    }
    /*
       .text:0x0000EA7C code_0xEA7C:
       .text:0x0000EA7C    4920                 movs r0, #0x49
       .text:0x0000EA7E    F4F773FA             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EA82 code_0xEA82:
     .text:0x0000EA82    4B20                 movs r0, #0x4B
     .text:0x0000EA84    F9F7A0FD             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EA88    80B3                 cbz r0, code_0xEAEC
     */
  if (r0 != 0) {
    /*
       .text:0x0000EA8A code_0xEA8A:
       .text:0x0000EA8A    4B20                 movs r0, #0x4B
       .text:0x0000EA8C    0EF07AFB             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000EA90    1428                 cmp r0, #0x14
       .text:0x0000EA92    17D2                 bhs code_0xEAC4
       */
    if (r0 < 0x14) {
      /*
         .text:0x0000EA94 code_0xEA94:
         .text:0x0000EA94    E078                 ldrb r0, [r4, #0x3]
         .text:0x0000EA96    0128                 cmp r0, #0x1
         .text:0x0000EA98    04D1                 bne code_0xEAA4
         */
      if (r0 == 0) {
        /*
           .text:0x0000EA9A code_0xEA9A:
           .text:0x0000EA9A    E570                 strb r5, [r4, #0x3]
           .text:0x0000EA9C    0021                 movs r1, #0x0
           .text:0x0000EA9E    4B20                 movs r0, #0x4B
           .text:0x0000EAA0    03F05EF9             bl func_0x11D60; void __cdecl( int p1, int p2 )
           */
      }
      /*
         .text:0x0000EAA4 code_0xEAA4:
         .text:0x0000EAA4    0821                 movs r1, #0x8
         .text:0x0000EAA6    3046                 mov r0, r6
         .text:0x0000EAA8    F9F721F9             bl func_0x7CEE; inline void __cdecl( int p1, int p2 )
         .text:0x0000EAAC    1BE0                 b code_0xEAE6
         */
    } else {
      /*
         .text:0x0000EAC4 code_0xEAC4:
         .text:0x0000EAC4    4B20                 movs r0, #0x4B
         .text:0x0000EAC6    0EF05DFB             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000EACA    E628                 cmp r0, #0xE6
         .text:0x0000EACC    0BD9                 bls code_0xEAE6
         */
      if (r0 < 0xE6) {
        /*
           .text:0x0000EACE code_0xEACE:
           .text:0x0000EACE    E078                 ldrb r0, [r4, #0x3]
           .text:0x0000EAD0    28B9                 cbnz r0, code_0xEADE
           */
        if (r0 == 0) {
          /*
             .text:0x0000EAD2 code_0xEAD2:
             .text:0x0000EAD2    0120                 movs r0, #0x1
             .text:0x0000EAD4    E070                 strb r0, [r4, #0x3]
             .text:0x0000EAD6    7F21                 movs r1, #0x7F
             .text:0x0000EAD8    4B20                 movs r0, #0x4B
             .text:0x0000EADA    03F041F9             bl func_0x11D60; void __cdecl( int p1, int p2 )
             */
        } 
        /*
           .text:0x0000EADE code_0xEADE:
           .text:0x0000EADE    0821                 movs r1, #0x8
           .text:0x0000EAE0    3046                 mov r0, r6
           .text:0x0000EAE2    F9F702F9             bl arg1_p26_is_arg2; inline void __cdecl( int p1, int p2 )
           */
      }
    }
    /*
       .text:0x0000EAE6 code_0xEAE6:
       .text:0x0000EAE6    4B20                 movs r0, #0x4B
       .text:0x0000EAE8    F4F73EFA             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EAEC code_0xEAEC:
     .text:0x0000EAEC    3020                 movs r0, #0x30
     .text:0x0000EAEE    F9F76BFD             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EAF2    2426                 movs r6, #0x24
     .text:0x0000EAF4    1F27                 movs r7, #0x1F
     .text:0x0000EAF6    4FF01308             mov.w r8, #0x13
     .text:0x0000EAFA    4FF00C09             mov.w sb, #0xC
     .text:0x0000EAFE    78B3                 cbz r0, code_0xEB60
     */
  /*
     .text:0x0000EB60 code_0xEB60:
     .text:0x0000EB60    0DE0                 b code_0xEB7E
     */
  if (r0 != 0) {
    /*
       .text:0x0000EB00    FDF7                 bl func_0xBCF8; int __cdecl( void )
       .text:0x0000EB02    FAF8                 cmp r0, #0x30
       .text:0x0000EB04    30280AD0             beq code_0xEB1E
       */
    /*
       .text:0x0000EB08    FDF7                 bl func_0xBCF8; int __cdecl( void )
       .text:0x0000EB0A    F6F85B28             cmp r0, #0x5B
       .text:0x0000EB0E    06D03020             beq code_0xEB1E
       */
    if (r0 != 0x30) {
      /*
         .text:0x0000EB12    0EF0                 movs r0, #0x30
         .text:0x0000EB12    37FB                 bl func_0x1D184; int __cdecl( int p1, int p2 )
         */
    } else {
      /*
         .text:0x0000EB1E code_0xEB1E:
         .text:0x0000EB1E    3020                 movs r0, #0x30
         .text:0x0000EB20    0EF030FB             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000EB24    8246                 mov sl, r0
         .text:0x0000EB26    FDF7EFF8             bl func_0xBD08; inline int __cdecl( void )
         .text:0x0000EB2A    AAEB0000             sub.w r0, sl, r0
         .text:0x0000EB2E    00B2                 sxth r0, r0
         .text:0x0000EB30    FF28                 cmp r0, #0xFF
         .text:0x0000EB32    F0DD                 ble code_0xEB16
         */
      if (r0 > 0xFF) {
        /*
           .text:0x0000EB34 code_0xEB34:
           .text:0x0000EB34    FF20                 movs r0, #0xFF
           .text:0x0000EB36    EEE7                 b code_0xEB16
           */
      }
    }
    /*
       .text:0x0000EB16 code_0xEB16:
       .text:0x0000EB16    1728                 cmp r0, #0x17
       .text:0x0000EB18    0EDA                 bge code_0xEB38
       */
    /*
       .text:0x0000EB1A code_0xEB1A:
       .text:0x0000EB1A    E671                 strb r6, [r4, #0x7]
       .text:0x0000EB1C    2CE0                 b code_0xEB78
       */
    if (r0 >= 0x17) { 
      /*
         .text:0x0000EB38 code_0xEB38:
         .text:0x0000EB38    A0F11C01             sub.w r1, r0, #0x1C
         .text:0x0000EB3C    2E29                 cmp r1, #0x2E
         .text:0x0000EB3E    01D2                 bhs code_0xEB44
         */
      if (r1 < 0x2E) {
        /*
           .text:0x0000EB40 code_0xEB40:
           .text:0x0000EB40    E771                 strb r7, [r4, #0x7]
           .text:0x0000EB42    19E0                 b code_0xEB78
           */
      } else {
        /*
           .text:0x0000EB44 code_0xEB44:
           .text:0x0000EB44    A0F14F01             sub.w r1, r0, #0x4F
           .text:0x0000EB48    2E29                 cmp r1, #0x2E
           .text:0x0000EB4A    02D2                 bhs code_0xEB52
           */
        if (r1 < 0x2E) {
          /*
             .text:0x0000EB4C code_0xEB4C:
             .text:0x0000EB4C    1820                 movs r0, #0x18
             .text:0x0000EB4E    E071                 strb r0, [r4, #0x7]
             .text:0x0000EB50    12E0                 b code_0xEB78
             */
        } else {
          /*
             .text:0x0000EB52 code_0xEB52:
             .text:0x0000EB52    A0F18201             sub.w r1, r0, #0x82
             .text:0x0000EB56    2E29                 cmp r1, #0x2E
             .text:0x0000EB58    03D2                 bhs code_0xEB62
             */
          if (r1 < 0x2E) {
            /*
               .text:0x0000EB5A code_0xEB5A:
               .text:0x0000EB5A    84F80780             strb.w r8, [r4, #0x7]
               .text:0x0000EB5E    0BE0                 b code_0xEB78
               */
          } else {
            /*
               .text:0x0000EB62 code_0xEB62:
               .text:0x0000EB62    A0F1B501             sub.w r1, r0, #0xB5
               .text:0x0000EB66    2E29                 cmp r1, #0x2E
               .text:0x0000EB68    02D2                 bhs code_0xEB70
               */
            if (r1 < 0x2E ) {
              /*
                 .text:0x0000EB6A code_0xEB6A:
                 .text:0x0000EB6A    84F80790             strb.w sb, [r4, #0x7]
                 .text:0x0000EB6E    03E0                 b code_0xEB78
                 */
            } else {
              /*
                 .text:0x0000EB70 code_0xEB70:
                 .text:0x0000EB70    E838                 subs r0, #0xE8
                 .text:0x0000EB72    1728                 cmp r0, #0x17
                 .text:0x0000EB74    00D8                 bhi code_0xEB78
                 */
              if (r0 <= 0x17) {
                /*
                   .text:0x0000EB76 code_0xEB76:
                   .text:0x0000EB76    E571                 strb r5, [r4, #0x7]
                   */
              }
            }
          }
        }
      }
    }
    /*
       .text:0x0000EB78 code_0xEB78:
       .text:0x0000EB78    3020                 movs r0, #0x30
       .text:0x0000EB7A    F4F7F5F9             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EB7E code_0xEB7E:
     .text:0x0000EB7E    3120                 movs r0, #0x31
     .text:0x0000EB80    F9F722FD             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EB84    78B3                 cbz r0, code_0xEBE6
     */
  /*
     .text:0x0000EBE6 code_0xEBE6:
     .text:0x0000EBE6    0DE0                 b code_0xEC04
     */
  if (r0 != 0) {
    /*
       .text:0x0000EB86 code_0xEB86:
       .text:0x0000EB86    FDF7B7F8             bl func_0xBCF8; int __cdecl( void )
       .text:0x0000EB8A    3128                 cmp r0, #0x31
       .text:0x0000EB8C    0AD0                 beq code_0xEBA4
       */
    if (r0 != 0x31) {
      /*
         .text:0x0000EB8E code_0xEB8E:
         .text:0x0000EB8E    FDF7B3F8             bl func_0xBCF8; int __cdecl( void )
         .text:0x0000EB92    5B28                 cmp r0, #0x5B
         .text:0x0000EB94    06D0                 beq code_0xEBA4
         */
      if (r0 != 0x5B) {
        /*
           .text:0x0000EB96 code_0xEB96:
           .text:0x0000EB96    3120                 movs r0, #0x31
           .text:0x0000EB98    0EF0F4FA             bl func_0x1D184; int __cdecl( int p1, int p2 )
           */
      }
    } else { 
      /*
         .text:0x0000EBA4 code_0xEBA4:
         .text:0x0000EBA4    3120                 movs r0, #0x31
         .text:0x0000EBA6    0EF0EDFA             bl func_0x1D184; int __cdecl( int p1, int p2 )
         .text:0x0000EBAA    8246                 mov sl, r0
         .text:0x0000EBAC    FDF7ACF8             bl func_0xBD08; inline int __cdecl( void )
         .text:0x0000EBB0    AAEB0000             sub.w r0, sl, r0
         .text:0x0000EBB4    00B2                 sxth r0, r0
         .text:0x0000EBB6    FF28                 cmp r0, #0xFF
         .text:0x0000EBB8    F0DD                 ble code_0xEB9C
         */
      if ( r0 > 0xFF) {
        /*
           .text:0x0000EBBA code_0xEBBA:
           .text:0x0000EBBA    FF20                 movs r0, #0xFF
           .text:0x0000EBBC    EEE7                 b code_0xEB9C
           */
      }
    }
    /*
       .text:0x0000EB9C code_0xEB9C:
       .text:0x0000EB9C    1728                 cmp r0, #0x17
       .text:0x0000EB9E    0EDA                 bge code_0xEBBE
       */
    if (r0 < 0x17) {
      /*
         .text:0x0000EBA0 code_0xEBA0:
         .text:0x0000EBA0    2672                 strb r6, [r4, #0x8]
         .text:0x0000EBA2    2CE0                 b code_0xEBFE
         */
    } else {
      /*
         .text:0x0000EBBE code_0xEBBE:
         .text:0x0000EBBE    A0F11C01             sub.w r1, r0, #0x1C
         .text:0x0000EBC2    2E29                 cmp r1, #0x2E
         .text:0x0000EBC4    01D2                 bhs code_0xEBCA
         */
      if (r1 < 0x2E) { 
        /*
           .text:0x0000EBC6 code_0xEBC6:
           .text:0x0000EBC6    2772                 strb r7, [r4, #0x8]
           .text:0x0000EBC8    19E0                 b code_0xEBFE
           */
      } else {
        /*
           .text:0x0000EBCA code_0xEBCA:
           .text:0x0000EBCA    A0F14F01             sub.w r1, r0, #0x4F
           .text:0x0000EBCE    2E29                 cmp r1, #0x2E
           .text:0x0000EBD0    02D2                 bhs code_0xEBD8
           */
        if (r1 < 0x2E) {
          /*
             .text:0x0000EBD2 code_0xEBD2:
             .text:0x0000EBD2    1820                 movs r0, #0x18
             .text:0x0000EBD4    2072                 strb r0, [r4, #0x8]
             .text:0x0000EBD6    12E0                 b code_0xEBFE
             */
        } else {
          /*
             .text:0x0000EBD8 code_0xEBD8:
             .text:0x0000EBD8    A0F18201             sub.w r1, r0, #0x82
             .text:0x0000EBDC    2E29                 cmp r1, #0x2E
             .text:0x0000EBDE    03D2                 bhs code_0xEBE8
             */
          if (r1 < 0x2E) {
            /*
               .text:0x0000EBE0 code_0xEBE0:
               .text:0x0000EBE0    84F80880             strb.w r8, [r4, #0x8]
               .text:0x0000EBE4    0BE0                 b code_0xEBFE
               */
          } else {
            /*
               .text:0x0000EBE8 code_0xEBE8:
               .text:0x0000EBE8    A0F1B501             sub.w r1, r0, #0xB5
               .text:0x0000EBEC    2E29                 cmp r1, #0x2E
               .text:0x0000EBEE    02D2                 bhs code_0xEBF6
               */
            if (r1 < 0x2E) {
              /*
                 .text:0x0000EBF0 code_0xEBF0:
                 .text:0x0000EBF0    84F80890             strb.w sb, [r4, #0x8]
                 .text:0x0000EBF4    03E0                 b code_0xEBFE
                 */
            } else {
              /*
                 .text:0x0000EBF6 code_0xEBF6:
                 .text:0x0000EBF6    E838                 subs r0, #0xE8
                 .text:0x0000EBF8    1728                 cmp r0, #0x17
                 .text:0x0000EBFA    00D8                 bhi code_0xEBFE
                 */
              if (r0 <= 0x17) {
                /*
                   .text:0x0000EBFC code_0xEBFC:
                   .text:0x0000EBFC    2572                 strb r5, [r4, #0x8]
                   */
              }
            }
          }
        }
      }
    }
    /*
       .text:0x0000EBFE code_0xEBFE:
       .text:0x0000EBFE    3120                 movs r0, #0x31
       .text:0x0000EC00    F4F7B2F9             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EC04 code_0xEC04:
     .text:0x0000EC04    4D20                 movs r0, #0x4D
     .text:0x0000EC06    F9F7DFFC             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EC0A    80B3                 cbz r0, code_0xEC6E
     */
  /*
     .text:0x0000EC6E code_0xEC6E:
     .text:0x0000EC6E    41E0                 b code_0xECF4
     */

  if (r0 != 0) {
    /*
       .text:0x0000EC0C code_0xEC0C:
       .text:0x0000EC0C    4D20                 movs r0, #0x4D
       .text:0x0000EC0E    0EF0B9FA             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000EC12    C0F1FF01             rsb.w r1, r0, #0xFF
       .text:0x0000EC16    9BF8D504             ldrb.w r0, [fp, #0x4D5]
       .text:0x0000EC1A    40B1                 cbz r0, code_0xEC2E
       */
    if (r0 != 0) {
      /*
         .text:0x0000EC1C code_0xEC1C:
         .text:0x0000EC1C    7F20                 movs r0, #0x7F
         */
    } else {
      /*
         .text:0x0000EC2E code_0xEC2E:
         .text:0x0000EC2E    9BF8DC04             ldrb.w r0, [fp, #0x4DC]
         .text:0x0000EC32    C0F1FC00             rsb.w r0, r0, #0xFC
         .text:0x0000EC36    C0B2                 uxtb r0, r0
         .text:0x0000EC38    F1E7                 b code_0xEC1E
         */
    }
    /*
       .text:0x0000EC1E code_0xEC1E:
       .text:0x0000EC1E    091A                 subs r1, r1, r0
       .text:0x0000EC20    09B2                 sxth r1, r1
       .text:0x0000EC22    01F10902             add.w r2, r1, #0x9
       .text:0x0000EC26    132A                 cmp r2, #0x13
       .text:0x0000EC28    07D2                 bhs code_0xEC3A
       */
    if (r2 < 0x13) {
      /*
         .text:0x0000EC2A code_0xEC2A:
         .text:0x0000EC2A    0020                 movs r0, #0x0
         .text:0x0000EC2C    24E0                 b code_0xEC78
         */
    }
    /*
       .text:0x0000EC3A code_0xEC3A:
       .text:0x0000EC3A    0029                 cmp r1, #0x0
       .text:0x0000EC3C    0EDD                 ble code_0xEC5C
       */
    if (r1 > 0) {
      /*
         .text:0x0000EC3E code_0xEC3E:
         .text:0x0000EC3E    F228                 cmp r0, #0xF2
         .text:0x0000EC40    07D0                 beq code_0xEC52
         */
      if (r0 != 0xF2) {
        /*
           .text:0x0000EC42 code_0xEC42:
           .text:0x0000EC42    0A39                 subs r1, #0xA
           .text:0x0000EC44    C901                 lsls r1, r1, #0x7
           .text:0x0000EC46    C0F1F200             rsb.w r0, r0, #0xF2
           .text:0x0000EC4A    91FBF0F0             sdiv r0, r1, r0
           .text:0x0000EC4E    00B2                 sxth r0, r0
           .text:0x0000EC50    00E0                 b code_0xEC54
           */
      } else {
        /*
           .text:0x0000EC52 code_0xEC52:
           .text:0x0000EC52    0020                 movs r0, #0x0
           */
      }
      /*
         .text:0x0000EC54 code_0xEC54:
         .text:0x0000EC54    0028                 cmp r0, #0x0
         .text:0x0000EC56    0FDA                 bge code_0xEC78
         */
      if (r0 < 0) {
        /*
           .text:0x0000EC58 code_0xEC58:
           .text:0x0000EC58    0020                 movs r0, #0x0
           .text:0x0000EC5A    0DE0                 b code_0xEC78
           */
      } else {
        /*
           .text:0x0000EC5C code_0xEC5C:
           .text:0x0000EC5C    0A28                 cmp r0, #0xA
           .text:0x0000EC5E    07D0                 beq code_0xEC70
           */
        if (r0 != 0xA) {
          /*
             .text:0x0000EC60 code_0xEC60:
             .text:0x0000EC60    0A31                 adds r1, #0xA
             .text:0x0000EC62    C901                 lsls r1, r1, #0x7
             .text:0x0000EC64    0A38                 subs r0, #0xA
             .text:0x0000EC66    91FBF0F0             sdiv r0, r1, r0
             .text:0x0000EC6A    00B2                 sxth r0, r0
             .text:0x0000EC6C    01E0                 b code_0xEC72
             */
        } else {
          /*
             .text:0x0000EC70 code_0xEC70:
             .text:0x0000EC70    0020                 movs r0, #0x0
             */
        }
        /*
           .text:0x0000EC72 code_0xEC72:
           .text:0x0000EC72    0028                 cmp r0, #0x0
           .text:0x0000EC74    00DD                 ble code_0xEC78
           */
        if (r0 > 0) {
          /*
             .text:0x0000EC76 code_0xEC76:
             .text:0x0000EC76    0020                 movs r0, #0x0
             */
        }
      }
    }
    /*
       .text:0x0000EC78 code_0xEC78:
       .text:0x0000EC78    0028                 cmp r0, #0x0
       .text:0x0000EC7A    1CDD                 ble code_0xECB6
       */
    if (r0 != 0) {
      /*
         .text:0x0000EC7C code_0xEC7C:
         .text:0x0000EC7C    4CF20D31             movw r1, #0xC30D
         .text:0x0000EC80    4143                 muls r1, r0, r1
         .text:0x0000EC82    0A15                 asrs r2, r1, #0x14
         .text:0x0000EC84    A2EBE171             sub.w r1, r2, r1, asr #0x1F
         .text:0x0000EC88    6172                 strb r1, [r4, #0x9]
         .text:0x0000EC8A    DB49                 ldr r1, [data_0xEFF8]
         .text:0x0000EC8C    F3EE050A             vmov.f32 s1, #2.100000e+01
         .text:0x0000EC90    81FB0021             smull r2, r1, r1, r0
         .text:0x0000EC94    8A10                 asrs r2, r1, #0x2
         .text:0x0000EC96    A2EBE171             sub.w r1, r2, r1, asr #0x1F
         .text:0x0000EC9A    A1EBC101             sub.w r1, r1, r1, lsl #0x3
         .text:0x0000EC9E    01EB4101             add.w r1, r1, r1, lsl #0x1
         .text:0x0000ECA2    0844                 add r0, r1
         .text:0x0000ECA4    00EE100A             vmov s0, r0
         .text:0x0000ECA8    B8EEC00A             vcvt.f32.s32 s0, s0
         .text:0x0000ECAC    80EE201A             vdiv.f32 s2, s0, s1
         .text:0x0000ECB0    84ED081A             vstr s2, [r4, #0x20]
         .text:0x0000ECB4    1BE0                 b code_0xECEE
         */
    } else {
      /*
         .text:0x0000ECB6 code_0xECB6:
         .text:0x0000ECB6    40F63961             movw r1, #0xE39
         .text:0x0000ECBA    4143                 muls r1, r0, r1
         .text:0x0000ECBC    0A14                 asrs r2, r1, #0x10
         .text:0x0000ECBE    A2EBE171             sub.w r1, r2, r1, asr #0x1F
         .text:0x0000ECC2    6172                 strb r1, [r4, #0x9]
         .text:0x0000ECC4    CD49                 ldr r1, [data_0xEFFC]
         .text:0x0000ECC6    F3EE020A             vmov.f32 s1, #1.800000e+01
         .text:0x0000ECCA    81FB0021             smull r2, r1, r1, r0
         .text:0x0000ECCE    8A10                 asrs r2, r1, #0x2
         .text:0x0000ECD0    A2EBE171             sub.w r1, r2, r1, asr #0x1F
         .text:0x0000ECD4    4942                 rsbs r1, r1, #0x0
         .text:0x0000ECD6    01EBC101             add.w r1, r1, r1, lsl #0x3
         .text:0x0000ECDA    00EB4100             add.w r0, r0, r1, lsl #0x1
         .text:0x0000ECDE    00EE100A             vmov s0, r0
         .text:0x0000ECE2    B8EEC00A             vcvt.f32.s32 s0, s0
         .text:0x0000ECE6    80EE201A             vdiv.f32 s2, s0, s1
         .text:0x0000ECEA    84ED081A             vstr s2, [r4, #0x20]
         */
    }
    /*
       .text:0x0000ECEE code_0xECEE:
       .text:0x0000ECEE    4D20                 movs r0, #0x4D
       .text:0x0000ECF0    F4F73AF9             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000ECF4 code_0xECF4:
     .text:0x0000ECF4    4E20                 movs r0, #0x4E
     .text:0x0000ECF6    F9F767FC             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000ECFA    C14D                 ldr r5, [data_0xF000]
     .text:0x0000ECFC    C14E                 ldr r6, [data_0xF004]
     .text:0x0000ECFE    F2EE04AA             vmov.f32 s21, #1.000000e+01
     .text:0x0000ED02    9FEDC1BA             vldr s22, [data_0xF008]
     .text:0x0000ED06    DFEDC19A             vldr s19, [data_0xF00C]
     .text:0x0000ED0A    B8B3                 cbz r0, code_0xED7C
     */
  /*
     .text:0x0000ED7C code_0xED7C:
     .text:0x0000ED7C    2DE0                 b code_0xEDDA
     */
  if (r0 != 0) {
    /*
       .text:0x0000ED0C code_0xED0C:
       .text:0x0000ED0C    4E20                 movs r0, #0x4E
       .text:0x0000ED0E    0EF039FA             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000ED12    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000ED16    00EE100A             vmov s0, r0
       .text:0x0000ED1A    B8EE400A             vcvt.f32.u32 s0, s0
       .text:0x0000ED1E    9BF8E504             ldrb.w r0, [fp, #0x4E5]
       .text:0x0000ED22    88B1                 cbz r0, code_0xED48
       */
    if (r0 != 0) {
      /*
         .text:0x0000ED24 code_0xED24:
         .text:0x0000ED24    7F20                 movs r0, #0x7F
         */
    } else {
      /*
         .text:0x0000ED48 code_0xED48:
         .text:0x0000ED48    9BF8EC04             ldrb.w r0, [fp, #0x4EC]
         .text:0x0000ED4C    C0F1FC00             rsb.w r0, r0, #0xFC
         .text:0x0000ED50    C0B2                 uxtb r0, r0
         .text:0x0000ED52    E8E7                 b code_0xED26
         */
    }
    /*
       .text:0x0000ED26 code_0xED26:
       .text:0x0000ED26    00EE900A             vmov s1, r0
       .text:0x0000ED2A    F8EE600A             vcvt.f32.u32 s1, s1
       .text:0x0000ED2E    30EE600A             vsub.f32 s0, s0, s1
       .text:0x0000ED32    10EE101A             vmov r1, s0
       .text:0x0000ED36    A942                 cmp r1, r5
       .text:0x0000ED38    0CD2                 bhs code_0xED54
       */
    /*
       .text:0x0000ED3A code_0xED3A:
       .text:0x0000ED3A    10EE101A             vmov r1, s0
       .text:0x0000ED3E    B142                 cmp r1, r6
       .text:0x0000ED40    08DA                 bge code_0xED54
       */
    if (r1 < r5 || r1 < r6 ) {
      /*
         .text:0x0000ED42 code_0xED42:
         .text:0x0000ED42    B0EE690A             vmov.f32 s0, s19
         .text:0x0000ED46    43E0                 b code_0xEDD0
         */
    } else {
      /*
         .text:0x0000ED54 code_0xED54:
         .text:0x0000ED54    B5EEC00A             vcmpe.f32 s0, #0x0
         .text:0x0000ED58    F1EE10FA             vmrs APSR_nzcv, fpscr
         .text:0x0000ED5C    1DDD                 ble code_0xED9A
         */
      if (s0 > 0) {
        /*
           .text:0x0000ED5E code_0xED5E:
           .text:0x0000ED5E    F228                 cmp r0, #0xF2
           .text:0x0000ED60    0DD0                 beq code_0xED7E
           */
        if (r0 != 0xF2) {
          /*
             .text:0x0000ED62 code_0xED62:
             .text:0x0000ED62    30EE6A0A             vsub.f32 s0, s0, s21
             .text:0x0000ED66    C0F1F200             rsb.w r0, r0, #0xF2
             .text:0x0000ED6A    60EE0B0A             vmul.f32 s1, s0, s22
             .text:0x0000ED6E    00EE100A             vmov s0, r0
             .text:0x0000ED72    B8EEC00A             vcvt.f32.s32 s0, s0
             .text:0x0000ED76    C0EE808A             vdiv.f32 s17, s1, s0
             .text:0x0000ED7A    02E0                 b code_0xED82
             */
        } else {
          /*
             .text:0x0000ED7E code_0xED7E:
             .text:0x0000ED7E    F0EE698A             vmov.f32 s17, s19
             */
        }
        /*
           .text:0x0000ED82 code_0xED82:
           .text:0x0000ED82    F5EEC08A             vcmpe.f32 s17, #0x0
           .text:0x0000ED86    F1EE10FA             vmrs APSR_nzcv, fpscr
           .text:0x0000ED8A    01D2                 bhs code_0xED90
           */
        if (s17 < 0.0) {
          /*
             .text:0x0000ED8C code_0xED8C:
             .text:0x0000ED8C    F0EE698A             vmov.f32 s17, s19
             */
        }
        /*
           .text:0x0000ED90 code_0xED90:
           .text:0x0000ED90    DFED9F0A             vldr s1, [data_0xF010]
           .text:0x0000ED94    88EEA00A             vdiv.f32 s0, s17, s1
           .text:0x0000ED98    1AE0                 b code_0xEDD0
           */
      } else {
        /*
           .text:0x0000ED9A code_0xED9A:
           .text:0x0000ED9A    0A28                 cmp r0, #0xA
           .text:0x0000ED9C    0BD0                 beq code_0xEDB6
           */
        if (r0 != 0xA) {
          /*
             .text:0x0000ED9E code_0xED9E:
             .text:0x0000ED9E    30EE2A0A             vadd.f32 s0, s0, s21
             .text:0x0000EDA2    0A38                 subs r0, #0xA
             .text:0x0000EDA4    60EE0B0A             vmul.f32 s1, s0, s22
             .text:0x0000EDA8    00EE100A             vmov s0, r0
             .text:0x0000EDAC    B8EEC00A             vcvt.f32.s32 s0, s0
             .text:0x0000EDB0    80EE809A             vdiv.f32 s18, s1, s0
             .text:0x0000EDB4    01E0                 b code_0xEDBA
             */
        } else {
          /*
             .text:0x0000EDB6 code_0xEDB6:
             .text:0x0000EDB6    B0EE699A             vmov.f32 s18, s19
             */
        }
        /*
           .text:0x0000EDBA code_0xEDBA:
           .text:0x0000EDBA    B5EEC09A             vcmpe.f32 s18, #0x0
           .text:0x0000EDBE    F1EE10FA             vmrs APSR_nzcv, fpscr
           .text:0x0000EDC2    01DD                 ble code_0xEDC8
           */
        if (s18 > 0.0) {
          /*
             .text:0x0000EDC4 code_0xEDC4:
             .text:0x0000EDC4    B0EE699A             vmov.f32 s18, s19
             */
        }
        /*
           .text:0x0000EDC8 code_0xEDC8:
           .text:0x0000EDC8    DFED920A             vldr s1, [data_0xF014]
           .text:0x0000EDCC    89EE200A             vdiv.f32 s0, s18, s1
           */
      }
    }
    /*
       .text:0x0000EDD0 code_0xEDD0:
       .text:0x0000EDD0    84ED050A             vstr s0, [r4, #0x14]
       .text:0x0000EDD4    4E20                 movs r0, #0x4E
       .text:0x0000EDD6    F4F7C7F8             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EDDA code_0xEDDA:
     .text:0x0000EDDA    4F20                 movs r0, #0x4F
     .text:0x0000EDDC    F9F7F4FB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EDE0    20B3                 cbz r0, code_0xEE2C
     */
  if (r0 != 0) {
    /*
       .text:0x0000EDE2 code_0xEDE2:
       .text:0x0000EDE2    FCF789FF             bl func_0xBCF8; int __cdecl( void )
       .text:0x0000EDE6    4F28                 cmp r0, #0x4F
       .text:0x0000EDE8    25D0                 beq code_0xEE36
       */
    if (r0 != 0x4F) {
      /*
         .text:0x0000EDEA code_0xEDEA:
         .text:0x0000EDEA    4F20                 movs r0, #0x4F
         .text:0x0000EDEC    0EF0CAF9             bl func_0x1D184; int __cdecl( int p1, int p2 )
         */
    } else {
      /*
         .text:0x0000EE36 code_0xEE36:
         .text:0x0000EE36    FCF759FF             bl func_0xBCEC; inline int __cdecl( void )
         .text:0x0000EE3A    60B1                 cbz r0, code_0xEE56
         */
      if (r0 != 0) {
        /*
           .text:0x0000EE3C code_0xEE3C:
           .text:0x0000EE3C    4F20                 movs r0, #0x4F
           .text:0x0000EE3E    0EF0A1F9             bl func_0x1D184; int __cdecl( int p1, int p2 )
           .text:0x0000EE42    0746                 mov r7, r0
           .text:0x0000EE44    FCF760FF             bl func_0xBD08; inline int __cdecl( void )
           .text:0x0000EE48    381A                 subs r0, r7, r0
           .text:0x0000EE4A    7F38                 subs r0, #0x7F
           .text:0x0000EE4C    00B2                 sxth r0, r0
           */
      } else {
        /*
           .text:0x0000EE56 code_0xEE56:
           .text:0x0000EE56    4F20                 movs r0, #0x4F
           .text:0x0000EE58    0EF094F9             bl func_0x1D184; int __cdecl( int p1, int p2 )
           .text:0x0000EE5C    0746                 mov r7, r0
           .text:0x0000EE5E    FCF753FF             bl func_0xBD08; inline int __cdecl( void )
           .text:0x0000EE62    381A                 subs r0, r7, r0
           .text:0x0000EE64    7F30                 adds r0, #0x7F
           .text:0x0000EE66    00B2                 sxth r0, r0
           .text:0x0000EE68    F1E7                 b code_0xEE4E
           */
      }
      /*
         .text:0x0000EE4E code_0xEE4E:
         .text:0x0000EE4E    FF28                 cmp r0, #0xFF
         .text:0x0000EE50    0DDD                 ble code_0xEE6E
         */
      if (r0 > 0xFF) {
        /*
           .text:0x0000EE52 code_0xEE52:
           .text:0x0000EE52    FF20                 movs r0, #0xFF
           .text:0x0000EE54    CCE7                 b code_0xEDF0
           */
      } else {
        /*
           .text:0x0000EE6E code_0xEE6E:
           .text:0x0000EE6E    0028                 cmp r0, #0x0
           .text:0x0000EE70    BEDA                 bge code_0xEDF0
           */
        if (r0 < 0) {
          /*
             .text:0x0000EE72 code_0xEE72:
             .text:0x0000EE72    0020                 movs r0, #0x0
             .text:0x0000EE74    BCE7                 b code_0xEDF0
             */
        }
      }
    }
    /*
       .text:0x0000EDF0 code_0xEDF0:
       .text:0x0000EDF0    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000EDF4    00EE100A             vmov s0, r0
       .text:0x0000EDF8    B8EEC00A             vcvt.f32.s32 s0, s0
       .text:0x0000EDFC    84ED040A             vstr s0, [r4, #0x10]
       .text:0x0000EE00    9BF8E504             ldrb.w r0, [fp, #0x4E5]
       .text:0x0000EE04    88B3                 cbz r0, code_0xEE6A
       */
    /*
       .text:0x0000EE6A code_0xEE6A:
       .text:0x0000EE6A    04E0                 b code_0xEE76
       */
    if (r0 != 0) {
      /*
         .text:0x0000EE06 code_0xEE06:
         .text:0x0000EE06    7F20                 movs r0, #0x7F
         */
    } else {
      /*
         .text:0x0000EE76 code_0xEE76:
         .text:0x0000EE76    9BF8EC04             ldrb.w r0, [fp, #0x4EC]
         .text:0x0000EE7A    C0F1FC00             rsb.w r0, r0, #0xFC
         .text:0x0000EE7E    C0B2                 uxtb r0, r0
         .text:0x0000EE80    C2E7                 b code_0xEE08
         */
    }
    /*
       .text:0x0000EE08 code_0xEE08:
       .text:0x0000EE08    9BF8F514             ldrb.w r1, [fp, #0x4F5]
       .text:0x0000EE0C    71B3                 cbz r1, code_0xEE6C
       */
    /*
       .text:0x0000EE6C code_0xEE6C:
       .text:0x0000EE6C    09E0                 b code_0xEE82
       */
    if (r1 != 0) {
      /*
         .text:0x0000EE0E code_0xEE0E:
         .text:0x0000EE0E    94ED040A             vldr s0, [r4, #0x10]
         .text:0x0000EE12    C0EE0A0A             vdiv.f32 s1, s0, s20
         .text:0x0000EE16    30EEC80A             vsub.f32 s0, s1, s16
         .text:0x0000EE1A    84ED040A             vstr s0, [r4, #0x10]
         */
    } else {
      /*
         .text:0x0000EE82 code_0xEE82:
         .text:0x0000EE82    00EE100A             vmov s0, r0
         .text:0x0000EE86    D4ED040A             vldr s1, [r4, #0x10]
         .text:0x0000EE8A    B8EE400A             vcvt.f32.u32 s0, s0
         .text:0x0000EE8E    30EEC00A             vsub.f32 s0, s1, s0
         .text:0x0000EE92    84ED040A             vstr s0, [r4, #0x10]
         .text:0x0000EE96    94ED040A             vldr s0, [r4, #0x10]
         .text:0x0000EE9A    10EE101A             vmov r1, s0
         .text:0x0000EE9E    A942                 cmp r1, r5
         .text:0x0000EEA0    0AD2                 bhs code_0xEEB8
         */
      if (r1 < r5) {
        /*
           .text:0x0000EEA2 code_0xEEA2:
           .text:0x0000EEA2    94ED040A             vldr s0, [r4, #0x10]
           .text:0x0000EEA6    10EE101A             vmov r1, s0
           .text:0x0000EEAA    B142                 cmp r1, r6
           .text:0x0000EEAC    04DA                 bge code_0xEEB8
           */
        if (r1 < r6) {
          /*
             .text:0x0000EEAE code_0xEEAE:
             .text:0x0000EEAE    00E0                 b code_0xEEB2
             */
          /*
             .text:0x0000EEB2 code_0xEEB2:
             .text:0x0000EEB2    C4ED049A             vstr s19, [r4, #0x10]
             .text:0x0000EEB6    42E0                 b code_0xEF3E
             */
        }
      }
      /*
         .text:0x0000EEB8 code_0xEEB8:
         .text:0x0000EEB8    94ED040A             vldr s0, [r4, #0x10]
         .text:0x0000EEBC    B5EEC00A             vcmpe.f32 s0, #0x0
         .text:0x0000EEC0    F1EE10FA             vmrs APSR_nzcv, fpscr
         .text:0x0000EEC4    1EDD                 ble code_0xEF04
         */
      if (s0 > 0.0) {
        /*
           .text:0x0000EEC6 code_0xEEC6:
           .text:0x0000EEC6    F228                 cmp r0, #0xF2
           .text:0x0000EEC8    10D0                 beq code_0xEEEC
           */
        if (r0 != 0xF2) {
          /*
             .text:0x0000EECA code_0xEECA:
             .text:0x0000EECA    94ED040A             vldr s0, [r4, #0x10]
             .text:0x0000EECE    C0F1F200             rsb.w r0, r0, #0xF2
             .text:0x0000EED2    30EE6A0A             vsub.f32 s0, s0, s21
             .text:0x0000EED6    60EE0B0A             vmul.f32 s1, s0, s22
             .text:0x0000EEDA    00EE100A             vmov s0, r0
             .text:0x0000EEDE    B8EEC00A             vcvt.f32.s32 s0, s0
             .text:0x0000EEE2    80EE801A             vdiv.f32 s2, s1, s0
             .text:0x0000EEE6    84ED041A             vstr s2, [r4, #0x10]
             .text:0x0000EEEA    01E0                 b code_0xEEF0
             */
        } else {
          /*
             .text:0x0000EEEC code_0xEEEC:
             .text:0x0000EEEC    C4ED049A             vstr s19, [r4, #0x10]
             */
        }
        /*
           .text:0x0000EEF0 code_0xEEF0:
           .text:0x0000EEF0    94ED040A             vldr s0, [r4, #0x10]
           .text:0x0000EEF4    B5EEC00A             vcmpe.f32 s0, #0x0
           .text:0x0000EEF8    F1EE10FA             vmrs APSR_nzcv, fpscr
           .text:0x0000EEFC    1FD2                 bhs code_0xEF3E
           */
        if (s0 < 0.0) {
          /*
             .text:0x0000EEFE code_0xEEFE:
             .text:0x0000EEFE    C4ED049A             vstr s19, [r4, #0x10]
             .text:0x0000EF02    1CE0                 b code_0xEF3E
             */
        }
      } else {
        /*
           .text:0x0000EF04 code_0xEF04:
           .text:0x0000EF04    0A28                 cmp r0, #0xA
           .text:0x0000EF06    0FD0                 beq code_0xEF28
           */
        if (r0 != 0xA) {
          /*
             .text:0x0000EF08 code_0xEF08:
             .text:0x0000EF08    94ED040A             vldr s0, [r4, #0x10]
             .text:0x0000EF0C    0A38                 subs r0, #0xA
             .text:0x0000EF0E    30EE2A0A             vadd.f32 s0, s0, s21
             .text:0x0000EF12    60EE0B0A             vmul.f32 s1, s0, s22
             .text:0x0000EF16    00EE100A             vmov s0, r0
             .text:0x0000EF1A    B8EEC00A             vcvt.f32.s32 s0, s0
             .text:0x0000EF1E    80EE801A             vdiv.f32 s2, s1, s0
             .text:0x0000EF22    84ED041A             vstr s2, [r4, #0x10]
             .text:0x0000EF26    01E0                 b code_0xEF2C
             */
        } else {
          /*
             .text:0x0000EF28 code_0xEF28:
             .text:0x0000EF28    C4ED049A             vstr s19, [r4, #0x10]
             */
        }
        /*
           .text:0x0000EF2C code_0xEF2C:
           .text:0x0000EF2C    94ED040A             vldr s0, [r4, #0x10]
           .text:0x0000EF30    B5EEC00A             vcmpe.f32 s0, #0x0
           .text:0x0000EF34    F1EE10FA             vmrs APSR_nzcv, fpscr
           .text:0x0000EF38    01DD                 ble code_0xEF3E
           */
        /*
           .text:0x0000EF3A code_0xEF3A:
           .text:0x0000EF3A    C4ED049A             vstr s19, [r4, #0x10]
           */
      }
    }
    /*
       .text:0x0000EF3E code_0xEF3E:
       .text:0x0000EF3E    94ED040A             vldr s0, [r4, #0x10]
       .text:0x0000EF42    C0EE0A0A             vdiv.f32 s1, s0, s20
       .text:0x0000EF46    C4ED040A             vstr s1, [r4, #0x10]
       .text:0x0000EF4A    68E7                 b code_0xEE1E
       */
    /*
       .text:0x0000EE1E code_0xEE1E:
       .text:0x0000EE1E    94ED040A             vldr s0, [r4, #0x10]
       .text:0x0000EE22    84ED060A             vstr s0, [r4, #0x18]
       .text:0x0000EE26    4F20                 movs r0, #0x4F
       .text:0x0000EE28    F4F79EF8             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EE2C code_0xEE2C:
     .text:0x0000EE2C    0120                 movs r0, #0x1
     .text:0x0000EE2E    F9F7CBFB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EE32    E8BB                 cbnz r0, code_0xEEB0
     */
  /*
     .text:0x0000EE34 code_0xEE34:
     .text:0x0000EE34    8AE0                 b code_0xEF4C
     */
  /*
     .text:0x0000EEB0 code_0xEEB0:
     .text:0x0000EEB0    50E0                 b code_0xEF54
     */
  if (r0 == 0) {
    /*
       .text:0x0000EF4C code_0xEF4C:
       .text:0x0000EF4C    0220                 movs r0, #0x2
       .text:0x0000EF4E    F9F73BFB             bl func_0x85C8; inline int __cdecl( int p1 )
       .text:0x0000EF52    38B1                 cbz r0, code_0xEF64
       */
    if (r0 != 0) {
      /*
         .text:0x0000EF54 code_0xEF54:
         .text:0x0000EF54    FDF7E6FD             bl func_0xCB24; void __cdecl( int p1, int p2, int p3 )
         .text:0x0000EF58    0120                 movs r0, #0x1
         .text:0x0000EF5A    F4F705F8             bl func_0x2F68; inline void __cdecl( int p1 )
         .text:0x0000EF5E    0220                 movs r0, #0x2
         .text:0x0000EF60    F4F702F8             bl func_0x2F68; inline void __cdecl( int p1 )
         */
    }
  } else {
    /*
       .text:0x0000EF54 code_0xEF54:
       .text:0x0000EF54    FDF7E6FD             bl func_0xCB24; void __cdecl( int p1, int p2, int p3 )
       .text:0x0000EF58    0120                 movs r0, #0x1
       .text:0x0000EF5A    F4F705F8             bl func_0x2F68; inline void __cdecl( int p1 )
       .text:0x0000EF5E    0220                 movs r0, #0x2
       .text:0x0000EF60    F4F702F8             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EF64 code_0xEF64:
     .text:0x0000EF64    1F20                 movs r0, #0x1F
     .text:0x0000EF66    F9F72FFB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EF6A    18B9                 cbnz r0, code_0xEF74
     */
  if (r0 == 0) {
    /*
       .text:0x0000EF6C code_0xEF6C:
       .text:0x0000EF6C    2020                 movs r0, #0x20
       .text:0x0000EF6E    F9F72BFB             bl func_0x85C8; inline int __cdecl( int p1 )
       .text:0x0000EF72    38B1                 cbz r0, code_0xEF84
       */
    if (r0 != 0) {
      /*
         .text:0x0000EF74 code_0xEF74:
         .text:0x0000EF74    FDF714FE             bl func_0xCBA0; void __cdecl( int p1, int p2, int p3 )
         .text:0x0000EF78    1F20                 movs r0, #0x1F
         .text:0x0000EF7A    F3F7F5FF             bl func_0x2F68; inline void __cdecl( int p1 )
         .text:0x0000EF7E    2020                 movs r0, #0x20
         .text:0x0000EF80    F3F7F2FF             bl func_0x2F68; inline void __cdecl( int p1 )
         */
    }
  }
  /*
      .text:0x0000EF74 code_0xEF74:
      .text:0x0000EF74    FDF714FE             bl func_0xCBA0; void __cdecl( int p1, int p2, int p3 )
      .text:0x0000EF78    1F20                 movs r0, #0x1F
      .text:0x0000EF7A    F3F7F5FF             bl func_0x2F68; inline void __cdecl( int p1 )
      .text:0x0000EF7E    2020                 movs r0, #0x20
      .text:0x0000EF80    F3F7F2FF             bl func_0x2F68; inline void __cdecl( int p1 )
      */
  /*
     .text:0x0000EF84 code_0xEF84:
     .text:0x0000EF84    0020                 movs r0, #0x0
     .text:0x0000EF86    F9F71FFB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EF8A    20B1                 cbz r0, code_0xEF96
     */
  if (r0 != 0) {
    /*
       .text:0x0000EF8C code_0xEF8C:
       .text:0x0000EF8C    FDF746FE             bl func_0xCC1C; void __cdecl( void )
       .text:0x0000EF90    0020                 movs r0, #0x0
       .text:0x0000EF92    F3F7E9FF             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EF96 code_0xEF96:
     .text:0x0000EF96    1E20                 movs r0, #0x1E
     .text:0x0000EF98    F9F716FB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EF9C    20B1                 cbz r0, code_0xEFA8
     */
  if (r0 != 0) {
    /*
       .text:0x0000EF9E code_0xEF9E:
       .text:0x0000EF9E    FDF785FE             bl func_0xCCAC; void __cdecl( void )
       .text:0x0000EFA2    1E20                 movs r0, #0x1E
       .text:0x0000EFA4    F3F7E0FF             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EFA8 code_0xEFA8:
     .text:0x0000EFA8    05F060FA             bl func_0x1446C; void __cdecl( int p1, int p2, int p3 )
     .text:0x0000EFAC    3220                 movs r0, #0x32
     .text:0x0000EFAE    F9F70BFB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EFB2    20B1                 cbz r0, code_0xEFBE
     */
  if (r0 != 0) {
    /*
       .text:0x0000EFB4 code_0xEFB4:
       .text:0x0000EFB4    05F038FA             bl func_0x14428; void __cdecl( void )
       .text:0x0000EFB8    3220                 movs r0, #0x32
       .text:0x0000EFBA    F3F7D5FF             bl func_0x2F68; inline void __cdecl( int p1 )
       */
  }
  /*
     .text:0x0000EFBE code_0xEFBE:
     .text:0x0000EFBE    3A20                 movs r0, #0x3A
     .text:0x0000EFC0    F9F702FB             bl func_0x85C8; inline int __cdecl( int p1 )
     .text:0x0000EFC4    0028                 cmp r0, #0x0
     .text:0x0000EFC6    00F01380             beq.w code_0xEFF0
     */
  if (r0 != 0) {
    /*
       .text:0x0000EFCA code_0xEFCA:
       .text:0x0000EFCA    3A20                 movs r0, #0x3A
       .text:0x0000EFCC    0EF0DAF8             bl func_0x1D184; int __cdecl( int p1, int p2 )
       .text:0x0000EFD0    1149                 ldr r1, [data_0xF018]
       .text:0x0000EFD2    C0F1FF00             rsb.w r0, r0, #0xFF
       .text:0x0000EFD6    01EBC000             add.w r0, r1, r0, lsl #0x3
       .text:0x0000EFDA    90ED000A             vldr s0, [r0]
       .text:0x0000EFDE    84ED070A             vstr s0, [r4, #0x1C]
       .text:0x0000EFE2    3A20                 movs r0, #0x3A
       .text:0x0000EFE4    BDEC0E8B             vpop {d8, d9, d10, d11, d12, d13, d14}
       .text:0x0000EFE8    BDE8F05F             pop.w {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
       .text:0x0000EFEC    F3F7BCBF             b.w func_0x2F68; inline void __cdecl( int p1 )
       */
  } else {
  /*
     .text:0x0000EFF0 code_0xEFF0:
     .text:0x0000EFF0    BDEC0E8B             vpop {d8, d9, d10, d11, d12, d13, d14}
     .text:0x0000EFF4    BDE8F09F             pop.w {r4, r5, r6, r7, r8, sb, sl, fp, ip, pc}
     */
  }
}
