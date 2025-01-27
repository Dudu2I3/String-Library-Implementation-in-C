#include "tests.h"

START_TEST(my_sprintf_1) {
  char c = 'a';
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%c", c);
  int suc2 = sprintf(temp2, "%c", c);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_2) {
  char c = 'a';
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "aboba: %c", c);
  int suc2 = sprintf(temp2, "aboba: %c", c);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_3) {
  char c = 'A';
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "aboba: %c%c", c, c);
  int suc2 = sprintf(temp2, "aboba: %c%c", c, c);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_4) {
  unsigned int c = 34001;
  char temp1[20];
  char temp2[20] = "aboba: ф";
  int suc1 = my_sprintf(temp1, "aboba: %lc", c);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, 9);
}
END_TEST

START_TEST(my_sprintf_5) {
  char s[20] = "abcdef";
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%s", s);
  int suc2 = sprintf(temp2, "%s", s);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_6) {
  char s[20] = "abcdef";
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "aboba: %s", s);
  int suc2 = sprintf(temp2, "aboba: %s", s);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_7) {
  char s[20] = "abcdef";
  char temp1[50];
  char temp2[50];
  int suc1 = my_sprintf(temp1, "aboba: %s%s", s, s);
  int suc2 = sprintf(temp2, "aboba: %s%s", s, s);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_8) {
  char s[20] = "абвгде";
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "aboba: %s", s);
  int suc2 = sprintf(temp2, "aboba: %s", s);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_9) {
  char s[20] = "abcdef";
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%-10s", s);
  int suc2 = sprintf(temp2, "%-10s", s);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_10) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%d", i);
  int suc2 = sprintf(temp2, "%d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_11) {
  int i = -1000;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%d", i);
  int suc2 = sprintf(temp2, "%d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_12) {
  int i = -100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%d%d", i, i);
  int suc2 = sprintf(temp2, "%d%d", i, i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_13) {
  short i = 123;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%hd%hd", i, i);
  int suc2 = sprintf(temp2, "%hd%hd", i, i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_14) {
  long i = 13214525533246;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%ld%ld", i, i);
  int suc2 = sprintf(temp2, "%ld%ld", i, i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_15) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%-8d", i);
  int suc2 = sprintf(temp2, "%-8d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_16) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%+d", i);
  int suc2 = sprintf(temp2, "%+d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_17) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "% d", i);
  int suc2 = sprintf(temp2, "% d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_18) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%0d", i);
  int suc2 = sprintf(temp2, "%0d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_19) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%5d", i);
  int suc2 = sprintf(temp2, "%5d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_20) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%5.0d", i);
  int suc2 = sprintf(temp2, "%5.0d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_21) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%5.8d", i);
  int suc2 = sprintf(temp2, "%5.8d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_22) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%o", i);
  int suc2 = sprintf(temp2, "%o", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_23) {
  int i = 143245;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%#o", i);
  int suc2 = sprintf(temp2, "%#o", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_24) {
  int i = 1000;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%x", i);
  int suc2 = sprintf(temp2, "%x", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_25) {
  int i = 1000;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%X", i);
  int suc2 = sprintf(temp2, "%X", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_26) {
  int i = 1000;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%#x", i);
  int suc2 = sprintf(temp2, "%#x", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_27) {
  int i = 1000;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%#X", i);
  int suc2 = sprintf(temp2, "%#X", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_28) {
  unsigned int u = 1000;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%u", u);
  int suc2 = sprintf(temp2, "%u", u);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_29) {
  unsigned int u = 65000;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%u", u);
  int suc2 = sprintf(temp2, "%u", u);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_30) {
  int i = 100;
  char temp1[20];
  char temp2[20];
  int suc1 = my_sprintf(temp1, "%-+9d", i);
  int suc2 = sprintf(temp2, "%-+9d", i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_31) {
  int i = 100;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%-+9d%-5.3d", i, i);
  int suc2 = sprintf(temp2, "%-+9d%-5.3d", i, i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_32) {
  float f = 16679.2;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%f", f);
  int suc2 = sprintf(temp2, "%f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_33) {
  float f = 16679.2;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "aboba: %f", f);
  int suc2 = sprintf(temp2, "aboba: %f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_34) {
  double f = 16679.2;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "aboba: %lf", f);
  int suc2 = sprintf(temp2, "aboba: %lf", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_35) {
  long double f = 16679.2;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "aboba: %Lf", f);
  int suc2 = sprintf(temp2, "aboba: %Lf", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_36) {
  float f = 160.232134;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%2f", f);
  int suc2 = sprintf(temp2, "%2f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_37) {
  float f = 160.232134;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%.2f", f);
  int suc2 = sprintf(temp2, "%.2f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_38) {
  float f = 160.232134;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%2.2f", f);
  int suc2 = sprintf(temp2, "%2.2f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_39) {
  float f = 0.2321340000;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#f", f);
  int suc2 = sprintf(temp2, "%#f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_40) {
  float f = 100.0;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#f", f);
  int suc2 = sprintf(temp2, "%#f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_41) {
  float f = NAN;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#f", f);
  int suc2 = sprintf(temp2, "%#f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

/* START_TEST(my_sprintf_42) {
  float f = INFINITY;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#f", f);
  int suc2 = sprintf(temp2, "%#f", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST */

START_TEST(my_sprintf_43) {
  float f = 100.05;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%f%f", f, f);
  int suc2 = sprintf(temp2, "%f%f", f, f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_44) {
  float f = 10000.3213;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%e", f);
  int suc2 = sprintf(temp2, "%e", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_45) {
  float f = 10000.3213;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "aboba: %e", f);
  int suc2 = sprintf(temp2, "aboba: %e", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_46) {
  float f = 10000.3213;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%e%e", f, f);
  int suc2 = sprintf(temp2, "%e%e", f, f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_47) {
  float f = 10000.3213;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%E", f);
  int suc2 = sprintf(temp2, "%E", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_48) {
  long double f = 10000.3213e-150;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%Le", f);
  int suc2 = sprintf(temp2, "%Le", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_49) {
  float f = 1.3213;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#e", f);
  int suc2 = sprintf(temp2, "%#e", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_50) {
  double f = -10000.3213312;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%g", f);
  int suc2 = sprintf(temp2, "%g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_51) {
  float f = 100.321;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%g", f);
  int suc2 = sprintf(temp2, "%g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_52) {
  float f = 100.32131245;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%.1g", f);
  int suc2 = sprintf(temp2, "%.1g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_53) {
  float f = 100.32131245;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%8.1g", f);
  int suc2 = sprintf(temp2, "%8.1g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_54) {
  float f = 100.00000;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#.1g", f);
  int suc2 = sprintf(temp2, "%#.1g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_55) {
  float f = 21.1;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#.0g", f);
  int suc2 = sprintf(temp2, "%#.0g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_56) {
  float f = 21.1;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#0.g", f);
  int suc2 = sprintf(temp2, "%#0.g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_57) {
  float f = NAN;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#0.g", f);
  int suc2 = sprintf(temp2, "%#0.g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

/* START_TEST(my_sprintf_58) {
  float f = INFINITY;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#0.g", f);
  int suc2 = sprintf(temp2, "%#0.g", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST */

START_TEST(my_sprintf_59) {
  int n = 0;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%n", &n);
  int suc2 = sprintf(temp2, "%n", &n);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_61) {
  int n = 0;
  char s[10] = "abcdef";
  char temp1[30];

#if defined(__APPLE__)
  int suc1 = my_sprintf(temp1, "%s%n", s, &n);
  ck_assert_str_eq(temp1, "abcdef");
  ck_assert_int_eq(suc1, 6);
#else
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%s%n", s, &n);
  int suc2 = sprintf(temp2, "%s%n", s, &n);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
#endif
}
END_TEST

START_TEST(my_sprintf_62) {
  long n = 0;
  char s[10] = "abcdef";
  char temp1[30];

#ifdef __APPLE__
  int suc1 = my_sprintf(temp1, "%s%ln", s, &n);
  ck_assert_str_eq(temp1, "abcdef");
  ck_assert_int_eq(n, 0);
  ck_assert_int_eq(suc1, 6);
#else
  char temp2[30];
  long n2 = 0;
  int suc1 = my_sprintf(temp1, "%s%ln", s, &n);
  int suc2 = sprintf(temp2, "%s%ln", s, &n2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(n, n2);
  ck_assert_int_eq(suc1, suc2);
#endif
}
END_TEST
START_TEST(my_sprintf_63) {
  int i;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%p", &i);
  int suc2 = sprintf(temp2, "%p", &i);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_64) {
  char temp1[40];
  char temp2[40];
  int a = 100;
  int suc1 = my_sprintf(temp1, "aboba: %#.6o", a);
  int suc2 = sprintf(temp2, "aboba: %#.6o", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_65) {
  char temp1[40];
  char temp2[40];
  int a = 113;
  int suc1 = my_sprintf(temp1, "aboba: %#x", a);
  int suc2 = sprintf(temp2, "aboba: %#x", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_66) {
  char temp1[40];
  char temp2[40];
  double a = 53425132.001;
  int suc1 = my_sprintf(temp1, "aboba: %20f", a);
  int suc2 = sprintf(temp2, "aboba: %20f", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_67) {
  char temp1[40];
  char temp2[40];
  double a = 53425132.001;
  int suc1 = my_sprintf(temp1, "aboba: %-20f", a);
  int suc2 = sprintf(temp2, "aboba: %-20f", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_68) {
  char temp1[40];
  char temp2[40];
  double a = 53425132.001;
  int suc1 = my_sprintf(temp1, "aboba: %- 20f", a);
  int suc2 = sprintf(temp2, "aboba: %- 20f", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_69) {
  char temp1[40];
  char temp2[40];
  double a = 53425132.001;
  int suc1 = my_sprintf(temp1, "aboba: %020f", a);
  int suc2 = sprintf(temp2, "aboba: %020f", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_70) {
  char temp1[40];
  char temp2[40];
  double a = 53425132.001;
  int suc1 = my_sprintf(temp1, "aboba: %- f", a);
  int suc2 = sprintf(temp2, "aboba: %- f", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_71) {
  char temp1[40];
  char temp2[40];
  int a = 534251;
  int suc1 = my_sprintf(temp1, "aboba: %.10d", a);
  int suc2 = sprintf(temp2, "aboba: %.10d", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_72) {
  char temp1[40];
  char temp2[40];
  int a = 534251;
  int suc1 = my_sprintf(temp1, "aboba: %10d", a);
  int suc2 = sprintf(temp2, "aboba: %10d", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_73) {
  char temp1[40];
  char temp2[40];
  int a = 534251;
  int suc1 = my_sprintf(temp1, "aboba: %- d", a);
  int suc2 = sprintf(temp2, "aboba: %- d", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_74) {
  char temp1[40];
  int x1 = 15;
  int x2 = 4;
  int a = 534251;

#ifdef __APPLE__
  int suc1 = my_sprintf(temp1, "aboba: %-*.*d", x1, x2, a);
  ck_assert_str_eq(temp1, "aboba: 0015           ");
  ck_assert_int_eq(suc1, 22);
#else
  char temp2[40];
  int suc1 = my_sprintf(temp1, "aboba: %-*.*d", x1, x2, a);
  int suc2 = sprintf(temp2, "aboba: %-*.*d", x1, x2, a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
#endif
}
END_TEST

START_TEST(my_sprintf_75) {
  char temp1[60];
  char temp2[60] = "aф";
  unsigned int ch = 34001;
  my_sprintf(temp1, "a%lc", ch);
  ck_assert_str_eq(temp1, temp2);
}
END_TEST

START_TEST(my_sprintf_76) {
  char temp1[40];
  char temp2[40];
  long int a = 10064576574;
  int suc1 = my_sprintf(temp1, "aboba: %lo", a);
  int suc2 = sprintf(temp2, "aboba: %lo", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_77) {
  char temp1[40];
  char temp2[40];
  short int a = 255;
  int suc1 = my_sprintf(temp1, "aboba: %hx", a);
  int suc2 = sprintf(temp2, "aboba: %hx", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_78) {
  char temp1[70];
  char temp2[70] = "aboba: 356765765878478600.000000";
  long double a = 356765765878478576.8769789789;
  int suc = my_sprintf(temp1, "aboba: %Lf", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc, 32);
}
END_TEST

START_TEST(my_sprintf_79) {
  char temp1[70];
  char temp2[70] = "454.534768785980531900000000000000";
  long double a = 454.5347687859805295365876;
  int suc = my_sprintf(temp1, "%.30Lf", a);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc, 34);
}
END_TEST

START_TEST(my_sprintf_80) {
  char temp1[70];
  char temp2[70];
  int suc1 = my_sprintf(temp1, "%%");
  int suc2 = sprintf(temp2, "%%");
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

/* START_TEST(my_sprintf_81) {
  float f = INFINITY;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#0.G", f);
  int suc2 = sprintf(temp2, "%#0.G", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST */

START_TEST(my_sprintf_82) {
  float f = NAN;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%#0.G", f);
  int suc2 = sprintf(temp2, "%#0.G", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_83) {
  float f = NAN;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%9.G", f);
  int suc2 = sprintf(temp2, "%9.G", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_84) {
  float f = NAN;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "%.9G", f);
  int suc2 = sprintf(temp2, "%.9G", f);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_85) {
  short n1 = 0;
  short n2 = 0;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "aboba%hn", &n1);
  int suc2 = sprintf(temp2, "aboba%hn", &n2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sprintf_86) {
  long n1 = 0;
  long n2 = 0;
  char temp1[30];
  char temp2[30];
  int suc1 = my_sprintf(temp1, "aboba%ln", &n1);
  int suc2 = sprintf(temp2, "aboba%ln", &n2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

Suite *my_sprintf_test(void) {
  Suite *suite = suite_create("\033[33m--my_sprintf--\033[0m");
  TCase *tcase_core = tcase_create("sprintf_tc");
  tcase_add_test(tcase_core, my_sprintf_1);
  tcase_add_test(tcase_core, my_sprintf_2);
  tcase_add_test(tcase_core, my_sprintf_3);
  tcase_add_test(tcase_core, my_sprintf_4);
  tcase_add_test(tcase_core, my_sprintf_5);
  tcase_add_test(tcase_core, my_sprintf_6);
  tcase_add_test(tcase_core, my_sprintf_7);
  tcase_add_test(tcase_core, my_sprintf_8);
  tcase_add_test(tcase_core, my_sprintf_9);
  tcase_add_test(tcase_core, my_sprintf_10);
  tcase_add_test(tcase_core, my_sprintf_11);
  tcase_add_test(tcase_core, my_sprintf_12);
  tcase_add_test(tcase_core, my_sprintf_13);
  tcase_add_test(tcase_core, my_sprintf_14);
  tcase_add_test(tcase_core, my_sprintf_15);
  tcase_add_test(tcase_core, my_sprintf_16);
  tcase_add_test(tcase_core, my_sprintf_17);
  tcase_add_test(tcase_core, my_sprintf_18);
  tcase_add_test(tcase_core, my_sprintf_19);
  tcase_add_test(tcase_core, my_sprintf_20);
  tcase_add_test(tcase_core, my_sprintf_21);
  tcase_add_test(tcase_core, my_sprintf_22);
  tcase_add_test(tcase_core, my_sprintf_23);
  tcase_add_test(tcase_core, my_sprintf_24);
  tcase_add_test(tcase_core, my_sprintf_25);
  tcase_add_test(tcase_core, my_sprintf_26);
  tcase_add_test(tcase_core, my_sprintf_27);
  tcase_add_test(tcase_core, my_sprintf_28);
  tcase_add_test(tcase_core, my_sprintf_29);
  tcase_add_test(tcase_core, my_sprintf_30);
  tcase_add_test(tcase_core, my_sprintf_31);
  tcase_add_test(tcase_core, my_sprintf_32);
  tcase_add_test(tcase_core, my_sprintf_33);
  tcase_add_test(tcase_core, my_sprintf_34);
  tcase_add_test(tcase_core, my_sprintf_35);
  tcase_add_test(tcase_core, my_sprintf_36);
  tcase_add_test(tcase_core, my_sprintf_37);
  tcase_add_test(tcase_core, my_sprintf_38);
  tcase_add_test(tcase_core, my_sprintf_39);
  tcase_add_test(tcase_core, my_sprintf_40);
  tcase_add_test(tcase_core, my_sprintf_41);
  // tcase_add_test(tcase_core, my_sprintf_42);
  tcase_add_test(tcase_core, my_sprintf_43);
  tcase_add_test(tcase_core, my_sprintf_44);
  tcase_add_test(tcase_core, my_sprintf_45);
  tcase_add_test(tcase_core, my_sprintf_46);
  tcase_add_test(tcase_core, my_sprintf_47);
  tcase_add_test(tcase_core, my_sprintf_48);
  tcase_add_test(tcase_core, my_sprintf_49);
  tcase_add_test(tcase_core, my_sprintf_50);
  tcase_add_test(tcase_core, my_sprintf_51);
  tcase_add_test(tcase_core, my_sprintf_52);
  tcase_add_test(tcase_core, my_sprintf_53);
  tcase_add_test(tcase_core, my_sprintf_54);
  tcase_add_test(tcase_core, my_sprintf_55);
  tcase_add_test(tcase_core, my_sprintf_56);
  tcase_add_test(tcase_core, my_sprintf_57);
  // tcase_add_test(tcase_core, my_sprintf_58);
  tcase_add_test(tcase_core, my_sprintf_59);
  tcase_add_test(tcase_core, my_sprintf_61);
  tcase_add_test(tcase_core, my_sprintf_62);
  tcase_add_test(tcase_core, my_sprintf_63);
  tcase_add_test(tcase_core, my_sprintf_64);
  tcase_add_test(tcase_core, my_sprintf_65);
  tcase_add_test(tcase_core, my_sprintf_66);
  tcase_add_test(tcase_core, my_sprintf_67);
  tcase_add_test(tcase_core, my_sprintf_68);
  tcase_add_test(tcase_core, my_sprintf_69);
  tcase_add_test(tcase_core, my_sprintf_70);
  tcase_add_test(tcase_core, my_sprintf_71);
  tcase_add_test(tcase_core, my_sprintf_72);
  tcase_add_test(tcase_core, my_sprintf_73);
  tcase_add_test(tcase_core, my_sprintf_74);
  tcase_add_test(tcase_core, my_sprintf_75);
  tcase_add_test(tcase_core, my_sprintf_76);
  tcase_add_test(tcase_core, my_sprintf_77);
  tcase_add_test(tcase_core, my_sprintf_78);
  tcase_add_test(tcase_core, my_sprintf_79);
  tcase_add_test(tcase_core, my_sprintf_80);
  // tcase_add_test(tcase_core, my_sprintf_81);
  tcase_add_test(tcase_core, my_sprintf_82);
  tcase_add_test(tcase_core, my_sprintf_83);
  tcase_add_test(tcase_core, my_sprintf_84);
  tcase_add_test(tcase_core, my_sprintf_85);
  tcase_add_test(tcase_core, my_sprintf_86);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
