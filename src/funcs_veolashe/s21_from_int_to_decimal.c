#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (!dst)
    res++;
  else {
    clean_decimal_nutmegha(dst);
    if (src < 0) {
      src = -src;
      dst->bits[3] |= 0x80000000;
    }
    dst->bits[0] = src;
  }
  return res;
}
