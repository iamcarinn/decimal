#include "s21_decimal.h"
//-----------------------------------------------------------------
//__________________test 1 from s21_decimal to int_____________________
//-----------------------------------------------------------------

#test s21_from_decimal_to_int_test

s21_decimal a = {{2, 0, 0, 0x80000000}};
s21_decimal b = {{228322, 0, 0, 0}};
s21_decimal c = {{1234, 0, 0, 0b00000000000000010000000000000000}};
s21_decimal d = {{123445, 132123, 0, 0}};
s21_decimal i = {{123445, 0, 0, 0b11111111111111111111111111111111}};
int e = 0;
int f = 0;
int g = 0;
int h = 0;

ck_assert_int_eq(s21_from_decimal_to_int(a, &e), 0);
ck_assert_int_eq(e, -2);

ck_assert_int_eq(s21_from_decimal_to_int(b, &f), 0);
ck_assert_int_eq(f, 228322);

ck_assert_int_eq(s21_from_decimal_to_int(c, &g), 0);
ck_assert_int_eq(g, 123);

ck_assert_int_eq(s21_from_decimal_to_int(d, &h), 1);
ck_assert_int_eq(s21_from_decimal_to_int(b, NULL), 1);
ck_assert_int_eq(s21_from_decimal_to_int(b, NULL), 1);
ck_assert_int_eq(s21_from_decimal_to_int(i, &h), 1);

//-----------------------------------------------------------------
//__________________test 2 from int to decimal_____________________
//-----------------------------------------------------------------

#test s21_from_int_to_decimal_test

s21_decimal a = {{0, 0, 0, 0}};
s21_decimal b = {{0, 0, 0, 0}};
s21_decimal c = {{0, 0, 0, 0}};
s21_decimal d = {{0, 0, 0, 0}};
s21_decimal i = {{0, 0, 0, 0}};
s21_decimal k = {{0, 0, 0, 0}};

int e = 228;
int f = 322;
int g = -1337;
int h = 0;
int j = 2147483647;
int l = -2147483647;

ck_assert_int_eq(s21_from_int_to_decimal(e, &a), 0);
ck_assert_int_eq(e, a.bits[0]);

ck_assert_int_eq(s21_from_int_to_decimal(f, &b), 0);
ck_assert_int_eq(f, b.bits[0]);

ck_assert_int_eq(s21_from_int_to_decimal(g, &c), 0);
ck_assert_int_eq(-g, c.bits[0]);
ck_assert_int_eq(0x80000000, c.bits[3]);

ck_assert_int_eq(s21_from_int_to_decimal(h, &d), 0);
ck_assert_int_eq(h, d.bits[0]);

ck_assert_int_eq(s21_from_int_to_decimal(j, &i), 0);
ck_assert_int_eq(j, i.bits[0]);

ck_assert_int_eq(s21_from_int_to_decimal(l, &k), 0);
ck_assert_int_eq(-l, k.bits[0]);
ck_assert_int_eq(0x80000000, k.bits[3]);

ck_assert_int_eq(s21_from_int_to_decimal(l, NULL), 1);

//-----------------------------------------------------------------
//__________________test 3 from s21_decimal to float___________________
//-----------------------------------------------------------------

#test s21_from_decimal_to_float_test

s21_decimal a = {{2, 0, 0, 0x80000000}};
s21_decimal b = {{228322, 4, 0, 0b000000000000001010000000000000000}};
s21_decimal c = {{0, 0, 0, 0x80000000}};
s21_decimal d = {{0, 0, 0, 0}};
s21_decimal i = {{0b11101011000111110000101011010010,
                  0b10101011010101001010100110001100, 0,
                  0b000000000000101000000000000000000}};  //  0.1234567890123...
s21_decimal k = {
    {0b01101010110111001011101011000000, 0b10011000001000100111111010101010,
     0b00000000000010100011011001001100, 0b10000000000101110000000000000000}};

float e = 0.0;
float f = 0.0;
float g = 0.0;
float h = 0.0;
float j = 0.0;
float l = 0.0;

ck_assert_int_eq(s21_from_decimal_to_float(a, &e), 0);
ck_assert_float_eq_tol(e, -2.0, 1e-9);
ck_assert_int_eq(s21_from_decimal_to_float(b, &f), 0);
ck_assert_float_eq_tol(f, 171800.97506, 1e-9);
ck_assert_int_eq(s21_from_decimal_to_float(c, &g), 0);
ck_assert_float_eq(g, -0.0);
ck_assert_int_eq(s21_from_decimal_to_float(c, NULL), 1);
ck_assert_int_eq(s21_from_decimal_to_float((s21_decimal){{0, 0, 0, 0xffffffff}},
                                           &e),
                 1);

ck_assert_int_eq(s21_from_decimal_to_float(d, &h), 0);
ck_assert_float_eq(h, -0.0);
ck_assert_int_eq(s21_from_decimal_to_float(i, &j), 0);
ck_assert_float_eq_tol(j, 0.123457, 1e-6);
ck_assert_int_eq(s21_from_decimal_to_float(k, &l), 0);
ck_assert_float_eq_tol(l, -123.457, 1e-3);

//-----------------------------------------------------------------
//__________________test 4 from float to decimal___________________
//-----------------------------------------------------------------
#test s21_from_float_to_decimal_test

s21_decimal a = {{0, 0, 0, 0}};
s21_decimal b = {{0, 0, 0, 0}};
s21_decimal c = {{0, 0, 0, 0}};
s21_decimal d = {{0, 0, 0, 0}};
s21_decimal j = {{0, 0, 0, 0}};
s21_decimal l = {{0, 0, 0, 0}};
s21_decimal n = {{0, 0, 0, 0}};
s21_decimal o = {{0, 0, 0, 0}};

float e = 0.00228;
float f = 3221231231;
float g = -1337.55532;
float h = -0.034132;
float i = 12345678912345;
float k = 3e-29;
float m = 2e30;
float p = 248e26;

ck_assert_int_eq(s21_from_float_to_decimal(e, &a), 0);
ck_assert_int_eq(a.bits[0], 0b1000101100101001000000);
ck_assert_int_eq(a.bits[1], 0);
ck_assert_int_eq(a.bits[2], 0);
ck_assert_int_eq(a.bits[3], 0b000000000000010010000000000000000);

ck_assert_int_eq(s21_from_float_to_decimal(f, &b), 0);
ck_assert_int_eq(b.bits[0], 0b11000000000000000001010110011000);
ck_assert_int_eq(b.bits[1], 0);
ck_assert_int_eq(b.bits[2], 0);
ck_assert_int_eq(b.bits[3], 0);

ck_assert_int_eq(s21_from_float_to_decimal(g, &c), 0);
ck_assert_int_eq(c.bits[0], 0b101000110100011010011);
ck_assert_int_eq(c.bits[1], 0);
ck_assert_int_eq(c.bits[2], 0);
ck_assert_int_eq(c.bits[3], 0b10000000000000110000000000000000);

ck_assert_int_eq(s21_from_float_to_decimal(h, &d), 0);
ck_assert_int_eq(d.bits[0], 0b1101000001010011010000);
ck_assert_int_eq(d.bits[1], 0);
ck_assert_int_eq(d.bits[2], 0);
ck_assert_int_eq(d.bits[3], 0b10000000000010000000000000000000);

ck_assert_int_eq(s21_from_float_to_decimal(i, &j), 0);
ck_assert_int_eq(j.bits[0], 0b01110011110111101111010000000000);
ck_assert_int_eq(j.bits[1], 0b00000000000000000000101100111010);
ck_assert_int_eq(j.bits[2], 0);
ck_assert_int_eq(j.bits[3], 0);

ck_assert_int_eq(s21_from_float_to_decimal(k, &l), 1);
ck_assert_int_eq(s21_from_float_to_decimal(m, &n), 1);
ck_assert_int_eq(s21_from_float_to_decimal(h, NULL), 1);

ck_assert_int_eq(s21_from_float_to_decimal(p, &o), 0);
ck_assert_int_eq(o.bits[0], 0b11100000000000000000000000000000);
ck_assert_int_eq(o.bits[1], 0b11100001110011000110110001001100);
ck_assert_int_eq(o.bits[2], 0b01010000001000100001010001000101);
ck_assert_int_eq(o.bits[3], 0);
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
#test s21_is_equal_test
//-----------------------------------------------------------------
//__________________test is equal_________________________________
//-----------------------------------------------------------------

s21_decimal dec1 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec2 = {{188, 0, 0, 131072}};  // 1.88
int res1 = s21_is_equal(dec1, dec2);
ck_assert_int_eq(res1, 0);

