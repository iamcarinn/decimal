#ifndef _S21_DECIMAL_H_VEOLASHE_
#define _S21_DECIMAL_H_VEOLASHE_

int s21_from_int_to_decimal(int src, s21_decimal *dst);
void bitprint_decimal(s21_decimal d);
void nulify(s21_decimal *x);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
void bitprint_int(int src);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
void str_to_num(char s[], int *num);
void grade_to_decimal(int grade, s21_decimal *dst);
void num_to_decimal(int num, s21_decimal *dst, int *grade);
void float_parser(char str[], int *a, int *b, int *err);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
typedef union {
  float f;
  int i;
} bit_float;
#define DECIMAL_TEN \
  (s21_decimal) {   \
    { 10, 0, 0, 0 } \
  }

int s21_from_decimal_to_float(s21_decimal src, float *dst);
void grade_increase(s21_decimal *src, int *grade);
void grade_decrease(s21_decimal *src);
void decimal_to_string(s21_decimal *src, s21_decimal *buff, char *res);
int correct_decimal(s21_decimal a);

#endif
