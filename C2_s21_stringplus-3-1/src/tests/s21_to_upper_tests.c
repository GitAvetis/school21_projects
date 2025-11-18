#include "tests.h"
START_TEST(to_upper1) {
  const char string[] = "hello world!";
  char *on_test = s21_to_upper(string);
  ck_assert_str_eq("HELLO WORLD!", on_test);
  if (on_test) free(on_test);
}
END_TEST

START_TEST(to_upper2) {
  const char string[] = "";
  char *on_test = s21_to_upper(string);
  ck_assert_str_eq("", on_test);
  if (on_test) free(on_test);
}
END_TEST

START_TEST(to_upper3) {
  const char string[] = "\n";
  char *on_test = s21_to_upper(string);
  ck_assert_str_eq("\n", on_test);
  if (on_test) free(on_test);
}
END_TEST

Suite *s21_to_upper_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_to_upper_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, to_upper1);
  tcase_add_test(tc_core, to_upper2);
  tcase_add_test(tc_core, to_upper3);
  suite_add_tcase(s, tc_core);

  return s;
}
