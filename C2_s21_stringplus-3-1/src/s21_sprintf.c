#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  // сохраняем указатель для запис
  char *p = str;

  // помогает нам работать с аргументами функции
  va_list args;
  va_start(args, format);
  // пример получения целого числа: int value = va_arg(args, int);
  fill_str(&p, format, &args);

  // не забываем очистить память макроса
  va_end(args);

  // возвращаем количество записанных символов в строку
  return p - str;
}

void fill_str(char **p, const char *format, va_list *args) {
  char *pfr = (char *)format;
  while (*pfr != '\0') {
    if (*pfr == '%') {
      // перескакиваем на следующий символ после %
      pfr++;
      if (*pfr == '%') {
        **p = *pfr;
        *p += 1;
        pfr += 1;
      } else {
        //  обрабатываем часть строки после %
        cook_format_params(p, &pfr, args);
      }
      //  после парсинга указатель pfr должен указывать на символ после
      //  форматного ввода
      //  например в строке "цена = %d$" *ptr должен равняться $.
    } else {
      // записываем в нашу основную строку символ и двигаем указатели на 1
      **p = *pfr;
      *p += 1;
      pfr += 1;
    }
  }
  // в конец строки пишем терминирующий 0
  **p = '\0';
}

void cook_format_params(char **p, char **pfr, va_list *args) {
  format_conf fconf = {0};
  char to_output[2048] = {0};
  fconf.precision = -1;
  fill_struct(pfr, &fconf);
  switch (fconf.type) {
    case 'c':
      spec_c(&fconf, args, to_output);
      break;

    case 'd':
      spec_d(args, to_output, &fconf);
      break;

    case 's':
      spec_s(args, to_output, &fconf);
      break;

    case 'f':
      spec_f(args, to_output, &fconf);
      break;

    case 'u':
      spec_u(args, to_output, &fconf);
      break;

      // case '%':
      //   *to_output = '%';
      //   break;

    default:
      break;
  }

  copy(p, to_output);
}

void fill_struct(char **pfr, format_conf *fconf) {
  flag_check(pfr, fconf);
  width_check(pfr, fconf);
  precision_check(pfr, fconf);
  len_check(pfr, fconf);
  type_check(pfr, fconf);
}

void flag_check(char **check, format_conf *fconf) {
  const char *all_flags = "+- 0#";
  while (s21_strchr(all_flags, **check)) {
    switch (**check) {
      case '-':
        fconf->minus = true;
        *check += 1;
        break;

      case '+':
        fconf->plus = true;
        *check += 1;
        break;

      case '0':
        fconf->zero = true;
        *check += 1;
        break;

        // case '#':
        //   fconf->scharp = true;
        //   *check += 1;
        //   break;

      case ' ':
        fconf->space = true;
        *check += 1;
        break;

      default:
        break;
    }
  }
}

void width_check(char **check, format_conf *fconf) {
  const char *all_digits = "0123456789";

  if (s21_strchr(all_digits, **check)) {
    int result = 0;
    while (s21_strchr(all_digits, **check)) {
      result = result * 10 + (**check - '0');
      *check += 1;
    }
    fconf->width = result;
  }
}

void precision_check(char **check, format_conf *fconf) {
  if (**check == '.') {
    *check += 1;
    const char *all_digits = "0123456789";
    int result = 0;
    while (s21_strchr(all_digits, **check)) {
      result = result * 10 + (**check - '0');
      *check += 1;
    }
    fconf->precision = result;
  }
}

// Нужно проверить реализацию и поменять если что то пойдет не так
void len_check(char **check, format_conf *fconf) {
  const char *all_len = "lLh";
  while (s21_strchr(all_len, **check)) {
    fconf->len = **check;
    *check += 1;
  }
}

void type_check(char **check, format_conf *fconf) {
  const char *all_types = "cdfsugGeExXop";
  const char *type_char = s21_strchr(all_types, **check);
  if (type_char) {
    fconf->type = type_char[0];
    *check += 1;
  } else {
    fconf->bug_suc = true;
  }
}

