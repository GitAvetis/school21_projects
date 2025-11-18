#include "s21_decimal.h"

int left_shift(s21_decimal *d) {
  int is_overflow = get_bit(*d, 95);

  for (int i = 95; i >= 0; i--) {
    if (i != 0) {
      set_bit(d, i, get_bit(*d, i - 1));
    } else {
      set_bit(d, i, 0);
    }
  }

  return is_overflow;
}

int right_shift(s21_decimal *d) {
  int is_overflow = get_bit(*d, 1);
  for (int i = 0; i <= 95; i++) {
    if (i != 95) {
      set_bit(d, i, get_bit(*d, i + 1));
    } else {
      set_bit(d, i, 0);
    }
  }

  return is_overflow;
}
