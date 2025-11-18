#include "tests.h"

// 123.3936050122
START_TEST(s21_round_1) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 2483027026;  // 0b10010011111100000001110001010010
  dec1.bits[1] = 288;         // 0b00000000000000000000000100100000
  dec1.bits[2] = 0;           // 0b00000000000000000000000000000000
  dec1.bits[3] = 655360;      // 0b00000000000010100000000000000000

  s21_decimal result;
  result.bits[0] = 124;  // 0b00000000000000000000000001111100
  result.bits[1] = 0;    // 0b00000000000000000000000000000000
  result.bits[2] = 0;    // 0b00000000000000000000000000000000
  result.bits[3] = 0;    // 0b00000000000000000000000000000000
  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

// Число 456.789 (больше 0.5)
START_TEST(s21_round_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 456789;  // 0b00000000000000000000000111011001
  dec1.bits[1] = 0;       // 0b00000000000000000000000000000000
  dec1.bits[2] = 0;       // 0b00000000000000000000000000000000
  dec1.bits[3] = 196608;  // 0b00000000000011000000000000000000

  s21_decimal result;
  result.bits[0] = 457;  // 0b00000000000000000000000111011001
  result.bits[1] = 0;    // 0b00000000000000000000000000000000
  result.bits[2] = 0;    // 0b00000000000000000000000000000000
  result.bits[3] = 0;    // 0b00000000000000000000000000000000

  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_round(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

// Число 123.456 (меньше 0.5)
START_TEST(s21_round_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 123456;  // 0b00000000000000011110001001000000
  dec1.bits[1] = 0;       // 0b00000000000000000000000000000000
  dec1.bits[2] = 0;       // 0b00000000000000000000000000000000
  dec1.bits[3] = 196608;  // 0b00000000000011000000000000000000 (scale = 3)

  s21_decimal result;
  result.bits[0] = 123;  // 0b00000000000000000000000001111011
  result.bits[1] = 0;    // 0b00000000000000000000000000000000
  result.bits[2] = 0;    // 0b00000000000000000000000000000000
  result.bits[3] = 0;    // 0b00000000000000000000000000000000 (scale = 0)

  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_round(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

// Число -78.89 (округление вниз)
START_TEST(s21_round_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 7889;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = 196608;

  s21_decimal result;
  result.bits[0] = 8;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;

  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_round(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

// Число 42
START_TEST(s21_round_5) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  dec1.bits[0] = 42;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = 0;

  s21_decimal result;
  result.bits[0] = 42;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;

  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_round(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

// 14.50
START_TEST(s21_round_6) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};

  dec1.bits[0] = 14500;   // 0b01100011000011111111111111111111
  dec1.bits[1] = 0;       // 0b01101011110001110101111000101101
  dec1.bits[2] = 0;       // 0b00000000000000000000000000000101
  dec1.bits[3] = 196608;  // 0b10000000000010100000000000000000
  s21_decimal result;
  result.bits[0] = 14;  // 0b01010100000010111110010000000000
  result.bits[1] = 0;   // 0b00000000000000000000000000000010
  result.bits[2] = 0;   // 0b00000000000000000000000000000000
  result.bits[3] = 0;   // 0b10000000000000000000000000000000
  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal dec1 = {{123, 0, 0, 0}, 0};
  set_scale(&dec1, 1);
  s21_decimal result = {{0, 0, 0, 0}, 0};

  s21_round(dec1, &result);
  ck_assert_float_eq(12, result.bits[0]);
}
END_TEST

Suite* test_s21_round(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("test_s21_round");
  tc = tcase_create("case_round");
  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_7);
  // tcase_add_test(tc, s21_round_7);
  // tcase_add_test(tc, s21_round_9);
  // tcase_add_test(tc, s21_round_10);
  // tcase_add_test(tc, s21_round_11);
  // tcase_add_test(tc, s21_round_12);
  // tcase_add_test(tc, s21_round_13);
  // tcase_add_test(tc, s21_roundTest1);
  // tcase_add_test(tc, s21_roundTest2);
  // tcase_add_test(tc, s21_roundTest3);
  // tcase_add_test(tc, s21_roundTest4);
  // tcase_add_test(tc, s21_roundTest5);
  // tcase_add_test(tc, s21_roundTest6);
  // tcase_add_test(tc, s21_roundTest7);
  // tcase_add_test(tc, s21_roundTest8);
  // tcase_add_test(tc, s21_roundTest9);
  // tcase_add_test(tc, s21_roundTest10);
  // tcase_add_test(tc, s21_roundTest11);
  // tcase_add_test(tc, s21_roundTest12);
  // tcase_add_test(tc, s21_roundTest13);
  // tcase_add_test(tc, s21_roundTest14);
  // tcase_add_test(tc, s21_roundTest15);

  suite_add_tcase(s, tc);
  return s;
}
