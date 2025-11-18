#include "s21_string.h"

int s21_atoi(const char *str) {
  int result = 0;
  int sign = 1;
  while (isspace(*str)) str++;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }
  while (isdigit(*str)) {
    result = result * 10 + (*str - '0');
    str++;
  }
  return sign * result;
}

long int s21_strtol(const char *nptr, char **endptr, int base) {
  const char *s = nptr;
  long int result = 0;
  int sign = 1;
  int overflow = 0;
  while (isspace((unsigned char)*s)) {
    s++;
  }
  if (*s == '+' || *s == '-') {
    if (*s == '-') {
      sign = -1;
    }
    s++;
  }
  if (base == 0) {
    if (*s == '0') {
      if (*(s + 1) == 'x' || *(s + 1) == 'X') {
        base = 16;
        s += 2;
      } else {
        base = 8;
        s++;
      }
    } else {
      base = 10;
    }
  } else if (base == 16 && *s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X')) {
    s += 2;
  }

  if (base < 2 || base > 36) {
    if (endptr) {
      *endptr = (char *)nptr;
    }
    return 0;
  }
  while (*s) {
    int digit;
    if (isdigit((unsigned char)*s)) {
      digit = *s - '0';
    } else if (*s >= 'a' && *s <= 'z') {
      digit = *s - 'a' + 10;
    } else if (*s >= 'A' && *s <= 'Z') {
      digit = *s - 'A' + 10;
    } else {
      break;
    }
    if (digit >= base) {
      break;
    }
    if (result > (LONG_MAX - digit) / base) {
      overflow = 1;
      break;
    }
    result = result * base + digit;
    s++;
  }
  if (endptr) {
    *endptr = (char *)(s);
  }
  if (overflow) {
    return sign == 1 ? LONG_MAX : LONG_MIN;
  }
  return sign * result;
}

double s21_strtod(const char *str, char **endptr) {
  const char *s = str;
  double result = 0.0;
  int sign = 1;
  double fraction = 0.0;
  int exponent = 0;
  while (isspace(*s)) {
    s++;
  }
  if (*s == '-') {
    sign = -1;
    s++;
  } else if (*s == '+') {
    s++;
  }
  while (isdigit(*s)) {
    result = result * 10.0 + (*s - '0');
    s++;
  }
  if (*s == '.') {
    double divisor = 1.0;
    s++;
    while (isdigit(*s)) {
      fraction = fraction * 10.0 + (*s - '0');
      divisor *= 10.0;
      s++;
    }
    result += fraction / divisor;
  }
  if (*s == 'e' || *s == 'E') {
    int exp_sign = 1;
    s++;
    if (*s == '-') {
      exp_sign = -1;
      s++;
    } else if (*s == '+') {
      s++;
    }
    while (isdigit(*s)) {
      exponent = exponent * 10 + (*s - '0');
      s++;
    }
    result *= pow(10, exp_sign * exponent);
  }
  if (endptr) {
    *endptr = (char *)s;
  }
  return sign * result;
}

long double s21_strtold(const char *str, char **endptr) {
  const char *s = str;
  long double result = 0.0;
  int sign = 1;
  long double fraction = 0.0;
  int exponent = 0;
  while (isspace(*s)) {
    s++;
  }
  if (*s == '-') {
    sign = -1;
    s++;
  } else if (*s == '+') {
    s++;
  }
  while (isdigit(*s)) {
    result = result * 10.0 + (*s - '0');
    s++;
  }
  if (*s == '.') {
    long double divisor = 1.0;
    s++;
    while (isdigit(*s)) {
      fraction = fraction * 10.0 + (*s - '0');
      divisor *= 10.0;
      s++;
    }
    result += fraction / divisor;
  }
  if (*s == 'e' || *s == 'E') {
    int exp_sign = 1;
    s++;
    if (*s == '-') {
      exp_sign = -1;
      s++;
    } else if (*s == '+') {
      s++;
    }
    while (isdigit(*s)) {
      exponent = exponent * 10 + (*s - '0');
      s++;
    }
    result *= pow(10, exp_sign * exponent);
  }
  if (endptr) {
    *endptr = (char *)s;
  }
  return sign * result;
}

