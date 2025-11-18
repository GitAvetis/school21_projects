#include "tests.h"

void compare_strtok(const char *str, const char *delim) {
  char str1[256];
  char str2[256];
  strcpy(str1, str);
  strcpy(str2, str);

  char *token1 = strtok(str1, delim);
  char *token2 = s21_strtok(str2, delim);

  while (token1 != NULL && token2 != NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = strtok(NULL, delim);
    token2 = s21_strtok(NULL, delim);
  }

  ck_assert_ptr_eq(token1, token2);
}

START_TEST(test_strtok_basic) { compare_strtok("Hello, World!", " "); }
END_TEST

START_TEST(test_strtok_multiple_delims) {
  compare_strtok("Hello,World;from:strtok", ",;:");
}
END_TEST

START_TEST(test_strtok_empty_string) { compare_strtok("", " "); }
END_TEST

START_TEST(test_strtok_no_delims) { compare_strtok("HelloWorld", " "); }
END_TEST

START_TEST(test_strtok_delim_at_end) { compare_strtok("Hello World ", " "); }
END_TEST

START_TEST(test_strtok_delim_at_start) { compare_strtok(" Hello World", " "); }
END_TEST

START_TEST(test_strtok_delim_in_middle) {
  compare_strtok("Hello,World,from,strtok", ",");
}
END_TEST

Suite *s21_strtok_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strtok_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strtok_basic);
  tcase_add_test(tc_core, test_strtok_multiple_delims);
  tcase_add_test(tc_core, test_strtok_empty_string);
  tcase_add_test(tc_core, test_strtok_no_delims);
  tcase_add_test(tc_core, test_strtok_delim_at_end);
  tcase_add_test(tc_core, test_strtok_delim_at_start);
  tcase_add_test(tc_core, test_strtok_delim_in_middle);
  suite_add_tcase(s, tc_core);

  return s;
}
