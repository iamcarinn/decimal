#include "../s21_decimal.h"

// Округляет ближайшего целого числа в сторону отрицательной бесконечности
int s21_floor(s21_decimal value, s21_decimal *result) {
  int err = 0, mark = 0, remnant = 0;
  int scale = get_scale_nutmegha(&value);
  int sign = get_sign_nutmegha(value);
  if (scale > 28 || !result) {
    err = 1;
  } else {
    for (; scale > 0; scale--) {
      remnant = s21_div_ten_nutmegha(&value);
      if (remnant != 0) mark = 1;
    }
    if (sign == 1 && mark == 1) {
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