void skip_spaces(const char **str) {
  while (**str && isspace(**str)) {
    (*str)++;
  }
}

unsigned long int s21_strtoul(const char *nptr, char **endptr, int base) {
  const char *s = nptr;
  unsigned long int result = 0;
  int overflow = 0;
  while (isspace((unsigned char)*s)) {
    s++;
  }
  if (*s == '+') {
    s++;
  } else if (*s == '-') {
    if (endptr) {
      *endptr = (char *)nptr;
    }
    return 0;
  }
  if (base == 0) {
    if (*s == '0') {
      if (*(s + 1) == 'x' || *(s + 1) == 'X') {
        base = 16;
        s += 2;
      } else {
        base = 8;
        s++;
      }
    } else {
      base = 10;
    }
  } else if (base == 16 && *s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X')) {
    s += 2;
  }
  if (base < 2 || base > 36) {
    if (endptr) {
      *endptr = (char *)nptr;
    }
    return 0;
  }
  while (*s) {
    int digit;
    if (isdigit((unsigned char)*s)) {
      digit = *s - '0';
    } else if (*s >= 'a' && *s <= 'z') {
      digit = *s - 'a' + 10;
    } else if (*s >= 'A' && *s <= 'Z') {
      digit = *s - 'A' + 10;
    } else {
      break;
    }
    if (digit >= base) {
      break;
    }
    if (result > (ULONG_MAX - digit) / base) {
      overflow = 1;
      break;
    }
    result = result * base + digit;
    s++;
  }
  if (endptr) {
    *endptr = (char *)(s);
  }
  if (overflow) {
    return ULONG_MAX;
  }
  return result;
}