s21_decimal dec3 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec4 = {{123, 0, 0, 131072}};  // 1.23
int res2 = s21_is_equal(dec3, dec4);
ck_assert_int_eq(res2, 1);

s21_decimal dec5 = {{123, 0, 0, 131072}};      // 1.23
s21_decimal dec6 = {{123, 0, 0, 2147352576}};  // -1.23
int res3 = s21_is_equal(dec5, dec6);
ck_assert_int_eq(res3, 0);

s21_decimal dec7 = {{0, 0, 0, 0}};  // 0
s21_decimal dec8 = {{0, 0, 0, 0}};  // 0
int res4 = s21_is_equal(dec7, dec8);
ck_assert_int_eq(res4, 1);

s21_decimal dec9 = {{8, 0, 0, 2147483648}};   // -8
s21_decimal dec10 = {{8, 0, 0, 2147483648}};  // -8
int res5 = s21_is_equal(dec9, dec10);
ck_assert_int_eq(res5, 1);

s21_decimal dec11 = {{812324465, 0, 0, 2148073472}};  // -8.12324465
s21_decimal dec12 = {{81, 0, 0, 2147549184}};         // -8.1
int res6 = s21_is_equal(dec11, dec12);
ck_assert_int_eq(res6, 0);

s21_decimal dec13 = {{1451232446, 0, 0, 2148073472}};  // -145.1232446
s21_decimal dec14 = {{81, 0, 0, 2147549184}};          // -8.1
int res7 = s21_is_equal(dec13, dec14);
ck_assert_int_eq(res7, 0);

s21_decimal dec15 = {
    {3826123425, 752583898, 0, 2148663296}};  // -3.232323233232323233
s21_decimal dec16 = {{3796893695, 192705379, 187211,
                      2148663296}};  // -34545124.232446543232446543;
int res8 = s21_is_equal(dec15, dec16);
ck_assert_int_eq(res8, 0);

s21_decimal src1, src2;
// src1 = 9999999999999999999;
// src2 = 1;
src1.bits[0] = 0b10001001111001111111111111111111;
src1.bits[1] = 0b10001010110001110010001100000100;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000000000000000000000;
src2.bits[0] = 0b00000000000000000000000000000001;
src2.bits[1] = 0b00000000000000000000000000000000;
src2.bits[2] = 0b00000000000000000000000000000000;
src2.bits[3] = 0b00000000000000000000000000000000;
int res9 = s21_is_equal(src1, src2);
ck_assert_int_eq(res9, 0);

#test s21_is_greater_test
//-----------------------------------------------------------------
//__________________test is greater________________________________
//-----------------------------------------------------------------

s21_decimal dec1 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec2 = {{188, 0, 0, 131072}};  // 1.88
int res1 = s21_is_greater(dec1, dec2);
ck_assert_int_eq(res1, 0);

s21_decimal dec3 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec4 = {{123, 0, 0, 131072}};  // 1.23
int res2 = s21_is_greater(dec3, dec4);
ck_assert_int_eq(res2, 0);

s21_decimal dec5 = {{123, 0, 0, 131072}};      // 1.23
s21_decimal dec6 = {{123, 0, 0, 2147352576}};  // -1.23
int res3 = s21_is_greater(dec5, dec6);
ck_assert_int_eq(res3, 1);

s21_decimal dec7 = {{0, 0, 0, 0}};  // 0
s21_decimal dec8 = {{0, 0, 0, 0}};  // 0
int res4 = s21_is_greater(dec7, dec8);
ck_assert_int_eq(res4, 0);

s21_decimal dec9 = {{8, 0, 0, 2147483648}};   // -8;
s21_decimal dec10 = {{8, 0, 0, 2147483648}};  // -8;
int res5 = s21_is_greater(dec9, dec10);
ck_assert_int_eq(res5, 0);

s21_decimal dec11 = {{3232446546, 0, 0, 2148073472}};  // -3.232446546
s21_decimal dec12 = {{323, 0, 0, 2147352576}};         // -3.23
int res6 = s21_is_greater(dec11, dec12);
ck_assert_int_eq(res6, 0);

s21_decimal dec13 = {{1451232446, 0, 0, 0x80070000}};  // -145.1232446
s21_decimal dec14 = {{81, 0, 0, 0x80010000}};          // -8.1
int res7 = s21_is_greater(dec13, dec14);
ck_assert_int_eq(res7, 0);

s21_decimal dec15 = {
    {3826123425, 752583898, 0, 2148663296}};  // -3.232323233232323233
s21_decimal dec16 = {{3796893695, 192705379, 187211,
                      2148663296}};  // -34545124.232446543232446543;
int res8 = s21_is_greater(dec15, dec16);
ck_assert_int_eq(res8, 1);

s21_decimal dec17 = {
    {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
s21_decimal dec18 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
ck_assert_int_eq(s21_is_greater(dec17, dec18), 1);
ck_assert_int_eq(s21_is_greater(dec18, dec17), 0);

s21_decimal dec19 = {
    {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
s21_decimal dec20 = {{12, 0, 0, 0b00000000000000010000000000000000}};
ck_assert_int_eq(s21_is_greater(dec20, dec19), 1);

s21_decimal dec21 = {
    {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
s21_decimal dec22 = {{12, 0, 0, 0b00000000000000010000000000000000}};
ck_assert_int_eq(s21_is_greater(dec22, dec21), 0);

s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}};
s21_decimal b = {{S21_MAX_UINT, S21_MAX_UINT - 1, 0, 0}};
ck_assert_int_eq(s21_is_greater(a, b), 1);

s21_decimal c = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}};
s21_decimal d = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}};
ck_assert_int_eq(s21_is_greater(c, d), 0);

s21_decimal e = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
s21_decimal f = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT - 1, 0}};
ck_assert_int_eq(s21_is_greater(e, f), 1);

s21_decimal src1, src2;
// src1 = -545454512454545.35265454545645;
// src2 = 54564654;
src1.bits[0] = 0b10000010111000100101101011101101;
src1.bits[1] = 0b11111001111010000010010110101101;
src1.bits[2] = 0b10110000001111101111000010010100;
src1.bits[3] = 0b10000000000011100000000000000000;
src2.bits[0] = 0b00000011010000001001011100101110;
src2.bits[1] = 0b00000000000000000000000000000000;
src2.bits[2] = 0b00000000000000000000000000000000;
src2.bits[3] = 0b00000000000000000000000000000000;
int result = s21_is_greater(src1, src2);
ck_assert_int_eq(result, 0);

#test s21_is_greater_or_equeal_test
//-----------------------------------------------------------------
//__________________test is greater or equal_____________________
//-----------------------------------------------------------------

// float num1 = 1.375323;
// float num2 = 1.39;
s21_decimal dec1 = {{952788803, 320, 0, 2148204544}};
s21_decimal dec2 = {{139, 0, 0, 131072}};
int res1 = s21_is_greater_or_equal(dec1, dec2);
ck_assert_int_eq(res1, 0);

//  int num1 = 2;
//  int num2 = 1;
s21_decimal dec3 = {{2, 0, 0, 0}};
s21_decimal dec4 = {{1, 0, 0, 0}};
int res2 = s21_is_greater_or_equal(dec3, dec4);
ck_assert_int_eq(res2, 1);

// float num1 = 1.39;
// float num2 = -1.39;
s21_decimal dec5 = {{139, 0, 0, 131072}};
s21_decimal dec6 = {{139, 0, 0, 2147614720}};
int res3 = s21_is_greater_or_equal(dec5, dec6);
ck_assert_int_eq(res3, 1);

//  int num1 = 0;
//  int num2 = 0;
s21_decimal dec7 = {{0, 0, 0, 0}};
s21_decimal dec8 = {{0, 0, 0, 0}};
int res4 = s21_is_greater_or_equal(dec7, dec8);
ck_assert_int_eq(res4, 1);

//  int num1 = -3;
//  int num2 = -3;
//  s21_decimal dec1, dec2;
s21_decimal dec9 = {{3, 0, 0, 2147483648}};
s21_decimal dec10 = {{3, 0, 0, 2147483648}};
int res5 = s21_is_greater(dec9, dec10);
ck_assert_int_eq(res5, 0);

// float num1 = 10423546.34534534;
// float num2 = 3.34534534;

s21_decimal dec11 = {{431533702, 242692, 0, 524288}};
s21_decimal dec12 = {{334534534, 0, 0, 524288}};
int res6 = s21_is_greater_or_equal(dec11, dec12);
ck_assert_int_eq(res6, 1);

