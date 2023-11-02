#include "../s21_decimal.h"

int compression_big_dec_to_dec(big_decimal *buffer, unsigned int *last_rem,
                               unsigned int *rem) {
  unsigned int divider, div_scale;
  *last_rem = 0, *rem = 0;
  div_scale = 0;
  while ((buffer->part[5] | buffer->part[4] | buffer->part[3]) > 0) {
    *rem |= *last_rem;
    if ((buffer->part[3] > 999999999U) ||
        ((buffer->part[5] | buffer->part[4]) != 0U)) {
      divider = 1000000000U;
      div_scale += 9;
    } else if (buffer->part[3] > 9999U) {
      divider = 1000U;
      div_scale += 3;
    } else {
      divider = 10U;
      div_scale += 1;
    }
    div_big_decimal_on_uint(buffer, divider, last_rem);
  }
  return div_scale;
}

// Банковское округление
void bank_round(big_decimal *buffer, unsigned int *round_scale) {
  unsigned int last_rem, rem, div_scale;
  last_rem = 0, rem = 0, div_scale = 0;

  div_scale = compression_big_dec_to_dec(buffer, &last_rem, &rem);
  // banking condition
  if (((rem > 0U || (buffer->part[0] & 1U)) && (last_rem == 5U)) ||
      (last_rem > 5U)) {
    add_uint(buffer, 1U);
    div_scale += compression_big_dec_to_dec(buffer, &last_rem, &rem);
  }
  *round_scale = div_scale;
}

void set_bit(unsigned int *num, int number_of_bits, int bit) {
  if (bit == 0) {
    if (*num & (1 << number_of_bits)) {
      *num &= ~(1 << number_of_bits);
    }
  } else {
    if (!(*num & (1 << number_of_bits))) {
      *num |= (1 << number_of_bits);
    }
  }
}

int get_bit(s21_decimal num, int number_of_int_in_array, int number_of_bits) {
  int check = 0;
  int result = 0;
  check = num.bits[number_of_int_in_array];
  if (check &= (1 << number_of_bits)) {
    result = 1;
  }
  return result;
}

int get_bit_big(big_decimal num, int number_of_int_in_array,
                int number_of_bits) {
  int check = 0;
  int result = 0;
  check = num.part[number_of_int_in_array];
  if (check &= (1 << number_of_bits)) {
    result = 1;
  }
  return result;
}

//. Without scaling and information about the sign, scale
void decimal_to_big_decimal(s21_decimal a, big_decimal *result) {
  for (int i = 0; i < 3; i++) {
    result->part[i] = a.bits[i];
  }
  for (int i = 3; i < 6; i++) {
    result->part[i] = 0;
  }
}

void big_decimal_to_decimal(big_decimal result, unsigned int sign,
                            unsigned int scale, s21_decimal *a) {
  for (int i = 0; i < 3; i++) {
    a->bits[i] = result.part[i];
  }
  a->bits[3] = (scale + (sign << 15)) << 16;
}

int add_uint(big_decimal *number, unsigned int a) {
  unsigned int i;
  unsigned long int res_sum;

  res_sum = (unsigned long int)a + number->part[0];
  number->part[0] = (unsigned int)res_sum;
  i = 1;
  a = res_sum >> 32;
  while (res_sum > __UINT32_MAX__) {
    res_sum = (unsigned long int)a + number->part[i];
    number->part[i] = (unsigned int)res_sum;
    a = res_sum >> 32;
    i++;
  }

  return 0;
}

int div_big_decimal_on_uint(big_decimal *src, unsigned int divider,
                            unsigned int *last_remainder) {
  unsigned int remainder;
  unsigned long int num;

  remainder = src->part[5] - (src->part[5] / divider) * divider;
  src->part[5] /= divider;
  for (int i = 4; i >= 0; i--) {
    num = src->part[i] + ((unsigned long int)remainder << 32);
    src->part[i] = (unsigned int)(num / divider);
    remainder = (unsigned int)num - src->part[i] * divider;
  }
  *last_remainder = remainder;

  return 0;
}

