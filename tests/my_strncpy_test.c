#include "tests.h"

START_TEST(my_strncpy_1) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char *str_test = "fghij";
  my_size_t n = 10;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_2) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char *str_test = "fgh";
  my_size_t n = 5;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_3) {
  char str1[12] = "abc";
  char str2[12] = "abc";
  char *str_test = "fghij";
  my_size_t n = 6;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_4) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char *str_test = "fghij";
  my_size_t n = 6;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_5) {
  char str1[12] = "";
  char str2[12] = "";
  char *str_test = "fghij";
  my_size_t n = 6;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_6) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char *str_test = "";
  my_size_t n = 5;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_7) {
  char str1[12] = "";
  char str2[12] = "";
  char *str_test = "";
  my_size_t n = 5;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_9) {
  char str1[12] = "abc\nde";
  char str2[12] = "abc\nde";
  char *str_test = "fghij";
  my_size_t n = 6;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_10) {
  char str1[12] = "abc\nde";
  char str2[12] = "abc\nde";
  char *str_test = "f\t\tij";
  my_size_t n = 6;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_11) {
  char str1[12] = "abc\0de";
  char str2[12] = "abc\0de";
  char *str_test = "f\t\tij";
  my_size_t n = 6;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_strncpy_12) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char *str_test = "f\0ij";
  my_size_t n = 6;
  my_strncpy(str1, str_test, n);
  strncpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *my_strncpy_test(void) {
  Suite *suite = suite_create("\033[33m--my_strncpy--\033[0m");
  TCase *tcase_core = tcase_create("strncpy_tc");
  tcase_add_test(tcase_core, my_strncpy_1);
  tcase_add_test(tcase_core, my_strncpy_2);
  tcase_add_test(tcase_core, my_strncpy_3);
  tcase_add_test(tcase_core, my_strncpy_4);
  tcase_add_test(tcase_core, my_strncpy_5);
  tcase_add_test(tcase_core, my_strncpy_6);
  tcase_add_test(tcase_core, my_strncpy_7);
  tcase_add_test(tcase_core, my_strncpy_9);
  tcase_add_test(tcase_core, my_strncpy_10);
  tcase_add_test(tcase_core, my_strncpy_11);
  tcase_add_test(tcase_core, my_strncpy_12);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