// float num1 = 1042634.34534534;
// float num2 = 10424546.34534534;
s21_decimal dec13 = {{3103424134, 24275, 0, 524288}};
s21_decimal dec14 = {{1647285894, 242715, 0, 524288}};
int res7 = s21_is_greater_or_equal(dec13, dec14);
ck_assert_int_eq(res7, 0);

// float num1 = 10426.34534534;
// float num2 = 104234.345345;
s21_decimal dec15 = {{3252448902, 242, 0, 524288}};
s21_decimal dec16 = {{1155130241, 24, 0, 393216}};
int res8 = s21_is_greater_or_equal(dec15, dec16);
ck_assert_int_eq(res8, 0);

// float num1 = 1042.5667777;
// float num2 = 1042.345345;
s21_decimal dec17 = {{1835733185, 2, 0, 458752}};
s21_decimal dec18 = {{1042345345, 0, 0, 393216}};
int res9 = s21_is_greater_or_equal(dec17, dec18);
ck_assert_int_eq(res9, 1);

s21_decimal dec19 = {
    {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
s21_decimal dec20 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //
ck_assert_int_eq(s21_is_greater_or_equal(dec19, dec20), 1);
ck_assert_int_eq(s21_is_greater_or_equal(dec20, dec19), 0);

s21_decimal dec21 = {
    {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
s21_decimal dec22 = {{12, 0, 0, 0b00000000000000010000000000000000}};
ck_assert_int_eq(s21_is_greater_or_equal(dec21, dec22), 0);
ck_assert_int_eq(s21_is_greater_or_equal(dec22, dec21), 1);

s21_decimal dec23 = {
    {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
s21_decimal dec24 = {{12, 0, 0, 0b00000000000000010000000000000000}};
ck_assert_int_eq(s21_is_greater_or_equal(dec23, dec24), 1);
ck_assert_int_eq(s21_is_greater_or_equal(dec24, dec23), 0);

s21_decimal dec25 = {
    {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
s21_decimal dec26 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //

ck_assert_int_eq(s21_is_greater_or_equal(dec25, dec26), 0);
ck_assert_int_eq(s21_is_greater_or_equal(dec26, dec25), 1);

s21_decimal dec27 = {{12345, 0, 0, 0}};
s21_decimal dec28 = {{12345, 0, 0, 0}};
ck_assert_int_eq(s21_is_greater_or_equal(dec27, dec28), 1);
ck_assert_int_eq(s21_is_greater_or_equal(dec28, dec27), 1);

s21_decimal dec29 = {{0, 0, 0, 0}};
s21_decimal dec30 = {{0, 0, 0, 0}};
ck_assert_int_eq(s21_is_greater_or_equal(dec29, dec30), 1);
ck_assert_int_eq(s21_is_greater_or_equal(dec30, dec29), 1);

#test s21_is_less_test
//-----------------------------------------------------------------
//__________________test is less___________________________________
//-----------------------------------------------------------------

s21_decimal dec1 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec2 = {{188, 0, 0, 131072}};  // 1.88
int res1 = s21_is_less(dec1, dec2);
ck_assert_int_eq(res1, 1);

s21_decimal dec3 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec4 = {{123, 0, 0, 131072}};  // 1.23
int res2 = s21_is_less(dec3, dec4);
ck_assert_int_eq(res2, 0);

s21_decimal dec5 = {{123, 0, 0, 131072}};      // 1.23
s21_decimal dec6 = {{123, 0, 0, 2147352576}};  // -1.23
int res3 = s21_is_less(dec5, dec6);
ck_assert_int_eq(res3, 0);

s21_decimal dec7 = {{0, 0, 0, 0}};  // 0
s21_decimal dec8 = {{0, 0, 0, 0}};  // 0
int res4 = s21_is_less(dec7, dec8);
ck_assert_int_eq(res4, 0);

s21_decimal dec9 = {{8, 0, 0, 2147483648}};   // -8
s21_decimal dec10 = {{8, 0, 0, 2147483648}};  // -8
int res5 = s21_is_less(dec9, dec10);
ck_assert_int_eq(res5, 0);

s21_decimal dec11 = {{3232446546, 0, 0, 2148073472}};  // -3.232446546
s21_decimal dec12 = {{32, 0, 0, 2147549184}};          // -3.2
int res6 = s21_is_less(dec11, dec12);
ck_assert_int_eq(res6, 1);

s21_decimal dec13 = {{889192447, 3659439603, 1872120, 2148663296}};
// -34534534.232446543232446543
s21_decimal dec14 = {{3826123425, 752583898, 0, 2148663296}};
// -3.232323233232323233
int res7 = s21_is_less(dec13, dec14);
ck_assert_int_eq(res7, 1);

s21_decimal dec15 = {{12345, 0, 0, 0b00000000000001000000000000000000}};
//  1.2345
s21_decimal dec16 = {{12, 0, 0, 0b10000000000000010000000000000000}};
//-1.2
ck_assert_int_eq(s21_is_less(dec15, dec16), 0);
ck_assert_int_eq(s21_is_less(dec16, dec15), 1);

s21_decimal dec17 = {{12345, 0, 0, 0b10000000000001000000000000000000}};
// -1.2345
s21_decimal dec18 = {{12, 0, 0, 0b00000000000000010000000000000000}};
//  1.2;
ck_assert_int_eq(s21_is_less(dec17, dec18), 1);
ck_assert_int_eq(s21_is_less(dec18, dec17), 0);

s21_decimal dec19 = {{12345, 0, 0, 0b00000000000001000000000000000000}};
//  1.2345
s21_decimal dec20 = {{12, 0, 0, 0b00000000000000010000000000000000}};
//  1.2;
ck_assert_int_eq(s21_is_less(dec19, dec20), 0);
ck_assert_int_eq(s21_is_less(dec20, dec19), 1);

s21_decimal dec21 = {{12345, 0, 0, 0b10000000000001000000000000000000}};
// -1.2345
s21_decimal dec22 = {{12, 0, 0, 0b10000000000000010000000000000000}};
//  -1.2;
ck_assert_int_eq(s21_is_less(dec21, dec22), 1);
ck_assert_int_eq(s21_is_less(dec22, dec21), 0);

s21_decimal dec23 = {{12345, 0, 0, 0}};
s21_decimal dec24 = {{12345, 0, 0, 0}};
ck_assert_int_eq(s21_is_less(dec23, dec24), 0);
ck_assert_int_eq(s21_is_less(dec24, dec23), 0);

s21_decimal src1, src2;
// src1 = -545454512454545.35265454545645;
// src2 = 54564654;
src1.bits[0] = 0b10000010111000100101101011101101;
src1.bits[1] = 0b11111001111010000010010110101101;
src1.bits[2] = 0b10110000001111101111000010010100;
src1.bits[3] = 0b10000000000011100000000000000000;
src2.bits[0] = 0b00000011010000001001011100101110;
src2.bits[1] = 0b00000000000000000000000000000000;
src2.bits[2] = 0b00000000000000000000000000000000;
src2.bits[3] = 0b00000000000000000000000000000000;
int res8 = s21_is_less(src1, src2);
ck_assert_int_eq(res8, 1);

#test s21_is_less_or_equal_test
//-----------------------------------------------------------------
//__________________test is less or equal__________________________
//-----------------------------------------------------------------

s21_decimal dec1 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec2 = {{188, 0, 0, 131072}};  // 1.88
int res1 = s21_is_less_or_equal(dec1, dec2);
ck_assert_int_eq(res1, 1);

s21_decimal dec3 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec4 = {{123, 0, 0, 131072}};  // 1.23
int res2 = s21_is_less_or_equal(dec3, dec4);
ck_assert_int_eq(res2, 1);

s21_decimal dec5 = {{123, 0, 0, 131072}};      // 1.23
s21_decimal dec6 = {{123, 0, 0, 2147352576}};  // -1.23
int res3 = s21_is_less_or_equal(dec5, dec6);
ck_assert_int_eq(res3, 0);

s21_decimal dec7 = {{0, 0, 0, 0}};  // 0
s21_decimal dec8 = {{0, 0, 0, 0}};  // 0
int res4 = s21_is_less_or_equal(dec7, dec8);
ck_assert_int_eq(res4, 1);

s21_decimal dec9 = {{8, 0, 0, 2147483648}};   // -8
s21_decimal dec10 = {{8, 0, 0, 2147483648}};  // -8
int res5 = s21_is_less_or_equal(dec9, dec10);
ck_assert_int_eq(res5, 1);

s21_decimal dec11 = {{812324465, 0, 0, 0x80080000}};  // -8.12324465
s21_decimal dec12 = {{81, 0, 0, 0x80010000}};         // -8.1
int res6 = s21_is_less_or_equal(dec11, dec12);
ck_assert_int_eq(res6, 1);

s21_decimal dec13 = {{1451232446, 0, 0, 0x80070000}};  // -145.1232446
s21_decimal dec14 = {{81, 0, 0, 0x80010000}};          // -8.1
int res7 = s21_is_less_or_equal(dec13, dec14);
ck_assert_int_eq(res7, 1);

s21_decimal dec15 = {
    {3826123425, 752583898, 0, 2148663296}};  // -3.232323233232323233
s21_decimal dec16 = {{3796893695, 192705379, 187211,
                      2148663296}};  // -34545124.232446543232446543;
int res8 = s21_is_less_or_equal(dec15, dec16);
ck_assert_int_eq(res8, 0);

s21_decimal src1, src2;
// src1 = 9999999999999999999;
// src2 = 1;
src1.bits[0] = 0b10001001111001111111111111111111;
src1.bits[1] = 0b10001010110001110010001100000100;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000000000000000000000;
src2.bits[0] = 0b00000000000000000000000000000001;
src2.bits[1] = 0b00000000000000000000000000000000;
src2.bits[2] = 0b00000000000000000000000000000000;
src2.bits[3] = 0b00000000000000000000000000000000;
int res9 = s21_is_less_or_equal(src1, src2);
ck_assert_int_eq(res9, 0);

#test s21_is_not_equal_test
//-----------------------------------------------------------------
//__________________test is not equal______________________________
//-----------------------------------------------------------------

s21_decimal dec1 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec2 = {{188, 0, 0, 131072}};  // 1.88
int res1 = s21_is_not_equal(dec1, dec2);
ck_assert_int_eq(res1, 1);

s21_decimal dec3 = {{123, 0, 0, 131072}};  // 1.23
s21_decimal dec4 = {{123, 0, 0, 131072}};  // 1.23
int res2 = s21_is_not_equal(dec3, dec4);
ck_assert_int_eq(res2, 0);

s21_decimal dec5 = {{123, 0, 0, 131072}};      // 1.23
s21_decimal dec6 = {{123, 0, 0, 2147352576}};  // -1.23
int res3 = s21_is_not_equal(dec5, dec6);
ck_assert_int_eq(res3, 1);

s21_decimal dec7 = {{0, 0, 0, 0}};  // 0
s21_decimal dec8 = {{0, 0, 0, 0}};  // 0
int res4 = s21_is_not_equal(dec7, dec8);
ck_assert_int_eq(res4, 0);

s21_decimal dec9 = {{8, 0, 0, 2147483648}};   // -8
s21_decimal dec10 = {{8, 0, 0, 2147483648}};  // -8
int res5 = s21_is_not_equal(dec9, dec10);
ck_assert_int_eq(res5, 0);

s21_decimal dec11 = {{812324465, 0, 0, 2148073472}};  // -8.12324465
s21_decimal dec12 = {{81, 0, 0, 2147549184}};         // -8.1
int res6 = s21_is_not_equal(dec11, dec12);
ck_assert_int_eq(res6, 1);

s21_decimal dec13 = {{1451232446, 0, 0, 2148073472}};  // -145.1232446
s21_decimal dec14 = {{81, 0, 0, 2147549184}};          // -8.1
int res7 = s21_is_not_equal(dec13, dec14);
ck_assert_int_eq(res7, 1);

s21_decimal dec15 = {
    {3826123425, 752583898, 0, 2148663296}};  // -3.232323233232323233
s21_decimal dec16 = {{3796893695, 192705379, 187211,
                      2148663296}};  // -34545124.232446543232446543;
int res8 = s21_is_not_equal(dec15, dec16);
ck_assert_int_eq(res8, 1);

s21_decimal src1, src2;
// src1 = 9999999999999999999;
// src2 = 1;
src1.bits[0] = 0b10001001111001111111111111111111;
src1.bits[1] = 0b10001010110001110010001100000100;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000000000000000000000;
src2.bits[0] = 0b00000000000000000000000000000001;
src2.bits[1] = 0b00000000000000000000000000000000;
src2.bits[2] = 0b00000000000000000000000000000000;
src2.bits[3] = 0b00000000000000000000000000000000;
int res9 = s21_is_not_equal(src1, src2);
ck_assert_int_eq(res9, 1);

// FLOOR
#test nutmegha_1
s21_decimal src, origin, result;
// src = 5.0;
src.bits[0] = 0b00000000000000000000000000110010;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000000010000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 5;
origin.bits[0] = 0b00000000000000000000000000000101;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_2
s21_decimal src, origin, result;
// src = 3.4;
src.bits[0] = 0b00000000000000000000000000100010;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000000010000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 3;
origin.bits[0] = 0b00000000000000000000000000000011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_3
s21_decimal src, origin, result;
// src = 0.0;
src.bits[0] = 0b00000000000000000000000000000000;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000000010000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_4
s21_decimal src, origin, result;
// src = -2.4363463;
src.bits[0] = 0b00000001011100111100000111000111;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000001110000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = -3;
origin.bits[0] = 0b00000000000000000000000000000011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_5
s21_decimal src, origin, result;
// src = -0.0;
src.bits[0] = 0b00000000000000000000000000000000;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000000010000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_6
s21_decimal src, origin, result;
// src = -0.45;
src.bits[0] = 0b00000000000000000000000000101101;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000000100000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = -1;
origin.bits[0] = 0b00000000000000000000000000000001;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_7
s21_decimal src, origin, result;
// src = 652.34631;
src.bits[0] = 0b00000011111000110110011011000111;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000001010000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 652;
origin.bits[0] = 0b00000000000000000000001010001100;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_8
s21_decimal src, origin, result;
// src = 4.97623323;
src.bits[0] = 0b00011101101010010010000100011011;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000010000000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 4;
origin.bits[0] = 0b00000000000000000000000000000100;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_9
s21_decimal src, origin, result;
// src = 65658654.59;
src.bits[0] = 0b10000111010110110010011111110011;
src.bits[1] = 0b00000000000000000000000000000001;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000000100000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 65658654;
origin.bits[0] = 0b00000011111010011101111100011110;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_10
s21_decimal src, origin, result;
// src = -364748.110;
src.bits[0] = 0b00010101101111011001110101001110;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000000110000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = -364749;
origin.bits[0] = 0b00000000000001011001000011001101;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_11
s21_decimal src, origin, result;
// src = 1.9874565432111;
src.bits[0] = 0b01101000011010011010001100101111;
src.bits[1] = 0b00000000000000000001001000010011;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000011010000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 1;
origin.bits[0] = 0b00000000000000000000000000000001;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_12
s21_decimal src, origin, result;
// src = -98.78798789312;
src.bits[0] = 0b00010110010010101110101011000000;
src.bits[1] = 0b00000000000000000000100011111100;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000010110000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = -99;
origin.bits[0] = 0b00000000000000000000000001100011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_13
s21_decimal src, origin, result;
// src = 999999999999999999911.3;
src.bits[0] = 0b10110010001111111111110010001001;
src.bits[1] = 0b00011001111000001100100110111010;
src.bits[2] = 0b00000000000000000000001000011110;
src.bits[3] = 0b00000000000000010000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 999999999999999999911;
origin.bits[0] = 0b11011110100111111111111110100111;
origin.bits[1] = 0b00110101110010011010110111000101;
origin.bits[2] = 0b00000000000000000000000000110110;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_14
s21_decimal src, origin, result;
// src = -545454512454545.35265454545645;
src.bits[0] = 0b10000010111000100101101011101101;
src.bits[1] = 0b11111001111010000010010110101101;
src.bits[2] = 0b10110000001111101111000010010100;
src.bits[3] = 0b10000000000011100000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = -545454512454546;
origin.bits[0] = 0b10000110011101001011101110010010;
origin.bits[1] = 0b00000000000000011111000000010110;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_15
s21_decimal src, origin, result;
// src = 545454512454545.35265454545645;
src.bits[0] = 0b10000010111000100101101011101101;
src.bits[1] = 0b11111001111010000010010110101101;
src.bits[2] = 0b10110000001111101111000010010100;
src.bits[3] = 0b00000000000011100000000000000000;
int check = s21_floor(src, &result);
int check_origin = 0;
// origin = 545454512454545;
origin.bits[0] = 0b10000110011101001011101110010001;
origin.bits[1] = 0b00000000000000011111000000010110;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

// ROUND
#test nutmegha_16
s21_decimal src, origin, result;
// src = 5.0;
src.bits[0] = 0b00000000000000000000000000110010;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000000010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 5;
origin.bits[0] = 0b00000000000000000000000000000101;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_17
s21_decimal src, origin, result;
// src = 3.4;
src.bits[0] = 0b00000000000000000000000000100010;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000000010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 3;
origin.bits[0] = 0b00000000000000000000000000000011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_18
s21_decimal src, origin, result;
// src = 0.0;
src.bits[0] = 0b00000000000000000000000000000000;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000000010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_19
s21_decimal src, origin, result;
// src = -2.4363463;
src.bits[0] = 0b00000001011100111100000111000111;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000001110000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = -2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_20
s21_decimal src, origin, result;
// src = -0.0;
src.bits[0] = 0b00000000000000000000000000000000;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000000010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_21
s21_decimal src, origin, result;
// src = -0.45;
src.bits[0] = 0b00000000000000000000000000101101;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000000100000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_22
s21_decimal src, origin, result;
// src = 652.34631;
src.bits[0] = 0b00000011111000110110011011000111;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000001010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 652;
origin.bits[0] = 0b00000000000000000000001010001100;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_23
s21_decimal src, origin, result;
// src = 4.97623323;
src.bits[0] = 0b00011101101010010010000100011011;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000010000000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 5;
origin.bits[0] = 0b00000000000000000000000000000101;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_24
s21_decimal src, origin, result;
// src = 65658654.59;
src.bits[0] = 0b10000111010110110010011111110011;
src.bits[1] = 0b00000000000000000000000000000001;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000000100000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 65658655;
origin.bits[0] = 0b00000011111010011101111100011111;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_25
s21_decimal src, origin, result;
// src = -364748.110;
src.bits[0] = 0b00010101101111011001110101001110;
src.bits[1] = 0b00000000000000000000000000000000;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000000110000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = -364748;
origin.bits[0] = 0b00000000000001011001000011001100;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_26
s21_decimal src, origin, result;
// src = 1.9874565432111;
src.bits[0] = 0b01101000011010011010001100101111;
src.bits[1] = 0b00000000000000000001001000010011;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b00000000000011010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_27
s21_decimal src, origin, result;
// src = -98.78798789312;
src.bits[0] = 0b00010110010010101110101011000000;
src.bits[1] = 0b00000000000000000000100011111100;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000010110000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = -99;
origin.bits[0] = 0b00000000000000000000000001100011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_28
s21_decimal src, origin, result;
// src = 999999999999999999911.3;
src.bits[0] = 0b10110010001111111111110010001001;
src.bits[1] = 0b00011001111000001100100110111010;
src.bits[2] = 0b00000000000000000000001000011110;
src.bits[3] = 0b00000000000000010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 999999999999999999911;
origin.bits[0] = 0b11011110100111111111111110100111;
origin.bits[1] = 0b00110101110010011010110111000101;
origin.bits[2] = 0b00000000000000000000000000110110;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_29
s21_decimal src, origin, result;
// src = -545454512454545.35265454545645;
src.bits[0] = 0b10000010111000100101101011101101;
src.bits[1] = 0b11111001111010000010010110101101;
src.bits[2] = 0b10110000001111101111000010010100;
src.bits[3] = 0b10000000000011100000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = -545454512454545;
origin.bits[0] = 0b10000110011101001011101110010001;
origin.bits[1] = 0b00000000000000011111000000010110;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_30
s21_decimal src, origin, result;
// src = 545454512454545.35265454545645;
src.bits[0] = 0b10000010111000100101101011101101;
src.bits[1] = 0b11111001111010000010010110101101;
src.bits[2] = 0b10110000001111101111000010010100;
src.bits[3] = 0b00000000000011100000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 545454512454545;
origin.bits[0] = 0b10000110011101001011101110010001;
origin.bits[1] = 0b00000000000000011111000000010110;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_31
s21_decimal src, origin, result;
// src = 7961327845421.879754123131254;
src.bits[0] = 0b01001110111001000011100101110110;
src.bits[1] = 0b01001011001101011010000111011001;
src.bits[2] = 0b00011001101110010111010010111111;
src.bits[3] = 0b00000000000011110000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 7961327845422;
origin.bits[0] = 0b10100100000111100100000000101110;
origin.bits[1] = 0b00000000000000000000011100111101;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_32
s21_decimal src, origin, result;
// src = 12345677.987654345678987654346;
src.bits[0] = 0b10010001000010101111010011001010;
src.bits[1] = 0b11000000010001011101010111110010;
src.bits[2] = 0b00100111111001000001101100000000;
src.bits[3] = 0b00000000000101010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 12345678;
origin.bits[0] = 0b00000000101111000110000101001110;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_33
s21_decimal src, origin, result;
// src = -12345677.987654345678987654346;
src.bits[0] = 0b10010001000010101111010011001010;
src.bits[1] = 0b11000000010001011101010111110010;
src.bits[2] = 0b00100111111001000001101100000000;
src.bits[3] = 0b10000000000101010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = -12345678;
origin.bits[0] = 0b00000000101111000110000101001110;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_34
s21_decimal src, origin, result;
// src = 87654323456.9876545678987653;
src.bits[0] = 0b00010001110011011101000110000101;
src.bits[1] = 0b11110101101111000110111111000000;
src.bits[2] = 0b00000010110101010000111100111111;
src.bits[3] = 0b00000000000100000000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 87654323457;
origin.bits[0] = 0b01101000100110101101010100000001;
origin.bits[1] = 0b00000000000000000000000000010100;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_35
s21_decimal src, origin, result;
// src = 336565445454313.859865545;
src.bits[0] = 0b00111110111111000101101111001001;
src.bits[1] = 0b00111111110101011110000010001011;
src.bits[2] = 0b00000000000000000100011101000101;
src.bits[3] = 0b00000000000010010000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 336565445454314;
origin.bits[0] = 0b10111111110100011110100111101010;
origin.bits[1] = 0b00000000000000010011001000011010;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_36
s21_decimal src, origin, result;
// src = -15456451234534;
src.bits[0] = 0b10111100010010010000101011100110;
src.bits[1] = 0b00000000000000000000111000001110;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000000000000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = -15456451234534;
origin.bits[0] = 0b10111100010010010000101011100110;
origin.bits[1] = 0b00000000000000000000111000001110;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_37
s21_decimal src, origin, result;
// src = -0.42354543545;
src.bits[0] = 0b11011100100001110000101110111001;
src.bits[1] = 0b00000000000000000000000000001001;
src.bits[2] = 0b00000000000000000000000000000000;
src.bits[3] = 0b10000000000010110000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_38
s21_decimal src, origin, result;
// src = 79228162514264337593543950335;
src.bits[0] = 0b11111111111111111111111111111111;
src.bits[1] = 0b11111111111111111111111111111111;
src.bits[2] = 0b11111111111111111111111111111111;
src.bits[3] = 0b00000000000000000000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 79228162514264337593543950335;
origin.bits[0] = 0b11111111111111111111111111111111;
origin.bits[1] = 0b11111111111111111111111111111111;
origin.bits[2] = 0b11111111111111111111111111111111;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_39
s21_decimal src, origin, result;
// src = 2.7986531268974139743;
src.bits[0] = 0b11111110100100001101100101011111;
src.bits[1] = 0b10000100011001000010000111101000;
src.bits[2] = 0b00000000000000000000000000000001;
src.bits[3] = 0b00000000000100110000000000000000;
int check = s21_round(src, &result);
int check_origin = 0;
// origin = 3;
origin.bits[0] = 0b00000000000000000000000000000011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

// NEGATE
#test nutmegha_40
s21_decimal src1, origin, result;
// src1 = 2.1234;
src1.bits[0] = 0b00000000000000000101001011110010;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000001000000000000000000;
// origin = -2.1234;
origin.bits[0] = 0b00000000000000000101001011110010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000001000000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_41
s21_decimal src1, origin, result;
// src1 = 457.000001;
src1.bits[0] = 0b00011011001111010100010001000001;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000001100000000000000000;
// origin = -457.000001;
origin.bits[0] = 0b00011011001111010100010001000001;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000001100000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_42
s21_decimal src1, origin, result;
// src1 = 2.000;
src1.bits[0] = 0b00000000000000000000011111010000;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000110000000000000000;
// origin = -2.000;
origin.bits[0] = 0b00000000000000000000011111010000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000110000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_43
s21_decimal src1, origin, result;
// src1 = 0.000000000000000000000000000;
src1.bits[0] = 0b00000000000000000000000000000000;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000110110000000000000000;
// origin = 0.000000000000000000000000000;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000110110000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_44
s21_decimal src1, origin, result;
// src1 = -3;
src1.bits[0] = 0b00000000000000000000000000000011;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000000000000000000000000;
// origin = 3;
origin.bits[0] = 0b00000000000000000000000000000011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_45
s21_decimal src1, origin, result;
// src1 = 2.222212;
src1.bits[0] = 0b00000000001000011110100010000100;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000001100000000000000000;
// origin = -2.222212;
origin.bits[0] = 0b00000000001000011110100010000100;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000001100000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_46
s21_decimal src1, origin, result;
// src1 = 2.22221200000001000;
src1.bits[0] = 0b00000111100011111010001111101000;
src1.bits[1] = 0b00000011000101010111110100000001;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000100010000000000000000;
// origin = -2.22221200000001000;
origin.bits[0] = 0b00000111100011111010001111101000;
origin.bits[1] = 0b00000011000101010111110100000001;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000100010000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_47
s21_decimal src1, origin, result;
// src1 = 3.745754741;
src1.bits[0] = 0b11011111010000111010111001110101;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000010010000000000000000;
// origin = -3.745754741;
origin.bits[0] = 0b11011111010000111010111001110101;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000010010000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_48
s21_decimal src1, origin, result;
// src1 = 2.222212;
src1.bits[0] = 0b00000000001000011110100010000100;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000001100000000000000000;
// origin = -2.222212;
origin.bits[0] = 0b00000000001000011110100010000100;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000001100000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_49
s21_decimal src1, origin, result;
// src1 = -364748;
src1.bits[0] = 0b00000000000001011001000011001100;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000000000000000000000000;
// origin = 364748;
origin.bits[0] = 0b00000000000001011001000011001100;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_50
s21_decimal src1, origin, result;
// src1 = 987456543210.0;
src1.bits[0] = 0b00011001111101110000001100100100;
src1.bits[1] = 0b00000000000000000000100011111011;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000010000000000000000;
// origin = -987456543210.0;
origin.bits[0] = 0b00011001111101110000001100100100;
origin.bits[1] = 0b00000000000000000000100011111011;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000010000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_51
s21_decimal src1, origin, result;
// src1 = -9878798789.5867800;
src1.bits[0] = 0b11001110100110111101100110011000;
src1.bits[1] = 0b00000001010111101111011100100110;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000001110000000000000000;
// origin = 9878798789.5867800;
origin.bits[0] = 0b11001110100110111101100110011000;
origin.bits[1] = 0b00000001010111101111011100100110;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000001110000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_52
s21_decimal src1, origin, result;
// src1 = 9999999999999999999;
src1.bits[0] = 0b10001001111001111111111111111111;
src1.bits[1] = 0b10001010110001110010001100000100;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000000000000000000000;
// origin = -9999999999999999999;
origin.bits[0] = 0b10001001111001111111111111111111;
origin.bits[1] = 0b10001010110001110010001100000100;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_53
s21_decimal src1, origin, result;
// src1 = 18446744073709551615;
src1.bits[0] = 0b11111111111111111111111111111111;
src1.bits[1] = 0b11111111111111111111111111111111;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000000000000000000000;
// origin = -18446744073709551615;
origin.bits[0] = 0b11111111111111111111111111111111;
origin.bits[1] = 0b11111111111111111111111111111111;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_54
s21_decimal src1, origin, result;
// src1 = 18446744073709551615.0;
src1.bits[0] = 0b11111111111111111111111111110110;
src1.bits[1] = 0b11111111111111111111111111111111;
src1.bits[2] = 0b00000000000000000000000000001001;
src1.bits[3] = 0b00000000000000010000000000000000;
// origin = -18446744073709551615.0;
origin.bits[0] = 0b11111111111111111111111111110110;
origin.bits[1] = 0b11111111111111111111111111111111;
origin.bits[2] = 0b00000000000000000000000000001001;
origin.bits[3] = 0b10000000000000010000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_55
s21_decimal src1, origin, result;
// src1 = -796214545.3526545454564545456;
src1.bits[0] = 0b10111111111111101001001110110000;
src1.bits[1] = 0b11101010111111101111100111101000;
src1.bits[2] = 0b00011001101110100010000111100001;
src1.bits[3] = 0b10000000000100110000000000000000;
// origin = 796214545.3526545454564545456;
origin.bits[0] = 0b10111111111111101001001110110000;
origin.bits[1] = 0b11101010111111101111100111101000;
origin.bits[2] = 0b00011001101110100010000111100001;
origin.bits[3] = 0b00000000000100110000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_56
s21_decimal src1, origin, result;
// src1 = -545454512454545.35265454545645;
src1.bits[0] = 0b10000010111000100101101011101101;
src1.bits[1] = 0b11111001111010000010010110101101;
src1.bits[2] = 0b10110000001111101111000010010100;
src1.bits[3] = 0b10000000000011100000000000000000;
// origin = 545454512454545.35265454545645;
origin.bits[0] = 0b10000010111000100101101011101101;
origin.bits[1] = 0b11111001111010000010010110101101;
origin.bits[2] = 0b10110000001111101111000010010100;
origin.bits[3] = 0b00000000000011100000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_57
s21_decimal src1, origin, result;
// src1 = -7961327845421.843434341378545;
src1.bits[0] = 0b11110011001100111010100111110001;
src1.bits[1] = 0b01001011001101011000000011010000;
src1.bits[2] = 0b00011001101110010111010010111111;
src1.bits[3] = 0b10000000000011110000000000000000;
// origin = 7961327845421.843434341378545;
origin.bits[0] = 0b11110011001100111010100111110001;
origin.bits[1] = 0b01001011001101011000000011010000;
origin.bits[2] = 0b00011001101110010111010010111111;
origin.bits[3] = 0b00000000000011110000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_58
s21_decimal src1, origin, result;
// src1 = 12345677.987654345678987654346;
src1.bits[0] = 0b10010001000010101111010011001010;
src1.bits[1] = 0b11000000010001011101010111110010;
src1.bits[2] = 0b00100111111001000001101100000000;
src1.bits[3] = 0b00000000000101010000000000000000;
// origin = -12345677.987654345678987654346;
origin.bits[0] = 0b10010001000010101111010011001010;
origin.bits[1] = 0b11000000010001011101010111110010;
origin.bits[2] = 0b00100111111001000001101100000000;
origin.bits[3] = 0b10000000000101010000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_59
s21_decimal src1, origin, result;
// src1 = 12345677.987654345678987654346;
src1.bits[0] = 0b10010001000010101111010011001010;
src1.bits[1] = 0b11000000010001011101010111110010;
src1.bits[2] = 0b00100111111001000001101100000000;
src1.bits[3] = 0b00000000000101010000000000000000;
// origin = -12345677.987654345678987654346;
origin.bits[0] = 0b10010001000010101111010011001010;
origin.bits[1] = 0b11000000010001011101010111110010;
origin.bits[2] = 0b00100111111001000001101100000000;
origin.bits[3] = 0b10000000000101010000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_60
s21_decimal src1, origin, result;
// src1 = 87654323456.98765456789876530;
src1.bits[0] = 0b10110010000010100010111100110010;
src1.bits[1] = 0b10011001010111000101110110000000;
src1.bits[2] = 0b00011100010100101001100001111111;
src1.bits[3] = 0b00000000000100010000000000000000;
// origin = -87654323456.98765456789876530;
origin.bits[0] = 0b10110010000010100010111100110010;
origin.bits[1] = 0b10011001010111000101110110000000;
origin.bits[2] = 0b00011100010100101001100001111111;
origin.bits[3] = 0b10000000000100010000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_61
s21_decimal src1, origin, result;
// src1 = -854764561465456456.9876545679;
src1.bits[0] = 0b11000100000001000100000010001111;
src1.bits[1] = 0b01000000100100100110001100010101;
src1.bits[2] = 0b00011011100111100111001001011101;
src1.bits[3] = 0b10000000000010100000000000000000;
// origin = 854764561465456456.9876545679;
origin.bits[0] = 0b11000100000001000100000010001111;
origin.bits[1] = 0b01000000100100100110001100010101;
origin.bits[2] = 0b00011011100111100111001001011101;
origin.bits[3] = 0b00000000000010100000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_62
s21_decimal src1, origin, result;
// src1 = 79228162514264337593543950335;
src1.bits[0] = 0b11111111111111111111111111111111;
src1.bits[1] = 0b11111111111111111111111111111111;
src1.bits[2] = 0b11111111111111111111111111111111;
src1.bits[3] = 0b00000000000000000000000000000000;
// origin = -79228162514264337593543950335;
origin.bits[0] = 0b11111111111111111111111111111111;
origin.bits[1] = 0b11111111111111111111111111111111;
origin.bits[2] = 0b11111111111111111111111111111111;
origin.bits[3] = 0b10000000000000000000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_63
s21_decimal src1, origin, result;
// src1 = -69.1234567;
src1.bits[0] = 0b00101001001100110110011100000111;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000001110000000000000000;
// origin = 69.1234567;
origin.bits[0] = 0b00101001001100110110011100000111;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000001110000000000000000;
int check_origin = 0;
int check = s21_negate(src1, &result);
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_64
s21_decimal src1, origin, result;
// src1 = 2.1234;
src1.bits[0] = 0b00000000000000000101001011110010;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000001000000000000000000;
// origin = 2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_65
s21_decimal src1, origin, result;
// src1 = 457.000001;
src1.bits[0] = 0b00011011001111010100010001000001;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000001100000000000000000;
// origin = 457;
origin.bits[0] = 0b00000000000000000000000111001001;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_66
s21_decimal src1, origin, result;
// src1 = 2.000;
src1.bits[0] = 0b00000000000000000000011111010000;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000110000000000000000;
// origin = 2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_67
s21_decimal src1, origin, result;
// src1 = 0.000000000000000000000000000;
src1.bits[0] = 0b00000000000000000000000000000000;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000110110000000000000000;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_68
s21_decimal src1, origin, result;
// src1 = -3;
src1.bits[0] = 0b00000000000000000000000000000011;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000000000000000000000000;
// origin = -3;
origin.bits[0] = 0b00000000000000000000000000000011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_69
s21_decimal src1, origin, result;
// src1 = 2.222212;
src1.bits[0] = 0b00000000001000011110100010000100;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000001100000000000000000;
// origin = 2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_70
s21_decimal src1, origin, result;
// src1 = 2.22221200000001000;
src1.bits[0] = 0b00000111100011111010001111101000;
src1.bits[1] = 0b00000011000101010111110100000001;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000100010000000000000000;
// origin = 2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_71
s21_decimal src1, origin, result;
// src1 = 3.745754741;
src1.bits[0] = 0b11011111010000111010111001110101;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000010010000000000000000;
// origin = 3;
origin.bits[0] = 0b00000000000000000000000000000011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_72
s21_decimal src1, origin, result;
// src1 = 2.222212;
src1.bits[0] = 0b00000000001000011110100010000100;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000001100000000000000000;
// origin = 2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_73
s21_decimal src1, origin, result;
// src1 = -364748;
src1.bits[0] = 0b00000000000001011001000011001100;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000000000000000000000000;
// origin = -364748;
origin.bits[0] = 0b00000000000001011001000011001100;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_74
s21_decimal src1, origin, result;
// src1 = 987456543210.0;
src1.bits[0] = 0b00011001111101110000001100100100;
src1.bits[1] = 0b00000000000000000000100011111011;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000010000000000000000;
// origin = 987456543210;
origin.bits[0] = 0b11101000111111110001100111101010;
origin.bits[1] = 0b00000000000000000000000011100101;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_75
s21_decimal src1, origin, result;
// src1 = -9878798789.5867800;
src1.bits[0] = 0b11001110100110111101100110011000;
src1.bits[1] = 0b00000001010111101111011100100110;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000001110000000000000000;
// origin = -9878798789;
origin.bits[0] = 0b01001100110100101000000111000101;
origin.bits[1] = 0b00000000000000000000000000000010;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_76
s21_decimal src1, origin, result;
// src1 = 9999999999999999999;
src1.bits[0] = 0b10001001111001111111111111111111;
src1.bits[1] = 0b10001010110001110010001100000100;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000000000000000000000;
// origin = 9999999999999999999;
origin.bits[0] = 0b10001001111001111111111111111111;
origin.bits[1] = 0b10001010110001110010001100000100;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_77
s21_decimal src1, origin, result;
// src1 = 18446744073709551615;
src1.bits[0] = 0b11111111111111111111111111111111;
src1.bits[1] = 0b11111111111111111111111111111111;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000000000000000000000;
// origin = 18446744073709551615;
origin.bits[0] = 0b11111111111111111111111111111111;
origin.bits[1] = 0b11111111111111111111111111111111;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_78
s21_decimal src1, origin, result;
// src1 = 18446744073709551615.0;
src1.bits[0] = 0b11111111111111111111111111110110;
src1.bits[1] = 0b11111111111111111111111111111111;
src1.bits[2] = 0b00000000000000000000000000001001;
src1.bits[3] = 0b00000000000000010000000000000000;
// origin = 18446744073709551615;
origin.bits[0] = 0b11111111111111111111111111111111;
origin.bits[1] = 0b11111111111111111111111111111111;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_79
s21_decimal src1, origin, result;
// src1 = -796214545.3526545454564545456;
src1.bits[0] = 0b10111111111111101001001110110000;
src1.bits[1] = 0b11101010111111101111100111101000;
src1.bits[2] = 0b00011001101110100010000111100001;
src1.bits[3] = 0b10000000000100110000000000000000;
// origin = -796214545;
origin.bits[0] = 0b00101111011101010100010100010001;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_80
s21_decimal src1, origin, result;
// src1 = -545454512454545.35265454545645;
src1.bits[0] = 0b10000010111000100101101011101101;
src1.bits[1] = 0b11111001111010000010010110101101;
src1.bits[2] = 0b10110000001111101111000010010100;
src1.bits[3] = 0b10000000000011100000000000000000;
// origin = -545454512454545;
origin.bits[0] = 0b10000110011101001011101110010001;
origin.bits[1] = 0b00000000000000011111000000010110;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_81
s21_decimal src1, origin, result;
// src1 = -7961327845421.843434341378545;
src1.bits[0] = 0b11110011001100111010100111110001;
src1.bits[1] = 0b01001011001101011000000011010000;
src1.bits[2] = 0b00011001101110010111010010111111;
src1.bits[3] = 0b10000000000011110000000000000000;
// origin = -7961327845421;
origin.bits[0] = 0b10100100000111100100000000101101;
origin.bits[1] = 0b00000000000000000000011100111101;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_82
s21_decimal src1, origin, result;
// src1 = 12345677.987654345678987654346;
src1.bits[0] = 0b10010001000010101111010011001010;
src1.bits[1] = 0b11000000010001011101010111110010;
src1.bits[2] = 0b00100111111001000001101100000000;
src1.bits[3] = 0b00000000000101010000000000000000;
// origin = 12345677;
origin.bits[0] = 0b00000000101111000110000101001101;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_83
s21_decimal src1, origin, result;
// src1 = 12345677.987654345678987654346;
src1.bits[0] = 0b10010001000010101111010011001010;
src1.bits[1] = 0b11000000010001011101010111110010;
src1.bits[2] = 0b00100111111001000001101100000000;
src1.bits[3] = 0b00000000000101010000000000000000;
// origin = 12345677;
origin.bits[0] = 0b00000000101111000110000101001101;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_84
s21_decimal src1, origin, result;
// src1 = 87654323456.98765456789876530;
src1.bits[0] = 0b10110010000010100010111100110010;
src1.bits[1] = 0b10011001010111000101110110000000;
src1.bits[2] = 0b00011100010100101001100001111111;
src1.bits[3] = 0b00000000000100010000000000000000;
// origin = 87654323456;
origin.bits[0] = 0b01101000100110101101010100000000;
origin.bits[1] = 0b00000000000000000000000000010100;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_85
s21_decimal src1, origin, result;
// src1 = -854764561465456456.9876545679;
src1.bits[0] = 0b11000100000001000100000010001111;
src1.bits[1] = 0b01000000100100100110001100010101;
src1.bits[2] = 0b00011011100111100111001001011101;
src1.bits[3] = 0b10000000000010100000000000000000;
// origin = -854764561465456456;
origin.bits[0] = 0b00000100101111011011011101001000;
origin.bits[1] = 0b00001011110111001011101111010111;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_86
s21_decimal src1, origin, result;
// src1 = 0.0;
src1.bits[0] = 0b00000000000000000000000000000000;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000010000000000000000;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_87
s21_decimal src1, origin, result;
// src1 = -69.1234567;
src1.bits[0] = 0b00101001001100110110011100000111;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000001110000000000000000;
// origin = -69;
origin.bits[0] = 0b00000000000000000000000001000101;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_88
s21_decimal src1, origin, result;
// src1 = 13436577854.000000000000;
src1.bits[0] = 0b00100110011110011110000000000000;
src1.bits[1] = 0b01100101111110011111000000101100;
src1.bits[2] = 0b00000000000000000000001011011000;
src1.bits[3] = 0b00000000000011000000000000000000;
// origin = 13436577854;
origin.bits[0] = 0b00100000111000011110100000111110;
origin.bits[1] = 0b00000000000000000000000000000011;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_89
s21_decimal src1, origin, result;
// src1 = 79228162514264337593543950335;
src1.bits[0] = 0b11111111111111111111111111111111;
src1.bits[1] = 0b11111111111111111111111111111111;
src1.bits[2] = 0b11111111111111111111111111111111;
src1.bits[3] = 0b00000000000000000000000000000000;
// origin = 79228162514264337593543950335;
origin.bits[0] = 0b11111111111111111111111111111111;
origin.bits[1] = 0b11111111111111111111111111111111;
origin.bits[2] = 0b11111111111111111111111111111111;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_90
s21_decimal src1, origin, result;
// src1 = 79228162514264337593543950335;
src1.bits[0] = 0b11111111111111111111111111111111;
src1.bits[1] = 0b11111111111111111111111111111111;
src1.bits[2] = 0b11111111111111111111111111111111;
src1.bits[3] = 0b00000000000000000000000000000000;
// origin = 79228162514264337593543950335;
origin.bits[0] = 0b11111111111111111111111111111111;
origin.bits[1] = 0b11111111111111111111111111111111;
origin.bits[2] = 0b11111111111111111111111111111111;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_91
s21_decimal src1, origin, result;
// src1 = 665464545;
src1.bits[0] = 0b00100111101010100010111011100001;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000000000000000000000;
// origin = 665464545;
origin.bits[0] = 0b00100111101010100010111011100001;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_92
s21_decimal src1, origin, result;
// src1 = 2.7986531268974139743;
src1.bits[0] = 0b11111110100100001101100101011111;
src1.bits[1] = 0b10000100011001000010000111101000;
src1.bits[2] = 0b00000000000000000000000000000001;
src1.bits[3] = 0b00000000000100110000000000000000;
// origin = 2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_93
s21_decimal src1, origin, result;
// src1 = -2156878451.8547640000000000;
src1.bits[0] = 0b10010011100100010011000000000000;
src1.bits[1] = 0b00100110110100100010010100001001;
src1.bits[2] = 0b00000000000100011101011101011110;
src1.bits[3] = 0b10000000000100000000000000000000;
// origin = -2156878451;
origin.bits[0] = 0b10000000100011110101101001110011;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_94
s21_decimal src1, origin, result;
// src1 = 0.5456465465486476846545465485;
src1.bits[0] = 0b00001011000011110111000010001101;
src1.bits[1] = 0b10010110101100000101100101010001;
src1.bits[2] = 0b00010001101000010111101110000001;
src1.bits[3] = 0b00000000000111000000000000000000;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_95
s21_decimal src1, origin, result;
// src1 = -776890.75455454213415678965898;
src1.bits[0] = 0b11000010010111101111100010001010;
src1.bits[1] = 0b01011100000101000111000011011000;
src1.bits[2] = 0b11111011000001101110010110100011;
src1.bits[3] = 0b10000000000101110000000000000000;
// origin = -776890;
origin.bits[0] = 0b00000000000010111101101010111010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_96
s21_decimal src1, origin, result;
// src1 = -732123534337593543950335.12;
src1.bits[0] = 0b11000011000110111111111110101000;
src1.bits[1] = 0b10100001110111010100101100101110;
src1.bits[2] = 0b00000000001111001000111101010001;
src1.bits[3] = 0b10000000000000100000000000000000;
// origin = -732123534337593543950335;
origin.bits[0] = 0b11010011110111101111111111111111;
origin.bits[1] = 0b01111111000011110000001101001111;
origin.bits[2] = 0b00000000000000001001101100001000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_97
s21_decimal src1, origin, result;
// src1 = 675432788976.5424354657687;
src1.bits[0] = 0b10111110000100011000010110010111;
src1.bits[1] = 0b11011001001111010001001011000110;
src1.bits[2] = 0b00000000000001011001011001001000;
src1.bits[3] = 0b00000000000011010000000000000000;
// origin = 675432788976;
origin.bits[0] = 0b01000010111011100111001111110000;
origin.bits[1] = 0b00000000000000000000000010011101;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_98
s21_decimal src1, origin, result;
// src1 = -579895323215489956.67897455465;
src1.bits[0] = 0b11100110001001011001001101101001;
src1.bits[1] = 0b00111000110110101110001010110100;
src1.bits[2] = 0b10111011010111111101000100011110;
src1.bits[3] = 0b10000000000010110000000000000000;
// origin = -579895323215489956;
origin.bits[0] = 0b01011011001010110110101110100100;
origin.bits[1] = 0b00001000000011000011001110111001;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_99
s21_decimal src1, origin, result;
// src1 = 123523543453453453.0;
src1.bits[0] = 0b01001001011001111111110110000010;
src1.bits[1] = 0b00010001001001000111000000010101;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000010000000000000000;
// origin = 123523543453453453;
origin.bits[0] = 0b00100000111100001100110010001101;
origin.bits[1] = 0b00000001101101101101100000000010;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_100
s21_decimal src1, origin, result;
// src1 = 31231232456315.0;
src1.bits[0] = 0b11100001001010100010000011001110;
src1.bits[1] = 0b00000000000000010001110000001011;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000010000000000000000;
// origin = 31231232456315;
origin.bits[0] = 0b10010110100001000011011001111011;
origin.bits[1] = 0b00000000000000000001110001100111;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_101
s21_decimal src1, origin, result;
// src1 = 78987543557678337.5935439503;
src1.bits[0] = 0b00111011110001111000001010001111;
src1.bits[1] = 0b00101001100010100010010001100011;
src1.bits[2] = 0b00000010100011010101111010100001;
src1.bits[3] = 0b00000000000010100000000000000000;
// origin = 78987543557678337;
origin.bits[0] = 0b10011011011011111010010100000001;
origin.bits[1] = 0b00000001000110001001111011000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_102
s21_decimal src1, origin, result;
// src1 = -754567488438.97816770;
src1.bits[0] = 0b01011010011001011000011011000010;
src1.bits[1] = 0b00010111001011000011100101001001;
src1.bits[2] = 0b00000000000000000000000000000100;
src1.bits[3] = 0b10000000000010000000000000000000;
// origin = -754567488438;
origin.bits[0] = 0b10101111101110100010001110110110;
origin.bits[1] = 0b00000000000000000000000010101111;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_103
s21_decimal src1, origin, result;
// src1 = -2.514475768684753643;
src1.bits[0] = 0b10101100110010000011001011101011;
src1.bits[1] = 0b00100010111001010011011001100011;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000100100000000000000000;
// origin = -2;
origin.bits[0] = 0b00000000000000000000000000000010;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_104
s21_decimal src1, origin, result;
// src1 = -0.0;
src1.bits[0] = 0b00000000000000000000000000000000;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b10000000000000010000000000000000;
// origin = -0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b10000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_105
s21_decimal src1, origin, result;
// src1 = 0.0;
src1.bits[0] = 0b00000000000000000000000000000000;
src1.bits[1] = 0b00000000000000000000000000000000;
src1.bits[2] = 0b00000000000000000000000000000000;
src1.bits[3] = 0b00000000000000010000000000000000;
// origin = 0;
origin.bits[0] = 0b00000000000000000000000000000000;
origin.bits[1] = 0b00000000000000000000000000000000;
origin.bits[2] = 0b00000000000000000000000000000000;
origin.bits[3] = 0b00000000000000000000000000000000;
int check = s21_truncate(src1, &result);
int check_origin = 0;
ck_assert_int_eq(origin.bits[3], result.bits[3]);
ck_assert_int_eq(origin.bits[2], result.bits[2]);
ck_assert_int_eq(origin.bits[1], result.bits[1]);
ck_assert_int_eq(origin.bits[0], result.bits[0]);
ck_assert_int_eq(check, check_origin);

#test nutmegha_106
s21_decimal a = {{1, 2, 3, 0}};
ck_assert_int_eq(s21_truncate(a, NULL), 1);

#test nutmegha_107
s21_decimal a = {{1, 2, 3, 0}};
ck_assert_int_eq(s21_floor(a, NULL), 1);

#test nutmegha_108
s21_decimal a = {{1, 2, 3, 0}};
ck_assert_int_eq(s21_negate(a, NULL), 1);

#test nutmegha_109
s21_decimal a = {{1, 2, 3, 0}};
ck_assert_int_eq(s21_round(a, NULL), 1);
