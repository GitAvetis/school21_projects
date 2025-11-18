#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define S21_MAX_UINT 0xffffffff
#define S21_MINUS 0x80000000
#define S21_INT_MAX 2147483647
#define MAX_DECIMAL 79228162514264337593543950336.0

Suite *s21_is_greater_test(void);
Suite *s21_is_greater_or_equal_test(void);
Suite *s21_is_equal_test(void);
Suite *s21_is_not_equal_test(void);
Suite *s21_is_less_or_equal_test(void);
Suite *s21_is_less_test(void);
Suite *s21_truncate_test(void);
Suite *suite_add(void);
Suite *suite_div(void);
Suite *test_s21_round(void);
Suite *test_s21_floor(void);
Suite *test_s21_from_int_to_decimal(void);
Suite *suite_mul(void);
Suite *suite_sub(void);
Suite *s21_from_float_to_decimal_test(void);
Suite *s21_from_decimal_to_float_test(void);
Suite *suite_negate(void);

#endif