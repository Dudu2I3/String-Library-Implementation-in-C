#include "tests.h"

START_TEST(my_strncmp_1) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  my_size_t n = 5;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_2) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  my_size_t n = 3;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_3) {
  char str1[12] = "abcdf";
  char str2[12] = "abcdF";
  my_size_t n = 5;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_4) {
  char str1[12] = "abcdE";
  char str2[12] = "abcde";
  my_size_t n = 3;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_5) {
  char str1[12] = "abcdE";
  char str2[12] = "abcde";
  my_size_t n = 0;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_6) {
  char str1[12] = "";
  char str2[12] = "";
  my_size_t n = 0;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_7) {
  char str1[12] = "";
  char str2[12] = "";
  my_size_t n = 5;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_8) {
  char str1[12] = "abcde\n";
  char str2[12] = "abcde\n";
  my_size_t n = 6;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_9) {
  char str1[12] = "ab\0cde\n";
  char str2[12] = "ab\0cde\n";
  my_size_t n = 7;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strncmp_10) {
  char str1[12] = "abc\0de\n";
  char str2[12] = "ab\0cde\n";
  my_size_t n = 7;
  int i1 = my_strncmp(str1, str2, n);
  int i2 = strncmp(str1, str2, n);
  if (i1 > 0 || i1 < 0) i1 = (i1 > 0) * (i1 / i1) + (i1 < 0) * (i1 / -i1);
  if (i2 > 0 || i2 < 0) i2 = (i2 > 0) * (i2 / i2) + (i2 < 0) * (i2 / -i2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

Suite *my_strncmp_test(void) {
  Suite *suite = suite_create("\033[33m--my_strncmp--\033[0m");
  TCase *tcase_core = tcase_create("strncmp_tc");
  tcase_add_test(tcase_core, my_strncmp_1);
  tcase_add_test(tcase_core, my_strncmp_2);
  tcase_add_test(tcase_core, my_strncmp_3);
  tcase_add_test(tcase_core, my_strncmp_4);
  tcase_add_test(tcase_core, my_strncmp_5);
  tcase_add_test(tcase_core, my_strncmp_6);
  tcase_add_test(tcase_core, my_strncmp_7);
  tcase_add_test(tcase_core, my_strncmp_8);
  tcase_add_test(tcase_core, my_strncmp_9);
  tcase_add_test(tcase_core, my_strncmp_10);
  suite_add_tcase(suite, tcase_core);
  return suite;
}