void TIM1_TRG_COM_TIM11()
{
  r1 = 0x1;
  r0 = *_0x40014800_3;
  if (func_0x166D4(0x40014800, 1) == 0)
  {
    return;
  }

  r1 = 0x1;
  r0 = *_0x40014800_3;
  func_0x16500(r0, r1);
  if (two_or_four_or_with_20000F30() > 0)
  {
    while (1)
    {
      cond1 = (*((*_0x20000B78) + 0x1)) == 1;
      cond2 = (*(((*_0x2000561C) + r4) << 0x1)) <= (*(((*_0x2000562C) + r4) << 0x1));
      if (cond1 && cond2)
      {
        r0 = r4 + (r4 << 0x1);
        var0 = (r4 + (r4 << 0x1)) + (r4 << 0x3);
        var1 = *(((*_0x20001FD4_9) + (var0 << 0x2)) + 0x5);
        func_0x8054(r0);
        r1 = 0x0;
        r0 = r4;
        func_0x19E80(r0, r1, r2);
        r0 = *((*_0x20000B8B) + r4);
        func_0x8054(r0);
        r1 = 0x0;
        r0 = r4;
        func_0x19E80(r0, r1, r2);
        var2 = func_0x19E80(r4, 0) - func_0x19E80(0, r4);
        var3 = ((*_0x2000562C) - 0x30) + (r4 << 0x2);
        var4 = *(((((*_0x2000562C) - 0x30) + 0x30) + r4) << 0x1);
        var5 = (float) (*(((*_0x2000561C) + r4) << 0x1));
        var6 = ((*var3) / ((float) var4)) * var5;
        var7 = (*((*_0x20000B8B) + r4)) + ((int) ((char) ((int) var6)));
        *((*_0x20000B83) + r4) = var7;
        if (var4 != 0)
        {
          var8 = (float) (*(((*_0x2000561C) + r4) << 0x1));
          var9 = func_0x19E80(0, r4) + ((var2 / ((float) var4)) * var8);
        }

        if ((*((*_0x20005088_1) + (r4 << 0x2))) == 0.0)
        {
          r1 = (r4 << 0x1F) >> 0x1E;
          r0 = r4 >> 0x1;
          r2 = 0x0;
          func_0x9C74(r0, r1, r2);
        }
        else
        {
          r0 = (r4 << 0x19) >> 0x18;
          var10 = func_0x1D3B8(r0) + (*(((*_0x2000877C_2) + r4) << 0x2));
          r1 = (r4 << 0x1F) >> 0x1E;
          r0 = r4 >> 0x1;
          func_0x9C74(r0, r1, r2);
        }

        var11 = *(((*_0x20001FD4_9) + (var0 << 0x2)) + 0x5);
        func_0x8054(r0);
        r1 = 0x1;
        r0 = r4;
        func_0x19E80(r0, r1, r2);
        r0 = *((*_0x20000B8B) + r4);
        func_0x8054(r0);
        r1 = 0x1;
        r0 = r4;
        func_0x19E80(r0, r1, r2);
        r1 = *(((*_0x2000561C) + r4) << 0x1);
        var12 = (float) (*(((*_0x2000562C) + r4) << 0x1));
        var13 = (float) (*(((*_0x2000561C) + r4) << 0x1));
        var14 = (int) (((*var3) / var12) * var13);
        var15 = (*((*_0x20000B8B) + r4)) + ((int) ((char) var14));
        *(((*_0x20000B8B) - 0x8) + r4) = var15;
        if ((*(((*_0x2000562C) + r4) << 0x1)) != 0)
        {
          var16 = (float) (*(((*_0x2000562C) + r4) << 0x1));
          var17 = (float) (*(((*_0x2000561C) + r4) << 0x1));
          var18 = var9 + (((var9 - var9) / var16) * var17);
        }

        var19 = *(((*_0x20005088_1) + (r4 << 0x2)) + 0x20);
        if (var19 == 0)
        {
          var20 = 0x1 + ((r4 & 0x1) << 0x1);
          r0 = r4 >> 0x1;
          r2 = 0x0;
          func_0x9C74(r0, r1, r2);
        }
        else
        {
          var21 = (unsigned int) (0x1 + (r4 << 0x1));
          r0 = func_0x1D3B8(r0);
          var22 = *(((*_0x2000877C_2) + (0x1 + (r4 << 0x1))) << 0x1);
          r2 = func_0x1D3B8(r0) + var22;
          var23 = 0x1 + ((r4 & 0x1) << 0x1);
          r0 = r4 >> 0x1;
          func_0x9C74(r0, r1, r2);
        }

        var24 = (*(((*_0x2000561C) + r4) << 0x1)) + 0x1;
        *(((*_0x2000561C) + r4) << 0x1) = var24;
      }
      else
      {
        cond1 = var4 == 2;
        cond2 = (*(((*_0x2000561C) + r4) << 0x1)) <= (*(((*_0x2000562C) + r4) << 0x1));
        if (cond1 && cond2)
        {
          var25 = ((*_0x2000562C) - 0x30) + (r4 << 0x2);
          var26 = (float) (*(((*_0x2000562C) + r4) << 0x1));
          var27 = (float) (*(((*_0x2000561C) + r4) << 0x1));
          var28 = (int) (((*var25) / var26) * var27);
          var29 = (*((*_0x20000B8B) + r4)) + ((int) ((char) var28));
          *(((*_0x20000B8B) - 0x8) + r4) = var29;
          r0 = r4 + (r4 << 0x1);
          var30 = (r4 + (r4 << 0x1)) + (r4 << 0x3);
          var31 = *(((*_0x20001FD4_9) + (var30 << 0x2)) + 0x5);
          func_0x8054(r0);
          r1 = 0x0;
          r0 = r4;
          func_0x19E80(r0, r1, r2);
          r0 = *((*_0x20000B8B) + r4);
          func_0x8054(r0);
          r1 = 0x0;
          r0 = r4;
          func_0x19E80(r0, r1, r2);
          if ((*(((*_0x2000562C) + r4) << 0x1)) != 0)
          {
            var32 = (float) (*(((*_0x2000562C) + r4) << 0x1));
            var33 = (float) (*(((*_0x2000561C) + r4) << 0x1));
            var34 = (int) (((*var25) / var32) * var33);
          }

          if ((*((*_0x20005088_1) + (r4 << 0x2))) == 0.0)
          {
            r1 = (r4 << 0x1F) >> 0x1E;
            r0 = r4 >> 0x1;
            r2 = 0x0;
            func_0x9C74(r0, r1, r2);
          }
          else
          {
            r0 = (r4 << 0x19) >> 0x18;
            var35 = func_0x1D3B8(r0) + (*(((*_0x2000877C_2) + r4) << 0x2));
            r1 = (r4 << 0x1F) >> 0x1E;
            r0 = r4 >> 0x1;
            func_0x9C74(r0, r1, r2);
          }

          var36 = *(((*_0x20001FD4_9) + (var30 << 0x2)) + 0x5);
          func_0x8054(r0);
          r1 = 0x1;
          r0 = r4;
          func_0x19E80(r0, r1, r2);
          r0 = *((*_0x20000B8B) + r4);
          func_0x8054(r0);
          r1 = 0x1;
          r0 = r4;
          func_0x19E80(r0, r1, r2);
          if ((*(((*_0x2000562C) + r4) << 0x1)) != 0)
          {
            var37 = (float) (*(((*_0x2000562C) + r4) << 0x1));
            var38 = (float) (*(((*_0x2000561C) + r4) << 0x1));
            var39 = (int) (((*var25) / var37) * var38);
            var40 = ((float) ((int) var39)) + (((float) ((int) var34)) + var28);
          }

          var41 = *(((*_0x20005088_1) + (r4 << 0x2)) + 0x20);
          if (var41 == 0.0)
          {
            var42 = 0x1 + ((r4 & 0x1) << 0x1);
            r0 = r4 >> 0x1;
            r2 = 0x0;
            func_0x9C74(r0, r1, r2);
          }
          else
          {
            var43 = (unsigned int) (0x1 + (r4 << 0x1));
            r0 = func_0x1D3B8(r0);
            var44 = *(((*_0x2000877C_2) + (0x1 + (r4 << 0x1))) << 0x1);
            r2 = func_0x1D3B8(r0) + var44;
            var45 = 0x1 + ((r4 & 0x1) << 0x1);
            r0 = r4 >> 0x1;
            func_0x9C74(r0, r1, r2);
          }

          var46 = (*(((*_0x2000561C) + r4) << 0x1)) + 0x1;
          *(((*_0x2000561C) + r4) << 0x1) = var46;
        }
        else
        {
          if ((*(((*data_0x14BB4) + r4) << 0x1)) != 0)
          {
            r0 = r4 + (r4 << 0x1);
            var47 = (r4 + (r4 << 0x1)) + (r4 << 0x3);
            r2 = *_0x20000B83;
            var48 = *(((*_0x20001FD4_9) + (var47 << 0x2)) + 0x5);
            *((*_0x20000B83) + r4) = var48;
            var49 = (*(((*data_0x14BB4) + r4) << 0x1)) - 0x1;
            *(((*data_0x14BB4) + r4) << 0x1) = var49;
            func_0x8054(r0);
            r1 = 0x0;
            r0 = r4;
            func_0x19E80(r0, r1, r2);
            var50 = (float) (*(((*data_0x14BB4) + r4) << 0x1));
            if ((*((*_0x20005088_1) + (r4 << 0x2))) == 0.0)
            {
              r1 = (r4 << 0x1F) >> 0x1E;
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r0, r1, r2);
            }
            else
            {
              r0 = (r4 << 0x19) >> 0x18;
              var51 = func_0x1D3B8(r0) + (*(((*_0x2000877C_2) + r4) << 0x2));
              r1 = (r4 << 0x1F) >> 0x1E;
              r0 = r4 >> 0x1;
              func_0x9C74(r0, r1, r2);
            }

            var52 = *(((*_0x20001FD4_9) + (var47 << 0x2)) + 0x5);
            func_0x8054(r0);
            r1 = 0x1;
            r0 = r4;
            func_0x19E80(r0, r1, r2);
            var53 = (float) (*(((*data_0x14BB4) + r4) << 0x1));
            var54 = (var28 - (var50 / (*_0x440F0000))) - (var53 / (*_0x440F0000));
            var55 = *(((*_0x20005088_1) + (r4 << 0x2)) + 0x20);
            if (var55 == 0.0)
            {
              var56 = 0x1 + ((r4 & 0x1) << 0x1);
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r0, r1, r2);
            }
            else
            {
              var57 = (unsigned int) (0x1 + (r4 << 0x1));
              r0 = func_0x1D3B8(r0);
              var58 = *(((*_0x2000877C_2) + (0x1 + (r4 << 0x1))) << 0x1);
              r2 = func_0x1D3B8(r0) + var58;
              var59 = 0x1 + ((r4 & 0x1) << 0x1);
              r0 = r4 >> 0x1;
              func_0x9C74(r0, r1, r2);
            }

          }
          else
          {
            r0 = r4 + (r4 << 0x1);
            var60 = (r4 + (r4 << 0x1)) + (r4 << 0x3);
            var61 = *(((*_0x20001FD4_9) + (var60 << 0x2)) + 0x5);
            *((*_0x20000B83_1) + r4) = var61;
            func_0x8054(r0);
            r1 = 0x0;
            r0 = r4;
            func_0x19E80(r0, r1, r2);
            if ((*((*_0x20005088_2) + (r4 << 0x2))) == 0.0)
            {
              r1 = (r4 << 0x1F) >> 0x1E;
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r0, r1, r2);
            }
            else
            {
              r0 = (r4 << 0x19) >> 0x18;
              var62 = func_0x1D3B8(r0) + (*(((*_0x2000877C_2) + r4) << 0x2));
              r1 = (r4 << 0x1F) >> 0x1E;
              r0 = r4 >> 0x1;
              func_0x9C74(r0, r1, r2);
            }

            var63 = *(((*_0x20001FD4_9) + (var60 << 0x2)) + 0x5);
            func_0x8054(r0);
            r1 = 0x1;
            r0 = r4;
            func_0x19E80(r0, r1, r2);
            var64 = *(((*_0x20005088_2) + (r4 << 0x2)) + 0x20);
            if (var64 == 0.0)
            {
              var65 = 0x1 + ((r4 & 0x1) << 0x1);
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r0, r1, r2);
            }
            else
            {
              var66 = (unsigned int) (0x1 + (r4 << 0x1));
              r0 = func_0x1D3B8(r0);
              var67 = *(((*_0x2000877C_2) + (0x1 + (r4 << 0x1))) << 0x1);
              r2 = func_0x1D3B8(r0) + var67;
              var68 = 0x1 + ((r4 & 0x1) << 0x1);
              r0 = r4 >> 0x1;
              func_0x9C74(r0, r1, r2);
            }

          }

        }

      }

    }

  }

  *(((*_0x20000B83_1) - 0xB) + 0x5) = *((*_0x20000B83_1) + (*((*_0x20000B83_1) - 0xB)));
  r0 = 0x0;
  return r0;
}

