#include "tests.h"

int main(void) {
  Suite *s21_decimal_test[] = {s21_sum_matrix_test(),
                               s21_sub_matrix_test(),
                               s21_mult_number_test(),
                               s21_mult_matrix_test(),
                               s21_transpose_test(),
                               s21_calc_complements_test(),
                               s21_determinant_test(),
                               s21_inverse_matrix_test(),
                               NULL};

  for (int i = 0; s21_decimal_test[i] != NULL; i++) {
    SRunner *sr;
    sr = srunner_create(s21_decimal_test[i]);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }
  return 0;
}
