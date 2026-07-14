void func_0x9498(int p1)
{
  sp = sp - 0xA4;
  r6 = r0;
  r0 = func_0xB9B4(r0);
  r0 = r0 + (r0 << 0x1);
  var0 = (r0 + (r0 << 0x1)) + (r0 << 0x3);
  r8 = (*data_0x98A4) + (var0 << 0x2);
  if (func_0xB9B4(r0) != 2)
  {
    r0 = func_0xB9B4(var0);
    if (func_0xB9B4(var0) != 0)
    {
      var1 = *(((*data_0x98A4) + (var0 << 0x2)) + 0x7);
      *((*data_0x98A0) + r0) = var1;
    }
    else
    {
      r0 = *(*data_0x98BC);
      *((*data_0x98A0) + r0) = *(*data_0x98BC);
    }

  }
  else
  {
    var2 = *(((*data_0x98A4) + (var0 << 0x2)) + 0x7);
    *((*data_0x98A0) + r0) = var2;
  }

  r0 = 0x3D;
  r0 = func_0x1D184(0x3D, func_0xB9B4(r0), *data_0x98A4);
  var3 = (*data_0x98A8) + ((0xFF - func_0x1D184(0x3D, func_0xB9B4(r0), *data_0x98A4)) << 0x3);
  r0 = *data_0x98AC;
  r0 = (*data_0x98AC) + (r0 << 0x2);
  *local_0x2C = (*data_0x98AC) + (r0 << 0x2);
  *local_0x30 = (*data_0x98B0) + (r0 << 0x1);
  var4 = (*var3) * (*((*data_0x98AC) + (r0 << 0x2)));
  r0 = (int) ((int) var4);
  *(((*data_0x98B0) + (r0 << 0x1)) + 0x4C) = (int) ((int) var4);
  if (((int) ((int) var4)) >= 0x200)
  {
    *((*local_0x30) + 0x4C) = 0x1FF;
  }

  r4 = 0x0;
  sb = (*string_tR_1) + (r0 << 0x2);
  r0 = (*string_tR_1) + 0x1B0;
  var5 = ((*string_tR_1) + 0x1B0) + (r0 << 0x3);
  *local_0x34 = var5;
  r0 = r0 & 0x3;
  *local_0x44 = r0 & 0x3;
  var6 = 0x0 + ((r0 & 0x3) << 0x1);
  *local_0x38 = var6;
  *local_0x3C = 0x1 + ((*local_0x44) << 0x1);
  var7 = ((*data_0x98B8) + 0xE4) + (r0 << 0x2);
  *local_0x40 = var7;
  r0 = 0x4;
  r0 = 0x4 + (r0 >> 0x2);
  *local_0x48 = 0x4 + (r0 >> 0x2);
  r0 = (*data_0x98B8) + (r0 << 0x1);
  *local_0x4C = (*data_0x98B8) + (r0 << 0x1);
  r0 = (*data_0x98B8) + (r0 << 0x2);
  *local_0x50 = (*data_0x98B8) + (r0 << 0x2);
  var8 = (sp + 0x28) + (r0 << 0x3);
  *local_0x54 = var8;
  r0 = (*data_0x98B8) - 0x10C;
  var9 = ((*data_0x98B8) - 0x10C) + (r0 << 0x3);
  var10 = (sp + 0x8) + (r0 << 0x2);
  *local_0x58 = var9;
  while (1)
  {
    r0 = func_0x10998(r0);
    if (func_0x10998(r0) != 0)
    {
    }
    else
    {
    }

    r5 = *((*data_0x98B0) + 0x4A);
    r0 = func_0x2C58(func_0x10998(r0));
    if (func_0x2C58(func_0x10998(r0)) != 3)
    {
    }
    else
    {
      r0 = func_0xB9B4(func_0x2C58(func_0x10998(r0)));
      if (func_0xB9B4(func_0x2C58(func_0x10998(r0))) == 2)
      {
        var11 = (*((*data_0x98B0) + 0x4A)) + (func_0x2C64(r6) << 0x1);
        if (((int) var11) >= 0x200)
        {
        }

        if (0x1FF < 0)
        {
          r5 = 0x0;
        }

      }

    }

    var12 = func_0x807C(r6) & (~0x3);
    var13 = (*data_0x98C4) + ((*((*local_0x30) + 0x4C)) << 0x2);
    var14 = (*((*data_0x98C0) + var12)) * ((float) 0x4);
    var15 = (*((*data_0x98C4) + (r5 << 0x2))) + (*var13);
    *(sb + 0x4C) = (int) (var14 * var15);
    *local_0x5C = (*data_0x98B0) + (r4 << 0x1);
    var16 = *(((*data_0x98B0) + (r4 << 0x1)) + 0x60);
    var17 = *(((*data_0x98C8) + (var16 >> 0x3)) << 0x1);
    *(((*local_0x58) + (r4 << 0x2)) + 0xAC) = (int) (((float) var17) * (*(*local_0x2C)));
    var18 = ((*data_0x98B0) + 0x258) + (r4 << 0x2);
    *local_0x60 = var18;
    r5 = *(var18 + 0x40);
    if (((func_0xB9B4(func_0x2C58(var18)) == 8) && (r4 == 0)) && (func_0xB9B4() != 2))
    {
      var19 = (*(var18 + 0x40)) + (func_0x2C64(r6) << 0x4);
      if (((int) var19) > 0x1000)
      {
      }

      if (0xFFF < 0)
      {
        r5 = 0x0;
      }

    }
    else
    {
      if (func_0x2C58(var19) == 9)
      {
        if (r4 == 1)
        {
          var20 = ((int) var19) + (func_0x2C64(r6) << 0x4);
          if (((int) var20) < 0x1000)
          {
          }

          if (0xFFF < 0)
          {
            r5 = 0x0;
          }

        }

      }

    }

    fp = *((*string_tR_1) + 0x48);
    r0 = func_0x2C58(*string_tR_1);
    if (func_0x2C58(*string_tR_1) == 5)
    {
      r0 = func_0xB9B4(func_0x2C58(*string_tR_1));
      if (func_0xB9B4(func_0x2C58(*string_tR_1)) == 2)
      {
        r0 = func_0x2C64(r6);
        var21 = (*((*string_tR_1) + 0x48)) + (func_0x2C64(r6) << 0x4);
        if (((int) var21) > 0x1000)
        {
        }

        if (0xFFF < 0)
        {
          fp = 0x0;
        }

      }

    }

    r0 = func_0x81E8(r0);
    if (func_0x81E8(r0) == 0)
    {
      var22 = *(((*local_0x58) + (r4 << 0x2)) + 0x6C);
      var23 = *(((*local_0x58) + (r4 << 0x2)) + 0xAC);
      var24 = ((r5 - var22) - var23) - (*(sb + 0x4C));
      var25 = (var24 - fp) - func_0x85E4(*(r8 + 0x5));
      *(((*local_0x54) + r4) << 0x2) = var25;
    }
    else
    {
      var26 = *(((*local_0x58) + (r4 << 0x2)) + 0x6C);
      var27 = *(((*local_0x58) + (r4 << 0x2)) + 0xAC);
      var28 = (var26 + var27) + ((*(sb + 0x4C)) + r5);
      var29 = func_0x85E4(*(r8 + 0x5)) + (var28 + fp);
      *(((*local_0x54) + r4) << 0x2) = var29;
    }

    *(((*local_0x34) + r4) << 0x2) = *(((*local_0x54) + r4) << 0x2);
    if (func_0x10998(*local_0x34) == 0)
    {
      *local_0xC4 = 0x6;
    }
    else
    {
      *local_0xC4 = 0x8;
    }

    if (func_0x2C58(*data_0x98B0) != 3)
    {
    }
    else
    {
      var30 = (*((*data_0x98B0) + 0x4A)) + (func_0x2C64(r6) << 0x1);
    }

    var31 = func_0x807C(r6) & (~0x3);
    var32 = (*((*data_0x98CC) + var31)) * ((float) (*local_0xC4));
    var33 = (*data_0x98C4) + ((*((*local_0x30) + 0x4C)) << 0x2);
    var34 = (*((*data_0x98C4) + (0x0 << 0x2))) + (*var33);
    *(sb + 0x4E) = (int) (var32 * var34);
    var35 = *(((*data_0x98D0) + ((*((*local_0x5C) + 0x60)) >> 0x3)) << 0x1);
    *(((*local_0x58) + (r4 << 0x2)) + 0xAE) = (int) (((float) var35) * (*(*local_0x2C)));
    r5 = *((*local_0x60) + 0x42);
    cond = func_0x2C58(*local_0x60) == 6;
    r0 = func_0xB9B4(func_0x2C58(*local_0x60));
    if ((cond && (r4 == 0)) && (func_0xB9B4() == 2))
    {
      r0 = func_0x2C64(r6);
      var36 = (*((*local_0x60) + 0x42)) + (func_0x2C64(r6) << 0x4);
      if (((int) var36) >= 0x1000)
      {
      }

      if (0xFFF < 0)
      {
        r5 = 0x0;
      }

    }
    else
    {
      r0 = func_0x2C58(var36);
      if (func_0x2C58() != 7)
      {
      }
      else
      {
        if (r4 == 1)
        {
          r0 = func_0xB9B4(func_0x2C58(var36));
          if (func_0xB9B4(func_0x2C58(var36)) == 2)
          {
            r0 = func_0x2C64(r6);
            var37 = ((int) var36) + (func_0x2C64(r6) << 0x4);
            if (((int) var37) > 0x1000)
            {
            }

            if (0xFFF < 0)
            {
              r5 = 0x0;
            }

          }

        }

      }

    }

    fp = *((*string_tR_1) + 0x4A);
    r0 = func_0x2C58(r0);
    cond = func_0x2C58(r0) == 5;
    if (cond && (func_0xB9B4() == 2))
    {
      var38 = (*((*string_tR_1) + 0x4A)) + (func_0x2C64(r6) << 0x4);
      if (((int) var38) > 0x1000)
      {
      }

      if (0xFFF < 0)
      {
        fp = 0x0;
      }

    }

    var39 = *(((*local_0x58) + (r4 << 0x2)) + 0x6E);
    var40 = *(((*local_0x58) + (r4 << 0x2)) + 0xAE);
    var41 = (var39 + var40) + ((*(sb + 0x4E)) + r5);
    var42 = func_0x8600(*(r8 + 0x5)) + (var41 + fp);
    *(((*local_0x54) + (r4 << 0x2)) + 0x2) = var42;
    *(((*local_0x34) + (r4 << 0x2)) + 0x2) = var42;
    r5 = *((*data_0x9A84) + 0xE4);
    if (func_0x2C58(var42) == 4)
    {
      if (func_0xB9B4(func_0x2C58(var42)) == 2)
      {
        var43 = (*((*data_0x9A84) + 0xE4)) + (func_0x2C64(r6) << 0x1);
        r5 = (int) var43;
      }

    }

    if (r5 > 0x200)
    {
    }

    if (0x1FF < 0)
    {
    }

    if ((func_0x807C(r6) >> 0x2) >= 0x400)
    {
    }

    var44 = (*((*data_0x9A88) + (0x3FF << 0x2))) * ((float) (*local_0xC4));
    var45 = var44 * (*((*data_0x9A8C) + (0x0 << 0x2)));
    *((*local_0x4C) + 0x44) = (int) var45;
    var46 = *(((*data_0x9A84) + (r4 << 0x1)) + 0xEA);
    *(((*local_0x50) + (r4 << 0x1)) + 0x74) = (int) (((float) var46) * (*(*local_0x2C)));
    var47 = *(((*local_0x50) + (r4 << 0x1)) + 0x54);
    var48 = *(((*data_0x9A84) + (r4 << 0x1)) + 0xE0);
    var49 = *(((*local_0x50) + (r4 << 0x1)) + 0x74);
    var50 = ((*((*local_0x4C) + 0x44)) + var49) + (var48 + var47);
    var51 = (int) (func_0x8628(*(r8 + 0x5)) + var50);
    *((sl + r4) << 0x1) = var51;
    if (var51 > 0x1000)
    {
      *((sl + r4) << 0x1) = 0xFFF;
    }

    if ((*((sl + r4) << 0x1)) < 0)
    {
      *((sl + r4) << 0x1) = 0x0;
    }

    *(((*local_0x40) + r4) << 0x1) = *((sl + r4) << 0x1);
    if (func_0x7D1C(*local_0x40) == 1)
    {
      if (r4 == 0)
      {
        if ((*(r8 + 0x10)) == 4)
        {
          var52 = (*(((*local_0x40) + r4) << 0x1)) >> 0x2;
          var53 = (unsigned int) (r4 + ((*local_0x44) << 0x1));
          set_2000xxB4(*local_0x48, var53, get_equiv_between_0_and_1023_times_two_plus_0804A024(var52));
        }

        set_2000xxB4(*local_0x48, (unsigned int) (*local_0x38), 0x0);
      }
      else
      {
        if ((r4 != 1) && ((*(r8 + 0x20)) != 4))
        {
          var54 = (*(((*local_0x40) + r4) << 0x1)) >> 0x2;
          var55 = (unsigned int) (r4 + ((*local_0x44) << 0x1));
          set_2000xxB4(*local_0x48, var55, get_equiv_between_0_and_1023_times_two_plus_0804A024(var54));
        }

        set_2000xxB4(*local_0x48, (unsigned int) (*local_0x3C), 0x0);
      }

    }
    else
    {
      var56 = (unsigned int) (r4 + ((*local_0x44) << 0x1));
      set_2000xxB4(*local_0x48, var56, 0x0);
    }

    r4 = r4 + 0x1;
    if ((r4 + 0x1) >= 2)
    {
      break;
    }

  }

  sp = sp + 0xA4;
}

