#include "tests.h"

START_TEST(my_strstr_1) {
  char str1[12] = "abcde";
  char str2[12] = "cde";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_2) {
  char str1[12] = "abcdcdcdcde";
  char str2[12] = "cde";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_3) {
  char str1[12] = "abcccccccde";
  char str2[12] = "cde";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_4) {
  char str1[30] = "A very long string to test";
  char str2[12] = "test";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_5) {
  char str1[12] = "abcde";
  char str2[12] = "cDe";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_6) {
  char str1[12] = "abcde";
  char str2[12] = "c";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_7) {
  char str1[12] = "";
  char str2[12] = "cde";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_8) {
  char str1[12] = "abcde";
  char str2[12] = "";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_9) {
  char str1[12] = "";
  char str2[12] = "";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_10) {
  char str1[12] = "abc\tde";
  char str2[12] = "cde";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_11) {
  char str1[12] = "abc\tde";
  char str2[12] = "c\tde";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_12) {
  char str1[12] = "abc\td\0e";
  char str2[12] = "c\tde";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_13) {
  char str1[12] = "abcde";
  char str2[12] = "cde\0";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strstr_14) {
  char str1[12] = "abcde";
  char str2[12] = "\0cde";
  char *s1 = my_strstr(str1, str2);
  char *s2 = strstr(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *my_strstr_test(void) {
  Suite *suite = suite_create("\033[33m--my_strstr--\033[0m");
  TCase *tcase_core = tcase_create("strstr_tc");
  tcase_add_test(tcase_core, my_strstr_1);
  tcase_add_test(tcase_core, my_strstr_2);
  tcase_add_test(tcase_core, my_strstr_3);
  tcase_add_test(tcase_core, my_strstr_4);
  tcase_add_test(tcase_core, my_strstr_5);
  tcase_add_test(tcase_core, my_strstr_6);
  tcase_add_test(tcase_core, my_strstr_7);
  tcase_add_test(tcase_core, my_strstr_8);
  tcase_add_test(tcase_core, my_strstr_9);
  tcase_add_test(tcase_core, my_strstr_10);
  tcase_add_test(tcase_core, my_strstr_11);
  tcase_add_test(tcase_core, my_strstr_12);
  tcase_add_test(tcase_core, my_strstr_13);
  tcase_add_test(tcase_core, my_strstr_14);
  suite_add_tcase(suite, tcase_core);
  return suite;
}