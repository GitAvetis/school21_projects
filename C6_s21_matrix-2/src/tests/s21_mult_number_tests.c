#include "tests.h"

START_TEST(test_s21_mult_number_1) {
  matrix_t matr1;
  int number = 2;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}, {2.0, 3.0, 4.0}};
  double _result[3][3] = {{2.0, 4.0, 6.0}, {0.0, 8.0, 4.0}, {4.0, 6.0, 8.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_mult_number(&matr1, number, &matr_my_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  matrix_t matr1;
  int number = 2;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 0.0, 3.0}, {0.0, 0.0, 2.0}, {2.0, 0.0, 4.0}};
  double _result[3][3] = {{2.0, 0.0, 6.0}, {0.0, 0.0, 4.0}, {4.0, 0.0, 8.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_mult_number(&matr1, number, &matr_my_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
  matrix_t matr1;
  double number = 2.5;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}, {2.0, 3.0, 4.0}};
  double _result[3][3] = {{2.5, 5.0, 7.5}, {0.0, 10.0, 5.0}, {5.0, 7.5, 10.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_mult_number(&matr1, number, &matr_my_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
  matrix_t matr1;
  double number = 2.113;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}, {2.0, 3.0, 4.0}};
  double _result[3][3] = {
      {2.113, 4.226, 6.339}, {0.0, 8.452, 4.226}, {4.226, 6.339, 8.452}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_mult_number(&matr1, number, &matr_my_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_mult_number_5) {
  matrix_t matr1;
  double number = 2.111;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.1, 2.2, 3.3}, {0.0, 4.4, 2.2}, {2.2, 3.3, 4.4}};
  double _result[3][3] = {{2.3221, 4.6442, 6.9663},
                          {0.0, 9.2884, 4.6442},
                          {4.6442, 6.9663, 9.2884}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_mult_number(&matr1, number, &matr_my_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

Suite *s21_mult_number_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_mult_number_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_mult_number_1);
  tcase_add_test(tc_core, test_s21_mult_number_2);
  tcase_add_test(tc_core, test_s21_mult_number_3);
  tcase_add_test(tc_core, test_s21_mult_number_4);
  tcase_add_test(tc_core, test_s21_mult_number_5);

  suite_add_tcase(s, tc_core);

  return s;
}
