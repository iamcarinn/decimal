#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err = 0;
  int exponent = ((*((unsigned int *)&src) & 0x7F800000) >> 23) - 126;
  if (!dst)
    err++;
  else {
    if (exponent < -94) {
      clean_decimal_nutmegha(dst);
      if (*((unsigned int *)&src) != 0) {
        err = 1;
      }
      clean_decimal_nutmegha(dst);
    } else if (exponent > 96) {
      err = 1;
    } else {
      clean_decimal_nutmegha(dst);
      char str[15] = "";
      int num = 0;
      int grade = 0;
      sprintf(str, "%e", src);
      float_parser(str, &num, &grade, &err);
      num_to_decimal(num, dst, &grade);
      grade_to_decimal(grade, dst);
    }
  }
  return err;
}

void num_to_decimal(int num, s21_decimal *dst, int *grade) {
  if (num & 0x80000000) {
    dst->bits[3] |= 0x80000000;
    num = -num;
  }
  dst->bits[0] = num;
  if (*grade > 0) {
    s21_decimal buff = *dst;
    for (int i = 0; i < *grade; i++) {
      s21_mul(DECIMAL_TEN, buff, dst);
      buff = *dst;
    }
    *grade = 0;
  }
}

void grade_to_decimal(int grade, s21_decimal *dst) {
  grade = -grade;
  dst->bits[3] |= (grade << 16);
}

void float_parser(char str[], int *a, int *b, int *err) {
  char num[10] = "";
  char grade[4] = "";
  int i = 0;
  for (int j = 0; str[i] != 'e'; i++) {
    if (str[i] != '.') {
      num[j] = str[i];
      j++;
    }
  }
  memcpy(grade, str + i + 1, 3);
  str_to_num(num, a);
  str_to_num(grade, b);
  if (*b < -28 || *b > 28) (*err)++;
  *b -= 6;
}

void str_to_num(char s[], int *num) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] != '+' && s[i] != '-') *num = (*num * 10) + (s[i] - '0');
  }
  if (s[0] == '-') *num = -(*num);
}
