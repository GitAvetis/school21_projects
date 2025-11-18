#include "tests.h"

START_TEST(test_s21_calc_complements_1) {
  matrix_t matr1;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}, {5.0, 2.0, 1.0}};
  double _result[3][3] = {
      {0.0, 10.0, -20.0}, {4.0, -14.0, 8.0}, {-8.0, -2.0, 4.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr_result, _result);

  s21_calc_complements(&matr1, &matr_my_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t matr1;
  matrix_t matr_my_result;

  double _matr1[2][3] = {{1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}};

  s21_create_matrix(2, 3, &matr1);

  fill_matrix(&matr1, _matr1);

  int result = s21_calc_complements(&matr1, &matr_my_result);

  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&matr1);
}
END_TEST

Suite *s21_calc_complements_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_calc_complements_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_calc_complements_1);
  tcase_add_test(tc_core, test_s21_calc_complements_2);

  suite_add_tcase(s, tc_core);

  return s;
}
