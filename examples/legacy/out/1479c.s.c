void TIM1_TRG_COM_TIM11()
{
  r1 = 0x1;
  r4 = *_0x40014800_3;
  r0 = *_0x40014800_3;
  r0 = func_0x166D4(*_0x40014800_3, 0x1);
  if (func_0x166D4(0x40014800, 1) == 0)
  {
    return;
  }

  r1 = 0x1;
  r0 = *_0x40014800_3;
  func_0x16500(*_0x40014800_3, 0x1);
  r4 = 0x0;
  r0 = two_or_four_or_with_20000F30();
  if (two_or_four_or_with_20000F30() > 0)
  {
    sl = *_0x2000561C;
    s17 = *_0x440F0000;
    fp = *_0x20001FD4_9;
    r7 = *_0x2000877C_2;
    r6 = 0x1;
    while (1)
    {
      r0 = *_0x20000B78;
      r0 = *((*_0x20000B78) + 0x1);
      cond1 = (*((*_0x20000B78) + 0x1)) == 1;
      sb = *_0x2000562C;
      r1 = *((sl + r4) << 0x1);
      r2 = *(((*_0x2000562C) + r4) << 0x1);
      cond2 = (*((sl + r4) << 0x1)) <= (*(((*_0x2000562C) + r4) << 0x1));
      if (cond1 && cond2)
      {
        r0 = r4 + (r4 << 0x1);
        var0 = (r4 + (r4 << 0x1)) + (r4 << 0x3);
        r5 = fp + (var0 << 0x2);
        var1 = *((fp + (var0 << 0x2)) + 0x5);
        func_0x8054(var1);
        r1 = 0x0;
        r0 = r4;
        func_0x19E80(r4, 0x0, *(((*_0x2000562C) + r4) << 0x1));
        s0 = func_0x19E80(, 0);
        s16 = func_0x19E80(, 0);
        r0 = *_0x20000B8B;
        r0 = *((*_0x20000B8B) + r4);
        func_0x8054(*((*_0x20000B8B) + r4));
        r1 = 0x0;
        r0 = r4;
        func_0x19E80(r4, 0x0, *(((*_0x2000562C) + r4) << 0x1));
        s0 = func_0x19E80(0, );
        var2 = func_0x19E80(, 0) - func_0x19E80(0, );
        r0 = (*_0x2000562C) - 0x30;
        var3 = ((*_0x2000562C) - 0x30) + (r4 << 0x2);
        r0 = ((*_0x2000562C) - 0x30) + 0x30;
        s4 = *var3;
        var4 = *(((((*_0x2000562C) - 0x30) + 0x30) + r4) << 0x1);
        r1 = *((sl + r4) << 0x1);
        s2 = var4;
        r2 = *_0x20000B8B;
        s2 = (float) var4;
        r2 = *((*_0x20000B8B) + r4);
        s3 = (*var3) / ((float) var4);
        s2 = *((sl + r4) << 0x1);
        var5 = (float) (*((sl + r4) << 0x1));
        var6 = ((*var3) / ((float) var4)) * var5;
        s2 = (int) var6;
        r3 = (int) var6;
        var7 = (*((*_0x20000B8B) + r4)) + ((int) ((char) ((int) var6)));
        r3 = *_0x20000B83;
        *((*_0x20000B83) + r4) = var7;
        if (var4 != 0)
        {
          s2 = var4;
          s3 = (float) var4;
          s2 = var2 / ((float) var4);
          s1 = *((sl + r4) << 0x1);
          var8 = (float) (*((sl + r4) << 0x1));
          var9 = func_0x19E80(0, ) + ((var2 / ((float) var4)) * var8);
        }

        r0 = *_0x20005088_1;
        sb = (*_0x20005088_1) + (r4 << 0x2);
        s1 = *((*_0x20005088_1) + (r4 << 0x2));
        if ((*((*_0x20005088_1) + (r4 << 0x2))) == 0.0)
        {
          r0 = r4 << 0x1F;
          r1 = (r4 << 0x1F) >> 0x1E;
          r0 = r4 >> 0x1;
          r2 = 0x0;
          func_0x9C74(r4 >> 0x1, (r4 << 0x1F) >> 0x1E, 0x0);
        }
        else
        {
          r0 = r4 << 0x19;
          r0 = (r4 << 0x19) >> 0x18;
          r0 = func_0x1D3B8((r4 << 0x19) >> 0x18);
          r1 = *((r7 + r4) << 0x2);
          var10 = func_0x1D3B8((r4 << 0x19) >> 0x18) + (*((r7 + r4) << 0x2));
          r0 = r4 << 0x1F;
          r1 = (r4 << 0x1F) >> 0x1E;
          r0 = r4 >> 0x1;
          func_0x9C74(r4 >> 0x1, (r4 << 0x1F) >> 0x1E, var10);
        }

        var11 = *((fp + (var0 << 0x2)) + 0x5);
        func_0x8054(var11);
        r1 = 0x1;
        r0 = r4;
        func_0x19E80(r4, 0x1, var10);
        s16 = var9;
        r5 = *_0x20000B8B;
        r0 = *((*_0x20000B8B) + r4);
        func_0x8054(*((*_0x20000B8B) + r4));
        r1 = 0x1;
        r0 = r4;
        func_0x19E80(r4, 0x1, var10);
        s1 = var9 - var9;
        r0 = *_0x2000562C;
        s3 = *var3;
        r1 = *((sl + r4) << 0x1);
        r0 = *(((*_0x2000562C) + r4) << 0x1);
        r3 = *((*_0x20000B8B) + r4);
        s2 = *(((*_0x2000562C) + r4) << 0x1);
        var12 = (float) (*(((*_0x2000562C) + r4) << 0x1));
        s4 = (*var3) / var12;
        s2 = *((sl + r4) << 0x1);
        var13 = (float) (*((sl + r4) << 0x1));
        s2 = ((*var3) / var12) * var13;
        var14 = (int) (((*var3) / var12) * var13);
        r2 = var14;
        var15 = (*((*_0x20000B8B) + r4)) + ((int) ((char) var14));
        r3 = (*_0x20000B8B) - 0x8;
        *(((*_0x20000B8B) - 0x8) + r4) = var15;
        if ((*(((*_0x2000562C) + r4) << 0x1)) != 0)
        {
          s2 = *(((*_0x2000562C) + r4) << 0x1);
          var16 = (float) (*(((*_0x2000562C) + r4) << 0x1));
          s2 = (var9 - var9) / var16;
          s1 = *((sl + r4) << 0x1);
          var17 = (float) (*((sl + r4) << 0x1));
          var18 = var9 + (((var9 - var9) / var16) * var17);
        }

        var19 = *(((*_0x20005088_1) + (r4 << 0x2)) + 0x20);
        if (var19 == 0)
        {
          r0 = r4 & 0x1;
          var20 = r6 + ((r4 & 0x1) << 0x1);
          r0 = r4 >> 0x1;
          r2 = 0x0;
          func_0x9C74(r4 >> 0x1, var20, 0x0);
        }
        else
        {
          r3 = r6 + (r4 << 0x1);
          var21 = (unsigned int) (r6 + (r4 << 0x1));
          r0 = func_0x1D3B8(var21);
          var22 = *((r7 + (r6 + (r4 << 0x1))) << 0x1);
          r2 = func_0x1D3B8(var21) + var22;
          r0 = r4 & 0x1;
          var23 = r6 + ((r4 & 0x1) << 0x1);
          r0 = r4 >> 0x1;
          func_0x9C74(r4 >> 0x1, var23, func_0x1D3B8(var21) + var22);
        }

        r0 = *((sl + r4) << 0x1);
        var24 = (*((sl + r4) << 0x1)) + 0x1;
        *((sl + r4) << 0x1) = var24;
      }
      else
      {
        cond1 = var4 == 2;
        r2 = *_0x2000562C;
        r0 = *((sl + r4) << 0x1);
        r1 = *(((*_0x2000562C) + r4) << 0x1);
        cond2 = (*((sl + r4) << 0x1)) <= (*(((*_0x2000562C) + r4) << 0x1));
        if (cond1 && cond2)
        {
          s0 = *(((*_0x2000562C) + r4) << 0x1);
          r3 = (*_0x2000562C) - 0x30;
          var25 = ((*_0x2000562C) - 0x30) + (r4 << 0x2);
          var26 = (float) (*(((*_0x2000562C) + r4) << 0x1));
          s1 = *var25;
          sb = *_0x20000B8B;
          s2 = (*var25) / var26;
          s0 = *((sl + r4) << 0x1);
          r1 = *((*_0x20000B8B) + r4);
          var27 = (float) (*((sl + r4) << 0x1));
          s0 = ((*var25) / var26) * var27;
          var28 = (int) (((*var25) / var26) * var27);
          r0 = var28;
          var29 = (*((*_0x20000B8B) + r4)) + ((int) ((char) var28));
          r1 = (*_0x20000B8B) - 0x8;
          *(((*_0x20000B8B) - 0x8) + r4) = var29;
          r0 = r4 + (r4 << 0x1);
          var30 = (r4 + (r4 << 0x1)) + (r4 << 0x3);
          r8 = fp + (var30 << 0x2);
          var31 = *((fp + (var30 << 0x2)) + 0x5);
          func_0x8054(var31);
          r1 = 0x0;
          r0 = r4;
          func_0x19E80(r4, 0x0, *_0x2000562C);
          r0 = *((*_0x20000B8B) + r4);
          func_0x8054(*((*_0x20000B8B) + r4));
          r1 = 0x0;
          r0 = r4;
          func_0x19E80(r4, 0x0, *_0x2000562C);
          r0 = *_0x2000562C;
          r0 = *(((*_0x2000562C) + r4) << 0x1);
          if ((*(((*_0x2000562C) + r4) << 0x1)) != 0)
          {
            s1 = *(((*_0x2000562C) + r4) << 0x1);
            s2 = *var25;
            r0 = *((sl + r4) << 0x1);
            var32 = (float) (*(((*_0x2000562C) + r4) << 0x1));
            s3 = (*var25) / var32;
            s1 = *((sl + r4) << 0x1);
            var33 = (float) (*((sl + r4) << 0x1));
            s1 = ((*var25) / var32) * var33;
            var34 = (int) (((*var25) / var32) * var33);
            r0 = var34;
            r0 = (int) var34;
            s1 = (int) var34;
            s1 = (float) ((int) var34);
            s0 = ((float) ((int) var34)) + var28;
          }

          r0 = *_0x20005088_1;
          sb = (*_0x20005088_1) + (r4 << 0x2);
          s1 = *((*_0x20005088_1) + (r4 << 0x2));
          if ((*((*_0x20005088_1) + (r4 << 0x2))) == 0.0)
          {
            r0 = r4 << 0x1F;
            r1 = (r4 << 0x1F) >> 0x1E;
            r0 = r4 >> 0x1;
            r2 = 0x0;
            func_0x9C74(r4 >> 0x1, (r4 << 0x1F) >> 0x1E, 0x0);
          }
          else
          {
            r0 = r4 << 0x19;
            r0 = (r4 << 0x19) >> 0x18;
            r0 = func_0x1D3B8((r4 << 0x19) >> 0x18);
            r1 = *((r7 + r4) << 0x2);
            var35 = func_0x1D3B8((r4 << 0x19) >> 0x18) + (*((r7 + r4) << 0x2));
            r0 = r4 << 0x1F;
            r1 = (r4 << 0x1F) >> 0x1E;
            r0 = r4 >> 0x1;
            func_0x9C74(r4 >> 0x1, (r4 << 0x1F) >> 0x1E, var35);
          }

          var36 = *((fp + (var30 << 0x2)) + 0x5);
          func_0x8054(var36);
          r1 = 0x1;
          r0 = r4;
          func_0x19E80(r4, 0x1, var35);
          r0 = *_0x20000B8B;
          r0 = *((*_0x20000B8B) + r4);
          func_0x8054(*((*_0x20000B8B) + r4));
          r1 = 0x1;
          r0 = r4;
          func_0x19E80(r4, 0x1, var35);
          r0 = *_0x2000562C;
          r0 = *(((*_0x2000562C) + r4) << 0x1);
          if ((*(((*_0x2000562C) + r4) << 0x1)) != 0)
          {
            s1 = *(((*_0x2000562C) + r4) << 0x1);
            s3 = *var25;
            r0 = *((sl + r4) << 0x1);
            var37 = (float) (*(((*_0x2000562C) + r4) << 0x1));
            s2 = (*var25) / var37;
            s1 = *((sl + r4) << 0x1);
            var38 = (float) (*((sl + r4) << 0x1));
            s1 = ((*var25) / var37) * var38;
            var39 = (int) (((*var25) / var37) * var38);
            r0 = var39;
            r0 = (int) var39;
            s1 = (int) var39;
            s1 = (float) ((int) var39);
            var40 = ((float) ((int) var39)) + (((float) ((int) var34)) + var28);
          }

          var41 = *(((*_0x20005088_1) + (r4 << 0x2)) + 0x20);
          if (var41 == 0.0)
          {
            r0 = r4 & 0x1;
            var42 = r6 + ((r4 & 0x1) << 0x1);
            r0 = r4 >> 0x1;
            r2 = 0x0;
            func_0x9C74(r4 >> 0x1, var42, 0x0);
          }
          else
          {
            r3 = r6 + (r4 << 0x1);
            var43 = (unsigned int) (r6 + (r4 << 0x1));
            r0 = func_0x1D3B8(var43);
            var44 = *((r7 + (r6 + (r4 << 0x1))) << 0x1);
            r2 = func_0x1D3B8(var43) + var44;
            r0 = r4 & 0x1;
            var45 = r6 + ((r4 & 0x1) << 0x1);
            r0 = r4 >> 0x1;
            func_0x9C74(r4 >> 0x1, var45, func_0x1D3B8(var43) + var44);
          }

          r0 = *((sl + r4) << 0x1);
          var46 = (*((sl + r4) << 0x1)) + 0x1;
          *((sl + r4) << 0x1) = var46;
        }
        else
        {
          r8 = *data_0x14BB4;
          r1 = *(((*data_0x14BB4) + r4) << 0x1);
          if ((*(((*data_0x14BB4) + r4) << 0x1)) != 0)
          {
            r0 = r4 + (r4 << 0x1);
            var47 = (r4 + (r4 << 0x1)) + (r4 << 0x3);
            sb = fp + (var47 << 0x2);
            r2 = *_0x20000B83;
            var48 = *((fp + (var47 << 0x2)) + 0x5);
            *((*_0x20000B83) + r4) = var48;
            var49 = (*(((*data_0x14BB4) + r4) << 0x1)) - 0x1;
            *(((*data_0x14BB4) + r4) << 0x1) = var49;
            func_0x8054(var48);
            r1 = 0x0;
            r0 = r4;
            func_0x19E80(r4, 0x0, *_0x20000B83);
            r0 = *(((*data_0x14BB4) + r4) << 0x1);
            s1 = *(((*data_0x14BB4) + r4) << 0x1);
            var50 = (float) (*(((*data_0x14BB4) + r4) << 0x1));
            s1 = var50 / s17;
            s0 = var28 - (var50 / s17);
            r0 = *_0x20005088_1;
            r5 = (*_0x20005088_1) + (r4 << 0x2);
            s1 = *((*_0x20005088_1) + (r4 << 0x2));
            if ((*((*_0x20005088_1) + (r4 << 0x2))) == 0.0)
            {
              r0 = r4 << 0x1F;
              r1 = (r4 << 0x1F) >> 0x1E;
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r4 >> 0x1, (r4 << 0x1F) >> 0x1E, 0x0);
            }
            else
            {
              r0 = r4 << 0x19;
              r0 = (r4 << 0x19) >> 0x18;
              r0 = func_0x1D3B8((r4 << 0x19) >> 0x18);
              r1 = *((r7 + r4) << 0x2);
              var51 = func_0x1D3B8((r4 << 0x19) >> 0x18) + (*((r7 + r4) << 0x2));
              r0 = r4 << 0x1F;
              r1 = (r4 << 0x1F) >> 0x1E;
              r0 = r4 >> 0x1;
              func_0x9C74(r4 >> 0x1, (r4 << 0x1F) >> 0x1E, var51);
            }

            var52 = *((fp + (var47 << 0x2)) + 0x5);
            func_0x8054(var52);
            r1 = 0x1;
            r0 = r4;
            func_0x19E80(r4, 0x1, var51);
            r0 = *(((*data_0x14BB4) + r4) << 0x1);
            s1 = *(((*data_0x14BB4) + r4) << 0x1);
            var53 = (float) (*(((*data_0x14BB4) + r4) << 0x1));
            s1 = var53 / s17;
            var54 = (var28 - (var50 / s17)) - (var53 / s17);
            var55 = *(((*_0x20005088_1) + (r4 << 0x2)) + 0x20);
            if (var55 == 0.0)
            {
              r0 = r4 & 0x1;
              var56 = r6 + ((r4 & 0x1) << 0x1);
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r4 >> 0x1, var56, 0x0);
            }
            else
            {
              r3 = r6 + (r4 << 0x1);
              var57 = (unsigned int) (r6 + (r4 << 0x1));
              r0 = func_0x1D3B8(var57);
              var58 = *((r7 + (r6 + (r4 << 0x1))) << 0x1);
              r2 = func_0x1D3B8(var57) + var58;
              r0 = r4 & 0x1;
              var59 = r6 + ((r4 & 0x1) << 0x1);
              r0 = r4 >> 0x1;
              func_0x9C74(r4 >> 0x1, var59, func_0x1D3B8(var57) + var58);
            }

          }
          else
          {
            r0 = r4 + (r4 << 0x1);
            var60 = (r4 + (r4 << 0x1)) + (r4 << 0x3);
            r5 = fp + (var60 << 0x2);
            r1 = *_0x20000B83_1;
            var61 = *((fp + (var60 << 0x2)) + 0x5);
            *((*_0x20000B83_1) + r4) = var61;
            func_0x8054(var61);
            r1 = 0x0;
            r0 = r4;
            func_0x19E80(r4, 0x0, *_0x20000B83);
            r0 = *_0x20005088_2;
            r8 = (*_0x20005088_2) + (r4 << 0x2);
            s1 = *((*_0x20005088_2) + (r4 << 0x2));
            if ((*((*_0x20005088_2) + (r4 << 0x2))) == 0.0)
            {
              r0 = r4 << 0x1F;
              r1 = (r4 << 0x1F) >> 0x1E;
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r4 >> 0x1, (r4 << 0x1F) >> 0x1E, 0x0);
            }
            else
            {
              r0 = r4 << 0x19;
              r0 = (r4 << 0x19) >> 0x18;
              r0 = func_0x1D3B8((r4 << 0x19) >> 0x18);
              r1 = *((r7 + r4) << 0x2);
              var62 = func_0x1D3B8((r4 << 0x19) >> 0x18) + (*((r7 + r4) << 0x2));
              r0 = r4 << 0x1F;
              r1 = (r4 << 0x1F) >> 0x1E;
              r0 = r4 >> 0x1;
              func_0x9C74(r4 >> 0x1, (r4 << 0x1F) >> 0x1E, var62);
            }

            var63 = *((fp + (var60 << 0x2)) + 0x5);
            func_0x8054(var63);
            r1 = 0x1;
            r0 = r4;
            func_0x19E80(r4, 0x1, var62);
            var64 = *(((*_0x20005088_2) + (r4 << 0x2)) + 0x20);
            if (var64 == 0.0)
            {
              r0 = r4 & 0x1;
              var65 = r6 + ((r4 & 0x1) << 0x1);
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r4 >> 0x1, var65, 0x0);
            }
            else
            {
              r3 = r6 + (r4 << 0x1);
              var66 = (unsigned int) (r6 + (r4 << 0x1));
              r0 = func_0x1D3B8(var66);
              var67 = *((r7 + (r6 + (r4 << 0x1))) << 0x1);
              r2 = func_0x1D3B8(var66) + var67;
              r0 = r4 & 0x1;
              var68 = r6 + ((r4 & 0x1) << 0x1);
              r0 = r4 >> 0x1;
              func_0x9C74(r4 >> 0x1, var68, func_0x1D3B8(var66) + var67);
            }

          }

        }

      }

      r0 = r4 + 0x1;
      r4 = (unsigned int) (r4 + 0x1);
      r0 = two_or_four_or_with_20000F30();
    }

  }

  r0 = *_0x20000B83_1;
  r1 = (*_0x20000B83_1) - 0xB;
  r2 = *((*_0x20000B83_1) - 0xB);
  r0 = *((*_0x20000B83_1) + (*((*_0x20000B83_1) - 0xB)));
  *(((*_0x20000B83_1) - 0xB) + 0x5) = *((*_0x20000B83_1) + (*((*_0x20000B83_1) - 0xB)));
  r0 = 0x0;
  return r0;
}

