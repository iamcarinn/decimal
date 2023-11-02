#ifndef S21_LETITIAR_H_
#define S21_LETITIAR_H_

typedef enum { false, true } bool;
typedef enum { LOW, MID, HIGH, SCALE, AMOUNT } bits;

#define S21_MAX_UINT 4294967295  // 0b11111111111111111111111111111111

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

/* SECONDARY FUNCTIONS */

void s21_init_decimal(s21_decimal *src);

/* bit operations */
bool s21_bit_clearing(s21_decimal *src, int index);

/* check s21_decimal status */
int s21_is_mantissa_zeros(s21_decimal src);
int s21_is_decimal_zero(s21_decimal src_1, s21_decimal src_2);
int s21_is_decimal_inf(s21_decimal src_1);

/* other functions */
void s21_decimal_normalization(s21_decimal *src_1, s21_decimal *src_2);
s21_decimal s21_mantisses_addition(s21_decimal *src_1, s21_decimal *src_2);

s21_decimal s21_mantisses_division(s21_decimal src_1, s21_decimal src_2,
                                   s21_decimal *rest_decimal);

int s21_bits_comparison(s21_decimal value1, s21_decimal value2);

#endif  // S21_LETITIAR_H_