int mul10xbig_decimal(big_decimal *src, int scale) {
  const unsigned int s_powers10[] = {1,         10,        100,     1000,
                                     10000,     100000,    1000000, 10000000,
                                     100000000, 1000000000};
  big_decimal temp_buf = {.part[0] = 0,
                          .part[1] = 0,
                          .part[2] = 0,
                          .part[3] = 0,
                          .part[4] = 0,
                          .part[5] = 0};
  unsigned int temp, power;

  unsigned long int res_mul;
  while (scale > 0) {
    if (scale >= MAX_INT_SCALE) {
      power = s_powers10[MAX_INT_SCALE];
    } else {
      power = s_powers10[scale];
    }
    scale -= MAX_INT_SCALE;

    res_mul = mul_32x32_to_64(src->part[0], power);
    temp_buf.part[0] = (unsigned int)res_mul;
    temp = (unsigned int)(res_mul >> 32);

    for (size_t i = 1; i < 6; i++) {
      res_mul = mul_32x32_to_64(src->part[i], power);
      temp_buf.part[i] = ((unsigned int)res_mul) + temp;
      temp = (unsigned int)((res_mul + temp) >> 32);
    }

    for (size_t i = 0; i < 6; i++) {
      src->part[i] = temp_buf.part[i];
    }
  }
  return 0;
}

unsigned long int mul_32x32_to_64(unsigned int a, unsigned int b) {
  return (unsigned long int)a * (unsigned long int)b;
}

// s21_sub
// возвращает результат вычитания в виде переменной big_decimal
big_decimal flexin(big_decimal value_1, big_decimal value_2) {
  big_decimal result = {0};
  preparing_numbers_for_subtraction(&value_1, &value_2, &result);
  return result;
}
// подготовительные действия для выполнения вычитания
void preparing_numbers_for_subtraction(big_decimal *a, big_decimal *b,
                                       big_decimal *result) {
  int count = 1;  // для отслеживания порядкового номера элемента в массиве
  for (int i = 0; i < 6; i++) {
    count = i + 1;
    if (a->part[i] >= b->part[i]) {
      result->part[i] = a->part[i] - b->part[i];  // разность значений
    } else {
      result->part[i] = (~(b->part[i] - a->part[i])) + 1;
      // чтобы выполнить корректное вычитание циклим
      while (1) {
        if (a->part[count] == 0) {
          a->part[count] = _MAX_UINT_;
          count++;
        } else {
          a->part[count] -= 1;
          break;
        }
      }
    }
  }
}
// кто больше
int get_result_max_scale(int a, int b) { return a > b ? a : b; }

// s21_add
int summ_helper(big_decimal x, big_decimal y, big_decimal *z) {
  int ans = 0;
  int tmp = 0;
  int left, right;
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 32; k++) {
      // printf("%d", tmp);
      //  считывает по очереди биты
      left = get_bit_big(x, i, k), right = get_bit_big(y, i, k);
      // если оба бита установлены
      if ((left == 1) & (right == 1)) {
        if (i == 5 && k == 31) {  // !!!! переполнение
          ans = 1;
        } else {
          if (tmp == 1) {
            set_bit(&z->part[i], k, 1);
          } else {
            set_bit(&z->part[i], k, 0);
          }
          tmp = 1;
        }
      }
      // если установлен только один из двух битов
      if (left ^ right) {
        if (i == 5 && k == 31 && tmp != 0) {  // переполнение
          ans = 1;
        } else {
          if (!tmp) {
            set_bit(&z->part[i], k, 1);
          } else {
            set_bit(&z->part[i], k, 0);
          }
        }
      }
      // если оба бита нули и в памяти есть 1
      if (!left && !right && tmp) {
        set_bit(&z->part[i], k, 1);
        tmp = 0;
      } else if (!left && !right && !tmp) {
        set_bit(&z->part[i], k, 0);
      }
    }
  }
  return ans;
}

// s21_is_greater
void help_in_scaling_values(s21_decimal a, s21_decimal b, big_decimal *big_a,
                            big_decimal *big_b, int *scale_a, int *scale_b) {
  decimal_to_big_decimal(a, big_a);
  decimal_to_big_decimal(b, big_b);
  *scale_a = get_scale_nutmegha(&a);
  *scale_b = get_scale_nutmegha(&b);
  if (*scale_a > *scale_b) {
    mul10xbig_decimal(big_b, *scale_a - *scale_b);
  } else {
    mul10xbig_decimal(big_a, *scale_b - *scale_a);
  }
}
