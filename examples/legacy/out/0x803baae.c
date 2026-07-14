void func_0x803baae(int p1, int p2) {
  /*
  0x803baae 4 2de9f84f stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, lr}
  0x803bab2 2 0446 mov r4, p1
  0x803bab4 2 0d46 mov r5, p2
  0x803bab6 2 6946 mov r1, sp
  0x803bab8 2 2046 mov r0, r4
  0x803baba 4 01f01ffe bl 0x803d6fc
  0x803babe 2 8046 mov r8, r0
  0x803bac0 4 5fea0800 movs.w r0, r8
  0x803bac4 2 01d1 bne.n 0x803baca
  */
  if (r0 == 0) {
    /*
    0x803bac6 4 94f81180 ldrb.w r8, [r4, 17]
    */
  }
  /*
  0x803baca 4 b8f1000f cmp.w r8, 0
  0x803bace 2 02d0 beq.n 0x803bad6
  */
  if (r8 != 0) {
    /*
    0x803bad0 2 4046 mov r0, r8
    0x803bad2 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
    */
    return;
  }
  /*
  0x803bad6 2 e068 ldr r0, [r4, 12]
  0x803bad8 2 a842 cmp r0, r5
  0x803bada 2 04d2 bcs.n 0x803bae6
  */
  /*
  0x803badc 2 217c ldrb r1, [r4, 16]
  0x803bade 4 11f0020f tst.w r1, 2
  0x803bae2 2 00d1 bne.n 0x803bae6
  */
  if (r0 < r5 && ~(r1 & 2)) {
    /*
    0x803bae4 2 0546 mov r5, r0
    */
  }
  /*
  0x803bae6 2 6069 ldr r0, [r4, 20]
  0x803bae8 2 0027 movs r7, 0
  0x803baea 2 6761 str r7, [r4, 20]
  0x803baec 4 4ff00109 mov.w r9, 1
  0x803baf0 2 002d cmp r5, 0
  0x803baf2 2 65d0 beq.n 0x803bbc0
  */
  if (r5 != 0) {
    /*
    0x803baf4 2 0099 ldr r1, [sp, 0]
    0x803baf6 2 4989 ldrh r1, [r1, 10]
    0x803baf8 2 0e03 lsls r6, r1, 12
    0x803bafa 4 4ff0020a mov.w sl, 2
    0x803bafe 2 68b1 cbz r0, 0x803bb1c
    */
    cond0 = r0 != 0;
    /*
    0x803bb00 2 691e subs r1, r5, 1
    0x803bb02 2 401e subs r0, r0, 1
    0x803bb04 4 b1fbf6f1 udiv r1, r1, r6
    0x803bb08 4 b0fbf6f2 udiv r2, r0, r6
    0x803bb0c 2 9142 cmp r1, r2
    0x803bb0e 2 05d3 bcc.n 0x803bb1c
    */
    cond1 = r1 >= r2;
    if (cond0 && cond1) {
      /*
      0x803bb10 2 711e subs r1, r6, 1
      0x803bb12 2 8843 bics r0, r1
      0x803bb14 2 6061 str r0, [r4, 20]
      0x803bb16 2 2d1a subs r5, r5, r0
      0x803bb18 2 a169 ldr r1, [r4, 24]
      0x803bb1a 2 0de0 b.n 0x803bb38
      */
    } else {
      /*
      0x803bb1c 2 a168 ldr r1, [r4, 8]
      0x803bb1e 2 51b9 cbnz r1, 0x803bb36
      */
      if (r1 == 0) {
        /*
        0x803bb20 2 0021 movs r1, 0
        0x803bb22 2 2046 mov r0, r4
        0x803bb24 4 fff7f4fa bl 0x803b110
        0x803bb28 2 0146 mov r1, r0
        0x803bb2a 2 0129 cmp r1, 1
        0x803bb2c 2 15d0 beq.n 0x803bb5a
        */
        if (r1 == 1) {
          /*
          0x803bb5a 4 84f811a0 strb.w sl, [r4, 17]
          0x803bb5e 2 0220 movs r0, 2
          0x803bb60 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
          */
          return;
        }
        /*
        0x803bb2e 4 b1f1ff3f cmp.w r1, 4294967295
        0x803bb32 2 17d0 beq.n 0x803bb64
        */
        if (r1 == -1) {
          /*
          0x803bb64 4 84f81190 strb.w r9, [r4, 17]
          0x803bb68 2 0120 movs r0, 1
          0x803bb6a 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
          */
          return;
        }
        /*
        0x803bb34 2 a160 str r1, [r4, 8]
        */
      }
      /*
      0x803bb36 2 a161 str r1, [r4, 24]
      */
    }
    /*
    0x803bb38 2 91b3 cbz r1, 0x803bba0
    */
    if (r1 != 0) {
      /*
      0x803bb3a 2 b542 cmp r5, r6
      0x803bb3c 2 34d9 bls.n 0x803bba8
      */
      if (r5 > r6) {
        while (1) {
          /*
          0x803bb3e 2 ad1b subs r5, r5, r6
          0x803bb40 2 6069 ldr r0, [r4, 20]
          0x803bb42 2 3044 add r0, r6
          0x803bb44 2 6061 str r0, [r4, 20]
          0x803bb46 2 207c ldrb r0, [r4, 16]
          0x803bb48 4 10f0020f tst.w r0, 2
          0x803bb4c 2 11d0 beq.n 0x803bb72
          */
          if (r0 & 2) {
            /*
            0x803bb4e 2 2046 mov r0, r4
            0x803bb50 4 fff7defa bl 0x803b110
            0x803bb54 2 0146 mov r1, r0
            0x803bb56 2 51b1 cbz r1, 0x803bb6e
            */
            if (r1 == 0) {
              /*
              0x803bb6e 2 0025 movs r5, 0
              0x803bb70 2 1ae0 b.n 0x803bba8
              */
              break;
            }
            /*
            0x803bb58 2 0fe0 b.n 0x803bb7a
            */
          } else {
            /*
            0x803bb72 2 2046 mov r0, r4
            0x803bb74 4 00f00cfe bl 0x803c790
            0x803bb78 2 0146 mov r1, r0
            */
          }
          /*
          0x803bb7a 4 b1f1ff3f cmp.w r1, 4294967295
          0x803bb7e 2 0ad0 beq.n 0x803bb96
          */
          if (r1 == -1) {
            /*
            0x803bb96 4 84f81190 strb.w r9, [r4, 17]
            0x803bb9a 2 0120 movs r0, 1
            0x803bb9c 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
            */
            return;
          }
          /*
          0x803bb80 2 0129 cmp r1, 1
          0x803bb82 2 03d9 bls.n 0x803bb8c
          */
          cond0 = r1 <= 1;
          /*
          0x803bb84 2 0098 ldr r0, [sp, 0]
          0x803bb86 2 c069 ldr r0, [r0, 28]
          0x803bb88 2 8842 cmp r0, r1
          0x803bb8a 2 0ad8 bhi.n 0x803bba2
          */
          cond1 = r0 <= r1;
          if (cond0 || cond1) {
            /*
            0x803bb8c 4 84f811a0 strb.w sl, [r4, 17]
            0x803bb90 2 0220 movs r0, 2
            0x803bb92 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
            */
            return;
          }
          /*
          0x803bba2 2 a161 str r1, [r4, 24]
          0x803bba4 2 b542 cmp r5, r6
          0x803bba6 2 cad8 bhi.n 0x803bb3e
          */
          if (r5 <= r6) { break; }
        }
      }
      /*
      0x803bba8 2 6069 ldr r0, [r4, 20]
      0x803bbaa 2 2844 add r0, r5
      0x803bbac 2 6061 str r0, [r4, 20]
      0x803bbae 2 2805 lsls r0, r5, 20
      0x803bbb0 2 000d lsrs r0, r0, 20
      0x803bbb2 2 05d0 beq.n 0x803bbc0
      */
      if (r0 != 0) {
        /*
        0x803bbb4 2 0098 ldr r0, [sp, 0]
        0x803bbb6 4 fff74dfa bl 0x803b054
        0x803bbba 2 08b3 cbz r0, 0x803bc00
        */
        if (r0 == 0) {
          /*
          0x803bc00 4 84f811a0 strb.w sl, [r4, 17]
          0x803bc04 2 0220 movs r0, 2
          0x803bc06 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
          */
          return;
        }
        /*
        0x803bbbc 4 00eb1537 add.w r7, r0, r5, lsr 12
        */
      }
    } else {
      /*
      0x803bba0 2 0ee0 b.n 0x803bbc0
      */
    }
  }
  /*
  0x803bbc0 2 e168 ldr r1, [r4, 12]
  0x803bbc2 2 6069 ldr r0, [r4, 20]
  0x803bbc4 2 8842 cmp r0, r1
  0x803bbc6 2 04d9 bls.n 0x803bbd2
  */
  if (r0 > r1) {
    /*
    0x803bbc8 2 e060 str r0, [r4, 12]
    0x803bbca 2 217c ldrb r1, [r4, 16]
    0x803bbcc 4 41f04001 orr.w r1, r1, 64
    0x803bbd0 2 2174 strb r1, [r4, 16]
    */
  }
  /*
  0x803bbd2 2 0005 lsls r0, r0, 20
  0x803bbd4 2 000d lsrs r0, r0, 20
  0x803bbd6 2 2bd0 beq.n 0x803bc30
  */
  if (r0 == 0) {
    /*
    0x803bc30 2 4046 mov r0, r8
    0x803bc32 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
    */
    return;
  }
  /*
  0x803bbd8 2 e269 ldr r2, [r4, 28]
  0x803bbda 2 ba42 cmp r2, r7
  0x803bbdc 2 28d0 beq.n 0x803bc30
  */
  if (r2 == r7) {
    /*
    0x803bc30 2 4046 mov r0, r8
    0x803bc32 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
    */
    return;
  }
  /*
  0x803bbde 2 207c ldrb r0, [r4, 16]
  0x803bbe0 4 10f0800f tst.w r0, 128
  0x803bbe4 2 15d0 beq.n 0x803bc12
  */
  if (r0 & 128) {
    /*
    0x803bbe6 2 0098 ldr r0, [sp, 0]
    0x803bbe8 2 0123 movs r3, 1
    0x803bbea 4 04f12801 add.w r1, r4, 40
    0x803bbee 2 4078 ldrb r0, [r0, 1]
    0x803bbf0 4 fff745ff bl 0x803ba7e
    0x803bbf4 2 48b1 cbz r0, 0x803bc0a
    */
    if (r0 != 0) {
      /*
      0x803bbf6 4 84f81190 strb.w r9, [r4, 17]
      0x803bbfa 2 0120 movs r0, 1
      0x803bbfc 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
      */
      return;
    }
    /*
    0x803bc0a 2 207c ldrb r0, [r4, 16]
    0x803bc0c 4 00f07f00 and.w r0, r0, 127
    0x803bc10 2 2074 strb r0, [r4, 16]
    */
  }
  /*
  0x803bc12 2 0098 ldr r0, [sp, 0]
  0x803bc14 2 0123 movs r3, 1
  0x803bc16 2 3a46 mov r2, r7
  0x803bc18 2 4078 ldrb r0, [r0, 1]
  0x803bc1a 4 04f12801 add.w r1, r4, 40
  0x803bc1e 4 fff724ff bl 0x803ba6a
  0x803bc22 2 20b1 cbz r0, 0x803bc2e
  */
  if (r0 != 0) {
    /*
    0x803bc24 4 84f81190 strb.w r9, [r4, 17]
    0x803bc28 2 0120 movs r0, 1
    0x803bc2a 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
    */
    return;
  }
  /*
  0x803bc2e 2 e761 str r7, [r4, 28]
  */
  /*
  0x803bc30 2 4046 mov r0, r8
  0x803bc32 4 bde8f88f ldmia.w sp!, {r3, r4, r5, r6, r7, r8, r9, sl, fp, pc}
  */
  return;
}

