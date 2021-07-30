0x802f708 4 2de9f041 stmdb sp!, {r4, r5, r6, r7, r8, lr}
0x802f70c 2 8ab0 sub sp, 40
0x802f70e 2 0546 mov r5, r0
0x802f710 2 0021 movs r1, 0
0x802f712 2 5348 mov r0, 0x40002000
0x802f714 4 06f0f7fe bl 0x8036506
0x802f718 2 5248 mov r0, 0x20000f28
0x802f71a 2 8078 ldrb r0, [r0, 2]
0x802f71c 2 0a28 cmp r0, 10
0x802f71e 2 37d2 bcs.n 0x802f790
0x802f720 4 dfe800f0 tbb [pc, r0] 0x802f72e, 0x802f738, 0x802f742, 0x802f74c, 0x802f756, 0x802f760, 0x802f76a, 0x802f774, 0x802f77e, 0x802f788 
0x802f726 2 0f14 asrs r7, r1, 16
0x802f728 2 191e subs r1, r3, 0
0x802f72a 2 2328 cmp r0, 35
0x802f72c 2 2d32 adds r2, 45
0x802f72e 2 4ea1 add r1, pc, 312 ; (adr r1, 0x00000160)
0x802f730 2 02a8 add r0, sp, 8
0x802f732 4 f0f7ebfd bl 0x802030c
0x802f736 2 2be0 b.n 0x802f790
0x802f738 2 4ea1 add r1, pc, 312 ; (adr r1, 0x00000140)
0x802f73a 2 02a8 add r0, sp, 8
0x802f73c 4 f0f7e6fd bl 0x802030c
0x802f740 2 26e0 b.n 0x802f790
0x802f742 2 4fa1 add r1, pc, 316 ; (adr r1, 0x00000144)
0x802f744 2 02a8 add r0, sp, 8
0x802f746 4 f0f7e1fd bl 0x802030c
0x802f748 4 e1fd21e0 b.n 0x802f790
0x802f74c 2 4fa1 add r1, pc, 316 ; (adr r1, 0x00000144)
0x802f74e 2 02a8 add r0, sp, 8
0x802f750 4 f0f7dcfd bl 0x802030c
0x802f754 2 1ce0 b.n 0x802f790
0x802f756 2 50a1 add r1, pc, 320 ; (adr r1, 0x00000148)
0x802f758 2 02a8 add r0, sp, 8
0x802f75a 4 f0f7d7fd bl 0x802030c
0x802f75e 2 17e0 b 0x802f790
0x802f760 2 50a1 add r1, pc, 320 ; (adr r1, 0x00000148)
0x802f762 2 02a8 add r0, sp, 8
0x802f764 4 f0f7d2fd bl 0x802030c
0x802f768 2 12e0 b.n 0x802f790
0x802f76a 2 51a1 add r1, pc, 324 ; (adr r1, 0x00000148)
0x802f76c 2 02a8 add r0, sp, 8
0x802f76e 4 f0f7cdfd bl 0x802030c
0x802f772 2 0de0 b.n 0x802f790
0x802f774 2 51a1 add r1, pc, 324 ; (adr r1, 0x00000148)
0x802f776 2 02a8 add r0, sp, 8
0x802f778 4 f0f7c8fd bl 0x802030c
0x802f77a 4 c8fd08e0 b.n 0x802f790
0x802f77e 2 52a1 add r1, pc, 328 ; (adr r1, 0x00000150)
0x802f780 2 02a8 add r0, sp, 8
0x802f782 4 f0f7c3fd bl 0x802030c
0x802f786 2 03e0 b.n 0x802f790
0x802f788 2 52a1 add r1, pc, 328 ; (adr r1, 0x00000150)
0x802f78a 2 02a8 add r0, sp, 8
0x802f78c 4 f0f7befd bl 0x802030c
0x802f790 2 0122 movs r2, 1
0x802f792 2 53a1 add r1, pc, 332 ; (adr r1, 0x0000015c)
0x802f794 2 5348 mov r0, 0x200098e4
0x802f796 4 0cf04ffa bl 0x803bc38
0x802f79a 2 324e mov r6, 0x20000f28
0x802f79c 2 3070 strb r0, [r6, 0]
0x802f79e 2 0127 movs r7, 1
0x802f7a0 2 0028 cmp r0, 0
0x802f7a2 2 55d1 bne.n 0x802f850
0x802f7a4 2 0122 movs r2, 1
0x802f7a6 2 02a9 add r1, sp, 8
0x802f7a8 2 4f48 mov r0, 0x200088bc
0x802f7aa 4 0cf06bfa bl 0x803bc84
0x802f7ae 2 7070 strb r0, [r6, 1]
0x802f7b0 2 0028 cmp r0, 0
0x802f7b2 2 48d1 bne.n 0x802f846
0x802f7b4 2 6c1e subs r4, r5, 1
0x802f7b6 2 6220 movs r0, 98
0x802f7b8 4 04fb00f1 mul.w r1, r4, r0
0x802f7bc 2 4a48 mov r0, 0x200088bc
0x802f7be 4 0cf076f9 bl 0x803baae
0x802f7c2 2 01ab add r3, sp, 4
0x802f7c4 2 5122 movs r2, 81
0x802f7c6 2 4949 mov r1, 0x2000a91c
0x802f7c8 2 4748 mov r0, 0x200088bc
0x802f7ca 4 0cf041fb bl 0x803be50
0x802f7ce 4 04eb0410 add.w r0, r4, r4, lsl 4
0x802f7d2 4 00eb4410 add.w r0, r0, r4, lsl 5
0x802f7d6 2 5121 movs r1, 81
0x802f7d8 4 01eb4001 add.w r1, r1, r0, lsl 1
0x802f7dc 2 4248 mov r0, 0x200088bc
0x802f7de 4 0cf066f9 bl 0x803baae
0x802f7e2 2 01ab add r3, sp, 4
0x802f7e4 2 1122 movs r2, 17
0x802f7e6 2 4249 mov r1, 0x2000a96d
0x802f7e8 2 3f48 mov r0, 0x200088bc
0x802f7ea 4 0cf031fb bl 0x803be50
0x802f7ee 2 0021 movs r1, 0
0x802f7f0 2 3e48 mov r0, 0x2000a91c
0x802f7f2 2 404c mov r4, 0x20004afc
0x802f7f4 4 4ff00208 mov.w r8, 2
0x802f7f8 4 04eb0112 add.w r2, r4, r1, lsl 4
0x802f7fc 2 435c ldrb r3, [r0, r1]
0x802f7fe 2 1371 strb r3, [r2, 4]
0x802f800 4 82f80580 strb.w r8, [r2, 5]
0x802f804 2 9771 strb r7, [r2, 6]
0x802f806 2 491c adds r1, r1, 1
0x802f808 2 c9b2 uxtb r1, r1
0x802f80a 2 5129 cmp r1, 81
0x802f80c 2 f4d3 bcc.n 0x802f7f8
0x802f80e 4 02f085fd bl 0x803231c
0x802f812 4 4ff4c072 mov.w r2, 384
0x802f816 2 3849 mov r1, 0x2000a9ca
0x802f818 4 4ff4fa20 mov.w r0, 512000
0x802f81c 4 01f038f8 bl 0x8030890
0x802f820 2 3548 mov r0, 0x2000a9ca
0x802f822 2 b178 ldrb r1, [r6, 2]
0x802f824 4 00ebc110 add.w r0, r0, r1, lsl 7
0x802f828 2 2844 add r0, r5
0x802f82a 4 10f8010c ldrb.w r0, [r0, -1]
0x802f82e 2 ff28 cmp r0, 255
0x802f830 2 02d0 beq.n 0x802f838
0x802f832 4 84f81405 strb.w r0, [r4, 1300]
0x802f836 2 02e0 b.n 0x802f83e
0x802f838 2 0020 movs r0, 0
0x802f83a 4 84f81405 strb.w r0, [r4, 1300]
0x802f83e 4 84f81585 strb.w r8, [r4, 1301]
0x802f842 4 84f81675 strb.w r7, [r4, 1302]
0x802f846 2 0122 movs r2, 1
0x802f848 2 25a1 add r1, pc, 148 ; (adr r1, 0x0000011c)
0x802f84a 2 0020 movs r0, 0
0x802f84c 4 0cf0f4f9 bl 0x803bc38
0x802f850 2 3771 strb r7, [r6, 4]
0x802f852 2 0121 movs r1, 1
0x802f854 2 0248 mov r0, 0x40002000
0x802f856 4 06f056fe bl 0x8036506
0x802f85a 2 0ab0 add sp, 40
0x802f85c 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
0x802f866 2 0020 movs r0, 0
0x802f868 2 6464 str r4, [r4, 68]
0x802f86a 2 5f62 str r7, [r3, 36]
0x802f86c 2 616e ldr r1, [r4, 100]
0x802f86e 2 6b5f ldrsh r3, [r5, r5]
0x802f870 2 312e cmp r6, 49
0x802f872 2 7000 lsls r0, r6, 1
0x802f874 2 6464 str r4, [r4, 68]
0x802f876 2 5f62 str r7, [r3, 36]
0x802f878 2 616e ldr r1, [r4, 100]
0x802f87a 2 6b5f ldrsh r3, [r5, r5]
0x802f87c 2 322e cmp r6, 50
0x802f87e 2 7000 lsls r0, r6, 1
0x802f880 2 6464 str r4, [r4, 68]
0x802f882 2 5f62 str r7, [r3, 36]
0x802f884 2 616e ldr r1, [r4, 100]
0x802f886 2 6b5f ldrsh r3, [r5, r5]
0x802f888 2 662e cmp r6, 102
0x802f88a 2 7000 lsls r0, r6, 1
0x802f88c 2 6464 str r4, [r4, 68]
0x802f88e 2 5f62 str r7, [r3, 36]
0x802f890 2 616e ldr r1, [r4, 100]
0x802f892 2 6b5f ldrsh r3, [r5, r5]
0x802f894 2 332e cmp r6, 51
0x802f896 2 7000 lsls r0, r6, 1
0x802f898 2 6464 str r4, [r4, 68]
0x802f89a 2 5f62 str r7, [r3, 36]
0x802f89c 2 616e ldr r1, [r4, 100]
0x802f89e 2 6b5f ldrsh r3, [r5, r5]
0x802f8a0 2 342e cmp r6, 52
0x802f8a2 2 7000 lsls r0, r6, 1
0x802f8a4 2 6464 str r4, [r4, 68]
0x802f8a6 2 5f62 str r7, [r3, 36]
0x802f8a8 2 616e ldr r1, [r4, 100]
0x802f8aa 2 6b5f ldrsh r3, [r5, r5]
0x802f8ac 2 352e cmp r6, 53
0x802f8ae 2 7000 lsls r0, r6, 1
0x802f8b0 2 6464 str r4, [r4, 68]
0x802f8b2 2 5f62 str r7, [r3, 36]
0x802f8b4 2 616e ldr r1, [r4, 100]
0x802f8b6 2 6b5f ldrsh r3, [r5, r5]
0x802f8b8 2 362e cmp r6, 54
0x802f8ba 2 7000 lsls r0, r6, 1
0x802f8bc 2 6464 str r4, [r4, 68]
0x802f8be 2 5f62 str r7, [r3, 36]
0x802f8c0 2 616e ldr r1, [r4, 100]
0x802f8c2 2 6b5f ldrsh r3, [r5, r5]
0x802f8c4 2 372e cmp r6, 55
0x802f8c6 2 7000 lsls r0, r6, 1
0x802f8c8 2 6464 str r4, [r4, 68]
0x802f8ca 2 5f62 str r7, [r3, 36]
0x802f8cc 2 616e ldr r1, [r4, 100]
0x802f8ce 2 6b5f ldrsh r3, [r5, r5]
0x802f8d0 2 382e cmp r6, 56
0x802f8d2 2 7000 lsls r0, r6, 1
0x802f8d4 2 6464 str r4, [r4, 68]
0x802f8d6 2 5f62 str r7, [r3, 36]
0x802f8d8 2 616e ldr r1, [r4, 100]
0x802f8da 2 6b5f ldrsh r3, [r5, r5]
0x802f8dc 2 392e cmp r6, 57
0x802f8de 2 7000 lsls r0, r6, 1
0x802f8e0 2 3000 movs r0, r6
0x802f8e2 2 0000 movs r0, r0
0x802f8e4 2 e498 ldr r0, [sp, 912]
0x802f8e6 2 0020 movs r0, 0
0x802f8e8 2 bc88 ldrh r4, [r7, 4]
0x802f8ea 2 0020 movs r0, 0
0x802f8ec 2 1ca9 add r1, sp, 112
0x802f8ee 2 0020 movs r0, 0
0x802f8f0 2 6da9 add r1, sp, 436
0x802f8f2 2 0020 movs r0, 0
0x802f8f4 2 fc4a mov r2, 0x92022200
0x802f8f6 2 0020 movs r0, 0
0x802f8f8 2 caa9 add r1, sp, 808
0x802f8fa 2 0020 movs r0, 0
0x802f8fc 2 70b5 push {r4, r5, r6, lr}
0x802f8fe 2 724d mov r5, 0x40002000
0x802f900 2 0021 movs r1, 0
0x802f902 2 2846 mov r0, r5
0x802f904 4 06f0fffd bl 0x8036506
0x802f908 2 2c22 movs r2, 44
0x802f90a 2 7049 mov r1, 0x2000a99e
0x802f90c 4 4ff4fe20 mov.w r0, 520192
0x802f910 4 00f0beff bl 0x8030890
0x802f912 4 beff6d4c vdup.16 q2, d29[3]
0x802f916 2 6079 ldrb r0, [r4, 5]
0x802f918 2 5a28 cmp r0, 90
0x802f91a 2 7cd1 bne.n 0x802fa16
0x802f91c 2 607f ldrb r0, [r4, 29]
0x802f91e 4 06f0adff bl 0x803687c
0x802f922 2 a078 ldrb r0, [r4, 2]
0x802f924 4 fcf77cf8 bl 0x802ba20
0x802f928 2 e078 ldrb r0, [r4, 3]
0x802f92a 2 1028 cmp r0, 16
0x802f92c 2 74d0 beq.n 0x802fa18
0x802f92e 4 94f90300 ldrsb.w r0, [r4, 3]
0x802f932 4 fcf77df8 bl 0x802ba30
0x802f936 4 94f82900 ldrb.w r0, [r4, 41]
0x802f93a 4 fbf79ffe bl 0x802b67c
0x802f93e 2 2079 ldrb r0, [r4, 4]
0x802f940 4 fcf780f8 bl 0x802ba44
0x802f944 4 94f90000 ldrsb.w r0, [r4]
0x802f948 4 fcf7dcf8 bl 0x802bb04
0x802f94c 2 6078 ldrb r0, [r4, 1]
0x802f94e 4 fcf7eff8 bl 0x802bb30
0x802f952 4 94f90600 ldrsb.w r0, [r4, 6]
0x802f956 4 02f06bfb bl 0x8032030
0x802f95a 2 e179 ldrb r1, [r4, 7]
0x802f95c 2 0129 cmp r1, 1
0x802f95e 2 02d0 beq.n 0x802f966
0x802f960 2 09b1 cbz r1, 0x802f966
0x802f962 2 0120 movs r0, 1
0x802f964 2 e071 strb r0, [r4, 7]
0x802f966 2 e079 ldrb r0, [r4, 7]
0x802f968 4 0af096f9 bl 0x8039c98
0x802f96c 2 607a ldrb r0, [r4, 9]
0x802f96e 4 02f049fb bl 0x8032004
0x802f972 2 a07a ldrb r0, [r4, 10]
0x802f974 4 f3f7b6f9 bl 0x8022ce4
0x802f978 2 e07a ldrb r0, [r4, 11]
0x802f97a 4 fdf76bf8 bl 0x802ca54
0x802f97e 2 207b ldrb r0, [r4, 12]
0x802f980 4 f3f7b2fa bl 0x8022ee8
0x802f984 4 94f90d00 ldrsb.w r0, [r4, 13]
0x802f988 4 f8f7f4f8 bl 0x8027b74
0x802f98c 2 207c ldrb r0, [r4, 16]
0x802f98e 4 02f02ffd bl 0x80323f0
0x802f992 2 207a ldrb r0, [r4, 8]
0x802f994 4 fcf7f4f8 bl 0x802bb80
0x802f998 2 617c ldrb r1, [r4, 17]
0x802f99a 4 4ff47a70 mov.w r0, 1000
0x802f99e 4 11fb00f0 smulbb r0, r1, r0
0x802f9a2 4 00ee100a vmov s0, r0
0x802f9a6 4 b8ee400a vcvt.f32.u32 s0, s0
0x802f9aa 4 fdf7c5f9 bl 0x802cd38
0x802f9ae 2 a17c ldrb r1, [r4, 18]
0x802f9b0 2 6420 movs r0, 100
0x802f9b2 4 11fb00f0 smulbb r0, r1, r0
0x802f9b6 4 00ee100a vmov s0, r0
0x802f9ba 4 b8ee400a vcvt.f32.u32 s0, s0
0x802f9be 4 fdf7e1f9 bl 0x802cd84
0x802f9c2 2 e17c ldrb r1, [r4, 19]
0x802f9c4 4 4ff47a70 mov.w r0, 1000
0x802f9c8 4 11fb00f0 smulbb r0, r1, r0
0x802f9cc 4 00ee100a vmov s0, r0
0x802f9d0 4 b8ee400a vcvt.f32.u32 s0, s0
0x802f9d4 4 01f050f8 bl 0x8030a78
0x802f9d8 2 207d ldrb r0, [r4, 20]
0x802f9da 2 6421 movs r1, 100
0x802f9dc 4 10fb01f0 smulbb r0, r0, r1
0x802f9e0 4 00ee100a vmov s0, r0
0x802f9e4 4 b8ee400a vcvt.f32.u32 s0, s0
0x802f9e8 4 01f058f8 bl 0x8030a9c
0x802f9ec 2 607d ldrb r0, [r4, 21]
0x802f9ee 4 4ff47a71 mov.w r1, 1000
0x802f9f2 4 10fb01f0 smulbb r0, r0, r1
0x802f9f6 4 00ee100a vmov s0, r0
0x802f9fa 4 b8ee400a vcvt.f32.u32 s0, s0
0x802f9fe 4 f2f7bff8 bl 0x8021b80
0x802fa02 2 a07d ldrb r0, [r4, 22]
0x802fa04 4 4ff47a71 mov.w r1, 1000
0x802fa08 4 10fb01f0 smulbb r0, r0, r1
0x802fa0c 4 00ee100a vmov s0, r0
0x802fa10 4 b8ee400a vcvt.f32.u32 s0, s0
0x802fa14 2 01e0 b.n 0x802fa1a
0x802fa16 2 49e0 b.n 0x802faac
0x802fa18 2 4ee0 b.n 0x802fab8
0x802fa1a 4 f4f7e1f9 bl 0x8023de0
0x802fa1e 2 e07d ldrb r0, [r4, 23]
0x802fa20 4 fdf7b2fb bl 0x802d188
0x802fa24 2 207e ldrb r0, [r4, 24]
0x802fa26 4 fbf775ff bl 0x802b914
0x802fa2a 2 607e ldrb r0, [r4, 25]
0x802fa2c 4 fbf7a4ff bl 0x802b978
0x802fa30 2 a07e ldrb r0, [r4, 26]
0x802fa32 4 fbf785ff bl 0x802b940
0x802fa36 2 e07e ldrb r0, [r4, 27]
0x802fa38 4 fbf78eff bl 0x802b958
0x802fa3c 2 207f ldrb r0, [r4, 28]
0x802fa3e 4 fcf795f8 bl 0x802bb6c
0x802fa42 2 a07f ldrb r0, [r4, 30]
0x802fa44 4 01f00ef8 bl 0x8030a64
0x802fa48 4 94f91f00 ldrsb.w r0, [r4, 31]
0x802fa4c 4 fcf762f9 bl 0x802bd14
0x802fa50 4 94f92000 ldrsb.w r0, [r4, 32]
0x802fa54 4 fcf78cf9 bl 0x802bd70
0x802fa58 4 94f92200 ldrsb.w r0, [r4, 34]
0x802fa5c 4 f8f7cafb bl 0x80281f4
0x802fa60 4 94f82400 ldrb.w r0, [r4, 36]
0x802fa64 4 04f0c0fc bl 0x80343e8
0x802fa68 4 94f82300 ldrb.w r0, [r4, 35]
0x802fa6c 4 f3f71ef9 bl 0x8022cac
0x802fa70 4 94f82500 ldrb.w r0, [r4, 37]
0x802fa74 4 fdf7acf9 bl 0x802cdd0
0x802fa78 4 94f82600 ldrb.w r0, [r4, 38]
0x802fa7c 4 01f020f8 bl 0x8030ac0
0x802fa80 4 94f82700 ldrb.w r0, [r4, 39]
0x802fa84 4 fbf70cfc bl 0x802b2a0
0x802fa88 4 94f82800 ldrb.w r0, [r4, 40]
0x802fa8c 4 f8f7dafd bl 0x8028644
0x802fa90 4 94f82a00 ldrb.w r0, [r4, 42]
0x802fa94 2 0128 cmp r0, 1
0x802fa96 2 14d0 beq.n 0x802fac2
0x802fa98 4 f9f7f2fc bl 0x8029480
0x802fa9c 4 94f82b00 ldrb.w r0, [r4, 43]
0x802faa0 4 f3f712f9 bl 0x8022cc8
0x802faa4 4 94f82100 ldrb.w r0, [r4, 33]
0x802faa8 4 02f0f0f9 bl 0x8031e8c
0x802faac 2 2846 mov r0, r5
0x802faae 4 bde87040 ldmia.w sp!, {r4, r5, r6, lr}
0x802fab2 2 0121 movs r1, 1
0x802fab4 4 06f027bd b.w 0x8036506
0x802fab8 4 4ff0ff30 mov.w r0, 4294967295
0x802fabc 4 fbf7b8ff bl 0x802ba30
0x802fac0 2 39e7 b.n 0x802f936
0x802fac2 4 f9f7e3fc bl 0x802948c
0x802fac6 2 e9e7 b.n 0x802fa9c
