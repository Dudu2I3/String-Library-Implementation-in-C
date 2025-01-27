#include "tests.h"

START_TEST(my_memcmp_1) {
  char *str1 = "abcde";
  char *str2 = "abcde";
  my_size_t n = 5;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_2) {
  char *str1 = "abcde";
  char *str2 = "fghjk";
  my_size_t n = 5;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_3) {
  char *str1 = "abcde";
  char *str2 = "ABCDE";
  my_size_t n = 5;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_4) {
  char *str1 = "abcde\n";
  char *str2 = "abcde\n";
  my_size_t n = 6;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_5) {
  char *str1 = "\n\tabcde\n";
  char *str2 = "\t\nabcde\n";
  my_size_t n = 6;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_6) {
  char *str1 = "A very long text to test the program\n";
  char *str2 = "A very long text to test the program\n";
  my_size_t n = 15;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_7) {
  char *str1 = "AB";
  char *str2 = "Ab";
  my_size_t n = 1;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_8) {
  char *str1 = "averylongtexttotesttheprogram!";
  char *str2 = "averylongtexttotesttheprogram?";
  my_size_t n = 29;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_9) {
  char str1[10] = "abcde";
  char str2[10] = "abcdefg";
  my_size_t n = 10;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(my_memcmp_10) {
  char str1[10] = "abcdefg";
  char str2[10] = "abcde";
  my_size_t n = 10;
  int i1 = my_memcmp(str1, str2, n);
  int i2 = memcmp(str1, str2, n);
  ck_assert_int_eq(i1, i2);
}
END_TEST

Suite *my_memcmp_test(void) {
  Suite *suite = suite_create("\033[33m--my_memcmp--\033[0m");
  TCase *tcase_core = tcase_create("memcmp_tc");
  tcase_add_test(tcase_core, my_memcmp_1);
  tcase_add_test(tcase_core, my_memcmp_2);
  tcase_add_test(tcase_core, my_memcmp_3);
  tcase_add_test(tcase_core, my_memcmp_4);
  tcase_add_test(tcase_core, my_memcmp_5);
  tcase_add_test(tcase_core, my_memcmp_6);
  tcase_add_test(tcase_core, my_memcmp_7);
  tcase_add_test(tcase_core, my_memcmp_8);
  tcase_add_test(tcase_core, my_memcmp_9);
  tcase_add_test(tcase_core, my_memcmp_10);
  suite_add_tcase(suite, tcase_core);
  return suite;
}