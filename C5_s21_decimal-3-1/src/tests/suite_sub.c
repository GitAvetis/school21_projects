#include "tests.h"

START_TEST(sub_0) {
  s21_decimal val1 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{2, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = {{2, 0, 0, 0}, 0};
  s21_decimal val2 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  s21_decimal val1 = {{2, 0, 0, 0}, 0};
  s21_decimal val2 = {{2, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_4) {
  s21_decimal val1 = {{8, 0, 0, 0}, 0};
  s21_decimal val2 = {{2, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_5) {
  s21_decimal val1 = {{2, 0, 0, 0}, 0};
  s21_decimal val2 = {{8, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_6) {
  s21_decimal val1 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{2, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_7) {
  s21_decimal val1 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{8, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_8) {
  s21_decimal val1 = {{2, 0, 0, 0}, 0};
  s21_decimal val2 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_9) {
  s21_decimal val1 = {{8, 0, 0, 0}, 0};
  s21_decimal val2 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_10) {
  s21_decimal val1 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_11) {
  s21_decimal val1 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{4, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_12) {
  s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal val2 = {{4, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_13) {
  s21_decimal val1 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_14) {
  s21_decimal val1 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_15) {
  s21_decimal val1 = {{4, 0, 0, 0}, 0};
  s21_decimal val2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_16) {
  s21_decimal val1 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_17) {
  s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal val2 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_18) {
  s21_decimal val1 = {{4, 0, 0, 0}, 0};
  s21_decimal val2 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_19) {
  s21_decimal val1 = {{4, 0, 0, 0}, 0};
  s21_decimal val2 = {{4, 0, 0, 0}, 0};
  s21_decimal res = {{0}, 0};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_20) {
  s21_decimal dec1 = {{0}, 0};
  s21_decimal dec2 = {{0}, 0};
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  s21_decimal res1 = {{0}, 0};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_21) {
  s21_decimal dec1 = {{0}, 0};
  s21_decimal dec2 = {{0}, 0};
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  s21_decimal res1 = {{0}, 0};
  int res = 99899;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_22) {
  s21_decimal value_1 = {{13, 0, 0, 0}, 0};
  set_scale(&value_1, 1);
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}, 0};
  set_scale(&value_2, 2);
  set_sign(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{156, 0, 0, 0}, 0};
  set_scale(&check, 2);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_23) {
  s21_decimal value_1 = {{13, 0, 0, 0}, 0};
  set_scale(&value_1, 1);
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}, 0};
  set_scale(&value_2, 2);
  s21_decimal result = {0};
  s21_decimal check = {{416, 0, 0, 0}, 0};
  set_scale(&check, 2);
  set_sign(&check, 1);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_24) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}, 0};
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}, 0};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}, 0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(sub_25) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}, 0};
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}, 0};
  set_sign(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}, 0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(sub_26) {
  s21_decimal value_1 = {{64071, 0, 0, 0}, 0};
  set_scale(&value_1, 4);
  s21_decimal value_2 = {{5919, 0, 0, 0}, 0};
  set_scale(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{5854929, 0, 0, 0}, 0};
  set_scale(&check, 4);
  set_sign(&check, 1);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

// START_TEST(sub_27) {
//   s21_decimal src1 = {0}, src2 = {0};
//   float a = -9403;
//   float b = 202.098;
//   float res_our_dec = 0.0;
//   s21_from_float_to_decimal(a, &src1);
//   s21_from_float_to_decimal(b, &src2);
//   float res_origin = a - b;
//   s21_decimal res_od = {0};
//   s21_sub(src1, src2, &res_od);
//   s21_from_decimal_to_float(res_od, &res_our_dec);
//   ck_assert_float_eq(res_our_dec, res_origin);
// }
// END_TEST

// START_TEST(sub_test_11) {
//   int num1 = 123;
//   float num2 = 12.5;
//   float origin_float = 110.5;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_int_to_decimal(num1, &a);
//   s21_from_float_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, origin_float);
// }
// END_TEST

// START_TEST(sub_test_12) {
//   int num1 = -123;
//   float num2 = 12.5;
//   float dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_int_to_decimal(num1, &a);
//   s21_from_float_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_14) {
//   int num1 = 9403;
//   float num2 = 202.098;
//   float dif_float = 9200.902;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_int_to_decimal(num1, &a);
//   s21_from_float_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_15) {
//   int num1 = -9403;
//   float num2 = 202.098;
//   float dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_int_to_decimal(num1, &a);
//   s21_from_float_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_16) {
//   float num1 = 9403.0;
//   float num2 = 202.09e8;
//   float dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_float_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_17) {
//   float num1 = 9403.0e2;
//   float num2 = 202.09e8;
//   float dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_float_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_18) {
//   float num1 = -9403.0e2;
//   int num2 = -202;
//   float dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_int_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_19) {
//   float num1 = -94;
//   float num2 = -202;
//   float dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_int_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_20) {
//   float num1 = -1.0 / 0.0;
//   int num2 = 202;
//   double dif_float = 0 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_int_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_21) {
//   float num1 = 1.0 / 0.0;
//   int num2 = 20;
//   double dif_float = 0 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_int_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

START_TEST(s21_sub_int_22) {
  s21_decimal dec1 = {{0}, 0};
  s21_decimal dec2 = {{0}, 0};
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  s21_decimal res1 = {{0}, 0};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_23) {
  s21_decimal dec1 = {{0}, 0};
  s21_decimal dec2 = {{0}, 0};
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = 99899;
  s21_decimal res1 = {{0}, 0};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_24) {
  s21_decimal dec1 = {{0}, 0};
  s21_decimal dec2 = {{0}, 0};
  int tmp1 = -2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}, 0};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_25) {
  s21_decimal dec1 = {{0}, 0};
  s21_decimal dec2 = {{0}, 0};
  int tmp1 = -214748347;
  int tmp2 = 217483647;
  int res_s21 = 0;
  int res = -214748347 - 217483647;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}, 0};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_26) {
  s21_decimal dec1 = {{0}, 0};
  s21_decimal dec2 = {{0}, 0};
  int tmp1 = 214748347;
  int tmp2 = -217483647;
  int res_s21 = 0;
  int res = 214748347 - -217483647;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}, 0};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_inf_27) {
  float tmp = pow(2, 31);
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, 0}, 0};
  s21_decimal dec2 = {{1, 0, 0, tmp}, 0};
  s21_decimal res1 = {{0}, 0};
  int ret_s21 = s21_sub(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(s21_sub_neg_inf_28) {
  float tmp = pow(2, 31);
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, tmp}, 0};
  s21_decimal dec2 = {{1, 0, 0, 0}, 0};
  s21_decimal res1 = {{0}, 0};
  int ret_s21 = s21_sub(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST

Suite *suite_sub(void) {
  Suite *s = suite_create("suite_sub");
  TCase *tc = tcase_create("log_tc");

  tcase_add_test(tc, sub_0);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);
  tcase_add_test(tc, sub_14);
  tcase_add_test(tc, sub_15);
  tcase_add_test(tc, sub_16);
  tcase_add_test(tc, sub_17);
  tcase_add_test(tc, sub_18);
  tcase_add_test(tc, sub_19);
  tcase_add_test(tc, sub_20);
  tcase_add_test(tc, sub_21);
  tcase_add_test(tc, sub_22);
  tcase_add_test(tc, sub_23);
  tcase_add_test(tc, sub_24);
  tcase_add_test(tc, sub_25);
  tcase_add_test(tc, sub_26);
  //   tcase_add_test(tc, sub_27);
  //   tcase_add_test(tc, sub_test_11);
  //   tcase_add_test(tc, sub_test_12);
  //   tcase_add_test(tc, sub_test_14);
  //   tcase_add_test(tc, sub_test_15);
  //   tcase_add_test(tc, sub_test_16);
  //   tcase_add_test(tc, sub_test_17);
  //   tcase_add_test(tc, sub_test_18);
  //   tcase_add_test(tc, sub_test_19);
  //   tcase_add_test(tc, sub_test_20);
  //   tcase_add_test(tc, sub_test_21);
  tcase_add_test(tc, s21_sub_int_22);
  tcase_add_test(tc, s21_sub_int_23);
  tcase_add_test(tc, s21_sub_int_24);
  tcase_add_test(tc, s21_sub_int_25);
  tcase_add_test(tc, s21_sub_int_26);
  tcase_add_test(tc, s21_sub_inf_27);
  tcase_add_test(tc, s21_sub_neg_inf_28);

  suite_add_tcase(s, tc);
  return s;
}
