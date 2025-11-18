#include "tests.h"

START_TEST(test_is_less_or_equal_1) {
  s21_decimal dec_1 = {{12345678, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1000, 0, 0, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_2) {
  s21_decimal dec_1 = {{999, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1000, 0, 0, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_3) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_4) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 1, 0, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_5) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT - 1, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_6) {
  s21_decimal dec_1 = {{15, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{14, 0, 0, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

// проверяем на переполнение чисел с очень разными скейлами
START_TEST(test_is_less_or_equal_7) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  set_scale(&dec_1, 27);
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

// проверяем на переполнение чисел с очень разными скейлами
START_TEST(test_is_less_or_equal_8) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_9) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_10) {
  s21_decimal dec_1 = {{0, 0, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{0, 0, S21_MAX_UINT - 1, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_11) {
  s21_decimal dec_1 = {{0, 0, S21_MAX_UINT, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 0, S21_MAX_UINT - 1, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_12) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_13) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, S21_MINUS}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_14) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, S21_MINUS}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

// сравниваем очень маленькие числа
START_TEST(test_is_less_or_equal_15) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{2, 0, 0, 0}, 0};
  set_scale(&dec_1, 28);  // 0.0000000000000000000000000001
  set_scale(&dec_2, 28);  // 0.0000000000000000000000000002
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_16) {
  s21_decimal dec_1 = {{2, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1, 0, 0, 0}, 0};
  set_scale(&dec_1, 28);  // 0.0000000000000000000000000002
  set_scale(&dec_2, 28);  // 0.0000000000000000000000000001
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

// дробные числа с разными знаками
START_TEST(test_is_less_or_equal_17) {
  s21_decimal dec_1 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // 12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_18) {
  s21_decimal dec_1 = {{12345, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // -12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_19) {
  s21_decimal dec_1 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, S21_MINUS}, 0};
  set_scale(&dec_1, 3);  // 12.345
  set_scale(&dec_2, 4);  // -3.4567
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_20) {
  s21_decimal dec_1 = {{12345, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // -12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_21) {
  s21_decimal dec_1 = {{0, 1, 12345, 0}, 0};
  s21_decimal dec_2 = {{0, 1, 12345, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 3);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_22) {
  s21_decimal dec_1 = {{0, 12345, 0, 0}, 0};
  s21_decimal dec_2 = {{0, 12345, 0, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 3);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_23) {
  s21_decimal dec_1 = {{0, 12345, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 34567, 0, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 4);
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_24) {
  s21_decimal dec_1 = {{0, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 0, 0, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_25) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, NEG_INF};
  s21_decimal dec_2 = {{0, 0, 0, 0}, NEG_INF};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_26) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, NEG_INF};
  s21_decimal dec_2 = {{0, 0, 0, 0}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_27) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{0, 0, 0, 0}, INF};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_28) {
  s21_decimal dec_1 = {{2, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{1, 0, 0, S21_MINUS}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_29) {
  s21_decimal dec_1 = {{1, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{10, 0, 0, S21_MINUS}, 0};
  int result = s21_is_less_or_equal(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *s21_is_less_or_equal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_is_less_or_equal_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_is_less_or_equal_1);
  tcase_add_test(tc_core, test_is_less_or_equal_2);
  tcase_add_test(tc_core, test_is_less_or_equal_3);
  tcase_add_test(tc_core, test_is_less_or_equal_4);
  tcase_add_test(tc_core, test_is_less_or_equal_5);
  tcase_add_test(tc_core, test_is_less_or_equal_6);
  tcase_add_test(tc_core, test_is_less_or_equal_7);
  tcase_add_test(tc_core, test_is_less_or_equal_8);
  tcase_add_test(tc_core, test_is_less_or_equal_9);
  tcase_add_test(tc_core, test_is_less_or_equal_10);
  tcase_add_test(tc_core, test_is_less_or_equal_11);
  tcase_add_test(tc_core, test_is_less_or_equal_12);
  tcase_add_test(tc_core, test_is_less_or_equal_13);
  tcase_add_test(tc_core, test_is_less_or_equal_14);
  tcase_add_test(tc_core, test_is_less_or_equal_15);
  tcase_add_test(tc_core, test_is_less_or_equal_16);
  tcase_add_test(tc_core, test_is_less_or_equal_17);
  tcase_add_test(tc_core, test_is_less_or_equal_18);
  tcase_add_test(tc_core, test_is_less_or_equal_19);
  tcase_add_test(tc_core, test_is_less_or_equal_20);
  tcase_add_test(tc_core, test_is_less_or_equal_21);
  tcase_add_test(tc_core, test_is_less_or_equal_22);
  tcase_add_test(tc_core, test_is_less_or_equal_23);
  tcase_add_test(tc_core, test_is_less_or_equal_24);
  tcase_add_test(tc_core, test_is_less_or_equal_25);
  tcase_add_test(tc_core, test_is_less_or_equal_26);
  tcase_add_test(tc_core, test_is_less_or_equal_27);
  tcase_add_test(tc_core, test_is_less_or_equal_28);
  tcase_add_test(tc_core, test_is_less_or_equal_29);

  suite_add_tcase(s, tc_core);

  return s;
}