#include "tests.h"

START_TEST(from_float_to_decimal_1) {
  float a = 0.1234678f;
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_result = {{1234678, 0, 0, 0}, 0};
  set_scale(&dec_result, 7);
  s21_from_float_to_decimal(a, &dec_1);
  int result = s21_is_equal(dec_1, dec_result);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  float a = -0.1234678f;
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_result = {{1234678, 0, 0, 0}, 0};
  set_scale(&dec_result, 7);
  set_sign(&dec_result, 1);
  s21_from_float_to_decimal(a, &dec_1);
  int result = s21_is_equal(dec_1, dec_result);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_float_to_decimal_3) {
  float a = 0;
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_result = {{0, 0, 0, 0}, 0};
  s21_from_float_to_decimal(a, &dec_1);
  int result = s21_is_equal(dec_1, dec_result);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  float a = 89228162514264337593543950336.0;
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_result = {{0, 0, 0, 0}, 0};
  s21_from_float_to_decimal(a, &dec_1);
  int result = s21_is_equal(dec_1, dec_result);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_float_to_decimal_5) {
  float a = 1.234678f;
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_result = {{1234678, 0, 0, 0}, 0};
  set_scale(&dec_result, 6);
  s21_from_float_to_decimal(a, &dec_1);
  int result = s21_is_equal(dec_1, dec_result);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  float a = 1234567881.0f;
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_result = {{1234568000, 0, 0, 0}, 0};
  set_scale(&dec_result, 0);
  s21_from_float_to_decimal(a, &dec_1);
  int result = s21_is_equal(dec_1, dec_result);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  float a = 1234.5678f;
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_result = {{1234568, 0, 0, 0}, 0};
  set_scale(&dec_result, 3);
  s21_from_float_to_decimal(a, &dec_1);
  int result = s21_is_equal(dec_1, dec_result);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *s21_from_float_to_decimal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_from_float_to_decimal_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, from_float_to_decimal_1);
  tcase_add_test(tc_core, from_float_to_decimal_2);
  tcase_add_test(tc_core, from_float_to_decimal_3);
  tcase_add_test(tc_core, from_float_to_decimal_4);
  tcase_add_test(tc_core, from_float_to_decimal_5);
  tcase_add_test(tc_core, from_float_to_decimal_6);
  tcase_add_test(tc_core, from_float_to_decimal_7);

  suite_add_tcase(s, tc_core);

  return s;
}