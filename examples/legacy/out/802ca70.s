0x802ca70 2 10b5 push {r4, lr}
0x802ca72 2 8eb0 sub sp, 56
0x802ca74 2 0446 mov r4, r0
0x802ca76 4 fbf71bfb bl 0x80280b0
0x802ca7a 2 58b1 cbz r0, 0x802ca94

0x802ca7c 4 fbf718fb bl 0x80280b0
0x802ca80 2 0128 cmp r0, 1
0x802ca82 2 07d0 beq.n 0x802ca94

0x802ca84 4 fbf714fb bl 0x80280b0
0x802ca88 2 0228 cmp r0, 2
0x802ca8a 2 03d0 beq.n 0x802ca94

0x802ca8c 4 fbf710fb bl 0x80280b0
0x802ca90 2 0328 cmp r0, 3
0x802ca92 2 24d1 bne.n 0x802cade

if (r0 == 3 || r0 == 2 || r0 == 1 || r0 == 0) {
  0x802ca94 4 fbf70cfb bl 0x80280b0
  0x802ca98 2 0228 cmp r0, 2
  0x802ca9a 2 22d0 beq.n 0x802cae2

  0x802ca9c 4 fbf708fb bl 0x80280b0
  0x802caa0 2 0328 cmp r0, 3
  0x802caa2 2 1ed0 beq.n 0x802cae2

  0x802caa4 4 fbf744fa bl 0x8027f30
  0x802caa8 2 0128 cmp r0, 1
  0x802caaa 2 1ad0 beq.n 0x802cae2

  if (r0 != 1 || r0 == 3 || r0 == 2)

    0x802caac 2 10a2 add r2, pc, 64 ; (adr r2, 0x00000080)
    0x802caae 2 11a1 add r1, pc, 68 ; (adr r1, 0x00000084)
    0x802cab0 2 01a8 add r0, sp, 4
    0x802cab2 4 f3f72bfc bl 0x802030c
  } else {
    0x802cae2 2 2246 mov r2, r4
    0x802cae4 2 05a1 add r1, pc, 20 ; (adr r1, 0x0000008c)
    0x802cae6 2 01a8 add r0, sp, 4
    0x802cae8 4 f3f710fc bl 0x802030c
    0x802caec 2 e3e7 b.n 0x802cab6
  }
  0x802cab6 2 0020 movs r0, 0
  0x802cab8 2 0090 str r0, [sp, 0]
  0x802caba 2 1923 movs r3, 25
  0x802cabc 2 3c22 movs r2, 60
  0x802cabe 2 1821 movs r1, 24
  0x802cac0 2 0420 movs r0, 4
  0x802cac2 4 03f0b7f8 bl 0x802fc34
  0x802cac6 2 4922 movs r2, 73
  0x802cac8 2 0021 movs r1, 0
  0x802caca 2 01a8 add r0, sp, 4
  0x802cacc 4 f4f7e6ff bl 0x8021a9c
  0x802cad0 2 0121 movs r1, 1
  0x802cad2 2 0091 str r1, [sp, 0]
  0x802cad4 2 084b mov r3, 0x20001a20
  0x802cad6 2 01aa add r2, sp, 4
  0x802cad8 2 1821 movs r1, 24
  0x802cada 4 03f096fc bl 0x803040a
}
0x802cade 2 0eb0 add sp, 56
0x802cae0 2 10bd pop {r4, pc}
