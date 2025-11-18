#include "tests.h"

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t matr1;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{2.0, 5.0, 7.0}, {6.0, 3.0, 4.0}, {5.0, -2.0, -3.0}};
  double _result[3][3] = {
      {1.0, -1.0, 1.0}, {-38.0, 41.0, -34.0}, {27.0, -29.0, 24.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_inverse_matrix(&matr1, &matr_my_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t matr1;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 4.0, 4.0}, {5.0, 7.0, 7.0}};
  double _result[3][3] = {
      {0.0, 0.875, -0.5}, {-1.0, -1.0, 1.0}, {1.0, 0.375, -0.5}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_inverse_matrix(&matr1, &matr_my_result);
  // print_matrix(matr_my_result);
  // print_matrix(matr_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t matr1;
  matrix_t matr_my_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 4.0, 4.0}, {5.0, 6.0, 7.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_my_result);

  fill_matrix(&matr1, _matr1);

  s21_inverse_matrix(&matr1, &matr_my_result);

  int result = s21_inverse_matrix(&matr1, &matr_my_result);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
  matrix_t matr1;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{3.0, 2.0, 2.0}, {3.0, 3.0, 2.0}, {3.0, 1.0, 1.0}};
  double _result[3][3] = {
      {-0.3333333, 0.0, 0.6666666}, {-1.0, 1.0, 0.0}, {2.0, -1.0, -1.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_inverse_matrix(&matr1, &matr_my_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

Suite *s21_inverse_matrix_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_inverse_matrix_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_inverse_matrix_1);
  tcase_add_test(tc_core, test_s21_inverse_matrix_2);
  tcase_add_test(tc_core, test_s21_inverse_matrix_3);
  tcase_add_test(tc_core, test_s21_inverse_matrix_4);

  suite_add_tcase(s, tc_core);

  return s;
}
