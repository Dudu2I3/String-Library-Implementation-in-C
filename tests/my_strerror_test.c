#include "tests.h"

START_TEST(my_strerror_generic) {
  for (size_t errnum = 0; errnum < 150; errnum++) {
    char *expected = strerror(errnum);
    char *result = my_strerror(errnum);
    ck_assert_str_eq(result, expected);
  }
}
END_TEST

Suite *my_strerror_test(void) {
  Suite *suite = suite_create("\033[33m--my_strerror--\033[0m");
  TCase *tcase_core = tcase_create("strerror_tc");
  tcase_add_test(tcase_core, my_strerror_generic);
  suite_add_tcase(suite, tcase_core);
  return suite;
}