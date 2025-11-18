#include "tests.h"

START_TEST(memchr_1) {
  char str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int ch = 5;
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "Hello, world!";
  int ch = 'W';
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int ch = 11;
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "";
  int ch = 1;
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = {1, 2, 3, 4, 5};
  int ch = 4;
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int ch = 10;
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int ch = 1;
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int ch = 6;
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

Suite *s21_memchr_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memchr_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, memchr_1);
  tcase_add_test(tc_core, memchr_2);
  tcase_add_test(tc_core, memchr_3);
  tcase_add_test(tc_core, memchr_4);
  tcase_add_test(tc_core, memchr_5);
  tcase_add_test(tc_core, memchr_6);
  tcase_add_test(tc_core, memchr_7);
  tcase_add_test(tc_core, memchr_8);
  suite_add_tcase(s, tc_core);

  return s;
}