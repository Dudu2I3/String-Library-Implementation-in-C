#include "tests.h"

START_TEST(my_strcspn_1) {
  char *str1 = "abcde";
  char *str2 = "ace";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_2) {
  char *str1 = "abcde";
  char *str2 = "e";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_3) {
  char *str1 = "ABCDE";
  char *str2 = "ace";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_4) {
  char *str1 = "ABCDE";
  char *str2 = "acE";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_5) {
  char *str1 = "abcde";
  char *str2 = "jklt";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_6) {
  char *str1 = "abcde";
  char *str2 = "";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_7) {
  char *str1 = "";
  char *str2 = "fsda";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_8) {
  char *str1 = "abcde\t";
  char *str2 = "jkl\t";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_9) {
  char *str1 = "ab\0cde";
  char *str2 = "cde";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_strcspn_10) {
  char *str1 = "abcde";
  char *str2 = "\0cde";
  int i1 = my_strcspn(str1, str2);
  int i2 = strcspn(str1, str2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

Suite *my_strcspn_test(void) {
  Suite *suite = suite_create("\033[33m--my_strcspn--\033[0m");
  TCase *tcase_core = tcase_create("strcspn_tc");
  tcase_add_test(tcase_core, my_strcspn_1);
  tcase_add_test(tcase_core, my_strcspn_2);
  tcase_add_test(tcase_core, my_strcspn_3);
  tcase_add_test(tcase_core, my_strcspn_4);
  tcase_add_test(tcase_core, my_strcspn_5);
  tcase_add_test(tcase_core, my_strcspn_6);
  tcase_add_test(tcase_core, my_strcspn_7);
  tcase_add_test(tcase_core, my_strcspn_8);
  tcase_add_test(tcase_core, my_strcspn_9);
  tcase_add_test(tcase_core, my_strcspn_10);
  suite_add_tcase(suite, tcase_core);
  return suite;
}