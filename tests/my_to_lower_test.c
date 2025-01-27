#include "tests.h"

START_TEST(my_to_lower_1) {
  char str1[12] = "ABCDE";
  char str2[12] = "abcde";
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_to_lower_2) {
  char str1[12] = "AbcdE";
  char str2[12] = "abcde";
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_to_lower_3) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_to_lower_4) {
  char str1[12] = "";
  char str2[12] = "";
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_to_lower_5) {
  char str1[12] = "12345";
  char str2[12] = "12345";
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_to_lower_6) {
  char str1[12] = "ABC\0DE";
  char str2[12] = "abc";
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_to_lower_7) {
  char str1[12] = "\0ABC\tDE";
  char str2[12] = "";
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_to_lower_8) {
  char str1[12] = "ABC\tDE";
  char str2[12] = "abc\tde";
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_to_lower_9) {
  char *str1 = my_NULL;
  char *str2 = NULL;
  char *s1 = my_to_lower(str1);
  char *s2 = str2;
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *my_to_lower_test(void) {
  Suite *suite = suite_create("\033[33m--my_to_lower--\033[0m");
  TCase *tcase_core = tcase_create("to_lower_tc");
  tcase_add_test(tcase_core, my_to_lower_1);
  tcase_add_test(tcase_core, my_to_lower_2);
  tcase_add_test(tcase_core, my_to_lower_3);
  tcase_add_test(tcase_core, my_to_lower_4);
  tcase_add_test(tcase_core, my_to_lower_5);
  tcase_add_test(tcase_core, my_to_lower_6);
  tcase_add_test(tcase_core, my_to_lower_7);
  tcase_add_test(tcase_core, my_to_lower_8);
  tcase_add_test(tcase_core, my_to_lower_9);
  suite_add_tcase(suite, tcase_core);
  return suite;
}