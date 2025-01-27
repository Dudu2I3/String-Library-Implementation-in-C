#include "tests.h"

START_TEST(my_strlen_1) {
  char str[] = "abcde";
  int str1 = my_strlen(str);
  int str2 = strlen(str);
  ck_assert_int_eq(str1, str2);
}
END_TEST

START_TEST(my_strlen_2) {
  char str[1] = "";
  int str1 = my_strlen(str);
  int str2 = strlen(str);
  ck_assert_int_eq(str1, str2);
}
END_TEST

START_TEST(my_strlen_3) {
  char str[] = "";
  int str1 = my_strlen(str);
  int str2 = strlen(str);
  ck_assert_int_eq(str1, str2);
}
END_TEST

START_TEST(my_strlen_4) {
  char str[] = "a\nb\nc\nd\0e\nf\ng\n";
  int str1 = my_strlen(str);
  int str2 = strlen(str);
  ck_assert_int_eq(str1, str2);
}
END_TEST

START_TEST(my_strlen_5) {
  char str[] = "A very long and very silly text to test string length";
  int str1 = my_strlen(str);
  int str2 = strlen(str);
  ck_assert_int_eq(str1, str2);
}
END_TEST

START_TEST(my_strlen_6) {
  char str[] = "abcdefg\0gfedcba";
  int str1 = my_strlen(str);
  int str2 = strlen(str);
  ck_assert_int_eq(str1, str2);
}
END_TEST

Suite *my_strlen_test(void) {
  Suite *suite = suite_create("\033[33m--my_strlen--\033[0m");
  TCase *tcase_core = tcase_create("strlen_tc");
  tcase_add_test(tcase_core, my_strlen_1);
  tcase_add_test(tcase_core, my_strlen_2);
  tcase_add_test(tcase_core, my_strlen_3);
  tcase_add_test(tcase_core, my_strlen_4);
  tcase_add_test(tcase_core, my_strlen_5);
  tcase_add_test(tcase_core, my_strlen_6);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
