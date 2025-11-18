#include "tests.h"

START_TEST(test_d) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  int n = 42;

  s21_sprintf(s21_buffer, "%5d", n);
  sprintf(std_buffer, "%5d", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_d_flags) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  int n = 42;

  s21_sprintf(s21_buffer, "%+d", n);
  sprintf(std_buffer, "%+d", n);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "% d", n);
  sprintf(std_buffer, "% d", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_c_width) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  char n = 'A';

  s21_sprintf(s21_buffer, "%5c", n);
  sprintf(std_buffer, "%5c", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  char *n = "Hello, world!";

  s21_sprintf(s21_buffer, "%10.5s", n);
  sprintf(std_buffer, "%10.5s", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_u_h) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  unsigned short n = 65000;

  s21_sprintf(s21_buffer, "%hu", n);
  sprintf(std_buffer, "%hu", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_u_l) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  unsigned long n = 4294967295;

  s21_sprintf(s21_buffer, "%lu", n);
  sprintf(std_buffer, "%lu", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_f) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  double n = 3.14159;

  s21_sprintf(s21_buffer, "%+.2f", n);
  sprintf(std_buffer, "%+.2f", n);
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "% .3f", n);
  sprintf(std_buffer, "% .3f", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_prozent) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};

  s21_sprintf(s21_buffer, "%%");
  sprintf(std_buffer, "%%");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

