#include "../s21_decimal.h"

// СТЕПЕНЬ
//  посмотреть значение степени
int get_scale_nutmegha(s21_decimal *dec) {
  int scale = 0b11111111;
  scale <<= 16;
  int res = dec->bits[3] & scale;
  res >>= 16;
  return res;
}

// поменять значение степени
void set_scale_nutmegha(s21_decimal *dec, int scale) {
  int old_scale = get_scale_nutmegha(dec) << 16;
  scale <<= 16;
  dec->bits[3] -= old_scale;
  dec->bits[3] += scale;
}

// ЗНАК
//  посмотреть значения знака
int get_sign_nutmegha(s21_decimal dec) {
  int res = 1;
  int index = 127;
  int mask = 1 << index;
  if ((dec.bits[3] & mask) != 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

// поменять значение знака
void set_sign_nutmegha(s21_decimal *dec) {
  int index = 127;
  int mask = 1 << index;
  dec->bits[3] = dec->bits[3] ^ mask;
}

// БИТЫ
// посмотреть значения бита
int get_bit_nutmegha(s21_decimal dec, int index) {
  int res = -1;
  if (index >= 0 && index < 128) {
    int mask = 1;
    mask <<= (index % 32);
    if ((dec.bits[index / 32] & mask) != 0) {
      res = 1;
    } else {
      res = 0;
    }
  }
  return res;
}

// поменять значение бита на противоположное
void set_bit_nutmegha(s21_decimal *dec, int index) {
  if (index >= 0 && index < 128) {
    int mask = 1;
    mask <<= (index % 32);
    dec->bits[index / 32] = dec->bits[index / 32] ^ mask;
  }
}

//  копирование decimal
void copy_decimal_nutmegha(s21_decimal *old, s21_decimal *neww) {
  for (int i = 0; i < 3; i++) {
    neww->bits[i] = old->bits[i];
  }
}

// очистка decimal
void clean_decimal_nutmegha(s21_decimal *dec) {
  for (int i = 0; i < 4; i++) {
    dec->bits[i] = 0;
  }
}

// прибавление 1
void sum_one_nutmegha(s21_decimal *value) {
  int was = 0;
  for (int i = 0; i <= 95 && was == 0; i++) {
    if (get_bit_nutmegha(*value, i) == 0) {
      was = 1;
    }
    set_bit_nutmegha(value, i);
  }
}

// Деление на 10
int s21_div_ten_nutmegha(s21_decimal *value) {
  int x = 0;
  s21_decimal res = {0};
  for (int i = 2; i >= 0; i--) {
    for (int j = 31; j >= 0; j--) {
      x <<= 1;
      s21_value_offset_nutmegha(&res);
      if (get_bit_nutmegha(*value, i * 32 + j) == 1) {
        x += 1;
      }
      if (x >= 10) {
        x -= 10;
        res.bits[0] += 1;
      }
    }
  }
  copy_decimal_nutmegha(&res, value);
  set_scale_nutmegha(value, get_scale_nutmegha(value) - 1);
  return x;
}

// смещение значения влево для 0-2 инта
void s21_value_offset_nutmegha(s21_decimal *dec) {
  for (int i = 95; i >= 0; i--) {
    if (get_bit_nutmegha(*dec, i) == 1) {
      if (get_bit_nutmegha(*dec, i + 1) == 0) {
        set_bit_nutmegha(dec, i + 1);
      }
    }
    if (get_bit_nutmegha(*dec, i) == 0) {
      if (get_bit_nutmegha(*dec, i + 1) == 1) {
        set_bit_nutmegha(dec, i + 1);
      }
    }
    if (i == 0) {
      if (get_bit_nutmegha(*dec, i) == 1) {
        set_bit_nutmegha(dec, i);
      }
    }
  }
}
