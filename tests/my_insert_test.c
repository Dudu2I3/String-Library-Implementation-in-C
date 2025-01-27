#include "tests.h"

START_TEST(my_insert_1) {
  char str1[] = "abefg";
  char str2[] = "cd";
  my_size_t n = 2;
  char *str_result1 = my_insert(str1, str2, n);
  char str_result2[] = "abcdefg";
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_2) {
  char str1[] = "cdefg";
  char str2[] = "ab";
  my_size_t n = 0;
  char *str_result1 = my_insert(str1, str2, n);
  char str_result2[] = "abcdefg";
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_3) {
  char str1[] = "abcde";
  char str2[] = "fg";
  my_size_t n = 5;
  char *str_result1 = my_insert(str1, str2, n);
  char str_result2[] = "abcdefg";
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_4) {
  char str1[] = "abcdefg";
  char str2[] = "";
  my_size_t n = 5;
  char *str_result1 = my_insert(str1, str2, n);
  char str_result2[] = "abcdefg";
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_5) {
  char str1[] = "";
  char str2[] = "abcdefg";
  my_size_t n = 0;
  char *str_result1 = my_insert(str1, str2, n);
  char str_result2[] = "abcdefg";
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_6) {
  char str1[] = "abefg";
  char str2[] = "cd";
  my_size_t n = 9;
  char *str_result1 = my_insert(str1, str2, n);
  char *str_result2 = NULL;
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_7) {
  char str1[] = "";
  char str2[] = "";
  my_size_t n = 0;
  char *str_result1 = my_insert(str1, str2, n);
  char *str_result2 = "";
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_8) {
  char str1[] = "abcdefg";
  char *str2 = NULL;
  my_size_t n = 0;
  char *str_result1 = my_insert(str1, str2, n);
  char *str_result2 = NULL;
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_9) {
  char *str1 = NULL;
  char str2[] = "abcdefg";
  my_size_t n = 0;
  char *str_result1 = my_insert(str1, str2, n);
  char *str_result2 = NULL;
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_10) {
  char *str1 = NULL;
  char *str2 = NULL;
  my_size_t n = 0;
  char *str_result1 = my_insert(str1, str2, n);
  char *str_result2 = NULL;
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_11) {
  char str1[] = "ab\0cdefg";
  char str2[] = "abc\0defg";
  my_size_t n = 3;
  char *str_result1 = my_insert(str1, str2, n);
  char *str_result2 = NULL;
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_12) {
  char str1[] = "ab\ncdefg";
  char str2[] = "abc\ndefg";
  my_size_t n = 3;
  char *str_result1 = my_insert(str1, str2, n);
  char str_result2[] = "ab\nabc\ndefgcdefg";
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_13) {
  char str1[] = "ab\ncdefg";
  char str2[] = "abc\ndefg";
  my_size_t n = -5;
  char *str_result1 = my_insert(str1, str2, n);
  char *str_result2 = NULL;
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

START_TEST(my_insert_14) {
  char str1[] = "abfg";
  char str2[] = "cefg";
  my_size_t n = -1;
  char *str_result1 = my_insert(str1, str2, n);
  char *str_result2 = NULL;
  ck_assert_pstr_eq(str_result1, str_result2);
  if (str_result1) free(str_result1);
}
END_TEST

Suite *my_insert_test(void) {
  Suite *suite = suite_create("\033[33m--my_insert--\033[0m");
  TCase *tcase_core = tcase_create("insert_tc");
  tcase_add_test(tcase_core, my_insert_1);
  tcase_add_test(tcase_core, my_insert_2);
  tcase_add_test(tcase_core, my_insert_3);
  tcase_add_test(tcase_core, my_insert_4);
  tcase_add_test(tcase_core, my_insert_5);
  tcase_add_test(tcase_core, my_insert_6);
  tcase_add_test(tcase_core, my_insert_7);
  tcase_add_test(tcase_core, my_insert_8);
  tcase_add_test(tcase_core, my_insert_9);
  tcase_add_test(tcase_core, my_insert_10);
  tcase_add_test(tcase_core, my_insert_11);
  tcase_add_test(tcase_core, my_insert_12);
  tcase_add_test(tcase_core, my_insert_13);
  tcase_add_test(tcase_core, my_insert_14);
  suite_add_tcase(suite, tcase_core);
  return suite;
}