#include "tests.h"

START_TEST(my_strtok_1) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char delim[12] = "cd";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(my_strtok_2) {
  char str1[12] = "abcde";
  char str2[12] = "abcde";
  char delim[12] = "cd";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_3) {
  char str1[12] = "cdddcabcde";
  char str2[12] = "cdddcabcde";
  char delim[12] = "cd";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_4) {
  char str1[20] = "cdddcabcdecddc";
  char str2[20] = "cdddcabcdecddc";
  char delim[12] = "cd";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_5) {
  char str1[20] = "cdddcabcdecddc";
  char str2[20] = "cdddcabcdecddc";
  char delim[12] = "po";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_6) {
  char str1[20] = "cdddcabcdecddc";
  char str2[20] = "cdddcabcdecddc";
  char delim[12] = "";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_7) {
  char str1[20] = "";
  char str2[20] = "";
  char delim[12] = "abc";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_8) {
  char str1[20] = "";
  char str2[20] = "";
  char delim[12] = "";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_9) {
  char str1[20] = "abcd\te";
  char str2[20] = "abcd\te";
  char delim[12] = "c\t";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_10) {
  char str1[20] = "ab\0cd\te";
  char str2[20] = "ab\0cd\te";
  char delim[12] = "c\t";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_11) {
  char str1[20] = "ab\0cd\te";
  char str2[20] = "ab\0cd\te";
  char delim[12] = "\0ab";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_12) {
  char str1[20] = "\0abcd\te";
  char str2[20] = "\0abcd\te";
  char delim[12] = "\0ab";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_13) {
  char str1[20] = "abcde";
  char str2[20] = "abcde";
  char delim[12] = "ABCDE";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

START_TEST(my_strtok_14) {
  char str1[20] = "abcde";
  char str2[20] = "abcde";
  char delim[12] = "ABCDE";
  char *s1 = my_strtok(str1, delim);
  char *s2 = strtok(str2, delim);
  while (s1 != my_NULL && s2 != NULL) {
    ck_assert_pstr_eq(s1, s2);
    s1 = my_strtok(my_NULL, delim);
    s2 = strtok(NULL, delim);
  }
  ck_assert_pstr_eq(s1, s2);  // check on null
}
END_TEST

Suite *my_strtok_test(void) {
  Suite *suite = suite_create("\033[33m--my_strtok--\033[0m");
  TCase *tcase_core = tcase_create("strtok_tc");
  tcase_add_test(tcase_core, my_strtok_1);
  tcase_add_test(tcase_core, my_strtok_2);
  tcase_add_test(tcase_core, my_strtok_3);
  tcase_add_test(tcase_core, my_strtok_4);
  tcase_add_test(tcase_core, my_strtok_5);
  tcase_add_test(tcase_core, my_strtok_6);
  tcase_add_test(tcase_core, my_strtok_7);
  tcase_add_test(tcase_core, my_strtok_8);
  tcase_add_test(tcase_core, my_strtok_9);
  tcase_add_test(tcase_core, my_strtok_10);
  tcase_add_test(tcase_core, my_strtok_11);
  tcase_add_test(tcase_core, my_strtok_12);
  tcase_add_test(tcase_core, my_strtok_13);
  tcase_add_test(tcase_core, my_strtok_14);
  suite_add_tcase(suite, tcase_core);
  return suite;
}