#include "tests.h"
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

START_TEST(test_decimal_floating_point_f) {
  const char *input = "123.456";
  float s21_result = 0.0, std_result = 0.0;

  s21_sscanf(input, "%f", &s21_result);
  sscanf(input, "%f", &std_result);

  ck_assert_msg(fabs(s21_result - std_result) < 1e-6,
                "Expected %.6f, but got %.6f", std_result, s21_result);
}
END_TEST

START_TEST(test_scientific_notation_G) {
  const char *input = "1.23456789E+10";
  float s21_result = 0.0, std_result = 0.0;

  s21_sscanf(input, "%G", &s21_result);
  sscanf(input, "%G", &std_result);

  ck_assert_msg(fabs(s21_result - std_result) < 1e-6, "Expected %G, but got %G",
                std_result, s21_result);
}
END_TEST

START_TEST(test_scientific_notation_E) {
  const char *input = "6.02214076E23";
  float s21_result = 0.0, std_result = 0.0;

  s21_sscanf(input, "%E", &s21_result);
  sscanf(input, "%E", &std_result);

  ck_assert_msg(fabs(s21_result - std_result) < 1e-6, "Expected %E, but got %E",
                std_result, s21_result);
}
END_TEST

START_TEST(test_shortest_representation_g) {
  const char *input = "123.45";
  float s21_result = 0.0, std_result = 0.0;

  s21_sscanf(input, "%g", &s21_result);
  sscanf(input, "%g", &std_result);

  ck_assert_msg(fabs(s21_result - std_result) < 1e-6, "Expected %g, but got %g",
                std_result, s21_result);
}
END_TEST

START_TEST(test_unsigned_hexadecimal_x) {
  const char *input = "2a3f";
  unsigned int s21_result = 0, std_result = 0;

  s21_sscanf(input, "%x", &s21_result);
  sscanf(input, "%x", &std_result);

  ck_assert_msg(s21_result == std_result, "Expected %#x, but got %#x",
                std_result, s21_result);
}
END_TEST

START_TEST(test_unsigned_hexadecimal_X) {
  const char *input = "A2B4";
  unsigned int s21_result = 0, std_result = 0;

  s21_sscanf(input, "%X", &s21_result);
  sscanf(input, "%X", &std_result);

  ck_assert_msg(s21_result == std_result, "Expected %#X, but got %#X",
                std_result, s21_result);
}
END_TEST

START_TEST(test_width_description_fixed) {
  const char *input = "12345";
  int s21_result = 0, std_result = 0;

  s21_sscanf(input, "%2d", &s21_result);
  sscanf(input, "%2d", &std_result);

  ck_assert_msg(s21_result == std_result, "Expected %d, but got %d", std_result,
                s21_result);
}
END_TEST

START_TEST(test_width_description_string) {
  const char *input = "HelloWorld";
  char s21_result[6] = {0}, std_result[6] = {0};

  s21_sscanf(input, "%5s", s21_result);
  sscanf(input, "%5s", std_result);

  ck_assert_msg(strcmp(s21_result, std_result) == 0, "Expected %s, but got %s",
                std_result, s21_result);
}
END_TEST

START_TEST(test_width_suppression) {
  const char *input = "12345";
  int s21_result = 0, std_result = 0;

  s21_sscanf(input, "%*2d%d", &s21_result);
  sscanf(input, "%*2d%d", &std_result);

  ck_assert_msg(s21_result == std_result, "Expected %d, but got %d", std_result,
                s21_result);
}
END_TEST

START_TEST(test_width_suppression_string) {
  const char *input = "HelloWorld";
  char s21_result[6] = {0}, std_result[6] = {0};

  s21_sscanf(input, "%*5s%s", s21_result);
  sscanf(input, "%*5s%5s", std_result);

  ck_assert_msg(strcmp(s21_result, std_result) == 0, "Expected %s, but got %s",
                std_result, s21_result);
}
END_TEST