void itoa(long int value, char *buffer, int base) {
  int i = 0;
  int is_negative = 0;

  if (value < 0 && base == 10) {
    is_negative = 1;
    value = -value;
  }

  do {
    int digit = value % base;
    buffer[i++] = (digit < 10) ? ('0' + digit) : ('a' + (digit - 10));
    value /= base;
  } while (value > 0);

  if (is_negative) {
    buffer[i++] = '-';
  }
  buffer[i] = '\0';

  for (int j = 0, k = i - 1; j < k; j++, k--) {
    char temp = buffer[j];
    buffer[j] = buffer[k];
    buffer[k] = temp;
  }
}

void long_u_itoa(s21_size_t value, char *buffer, int base) {
  int i = 0;
  do {
    int digit = value % base;
    buffer[i++] = (digit < 10) ? ('0' + digit) : ('a' + (digit - 10));
    value /= base;
  } while (value > 0);

  buffer[i] = '\0';

  for (int j = 0, k = i - 1; j < k; j++, k--) {
    char temp = buffer[j];
    buffer[j] = buffer[k];
    buffer[k] = temp;
  }
}

void copy(char **dest, const char *src) {
  while (*src) {
    **dest = *src;
    *dest += 1;
    src += 1;
  }
  **dest = '\0';
}

void spec_s(va_list *args, char *to_out, format_conf *fconf) {
  char *val = va_arg(*args, char *);
  char with_psecision[256];
  int len = (int)s21_strlen(val);
  int otstup =
      fconf->width -
      (len < fconf->precision || fconf->precision < 0 ? len : fconf->precision);

  char *ch = with_psecision;
  if (fconf->precision >= 0) {
    for (int i = 0; i < fconf->precision; i++) {
      *ch = *val;
      ch += 1;
      val += 1;
    }
    *ch = '\0';
  } else {
    copy(&ch, val);
  }

  if (fconf->minus == false) {
    print_white_spaces(&to_out, fconf->zero ? '0' : ' ', otstup);

    copy(&to_out, with_psecision);
  } else {
    copy(&to_out, with_psecision);
    print_white_spaces(&to_out, fconf->zero ? '0' : ' ', otstup);
  }
}

void spec_d(va_list *args, char *to_out, const format_conf *fconf) {
  char num_str[100];
  int is_negative = 0;
  int len = 0;
  if (fconf->len == 'l') {
    long int val = (long int)va_arg(*args, long int);
    itoa(val, num_str, 10);
    is_negative = val < 0;
  } else if (fconf->len == 'h') {
    short int val = (short int)va_arg(*args, int);
    itoa(val, num_str, 10);
    is_negative = val < 0;
  } else {
    int val = va_arg(*args, int);
    itoa(val, num_str, 10);
    is_negative = val < 0;
  }

  len = (int)s21_strlen(num_str);
  if (is_negative) {
    len--;
  }

  int precision_zeros = 0;
  if (fconf->precision >= 0) {
    precision_zeros = fconf->precision > len ? fconf->precision - len : 0;
  }

  int total_len = len + precision_zeros;
  if (is_negative) total_len++;
  if ((fconf->plus || fconf->space) && !is_negative) total_len++;

  if (!fconf->minus && fconf->width > total_len) {
    char padding_char = (fconf->zero && fconf->precision < 0) ? '0' : ' ';
    print_white_spaces(&to_out, padding_char, fconf->width - total_len);
  }

  if (is_negative) {
    *to_out = '-';
    to_out++;
  } else if (fconf->plus) {
    *to_out = '+';
    to_out++;
  } else if (fconf->space) {
    *to_out = ' ';
    to_out++;
  }

  print_white_spaces(&to_out, '0', precision_zeros);

  copy(&to_out, is_negative ? num_str + 1 : num_str);

  if (fconf->minus && fconf->width > total_len) {
    print_white_spaces(&to_out, ' ', fconf->width - total_len);
  }
}

