#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *s21_sum_matrix_test(void);
Suite *s21_sub_matrix_test(void);
Suite *s21_mult_number_test(void);
Suite *s21_mult_matrix_test(void);
Suite *s21_transpose_test(void);
Suite *s21_calc_complements_test(void);
Suite *s21_determinant_test(void);
Suite *s21_inverse_matrix_test(void);

#endif
