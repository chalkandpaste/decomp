entrance:
0x80304d4 2 10b5 push {r4, lr}
0x80304d6 2 174c mov r4, 0x40013000
0x80304d8 2 174b mov r3, 0x40020400
0x80304da 2 0246 mov r2, r0
0x80304dc 2 0129 cmp r1, 1
0x80304de 2 0fd0 beq.n +34

rx_loc: (len = 18)
0x80304e0 4 4ff40071 mov.w r1, 512
0x80304e4 2 1846 mov r0, r3
0x80304e6 4 f7f702fc bl 0x8027cee
0x80304ea 2 9915 asrs r1, r3, 22
0x80304ec 4 f7f7fffb bl 0x8027cee
0x80304f0 2 2088 ldrh r0, [r4, 0]
0x80304f2 2 12b1 cbz r2, +8

panel_rx_loc: (len = 6)
0x80304f4 4 00bf 00bf  nop nop #  bic.w r0, r0, 56 ## nop
0x80304f8 2 0ce0 b.n +28

mem_off_loc: (len = 6)
0x80304fa 4 40f03000 orr.w r0, r0, 48
0x80304fe 2 09e0 b.n +22

tx_loc: (len = 4)
0x8030500 2 2088 ldrh r0, [r4, 0]
0x8030502 2 1ab1 cbz r2, +10

panel_tx_loc: (len = 8)
0x8030504 4 00bf 00bf no pnop # 40f03000 orr.w r0, r0, 48 ## nop
0x8030508 2 0902 lsls r1, r1, 8
0x803050a 2 03e0 b.n +10

mem_tx_loc: (len = 10)
0x803050c 4 20f03800 bic.w r0, r0, 56
0x8030510 4 4ff40071 mov.w r1, 512

pre_return: (len = 8)
0x8030514 2 2080 strh r0, [r4, 0]
0x8030516 2 1846 mov r0, r3
0x8030518 4 f7f7e7fb bl 0x8027cea

return: (len = 2)
0x803051c 2 0120 movs r0, 1
0x803051e 2 10bd pop {r4, pc}

          10b5 174c 174b 0246 0129 0fd0
4ff4 0071 1846 f7f7 02fc 9915 f7f7 fffb
2088 12b1 00bf 00bf 0ce0 40f0 3000 09e0
2088 1ab1 00bf 00bf 0902 03e0 20f0 3800
4ff4 0071 2080 1846 f7f7 e7fb 0120 10bd
