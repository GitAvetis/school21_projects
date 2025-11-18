#include "tests.h"

START_TEST(test_s21_sub_matrix_1) {
  matrix_t matr1;
  matrix_t matr2;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  double _matr2[3][3] = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  double _result[3][3] = {{0.0, 1.0, 2.0}, {3.0, 4.0, 5.0}, {6.0, 7.0, 8.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);
  s21_create_matrix(3, 3, &matr_result);
  // s21_create_matrix(3, 3, &matr_my_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr2, _matr2);
  fill_matrix(&matr_result, _result);

  s21_sub_matrix(&matr1, &matr2, &matr_my_result);

  // print_matrix(matr_my_result);
  // print_matrix(matr_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t matr1;
  matrix_t matr2;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  double _matr2[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  double _result[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);
  s21_create_matrix(3, 3, &matr_result);
  // s21_create_matrix(3, 3, &matr_my_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr2, _matr2);
  fill_matrix(&matr_result, _result);

  s21_sub_matrix(&matr1, &matr2, &matr_my_result);

  // print_matrix(matr_my_result);
  // print_matrix(matr_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  matrix_t matr1;
  matrix_t matr2;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {
      {10.0, 20.0, 30.0}, {40.0, 50.0, 60.0}, {70.0, 80.0, 90.0}};
  double _matr2[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  double _result[3][3] = {
      {9.0, 18.0, 27.0}, {36.0, 45.0, 54.0}, {63.0, 72.0, 81.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);
  s21_create_matrix(3, 3, &matr_result);
  // s21_create_matrix(3, 3, &matr_my_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr2, _matr2);
  fill_matrix(&matr_result, _result);

  s21_sub_matrix(&matr1, &matr2, &matr_my_result);

  // print_matrix(matr_my_result);
  // print_matrix(matr_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_4) {
  matrix_t matr1;
  matrix_t matr2;
  matrix_t matr_my_result;
  matrix_t matr_result;

  double _matr1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  double _matr2[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  double _result[3][3] = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};

  s21_create_matrix(3, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);
  s21_create_matrix(3, 3, &matr_result);
  // s21_create_matrix(3, 3, &matr_my_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr2, _matr2);
  fill_matrix(&matr_result, _result);

  s21_sub_matrix(&matr1, &matr2, &matr_my_result);

  // print_matrix(matr_my_result);
  // print_matrix(matr_result);

  int result = s21_eq_matrix(&matr_my_result, &matr_result);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  s21_remove_matrix(&matr_my_result);
  s21_remove_matrix(&matr_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_5) {
  matrix_t matr1;
  matrix_t matr2;
  matrix_t matr_my_result;

  double _matr1[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
  double _matr2[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  s21_create_matrix(2, 3, &matr1);
  s21_create_matrix(3, 3, &matr2);
  // s21_create_matrix(3, 3, &matr_my_result);

  fill_matrix(&matr1, _matr1);
  fill_matrix(&matr2, _matr2);

  int result = s21_sub_matrix(&matr1, &matr2, &matr_my_result);

  // print_matrix(matr_my_result);
  // print_matrix(matr_result);

  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&matr1);
  s21_remove_matrix(&matr2);
  // s21_remove_matrix(&matr_my_result);
}
END_TEST

Suite *s21_sub_matrix_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sub_matrix_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sub_matrix_1);
  tcase_add_test(tc_core, test_s21_sub_matrix_2);
  tcase_add_test(tc_core, test_s21_sub_matrix_3);
  tcase_add_test(tc_core, test_s21_sub_matrix_4);
  tcase_add_test(tc_core, test_s21_sub_matrix_5);

  suite_add_tcase(s, tc_core);

  return s;
}
