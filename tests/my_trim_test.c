#include "tests.h"

START_TEST(my_trim_1) {
  char str1[12] = "aabcdee";
  char str2[12] = "bcd";
  char str_trim[12] = "ae";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
  free(s1);
}
END_TEST

START_TEST(my_trim_2) {
  char str1[12] = "aaabcde";
  char str2[12] = "bcde";
  char str_trim[12] = "a";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
  free(s1);
}
END_TEST

START_TEST(my_trim_3) {
  char str1[12] = "abcdeee";
  char str2[12] = "abcd";
  char str_trim[12] = "e";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
  free(s1);
}
END_TEST

START_TEST(my_trim_4) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char str_trim[12] = "bcd";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
  free(s1);
}
END_TEST

START_TEST(my_trim_5) {
  char str1[12] = "abcde";
  char *str2 = NULL;
  char str_trim[12] = "abcde";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_trim_6) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char str_trim[12] = "ABCDE";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
  free(s1);
}
END_TEST

START_TEST(my_trim_7) {
  char str1[12] = "";
  char *str2 = NULL;
  char str_trim[12] = "ABCDE";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_trim_8) {
  char str1[12] = "";
  char *str2 = NULL;
  char str_trim[12] = "\0";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_trim_9) {
  char str1[12] = "\t\tabcde\t\t";
  char str2[12] = "abcde";
  char str_trim[12] = "\t";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
  free(s1);
}
END_TEST

START_TEST(my_trim_10) {
  char str1[12] = "\t\ta\tbcd\te\t\t";
  char str2[12] = "a\tbcd\te";
  char str_trim[12] = "\t";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
  free(s1);
}
END_TEST

START_TEST(my_trim_11) {
  char str1[12] = "abc\0de";
  char str2[12] = "b";
  char str_trim[12] = "ac";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
  free(s1);
}
END_TEST

START_TEST(my_trim_12) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char str_trim[12] = "\0ae";
  char *s1 = my_trim(str1, str_trim);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
  free(s1);
}
END_TEST

Suite *my_trim_test(void) {
  Suite *suite = suite_create("\033[33m--my_trim--\033[0m");
  TCase *tcase_core = tcase_create("trim_tc");
  tcase_add_test(tcase_core, my_trim_1);
  tcase_add_test(tcase_core, my_trim_2);
  tcase_add_test(tcase_core, my_trim_3);
  tcase_add_test(tcase_core, my_trim_4);
  tcase_add_test(tcase_core, my_trim_5);
  tcase_add_test(tcase_core, my_trim_6);
  tcase_add_test(tcase_core, my_trim_7);
  tcase_add_test(tcase_core, my_trim_8);
  tcase_add_test(tcase_core, my_trim_9);
  tcase_add_test(tcase_core, my_trim_10);
  tcase_add_test(tcase_core, my_trim_11);
  tcase_add_test(tcase_core, my_trim_12);
  suite_add_tcase(suite, tcase_core);
  return suite;
}