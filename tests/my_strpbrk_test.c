#include "tests.h"

START_TEST(my_strpbrk_1) {
  char str1[12] = "abcde";
  char str2[12] = "edc";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_2) {
  char str1[12] = "abcde";
  char str2[12] = "e";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_3) {
  char str1[12] = "abcde";
  char str2[12] = "A";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_4) {
  char str1[12] = "abcde";
  char str2[12] = "";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_5) {
  char str1[12] = "";
  char str2[12] = "abc";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_6) {
  char str1[12] = "";
  char str2[12] = "";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_7) {
  char str1[12] = "abc\tde";
  char str2[12] = "\t";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_8) {
  char str1[12] = "abc\0de";
  char str2[12] = "\0";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_9) {
  char str1[12] = "abc\0de";
  char str2[12] = "de";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strpbrk_10) {
  char str1[12] = "abcde";
  char str2[12] = "\0abcde";
  char *s1 = my_strpbrk(str1, str2);
  char *s2 = strpbrk(str1, str2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *my_strpbrk_test(void) {
  Suite *suite = suite_create("\033[33m--my_strpbrk--\033[0m");
  TCase *tcase_core = tcase_create("strpbrk_tc");
  tcase_add_test(tcase_core, my_strpbrk_1);
  tcase_add_test(tcase_core, my_strpbrk_2);
  tcase_add_test(tcase_core, my_strpbrk_3);
  tcase_add_test(tcase_core, my_strpbrk_4);
  tcase_add_test(tcase_core, my_strpbrk_5);
  tcase_add_test(tcase_core, my_strpbrk_6);
  tcase_add_test(tcase_core, my_strpbrk_7);
  tcase_add_test(tcase_core, my_strpbrk_8);
  tcase_add_test(tcase_core, my_strpbrk_9);
  tcase_add_test(tcase_core, my_strpbrk_10);
  suite_add_tcase(suite, tcase_core);
  return suite;
}