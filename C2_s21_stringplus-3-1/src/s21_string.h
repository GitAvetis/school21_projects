#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(__APPLE__) || defined(__MACH__)
#define ERRORS_COUNT 107
#define ERR "Unknown error: "
#elif defined(__linux__)
#define ERRORS_COUNT 134
#define ERR "Unknown error "
#else
#define ERRORS_COUNT 134
#endif

#define s21_size_t unsigned long

// нужно прогнать strerror на линуксе!!!

#define s21_NULL (void *)0

typedef struct s21_string {
  bool plus;  // Заставляет явно указывать + или - даже для положительных чисел.
  bool minus;  // Выравнивание по левому краю в пределах заданной ширины поля.
  bool space;  // Ставить пробел, если знак числа не будет выведен
  bool scharp;
  bool zero;  // Заполняет число слева нулями (0) вместо пробелов, где указан
              // спецификатор ширины
  int width;  // Минимальное количество печатаемых символов.
  int precision;  // точность с которой выводить значения
  char type;      // тип значения (s, d, c, и т.д.)
  char len;       // l L h модификатор длины
  bool bug_suc;   // если не нашли тип данных.

} format_conf;

void *s21_memchr(const void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

void *s21_memcpy(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, s21_size_t n);

char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strchr(const char *str, int c);

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strcspn(const char *str1, const char *str2);

char *s21_strerror(int errnum);

s21_size_t s21_strlen(const char *str);

char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);

/*2 and 3 part
форматная строка имеет вид:
%[flags][width][.precision][size]type, где:
flags: +, -, пробел (доп часть 0 ,#)
width: число (доп *)
.precision: .число доп часть(.*)
size - (.число .*) параметр только для строки
type - тип преобразования (c, d, f, s и т.д)
len - l,h;


*/

int s21_sprintf(char *str, const char *format, ...);

void flag_check(char **check, format_conf *fconf);

void width_check(char **check, format_conf *fconf);

void precision_check(char **check, format_conf *fconf);

void len_check(char **check, format_conf *fconf);

void type_check(char **check, format_conf *fconf);

void itoa(long int value, char *buffer,
          int base);  // перевод числа в строковый формат

void long_u_itoa(s21_size_t value, char *buffer, int base);

void copy(char **dest, const char *src);

void spec_d(va_list *args, char *to_out, const format_conf *fconf);

void spec_u(va_list *args, char *to_out, format_conf *fconf);

void spec_f(va_list *args, char *to_out, format_conf *fconf);

void spec_s(va_list *args, char *to_out, format_conf *fconf);

void spec_c(const format_conf *fconf, va_list *args, char *to_out);

void print_white_spaces(char **to_out, char to_fill, int num_of_spaces);

/// @brief записывает в строку получившийся результат из орматной строки
/// @param p указатель на начало записи
/// @param format указатель на форматную строку
/// @param args аргументы для извлечения значений
void fill_str(char **p, const char *format, va_list *args);

void fill_struct(char **pfr, format_conf *fconf);

/// @brief парсит часть строки после %, записывает получившийся результат  в
/// финальную строку и переводит указатель далее
/// @param p указатель на конец финальной строки для записи
/// @param pfr указатель на место начала парсинга в форматированной строке
/// @param args аргументы для извлеения значений
void cook_format_params(char **p, char **pfr, va_list *args);

// 4 part
int s21_sscanf(const char *str, const char *format, ...);

int s21_atoi(const char *str);

double s21_strtod(const char *str, char **endptr);

void skip_spaces(const char **str);

int s21_sscanf(const char *str, const char *format, ...);

long int s21_strtol(const char *nptr, char **endptr, int base);

unsigned long int s21_strtoul(const char *nptr, char **endptr, int base);

long double s21_strtold(const char *str, char **endptr);

unsigned int s21_strtou(const char *nptr, char **endptr, int base);

// 5 part
void *s21_to_upper(const char *str);

void *s21_to_lower(const char *str);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void *s21_trim(const char *src, const char *trim_chars);

