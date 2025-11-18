#include "tests.h"

START_TEST(strncmp_1) {
  const char *str1 = "Hello";
  const char *str2 = "Help";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(strncmp_2) {
  const char *str1 = "Hello";
  const char *str2 = "Help";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
}
END_TEST

START_TEST(strncmp_3) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

START_TEST(strncmp_4) {
  const char *str1 = "Zero";
  const char *str2 = "Null";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(strncmp_5) {
  const char *str1 = "\n\n";
  const char *str2 = "\t\t";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
}
END_TEST

START_TEST(strncmp_6) {
  const char *str1 = "Window\n";
  const char *str2 = "Window\r";
  ck_assert_int_eq(s21_strncmp(str1, str2, 8), strncmp(str1, str2, 8));
}
END_TEST

START_TEST(strncmp_7) {
  const char *str1 = "q12345qwert";
  const char *str2 = "12345qwert";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_8) {
  const char *str1 = "";
  const char *str2 = "f";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(strncmp_9) {
  const char *str1 = "qwerty";
  const char *str2 = "qwerth";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
}
END_TEST

Suite *s21_strncmp_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncmp_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, strncmp_1);
  tcase_add_test(tc_core, strncmp_2);
  tcase_add_test(tc_core, strncmp_3);
  tcase_add_test(tc_core, strncmp_4);
  tcase_add_test(tc_core, strncmp_5);
  tcase_add_test(tc_core, strncmp_6);
  tcase_add_test(tc_core, strncmp_7);
  tcase_add_test(tc_core, strncmp_8);
  tcase_add_test(tc_core, strncmp_9);
  suite_add_tcase(s, tc_core);

  return s;
}