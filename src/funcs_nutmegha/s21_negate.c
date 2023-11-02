#include "../s21_decimal.h"

// Возвращает результат умножения указанного s21_decimal на -1
int s21_negate(s21_decimal value, s21_decimal *result) {
  int err = 0;
  int sign = get_sign_nutmegha(value);
  int scale = get_scale_nutmegha(&value);
  if (scale > 28 || !result) {
    err = 1;
  } else {
    clean_decimal_nutmegha(result);
    copy_decimal_nutmegha(&value, result);
    if (sign == 0) {
      set_sign_nutmegha(result);
    }
    set_scale_nutmegha(result, scale);
  }
  return err;
}
