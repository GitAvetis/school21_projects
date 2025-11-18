#include "s21_decimal.h"

int s21_add_simple(s21_decimal value1, s21_decimal value2,
                   s21_decimal *result) {
  int rank = 0;
  for (size_t i = 0; i < 96; i++) {
    set_bit(result, i, 0);
  }

  for (size_t i = 0; i < 96; i++) {
    int bit1 = get_bit(value1, i);
    int bit2 = get_bit(value2, i);
    set_bit(result, i, bit1 ^ bit2 ^ rank);
    rank = (bit1 && bit2) || (bit1 && rank) || (bit2 && rank);
  }
  return rank;
}

void s21_simple_sub(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
  result->value_type = NormalValue;
  for (int i = 0; i < 96; i++) {
    int bit1 = get_bit(value_1, i);
    int bit2 = get_bit(value_2, i);
    set_bit(result, i, bit1 ^ bit2);
    if (!bit1 && bit2) {
      int k = i + 1;
      while ((bit1 = get_bit(value_1, k)) != 1) {
        set_bit(&value_1, k, 1);
        k++;
      }
      set_bit(&value_1, k, 0);
    }
  }
}

int s21_simple_mul(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int is_overfull = 0;
  s21_decimal temp = {{0}, 0};
  for (int i = 0; i < 96 && !is_overfull; i++) {
    if (get_bit(value_2, i) == 1) {
      s21_decimal temp_result = value_1;

      for (int t = 0; t < i; t++) {
        if (left_shift(&temp_result)) {
          is_overfull = 1;
          break;
        }
      }

      if (is_overfull ||
          (is_overfull = s21_add_simple(temp_result, temp, &temp))) {
        break;
      }
    }
  }

  if (!is_overfull) *result = temp;

  return is_overfull;
}

int s21_simple_div(s21_decimal *value_1, s21_decimal *value_2,
                   s21_decimal *result) {
  s21_decimal src_value_2 = *value_2;

  int first_size = get_size(*value_1);
  int second_size = get_size(*value_2);
  int dif_size = first_size - second_size;

  for (int i = 0; i < dif_size; i++) {
    left_shift(value_2);
  }
  while (1) {
    if (s21_is_greater_or_equal(*value_1, *value_2)) {
      s21_sub(*value_1, *value_2, value_1);
      set_bit(result, 0, 1);
    } else {
      set_bit(result, 0, 0);
    }

    right_shift(value_2);
    if (s21_is_less(*value_2, src_value_2)) {
      break;
    } else {
      left_shift(result);
    }
  }

  return 0;
}

int get_size(s21_decimal num) {
  int size = 0;

  for (int i = 95; i >= 0; i--) {
    if (get_bit(num, i) == 1) {
      size = i + 1;
      break;
    }
  }

  return size;
}
