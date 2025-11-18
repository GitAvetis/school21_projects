#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NormalValue = 0,
  INF = 1,
  NEG_INF = 2,
  NotANumber = 3
} value_type_t;

typedef struct {
  unsigned int bits[4];
  value_type_t value_type;

} s21_decimal;

/*                    Арифметические операторы

Функции возвращают код ошибки:
0 — OK;
1 — число слишком велико или равно бесконечности;
2 — число слишком мало или равно отрицательной бесконечности;
3 — деление на 0.
Уточнение про числа, не вмещающиеся в мантиссу:

При получении чисел, не вмещающихся в мантиссу при арифметических операциях,
используй банковское округление
(например, 79,228,162,514,264,337,593,543,950,335 — 0.6
= 79,228,162,514,264,337,593,543,950,334).

*/

/// @brief Сложение
/// @param value_1
/// @param value_2
/// @param result
/// @return
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/// @brief Вычитание
/// @param value_1
/// @param value_2
/// @param result
/// @return
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/// @brief Умножение
/// @param value_1
/// @param value_2
/// @param result
/// @return
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/// @brief Деление
/// @param value_1
/// @param value_2
/// @param result
/// @return
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*          Операторы сравнения

Возвращаемое значение:

0 — FALSE;
1 — TRUE.

*/

/// @brief Меньше
/// @param dec_left число в формате децимал
/// @param dec_right число в формате децимал
/// @return Возвращаемое значение 0 — FALSE 1 — TRUE
int s21_is_less(s21_decimal, s21_decimal);

/// @brief Меньше или равно
/// @param dec_left число в формате децимал
/// @param dec_right число в формате децимал
/// @return Возвращаемое значение 0 — FALSE 1 — TRUE
int s21_is_less_or_equal(s21_decimal, s21_decimal);

/// @brief Больше
/// @param dec_left число в формате децимал
/// @param dec_right число в формате децимал
/// @return Возвращаемое значение 0 — FALSE 1 — TRUE
int s21_is_greater(s21_decimal, s21_decimal);

/// @brief Больше или равно
/// @param dec_left число в формате децимал
/// @param dec_right число в формате децимал
/// @return Возвращаемое значение 0 — FALSE 1 — TRUE
int s21_is_greater_or_equal(s21_decimal, s21_decimal);

/// @brief Равно
/// @param dec_left число в формате децимал
/// @param dec_right число в формате децимал
/// @return Возвращаемое значение 0 — FALSE 1 — TRUE
int s21_is_equal(s21_decimal, s21_decimal);

/// @brief Не равно
/// @param dec_left число в формате децимал
/// @param dec_right число в формате децимал
/// @return Возвращаемое значение 0 — FALSE 1 — TRUE
int s21_is_not_equal(s21_decimal, s21_decimal);

/*          Преобразователи

Возвращаемое значение — код ошибки:

0 — OK;
1 — ошибка конвертации.

Уточнение про преобразование числа типа float:

-- Если числа слишком малы (0 < |x| < 1e-28),
    возвращай ошибку и значение, равное 0.
-- Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335)
     или равны бесконечности, возвращай ошибку.
-- При обработке числа с типом float преобразовывай все содержащиеся в нём
     значимые десятичные цифры. Если таких цифр больше 7, то значение числа
     должно округляться к ближайшему, у которого не больше 7 значимых цифр.

Уточнение про преобразование из числа типа decimal в тип int:

-- Если в числе типа decimal есть дробная часть, то её следует
     отбросить (например, 0.9 преобразуется 0).

*/

/// @brief Из int
/// @param src число, которое мы хотим конвертировать
/// @param dst указатель на массив s21_decimal
/// @return число в decimal
int s21_from_int_to_decimal(int src, s21_decimal *dst);

/// @brief Из float
/// @param src
/// @param dst
/// @return
int s21_from_float_to_decimal(float src, s21_decimal *dst);

/// @brief В int
/// @param src
/// @param dst
/// @return
int s21_from_decimal_to_int(s21_decimal src, int *dst);

/// @brief В float
/// @param src
/// @param dst
/// @return
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/*          Другие функции

Возвращаемое значение — код ошибки:

0 — OK;
1 — ошибка вычисления.
 */

