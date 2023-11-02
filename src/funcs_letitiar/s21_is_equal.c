#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) {
    value_1.bits[3] = 0;
  }
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    value_2.bits[3] = 0;
  }
  if (s21_is_decimal_zero(value_1, value_2) == 1)
    result = true;
  else if (get_sign_nutmegha(value_1) != get_sign_nutmegha(value_2))
    result = false;
  else {
    int scale_value_1 = get_scale_nutmegha(&value_1);
    int scale_value_2 = get_scale_nutmegha(&value_2);

    if (scale_value_1 != scale_value_2) {
      s21_decimal_normalization(&value_1, &value_2);
    }

    if (s21_bits_comparison(value_1, value_2) >= 0)
      result = false;
    else
      result = true;
  }
  return result;
}
