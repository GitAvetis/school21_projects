#include "tests.h"

START_TEST(strrchr1) {
  const char string[] = "hello world";
  s21_size_t c = 'e';
  ck_assert_str_eq(strrchr(string, c), s21_strrchr(string, c));
}
END_TEST

START_TEST(strrchr2) {
  const char string[] = "";
  s21_size_t c = 'e';
  ck_assert_ptr_null(strrchr(string, c));
  ck_assert_ptr_null(s21_strrchr(string, c));
}
END_TEST

START_TEST(strrchr3) {
  const char string[] = "abcdfg";
  s21_size_t c = 'e';
  ck_assert_ptr_null(strrchr(string, c));
  ck_assert_ptr_null(s21_strrchr(string, c));
}
END_TEST

// Тест: символ найден в конце строки
START_TEST(test_strrchr_found_end) {
  const char *str = "hello";
  int c = 'o';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: символ найден в середине строки
START_TEST(test_strrchr_found_middle) {
  const char *str = "hello";
  int c = 'l';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: символ найден в начале строки
START_TEST(test_strrchr_found_start) {
  const char *str = "hello";
  int c = 'h';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: символ не найден
START_TEST(test_strrchr_not_found) {
  const char *str = "hello";
  int c = 'z';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: поиск символа `\0`
START_TEST(test_strrchr_null_char) {
  const char *str = "hello";
  int c = '\0';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: строка с несколькими одинаковыми символами
START_TEST(test_strrchr_multiple_occurrences) {
  const char *str = "banana";
  int c = 'a';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: строка из одного символа
START_TEST(test_strrchr_single_char) {
  const char *str = "a";
  int c = 'a';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: строка пустая
START_TEST(test_strrchr_empty_string) {
  const char *str = "";
  int c = 'a';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: строка содержит пробелы
START_TEST(test_strrchr_with_spaces) {
  const char *str = "a b c d";
  int c = ' ';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: строка с ASCII
START_TEST(test_strrchr_ascii) {
  const char str[] = {'a', 'b', 'c', '\x7F', 'd', 'e', 'f', '\0'};
  int c = '\x7F';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: строка с повторяющимся символом,последний символ совпадает
START_TEST(test_strrchr_repeated_last_char) {
  const char *str = "aaaaaa";
  int c = 'a';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: строка с символами из разных диапазонов
START_TEST(test_strrchr_mixed_chars) {
  const char *str = "abc123!@#";
  int c = '1';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}

Suite *s21_strrchr_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strrchr_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, strrchr1);
  tcase_add_test(tc_core, strrchr2);
  tcase_add_test(tc_core, strrchr3);
  tcase_add_test(tc_core, test_strrchr_found_end);
  tcase_add_test(tc_core, test_strrchr_found_middle);
  tcase_add_test(tc_core, test_strrchr_found_start);
  tcase_add_test(tc_core, test_strrchr_not_found);
  tcase_add_test(tc_core, test_strrchr_null_char);
  tcase_add_test(tc_core, test_strrchr_multiple_occurrences);
  tcase_add_test(tc_core, test_strrchr_single_char);
  tcase_add_test(tc_core, test_strrchr_empty_string);
  tcase_add_test(tc_core, test_strrchr_with_spaces);
  tcase_add_test(tc_core, test_strrchr_ascii);
  tcase_add_test(tc_core, test_strrchr_repeated_last_char);
  tcase_add_test(tc_core, test_strrchr_mixed_chars);

  suite_add_tcase(s, tc_core);

  return s;
}