/// @brief Округляет указанное Decimal число до ближайшего целого числа в
/// сторону отрицательной бесконечности.
/// @param value
/// @param result
/// @return
int s21_floor(s21_decimal value, s21_decimal *result);

/// @brief Округляет Decimal до ближайшего целого числа.
/// @param value
/// @param result
/// @return Возвращаемое значение — код ошибки 0 — OК 1 — ошибка вычисления.
int s21_round(s21_decimal value, s21_decimal *result);

/// @brief Возвращает целые цифры указанного Decimal числа; любые дробные цифры
/// отбрасываются, включая конечные нули.
/// @param value
/// @param result
/// @return
int s21_truncate(s21_decimal value, s21_decimal *result);

/// @brief Возвращает результат умножения указанного Decimal на -1.
/// @param value
/// @param result
/// @return
int s21_negate(s21_decimal value, s21_decimal *result);

/*          Вспомогательные функции

Нужны для работы общих функций

*/

/// @brief позволяет посмотреть чему равен конкретный бит у числа
/// @param d число в формате децимал
/// @param i индекс бита, который мы хотим получить
/// @return возвращает 0 или 1 в зависимости от значения бита
int get_bit(s21_decimal d, int index);

/// @brief устанавливает значание конкретного бита в числе
/// @param d число в формате децимал
/// @param index индекс бита, который мы хотим установить
/// @param value 0 или 1 значение в которое установить бит
void set_bit(s21_decimal *d, int index, int value);

/// @brief позволяет посмотреть знак числа
/// @param d число в формате децимал
/// @return 0 - плюс, 1 - минус
int get_sign(s21_decimal d);

/// @brief позволяет установить знак числа
/// @param d число в формате децимал
/// @param value 0 - плюс, 1 - минус
void set_sign(s21_decimal *d, int value);

/// @brief очищает знак числа (убирает минус)
/// @param d число в формате децимал
void clear_sign(s21_decimal *d);

/// @brief показывает степень числа
/// @param d число в формате децимал
/// @return возвращает степень числа
int get_scale(s21_decimal d);

/// @brief устанавливает степень числа
/// @param d число в формате децимал
/// @param scale степень числа (от 0 до 28)
void set_scale(s21_decimal *d, int scale);

/// @brief выводит в консоль децимал
/// @param d число в формате децимал
void print_decimal(s21_decimal d);

/// @brief выводит в консоль число в десятичном представлении
/// @param d число в формате децимал
void print_int(s21_decimal d);

/// @brief отбрасывает лишние нули после запятой
/// @param dec число в формате децимал
/// @example dec_normalize(s21_decimal *dec)
void kill_zeros_in_scale(s21_decimal *dec);

/// @brief находит остаток от деления на 10 (scale не учитывается)
/// @param dec число в формате децимал
/// @return возвращает остаток от деления в 10-ном представлении
int remainder_by_10(s21_decimal dec);

/// @brief целочисленное деление на десять. Scale не учитывается и не меняется.
/// Делаем это вне функции!!!
/// @param dec число в формате децимал
void divide_by_10(s21_decimal *dec);

/// @brief находит первые левые биты двух чисел, которые различаются
/// @param dec_left левый децимал
/// @param dec_right правый децимал
/// @param bit_left бит левого децимала
/// @param bit_right бит правого децимала
/// @return возвращает 1 если все биты одинаковые
int simple_comparsion(s21_decimal dec_left, s21_decimal dec_right,
                      int *bit_left, int *bit_right);

int s21_add_simple(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int s21_simple_mul(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
int left_shift(s21_decimal *d);
int is_zero(s21_decimal decimal);
int s21_bank_round(s21_decimal value, s21_decimal *result, int z_scale);
int check_for_nonzero_after(s21_decimal decimal);
int is_even(s21_decimal decimal);
void s21_simple_sub(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
int s21_simple_div(s21_decimal *value_1, s21_decimal *value_2,
                   s21_decimal *result);
int right_shift(s21_decimal *d);
void s21_normalize(s21_decimal *num1, s21_decimal *num2);

/// @brief Отбрасывает нули слева и считает количество оставшихся битов
/// @param num число в формате децимал
/// @return количество битов без нулей слева
int get_size(s21_decimal num);

// int is_zero(s21_decimal dec);

#endif
