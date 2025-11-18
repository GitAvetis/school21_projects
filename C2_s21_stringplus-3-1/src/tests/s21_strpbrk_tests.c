#include "tests.h"

START_TEST(test_s21_strpbrk_tests_file) {
  FILE *fp = fopen("tests/test_files/strings.txt", "r");
  if (fp == NULL) {
    ck_abort_msg("Can't open file with tests data!\n");
  }

  char buffer[MAX_LEN_STR] = "";
  while (fgets(buffer, MAX_LEN_STR, fp) != NULL) {
    // генерируем максимальную длину строки
    const char str2[MAX_LEN_STR] = "Aabq12345xcvbnm=+MNB";
    ck_assert_pstr_eq(s21_strpbrk(buffer, str2), strpbrk(buffer, str2));
  }
  fclose(fp);
}
END_TEST

Suite *s21_strpbrk_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strpbrk_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_tests_file);
  suite_add_tcase(s, tc_core);

  return s;
}