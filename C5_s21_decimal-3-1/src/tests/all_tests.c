#include "tests.h"

int main() {
  // int number_fails = 0;

  Suite *s21_decimal_test[] = {s21_is_greater_test(),
                               s21_is_greater_or_equal_test(),
                               s21_is_equal_test(),
                               s21_is_not_equal_test(),
                               s21_is_less_or_equal_test(),
                               s21_is_less_test(),
                               s21_truncate_test(),
                               suite_add(),
                               suite_div(),
                               test_s21_round(),
                               test_s21_floor(),
                               test_s21_from_int_to_decimal(),
                               suite_sub(),
                               suite_mul(),
                               s21_from_float_to_decimal_test(),
                               s21_from_decimal_to_float_test(),
                               suite_negate(),
                               NULL};

  for (int i = 0; s21_decimal_test[i] != NULL; i++) {
    SRunner *sr;
    sr = srunner_create(s21_decimal_test[i]);
    srunner_run_all(sr, CK_NORMAL);
    // number_fails = +srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  return 0;
}
