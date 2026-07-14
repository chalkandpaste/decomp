void func_0xD630(int r0, int r1, int r2, int r3)
{
  r0 = 0x51;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x51;
    r0 = func_0x1D184(r0, r1, r2);
    func_0x12428(r0);
    *((*_0x20004CFC_8) + 0x126) = 0x1;
    *((*_0x20004CFC_8) + 0x2A6) = 0x1;
    *((*_0x20004CFC_8) + 0xC6) = 0x1;
    *((*_0x20004CFC_8) + 0x1A6) = 0x1;
    r0 = 0x51;
    func_0x2F68(r0);
  }

  r0 = 0x11;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x11;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    var0 = (float) (func_0x1D184(r0, r1, r2) << 0x4);
    var1 = (unsigned int) ((unsigned int) (var0 * (*data_0xDA5C)));
    *((*_0x200049DC) + 0x40) = var1;
    var2 = (((float) var1) - (*_0x424A38EB)) * ((*((*_0x200049DC) + 0x10)) - 1.000000e+00);
    *((*_0x200049DC) + 0x14) = var2 / (*_0xBF7CD6EA);
    r0 = 0x11;
    func_0x2F68(r0);
  }

  r0 = 0xF;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0xF;
    r0 = func_0x1D184(r0, r1, r2);
    r1 = (*0x08046C24) - 0x400;
    var3 = ((*0x08046C24) - 0x400) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x1B74(r0);
    var4 = (*var3) * (var2 / (*((*0x08046C24) + 0x3FC)));
    *(*_0x200049DC) = (unsigned int) (var4 * 2.000000e+00);
    var5 = (float) ((unsigned int) (var4 * 2.000000e+00));
    r0 = 2.000000e+00 / var5;
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = (*0x08046C24) - 0x400;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0x4) = func_0x1D778(r0, r1);
    var6 = (func_0x1D778(r0, r1) - 1.000000e+00) * (*_0x457FF000);
    *((*_0x200049DC) + 0x8) = var6 / (-9.375000e-01);
    r0 = 0xF;
    func_0x2F68(r0);
  }

  r0 = 0x10;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x10;
    r0 = func_0x1D184(r0, r1, r2);
    var7 = (*_0x08047024) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x3DD4(r0);
    var8 = var6 / (*(((*_0x08047024) + 0x400) + 0x3FC));
    var9 = (unsigned int) (((*var7) * var8) * 2.000000e+00);
    *((*_0x200049DC) + 0xC) = var9;
    r0 = 2.000000e+00 / ((float) var9);
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = (*0x08046C24) - 0x400;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0x10) = func_0x1D778(r0, r1);
    r0 = *((*_0x200049DC) + 0x40);
    var10 = ((float) (*((*_0x200049DC) + 0x40))) - (*_0x424A38EB);
    var11 = var10 * (func_0x1D778(r0, r1) - 1.000000e+00);
    *((*_0x200049DC) + 0x14) = var11 / (*_0xBF7CD6EA);
    r0 = 0x10;
    func_0x2F68(r0);
  }

  r0 = 0x12;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x12;
    r0 = func_0x1D184(r0, r1, r2);
    var12 = (*_0x08047024) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x3DD4(r0);
    var13 = var11 / (*(((*_0x08047024) + 0x400) + 0x3FC));
    var14 = (unsigned int) (((*var12) * var13) * 2.000000e+00);
    *((*_0x200049DC) + 0x18) = var14;
    func_0x3DD4(r0);
    var15 = -(((float) (*((*_0x200049DC) + 0x18))) - (var14 * 2.000000e+00));
    var16 = var15 * ((float) (*((*_0x200004D8_2) + 0x4)));
    var17 = (var16 / (*data_0xDA90)) + ((float) (*((*_0x200049DC) + 0x18)));
    *((*_0x200049DC) + 0x18) = (unsigned int) var17;
    r0 = 2.000000e+00 / ((float) ((unsigned int) var17));
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = (*0x08046C24) - 0x400;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0x1C) = func_0x1D778(r0, r1);
    r0 = 0x12;
    func_0x2F68(r0);
  }

  r0 = 0x29;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x29;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    var18 = (float) (func_0x1D184(r0, r1, r2) << 0x4);
    var19 = (unsigned int) ((unsigned int) (var18 * (*data_0xDA5C)));
    *((*_0x200049DC) + 0xD0) = var19;
    var20 = (((float) var19) - (*_0x424A38EB)) * ((*((*_0x200049DC) + 0xA0)) - 1.000000e+00);
    *((*_0x200049DC) + 0xA4) = var20 / (*_0xBF7CD6EA);
    r0 = 0x29;
    func_0x2F68(r0);
  }

  r0 = 0x1D;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x1D;
    r0 = func_0x1D184(r0, r1, r2);
    r1 = *_0x08046824;
    var21 = (*_0x08046824) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x1B74(r0);
    var22 = (*var21) * (var20 / (*((*0x08046C24) + 0x3FC)));
    *((*_0x200049DC) + 0x90) = (unsigned int) (var22 * 2.000000e+00);
    var23 = (float) ((unsigned int) (var22 * 2.000000e+00));
    r0 = 2.000000e+00 / var23;
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0x94) = func_0x1D778(r0, r1);
    var24 = (func_0x1D778(r0, r1) - 1.000000e+00) * (*_0x457FF000);
    *((*_0x200049DC) + 0x98) = var24 / (-9.375000e-01);
    r0 = 0x1D;
    func_0x2F68(r0);
  }

  r0 = 0x28;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x28;
    r0 = func_0x1D184(r0, r1, r2);
    var25 = (*_0x08047024) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x3DD4(r0);
    var26 = var24 / (*(((*_0x08047024) + 0x400) + 0x3FC));
    var27 = (unsigned int) (((*var25) * var26) * 2.000000e+00);
    *((*_0x200049DC) + 0x9C) = var27;
    r0 = 2.000000e+00 / ((float) var27);
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0xA0) = func_0x1D778(r0, r1);
    r0 = *((*_0x200049DC) + 0xD0);
    var28 = ((float) (*((*_0x200049DC) + 0xD0))) - (*_0x424A38EB);
    var29 = var28 * (func_0x1D778(r0, r1) - 1.000000e+00);
    *((*_0x200049DC) + 0xA4) = var29 / (*_0xBF7CD6EA);
    r0 = 0x28;
    func_0x2F68(r0);
  }

  r0 = 0x2A;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x2A;
    r0 = func_0x1D184(r0, r1, r2);
    var30 = (*_0x08047024) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x3DD4(r0);
    var31 = var29 / (*(((*_0x08047024) + 0x400) + 0x3FC));
    var32 = (unsigned int) (((*var30) * var31) * 2.000000e+00);
    *((*_0x200049DC) + 0xA8) = var32;
    func_0x3DD4(r0);
    var33 = -(((float) (*((*_0x200049DC) + 0xA8))) - (var32 * 2.000000e+00));
    var34 = var33 * ((float) (*((*_0x200004D8_2) + 0x4)));
    var35 = (var34 / (*data_0xDA90)) + ((float) (*((*_0x200049DC) + 0xA8)));
    *((*_0x200049DC) + 0xA8) = (unsigned int) var35;
    r0 = 2.000000e+00 / ((float) ((unsigned int) var35));
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0xAC) = func_0x1D778(r0, r1);
    r0 = 0x2A;
    func_0x2F68(r0);
  }

  r0 = 0xA;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x9;
    var36 = 0x7FF + (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x8A) = var36;
    r0 = 0x8;
    var37 = 0x7FF - (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x88) = var37;
    r0 = 0xA;
    r0 = func_0x1D184(r0, r1, r2);
    r1 = *_0x08046824_1;
    var38 = (*_0x08046824_1) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x1B74(r0);
    var39 = (*var38) * (s24 / (*((*0x08046C24) + 0x3FC)));
    *((*_0x200049DC) + 0x44) = (unsigned int) (var39 * 2.000000e+00);
    var40 = (float) ((unsigned int) (var39 * 2.000000e+00));
    r0 = 2.000000e+00 / var40;
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824_1;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0x48) = func_0x1D778(r0, r1);
    r0 = *((*_0x200049DC) + 0x8A);
    var41 = ((float) (*((*_0x200049DC) + 0x8A))) - (((float) (*((*_0x200049DC) + 0x88))) * (*data_0xDECC));
    var42 = var41 * (func_0x1D778(r0, r1) - 1.000000e+00);
    *((*_0x200049DC) + 0x4C) = var42 / (-9.375000e-01);
    r0 = 0xA;
    func_0x2F68(r0);
  }

  r0 = 0xB;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x9;
    var43 = 0x7FF + (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x8A) = var43;
    r0 = 0x8;
    var44 = 0x7FF - (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x88) = var44;
    r0 = 0xB;
    r0 = func_0x1D184(r0, r1, r2);
    var45 = (*_0x08047024) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x3DD4(r0);
    var46 = var42 / (*(((*_0x08047024) + 0x400) + 0x3FC));
    var47 = (unsigned int) (((*var45) * var46) * 2.000000e+00);
    *((*_0x200049DC) + 0x50) = var47;
    r0 = 2.000000e+00 / ((float) var47);
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824_1;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0x54) = func_0x1D778(r0, r1);
    r0 = *((*_0x200049DC) + 0x8A);
    var48 = (*data_0xDED4) - (((float) (*((*_0x200049DC) + 0x8A))) * (*data_0xDED8));
    var49 = var48 * (func_0x1D778(r0, r1) - 1.000000e+00);
    *((*_0x200049DC) + 0x58) = var49 / (*_0xBF7CD6EA);
    r0 = 0xB;
    func_0x2F68(r0);
  }

  r0 = 0xC;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0xC;
    r0 = func_0x1D184(r0, r1, r2);
    var50 = (*_0x08047024) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x3DD4(r0);
    var51 = var49 / (*(((*_0x08047024) + 0x400) + 0x3FC));
    var52 = (unsigned int) (((*var50) * var51) * 2.000000e+00);
    func_0x3DD4(r0);
    var53 = -(((float) (*((*_0x200049DC) + 0x5C))) - ((((*var50) * var51) * 2.000000e+00) * 2.000000e+00));
    var54 = var53 * ((float) (*((*_0x200004D8_2) + 0x4)));
    var55 = (var54 / (*data_0xDA90)) + ((float) var52);
    var56 = 2.000000e+00 / ((float) (*((*_0x200049DC) + 0x5C)));
    r0 = var56;
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824_1;
    r0 = func_0x1D778(r0, r1);
    r0 = 0x0;
    r1 = *_0x20001FD4_3;
    while (1)
    {
      var57 = (r0 + (r0 << 0x1)) + (r0 << 0x3);
      var58 = *(((*_0x20001FD4_3) + (var57 << 0x2)) + 0x8);
      if (var58 == 3)
      {
        r2 = (*_0x200049DC) + (r0 << 0x2);
        var59 = ((float) (*((*_0x200049DC) + 0x88))) - ((*((*_0x2000501C) + (r0 << 0x2))) * (*data_0xDED8));
        var60 = var59 * (func_0x1D778(r0, r1) - 1.000000e+00);
        var61 = (var59 * (func_0x1D778(r0, r1) - 1.000000e+00)) / (*_0xBF7CD6EA);
        *(((*_0x200049DC) + (r0 << 0x2)) + 0x64) = (var59 * (func_0x1D778(r0, r1) - 1.000000e+00)) / (*_0xBF7CD6EA);
      }

      r0 = r0 + 0x1;
    }

    *((*_0x200049DC) + 0x60) = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0x5C) = (unsigned int) var55;
    r0 = 0xC;
    func_0x2F68(r0);
  }

  r0 = 0x9;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x9;
    var62 = 0x7FF + (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x8A) = var62;
    r0 = 0x8;
    var63 = 0x7FF - (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x88) = var63;
    var64 = ((float) (*((*_0x200049DC) + 0x8A))) - (((float) var63) * (*data_0xDECC));
    var65 = var64 * ((*((*_0x200049DC) + 0x48)) - 1.000000e+00);
    *((*_0x200049DC) + 0x4C) = var65 / (-9.375000e-01);
    s0 = *data_0xDED4;
    var66 = (*data_0xDED4) - (((float) (*((*_0x200049DC) + 0x8A))) * (*data_0xDED8));
    var67 = var66 * ((*((*_0x200049DC) + 0x54)) - 1.000000e+00);
    *((*_0x200049DC) + 0x58) = var67 / (*_0xBF7CD6EA);
    r0 = 0x9;
    func_0x2F68(r0);
  }

  r0 = 0x8;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x9;
    var68 = 0x7FF + (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x8A) = var68;
    r0 = 0x8;
    var69 = 0x7FF - (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x88) = var69;
    var70 = ((float) (*((*_0x200049DC) + 0x8A))) - (((float) var69) * (*data_0xDECC));
    var71 = var70 * ((*((*_0x200049DC) + 0x48)) - 1.000000e+00);
    *((*_0x200049DC) + 0x4C) = var71 / (-9.375000e-01);
    var72 = (*data_0xDED4) - (((float) (*((*_0x200049DC) + 0x8A))) * (*data_0xDED8));
    var73 = var72 * ((*((*_0x200049DC) + 0x54)) - 1.000000e+00);
    *((*_0x200049DC) + 0x58) = var73 / (*_0xBF7CD6EA);
    r0 = 0x0;
    r2 = *_0x20001FD4_3;
    while (1)
    {
      var74 = (r0 + (r0 << 0x1)) + (r0 << 0x3);
      var75 = *(((*_0x20001FD4_3) + (var74 << 0x2)) + 0x8);
      if (var75 == 3)
      {
        s0 = (float) (*((*_0x200049DC) + 0x88));
        r1 = (*_0x200049DC) + (r0 << 0x2);
        var76 = ((float) (*((*_0x200049DC) + 0x88))) - ((*((*_0x2000501C) + (r0 << 0x2))) * (*data_0xDED8));
        var77 = var76 * ((*((*_0x200049DC) + 0x60)) - 1.000000e+00);
        *(((*_0x200049DC) + (r0 << 0x2)) + 0x64) = var77 / (*_0xBF7CD6EA);
      }

    }

    r0 = 0x8;
    func_0x2F68(r0);
  }

  r0 = 0x18;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x27;
    var78 = 0x7FF + (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x11A) = var78;
    r0 = 0x26;
    var79 = 0x7FF - (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x118) = var79;
    r0 = 0x18;
    r0 = func_0x1D184(r0, r1, r2);
    r1 = *_0x08046824_1;
    var80 = (*_0x08046824_1) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x1B74(r0);
    var81 = (*var80) * (s0 / (*((*0x08046C24) + 0x3FC)));
    *((*_0x200049DC) + 0xD4) = (unsigned int) (var81 * 2.000000e+00);
    var82 = (float) ((unsigned int) (var81 * 2.000000e+00));
    r0 = 2.000000e+00 / var82;
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824_1;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0xD8) = func_0x1D778(r0, r1);
    r0 = *((*_0x200049DC) + 0x11A);
    var83 = ((float) (*((*_0x200049DC) + 0x11A))) - (((float) (*((*_0x200049DC) + 0x118))) * (*data_0xDECC));
    var84 = var83 * (func_0x1D778(r0, r1) - 1.000000e+00);
    *((*_0x200049DC) + 0xDC) = var84 / (-9.375000e-01);
    r0 = 0x18;
    func_0x2F68(r0);
  }

  r0 = 0x19;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x27;
    var85 = 0x7FF + (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x11A) = var85;
    r0 = 0x26;
    var86 = 0x7FF - (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x118) = var86;
    r0 = 0x19;
    r0 = func_0x1D184(r0, r1, r2);
    var87 = (*_0x08047024) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x3DD4(r0);
    var88 = var84 / (*(((*_0x08047024) + 0x400) + 0x3FC));
    var89 = (unsigned int) (((*var87) * var88) * 2.000000e+00);
    *((*_0x200049DC) + 0xE0) = var89;
    r0 = 2.000000e+00 / ((float) var89);
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824_1;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0xE4) = func_0x1D778(r0, r1);
    r0 = *((*_0x200049DC) + 0x11A);
    var90 = (*data_0xDED4) - (((float) (*((*_0x200049DC) + 0x11A))) * (*data_0xDED8));
    var91 = var90 * (func_0x1D778(r0, r1) - 1.000000e+00);
    *((*_0x200049DC) + 0xE8) = var91 / (*_0xBF7CD6EA);
    r0 = 0x19;
    func_0x2F68(r0);
  }

  r0 = 0x1A;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x1A;
    r0 = func_0x1D184(r0, r1, r2);
    var92 = (*_0x08047024) + (func_0x1D184(r0, r1, r2) << 0x3);
    func_0x3DD4(r0);
    var93 = var91 / (*(((*_0x08047024) + 0x400) + 0x3FC));
    var94 = (unsigned int) (((*var92) * var93) * 2.000000e+00);
    func_0x3DD4(r0);
    var95 = -(((float) (*((*_0x200049DC) + 0xEC))) - ((((*var92) * var93) * 2.000000e+00) * 2.000000e+00));
    var96 = var95 * ((float) (*((*_0x200004D8_2) + 0x4)));
    var97 = (var96 / (*data_0xDA90)) + ((float) var94);
    var98 = 2.000000e+00 / ((float) (*((*_0x200049DC) + 0xEC)));
    r0 = var98;
    r0 = func_0x1E2F0(r0, r1);
    func_0x1A178(r0, r1);
    r0 = *_0x08046824_1;
    r0 = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0xF0) = func_0x1D778(r0, r1);
    *((*_0x200049DC) + 0xEC) = (unsigned int) var97;
    r0 = 0x0;
    r2 = *_0x20001FD4_4;
    while (1)
    {
      var99 = (r0 + (r0 << 0x1)) + (r0 << 0x3);
      var100 = *(((*_0x20001FD4_4) + (var99 << 0x2)) + 0x18);
      if (var100 == 3)
      {
        var101 = *(((*_0x2000501C) + (r0 << 0x2)) + 0x20);
        r1 = (*_0x200049DC) + (r0 << 0x2);
        var102 = ((float) (*((*_0x200049DC) + 0x118))) - (var101 * (*data_0xDED8));
        var103 = var102 * (func_0x1D778(r0, r1) - 1.000000e+00);
        var104 = (var102 * (func_0x1D778(r0, r1) - 1.000000e+00)) / (*_0xBF7CD6EA);
        *(((*_0x200049DC) + (r0 << 0x2)) + 0xF4) = (var102 * (func_0x1D778(r0, r1) - 1.000000e+00)) / (*_0xBF7CD6EA);
      }

    }

    r0 = 0x1A;
    func_0x2F68(r0);
  }

  r0 = 0x27;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x27;
    var105 = 0x7FF + (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x11A) = var105;
    r0 = 0x26;
    var106 = 0x7FF - (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x118) = var106;
    var107 = ((float) (*((*_0x200049DC) + 0x11A))) - (((float) var106) * (*data_0xDECC));
    var108 = var107 * ((*((*_0x200049DC) + 0xD8)) - 1.000000e+00);
    *((*_0x200049DC) + 0xDC) = var108 / (-9.375000e-01);
    var109 = (*data_0xDED4) - (((float) (*((*_0x200049DC) + 0x11A))) * (*data_0xDED8));
    var110 = var109 * ((*((*_0x200049DC) + 0xE4)) - 1.000000e+00);
    *((*_0x200049DC) + 0xE8) = var110 / (*_0xBF7CD6EA);
    r0 = 0x27;
    func_0x2F68(r0);
  }

  r0 = 0x26;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x27;
    var111 = 0x7FF + (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x11A) = var111;
    r0 = 0x26;
    var112 = 0x7FF - (func_0x1D184(r0, r1, r2) << 0x3);
    *((*_0x200049DC) + 0x118) = var112;
    var113 = ((float) (*((*_0x200049DC) + 0x11A))) - (((float) var112) * (*data_0xDECC));
    var114 = var113 * ((*((*_0x200049DC) + 0xD8)) - 1.000000e+00);
    *((*_0x200049DC) + 0xDC) = var114 / (-9.375000e-01);
    var115 = (*data_0xDED4) - (((float) (*((*_0x200049DC) + 0x11A))) * (*data_0xDED8));
    var116 = var115 * ((*((*_0x200049DC) + 0xE4)) - 1.000000e+00);
    *((*_0x200049DC) + 0xE8) = var116 / (*_0xBF7CD6EA);
    r0 = 0x0;
    r2 = *_0x20001FD4_4;
    while (1)
    {
      var117 = (r0 + (r0 << 0x1)) + (r0 << 0x3);
      var118 = *(((*_0x20001FD4_4) + (var117 << 0x2)) + 0x18);
      if (var118 == 3)
      {
        var119 = *(((*_0x2000501C) + (r0 << 0x2)) + 0x20);
        r1 = (*_0x200049DC) + (r0 << 0x2);
        var120 = ((float) (*((*_0x200049DC) + 0x118))) - (var119 * (*data_0xDED8));
        var121 = var120 * ((*((*_0x200049DC) + 0xF0)) - 1.000000e+00);
        *(((*_0x200049DC) + (r0 << 0x2)) + 0xF4) = var121 / (*_0xBF7CD6EA);
      }

    }

    r0 = 0x26;
    func_0x2F68(r0);
  }

  r0 = 0x3;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x3;
    r0 = func_0x1D184(r0, r1, r2);
    r2 = func_0x1D184(r0, r1, r2) << 0x2;
    r1 = 0x2;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x3;
    func_0x2F68(r0);
  }

  r0 = 0x21;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x21;
    r0 = func_0x1D184(r0, r1, r2);
    r2 = func_0x1D184(r0, r1, r2) << 0x2;
    r1 = 0x3;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x21;
    func_0x2F68(r0);
  }

  r0 = 0x39;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x39;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0xFF - func_0x1D184(r0, r1, r2);
    *((*_0x200004D8_2) + 0xC) = 0xFF - func_0x1D184(r0, r1, r2);
    r0 = 0xD;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0x7;
    r0 = func_0x1D184(r0, r1, r2);
    var122 = (*((*_0x200004D8_2) + 0xC)) + ((*((*_0x200004D8_2) + 0xC)) >> 0x1F);
    r1 = 0x100 - (var122 >> 0x1);
    var123 = (0x100 - (var122 >> 0x1)) - (func_0x1D184(r0, r1, r2) >> 0x1);
    var124 = (((float) var123) / (*data_0xE474)) + (*data_0xE478);
    var125 = (unsigned int) (((float) func_0x1D184(r0, r1, r2)) * var124);
    r0 = 0xFFFF & (var125 << 0x2);
    r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r1 = 0x0;
    r0 = 0x9;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x1B;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0x25;
    r0 = func_0x1D184(r0, r1, r2);
    var126 = (*((*_0x200004D8_2) + 0xC)) + ((*((*_0x200004D8_2) + 0xC)) >> 0x1F);
    r1 = 0x100 - (var126 >> 0x1);
    var127 = (0x100 - (var126 >> 0x1)) - (func_0x1D184(r0, r1, r2) >> 0x1);
    var128 = (((float) var127) / (*data_0xE474)) + (*data_0xE478);
    var129 = (unsigned int) (((float) func_0x1D184(r0, r1, r2)) * var128);
    r0 = 0xFFFF & (var129 << 0x2);
    r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r1 = 0x1;
    r0 = 0x9;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x7;
    var130 = func_0x1D184(r0, r1, r2) + (*((*_0x200004D8_2) + 0xC));
    r2 = 0xFFFF & (var130 << 0x1);
    r1 = 0x6;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x25;
    var131 = func_0x1D184(r0, r1, r2) + (*((*_0x200004D8_2) + 0xC));
    r2 = 0xFFFF & (var131 << 0x1);
    r1 = 0x7;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x5;
    var132 = func_0x1D184(r0, r1, r2) + (*((*_0x200004D8_2) + 0xC));
    r2 = 0xFFFF & (var132 << 0x1);
    r1 = 0x4;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x23;
    var133 = func_0x1D184(r0, r1, r2) + (*((*_0x200004D8_2) + 0xC));
    r2 = 0xFFFF & (var133 << 0x1);
    r1 = 0x5;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x39;
    func_0x2F68(r0);
  }

  r0 = 0x7;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x39;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0xFF - func_0x1D184(r0, r1, r2);
    *((*_0x200004D8_2) + 0xC) = 0xFF - func_0x1D184(r0, r1, r2);
    r0 = 0x7;
    var134 = func_0x1D184(r0, r1, r2) + (*((*_0x200004D8_2) + 0xC));
    r2 = 0xFFFF & (var134 << 0x1);
    r1 = 0x6;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0xD;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0x7;
    r0 = func_0x1D184(r0, r1, r2);
    var135 = (*((*_0x200004D8_2) + 0xC)) + ((*((*_0x200004D8_2) + 0xC)) >> 0x1F);
    r1 = 0x100 - (var135 >> 0x1);
    var136 = (0x100 - (var135 >> 0x1)) - (func_0x1D184(r0, r1, r2) >> 0x1);
    var137 = (((float) var136) / (*data_0xE474)) + (*data_0xE478);
    var138 = (unsigned int) (((float) func_0x1D184(r0, r1, r2)) * var137);
    r0 = 0xFFFF & (var138 << 0x2);
    r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r1 = 0x0;
    r0 = 0x9;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x7;
    func_0x2F68(r0);
  }

  r0 = 0x25;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x39;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0xFF - func_0x1D184(r0, r1, r2);
    *((*_0x200004D8_2) + 0xC) = 0xFF - func_0x1D184(r0, r1, r2);
    r0 = 0x25;
    var139 = func_0x1D184(r0, r1, r2) + (*((*_0x200004D8_2) + 0xC));
    r2 = 0xFFFF & (var139 << 0x1);
    r1 = 0x7;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x1B;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0x25;
    r0 = func_0x1D184(r0, r1, r2);
    var140 = (*((*_0x200004D8_2) + 0xC)) + ((*((*_0x200004D8_2) + 0xC)) >> 0x1F);
    r1 = 0x100 - (var140 >> 0x1);
    var141 = (0x100 - (var140 >> 0x1)) - (func_0x1D184(r0, r1, r2) >> 0x1);
    var142 = (((float) var141) / (*data_0xE474)) + (*data_0xE478);
    var143 = (unsigned int) (((float) func_0x1D184(r0, r1, r2)) * var142);
    r0 = 0xFFFF & (var143 << 0x2);
    r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r1 = 0x1;
    r0 = 0x9;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x25;
    func_0x2F68(r0);
  }

  r0 = 0x5;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x5;
    var144 = func_0x1D184(r0, r1, r2) + (*((*_0x200004D8_2) + 0xC));
    r2 = 0xFFFF & (var144 << 0x1);
    r1 = 0x4;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x5;
    func_0x2F68(r0);
  }

  r0 = 0x23;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x23;
    var145 = func_0x1D184(r0, r1, r2) + (*((*_0x200004D8_2) + 0xC));
    r2 = 0xFFFF & (var145 << 0x1);
    r1 = 0x5;
    r0 = 0x8;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x23;
    func_0x2F68(r0);
  }

  r0 = 0xD;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x39;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0xFF - func_0x1D184(r0, r1, r2);
    *((*_0x200004D8_2) + 0xC) = 0xFF - func_0x1D184(r0, r1, r2);
    r0 = 0xD;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0x7;
    r0 = func_0x1D184(r0, r1, r2);
    var146 = (*((*_0x200004D8_2) + 0xC)) + ((*((*_0x200004D8_2) + 0xC)) >> 0x1F);
    r1 = 0x100 - (var146 >> 0x1);
    var147 = (0x100 - (var146 >> 0x1)) - (func_0x1D184(r0, r1, r2) >> 0x1);
    var148 = (((float) var147) / (*data_0xE474)) + (*data_0xE478);
    var149 = (unsigned int) (((float) func_0x1D184(r0, r1, r2)) * var148);
    r0 = 0xFFFF & (var149 << 0x2);
    r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r1 = 0x0;
    r0 = 0x9;
    set_2000xxB4(r0, r1, r2);
    r0 = 0xD;
    func_0x2F68(r0);
  }

  r0 = 0x1B;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x39;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0xFF - func_0x1D184(r0, r1, r2);
    *((*_0x200004D8_2) + 0xC) = 0xFF - func_0x1D184(r0, r1, r2);
    r0 = 0x1B;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0x25;
    r0 = func_0x1D184(r0, r1, r2);
    var150 = (*((*_0x200004D8_2) + 0xC)) + ((*((*_0x200004D8_2) + 0xC)) >> 0x1F);
    r1 = 0x100 - (var150 >> 0x1);
    var151 = (0x100 - (var150 >> 0x1)) - (func_0x1D184(r0, r1, r2) >> 0x1);
    var152 = (((float) var151) / (*data_0xE474)) + (*data_0xE478);
    s0 = ((float) func_0x1D184(r0, r1, r2)) * var152;
    var153 = (unsigned int) (((float) func_0x1D184(r0, r1, r2)) * var152);
    r0 = 0xFFFF & (var153 << 0x2);
    r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r1 = 0x1;
    r0 = 0x9;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x1B;
    func_0x2F68(r0);
  }

  r0 = 0xE;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0xE;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x2;
    r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r1 = 0x2;
    r0 = 0x9;
    set_2000xxB4(r0, r1, r2);
    r0 = 0xE;
    func_0x2F68(r0);
  }

  r0 = 0x1C;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x1C;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x2;
    r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
    r1 = 0x3;
    r0 = 0x9;
    set_2000xxB4(r0, r1, r2);
    r0 = 0x1C;
    func_0x2F68(r0);
  }

  r0 = 0x37;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x37;
    r0 = func_0x1D184(r0, r1, r2);
    if ((*((*_0x20004CFC_8) + 0x375)) == 0)
    {
    }
    else
    {
      r1 = 0x7F;
    }

    var154 = (int) (func_0x1D184(r0, r1, r2) - 0x7F);
    if ((var154 + 0x9) < 0x13)
    {
      r2 = 0x3FF;
      r1 = 0x5;
      r0 = 0x9;
      set_2000xxB4(r0, r1, r2);
      r2 = 0x3FF;
      r1 = 0x4;
      r0 = 0x9;
      set_2000xxB4(r0, r1, r2);
    }
    else
    {
      if (0x9 > 0)
      {
        if (0x4 != 0xF2)
        {
          var155 = ((0x9 - 0xA) << 0x7) / (0xF2 - 0x4);
        }
        else
        {
        }

        if (0x0 < 0)
        {
        }

        r2 = 0x3FF;
        r1 = 0x4;
        r0 = 0x9;
        set_2000xxB4(r0, r1, r2);
        r0 = 0x400 - (0x0 << 0x3);
        var156 = (unsigned int) (0x400 - (0x0 << 0x3));
        r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
        r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
        r1 = 0x5;
        r0 = 0x9;
        set_2000xxB4(r0, r1, r2);
      }
      else
      {
        if (0x4 != 0xA)
        {
          var157 = ((0x9 + 0xA) << 0x7) / (0x4 - 0xA);
        }
        else
        {
        }

        if (0x0 > 0)
        {
        }

        r2 = 0x3FF;
        r1 = 0x5;
        r0 = 0x9;
        set_2000xxB4(r0, r1, r2);
        r0 = 0x400 + (0x0 << 0x3);
        var158 = (unsigned int) (0x400 + (0x0 << 0x3));
        r0 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
        r2 = get_equiv_between_0_and_1023_times_two_plus_0804A024(r0);
        r1 = 0x4;
        r0 = 0x9;
        set_2000xxB4(r0, r1, r2);
      }

    }

    r0 = 0x37;
    func_0x2F68(r0);
  }

  r0 = 0x4;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x4;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*string_tR_2) + 0x40) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x4;
    func_0x2F68(r0);
  }

  r0 = 0x6;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x6;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*string_tR_2) + 0x42) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x6;
    func_0x2F68(r0);
  }

  r0 = 0x22;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x22;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*string_tR_2) + 0x44) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x22;
    func_0x2F68(r0);
  }

  r0 = 0x24;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x24;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*string_tR_2) + 0x46) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x24;
    func_0x2F68(r0);
  }

  r0 = 0x13;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x13;
    r0 = func_0x1D184(r0, r1, r2);
    var159 = (func_0x1D184(r0, r1, r2) + 0x37) << 0x3;
    *((*_0x20005088) + 0xE0) = var159;
    r0 = 0x13;
    func_0x2F68(r0);
  }

  r0 = 0x2B;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x2B;
    r0 = func_0x1D184(r0, r1, r2);
    var160 = (func_0x1D184(r0, r1, r2) + 0x37) << 0x3;
    *((*_0x20005088) + 0xE2) = var160;
    r0 = 0x2B;
    func_0x2F68(r0);
  }

  r0 = 0x35;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    if (func_0xBCF8() != 0x35)
    {
      r0 = 0x35;
      r0 = func_0x1D184(r0, r1, r2);
    }
    else
    {
      r0 = 0x35;
      r0 = func_0x1D184(r0, r1, r2);
      var161 = func_0x1D184(r0, r1, r2) - func_0xBD08(r0);
      if (((int) var161) > 0xFF)
      {
        r0 = 0xFF;
      }
      else
      {
        if (0xFF < 0)
        {
          r0 = 0x0;
        }

      }

    }

    r0 = 0xFF - r0;
    r0 = (0xFF - r0) << 0x1;
    *((*_0x2000501C) + 0x4A) = (0xFF - r0) << 0x1;
    r0 = 0x35;
    func_0x2F68(r0);
  }

  r0 = 0x36;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    if (func_0xBCF8() != 0x36)
    {
      r0 = 0x36;
      r0 = func_0x1D184(r0, r1, r2);
    }
    else
    {
      r0 = 0x36;
      r0 = func_0x1D184(r0, r1, r2);
      var162 = func_0x1D184(r0, r1, r2) - func_0xBD08(r0);
      if (((int) var162) > 0xFF)
      {
      }

      if (0xFF < 0x0)
      {
        r0 = 0x0;
      }

    }

    r0 = 0xFF - r0;
    r0 = (0xFF - r0) << 0x1;
    *((*_0x20005088) + 0xE4) = (0xFF - r0) << 0x1;
    r0 = 0x36;
    func_0x2F68(r0);
  }

  r0 = 0x38;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    if (func_0xBCF8() != 0x38)
    {
      r0 = 0x38;
      r0 = func_0x1D184(r0, r1, r2);
    }
    else
    {
      r0 = 0x38;
      r0 = func_0x1D184(r0, r1, r2);
      var163 = func_0x1D184(r0, r1, r2) - func_0xBD08(r0);
      if (((int) var163) > 0xFF)
      {
      }

      if (0xFF < 0)
      {
        r0 = 0x0;
      }

    }

    r0 = 0xFF - r0;
    var164 = (int) ((0xFF - r0) << 0x1);
    *((*_0x2000501C) + 0x48) = var164;
    *((*string_tR_2) + 0x48) = *(((*_0x0804D024) + var164) << 0x1);
    r1 = *_0x0804D424;
    *((*string_tR_2) + 0x4A) = *(((*_0x0804D424) + var164) << 0x1);
    r0 = 0x38;
    func_0x2F68(r0);
  }

  r0 = 0x14;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x14;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*_0x2000501C) + 0x5C) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x14;
    func_0x2F68(r0);
  }

  r0 = 0x2C;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x2C;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*_0x2000501C) + 0x5E) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x2C;
    func_0x2F68(r0);
  }

  r0 = 0x16;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x16;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*_0x2000501C) + 0x60) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x16;
    func_0x2F68(r0);
  }

  r0 = 0x2E;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x2E;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*_0x2000501C) + 0x62) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x2E;
    func_0x2F68(r0);
  }

  r0 = 0x15;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x15;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*_0x20005088) + 0xE6) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x15;
    func_0x2F68(r0);
  }

  r0 = 0x2D;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x2D;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*_0x20005088) + 0xE8) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x2D;
    func_0x2F68(r0);
  }

  r0 = 0x17;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x17;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*_0x20005088) + 0xEA) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x17;
    func_0x2F68(r0);
  }

  r0 = 0x2F;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x2F;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = func_0x1D184(r0, r1, r2) << 0x4;
    *((*_0x20005088) + 0xEC) = func_0x1D184(r0, r1, r2) << 0x4;
    r0 = 0x2F;
    func_0x2F68(r0);
  }

  r0 = 0x3F;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    func_0x8748();
    r0 = 0x3F;
    func_0x2F68(r0);
  }

  r0 = 0x3E;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    func_0x8748();
    r0 = 0x3E;
    func_0x2F68(r0);
  }

  r0 = 0x41;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    func_0x8EB0(r0, r1, r2);
    r0 = 0x41;
    func_0x2F68(r0);
  }

  r0 = 0x40;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    func_0x8EB0(r0, r1, r2);
    r0 = 0x40;
    func_0x2F68(r0);
  }

  r0 = 0x4A;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x4A;
    r0 = func_0x1D184(r0, r1, r2);
    if (func_0x1D184(r0, r1, r2) < 0x14)
    {
      if ((*(*_0x200004D8_2)) != 1)
      {
      }
      else
      {
        *(*_0x200004D8_2) = 0x0;
        r1 = 0x0;
        r0 = 0x4A;
        func_0x11D60(r0, r1);
      }

      r1 = 0x4;
      r0 = *_0x40020800_9;
      func_0x7CEE(r0, r1);
    }
    else
    {
      r0 = 0x4A;
      r0 = func_0x1D184(r0, r1, r2);
      if (func_0x1D184(r0, r1, r2) < 0xE6)
      {
        if ((*(*_0x200004D8_2)) != 0)
        {
          *(*_0x200004D8_2) = 0x1;
          r1 = 0x7F;
          r0 = 0x4A;
          func_0x11D60(r0, r1);
        }

        r1 = 0x4;
        r0 = *_0x40020800_9;
        arg1_p26_is_arg2(r0, r1);
      }

    }

    r0 = 0x4A;
    func_0x2F68(r0);
  }

  r0 = 0x4C;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x4C;
    r0 = func_0x1D184(r0, r1, r2);
    if (func_0x1D184(r0, r1, r2) < 0x14)
    {
      if ((*((*_0x200004D8_2) + 0x1)) == 1)
      {
        *((*_0x200004D8_2) + 0x1) = 0x0;
        r1 = 0x0;
        r0 = 0x4C;
        func_0x11D60(r0, r1);
      }

      r1 = 0x2;
      r0 = *_0x40020800_9;
      func_0x7CEE(r0, r1);
    }
    else
    {
      r0 = 0x4C;
      r0 = func_0x1D184(r0, r1, r2);
      if (func_0x1D184(r0, r1, r2) > 0xE6)
      {
        if ((*((*_0x200004D8_2) + 0x1)) == 0)
        {
          *((*_0x200004D8_2) + 0x1) = 0x1;
          r1 = 0x7F;
          r0 = 0x4C;
          func_0x11D60(r0, r1);
        }

        r1 = 0x2;
        r0 = *_0x40020800_9;
        arg1_p26_is_arg2(r0, r1);
      }

    }

    r0 = 0x4C;
    func_0x2F68(r0);
  }

  r0 = 0x49;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x49;
    r0 = func_0x1D184(r0, r1, r2);
    if (func_0x1D184(r0, r1, r2) < 0x14)
    {
      if ((*((*_0x200004D8_2) + 0x2)) == 1)
      {
        *((*_0x200004D8_2) + 0x2) = 0x0;
        r1 = 0x0;
        r0 = 0x49;
        func_0x11D60(r0, r1);
      }

      r1 = 0x1;
      r0 = *_0x40020800_9;
      func_0x7CEE(r0, r1);
    }
    else
    {
      r0 = 0x49;
      r0 = func_0x1D184(r0, r1, r2);
      if (func_0x1D184(r0, r1, r2) < 0xE6)
      {
        if ((*((*_0x200004D8_2) + 0x2)) == 0)
        {
          *((*_0x200004D8_2) + 0x2) = 0x1;
          r1 = 0x7F;
          r0 = 0x49;
          func_0x11D60(r0, r1);
        }

        r1 = 0x1;
        r0 = *_0x40020800_9;
        arg1_p26_is_arg2(r0, r1);
      }

    }

    r0 = 0x49;
    func_0x2F68(r0);
  }

  r0 = 0x4B;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x4B;
    r0 = func_0x1D184(r0, r1, r2);
    if (func_0x1D184(r0, r1, r2) < 0x14)
    {
      if ((*((*_0x200004D8_2) + 0x3)) == 0)
      {
        *((*_0x200004D8_2) + 0x3) = 0x0;
        r1 = 0x0;
        r0 = 0x4B;
        func_0x11D60(r0, r1);
      }

      r1 = 0x8;
      r0 = *_0x40020800_9;
      func_0x7CEE(r0, r1);
    }
    else
    {
      r0 = 0x4B;
      r0 = func_0x1D184(r0, r1, r2);
      if (func_0x1D184(r0, r1, r2) < 0xE6)
      {
        if ((*((*_0x200004D8_2) + 0x3)) == 0)
        {
          *((*_0x200004D8_2) + 0x3) = 0x1;
          r1 = 0x7F;
          r0 = 0x4B;
          func_0x11D60(r0, r1);
        }

        r1 = 0x8;
        r0 = *_0x40020800_9;
        arg1_p26_is_arg2(r0, r1);
      }

    }

    r0 = 0x4B;
    func_0x2F68(r0);
  }

  r0 = 0x30;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    if (func_0xBCF8() != 0x30)
    {
      r0 = 0x30;
      r0 = func_0x1D184(r0, r1, r2);
    }
    else
    {
      r0 = 0x30;
      r0 = func_0x1D184(r0, r1, r2);
      var165 = func_0x1D184(r0, r1, r2) - func_0xBD08(r0);
      if (((int) var165) > 0xFF)
      {
        r0 = 0xFF;
      }

    }

    *((*_0x200004D8_2) + 0x7) = 0x24;
    if (r0 >= 0x17)
    {
      r1 = r0 - 0x1C;
      if ((r0 - 0x1C) < 0x2E)
      {
        *((*_0x200004D8_2) + 0x7) = 0x1F;
      }
      else
      {
        r1 = r0 - 0x4F;
        if ((r0 - 0x4F) < 0x2E)
        {
          *((*_0x200004D8_2) + 0x7) = 0x18;
        }
        else
        {
          r1 = 0x18 - 0x82;
          if ((0x18 - 0x82) < 0x2E)
          {
            *((*_0x200004D8_2) + 0x7) = 0x13;
          }
          else
          {
            r1 = 0x18 - 0xB5;
            if ((0x18 - 0xB5) < 0x2E)
            {
              *((*_0x200004D8_2) + 0x7) = 0xC;
            }
            else
            {
              if ((0x18 - 0xE8) <= 0x17)
              {
                *((*_0x200004D8_2) + 0x7) = 0x0;
              }

            }

          }

        }

      }

    }

    r0 = 0x30;
    func_0x2F68(r0);
  }

  r0 = 0x31;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = func_0xBCF8();
    if (func_0xBCF8() != 0x31)
    {
      if (func_0xBCF8() != 0x5B)
      {
        r0 = 0x31;
        r0 = func_0x1D184(r0, r1, r2);
      }

    }
    else
    {
      r0 = 0x31;
      r0 = func_0x1D184(r0, r1, r2);
      var166 = func_0x1D184(r0, r1, r2) - func_0xBD08(r0);
      if (((int) var166) > 0xFF)
      {
        r0 = 0xFF;
      }

    }

    if (r0 < 0x17)
    {
      *((*_0x200004D8_2) + 0x8) = 0x24;
    }
    else
    {
      r1 = r0 - 0x1C;
      if ((r0 - 0x1C) < 0x2E)
      {
        *((*_0x200004D8_2) + 0x8) = 0x1F;
      }
      else
      {
        r1 = r0 - 0x4F;
        if ((r0 - 0x4F) < 0x2E)
        {
          *((*_0x200004D8_2) + 0x8) = 0x18;
        }
        else
        {
          r1 = 0x18 - 0x82;
          if ((0x18 - 0x82) < 0x2E)
          {
            *((*_0x200004D8_2) + 0x8) = 0x13;
          }
          else
          {
            r1 = 0x18 - 0xB5;
            if ((0x18 - 0xB5) < 0x2E)
            {
              *((*_0x200004D8_2) + 0x8) = 0xC;
            }
            else
            {
              if ((0x18 - 0xE8) <= 0x17)
              {
                *((*_0x200004D8_2) + 0x8) = 0x0;
              }

            }

          }

        }

      }

    }

    r0 = 0x31;
    func_0x2F68(r0);
  }

  r0 = 0x4D;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x4D;
    r0 = func_0x1D184(r0, r1, r2);
    if ((*((*_0x20004CFC_8) + 0x4D5)) != 0)
    {
    }
    else
    {
      var167 = (unsigned int) (0xFC - (*((*_0x20004CFC_8) + 0x4DC)));
    }

    var168 = (0xFF - func_0x1D184(r0, r1, r2)) - var167;
    if ((((int) var168) + 0x9) < 0x13)
    {
      r0 = 0x0;
    }

    if (((int) var168) > 0)
    {
      if (0x0 != 0xF2)
      {
        var169 = (((int) var168) - 0xA) << 0x7;
        var170 = (int) (var169 / (0xF2 - 0x0));
      }
      else
      {
      }

      if (0x0 < 0)
      {
        r0 = 0x0;
      }
      else
      {
        if (0x0 != 0xA)
        {
          var171 = ((var169 + 0xA) << 0x7) / (0x0 - 0xA);
        }
        else
        {
        }

        if (0x0 > 0)
        {
          r0 = 0x0;
        }

      }

    }

    if (r0 != 0)
    {
      var172 = ((r0 * 0xC30D) >> 0x14) - ((r0 * 0xC30D) >> 0x1F);
      *((*_0x200004D8_2) + 0x9) = var172;
      var173 = ((*data_0xEFF8) * r0) & (0xFFFFFFFF00000000 >> 32);
      var174 = (unsigned int) ((var173 * r0) & 0xFFFFFFFF);
      var175 = (var173 >> 0x2) - (var173 >> 0x1F);
      var176 = (var175 - (var175 << 0x3)) + ((var175 - (var175 << 0x3)) << 0x1);
      r0 = r0 + var176;
      var177 = ((float) (r0 + var176)) / 2.100000e+01;
      *((*_0x200004D8_2) + 0x20) = var177;
    }
    else
    {
      var178 = ((r0 + var176) * 0xE39) >> 0x10;
      var179 = var178 - (((r0 + var176) * 0xE39) >> 0x1F);
      *((*_0x200004D8_2) + 0x9) = var179;
      var180 = ((*data_0xEFFC) * (r0 + var176)) & (0xFFFFFFFF00000000 >> 32);
      var181 = (unsigned int) ((var180 * (r0 + var176)) & 0xFFFFFFFF);
      r2 = var180 >> 0x2;
      var182 = (var180 >> 0x2) - (var180 >> 0x1F);
      r1 = 0x0 - var182;
      var183 = (0x0 - var182) + ((0x0 - var182) << 0x3);
      var184 = (r0 + var176) + (var183 << 0x1);
      s0 = (float) var184;
      *((*_0x200004D8_2) + 0x20) = ((float) var184) / 1.800000e+01;
    }

    r0 = 0x4D;
    func_0x2F68(r0);
  }

  r0 = 0x4E;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x4E;
    r0 = func_0x1D184(r0, r1, r2);
    r0 = 0xFF - func_0x1D184(r0, r1, r2);
    var185 = (float) (0xFF - func_0x1D184(r0, r1, r2));
    if ((*((*_0x20004CFC_8) + 0x4E5)) != 0)
    {
    }
    else
    {
      var186 = (unsigned int) (0xFC - (*((*_0x20004CFC_8) + 0x4EC)));
    }

    r1 = var185 - ((float) var186);
    if (((var185 - ((float) var186)) < (*data_0xF000)) || ((var185 - ((float) var186)) < (*data_0xF004)))
    {
      s0 = *data_0xF00C;
    }
    else
    {
      if ((*data_0xF00C) > 0)
      {
        if (var186 != 0xF2)
        {
          var187 = (((*data_0xF00C) - 1.000000e+01) * (*data_0xF008)) / ((float) (0xF2 - var186));
        }
        else
        {
        }

        if ((*data_0xF00C) < 0.0)
        {
        }

      }
      else
      {
        if (var186 != 0xA)
        {
          var188 = (((*data_0xF00C) + 1.000000e+01) * (*data_0xF008)) / ((float) (var186 - 0xA));
        }
        else
        {
        }

        if ((*data_0xF00C) > 0.0)
        {
        }

        s0 = (*data_0xF00C) / (*data_0xF014);
      }

    }

    *((*_0x200004D8_2) + 0x14) = s0;
    r0 = 0x4E;
    func_0x2F68(r0);
  }

  r0 = 0x4F;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = func_0xBCF8();
    if (func_0xBCF8() != 0x4F)
    {
      r0 = 0x4F;
      r0 = func_0x1D184(r0, r1, r2);
    }
    else
    {
      r0 = func_0xBCEC(r0);
      if (func_0xBCEC(r0) != 0)
      {
        r0 = 0x4F;
        r0 = func_0x1D184(r0, r1, r2);
        var189 = func_0x1D184(r0, r1, r2) - func_0xBD08(r0);
      }
      else
      {
        r0 = 0x4F;
        r0 = func_0x1D184(r0, r1, r2);
        var190 = func_0x1D184(r0, r1, r2) - func_0xBD08(r0);
      }

      if (((int) (var190 + 0x7F)) > 0xFF)
      {
        r0 = 0xFF;
      }
      else
      {
        if (0xFF < 0)
        {
          r0 = 0x0;
        }

      }

    }

    r0 = 0xFF - r0;
    *((*_0x200004D8_2) + 0x10) = (float) (0xFF - r0);
    if ((*((*_0x20004CFC_8) + 0x4E5)) != 0)
    {
    }
    else
    {
      var191 = (unsigned int) (0xFC - (*((*_0x20004CFC_8) + 0x4EC)));
    }

    r1 = *((*_0x20004CFC_8) + 0x4F5);
    if ((*((*_0x20004CFC_8) + 0x4F5)) != 0)
    {
      var192 = ((*((*_0x200004D8_2) + 0x10)) / (*data_0xDA90)) - 1.000000e+00;
      *((*_0x200004D8_2) + 0x10) = var192;
    }
    else
    {
      var193 = (*((*_0x200004D8_2) + 0x10)) - ((float) var191);
      *((*_0x200004D8_2) + 0x10) = var193;
      r1 = *((*_0x200004D8_2) + 0x10);
      if ((*((*_0x200004D8_2) + 0x10)) < (*data_0xF000))
      {
        r1 = *((*_0x200004D8_2) + 0x10);
        if ((*((*_0x200004D8_2) + 0x10)) < (*data_0xF004))
        {
          *((*_0x200004D8_2) + 0x10) = *data_0xF00C;
        }

      }

      if ((*((*_0x200004D8_2) + 0x10)) > 0.0)
      {
        if (var191 != 0xF2)
        {
          var194 = ((*((*_0x200004D8_2) + 0x10)) - 1.000000e+01) * (*data_0xF008);
          var195 = var194 / ((float) (0xF2 - var191));
          *((*_0x200004D8_2) + 0x10) = var195;
        }
        else
        {
          *((*_0x200004D8_2) + 0x10) = *data_0xF00C;
        }

        if ((*((*_0x200004D8_2) + 0x10)) < 0.0)
        {
          *((*_0x200004D8_2) + 0x10) = *data_0xF00C;
        }

      }
      else
      {
        if (var191 != 0xA)
        {
          var196 = ((*((*_0x200004D8_2) + 0x10)) + 1.000000e+01) * (*data_0xF008);
          var197 = var196 / ((float) (var191 - 0xA));
          *((*_0x200004D8_2) + 0x10) = var197;
        }
        else
        {
          *((*_0x200004D8_2) + 0x10) = *data_0xF00C;
        }

        *((*_0x200004D8_2) + 0x10) = *data_0xF00C;
      }

    }

    *((*_0x200004D8_2) + 0x10) = (*((*_0x200004D8_2) + 0x10)) / (*data_0xDA90);
    *((*_0x200004D8_2) + 0x18) = *((*_0x200004D8_2) + 0x10);
    r0 = 0x4F;
    func_0x2F68(r0);
  }

  r0 = 0x1;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) == 0)
  {
    r0 = 0x2;
    r0 = func_0x85C8(r0);
    if (func_0x85C8(r0) != 0)
    {
      func_0xCB24(r0, r1, r2);
      r0 = 0x1;
      func_0x2F68(r0);
      r0 = 0x2;
      func_0x2F68(r0);
    }

  }
  else
  {
    func_0xCB24(r0, r1, r2);
    r0 = 0x1;
    func_0x2F68(r0);
    r0 = 0x2;
    func_0x2F68(r0);
  }

  r0 = 0x1F;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) == 0)
  {
    r0 = 0x20;
    r0 = func_0x85C8(r0);
    if (func_0x85C8(r0) != 0)
    {
      func_0xCBA0(r0, r1, r2);
      r0 = 0x1F;
      func_0x2F68(r0);
      r0 = 0x20;
      func_0x2F68(r0);
    }

  }
  else
  {
    func_0xCBA0(r0, r1, r2);
    r0 = 0x1F;
    func_0x2F68(r0);
    r0 = 0x20;
    func_0x2F68(r0);
  }

  r0 = 0x0;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    func_0xCC1C();
    r0 = 0x0;
    func_0x2F68(r0);
  }

  r0 = 0x1E;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    func_0xCCAC();
    r0 = 0x1E;
    func_0x2F68(r0);
  }

  func_0x1446C(r0, r1, r2);
  r0 = 0x32;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    func_0x14428();
    r0 = 0x32;
    func_0x2F68(r0);
  }

  r0 = 0x3A;
  r0 = func_0x85C8(r0);
  if (func_0x85C8(r0) != 0)
  {
    r0 = 0x3A;
    r0 = func_0x1D184(r0, r1, r2);
    r1 = *data_0xF018;
    var198 = (*data_0xF018) + ((0xFF - func_0x1D184(r0, r1, r2)) << 0x3);
    *((*_0x200004D8_2) + 0x1C) = *var198;
  }

}

