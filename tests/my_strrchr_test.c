#include "tests.h"

START_TEST(my_strrchr_1) {
  char str1[12] = "abcdea";
  char ch = 'a';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_2) {
  char str1[12] = "aaaaaabcde";
  char ch = 'a';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_3) {
  char str1[12] = "acdeb";
  char ch = 'b';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_4) {
  char str1[12] = "aaaaaabcde";
  char ch = 'A';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_5) {
  char str1[12] = "";
  char ch = 'A';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_6) {
  char str1[12] = "abcde   ";
  char ch = ' ';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_7) {
  char str1[12] = "abcde";
  char ch = 97;
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_8) {
  char str1[12] = "ab\t\tcde";
  char ch = '\t';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_9) {
  char str1[12] = "abcde";
  char ch = '\0';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_10) {
  char str1[12] = "abc\0de";
  char ch = 'e';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_11) {
  char str1[12] = "abccba\0bde";
  char ch = 'b';
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strrchr_12) {
  char str1[12] = "abcde";
  char ch = -1;
  char *s1 = my_strrchr(str1, ch);
  char *s2 = strrchr(str1, ch);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *my_strrchr_test(void) {
  Suite *suite = suite_create("\033[33m--my_strrchr--\033[0m");
  TCase *tcase_core = tcase_create("strrchr_tc");
  tcase_add_test(tcase_core, my_strrchr_1);
  tcase_add_test(tcase_core, my_strrchr_2);
  tcase_add_test(tcase_core, my_strrchr_3);
  tcase_add_test(tcase_core, my_strrchr_4);
  tcase_add_test(tcase_core, my_strrchr_5);
  tcase_add_test(tcase_core, my_strrchr_6);
  tcase_add_test(tcase_core, my_strrchr_7);
  tcase_add_test(tcase_core, my_strrchr_8);
  tcase_add_test(tcase_core, my_strrchr_9);
  tcase_add_test(tcase_core, my_strrchr_10);
  tcase_add_test(tcase_core, my_strrchr_11);
  tcase_add_test(tcase_core, my_strrchr_12);
  suite_add_tcase(suite, tcase_core);
  return suite;
}