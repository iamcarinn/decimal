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
