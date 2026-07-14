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
      r0 = *(r0 + 0x1);
      cond1 = r0 == 1;
      sb = *_0x2000562C;
      r1 = *((sl + r4) << 0x1);
      r2 = *((sb + r4) << 0x1);
      cond2 = r1 <= r2;
      if (cond1 && cond2)
      {
        r0 = r4 + (r4 << 0x1);
        r0 = r0 + (r4 << 0x3);
        r5 = fp + (r0 << 0x2);
        r0 = *(r5 + 0x5);
        func_0x8054(r0);
        r1 = 0x0;
        r0 = r4;
        func_0x19E80(r0, r1, r2);
        s0 = func_0x19E80(r4, 0);
        s16 = s0;
        r0 = *_0x20000B8B;
        r0 = *(r0 + r4);
        func_0x8054(r0);
        r1 = 0x0;
        r0 = r4;
        func_0x19E80(r0, r1, r2);
        s0 = func_0x19E80(0, r4);
        s1 = s16 - s0;
        r0 = sb - 0x30;
        r8 = r0 + (r4 << 0x2);
        r0 = r0 + 0x30;
        s4 = *r8;
        r0 = *((r0 + r4) << 0x1);
        r1 = *((sl + r4) << 0x1);
        s2 = r0;
        r2 = *_0x20000B8B;
        s2 = (float) s2;
        r2 = *(r2 + r4);
        s3 = s4 / s2;
        s2 = r1;
        s2 = (float) s2;
        s2 = s3 * s2;
        s2 = (int) s2;
        r3 = s2;
        r2 = r2 + ((int) ((char) r3));
        r3 = *_0x20000B83;
        *(r3 + r4) = r2;
        if (r0 != 0)
        {
          s2 = r0;
          s3 = (float) s2;
          s2 = s1 / s3;
          s1 = r1;
          s1 = (float) s1;
          s0 = s0 + (s2 * s1);
        }

        r0 = *_0x20005088_1;
        sb = r0 + (r4 << 0x2);
        s1 = *sb;
        if (s1 == 0.0)
        {
          r0 = r4 << 0x1F;
          r1 = r0 >> 0x1E;
          r0 = r4 >> 0x1;
          r2 = 0x0;
          func_0x9C74(r0, r1, r2);
        }
        else
        {
          r0 = r4 << 0x19;
          r0 = r0 >> 0x18;
          r0 = func_0x1D3B8(r0);
          r1 = *((r7 + r4) << 0x2);
          r2 = r0 + r1;
          r0 = r4 << 0x1F;
          r1 = r0 >> 0x1E;
          r0 = r4 >> 0x1;
          func_0x9C74(r0, r1, r2);
        }

        r0 = *(r5 + 0x5);
        func_0x8054(r0);
        r1 = 0x1;
        r0 = r4;
        func_0x19E80(r0, r1, r2);
        s16 = s0;
        r5 = *_0x20000B8B;
        r0 = *(r5 + r4);
        func_0x8054(r0);
        r1 = 0x1;
        r0 = r4;
        func_0x19E80(r0, r1, r2);
        s1 = s16 - s0;
        r0 = *_0x2000562C;
        s3 = *r8;
        r1 = *((sl + r4) << 0x1);
        r0 = *((r0 + r4) << 0x1);
        r3 = *(r5 + r4);
        s2 = r0;
        s2 = (float) s2;
        s4 = s3 / s2;
        s2 = r1;
        s2 = (float) s2;
        s2 = s4 * s2;
        s2 = (int) s2;
        r2 = s2;
        r2 = r3 + ((int) ((char) r2));
        r3 = r5 - 0x8;
        *(r3 + r4) = r2;
        if (r0 != 0)
        {
          s2 = r0;
          s3 = (float) s2;
          s2 = s1 / s3;
          s1 = r1;
          s1 = (float) s1;
          s0 = s0 + (s2 * s1);
        }

        s1 = *(sb + 0x20);
        if (s1 == 0)
        {
          r0 = r4 & 0x1;
          r1 = r6 + (r0 << 0x1);
          r0 = r4 >> 0x1;
          r2 = 0x0;
          func_0x9C74(r0, r1, r2);
        }
        else
        {
          r3 = r6 + (r4 << 0x1);
          r0 = (unsigned int) r3;
          r0 = func_0x1D3B8(r0);
          r1 = *((r7 + r3) << 0x1);
          r2 = r0 + r1;
          r0 = r4 & 0x1;
          r1 = r6 + (r0 << 0x1);
          r0 = r4 >> 0x1;
          func_0x9C74(r0, r1, r2);
        }

        r0 = *((sl + r4) << 0x1);
        r0 = r0 + 0x1;
        *((sl + r4) << 0x1) = r0;
      }
      else
      {
        cond1 = r0 == 2;
        r2 = *_0x2000562C;
        r0 = *((sl + r4) << 0x1);
        r1 = *((r2 + r4) << 0x1);
        cond2 = r0 <= r1;
        if (cond1 && cond2)
        {
          s0 = r1;
          r3 = r2 - 0x30;
          r5 = r3 + (r4 << 0x2);
          s0 = (float) s0;
          s1 = *r5;
          sb = *_0x20000B8B;
          s2 = s1 / s0;
          s0 = r0;
          r1 = *(sb + r4);
          s0 = (float) s0;
          s0 = s2 * s0;
          s0 = (int) s0;
          r0 = s0;
          r0 = r1 + ((int) ((char) r0));
          r1 = sb - 0x8;
          *(r1 + r4) = r0;
          r0 = r4 + (r4 << 0x1);
          r0 = r0 + (r4 << 0x3);
          r8 = fp + (r0 << 0x2);
          r0 = *(r8 + 0x5);
          func_0x8054(r0);
          r1 = 0x0;
          r0 = r4;
          func_0x19E80(r0, r1, r2);
          r0 = *(sb + r4);
          func_0x8054(r0);
          r1 = 0x0;
          r0 = r4;
          func_0x19E80(r0, r1, r2);
          r0 = *_0x2000562C;
          r0 = *((r0 + r4) << 0x1);
          if (r0 != 0)
          {
            s1 = r0;
            s2 = *r5;
            r0 = *((sl + r4) << 0x1);
            s1 = (float) s1;
            s3 = s2 / s1;
            s1 = r0;
            s1 = (float) s1;
            s1 = s3 * s1;
            s1 = (int) s1;
            r0 = s1;
            r0 = (int) r0;
            s1 = r0;
            s1 = (float) s1;
            s0 = s1 + s0;
          }

          r0 = *_0x20005088_1;
          sb = r0 + (r4 << 0x2);
          s1 = *sb;
          if (s1 == 0.0)
          {
            r0 = r4 << 0x1F;
            r1 = r0 >> 0x1E;
            r0 = r4 >> 0x1;
            r2 = 0x0;
            func_0x9C74(r0, r1, r2);
          }
          else
          {
            r0 = r4 << 0x19;
            r0 = r0 >> 0x18;
            r0 = func_0x1D3B8(r0);
            r1 = *((r7 + r4) << 0x2);
            r2 = r0 + r1;
            r0 = r4 << 0x1F;
            r1 = r0 >> 0x1E;
            r0 = r4 >> 0x1;
            func_0x9C74(r0, r1, r2);
          }

          r0 = *(r8 + 0x5);
          func_0x8054(r0);
          r1 = 0x1;
          r0 = r4;
          func_0x19E80(r0, r1, r2);
          r0 = *_0x20000B8B;
          r0 = *(r0 + r4);
          func_0x8054(r0);
          r1 = 0x1;
          r0 = r4;
          func_0x19E80(r0, r1, r2);
          r0 = *_0x2000562C;
          r0 = *((r0 + r4) << 0x1);
          if (r0 != 0)
          {
            s1 = r0;
            s3 = *r5;
            r0 = *((sl + r4) << 0x1);
            s1 = (float) s1;
            s2 = s3 / s1;
            s1 = r0;
            s1 = (float) s1;
            s1 = s2 * s1;
            s1 = (int) s1;
            r0 = s1;
            r0 = (int) r0;
            s1 = r0;
            s1 = (float) s1;
            s0 = s1 + s0;
          }

          s1 = *(sb + 0x20);
          if (s1 == 0.0)
          {
            r0 = r4 & 0x1;
            r1 = r6 + (r0 << 0x1);
            r0 = r4 >> 0x1;
            r2 = 0x0;
            func_0x9C74(r0, r1, r2);
          }
          else
          {
            r3 = r6 + (r4 << 0x1);
            r0 = (unsigned int) r3;
            r0 = func_0x1D3B8(r0);
            r1 = *((r7 + r3) << 0x1);
            r2 = r0 + r1;
            r0 = r4 & 0x1;
            r1 = r6 + (r0 << 0x1);
            r0 = r4 >> 0x1;
            func_0x9C74(r0, r1, r2);
          }

          r0 = *((sl + r4) << 0x1);
          r0 = r0 + 0x1;
          *((sl + r4) << 0x1) = r0;
        }
        else
        {
          r8 = *data_0x14BB4;
          r1 = *((r8 + r4) << 0x1);
          if (r1 != 0)
          {
            r0 = r4 + (r4 << 0x1);
            r0 = r0 + (r4 << 0x3);
            sb = fp + (r0 << 0x2);
            r2 = *_0x20000B83;
            r0 = *(sb + 0x5);
            *(r2 + r4) = r0;
            r1 = r1 - 0x1;
            *((r8 + r4) << 0x1) = r1;
            func_0x8054(r0);
            r1 = 0x0;
            r0 = r4;
            func_0x19E80(r0, r1, r2);
            r0 = *((r8 + r4) << 0x1);
            s1 = r0;
            s2 = (float) s1;
            s1 = s2 / s17;
            s0 = s0 - s1;
            r0 = *_0x20005088_1;
            r5 = r0 + (r4 << 0x2);
            s1 = *r5;
            if (s1 == 0.0)
            {
              r0 = r4 << 0x1F;
              r1 = r0 >> 0x1E;
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r0, r1, r2);
            }
            else
            {
              r0 = r4 << 0x19;
              r0 = r0 >> 0x18;
              r0 = func_0x1D3B8(r0);
              r1 = *((r7 + r4) << 0x2);
              r2 = r0 + r1;
              r0 = r4 << 0x1F;
              r1 = r0 >> 0x1E;
              r0 = r4 >> 0x1;
              func_0x9C74(r0, r1, r2);
            }

            r0 = *(sb + 0x5);
            func_0x8054(r0);
            r1 = 0x1;
            r0 = r4;
            func_0x19E80(r0, r1, r2);
            r0 = *((r8 + r4) << 0x1);
            s1 = r0;
            s2 = (float) s1;
            s1 = s2 / s17;
            s0 = s0 - s1;
            s1 = *(r5 + 0x20);
            if (s1 == 0.0)
            {
              r0 = r4 & 0x1;
              r1 = r6 + (r0 << 0x1);
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r0, r1, r2);
            }
            else
            {
              r3 = r6 + (r4 << 0x1);
              r0 = (unsigned int) r3;
              r0 = func_0x1D3B8(r0);
              r1 = *((r7 + r3) << 0x1);
              r2 = r0 + r1;
              r0 = r4 & 0x1;
              r1 = r6 + (r0 << 0x1);
              r0 = r4 >> 0x1;
              func_0x9C74(r0, r1, r2);
            }

          }
          else
          {
            r0 = r4 + (r4 << 0x1);
            r0 = r0 + (r4 << 0x3);
            r5 = fp + (r0 << 0x2);
            r1 = *_0x20000B83_1;
            r0 = *(r5 + 0x5);
            *(r1 + r4) = r0;
            func_0x8054(r0);
            r1 = 0x0;
            r0 = r4;
            func_0x19E80(r0, r1, r2);
            r0 = *_0x20005088_2;
            r8 = r0 + (r4 << 0x2);
            s1 = *r8;
            if (s1 == 0.0)
            {
              r0 = r4 << 0x1F;
              r1 = r0 >> 0x1E;
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r0, r1, r2);
            }
            else
            {
              r0 = r4 << 0x19;
              r0 = r0 >> 0x18;
              r0 = func_0x1D3B8(r0);
              r1 = *((r7 + r4) << 0x2);
              r2 = r0 + r1;
              r0 = r4 << 0x1F;
              r1 = r0 >> 0x1E;
              r0 = r4 >> 0x1;
              func_0x9C74(r0, r1, r2);
            }

            r0 = *(r5 + 0x5);
            func_0x8054(r0);
            r1 = 0x1;
            r0 = r4;
            func_0x19E80(r0, r1, r2);
            s1 = *(r8 + 0x20);
            if (s1 == 0.0)
            {
              r0 = r4 & 0x1;
              r1 = r6 + (r0 << 0x1);
              r0 = r4 >> 0x1;
              r2 = 0x0;
              func_0x9C74(r0, r1, r2);
            }
            else
            {
              r3 = r6 + (r4 << 0x1);
              r0 = (unsigned int) r3;
              r0 = func_0x1D3B8(r0);
              r1 = *((r7 + r3) << 0x1);
              r2 = r0 + r1;
              r0 = r4 & 0x1;
              r1 = r6 + (r0 << 0x1);
              r0 = r4 >> 0x1;
              func_0x9C74(r0, r1, r2);
            }

          }

        }

      }

      r0 = r4 + 0x1;
      r4 = (unsigned int) r0;
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

