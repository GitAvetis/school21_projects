#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_STR 2048
// #include "../s21_sscanf.h"
#include "../s21_string.h"

Suite *s21_memcpy_test(void);
Suite *s21_memchr_test(void);
Suite *s21_memset_test(void);
Suite *s21_strncmp_test(void);
Suite *s21_strcspn_test(void);
Suite *s21_strtok_test(void);
Suite *s21_strncat_test(void);
Suite *s21_strncpy_test(void);
Suite *s21_to_lower_test(void);
Suite *s21_to_upper_test(void);
Suite *s21_strrchr_test(void);
Suite *s21_strchr_test(void);
Suite *s21_insert_test(void);
Suite *s21_trim_test(void);
Suite *s21_strlen_test(void);
Suite *t_s21_memcmp(void);
Suite *t_s21_memcpy(void);
Suite *t_s21_strerror(void);
Suite *t_s21_strstr(void);
Suite *s21_strpbrk_test(void);
Suite *s21_sprintf_test(void);
Suite *sscanf_suite(void);

#endif
