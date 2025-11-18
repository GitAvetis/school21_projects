#include "tests.h"

int main() {
  int number_fails = 0;

  Suite *s21_string_test[] = {s21_strtok_test(),
                              s21_memcpy_test(),
                              s21_strcspn_test(),
                              s21_memchr_test(),
                              s21_memset_test(),
                              s21_strncmp_test(),
                              s21_strncat_test(),
                              s21_strncpy_test(),
                              s21_to_lower_test(),
                              s21_to_upper_test(),
                              s21_trim_test(),
                              s21_strrchr_test(),
                              s21_strchr_test(),
                              s21_insert_test(),
                              s21_strlen_test(),
                              t_s21_memcmp(),
                              t_s21_memcpy(),
                              t_s21_strerror(),
                              t_s21_strstr(),
                              s21_strpbrk_test(),
                              s21_sprintf_test(),
                              sscanf_suite(),
                              s21_NULL};

  for (int i = 0; s21_string_test[i] != s21_NULL; i++) {
    SRunner *sr;
    sr = srunner_create(s21_string_test[i]);
    srunner_run_all(sr, CK_NORMAL);
    number_fails = +srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("Numbers fails = %d\n", number_fails);
  return 0;
}
