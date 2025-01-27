#include "tests.h"

START_TEST(my_strncat_1) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char str_test[6] = "fghij";
  my_size_t n = 5;
  char* s1 = my_strncat(str1, str_test, n);
  char* s2 = strncat(str2, str_test, n);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strncat_2) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char str_test[6] = "f";
  my_size_t n = 5;
  char* s1 = my_strncat(str1, str_test, n);
  char* s2 = strncat(str2, str_test, n);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strncat_3) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char str_test[6] = "";
  my_size_t n = 5;
  char* s1 = my_strncat(str1, str_test, n);
  char* s2 = strncat(str2, str_test, n);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strncat_4) {
  char str1[12] = "";
  char str2[12] = "";
  char str_test[6] = "abcde";
  my_size_t n = 5;
  char* s1 = my_strncat(str1, str_test, n);
  char* s2 = strncat(str2, str_test, n);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strncat_5) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char str_test[6] = "abcde";
  my_size_t n = 3;
  char* s1 = my_strncat(str1, str_test, n);
  char* s2 = strncat(str2, str_test, n);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strncat_6) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char str_test[6] = "abcde";
  my_size_t n = 0;
  char* s1 = my_strncat(str1, str_test, n);
  char* s2 = strncat(str2, str_test, n);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strncat_7) {
  char str1[12] = "abcde\n";
  char str2[12] = "abcde\n";
  char str_test[6] = "abcde";
  my_size_t n = 5;
  char* s1 = my_strncat(str1, str_test, n);
  char* s2 = strncat(str2, str_test, n);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strncat_8) {
  char str1[12] = "";
  char str2[12] = "";
  char str_test[6] = "";
  my_size_t n = 0;
  char* s1 = my_strncat(str1, str_test, n);
  char* s2 = strncat(str2, str_test, n);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite* my_strncat_test(void) {
  Suite* suite = suite_create("\033[33m--my_strncat--\033[0m");
  TCase* tcase_core = tcase_create("strncat_tc");
  tcase_add_test(tcase_core, my_strncat_1);
  tcase_add_test(tcase_core, my_strncat_2);
  tcase_add_test(tcase_core, my_strncat_3);
  tcase_add_test(tcase_core, my_strncat_4);
  tcase_add_test(tcase_core, my_strncat_5);
  tcase_add_test(tcase_core, my_strncat_6);
  tcase_add_test(tcase_core, my_strncat_7);
  tcase_add_test(tcase_core, my_strncat_8);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
