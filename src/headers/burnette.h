#ifndef _S21_DECIMAL_H_BURNETTE_
#define _S21_DECIMAL_H_BURNETTE_

#define MASK_SCALE 0xff0000U
#define MAX_INT_SCALE 9
#define _MAX_UINT_ 4294967295U

// Структура big_decimal позволяет хранить такие числа,
// используя несколько беззнаковых целых чисел.
// Каждое число в массиве представляет собой часть десятичного числа,
// которое можно складывать, вычитать, умножать и делить,
// используя соответствующие алгоритмы.
typedef struct {
  unsigned int part[6];
} big_decimal;

#define DECIMAL_IS_ZERO(a) (a.bits[0] == 0 && a.bits[1] == 0 && a.bits[2] == 0)
#define OK 0
#define INF_PLUS 1
#define INF_MINUS 2
#define DIV_BY_ZERO 3

// Сложение 2 Decimal
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int summ_helper(big_decimal x, big_decimal y, big_decimal *z);

// Вычитание 2 Decimal
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Умножение 2 Decimal
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Деление 2 Decimal
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Слава компилятору, без s21_mod!!

// Второстепенные функции

void decimal_to_big_decimal(s21_decimal a, big_decimal *result);
void big_decimal_to_decimal(big_decimal result, unsigned int sign,
                            unsigned int scale, s21_decimal *a);

void bank_round(big_decimal *buffer, unsigned int *round_scale);
int add_uint(big_decimal *number, unsigned int a);
int div_big_decimal_on_uint(big_decimal *src, unsigned int divider,
                            unsigned int *last_remainder);

int mul10xbig_decimal(big_decimal *src, int scale);
unsigned long int mul_32x32_to_64(unsigned int a, unsigned int b);
void bank_round(big_decimal *buffer, unsigned int *round_scale);
void _mul_base_part(unsigned long *temp, unsigned long *temp2,
                    s21_decimal value_1, s21_decimal value_2,
                    big_decimal *big_result);
void _mul_high_part(unsigned long temp, unsigned long temp2,
                    s21_decimal value_1, s21_decimal value_2,
                    big_decimal *big_result);
// s21_sub
big_decimal flexin(big_decimal value_1, big_decimal value_2);
void preparing_numbers_for_subtraction(big_decimal *a, big_decimal *b,
                                       big_decimal *result);
int get_result_max_scale(int a, int b);
int get_result_min_scale(int a, int b);
int get_bit(s21_decimal num, int number_of_int_in_array, int number_of_bits);
void set_bit(unsigned int *num, int number_of_bits, int bit);
int get_bit_big(big_decimal num, int number_of_int_in_array,
                int number_of_bits);

// s21_is_greater
void help_in_scaling_values(s21_decimal a, s21_decimal b, big_decimal *big_a,
                            big_decimal *big_b, int *scale_a, int *scale_b);
#endif
