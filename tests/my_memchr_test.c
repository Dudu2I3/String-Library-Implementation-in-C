#include "tests.h"

START_TEST(my_memchr_1) {
  char *str = "abcde";
  char *c1 = my_memchr(str, 'b', 5);
  char *c2 = memchr(str, 'b', 5);
  ck_assert_ptr_eq(c1, c2);
}
END_TEST

START_TEST(my_memchr_2) {
  char *str = "abcdefg";
  my_size_t n = 1;
  char *c1 = my_memchr(str, 'b', n);
  char *c2 = memchr(str, 'b', n);
  ck_assert_ptr_eq(c1, c2);
}
END_TEST

START_TEST(my_memchr_3) {
  char *str = NULL;
  my_size_t n = 0;
  char *c1 = my_memchr(str, 'b', n);
  char *c2 = memchr(str, 'b', n);
  ck_assert_ptr_eq(c1, c2);
}
END_TEST

START_TEST(my_memchr_4) {
  char *str = "abcde";
  my_size_t n = 5;
  char *c1 = my_memchr(str, 'o', n);
  char *c2 = memchr(str, 'o', n);
  ck_assert_ptr_eq(c1, c2);
}
END_TEST

START_TEST(my_memchr_5) {
  char *str = "abcde";
  my_size_t n = 5;
  char *c1 = my_memchr(str, 'B', n);
  char *c2 = memchr(str, 'B', n);
  ck_assert_ptr_eq(c1, c2);
}
END_TEST

START_TEST(my_memchr_6) {
  char *str = "abcde";
  my_size_t n = 6;
  char *c1 = my_memchr(str, '\0', n);
  char *c2 = memchr(str, '\0', n);
  ck_assert_ptr_eq(c1, c2);
}
END_TEST

START_TEST(my_memchr_7) {
  char *str = "abc\t\tde";
  my_size_t n = 6;
  char *c1 = my_memchr(str, '\t', n);
  char *c2 = memchr(str, '\t', n);
  ck_assert_ptr_eq(c1, c2);
}
END_TEST

START_TEST(my_memchr_8) {
  char *str = "abc\n\tde";
  my_size_t n = 8;
  char *c1 = my_memchr(str, '\n', n);
  char *c2 = memchr(str, '\n', n);
  ck_assert_ptr_eq(c1, c2);
}
END_TEST

Suite *my_memchr_test(void) {
  Suite *suite = suite_create("\033[33m--my_memchr--\033[0m");
  TCase *tcase_core = tcase_create("memchr_tc");
  tcase_add_test(tcase_core, my_memchr_1);
  tcase_add_test(tcase_core, my_memchr_2);
  tcase_add_test(tcase_core, my_memchr_3);
  tcase_add_test(tcase_core, my_memchr_4);
  tcase_add_test(tcase_core, my_memchr_5);
  tcase_add_test(tcase_core, my_memchr_6);
  tcase_add_test(tcase_core, my_memchr_7);
  tcase_add_test(tcase_core, my_memchr_8);
  suite_add_tcase(suite, tcase_core);
  return suite;
}