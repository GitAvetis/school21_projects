#include "tests.h"

START_TEST(test_s21_memcmp_1) {
  const char str1[] = "abcdef";
  const char str2[] = "abcdef";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  const char str1[] = "abcdef";
  const char str2[] = "ghijkl";
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(test_s21_memcmp_3) {
  const char str1[] = {0, 1, 2, 3, 4, 5};
  const char str2[] = {0, 1, 2, 3, 4, 6};
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

START_TEST(test_s21_memcmp_4) {
  const char str1[] = "subsequence";
  const char str2[] = "sub";
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
}
END_TEST

START_TEST(test_s21_memcmp_5) {
  const char str1[] = {0, 0, 0, 0, 0};
  const char str2[] = {0, 0, 0, 0, 1};
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

Suite *t_s21_memcmp(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("t_s21_memcmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcmp_1);
  tcase_add_test(tc_core, test_s21_memcmp_2);
  tcase_add_test(tc_core, test_s21_memcmp_3);
  tcase_add_test(tc_core, test_s21_memcmp_4);
  tcase_add_test(tc_core, test_s21_memcmp_5);
  suite_add_tcase(s, tc_core);

  return s;
}