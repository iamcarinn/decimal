#ifndef _S21_DIVISION_H_
#define _S21_DIVISION_H_

#define BASE 2
#define ADIG 8

typedef struct a {
  unsigned char *byte;   // число как массив байтов
  unsigned int cells;    // кол-во байтов
  unsigned int size;     // кол-во битов в ячейках ADIG
  unsigned int bin_len;  // длина числа в двоичной форме
  unsigned char sign;    // 0 = plus; 1 = minus
} num_as_bytes;

// обьединение для int в num_as_bytes
union uint64_char {
  char p[8];
  uint64_t num;
};

union uint32_char {
  char p[4];
  uint32_t num;
};

unsigned int len_of_unsigned_int(const unsigned long long num, int base);
unsigned int help_len_of_unsigned_int(unsigned long long num);
void print_binary(unsigned long long int num, int size);
unsigned long long int int_pow(const unsigned int pow, int num);
unsigned long long int base_pow(const unsigned int pow);
int set_t(num_as_bytes a, num_as_bytes b);
int set_m(int len);

// алокация и освобождение памяти

num_as_bytes num_as_bytes_alloc(unsigned int amount_of_cells);
void num_as_bytes_free(num_as_bytes *num);

// печатаемnum_as_bytes

char *to_string_num_as_bytes_binary(num_as_bytes num);
void print_num_as_bytes_binary(num_as_bytes num);
void print_num_as_bytes_info(num_as_bytes num);

// работает только когда num < 2^64
void print_num_as_bytes_dec(num_as_bytes num);

//==============================================================
// Мат. функции, работающие с num_as_bytes variable

void num_as_bytes_sum_num_as_bytes(num_as_bytes a, num_as_bytes b,
                                   num_as_bytes *res);
void num_as_bytes_sub_num_as_bytes(num_as_bytes a, num_as_bytes b,
                                   num_as_bytes *res);
void num_as_bytes_mul_num_as_bytes(num_as_bytes a, num_as_bytes b,
                                   num_as_bytes *res);

// только для 2байтовых/1байтовых
void num_as_bytes_school_div(num_as_bytes a, num_as_bytes b, num_as_bytes *q,
                             num_as_bytes *r);

void num_as_bytes_sub_helper(unsigned char *res, unsigned char *a,
                             unsigned char *b, unsigned int m);
void num_as_bytes_mul_help(unsigned char *res, unsigned char *a,
                           unsigned char *b, unsigned int m);
void add_arr(unsigned char *res, unsigned char *a, unsigned char *b,
             unsigned int m);

// Чтобы копировать переменные

// копировать переменную с меньшим кол-вом ячеек
void num_as_bytes_cpy_eq_or_sm(num_as_bytes src, num_as_bytes *trg,
                               unsigned int how_much, unsigned int start);

// также мб работать копирование перем один. размера
void num_as_bytes_cpy_big(num_as_bytes src, num_as_bytes *trg,
                          unsigned int size);

// разделяем

void split_num_as_bytes_twice(num_as_bytes a, num_as_bytes *a1,
                              num_as_bytes *a2);
void split_num_as_bytes_t(num_as_bytes a, num_as_bytes *mass, int t);

//==============================================================
// соединять числа

void conc_num_as_bytes(num_as_bytes a, num_as_bytes b, num_as_bytes *trg);
void conc_many_num_as_bytes(num_as_bytes *trg, num_as_bytes *sources, int t);
void conc_num_as_bytes_as_dec(num_as_bytes a, num_as_bytes b,
                              num_as_bytes *ans);

//==============================================================
// основные рекурсии

// делимого и делителя количества байтов должно быть 2/1
void div21(num_as_bytes a, num_as_bytes b, num_as_bytes *q, num_as_bytes *r);
// делимого и делителя количества байтов должно быть 3/2
void div32(num_as_bytes al, num_as_bytes a3, num_as_bytes b, num_as_bytes *q,
           num_as_bytes *r);

void get_quotient_and_remainder(num_as_bytes dend, num_as_bytes sor,
                                num_as_bytes *q, num_as_bytes *r);

// code_error = 1 - переполнение
unsigned int num_as_bytes_division_dec_fractions(num_as_bytes dividend,
                                                 num_as_bytes divisor,
                                                 num_as_bytes *quotient,
                                                 char *code_error);

// побитовые сдвиги

void num_as_bytes_left_shift(num_as_bytes *src, int shift, int m);
void num_as_bytes_right_shift(num_as_bytes *src, int shift);
int full_left_shift(num_as_bytes *trg, int m);
void dend_left_shift(num_as_bytes dend, num_as_bytes *a, int o);

// постобработка

void num_as_bytes_bank_rounding_96bit(num_as_bytes *num, num_as_bytes round);

// return:
// 0 - no overflow
// 1 - overflow
char num_as_bytes_overflow(num_as_bytes num);

void set_num_as_bytes_len(num_as_bytes *a);
void num_as_bytes_rm_zeros(num_as_bytes *a);

// связь

int num_as_bytes_is_bigger_or_equal(num_as_bytes a, num_as_bytes b);

int num_as_bytes_is_zero(num_as_bytes num);

void uint32_to_num_as_bytes(uint32_t num, num_as_bytes *arr);
void uint64_to_num_as_bytes(uint64_t num, num_as_bytes *arr);
void set_q_one(num_as_bytes *q, int m);
void num_as_bytes_base_pow(num_as_bytes *based, int pow);
unsigned long long num_as_bytes_to_unsigned_long(num_as_bytes a);

void decimal_to_num_as_bytes(s21_decimal src, num_as_bytes *trg);
void ten_pow(int pow, num_as_bytes *ten);
void scale_before_s21_div(s21_decimal value_1, s21_decimal value_2,
                          num_as_bytes *dividend, num_as_bytes *divisor);
void num_as_bytes_to_s21_decimal(int sign_result, unsigned int result_scale,
                                 num_as_bytes src, s21_decimal *result);

unsigned int get_result_scale_mod(s21_decimal value_1, s21_decimal value_2);

#endif  // _S21_DIVISION_H_
