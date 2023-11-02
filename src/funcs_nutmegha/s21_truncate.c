#include "../s21_decimal.h"

// Возвращает целые цифры
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int err = 0;
  int scale = get_scale_nutmegha(&value);
  if (scale > 28 || !result) {
    err = 1;
  } else {
    for (; scale > 0; scale--) {
      s21_div_ten_nutmegha(&value);
    }

    clean_decimal_nutmegha(result);
    copy_decimal_nutmegha(&value, result);
    if (get_sign_nutmegha(value) == 1) {
      set_sign_nutmegha(result);
    }
  }
  return err;
}
