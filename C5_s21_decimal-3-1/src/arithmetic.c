#include "s21_decimal.h"
#define S21_MAX_UINT 0xffffffff
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  value_1.value_type = 0;
  value_2.value_type = 0;
  int cod_errors = NormalValue;
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
  result->value_type = NormalValue;
  int overlod = 0;
  int sign1 = get_sign(value_1);
  int sign2 = get_sign(value_2);
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  s21_normalize(&value_1, &value_2);
  int scale_posle_normaliz = get_scale(value_1);
  if (!(sign1 ^ sign2)) {
    overlod = s21_add_simple(value_1, value_2, result);
    set_sign(result, sign1);
    if (overlod && sign1 && sign2) {
      cod_errors = NEG_INF;
      result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
      result->value_type = NormalValue;
      set_sign(result, 1);
    } else if (overlod && !sign1 && !sign2) {
      cod_errors = INF;
      result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
      result->value_type = NormalValue;
    }
  } else {
    if (s21_is_less_or_equal(value_1, value_2)) {
      s21_simple_sub(value_2, value_1, result);
      set_sign(result, sign2);
    } else {
      s21_simple_sub(value_1, value_2, result);
      set_sign(result, sign1);
    }
  }

  if (overlod && get_scale(value_1)) {
    s21_bank_round(value_1, &value_1, 1);
    s21_bank_round(value_2, &value_2, 1);
    s21_add(value_1, value_2, result);
  } else
    set_scale(result, scale_posle_normaliz);

  return cod_errors;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int cod_errors = NormalValue;
  if (get_sign(value_2)) {
    set_sign(&value_2, 0);
  } else {
    set_sign(&value_2, 1);
  }
  cod_errors = s21_add(value_1, value_2, result);
  return cod_errors;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign1 = get_sign(value_1);
  int sign2 = get_sign(value_2);
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  int cod_errors = NormalValue;
  int first_scale = get_scale(value_1);
  int second_scale = get_scale(value_2);
  s21_decimal temp = {{0, 0, 0, 0}, 0};
  s21_decimal temp_value_1 = value_1;
  s21_decimal temp_value_2 = value_2;
  s21_decimal value_2_with_no_scale = value_2;
  set_scale(&value_2_with_no_scale, 0);
  set_scale(&temp_value_1, 0);
  set_scale(&temp_value_2, 0);
  s21_decimal ten = {{10, 0, 0, 0}, 0};
  s21_decimal zero_value = {{0, 0, 0, 0}, 0};
  if (!s21_is_equal(value_2, zero_value)) {
    s21_simple_div(&temp_value_1, &temp_value_2, &temp);
    int current_scale = 0;
    int number_of_perebors = 0;
    while (!s21_is_equal(temp_value_1, zero_value) && current_scale < 28) {
      s21_simple_mul(temp_value_1, ten, &temp_value_1);
      s21_decimal temp_ost = {{0, 0, 0, 0}, 0};
      temp_value_2 = value_2_with_no_scale;
      s21_simple_div(&temp_value_1, &temp_value_2, &temp_ost);
      if (s21_simple_mul(temp, ten, &temp)) number_of_perebors++;
      s21_add(temp, temp_ost, &temp);
      current_scale++;
    }
    set_scale(&temp, abs(current_scale - second_scale - first_scale -
                         number_of_perebors));
    if (sign1 ^ sign2) {
      s21_negate(temp, &temp);
    }
  } else {
    cod_errors = NotANumber;
  }
  *result = temp;
  return cod_errors;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int cod_errors = NormalValue;
  int is_overload = 0;
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
  result->value_type = NormalValue;
  int first_scale = get_scale(value_1);
  int second_scale = get_scale(value_2);
  int sum_of_scales = first_scale + second_scale;

  is_overload = s21_simple_mul(value_1, value_2, result);
  if (is_overload && (get_sign(value_1) | get_sign(value_1))) {
    if (get_sign(value_1) && get_sign(value_2)) {
      cod_errors = INF;
    } else
      cod_errors = NEG_INF;
  } else if (is_overload && !(get_sign(value_1) | get_sign(value_1))) {
    cod_errors = INF;
  }

  set_scale(result, sum_of_scales);

  if (get_sign(value_1) ^ get_sign(value_2)) {
    s21_negate(*result, result);
  }

  return cod_errors;
}

// int main(){
//   s21_decimal dec1 = {{1000000000,0,0,0},0};
//   s21_decimal dec2 = {{10,0,0,0},0};
//   set_sign(&dec1, 1);
//   // set_sign(&dec2, 1);
//   print_int(dec1);
//   print_int(dec2);
//   // set_scale(&dec2, 28);
//   // set_scale(&dec1, 28);
//   // int tmp1 = -100;
//   // int tmp2 = -99999;
//   // float res_s21 = 0;
//   // float res = 0.00100001;
//   // s21_from_int_to_decimal(tmp1, &dec1);
//   // s21_from_int_to_decimal(tmp2, &dec2);
//   // print_decimal(dec1);
//   // print_decimal(dec2);
//   s21_decimal res1;
//   s21_div(dec1, dec2, &res1);
//   print_decimal(res1);
//   print_int(res1);
//   // s21_from_decimal_to_float(res1, &res_s21);
// }
