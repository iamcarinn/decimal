#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  if (!dst || correct_decimal(src))
    res = 1;
  else {
    s21_decimal buff = {{0, 0, 0, 0}};
    s21_truncate(src, &buff);
    if (buff.bits[1] == 0 && buff.bits[2] == 0 &&
        !(buff.bits[0] & 0x80000000)) {
      if (src.bits[3] & 0x80000000)
        *dst = -(buff.bits[0]);
      else
        *dst = buff.bits[0];
    } else {
      res = 1;
    }
  }
  return res;
}
