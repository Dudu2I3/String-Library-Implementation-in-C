#include "tests.h"

START_TEST(my_memcpy_1) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  const char *str_test = "efgch";
  my_size_t n = 5;
  my_memcpy(str1, str_test, n);
  memcpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_memcpy_2) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  const char *str_test = "efgch";
  my_size_t n = 3;
  my_memcpy(str1, str_test, n);
  memcpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_memcpy_3) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  const char *str_test = "efgch";
  my_size_t n = 0;
  my_memcpy(str1, str_test, n);
  memcpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_memcpy_4) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  const char *str_test = "bg";
  my_size_t n = 3;
  my_memcpy(str1, str_test, n);
  memcpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_memcpy_5) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  const char *str_test = "fgfgfgfgf";
  my_size_t n = 10;
  my_memcpy(str1, str_test, n);
  memcpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(my_memcpy_6) {
  char str1[10] = "abcde";
  char str2[10] = "abcde";
  const char *str_test = "\t\t\tabcde\t";
  my_size_t n = 10;
  my_memcpy(str1, str_test, n);
  memcpy(str2, str_test, n);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *my_memcpy_test(void) {
  Suite *suite = suite_create("\033[33m--my_memcpy--\033[0m");
  TCase *tcase_core = tcase_create("memcpy_tc");
  tcase_add_test(tcase_core, my_memcpy_1);
  tcase_add_test(tcase_core, my_memcpy_2);
  tcase_add_test(tcase_core, my_memcpy_3);
  tcase_add_test(tcase_core, my_memcpy_4);
  tcase_add_test(tcase_core, my_memcpy_5);
  tcase_add_test(tcase_core, my_memcpy_6);
  suite_add_tcase(suite, tcase_core);
  return suite;
}