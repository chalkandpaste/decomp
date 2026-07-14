void TIM1_UP_TIM10()
{
  sp = sp - 0x4;
  r1 = 0x1;
  r4 = *_0x40014400_3;
  r0 = *_0x40014400_3;
  r0 = func_0x166D4(r0, r1);
  r8 = *_0x457FE000;
  sb = 0x2;
  s17 = 1.000000e+00;
  s16 = *_0xBF7CD6EA;
  r6 = *_0x20004BDC;
  r7 = 0x3;
  sl = 0x4;
  s20 = *_0x00000000;
  r5 = 0x0;
  fp = 0x1;
  cond1 = func_0x166D4(r0, r1) != 0;
  r1 = 0x1;
  r0 = *_0x40014400_3;
  func_0x16500(r0, r1);
  *local_0x28 = 0x0;
  r0 = two_or_four_or_with_20000F30();
  r1 = *local_0x28;
  cond2 = two_or_four_or_with_20000F30() > (*local_0x28);
  if (cond1 && cond2)
  {
    s18 = *_0x3C4A458F;
    s19 = *_0x41CA2C46;
    s21 = *_0x457FF000;
    r4 = *_0x2000501C;
    while (1)
    {
      r0 = *local_0x28;
      r1 = (*local_0x28) + ((*local_0x28) << 0x1);
      var0 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
      r1 = *_0x20001FD4_7;
      r0 = (*_0x20001FD4_7) + (var0 << 0x2);
      var1 = *(((*_0x20001FD4_7) + (var0 << 0x2)) + 0x9);
      if (var1 == 1)
      {
        r0 = *local_0x28;
        r2 = (*local_0x28) + ((*local_0x28) << 0x1);
        var2 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
        r0 = (*_0x20001FD4_7) + (var2 << 0x2);
        var3 = *(((*_0x20001FD4_7) + (var2 << 0x2)) + 0x8);
        if (var3 != 0)
        {
          if (var3 != 1)
          {
            if (var3 != 2)
            {
              if (var3 == 3)
              {
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var4 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_7) + (var4 << 0x2);
                r2 = *((*_0x20004BDC) + 0x5C);
                var5 = *(((*_0x20001FD4_7) + (var4 << 0x2)) + 0xC);
                if (var5 >= (*((*_0x20004BDC) + 0x5C)))
                {
                  r0 = *local_0x28;
                  r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                  var6 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                  r0 = (*_0x20001FD4_7) + (var6 << 0x2);
                  *(((*_0x20001FD4_7) + (var6 << 0x2)) + 0xC) = 0x0;
                  r0 = *local_0x28;
                  r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                  var7 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                  r0 = (*_0x20001FD4_7) + (var7 << 0x2);
                  *(((*_0x20001FD4_7) + (var7 << 0x2)) + 0x8) = 0x4;
                  r0 = *local_0x28;
                  r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                  var8 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                  r0 = (*_0x20001FD4_7) + (var8 << 0x2);
                  *(((*_0x20001FD4_7) + (var8 << 0x2)) + 0x9) = 0x0;
                }
                else
                {
                  r0 = *local_0x28;
                  r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
                  var9 = *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0x64);
                  r0 = *local_0x28;
                  s2 = *((*_0x20004BDC) + 0x60);
                  r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                  s1 = *((*_0x2000501C) + ((*local_0x28) << 0x2));
                  r0 = *local_0x28;
                  var10 = var9 + ((*((*_0x2000501C) + ((*local_0x28) << 0x2))) * (*((*_0x20004BDC) + 0x60)));
                  r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                  *((*_0x2000501C) + ((*local_0x28) << 0x2)) = var10;
                  r0 = *local_0x28;
                  r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                  var11 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                  r0 = (*_0x20001FD4_7) + (var11 << 0x2);
                  var12 = *(((*_0x20001FD4_7) + (var11 << 0x2)) + 0xC);
                  r2 = var12 + 0x1;
                  *(((*_0x20001FD4_7) + (var11 << 0x2)) + 0xC) = var12 + 0x1;
                }

              }

            }
            else
            {
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var13 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = *(((*_0x20001FD4_7) + var13) << 0x2);
            }

          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var14 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var14) << 0x2);
            cond1 = (*(((*_0x20001FD4_7) + var14) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var15 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var15 << 0x2);
            var16 = *(((*_0x20001FD4_7) + (var15 << 0x2)) + 0x4);
            cond2 = var16 == 0;
            if (cond1 && cond2)
            {
              r0 = *((*_0x20004BDC) + 0x88);
              s0 = *((*_0x20004BDC) + 0x88);
              r0 = *local_0x28;
              s0 = (float) (*((*_0x20004BDC) + 0x88));
              r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
              s1 = *((*_0x2000501C) + ((*local_0x28) << 0x2));
              r0 = *local_0x28;
              var17 = ((float) (*((*_0x20004BDC) + 0x88))) - ((*((*_0x2000501C) + ((*local_0x28) << 0x2))) * (*_0x3C4A458F));
              s1 = *((*_0x20004BDC) + 0x60);
              s1 = (*((*_0x20004BDC) + 0x60)) - 1.000000e+00;
              var18 = var17 * ((*((*_0x20004BDC) + 0x60)) - 1.000000e+00);
              s0 = var18 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
              *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0x64) = var18 / (*_0xBF7CD6EA);
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var19 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var19 << 0x2);
              *(((*_0x20001FD4_7) + (var19 << 0x2)) + 0xC) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var20 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var20 << 0x2);
              *(((*_0x20001FD4_7) + (var20 << 0x2)) + 0x8) = 0x3;
            }
            else
            {
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var21 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var21 << 0x2);
              r2 = *((*_0x20004BDC) + 0x50);
              var22 = *(((*_0x20001FD4_7) + (var21 << 0x2)) + 0xC);
              if (var22 >= (*((*_0x20004BDC) + 0x50)))
              {
                r0 = *((*_0x20004BDC) + 0x88);
                s1 = *((*_0x20004BDC) + 0x60);
                s0 = *((*_0x20004BDC) + 0x88);
                r0 = *local_0x28;
                s1 = (*((*_0x20004BDC) + 0x60)) - 1.000000e+00;
                s0 = (float) (*((*_0x20004BDC) + 0x88));
                var23 = ((float) (*((*_0x20004BDC) + 0x88))) - (*_0x41CA2C46);
                var24 = var23 * ((*((*_0x20004BDC) + 0x60)) - 1.000000e+00);
                s1 = var24 / (*_0xBF7CD6EA);
                r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
                *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0x64) = var24 / (*_0xBF7CD6EA);
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var25 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_7) + (var25 << 0x2);
                *(((*_0x20001FD4_7) + (var25 << 0x2)) + 0xC) = 0x0;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var26 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_7) + (var26 << 0x2);
                *(((*_0x20001FD4_7) + (var26 << 0x2)) + 0x8) = 0x2;
              }
              else
              {
                s0 = *((*_0x20004BDC) + 0x58);
                r0 = *local_0x28;
                s2 = *((*_0x20004BDC) + 0x54);
                r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                s1 = *((*_0x2000501C) + ((*local_0x28) << 0x2));
                r0 = *local_0x28;
                var27 = (*((*_0x20004BDC) + 0x58)) + ((*((*_0x2000501C) + ((*local_0x28) << 0x2))) * (*((*_0x20004BDC) + 0x54)));
                r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                *((*_0x2000501C) + ((*local_0x28) << 0x2)) = var27;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var28 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_7) + (var28 << 0x2);
                var29 = *(((*_0x20001FD4_7) + (var28 << 0x2)) + 0xC);
                r2 = var29 + 0x1;
                *(((*_0x20001FD4_7) + (var28 << 0x2)) + 0xC) = var29 + 0x1;
              }

            }

          }

        }
        else
        {
          r0 = *local_0x28;
          r2 = (*local_0x28) + ((*local_0x28) << 0x1);
          var30 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
          r0 = *(((*_0x20001FD4_7) + var30) << 0x2);
          cond1 = (*(((*_0x20001FD4_7) + var30) << 0x2)) == 0;
          r0 = *local_0x28;
          r2 = (*local_0x28) + ((*local_0x28) << 0x1);
          var31 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
          r0 = (*_0x20001FD4_7) + (var31 << 0x2);
          var32 = *(((*_0x20001FD4_7) + (var31 << 0x2)) + 0x4);
          cond2 = var32 == 0;
          if (cond1 && cond2)
          {
            r0 = *((*_0x20004BDC) + 0x88);
            s0 = *((*_0x20004BDC) + 0x88);
            r0 = *local_0x28;
            s0 = (float) (*((*_0x20004BDC) + 0x88));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            s1 = *((*_0x2000501C) + ((*local_0x28) << 0x2));
            r0 = *local_0x28;
            var33 = ((float) (*((*_0x20004BDC) + 0x88))) - ((*((*_0x2000501C) + ((*local_0x28) << 0x2))) * (*_0x3C4A458F));
            s1 = *((*_0x20004BDC) + 0x60);
            s1 = (*((*_0x20004BDC) + 0x60)) - 1.000000e+00;
            var34 = var33 * ((*((*_0x20004BDC) + 0x60)) - 1.000000e+00);
            s0 = var34 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0x64) = var34 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var35 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var35 << 0x2);
            *(((*_0x20001FD4_7) + (var35 << 0x2)) + 0xC) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var36 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var36 << 0x2);
            *(((*_0x20001FD4_7) + (var36 << 0x2)) + 0x8) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var37 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var37 << 0x2);
            var38 = *(((*_0x20001FD4_7) + (var37 << 0x2)) + 0xC);
            if (var38 != 0)
            {
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var39 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var39 << 0x2);
              r2 = *((*_0x20004BDC) + 0x44);
              var40 = *(((*_0x20001FD4_7) + (var39 << 0x2)) + 0xC);
              if (var40 < (*((*_0x20004BDC) + 0x44)))
              {
                r0 = *local_0x28;
                r0 = *(((*_0x2000501C) + (*local_0x28)) << 0x2);
                if ((*(((*_0x2000501C) + (*local_0x28)) << 0x2)) >= (*_0x457FE000))
                {
                  r0 = *((*_0x20004BDC) + 0x8A);
                  s0 = *((*_0x20004BDC) + 0x8A);
                  r0 = *local_0x28;
                  s0 = (float) (*((*_0x20004BDC) + 0x8A));
                  r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                  *((*_0x2000501C) + ((*local_0x28) << 0x2)) = (float) (*((*_0x20004BDC) + 0x8A));
                  r0 = *local_0x28;
                  r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                  var41 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                  r0 = (*_0x20001FD4_7) + (var41 << 0x2);
                  *(((*_0x20001FD4_7) + (var41 << 0x2)) + 0xC) = 0x0;
                  r0 = *local_0x28;
                  r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                  var42 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                  r0 = (*_0x20001FD4_7) + (var42 << 0x2);
                  *(((*_0x20001FD4_7) + (var42 << 0x2)) + 0x8) = 0x1;
                }
                else
                {
                  s0 = *((*_0x20004BDC) + 0x4C);
                  r0 = *local_0x28;
                  s2 = *((*_0x20004BDC) + 0x48);
                  r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                  s1 = *((*_0x2000501C) + ((*local_0x28) << 0x2));
                  r0 = *local_0x28;
                  var43 = (*((*_0x20004BDC) + 0x4C)) + ((*((*_0x2000501C) + ((*local_0x28) << 0x2))) * (*((*_0x20004BDC) + 0x48)));
                  r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                  *((*_0x2000501C) + ((*local_0x28) << 0x2)) = var43;
                  r0 = *local_0x28;
                  r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                  var44 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                  r0 = (*_0x20001FD4_7) + (var44 << 0x2);
                  var45 = *(((*_0x20001FD4_7) + (var44 << 0x2)) + 0xC);
                  r2 = var45 + 0x1;
                  *(((*_0x20001FD4_7) + (var44 << 0x2)) + 0xC) = var45 + 0x1;
                }

              }
              else
              {
                r0 = *((*_0x20004BDC) + 0x8A);
                s0 = *((*_0x20004BDC) + 0x8A);
                r0 = *local_0x28;
                s0 = (float) (*((*_0x20004BDC) + 0x8A));
                r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                *((*_0x2000501C) + ((*local_0x28) << 0x2)) = (float) (*((*_0x20004BDC) + 0x8A));
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var46 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_7) + (var46 << 0x2);
                *(((*_0x20001FD4_7) + (var46 << 0x2)) + 0xC) = 0x0;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var47 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_7) + (var47 << 0x2);
                *(((*_0x20001FD4_7) + (var47 << 0x2)) + 0x8) = 0x1;
              }

            }
            else
            {
              r0 = *local_0x28;
              r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
              s1 = *((*_0x2000501C) + ((*local_0x28) << 0x2));
              r0 = *((*_0x20004BDC) + 0x88);
              s0 = *((*_0x20004BDC) + 0x88);
              s0 = (float) (*((*_0x20004BDC) + 0x88));
              if ((*((*_0x2000501C) + ((*local_0x28) << 0x2))) <= ((float) (*((*_0x20004BDC) + 0x88))))
              {
                s0 = *((*_0x20004BDC) + 0x88);
                r0 = *local_0x28;
                s0 = (float) (*((*_0x20004BDC) + 0x88));
                r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
                *((*_0x2000501C) + ((*local_0x28) << 0x2)) = (float) (*((*_0x20004BDC) + 0x88));
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var48 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_7) + (var48 << 0x2);
                var49 = *(((*_0x20001FD4_7) + (var48 << 0x2)) + 0xC);
                r2 = var49 + 0x1;
                *(((*_0x20001FD4_7) + (var48 << 0x2)) + 0xC) = var49 + 0x1;
              }
              else
              {
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var50 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_7) + (var50 << 0x2);
                var51 = *(((*_0x20001FD4_7) + (var50 << 0x2)) + 0xC);
                r2 = var51 + 0x1;
                *(((*_0x20001FD4_7) + (var50 << 0x2)) + 0xC) = var51 + 0x1;
              }

            }

          }

        }

      }

      r0 = *local_0x28;
      r2 = (*local_0x28) + ((*local_0x28) << 0x1);
      var52 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
      r0 = (*_0x20001FD4_7) + (var52 << 0x2);
      var53 = *(((*_0x20001FD4_7) + (var52 << 0x2)) + 0x19);
      if (var53 == 1)
      {
        r0 = *local_0x28;
        r2 = (*local_0x28) + ((*local_0x28) << 0x1);
        var54 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
        r0 = (*_0x20001FD4_7) + (var54 << 0x2);
        var55 = *(((*_0x20001FD4_7) + (var54 << 0x2)) + 0x18);
        switch (var55)
        {
          case 0:
            break;

          case 0:
            break;

          case 0:
            break;

          case 0:
            break;

          case 1:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var56 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var56) << 0x2);
            cond1 = (*(((*_0x20001FD4_7) + var56) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var57 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var57 << 0x2);
            var58 = *(((*_0x20001FD4_7) + (var57 << 0x2)) + 0x4);
            cond2 = var58 == 0;
            if (cond1 && cond2)
          {
            r0 = *((*_0x20004BDC) + 0x118);
            s0 = *((*_0x20004BDC) + 0x118);
            r0 = *local_0x28;
            s0 = (float) (*((*_0x20004BDC) + 0x118));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var59 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var60 = ((float) (*((*_0x20004BDC) + 0x118))) - (var59 * (*_0x3C4A458F));
            s1 = *((*_0x20004BDC) + 0xF0);
            s1 = (*((*_0x20004BDC) + 0xF0)) - 1.000000e+00;
            var61 = var60 * ((*((*_0x20004BDC) + 0xF0)) - 1.000000e+00);
            s1 = var61 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4) = var61 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var62 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var62 << 0x2);
            *(((*_0x20001FD4_7) + (var62 << 0x2)) + 0x1C) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var63 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var63 << 0x2);
            *(((*_0x20001FD4_7) + (var63 << 0x2)) + 0x18) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var64 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var64 << 0x2);
            r2 = *((*_0x20004BDC) + 0xE0);
            var65 = *(((*_0x20001FD4_7) + (var64 << 0x2)) + 0x1C);
            if (var65 >= (*((*_0x20004BDC) + 0xE0)))
            {
              r0 = *((*_0x20004BDC) + 0x118);
              s1 = *((*_0x20004BDC) + 0xF0);
              s0 = *((*_0x20004BDC) + 0x118);
              r0 = *local_0x28;
              s1 = (*((*_0x20004BDC) + 0xF0)) - 1.000000e+00;
              s0 = (float) (*((*_0x20004BDC) + 0x118));
              var66 = ((float) (*((*_0x20004BDC) + 0x118))) - (*_0x41CA2C46);
              var67 = var66 * ((*((*_0x20004BDC) + 0xF0)) - 1.000000e+00);
              s1 = var67 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
              *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4) = var67 / (*_0xBF7CD6EA);
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var68 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var68 << 0x2);
              *(((*_0x20001FD4_7) + (var68 << 0x2)) + 0x1C) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var69 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var69 << 0x2);
              *(((*_0x20001FD4_7) + (var69 << 0x2)) + 0x18) = 0x2;
            }

            s0 = *((*_0x20004BDC) + 0xE8);
            r0 = *local_0x28;
            s2 = *((*_0x20004BDC) + 0xE4);
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var70 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var71 = (*((*_0x20004BDC) + 0xE8)) + (var70 * (*((*_0x20004BDC) + 0xE4)));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = var71;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var72 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var72 << 0x2);
            var73 = *(((*_0x20001FD4_7) + (var72 << 0x2)) + 0x1C);
            r1 = var73 + 0x1;
            *(((*_0x20001FD4_7) + (var72 << 0x2)) + 0x1C) = var73 + 0x1;
          }

            break;

          case 1:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var56 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var56) << 0x2);
            cond1 = (*(((*_0x20001FD4_7) + var56) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var57 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var57 << 0x2);
            var58 = *(((*_0x20001FD4_7) + (var57 << 0x2)) + 0x4);
            cond2 = var58 == 0;
            if (cond1 && cond2)
          {
            r0 = *((*_0x20004BDC) + 0x118);
            s0 = *((*_0x20004BDC) + 0x118);
            r0 = *local_0x28;
            s0 = (float) (*((*_0x20004BDC) + 0x118));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var59 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var60 = ((float) (*((*_0x20004BDC) + 0x118))) - (var59 * (*_0x3C4A458F));
            s1 = *((*_0x20004BDC) + 0xF0);
            s1 = (*((*_0x20004BDC) + 0xF0)) - 1.000000e+00;
            var61 = var60 * ((*((*_0x20004BDC) + 0xF0)) - 1.000000e+00);
            s1 = var61 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4) = var61 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var62 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var62 << 0x2);
            *(((*_0x20001FD4_7) + (var62 << 0x2)) + 0x1C) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var63 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var63 << 0x2);
            *(((*_0x20001FD4_7) + (var63 << 0x2)) + 0x18) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var64 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var64 << 0x2);
            r2 = *((*_0x20004BDC) + 0xE0);
            var65 = *(((*_0x20001FD4_7) + (var64 << 0x2)) + 0x1C);
            if (var65 >= (*((*_0x20004BDC) + 0xE0)))
            {
              r0 = *((*_0x20004BDC) + 0x118);
              s1 = *((*_0x20004BDC) + 0xF0);
              s0 = *((*_0x20004BDC) + 0x118);
              r0 = *local_0x28;
              s1 = (*((*_0x20004BDC) + 0xF0)) - 1.000000e+00;
              s0 = (float) (*((*_0x20004BDC) + 0x118));
              var66 = ((float) (*((*_0x20004BDC) + 0x118))) - (*_0x41CA2C46);
              var67 = var66 * ((*((*_0x20004BDC) + 0xF0)) - 1.000000e+00);
              s1 = var67 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
              *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4) = var67 / (*_0xBF7CD6EA);
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var68 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var68 << 0x2);
              *(((*_0x20001FD4_7) + (var68 << 0x2)) + 0x1C) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var69 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var69 << 0x2);
              *(((*_0x20001FD4_7) + (var69 << 0x2)) + 0x18) = 0x2;
            }

            s0 = *((*_0x20004BDC) + 0xE8);
            r0 = *local_0x28;
            s2 = *((*_0x20004BDC) + 0xE4);
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var70 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var71 = (*((*_0x20004BDC) + 0xE8)) + (var70 * (*((*_0x20004BDC) + 0xE4)));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = var71;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var72 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var72 << 0x2);
            var73 = *(((*_0x20001FD4_7) + (var72 << 0x2)) + 0x1C);
            r1 = var73 + 0x1;
            *(((*_0x20001FD4_7) + (var72 << 0x2)) + 0x1C) = var73 + 0x1;
          }

            break;

          case 1:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var56 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var56) << 0x2);
            cond1 = (*(((*_0x20001FD4_7) + var56) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var57 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var57 << 0x2);
            var58 = *(((*_0x20001FD4_7) + (var57 << 0x2)) + 0x4);
            cond2 = var58 == 0;
            if (cond1 && cond2)
          {
            r0 = *((*_0x20004BDC) + 0x118);
            s0 = *((*_0x20004BDC) + 0x118);
            r0 = *local_0x28;
            s0 = (float) (*((*_0x20004BDC) + 0x118));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var59 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var60 = ((float) (*((*_0x20004BDC) + 0x118))) - (var59 * (*_0x3C4A458F));
            s1 = *((*_0x20004BDC) + 0xF0);
            s1 = (*((*_0x20004BDC) + 0xF0)) - 1.000000e+00;
            var61 = var60 * ((*((*_0x20004BDC) + 0xF0)) - 1.000000e+00);
            s1 = var61 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4) = var61 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var62 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var62 << 0x2);
            *(((*_0x20001FD4_7) + (var62 << 0x2)) + 0x1C) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var63 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var63 << 0x2);
            *(((*_0x20001FD4_7) + (var63 << 0x2)) + 0x18) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var64 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var64 << 0x2);
            r2 = *((*_0x20004BDC) + 0xE0);
            var65 = *(((*_0x20001FD4_7) + (var64 << 0x2)) + 0x1C);
            if (var65 >= (*((*_0x20004BDC) + 0xE0)))
            {
              r0 = *((*_0x20004BDC) + 0x118);
              s1 = *((*_0x20004BDC) + 0xF0);
              s0 = *((*_0x20004BDC) + 0x118);
              r0 = *local_0x28;
              s1 = (*((*_0x20004BDC) + 0xF0)) - 1.000000e+00;
              s0 = (float) (*((*_0x20004BDC) + 0x118));
              var66 = ((float) (*((*_0x20004BDC) + 0x118))) - (*_0x41CA2C46);
              var67 = var66 * ((*((*_0x20004BDC) + 0xF0)) - 1.000000e+00);
              s1 = var67 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
              *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4) = var67 / (*_0xBF7CD6EA);
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var68 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var68 << 0x2);
              *(((*_0x20001FD4_7) + (var68 << 0x2)) + 0x1C) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var69 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var69 << 0x2);
              *(((*_0x20001FD4_7) + (var69 << 0x2)) + 0x18) = 0x2;
            }

            s0 = *((*_0x20004BDC) + 0xE8);
            r0 = *local_0x28;
            s2 = *((*_0x20004BDC) + 0xE4);
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var70 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var71 = (*((*_0x20004BDC) + 0xE8)) + (var70 * (*((*_0x20004BDC) + 0xE4)));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = var71;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var72 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var72 << 0x2);
            var73 = *(((*_0x20001FD4_7) + (var72 << 0x2)) + 0x1C);
            r1 = var73 + 0x1;
            *(((*_0x20001FD4_7) + (var72 << 0x2)) + 0x1C) = var73 + 0x1;
          }

            break;

          case 1:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var56 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var56) << 0x2);
            cond1 = (*(((*_0x20001FD4_7) + var56) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var57 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var57 << 0x2);
            var58 = *(((*_0x20001FD4_7) + (var57 << 0x2)) + 0x4);
            cond2 = var58 == 0;
            if (cond1 && cond2)
          {
            r0 = *((*_0x20004BDC) + 0x118);
            s0 = *((*_0x20004BDC) + 0x118);
            r0 = *local_0x28;
            s0 = (float) (*((*_0x20004BDC) + 0x118));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var59 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var60 = ((float) (*((*_0x20004BDC) + 0x118))) - (var59 * (*_0x3C4A458F));
            s1 = *((*_0x20004BDC) + 0xF0);
            s1 = (*((*_0x20004BDC) + 0xF0)) - 1.000000e+00;
            var61 = var60 * ((*((*_0x20004BDC) + 0xF0)) - 1.000000e+00);
            s1 = var61 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4) = var61 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var62 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var62 << 0x2);
            *(((*_0x20001FD4_7) + (var62 << 0x2)) + 0x1C) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var63 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var63 << 0x2);
            *(((*_0x20001FD4_7) + (var63 << 0x2)) + 0x18) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var64 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var64 << 0x2);
            r2 = *((*_0x20004BDC) + 0xE0);
            var65 = *(((*_0x20001FD4_7) + (var64 << 0x2)) + 0x1C);
            if (var65 >= (*((*_0x20004BDC) + 0xE0)))
            {
              r0 = *((*_0x20004BDC) + 0x118);
              s1 = *((*_0x20004BDC) + 0xF0);
              s0 = *((*_0x20004BDC) + 0x118);
              r0 = *local_0x28;
              s1 = (*((*_0x20004BDC) + 0xF0)) - 1.000000e+00;
              s0 = (float) (*((*_0x20004BDC) + 0x118));
              var66 = ((float) (*((*_0x20004BDC) + 0x118))) - (*_0x41CA2C46);
              var67 = var66 * ((*((*_0x20004BDC) + 0xF0)) - 1.000000e+00);
              s1 = var67 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
              *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4) = var67 / (*_0xBF7CD6EA);
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var68 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var68 << 0x2);
              *(((*_0x20001FD4_7) + (var68 << 0x2)) + 0x1C) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var69 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_7) + (var69 << 0x2);
              *(((*_0x20001FD4_7) + (var69 << 0x2)) + 0x18) = 0x2;
            }

            s0 = *((*_0x20004BDC) + 0xE8);
            r0 = *local_0x28;
            s2 = *((*_0x20004BDC) + 0xE4);
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var70 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var71 = (*((*_0x20004BDC) + 0xE8)) + (var70 * (*((*_0x20004BDC) + 0xE4)));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = var71;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var72 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var72 << 0x2);
            var73 = *(((*_0x20001FD4_7) + (var72 << 0x2)) + 0x1C);
            r1 = var73 + 0x1;
            *(((*_0x20001FD4_7) + (var72 << 0x2)) + 0x1C) = var73 + 0x1;
          }

            break;

          case 2:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var74 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var74) << 0x2);
            break;

          case 2:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var74 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var74) << 0x2);
            break;

          case 2:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var74 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var74) << 0x2);
            break;

          case 2:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var74 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_7) + var74) << 0x2);
            break;

          case 3:
            break;

          case 3:
            break;

          case 3:
            break;

          case 3:
            break;

          default:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var75 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var75 << 0x2);
            r2 = *((*_0x20004BDC) + 0xEC);
            var76 = *(((*_0x20001FD4_7) + (var75 << 0x2)) + 0x1C);
            if (var76 >= (*((*_0x20004BDC) + 0xEC)))
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var77 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var77 << 0x2);
            *(((*_0x20001FD4_7) + (var77 << 0x2)) + 0x1C) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var78 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var78 << 0x2);
            *(((*_0x20001FD4_7) + (var78 << 0x2)) + 0x18) = 0x4;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var79 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var79 << 0x2);
            *(((*_0x20001FD4_7) + (var79 << 0x2)) + 0x19) = 0x0;
          }
          else
          {
            r0 = *local_0x28;
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            var80 = *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4);
            r0 = *local_0x28;
            s2 = *((*_0x20004BDC) + 0xF0);
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var81 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var82 = var80 + (var81 * (*((*_0x20004BDC) + 0xF0)));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = var82;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var83 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var83 << 0x2);
            var84 = *(((*_0x20001FD4_7) + (var83 << 0x2)) + 0x1C);
            r1 = var84 + 0x1;
            *(((*_0x20001FD4_7) + (var83 << 0x2)) + 0x1C) = var84 + 0x1;
          }


          default:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var75 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var75 << 0x2);
            r2 = *((*_0x20004BDC) + 0xEC);
            var76 = *(((*_0x20001FD4_7) + (var75 << 0x2)) + 0x1C);
            if (var76 >= (*((*_0x20004BDC) + 0xEC)))
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var77 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var77 << 0x2);
            *(((*_0x20001FD4_7) + (var77 << 0x2)) + 0x1C) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var78 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var78 << 0x2);
            *(((*_0x20001FD4_7) + (var78 << 0x2)) + 0x18) = 0x4;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var79 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var79 << 0x2);
            *(((*_0x20001FD4_7) + (var79 << 0x2)) + 0x19) = 0x0;
          }
          else
          {
            r0 = *local_0x28;
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            var80 = *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4);
            r0 = *local_0x28;
            s2 = *((*_0x20004BDC) + 0xF0);
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var81 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var82 = var80 + (var81 * (*((*_0x20004BDC) + 0xF0)));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = var82;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var83 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var83 << 0x2);
            var84 = *(((*_0x20001FD4_7) + (var83 << 0x2)) + 0x1C);
            r1 = var84 + 0x1;
            *(((*_0x20001FD4_7) + (var83 << 0x2)) + 0x1C) = var84 + 0x1;
          }


          default:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var75 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var75 << 0x2);
            r2 = *((*_0x20004BDC) + 0xEC);
            var76 = *(((*_0x20001FD4_7) + (var75 << 0x2)) + 0x1C);
            if (var76 >= (*((*_0x20004BDC) + 0xEC)))
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var77 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var77 << 0x2);
            *(((*_0x20001FD4_7) + (var77 << 0x2)) + 0x1C) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var78 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var78 << 0x2);
            *(((*_0x20001FD4_7) + (var78 << 0x2)) + 0x18) = 0x4;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var79 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var79 << 0x2);
            *(((*_0x20001FD4_7) + (var79 << 0x2)) + 0x19) = 0x0;
          }
          else
          {
            r0 = *local_0x28;
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            var80 = *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4);
            r0 = *local_0x28;
            s2 = *((*_0x20004BDC) + 0xF0);
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var81 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var82 = var80 + (var81 * (*((*_0x20004BDC) + 0xF0)));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = var82;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var83 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var83 << 0x2);
            var84 = *(((*_0x20001FD4_7) + (var83 << 0x2)) + 0x1C);
            r1 = var84 + 0x1;
            *(((*_0x20001FD4_7) + (var83 << 0x2)) + 0x1C) = var84 + 0x1;
          }


          default:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var75 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var75 << 0x2);
            r2 = *((*_0x20004BDC) + 0xEC);
            var76 = *(((*_0x20001FD4_7) + (var75 << 0x2)) + 0x1C);
            if (var76 >= (*((*_0x20004BDC) + 0xEC)))
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var77 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var77 << 0x2);
            *(((*_0x20001FD4_7) + (var77 << 0x2)) + 0x1C) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var78 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var78 << 0x2);
            *(((*_0x20001FD4_7) + (var78 << 0x2)) + 0x18) = 0x4;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var79 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var79 << 0x2);
            *(((*_0x20001FD4_7) + (var79 << 0x2)) + 0x19) = 0x0;
          }
          else
          {
            r0 = *local_0x28;
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            var80 = *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xF4);
            r0 = *local_0x28;
            s2 = *((*_0x20004BDC) + 0xF0);
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            var81 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
            r0 = *local_0x28;
            var82 = var80 + (var81 * (*((*_0x20004BDC) + 0xF0)));
            r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
            *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = var82;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var83 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_7) + (var83 << 0x2);
            var84 = *(((*_0x20001FD4_7) + (var83 << 0x2)) + 0x1C);
            r1 = var84 + 0x1;
            *(((*_0x20001FD4_7) + (var83 << 0x2)) + 0x1C) = var84 + 0x1;
          }


        }

      }

      r0 = *local_0x28;
      r1 = *_0x457FF000_1;
      r0 = *(((*_0x2000501C) + (*local_0x28)) << 0x2);
      if ((*(((*_0x2000501C) + (*local_0x28)) << 0x2)) > (*_0x457FF000_1))
      {
        r0 = *local_0x28;
        r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
        *((*_0x2000501C) + ((*local_0x28) << 0x2)) = *_0x457FF000;
      }

      r0 = *local_0x28;
      r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
      var85 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
      if (var85 > (*_0x457FF000_1))
      {
        r0 = *local_0x28;
        r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
        *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = *_0x457FF000;
      }

      r0 = *local_0x28;
      r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
      s0 = *((*_0x2000501C) + ((*local_0x28) << 0x2));
      if ((*((*_0x2000501C) + ((*local_0x28) << 0x2))) < 0.0)
      {
        r0 = *local_0x28;
        r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
        *((*_0x2000501C) + ((*local_0x28) << 0x2)) = *_0x00000000;
      }

      r0 = *local_0x28;
      r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
      var86 = *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20);
      if (var86 < 0.0)
      {
        r0 = *local_0x28;
        r0 = (*_0x2000501C) + ((*local_0x28) << 0x2);
        *(((*_0x2000501C) + ((*local_0x28) << 0x2)) + 0x20) = *_0x00000000;
      }

      r0 = *local_0x28;
      func_0x19CAC(r0);
      r0 = *local_0x28;
      r0 = (*local_0x28) + 0x1;
      *local_0x28 = (*local_0x28) + 0x1;
      r0 = two_or_four_or_with_20000F30();
      r1 = *local_0x28;
      if (two_or_four_or_with_20000F30() <= (*local_0x28))
      {
        break;
      }

    }

  }

  r4 = *_0x40010000_3;
  r1 = 0x1;
  r0 = *_0x40010000_3;
  r0 = func_0x166D4(r0, r1);
  cond1 = func_0x166D4(r0, r1) != 0;
  r1 = 0x1;
  r0 = *_0x40010000_3;
  func_0x16500(r0, r1);
  *local_0x28 = 0x0;
  r0 = two_or_four_or_with_20000F30();
  r1 = *local_0x28;
  cond2 = two_or_four_or_with_20000F30() > (*local_0x28);
  if (cond1 && cond2)
  {
    s18 = *_0xBC4A458F;
    sb = 0x4;
    r4 = *_0x20005088;
    s19 = 2.000000e+01;
    sl = 0x1;
    r8 = 0x6;
    while (1)
    {
      r0 = *local_0x28;
      r1 = (*local_0x28) + ((*local_0x28) << 0x1);
      var87 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
      r1 = *_0x20001FD4_8;
      r0 = (*_0x20001FD4_8) + (var87 << 0x2);
      var88 = *(((*_0x20001FD4_8) + (var87 << 0x2)) + 0x11);
      cond1 = var88 == 1;
      r0 = *local_0x28;
      r2 = (*local_0x28) + ((*local_0x28) << 0x1);
      var89 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
      r0 = (*_0x20001FD4_8) + (var89 << 0x2);
      var90 = *(((*_0x20001FD4_8) + (var89 << 0x2)) + 0x10);
      cond2 = var90 < 7;
      if (cond1 && cond2)
      {
        switch (var90)
        {
          case 0:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var91 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var91) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var91) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var92 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var92 << 0x2);
            var93 = *(((*_0x20001FD4_8) + (var92 << 0x2)) + 0x4);
            cond2 = var93 != 0;
            if (cond1 && cond2)
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var94 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var94 << 0x2);
            var95 = *(((*_0x20001FD4_8) + (var94 << 0x2)) + 0x14);
            r0 = *(*_0x20004BDC);
            if ((*(*_0x20004BDC)) > var95)
            {
              r0 = *local_0x28;
              r2 = *_457FE000;
              r0 = *(((*_0x20005088) + (*local_0x28)) << 0x2);
            }

            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var96 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var96 << 0x2);
            *(((*_0x20001FD4_8) + (var96 << 0x2)) + 0x14) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var97 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var97 << 0x2);
            *(((*_0x20001FD4_8) + (var97 << 0x2)) + 0x10) = 0x1;
          }
          else
          {
            r0 = *local_0x28;
            s1 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
            s0 = *((*_0x20005088) + ((*local_0x28) << 0x2));
            s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
            r0 = *local_0x28;
            var98 = (*((*_0x20005088) + ((*local_0x28) << 0x2))) * (*_0xBC4A458F);
            var99 = var98 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
            s1 = var99 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0x20) = var99 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var100 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var100 << 0x2);
            *(((*_0x20001FD4_8) + (var100 << 0x2)) + 0x14) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var101 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var101 << 0x2);
            *(((*_0x20001FD4_8) + (var101 << 0x2)) + 0x10) = 0x3;
          }

            break;

          case 0:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var91 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var91) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var91) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var92 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var92 << 0x2);
            var93 = *(((*_0x20001FD4_8) + (var92 << 0x2)) + 0x4);
            cond2 = var93 != 0;
            if (cond1 && cond2)
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var94 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var94 << 0x2);
            var95 = *(((*_0x20001FD4_8) + (var94 << 0x2)) + 0x14);
            r0 = *(*_0x20004BDC);
            if ((*(*_0x20004BDC)) > var95)
            {
              r0 = *local_0x28;
              r2 = *_457FE000;
              r0 = *(((*_0x20005088) + (*local_0x28)) << 0x2);
            }

            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var96 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var96 << 0x2);
            *(((*_0x20001FD4_8) + (var96 << 0x2)) + 0x14) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var97 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var97 << 0x2);
            *(((*_0x20001FD4_8) + (var97 << 0x2)) + 0x10) = 0x1;
          }
          else
          {
            r0 = *local_0x28;
            s1 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
            s0 = *((*_0x20005088) + ((*local_0x28) << 0x2));
            s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
            r0 = *local_0x28;
            var98 = (*((*_0x20005088) + ((*local_0x28) << 0x2))) * (*_0xBC4A458F);
            var99 = var98 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
            s1 = var99 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0x20) = var99 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var100 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var100 << 0x2);
            *(((*_0x20001FD4_8) + (var100 << 0x2)) + 0x14) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var101 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var101 << 0x2);
            *(((*_0x20001FD4_8) + (var101 << 0x2)) + 0x10) = 0x3;
          }

            break;

          case 0:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var91 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var91) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var91) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var92 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var92 << 0x2);
            var93 = *(((*_0x20001FD4_8) + (var92 << 0x2)) + 0x4);
            cond2 = var93 != 0;
            if (cond1 && cond2)
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var94 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var94 << 0x2);
            var95 = *(((*_0x20001FD4_8) + (var94 << 0x2)) + 0x14);
            r0 = *(*_0x20004BDC);
            if ((*(*_0x20004BDC)) > var95)
            {
              r0 = *local_0x28;
              r2 = *_457FE000;
              r0 = *(((*_0x20005088) + (*local_0x28)) << 0x2);
            }

            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var96 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var96 << 0x2);
            *(((*_0x20001FD4_8) + (var96 << 0x2)) + 0x14) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var97 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var97 << 0x2);
            *(((*_0x20001FD4_8) + (var97 << 0x2)) + 0x10) = 0x1;
          }
          else
          {
            r0 = *local_0x28;
            s1 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
            s0 = *((*_0x20005088) + ((*local_0x28) << 0x2));
            s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
            r0 = *local_0x28;
            var98 = (*((*_0x20005088) + ((*local_0x28) << 0x2))) * (*_0xBC4A458F);
            var99 = var98 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
            s1 = var99 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0x20) = var99 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var100 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var100 << 0x2);
            *(((*_0x20001FD4_8) + (var100 << 0x2)) + 0x14) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var101 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var101 << 0x2);
            *(((*_0x20001FD4_8) + (var101 << 0x2)) + 0x10) = 0x3;
          }

            break;

          case 0:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var91 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var91) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var91) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var92 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var92 << 0x2);
            var93 = *(((*_0x20001FD4_8) + (var92 << 0x2)) + 0x4);
            cond2 = var93 != 0;
            if (cond1 && cond2)
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var94 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var94 << 0x2);
            var95 = *(((*_0x20001FD4_8) + (var94 << 0x2)) + 0x14);
            r0 = *(*_0x20004BDC);
            if ((*(*_0x20004BDC)) > var95)
            {
              r0 = *local_0x28;
              r2 = *_457FE000;
              r0 = *(((*_0x20005088) + (*local_0x28)) << 0x2);
            }

            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var96 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var96 << 0x2);
            *(((*_0x20001FD4_8) + (var96 << 0x2)) + 0x14) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var97 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var97 << 0x2);
            *(((*_0x20001FD4_8) + (var97 << 0x2)) + 0x10) = 0x1;
          }
          else
          {
            r0 = *local_0x28;
            s1 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
            s0 = *((*_0x20005088) + ((*local_0x28) << 0x2));
            s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
            r0 = *local_0x28;
            var98 = (*((*_0x20005088) + ((*local_0x28) << 0x2))) * (*_0xBC4A458F);
            var99 = var98 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
            s1 = var99 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0x20) = var99 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var100 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var100 << 0x2);
            *(((*_0x20001FD4_8) + (var100 << 0x2)) + 0x14) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var101 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var101 << 0x2);
            *(((*_0x20001FD4_8) + (var101 << 0x2)) + 0x10) = 0x3;
          }

            break;

          case 1:
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var102 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var102) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var102) << 0x2)) == 0;
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var103 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var103 << 0x2);
            var104 = *(((*_0x20001FD4_8) + (var103 << 0x2)) + 0x4);
            cond2 = var104 != 0;
            if (cond1 && cond2)
          {
            r0 = *stack_0x0;
            s1 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
            s0 = *((*_0x20005088) + ((*stack_0x0) << 0x2));
            s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
            r0 = *stack_0x0;
            var105 = (*((*_0x20005088) + ((*stack_0x0) << 0x2))) * (*_0xBC4A458F);
            var106 = var105 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
            s1 = var106 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*stack_0x0) << 0x2);
            *(((*_0x20004BDC) + ((*stack_0x0) << 0x2)) + 0x20) = var106 / (*_0xBF7CD6EA);
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var107 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var107 << 0x2);
            *(((*_0x20001FD4_8) + (var107 << 0x2)) + 0x14) = 0x0;
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var108 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var108 << 0x2);
            *(((*_0x20001FD4_8) + (var108 << 0x2)) + 0x10) = 0x3;
          }
          else
          {
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var109 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var109 << 0x2);
            r2 = *((*_0x20004BDC) + 0xC);
            var110 = *(((*_0x20001FD4_8) + (var109 << 0x2)) + 0x14);
            if (var110 >= (*((*_0x20004BDC) + 0xC)))
            {
              r0 = *((*_0x20004BDC) + 0x40);
              s1 = *((*_0x20004BDC) + 0x1C);
              s0 = *((*_0x20004BDC) + 0x40);
              r0 = *stack_0x0;
              s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
              s0 = (float) (*((*_0x20004BDC) + 0x40));
              var111 = ((float) (*((*_0x20004BDC) + 0x40))) * (*_0xBC4A458F);
              var112 = var111 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
              s1 = var112 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*stack_0x0) << 0x2);
              *(((*_0x20004BDC) + ((*stack_0x0) << 0x2)) + 0x20) = var112 / (*_0xBF7CD6EA);
              r0 = *stack_0x0;
              r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var113 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var113 << 0x2);
              *(((*_0x20001FD4_8) + (var113 << 0x2)) + 0x14) = 0x0;
              r0 = *stack_0x0;
              r2 = 0x2;
              r3 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var114 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var114 << 0x2);
              *(((*_0x20001FD4_8) + (var114 << 0x2)) + 0x10) = 0x2;
            }
            else
            {
              s0 = *((*_0x20004BDC) + 0x14);
              r0 = *stack_0x0;
              s2 = *((*_0x20004BDC) + 0x10);
              r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
              s1 = *((*_0x20005088) + ((*stack_0x0) << 0x2));
              r0 = *stack_0x0;
              var115 = (*((*_0x20004BDC) + 0x14)) + ((*((*_0x20005088) + ((*stack_0x0) << 0x2))) * (*((*_0x20004BDC) + 0x10)));
              r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
              *((*_0x20005088) + ((*stack_0x0) << 0x2)) = var115;
              r0 = *stack_0x0;
              r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var116 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var116 << 0x2);
              var117 = *(((*_0x20001FD4_8) + (var116 << 0x2)) + 0x14);
              r2 = var117 + 0x1;
              *(((*_0x20001FD4_8) + (var116 << 0x2)) + 0x14) = var117 + 0x1;
            }

          }

            break;

          case 1:
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var102 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var102) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var102) << 0x2)) == 0;
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var103 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var103 << 0x2);
            var104 = *(((*_0x20001FD4_8) + (var103 << 0x2)) + 0x4);
            cond2 = var104 != 0;
            if (cond1 && cond2)
          {
            r0 = *stack_0x0;
            s1 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
            s0 = *((*_0x20005088) + ((*stack_0x0) << 0x2));
            s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
            r0 = *stack_0x0;
            var105 = (*((*_0x20005088) + ((*stack_0x0) << 0x2))) * (*_0xBC4A458F);
            var106 = var105 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
            s1 = var106 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*stack_0x0) << 0x2);
            *(((*_0x20004BDC) + ((*stack_0x0) << 0x2)) + 0x20) = var106 / (*_0xBF7CD6EA);
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var107 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var107 << 0x2);
            *(((*_0x20001FD4_8) + (var107 << 0x2)) + 0x14) = 0x0;
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var108 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var108 << 0x2);
            *(((*_0x20001FD4_8) + (var108 << 0x2)) + 0x10) = 0x3;
          }
          else
          {
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var109 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var109 << 0x2);
            r2 = *((*_0x20004BDC) + 0xC);
            var110 = *(((*_0x20001FD4_8) + (var109 << 0x2)) + 0x14);
            if (var110 >= (*((*_0x20004BDC) + 0xC)))
            {
              r0 = *((*_0x20004BDC) + 0x40);
              s1 = *((*_0x20004BDC) + 0x1C);
              s0 = *((*_0x20004BDC) + 0x40);
              r0 = *stack_0x0;
              s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
              s0 = (float) (*((*_0x20004BDC) + 0x40));
              var111 = ((float) (*((*_0x20004BDC) + 0x40))) * (*_0xBC4A458F);
              var112 = var111 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
              s1 = var112 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*stack_0x0) << 0x2);
              *(((*_0x20004BDC) + ((*stack_0x0) << 0x2)) + 0x20) = var112 / (*_0xBF7CD6EA);
              r0 = *stack_0x0;
              r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var113 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var113 << 0x2);
              *(((*_0x20001FD4_8) + (var113 << 0x2)) + 0x14) = 0x0;
              r0 = *stack_0x0;
              r2 = 0x2;
              r3 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var114 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var114 << 0x2);
              *(((*_0x20001FD4_8) + (var114 << 0x2)) + 0x10) = 0x2;
            }
            else
            {
              s0 = *((*_0x20004BDC) + 0x14);
              r0 = *stack_0x0;
              s2 = *((*_0x20004BDC) + 0x10);
              r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
              s1 = *((*_0x20005088) + ((*stack_0x0) << 0x2));
              r0 = *stack_0x0;
              var115 = (*((*_0x20004BDC) + 0x14)) + ((*((*_0x20005088) + ((*stack_0x0) << 0x2))) * (*((*_0x20004BDC) + 0x10)));
              r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
              *((*_0x20005088) + ((*stack_0x0) << 0x2)) = var115;
              r0 = *stack_0x0;
              r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var116 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var116 << 0x2);
              var117 = *(((*_0x20001FD4_8) + (var116 << 0x2)) + 0x14);
              r2 = var117 + 0x1;
              *(((*_0x20001FD4_8) + (var116 << 0x2)) + 0x14) = var117 + 0x1;
            }

          }

            break;

          case 1:
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var102 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var102) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var102) << 0x2)) == 0;
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var103 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var103 << 0x2);
            var104 = *(((*_0x20001FD4_8) + (var103 << 0x2)) + 0x4);
            cond2 = var104 != 0;
            if (cond1 && cond2)
          {
            r0 = *stack_0x0;
            s1 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
            s0 = *((*_0x20005088) + ((*stack_0x0) << 0x2));
            s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
            r0 = *stack_0x0;
            var105 = (*((*_0x20005088) + ((*stack_0x0) << 0x2))) * (*_0xBC4A458F);
            var106 = var105 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
            s1 = var106 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*stack_0x0) << 0x2);
            *(((*_0x20004BDC) + ((*stack_0x0) << 0x2)) + 0x20) = var106 / (*_0xBF7CD6EA);
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var107 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var107 << 0x2);
            *(((*_0x20001FD4_8) + (var107 << 0x2)) + 0x14) = 0x0;
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var108 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var108 << 0x2);
            *(((*_0x20001FD4_8) + (var108 << 0x2)) + 0x10) = 0x3;
          }
          else
          {
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var109 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var109 << 0x2);
            r2 = *((*_0x20004BDC) + 0xC);
            var110 = *(((*_0x20001FD4_8) + (var109 << 0x2)) + 0x14);
            if (var110 >= (*((*_0x20004BDC) + 0xC)))
            {
              r0 = *((*_0x20004BDC) + 0x40);
              s1 = *((*_0x20004BDC) + 0x1C);
              s0 = *((*_0x20004BDC) + 0x40);
              r0 = *stack_0x0;
              s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
              s0 = (float) (*((*_0x20004BDC) + 0x40));
              var111 = ((float) (*((*_0x20004BDC) + 0x40))) * (*_0xBC4A458F);
              var112 = var111 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
              s1 = var112 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*stack_0x0) << 0x2);
              *(((*_0x20004BDC) + ((*stack_0x0) << 0x2)) + 0x20) = var112 / (*_0xBF7CD6EA);
              r0 = *stack_0x0;
              r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var113 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var113 << 0x2);
              *(((*_0x20001FD4_8) + (var113 << 0x2)) + 0x14) = 0x0;
              r0 = *stack_0x0;
              r2 = 0x2;
              r3 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var114 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var114 << 0x2);
              *(((*_0x20001FD4_8) + (var114 << 0x2)) + 0x10) = 0x2;
            }
            else
            {
              s0 = *((*_0x20004BDC) + 0x14);
              r0 = *stack_0x0;
              s2 = *((*_0x20004BDC) + 0x10);
              r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
              s1 = *((*_0x20005088) + ((*stack_0x0) << 0x2));
              r0 = *stack_0x0;
              var115 = (*((*_0x20004BDC) + 0x14)) + ((*((*_0x20005088) + ((*stack_0x0) << 0x2))) * (*((*_0x20004BDC) + 0x10)));
              r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
              *((*_0x20005088) + ((*stack_0x0) << 0x2)) = var115;
              r0 = *stack_0x0;
              r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var116 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var116 << 0x2);
              var117 = *(((*_0x20001FD4_8) + (var116 << 0x2)) + 0x14);
              r2 = var117 + 0x1;
              *(((*_0x20001FD4_8) + (var116 << 0x2)) + 0x14) = var117 + 0x1;
            }

          }

            break;

          case 1:
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var102 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var102) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var102) << 0x2)) == 0;
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var103 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var103 << 0x2);
            var104 = *(((*_0x20001FD4_8) + (var103 << 0x2)) + 0x4);
            cond2 = var104 != 0;
            if (cond1 && cond2)
          {
            r0 = *stack_0x0;
            s1 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
            s0 = *((*_0x20005088) + ((*stack_0x0) << 0x2));
            s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
            r0 = *stack_0x0;
            var105 = (*((*_0x20005088) + ((*stack_0x0) << 0x2))) * (*_0xBC4A458F);
            var106 = var105 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
            s1 = var106 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*stack_0x0) << 0x2);
            *(((*_0x20004BDC) + ((*stack_0x0) << 0x2)) + 0x20) = var106 / (*_0xBF7CD6EA);
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var107 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var107 << 0x2);
            *(((*_0x20001FD4_8) + (var107 << 0x2)) + 0x14) = 0x0;
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var108 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var108 << 0x2);
            *(((*_0x20001FD4_8) + (var108 << 0x2)) + 0x10) = 0x3;
          }
          else
          {
            r0 = *stack_0x0;
            r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
            var109 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
            r0 = (*_0x20001FD4_8) + (var109 << 0x2);
            r2 = *((*_0x20004BDC) + 0xC);
            var110 = *(((*_0x20001FD4_8) + (var109 << 0x2)) + 0x14);
            if (var110 >= (*((*_0x20004BDC) + 0xC)))
            {
              r0 = *((*_0x20004BDC) + 0x40);
              s1 = *((*_0x20004BDC) + 0x1C);
              s0 = *((*_0x20004BDC) + 0x40);
              r0 = *stack_0x0;
              s1 = (*((*_0x20004BDC) + 0x1C)) - 1.000000e+00;
              s0 = (float) (*((*_0x20004BDC) + 0x40));
              var111 = ((float) (*((*_0x20004BDC) + 0x40))) * (*_0xBC4A458F);
              var112 = var111 * ((*((*_0x20004BDC) + 0x1C)) - 1.000000e+00);
              s1 = var112 / (*_0xBF7CD6EA);
              r0 = (*_0x20004BDC) + ((*stack_0x0) << 0x2);
              *(((*_0x20004BDC) + ((*stack_0x0) << 0x2)) + 0x20) = var112 / (*_0xBF7CD6EA);
              r0 = *stack_0x0;
              r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var113 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var113 << 0x2);
              *(((*_0x20001FD4_8) + (var113 << 0x2)) + 0x14) = 0x0;
              r0 = *stack_0x0;
              r2 = 0x2;
              r3 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var114 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var114 << 0x2);
              *(((*_0x20001FD4_8) + (var114 << 0x2)) + 0x10) = 0x2;
            }
            else
            {
              s0 = *((*_0x20004BDC) + 0x14);
              r0 = *stack_0x0;
              s2 = *((*_0x20004BDC) + 0x10);
              r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
              s1 = *((*_0x20005088) + ((*stack_0x0) << 0x2));
              r0 = *stack_0x0;
              var115 = (*((*_0x20004BDC) + 0x14)) + ((*((*_0x20005088) + ((*stack_0x0) << 0x2))) * (*((*_0x20004BDC) + 0x10)));
              r0 = (*_0x20005088) + ((*stack_0x0) << 0x2);
              *((*_0x20005088) + ((*stack_0x0) << 0x2)) = var115;
              r0 = *stack_0x0;
              r2 = (*stack_0x0) + ((*stack_0x0) << 0x1);
              var116 = ((*stack_0x0) + ((*stack_0x0) << 0x1)) + ((*stack_0x0) << 0x3);
              r0 = (*_0x20001FD4_8) + (var116 << 0x2);
              var117 = *(((*_0x20001FD4_8) + (var116 << 0x2)) + 0x14);
              r2 = var117 + 0x1;
              *(((*_0x20001FD4_8) + (var116 << 0x2)) + 0x14) = var117 + 0x1;
            }

          }

            break;

          case 2:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var118 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var118) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var118) << 0x2)) != 1;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var119 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var119 << 0x2);
            var120 = *(((*_0x20001FD4_8) + (var119 << 0x2)) + 0x4);
            cond2 = var120 != 1;
            if (cond1 && cond2)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var121 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var121 << 0x2);
            *(((*_0x20001FD4_8) + (var121 << 0x2)) + 0x14) = 0x0;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var122 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var122 << 0x2);
            *(((*_0x20001FD4_8) + (var122 << 0x2)) + 0x10) = 0x3;
          }
          else
          {
            r0 = *((*_0x20004BDC) + 0x40);
            s0 = *((*_0x20004BDC) + 0x40);
            r0 = *sp;
            s0 = (float) (*((*_0x20004BDC) + 0x40));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *((*_0x20005088) + ((*sp) << 0x2)) = (float) (*((*_0x20004BDC) + 0x40));
          }

            break;

          case 2:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var118 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var118) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var118) << 0x2)) != 1;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var119 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var119 << 0x2);
            var120 = *(((*_0x20001FD4_8) + (var119 << 0x2)) + 0x4);
            cond2 = var120 != 1;
            if (cond1 && cond2)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var121 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var121 << 0x2);
            *(((*_0x20001FD4_8) + (var121 << 0x2)) + 0x14) = 0x0;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var122 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var122 << 0x2);
            *(((*_0x20001FD4_8) + (var122 << 0x2)) + 0x10) = 0x3;
          }
          else
          {
            r0 = *((*_0x20004BDC) + 0x40);
            s0 = *((*_0x20004BDC) + 0x40);
            r0 = *sp;
            s0 = (float) (*((*_0x20004BDC) + 0x40));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *((*_0x20005088) + ((*sp) << 0x2)) = (float) (*((*_0x20004BDC) + 0x40));
          }

            break;

          case 2:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var118 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var118) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var118) << 0x2)) != 1;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var119 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var119 << 0x2);
            var120 = *(((*_0x20001FD4_8) + (var119 << 0x2)) + 0x4);
            cond2 = var120 != 1;
            if (cond1 && cond2)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var121 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var121 << 0x2);
            *(((*_0x20001FD4_8) + (var121 << 0x2)) + 0x14) = 0x0;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var122 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var122 << 0x2);
            *(((*_0x20001FD4_8) + (var122 << 0x2)) + 0x10) = 0x3;
          }
          else
          {
            r0 = *((*_0x20004BDC) + 0x40);
            s0 = *((*_0x20004BDC) + 0x40);
            r0 = *sp;
            s0 = (float) (*((*_0x20004BDC) + 0x40));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *((*_0x20005088) + ((*sp) << 0x2)) = (float) (*((*_0x20004BDC) + 0x40));
          }

            break;

          case 2:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var118 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var118) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var118) << 0x2)) != 1;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var119 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var119 << 0x2);
            var120 = *(((*_0x20001FD4_8) + (var119 << 0x2)) + 0x4);
            cond2 = var120 != 1;
            if (cond1 && cond2)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var121 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var121 << 0x2);
            *(((*_0x20001FD4_8) + (var121 << 0x2)) + 0x14) = 0x0;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var122 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var122 << 0x2);
            *(((*_0x20001FD4_8) + (var122 << 0x2)) + 0x10) = 0x3;
          }
          else
          {
            r0 = *((*_0x20004BDC) + 0x40);
            s0 = *((*_0x20004BDC) + 0x40);
            r0 = *sp;
            s0 = (float) (*((*_0x20004BDC) + 0x40));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *((*_0x20005088) + ((*sp) << 0x2)) = (float) (*((*_0x20004BDC) + 0x40));
          }

            break;

          case 3:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var123 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var123 << 0x2);
            r2 = *((*_0x20004BDC) + 0x18);
            var124 = *(((*_0x20001FD4_8) + (var123 << 0x2)) + 0x14);
            if (var124 >= (*((*_0x20004BDC) + 0x18)))
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var125 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var125 << 0x2);
            *(((*_0x20001FD4_8) + (var125 << 0x2)) + 0x14) = 0x0;
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s0 = *((*_0x20005088) + ((*sp) << 0x2));
            if ((*((*_0x20005088) + ((*sp) << 0x2))) <= 0.0)
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var126 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var126 << 0x2);
              *(((*_0x20001FD4_8) + (var126 << 0x2)) + 0x10) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var127 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var127 << 0x2);
              *(((*_0x20001FD4_8) + (var127 << 0x2)) + 0x11) = 0x0;
            }
            else
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var128 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var128 << 0x2);
              *(((*_0x20001FD4_8) + (var128 << 0x2)) + 0x10) = 0x6;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20004BDC) + ((*sp) << 0x2);
            var129 = *(((*_0x20004BDC) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            s2 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s1 = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            var130 = var129 + ((*((*_0x20005088) + ((*sp) << 0x2))) * (*((*_0x20004BDC) + 0x1C)));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *((*_0x20005088) + ((*sp) << 0x2)) = var130;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var131 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var131 << 0x2);
            var132 = *(((*_0x20001FD4_8) + (var131 << 0x2)) + 0x14);
            r2 = var132 + 0x1;
            *(((*_0x20001FD4_8) + (var131 << 0x2)) + 0x14) = var132 + 0x1;
          }

            break;

          case 3:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var123 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var123 << 0x2);
            r2 = *((*_0x20004BDC) + 0x18);
            var124 = *(((*_0x20001FD4_8) + (var123 << 0x2)) + 0x14);
            if (var124 >= (*((*_0x20004BDC) + 0x18)))
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var125 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var125 << 0x2);
            *(((*_0x20001FD4_8) + (var125 << 0x2)) + 0x14) = 0x0;
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s0 = *((*_0x20005088) + ((*sp) << 0x2));
            if ((*((*_0x20005088) + ((*sp) << 0x2))) <= 0.0)
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var126 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var126 << 0x2);
              *(((*_0x20001FD4_8) + (var126 << 0x2)) + 0x10) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var127 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var127 << 0x2);
              *(((*_0x20001FD4_8) + (var127 << 0x2)) + 0x11) = 0x0;
            }
            else
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var128 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var128 << 0x2);
              *(((*_0x20001FD4_8) + (var128 << 0x2)) + 0x10) = 0x6;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20004BDC) + ((*sp) << 0x2);
            var129 = *(((*_0x20004BDC) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            s2 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s1 = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            var130 = var129 + ((*((*_0x20005088) + ((*sp) << 0x2))) * (*((*_0x20004BDC) + 0x1C)));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *((*_0x20005088) + ((*sp) << 0x2)) = var130;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var131 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var131 << 0x2);
            var132 = *(((*_0x20001FD4_8) + (var131 << 0x2)) + 0x14);
            r2 = var132 + 0x1;
            *(((*_0x20001FD4_8) + (var131 << 0x2)) + 0x14) = var132 + 0x1;
          }

            break;

          case 3:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var123 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var123 << 0x2);
            r2 = *((*_0x20004BDC) + 0x18);
            var124 = *(((*_0x20001FD4_8) + (var123 << 0x2)) + 0x14);
            if (var124 >= (*((*_0x20004BDC) + 0x18)))
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var125 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var125 << 0x2);
            *(((*_0x20001FD4_8) + (var125 << 0x2)) + 0x14) = 0x0;
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s0 = *((*_0x20005088) + ((*sp) << 0x2));
            if ((*((*_0x20005088) + ((*sp) << 0x2))) <= 0.0)
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var126 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var126 << 0x2);
              *(((*_0x20001FD4_8) + (var126 << 0x2)) + 0x10) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var127 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var127 << 0x2);
              *(((*_0x20001FD4_8) + (var127 << 0x2)) + 0x11) = 0x0;
            }
            else
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var128 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var128 << 0x2);
              *(((*_0x20001FD4_8) + (var128 << 0x2)) + 0x10) = 0x6;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20004BDC) + ((*sp) << 0x2);
            var129 = *(((*_0x20004BDC) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            s2 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s1 = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            var130 = var129 + ((*((*_0x20005088) + ((*sp) << 0x2))) * (*((*_0x20004BDC) + 0x1C)));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *((*_0x20005088) + ((*sp) << 0x2)) = var130;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var131 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var131 << 0x2);
            var132 = *(((*_0x20001FD4_8) + (var131 << 0x2)) + 0x14);
            r2 = var132 + 0x1;
            *(((*_0x20001FD4_8) + (var131 << 0x2)) + 0x14) = var132 + 0x1;
          }

            break;

          case 3:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var123 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var123 << 0x2);
            r2 = *((*_0x20004BDC) + 0x18);
            var124 = *(((*_0x20001FD4_8) + (var123 << 0x2)) + 0x14);
            if (var124 >= (*((*_0x20004BDC) + 0x18)))
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var125 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var125 << 0x2);
            *(((*_0x20001FD4_8) + (var125 << 0x2)) + 0x14) = 0x0;
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s0 = *((*_0x20005088) + ((*sp) << 0x2));
            if ((*((*_0x20005088) + ((*sp) << 0x2))) <= 0.0)
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var126 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var126 << 0x2);
              *(((*_0x20001FD4_8) + (var126 << 0x2)) + 0x10) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var127 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var127 << 0x2);
              *(((*_0x20001FD4_8) + (var127 << 0x2)) + 0x11) = 0x0;
            }
            else
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var128 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var128 << 0x2);
              *(((*_0x20001FD4_8) + (var128 << 0x2)) + 0x10) = 0x6;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20004BDC) + ((*sp) << 0x2);
            var129 = *(((*_0x20004BDC) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            s2 = *((*_0x20004BDC) + 0x1C);
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s1 = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            var130 = var129 + ((*((*_0x20005088) + ((*sp) << 0x2))) * (*((*_0x20004BDC) + 0x1C)));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *((*_0x20005088) + ((*sp) << 0x2)) = var130;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var131 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var131 << 0x2);
            var132 = *(((*_0x20001FD4_8) + (var131 << 0x2)) + 0x14);
            r2 = var132 + 0x1;
            *(((*_0x20001FD4_8) + (var131 << 0x2)) + 0x14) = var132 + 0x1;
          }

            break;

          case 4:
            break;

          case 4:
            break;

          case 4:
            break;

          case 4:
            break;

          case 5:
            break;

          case 5:
            break;

          case 5:
            break;

          case 5:
            break;

          case 6:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var133 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var133 << 0x2);
            var134 = *(((*_0x20001FD4_8) + (var133 << 0x2)) + 0x14);
            if (var134 != 0)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var135 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var135 << 0x2);
            var136 = *(((*_0x20001FD4_8) + (var135 << 0x2)) + 0x14);
            if (var136 >= 0x14)
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *((*_0x20005088) + ((*sp) << 0x2)) = *_0x00000000;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var137 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var137 << 0x2);
              *(((*_0x20001FD4_8) + (var137 << 0x2)) + 0x14) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var138 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_8) + (var138 << 0x2);
              *(((*_0x20001FD4_8) + (var138 << 0x2)) + 0x10) = 0x4;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var139 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_8) + (var139 << 0x2);
              *(((*_0x20001FD4_8) + (var139 << 0x2)) + 0x11) = 0x0;
            }
            else
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              var140 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x40);
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var141 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var141 << 0x2);
              var142 = *(((*_0x20001FD4_8) + (var141 << 0x2)) + 0x14);
              r0 = 0x14 - var142;
              s0 = 0x14 - var142;
              r0 = *sp;
              s0 = (float) (0x14 - var142);
              var143 = var140 * ((float) (0x14 - var142));
              s1 = var143 / 2.000000e+01;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *((*_0x20005088) + ((*sp) << 0x2)) = var143 / 2.000000e+01;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var144 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var144 << 0x2);
              var145 = *(((*_0x20001FD4_8) + (var144 << 0x2)) + 0x14);
              r2 = var145 + 0x1;
              *(((*_0x20001FD4_8) + (var144 << 0x2)) + 0x14) = var145 + 0x1;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s0 = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x40) = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var146 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var146 << 0x2);
            var147 = *(((*_0x20001FD4_8) + (var146 << 0x2)) + 0x14);
            r2 = var147 + 0x1;
            *(((*_0x20001FD4_8) + (var146 << 0x2)) + 0x14) = var147 + 0x1;
          }

            break;

          case 6:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var133 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var133 << 0x2);
            var134 = *(((*_0x20001FD4_8) + (var133 << 0x2)) + 0x14);
            if (var134 != 0)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var135 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var135 << 0x2);
            var136 = *(((*_0x20001FD4_8) + (var135 << 0x2)) + 0x14);
            if (var136 >= 0x14)
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *((*_0x20005088) + ((*sp) << 0x2)) = *_0x00000000;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var137 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var137 << 0x2);
              *(((*_0x20001FD4_8) + (var137 << 0x2)) + 0x14) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var138 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_8) + (var138 << 0x2);
              *(((*_0x20001FD4_8) + (var138 << 0x2)) + 0x10) = 0x4;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var139 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_8) + (var139 << 0x2);
              *(((*_0x20001FD4_8) + (var139 << 0x2)) + 0x11) = 0x0;
            }
            else
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              var140 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x40);
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var141 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var141 << 0x2);
              var142 = *(((*_0x20001FD4_8) + (var141 << 0x2)) + 0x14);
              r0 = 0x14 - var142;
              s0 = 0x14 - var142;
              r0 = *sp;
              s0 = (float) (0x14 - var142);
              var143 = var140 * ((float) (0x14 - var142));
              s1 = var143 / 2.000000e+01;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *((*_0x20005088) + ((*sp) << 0x2)) = var143 / 2.000000e+01;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var144 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var144 << 0x2);
              var145 = *(((*_0x20001FD4_8) + (var144 << 0x2)) + 0x14);
              r2 = var145 + 0x1;
              *(((*_0x20001FD4_8) + (var144 << 0x2)) + 0x14) = var145 + 0x1;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s0 = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x40) = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var146 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var146 << 0x2);
            var147 = *(((*_0x20001FD4_8) + (var146 << 0x2)) + 0x14);
            r2 = var147 + 0x1;
            *(((*_0x20001FD4_8) + (var146 << 0x2)) + 0x14) = var147 + 0x1;
          }

            break;

          case 6:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var133 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var133 << 0x2);
            var134 = *(((*_0x20001FD4_8) + (var133 << 0x2)) + 0x14);
            if (var134 != 0)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var135 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var135 << 0x2);
            var136 = *(((*_0x20001FD4_8) + (var135 << 0x2)) + 0x14);
            if (var136 >= 0x14)
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *((*_0x20005088) + ((*sp) << 0x2)) = *_0x00000000;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var137 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var137 << 0x2);
              *(((*_0x20001FD4_8) + (var137 << 0x2)) + 0x14) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var138 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_8) + (var138 << 0x2);
              *(((*_0x20001FD4_8) + (var138 << 0x2)) + 0x10) = 0x4;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var139 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_8) + (var139 << 0x2);
              *(((*_0x20001FD4_8) + (var139 << 0x2)) + 0x11) = 0x0;
            }
            else
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              var140 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x40);
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var141 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var141 << 0x2);
              var142 = *(((*_0x20001FD4_8) + (var141 << 0x2)) + 0x14);
              r0 = 0x14 - var142;
              s0 = 0x14 - var142;
              r0 = *sp;
              s0 = (float) (0x14 - var142);
              var143 = var140 * ((float) (0x14 - var142));
              s1 = var143 / 2.000000e+01;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *((*_0x20005088) + ((*sp) << 0x2)) = var143 / 2.000000e+01;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var144 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var144 << 0x2);
              var145 = *(((*_0x20001FD4_8) + (var144 << 0x2)) + 0x14);
              r2 = var145 + 0x1;
              *(((*_0x20001FD4_8) + (var144 << 0x2)) + 0x14) = var145 + 0x1;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s0 = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x40) = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var146 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var146 << 0x2);
            var147 = *(((*_0x20001FD4_8) + (var146 << 0x2)) + 0x14);
            r2 = var147 + 0x1;
            *(((*_0x20001FD4_8) + (var146 << 0x2)) + 0x14) = var147 + 0x1;
          }

            break;

          case 6:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var133 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var133 << 0x2);
            var134 = *(((*_0x20001FD4_8) + (var133 << 0x2)) + 0x14);
            if (var134 != 0)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var135 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var135 << 0x2);
            var136 = *(((*_0x20001FD4_8) + (var135 << 0x2)) + 0x14);
            if (var136 >= 0x14)
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *((*_0x20005088) + ((*sp) << 0x2)) = *_0x00000000;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var137 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var137 << 0x2);
              *(((*_0x20001FD4_8) + (var137 << 0x2)) + 0x14) = 0x0;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var138 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_8) + (var138 << 0x2);
              *(((*_0x20001FD4_8) + (var138 << 0x2)) + 0x10) = 0x4;
              r0 = *local_0x28;
              r2 = (*local_0x28) + ((*local_0x28) << 0x1);
              var139 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
              r0 = (*_0x20001FD4_8) + (var139 << 0x2);
              *(((*_0x20001FD4_8) + (var139 << 0x2)) + 0x11) = 0x0;
            }
            else
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              var140 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x40);
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var141 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var141 << 0x2);
              var142 = *(((*_0x20001FD4_8) + (var141 << 0x2)) + 0x14);
              r0 = 0x14 - var142;
              s0 = 0x14 - var142;
              r0 = *sp;
              s0 = (float) (0x14 - var142);
              var143 = var140 * ((float) (0x14 - var142));
              s1 = var143 / 2.000000e+01;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *((*_0x20005088) + ((*sp) << 0x2)) = var143 / 2.000000e+01;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var144 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var144 << 0x2);
              var145 = *(((*_0x20001FD4_8) + (var144 << 0x2)) + 0x14);
              r2 = var145 + 0x1;
              *(((*_0x20001FD4_8) + (var144 << 0x2)) + 0x14) = var145 + 0x1;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            s0 = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x40) = *((*_0x20005088) + ((*sp) << 0x2));
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var146 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var146 << 0x2);
            var147 = *(((*_0x20001FD4_8) + (var146 << 0x2)) + 0x14);
            r2 = var147 + 0x1;
            *(((*_0x20001FD4_8) + (var146 << 0x2)) + 0x14) = var147 + 0x1;
          }

            break;

        }

      }

      r0 = *local_0x28;
      r2 = (*local_0x28) + ((*local_0x28) << 0x1);
      var148 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
      r0 = (*_0x20001FD4_8) + (var148 << 0x2);
      var149 = *(((*_0x20001FD4_8) + (var148 << 0x2)) + 0x21);
      cond1 = var149 == 1;
      r0 = *local_0x28;
      r2 = (*local_0x28) + ((*local_0x28) << 0x1);
      var150 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
      r0 = (*_0x20001FD4_8) + (var150 << 0x2);
      var151 = *(((*_0x20001FD4_8) + (var150 << 0x2)) + 0x20);
      cond2 = var151 < 7;
      if (cond1 && cond2)
      {
        switch (var151)
        {
          case 0:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var152 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var152) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var152) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var153 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var153 << 0x2);
            var154 = *(((*_0x20001FD4_8) + (var153 << 0x2)) + 0x4);
            cond2 = var154 == 0;
            if (cond1 && cond2)
          {
            r0 = *local_0x28;
            s1 = *((*_0x20004BDC) + 0xAC);
            r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
            var155 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
            s1 = (*((*_0x20004BDC) + 0xAC)) - 1.000000e+00;
            r0 = *local_0x28;
            s0 = var155 * (*_0xBC4A458F);
            var156 = (var155 * (*_0xBC4A458F)) * ((*((*_0x20004BDC) + 0xAC)) - 1.000000e+00);
            s1 = var156 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xB0) = var156 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var157 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var157 << 0x2);
            *(((*_0x20001FD4_8) + (var157 << 0x2)) + 0x24) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var158 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var158 << 0x2);
            *(((*_0x20001FD4_8) + (var158 << 0x2)) + 0x20) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var159 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var159 << 0x2);
            r2 = *((*_0x20004BDC) + 0x90);
            var160 = *(((*_0x20001FD4_8) + (var159 << 0x2)) + 0x24);
            if (var160 < (*((*_0x20004BDC) + 0x90)))
            {
              r0 = *local_0x28;
              r2 = *_0x457FE000_1;
              r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
              var161 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
              if (var161 < (*_0x457FE000_1))
              {
                s0 = *((*_0x20004BDC) + 0x98);
                r0 = *local_0x28;
                s2 = *((*_0x20004BDC) + 0x94);
                r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
                var162 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
                r0 = *local_0x28;
                var163 = (*((*_0x20004BDC) + 0x98)) + (var162 * (*((*_0x20004BDC) + 0x94)));
                r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
                *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20) = var163;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var164 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_8) + (var164 << 0x2);
                var165 = *(((*_0x20001FD4_8) + (var164 << 0x2)) + 0x24);
                r1 = var165 + 0x1;
                *(((*_0x20001FD4_8) + (var164 << 0x2)) + 0x24) = var165 + 0x1;
              }
              else
              {
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var166 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                var167 = (var165 + 0x1) + (var166 << 0x2);
                *(var167 + 0x24) = 0x0;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var168 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                var169 = (var165 + 0x1) + (var168 << 0x2);
                *(var169 + 0x20) = 0x1;
              }

            }

          }

            break;

          case 0:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var152 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var152) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var152) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var153 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var153 << 0x2);
            var154 = *(((*_0x20001FD4_8) + (var153 << 0x2)) + 0x4);
            cond2 = var154 == 0;
            if (cond1 && cond2)
          {
            r0 = *local_0x28;
            s1 = *((*_0x20004BDC) + 0xAC);
            r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
            var155 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
            s1 = (*((*_0x20004BDC) + 0xAC)) - 1.000000e+00;
            r0 = *local_0x28;
            s0 = var155 * (*_0xBC4A458F);
            var156 = (var155 * (*_0xBC4A458F)) * ((*((*_0x20004BDC) + 0xAC)) - 1.000000e+00);
            s1 = var156 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xB0) = var156 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var157 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var157 << 0x2);
            *(((*_0x20001FD4_8) + (var157 << 0x2)) + 0x24) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var158 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var158 << 0x2);
            *(((*_0x20001FD4_8) + (var158 << 0x2)) + 0x20) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var159 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var159 << 0x2);
            r2 = *((*_0x20004BDC) + 0x90);
            var160 = *(((*_0x20001FD4_8) + (var159 << 0x2)) + 0x24);
            if (var160 < (*((*_0x20004BDC) + 0x90)))
            {
              r0 = *local_0x28;
              r2 = *_0x457FE000_1;
              r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
              var161 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
              if (var161 < (*_0x457FE000_1))
              {
                s0 = *((*_0x20004BDC) + 0x98);
                r0 = *local_0x28;
                s2 = *((*_0x20004BDC) + 0x94);
                r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
                var162 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
                r0 = *local_0x28;
                var163 = (*((*_0x20004BDC) + 0x98)) + (var162 * (*((*_0x20004BDC) + 0x94)));
                r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
                *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20) = var163;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var164 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_8) + (var164 << 0x2);
                var165 = *(((*_0x20001FD4_8) + (var164 << 0x2)) + 0x24);
                r1 = var165 + 0x1;
                *(((*_0x20001FD4_8) + (var164 << 0x2)) + 0x24) = var165 + 0x1;
              }
              else
              {
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var166 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                var167 = (var165 + 0x1) + (var166 << 0x2);
                *(var167 + 0x24) = 0x0;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var168 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                var169 = (var165 + 0x1) + (var168 << 0x2);
                *(var169 + 0x20) = 0x1;
              }

            }

          }

            break;

          case 0:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var152 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var152) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var152) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var153 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var153 << 0x2);
            var154 = *(((*_0x20001FD4_8) + (var153 << 0x2)) + 0x4);
            cond2 = var154 == 0;
            if (cond1 && cond2)
          {
            r0 = *local_0x28;
            s1 = *((*_0x20004BDC) + 0xAC);
            r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
            var155 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
            s1 = (*((*_0x20004BDC) + 0xAC)) - 1.000000e+00;
            r0 = *local_0x28;
            s0 = var155 * (*_0xBC4A458F);
            var156 = (var155 * (*_0xBC4A458F)) * ((*((*_0x20004BDC) + 0xAC)) - 1.000000e+00);
            s1 = var156 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xB0) = var156 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var157 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var157 << 0x2);
            *(((*_0x20001FD4_8) + (var157 << 0x2)) + 0x24) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var158 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var158 << 0x2);
            *(((*_0x20001FD4_8) + (var158 << 0x2)) + 0x20) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var159 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var159 << 0x2);
            r2 = *((*_0x20004BDC) + 0x90);
            var160 = *(((*_0x20001FD4_8) + (var159 << 0x2)) + 0x24);
            if (var160 < (*((*_0x20004BDC) + 0x90)))
            {
              r0 = *local_0x28;
              r2 = *_0x457FE000_1;
              r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
              var161 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
              if (var161 < (*_0x457FE000_1))
              {
                s0 = *((*_0x20004BDC) + 0x98);
                r0 = *local_0x28;
                s2 = *((*_0x20004BDC) + 0x94);
                r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
                var162 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
                r0 = *local_0x28;
                var163 = (*((*_0x20004BDC) + 0x98)) + (var162 * (*((*_0x20004BDC) + 0x94)));
                r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
                *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20) = var163;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var164 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_8) + (var164 << 0x2);
                var165 = *(((*_0x20001FD4_8) + (var164 << 0x2)) + 0x24);
                r1 = var165 + 0x1;
                *(((*_0x20001FD4_8) + (var164 << 0x2)) + 0x24) = var165 + 0x1;
              }
              else
              {
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var166 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                var167 = (var165 + 0x1) + (var166 << 0x2);
                *(var167 + 0x24) = 0x0;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var168 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                var169 = (var165 + 0x1) + (var168 << 0x2);
                *(var169 + 0x20) = 0x1;
              }

            }

          }

            break;

          case 0:
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var152 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var152) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var152) << 0x2)) == 0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var153 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var153 << 0x2);
            var154 = *(((*_0x20001FD4_8) + (var153 << 0x2)) + 0x4);
            cond2 = var154 == 0;
            if (cond1 && cond2)
          {
            r0 = *local_0x28;
            s1 = *((*_0x20004BDC) + 0xAC);
            r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
            var155 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
            s1 = (*((*_0x20004BDC) + 0xAC)) - 1.000000e+00;
            r0 = *local_0x28;
            s0 = var155 * (*_0xBC4A458F);
            var156 = (var155 * (*_0xBC4A458F)) * ((*((*_0x20004BDC) + 0xAC)) - 1.000000e+00);
            s1 = var156 / (*_0xBF7CD6EA);
            r0 = (*_0x20004BDC) + ((*local_0x28) << 0x2);
            *(((*_0x20004BDC) + ((*local_0x28) << 0x2)) + 0xB0) = var156 / (*_0xBF7CD6EA);
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var157 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var157 << 0x2);
            *(((*_0x20001FD4_8) + (var157 << 0x2)) + 0x24) = 0x0;
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var158 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var158 << 0x2);
            *(((*_0x20001FD4_8) + (var158 << 0x2)) + 0x20) = 0x3;
          }
          else
          {
            r0 = *local_0x28;
            r2 = (*local_0x28) + ((*local_0x28) << 0x1);
            var159 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
            r0 = (*_0x20001FD4_8) + (var159 << 0x2);
            r2 = *((*_0x20004BDC) + 0x90);
            var160 = *(((*_0x20001FD4_8) + (var159 << 0x2)) + 0x24);
            if (var160 < (*((*_0x20004BDC) + 0x90)))
            {
              r0 = *local_0x28;
              r2 = *_0x457FE000_1;
              r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
              var161 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
              if (var161 < (*_0x457FE000_1))
              {
                s0 = *((*_0x20004BDC) + 0x98);
                r0 = *local_0x28;
                s2 = *((*_0x20004BDC) + 0x94);
                r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
                var162 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
                r0 = *local_0x28;
                var163 = (*((*_0x20004BDC) + 0x98)) + (var162 * (*((*_0x20004BDC) + 0x94)));
                r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
                *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20) = var163;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var164 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                r0 = (*_0x20001FD4_8) + (var164 << 0x2);
                var165 = *(((*_0x20001FD4_8) + (var164 << 0x2)) + 0x24);
                r1 = var165 + 0x1;
                *(((*_0x20001FD4_8) + (var164 << 0x2)) + 0x24) = var165 + 0x1;
              }
              else
              {
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var166 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                var167 = (var165 + 0x1) + (var166 << 0x2);
                *(var167 + 0x24) = 0x0;
                r0 = *local_0x28;
                r2 = (*local_0x28) + ((*local_0x28) << 0x1);
                var168 = ((*local_0x28) + ((*local_0x28) << 0x1)) + ((*local_0x28) << 0x3);
                var169 = (var165 + 0x1) + (var168 << 0x2);
                *(var169 + 0x20) = 0x1;
              }

            }

          }

            break;

          case 1:
            *(var151 + 0x24) = *_0x20001FD4_8;
            break;

          case 1:
            *(var151 + 0x24) = *_0x20001FD4_8;
            break;

          case 1:
            *(var151 + 0x24) = *_0x20001FD4_8;
            break;

          case 1:
            *(var151 + 0x24) = *_0x20001FD4_8;
            break;

          case 2:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var170 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var170) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var170) << 0x2)) != 1;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var171 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var171 << 0x2);
            var172 = *(((*_0x20001FD4_8) + (var171 << 0x2)) + 0x4);
            cond2 = var172 != 1;
            if (cond1 && cond2)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var173 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var173 << 0x2);
            *(((*_0x20001FD4_8) + (var173 << 0x2)) + 0x24) = 0x0;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var174 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var174 << 0x2);
            *(((*_0x20001FD4_8) + (var174 << 0x2)) + 0x20) = 0x3;
          }
          else
          {
            r0 = *((*_0x20004BDC) + 0xD0);
            s0 = *((*_0x20004BDC) + 0xD0);
            r0 = *sp;
            s0 = (float) (*((*_0x20004BDC) + 0xD0));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = (float) (*((*_0x20004BDC) + 0xD0));
          }

            break;

          case 2:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var170 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var170) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var170) << 0x2)) != 1;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var171 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var171 << 0x2);
            var172 = *(((*_0x20001FD4_8) + (var171 << 0x2)) + 0x4);
            cond2 = var172 != 1;
            if (cond1 && cond2)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var173 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var173 << 0x2);
            *(((*_0x20001FD4_8) + (var173 << 0x2)) + 0x24) = 0x0;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var174 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var174 << 0x2);
            *(((*_0x20001FD4_8) + (var174 << 0x2)) + 0x20) = 0x3;
          }
          else
          {
            r0 = *((*_0x20004BDC) + 0xD0);
            s0 = *((*_0x20004BDC) + 0xD0);
            r0 = *sp;
            s0 = (float) (*((*_0x20004BDC) + 0xD0));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = (float) (*((*_0x20004BDC) + 0xD0));
          }

            break;

          case 2:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var170 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var170) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var170) << 0x2)) != 1;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var171 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var171 << 0x2);
            var172 = *(((*_0x20001FD4_8) + (var171 << 0x2)) + 0x4);
            cond2 = var172 != 1;
            if (cond1 && cond2)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var173 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var173 << 0x2);
            *(((*_0x20001FD4_8) + (var173 << 0x2)) + 0x24) = 0x0;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var174 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var174 << 0x2);
            *(((*_0x20001FD4_8) + (var174 << 0x2)) + 0x20) = 0x3;
          }
          else
          {
            r0 = *((*_0x20004BDC) + 0xD0);
            s0 = *((*_0x20004BDC) + 0xD0);
            r0 = *sp;
            s0 = (float) (*((*_0x20004BDC) + 0xD0));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = (float) (*((*_0x20004BDC) + 0xD0));
          }

            break;

          case 2:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var170 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = *(((*_0x20001FD4_8) + var170) << 0x2);
            cond1 = (*(((*_0x20001FD4_8) + var170) << 0x2)) != 1;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var171 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var171 << 0x2);
            var172 = *(((*_0x20001FD4_8) + (var171 << 0x2)) + 0x4);
            cond2 = var172 != 1;
            if (cond1 && cond2)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var173 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var173 << 0x2);
            *(((*_0x20001FD4_8) + (var173 << 0x2)) + 0x24) = 0x0;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var174 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var174 << 0x2);
            *(((*_0x20001FD4_8) + (var174 << 0x2)) + 0x20) = 0x3;
          }
          else
          {
            r0 = *((*_0x20004BDC) + 0xD0);
            s0 = *((*_0x20004BDC) + 0xD0);
            r0 = *sp;
            s0 = (float) (*((*_0x20004BDC) + 0xD0));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = (float) (*((*_0x20004BDC) + 0xD0));
          }

            break;

          case 3:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var175 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var175 << 0x2);
            r2 = *((*_0x20004BDC) + 0xA8);
            var176 = *(((*_0x20001FD4_8) + (var175 << 0x2)) + 0x24);
            if (var176 >= (*((*_0x20004BDC) + 0xA8)))
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var177 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var177 << 0x2);
            *(((*_0x20001FD4_8) + (var177 << 0x2)) + 0x24) = 0x0;
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var178 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            if (var178 > 0.0)
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var179 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var179 << 0x2);
              *(((*_0x20001FD4_8) + (var179 << 0x2)) + 0x20) = 0x6;
            }
            else
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var180 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var180 << 0x2);
              *(((*_0x20001FD4_8) + (var180 << 0x2)) + 0x20) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var181 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var181 << 0x2);
              *(((*_0x20001FD4_8) + (var181 << 0x2)) + 0x21) = 0x0;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20004BDC) + ((*sp) << 0x2);
            var182 = *(((*_0x20004BDC) + ((*sp) << 0x2)) + 0xB0);
            r0 = *sp;
            s2 = *((*_0x20004BDC) + 0xAC);
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var183 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            var184 = var182 + (var183 * (*((*_0x20004BDC) + 0xAC)));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = var184;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var185 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var185 << 0x2);
            var186 = *(((*_0x20001FD4_8) + (var185 << 0x2)) + 0x24);
            r1 = var186 + 0x1;
            *(((*_0x20001FD4_8) + (var185 << 0x2)) + 0x24) = var186 + 0x1;
          }

            break;

          case 3:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var175 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var175 << 0x2);
            r2 = *((*_0x20004BDC) + 0xA8);
            var176 = *(((*_0x20001FD4_8) + (var175 << 0x2)) + 0x24);
            if (var176 >= (*((*_0x20004BDC) + 0xA8)))
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var177 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var177 << 0x2);
            *(((*_0x20001FD4_8) + (var177 << 0x2)) + 0x24) = 0x0;
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var178 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            if (var178 > 0.0)
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var179 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var179 << 0x2);
              *(((*_0x20001FD4_8) + (var179 << 0x2)) + 0x20) = 0x6;
            }
            else
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var180 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var180 << 0x2);
              *(((*_0x20001FD4_8) + (var180 << 0x2)) + 0x20) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var181 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var181 << 0x2);
              *(((*_0x20001FD4_8) + (var181 << 0x2)) + 0x21) = 0x0;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20004BDC) + ((*sp) << 0x2);
            var182 = *(((*_0x20004BDC) + ((*sp) << 0x2)) + 0xB0);
            r0 = *sp;
            s2 = *((*_0x20004BDC) + 0xAC);
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var183 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            var184 = var182 + (var183 * (*((*_0x20004BDC) + 0xAC)));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = var184;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var185 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var185 << 0x2);
            var186 = *(((*_0x20001FD4_8) + (var185 << 0x2)) + 0x24);
            r1 = var186 + 0x1;
            *(((*_0x20001FD4_8) + (var185 << 0x2)) + 0x24) = var186 + 0x1;
          }

            break;

          case 3:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var175 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var175 << 0x2);
            r2 = *((*_0x20004BDC) + 0xA8);
            var176 = *(((*_0x20001FD4_8) + (var175 << 0x2)) + 0x24);
            if (var176 >= (*((*_0x20004BDC) + 0xA8)))
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var177 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var177 << 0x2);
            *(((*_0x20001FD4_8) + (var177 << 0x2)) + 0x24) = 0x0;
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var178 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            if (var178 > 0.0)
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var179 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var179 << 0x2);
              *(((*_0x20001FD4_8) + (var179 << 0x2)) + 0x20) = 0x6;
            }
            else
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var180 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var180 << 0x2);
              *(((*_0x20001FD4_8) + (var180 << 0x2)) + 0x20) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var181 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var181 << 0x2);
              *(((*_0x20001FD4_8) + (var181 << 0x2)) + 0x21) = 0x0;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20004BDC) + ((*sp) << 0x2);
            var182 = *(((*_0x20004BDC) + ((*sp) << 0x2)) + 0xB0);
            r0 = *sp;
            s2 = *((*_0x20004BDC) + 0xAC);
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var183 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            var184 = var182 + (var183 * (*((*_0x20004BDC) + 0xAC)));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = var184;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var185 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var185 << 0x2);
            var186 = *(((*_0x20001FD4_8) + (var185 << 0x2)) + 0x24);
            r1 = var186 + 0x1;
            *(((*_0x20001FD4_8) + (var185 << 0x2)) + 0x24) = var186 + 0x1;
          }

            break;

          case 3:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var175 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var175 << 0x2);
            r2 = *((*_0x20004BDC) + 0xA8);
            var176 = *(((*_0x20001FD4_8) + (var175 << 0x2)) + 0x24);
            if (var176 >= (*((*_0x20004BDC) + 0xA8)))
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var177 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var177 << 0x2);
            *(((*_0x20001FD4_8) + (var177 << 0x2)) + 0x24) = 0x0;
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var178 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            if (var178 > 0.0)
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var179 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var179 << 0x2);
              *(((*_0x20001FD4_8) + (var179 << 0x2)) + 0x20) = 0x6;
            }
            else
            {
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var180 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var180 << 0x2);
              *(((*_0x20001FD4_8) + (var180 << 0x2)) + 0x20) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var181 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var181 << 0x2);
              *(((*_0x20001FD4_8) + (var181 << 0x2)) + 0x21) = 0x0;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20004BDC) + ((*sp) << 0x2);
            var182 = *(((*_0x20004BDC) + ((*sp) << 0x2)) + 0xB0);
            r0 = *sp;
            s2 = *((*_0x20004BDC) + 0xAC);
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var183 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            var184 = var182 + (var183 * (*((*_0x20004BDC) + 0xAC)));
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = var184;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var185 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var185 << 0x2);
            var186 = *(((*_0x20001FD4_8) + (var185 << 0x2)) + 0x24);
            r1 = var186 + 0x1;
            *(((*_0x20001FD4_8) + (var185 << 0x2)) + 0x24) = var186 + 0x1;
          }

            break;

          case 4:
            r1 = *(var151 + 0x24);
            r1 = (*(var151 + 0x24)) + 0x1;
            *(var151 + 0x24) = (*(var151 + 0x24)) + 0x1;
            break;

          case 4:
            r1 = *(var151 + 0x24);
            r1 = (*(var151 + 0x24)) + 0x1;
            *(var151 + 0x24) = (*(var151 + 0x24)) + 0x1;
            break;

          case 4:
            r1 = *(var151 + 0x24);
            r1 = (*(var151 + 0x24)) + 0x1;
            *(var151 + 0x24) = (*(var151 + 0x24)) + 0x1;
            break;

          case 4:
            r1 = *(var151 + 0x24);
            r1 = (*(var151 + 0x24)) + 0x1;
            *(var151 + 0x24) = (*(var151 + 0x24)) + 0x1;
            break;

          case 5:
            r1 = *(var151 + 0x24);
            r1 = (*(var151 + 0x24)) + 0x1;
            *(var151 + 0x24) = (*(var151 + 0x24)) + 0x1;
            break;

          case 5:
            r1 = *(var151 + 0x24);
            r1 = (*(var151 + 0x24)) + 0x1;
            *(var151 + 0x24) = (*(var151 + 0x24)) + 0x1;
            break;

          case 5:
            r1 = *(var151 + 0x24);
            r1 = (*(var151 + 0x24)) + 0x1;
            *(var151 + 0x24) = (*(var151 + 0x24)) + 0x1;
            break;

          case 5:
            r1 = *(var151 + 0x24);
            r1 = (*(var151 + 0x24)) + 0x1;
            *(var151 + 0x24) = (*(var151 + 0x24)) + 0x1;
            break;

          case 6:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var187 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var187 << 0x2);
            var188 = *(((*_0x20001FD4_8) + (var187 << 0x2)) + 0x24);
            if (var188 != 0)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var189 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var189 << 0x2);
            var190 = *(((*_0x20001FD4_8) + (var189 << 0x2)) + 0x24);
            if (var190 < 0x14)
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              var191 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x60);
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var192 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var192 << 0x2);
              var193 = *(((*_0x20001FD4_8) + (var192 << 0x2)) + 0x24);
              r0 = 0x14 - var193;
              s0 = 0x14 - var193;
              s0 = (float) (0x14 - var193);
              var194 = var191 * ((float) (0x14 - var193));
              s1 = var194 / 2.000000e+01;
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = var194 / 2.000000e+01;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var195 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var195 << 0x2);
              var196 = *(((*_0x20001FD4_8) + (var195 << 0x2)) + 0x24);
              r1 = var196 + 0x1;
              *(((*_0x20001FD4_8) + (var195 << 0x2)) + 0x24) = var196 + 0x1;
            }
            else
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = *_0x00000000;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var197 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var198 = (var196 + 0x1) + (var197 << 0x2);
              *(var198 + 0x24) = 0x0;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var199 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var200 = (var196 + 0x1) + (var199 << 0x2);
              *(var200 + 0x20) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var201 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var202 = (var196 + 0x1) + (var201 << 0x2);
              *(var202 + 0x21) = 0x0;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var203 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x60) = var203;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var204 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var204 << 0x2);
            var205 = *(((*_0x20001FD4_8) + (var204 << 0x2)) + 0x24);
            r1 = var205 + 0x1;
            *(((*_0x20001FD4_8) + (var204 << 0x2)) + 0x24) = var205 + 0x1;
          }

            break;

          case 6:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var187 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var187 << 0x2);
            var188 = *(((*_0x20001FD4_8) + (var187 << 0x2)) + 0x24);
            if (var188 != 0)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var189 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var189 << 0x2);
            var190 = *(((*_0x20001FD4_8) + (var189 << 0x2)) + 0x24);
            if (var190 < 0x14)
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              var191 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x60);
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var192 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var192 << 0x2);
              var193 = *(((*_0x20001FD4_8) + (var192 << 0x2)) + 0x24);
              r0 = 0x14 - var193;
              s0 = 0x14 - var193;
              s0 = (float) (0x14 - var193);
              var194 = var191 * ((float) (0x14 - var193));
              s1 = var194 / 2.000000e+01;
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = var194 / 2.000000e+01;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var195 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var195 << 0x2);
              var196 = *(((*_0x20001FD4_8) + (var195 << 0x2)) + 0x24);
              r1 = var196 + 0x1;
              *(((*_0x20001FD4_8) + (var195 << 0x2)) + 0x24) = var196 + 0x1;
            }
            else
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = *_0x00000000;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var197 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var198 = (var196 + 0x1) + (var197 << 0x2);
              *(var198 + 0x24) = 0x0;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var199 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var200 = (var196 + 0x1) + (var199 << 0x2);
              *(var200 + 0x20) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var201 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var202 = (var196 + 0x1) + (var201 << 0x2);
              *(var202 + 0x21) = 0x0;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var203 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x60) = var203;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var204 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var204 << 0x2);
            var205 = *(((*_0x20001FD4_8) + (var204 << 0x2)) + 0x24);
            r1 = var205 + 0x1;
            *(((*_0x20001FD4_8) + (var204 << 0x2)) + 0x24) = var205 + 0x1;
          }

            break;

          case 6:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var187 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var187 << 0x2);
            var188 = *(((*_0x20001FD4_8) + (var187 << 0x2)) + 0x24);
            if (var188 != 0)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var189 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var189 << 0x2);
            var190 = *(((*_0x20001FD4_8) + (var189 << 0x2)) + 0x24);
            if (var190 < 0x14)
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              var191 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x60);
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var192 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var192 << 0x2);
              var193 = *(((*_0x20001FD4_8) + (var192 << 0x2)) + 0x24);
              r0 = 0x14 - var193;
              s0 = 0x14 - var193;
              s0 = (float) (0x14 - var193);
              var194 = var191 * ((float) (0x14 - var193));
              s1 = var194 / 2.000000e+01;
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = var194 / 2.000000e+01;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var195 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var195 << 0x2);
              var196 = *(((*_0x20001FD4_8) + (var195 << 0x2)) + 0x24);
              r1 = var196 + 0x1;
              *(((*_0x20001FD4_8) + (var195 << 0x2)) + 0x24) = var196 + 0x1;
            }
            else
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = *_0x00000000;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var197 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var198 = (var196 + 0x1) + (var197 << 0x2);
              *(var198 + 0x24) = 0x0;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var199 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var200 = (var196 + 0x1) + (var199 << 0x2);
              *(var200 + 0x20) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var201 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var202 = (var196 + 0x1) + (var201 << 0x2);
              *(var202 + 0x21) = 0x0;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var203 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x60) = var203;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var204 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var204 << 0x2);
            var205 = *(((*_0x20001FD4_8) + (var204 << 0x2)) + 0x24);
            r1 = var205 + 0x1;
            *(((*_0x20001FD4_8) + (var204 << 0x2)) + 0x24) = var205 + 0x1;
          }

            break;

          case 6:
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var187 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var187 << 0x2);
            var188 = *(((*_0x20001FD4_8) + (var187 << 0x2)) + 0x24);
            if (var188 != 0)
          {
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var189 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var189 << 0x2);
            var190 = *(((*_0x20001FD4_8) + (var189 << 0x2)) + 0x24);
            if (var190 < 0x14)
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              var191 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x60);
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var192 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var192 << 0x2);
              var193 = *(((*_0x20001FD4_8) + (var192 << 0x2)) + 0x24);
              r0 = 0x14 - var193;
              s0 = 0x14 - var193;
              s0 = (float) (0x14 - var193);
              var194 = var191 * ((float) (0x14 - var193));
              s1 = var194 / 2.000000e+01;
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = var194 / 2.000000e+01;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var195 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              r0 = (*_0x20001FD4_8) + (var195 << 0x2);
              var196 = *(((*_0x20001FD4_8) + (var195 << 0x2)) + 0x24);
              r1 = var196 + 0x1;
              *(((*_0x20001FD4_8) + (var195 << 0x2)) + 0x24) = var196 + 0x1;
            }
            else
            {
              r0 = *sp;
              r0 = (*_0x20005088) + ((*sp) << 0x2);
              *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20) = *_0x00000000;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var197 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var198 = (var196 + 0x1) + (var197 << 0x2);
              *(var198 + 0x24) = 0x0;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var199 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var200 = (var196 + 0x1) + (var199 << 0x2);
              *(var200 + 0x20) = 0x4;
              r0 = *sp;
              r2 = (*sp) + ((*sp) << 0x1);
              var201 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
              var202 = (var196 + 0x1) + (var201 << 0x2);
              *(var202 + 0x21) = 0x0;
            }

          }
          else
          {
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            var203 = *(((*_0x20005088) + ((*sp) << 0x2)) + 0x20);
            r0 = *sp;
            r0 = (*_0x20005088) + ((*sp) << 0x2);
            *(((*_0x20005088) + ((*sp) << 0x2)) + 0x60) = var203;
            r0 = *sp;
            r2 = (*sp) + ((*sp) << 0x1);
            var204 = ((*sp) + ((*sp) << 0x1)) + ((*sp) << 0x3);
            r0 = (*_0x20001FD4_8) + (var204 << 0x2);
            var205 = *(((*_0x20001FD4_8) + (var204 << 0x2)) + 0x24);
            r1 = var205 + 0x1;
            *(((*_0x20001FD4_8) + (var204 << 0x2)) + 0x24) = var205 + 0x1;
          }

            break;

        }

      }

      r0 = func_0x7D1C(r0);
      if (func_0x7D1C(r0) != 0)
      {
        r0 = *local_0x28;
        fp = *string_h_6;
        r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
        s0 = *((*_0x20005088) + ((*local_0x28) << 0x2));
        s1 = *((*string_h_6) + 0x8);
        var206 = (unsigned int) (*((*_0x20005088) + ((*local_0x28) << 0x2)));
        r0 = var206;
        r0 = (unsigned int) var206;
        s0 = (unsigned int) var206;
        s0 = (float) ((unsigned int) var206);
        var207 = ((float) ((unsigned int) var206)) * (*((*string_h_6) + 0x8));
        s0 = (unsigned int) var207;
        r0 = (unsigned int) var207;
        r0 = (unsigned int) ((unsigned int) var207);
        r0 = get_point_on_2A024_curve(r0);
        r1 = *local_0x28;
        r2 = *local_0x28;
        r1 = (*local_0x28) << 0x1E;
        r1 = ((*local_0x28) << 0x1E) >> 0x1D;
        r3 = 0x6 + ((*local_0x28) >> 0x2);
        r2 = get_point_on_2A024_curve(r0);
        r0 = 0x6 + ((*local_0x28) >> 0x2);
        play_note_in_mem_on_voice_p1_note_p2_vol_p3(r0, r1, r2);
        r0 = *local_0x28;
        s1 = *((*string_h_6) + 0x8);
        r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
        var208 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
        s0 = (unsigned int) var208;
        r0 = (unsigned int) var208;
        r0 = (unsigned int) ((unsigned int) var208);
        s0 = (unsigned int) ((unsigned int) var208);
        s0 = (float) ((unsigned int) ((unsigned int) var208));
        var209 = ((float) ((unsigned int) ((unsigned int) var208))) * (*((*string_h_6) + 0x8));
        s0 = (unsigned int) var209;
        r0 = (unsigned int) var209;
        r0 = (unsigned int) ((unsigned int) var209);
        r0 = get_point_on_2A024_curve(r0);
        r2 = get_point_on_2A024_curve(r0);
        r0 = *local_0x28;
        r0 = (*local_0x28) & 0x3;
        var210 = 0x1 + (((*local_0x28) & 0x3) << 0x1);
        r0 = *local_0x28;
        r0 = 0x6 + ((*local_0x28) >> 0x2);
        play_note_in_mem_on_voice_p1_note_p2_vol_p3(r0, r1, r2);
      }
      else
      {
        r0 = *local_0x28;
        r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
        s0 = *((*_0x20005088) + ((*local_0x28) << 0x2));
        var211 = (unsigned int) (*((*_0x20005088) + ((*local_0x28) << 0x2)));
        r0 = var211;
        r0 = (unsigned int) var211;
        if (((unsigned int) var211) >= 0x1000)
        {
          r0 = 0xFFF;
        }

        fp = *string_dT;
        r1 = *local_0x28;
        r1 = *(((*string_dT) + (*local_0x28)) << 0x2);
        s0 = *(((*string_dT) + (*local_0x28)) << 0x2);
        r1 = *string_h_6;
        var212 = (float) (*(((*string_dT) + (*local_0x28)) << 0x2));
        s1 = *((*string_h_6) + 0x8);
        r1 = *_0x0803E4DC;
        r0 = (*_0x0803E4DC) + (0xFFF << 0x2);
        s0 = var212 * (*((*string_h_6) + 0x8));
        s1 = *((*_0x0803E4DC) + (0xFFF << 0x2));
        var213 = (var212 * (*((*string_h_6) + 0x8))) * (*((*_0x0803E4DC) + (0xFFF << 0x2)));
        s0 = (unsigned int) var213;
        r0 = (unsigned int) var213;
        r0 = (unsigned int) ((unsigned int) var213);
        if (((unsigned int) ((unsigned int) var213)) >= 0x1000)
        {
          r0 = 0xFFF;
        }

        r0 = 0xFFF >> 0x2;
        r0 = get_point_on_2A024_curve(r0);
        r1 = *local_0x28;
        r2 = *local_0x28;
        r1 = (*local_0x28) << 0x1E;
        r1 = ((*local_0x28) << 0x1E) >> 0x1D;
        r3 = 0x6 + ((*local_0x28) >> 0x2);
        r2 = get_point_on_2A024_curve(r0);
        r0 = 0x6 + ((*local_0x28) >> 0x2);
        play_note_in_mem_on_voice_p1_note_p2_vol_p3(r0, r1, r2);
        r0 = *local_0x28;
        r0 = (*_0x20005088) + ((*local_0x28) << 0x2);
        var214 = *(((*_0x20005088) + ((*local_0x28) << 0x2)) + 0x20);
        s0 = (unsigned int) var214;
        r0 = (unsigned int) var214;
        r0 = (unsigned int) ((unsigned int) var214);
        if (((unsigned int) ((unsigned int) var214)) >= 0x1000)
        {
          r0 = 0xFFF;
        }

        r1 = *local_0x28;
        r1 = (*string_dT) + ((*local_0x28) << 0x2);
        var215 = *(((*string_dT) + ((*local_0x28) << 0x2)) + 0x2);
        s0 = var215;
        r1 = *string_h_6;
        s0 = (float) var215;
        s1 = *((*string_h_6) + 0x8);
        r1 = *_0x0803E4DC;
        r0 = (*_0x0803E4DC) + (0xFFF << 0x2);
        var216 = ((float) var215) * (*((*string_h_6) + 0x8));
        s1 = *((*_0x0803E4DC) + (0xFFF << 0x2));
        var217 = var216 * (*((*_0x0803E4DC) + (0xFFF << 0x2)));
        s0 = (unsigned int) var217;
        r0 = (unsigned int) var217;
        r0 = (unsigned int) ((unsigned int) var217);
        if (((unsigned int) ((unsigned int) var217)) >= 0x1000)
        {
          r0 = 0xFFF;
        }

        r0 = 0xFFF >> 0x2;
        r0 = get_point_on_2A024_curve(r0);
        r2 = get_point_on_2A024_curve(r0);
        r0 = *local_0x28;
        r0 = (*local_0x28) & 0x3;
        var218 = 0x1 + (((*local_0x28) & 0x3) << 0x1);
        r0 = *local_0x28;
        r0 = 0x6 + ((*local_0x28) >> 0x2);
        play_note_in_mem_on_voice_p1_note_p2_vol_p3(r0, r1, r2);
      }

      r0 = *data_0x161AC;
      r1 = *local_0x28;
      r1 = *((*data_0x161AC) + (*local_0x28));
      if ((*((*data_0x161AC) + (*local_0x28))) == 1)
      {
        r1 = *local_0x28;
        *((*data_0x161AC) + (*local_0x28)) = 0x0;
      }

      r1 = *local_0x28;
      r0 = *((*data_0x161AC) + (*local_0x28));
      r1 = *local_0x28;
      r0 = func_0x2610(r0, r1);
      if (func_0x2610(r0, r1) > 0x7F)
      {
        r0 = 0x7F;
      }

      r1 = *_0x08042D24;
      r0 = (*_0x08042D24) + (0x7F << 0x2);
      r1 = *local_0x28;
      s0 = *((*_0x08042D24) + (0x7F << 0x2));
      r0 = *_0x20005484;
      r0 = (*_0x20005484) + ((*local_0x28) << 0x2);
      *((*_0x20005484) + ((*local_0x28) << 0x2)) = *((*_0x08042D24) + (0x7F << 0x2));
      r0 = *local_0x28;
      r0 = (*local_0x28) + 0x1;
      *local_0x28 = (*local_0x28) + 0x1;
      r0 = two_or_four_or_with_20000F30();
      r1 = *local_0x28;
      if (two_or_four_or_with_20000F30() < (*local_0x28))
      {
        break;
      }

    }

  }

  sp = sp + 0x4;
}

