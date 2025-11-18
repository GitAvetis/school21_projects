#include "tests.h"

START_TEST(test_s21_strcspn_tests_file) {
  FILE *fp = fopen("tests/test_files/strcspn1.txt", "r");
  FILE *f = fopen("tests/test_files/strcspn2.txt", "r");
  if (fp == NULL || f == NULL) {
    ck_abort_msg("Can't open file with tests data!\n");
  }

  char s[MAX_LEN_STR] = "";
  char reject[MAX_LEN_STR] = "";
  while (fgets(s, MAX_LEN_STR, fp) != NULL &&
         fgets(reject, MAX_LEN_STR, f) != NULL) {
    ck_assert_int_eq(s21_strcspn(s, reject), strcspn(s, reject));
  }
  fclose(fp);
  fclose(f);
}
END_TEST

// Тест: символ найден в середине строки
START_TEST(test_strcspn_found_middle) {
  const char str1[] = "Hello, world!";
  const char str2[] = "ow";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: символ найден в начале строки
START_TEST(test_strcspn_found_start) {
  const char str1[] = "Hello, world!";
  const char str2[] = "H";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: символ найден в конце строки
START_TEST(test_strcspn_found_end) {
  const char str1[] = "Hello, world!";
  const char str2[] = "!";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: символ не найден
START_TEST(test_strcspn_not_found) {
  const char str1[] = "Hello, world!";
  const char str2[] = "z";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: пустая строка поиска
START_TEST(test_strcspn_empty_search) {
  const char str1[] = "Hello, world!";
  const char str2[] = "";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: строка поиска содержит все символы исходной строки
START_TEST(test_strcspn_full_match) {
  const char str1[] = "abcdef";
  const char str2[] = "abcdef";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: строка поиска содержит символы,которых нет в исходной
START_TEST(test_strcspn_no_overlap) {
  const char str1[] = "abcdef";
  const char str2[] = "xyz";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: исходная строка состоит толькоиз пробелов
START_TEST(test_strcspn_only_spaces) {
  const char str1[] = "     ";
  const char str2[] = " ";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: строка поиска состоит из символов с кодировкой
START_TEST(test_strcspn_high_ascii) {
  const char str1[] = "Hello\xFFworld";
  const char str2[] = "\xFF";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

// Тест: символ найден в длинной строкe
START_TEST(test_strcspn_first_char_in_long_string) {
  char str1[1000];
  memset(str1, 'a', 999);
  str1[0] = 'b';
  str1[999] = '\0';

  const char str2[] = "b";

  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, strcspn(str1, str2));
}
END_TEST

Suite *s21_strcspn_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strcspn_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strcspn_tests_file);
  tcase_add_test(tc_core, test_strcspn_found_middle);
  tcase_add_test(tc_core, test_strcspn_found_start);
  tcase_add_test(tc_core, test_strcspn_found_end);
  tcase_add_test(tc_core, test_strcspn_not_found);
  tcase_add_test(tc_core, test_strcspn_empty_search);
  tcase_add_test(tc_core, test_strcspn_full_match);
  tcase_add_test(tc_core, test_strcspn_no_overlap);
  tcase_add_test(tc_core, test_strcspn_only_spaces);
  tcase_add_test(tc_core, test_strcspn_high_ascii);
  tcase_add_test(tc_core, test_strcspn_first_char_in_long_string);

  suite_add_tcase(s, tc_core);

  return s;
}
