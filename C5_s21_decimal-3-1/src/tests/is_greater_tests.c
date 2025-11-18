#include "tests.h"

START_TEST(test_is_greater_1) {
  s21_decimal dec_1 = {{12345678, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1000, 0, 0, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_2) {
  s21_decimal dec_1 = {{999, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1000, 0, 0, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_3) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_4) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 1, 0, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_5) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT - 1, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_6) {
  s21_decimal dec_1 = {{15, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{14, 0, 0, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

// проверяем на переполнение чисел с очень разными скейлами
START_TEST(test_is_greater_7) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  set_scale(&dec_1, 27);
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

// проверяем на переполнение чисел с очень разными скейлами
START_TEST(test_is_greater_8) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_9) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_10) {
  s21_decimal dec_1 = {{0, 0, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{0, 0, S21_MAX_UINT - 1, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_11) {
  s21_decimal dec_1 = {{0, 0, S21_MAX_UINT, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 0, S21_MAX_UINT - 1, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_12) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_13) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, S21_MINUS}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_14) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, S21_MINUS}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

// сравниваем очень маленькие числа
START_TEST(test_is_greater_15) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{2, 0, 0, 0}, 0};
  set_scale(&dec_1, 28);  // 0.0000000000000000000000000001
  set_scale(&dec_2, 28);  // 0.0000000000000000000000000002
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_16) {
  s21_decimal dec_1 = {{2, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1, 0, 0, 0}, 0};
  set_scale(&dec_1, 28);  // 0.0000000000000000000000000002
  set_scale(&dec_2, 28);  // 0.0000000000000000000000000001
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

// дробные числа с разными знаками
START_TEST(test_is_greater_17) {
  s21_decimal dec_1 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // 12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_18) {
  s21_decimal dec_1 = {{12345, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // -12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_19) {
  s21_decimal dec_1 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, S21_MINUS}, 0};
  set_scale(&dec_1, 3);  // 12.345
  set_scale(&dec_2, 4);  // -3.4567
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_20) {
  s21_decimal dec_1 = {{12345, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // -12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_21) {
  s21_decimal dec_1 = {{0, 12345, 0, 0}, 0};
  s21_decimal dec_2 = {{0, 34567, 0, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 4);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_22) {
  s21_decimal dec_1 = {{0, 12345, 0, 0}, 0};
  s21_decimal dec_2 = {{0, 34567, 0, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 3);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_23) {
  s21_decimal dec_1 = {{0, 12345, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 34567, 0, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 4);
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_24) {
  s21_decimal dec_1 = {{0, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 0, 0, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_25) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{0, 0, 0, S21_MINUS}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_26) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, INF};
  s21_decimal dec_2 = {{1, 0, 0, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_27) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, NEG_INF};
  s21_decimal dec_2 = {{1, 0, 0, 0}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_28) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, NEG_INF};
  s21_decimal dec_2 = {{1, 0, 0, 0}, NEG_INF};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_29) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, INF};
  s21_decimal dec_2 = {{1, 0, 0, 0}, NEG_INF};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_30) {
  s21_decimal dec_1 = {{2, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{1, 0, 0, S21_MINUS}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_greater_31) {
  s21_decimal dec_1 = {{2, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{10, 0, 0, S21_MINUS}, 0};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_greater_32) {
  s21_decimal dec_1 = {{2, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{10, 0, 0, S21_MINUS}, NEG_INF};
  int result = s21_is_greater(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *s21_is_greater_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_is_greater_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_is_greater_1);
  tcase_add_test(tc_core, test_is_greater_2);
  tcase_add_test(tc_core, test_is_greater_3);
  tcase_add_test(tc_core, test_is_greater_4);
  tcase_add_test(tc_core, test_is_greater_5);
  tcase_add_test(tc_core, test_is_greater_6);
  tcase_add_test(tc_core, test_is_greater_7);
  tcase_add_test(tc_core, test_is_greater_8);
  tcase_add_test(tc_core, test_is_greater_9);
  tcase_add_test(tc_core, test_is_greater_10);
  tcase_add_test(tc_core, test_is_greater_11);
  tcase_add_test(tc_core, test_is_greater_12);
  tcase_add_test(tc_core, test_is_greater_13);
  tcase_add_test(tc_core, test_is_greater_14);
  tcase_add_test(tc_core, test_is_greater_15);
  tcase_add_test(tc_core, test_is_greater_16);
  tcase_add_test(tc_core, test_is_greater_17);
  tcase_add_test(tc_core, test_is_greater_18);
  tcase_add_test(tc_core, test_is_greater_19);
  tcase_add_test(tc_core, test_is_greater_20);
  tcase_add_test(tc_core, test_is_greater_21);
  tcase_add_test(tc_core, test_is_greater_22);
  tcase_add_test(tc_core, test_is_greater_23);
  tcase_add_test(tc_core, test_is_greater_24);
  tcase_add_test(tc_core, test_is_greater_25);
  tcase_add_test(tc_core, test_is_greater_26);
  tcase_add_test(tc_core, test_is_greater_27);
  tcase_add_test(tc_core, test_is_greater_28);
  tcase_add_test(tc_core, test_is_greater_29);
  tcase_add_test(tc_core, test_is_greater_30);
  tcase_add_test(tc_core, test_is_greater_31);
  tcase_add_test(tc_core, test_is_greater_32);

  suite_add_tcase(s, tc_core);

  return s;
}