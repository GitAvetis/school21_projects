#include "tests.h"

START_TEST(test_from_decimal_to_float_1) {
  s21_decimal dec_1 = {{18122, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);
  set_sign(&dec_1, 1);

  float s21_result = 0;
  float result = -18.122;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_2) {
  s21_decimal dec_1 = {{18122, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);

  float s21_result = 0;
  float result = 18.122;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_3) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  set_sign(&dec_1, 1);

  float s21_result = 0;
  float result = -1;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_4) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};

  float s21_result = 0;
  float result = 1;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_5) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  set_scale(&dec_1, 1);
  set_sign(&dec_1, 1);

  float s21_result = 0;
  float result = -0.1;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_6) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  set_scale(&dec_1, 1);

  float s21_result = 0;
  float result = 0.1;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_7) {
  s21_decimal dec_1 = {{123456, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);

  float s21_result = 0;
  float result = 123.456;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_8) {
  s21_decimal dec_1 = {{123456, 0, 0, S21_MINUS}, 0};
  set_scale(&dec_1, 3);

  float s21_result = 0;
  float result = -123.456;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 0.0000001);
}
END_TEST

START_TEST(test_from_decimal_to_float_9) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  set_scale(&dec_1, 1);

  float s21_result = 0;
  float result = 429496729.5;

  s21_from_decimal_to_float(dec_1, &s21_result);
  ck_assert_float_eq_tol(s21_result, result, 50.0000001);
}
END_TEST

Suite *s21_from_decimal_to_float_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_from_decimal_to_float_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_decimal_to_float_1);
  tcase_add_test(tc_core, test_from_decimal_to_float_2);
  tcase_add_test(tc_core, test_from_decimal_to_float_3);
  tcase_add_test(tc_core, test_from_decimal_to_float_4);
  tcase_add_test(tc_core, test_from_decimal_to_float_5);
  tcase_add_test(tc_core, test_from_decimal_to_float_6);
  tcase_add_test(tc_core, test_from_decimal_to_float_7);
  tcase_add_test(tc_core, test_from_decimal_to_float_8);
  tcase_add_test(tc_core, test_from_decimal_to_float_9);

  suite_add_tcase(s, tc_core);

  return s;
}