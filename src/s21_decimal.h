#ifndef _S21_DECIMAL_H_
#define _S21_DECIMAL_H_
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR_ROUND 1
#define CONVERSION_ERROR 1

#define TRUE 1
#define FALSE 0
typedef struct {
  unsigned int bits[4];
} s21_decimal;
#include "headers/burnette.h"
#include "headers/letitiar.h"
#include "headers/nutmegha.h"
#include "headers/s21_div.h"
#include "headers/veolashe.h"
#endif  // _S21_DECIMAL_H_
