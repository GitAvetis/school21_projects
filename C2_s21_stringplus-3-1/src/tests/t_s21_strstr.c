#include "tests.h"

START_TEST(test_s21_strstr_1) {
  char haystack[] = "";
  const char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_2) {
  char haystack[] = "school_21";
  const char needle[] = "zzz";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_3) {
  char haystack[] = "my my my ";
  const char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *t_s21_strstr(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("t_s21_strstr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strstr_1);
  tcase_add_test(tc_core, test_s21_strstr_2);
  tcase_add_test(tc_core, test_s21_strstr_3);
  suite_add_tcase(s, tc_core);

  return s;
}
