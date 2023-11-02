#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = false;

  int sign_value_1 = get_sign_nutmegha(value_1);
  int sign_value_2 = get_sign_nutmegha(value_2);
  int scale_value_1 = get_scale_nutmegha(&value_1);
  int scale_value_2 = get_scale_nutmegha(&value_2);

  if (s21_is_decimal_zero(value_1, value_2) == 3)
    result = false;
  else if (value_1.bits[0] == 0 && value_2.bits[0] == 0) {
    result = false;
  } else if (sign_value_1 && !sign_value_2)
    result = false;
  else if (!sign_value_1 && sign_value_2)
    result = true;
  else if (sign_value_1 && sign_value_2) {
    s21_bit_clearing(&value_1, 127);
    s21_bit_clearing(&value_2, 127);

    if (scale_value_1 != scale_value_2)
      s21_decimal_normalization(&value_1, &value_2);

    result = s21_bits_comparison(value_1, value_2);
    if (result == -1) result = false;
  } else {
    if (scale_value_1 != scale_value_2)
      s21_decimal_normalization(&value_1, &value_2);
    result = s21_bits_comparison(value_1, value_2);
    if (result != 0)
      result = false;
    else
      result = true;
  }

  return result;
}
