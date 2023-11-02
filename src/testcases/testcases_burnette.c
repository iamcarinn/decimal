//-----------------------------------------------------------------
//__________________test 5 add_____________________________________
//-----------------------------------------------------------------
#test s21_add_test

s21_decimal a = {{228, 0, 0, 0}};
s21_decimal b = {{3, 0, 0, 0}};
s21_decimal res1 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_add(a, b, &res1), 0);
ck_assert_int_eq(res1.bits[0], 231);
ck_assert_int_eq(res1.bits[1], 0);
ck_assert_int_eq(res1.bits[2], 0);
ck_assert_int_eq(res1.bits[3], 0);
//---------------------------------
s21_decimal c = {{322, 12345, 0, 0}};
s21_decimal d = {{144, 67890, 4, 0}};
s21_decimal res2 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_add(c, d, &res2), 0);
ck_assert_int_eq(res2.bits[0], 466);
ck_assert_int_eq(res2.bits[1], 80235);
ck_assert_int_eq(res2.bits[2], 4);
ck_assert_int_eq(res2.bits[3], 0);
//---------------------------------
s21_decimal e = {{322, 12345, 0, 0x80000000}};
s21_decimal f = {{556, 67890, 4, 0}};
s21_decimal res3 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_add(e, f, &res3), 0);
ck_assert_int_eq(res3.bits[0], 234);
ck_assert_int_eq(res3.bits[1], 55545);
ck_assert_int_eq(res3.bits[2], 4);
ck_assert_int_eq(res3.bits[3], 0);
//---------------------------------
s21_decimal g = {{12345, 12345, 0, 0b00000000000000110000000000000000}};
s21_decimal h = {{12345, 12345, 0, 0}};
s21_decimal res4 = {{0, 0, 0, 0}};
ck_assert_int_eq(s21_add(g, h, &res4), 0);
ck_assert_int_eq(res4.bits[0], 0b00000000101111001000111011100001);
ck_assert_int_eq(res4.bits[1], 0b00000000101111001000111011100001);
ck_assert_int_eq(res4.bits[2], 0);
ck_assert_int_eq(res4.bits[3], 0b00000000000000110000000000000000);
//---------------------------------
s21_decimal i = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
s21_decimal j = {{8, 0, 0, 0b00000000000000010000000000000000}};
s21_decimal res5 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_add(i, j, &res5), 1);
//----------------------------------------
s21_decimal k = {{12345, 12345, 0, 0x80000000}};
s21_decimal l = {{12345, 12345, 0, 0x80000000}};
s21_decimal res6 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_add(k, l, &res6), 0);
ck_assert_int_eq(res6.bits[0], 24690);
ck_assert_int_eq(res6.bits[1], 24690);
ck_assert_int_eq(res6.bits[2], 0);
ck_assert_int_eq(res6.bits[3], 0x80000000);
//----------------------------------------
s21_decimal m = {{12345, 12345, 0, 0}};
s21_decimal n = {{12345, 12345, 1, 0x80000000}};
s21_decimal res7 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_add(m, n, &res7), 0);
ck_assert_int_eq(res7.bits[0], 0);
ck_assert_int_eq(res7.bits[1], 0);
ck_assert_int_eq(res7.bits[2], 1);
ck_assert_int_eq(res7.bits[3], 0x80000000);

//-----------------------------------------------------------------
//__________________test 6 mul_____________________________________
//-----------------------------------------------------------------
#test s21_mul_test

s21_decimal a = {{228, 0, 0, 0}};
s21_decimal b = {{3, 0, 0, 0}};
s21_decimal res1 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_mul(a, b, &res1), 0);
ck_assert_int_eq(res1.bits[0], 684);
ck_assert_int_eq(res1.bits[1], 0);
ck_assert_int_eq(res1.bits[2], 0);
ck_assert_int_eq(res1.bits[3], 0);
//---------------------------------
s21_decimal c = {{4, 0, 0, 0}};
s21_decimal d = {{20, 0, 0, 0b00000000000000010000000000000000}};
s21_decimal res2 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_mul(c, d, &res2), 0);
ck_assert_int_eq(res2.bits[0], 80);
ck_assert_int_eq(res2.bits[1], 0);
ck_assert_int_eq(res2.bits[2], 0);
ck_assert_int_eq(res2.bits[3], 0b00000000000000010000000000000000);
//---------------------------------
s21_decimal e = {{4, 0, 0, 0b00000000000000010000000000000000}};
s21_decimal f = {{100, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal res3 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_mul(e, f, &res3), 0);
ck_assert_int_eq(res3.bits[0], 400);
ck_assert_int_eq(res3.bits[1], 0);
ck_assert_int_eq(res3.bits[2], 0);
ck_assert_int_eq(res3.bits[3], 0b00000000000000010000000000000000);
//---------------------------------
s21_decimal g = {{228322, 4, 0, 0b00000000000001010000000000000000}};
s21_decimal h = {{322228, 5, 0, 0b00000000000000000000000000000000}};
s21_decimal res4 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_mul(g, h, &res4), 0);
ck_assert_int_eq(res4.bits[0], 0b00100001001101111010111011101000);
ck_assert_int_eq(res4.bits[1], 0b00000000001001010001011001001011);
ck_assert_int_eq(res4.bits[2], 20);
ck_assert_int_eq(res4.bits[3], 0b00000000000001010000000000000000);
//---------------------------------
s21_decimal i = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
s21_decimal j = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
s21_decimal res5 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_mul(i, j, &res5), 1);
//---------------------------------
s21_decimal k = {{1, 0, 0, 0b00000000000111000000000000000000}};
s21_decimal l = {{1, 0, 0, 0b10000000000111000000000000000000}};
s21_decimal res6 = {{0, 0, 0, 0}};
ck_assert_int_eq(s21_mul(k, l, &res6), 2);
//---------------------------------
s21_decimal m = {{0, 0b00000000001000000000000000000000, 0, 0}};
s21_decimal n = {{2048, 0, 0, 0}};
s21_decimal res7 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_mul(m, n, &res7), 0);
ck_assert_int_eq(res7.bits[0], 0);
ck_assert_int_eq(res7.bits[1], 0);
ck_assert_int_eq(res7.bits[2], 1);
ck_assert_int_eq(res7.bits[3], 0);
//-----------------------------------------------------------------
//__________________test 7 sub_____________________________________
//-----------------------------------------------------------------
#test s21_sub_test

