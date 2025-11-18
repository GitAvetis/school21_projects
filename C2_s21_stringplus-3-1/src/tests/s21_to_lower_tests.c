#include "tests.h"

START_TEST(to_lower1) {
  const char string[] = "HELLO WORLD!";
  char *on_test = s21_to_lower(string);
  ck_assert_str_eq("hello world!", on_test);
  if (on_test) free(on_test);
}
END_TEST

START_TEST(to_lower2) {
  const char string[] = "";
  char *on_test = s21_to_lower(string);
  ck_assert_str_eq("", on_test);
  if (on_test) free(on_test);
}
END_TEST

START_TEST(to_lower3) {
  const char string[] = "\n";
  char *on_test = s21_to_lower(string);
  ck_assert_str_eq("\n", on_test);
  if (on_test) free(on_test);
}
END_TEST

Suite *s21_to_lower_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_to_lower_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, to_lower1);
  tcase_add_test(tc_core, to_lower2);
  tcase_add_test(tc_core, to_lower3);
  suite_add_tcase(s, tc_core);

  return s;
}
