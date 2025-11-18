#include "s21_decimal.h"
#define MAX_DECIMAL 79228162514264337593543950336.0
#define MASK_EXP 2139095040
#define MASK_INT 8388607
#define MASK_SIGN 2147483648

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = 1;

  if (src.bits[1] == 0 && src.bits[2] == 0) {
    *dst = src.bits[0];

    if (get_sign(src)) {
      *dst *= -1;
    }

    *dst /= (int)pow(10, get_scale(src));

    status = 0;
  }

  return status;
}

// инт перевсти в ансайт
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
  dst->value_type = NormalValue;

  set_scale(dst, 0);
  if (src < 0) {
    set_sign(dst, 1);
    src *= -1;
  }
  dst->bits[0] = (unsigned int)src;

  return 0;
}
int count_front_zeros_in_f_part(float f) {
  int counter_of_zeros = -1;
  if (f != 0.0) {
    while (!(int)f) {
      f *= 10;
      counter_of_zeros++;
    }
  }

  return counter_of_zeros;
}
void more_then_seven_nums_rounding(s21_decimal *decimal_for_int,
                                   s21_decimal *mult,
                                   int counter_of_digits_in_int_part) {
  int num_of_zeros = counter_of_digits_in_int_part - 7;
  set_scale(decimal_for_int, num_of_zeros);
  s21_bank_round(*decimal_for_int, decimal_for_int, 0);
  mult->bits[0] = pow(10, num_of_zeros);
  s21_mul(*decimal_for_int, *mult, decimal_for_int);
}
void getting_int_part_by_exp(int *scale, float src, unsigned int *int_part,
                             s21_decimal *decimal_for_int, s21_decimal *mult,
                             s21_decimal *decimal_for_div) {
  const uint32_t *float_as_bits =
      (uint32_t *)&src;  // считываем число как набор битов
  int exp = ((*float_as_bits & MASK_EXP) >> 23) - 127;
  unsigned int mantissa = (*float_as_bits & MASK_INT) |
                          (1 << 23);  // к мантиссе добавляется неявная единица
  if (exp > 0 && exp <= 23) {
    *scale = 8;
    *int_part = mantissa >> (23 - exp);  // выделяем  целую часть
    decimal_for_int->bits[0] = *int_part;
    for (int i = 0; i < 4; i++) {  // нужно для подсчёта цифр в целой части
      decimal_for_div->bits[i] = decimal_for_int->bits[i];
    }  // записываем в decimal_for_int целую часть, умноженную на 10^sacle
    s21_mul(*decimal_for_int, *mult, decimal_for_int);
  } else if ((int)exp <= 0) {
    if (exp == 0) decimal_for_int->bits[0] = 1;
    int f_counter_of_zeros = count_front_zeros_in_f_part(src - *int_part);
    *scale = 8 + f_counter_of_zeros;  // если есть нули сразу после запятой
  } else if ((int)exp > 23) {
    int num_of_shifts =
        exp - 23;  // на сколько сдвинуться, чтобы получить целую часть
    *int_part = mantissa;
    decimal_for_int->bits[0] = mantissa;
    while (num_of_shifts--) {
      left_shift(decimal_for_int);
    }
    for (int i = 0; i < 4; i++) {
      decimal_for_div->bits[i] = decimal_for_int->bits[i];
    }
  }
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int function_result_code = 0;  // 0 - OK, 1 - ERROR

  s21_decimal decimal_for_float = {{0}, 0};  // под целую часть исходного числа
  s21_decimal decimal_for_int = {{0}, 0};  // под дробную часть исходного числа
  s21_decimal decimal_for_div = {
      {0}, 0};  // временная переменная используемая в делении
  s21_decimal decimal_zero = {{0}, 0};           // для сравнения с нулём
  s21_decimal mult = {{100000000, 0, 0, 0}, 0};  // для операций умножения

  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
  dst->value_type = NormalValue;

  if (isinf(src) || isnan(src) || fabsf(src) > MAX_DECIMAL) {
    function_result_code = 1;
  } else {
    int scale = 0;
    int sign = 0;
    if (src < 0) {  // если число отрицательное - инвертируем его
      src *= -1;
      sign = 1;
    }
    unsigned int int_part = 0;
    int counter_of_digits_in_int_part = 0;
    getting_int_part_by_exp(
        &scale, src, &int_part, &decimal_for_int, &mult,
        &decimal_for_div);  // в зависимости от экспаненты получаем scale и
                            // целую часть числа
    while (!s21_is_equal(decimal_for_div, decimal_zero)) {
      divide_by_10(&decimal_for_div);
      counter_of_digits_in_int_part++;
    }  // если целая часть больше нуля, то считаем количество цифр в этом числе
    if (counter_of_digits_in_int_part > 7) {  // если цифр больше семи, то
                                              // округляем  до 7 значимых цифр
      more_then_seven_nums_rounding(&decimal_for_int, &mult,
                                    counter_of_digits_in_int_part);
    } else {
      decimal_for_float.bits[0] =
          (src - int_part) * pow(10, (scale));  // считаем дробную часть
    }
    s21_add(decimal_for_float, decimal_for_int, dst);
    set_sign(dst, sign);
    set_scale(dst, scale);
    s21_bank_round(*dst, dst, scale - 1 - counter_of_digits_in_int_part);
    kill_zeros_in_scale(dst);
  }
  return function_result_code;
}
int main() {
  float a = 1234.5678f;
  s21_decimal decimal_for_float = {{0}, 0};
  s21_from_float_to_decimal(a, &decimal_for_float);
  print_decimal(decimal_for_float);
  print_int(decimal_for_float);
}
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0;
  unsigned int *p = (unsigned int *)dst;

  int exponent = 0;
  int sign = get_sign(src);

  // убираем знак, чтобы избежать ошибок
  set_sign(&src, 0);

  // Находим целую часть децимала
  s21_decimal integer_part = {{0, 0, 0, 0}, 0};
  s21_truncate(src, &integer_part);
  // print_decimal(integer_part);
  // print_int(integer_part);

  s21_decimal fractional_part = {{0, 0, 0, 0}, 0};
  s21_sub(src, integer_part, &fractional_part);
  int correct_scale = get_scale(fractional_part);
  set_scale(&fractional_part, 0);

  // print_decimal(fractional_part);
  // print_int(fractional_part);

  // уменьшаем целую часть до 24 бит
  while (get_size(integer_part) > 24) {
    right_shift(&integer_part);
    exponent++;
  }

  int free_bits = 24 - get_size(integer_part);
  // printf("free_bits = %d\n", free_bits);
  exponent += get_size(integer_part) - 1;

  // подготавливаем дробную часть под флоат
  // оставляем только 7 цифр в дробной части (банковское округление)
  while (get_size(fractional_part) > 32 ||
         fractional_part.bits[0] > 999999999) {
    // divide_by_10(&fractional_part);
    set_scale(&fractional_part, 1);
    s21_bank_round(fractional_part, &fractional_part, 0);
    correct_scale = 9;
  }

  // print_decimal(fractional_part);
  // print_int(fractional_part);

  double f_part = (int)fractional_part.bits[0] / pow(10, correct_scale);
  // printf("fractional_part.bits[0] = %d\n", fractional_part.bits[0]);
  // printf("correct_scale = %d\n", correct_scale);
  // printf("f_part = %lf\n", f_part);

  // конвертируем дробную часть в биты
  unsigned int frac_to_float = 0;
  for (int i = 0; i < free_bits + 1; i++) {
    f_part *= 2;
    // printf("f_part = %lf\n", f_part);
    if (f_part > 1) {
      f_part -= 1;
      frac_to_float = (frac_to_float << 1) | 1;
    } else {
      frac_to_float = (frac_to_float << 1);
    }
  }
  // уменьшаем погрешность
  int correction_mask = (frac_to_float & 1) << 1;
  frac_to_float = (frac_to_float | correction_mask) >> 1;

  // если целой части нет, то надо сдвинуть дробную
  if (exponent == -1) {
    int mask = 0x800000;  // 10000000 00000000 00000000
    while ((frac_to_float & mask) >> 23 == 0) {
      frac_to_float = frac_to_float << 1;
      exponent--;
    }
  }

  // printf("frac_to_float = %u\n", frac_to_float);
  // printf("exponent = %d\n", exponent);

  // перемещаем интовые биты на правильную позицию
  integer_part.bits[0] = integer_part.bits[0] << free_bits;
  // print_decimal(integer_part);
  // print_int(integer_part);

  // Записываем мантису во флоат и удаляем 24 бит
  *p = (*p | integer_part.bits[0] | frac_to_float) & ~(1 << 23);

  // integer_part.bits[0] = *p;
  // print_decimal(integer_part);
  // print_int(integer_part);

  // Готовим и записываем экспоненту
  exponent += 127;
  *p = *p | (exponent << 23);

  // записываем во флоат знак
  *p = *p | (sign << 31);
  return 0;
}