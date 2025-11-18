#include "tests.h"

START_TEST(test_truncate_1) {
  s21_decimal dec_1 = {{15555, 0, 0, 0}, 0};  // 1.5555
  set_scale(&dec_1, 4);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{1, 0, 0, 0}, 0};  // 1

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_2) {
  s21_decimal dec_1 = {{15555, 0, 0, S21_MINUS}, 0};  // -1.5555
  set_scale(&dec_1, 4);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{1, 0, 0, S21_MINUS}, 0};  // -1

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_3) {
  s21_decimal dec_1 = {{S21_MAX_UINT, 0, 0, 0}, 0};  // 4 294.967295
  set_scale(&dec_1, 6);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{4294, 0, 0, 0}, 0};  // 4294

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_4) {
  s21_decimal dec_1 = {{0, S21_MAX_UINT, 0, 0},
                       0};  // +1 844 674 406.9414584320
  set_scale(&dec_1, 10);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{1844674406, 0, 0, 0}, 0};  // +1 844 674 406

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_5) {
  s21_decimal dec_1 = {{0, 0, S21_MAX_UINT, 0},
                       0};  // +79 228 162 495 817 593.519 834 398 720
  set_scale(&dec_1, 12);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{298133369, 18446744, 0, 0},
                        0};  // +79 228 162 495 817 593

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_6) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_7) {
  s21_decimal dec_1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0},
                       0};  // +7.9 228 162 514 264 337 593 543 950 335
  set_scale(&dec_1, 28);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{7, 0, 0, 0}, 0};

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_8) {
  s21_decimal dec_1 = {{1879048192, 3003322535, 3794707603, 0},
                       0};  // +70.000 000 000 000 000 000 000 000 000
  set_scale(&dec_1, 27);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{70, 0, 0, 0}, 0};

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_9) {
  s21_decimal dec_1 = {{1879048192, 3003322535, 3794707603, S21_MINUS},
                       0};  // -70.000 000 000 000 000 000 000 000 000
  set_scale(&dec_1, 27);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{70, 0, 0, S21_MINUS}, 0};  // -70

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_10) {
  s21_decimal dec_1 = {{1879048193, 3003322535, 3794707603, S21_MINUS},
                       0};  // -70.000 000 000 000 000 000 000 000 001
  set_scale(&dec_1, 27);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{70, 0, 0, S21_MINUS}, 0};  // -70

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_11) {
  s21_decimal dec_1 = {{1879048193, 3003322535, 3794707603, 0},
                       0};  // +70.000 000 000 000 000 000 000 000 001
  set_scale(&dec_1, 27);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{70, 0, 0, 0}, 0};  // +70

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

START_TEST(test_truncate_12) {
  s21_decimal dec_1 = {{12345, 0, 0, S21_MINUS}, 0};
  set_scale(&dec_1, 3);
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{12, 0, 0, S21_MINUS}, 0};

  s21_truncate(dec_1, &result);

  ck_assert_int_eq(s21_is_equal(result, etalon), 1);
}
END_TEST

Suite *s21_truncate_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_truncate_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_truncate_1);
  tcase_add_test(tc_core, test_truncate_2);
  tcase_add_test(tc_core, test_truncate_3);
  tcase_add_test(tc_core, test_truncate_4);
  tcase_add_test(tc_core, test_truncate_5);
  tcase_add_test(tc_core, test_truncate_6);
  tcase_add_test(tc_core, test_truncate_7);
  tcase_add_test(tc_core, test_truncate_8);
  tcase_add_test(tc_core, test_truncate_9);
  tcase_add_test(tc_core, test_truncate_10);
  tcase_add_test(tc_core, test_truncate_11);
  tcase_add_test(tc_core, test_truncate_12);

  suite_add_tcase(s, tc_core);

  return s;
}