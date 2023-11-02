#include "../s21_decimal.h"

int correct_decimal(s21_decimal a) {
  int err = 0;
  if (a.bits[3] & 0x7F00FFFF) err = 1;
  if (((a.bits[3] & 0x7fffffff) >> 16) > 28) err = 1;
  return err;
}
