#include "tests.h"

START_TEST(memcpy1) {
  const char src[10] = "";
  char dest_s21[10] = "test";
  char dest[10] = "test";
  s21_memcpy(dest_s21, src, 0);
  memcpy(dest, src, 0);
  ck_assert_mem_eq(dest_s21, dest, 10);
}
END_TEST

START_TEST(memcpy2) {
  char src[] = "Hello";
  char dest_s21[10] = "";
  char dest[10] = "";
  s21_memcpy(dest_s21, src, sizeof(src) - 1);
  memcpy(dest, src, sizeof(src) - 1);
  ck_assert_mem_eq(dest_s21, dest, sizeof(src));
}
END_TEST

START_TEST(memcpy3) {
  char src[1024] = "";
  char dest_s21[1024] = "";
  char dest[1024] = "";
  for (int i = 0; i < 1024; ++i) {
    src[i] = i % 256;
  }
  s21_memcpy(dest_s21, src, 1024);
  memcpy(dest, src, 1024);
  ck_assert_mem_eq(dest_s21, dest, 1024);
}
END_TEST

START_TEST(memcpy4) {
  ck_assert_ptr_eq(s21_memcpy(NULL, NULL, 0), NULL);
  const char src[] = "test";
  char dest[10] = "";
  ck_assert_ptr_eq(s21_memcpy(dest, NULL, 0), dest);
  ck_assert_ptr_eq(s21_memcpy(NULL, src, 0), NULL);
}
END_TEST

START_TEST(memcpy5) {
  int src_int = 12345;
  int dest_int_s21 = 0;
  int dest_int = 0;
  s21_memcpy(&dest_int_s21, &src_int, sizeof(int));
  memcpy(&dest_int, &src_int, sizeof(int));
  ck_assert_int_eq(dest_int_s21, dest_int);
  double src_double = 3.14159;
  double dest_double_s21 = 0.0;
  double dest_double = 0.0;
  s21_memcpy(&dest_double_s21, &src_double, sizeof(double));
  memcpy(&dest_double, &src_double, sizeof(double));
  ck_assert_double_eq(dest_double_s21, dest_double);
}
END_TEST

Suite *t_s21_memcpy(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("t_s21_memcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, memcpy1);
  tcase_add_test(tc_core, memcpy2);
  tcase_add_test(tc_core, memcpy3);
  tcase_add_test(tc_core, memcpy4);
  tcase_add_test(tc_core, memcpy5);
  suite_add_tcase(s, tc_core);

  return s;
}
