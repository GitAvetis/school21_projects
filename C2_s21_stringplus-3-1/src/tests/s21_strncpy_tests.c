#include "tests.h"

START_TEST(test_s21_strncpy_from_file) {
  FILE *fp = fopen("tests/test_files/strings.txt", "r");
  if (fp == NULL) {
    ck_abort_msg("Can't open file with tests data!\n");
  }

  char buffer[MAX_LEN_STR] = "";
  while (fgets(buffer, MAX_LEN_STR, fp) != NULL) {
    // генерируем максимальную длину строки
    for (s21_size_t i = 0; i < 100; i += 10) {
      // создаем начальные строки для дозаписи
      char dest_s21[MAX_LEN_STR] =
          "bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla "
          "bla";
      char dest[MAX_LEN_STR] =
          "bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla "
          "bla";
      ck_assert_pstr_eq(s21_strncpy(dest_s21, buffer, i),
                        strncpy(dest, buffer, i));
    }
  }
  fclose(fp);
}
END_TEST

Suite *s21_strncpy_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncpy_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncpy_from_file);
  suite_add_tcase(s, tc_core);

  return s;
}