#ifdef __linux__
#define ERRORS                                             \
  {                                                        \
      "Success",                                           \
      "Operation not permitted",                           \
      "No such file or directory",                         \
      "No such process",                                   \
      "Interrupted system call",                           \
      "Input/output error",                                \
      "No such device or address",                         \
      "Argument list too long",                            \
      "Exec format error",                                 \
      "Bad file descriptor",                               \
      "No child processes",                                \
      "Resource temporarily unavailable",                  \
      "Cannot allocate memory",                            \
      "Permission denied",                                 \
      "Bad address",                                       \
      "Block device required",                             \
      "Device or resource busy",                           \
      "File exists",                                       \
      "Invalid cross-device link",                         \
      "No such device",                                    \
      "Not a directory",                                   \
      "Is a directory",                                    \
      "Invalid argument",                                  \
      "Too many open files in system",                     \
      "Too many open files",                               \
      "Inappropriate ioctl for device",                    \
      "Text file busy",                                    \
      "File too large",                                    \
      "No space left on device",                           \
      "Illegal seek",                                      \
      "Read-only file system",                             \
      "Too many links",                                    \
      "Broken pipe",                                       \
      "Numerical argument out of domain",                  \
      "Numerical result out of range",                     \
      "Resource deadlock avoided",                         \
      "File name too long",                                \
      "No locks available",                                \
      "Function not implemented",                          \
      "Directory not empty",                               \
      "Too many levels of symbolic links",                 \
      "Unknown error 41",                                  \
      "No message of desired type",                        \
      "Identifier removed",                                \
      "Channel number out of range",                       \
      "Level 2 not synchronized",                          \
      "Level 3 halted",                                    \
      "Level 3 reset",                                     \
      "Link number out of range",                          \
      "Protocol driver not attached",                      \
      "No CSI structure available",                        \
      "Level 2 halted",                                    \
      "Invalid exchange",                                  \
      "Invalid request descriptor",                        \
      "Exchange full",                                     \
      "No anode",                                          \
      "Invalid request code",                              \
      "Invalid slot",                                      \
      "Unknown error 58",                                  \
      "Bad font file format",                              \
      "Device not a stream",                               \
      "No data available",                                 \
      "Timer expired",                                     \
      "Out of streams resources",                          \
      "Machine is not on the network",                     \
      "Package not installed",                             \
      "Object is remote",                                  \
      "Link has been severed",                             \
      "Advertise error",                                   \
      "Srmount error",                                     \
      "Communication error on send",                       \
      "Protocol error",                                    \
      "Multihop attempted",                                \
      "RFS specific error",                                \
      "Bad message",                                       \
      "Value too large for defined data type",             \
      "Name not unique on network",                        \
      "File descriptor in bad state",                      \
      "Remote address changed",                            \
      "Can not access a needed shared library",            \
      "Accessing a corrupted shared library",              \
      ".lib section in a.out corrupted",                   \
      "Attempting to link in too many shared libraries",   \
      "Cannot exec a shared library directly",             \
      "Invalid or incomplete multibyte or wide character", \
      "Interrupted system call should be restarted",       \
      "Streams pipe error",                                \
      "Too many users",                                    \
      "Socket operation on non-socket",                    \
      "Destination address required",                      \
      "Message too long",                                  \
      "Protocol wrong type for socket",                    \
      "Protocol not available",                            \
      "Protocol not supported",                            \
      "Socket type not supported",                         \
      "Operation not supported",                           \
      "Protocol family not supported",                     \
      "Address family not supported by protocol",          \
      "Address already in use",                            \
      "Cannot assign requested address",                   \
      "Network is down",                                   \
      "Network is unreachable",                            \
      "Network dropped connection on reset",               \
      "Software caused connection abort",                  \
      "Connection reset by peer",                          \
      "No buffer space available",                         \
      "Transport endpoint is already connected",           \
      "Transport endpoint is not connected",               \
      "Cannot send after transport endpoint shutdown",     \
      "Too many references: cannot splice",                \
      "Connection timed out",                              \
      "Connection refused",                                \
      "Host is down",                                      \
      "No route to host",                                  \
      "Operation already in progress",                     \
      "Operation now in progress",                         \
      "Stale file handle",                                 \
      "Structure needs cleaning",                          \
      "Not a XENIX named type file",                       \
      "No XENIX semaphores available",                     \
      "Is a named type file",                              \
      "Remote I/O error",                                  \
      "Disk quota exceeded",                               \
      "No medium found",                                   \
      "Wrong medium type",                                 \
      "Operation canceled",                                \
      "Required key not available",                        \
      "Key has expired",                                   \
      "Key has been revoked",                              \
      "Key was rejected by service",                       \
      "Owner died",                                        \
      "State not recoverable",                             \
      "Operation not possible due to RF-kill",             \
      "Memory page has hardware error",                    \
  };

