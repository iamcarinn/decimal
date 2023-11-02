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
