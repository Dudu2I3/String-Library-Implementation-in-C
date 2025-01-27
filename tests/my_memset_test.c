#include "tests.h"

START_TEST(my_memset_1) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  char c = '$';
  my_size_t n = 3;
  my_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(my_memset_2) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  char c = '$';
  my_size_t n = 5;
  my_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(my_memset_3) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  char c = '\n';
  my_size_t n = 3;
  my_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(my_memset_4) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  char c = '$';
  my_size_t n = 0;
  my_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(my_memset_5) {
  char str1[10] = "ab";
  char str2[10] = "ab";
  char c = '$';
  my_size_t n = 9;
  my_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_memset_6) {
  char str1[10] = "";
  char str2[10] = "";
  char c = 'A';
  my_size_t n = 9;
  my_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *my_memset_test(void) {
  Suite *suite = suite_create("\033[33m--my_memset--\033[0m");
  TCase *tcase_core = tcase_create("memset_tc");
  tcase_add_test(tcase_core, my_memset_1);
  tcase_add_test(tcase_core, my_memset_2);
  tcase_add_test(tcase_core, my_memset_3);
  tcase_add_test(tcase_core, my_memset_4);
  tcase_add_test(tcase_core, my_memset_5);
  tcase_add_test(tcase_core, my_memset_6);
  suite_add_tcase(suite, tcase_core);
  return suite;
}