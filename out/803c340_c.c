int func_0x803c340(int p1, int p2, int p3) {
  /*
  0x803c340 4 2de9f041 stmdb sp!, {r4, r5, r6, r7, r8, lr}
  0x803c344 2 84b0 sub sp, 16
  0x803c346 2 0e46 mov r6, r1
  0x803c348 2 9046 mov r8, r2
  0x803c34a 2 0027 movs r7, 0
  0x803c34c 2 3760 str r7, [r6, 0]
  0x803c34e 4 00f09bfa bl 0x803c888
  0x803c352 2 0546 mov r5, r0
  0x803c354 2 2800 movs r0, r5
  0x803c356 2 03d5 bpl.n 0x803c360
  */
sp = sp - 16;
r6 = r1;
r8 = r2;
r7 = 0;
*( r6 + 0 ) = r7;
func_0x803c888();
r5 = r0;
r0 = r5;
  if (r0 == 0) {
  /*
    0x803c358 2 04b0 add sp, 16
    0x803c35a 2 0b20 movs r0, 11
    0x803c35c 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 11;
    return r0;
  }
  /*
  0x803c360 2 b048 mov r0, 0x20001e68
  0x803c362 4 50f82540 ldr.w r4, [r0, r5, lsl 2]
  0x803c366 2 b4b1 cbz r4, 0x803c396
  */
r0 = 0x20001e68;
r4 = *( r0 + r5 << 2 );

  if (r4 == 0) {
  /*
    0x803c396 2 04b0 add sp, 16
    0x803c398 2 0c20 movs r0, 12
    0x803c39a 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 12;
    return r0;
  }

  /*
  0x803c368 2 3460 str r4, [r6, 0]
  0x803c36a 4 08f0fe06 and.w r6, r8, 254
  0x803c36e 2 2078 ldrb r0, [r4, 0]
  0x803c370 2 28b1 cbz r0, 0x803c37e
  */
*( r6 + 0 ) = r4;
r6 = r8 & 254;
r0 = *( r4 + 0 );
  cond0 = r0 == 0;
  /*
  0x803c372 2 6078 ldrb r0, [r4, 1]
  0x803c374 4 fff781fb bl 0x803ba7a
  0x803c378 4 10f0010f tst.w r0, 1
  0x803c37c 2 0fd0 beq.n 0x803c39e
  */
r0 = *( r4 + 1 );
func_0x803ba7a();;
  cond1 = r0 & 1;

  if (~cond0 && ~(cond1)) {
  /*
    0x803c39e 2 36b1 cbz r6, 0x803c3ae
    0x803c3a0 4 10f0040f tst.w r0, 4
    0x803c3a4 2 03d0 beq.n 0x803c3ae
  */
    if (r6 == 0 || ~(r0 & 4)) {
  /*
      0x803c3ae 2 04b0 add sp, 16
      0x803c3b0 2 0020 movs r0, 0
      0x803c3b2 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 0;
      return 0;
    } else {
  /*
      0x803c3a6 2 04b0 add sp, 16
      0x803c3a8 2 0a20 movs r0, 10
      0x803c3aa 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 10;
      return 10;
    }
  }
  /*
  0x803c37e 2 2770 strb r7, [r4, 0]
  0x803c380 2 e8b2 uxtb r0, r5
  0x803c382 2 6070 strb r0, [r4, 1]
  0x803c384 4 fff76afb bl 0x803ba5c
  0x803c388 4 10f0010f tst.w r0, 1
  0x803c38c 2 13d0 beq.n 0x803c3b6
  */
*( r4 + 0 ) = r7;
r0 = (unsigned int) r5;
*( r4 + 1 ) = r0;
func_0x803ba5c();;
  if (r0 & 1) {
  /*
    0x803c38e 2 04b0 add sp, 16
    0x803c390 2 0320 movs r0, 3
    0x803c392 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 3;
    return 3;
  }
  /*
  0x803c3b6 2 36b1 cbz r6, 0x803c3c6
  0x803c3b8 4 10f0040f tst.w r0, 4
  0x803c3bc 2 03d0 beq.n 0x803c3c6
  */
  if (r6  != 0 && r0 & 4) {
  /*
    0x803c3be 2 04b0 add sp, 16
    0x803c3c0 2 0a20 movs r0, 10
    0x803c3c2 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 10;
    return 10;
  }
  /*
  0x803c3c6 2 0026 movs r6, 0
  0x803c3c8 2 3146 mov r1, r6
  0x803c3ca 2 2046 mov r0, r4
  0x803c3cc 4 fef700fe bl 0x803afd0
  0x803c3d0 2 0228 cmp r0, 2
  0x803c3d2 2 20d1 bne.n 0x803c416
  */
r6 = 0;
r1 = r6;
r0 = r4;
func_0x803afd0();;
  if (r0 == 2) {
  /*
    0x803c3d4 2 0025 movs r5, 0
    0x803c3d6 2 e846 mov r8, sp
  */
r5 = 0;
r8 = sp;
    while (r5 < 4) {
  /*
      0x803c3d8 4 04eb0510 add.w r0, r4, r5, lsl 4
      0x803c3dc 4 00f5fb70 add.w r0, r0, 502
      0x803c3e0 2 0179 ldrb r1, [r0, 4]
      0x803c3e2 2 19b1 cbz r1, 0x803c3ec
  */
r0 = r4 + (r5 << 4);
r0 = r0 + 502;
r1 = *( r0 + 4 );
      if (r1 != 0) {
  /*
        0x803c3e4 2 0830 adds r0, 8
        0x803c3e6 4 00f0e8fb bl 0x803cbba
        0x803c3ea 2 00e0 b.n 0x803c3ee
  */
r0 = r0 + 8;
func_0x803cbba();;
      } else {
  /*
        0x803c3ec 2 0020 movs r0, 0
  */
r0 = 0;
      }
  /*
      0x803c3ee 4 48f82500 str.w r0, [r8, r5, lsl 2]
      0x803c3f2 2 6d1c adds r5, r5, 1
      0x803c3f4 2 042d cmp r5, 4
      0x803c3f6 2 efd3 bcc.n 0x803c3d8
  */
*( r8 + r5 << lsl ) = r0;
r5 = r5 + 1;
      }
    }
  /*
    0x803c3f8 2 0025 movs r5, 0
  */
r5 = 0;
    while (1) {
  /*
    0x803c3fa 4 58f82560 ldr.w r6, [r8, r5, lsl 2]
    0x803c3fe 2 26b1 cbz r6, 0x803c40a
  */
r6 = *( r8 + r5 << 2 );
    if (r6 != 0) {
  /*
      0x803c400 2 3146 mov r1, r6
      0x803c402 2 2046 mov r0, r4
      0x803c404 4 fef7e4fd bl 0x803afd0
      0x803c408 2 00e0 b.n 0x803c40c
  */
r1 = r6;
r0 = r4;
func_0x803afd0();;
    } else {
  /*
      0x803c40a 2 0320 movs r0, 3
  */
r0 = 3;
    }
  /*
    0x803c40c 2 0228 cmp r0, 2
    0x803c40e 2 02d3 bcc.n 0x803c416
    0x803c410 2 6d1c adds r5, r5, 1
    0x803c412 2 042d cmp r5, 4
    0x803c414 2 f1d3 bcc.n 0x803c3fa
  */
r5 = r5 + 1;
    if (r0 < 2 && r5 >= 4) { break; }
  }
  /*
  0x803c416 2 0428 cmp r0, 4
  0x803c418 2 05d0 beq.n 0x803c426
  */
  if (r0 == 4) {
  /*
    0x803c426 2 04b0 add sp, 16
    0x803c428 2 0120 movs r0, 1
    0x803c42a 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 1;
    return 1;
  }

  /*
  0x803c41a 2 0228 cmp r0, 2
  0x803c41c 2 07d3 bcc.n 0x803c42e
  */
  if (r0 >= 2) {
  /*
    0x803c41e 2 04b0 add sp, 16
    0x803c420 2 0d20 movs r0, 13
    0x803c422 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
    return 13;
  }
  /*
  0x803c42e 4 04f14300 add.w r0, r4, 67
  0x803c432 4 00f0cdfb bl 0x803cbd0
  0x803c436 4 b0f5805f cmp.w r0, 4096
  0x803c43a 2 03d0 beq.n 0x803c444
  */
r0 = r4 + 67;
func_0x803cbd0();;
  if (r0 != 4096) {
  /*
    0x803c43c 2 04b0 add sp, 16
    0x803c43e 2 0d20 movs r0, 13
    0x803c440 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
    return 13;
  }
  /*
  0x803c444 4 04f14e00 add.w r0, r4, 78
  0x803c448 4 00f0c2fb bl 0x803cbd0
  0x803c44c 2 0146 mov r1, r0
  0x803c44e 2 21b9 cbnz r1, 0x803c45a
  */
r0 = r4 + 78;
func_0x803cbd0();;
r1 = r0;
  if (r1 == 0) {
  /*
    0x803c450 4 04f15c00 add.w r0, r4, 92
    0x803c454 4 00f0b1fb bl 0x803cbba
    0x803c458 2 0146 mov r1, r0
  */
r0 = r4 + 92;
func_0x803cbba();;
r1 = r0;
  }
  /*
  0x803c45a 2 2162 str r1, [r4, 32]
  0x803c45c 4 94f84800 ldrb.w r0, [r4, 72]
  0x803c460 2 a070 strb r0, [r4, 2]
  0x803c462 2 0128 cmp r0, 1
  0x803c464 2 05d0 beq.n 0x803c472
  0x803c466 2 0228 cmp r0, 2
  0x803c468 2 03d0 beq.n 0x803c472
  */
*( r4 + 32 ) = r1;
r0 = *( r4 + 72 );
*( r4 + 2 ) = r0;
  if (r0 != 1 || r0 != 2) {
  /*
    0x803c46a 2 04b0 add sp, 16
    0x803c46c 2 0d20 movs r0, 13
    0x803c46e 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
    return 13;
  }

  /*
  0x803c472 4 00fb01f8 mul.w r8, r0, r1
  0x803c476 4 94f84500 ldrb.w r0, [r4, 69]
  0x803c47a 2 6081 strh r0, [r4, 10]
  0x803c47c 2 10b1 cbz r0, 0x803c484
  */
r8 = r0 * r1;
r0 = *( r4 + 69 );
*( r4 + 10 ) = r0;

  /*
  0x803c47e 2 411e subs r1, r0, 1
  0x803c480 2 0842 tst r0, r1
  0x803c482 2 03d0 beq.n 0x803c48c
  */
r1 = r0 - 1;

  if (r0 == 0 && (r0 & r1)) {
  /*
    0x803c484 2 04b0 add sp, 16
    0x803c486 2 0d20 movs r0, 13
    0x803c488 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
    return 13;
  }

  /*
  0x803c48c 4 04f14900 add.w r0, r4, 73
  0x803c490 4 00f09efb bl 0x803cbd0
  0x803c494 2 2081 strh r0, [r4, 8]
  0x803c496 4 10f07f0f tst.w r0, 127
  0x803c49a 2 03d0 beq.n 0x803c4a4
  */
r0 = r4 + 73;
func_0x803cbd0();;
*( r4 + 8 ) = r0;
  if (r0 & 127) {
  /*
    0x803c49c 2 04b0 add sp, 16
    0x803c49e 2 0d20 movs r0, 13
    0x803c4a0 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
    return 13;
  }
  /*
  0x803c4a4 4 04f14b00 add.w r0, r4, 75
  0x803c4a8 4 00f092fb bl 0x803cbd0
  0x803c4ac 2 0546 mov r5, r0
  0x803c4ae 2 2800 movs r0, r5
  0x803c4b0 2 04d1 bne.n 0x803c4bc
  */
r0 = r4 + 75;
func_0x803cbd0();;
r5 = r0;
r0 = r5;
  if (r0 != 0) {
  /*
    0x803c4b2 4 04f15800 add.w r0, r4, 88
    0x803c4b6 4 00f080fb bl 0x803cbba
    0x803c4ba 2 0546 mov r5, r0
  */
r0 = r4 + 88;
func_0x803cbba();;
r5 = r0;
  }
  /*
  0x803c4bc 4 04f14600 add.w r0, r4, 70
  0x803c4c0 4 00f086fb bl 0x803cbd0
  0x803c4c4 2 0246 mov r2, r0
  0x803c4c6 2 52b1 cbz r2, 0x803c4de
  */
r0 = r4 + 70;
func_0x803cbd0();;
r2 = r0;
  if (r2 == 0) {
  /*
    0x803c4de 2 04b0 add sp, 16
    0x803c4e0 2 0d20 movs r0, 13
    0x803c4e2 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
    return 13;
  }

  /*
  0x803c4c8 2 2389 ldrh r3, [r4, 8]
  0x803c4ca 4 02eb0800 add.w r0, r2, r8
  0x803c4ce 4 00ebd311 add.w r1, r0, r3, lsr 7
  0x803c4d2 2 8d42 cmp r5, r1
  0x803c4d4 2 07d2 bcs.n 0x803c4e6
  */
r3 = *( r4 + 8 );
r0 = r2 + r8;
r1 = r0 + (r3 >> 7);
  if (r5 < r1) {
  /*
    0x803c4d6 2 04b0 add sp, 16
    0x803c4d8 2 0d20 movs r0, 13
    0x803c4da 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
    return 13;
  }
  /*
  0x803c4e6 4 b4f80ac0 ldrh.w ip, [r4, 10]
  0x803c4ea 2 681a subs r0, r5, r1
  0x803c4ec 4 b0fbfcf0 udiv r0, r0, ip
  0x803c4f0 2 78b3 cbz r0, 0x803c552
  */
ip = *( r4 + 10 );
r0 = r5 - r1;
r0 = r0 / ip;
  if (r0 == 0) {
  /*
    0x803c552 2 ffe7 b.n 0x803c554
    0x803c554 2 04b0 add sp, 16
    0x803c556 2 0d20 movs r0, 13
    0x803c558 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
    return 13;
  }
  /*
  0x803c4f2 2 0025 movs r5, 0
  0x803c4f4 4 dff830c1 mov ip, 0xffffff5
  0x803c4f8 2 6045 cmp r0, ip
  0x803c4fa 2 00d8 bhi.n 0x803c4fe
  */
r5 = 0;
ip = 0xffffff5;
  if (r0 <= ip) {
  /*
    0x803c4fc 2 0325 movs r5, 3
  */
r5 = 3;
  }
  /*
  0x803c4fe 4 4ff6f57c movw ip, 65525
  0x803c502 2 6045 cmp r0, ip
  0x803c504 2 00d8 bhi.n 0x803c508
  */
ip = 65525;
  if (r0 <= ip) {
  /*
    0x803c506 2 0225 movs r5, 2
  */
r5 = 2;
  }
  /*
  0x803c508 4 40f6f57c movw ip, 4085
  0x803c50c 2 6045 cmp r0, ip
  0x803c50e 2 00d8 bhi.n 0x803c512
  */
ip = 4085;
  if (r0 <= ip) {
  /*
    0x803c510 2 0125 movs r5, 1
  */
r5 = 1;
  }
  /*
  0x803c512 2 1db3 cbz r5, 0x803c55c
  */
  if (r5 == 0) {
  /*
      0x803c55c 2 04b0 add sp, 16
      0x803c55e 2 0d20 movs r0, 13
      0x803c560 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
      return 13;
  }
  /*
  0x803c514 2 801c adds r0, r0, 2
  0x803c516 2 e061 str r0, [r4, 28]
  0x803c518 2 6662 str r6, [r4, 36]
  0x803c51a 2 3244 add r2, r6
  0x803c51c 2 a262 str r2, [r4, 40]
  0x803c51e 2 3144 add r1, r6
  0x803c520 2 2163 str r1, [r4, 48]
  0x803c522 2 032d cmp r5, 3
  0x803c524 2 1ed0 beq.n 0x803c564
  */
r0 = r0 + 2;
*( r4 + 28 ) = r0;
*( r4 + 36 ) = r6;
r2 = r2 + r6;
*( r4 + 40 ) = r2;
r1 = r1 + r6;
*( r4 + 48 ) = r1;
  if (r5 == 3) {
    /*
    0x803c564 4 04f16200 add.w r0, r4, 98
    0x803c568 4 00f032fb bl 0x803cbd0
    0x803c56c 2 18b1 cbz r0, 0x803c576
    */
r0 = r4 + 98;
func_0x803cbd0();;
    if (r0 != 0) {
      /*
      0x803c56e 2 04b0 add sp, 16
      0x803c570 2 0d20 movs r0, 13
      0x803c572 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
      */
sp = sp + 16;
r0 = 13;
      return 13;
    }
    /*
    0x803c576 2 2089 ldrh r0, [r4, 8]
    0x803c578 2 18b1 cbz r0, 0x803c582
    */
r0 = *( r4 + 8 );
    if (r0 != 0) {
      /*
      0x803c57a 2 04b0 add sp, 16
      0x803c57c 2 0d20 movs r0, 13
      0x803c57e 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
      */
sp = sp + 16;
r0 = 13;
      return 13;
    }
    /*
    0x803c582 4 04f16400 add.w r0, r4, 100
    0x803c586 4 00f018fb bl 0x803cbba
    0x803c58a 2 e062 str r0, [r4, 44]
    0x803c58c 2 e069 ldr r0, [r4, 28]
    0x803c58e 2 8000 lsls r0, r0, 2
    0x803c590 2 d5e7 b.n 0x803c53e
    */
r0 = r4 + 100;
func_0x803cbba();;
*( r4 + 44 ) = r0;
r0 = *( r4 + 28 );
r0 = r0 << 2;
  } else {
    /*
    0x803c526 2 a3b3 cbz r3, 0x803c592
    */
    if (r3 == 0) {
      /*
      0x803c592 2 ffe7 b.n 0x803c594
      0x803c594 2 04b0 add sp, 16
      0x803c596 2 0d20 movs r0, 13
      0x803c598 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
      */
sp = sp + 16;
r0 = 13;
      return 13;
    }
    /*
    0x803c528 4 02eb0801 add.w r1, r2, r8
    0x803c52c 2 e162 str r1, [r4, 44]
    0x803c52e 2 022d cmp r5, 2
    0x803c530 2 34d0 beq.n 0x803c59c
    */
r1 = r2 + r8;
*( r4 + 44 ) = r1;
    if (r5 == 2) {
      /*
      0x803c59c 2 4000 lsls r0, r0, 1
      0x803c59e 2 cee7 b.n 0x803c53e
      */
r0 = r0 << 1;
    } else {
      /*
      0x803c532 4 00f00101 and.w r1, r0, 1
      0x803c536 4 00eb4000 add.w r0, r0, r0, lsl 1
      0x803c53a 4 01eb5000 add.w r0, r1, r0, lsr 1
      */
r1 = r0 & 1;
r0 = r0 + (r0 << 1);
r0 = r1 + (r0 >> 1);
    }
  }
  /*
  0x803c53e 2 216a ldr r1, [r4, 32]
  0x803c540 4 00f6ff70 addw r0, r0, 4095
  0x803c544 4 b1eb103f cmp.w r1, r0, lsr 12
  0x803c548 2 2ad2 bcs.n 0x803c5a0
  */
r1 = *( r4 + 32 );
r0 = r0 + 4095;
  if (r1 < r0) {
  /*
      0x803c54a 2 04b0 add sp, 16
      0x803c54c 2 0d20 movs r0, 13
      0x803c54e 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
sp = sp + 16;
r0 = 13;
      return 13;
  }
  /*
  0x803c5a0 4 4ff0ff30 mov.w r0, 4294967295
  0x803c5a4 2 6061 str r0, [r4, 20]
  0x803c5a6 2 2061 str r0, [r4, 16]
  0x803c5a8 2 8020 movs r0, 128
  0x803c5aa 2 2071 strb r0, [r4, 4]
  0x803c5ac 2 032d cmp r5, 3
  0x803c5ae 2 2bd1 bne.n 0x803c608
  */
r0 = 4294967295;
*( r4 + 20 ) = r0;
*( r4 + 16 ) = r0;
r0 = 128;
*( r4 + 4 ) = r0;
  cond0 = r5 == 3;
  /*
  0x803c5b0 4 04f16800 add.w r0, r4, 104
  0x803c5b4 4 00f00cfb bl 0x803cbd0
  0x803c5b8 2 0128 cmp r0, 1
  0x803c5ba 2 25d1 bne.n 0x803c608
  */
r0 = r4 + 104;
func_0x803cbd0();;
  cond1 = r0 == 1;
  /*
  0x803c5bc 2 711c adds r1, r6, 1
  0x803c5be 2 2046 mov r0, r4
  0x803c5c0 4 00f0c5fd bl 0x803d14e
  0x803c5c4 2 00bb cbnz r0, 0x803c608
  */
r1 = r6 + 1;
r0 = r4;
func_0x803d14e();;
  cond2 = r0 == 0;
  /*
  0x803c5c6 2 2771 strb r7, [r4, 4]
  0x803c5c8 4 04f23620 addw r0, r4, 566
  0x803c5cc 4 00f000fb bl 0x803cbd0
  0x803c5d0 4 a0f52a41 sub.w r1, r0, 43520
  0x803c5d4 2 5539 subs r1, 85
  0x803c5d6 2 17d1 bne.n 0x803c608
  */
*( r4 + 4 ) = r7;
r0 = r4 + 566;
func_0x803cbd0();;
r1 = r0 - 43520;
r1 = r1 - 85;
  cond3 = r1 == 0;
  /*
  0x803c5d8 4 04f13800 add.w r0, r4, 56
  0x803c5dc 4 00f0edfa bl 0x803cbba
  0x803c5e0 2 1249 mov r1, 0x41615252
  0x803c5e2 2 8842 cmp r0, r1
  0x803c5e4 2 10d1 bne.n 0x803c608
  */
r0 = r4 + 56;
func_0x803cbba();;
r1 = 0x41615252;
  cond4 = r0 == r1;
  /*
  0x803c5e6 4 04f50770 add.w r0, r4, 540
  0x803c5ea 4 00f0e6fa bl 0x803cbba
  0x803c5ee 2 1049 mov r1, 0x61417272
  0x803c5f0 2 8842 cmp r0, r1
  0x803c5f2 2 09d1 bne.n 0x803c608
  */
r0 = r4 + 540;
func_0x803cbba();;
r1 = 0x61417272;
  cond5 = r0 == r1;
  if (cond0 && cond1 && cond2 && cond3 && cond4 && cond5) {
  /*
    0x803c5f4 4 04f50870 add.w r0, r4, 544
    0x803c5f8 4 00f0dffa bl 0x803cbba
    0x803c5fc 2 6061 str r0, [r4, 20]
    0x803c5fe 4 04f50970 add.w r0, r4, 548
    0x803c602 4 00f0dafa bl 0x803cbba
    0x803c606 2 2061 str r0, [r4, 16]
  */
r0 = r4 + 544;
func_0x803cbba();;
*( r4 + 20 ) = r0;
r0 = r4 + 548;
func_0x803cbba();;
*( r4 + 16 ) = r0;
  }
  /*
  0x803c608 2 2570 strb r5, [r4, 0]
  0x803c60a 2 0a49 mov r1, 0x20001e64
  0x803c60c 2 0888 ldrh r0, [r1, 0]
  0x803c60e 2 401c adds r0, r0, 1
  0x803c610 2 0880 strh r0, [r1, 0]
  0x803c612 2 e080 strh r0, [r4, 6]
  0x803c614 2 0848 mov r0, 0x20018b78
  0x803c616 2 e060 str r0, [r4, 12]
  0x803c618 2 a761 str r7, [r4, 24]
  0x803c61a 2 04b0 add sp, 16
  0x803c61c 2 0020 movs r0, 0
  0x803c61e 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
*( r4 + 0 ) = r5;
r1 = 0x20001e64;
r0 = *( r1 + 0 );
r0 = r0 + 1;
*( r1 + 0 ) = r0;
*( r4 + 6 ) = r0;
r0 = 0x20018b78;
*( r4 + 12 ) = r0;
*( r4 + 24 ) = r7;
sp = sp + 16;
r0 = 0;
  return 0;
}
