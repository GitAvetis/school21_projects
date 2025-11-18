#include "tests.h"

START_TEST(test_s21_determinant_1) {
  matrix_t matr1;
  double result = 0;
  double my_result = 0;
  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  s21_create_matrix(3, 3, &matr1);
  fill_matrix(&matr1, _matr1);
  s21_determinant(&matr1, &my_result);

  ck_assert_double_eq_tol(result, my_result, 0.0000001);
  s21_remove_matrix(&matr1);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t matr1;
  double result = -27;
  double my_result = 0;
  double _matr1[3][3] = {{10.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  s21_create_matrix(3, 3, &matr1);
  fill_matrix(&matr1, _matr1);
  s21_determinant(&matr1, &my_result);

  ck_assert_double_eq_tol(result, my_result, 0.0000001);
  s21_remove_matrix(&matr1);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t matr1;
  double result = -405;
  double my_result = 0;
  double _matr1[3][3] = {{10.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 0.0}};

  s21_create_matrix(3, 3, &matr1);
  fill_matrix(&matr1, _matr1);
  s21_determinant(&matr1, &my_result);

  ck_assert_double_eq_tol(result, my_result, 0.0000001);
  s21_remove_matrix(&matr1);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  matrix_t matr1;
  double result = 72;
  double my_result = 0;
  double _matr1[3][3] = {{-23.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  s21_create_matrix(3, 3, &matr1);
  fill_matrix(&matr1, _matr1);
  s21_determinant(&matr1, &my_result);

  ck_assert_double_eq_tol(result, my_result, 0.0000001);
  s21_remove_matrix(&matr1);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t matr1;
  double result = 0;
  double my_result = 0;
  double _matr1[3][3] = {{1.5, 2.5, 3.5}, {4.5, 5.5, 6.5}, {7.5, 8.5, 9.5}};

  s21_create_matrix(3, 3, &matr1);
  fill_matrix(&matr1, _matr1);
  s21_determinant(&matr1, &my_result);

  ck_assert_double_eq_tol(result, my_result, 0.0000001);
  s21_remove_matrix(&matr1);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  matrix_t matr1;
  double result = -18;
  double my_result = 0;
  double _matr1[3][3] = {{7.5, 2.5, 3.5}, {4.5, 5.5, 6.5}, {7.5, 8.5, 9.5}};

  s21_create_matrix(3, 3, &matr1);
  fill_matrix(&matr1, _matr1);
  s21_determinant(&matr1, &my_result);

  ck_assert_double_eq_tol(result, my_result, 0.0000001);
  s21_remove_matrix(&matr1);
}
END_TEST

Suite *s21_determinant_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_determinant_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_determinant_1);
  tcase_add_test(tc_core, test_s21_determinant_2);
  tcase_add_test(tc_core, test_s21_determinant_3);
  tcase_add_test(tc_core, test_s21_determinant_4);
  tcase_add_test(tc_core, test_s21_determinant_5);
  tcase_add_test(tc_core, test_s21_determinant_6);

  suite_add_tcase(s, tc_core);

  return s;
}
