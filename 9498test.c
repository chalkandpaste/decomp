long func_0x8029498 ( int r0, int r1, int r2 ){
/*0x8029498
0x8029498 4 2de9f04f stmdb sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
0x802949c 2 a9b0 sub sp, 164
0x802949e 2 0646 mov r6, r0
0x80294a0 4 02f088fa bl 0x802b9b4 ; int func_0x802b9b4 ()
0x80294a4 2 0146 mov r1, r0
0x80294a6 4 06eb4600 add.w r0, r6, r6, lsl 1
0x80294aa 2 fe4a mov r2, 0x20001fd4
0x80294ac 2 fc4c mov r4, 0x20000500
0x80294ae 4 00ebc600 add.w r0, r0, r6, lsl 3
0x80294b2 4 02eb8008 add.w r8, r2, r0, lsl 2
0x80294b6 2 0229 cmp r1, 2
0x80294b8 2 69d0 beq.n 0x802958e
*/
cond0 = r1 != 2;
if ( cond0 ) 
{
/*0x80294ba
0x80294ba 4 02f07bfa bl 0x802b9b4 ; int func_0x802b9b4 ()
0x80294be 2 0028 cmp r0, 0
0x80294c0 2 69d0 beq.n 0x8029596
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x80294c2
0x80294c2 4 98f80700 ldrb.w r0, [r8, 7]
0x80294c6 2 a055 strb r0, [r4, r6]
*/

}
else
{
/*0x8029596
0x8029596 2 c948 mov r0, 0x20000f48
0x8029598 2 0078 ldrb r0, [r0, 0]
0x802959a 2 a055 strb r0, [r4, r6]
0x802959c 2 94e7 b.n 0x80294c8
*/

}
/*0x80294c8
0x80294c8 2 3d20 movs r0, 61
0x80294ca 4 13f05bfe bl 0x803d184 ; int func_0x803d184 ( int r0 )
0x80294ce 2 f649 mov r1, 0x8046024
0x80294d0 4 c0f1ff00 rsb r0, r0, 255
0x80294d4 4 01ebc000 add.w r0, r1, r0, lsl 3
0x80294d8 2 f54a mov r2, 0x2000501c
0x80294da 4 90ed000a vldr s0, [r0]
0x80294de 2 f348 mov r0, 0x20005484
0x80294e0 4 02eb4601 add.w r1, r2, r6, lsl 1
0x80294e4 4 00eb8600 add.w r0, r0, r6, lsl 2
0x80294e8 2 2790 str r0, [sp, 156]
0x80294ea 4 d0ed000a vldr s1, [r0]
0x80294ee 2 2691 str r1, [sp, 152]
0x80294f0 4 20ee200a vmul.f32 s0, s0, s1
0x80294f4 4 bdeec00a vcvt.s32.f32 s0, s0
0x80294f8 4 10ee100a vmov r0, s0
0x80294fc 2 00b2 sxth r0, r0
0x80294fe 4 a1f84c00 strh.w r0, [r1, 76]
0x8029502 4 b0f5007f cmp.w r0, 512
0x8029506 2 04db blt.n 0x8029512
*/
cond0 = r0 >= 512;
if ( cond0 ) 
{
/*0x8029508
0x8029508 2 2698 ldr r0, [sp, 152]
0x802950a 4 40f2ff11 movw r1, 511
0x802950e 4 a0f84c10 strh.w r1, [r0, 76]
*/

}
/*0x8029512
0x8029512 2 0024 movs r4, 0
0x8029514 2 e748 mov r0, 0x20005274
0x8029516 2 0022 movs r2, 0
0x8029518 4 00eb8609 add.w r9, r0, r6, lsl 2
0x802951c 4 00f5d870 add.w r0, r0, 432
0x8029520 4 00ebc600 add.w r0, r0, r6, lsl 3
0x8029524 2 2590 str r0, [sp, 148]
0x8029526 4 06f00300 and.w r0, r6, 3
0x802952a 2 2190 str r0, [sp, 132]
0x802952c 4 02eb4000 add.w r0, r2, r0, lsl 1
0x8029530 2 2490 str r0, [sp, 144]
0x8029532 2 2198 ldr r0, [sp, 132]
0x8029534 2 0122 movs r2, 1
0x8029536 2 e049 mov r1, 0x20005380
0x8029538 4 02eb4000 add.w r0, r2, r0, lsl 1
0x802953c 2 2390 str r0, [sp, 140]
0x802953e 4 01f1e400 add.w r0, r1, 228
0x8029542 4 00eb8600 add.w r0, r0, r6, lsl 2
0x8029546 2 2290 str r0, [sp, 136]
0x8029548 2 0420 movs r0, 4
0x802954a 4 00eb9600 add.w r0, r0, r6, lsr 2
0x802954e 2 2090 str r0, [sp, 128]
0x8029550 4 01eb4600 add.w r0, r1, r6, lsl 1
0x8029554 2 1f90 str r0, [sp, 124]
0x8029556 4 01eb8600 add.w r0, r1, r6, lsl 2
0x802955a 2 1e90 str r0, [sp, 120]
0x802955c 2 0aa8 add r0, sp, 40
0x802955e 4 00ebc600 add.w r0, r0, r6, lsl 3
0x8029562 2 1d90 str r0, [sp, 116]
0x8029564 4 a1f58670 sub.w r0, r1, 268
0x8029568 2 02ab add r3, sp, 8
0x802956a 4 00ebc600 add.w r0, r0, r6, lsl 3
0x802956e 4 03eb860a add.w sl, r3, r6, lsl 2
0x8029572 2 1c90 str r0, [sp, 112]
*/
while (1) 
{
/*0x8029574
0x8029574 4 07f010fa bl 0x8030998 ; int func_0x8030998 ()
0x8029578 2 88b1 cbz r0, 0x802959e
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x802957a
0x802957a 2 0627 movs r7, 6
*/

}
else
{
/*0x802959e
0x802959e 2 0427 movs r7, 4
0x80295a0 2 ece7 b.n 0x802957c
*/

}
while (1) 
{
/*0x802957c
0x802957c 4 dff830b3 mov fp, 0x2000501c
0x8029580 4 bbf94a50 ldrsh.w r5, [fp, 74]
0x8029584 4 f9f768fb bl 0x8022c58 ; int func_0x8022c58 ()
0x8029588 2 0328 cmp r0, 3
0x802958a 2 0ad0 beq.n 0x80295a2
*/
cond0 = r0 != 3;
if ( cond0 ) 
{
/*0x802958c
0x802958c 2 1be0 b.n 0x80295c6
*/

}
else
{
/*0x80295a2
0x80295a2 4 02f007fa bl 0x802b9b4 ; int func_0x802b9b4 ()
0x80295a6 2 0228 cmp r0, 2
0x80295a8 2 0dd1 bne.n 0x80295c6
*/
cond0 = r0 == 2;
if ( cond0 ) 
{
while (1) 
{
/*0x80295aa
0x80295aa 2 3046 mov r0, r6
0x80295ac 4 f9f75afb bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x80295b0 4 05eb4000 add.w r0, r5, r0, lsl 1
0x80295b4 2 05b2 sxth r5, r0
0x80295b6 4 b5f5007f cmp.w r5, 512
0x80295ba 2 01db blt.n 0x80295c0
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x80295bc
0x80295bc 4 40f2ff15 movw r5, 511
*/

}
/*0x80295c0
0x80295c0 2 002d cmp r5, 0
0x80295c2 2 00da bge.n 0x80295c6
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x80295c4
0x80295c4 2 0025 movs r5, 0
*/

}
while (1) 
{
/*0x80295c6
0x80295c6 2 3046 mov r0, r6
0x80295c8 4 fef758fd bl 0x802807c ; int func_0x802807c ( int r0 )
0x80295cc 4 20f00301 bic.w r1, r0, 3
0x80295d0 2 bb48 mov r0, 0x8043024
0x80295d2 4 00ee107a vmov s0, r7
0x80295d6 2 0844 add r0, r1
0x80295d8 2 269a ldr r2, [sp, 152]
0x80295da 4 d0ed000a vldr s1, [r0]
0x80295de 4 b8ee400a vcvt.f32.u32 s0, s0
0x80295e2 2 b848 mov r0, 0x8042524
0x80295e4 4 b2f94c20 ldrsh.w r2, [r2, 76]
0x80295e8 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80295ec 4 00eb8200 add.w r0, r0, r2, lsl 2
0x80295f0 4 20ee800a vmul.f32 s0, s1, s0
0x80295f4 4 d1ed000a vldr s1, [r1]
0x80295f8 4 90ed001a vldr s2, [r0]
0x80295fc 2 ac49 mov r1, 0x2000501c
0x80295fe 4 70ee810a vadd.f32 s1, s1, s2
0x8029602 4 01f5167b add.w fp, r1, 600
0x8029606 4 20ee200a vmul.f32 s0, s0, s1
0x802960a 4 bdeec00a vcvt.s32.f32 s0, s0
0x802960e 4 10ee100a vmov r0, s0
0x8029612 4 a9f84c00 strh.w r0, [r9, 76]
0x8029616 4 01eb4400 add.w r0, r1, r4, lsl 1
0x802961a 2 1b90 str r0, [sp, 108]
0x802961c 4 b0f96000 ldrsh.w r0, [r0, 96]
0x8029620 2 c110 asrs r1, r0, 3
0x8029622 2 a948 mov r0, 0x804d824
0x8029624 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x8029628 2 1c99 ldr r1, [sp, 112]
0x802962a 4 00ee100a vmov s0, r0
0x802962e 2 2798 ldr r0, [sp, 156]
0x8029630 4 01eb8407 add.w r7, r1, r4, lsl 2
0x8029634 4 b8ee400a vcvt.f32.u32 s0, s0
0x8029638 4 d0ed000a vldr s1, [r0]
0x802963c 4 20ee200a vmul.f32 s0, s0, s1
0x8029640 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029644 4 10ee100a vmov r0, s0
0x8029648 4 a7f8ac00 strh.w r0, [r7, 172]
0x802964c 4 0beb8400 add.w r0, fp, r4, lsl 2
0x8029650 2 1a90 str r0, [sp, 104]
0x8029652 4 b0f94050 ldrsh.w r5, [r0, 64]
0x8029656 4 f9f7fffa bl 0x8022c58 ; int func_0x8022c58 ()
0x802965a 2 0828 cmp r0, 8
0x802965c 2 04d1 bne.n 0x8029668
*/
cond2 = r0 == 8;
/*0x802965e
0x802965e 2 1cb9 cbnz r4, 0x8029668
*/
cond1 = r4 == 0;
/*0x8029660
0x8029660 4 02f0a8f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029664 2 0228 cmp r0, 2
0x8029666 2 04d0 beq.n 0x8029672
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{
while (1) 
{
/*0x8029672
0x8029672 2 3046 mov r0, r6
0x8029674 4 f9f7f6fa bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x8029678 4 05eb0010 add.w r0, r5, r0, lsl 4
0x802967c 2 05b2 sxth r5, r0
0x802967e 4 b5f5805f cmp.w r5, 4096
0x8029682 2 01db blt.n 0x8029688
*/
cond0 = r5 >= 4096;
if ( cond0 ) 
{
/*0x8029684
0x8029684 4 40f6ff75 movw r5, 4095
*/

}
/*0x8029688
0x8029688 2 002d cmp r5, 0
0x802968a 2 15da bge.n 0x80296b8
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x802968c
0x802968c 2 0025 movs r5, 0
0x802968e 2 13e0 b.n 0x80296b8
*/

}
while (1) 
{
/*0x80296b8
0x80296b8 2 7e48 mov r0, 0x20005274
0x80296ba 4 b0f948b0 ldrsh.w fp, [r0, 72]
0x80296be 4 f9f7cbfa bl 0x8022c58 ; int func_0x8022c58 ()
0x80296c2 2 0528 cmp r0, 5
0x80296c4 2 14d1 bne.n 0x80296f0
*/
cond1 = r0 == 5;
/*0x80296c6
0x80296c6 4 02f075f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x80296ca 2 0228 cmp r0, 2
0x80296cc 2 10d1 bne.n 0x80296f0
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
while (1) 
{
/*0x80296ce
0x80296ce 2 3046 mov r0, r6
0x80296d0 4 f9f7c8fa bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x80296d4 4 0beb0010 add.w r0, fp, r0, lsl 4
0x80296d8 4 0ffa80fb sxth.w fp, r0
0x80296dc 4 bbf5805f cmp.w fp, 4096
0x80296e0 2 01db blt.n 0x80296e6
*/
cond0 = fp >= 4096;
if ( cond0 ) 
{
/*0x80296e2
0x80296e2 4 40f6ff7b movw fp, 4095
*/

}
/*0x80296e6
0x80296e6 4 bbf1000f cmp.w fp, 0
0x80296ea 2 01da bge.n 0x80296f0
*/
cond0 = fp < 0;
if ( cond0 ) 
{
/*0x80296ec
0x80296ec 4 4ff0000b mov.w fp, 0
*/

}
while (1) 
{
/*0x80296f0
0x80296f0 4 fef77afd bl 0x80281e8 ; int func_0x80281e8 ()
0x80296f4 2 20b3 cbz r0, 0x8029740
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x80296f6
0x80296f6 4 98f80500 ldrb.w r0, [r8, 5]
0x80296fa 4 fef773ff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x80296fe 4 b7f86c10 ldrh.w r1, [r7, 108]
0x8029702 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029706 2 1144 add r1, r2
0x8029708 4 b9f84c20 ldrh.w r2, [r9, 76]
0x802970c 2 2a44 add r2, r5
0x802970e 2 1144 add r1, r2
0x8029710 2 5944 add r1, fp
0x8029712 2 0844 add r0, r1
0x8029714 2 1d99 ldr r1, [sp, 116]
0x8029716 4 21f82400 strh.w r0, [r1, r4, lsl 2]
*/

}
else
{
/*0x8029740
0x8029740 4 98f80500 ldrb.w r0, [r8, 5]
0x8029744 4 fef74eff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x8029748 4 b7f86c10 ldrh.w r1, [r7, 108]
0x802974c 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029750 2 691a subs r1, r5, r1
0x8029752 2 891a subs r1, r1, r2
0x8029754 4 b9f84c20 ldrh.w r2, [r9, 76]
0x8029758 2 891a subs r1, r1, r2
0x802975a 4 a1eb0b01 sub.w r1, r1, fp
0x802975e 2 081a subs r0, r1, r0
0x8029760 2 1d99 ldr r1, [sp, 116]
0x8029762 4 21f82400 strh.w r0, [r1, r4, lsl 2]
0x8029766 2 d8e7 b.n 0x802971a
*/

}
while (1) 
{
/*0x802971a
0x802971a 2 1d98 ldr r0, [sp, 116]
0x802971c 4 30f82410 ldrh.w r1, [r0, r4, lsl 2]
0x8029720 2 2598 ldr r0, [sp, 148]
0x8029722 4 20f82410 strh.w r1, [r0, r4, lsl 2]
0x8029726 4 07f037f9 bl 0x8030998 ; int func_0x8030998 ()
0x802972a 2 e8b1 cbz r0, 0x8029768
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x802972c
0x802972c 2 0820 movs r0, 8
0x802972e 2 0190 str r0, [sp, 4]
*/

}
else
{
/*0x8029768
0x8029768 2 0620 movs r0, 6
0x802976a 2 0190 str r0, [sp, 4]
0x802976c 2 e0e7 b.n 0x8029730
*/

}
while (1) 
{
/*0x8029730
0x8029730 2 5f48 mov r0, 0x2000501c
0x8029732 4 b0f94a50 ldrsh.w r5, [r0, 74]
0x8029736 4 f9f78ffa bl 0x8022c58 ; int func_0x8022c58 ()
0x802973a 2 0328 cmp r0, 3
0x802973c 2 17d0 beq.n 0x802976e
*/
cond0 = r0 != 3;
if ( cond0 ) 
{
/*0x802973e
0x802973e 2 28e0 b.n 0x8029792
*/

}
else
{
/*0x802976e
0x802976e 4 02f021f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029772 2 0228 cmp r0, 2
0x8029774 2 0dd1 bne.n 0x8029792
*/
cond0 = r0 == 2;
if ( cond0 ) 
{
while (1) 
{
/*0x8029776
0x8029776 2 3046 mov r0, r6
0x8029778 4 f9f774fa bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802977c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029780 2 05b2 sxth r5, r0
0x8029782 4 b5f5007f cmp.w r5, 512
0x8029786 2 01db blt.n 0x802978c
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029788
0x8029788 4 40f2ff15 movw r5, 511
*/

}
/*0x802978c
0x802978c 2 002d cmp r5, 0
0x802978e 2 00da bge.n 0x8029792
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029790
0x8029790 2 0025 movs r5, 0
*/

}
while (1) 
{
/*0x8029792
0x8029792 2 3046 mov r0, r6
0x8029794 4 fef772fc bl 0x802807c ; int func_0x802807c ( int r0 )
0x8029798 4 20f00301 bic.w r1, r0, 3
0x802979c 2 4b48 mov r0, 0x8044024
0x802979e 4 dff814b1 mov fp, 0x20005274
0x80297a2 2 0844 add r0, r1
0x80297a4 4 d0ed000a vldr s1, [r0]
0x80297a8 2 0198 ldr r0, [sp, 4]
0x80297aa 4 00ee100a vmov s0, r0
0x80297ae 2 4548 mov r0, 0x8042524
0x80297b0 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297b4 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80297b8 4 20ee800a vmul.f32 s0, s1, s0
0x80297bc 4 d1ed000a vldr s1, [r1]
0x80297c0 2 2699 ldr r1, [sp, 152]
0x80297c2 4 b1f94c10 ldrsh.w r1, [r1, 76]
0x80297c6 4 00eb8100 add.w r0, r0, r1, lsl 2
0x80297ca 4 90ed001a vldr s2, [r0]
0x80297ce 4 70ee810a vadd.f32 s1, s1, s2
0x80297d2 4 20ee200a vmul.f32 s0, s0, s1
0x80297d6 4 bdeec00a vcvt.s32.f32 s0, s0
0x80297da 4 10ee100a vmov r0, s0
0x80297de 4 a9f84e00 strh.w r0, [r9, 78]
0x80297e2 2 1b98 ldr r0, [sp, 108]
0x80297e4 4 b0f96000 ldrsh.w r0, [r0, 96]
0x80297e8 2 c110 asrs r1, r0, 3
0x80297ea 2 3948 mov r0, 0x804dc24
0x80297ec 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x80297f0 4 00ee100a vmov s0, r0
0x80297f4 2 2798 ldr r0, [sp, 156]
0x80297f6 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297fa 4 d0ed000a vldr s1, [r0]
0x80297fe 4 20ee200a vmul.f32 s0, s0, s1
0x8029802 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029806 4 10ee100a vmov r0, s0
0x802980a 4 a7f8ae00 strh.w r0, [r7, 174]
0x802980e 2 1a98 ldr r0, [sp, 104]
0x8029810 4 b0f94250 ldrsh.w r5, [r0, 66]
0x8029814 4 f9f720fa bl 0x8022c58 ; int func_0x8022c58 ()
0x8029818 2 0628 cmp r0, 6
0x802981a 2 04d1 bne.n 0x8029826
*/
cond2 = r0 == 6;
/*0x802981c
0x802981c 2 1cb9 cbnz r4, 0x8029826
*/
cond1 = r4 == 0;
/*0x802981e
0x802981e 4 02f0c9f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029822 2 0228 cmp r0, 2
0x8029824 2 04d0 beq.n 0x8029830
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{
while (1) 
{
/*0x8029830
0x8029830 2 3046 mov r0, r6
0x8029832 4 f9f717fa bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x8029836 4 05eb0010 add.w r0, r5, r0, lsl 4
0x802983a 2 05b2 sxth r5, r0
0x802983c 4 b5f5805f cmp.w r5, 4096
0x8029840 2 01db blt.n 0x8029846
*/
cond0 = r5 >= 4096;
if ( cond0 ) 
{
/*0x8029842
0x8029842 4 40f6ff75 movw r5, 4095
*/

}
/*0x8029846
0x8029846 2 002d cmp r5, 0
0x8029848 2 15da bge.n 0x8029876
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x802984a
0x802984a 2 0025 movs r5, 0
0x802984c 2 13e0 b.n 0x8029876
*/

}
while (1) 
{
/*0x8029876
0x8029876 4 bbf94ab0 ldrsh.w fp, [fp, 74]
0x802987a 4 f9f7edf9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802987e 2 0528 cmp r0, 5
0x8029880 2 2fd1 bne.n 0x80298e2
*/
cond1 = r0 == 5;
/*0x8029882
0x8029882 4 02f097f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029886 2 0228 cmp r0, 2
0x8029888 2 2bd1 bne.n 0x80298e2
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
while (1) 
{
/*0x802988a
0x802988a 2 3046 mov r0, r6
0x802988c 4 f9f7eaf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x8029890 4 0beb0010 add.w r0, fp, r0, lsl 4
0x8029894 4 0ffa80fb sxth.w fp, r0
0x8029898 4 bbf5805f cmp.w fp, 4096
0x802989c 2 1cdb blt.n 0x80298d8
*/
cond0 = fp >= 4096;
if ( cond0 ) 
{
/*0x802989e
0x802989e 2 19e0 b.n 0x80298d4
*/

/*0x80298d4
0x80298d4 4 40f6ff7b movw fp, 4095
*/

}
/*0x80298d8
0x80298d8 4 bbf1000f cmp.w fp, 0
0x80298dc 2 01da bge.n 0x80298e2
*/
cond0 = fp < 0;
if ( cond0 ) 
{
/*0x80298de
0x80298de 4 4ff0000b mov.w fp, 0
*/

}
while (1) 
{
/*0x80298e2
0x80298e2 4 98f80500 ldrb.w r0, [r8, 5]
0x80298e6 4 fef78bfe bl 0x8028600 ; int func_0x8028600 ( int r0, int r1 )
0x80298ea 4 b7f86e10 ldrh.w r1, [r7, 110]
0x80298ee 4 b7f8ae20 ldrh.w r2, [r7, 174]
0x80298f2 2 1144 add r1, r2
0x80298f4 4 b9f84e20 ldrh.w r2, [r9, 78]
0x80298f8 2 2a44 add r2, r5
0x80298fa 2 1144 add r1, r2
0x80298fc 2 5944 add r1, fp
0x80298fe 2 0844 add r0, r1
0x8029900 2 1d99 ldr r1, [sp, 116]
0x8029902 4 01eb8401 add.w r1, r1, r4, lsl 2
0x8029906 2 4880 strh r0, [r1, 2]
0x8029908 2 2599 ldr r1, [sp, 148]
0x802990a 4 01eb8401 add.w r1, r1, r4, lsl 2
0x802990e 2 4880 strh r0, [r1, 2]
0x8029910 2 5c4f mov r7, 0x20005088
0x8029912 4 b7f9e450 ldrsh.w r5, [r7, 228]
0x8029916 4 f9f79ff9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802991a 2 0428 cmp r0, 4
0x802991c 2 09d1 bne.n 0x8029932
*/
cond1 = r0 == 4;
/*0x802991e
0x802991e 4 02f049f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029922 2 0228 cmp r0, 2
0x8029924 2 05d1 bne.n 0x8029932
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
/*0x8029926
0x8029926 2 3046 mov r0, r6
0x8029928 4 f9f79cf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802992c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029930 2 05b2 sxth r5, r0
*/

}
while (1) 
{
/*0x8029932
0x8029932 4 b5f5007f cmp.w r5, 512
0x8029936 2 02db blt.n 0x802993e
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029938
0x8029938 4 40f2ff15 movw r5, 511
0x802993c 2 02e0 b.n 0x8029944
*/

}
else
{
/*0x802993e
0x802993e 2 002d cmp r5, 0
0x8029940 2 00da bge.n 0x8029944
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029942
0x8029942 2 0025 movs r5, 0
*/

}

}
while (1) 
{
/*0x8029944
0x8029944 2 3046 mov r0, r6
0x8029946 4 fef799fb bl 0x802807c ; int func_0x802807c ( int r0 )
0x802994a 2 8008 lsrs r0, r0, 2
0x802994c 4 b0f5806f cmp.w r0, 1024
0x8029950 2 01db blt.n 0x8029956
*/
cond0 = r0 >= 1024;
if ( cond0 ) 
{
/*0x8029952
0x8029952 4 40f2ff30 movw r0, 1023
*/

}
while (1) 
{
/*0x8029956
0x8029956 2 4c49 mov r1, 0x8045024
0x8029958 4 01eb8000 add.w r0, r1, r0, lsl 2
0x802995c 2 1f99 ldr r1, [sp, 124]
0x802995e 4 d0ed000a vldr s1, [r0]
0x8029962 2 0198 ldr r0, [sp, 4]
0x8029964 4 00ee100a vmov s0, r0
0x8029968 2 4848 mov r0, 0x8042524
0x802996a 4 b8ee400a vcvt.f32.u32 s0, s0
0x802996e 4 00eb8500 add.w r0, r0, r5, lsl 2
0x8029972 4 20ee800a vmul.f32 s0, s1, s0
0x8029976 4 d0ed000a vldr s1, [r0]
0x802997a 4 20ee200a vmul.f32 s0, s0, s1
0x802997e 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029982 4 10ee100a vmov r0, s0
0x8029986 4 a1f84400 strh.w r0, [r1, 68]
0x802998a 4 07eb4407 add.w r7, r7, r4, lsl 1
0x802998e 2 1e99 ldr r1, [sp, 120]
0x8029990 4 b7f9ea00 ldrsh.w r0, [r7, 234]
0x8029994 4 01eb4405 add.w r5, r1, r4, lsl 1
0x8029998 4 00ee100a vmov s0, r0
0x802999c 2 2798 ldr r0, [sp, 156]
0x802999e 4 b8eec00a vcvt.f32.s32 s0, s0
0x80299a2 4 d0ed000a vldr s1, [r0]
0x80299a6 4 20ee200a vmul.f32 s0, s0, s1
0x80299aa 4 bdeec00a vcvt.s32.f32 s0, s0
0x80299ae 4 10ee100a vmov r0, s0
0x80299b2 4 a5f87400 strh.w r0, [r5, 116]
0x80299b6 4 98f80500 ldrb.w r0, [r8, 5]
0x80299ba 4 fef735fe bl 0x8028628 ; int func_0x8028628 ( int r0, int r1 )
0x80299be 4 b5f85410 ldrh.w r1, [r5, 84]
0x80299c2 4 b7f8e020 ldrh.w r2, [r7, 224]
0x80299c6 4 b5f87430 ldrh.w r3, [r5, 116]
0x80299ca 2 0a44 add r2, r1
0x80299cc 2 1f99 ldr r1, [sp, 124]
0x80299ce 4 b1f84410 ldrh.w r1, [r1, 68]
0x80299d2 2 1944 add r1, r3
0x80299d4 2 1144 add r1, r2
0x80299d6 2 0844 add r0, r1
0x80299d8 2 00b2 sxth r0, r0
0x80299da 4 2af81400 strh.w r0, [sl, r4, lsl 1]
0x80299de 4 b0f5805f cmp.w r0, 4096
0x80299e2 2 03db blt.n 0x80299ec
*/
cond0 = r0 >= 4096;
if ( cond0 ) 
{
/*0x80299e4
0x80299e4 4 40f6ff70 movw r0, 4095
0x80299e8 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299ec
0x80299ec 4 3af91400 ldrsh.w r0, [sl, r4, lsl 1]
0x80299f0 2 0028 cmp r0, 0
0x80299f2 2 02da bge.n 0x80299fa
*/
cond0 = r0 < 0;
if ( cond0 ) 
{
/*0x80299f4
0x80299f4 2 0020 movs r0, 0
0x80299f6 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299fa
0x80299fa 2 2298 ldr r0, [sp, 136]
0x80299fc 4 3af81410 ldrh.w r1, [sl, r4, lsl 1]
0x8029a00 4 20f81410 strh.w r1, [r0, r4, lsl 1]
0x8029a04 4 fef78af9 bl 0x8027d1c ; int func_0x8027d1c ( int r0, int r1 )
0x8029a08 2 0128 cmp r0, 1
0x8029a0a 2 11d0 beq.n 0x8029a30
*/
cond0 = r0 != 1;
if ( cond0 ) 
{
/*0x8029a0c
0x8029a0c 2 2198 ldr r0, [sp, 132]
0x8029a0e 2 0022 movs r2, 0
0x8029a10 4 04eb4000 add.w r0, r4, r0, lsl 1
0x8029a14 2 c1b2 uxtb r1, r0
0x8029a16 2 2098 ldr r0, [sp, 128]
0x8029a18 4 00f0fefa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
*/

}
else
{
while (1) 
{
/*0x8029a30
0x8029a30 2 1cb9 cbnz r4, 0x8029a3a
*/
cond1 = r4 == 0;
/*0x8029a32
0x8029a32 4 98f81000 ldrb.w r0, [r8, 16]
0x8029a36 2 0428 cmp r0, 4
0x8029a38 2 02d0 beq.n 0x8029a40
*/
cond0 = r0 != 4;
if ( cond1 && ~(cond0) ) 
{
/*0x8029a40
0x8029a40 2 2498 ldr r0, [sp, 144]
0x8029a42 2 0022 movs r2, 0
0x8029a44 2 c1b2 uxtb r1, r0
0x8029a46 2 2098 ldr r0, [sp, 128]
0x8029a48 4 00f0e6fa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
0x8029a4c 2 e6e7 b.n 0x8029a1c
*/

}
else
{
while (1) 
{
/*0x8029a3a
0x8029a3a 2 012c cmp r4, 1
0x8029a3c 2 07d0 beq.n 0x8029a4e
*/
cond0 = r4 != 1;
if ( cond0 ) 
{
/*0x8029a3e
0x8029a3e 2 0ae0 b.n 0x8029a56
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
while (1) 
{
/*0x80298e2
0x80298e2 4 98f80500 ldrb.w r0, [r8, 5]
0x80298e6 4 fef78bfe bl 0x8028600 ; int func_0x8028600 ( int r0, int r1 )
0x80298ea 4 b7f86e10 ldrh.w r1, [r7, 110]
0x80298ee 4 b7f8ae20 ldrh.w r2, [r7, 174]
0x80298f2 2 1144 add r1, r2
0x80298f4 4 b9f84e20 ldrh.w r2, [r9, 78]
0x80298f8 2 2a44 add r2, r5
0x80298fa 2 1144 add r1, r2
0x80298fc 2 5944 add r1, fp
0x80298fe 2 0844 add r0, r1
0x8029900 2 1d99 ldr r1, [sp, 116]
0x8029902 4 01eb8401 add.w r1, r1, r4, lsl 2
0x8029906 2 4880 strh r0, [r1, 2]
0x8029908 2 2599 ldr r1, [sp, 148]
0x802990a 4 01eb8401 add.w r1, r1, r4, lsl 2
0x802990e 2 4880 strh r0, [r1, 2]
0x8029910 2 5c4f mov r7, 0x20005088
0x8029912 4 b7f9e450 ldrsh.w r5, [r7, 228]
0x8029916 4 f9f79ff9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802991a 2 0428 cmp r0, 4
0x802991c 2 09d1 bne.n 0x8029932
*/
cond1 = r0 == 4;
/*0x802991e
0x802991e 4 02f049f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029922 2 0228 cmp r0, 2
0x8029924 2 05d1 bne.n 0x8029932
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
/*0x8029926
0x8029926 2 3046 mov r0, r6
0x8029928 4 f9f79cf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802992c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029930 2 05b2 sxth r5, r0
*/

}
while (1) 
{
/*0x8029932
0x8029932 4 b5f5007f cmp.w r5, 512
0x8029936 2 02db blt.n 0x802993e
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029938
0x8029938 4 40f2ff15 movw r5, 511
0x802993c 2 02e0 b.n 0x8029944
*/

}
else
{
/*0x802993e
0x802993e 2 002d cmp r5, 0
0x8029940 2 00da bge.n 0x8029944
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029942
0x8029942 2 0025 movs r5, 0
*/

}

}
while (1) 
{
/*0x8029944
0x8029944 2 3046 mov r0, r6
0x8029946 4 fef799fb bl 0x802807c ; int func_0x802807c ( int r0 )
0x802994a 2 8008 lsrs r0, r0, 2
0x802994c 4 b0f5806f cmp.w r0, 1024
0x8029950 2 01db blt.n 0x8029956
*/
cond0 = r0 >= 1024;
if ( cond0 ) 
{
/*0x8029952
0x8029952 4 40f2ff30 movw r0, 1023
*/

}
while (1) 
{
/*0x8029956
0x8029956 2 4c49 mov r1, 0x8045024
0x8029958 4 01eb8000 add.w r0, r1, r0, lsl 2
0x802995c 2 1f99 ldr r1, [sp, 124]
0x802995e 4 d0ed000a vldr s1, [r0]
0x8029962 2 0198 ldr r0, [sp, 4]
0x8029964 4 00ee100a vmov s0, r0
0x8029968 2 4848 mov r0, 0x8042524
0x802996a 4 b8ee400a vcvt.f32.u32 s0, s0
0x802996e 4 00eb8500 add.w r0, r0, r5, lsl 2
0x8029972 4 20ee800a vmul.f32 s0, s1, s0
0x8029976 4 d0ed000a vldr s1, [r0]
0x802997a 4 20ee200a vmul.f32 s0, s0, s1
0x802997e 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029982 4 10ee100a vmov r0, s0
0x8029986 4 a1f84400 strh.w r0, [r1, 68]
0x802998a 4 07eb4407 add.w r7, r7, r4, lsl 1
0x802998e 2 1e99 ldr r1, [sp, 120]
0x8029990 4 b7f9ea00 ldrsh.w r0, [r7, 234]
0x8029994 4 01eb4405 add.w r5, r1, r4, lsl 1
0x8029998 4 00ee100a vmov s0, r0
0x802999c 2 2798 ldr r0, [sp, 156]
0x802999e 4 b8eec00a vcvt.f32.s32 s0, s0
0x80299a2 4 d0ed000a vldr s1, [r0]
0x80299a6 4 20ee200a vmul.f32 s0, s0, s1
0x80299aa 4 bdeec00a vcvt.s32.f32 s0, s0
0x80299ae 4 10ee100a vmov r0, s0
0x80299b2 4 a5f87400 strh.w r0, [r5, 116]
0x80299b6 4 98f80500 ldrb.w r0, [r8, 5]
0x80299ba 4 fef735fe bl 0x8028628 ; int func_0x8028628 ( int r0, int r1 )
0x80299be 4 b5f85410 ldrh.w r1, [r5, 84]
0x80299c2 4 b7f8e020 ldrh.w r2, [r7, 224]
0x80299c6 4 b5f87430 ldrh.w r3, [r5, 116]
0x80299ca 2 0a44 add r2, r1
0x80299cc 2 1f99 ldr r1, [sp, 124]
0x80299ce 4 b1f84410 ldrh.w r1, [r1, 68]
0x80299d2 2 1944 add r1, r3
0x80299d4 2 1144 add r1, r2
0x80299d6 2 0844 add r0, r1
0x80299d8 2 00b2 sxth r0, r0
0x80299da 4 2af81400 strh.w r0, [sl, r4, lsl 1]
0x80299de 4 b0f5805f cmp.w r0, 4096
0x80299e2 2 03db blt.n 0x80299ec
*/
cond0 = r0 >= 4096;
if ( cond0 ) 
{
/*0x80299e4
0x80299e4 4 40f6ff70 movw r0, 4095
0x80299e8 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299ec
0x80299ec 4 3af91400 ldrsh.w r0, [sl, r4, lsl 1]
0x80299f0 2 0028 cmp r0, 0
0x80299f2 2 02da bge.n 0x80299fa
*/
cond0 = r0 < 0;
if ( cond0 ) 
{
/*0x80299f4
0x80299f4 2 0020 movs r0, 0
0x80299f6 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299fa
0x80299fa 2 2298 ldr r0, [sp, 136]
0x80299fc 4 3af81410 ldrh.w r1, [sl, r4, lsl 1]
0x8029a00 4 20f81410 strh.w r1, [r0, r4, lsl 1]
0x8029a04 4 fef78af9 bl 0x8027d1c ; int func_0x8027d1c ( int r0, int r1 )
0x8029a08 2 0128 cmp r0, 1
0x8029a0a 2 11d0 beq.n 0x8029a30
*/
cond0 = r0 != 1;
if ( cond0 ) 
{
/*0x8029a0c
0x8029a0c 2 2198 ldr r0, [sp, 132]
0x8029a0e 2 0022 movs r2, 0
0x8029a10 4 04eb4000 add.w r0, r4, r0, lsl 1
0x8029a14 2 c1b2 uxtb r1, r0
0x8029a16 2 2098 ldr r0, [sp, 128]
0x8029a18 4 00f0fefa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
else
{
while (1) 
{
/*0x8029826
0x8029826 4 f9f717fa bl 0x8022c58 ; int func_0x8022c58 ()
0x802982a 2 0728 cmp r0, 7
0x802982c 2 0fd0 beq.n 0x802984e
*/
cond0 = r0 != 7;
if ( cond0 ) 
{
/*0x802982e
0x802982e 2 22e0 b.n 0x8029876
*/

}
else
{
/*0x802984e
0x802984e 2 012c cmp r4, 1
0x8029850 2 11d1 bne.n 0x8029876
*/
cond1 = r4 == 1;
/*0x8029852
0x8029852 4 02f0aff8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029856 2 0228 cmp r0, 2
0x8029858 2 0dd1 bne.n 0x8029876
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
while (1) 
{
/*0x8029876
0x8029876 4 bbf94ab0 ldrsh.w fp, [fp, 74]
0x802987a 4 f9f7edf9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802987e 2 0528 cmp r0, 5
0x8029880 2 2fd1 bne.n 0x80298e2
*/
cond1 = r0 == 5;
/*0x8029882
0x8029882 4 02f097f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029886 2 0228 cmp r0, 2
0x8029888 2 2bd1 bne.n 0x80298e2
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80298e2
0x80298e2 4 98f80500 ldrb.w r0, [r8, 5]
0x80298e6 4 fef78bfe bl 0x8028600 ; int func_0x8028600 ( int r0, int r1 )
0x80298ea 4 b7f86e10 ldrh.w r1, [r7, 110]
0x80298ee 4 b7f8ae20 ldrh.w r2, [r7, 174]
0x80298f2 2 1144 add r1, r2
0x80298f4 4 b9f84e20 ldrh.w r2, [r9, 78]
0x80298f8 2 2a44 add r2, r5
0x80298fa 2 1144 add r1, r2
0x80298fc 2 5944 add r1, fp
0x80298fe 2 0844 add r0, r1
0x8029900 2 1d99 ldr r1, [sp, 116]
0x8029902 4 01eb8401 add.w r1, r1, r4, lsl 2
0x8029906 2 4880 strh r0, [r1, 2]
0x8029908 2 2599 ldr r1, [sp, 148]
0x802990a 4 01eb8401 add.w r1, r1, r4, lsl 2
0x802990e 2 4880 strh r0, [r1, 2]
0x8029910 2 5c4f mov r7, 0x20005088
0x8029912 4 b7f9e450 ldrsh.w r5, [r7, 228]
0x8029916 4 f9f79ff9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802991a 2 0428 cmp r0, 4
0x802991c 2 09d1 bne.n 0x8029932
*/
cond1 = r0 == 4;
/*0x802991e
0x802991e 4 02f049f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029922 2 0228 cmp r0, 2
0x8029924 2 05d1 bne.n 0x8029932
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
/*0x8029926
0x8029926 2 3046 mov r0, r6
0x8029928 4 f9f79cf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802992c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029930 2 05b2 sxth r5, r0
*/

}
while (1) 
{
/*0x8029932
0x8029932 4 b5f5007f cmp.w r5, 512
0x8029936 2 02db blt.n 0x802993e
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029938
0x8029938 4 40f2ff15 movw r5, 511
0x802993c 2 02e0 b.n 0x8029944
*/

}
else
{
/*0x802993e
0x802993e 2 002d cmp r5, 0
0x8029940 2 00da bge.n 0x8029944
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029942
0x8029942 2 0025 movs r5, 0
*/

}

}
while (1) 
{
/*0x8029944
0x8029944 2 3046 mov r0, r6
0x8029946 4 fef799fb bl 0x802807c ; int func_0x802807c ( int r0 )
0x802994a 2 8008 lsrs r0, r0, 2
0x802994c 4 b0f5806f cmp.w r0, 1024
0x8029950 2 01db blt.n 0x8029956
*/
cond0 = r0 >= 1024;
if ( cond0 ) 
{
/*0x8029952
0x8029952 4 40f2ff30 movw r0, 1023
*/

}
while (1) 
{
/*0x8029956
0x8029956 2 4c49 mov r1, 0x8045024
0x8029958 4 01eb8000 add.w r0, r1, r0, lsl 2
0x802995c 2 1f99 ldr r1, [sp, 124]
0x802995e 4 d0ed000a vldr s1, [r0]
0x8029962 2 0198 ldr r0, [sp, 4]
0x8029964 4 00ee100a vmov s0, r0
0x8029968 2 4848 mov r0, 0x8042524
0x802996a 4 b8ee400a vcvt.f32.u32 s0, s0
0x802996e 4 00eb8500 add.w r0, r0, r5, lsl 2
0x8029972 4 20ee800a vmul.f32 s0, s1, s0
0x8029976 4 d0ed000a vldr s1, [r0]
0x802997a 4 20ee200a vmul.f32 s0, s0, s1
0x802997e 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029982 4 10ee100a vmov r0, s0
0x8029986 4 a1f84400 strh.w r0, [r1, 68]
0x802998a 4 07eb4407 add.w r7, r7, r4, lsl 1
0x802998e 2 1e99 ldr r1, [sp, 120]
0x8029990 4 b7f9ea00 ldrsh.w r0, [r7, 234]
0x8029994 4 01eb4405 add.w r5, r1, r4, lsl 1
0x8029998 4 00ee100a vmov s0, r0
0x802999c 2 2798 ldr r0, [sp, 156]
0x802999e 4 b8eec00a vcvt.f32.s32 s0, s0
0x80299a2 4 d0ed000a vldr s1, [r0]
0x80299a6 4 20ee200a vmul.f32 s0, s0, s1
0x80299aa 4 bdeec00a vcvt.s32.f32 s0, s0
0x80299ae 4 10ee100a vmov r0, s0
0x80299b2 4 a5f87400 strh.w r0, [r5, 116]
0x80299b6 4 98f80500 ldrb.w r0, [r8, 5]
0x80299ba 4 fef735fe bl 0x8028628 ; int func_0x8028628 ( int r0, int r1 )
0x80299be 4 b5f85410 ldrh.w r1, [r5, 84]
0x80299c2 4 b7f8e020 ldrh.w r2, [r7, 224]
0x80299c6 4 b5f87430 ldrh.w r3, [r5, 116]
0x80299ca 2 0a44 add r2, r1
0x80299cc 2 1f99 ldr r1, [sp, 124]
0x80299ce 4 b1f84410 ldrh.w r1, [r1, 68]
0x80299d2 2 1944 add r1, r3
0x80299d4 2 1144 add r1, r2
0x80299d6 2 0844 add r0, r1
0x80299d8 2 00b2 sxth r0, r0
0x80299da 4 2af81400 strh.w r0, [sl, r4, lsl 1]
0x80299de 4 b0f5805f cmp.w r0, 4096
0x80299e2 2 03db blt.n 0x80299ec
*/
cond0 = r0 >= 4096;
if ( cond0 ) 
{
/*0x80299e4
0x80299e4 4 40f6ff70 movw r0, 4095
0x80299e8 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299ec
0x80299ec 4 3af91400 ldrsh.w r0, [sl, r4, lsl 1]
0x80299f0 2 0028 cmp r0, 0
0x80299f2 2 02da bge.n 0x80299fa
*/
cond0 = r0 < 0;
if ( cond0 ) 
{
/*0x80299f4
0x80299f4 2 0020 movs r0, 0
0x80299f6 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299fa
0x80299fa 2 2298 ldr r0, [sp, 136]
0x80299fc 4 3af81410 ldrh.w r1, [sl, r4, lsl 1]
0x8029a00 4 20f81410 strh.w r1, [r0, r4, lsl 1]
0x8029a04 4 fef78af9 bl 0x8027d1c ; int func_0x8027d1c ( int r0, int r1 )
0x8029a08 2 0128 cmp r0, 1
0x8029a0a 2 11d0 beq.n 0x8029a30
*/
cond0 = r0 != 1;
if ( cond0 ) 
{
/*0x8029a0c
0x8029a0c 2 2198 ldr r0, [sp, 132]
0x8029a0e 2 0022 movs r2, 0
0x8029a10 4 04eb4000 add.w r0, r4, r0, lsl 1
0x8029a14 2 c1b2 uxtb r1, r0
0x8029a16 2 2098 ldr r0, [sp, 128]
0x8029a18 4 00f0fefa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}

}
while (1) 
{
/*0x8029792
0x8029792 2 3046 mov r0, r6
0x8029794 4 fef772fc bl 0x802807c ; int func_0x802807c ( int r0 )
0x8029798 4 20f00301 bic.w r1, r0, 3
0x802979c 2 4b48 mov r0, 0x8044024
0x802979e 4 dff814b1 mov fp, 0x20005274
0x80297a2 2 0844 add r0, r1
0x80297a4 4 d0ed000a vldr s1, [r0]
0x80297a8 2 0198 ldr r0, [sp, 4]
0x80297aa 4 00ee100a vmov s0, r0
0x80297ae 2 4548 mov r0, 0x8042524
0x80297b0 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297b4 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80297b8 4 20ee800a vmul.f32 s0, s1, s0
0x80297bc 4 d1ed000a vldr s1, [r1]
0x80297c0 2 2699 ldr r1, [sp, 152]
0x80297c2 4 b1f94c10 ldrsh.w r1, [r1, 76]
0x80297c6 4 00eb8100 add.w r0, r0, r1, lsl 2
0x80297ca 4 90ed001a vldr s2, [r0]
0x80297ce 4 70ee810a vadd.f32 s1, s1, s2
0x80297d2 4 20ee200a vmul.f32 s0, s0, s1
0x80297d6 4 bdeec00a vcvt.s32.f32 s0, s0
0x80297da 4 10ee100a vmov r0, s0
0x80297de 4 a9f84e00 strh.w r0, [r9, 78]
0x80297e2 2 1b98 ldr r0, [sp, 108]
0x80297e4 4 b0f96000 ldrsh.w r0, [r0, 96]
0x80297e8 2 c110 asrs r1, r0, 3
0x80297ea 2 3948 mov r0, 0x804dc24
0x80297ec 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x80297f0 4 00ee100a vmov s0, r0
0x80297f4 2 2798 ldr r0, [sp, 156]
0x80297f6 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297fa 4 d0ed000a vldr s1, [r0]
0x80297fe 4 20ee200a vmul.f32 s0, s0, s1
0x8029802 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029806 4 10ee100a vmov r0, s0
0x802980a 4 a7f8ae00 strh.w r0, [r7, 174]
0x802980e 2 1a98 ldr r0, [sp, 104]
0x8029810 4 b0f94250 ldrsh.w r5, [r0, 66]
0x8029814 4 f9f720fa bl 0x8022c58 ; int func_0x8022c58 ()
0x8029818 2 0628 cmp r0, 6
0x802981a 2 04d1 bne.n 0x8029826
*/
cond2 = r0 == 6;
/*0x802981c
0x802981c 2 1cb9 cbnz r4, 0x8029826
*/
cond1 = r4 == 0;
/*0x802981e
0x802981e 4 02f0c9f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029822 2 0228 cmp r0, 2
0x8029824 2 04d0 beq.n 0x8029830
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x8029876
0x8029876 4 bbf94ab0 ldrsh.w fp, [fp, 74]
0x802987a 4 f9f7edf9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802987e 2 0528 cmp r0, 5
0x8029880 2 2fd1 bne.n 0x80298e2
*/
cond1 = r0 == 5;
/*0x8029882
0x8029882 4 02f097f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029886 2 0228 cmp r0, 2
0x8029888 2 2bd1 bne.n 0x80298e2
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80298e2
0x80298e2 4 98f80500 ldrb.w r0, [r8, 5]
0x80298e6 4 fef78bfe bl 0x8028600 ; int func_0x8028600 ( int r0, int r1 )
0x80298ea 4 b7f86e10 ldrh.w r1, [r7, 110]
0x80298ee 4 b7f8ae20 ldrh.w r2, [r7, 174]
0x80298f2 2 1144 add r1, r2
0x80298f4 4 b9f84e20 ldrh.w r2, [r9, 78]
0x80298f8 2 2a44 add r2, r5
0x80298fa 2 1144 add r1, r2
0x80298fc 2 5944 add r1, fp
0x80298fe 2 0844 add r0, r1
0x8029900 2 1d99 ldr r1, [sp, 116]
0x8029902 4 01eb8401 add.w r1, r1, r4, lsl 2
0x8029906 2 4880 strh r0, [r1, 2]
0x8029908 2 2599 ldr r1, [sp, 148]
0x802990a 4 01eb8401 add.w r1, r1, r4, lsl 2
0x802990e 2 4880 strh r0, [r1, 2]
0x8029910 2 5c4f mov r7, 0x20005088
0x8029912 4 b7f9e450 ldrsh.w r5, [r7, 228]
0x8029916 4 f9f79ff9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802991a 2 0428 cmp r0, 4
0x802991c 2 09d1 bne.n 0x8029932
*/
cond1 = r0 == 4;
/*0x802991e
0x802991e 4 02f049f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029922 2 0228 cmp r0, 2
0x8029924 2 05d1 bne.n 0x8029932
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
/*0x8029926
0x8029926 2 3046 mov r0, r6
0x8029928 4 f9f79cf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802992c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029930 2 05b2 sxth r5, r0
*/

}
while (1) 
{
/*0x8029932
0x8029932 4 b5f5007f cmp.w r5, 512
0x8029936 2 02db blt.n 0x802993e
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029938
0x8029938 4 40f2ff15 movw r5, 511
0x802993c 2 02e0 b.n 0x8029944
*/

}
else
{
/*0x802993e
0x802993e 2 002d cmp r5, 0
0x8029940 2 00da bge.n 0x8029944
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029942
0x8029942 2 0025 movs r5, 0
*/

}

}
while (1) 
{
/*0x8029944
0x8029944 2 3046 mov r0, r6
0x8029946 4 fef799fb bl 0x802807c ; int func_0x802807c ( int r0 )
0x802994a 2 8008 lsrs r0, r0, 2
0x802994c 4 b0f5806f cmp.w r0, 1024
0x8029950 2 01db blt.n 0x8029956
*/
cond0 = r0 >= 1024;
if ( cond0 ) 
{
/*0x8029952
0x8029952 4 40f2ff30 movw r0, 1023
*/

}
while (1) 
{
/*0x8029956
0x8029956 2 4c49 mov r1, 0x8045024
0x8029958 4 01eb8000 add.w r0, r1, r0, lsl 2
0x802995c 2 1f99 ldr r1, [sp, 124]
0x802995e 4 d0ed000a vldr s1, [r0]
0x8029962 2 0198 ldr r0, [sp, 4]
0x8029964 4 00ee100a vmov s0, r0
0x8029968 2 4848 mov r0, 0x8042524
0x802996a 4 b8ee400a vcvt.f32.u32 s0, s0
0x802996e 4 00eb8500 add.w r0, r0, r5, lsl 2
0x8029972 4 20ee800a vmul.f32 s0, s1, s0
0x8029976 4 d0ed000a vldr s1, [r0]
0x802997a 4 20ee200a vmul.f32 s0, s0, s1
0x802997e 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029982 4 10ee100a vmov r0, s0
0x8029986 4 a1f84400 strh.w r0, [r1, 68]
0x802998a 4 07eb4407 add.w r7, r7, r4, lsl 1
0x802998e 2 1e99 ldr r1, [sp, 120]
0x8029990 4 b7f9ea00 ldrsh.w r0, [r7, 234]
0x8029994 4 01eb4405 add.w r5, r1, r4, lsl 1
0x8029998 4 00ee100a vmov s0, r0
0x802999c 2 2798 ldr r0, [sp, 156]
0x802999e 4 b8eec00a vcvt.f32.s32 s0, s0
0x80299a2 4 d0ed000a vldr s1, [r0]
0x80299a6 4 20ee200a vmul.f32 s0, s0, s1
0x80299aa 4 bdeec00a vcvt.s32.f32 s0, s0
0x80299ae 4 10ee100a vmov r0, s0
0x80299b2 4 a5f87400 strh.w r0, [r5, 116]
0x80299b6 4 98f80500 ldrb.w r0, [r8, 5]
0x80299ba 4 fef735fe bl 0x8028628 ; int func_0x8028628 ( int r0, int r1 )
0x80299be 4 b5f85410 ldrh.w r1, [r5, 84]
0x80299c2 4 b7f8e020 ldrh.w r2, [r7, 224]
0x80299c6 4 b5f87430 ldrh.w r3, [r5, 116]
0x80299ca 2 0a44 add r2, r1
0x80299cc 2 1f99 ldr r1, [sp, 124]
0x80299ce 4 b1f84410 ldrh.w r1, [r1, 68]
0x80299d2 2 1944 add r1, r3
0x80299d4 2 1144 add r1, r2
0x80299d6 2 0844 add r0, r1
0x80299d8 2 00b2 sxth r0, r0
0x80299da 4 2af81400 strh.w r0, [sl, r4, lsl 1]
0x80299de 4 b0f5805f cmp.w r0, 4096
0x80299e2 2 03db blt.n 0x80299ec
*/
cond0 = r0 >= 4096;
if ( cond0 ) 
{
/*0x80299e4
0x80299e4 4 40f6ff70 movw r0, 4095
0x80299e8 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299ec
0x80299ec 4 3af91400 ldrsh.w r0, [sl, r4, lsl 1]
0x80299f0 2 0028 cmp r0, 0
0x80299f2 2 02da bge.n 0x80299fa
*/
cond0 = r0 < 0;
if ( cond0 ) 
{
/*0x80299f4
0x80299f4 2 0020 movs r0, 0
0x80299f6 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299fa
0x80299fa 2 2298 ldr r0, [sp, 136]
0x80299fc 4 3af81410 ldrh.w r1, [sl, r4, lsl 1]
0x8029a00 4 20f81410 strh.w r1, [r0, r4, lsl 1]
0x8029a04 4 fef78af9 bl 0x8027d1c ; int func_0x8027d1c ( int r0, int r1 )
0x8029a08 2 0128 cmp r0, 1
0x8029a0a 2 11d0 beq.n 0x8029a30
*/
cond0 = r0 != 1;
if ( cond0 ) 
{
/*0x8029a0c
0x8029a0c 2 2198 ldr r0, [sp, 132]
0x8029a0e 2 0022 movs r2, 0
0x8029a10 4 04eb4000 add.w r0, r4, r0, lsl 1
0x8029a14 2 c1b2 uxtb r1, r0
0x8029a16 2 2098 ldr r0, [sp, 128]
0x8029a18 4 00f0fefa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
while (1) 
{
/*0x80296f0
0x80296f0 4 fef77afd bl 0x80281e8 ; int func_0x80281e8 ()
0x80296f4 2 20b3 cbz r0, 0x8029740
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x80296f6
0x80296f6 4 98f80500 ldrb.w r0, [r8, 5]
0x80296fa 4 fef773ff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x80296fe 4 b7f86c10 ldrh.w r1, [r7, 108]
0x8029702 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029706 2 1144 add r1, r2
0x8029708 4 b9f84c20 ldrh.w r2, [r9, 76]
0x802970c 2 2a44 add r2, r5
0x802970e 2 1144 add r1, r2
0x8029710 2 5944 add r1, fp
0x8029712 2 0844 add r0, r1
0x8029714 2 1d99 ldr r1, [sp, 116]
0x8029716 4 21f82400 strh.w r0, [r1, r4, lsl 2]
*/

}
else
{
/*0x8029740
0x8029740 4 98f80500 ldrb.w r0, [r8, 5]
0x8029744 4 fef74eff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x8029748 4 b7f86c10 ldrh.w r1, [r7, 108]
0x802974c 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029750 2 691a subs r1, r5, r1
0x8029752 2 891a subs r1, r1, r2
0x8029754 4 b9f84c20 ldrh.w r2, [r9, 76]
0x8029758 2 891a subs r1, r1, r2
0x802975a 4 a1eb0b01 sub.w r1, r1, fp
0x802975e 2 081a subs r0, r1, r0
0x8029760 2 1d99 ldr r1, [sp, 116]
0x8029762 4 21f82400 strh.w r0, [r1, r4, lsl 2]
0x8029766 2 d8e7 b.n 0x802971a
*/

}
while (1) 
{
/*0x802971a
0x802971a 2 1d98 ldr r0, [sp, 116]
0x802971c 4 30f82410 ldrh.w r1, [r0, r4, lsl 2]
0x8029720 2 2598 ldr r0, [sp, 148]
0x8029722 4 20f82410 strh.w r1, [r0, r4, lsl 2]
0x8029726 4 07f037f9 bl 0x8030998 ; int func_0x8030998 ()
0x802972a 2 e8b1 cbz r0, 0x8029768
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x802972c
0x802972c 2 0820 movs r0, 8
0x802972e 2 0190 str r0, [sp, 4]
*/

}
else
{
/*0x8029768
0x8029768 2 0620 movs r0, 6
0x802976a 2 0190 str r0, [sp, 4]
0x802976c 2 e0e7 b.n 0x8029730
*/

}
while (1) 
{
/*0x8029730
0x8029730 2 5f48 mov r0, 0x2000501c
0x8029732 4 b0f94a50 ldrsh.w r5, [r0, 74]
0x8029736 4 f9f78ffa bl 0x8022c58 ; int func_0x8022c58 ()
0x802973a 2 0328 cmp r0, 3
0x802973c 2 17d0 beq.n 0x802976e
*/
cond0 = r0 != 3;
if ( cond0 ) 
{
/*0x802973e
0x802973e 2 28e0 b.n 0x8029792
*/

}
else
{
/*0x802976e
0x802976e 4 02f021f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029772 2 0228 cmp r0, 2
0x8029774 2 0dd1 bne.n 0x8029792
*/
cond0 = r0 == 2;
if ( cond0 ) 
{

}

}
while (1) 
{
/*0x8029792
0x8029792 2 3046 mov r0, r6
0x8029794 4 fef772fc bl 0x802807c ; int func_0x802807c ( int r0 )
0x8029798 4 20f00301 bic.w r1, r0, 3
0x802979c 2 4b48 mov r0, 0x8044024
0x802979e 4 dff814b1 mov fp, 0x20005274
0x80297a2 2 0844 add r0, r1
0x80297a4 4 d0ed000a vldr s1, [r0]
0x80297a8 2 0198 ldr r0, [sp, 4]
0x80297aa 4 00ee100a vmov s0, r0
0x80297ae 2 4548 mov r0, 0x8042524
0x80297b0 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297b4 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80297b8 4 20ee800a vmul.f32 s0, s1, s0
0x80297bc 4 d1ed000a vldr s1, [r1]
0x80297c0 2 2699 ldr r1, [sp, 152]
0x80297c2 4 b1f94c10 ldrsh.w r1, [r1, 76]
0x80297c6 4 00eb8100 add.w r0, r0, r1, lsl 2
0x80297ca 4 90ed001a vldr s2, [r0]
0x80297ce 4 70ee810a vadd.f32 s1, s1, s2
0x80297d2 4 20ee200a vmul.f32 s0, s0, s1
0x80297d6 4 bdeec00a vcvt.s32.f32 s0, s0
0x80297da 4 10ee100a vmov r0, s0
0x80297de 4 a9f84e00 strh.w r0, [r9, 78]
0x80297e2 2 1b98 ldr r0, [sp, 108]
0x80297e4 4 b0f96000 ldrsh.w r0, [r0, 96]
0x80297e8 2 c110 asrs r1, r0, 3
0x80297ea 2 3948 mov r0, 0x804dc24
0x80297ec 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x80297f0 4 00ee100a vmov s0, r0
0x80297f4 2 2798 ldr r0, [sp, 156]
0x80297f6 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297fa 4 d0ed000a vldr s1, [r0]
0x80297fe 4 20ee200a vmul.f32 s0, s0, s1
0x8029802 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029806 4 10ee100a vmov r0, s0
0x802980a 4 a7f8ae00 strh.w r0, [r7, 174]
0x802980e 2 1a98 ldr r0, [sp, 104]
0x8029810 4 b0f94250 ldrsh.w r5, [r0, 66]
0x8029814 4 f9f720fa bl 0x8022c58 ; int func_0x8022c58 ()
0x8029818 2 0628 cmp r0, 6
0x802981a 2 04d1 bne.n 0x8029826
*/
cond2 = r0 == 6;
/*0x802981c
0x802981c 2 1cb9 cbnz r4, 0x8029826
*/
cond1 = r4 == 0;
/*0x802981e
0x802981e 4 02f0c9f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029822 2 0228 cmp r0, 2
0x8029824 2 04d0 beq.n 0x8029830
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x8029876
0x8029876 4 bbf94ab0 ldrsh.w fp, [fp, 74]
0x802987a 4 f9f7edf9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802987e 2 0528 cmp r0, 5
0x8029880 2 2fd1 bne.n 0x80298e2
*/
cond1 = r0 == 5;
/*0x8029882
0x8029882 4 02f097f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029886 2 0228 cmp r0, 2
0x8029888 2 2bd1 bne.n 0x80298e2
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80298e2
0x80298e2 4 98f80500 ldrb.w r0, [r8, 5]
0x80298e6 4 fef78bfe bl 0x8028600 ; int func_0x8028600 ( int r0, int r1 )
0x80298ea 4 b7f86e10 ldrh.w r1, [r7, 110]
0x80298ee 4 b7f8ae20 ldrh.w r2, [r7, 174]
0x80298f2 2 1144 add r1, r2
0x80298f4 4 b9f84e20 ldrh.w r2, [r9, 78]
0x80298f8 2 2a44 add r2, r5
0x80298fa 2 1144 add r1, r2
0x80298fc 2 5944 add r1, fp
0x80298fe 2 0844 add r0, r1
0x8029900 2 1d99 ldr r1, [sp, 116]
0x8029902 4 01eb8401 add.w r1, r1, r4, lsl 2
0x8029906 2 4880 strh r0, [r1, 2]
0x8029908 2 2599 ldr r1, [sp, 148]
0x802990a 4 01eb8401 add.w r1, r1, r4, lsl 2
0x802990e 2 4880 strh r0, [r1, 2]
0x8029910 2 5c4f mov r7, 0x20005088
0x8029912 4 b7f9e450 ldrsh.w r5, [r7, 228]
0x8029916 4 f9f79ff9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802991a 2 0428 cmp r0, 4
0x802991c 2 09d1 bne.n 0x8029932
*/
cond1 = r0 == 4;
/*0x802991e
0x802991e 4 02f049f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029922 2 0228 cmp r0, 2
0x8029924 2 05d1 bne.n 0x8029932
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
/*0x8029926
0x8029926 2 3046 mov r0, r6
0x8029928 4 f9f79cf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802992c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029930 2 05b2 sxth r5, r0
*/

}
while (1) 
{
/*0x8029932
0x8029932 4 b5f5007f cmp.w r5, 512
0x8029936 2 02db blt.n 0x802993e
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029938
0x8029938 4 40f2ff15 movw r5, 511
0x802993c 2 02e0 b.n 0x8029944
*/

}
else
{
/*0x802993e
0x802993e 2 002d cmp r5, 0
0x8029940 2 00da bge.n 0x8029944
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029942
0x8029942 2 0025 movs r5, 0
*/

}

}
while (1) 
{
/*0x8029944
0x8029944 2 3046 mov r0, r6
0x8029946 4 fef799fb bl 0x802807c ; int func_0x802807c ( int r0 )
0x802994a 2 8008 lsrs r0, r0, 2
0x802994c 4 b0f5806f cmp.w r0, 1024
0x8029950 2 01db blt.n 0x8029956
*/
cond0 = r0 >= 1024;
if ( cond0 ) 
{
/*0x8029952
0x8029952 4 40f2ff30 movw r0, 1023
*/

}
while (1) 
{
/*0x8029956
0x8029956 2 4c49 mov r1, 0x8045024
0x8029958 4 01eb8000 add.w r0, r1, r0, lsl 2
0x802995c 2 1f99 ldr r1, [sp, 124]
0x802995e 4 d0ed000a vldr s1, [r0]
0x8029962 2 0198 ldr r0, [sp, 4]
0x8029964 4 00ee100a vmov s0, r0
0x8029968 2 4848 mov r0, 0x8042524
0x802996a 4 b8ee400a vcvt.f32.u32 s0, s0
0x802996e 4 00eb8500 add.w r0, r0, r5, lsl 2
0x8029972 4 20ee800a vmul.f32 s0, s1, s0
0x8029976 4 d0ed000a vldr s1, [r0]
0x802997a 4 20ee200a vmul.f32 s0, s0, s1
0x802997e 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029982 4 10ee100a vmov r0, s0
0x8029986 4 a1f84400 strh.w r0, [r1, 68]
0x802998a 4 07eb4407 add.w r7, r7, r4, lsl 1
0x802998e 2 1e99 ldr r1, [sp, 120]
0x8029990 4 b7f9ea00 ldrsh.w r0, [r7, 234]
0x8029994 4 01eb4405 add.w r5, r1, r4, lsl 1
0x8029998 4 00ee100a vmov s0, r0
0x802999c 2 2798 ldr r0, [sp, 156]
0x802999e 4 b8eec00a vcvt.f32.s32 s0, s0
0x80299a2 4 d0ed000a vldr s1, [r0]
0x80299a6 4 20ee200a vmul.f32 s0, s0, s1
0x80299aa 4 bdeec00a vcvt.s32.f32 s0, s0
0x80299ae 4 10ee100a vmov r0, s0
0x80299b2 4 a5f87400 strh.w r0, [r5, 116]
0x80299b6 4 98f80500 ldrb.w r0, [r8, 5]
0x80299ba 4 fef735fe bl 0x8028628 ; int func_0x8028628 ( int r0, int r1 )
0x80299be 4 b5f85410 ldrh.w r1, [r5, 84]
0x80299c2 4 b7f8e020 ldrh.w r2, [r7, 224]
0x80299c6 4 b5f87430 ldrh.w r3, [r5, 116]
0x80299ca 2 0a44 add r2, r1
0x80299cc 2 1f99 ldr r1, [sp, 124]
0x80299ce 4 b1f84410 ldrh.w r1, [r1, 68]
0x80299d2 2 1944 add r1, r3
0x80299d4 2 1144 add r1, r2
0x80299d6 2 0844 add r0, r1
0x80299d8 2 00b2 sxth r0, r0
0x80299da 4 2af81400 strh.w r0, [sl, r4, lsl 1]
0x80299de 4 b0f5805f cmp.w r0, 4096
0x80299e2 2 03db blt.n 0x80299ec
*/
cond0 = r0 >= 4096;
if ( cond0 ) 
{
/*0x80299e4
0x80299e4 4 40f6ff70 movw r0, 4095
0x80299e8 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299ec
0x80299ec 4 3af91400 ldrsh.w r0, [sl, r4, lsl 1]
0x80299f0 2 0028 cmp r0, 0
0x80299f2 2 02da bge.n 0x80299fa
*/
cond0 = r0 < 0;
if ( cond0 ) 
{
/*0x80299f4
0x80299f4 2 0020 movs r0, 0
0x80299f6 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299fa
0x80299fa 2 2298 ldr r0, [sp, 136]
0x80299fc 4 3af81410 ldrh.w r1, [sl, r4, lsl 1]
0x8029a00 4 20f81410 strh.w r1, [r0, r4, lsl 1]
0x8029a04 4 fef78af9 bl 0x8027d1c ; int func_0x8027d1c ( int r0, int r1 )
0x8029a08 2 0128 cmp r0, 1
0x8029a0a 2 11d0 beq.n 0x8029a30
*/
cond0 = r0 != 1;
if ( cond0 ) 
{
/*0x8029a0c
0x8029a0c 2 2198 ldr r0, [sp, 132]
0x8029a0e 2 0022 movs r2, 0
0x8029a10 4 04eb4000 add.w r0, r4, r0, lsl 1
0x8029a14 2 c1b2 uxtb r1, r0
0x8029a16 2 2098 ldr r0, [sp, 128]
0x8029a18 4 00f0fefa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
else
{
while (1) 
{
/*0x8029668
0x8029668 4 f9f7f6fa bl 0x8022c58 ; int func_0x8022c58 ()
0x802966c 2 0928 cmp r0, 9
0x802966e 2 0fd0 beq.n 0x8029690
*/
cond0 = r0 != 9;
if ( cond0 ) 
{
/*0x8029670
0x8029670 2 22e0 b.n 0x80296b8
*/

}
else
{
/*0x8029690
0x8029690 2 012c cmp r4, 1
0x8029692 2 11d1 bne.n 0x80296b8
*/
cond1 = r4 == 1;
/*0x8029694
0x8029694 4 02f08ef9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029698 2 0228 cmp r0, 2
0x802969a 2 0dd1 bne.n 0x80296b8
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
while (1) 
{
/*0x80296b8
0x80296b8 2 7e48 mov r0, 0x20005274
0x80296ba 4 b0f948b0 ldrsh.w fp, [r0, 72]
0x80296be 4 f9f7cbfa bl 0x8022c58 ; int func_0x8022c58 ()
0x80296c2 2 0528 cmp r0, 5
0x80296c4 2 14d1 bne.n 0x80296f0
*/
cond1 = r0 == 5;
/*0x80296c6
0x80296c6 4 02f075f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x80296ca 2 0228 cmp r0, 2
0x80296cc 2 10d1 bne.n 0x80296f0
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80296f0
0x80296f0 4 fef77afd bl 0x80281e8 ; int func_0x80281e8 ()
0x80296f4 2 20b3 cbz r0, 0x8029740
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x80296f6
0x80296f6 4 98f80500 ldrb.w r0, [r8, 5]
0x80296fa 4 fef773ff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x80296fe 4 b7f86c10 ldrh.w r1, [r7, 108]
0x8029702 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029706 2 1144 add r1, r2
0x8029708 4 b9f84c20 ldrh.w r2, [r9, 76]
0x802970c 2 2a44 add r2, r5
0x802970e 2 1144 add r1, r2
0x8029710 2 5944 add r1, fp
0x8029712 2 0844 add r0, r1
0x8029714 2 1d99 ldr r1, [sp, 116]
0x8029716 4 21f82400 strh.w r0, [r1, r4, lsl 2]
*/

}
else
{
/*0x8029740
0x8029740 4 98f80500 ldrb.w r0, [r8, 5]
0x8029744 4 fef74eff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x8029748 4 b7f86c10 ldrh.w r1, [r7, 108]
0x802974c 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029750 2 691a subs r1, r5, r1
0x8029752 2 891a subs r1, r1, r2
0x8029754 4 b9f84c20 ldrh.w r2, [r9, 76]
0x8029758 2 891a subs r1, r1, r2
0x802975a 4 a1eb0b01 sub.w r1, r1, fp
0x802975e 2 081a subs r0, r1, r0
0x8029760 2 1d99 ldr r1, [sp, 116]
0x8029762 4 21f82400 strh.w r0, [r1, r4, lsl 2]
0x8029766 2 d8e7 b.n 0x802971a
*/

}
while (1) 
{
/*0x802971a
0x802971a 2 1d98 ldr r0, [sp, 116]
0x802971c 4 30f82410 ldrh.w r1, [r0, r4, lsl 2]
0x8029720 2 2598 ldr r0, [sp, 148]
0x8029722 4 20f82410 strh.w r1, [r0, r4, lsl 2]
0x8029726 4 07f037f9 bl 0x8030998 ; int func_0x8030998 ()
0x802972a 2 e8b1 cbz r0, 0x8029768
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x802972c
0x802972c 2 0820 movs r0, 8
0x802972e 2 0190 str r0, [sp, 4]
*/

}
else
{
/*0x8029768
0x8029768 2 0620 movs r0, 6
0x802976a 2 0190 str r0, [sp, 4]
0x802976c 2 e0e7 b.n 0x8029730
*/

}
while (1) 
{
/*0x8029730
0x8029730 2 5f48 mov r0, 0x2000501c
0x8029732 4 b0f94a50 ldrsh.w r5, [r0, 74]
0x8029736 4 f9f78ffa bl 0x8022c58 ; int func_0x8022c58 ()
0x802973a 2 0328 cmp r0, 3
0x802973c 2 17d0 beq.n 0x802976e
*/
cond0 = r0 != 3;
if ( cond0 ) 
{
/*0x802973e
0x802973e 2 28e0 b.n 0x8029792
*/

}
else
{
/*0x802976e
0x802976e 4 02f021f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029772 2 0228 cmp r0, 2
0x8029774 2 0dd1 bne.n 0x8029792
*/
cond0 = r0 == 2;
if ( cond0 ) 
{

}

}
while (1) 
{
/*0x8029792
0x8029792 2 3046 mov r0, r6
0x8029794 4 fef772fc bl 0x802807c ; int func_0x802807c ( int r0 )
0x8029798 4 20f00301 bic.w r1, r0, 3
0x802979c 2 4b48 mov r0, 0x8044024
0x802979e 4 dff814b1 mov fp, 0x20005274
0x80297a2 2 0844 add r0, r1
0x80297a4 4 d0ed000a vldr s1, [r0]
0x80297a8 2 0198 ldr r0, [sp, 4]
0x80297aa 4 00ee100a vmov s0, r0
0x80297ae 2 4548 mov r0, 0x8042524
0x80297b0 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297b4 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80297b8 4 20ee800a vmul.f32 s0, s1, s0
0x80297bc 4 d1ed000a vldr s1, [r1]
0x80297c0 2 2699 ldr r1, [sp, 152]
0x80297c2 4 b1f94c10 ldrsh.w r1, [r1, 76]
0x80297c6 4 00eb8100 add.w r0, r0, r1, lsl 2
0x80297ca 4 90ed001a vldr s2, [r0]
0x80297ce 4 70ee810a vadd.f32 s1, s1, s2
0x80297d2 4 20ee200a vmul.f32 s0, s0, s1
0x80297d6 4 bdeec00a vcvt.s32.f32 s0, s0
0x80297da 4 10ee100a vmov r0, s0
0x80297de 4 a9f84e00 strh.w r0, [r9, 78]
0x80297e2 2 1b98 ldr r0, [sp, 108]
0x80297e4 4 b0f96000 ldrsh.w r0, [r0, 96]
0x80297e8 2 c110 asrs r1, r0, 3
0x80297ea 2 3948 mov r0, 0x804dc24
0x80297ec 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x80297f0 4 00ee100a vmov s0, r0
0x80297f4 2 2798 ldr r0, [sp, 156]
0x80297f6 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297fa 4 d0ed000a vldr s1, [r0]
0x80297fe 4 20ee200a vmul.f32 s0, s0, s1
0x8029802 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029806 4 10ee100a vmov r0, s0
0x802980a 4 a7f8ae00 strh.w r0, [r7, 174]
0x802980e 2 1a98 ldr r0, [sp, 104]
0x8029810 4 b0f94250 ldrsh.w r5, [r0, 66]
0x8029814 4 f9f720fa bl 0x8022c58 ; int func_0x8022c58 ()
0x8029818 2 0628 cmp r0, 6
0x802981a 2 04d1 bne.n 0x8029826
*/
cond2 = r0 == 6;
/*0x802981c
0x802981c 2 1cb9 cbnz r4, 0x8029826
*/
cond1 = r4 == 0;
/*0x802981e
0x802981e 4 02f0c9f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029822 2 0228 cmp r0, 2
0x8029824 2 04d0 beq.n 0x8029830
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x8029876
0x8029876 4 bbf94ab0 ldrsh.w fp, [fp, 74]
0x802987a 4 f9f7edf9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802987e 2 0528 cmp r0, 5
0x8029880 2 2fd1 bne.n 0x80298e2
*/
cond1 = r0 == 5;
/*0x8029882
0x8029882 4 02f097f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029886 2 0228 cmp r0, 2
0x8029888 2 2bd1 bne.n 0x80298e2
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80298e2
0x80298e2 4 98f80500 ldrb.w r0, [r8, 5]
0x80298e6 4 fef78bfe bl 0x8028600 ; int func_0x8028600 ( int r0, int r1 )
0x80298ea 4 b7f86e10 ldrh.w r1, [r7, 110]
0x80298ee 4 b7f8ae20 ldrh.w r2, [r7, 174]
0x80298f2 2 1144 add r1, r2
0x80298f4 4 b9f84e20 ldrh.w r2, [r9, 78]
0x80298f8 2 2a44 add r2, r5
0x80298fa 2 1144 add r1, r2
0x80298fc 2 5944 add r1, fp
0x80298fe 2 0844 add r0, r1
0x8029900 2 1d99 ldr r1, [sp, 116]
0x8029902 4 01eb8401 add.w r1, r1, r4, lsl 2
0x8029906 2 4880 strh r0, [r1, 2]
0x8029908 2 2599 ldr r1, [sp, 148]
0x802990a 4 01eb8401 add.w r1, r1, r4, lsl 2
0x802990e 2 4880 strh r0, [r1, 2]
0x8029910 2 5c4f mov r7, 0x20005088
0x8029912 4 b7f9e450 ldrsh.w r5, [r7, 228]
0x8029916 4 f9f79ff9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802991a 2 0428 cmp r0, 4
0x802991c 2 09d1 bne.n 0x8029932
*/
cond1 = r0 == 4;
/*0x802991e
0x802991e 4 02f049f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029922 2 0228 cmp r0, 2
0x8029924 2 05d1 bne.n 0x8029932
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
/*0x8029926
0x8029926 2 3046 mov r0, r6
0x8029928 4 f9f79cf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802992c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029930 2 05b2 sxth r5, r0
*/

}
while (1) 
{
/*0x8029932
0x8029932 4 b5f5007f cmp.w r5, 512
0x8029936 2 02db blt.n 0x802993e
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029938
0x8029938 4 40f2ff15 movw r5, 511
0x802993c 2 02e0 b.n 0x8029944
*/

}
else
{
/*0x802993e
0x802993e 2 002d cmp r5, 0
0x8029940 2 00da bge.n 0x8029944
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029942
0x8029942 2 0025 movs r5, 0
*/

}

}
while (1) 
{
/*0x8029944
0x8029944 2 3046 mov r0, r6
0x8029946 4 fef799fb bl 0x802807c ; int func_0x802807c ( int r0 )
0x802994a 2 8008 lsrs r0, r0, 2
0x802994c 4 b0f5806f cmp.w r0, 1024
0x8029950 2 01db blt.n 0x8029956
*/
cond0 = r0 >= 1024;
if ( cond0 ) 
{
/*0x8029952
0x8029952 4 40f2ff30 movw r0, 1023
*/

}
while (1) 
{
/*0x8029956
0x8029956 2 4c49 mov r1, 0x8045024
0x8029958 4 01eb8000 add.w r0, r1, r0, lsl 2
0x802995c 2 1f99 ldr r1, [sp, 124]
0x802995e 4 d0ed000a vldr s1, [r0]
0x8029962 2 0198 ldr r0, [sp, 4]
0x8029964 4 00ee100a vmov s0, r0
0x8029968 2 4848 mov r0, 0x8042524
0x802996a 4 b8ee400a vcvt.f32.u32 s0, s0
0x802996e 4 00eb8500 add.w r0, r0, r5, lsl 2
0x8029972 4 20ee800a vmul.f32 s0, s1, s0
0x8029976 4 d0ed000a vldr s1, [r0]
0x802997a 4 20ee200a vmul.f32 s0, s0, s1
0x802997e 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029982 4 10ee100a vmov r0, s0
0x8029986 4 a1f84400 strh.w r0, [r1, 68]
0x802998a 4 07eb4407 add.w r7, r7, r4, lsl 1
0x802998e 2 1e99 ldr r1, [sp, 120]
0x8029990 4 b7f9ea00 ldrsh.w r0, [r7, 234]
0x8029994 4 01eb4405 add.w r5, r1, r4, lsl 1
0x8029998 4 00ee100a vmov s0, r0
0x802999c 2 2798 ldr r0, [sp, 156]
0x802999e 4 b8eec00a vcvt.f32.s32 s0, s0
0x80299a2 4 d0ed000a vldr s1, [r0]
0x80299a6 4 20ee200a vmul.f32 s0, s0, s1
0x80299aa 4 bdeec00a vcvt.s32.f32 s0, s0
0x80299ae 4 10ee100a vmov r0, s0
0x80299b2 4 a5f87400 strh.w r0, [r5, 116]
0x80299b6 4 98f80500 ldrb.w r0, [r8, 5]
0x80299ba 4 fef735fe bl 0x8028628 ; int func_0x8028628 ( int r0, int r1 )
0x80299be 4 b5f85410 ldrh.w r1, [r5, 84]
0x80299c2 4 b7f8e020 ldrh.w r2, [r7, 224]
0x80299c6 4 b5f87430 ldrh.w r3, [r5, 116]
0x80299ca 2 0a44 add r2, r1
0x80299cc 2 1f99 ldr r1, [sp, 124]
0x80299ce 4 b1f84410 ldrh.w r1, [r1, 68]
0x80299d2 2 1944 add r1, r3
0x80299d4 2 1144 add r1, r2
0x80299d6 2 0844 add r0, r1
0x80299d8 2 00b2 sxth r0, r0
0x80299da 4 2af81400 strh.w r0, [sl, r4, lsl 1]
0x80299de 4 b0f5805f cmp.w r0, 4096
0x80299e2 2 03db blt.n 0x80299ec
*/
cond0 = r0 >= 4096;
if ( cond0 ) 
{
/*0x80299e4
0x80299e4 4 40f6ff70 movw r0, 4095
0x80299e8 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299ec
0x80299ec 4 3af91400 ldrsh.w r0, [sl, r4, lsl 1]
0x80299f0 2 0028 cmp r0, 0
0x80299f2 2 02da bge.n 0x80299fa
*/
cond0 = r0 < 0;
if ( cond0 ) 
{
/*0x80299f4
0x80299f4 2 0020 movs r0, 0
0x80299f6 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299fa
0x80299fa 2 2298 ldr r0, [sp, 136]
0x80299fc 4 3af81410 ldrh.w r1, [sl, r4, lsl 1]
0x8029a00 4 20f81410 strh.w r1, [r0, r4, lsl 1]
0x8029a04 4 fef78af9 bl 0x8027d1c ; int func_0x8027d1c ( int r0, int r1 )
0x8029a08 2 0128 cmp r0, 1
0x8029a0a 2 11d0 beq.n 0x8029a30
*/
cond0 = r0 != 1;
if ( cond0 ) 
{
/*0x8029a0c
0x8029a0c 2 2198 ldr r0, [sp, 132]
0x8029a0e 2 0022 movs r2, 0
0x8029a10 4 04eb4000 add.w r0, r4, r0, lsl 1
0x8029a14 2 c1b2 uxtb r1, r0
0x8029a16 2 2098 ldr r0, [sp, 128]
0x8029a18 4 00f0fefa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}

}
while (1) 
{
/*0x80295c6
0x80295c6 2 3046 mov r0, r6
0x80295c8 4 fef758fd bl 0x802807c ; int func_0x802807c ( int r0 )
0x80295cc 4 20f00301 bic.w r1, r0, 3
0x80295d0 2 bb48 mov r0, 0x8043024
0x80295d2 4 00ee107a vmov s0, r7
0x80295d6 2 0844 add r0, r1
0x80295d8 2 269a ldr r2, [sp, 152]
0x80295da 4 d0ed000a vldr s1, [r0]
0x80295de 4 b8ee400a vcvt.f32.u32 s0, s0
0x80295e2 2 b848 mov r0, 0x8042524
0x80295e4 4 b2f94c20 ldrsh.w r2, [r2, 76]
0x80295e8 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80295ec 4 00eb8200 add.w r0, r0, r2, lsl 2
0x80295f0 4 20ee800a vmul.f32 s0, s1, s0
0x80295f4 4 d1ed000a vldr s1, [r1]
0x80295f8 4 90ed001a vldr s2, [r0]
0x80295fc 2 ac49 mov r1, 0x2000501c
0x80295fe 4 70ee810a vadd.f32 s1, s1, s2
0x8029602 4 01f5167b add.w fp, r1, 600
0x8029606 4 20ee200a vmul.f32 s0, s0, s1
0x802960a 4 bdeec00a vcvt.s32.f32 s0, s0
0x802960e 4 10ee100a vmov r0, s0
0x8029612 4 a9f84c00 strh.w r0, [r9, 76]
0x8029616 4 01eb4400 add.w r0, r1, r4, lsl 1
0x802961a 2 1b90 str r0, [sp, 108]
0x802961c 4 b0f96000 ldrsh.w r0, [r0, 96]
0x8029620 2 c110 asrs r1, r0, 3
0x8029622 2 a948 mov r0, 0x804d824
0x8029624 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x8029628 2 1c99 ldr r1, [sp, 112]
0x802962a 4 00ee100a vmov s0, r0
0x802962e 2 2798 ldr r0, [sp, 156]
0x8029630 4 01eb8407 add.w r7, r1, r4, lsl 2
0x8029634 4 b8ee400a vcvt.f32.u32 s0, s0
0x8029638 4 d0ed000a vldr s1, [r0]
0x802963c 4 20ee200a vmul.f32 s0, s0, s1
0x8029640 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029644 4 10ee100a vmov r0, s0
0x8029648 4 a7f8ac00 strh.w r0, [r7, 172]
0x802964c 4 0beb8400 add.w r0, fp, r4, lsl 2
0x8029650 2 1a90 str r0, [sp, 104]
0x8029652 4 b0f94050 ldrsh.w r5, [r0, 64]
0x8029656 4 f9f7fffa bl 0x8022c58 ; int func_0x8022c58 ()
0x802965a 2 0828 cmp r0, 8
0x802965c 2 04d1 bne.n 0x8029668
*/
cond2 = r0 == 8;
/*0x802965e
0x802965e 2 1cb9 cbnz r4, 0x8029668
*/
cond1 = r4 == 0;
/*0x8029660
0x8029660 4 02f0a8f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029664 2 0228 cmp r0, 2
0x8029666 2 04d0 beq.n 0x8029672
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80296b8
0x80296b8 2 7e48 mov r0, 0x20005274
0x80296ba 4 b0f948b0 ldrsh.w fp, [r0, 72]
0x80296be 4 f9f7cbfa bl 0x8022c58 ; int func_0x8022c58 ()
0x80296c2 2 0528 cmp r0, 5
0x80296c4 2 14d1 bne.n 0x80296f0
*/
cond1 = r0 == 5;
/*0x80296c6
0x80296c6 4 02f075f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x80296ca 2 0228 cmp r0, 2
0x80296cc 2 10d1 bne.n 0x80296f0
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80296f0
0x80296f0 4 fef77afd bl 0x80281e8 ; int func_0x80281e8 ()
0x80296f4 2 20b3 cbz r0, 0x8029740
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x80296f6
0x80296f6 4 98f80500 ldrb.w r0, [r8, 5]
0x80296fa 4 fef773ff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x80296fe 4 b7f86c10 ldrh.w r1, [r7, 108]
0x8029702 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029706 2 1144 add r1, r2
0x8029708 4 b9f84c20 ldrh.w r2, [r9, 76]
0x802970c 2 2a44 add r2, r5
0x802970e 2 1144 add r1, r2
0x8029710 2 5944 add r1, fp
0x8029712 2 0844 add r0, r1
0x8029714 2 1d99 ldr r1, [sp, 116]
0x8029716 4 21f82400 strh.w r0, [r1, r4, lsl 2]
*/

}
else
{
/*0x8029740
0x8029740 4 98f80500 ldrb.w r0, [r8, 5]
0x8029744 4 fef74eff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x8029748 4 b7f86c10 ldrh.w r1, [r7, 108]
0x802974c 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029750 2 691a subs r1, r5, r1
0x8029752 2 891a subs r1, r1, r2
0x8029754 4 b9f84c20 ldrh.w r2, [r9, 76]
0x8029758 2 891a subs r1, r1, r2
0x802975a 4 a1eb0b01 sub.w r1, r1, fp
0x802975e 2 081a subs r0, r1, r0
0x8029760 2 1d99 ldr r1, [sp, 116]
0x8029762 4 21f82400 strh.w r0, [r1, r4, lsl 2]
0x8029766 2 d8e7 b.n 0x802971a
*/

}
while (1) 
{
/*0x802971a
0x802971a 2 1d98 ldr r0, [sp, 116]
0x802971c 4 30f82410 ldrh.w r1, [r0, r4, lsl 2]
0x8029720 2 2598 ldr r0, [sp, 148]
0x8029722 4 20f82410 strh.w r1, [r0, r4, lsl 2]
0x8029726 4 07f037f9 bl 0x8030998 ; int func_0x8030998 ()
0x802972a 2 e8b1 cbz r0, 0x8029768
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x802972c
0x802972c 2 0820 movs r0, 8
0x802972e 2 0190 str r0, [sp, 4]
*/

}
else
{
/*0x8029768
0x8029768 2 0620 movs r0, 6
0x802976a 2 0190 str r0, [sp, 4]
0x802976c 2 e0e7 b.n 0x8029730
*/

}
while (1) 
{
/*0x8029730
0x8029730 2 5f48 mov r0, 0x2000501c
0x8029732 4 b0f94a50 ldrsh.w r5, [r0, 74]
0x8029736 4 f9f78ffa bl 0x8022c58 ; int func_0x8022c58 ()
0x802973a 2 0328 cmp r0, 3
0x802973c 2 17d0 beq.n 0x802976e
*/
cond0 = r0 != 3;
if ( cond0 ) 
{
/*0x802973e
0x802973e 2 28e0 b.n 0x8029792
*/

}
else
{
/*0x802976e
0x802976e 4 02f021f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029772 2 0228 cmp r0, 2
0x8029774 2 0dd1 bne.n 0x8029792
*/
cond0 = r0 == 2;
if ( cond0 ) 
{

}

}
while (1) 
{
/*0x8029792
0x8029792 2 3046 mov r0, r6
0x8029794 4 fef772fc bl 0x802807c ; int func_0x802807c ( int r0 )
0x8029798 4 20f00301 bic.w r1, r0, 3
0x802979c 2 4b48 mov r0, 0x8044024
0x802979e 4 dff814b1 mov fp, 0x20005274
0x80297a2 2 0844 add r0, r1
0x80297a4 4 d0ed000a vldr s1, [r0]
0x80297a8 2 0198 ldr r0, [sp, 4]
0x80297aa 4 00ee100a vmov s0, r0
0x80297ae 2 4548 mov r0, 0x8042524
0x80297b0 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297b4 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80297b8 4 20ee800a vmul.f32 s0, s1, s0
0x80297bc 4 d1ed000a vldr s1, [r1]
0x80297c0 2 2699 ldr r1, [sp, 152]
0x80297c2 4 b1f94c10 ldrsh.w r1, [r1, 76]
0x80297c6 4 00eb8100 add.w r0, r0, r1, lsl 2
0x80297ca 4 90ed001a vldr s2, [r0]
0x80297ce 4 70ee810a vadd.f32 s1, s1, s2
0x80297d2 4 20ee200a vmul.f32 s0, s0, s1
0x80297d6 4 bdeec00a vcvt.s32.f32 s0, s0
0x80297da 4 10ee100a vmov r0, s0
0x80297de 4 a9f84e00 strh.w r0, [r9, 78]
0x80297e2 2 1b98 ldr r0, [sp, 108]
0x80297e4 4 b0f96000 ldrsh.w r0, [r0, 96]
0x80297e8 2 c110 asrs r1, r0, 3
0x80297ea 2 3948 mov r0, 0x804dc24
0x80297ec 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x80297f0 4 00ee100a vmov s0, r0
0x80297f4 2 2798 ldr r0, [sp, 156]
0x80297f6 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297fa 4 d0ed000a vldr s1, [r0]
0x80297fe 4 20ee200a vmul.f32 s0, s0, s1
0x8029802 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029806 4 10ee100a vmov r0, s0
0x802980a 4 a7f8ae00 strh.w r0, [r7, 174]
0x802980e 2 1a98 ldr r0, [sp, 104]
0x8029810 4 b0f94250 ldrsh.w r5, [r0, 66]
0x8029814 4 f9f720fa bl 0x8022c58 ; int func_0x8022c58 ()
0x8029818 2 0628 cmp r0, 6
0x802981a 2 04d1 bne.n 0x8029826
*/
cond2 = r0 == 6;
/*0x802981c
0x802981c 2 1cb9 cbnz r4, 0x8029826
*/
cond1 = r4 == 0;
/*0x802981e
0x802981e 4 02f0c9f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029822 2 0228 cmp r0, 2
0x8029824 2 04d0 beq.n 0x8029830
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x8029876
0x8029876 4 bbf94ab0 ldrsh.w fp, [fp, 74]
0x802987a 4 f9f7edf9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802987e 2 0528 cmp r0, 5
0x8029880 2 2fd1 bne.n 0x80298e2
*/
cond1 = r0 == 5;
/*0x8029882
0x8029882 4 02f097f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029886 2 0228 cmp r0, 2
0x8029888 2 2bd1 bne.n 0x80298e2
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80298e2
0x80298e2 4 98f80500 ldrb.w r0, [r8, 5]
0x80298e6 4 fef78bfe bl 0x8028600 ; int func_0x8028600 ( int r0, int r1 )
0x80298ea 4 b7f86e10 ldrh.w r1, [r7, 110]
0x80298ee 4 b7f8ae20 ldrh.w r2, [r7, 174]
0x80298f2 2 1144 add r1, r2
0x80298f4 4 b9f84e20 ldrh.w r2, [r9, 78]
0x80298f8 2 2a44 add r2, r5
0x80298fa 2 1144 add r1, r2
0x80298fc 2 5944 add r1, fp
0x80298fe 2 0844 add r0, r1
0x8029900 2 1d99 ldr r1, [sp, 116]
0x8029902 4 01eb8401 add.w r1, r1, r4, lsl 2
0x8029906 2 4880 strh r0, [r1, 2]
0x8029908 2 2599 ldr r1, [sp, 148]
0x802990a 4 01eb8401 add.w r1, r1, r4, lsl 2
0x802990e 2 4880 strh r0, [r1, 2]
0x8029910 2 5c4f mov r7, 0x20005088
0x8029912 4 b7f9e450 ldrsh.w r5, [r7, 228]
0x8029916 4 f9f79ff9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802991a 2 0428 cmp r0, 4
0x802991c 2 09d1 bne.n 0x8029932
*/
cond1 = r0 == 4;
/*0x802991e
0x802991e 4 02f049f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029922 2 0228 cmp r0, 2
0x8029924 2 05d1 bne.n 0x8029932
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
/*0x8029926
0x8029926 2 3046 mov r0, r6
0x8029928 4 f9f79cf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802992c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029930 2 05b2 sxth r5, r0
*/

}
while (1) 
{
/*0x8029932
0x8029932 4 b5f5007f cmp.w r5, 512
0x8029936 2 02db blt.n 0x802993e
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029938
0x8029938 4 40f2ff15 movw r5, 511
0x802993c 2 02e0 b.n 0x8029944
*/

}
else
{
/*0x802993e
0x802993e 2 002d cmp r5, 0
0x8029940 2 00da bge.n 0x8029944
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029942
0x8029942 2 0025 movs r5, 0
*/

}

}
while (1) 
{
/*0x8029944
0x8029944 2 3046 mov r0, r6
0x8029946 4 fef799fb bl 0x802807c ; int func_0x802807c ( int r0 )
0x802994a 2 8008 lsrs r0, r0, 2
0x802994c 4 b0f5806f cmp.w r0, 1024
0x8029950 2 01db blt.n 0x8029956
*/
cond0 = r0 >= 1024;
if ( cond0 ) 
{
/*0x8029952
0x8029952 4 40f2ff30 movw r0, 1023
*/

}
while (1) 
{
/*0x8029956
0x8029956 2 4c49 mov r1, 0x8045024
0x8029958 4 01eb8000 add.w r0, r1, r0, lsl 2
0x802995c 2 1f99 ldr r1, [sp, 124]
0x802995e 4 d0ed000a vldr s1, [r0]
0x8029962 2 0198 ldr r0, [sp, 4]
0x8029964 4 00ee100a vmov s0, r0
0x8029968 2 4848 mov r0, 0x8042524
0x802996a 4 b8ee400a vcvt.f32.u32 s0, s0
0x802996e 4 00eb8500 add.w r0, r0, r5, lsl 2
0x8029972 4 20ee800a vmul.f32 s0, s1, s0
0x8029976 4 d0ed000a vldr s1, [r0]
0x802997a 4 20ee200a vmul.f32 s0, s0, s1
0x802997e 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029982 4 10ee100a vmov r0, s0
0x8029986 4 a1f84400 strh.w r0, [r1, 68]
0x802998a 4 07eb4407 add.w r7, r7, r4, lsl 1
0x802998e 2 1e99 ldr r1, [sp, 120]
0x8029990 4 b7f9ea00 ldrsh.w r0, [r7, 234]
0x8029994 4 01eb4405 add.w r5, r1, r4, lsl 1
0x8029998 4 00ee100a vmov s0, r0
0x802999c 2 2798 ldr r0, [sp, 156]
0x802999e 4 b8eec00a vcvt.f32.s32 s0, s0
0x80299a2 4 d0ed000a vldr s1, [r0]
0x80299a6 4 20ee200a vmul.f32 s0, s0, s1
0x80299aa 4 bdeec00a vcvt.s32.f32 s0, s0
0x80299ae 4 10ee100a vmov r0, s0
0x80299b2 4 a5f87400 strh.w r0, [r5, 116]
0x80299b6 4 98f80500 ldrb.w r0, [r8, 5]
0x80299ba 4 fef735fe bl 0x8028628 ; int func_0x8028628 ( int r0, int r1 )
0x80299be 4 b5f85410 ldrh.w r1, [r5, 84]
0x80299c2 4 b7f8e020 ldrh.w r2, [r7, 224]
0x80299c6 4 b5f87430 ldrh.w r3, [r5, 116]
0x80299ca 2 0a44 add r2, r1
0x80299cc 2 1f99 ldr r1, [sp, 124]
0x80299ce 4 b1f84410 ldrh.w r1, [r1, 68]
0x80299d2 2 1944 add r1, r3
0x80299d4 2 1144 add r1, r2
0x80299d6 2 0844 add r0, r1
0x80299d8 2 00b2 sxth r0, r0
0x80299da 4 2af81400 strh.w r0, [sl, r4, lsl 1]
0x80299de 4 b0f5805f cmp.w r0, 4096
0x80299e2 2 03db blt.n 0x80299ec
*/
cond0 = r0 >= 4096;
if ( cond0 ) 
{
/*0x80299e4
0x80299e4 4 40f6ff70 movw r0, 4095
0x80299e8 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299ec
0x80299ec 4 3af91400 ldrsh.w r0, [sl, r4, lsl 1]
0x80299f0 2 0028 cmp r0, 0
0x80299f2 2 02da bge.n 0x80299fa
*/
cond0 = r0 < 0;
if ( cond0 ) 
{
/*0x80299f4
0x80299f4 2 0020 movs r0, 0
0x80299f6 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299fa
0x80299fa 2 2298 ldr r0, [sp, 136]
0x80299fc 4 3af81410 ldrh.w r1, [sl, r4, lsl 1]
0x8029a00 4 20f81410 strh.w r1, [r0, r4, lsl 1]
0x8029a04 4 fef78af9 bl 0x8027d1c ; int func_0x8027d1c ( int r0, int r1 )
0x8029a08 2 0128 cmp r0, 1
0x8029a0a 2 11d0 beq.n 0x8029a30
*/
cond0 = r0 != 1;
if ( cond0 ) 
{
/*0x8029a0c
0x8029a0c 2 2198 ldr r0, [sp, 132]
0x8029a0e 2 0022 movs r2, 0
0x8029a10 4 04eb4000 add.w r0, r4, r0, lsl 1
0x8029a14 2 c1b2 uxtb r1, r0
0x8029a16 2 2098 ldr r0, [sp, 128]
0x8029a18 4 00f0fefa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}
else
{
/*0x802958e
0x802958e 4 98f80700 ldrb.w r0, [r8, 7]
0x8029592 2 a055 strb r0, [r4, r6]
0x8029594 2 98e7 b.n 0x80294c8
*/

}
/*0x80294c8
0x80294c8 2 3d20 movs r0, 61
0x80294ca 4 13f05bfe bl 0x803d184 ; int func_0x803d184 ( int r0 )
0x80294ce 2 f649 mov r1, 0x8046024
0x80294d0 4 c0f1ff00 rsb r0, r0, 255
0x80294d4 4 01ebc000 add.w r0, r1, r0, lsl 3
0x80294d8 2 f54a mov r2, 0x2000501c
0x80294da 4 90ed000a vldr s0, [r0]
0x80294de 2 f348 mov r0, 0x20005484
0x80294e0 4 02eb4601 add.w r1, r2, r6, lsl 1
0x80294e4 4 00eb8600 add.w r0, r0, r6, lsl 2
0x80294e8 2 2790 str r0, [sp, 156]
0x80294ea 4 d0ed000a vldr s1, [r0]
0x80294ee 2 2691 str r1, [sp, 152]
0x80294f0 4 20ee200a vmul.f32 s0, s0, s1
0x80294f4 4 bdeec00a vcvt.s32.f32 s0, s0
0x80294f8 4 10ee100a vmov r0, s0
0x80294fc 2 00b2 sxth r0, r0
0x80294fe 4 a1f84c00 strh.w r0, [r1, 76]
0x8029502 4 b0f5007f cmp.w r0, 512
0x8029506 2 04db blt.n 0x8029512
*/
cond0 = r0 >= 512;
if ( cond0 ) 
{
/*0x8029508
0x8029508 2 2698 ldr r0, [sp, 152]
0x802950a 4 40f2ff11 movw r1, 511
0x802950e 4 a0f84c10 strh.w r1, [r0, 76]
*/

}
/*0x8029512
0x8029512 2 0024 movs r4, 0
0x8029514 2 e748 mov r0, 0x20005274
0x8029516 2 0022 movs r2, 0
0x8029518 4 00eb8609 add.w r9, r0, r6, lsl 2
0x802951c 4 00f5d870 add.w r0, r0, 432
0x8029520 4 00ebc600 add.w r0, r0, r6, lsl 3
0x8029524 2 2590 str r0, [sp, 148]
0x8029526 4 06f00300 and.w r0, r6, 3
0x802952a 2 2190 str r0, [sp, 132]
0x802952c 4 02eb4000 add.w r0, r2, r0, lsl 1
0x8029530 2 2490 str r0, [sp, 144]
0x8029532 2 2198 ldr r0, [sp, 132]
0x8029534 2 0122 movs r2, 1
0x8029536 2 e049 mov r1, 0x20005380
0x8029538 4 02eb4000 add.w r0, r2, r0, lsl 1
0x802953c 2 2390 str r0, [sp, 140]
0x802953e 4 01f1e400 add.w r0, r1, 228
0x8029542 4 00eb8600 add.w r0, r0, r6, lsl 2
0x8029546 2 2290 str r0, [sp, 136]
0x8029548 2 0420 movs r0, 4
0x802954a 4 00eb9600 add.w r0, r0, r6, lsr 2
0x802954e 2 2090 str r0, [sp, 128]
0x8029550 4 01eb4600 add.w r0, r1, r6, lsl 1
0x8029554 2 1f90 str r0, [sp, 124]
0x8029556 4 01eb8600 add.w r0, r1, r6, lsl 2
0x802955a 2 1e90 str r0, [sp, 120]
0x802955c 2 0aa8 add r0, sp, 40
0x802955e 4 00ebc600 add.w r0, r0, r6, lsl 3
0x8029562 2 1d90 str r0, [sp, 116]
0x8029564 4 a1f58670 sub.w r0, r1, 268
0x8029568 2 02ab add r3, sp, 8
0x802956a 4 00ebc600 add.w r0, r0, r6, lsl 3
0x802956e 4 03eb860a add.w sl, r3, r6, lsl 2
0x8029572 2 1c90 str r0, [sp, 112]
*/
while (1) 
{
/*0x8029574
0x8029574 4 07f010fa bl 0x8030998 ; int func_0x8030998 ()
0x8029578 2 88b1 cbz r0, 0x802959e
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x802957a
0x802957a 2 0627 movs r7, 6
*/

}
else
{
/*0x802959e
0x802959e 2 0427 movs r7, 4
0x80295a0 2 ece7 b.n 0x802957c
*/

}
while (1) 
{
/*0x802957c
0x802957c 4 dff830b3 mov fp, 0x2000501c
0x8029580 4 bbf94a50 ldrsh.w r5, [fp, 74]
0x8029584 4 f9f768fb bl 0x8022c58 ; int func_0x8022c58 ()
0x8029588 2 0328 cmp r0, 3
0x802958a 2 0ad0 beq.n 0x80295a2
*/
cond0 = r0 != 3;
if ( cond0 ) 
{
/*0x802958c
0x802958c 2 1be0 b.n 0x80295c6
*/

}
else
{
/*0x80295a2
0x80295a2 4 02f007fa bl 0x802b9b4 ; int func_0x802b9b4 ()
0x80295a6 2 0228 cmp r0, 2
0x80295a8 2 0dd1 bne.n 0x80295c6
*/
cond0 = r0 == 2;
if ( cond0 ) 
{

}

}
while (1) 
{
/*0x80295c6
0x80295c6 2 3046 mov r0, r6
0x80295c8 4 fef758fd bl 0x802807c ; int func_0x802807c ( int r0 )
0x80295cc 4 20f00301 bic.w r1, r0, 3
0x80295d0 2 bb48 mov r0, 0x8043024
0x80295d2 4 00ee107a vmov s0, r7
0x80295d6 2 0844 add r0, r1
0x80295d8 2 269a ldr r2, [sp, 152]
0x80295da 4 d0ed000a vldr s1, [r0]
0x80295de 4 b8ee400a vcvt.f32.u32 s0, s0
0x80295e2 2 b848 mov r0, 0x8042524
0x80295e4 4 b2f94c20 ldrsh.w r2, [r2, 76]
0x80295e8 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80295ec 4 00eb8200 add.w r0, r0, r2, lsl 2
0x80295f0 4 20ee800a vmul.f32 s0, s1, s0
0x80295f4 4 d1ed000a vldr s1, [r1]
0x80295f8 4 90ed001a vldr s2, [r0]
0x80295fc 2 ac49 mov r1, 0x2000501c
0x80295fe 4 70ee810a vadd.f32 s1, s1, s2
0x8029602 4 01f5167b add.w fp, r1, 600
0x8029606 4 20ee200a vmul.f32 s0, s0, s1
0x802960a 4 bdeec00a vcvt.s32.f32 s0, s0
0x802960e 4 10ee100a vmov r0, s0
0x8029612 4 a9f84c00 strh.w r0, [r9, 76]
0x8029616 4 01eb4400 add.w r0, r1, r4, lsl 1
0x802961a 2 1b90 str r0, [sp, 108]
0x802961c 4 b0f96000 ldrsh.w r0, [r0, 96]
0x8029620 2 c110 asrs r1, r0, 3
0x8029622 2 a948 mov r0, 0x804d824
0x8029624 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x8029628 2 1c99 ldr r1, [sp, 112]
0x802962a 4 00ee100a vmov s0, r0
0x802962e 2 2798 ldr r0, [sp, 156]
0x8029630 4 01eb8407 add.w r7, r1, r4, lsl 2
0x8029634 4 b8ee400a vcvt.f32.u32 s0, s0
0x8029638 4 d0ed000a vldr s1, [r0]
0x802963c 4 20ee200a vmul.f32 s0, s0, s1
0x8029640 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029644 4 10ee100a vmov r0, s0
0x8029648 4 a7f8ac00 strh.w r0, [r7, 172]
0x802964c 4 0beb8400 add.w r0, fp, r4, lsl 2
0x8029650 2 1a90 str r0, [sp, 104]
0x8029652 4 b0f94050 ldrsh.w r5, [r0, 64]
0x8029656 4 f9f7fffa bl 0x8022c58 ; int func_0x8022c58 ()
0x802965a 2 0828 cmp r0, 8
0x802965c 2 04d1 bne.n 0x8029668
*/
cond2 = r0 == 8;
/*0x802965e
0x802965e 2 1cb9 cbnz r4, 0x8029668
*/
cond1 = r4 == 0;
/*0x8029660
0x8029660 4 02f0a8f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029664 2 0228 cmp r0, 2
0x8029666 2 04d0 beq.n 0x8029672
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80296b8
0x80296b8 2 7e48 mov r0, 0x20005274
0x80296ba 4 b0f948b0 ldrsh.w fp, [r0, 72]
0x80296be 4 f9f7cbfa bl 0x8022c58 ; int func_0x8022c58 ()
0x80296c2 2 0528 cmp r0, 5
0x80296c4 2 14d1 bne.n 0x80296f0
*/
cond1 = r0 == 5;
/*0x80296c6
0x80296c6 4 02f075f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x80296ca 2 0228 cmp r0, 2
0x80296cc 2 10d1 bne.n 0x80296f0
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80296f0
0x80296f0 4 fef77afd bl 0x80281e8 ; int func_0x80281e8 ()
0x80296f4 2 20b3 cbz r0, 0x8029740
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x80296f6
0x80296f6 4 98f80500 ldrb.w r0, [r8, 5]
0x80296fa 4 fef773ff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x80296fe 4 b7f86c10 ldrh.w r1, [r7, 108]
0x8029702 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029706 2 1144 add r1, r2
0x8029708 4 b9f84c20 ldrh.w r2, [r9, 76]
0x802970c 2 2a44 add r2, r5
0x802970e 2 1144 add r1, r2
0x8029710 2 5944 add r1, fp
0x8029712 2 0844 add r0, r1
0x8029714 2 1d99 ldr r1, [sp, 116]
0x8029716 4 21f82400 strh.w r0, [r1, r4, lsl 2]
*/

}
else
{
/*0x8029740
0x8029740 4 98f80500 ldrb.w r0, [r8, 5]
0x8029744 4 fef74eff bl 0x80285e4 ; int func_0x80285e4 ( int r0, int r1 )
0x8029748 4 b7f86c10 ldrh.w r1, [r7, 108]
0x802974c 4 b7f8ac20 ldrh.w r2, [r7, 172]
0x8029750 2 691a subs r1, r5, r1
0x8029752 2 891a subs r1, r1, r2
0x8029754 4 b9f84c20 ldrh.w r2, [r9, 76]
0x8029758 2 891a subs r1, r1, r2
0x802975a 4 a1eb0b01 sub.w r1, r1, fp
0x802975e 2 081a subs r0, r1, r0
0x8029760 2 1d99 ldr r1, [sp, 116]
0x8029762 4 21f82400 strh.w r0, [r1, r4, lsl 2]
0x8029766 2 d8e7 b.n 0x802971a
*/

}
while (1) 
{
/*0x802971a
0x802971a 2 1d98 ldr r0, [sp, 116]
0x802971c 4 30f82410 ldrh.w r1, [r0, r4, lsl 2]
0x8029720 2 2598 ldr r0, [sp, 148]
0x8029722 4 20f82410 strh.w r1, [r0, r4, lsl 2]
0x8029726 4 07f037f9 bl 0x8030998 ; int func_0x8030998 ()
0x802972a 2 e8b1 cbz r0, 0x8029768
*/
cond0 = r0 != 0;
if ( cond0 ) 
{
/*0x802972c
0x802972c 2 0820 movs r0, 8
0x802972e 2 0190 str r0, [sp, 4]
*/

}
else
{
/*0x8029768
0x8029768 2 0620 movs r0, 6
0x802976a 2 0190 str r0, [sp, 4]
0x802976c 2 e0e7 b.n 0x8029730
*/

}
while (1) 
{
/*0x8029730
0x8029730 2 5f48 mov r0, 0x2000501c
0x8029732 4 b0f94a50 ldrsh.w r5, [r0, 74]
0x8029736 4 f9f78ffa bl 0x8022c58 ; int func_0x8022c58 ()
0x802973a 2 0328 cmp r0, 3
0x802973c 2 17d0 beq.n 0x802976e
*/
cond0 = r0 != 3;
if ( cond0 ) 
{
/*0x802973e
0x802973e 2 28e0 b.n 0x8029792
*/

}
else
{
/*0x802976e
0x802976e 4 02f021f9 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029772 2 0228 cmp r0, 2
0x8029774 2 0dd1 bne.n 0x8029792
*/
cond0 = r0 == 2;
if ( cond0 ) 
{

}

}
while (1) 
{
/*0x8029792
0x8029792 2 3046 mov r0, r6
0x8029794 4 fef772fc bl 0x802807c ; int func_0x802807c ( int r0 )
0x8029798 4 20f00301 bic.w r1, r0, 3
0x802979c 2 4b48 mov r0, 0x8044024
0x802979e 4 dff814b1 mov fp, 0x20005274
0x80297a2 2 0844 add r0, r1
0x80297a4 4 d0ed000a vldr s1, [r0]
0x80297a8 2 0198 ldr r0, [sp, 4]
0x80297aa 4 00ee100a vmov s0, r0
0x80297ae 2 4548 mov r0, 0x8042524
0x80297b0 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297b4 4 00eb8501 add.w r1, r0, r5, lsl 2
0x80297b8 4 20ee800a vmul.f32 s0, s1, s0
0x80297bc 4 d1ed000a vldr s1, [r1]
0x80297c0 2 2699 ldr r1, [sp, 152]
0x80297c2 4 b1f94c10 ldrsh.w r1, [r1, 76]
0x80297c6 4 00eb8100 add.w r0, r0, r1, lsl 2
0x80297ca 4 90ed001a vldr s2, [r0]
0x80297ce 4 70ee810a vadd.f32 s1, s1, s2
0x80297d2 4 20ee200a vmul.f32 s0, s0, s1
0x80297d6 4 bdeec00a vcvt.s32.f32 s0, s0
0x80297da 4 10ee100a vmov r0, s0
0x80297de 4 a9f84e00 strh.w r0, [r9, 78]
0x80297e2 2 1b98 ldr r0, [sp, 108]
0x80297e4 4 b0f96000 ldrsh.w r0, [r0, 96]
0x80297e8 2 c110 asrs r1, r0, 3
0x80297ea 2 3948 mov r0, 0x804dc24
0x80297ec 4 30f81100 ldrh.w r0, [r0, r1, lsl 1]
0x80297f0 4 00ee100a vmov s0, r0
0x80297f4 2 2798 ldr r0, [sp, 156]
0x80297f6 4 b8ee400a vcvt.f32.u32 s0, s0
0x80297fa 4 d0ed000a vldr s1, [r0]
0x80297fe 4 20ee200a vmul.f32 s0, s0, s1
0x8029802 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029806 4 10ee100a vmov r0, s0
0x802980a 4 a7f8ae00 strh.w r0, [r7, 174]
0x802980e 2 1a98 ldr r0, [sp, 104]
0x8029810 4 b0f94250 ldrsh.w r5, [r0, 66]
0x8029814 4 f9f720fa bl 0x8022c58 ; int func_0x8022c58 ()
0x8029818 2 0628 cmp r0, 6
0x802981a 2 04d1 bne.n 0x8029826
*/
cond2 = r0 == 6;
/*0x802981c
0x802981c 2 1cb9 cbnz r4, 0x8029826
*/
cond1 = r4 == 0;
/*0x802981e
0x802981e 4 02f0c9f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029822 2 0228 cmp r0, 2
0x8029824 2 04d0 beq.n 0x8029830
*/
cond0 = r0 != 2;
if ( cond2 && cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x8029876
0x8029876 4 bbf94ab0 ldrsh.w fp, [fp, 74]
0x802987a 4 f9f7edf9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802987e 2 0528 cmp r0, 5
0x8029880 2 2fd1 bne.n 0x80298e2
*/
cond1 = r0 == 5;
/*0x8029882
0x8029882 4 02f097f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029886 2 0228 cmp r0, 2
0x8029888 2 2bd1 bne.n 0x80298e2
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{

}
while (1) 
{
/*0x80298e2
0x80298e2 4 98f80500 ldrb.w r0, [r8, 5]
0x80298e6 4 fef78bfe bl 0x8028600 ; int func_0x8028600 ( int r0, int r1 )
0x80298ea 4 b7f86e10 ldrh.w r1, [r7, 110]
0x80298ee 4 b7f8ae20 ldrh.w r2, [r7, 174]
0x80298f2 2 1144 add r1, r2
0x80298f4 4 b9f84e20 ldrh.w r2, [r9, 78]
0x80298f8 2 2a44 add r2, r5
0x80298fa 2 1144 add r1, r2
0x80298fc 2 5944 add r1, fp
0x80298fe 2 0844 add r0, r1
0x8029900 2 1d99 ldr r1, [sp, 116]
0x8029902 4 01eb8401 add.w r1, r1, r4, lsl 2
0x8029906 2 4880 strh r0, [r1, 2]
0x8029908 2 2599 ldr r1, [sp, 148]
0x802990a 4 01eb8401 add.w r1, r1, r4, lsl 2
0x802990e 2 4880 strh r0, [r1, 2]
0x8029910 2 5c4f mov r7, 0x20005088
0x8029912 4 b7f9e450 ldrsh.w r5, [r7, 228]
0x8029916 4 f9f79ff9 bl 0x8022c58 ; int func_0x8022c58 ()
0x802991a 2 0428 cmp r0, 4
0x802991c 2 09d1 bne.n 0x8029932
*/
cond1 = r0 == 4;
/*0x802991e
0x802991e 4 02f049f8 bl 0x802b9b4 ; int func_0x802b9b4 ()
0x8029922 2 0228 cmp r0, 2
0x8029924 2 05d1 bne.n 0x8029932
*/
cond0 = r0 == 2;
if ( cond1 && ~(cond0) ) 
{
/*0x8029926
0x8029926 2 3046 mov r0, r6
0x8029928 4 f9f79cf9 bl 0x8022c64 ; long func_0x8022c64 ( int r0 )
0x802992c 4 05eb4000 add.w r0, r5, r0, lsl 1
0x8029930 2 05b2 sxth r5, r0
*/

}
while (1) 
{
/*0x8029932
0x8029932 4 b5f5007f cmp.w r5, 512
0x8029936 2 02db blt.n 0x802993e
*/
cond0 = r5 >= 512;
if ( cond0 ) 
{
/*0x8029938
0x8029938 4 40f2ff15 movw r5, 511
0x802993c 2 02e0 b.n 0x8029944
*/

}
else
{
/*0x802993e
0x802993e 2 002d cmp r5, 0
0x8029940 2 00da bge.n 0x8029944
*/
cond0 = r5 < 0;
if ( cond0 ) 
{
/*0x8029942
0x8029942 2 0025 movs r5, 0
*/

}

}
while (1) 
{
/*0x8029944
0x8029944 2 3046 mov r0, r6
0x8029946 4 fef799fb bl 0x802807c ; int func_0x802807c ( int r0 )
0x802994a 2 8008 lsrs r0, r0, 2
0x802994c 4 b0f5806f cmp.w r0, 1024
0x8029950 2 01db blt.n 0x8029956
*/
cond0 = r0 >= 1024;
if ( cond0 ) 
{
/*0x8029952
0x8029952 4 40f2ff30 movw r0, 1023
*/

}
while (1) 
{
/*0x8029956
0x8029956 2 4c49 mov r1, 0x8045024
0x8029958 4 01eb8000 add.w r0, r1, r0, lsl 2
0x802995c 2 1f99 ldr r1, [sp, 124]
0x802995e 4 d0ed000a vldr s1, [r0]
0x8029962 2 0198 ldr r0, [sp, 4]
0x8029964 4 00ee100a vmov s0, r0
0x8029968 2 4848 mov r0, 0x8042524
0x802996a 4 b8ee400a vcvt.f32.u32 s0, s0
0x802996e 4 00eb8500 add.w r0, r0, r5, lsl 2
0x8029972 4 20ee800a vmul.f32 s0, s1, s0
0x8029976 4 d0ed000a vldr s1, [r0]
0x802997a 4 20ee200a vmul.f32 s0, s0, s1
0x802997e 4 bdeec00a vcvt.s32.f32 s0, s0
0x8029982 4 10ee100a vmov r0, s0
0x8029986 4 a1f84400 strh.w r0, [r1, 68]
0x802998a 4 07eb4407 add.w r7, r7, r4, lsl 1
0x802998e 2 1e99 ldr r1, [sp, 120]
0x8029990 4 b7f9ea00 ldrsh.w r0, [r7, 234]
0x8029994 4 01eb4405 add.w r5, r1, r4, lsl 1
0x8029998 4 00ee100a vmov s0, r0
0x802999c 2 2798 ldr r0, [sp, 156]
0x802999e 4 b8eec00a vcvt.f32.s32 s0, s0
0x80299a2 4 d0ed000a vldr s1, [r0]
0x80299a6 4 20ee200a vmul.f32 s0, s0, s1
0x80299aa 4 bdeec00a vcvt.s32.f32 s0, s0
0x80299ae 4 10ee100a vmov r0, s0
0x80299b2 4 a5f87400 strh.w r0, [r5, 116]
0x80299b6 4 98f80500 ldrb.w r0, [r8, 5]
0x80299ba 4 fef735fe bl 0x8028628 ; int func_0x8028628 ( int r0, int r1 )
0x80299be 4 b5f85410 ldrh.w r1, [r5, 84]
0x80299c2 4 b7f8e020 ldrh.w r2, [r7, 224]
0x80299c6 4 b5f87430 ldrh.w r3, [r5, 116]
0x80299ca 2 0a44 add r2, r1
0x80299cc 2 1f99 ldr r1, [sp, 124]
0x80299ce 4 b1f84410 ldrh.w r1, [r1, 68]
0x80299d2 2 1944 add r1, r3
0x80299d4 2 1144 add r1, r2
0x80299d6 2 0844 add r0, r1
0x80299d8 2 00b2 sxth r0, r0
0x80299da 4 2af81400 strh.w r0, [sl, r4, lsl 1]
0x80299de 4 b0f5805f cmp.w r0, 4096
0x80299e2 2 03db blt.n 0x80299ec
*/
cond0 = r0 >= 4096;
if ( cond0 ) 
{
/*0x80299e4
0x80299e4 4 40f6ff70 movw r0, 4095
0x80299e8 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299ec
0x80299ec 4 3af91400 ldrsh.w r0, [sl, r4, lsl 1]
0x80299f0 2 0028 cmp r0, 0
0x80299f2 2 02da bge.n 0x80299fa
*/
cond0 = r0 < 0;
if ( cond0 ) 
{
/*0x80299f4
0x80299f4 2 0020 movs r0, 0
0x80299f6 4 2af81400 strh.w r0, [sl, r4, lsl 1]
*/

}
while (1) 
{
/*0x80299fa
0x80299fa 2 2298 ldr r0, [sp, 136]
0x80299fc 4 3af81410 ldrh.w r1, [sl, r4, lsl 1]
0x8029a00 4 20f81410 strh.w r1, [r0, r4, lsl 1]
0x8029a04 4 fef78af9 bl 0x8027d1c ; int func_0x8027d1c ( int r0, int r1 )
0x8029a08 2 0128 cmp r0, 1
0x8029a0a 2 11d0 beq.n 0x8029a30
*/
cond0 = r0 != 1;
if ( cond0 ) 
{
/*0x8029a0c
0x8029a0c 2 2198 ldr r0, [sp, 132]
0x8029a0e 2 0022 movs r2, 0
0x8029a10 4 04eb4000 add.w r0, r4, r0, lsl 1
0x8029a14 2 c1b2 uxtb r1, r0
0x8029a16 2 2098 ldr r0, [sp, 128]
0x8029a18 4 00f0fefa bl 0x802a018 ; void func_0x802a018 ( int r0, int r1, int r2 )
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}
/*0x8029a1c
0x8029a1c 2 641c adds r4, r4, 1
0x8029a1e 2 022c cmp r4, 2
0x8029a20 4 fff6a8ad blt.w 0x8029574
*/

}

}