unsigned int s21_strtou(const char *nptr, char **endptr, int base) {
  const char *s = nptr;
  unsigned int result = 0;
  int overflow = 0;
  while (isspace((unsigned char)*s)) {
    s++;
  }
  if (*s == '+') {
    s++;
  } else if (*s == '-') {
    if (endptr) {
      *endptr = (char *)nptr;
    }
    return 0;
  }
  if (base == 0) {
    if (*s == '0') {
      if (*(s + 1) == 'x' || *(s + 1) == 'X') {
        base = 16;
        s += 2;
      } else {
        base = 8;
        s++;
      }
    } else {
      base = 10;
    }
  } else if (base == 16 && *s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X')) {
    s += 2;
  }
  if (base < 2 || base > 36) {
    if (endptr) {
      *endptr = (char *)nptr;
    }
    return 0;
  }
  while (*s) {
    int digit;
    if (isdigit((unsigned char)*s)) {
      digit = *s - '0';
    } else if (*s >= 'a' && *s <= 'z') {
      digit = *s - 'a' + 10;
    } else if (*s >= 'A' && *s <= 'Z') {
      digit = *s - 'A' + 10;
    } else {
      break;
    }
    if (digit >= base) {
      break;
    }
    if (result > (UINT_MAX - digit) / base) {
      overflow = 1;
      break;
    }
    result = result * base + digit;
    s++;
  }
  if (endptr) {
    *endptr = (char *)(s);
  }
  if (overflow) {
    return UINT_MAX;
  }
  return result;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int LFlag = 0;
  int lFlag = 0;
  int count = 0;
  int stopFlag = 0;
  if (*str == '\0' || format == NULL) {
    count = -1;
  }
  const char *f = format;
  const char *s = str;
  while (count != -1 && *f && stopFlag == 0) {
    if (isspace(*f)) {
      skip_spaces(&f);
      skip_spaces(&s);
    } else if (*f == '%') {
      f++;
      int suppress = 0, width = 0;
      if (*f == '*') {
        suppress = 1;
        f++;
      }
      while (isdigit(*f)) {
        width = width * 10 + (*f - '0');
        f++;
      }
      if (*f == 'L') {
        LFlag = 1;
        f++;
      }
      if (*f == 'l') {
        lFlag = 1;
        f++;
      }
      if (*f == 'h') {
        f++;
      }
      switch (*f) {
        case 'c': {
          int limit = (width > 0) ? width : 1;
          char buffer[limit + 1];
          for (int i = 0; i < limit && *s; i++) {
            buffer[i] = *s++;
          }
          buffer[limit] = '\0';
          if (!suppress) {
            char *val = va_arg(args, char *);
            *val = buffer[0];
            count++;
          }
          break;
        }
        case 'd': {
          char buffer[100] = {0};
          int i = 0;
          while ((*s == '-' || isdigit(*s)) && (width == 0 || i < width)) {
            buffer[i++] = *s++;
          }
          buffer[i] = '\0';
          if (!suppress) {
            int *val = va_arg(args, int *);
            *val = s21_atoi(buffer);
            count++;
          }
          break;
        }
        case 'i': {
          int *val = va_arg(args, int *);
          char buffer[100] = {0};
          int i = 0;
          while ((isdigit(*s) || *s == 'x' || *s == 'X' ||
                  (*s < 71 && *s > 64) || (*s < 103 && *s > 96)) &&
                 (width == 0 || i < width)) {
            buffer[i++] = *s++;
          }
          buffer[i] = '\0';
          if (buffer[0] == '0' && (buffer[1] == 'x' || buffer[1] == 'X')) {
            *val = s21_strtol(buffer, NULL, 16);
          } else if (buffer[0] == '0') {
            *val = s21_strtol(buffer, NULL, 8);
          } else {
            *val = s21_atoi(buffer);
          }
          count++;
          break;
        }
        case 'o': {
          char buffer[256] = {0};
          void *result = NULL;
          if (!suppress) {
            if (lFlag) {
              result = (unsigned long int *)va_arg(args, unsigned long int *);
            } else {
              result = (unsigned int *)va_arg(args, unsigned int *);
            }
          }
          int num_digits = 0;
          skip_spaces(&s);
          while ((*s >= '0' && *s <= '7') &&
                 (width == 0 || num_digits < width)) {
            buffer[num_digits++] = *s++;
          }
          buffer[num_digits] = '\0';
          if (!suppress && result) {
            char *end_ptr = NULL;
            if (lFlag) {
              unsigned long int val = s21_strtoul(buffer, &end_ptr, 8);
              if (end_ptr == buffer) {
                return count;
              }
              *(unsigned long int *)result = val;
              lFlag = 0;
            } else {
              unsigned int val = s21_strtou(buffer, &end_ptr, 8);
              if (end_ptr == buffer) {
                return count;
              }
              *(unsigned int *)result = val;
            }
            count++;
          }
          break;
        }
        case 'u': {
          unsigned long result = 0;
          int num_digits = 0;
          skip_spaces(&s);
          while (isdigit(*s) && (width == 0 || num_digits < width)) {
            result = result * 10 + (*s - '0');
            s++;
            num_digits++;
          }
          if (!suppress) {
            if (lFlag == 1) {
              unsigned long *val = va_arg(args, unsigned long *);
              *val = result;
            } else {
              unsigned int *val = va_arg(args, unsigned int *);
              *val = (unsigned int)result;
            }
            count++;
          }
          break;
        }
        case 'x':
        case 'X': {
          char buffer[256] = {0};
          void *result = NULL;
          if (!suppress) {
            if (lFlag) {
              result = (unsigned long int *)va_arg(args, unsigned long int *);
            } else {
              result = (unsigned int *)va_arg(args, unsigned int *);
            }
          }
          int num_digits = 0;
          skip_spaces(&s);
          while ((isdigit(*s) || (*s >= 'a' && *s <= 'f') ||
                  (*s >= 'A' && *s <= 'F')) &&
                 (width == 0 || num_digits < width)) {
            buffer[num_digits++] = *s++;
          }
          buffer[num_digits] = '\0';
          if (!suppress && result) {
            char *end_ptr = NULL;
            if (lFlag) {
              unsigned long int val = s21_strtoul(buffer, &end_ptr, 16);
              if (end_ptr == buffer) {
                return count;
              }
              *(unsigned long int *)result = val;
            } else {
              unsigned int val = s21_strtou(buffer, &end_ptr, 16);
              if (end_ptr == buffer) {
                return count;
              }
              *(unsigned int *)result = val;
            }
            count++;
          }
          break;
        }
        case 'p': {
          if (!suppress) {
            void **val = va_arg(args, void **);
            *val = (void *)s21_strtoul(s, (char **)&s, 16);
            count++;
          } else {
            s21_strtoul(s, (char **)&s, 16);
          }
          break;
        }
        case 'G':
        case 'g':
        case 'E':
        case 'f': {
          void *val = NULL;
          if (!suppress) {
            if (LFlag) {
              val = va_arg(args, long double *);
            } else if (lFlag) {
              val = va_arg(args, double *);
            } else {
              val = va_arg(args, float *);
            }
          }
          char buffer[256] = {0};
          int i = 0;
          skip_spaces(&s);
          while ((*s == '-' || *s == '+' || *s == '.' || isdigit(*s) ||
                  *s == 'e' || *s == 'E') &&
                 (width == 0 || i < width)) {
            buffer[i++] = *s++;
          }
          buffer[i] = '\0';
          if (!suppress && val) {
            char *end_ptr = NULL;
            if (LFlag) {
              long double result = s21_strtold(buffer, &end_ptr);
              if (end_ptr == buffer) {
                return count;
              }
              *(long double *)val = result;
              LFlag = 0;
            } else if (lFlag) {
              double result = s21_strtod(buffer, &end_ptr);
              if (end_ptr == buffer) {
                return count;
              }
              *(double *)val = result;
              lFlag = 0;
            } else {
              float result = s21_strtod(buffer, &end_ptr);
              if (end_ptr == buffer) {
                return count;
              }
              *(float *)val = (float)result;
            }
          }
          count++;
          break;
        }
        case 'e': {
          void *val = NULL;
          if (!suppress) {
            if (LFlag) {
              val = va_arg(args, double *);
            } else {
              val = va_arg(args, float *);
            }
          }
          char buffer[256] = {0};
          int i = 0;
          skip_spaces(&s);
          while ((*s == '-' || *s == '+' || *s == '.' || *s == 'e' ||
                  isdigit(*s)) &&
                 (width == 0 || i < width)) {
            buffer[i++] = *s++;
          }
          buffer[i] = '\0';
          if (!suppress && val) {
            char *end_ptr = NULL;
            if (LFlag) {
              double result = s21_strtod(buffer, &end_ptr);
              if (end_ptr == buffer) {
                return count;
              }
              *(double *)val = result;
              LFlag = 0;
            } else {
              float temp_result = s21_strtod(buffer, &end_ptr);
              if (end_ptr == buffer) {
                return count;
              }
              *(float *)val = (float)temp_result;
            }
          }
          count++;
          break;
        }
        case 'n': {
          if (!suppress) {
            int *val = va_arg(args, int *);
            *val = s - str;
          }
          break;
        }
        case 's': {
          char buffer[256] = {0};
          int i = 0;
          while (*s && !isspace(*s) && (width == 0 || i < width)) {
            buffer[i++] = *s++;
          }
          buffer[i] = '\0';
          if (!suppress && buffer[0] != '\0') {
            char *val = va_arg(args, char *);
            s21_strncpy(val, buffer, i);
            val[i] = '\0';
            count++;
          }
          break;
        }
        case '%': {
          if (*s == '%') {
            s++;
          } else {
            return count;
          }
          break;
        }
        default:
          count = 0;
          stopFlag = 1;
      }
      f++;
    } else {
      if (*f == *s) {
        f++;
        s++;
      } else {
        break;
      }
    }
  }
  va_end(args);
  return count;
}