// valitsa
START_TEST(f_minus) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  double n = 3.14;

  s21_sprintf(s21_buffer, "%-10.2f", n);
  sprintf(std_buffer, "%-10.2f", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_d_minus) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  int n = -42;

  s21_sprintf(s21_buffer, "%5d", n);
  sprintf(std_buffer, "%5d", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_minus_d) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  int n = 3;

  s21_sprintf(s21_buffer, "%-2d", n);
  sprintf(std_buffer, "%-2d", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_text_after_procent) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  int n = 3;

  s21_sprintf(s21_buffer, "text first %-2d text second", n);
  sprintf(std_buffer, "text first %-2d text second", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(flag_d_with_zero) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  int n = 3;

  s21_sprintf(s21_buffer, "text first %05d text second", n);
  sprintf(std_buffer, "text first %05d text second", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_spec_d_long) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  long n = 1234567890L;

  s21_sprintf(s21_buffer, "%ld", n);
  sprintf(std_buffer, "%ld", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_spec_d_short) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  short n = 12345;

  s21_sprintf(s21_buffer, "%hd", n);
  sprintf(std_buffer, "%hd", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_d_probl) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  int n = 123;

  s21_sprintf(s21_buffer, "%- d", n);
  sprintf(std_buffer, "%- d", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_spec_d_pluss) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  int n = 123;

  s21_sprintf(s21_buffer, "%-+d", n);
  sprintf(std_buffer, "%-+d", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_spec_c_minus) {
  char s21_buffer[100] = {0};
  char std_buffer[100] = {0};
  char n = 'S';

  s21_sprintf(s21_buffer, "%-10c", n);
  sprintf(std_buffer, "%-10c", n);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(simple_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "must be 100 :  %d";
  int val = 100;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "%5d";
  int val = 100;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_precision_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "%5.5d";
  int val = 100;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(negative_width_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "%-5d";
  int val = 100;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(positive_width_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "%+5d";
  int val = 100;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_plus_width_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "%05d";
  int val = 100;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(long_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "%-17.11ld";
  long int val = 2345678907689;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(short_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "%+17.11hd";
  short int val = -567;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "% d";
  short int val = 2034;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_prec_int) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.0d";
  short int val = -567;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_simple) {
  char str1[1024];
  char str2[1024];

  const char *format = "%u";
  unsigned int val = 123123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_width) {
  char str1[1024];
  char str2[1024];

  const char *format = "%15u";
  unsigned int val = 123123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_precision) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.15u";
  unsigned int val = 123123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_minus) {
  char str1[1024];
  char str2[1024];

  const char *format = "%-15u";
  unsigned int val = 123123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_plus) {
  char str1[1024];
  char str2[1024];

  const char *format = "%-15u";
  unsigned int val = 123123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_6) {
  char str1[1024];
  char str2[1024];

  const char *format = "% -15.5u";
  unsigned int val = 123123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_8) {
  char str1[1024];
  char str2[1024];

  const char *format = "%lu";
  unsigned long int val = 123123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_ultimate) {
  char str1[1024];
  char str2[1024];

  const char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, (unsigned)14, (unsigned short)1441,
                  (unsigned)14414, (unsigned)9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(simple_c) {
  char str1[1024];
  char str2[1024];

  const char *format = "%c";
  char val = 'A';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(multiple_c) {
  char str1[1024];
  char str2[1024];

  const char *format = "%c %c %c";
  char val1 = 'X', val2 = 'Y', val3 = 'Z';
  ck_assert_int_eq(s21_sprintf(str1, format, val1, val2, val3),
                   sprintf(str2, format, val1, val2, val3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(simple_s) {
  char str1[1024];
  char str2[1024];

  const char *format = "%s";
  char *val = "Hello, world!";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_s) {
  char str1[1024];
  char str2[1024];

  const char *format = "%20s";
  char *val = "Hello";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(simple_f) {
  char str1[1024];
  char str2[1024];

  const char *format = "%f";
  double val = 123.456;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precision_f) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.5f";
  double val = 123.456789;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(count_written_chars_n) {
//   char str1[1024];
//   char str2[1024];
//   int count1 = 0, count2 = 0;

//   const char *format = "Hello, world! %n";
//   s21_sprintf(str1, format, &count1);
//   sprintf(str2, format, &count2);

//   ck_assert_int_eq(count1, count2);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(multiple_n_specifiers) {
//   char str1[1024];
//   char str2[1024];
//   int count1[3] = {0}, count2[3] = {0};

//   const char *format = "Test %d%n, %% another %s%n, and final %f%n";
//   s21_sprintf(str1, format, 42, &count1[0], "string", &count1[1], 3.14,
//               &count1[2]);
//   sprintf(str2, format, 42, &count2[0], "string", &count2[1], 3.14,
//   &count2[2]);

//   ck_assert_int_eq(count1[0], count2[0]);
//   ck_assert_int_eq(count1[1], count2[1]);
//   ck_assert_int_eq(count1[2], count2[2]);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(f_3) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.1f";
  double val = 2.99;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_simple) {
  char str1[1024];
  char str2[1024];

  const char *format = "%c";
  char val = 'A';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_presicion) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.12c";
  char val = 'A';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_flags) {
  char str1[1024];
  char str2[1024];

  const char *format = "%-5.12c";
  char val = 'A';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(char_flags2) {
  char str1[1024];
  char str2[1024];

  const char *format = "%5.12c";
  char val = 'A';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(char_many) {
  char str1[1024];
  char str2[1024];

  const char *format = "%-5.3cHello, World!";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[1024];
  char str2[1024];

  const char *format = "%s";
  char *val = "Hello, World";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

START_TEST(string2) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.15s";
  char *val = "Hello, World";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
START_TEST(string3) {
  char str1[1024];
  char str2[1024];

  const char *format = "%-5.15s";
  char *val = "Hello, World";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

START_TEST(string4) {
  char str1[1024];
  char str2[1024];

  const char *format = "%-40.15s";
  char *val = "Hello, World";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

Suite *s21_sprintf_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_d);
  tcase_add_test(tc_core, test_d_flags);
  tcase_add_test(tc_core, test_c_width);
  tcase_add_test(tc_core, test_s);
  tcase_add_test(tc_core, test_u_h);
  tcase_add_test(tc_core, test_u_l);
  tcase_add_test(tc_core, test_f);
  tcase_add_test(tc_core, test_prozent);
  tcase_add_test(tc_core, f_minus);
  tcase_add_test(tc_core, test_d_minus);
  tcase_add_test(tc_core, test_minus_d);
  tcase_add_test(tc_core, test_text_after_procent);
  tcase_add_test(tc_core, flag_d_with_zero);
  tcase_add_test(tc_core, test_spec_d_long);
  tcase_add_test(tc_core, test_spec_d_short);
  tcase_add_test(tc_core, test_d_probl);
  tcase_add_test(tc_core, test_spec_d_pluss);
  tcase_add_test(tc_core, test_spec_c_minus);

  tcase_add_test(tc_core, simple_int);
  tcase_add_test(tc_core, width_int);
  tcase_add_test(tc_core, width_precision_int);
  tcase_add_test(tc_core, negative_width_int);
  tcase_add_test(tc_core, positive_width_int);
  tcase_add_test(tc_core, zero_plus_width_int);
  tcase_add_test(tc_core, long_int);
  tcase_add_test(tc_core, short_int);
  tcase_add_test(tc_core, space_int);
  tcase_add_test(tc_core, zero_prec_int);
  tcase_add_test(tc_core, unsigned_simple);
  tcase_add_test(tc_core, unsigned_width);
  tcase_add_test(tc_core, unsigned_precision);
  tcase_add_test(tc_core, unsigned_minus);
  tcase_add_test(tc_core, unsigned_plus);
  tcase_add_test(tc_core, unsigned_6);
  tcase_add_test(tc_core, unsigned_8);
  tcase_add_test(tc_core, unsigned_ultimate);
  tcase_add_test(tc_core, f_3);
  tcase_add_test(tc_core, simple_c);
  tcase_add_test(tc_core, multiple_c);
  tcase_add_test(tc_core, simple_s);
  tcase_add_test(tc_core, width_s);
  tcase_add_test(tc_core, simple_f);
  tcase_add_test(tc_core, precision_f);
  tcase_add_test(tc_core, char_simple);
  tcase_add_test(tc_core, char_presicion);
  tcase_add_test(tc_core, char_flags);
  tcase_add_test(tc_core, char_flags2);
  tcase_add_test(tc_core, char_many);

  tcase_add_test(tc_core, string);
  tcase_add_test(tc_core, string2);
  tcase_add_test(tc_core, string3);
  tcase_add_test(tc_core, string4);

  suite_add_tcase(s, tc_core);

  return s;
}