int func_0x803b110 (int p1, int p2) {
  /*
  0x803b110 4 2de9f041 stmdb sp!, {r4, r5, r6, r7, r8, lr}
  0x803b114 2 8046 mov r8, r0
  0x803b116 2 0f46 mov r7, r1
  0x803b118 4 d8f80050 ldr.w r5, [r8]
  0x803b11c 2 002f cmp r7, 0
  0x803b11e 2 08d0 beq.n 0x803b132
  */
  if (r7 != 0) {
  /*
    0x803b120 2 3946 mov r1, r7
    0x803b122 2 4046 mov r0, r8
    0x803b124 4 01f034fb bl 0x803c790
    0x803b128 2 0228 cmp r0, 2
    0x803b12a 2 09d2 bcs.n 0x803b140
  */
    if (r0 > 2) {
  /*
      0x803b12c 2 0120 movs r0, 1
      0x803b12e 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
      return 1;
    }
  /*
    0x803b140 4 b0f1ff3f cmp.w r0, 4294967295
    0x803b144 2 f3d0 beq.n 0x803b12e
    0x803b146 2 e969 ldr r1, [r5, 28]
    0x803b148 2 8142 cmp r1, r0
    0x803b14a 2 f0d8 bhi.n 0x803b12e
  */
    if (r0 == -1 || r1 > r0) {
  /*
      0x803b12e 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
      return r0;
    }
  /*
    0x803b14c 2 3e46 mov r6, r7
  */
  } else {
  /*
    0x803b132 2 2e69 ldr r6, [r5, 16]
    0x803b134 2 16b1 cbz r6, 0x803b13c
    0x803b136 2 e869 ldr r0, [r5, 28]
    0x803b138 2 b042 cmp r0, r6
    0x803b13a 2 08d8 bhi.n 0x803b14e
    0x803b13c 2 0126 movs r6, 1
    0x803b13e 2 06e0 b.n 0x803b14e
  */
  }
  /*
  0x803b14e 2 6869 ldr r0, [r5, 20]
  0x803b150 2 d8b1 cbz r0, 0x803b18a
  */
  if (r0 == 0) {
  /*
    0x803b18a 2 0020 movs r0, 0
    0x803b18c 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
  }
  /*
  0x803b152 2 0024 movs r4, 0
  0x803b154 2 be42 cmp r6, r7
  0x803b156 2 16d1 bne.n 0x803b186
  */
  if (r6 == r7) {
  /*
    0x803b158 2 741c adds r4, r6, 1
    0x803b15a 2 e869 ldr r0, [r5, 28]
    0x803b15c 2 a042 cmp r0, r4
    0x803b15e 2 00d8 bhi.n 0x803b162
  */
    if (r0 <= r4) {
  /*
      0x803b160 2 0224 movs r4, 2
  */
    }
  }
  /*
  0x803b162 2 2146 mov r1, r4
  0x803b164 2 4046 mov r0, r8
  0x803b166 4 01f013fb bl 0x803c790
  0x803b16a 2 0128 cmp r0, 1
  0x803b16c 2 dfd0 beq.n 0x803b12e
  0x803b16e 4 b0f1ff3f cmp.w r0, 4294967295
  0x803b172 2 dcd0 beq.n 0x803b12e
  */
  if (r0 == 1 || r0 == -1) {
  /*
    0x803b12e 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
    return r0;
  }
  /*
  0x803b174 2 38b1 cbz r0, 0x803b186
  */
  if (r0 != 0) {
  /*
    0x803b176 2 2869 ldr r0, [r5, 16]
    0x803b178 2 0228 cmp r0, 2
    0x803b17a 2 03d3 bcc.n 0x803b184
  */
    if (r0 >= 2) {
  /*
      0x803b17c 2 e969 ldr r1, [r5, 28]
      0x803b17e 2 8142 cmp r1, r0
      0x803b180 2 00d9 bls.n 0x803b184
  */
      if (r0 > r0) {
  /*
        0x803b182 2 0646 mov r6, r0
  */
      }
    }
  /*
    0x803b184 2 0024 movs r4, 0
  */
  }
  /*
  0x803b186 2 1cb1 cbz r4, 0x803b190
  */
  if (r4 != 0) {
  /*
    0x803b188 2 1ce0 b.n 0x803b1c4
  */
  } else {
  /*
    0x803b190 2 3446 mov r4, r6
  */
    while (1) {
  /*
      0x803b192 2 641c adds r4, r4, 1
      0x803b194 2 e869 ldr r0, [r5, 28]
      0x803b196 2 a042 cmp r0, r4
      0x803b198 2 05d8 bhi.n 0x803b1a6
  */
      if  (r0 <= r4) {
  /*
        0x803b19a 2 0224 movs r4, 2
        0x803b19c 2 022e cmp r6, 2
        0x803b19e 2 02d2 bcs.n 0x803b1a6
  */
        if (r6 < 2) {
  /*
          0x803b1a0 2 0020 movs r0, 0
          0x803b1a2 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
          return 0;
        }
      }
  /*
      0x803b1a6 2 2146 mov r1, r4
      0x803b1a8 2 4046 mov r0, r8
      0x803b1aa 4 01f0f1fa bl 0x803c790
      0x803b1ae 2 48b1 cbz r0, 0x803b1c4
  */
      if (r0 != 0) {
  /*
        0x803b1b0 2 0128 cmp r0, 1
        0x803b1b2 2 f6d0 beq.n 0x803b1a2
  */
        if (r0 == 1 || r0 == -1) {
  /*
          0x803b1a2 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
          return r0;
        }
  /*
        0x803b1ba 2 b442 cmp r4, r6
        0x803b1bc 2 e9d1 bne.n 0x803b192
  */
        if (r4 == r6) { 
  /*
          0x803b1be 2 0020 movs r0, 0
          0x803b1c0 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
          return 0;
        }
      } else {
        break;
      }
    }
  }
  /*
  0x803b1c4 4 4ff0ff32 mov.w r2, 4294967295
  0x803b1c8 2 2146 mov r1, r4
  0x803b1ca 2 2846 mov r0, r5
  0x803b1cc 4 01f0f9ff bl 0x803d1c2
  0x803b1d0 2 28b9 cbnz r0, 0x803b1de
  0x803b1d2 2 27b1 cbz r7, 0x803b1de
  */
  if (r0 == 0 && r7 != 0) {
  /*
    0x803b1d4 2 2246 mov r2, r4
    0x803b1d6 2 3946 mov r1, r7
    0x803b1d8 2 2846 mov r0, r5
    0x803b1da 4 01f0f2ff bl 0x803d1c2
  */
  }
  /*
  0x803b1de 2 28b1 cbz r0, 0x803b1ec
  */
  if (r0 != 0) {
  /*
    0x803b1e0 2 0128 cmp r0, 1
    0x803b1e2 2 10d0 beq.n 0x803b206
  */
    if (r0 != 1) {
  /*
      0x803b1e4 2 0124 movs r4, 1
  */
    } else {
  /*
      0x803b206 4 4ff0ff34 mov.w r4, 4294967295
      0x803b20a 2 ece7 b.n 0x803b1e6
  */
    }
  /*
    0x803b1e6 2 2046 mov r0, r4
    0x803b1e8 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
    return r4;
  }
  /*
  0x803b1ec 2 2c61 str r4, [r5, 16]
  0x803b1ee 2 e969 ldr r1, [r5, 28]
  0x803b1f0 2 6869 ldr r0, [r5, 20]
  0x803b1f2 2 891e subs r1, r1, 2
  0x803b1f4 2 8842 cmp r0, r1
  0x803b1f6 2 01d8 bhi.n 0x803b1fc
  */
  if (r0 <= r1) {
  /*
    0x803b1f8 2 401e subs r0, r0, 1
    0x803b1fa 2 6861 str r0, [r5, 20]
  */
  }
  /*
  0x803b1fc 2 2879 ldrb r0, [r5, 4]
  0x803b1fe 4 40f00100 orr.w r0, r0, 1
  0x803b202 2 2871 strb r0, [r5, 4]
  0x803b204 2 efe7 b.n 0x803b1e6
  0x803b1e6 2 2046 mov r0, r4
  0x803b1e8 4 bde8f081 ldmia.w sp!, {r4, r5, r6, r7, r8, pc}
  */
  return r4;
}
