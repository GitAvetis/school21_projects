#include "s21_decimal.h"

// Функция для округления числа
int s21_round(s21_decimal value, s21_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
  result->value_type = NormalValue;
  int scale = get_scale(value);
  if (scale == 0) {
    *result = value;
    return 0;
  }
  s21_decimal temp_decimal = value;
  int sign_decimal = get_sign(temp_decimal);
  clear_sign(&temp_decimal);
  int remainder = 0;
  int has_nonzero_after_remainder = check_for_nonzero_after(temp_decimal);
  if (scale == 1) {
    remainder = remainder_by_10(temp_decimal);
    for (int i = 0; i < scale; i++) {
      divide_by_10(&temp_decimal);
    }
  } else {
    for (int i = 0; i < scale; i++) {
      divide_by_10(&temp_decimal);
      if ((scale - 2) == i) {
        remainder = remainder_by_10(temp_decimal);
      }
    }
  }

  if (remainder >= 5) {
    if (remainder == 5 && has_nonzero_after_remainder != 1 &&
        is_even(temp_decimal)) {
      *result = temp_decimal;
    } else {
      s21_decimal one = {{1, 0, 0, 0}, 0};
      s21_add_simple(temp_decimal, one, result);
    }
  } else {
    *result = temp_decimal;
  }
  if (sign_decimal) {
    set_sign(result, 1);
  }
  set_scale(result, 0);
  return 0;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
  result->value_type = NormalValue;
  int scale = get_scale(value);

  if (scale == 0) {
    *result = value;
    return 0;
  }
  s21_decimal temp_decimal = value;
  int sign_decimal = get_sign(temp_decimal);
  clear_sign(&temp_decimal);

  if (sign_decimal == 1) {
    int has_nonzero_after_remainder = check_for_nonzero_after(temp_decimal);
    for (int i = 0; i < scale; i++) {
      divide_by_10(&temp_decimal);
    }
    if (has_nonzero_after_remainder == 1) {
      s21_decimal one = {{1, 0, 0, 0}, 0};
      s21_add_simple(temp_decimal, one, result);
    } else {
      *result = temp_decimal;
    }
  } else {
    for (int i = 0; i < scale; i++) {
      divide_by_10(&temp_decimal);
    }
    *result = temp_decimal;
  }

  if (sign_decimal) {
    set_sign(result, 1);
  }
  set_scale(result, 0);
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = 0;

  while (get_scale(value) > 0) {
    divide_by_10(&value);
    set_scale(&value, get_scale(value) - 1);
  }
  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  result->bits[3] = value.bits[3];
  result->value_type = value.value_type;
  return flag;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;

  int sign = get_sign(*result);

  if (sign == 1)
    set_sign(result, 0);
  else
    set_sign(result, 1);

  return 0;
}