#elif __APPLE__
#define ERRORS                                        \
  {"Undefined error: 0",                              \
   "Operation not permitted",                         \
   "No such file or directory",                       \
   "No such process",                                 \
   "Interrupted system call",                         \
   "Input/output error",                              \
   "Device not configured",                           \
   "Argument list too long",                          \
   "Exec format error",                               \
   "Bad file descriptor",                             \
   "No child processes",                              \
   "Resource deadlock avoided",                       \
   "Cannot allocate memory",                          \
   "Permission denied",                               \
   "Bad address",                                     \
   "Block device required",                           \
   "Resource busy",                                   \
   "File exists",                                     \
   "Cross-device link",                               \
   "Operation not supported by device",               \
   "Not a directory",                                 \
   "Is a directory",                                  \
   "Invalid argument",                                \
   "Too many open files in system",                   \
   "Too many open files",                             \
   "Inappropriate ioctl for device",                  \
   "Text file busy",                                  \
   "File too large",                                  \
   "No space left on device",                         \
   "Illegal seek",                                    \
   "Read-only file system",                           \
   "Too many links",                                  \
   "Broken pipe",                                     \
   "Numerical argument out of domain",                \
   "Result too large",                                \
   "Resource temporarily unavailable",                \
   "Operation now in progress",                       \
   "Operation already in progress",                   \
   "Socket operation on non-socket",                  \
   "Destination address required",                    \
   "Message too long",                                \
   "Protocol wrong type for socket",                  \
   "Protocol not available",                          \
   "Protocol not supported",                          \
   "Socket type not supported",                       \
   "Operation not supported",                         \
   "Protocol family not supported",                   \
   "Address family not supported by protocol family", \
   "Address already in use",                          \
   "Can't assign requested address",                  \
   "Network is down",                                 \
   "Network is unreachable",                          \
   "Network dropped connection on reset",             \
   "Software caused connection abort",                \
   "Connection reset by peer",                        \
   "No buffer space available",                       \
   "Socket is already connected",                     \
   "Socket is not connected",                         \
   "Can\'t send after socket shutdown",               \
   "Too many references: can\'t splice",              \
   "Operation timed out",                             \
   "Connection refused",                              \
   "Too many levels of symbolic links",               \
   "File name too long",                              \
   "Host is down",                                    \
   "No route to host",                                \
   "Directory not empty",                             \
   "Too many processes",                              \
   "Too many users",                                  \
   "Disc quota exceeded",                             \
   "Stale NFS file handle",                           \
   "Too many levels of remote in path",               \
   "RPC struct is bad",                               \
   "RPC version wrong",                               \
   "RPC prog. not avail",                             \
   "Program version wrong",                           \
   "Bad procedure for program",                       \
   "No locks available",                              \
   "Function not implemented",                        \
   "Inappropriate file type or format",               \
   "Authentication error",                            \
   "Need authenticator",                              \
   "Device power is off",                             \
   "Device error",                                    \
   "Value too large to be stored in data type",       \
   "Bad executable (or shared library)",              \
   "Bad CPU type in executable",                      \
   "Shared library version mismatch",                 \
   "Malformed Mach-o file",                           \
   "Operation canceled",                              \
   "Identifier removed",                              \
   "No message of desired type",                      \
   "Illegal byte sequence",                           \
   "Attribute not found",                             \
   "Bad message",                                     \
   "EMULTIHOP (Reserved)",                            \
   "No message available on STREAM",                  \
   "ENOLINK (Reserved)",                              \
   "No STREAM resources",                             \
   "Not a STREAM",                                    \
   "Protocol error",                                  \
   "STREAM ioctl timeout",                            \
   "Operation not supported on socket",               \
   "Policy not found",                                \
   "State not recoverable",                           \
   "Previous owner died",                             \
   "Interface output queue is full"};
#endif

#endif
