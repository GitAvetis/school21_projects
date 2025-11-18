#include "tests.h"

START_TEST(test_s21_strerror_1) {
  for (int i = -10; i < 150; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(test_s21_strerror_2) {
  ck_assert_str_eq(s21_strerror(-1), strerror(-1));
}
END_TEST

Suite *t_s21_strerror(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("t_s21_strerror");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strerror_1);
  tcase_add_test(tc_core, test_s21_strerror_2);
  suite_add_tcase(s, tc_core);

  return s;
}
