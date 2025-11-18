#include "tests.h"
START_TEST(strchr1) {
  const char string[] = "hello world";
  s21_size_t c = 'e';
  ck_assert_str_eq(strchr(string, c), s21_strchr(string, c));
}
END_TEST

START_TEST(strchr2) {
  const char string[] = "";
  s21_size_t c = 'e';
  ck_assert_ptr_null(strchr(string, c));
  ck_assert_ptr_null(s21_strchr(string, c));
}
END_TEST

START_TEST(strchr3) {
  const char string[] = "abcdfg";
  s21_size_t c = 'e';
  ck_assert_ptr_null(s21_strchr(string, c));
  ck_assert_ptr_null(strchr(string, c));
}
END_TEST

// Тест: символ найден в середине строки
START_TEST(test_strchr_found_middle) {
  const char str[] = "Hello, world!";
  char c = 'w';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: символ найден в начале строки
START_TEST(test_strchr_found_start) {
  const char str[] = "Hello, world!";
  char c = 'H';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: символ найден в конце строки
START_TEST(test_strchr_found_end) {
  const char str[] = "Hello, world!";
  char c = '!';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: символ не найден
START_TEST(test_strchr_not_found) {
  const char str[] = "Hello, world!";
  char c = 'z';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: поиск символа '\0'
START_TEST(test_strchr_find_null) {
  const char str[] = "Hello, world!";
  char c = '\0';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: пустая строка
START_TEST(test_strchr_empty_string) {
  const char str[] = "";
  char c = 'H';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: символ в длинной строке
START_TEST(test_strchr_long_string) {
  char str[1000];
  for (int i = 0; i < 999; i++) {
    str[i] = (i == 500) ? 'x' : 'a';
  }
  str[999] = '\0';

  char c = 'x';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: символ несколько раз
START_TEST(test_strchr_multiple_occurrences) {
  const char str[] = "banana";
  char c = 'a';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: строка содержит тольк символ
START_TEST(test_strchr_only_target) {
  const char str[] = "aaaaaa";
  char c = 'a';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: строка содержит ASCII
START_TEST(test_strchr_high_ascii) {
  const char str[] = "Hello\xFFworld";
  unsigned char c = '\xFF';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: строка заканчивается искомым символом
START_TEST(test_strchr_last_character) {
  const char str[] = "Hello!";
  char c = '!';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: символ не найден в строке с пробелами
START_TEST(test_strchr_not_found_with_spaces) {
  const char str[] = "    ";
  char c = 'a';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

// Тест: символ — пробел
START_TEST(test_strchr_space) {
  const char str[] = "This is a test string.";
  char c = ' ';

  char *result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, strchr(str, c));
}
END_TEST

Suite *s21_strchr_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strchr_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, strchr1);
  tcase_add_test(tc_core, strchr2);
  tcase_add_test(tc_core, strchr3);
  tcase_add_test(tc_core, test_strchr_found_middle);
  tcase_add_test(tc_core, test_strchr_found_start);
  tcase_add_test(tc_core, test_strchr_found_end);
  tcase_add_test(tc_core, test_strchr_not_found);
  tcase_add_test(tc_core, test_strchr_find_null);
  tcase_add_test(tc_core, test_strchr_empty_string);
  tcase_add_test(tc_core, test_strchr_long_string);
  tcase_add_test(tc_core, test_strchr_multiple_occurrences);
  tcase_add_test(tc_core, test_strchr_only_target);
  tcase_add_test(tc_core, test_strchr_high_ascii);
  tcase_add_test(tc_core, test_strchr_last_character);
  tcase_add_test(tc_core, test_strchr_not_found_with_spaces);
  tcase_add_test(tc_core, test_strchr_space);

  suite_add_tcase(s, tc_core);

  return s;
}