#include "s21_decimal.h"

int s21_is_less(s21_decimal dec_left, s21_decimal dec_right) {
  int flag = 0;

  // Проверка на краевые случаи
  if (dec_left.value_type != NormalValue ||
      dec_right.value_type != NormalValue) {
    if (dec_left.value_type == NEG_INF && (dec_right.value_type != NotANumber &&
                                           dec_right.value_type != NEG_INF)) {
      flag = 1;
    } else if (dec_right.value_type == INF &&
               dec_left.value_type == NormalValue) {
      flag = 1;
    }
  } else if (is_zero(dec_left) && is_zero(dec_right))
    flag = 0;
  else if (get_sign(dec_left) == 0 && get_sign(dec_right) == 1) {
    flag = 0;
  } else if (get_sign(dec_left) == 1 && get_sign(dec_right) == 0) {
    flag = 1;
  } else {
    // сохраняем значения первых различающихся битов слева
    int bit_left = get_bit(dec_left, 95);
    int bit_right = get_bit(dec_right, 95);
    simple_comparsion(dec_left, dec_right, &bit_left, &bit_right);

    // в зависимости от знака определяем какое число больше
    if (get_sign(dec_left) == 1 && get_sign(dec_right) == 1) {
      if (bit_left > bit_right)
        flag = 1;
      else
        flag = 0;

    } else {
      if (bit_left < bit_right)
        flag = 1;
      else
        flag = 0;
    }
  }
  return flag;
}

int s21_is_less_or_equal(s21_decimal dec_left, s21_decimal dec_right) {
  int flag = 0;

  if (dec_left.value_type != NormalValue ||
      dec_right.value_type != NormalValue) {
    if (dec_left.value_type == NEG_INF &&
        (dec_right.value_type != NotANumber)) {
      flag = 1;
    } else if (dec_right.value_type == INF &&
               dec_left.value_type != NotANumber) {
      flag = 1;
    }
  } else if (is_zero(dec_left) && is_zero(dec_right))
    flag = 1;
  else if (get_sign(dec_left) == 0 && get_sign(dec_right) == 1) {
    flag = 0;
  } else if (get_sign(dec_left) == 1 && get_sign(dec_right) == 0) {
    flag = 1;
  } else {
    // сохраняем значения первых различающихся битов слева
    int bit_left = get_bit(dec_left, 95);
    int bit_right = get_bit(dec_right, 95);
    simple_comparsion(dec_left, dec_right, &bit_left, &bit_right);

    // в зависимости от знака определяем какое число больше
    if (get_sign(dec_left) == 1 && get_sign(dec_right) == 1) {
      if (bit_left >= bit_right)
        flag = 1;
      else
        flag = 0;

    } else {
      if (bit_left <= bit_right)
        flag = 1;
      else
        flag = 0;
    }
  }
  return flag;
}

int s21_is_greater(s21_decimal dec_left, s21_decimal dec_right) {
  int flag = 0;

  if (dec_left.value_type != NormalValue ||
      dec_right.value_type != NormalValue) {
    if (dec_left.value_type == INF &&
        (dec_right.value_type != NotANumber && dec_right.value_type != INF)) {
      flag = 1;
    } else if (dec_right.value_type == NEG_INF &&
               (dec_left.value_type != NotANumber &&
                dec_left.value_type != NEG_INF)) {
      flag = 1;
    }
  } else if (is_zero(dec_left) && is_zero(dec_right))
    flag = 0;
  else if (get_sign(dec_left) == 0 && get_sign(dec_right) == 1) {
    flag = 1;
  } else if (get_sign(dec_left) == 1 && get_sign(dec_right) == 0) {
    flag = 0;
  } else {
    // сохраняем значения первых различающихся битов слева
    int bit_left = get_bit(dec_left, 95);
    int bit_right = get_bit(dec_right, 95);
    simple_comparsion(dec_left, dec_right, &bit_left, &bit_right);

    // в зависимости от знака определяем какое число больше
    if (get_sign(dec_left) == 1 && get_sign(dec_right) == 1) {
      if (bit_left < bit_right)
        flag = 1;
      else
        flag = 0;

    } else {
      if (bit_left > bit_right)
        flag = 1;
      else
        flag = 0;
    }
  }
  return flag;
}

int s21_is_greater_or_equal(s21_decimal dec_left, s21_decimal dec_right) {
  int flag = 0;

  if (dec_left.value_type != NormalValue ||
      dec_right.value_type != NormalValue) {
    if (dec_left.value_type == INF && (dec_right.value_type != NotANumber)) {
      flag = 1;
    } else if (dec_right.value_type == NEG_INF &&
               (dec_left.value_type != NotANumber)) {
      flag = 1;
    }
  } else if (is_zero(dec_left) && is_zero(dec_right))
    flag = 1;
  else if (get_sign(dec_left) == 0 && get_sign(dec_right) == 1) {
    flag = 1;
  } else if (get_sign(dec_left) == 1 && get_sign(dec_right) == 0) {
    flag = 0;
  } else {
    // сохраняем значения первых различающихся битов слева
    int bit_left = get_bit(dec_left, 95);
    int bit_right = get_bit(dec_right, 95);
    simple_comparsion(dec_left, dec_right, &bit_left, &bit_right);

    // в зависимости от знака определяем какое число больше
    if (get_sign(dec_left) == 1 && get_sign(dec_right) == 1) {
      if (bit_left <= bit_right)
        flag = 1;
      else
        flag = 0;

    } else {
      if (bit_left >= bit_right)
        flag = 1;
      else
        flag = 0;
    }
  }
  return flag;
}

int s21_is_equal(s21_decimal dec_left, s21_decimal dec_right) {
  int flag = 0;

  // Проверка на краевые случаи
  if (dec_left.value_type != NormalValue ||
      dec_right.value_type != NormalValue) {
    if ((dec_left.value_type == INF && dec_right.value_type == INF) ||
        (dec_left.value_type == NEG_INF && dec_right.value_type == NEG_INF)) {
      flag = 1;
    }
  }
  // если нули, то равны
  else if (is_zero(dec_left) && is_zero(dec_right))
    flag = 1;
  // когда одинаковый знак, то истина
  else if (!(get_sign(dec_left) ^ get_sign(dec_right))) {
    // сохраняем значения первых различающихся битов слева
    int bit_left = get_bit(dec_left, 95);
    int bit_right = get_bit(dec_right, 95);
    flag = simple_comparsion(dec_left, dec_right, &bit_left, &bit_right);
  }
  return flag;
}

int s21_is_not_equal(s21_decimal dec_left, s21_decimal dec_right) {
  return !s21_is_equal(dec_left, dec_right);
}

int simple_comparsion(s21_decimal dec_left, s21_decimal dec_right,
                      int* bit_left, int* bit_right) {
  int is_equal = 0;

  // пытаемся нормализовать скейл
  s21_normalize(&dec_left, &dec_right);

  int index = 95;
  *bit_left = get_bit(dec_left, index);
  *bit_right = get_bit(dec_right, index);

  while (index > 0 && *bit_left == 0 && *bit_right == 0) {
    index--;
    *bit_left = get_bit(dec_left, index);
    *bit_right = get_bit(dec_right, index);
  }

  while (index > 0 && ((*bit_left == 0 && *bit_right == 0) ||
                       (*bit_left == 1 && *bit_right == 1))) {
    index--;
    *bit_left = get_bit(dec_left, index);
    *bit_right = get_bit(dec_right, index);
  }

  // если дошли до конца и биты равны, то числа одинаковые
  if (index == 0 && *bit_left == *bit_right) is_equal = 1;

  return is_equal;
}
