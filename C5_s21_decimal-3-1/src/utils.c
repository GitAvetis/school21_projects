#include <math.h>

#include "s21_decimal.h"

int get_bit(s21_decimal d, int index) {
  unsigned int index_sign_mask = 1u << (index % 32);
  return (d.bits[index / 32] & index_sign_mask) > 0;
}

void set_bit(s21_decimal *d, int index, int value) {
  unsigned int index_sign_mask = 1u << (index % 32);
  if (value) {
    d->bits[index / 32] |= index_sign_mask;
  } else {
    d->bits[index / 32] &= ~index_sign_mask;
  }
}

int get_sign(s21_decimal d) {
  unsigned int index_sign_mask = 1u << 31;
  return (index_sign_mask & d.bits[3]) > 0;
}

void set_sign(s21_decimal *d, int value) {
  unsigned int index_sign_mask = 1u << 31;
  if (value) {
    d->bits[3] |= index_sign_mask;
  } else {
    d->bits[3] &= ~index_sign_mask;
  }
}

void clear_sign(s21_decimal *d) {
  unsigned int index_sign_mask = 1u << 31;
  d->bits[3] &= ~index_sign_mask;
}

int get_scale(s21_decimal d) {
  unsigned int index_scale_mask = 255 << 16;
  return (d.bits[3] & index_scale_mask) >> 16u;
}

void set_scale(s21_decimal *d, int scale) {
  int minus = get_sign(*d);
  d->bits[3] = 0;
  d->bits[3] = (unsigned int)scale << 16;
  set_sign(d, minus);
}

void print_decimal(s21_decimal d) {
  for (int i = 95; i >= 0; i--) {
    printf("%d", get_bit(d, i));
    if (i % 8 == 0) printf("  ");
  }
  printf("sign = %c", get_sign(d) == 0 ? '+' : '-');
  printf("  scale = %d", get_scale(d));
  printf("\n");
}

void divide_by_10(s21_decimal *dec) {
  // printf("\n Enter to divide_by_10\n");
  // заводим переменную для сохранения остатка
  uint64_t remainder = 0;
  for (int i = 2; i >= 0; i--) {
    // добавляем к нашему биту остаток от деления при прошлой операции
    uint64_t value = (remainder << 32) | dec->bits[i];
    dec->bits[i] = (unsigned int)(value / 10);
    // printf("\n dec->bits[%d] = %u\n", i, dec->bits[i]);
    //  сохраняем остаток от деления
    remainder = value % 10;
  }
}

void print_int(s21_decimal d) {
  char numbers[100] = {0};
  int index = 0;
  int scale = get_scale(d);
  char sign = get_sign(d) == 0 ? '+' : '-';

  while (d.bits[0] != 0 || d.bits[1] != 0 || d.bits[2] != 0) {
    int reminder = remainder_by_10(d);
    numbers[index] = reminder + '0';
    divide_by_10(&d);
    index++;
  }
  if (index == 0)
    printf("%c0", sign);
  else {
    int flag = 1;
    index--;
    printf("%c", sign);
    if (scale > index) {
      printf("0,");
      flag = 0;
      while (scale > index + 1) {
        printf("0");
        scale--;
      }
    }
    for (int i = index; i >= 0; i--) {
      if (scale == i + 1 && flag) printf(",");
      if ((i + 1 - scale) % 3 == 0 && i > scale && i + 1 != index) {
        printf(" ");
      }
      printf("%c", numbers[i]);
    }
  }
  printf("\n");
}

int check_for_nonzero_after(s21_decimal decimal) {
  s21_decimal temp = decimal;
  int flag = 0;

  int scale = get_scale(temp);  // 4
  int no_zero = 0;
  int scale_nn = scale - 1;
  for (int i = 0; i < scale_nn; i++) {
    int odin_element = remainder_by_10(temp);
    if (odin_element != 0) {  // есть элемент
      no_zero = 1;
      flag = 1;
    }
    if (odin_element == 0 && no_zero == 0) {  // элементы нули
      flag = 0;
    }
    divide_by_10(&temp);
  }
  return flag;
}

// определяет четное или нечетное число
int is_even(s21_decimal decimal) { return (decimal.bits[0] & 1) == 0; }

int is_zero(s21_decimal decimal) {
  for (int i = 0; i < 3; i++) {
    if (decimal.bits[i] != 0) {
      return 0;
    }
  }
  return 1;
}

void kill_zeros_in_scale(s21_decimal *dec) {
  while (get_scale(*dec) > 0 && remainder_by_10(*dec) == 0) {
    divide_by_10(dec);
    set_scale(dec, get_scale(*dec) - 1);
  }
}

// функция устанавливает  0 или 1, если после кстановленного z_scale
// смотрит есть лм после числа еще не 0 элементы
//  z_scale=1   6,5001 -> после 5 есть элемент ф-я возращает 1
//  z_scale=1   6,5000 -> после 5 нулевые ф-я возращает 0
int b_check_banck_for_nonzero_after(s21_decimal decimal, int z_scale) {
  s21_decimal temp = decimal;
  int flag = 0;

  int scale = get_scale(temp);     // 2
  int scale_nn = scale - z_scale;  // 1
  for (int i = 0; i < scale_nn; i++) {
    int no_zero = 0;
    int odin_element = remainder_by_10(temp);
    if (odin_element != 0) {  // есть элемент
      no_zero = 1;
      flag = 1;
    }
    if (odin_element == 0 && no_zero == 0) {  // элементы нули
      flag = 0;
    }
    divide_by_10(&temp);
  }
  return flag;
}

int s21_bank_round(s21_decimal value, s21_decimal *result, int z_scale) {
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
  int has_nonzero_after_remainder =
      b_check_banck_for_nonzero_after(temp_decimal, z_scale);

  int remainder = 0;
  int resalt_del_scale = scale - z_scale;
  for (int i = 0; i < resalt_del_scale; i++) {
    if (resalt_del_scale - 1 == i) {
      remainder = remainder_by_10(temp_decimal);
    }
    divide_by_10(&temp_decimal);
  }
  if (remainder >= 5) {
    if (remainder == 5 && has_nonzero_after_remainder == 1 &&
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
  set_scale(result, z_scale);

  return 0;
}

int remainder_by_10(s21_decimal dec) {
  // заводим переменную для сохранения остатка
  uint64_t remainder = 0;
  for (int i = 2; i >= 0; i--) {
    // добавляем к нашему биту остаток от деления при прошлой операции
    uint64_t value = (remainder << 32) | dec.bits[i];
    // сохраняем остаток от деления
    remainder = value % 10;
  }
  return (int)remainder;
}

void s21_normalize(s21_decimal *num1, s21_decimal *num2) {
  int first_scale = get_scale(*num1);
  int second_scale = get_scale(*num2);

  int difference = abs(first_scale - second_scale);
  s21_decimal multiplier = {{10, 0, 0, 0}, 0};
  s21_decimal *target = (first_scale > second_scale) ? num2 : num1;

  int target_scale = get_scale(*target);

  for (int i = 0; i < difference; i++) {
    if (target_scale < 28 && !s21_simple_mul(*target, multiplier, target)) {
      set_scale(target, ++target_scale);
    } else {
      // my_bank_round((first_scale > second_scale) ? num1 : num2,
      // target_scale);
      s21_bank_round((first_scale > second_scale) ? *num1 : *num2,
                     (first_scale > second_scale) ? num1 : num2, target_scale);
      break;
    }
  }
}
