#ifndef S21_NUTMEGHA_
#define S21_NUTMEGHA_

// другие функции
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// дополнительные
int get_scale_nutmegha(s21_decimal *dec);
void set_scale_nutmegha(s21_decimal *dec, int scale);
int get_sign_nutmegha(s21_decimal dec);
void set_sign_nutmegha(s21_decimal *dec);
int get_bit_nutmegha(s21_decimal dec, int index);
void set_bit_nutmegha(s21_decimal *dec, int index);
void copy_decimal_nutmegha(s21_decimal *old, s21_decimal *neww);
void clean_decimal_nutmegha(s21_decimal *dec);
void s21_value_offset_nutmegha(s21_decimal *dec);
int s21_div_ten_nutmegha(s21_decimal *value);
void print_dec_nutmegha(s21_decimal value);
void sum_one_nutmegha(s21_decimal *value);
#endif