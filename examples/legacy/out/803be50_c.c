int func_0x803be50(int * p1, int p2, int p3, int * p4) {
  /*
     0x803be50 4 2de9f84f stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, lr}
     0x803be54 2 0446 mov r4, r0
     0x803be56 2 8846 mov r8, r1
     0x803be58 2 1646 mov r6, r2
     0x803be5a 2 9946 mov r9, r3
     0x803be5c 2 0020 movs r0, 0
     0x803be5e 4 c9f80000 str.w r0, [r9]
     0x803be62 2 6946 mov r1, sp
     0x803be64 2 2046 mov r0, r4
     0x803be66 4 01f049fc bl 0x803d6fc
     0x803be6a 2 0028 cmp r0, 0
     0x803be6c 2 16d1 bne.n 0x803be9c
     0x803be6e 2 607c ldrb r0, [r4, 17]
     0x803be70 2 0028 cmp r0, 0
     0x803be72 2 13d1 bne.n 0x803be9c
     */
  r4 = p1;
  r8 = p2;
  r6 = p3;
  r9 = p4;
  r0 = 0;
  *( r9 ) = r0;
  r1 = sp;
  r0 = r4;
  r0 = func_0x803d6fc(r4, sp);
  cond1 = func_0x803d6fc(r4, sp) == 0;
  r0 = *( r4 + 17 );
  cond0 = *( r4 + 17 ) == 0;
  if (cond1 || cond0) {
    /*
       0x803be9c 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
       */
    return p1;
  }

  /*
     0x803be74 2 207c ldrb r0, [r4, 16]
     0x803be76 4 10f0010f tst.w r0, 1
     0x803be7a 2 0ed0 beq.n 0x803be9a
     */
  r0 = *( r4 + 16 );
  if (~(r0 & 1)) {
    /*
       0x803be9a 2 0720 movs r0, 7
       0x803be9c 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
       */
    r0 = 7;
    return;
  }
  /*
     0x803be7c 2 6169 ldr r1, [r4, 20]
     0x803be7e 2 e068 ldr r0, [r4, 12]
     0x803be80 2 401a subs r0, r0, r1
     0x803be82 2 8642 cmp r6, r0
     0x803be84 2 00d9 bls.n 0x803be88
     */
  r1 = *( r4 + 20 );
  r0 = *( r4 + 12 );
  r0 = r0 - r1;
  if (r6 > r0) {
    /*
       0x803be86 2 0646 mov r6, r0
       */
    r6 = r0;
  }
  /*
     0x803be88 2 002e cmp r6, 0
     0x803be8a 2 7dd0 beq.n 0x803bf88
     */
  if (r6 == 0) {
    /*
       0x803bf88 2 1de0 b.n 0x803bfc6
       0x803bfc6 2 0020 movs r0, 0
       0x803bfc8 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
       */
    r0 = 0;
    return;
  }

  /*
     0x803be8c 4 4ff0010a mov.w sl, 1
     */
  sl = 1;
  while (1) {
    /*
       0x803be90 2 6069 ldr r0, [r4, 20]
       0x803be92 2 0105 lsls r1, r0, 20
       0x803be94 2 090d lsrs r1, r1, 20
       0x803be96 2 03d0 beq.n 0x803bea0
       */
    r0 = *( r4 + 20 );
    r1 = r0 << 20;
    r1 = r1 >> 20;
    if (r1 == 0) {
      /*
         0x803bea0 2 0099 ldr r1, [sp, 0]
         0x803bea2 2 4989 ldrh r1, [r1, 10]
         0x803bea4 2 491e subs r1, r1, 1
         0x803bea6 4 01ea1037 and.w r7, r1, r0, lsr 12
         0x803beaa 2 87b9 cbnz r7, 0x803bece
         */
      r1 = *( sp + 0 );
      r1 = *( r1 + 10 );
      r1 = r1 - 1;
      r7 = r1 & (r0 >> 12);
      if (r7 == 0) {
        /*
           0x803beac 2 48b1 cbz r0, 0x803bec2
           */
        if (r0 == 0) {
          /*
             0x803bec2 2 a068 ldr r0, [r4, 8]
             0x803bec4 2 f7e7 b.n 0x803beb6
             */
          r0 = *( r4 + 8 );
        } else {
          /*
             0x803beae 2 2046 mov r0, r4
             0x803beb0 2 a169 ldr r1, [r4, 24]
             0x803beb2 4 00f06dfc bl 0x803c790
             */
          r0 = r4;
          r1 = *( r4 + 24 );
          func_0x803c790();;
        }
        /*
           0x803beb6 2 0228 cmp r0, 2
           0x803beb8 2 05d2 bcs.n 0x803bec6
           */
        if (r0 < 2) {
          /*
             0x803beba 2 0220 movs r0, 2
             0x803bebc 2 6074 strb r0, [r4, 17]
             0x803bebe 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
             */
          r0 = 2;
          *( r4 + 17 ) = r0;
          return;
        }
        /*
           0x803bec6 4 b0f1ff3f cmp.w r0, 4294967295
           0x803beca 2 1bd0 beq.n 0x803bf04
           */
        if (r0 == -1) {
          /*
             0x803bf04 4 84f811a0 strb.w sl, [r4, 17]
             0x803bf08 2 0120 movs r0, 1
             0x803bf0a 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
             */
          *( r4 + 17 ) = sl;
          r0 = 1;
          return;
        }
        /*
           0x803becc 2 a061 str r0, [r4, 24]
           */
        *( r4 + 24 ) = r0;
      }

      /*
         0x803bece 2 a169 ldr r1, [r4, 24]
         0x803bed0 2 0098 ldr r0, [sp, 0]
         0x803bed2 4 fff7bff8 bl 0x803b054
         0x803bed6 2 d0b1 cbz r0, 0x803bf0e
         */
      r1 = *( r4 + 24 );
      r0 = *( sp + 0 );
      func_0x803b054();;
      if (r0 == 0) {
        /*
           0x803bf0e 2 0220 movs r0, 2
           0x803bf10 2 6074 strb r0, [r4, 17]
           0x803bf12 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
           */
        r0 = 2;
        *( r4 + 17 ) = r0;
      }
      /*
         0x803bed8 4 00eb070b add.w fp, r0, r7
         0x803bedc 2 350b lsrs r5, r6, 12
         0x803bede 2 6db3 cbz r5, 0x803bf3c
         */
      fp = r0 + r7;
      r5 = r6 >> 12;
      if (r5 == 0) {
        /*
           0x803bf3c 2 e269 ldr r2, [r4, 28]
           0x803bf3e 2 5a45 cmp r2, fp
           0x803bf40 2 23d0 beq.n 0x803bf8a
           */
        r2 = *( r4 + 28 );
        if (r2 != fp) {
          /*
             0x803bf42 2 207c ldrb r0, [r4, 16]
             0x803bf44 4 10f0800f tst.w r0, 128
             0x803bf48 2 10d0 beq.n 0x803bf6c
             */
          r0 = *( r4 + 16 );
          if (r0 & 128) {
            /*
               0x803bf4a 2 0098 ldr r0, [sp, 0]
               0x803bf4c 2 0123 movs r3, 1
               0x803bf4e 4 04f12801 add.w r1, r4, 40
               0x803bf52 2 4078 ldrb r0, [r0, 1]
               0x803bf54 4 fff793fd bl 0x803ba7e
               0x803bf58 2 20b1 cbz r0, 0x803bf64
               */
            r0 = *( sp + 0 );
            r3 = 1;
            r1 = r4 + 40;
            r0 = *( r0 + 1 );
            func_0x803ba7e();;
            if (r0 != 0) {
              /*
                 0x803bf5a 4 84f811a0 strb.w sl, [r4, 17]
                 0x803bf5e 2 0120 movs r0, 1
                 0x803bf60 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
                 */
              *( r4 + 17 ) = sl;
              r0 = 1;
              return;
            }
            /*
               0x803bf64 2 207c ldrb r0, [r4, 16]
               0x803bf66 4 00f07f00 and.w r0, r0, 127
               0x803bf6a 2 2074 strb r0, [r4, 16]
               */
            r0 = *( r4 + 16 );
            r0 = r0 & 127;
            *( r4 + 16 ) = r0;
          }
          /*
             0x803bf6c 2 0098 ldr r0, [sp, 0]
             0x803bf6e 2 0123 movs r3, 1
             0x803bf70 2 5a46 mov r2, fp
             0x803bf72 2 4078 ldrb r0, [r0, 1]
             0x803bf74 4 04f12801 add.w r1, r4, 40
             0x803bf78 4 fff777fd bl 0x803ba6a
             0x803bf7c 2 28b1 cbz r0, 0x803bf8a
             */
          r0 = *( sp + 0 );
          r3 = 1;
          r2 = fp;
          r0 = *( r0 + 1 );
          r1 = r4 + 40;
          r0 = func_0x803ba6a(r0, r1, r2, r3);
          if (r0 == 0) {
            /*
               0x803bf7e 4 84f811a0 strb.w sl, [r4, 17]
               0x803bf82 2 0120 movs r0, 1
               0x803bf84 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
               */
            *( r4 + 17 ) = sl;
            r0 = 1;
            return;
          }
        }
        /*
           0x803bf8a 4 c4f81cb0 str.w fp, [r4, 28]
           */
        *( r4 + 28 ) = fp;
      } else {
        /*
           0x803bee0 2 0098 ldr r0, [sp, 0]
           0x803bee2 2 7a19 adds r2, r7, r5
           0x803bee4 2 4189 ldrh r1, [r0, 10]
           0x803bee6 2 8a42 cmp r2, r1
           0x803bee8 2 00d9 bls.n 0x803beec
           */
        r0 = *( sp + 0 );
        r2 = r7 + r5;
        r1 = *( r0 + 10 );
        if (r2 > r1) {
          /*
             0x803beea 2 cd1b subs r5, r1, r7
             */
          r5 = r1 - r7;
        }
        /*
           0x803beec 2 4078 ldrb r0, [r0, 1]
           0x803beee 2 2b46 mov r3, r5
           0x803bef0 2 5a46 mov r2, fp
           0x803bef2 2 4146 mov r1, r8
           0x803bef4 4 fff7b9fd bl 0x803ba6a
           0x803bef8 2 68b1 cbz r0, 0x803bf16
           */
        r0 = *( r0 + 1 );
        r3 = r5;
        r2 = fp;
        r1 = r8;
        func_0x803ba6a();;
        if (r0 != 0) {
          /*
             0x803befa 4 84f811a0 strb.w sl, [r4, 17]
             0x803befe 2 0120 movs r0, 1
             0x803bf00 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
             */
          *( r4 + 17 ) = sl;
          r0 = 1;
        }
        /*
           0x803bf16 2 207c ldrb r0, [r4, 16]
           0x803bf18 4 10f0800f tst.w r0, 128
           0x803bf1c 2 0cd0 beq.n 0x803bf38
           */
        r0 = *( r4 + 16 );
        if (~(r0 & 128)) {
          /*
             0x803bf1e 2 e069 ldr r0, [r4, 28]
             0x803bf20 4 a0eb0b00 sub.w r0, r0, fp
             0x803bf24 2 a842 cmp r0, r5
             0x803bf26 2 07d2 bcs.n 0x803bf38
             */
          r0 = *( r4 + 28 );
          r0 = r0 - fp;
          if (r0 < r5) {
            /*
               0x803bf28 4 08eb0030 add.w r0, r8, r0, lsl 12
               0x803bf2c 4 4ff48052 mov.w r2, 4096
               0x803bf30 4 04f12801 add.w r1, r4, 40
               0x803bf34 4 01f0fcf8 bl 0x803d130
               */
            r0 = r8 + (r0 << 12);
            r2 = 4096;
            r1 = r4 + 40;
            func_0x803d130(r0,r1,r2);
          }
        }
        /*
           0x803bf38 2 2d03 lsls r5, r5, 12
           0x803bf3a 2 37e0 b.n 0x803bfac
           0x803bfac 2 761b subs r6, r6, r5
           0x803bfae 4 d9f80000 ldr.w r0, [r9]
           0x803bfb2 2 2844 add r0, r5
           0x803bfb4 4 c9f80000 str.w r0, [r9]
           0x803bfb8 2 a844 add r8, r5
           0x803bfba 2 6069 ldr r0, [r4, 20]
           0x803bfbc 2 2844 add r0, r5
           0x803bfbe 2 6061 str r0, [r4, 20]
           0x803bfc0 2 002e cmp r6, 0
           0x803bfc2 4 7ff465af bne.w 0x803be90
           */
        r5 = r5 << 12;
        r6 = r6 - r5;
        r0 = *( r9 );
        r0 = r0 + r5;
        *( r9 ) = r0;
        r8 = r8 + r5;
        r0 = *( r4 + 20 );
        r0 = r0 + r5;
        *( r4 + 20 ) = r0;
        if (r6 == 0) { 
          break;
        }
      }
    } else {
      /*
         0x803be98 2 79e0 b.n 0x803bf8e
         */
    }
    /*
       0x803bf8e 2 a08a ldrh r0, [r4, 20]
       0x803bf90 4 c0f30b00 ubfx r0, r0, 0, 12
       0x803bf94 4 c0f58055 rsb r5, r0, 4096
       0x803bf98 2 b542 cmp r5, r6
       0x803bf9a 2 00d9 bls.n 0x803bf9e
       */
    r0 = *( r4 + 20 );
    r0 = r0 & 0xfff;
    r5 = r0 - 4096;
    if (r5 > r6) {
      /*
         0x803bf9c 2 3546 mov r5, r6
         */
      r5 = r6;
    }
    /*
       0x803bf9e 2 2044 add r0, r4
       0x803bfa0 4 00f12801 add.w r1, r0, 40
       0x803bfa4 2 2a46 mov r2, r5
       0x803bfa6 2 4046 mov r0, r8
       0x803bfa8 4 01f0c2f8 bl 0x803d130
       */
    r0 = r0 + r4;
    r1 = r0 + 40;
    r2 = r5;
    r0 = r8;
    func_0x803d130();;
    /*
       0x803bfac 2 761b subs r6, r6, r5
       0x803bfae 4 d9f80000 ldr.w r0, [r9]
       0x803bfb2 2 2844 add r0, r5
       0x803bfb4 4 c9f80000 str.w r0, [r9]
       0x803bfb8 2 a844 add r8, r5
       0x803bfba 2 6069 ldr r0, [r4, 20]
       0x803bfbc 2 2844 add r0, r5
       0x803bfbe 2 6061 str r0, [r4, 20]
       0x803bfc0 2 002e cmp r6, 0
       0x803bfc2 4 7ff465af bne.w 0x803be90
       */
    r6 = r6 - r5;
    r0 = *( r9 );
    r0 = r0 + r5;
    *( r9 ) = r0;
    r8 = r8 + r5;
    r0 = *( r4 + 20 );
    r0 = r0 + r5;
    *( r4 + 20 ) = r0;
    if (r6 == 0) { 
      break;
    }
  }
  /*
     0x803bfc6 2 0020 movs r0, 0
     0x803bfc8 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
     */
  r0 = 0;
  return;
} 
