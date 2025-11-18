#include "tests.h"

START_TEST(trim1) {
  const char src[] = " HELLO WORLD!";
  const char trim_cahrs[] = " !";
  char *for_test = s21_trim(src, trim_cahrs);
  ck_assert_str_eq("HELLO WORLD", for_test);
  if (for_test) free(for_test);
}
END_TEST

START_TEST(trim2) {
  const char src[] = " HELLO WORLD!";
  const char trim_cahrs[] = "";
  char *for_test = s21_trim(src, trim_cahrs);
  ck_assert_str_eq("HELLO WORLD!", for_test);
  if (for_test) free(for_test);
}
END_TEST

START_TEST(trim3) {
  const char src[] = "";
  const char trim_cahrs[] = " !";
  char *for_test = s21_trim(src, trim_cahrs);
  ck_assert_str_eq("", for_test);
  if (for_test) free(for_test);
}
END_TEST

START_TEST(all_empty) {
  const char str[] = "";
  const char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(str_empty) {
  const char str[] = "";
  const char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty) {
  const char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  const char trim_ch[] = "";
  char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
  const char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  const char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test1) {
  const char str[] = "+!!++Abo+ba++00";
  const char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test2) {
  const char str[] = "Ab000cd0";
  const char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test3) {
  const char str[] = "DoNotTouch";
  const char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test4) {
  const char str[] = "&* !!sc21 * **";
  const char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test5) {
  const char str[] = " Good morning!    ";
  const char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(empty_spaces) {
  const char str[] = "        abc         ";
  const char trim_ch[] = " ";
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trimt) {
  const char str[] = "\0";
  const char trim_ch[] = "abc";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);

  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *s21_trim_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_trim_test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, trim1);
  tcase_add_test(tc_core, trim2);
  tcase_add_test(tc_core, trim3);

  tcase_add_test(tc_core, all_empty);
  tcase_add_test(tc_core, str_empty);
  tcase_add_test(tc_core, trim_empty);
  tcase_add_test(tc_core, trim_and_str_eq);
  tcase_add_test(tc_core, trim_test1);
  tcase_add_test(tc_core, trim_test2);
  tcase_add_test(tc_core, trim_test3);
  tcase_add_test(tc_core, trim_test4);
  tcase_add_test(tc_core, trim_test5);
  tcase_add_test(tc_core, empty_spaces);
  tcase_add_test(tc_core, trimt);

  suite_add_tcase(s, tc_core);

  return s;
}
