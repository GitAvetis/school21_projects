#include "tests.h"

START_TEST(strlen1) {
  const char string[] = "hello world";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen2) {
  const char string[] = "";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

// Тест: пустая строка
START_TEST(test_strlen_empty_string) {
  const char *str = "";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка из одного символа
START_TEST(test_strlen_single_char) {
  const char *str = "a";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка из нескольких символов
START_TEST(test_strlen_normal_string) {
  const char *str = "Hello, world!";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка с пробелами
START_TEST(test_strlen_with_spaces) {
  const char *str = "   ";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка с escape
START_TEST(test_strlen_escape_sequences) {
  const char *str = "Line1\nLine2\tTab";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: длинная строка
START_TEST(test_strlen_long_string) {
  char str[1000];
  for (int i = 0; i < 999; i++) {
    str[i] = 'a';
  }
  str[999] = '\0';
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка с ASCII
START_TEST(test_strlen_high_ascii) {
  const char *str = "\xC3\xA9";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка снулями внутри
START_TEST(test_strlen_with_null_chars) {
  const char str[] = "abc\0def";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка с числовыми
START_TEST(test_strlen_numeric_string) {
  const char *str = "1234567890";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка из повторяющегося
START_TEST(test_strlen_repeated_chars) {
  const char *str = "aaaaaaa";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// Тест: строка с комбинацией символов и пробелов
START_TEST(test_strlen_mixed_chars_and_spaces) {
  const char *str = "Hello   World";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_uint_eq(result, expected);
}
END_TEST

Suite *s21_strlen_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strlen_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, strlen1);
  tcase_add_test(tc_core, strlen2);
  tcase_add_test(tc_core, test_strlen_empty_string);
  tcase_add_test(tc_core, test_strlen_single_char);
  tcase_add_test(tc_core, test_strlen_normal_string);
  tcase_add_test(tc_core, test_strlen_with_spaces);
  tcase_add_test(tc_core, test_strlen_escape_sequences);
  tcase_add_test(tc_core, test_strlen_long_string);
  tcase_add_test(tc_core, test_strlen_high_ascii);
  tcase_add_test(tc_core, test_strlen_with_null_chars);
  tcase_add_test(tc_core, test_strlen_numeric_string);
  tcase_add_test(tc_core, test_strlen_repeated_chars);
  tcase_add_test(tc_core, test_strlen_mixed_chars_and_spaces);

  suite_add_tcase(s, tc_core);

  return s;
}