START_TEST(test_character_parsing) {
  const char input[] = "A";
  char expected, actual;

  sscanf(input, "%c", &expected);
  s21_sscanf(input, "%c", &actual);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(test_signed_decimal) {
  const char input[] = "-12345";
  int expected, actual;

  sscanf(input, "%d", &expected);
  s21_sscanf(input, "%d", &actual);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(test_signed_integer) {
  const char input[] = "0x1A";
  int expected, actual;

  sscanf(input, "%i", &expected);
  s21_sscanf(input, "%i", &actual);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(test_scientific_notation_e) {
  const char input[] = "1.23e4";
  float expected, actual;

  sscanf(input, "%e", &expected);
  s21_sscanf(input, "%e", &actual);

  ck_assert(fabs(expected - actual) < 1e-6);
}
END_TEST

START_TEST(test_unsigned_octal) {
  const char input[] = "0123";
  unsigned int expected, actual;

  sscanf(input, "%o", &expected);
  s21_sscanf(input, "%o", &actual);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(test_string_parsing) {
  const char input[] = "HelloWorld";
  char expected[50], actual[50];

  sscanf(input, "%49s", expected);
  s21_sscanf(input, "%s", actual);

  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(test_unsigned_decimal) {
  const char input[] = "123456";
  unsigned int expected, actual;

  sscanf(input, "%u", &expected);
  s21_sscanf(input, "%u", &actual);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(test_pointer_parsing) {
  const char input[] = "0x7fff5fbff8b0";
  void *expected, *actual;

  sscanf(input, "%p", &expected);
  s21_sscanf(input, "%p", &actual);

  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(test_number_of_characters) {
  const char input[] = "12345";
  int expected = 0, actual = 0;

  sscanf(input, "%d%n", &expected, &expected);
  s21_sscanf(input, "%d%n", &actual, &actual);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(test_percentage_parsing) {
  const char input[] = "%";
  int expected = 1, actual = 0;

  expected = sscanf(input, "%%");
  actual = s21_sscanf(input, "%%");

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(test_number_of_characters_spaces) {
  const char input[] = "12345";
  int expected = 0, actual = 0;

  sscanf(input, " %d %n", &expected, &expected);
  s21_sscanf(input, " %d %n", &actual, &actual);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(test_volody) {
  const char input[] = "123 0x4A 077";
  int s21_num1, s21_num2, s21_num3;
  int num1, num2, num3;

  s21_sscanf(input, "%i %i %i", &s21_num1, &s21_num2, &s21_num3);
  sscanf(input, "%i %i %i", &num1, &num2, &num3);

  ck_assert_int_eq(num1, s21_num1);
  ck_assert_int_eq(num2, s21_num2);
  ck_assert_int_eq(num3, s21_num3);
}
END_TEST

Suite *sscanf_suite(void) {
  Suite *s = suite_create("s21_sscanf");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_character_parsing);
  tcase_add_test(tc_core, test_signed_decimal);
  tcase_add_test(tc_core, test_signed_integer);
  tcase_add_test(tc_core, test_scientific_notation_e);
  tcase_add_test(tc_core, test_unsigned_octal);
  tcase_add_test(tc_core, test_string_parsing);
  tcase_add_test(tc_core, test_unsigned_decimal);
  tcase_add_test(tc_core, test_pointer_parsing);
  tcase_add_test(tc_core, test_number_of_characters);
  tcase_add_test(tc_core, test_percentage_parsing);
  tcase_add_test(tc_core, test_decimal_floating_point_f);

  tcase_add_test(tc_core, test_scientific_notation_G);
  tcase_add_test(tc_core, test_scientific_notation_E);
  tcase_add_test(tc_core, test_shortest_representation_g);
  tcase_add_test(tc_core, test_unsigned_hexadecimal_x);
  tcase_add_test(tc_core, test_unsigned_hexadecimal_X);
  tcase_add_test(tc_core, test_width_description_fixed);
  tcase_add_test(tc_core, test_width_description_string);
  tcase_add_test(tc_core, test_width_suppression);
  tcase_add_test(tc_core, test_width_suppression_string);

  tcase_add_test(tc_core, test_number_of_characters_spaces);
  tcase_add_test(tc_core, test_volody);

  suite_add_tcase(s, tc_core);
  return s;
}
