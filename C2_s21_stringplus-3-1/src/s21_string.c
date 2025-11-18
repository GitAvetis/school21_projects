#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char buf[100];
  char *result;

  if (errnum < 0 || errnum >= ERRORS_COUNT) {
    const char *prefix = ERR;
    int i = 0;

    while (prefix[i] != '\0') {
      buf[i] = prefix[i];
      i++;
    }

    int num = errnum;
    if (num < 0) {
      buf[i++] = '-';
      num = -num;
    }

    int temp_num = num;
    int digit_count = 0;
    do {
      digit_count++;
      temp_num /= 10;
    } while (temp_num > 0);

    for (int j = 0; j < digit_count; j++) {
      buf[i + digit_count - 1 - j] = '0' + (num % 10);
      num /= 10;
    }
    i += digit_count;
    buf[i] = '\0';
    result = buf;
  } else {
    static const char *error_messages[] = ERRORS;
    result = (char *)error_messages[errnum];
  }

  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dest_char = dest;
  const char *src_char = src;

  for (s21_size_t i = 0; i < n; ++i) {
    *dest_char++ = *src_char++;
  }
  return dest;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *new_str = (const unsigned char *)str;
  unsigned char ickomiy = (unsigned char)c;
  int flag = 0;
  void *res = s21_NULL;
  for (s21_size_t i = 0; i < n && !flag; i++, new_str++) {
    if (*new_str == ickomiy) {
      res = (void *)new_str;
      flag = 1;
    }
  }
  return res;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *new_str = str;
  unsigned char sym = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++, new_str++) {
    *new_str = sym;
  }
  return str;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  if (n > 0) {
    int err = 0;
    s21_size_t i = 0;
    while (i < n && err == 0) {
      unsigned char fist = (unsigned char)*str1++;
      unsigned char second = (unsigned char)*str2++;
      if (fist != second) {
        res = fist - second;
        err = 1;
      }
      if (fist == '\0') {
        err = 1;
      }
      i++;
    }
  }
  return res;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  int flag = 0;
  s21_size_t res = 0;
  if (len2 == 0) {
    res = len1;
    flag = 1;
  }
  for (s21_size_t i = 0; i < len1 && !flag; i++) {
    for (s21_size_t j = 0; j < len2 && !flag; j++) {
      if (str2[j] == str1[i]) {
        res = i;
        flag = 1;
      }
    }
  }
  if (!flag) {
    res = len1;
  }

  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *olds = s21_NULL;
  char *token = s21_NULL;
  if (str != s21_NULL) {
    olds = str;
  }
  if (olds == s21_NULL) {
    token = s21_NULL;
  } else {
    while (*olds != '\0' && s21_strchr(delim, *olds) != s21_NULL) {
      olds++;
    }
    if (*olds == '\0') {
      olds = s21_NULL;
      token = s21_NULL;
    } else {
      token = olds;
      while (*olds != '\0' && s21_strchr(delim, *olds) == s21_NULL) {
        olds++;
      }
      if (*olds == '\0') {
        olds = s21_NULL;
      } else {
        *olds++ = '\0';
      }
    }
  }
  return token;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p_dest = dest + s21_strlen(dest);
  while (n > 0 && *src != '\0') {
    *p_dest++ = *src++;
    n--;
  }
  return dest;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_len = s21_strlen(src), str_len = s21_strlen(str);
  char *new_str;
  if (start_index > src_len) return s21_NULL;
  new_str = malloc(src_len + str_len + 1);
  if (new_str != s21_NULL) {
    int trig = 1;
    s21_size_t j = 0;
    for (s21_size_t i = 0; i <= src_len; i++) {
      if (i == start_index && trig) {
        for (; j < str_len; j++) {
          new_str[j + i] = str[j];
        }
        trig = 0;
      } else {
        if (trig)
          new_str[i + j] = src[i];
        else
          new_str[i + j - 1] = src[i - 1];
      }
    }
    new_str[src_len + str_len] = '\0';
  }
  return (void *)new_str;
}
void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t src_len = s21_strlen(src), trim_len = 0;
  if (trim_chars) {
    trim_len = s21_strlen(trim_chars);
  }

  char to_trim[2048] = {0};
  if (!trim_len) {
    to_trim[0] = ' ';
    to_trim[1] = '\0';
  } else {
    s21_strncpy(to_trim, trim_chars, sizeof(to_trim) - 1);
  }
  char *p_src_front = (char *)src;
  char *p_src_back = (char *)src + src_len - 1;
  while (p_src_front <= p_src_back &&
         s21_strchr(to_trim, *p_src_front) != s21_NULL) {
    p_src_front++;
  }
  while (p_src_back >= p_src_front &&
         s21_strchr(to_trim, *p_src_back) != s21_NULL) {
    p_src_back--;
  }
  unsigned long n = p_src_back - p_src_front + 1;

  char *trimed_str =
      (char *)malloc(n + 1);  // увеличил память на 1 чар для конца строки
  if (trimed_str) {
    s21_strncpy(trimed_str, p_src_front, n);
    trimed_str[n] = '\0';  // если не поможет +1 в маллоке
  }
  return (void *)trimed_str;
}

