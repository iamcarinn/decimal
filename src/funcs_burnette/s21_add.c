#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  unsigned int comeback;
  int sign = 0;
  big_decimal x = {0};
  big_decimal y = {0};
  big_decimal z = {0};
  int x_scale, y_scale;
  int x_sign = get_bit(value_1, 3, 31);
  int y_sign = get_bit(value_2, 3, 31);
  // приводим значения к одной и той же разрядности
  help_in_scaling_values(value_1, value_2, &x, &y, &x_scale, &y_scale);
  if (x_sign != y_sign) {
    if (x_sign == 1) {
      set_bit(&value_1.bits[3], 31, 0);
      comeback = s21_sub(value_2, value_1, result);
      return comeback;
    } else {
      set_bit(&value_2.bits[3], 31, 0);
      comeback = s21_sub(value_1, value_2, result);
      return comeback;
    }
  } else {
    if (x_sign == 0 && y_sign == 0) {
      comeback = summ_helper(x, y, &z);
    } else if (x_sign == 1 && y_sign == 1) {
      sign = 1;
      set_bit(&value_1.bits[3], 31, 0);
      set_bit(&value_2.bits[3], 31, 0);
      comeback = summ_helper(x, y, &z);
    }
  }
  unsigned int round_scale = 0;
  // функция проверяет, не превышает ли количество
  // разрядов после запятой максимально допустимое значение,
  // и при необходимости производит округление.
  bank_round(&z, &round_scale);
  round_scale = get_result_max_scale(x_scale, y_scale) - round_scale;
  if (round_scale > 28U && sign == 0) {
    result->bits[3] = 0;
    return 1;
  } else if (round_scale > 28U && sign == 1) {
    result->bits[3] = 0;
    return 2;
  }
  big_decimal_to_decimal(z, sign, round_scale, result);
  return comeback;
}