void spec_u(va_list *args, char *to_out, format_conf *fconf) {
  char num_str[100];
  int len = 0;
  if (fconf->len == 'l') {
    unsigned long val =
        (s21_size_t)va_arg(*args, s21_size_t);  // извлекаем аргумент после ""
    long_u_itoa(val, num_str, 10);
  } else {
    unsigned int val = (unsigned int)va_arg(
        *args, unsigned int);  // извлекаем аргумент после ""
    itoa(val, num_str, 10);
  }
  len = (int)s21_strlen(num_str);  // num "-123"
  int width_to_fill = (fconf->precision > fconf->width) ? fconf->precision - len
                                                        : fconf->width - len;

  int prec_flag = false;
  if (fconf->precision >= fconf->width) {
    fconf->zero = true;
    prec_flag = true;
  }

  if (fconf->minus == false || prec_flag) {
    print_white_spaces(&to_out, fconf->zero ? '0' : ' ', width_to_fill);
    copy(&to_out, num_str);

  } else {
    copy(&to_out, num_str);
    print_white_spaces(&to_out, fconf->zero ? '0' : ' ', width_to_fill);
    *to_out = '\0';
  }
}

void spec_f(va_list *args, char *to_out, format_conf *fconf) {
  double val;
  int is_negative = 0;
  if (fconf->len == 'l')
    val = va_arg(*args, double);
  else
    val = va_arg(*args, double);

  is_negative = val < 0;
  if (is_negative) val = -val;

  double integer_part = (int)val;
  double fractional_part = val - integer_part;
  char int_str[100];
  int precision = (fconf->precision >= 0) ? fconf->precision : 6;
  char frac_str[100] = {0};
  // преобразование дробной части в интовое значение и перевод в формат строки
  for (int i = 0; i < precision; i++) {
    fractional_part *= 10;
  }
  int frac_part_int = (int)fractional_part;
  double frac_of_frac = fractional_part - frac_part_int;
  frac_part_int += round(frac_of_frac);
  int logic;
  if (precision == 1) {
    logic = frac_part_int % 10;
  } else if (precision > 1) {
    logic = frac_part_int % (int)pow(10, precision);
  } else {
    logic = 1;
  }
  if (logic == 0) {
    integer_part++;
    itoa(integer_part, int_str, 10);
    itoa(0, frac_str, 10);
  } else {
    itoa(integer_part, int_str, 10);
    itoa(frac_part_int, frac_str, 10);
  }
  frac_str[precision] = '\0';
  int len = (int)s21_strlen(int_str) + 1 + precision;
  if ((fconf->plus || fconf->space) && !is_negative) len += 1;
  if (is_negative) len += 1;

  if (!fconf->minus)
    print_white_spaces(&to_out, fconf->zero ? '0' : ' ', fconf->width - len);
  if (is_negative)
    *to_out++ = '-';
  else if (fconf->plus)
    *to_out++ = '+';
  else if (fconf->space)
    *to_out++ = ' ';
  copy(&to_out, int_str);
  if (precision != 0) *to_out++ = '.';

  int frac_len = (int)s21_strlen(frac_str);
  if (frac_len < precision) {
    for (int i = 0; i < precision - frac_len; i++) {
      *to_out++ = '0';
    }
  }
  copy(&to_out, frac_str);
  if (fconf->minus) {
    print_white_spaces(&to_out, ' ', fconf->width - len);
    *to_out = '\0';
  }
}

void spec_c(const format_conf *fconf, va_list *args, char *to_out) {
  char c = (char)va_arg(*args, int);
  if (fconf->width > 0 && c) {
    int num_of_spaces = fconf->width - 1;
    if (fconf->minus) {
      *to_out = c;
      to_out++;
      print_white_spaces(&to_out, ' ', num_of_spaces);
      *to_out = '\0';
    } else {
      print_white_spaces(&to_out, ' ', num_of_spaces);
      *to_out = c;
      to_out++;
    }
  } else
    *to_out = c;
}

void print_white_spaces(char **to_out, char to_fill, int num_of_spaces) {
  if (num_of_spaces > 0) {
    for (int i = 0; i < num_of_spaces; i++) {
      **to_out = to_fill;
      *to_out += 1;
    }
  }
}

// int main() {
//   char s21_str1[1024];
//   char ____str2[1024];
//   const char *format = "This is a simple wide char %-5lc";
//   unsigned long val = L'Ф';
//   //ck_assert_str_eq(str1, str2);
//   s21_sprintf(s21_str1, format, val);
//   sprintf(____str2, format, val);
//   printf("s21:\"%s\"\n", s21_str1);
//   printf("std:\"%s\"\n", ____str2);
// }
