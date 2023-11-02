#include "../s21_decimal.h"

// Банковское округление
int s21_round(s21_decimal value, s21_decimal *result) {
  int err = 0, mark = 0, remnant = 0;
  int sign = get_sign_nutmegha(value);
  int scale = get_scale_nutmegha(&value);
  if (scale > 28 || !result) {
    err = 1;
  } else {
    for (; scale > 0; scale--) {
      remnant = s21_div_ten_nutmegha(&value);
      if (scale > 1 && remnant != 0) mark = 1;
    }
    if (remnant > 5 ||
        (remnant == 5 && (mark == 1 || get_bit_nutmegha(value, 0) == 1))) {
      sum_one_nutmegha(&value);
    }
    clean_decimal_nutmegha(result);
    copy_decimal_nutmegha(&value, result);
    if (sign == 1) {
      set_sign_nutmegha(result);
    }
  }
  return err;
}
