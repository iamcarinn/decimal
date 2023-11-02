#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  res = correct_decimal(src);
  if (!dst || res != 0) {
    res = 1;
  } else {
    if (s21_is_equal(src, (s21_decimal){{0, 0, 0, 0}}) ||
        s21_is_equal(src, (s21_decimal){{0, 0, 0, 0x80000000}})) {
      // Отдельно обрабатываем 0 и -0
      if (get_sign_nutmegha(src)) {
        *dst = -0.0;
      } else {
        *dst = 0.0;
      }
    } else {
      *dst = 0.0;
      double tmp = 0.0;
      // Запоминаем знак и степень decimal
      int sign = get_sign_nutmegha(src);
      int power = get_scale_nutmegha(&src);
      // Каждый бит s21_decimal переводим в double, для этого каждый бит
      // представляем как 2 в степени позиции бита и прибавляет к результату
      for (int i = 0; i < 96; i++) {
        if (get_bit_nutmegha(src, i) != 0) {
          tmp += pow(2.0, i);
        }
      }
      // учитываем степень и корректируем итоговый результат
      double powerten = pow(10, power);
      tmp /= powerten;
      if (sign == 1) {
        tmp *= -1.0;
      }
      *dst = (float)tmp;
    }
  }
  return res;
}
