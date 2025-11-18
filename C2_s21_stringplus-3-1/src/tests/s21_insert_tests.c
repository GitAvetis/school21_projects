#include "tests.h"

START_TEST(insert1) {
  const char src[] = "insert here";
  const char *str = "this ";
  char *for_test = s21_insert(src, str, 7);
  ck_assert_str_eq("insert this here", for_test);
  free(for_test);
}
END_TEST

START_TEST(insert2) {
  const char src[] = "insert here";
  const char *str = "->";
  char *for_test = s21_insert(src, str, 7);
  ck_assert_str_eq("insert ->here", for_test);
  free(for_test);
}
END_TEST

START_TEST(insert3) {
  const char src[] = "insert here";
  const char *str = "";
  char *for_test = s21_insert(src, str, 7);
  ck_assert_str_eq("insert here", for_test);
  free(for_test);
}
END_TEST

START_TEST(insert4) {
  const char src[] = "";
  const char *str = "this";
  char *for_test = s21_insert(src, str, 7);
  ck_assert_ptr_null(for_test);
  free(for_test);
}
END_TEST

Suite *s21_insert_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_insert_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, insert1);
  tcase_add_test(tc_core, insert2);
  tcase_add_test(tc_core, insert3);
  tcase_add_test(tc_core, insert4);
  suite_add_tcase(s, tc_core);

  return s;
}
