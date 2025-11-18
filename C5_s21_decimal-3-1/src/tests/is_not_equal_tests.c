#include "tests.h"

START_TEST(test_is_not_equal_1) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{0, 0, 0, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_2) {
  s21_decimal dec_1 = {{1, 1, 1, 0}, 0};
  s21_decimal dec_2 = {{1, 1, 1, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_3) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_4) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT, 0, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_5) {
  s21_decimal dec_1 = {{0, 0, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{0, 0, S21_MAX_UINT, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_6) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_7) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_8) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  set_scale(&dec_1, 4);
  set_scale(&dec_2, 4);
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_9) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  set_scale(&dec_1, 28);
  set_scale(&dec_2, 28);
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_10) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  set_scale(&dec_1, 28);
  set_scale(&dec_2, 28);
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_11) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  set_scale(&dec_1, 28);
  set_scale(&dec_2, 28);
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_12) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  set_scale(&dec_1, 28);
  set_scale(&dec_2, 28);
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_13) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{2, 0, 0, 0}, 0};
  set_scale(&dec_1, 28);
  set_scale(&dec_2, 28);
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_14) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{2, 0, 0, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_15) {
  s21_decimal dec_1 = {{1003, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1003, 1, 0, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_16) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT - 1, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_17) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT - 1, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_18) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT - 1, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  set_scale(&dec_1, 28);
  set_scale(&dec_2, 28);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_19) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  set_scale(&dec_1, 27);
  set_scale(&dec_2, 28);
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_20) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MINUS},
                       0};
  set_scale(&dec_1, 28);
  set_scale(&dec_2, 27);
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_21) {
  s21_decimal dec_1 = {{0, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 0, 0, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_22) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, INF};
  s21_decimal dec_2 = {{0, 0, 0, 0}, 0};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_not_equal_23) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, INF};
  s21_decimal dec_2 = {{0, 0, 0, 0}, INF};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_not_equal_24) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, NEG_INF};
  s21_decimal dec_2 = {{0, 0, 0, 0}, INF};
  int result = s21_is_not_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *s21_is_not_equal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_is_not_equal_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_is_not_equal_1);
  tcase_add_test(tc_core, test_is_not_equal_2);
  tcase_add_test(tc_core, test_is_not_equal_3);
  tcase_add_test(tc_core, test_is_not_equal_4);
  tcase_add_test(tc_core, test_is_not_equal_5);
  tcase_add_test(tc_core, test_is_not_equal_6);
  tcase_add_test(tc_core, test_is_not_equal_7);
  tcase_add_test(tc_core, test_is_not_equal_8);
  tcase_add_test(tc_core, test_is_not_equal_9);
  tcase_add_test(tc_core, test_is_not_equal_10);
  tcase_add_test(tc_core, test_is_not_equal_11);
  tcase_add_test(tc_core, test_is_not_equal_12);
  tcase_add_test(tc_core, test_is_not_equal_13);
  tcase_add_test(tc_core, test_is_not_equal_14);
  tcase_add_test(tc_core, test_is_not_equal_15);
  tcase_add_test(tc_core, test_is_not_equal_16);
  tcase_add_test(tc_core, test_is_not_equal_17);
  tcase_add_test(tc_core, test_is_not_equal_18);
  tcase_add_test(tc_core, test_is_not_equal_19);
  tcase_add_test(tc_core, test_is_not_equal_20);
  tcase_add_test(tc_core, test_is_not_equal_21);
  tcase_add_test(tc_core, test_is_not_equal_22);
  tcase_add_test(tc_core, test_is_not_equal_23);
  tcase_add_test(tc_core, test_is_not_equal_24);

  suite_add_tcase(s, tc_core);

  return s;
}