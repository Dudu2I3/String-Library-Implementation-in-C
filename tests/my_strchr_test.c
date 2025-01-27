#include "tests.h"

START_TEST(my_strchr_1) {
  char *str1 = "abcde";
  char *s1 = my_strchr(str1, 'a');
  char *s2 = strchr(str1, 'a');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_2) {
  char *str1 = "abcde";
  char *s1 = my_strchr(str1, 'e');
  char *s2 = strchr(str1, 'e');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_3) {
  char *str1 = "abcde";
  char *s1 = my_strchr(str1, 'h');
  char *s2 = strchr(str1, 'h');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_4) {
  char *str1 = "abcde";
  char *s1 = my_strchr(str1, '\0');
  char *s2 = strchr(str1, '\0');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_5) {
  char *str1 = "ab\0cde";
  char *s1 = my_strchr(str1, 'c');
  char *s2 = strchr(str1, 'c');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_6) {
  char *str1 = "ab\0cde";
  char *s1 = my_strchr(str1, 'b');
  char *s2 = strchr(str1, 'b');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_7) {
  char *str1 = "abcde\t";
  char *s1 = my_strchr(str1, '\t');
  char *s2 = strchr(str1, '\t');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_8) {
  char *str1 = "";
  char *s1 = my_strchr(str1, 'a');
  char *s2 = strchr(str1, 'a');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_9) {
  char *str1 = "";
  char *s1 = my_strchr(str1, 0);
  char *s2 = strchr(str1, 0);
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

START_TEST(my_strchr_10) {
  char *str1 = "ABCDE";
  char *s1 = my_strchr(str1, 'a');
  char *s2 = strchr(str1, 'a');
  ck_assert_ptr_eq(s1, s2);
}
END_TEST

Suite *my_strchr_test(void) {
  Suite *suite = suite_create("\033[33m--my_strchr--\033[0m");
  TCase *tcase_core = tcase_create("strchr_tc");
  tcase_add_test(tcase_core, my_strchr_1);
  tcase_add_test(tcase_core, my_strchr_2);
  tcase_add_test(tcase_core, my_strchr_3);
  tcase_add_test(tcase_core, my_strchr_4);
  tcase_add_test(tcase_core, my_strchr_5);
  tcase_add_test(tcase_core, my_strchr_6);
  tcase_add_test(tcase_core, my_strchr_7);
  tcase_add_test(tcase_core, my_strchr_8);
  tcase_add_test(tcase_core, my_strchr_9);
  tcase_add_test(tcase_core, my_strchr_10);
  suite_add_tcase(suite, tcase_core);
  return suite;
}