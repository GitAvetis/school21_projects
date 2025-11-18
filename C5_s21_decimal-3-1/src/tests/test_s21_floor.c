#include "tests.h"

START_TEST(s21_floor_1) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 165;    // 0b00000000000000000000000010100101
  dec1.bits[1] = 0;      // 0b00000000000000000000000000000000
  dec1.bits[2] = 0;      // 0b00000000000000000000000000000000
  dec1.bits[3] = 65536;  // 0b00000000000000010000000000000000

  s21_decimal result = {{0, 0, 0, 0}, 0};
  result.bits[0] = 16;  // 0b00000000000000000000000000010000
  result.bits[1] = 0;   // 0b00000000000000000000000000000000
  result.bits[2] = 0;   // 0b00000000000000000000000000000000
  result.bits[3] = 0;   // 0b00000000000000000000000000000000
  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_floor(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 165;    // 0b00000000000000000000000010100101
  dec1.bits[1] = 0;      // 0b00000000000000000000000000000000
  dec1.bits[2] = 0;      // 0b00000000000000000000000000000000
  dec1.bits[3] = 65536;  // 0b00000000000000010000000000000000

  s21_decimal result = {{0, 0, 0, 0}, 0};
  result.bits[0] = 16;  // 0b00000000000000000000000000010000
  result.bits[1] = 0;   // 0b00000000000000000000000000000000
  result.bits[2] = 0;   // 0b00000000000000000000000000000000
  result.bits[3] = 0;   // 0b00000000000000000000000000000000
  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_floor(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 105;  // 0b00000000000000000000000001101001
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = 65536;  // scale = 1 (0b00000000000000010000000000000000)

  s21_decimal result = {{0, 0, 0, 0}, 0};
  result.bits[0] = 10;  // 0b00000000000000000000000000001010
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;

  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_floor(dec1, &res1);

  ck_assert_uint_eq(res1.bits[0], result.bits[0]);
  ck_assert_uint_eq(res1.bits[1], result.bits[1]);
  ck_assert_uint_eq(res1.bits[2], result.bits[2]);
  ck_assert_uint_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 10;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = 0;

  s21_decimal result = {{0, 0, 0, 0}, 0};
  result.bits[0] = 10;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;

  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_floor(dec1, &res1);

  ck_assert_uint_eq(res1.bits[0], result.bits[0]);
  ck_assert_uint_eq(res1.bits[1], result.bits[1]);
  ck_assert_uint_eq(res1.bits[2], result.bits[2]);
  ck_assert_uint_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_5) {
  s21_decimal dec1 = {{12345, 0, 0, S21_MINUS}, 0};
  set_scale(&dec1, 3);
  s21_decimal result = {{13, 0, 0, S21_MINUS}, 0};
  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_floor(dec1, &res1);

  ck_assert_uint_eq(1, s21_is_equal(res1, result));
}
END_TEST

Suite *test_s21_floor(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("test_s21_floor");
  tc = tcase_create("case_floor");
  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_5);
  // tcase_add_test(tc, s21_floor_5);
  // tcase_add_test(tc, s21_floor_6);
  // tcase_add_test(tc, s21_floor_7);
  // tcase_add_test(tc, s21_floor_8);
  // tcase_add_test(tc, s21_floor_9);
  // tcase_add_test(tc, s21_floor_10);
  // tcase_add_test(tc, s21_floor_11);
  // tcase_add_test(tc, s21_floorTest1);
  // tcase_add_test(tc, s21_floorTest2);
  // tcase_add_test(tc, s21_floorTest4);
  // tcase_add_test(tc, s21_floorTest6);
  // tcase_add_test(tc, s21_floorTest7);
  // tcase_add_test(tc, s21_floorTest8);
  // tcase_add_test(tc, s21_floorTest9);
  // tcase_add_test(tc, s21_floorTest10);
  // tcase_add_test(tc, s21_floorTest11);

  // tcase_add_test(tc, test_floor_1);
  // tcase_add_test(tc, test_floor_2);
  // tcase_add_test(tc, test_floor_5);
  // tcase_add_test(tc, test_floor_6);
  suite_add_tcase(s, tc);
  return s;
}