s21_decimal a = {{228, 0, 0, 0}};
s21_decimal b = {{3, 0, 0, 0}};
s21_decimal res1 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_sub(a, b, &res1), 0);
ck_assert_int_eq(res1.bits[0], 225);
ck_assert_int_eq(res1.bits[1], 0);
ck_assert_int_eq(res1.bits[2], 0);
ck_assert_int_eq(res1.bits[3], 0);
//---------------------------------
s21_decimal c = {{228, 322, 1337, 0}};
s21_decimal d = {{3, 88, 63, 0x80000000}};
s21_decimal res2 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_sub(c, d, &res2), 0);
ck_assert_int_eq(res2.bits[0], 231);
ck_assert_int_eq(res2.bits[1], 410);
ck_assert_int_eq(res2.bits[2], 1400);
ck_assert_int_eq(res2.bits[3], 0);
//---------------------------------
s21_decimal e = {{228, 322, 1337, 0x80000000}};
s21_decimal f = {{8, 300, 63, 0}};
s21_decimal res3 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_sub(e, f, &res3), 0);
ck_assert_int_eq(res3.bits[0], 236);
ck_assert_int_eq(res3.bits[1], 622);
ck_assert_int_eq(res3.bits[2], 1400);
ck_assert_int_eq(res3.bits[3], 0x80000000);
//---------------------------------
s21_decimal g = {{228, 322, 1337, 0x80000000}};
s21_decimal h = {{228, 1400, 1400, 0x80000000}};
s21_decimal res4 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_sub(g, h, &res4), 0);
ck_assert_int_eq(res4.bits[0], 0);
ck_assert_int_eq(res4.bits[1], 1078);
ck_assert_int_eq(res4.bits[2], 63);
ck_assert_int_eq(res4.bits[3], 0);

//---------------------------------
s21_decimal i = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
s21_decimal j = {{8, 0, 0, 0b00000000000000010000000000000000}};
s21_decimal res5 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_sub(i, j, &res5), 0);
ck_assert_int_eq(res5.bits[0], 0xfffffffe);
ck_assert_int_eq(res5.bits[1], 0xffffffff);
ck_assert_int_eq(res5.bits[2], 0xffffffff);
ck_assert_int_eq(res5.bits[3], 0);

//-----------------------------------------------------------------
//__________________test 7 div_____________________________________
//-----------------------------------------------------------------
#test s21_div_test
s21_decimal a = {{9, 0, 0, 0x80000000}};
s21_decimal b = {{3, 0, 0, 0}};
s21_decimal res1 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_div(a, b, &res1), 0);
ck_assert_int_eq(res1.bits[0], 3);
ck_assert_int_eq(res1.bits[1], 0);
ck_assert_int_eq(res1.bits[2], 0);
ck_assert_int_eq(res1.bits[3], 0x80000000);
//--------------------------------------------------------------------
s21_decimal c = {{9, 0, 0, 0x80000000}};
s21_decimal d = {{0, 0, 0, 0}};
s21_decimal res2 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_div(c, d, &res2), 3);
//--------------------------------------------------------------------
s21_decimal e = {{1, 0, 0, 0}};
s21_decimal f = {{1, 0, 0, 0x1F8000}};
ck_assert_int_eq(s21_div(e, f, &res2), 1);
//--------------------------------------------------------------------

s21_decimal g = {{0xfffffffe, 0xffffffff, 0xffffffff, 0}};
s21_decimal h = {{2, 0, 0, 0}};
s21_decimal res3 = {{0, 0, 0, 0}};

ck_assert_int_eq(s21_div(g, h, &res3), 0);
ck_assert_int_eq(res3.bits[0], 0xffffffff);
ck_assert_int_eq(res3.bits[1], 0xffffffff);
ck_assert_int_eq(res3.bits[2], 0x7fffffff);
ck_assert_int_eq(res3.bits[3], 0);

//--------------------------------------------------------------------

s21_decimal i = {
    {0xffffffff, 0xffffffff, 0xffffffff, 0b00000000000011111000000000000000}};
s21_decimal j = {{2, 0, 0, 0}};

ck_assert_int_eq(s21_div(i, j, &res3), 0);
ck_assert_int_eq(res3.bits[0], 0);
ck_assert_int_eq(res3.bits[1], 0);
ck_assert_int_eq(res3.bits[2], 0x80000000);
ck_assert_int_eq(res3.bits[3], 0xF0000);
