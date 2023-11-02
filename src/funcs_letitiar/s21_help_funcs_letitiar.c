#include "../s21_decimal.h"

/*Initialization decimal*/

void s21_init_decimal(s21_decimal *src) {
  src->bits[LOW] = 0;
  src->bits[MID] = 0;
  src->bits[HIGH] = 0;
  src->bits[SCALE] = 0;
}

// int get_sign_nutmegha(s21_decimal number) { return (number.bits[3] >> 31) &
// 1U; }

/*Getters and setters*/

bool s21_bit_clearing(s21_decimal *src, int index) {
  bool result = false;

  if (index >= 0 && index <= 127) {
    unsigned int mask = 1u << (index % 32);
    src->bits[index / 32] &= ~(mask);
    result = true;
  }

  return result;
}

int s21_is_mantissa_zeros(s21_decimal src) {
  int result = false;

  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0) result = true;

  return result;
}

int s21_is_decimal_zero(s21_decimal src_1, s21_decimal src_2) {
  int result = -1;
  bool src_1_mantissa_zero = s21_is_mantissa_zeros(src_1);
  bool src_2_mantissa_zero = s21_is_mantissa_zeros(src_2);
  int sign_src_1 = get_sign_nutmegha(src_1);
  int sign_src_2 = get_sign_nutmegha(src_2);
  int scale_src_1 = get_scale_nutmegha(&src_1);
  int scale_src_2 = get_scale_nutmegha(&src_2);
  if (src_1_mantissa_zero == true && scale_src_1 == 0 &&
      src_2_mantissa_zero == true && scale_src_2 == 0) {
    result = 1;
  } else if (src_2_mantissa_zero == true && scale_src_2 == 0 &&
             sign_src_2 == 0) {
    result = 2;
  } else if (src_1_mantissa_zero == true && scale_src_1 == 0 &&
             sign_src_1 == 0) {
    result = 3;
  } else
    result = 0;

  return result;
}

int s21_index_of_elder_significant_bit(s21_decimal src) {
  int index_of_last_bit = 95;

  while (index_of_last_bit >= 0 &&
         get_bit_nutmegha(src, index_of_last_bit) == 0) {
    index_of_last_bit--;
  }

  return index_of_last_bit;
}

int s21_left_shift_n(s21_decimal *src, int shift_index) {
  int last_significant_bit = s21_index_of_elder_significant_bit(*src);
  int result = 0;
  if (last_significant_bit + shift_index > 95) {
    result = 1;
  } else
    for (int iter = 0; iter < shift_index; iter++) {
      bool last_low_bit = get_bit_nutmegha(*src, 31);
      bool last_mid_bit = get_bit_nutmegha(*src, 63);
      src->bits[LOW] = src->bits[LOW] << 1;
      src->bits[MID] = src->bits[MID] << 1;
      src->bits[HIGH] = src->bits[HIGH] << 1;
      if (last_low_bit == true) set_bit_nutmegha(src, 32);
      if (last_mid_bit == true) set_bit_nutmegha(src, 64);
    }
  return result;
}

void s21_decimal_normalization(s21_decimal *src_1, s21_decimal *src_2) {
  int smaller_scale = 0;
  int scale_src_1 = get_scale_nutmegha(src_1);
  int scale_src_2 = get_scale_nutmegha(src_2);

  if (scale_src_1 != scale_src_2) {
    s21_decimal *smaller_decimal = {0};
    s21_decimal buffer_decimal = {{0, 0, 0, 0}};
    if (scale_src_1 > scale_src_2) {
      smaller_decimal = src_2;
    } else if (scale_src_1 < scale_src_2) {
      smaller_decimal = src_1;
    }
    while (get_scale_nutmegha(src_1) != get_scale_nutmegha(src_2)) {
      s21_decimal decimal_x_8 = *smaller_decimal;
      s21_decimal decimal_x_2 = *smaller_decimal;
      smaller_scale = get_scale_nutmegha(smaller_decimal);

      s21_left_shift_n(&decimal_x_8, 3);
      s21_left_shift_n(&decimal_x_2, 1);

      buffer_decimal = s21_mantisses_addition(&decimal_x_8, &decimal_x_2);
      smaller_decimal->bits[LOW] = buffer_decimal.bits[LOW];
      smaller_decimal->bits[MID] = buffer_decimal.bits[MID];
      smaller_decimal->bits[HIGH] = buffer_decimal.bits[HIGH];
      set_scale_nutmegha(smaller_decimal, smaller_scale + 1);
    }
  }
}

s21_decimal s21_mantisses_addition(s21_decimal *src_1, s21_decimal *src_2) {
  s21_decimal result;
  int remembered_bit = 0;
  s21_init_decimal(&result);
  for (int iter = 0; iter < 96; iter++) {
    bool bit_src_1 = get_bit_nutmegha(*src_1, iter);
    bool bit_src_2 = get_bit_nutmegha(*src_2, iter);

    if (bit_src_1 == 0 && bit_src_2 == 0) {
      if (remembered_bit == 1) {
        set_bit_nutmegha(&result, iter);
        remembered_bit = 0;
      } else {
        s21_bit_clearing(&result, iter);
      }
    } else if (bit_src_1 != bit_src_2) {
      if (remembered_bit == 1) {
        s21_bit_clearing(&result, iter);
        remembered_bit = 1;
      } else {
        set_bit_nutmegha(&result, iter);
      }
    } else {
      if (remembered_bit == 1) {
        set_bit_nutmegha(&result, iter);
        remembered_bit = 1;
      } else {
        s21_bit_clearing(&result, iter);
        remembered_bit = 1;
      }
    }
  }
  return result;
}

int s21_bits_comparison(s21_decimal value_1, s21_decimal value_2) {
  int result = -1;
  for (int i = 95, break_flag = 1; i >= 0 && break_flag != 0; i--) {
    int bit_value_1 = get_bit_nutmegha(value_1, i);
    int bit_value_2 = get_bit_nutmegha(value_2, i);
    if (!bit_value_1 && bit_value_2) {
      result = true;
      break_flag = 0;
    } else if (bit_value_1 && !bit_value_2) {
      result = false;
      break_flag = 0;
    } else
      continue;
  }
  return result;
}
