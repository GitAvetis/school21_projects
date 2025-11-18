#include "tests.h"

START_TEST(test_is_less_1) {
  s21_decimal dec_1 = {{12345678, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1000, 0, 0, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_2) {
  s21_decimal dec_1 = {{999, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1000, 0, 0, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_3) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_4) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 1, 0, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, 0, 0, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_5) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT - 1, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_6) {
  s21_decimal dec_1 = {{15, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{14, 0, 0, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

// проверяем на переполнение чисел с очень разными скейлами
START_TEST(test_is_less_7) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  set_scale(&dec_1, 27);
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

// проверяем на переполнение чисел с очень разными скейлами
START_TEST(test_is_less_8) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_9) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_10) {
  s21_decimal dec_1 = {{0, 0, S21_MAX_UINT, 0}, 0};
  s21_decimal dec_2 = {{0, 0, S21_MAX_UINT - 1, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_11) {
  s21_decimal dec_1 = {{0, 0, S21_MAX_UINT, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 0, S21_MAX_UINT - 1, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_12) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, 0}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_13) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, S21_MINUS}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_14) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal dec_2 = {{0, S21_MAX_UINT - 1, 0, S21_MINUS}, 0};
  set_scale(&dec_2, 27);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

// сравниваем очень маленькие числа
START_TEST(test_is_less_15) {
  s21_decimal dec_1 = {{1, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{2, 0, 0, 0}, 0};
  set_scale(&dec_1, 28);  // 0.0000000000000000000000000001
  set_scale(&dec_2, 28);  // 0.0000000000000000000000000002
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_16) {
  s21_decimal dec_1 = {{2, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1, 0, 0, 0}, 0};
  set_scale(&dec_1, 28);  // 0.0000000000000000000000000002
  set_scale(&dec_2, 28);  // 0.0000000000000000000000000001
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

// дробные числа с разными знаками
START_TEST(test_is_less_17) {
  s21_decimal dec_1 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // 12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_18) {
  s21_decimal dec_1 = {{12345, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // -12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_19) {
  s21_decimal dec_1 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, S21_MINUS}, 0};
  set_scale(&dec_1, 3);  // 12.345
  set_scale(&dec_2, 4);  // -3.4567
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_20) {
  s21_decimal dec_1 = {{12345, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{34567, 0, 0, 0}, 0};
  set_scale(&dec_1, 3);  // -12.345
  set_scale(&dec_2, 4);  // 3.4567
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_21) {
  s21_decimal dec_1 = {{0, 1, 12345, 0}, 0};
  s21_decimal dec_2 = {{0, 1, 12345, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 3);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_22) {
  s21_decimal dec_1 = {{0, 12345, 0, 0}, 0};
  s21_decimal dec_2 = {{0, 12345, 0, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 3);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_23) {
  s21_decimal dec_1 = {{0, 12345, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 34567, 0, 0}, 0};
  set_scale(&dec_1, 3);
  set_scale(&dec_2, 4);
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_24) {
  s21_decimal dec_1 = {{0, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{0, 0, 0, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_25) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{0, 0, 0, S21_MINUS}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_26) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, NEG_INF};
  s21_decimal dec_2 = {{1, 0, 0, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_27) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, NEG_INF};
  s21_decimal dec_2 = {{1, 0, 0, 0}, NEG_INF};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_28) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, INF};
  s21_decimal dec_2 = {{0, 0, 0, 0}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_29) {
  s21_decimal dec_1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec_2 = {{1, 1, 0, 0}, INF};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_is_less_30) {
  s21_decimal dec_1 = {{0, 0, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{1, 1, 0, S21_MINUS}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_is_less_31) {
  s21_decimal dec_1 = {{2, 2, 0, S21_MINUS}, 0};
  s21_decimal dec_2 = {{1, 1, 0, S21_MINUS}, 0};
  int result = s21_is_less(dec_1, dec_2);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *s21_is_less_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_is_less_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_is_less_1);
  tcase_add_test(tc_core, test_is_less_2);
  tcase_add_test(tc_core, test_is_less_3);
  tcase_add_test(tc_core, test_is_less_4);
  tcase_add_test(tc_core, test_is_less_5);
  tcase_add_test(tc_core, test_is_less_6);
  tcase_add_test(tc_core, test_is_less_7);
  tcase_add_test(tc_core, test_is_less_8);
  tcase_add_test(tc_core, test_is_less_9);
  tcase_add_test(tc_core, test_is_less_10);
  tcase_add_test(tc_core, test_is_less_11);
  tcase_add_test(tc_core, test_is_less_12);
  tcase_add_test(tc_core, test_is_less_13);
  tcase_add_test(tc_core, test_is_less_14);
  tcase_add_test(tc_core, test_is_less_15);
  tcase_add_test(tc_core, test_is_less_16);
  tcase_add_test(tc_core, test_is_less_17);
  tcase_add_test(tc_core, test_is_less_18);
  tcase_add_test(tc_core, test_is_less_19);
  tcase_add_test(tc_core, test_is_less_20);
  tcase_add_test(tc_core, test_is_less_21);
  tcase_add_test(tc_core, test_is_less_22);
  tcase_add_test(tc_core, test_is_less_23);
  tcase_add_test(tc_core, test_is_less_24);
  tcase_add_test(tc_core, test_is_less_25);
  tcase_add_test(tc_core, test_is_less_26);
  tcase_add_test(tc_core, test_is_less_27);
  tcase_add_test(tc_core, test_is_less_28);
  tcase_add_test(tc_core, test_is_less_29);
  tcase_add_test(tc_core, test_is_less_30);
  tcase_add_test(tc_core, test_is_less_31);

  suite_add_tcase(s, tc_core);

  return s;
}