void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *strUp = malloc(len + 1);
  if (strUp != s21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] > 96 && str[i] < 123)
        strUp[i] = (char)str[i] - 32;
      else
        strUp[i] = (char)str[i];
    }
    strUp[len] = '\0';
  }
  return (void *)strUp;
}

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *strLow = malloc(len + 1);
  if (strLow != s21_NULL) {
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] > 64 && str[i] < 91)
        strLow[i] = (char)str[i] + 32;
      else
        strLow[i] = (char)str[i];
    }
    strLow[len] = '\0';
  }
  return (void *)strLow;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str) {
    for (; *(str + len); len++) {
    }
  }
  return len;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (src) {
    char *p_dest = dest;
    const char *p_src = src;
    while (n > 0 && *p_src != '\0') {
      *p_dest++ = *p_src++;
      n--;
    }
    for (; n > 0; n--) {
      *p_dest++ = '\0';
    }
  }
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);
  int flag = 0;
  char *res = s21_NULL;

  for (s21_size_t i = 0; i < len_str1 && flag == 0; i++) {
    for (s21_size_t j = 0; j < len_str2 && flag == 0; j++) {
      if (str1[i] == str2[j]) {
        res = (char *)str1 + i;
        flag = 1;
      }
    }
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  if (str != s21_NULL) {
    int len = s21_strlen(str);
    res = (char *)str + len;
    for (int i = len; i >= 0 && str[i] != (char)c; i--) {
      res--;
    }

    if (*(res + 1) == *str) res = s21_NULL;
  }
  return res;
}

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  if (str != s21_NULL) {
    res = (char *)str;
    int len = s21_strlen(str);
    for (int i = 0; i < len && str[i] != (char)c; i++) {
      res++;
    }

    if (*res != (char)c) res = s21_NULL;
  }
  return res;
}
// char *s21_strrchr(const char *str, int c) {
//   char *res = s21_NULL;
//   if (s21_strlen(str)) {
//     int len = s21_strlen(str);
//     res = (char *)str + len;
//     for (int i = len; i >= 0 && str[i] != c; i--) {
//       res--;
//     }

//     if (*(res + 1) == *str) res = s21_NULL;
//   }
//   return res;
// }

// char *s21_strchr(const char *str, int c) {
//   char *res = s21_NULL;
//   if (s21_strlen(str)) {
//     res = (char *)str;
//     int len = s21_strlen(str);
//     for (int i = 0; i < len && str[i] != c; i++) {
//       res++;
//     }
//     if (*res == 0) res = s21_NULL;
//   }

//   return res;
// }

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ptr1 = (const unsigned char *)str1;
  const unsigned char *ptr2 = (const unsigned char *)str2;
  int result = 0;

  for (size_t i = 0; i < n && result == 0; i++) {
    if (ptr1[i] != ptr2[i]) {
      result = (int)ptr1[i] - (int)ptr2[i];
      break;
    }
  }

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = NULL;

  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    for (; *haystack != '\0'; haystack++) {
      const char *h = haystack;
      const char *n = needle;

      while (*n != '\0' && *h == *n) {
        h++;
        n++;
      }

      if (*n == '\0') {
        result = (char *)haystack;
        break;
      }
    }
  }

  return result;
}
