#include "tests.h"

START_TEST(my_sscanf_1) {
  char str1[30] = "A";
  char temp1;
  char temp2;
  int suc1 = my_sscanf(str1, "%c", &temp1);
  int suc2 = sscanf(str1, "%c", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_2) {
  char str1[30] = "ab e";
  char temp1;
  char temp2;
  int suc1 = my_sscanf(str1, "%c%c%c", &temp1, &temp1, &temp1);
  int suc2 = sscanf(str1, "%c%c%c", &temp2, &temp2, &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_3) {
  char str1[30] = "ф";
  int temp1 = 0;
  int temp2 = 34001;
  int suc1 = my_sscanf(str1, "%lc", &temp1);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, 1);
}
END_TEST

START_TEST(my_sscanf_4) {
  char str1[30] = "фывф";
  int temp1 = 0;
  int temp2 = 34001;
  int suc1 = my_sscanf(str1, "%lc%lc%lc%lc", &temp1, &temp1, &temp1, &temp1);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, 4);
}
END_TEST

START_TEST(my_sscanf_5) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%s", temp1);
  int suc2 = sscanf(str1, "%s", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_6) {
  char str1[30] = "    abcdefg     ";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%s", temp1);
  int suc2 = sscanf(str1, "%s", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_7) {
  char str1[30] = "абвгдеёж";
  char temp1[20];
  char temp2[20];
  int suc1 = my_sscanf(str1, "%s", temp1);
  int suc2 = sscanf(str1, "%s", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_8) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%3s", temp1);
  int suc2 = sscanf(str1, "%3s", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_9) {
  char str1[30] = "abcdefg";
  char temp1[15];
  char temp2[15];
  int suc1 = my_sscanf(str1, "%10s", temp1);
  int suc2 = sscanf(str1, "%10s", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_10) {
  char str1[30] = "abcdefg fdsafsd";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%s%s", temp1, temp1);
  int suc2 = sscanf(str1, "%s%s", temp2, temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_11) {
  char str1[30] = "abcd\0efg fdsafsd";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%s%s", temp1, temp1);
  int suc2 = sscanf(str1, "%s%s", temp2, temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_12) {
  char str1[30] = "abcdefg \f\n\r\t\vfdsafsd";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%s%s", temp1, temp1);
  int suc2 = sscanf(str1, "%s%s", temp2, temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_13) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[abcdefg]", temp1);
  int suc2 = sscanf(str1, "%[abcdefg]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_14) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[abfg]", temp1);
  int suc2 = sscanf(str1, "%[abfg]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_15) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[a-g]", temp1);
  int suc2 = sscanf(str1, "%[a-g]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_16) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[a-d-g]", temp1);
  int suc2 = sscanf(str1, "%[a-d-g]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_17) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[a-d-G]", temp1);
  int suc2 = sscanf(str1, "%[a-d-G]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_18) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[^defg]", temp1);
  int suc2 = sscanf(str1, "%[^defg]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_19) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[^d-g]", temp1);
  int suc2 = sscanf(str1, "%[^d-g]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_20) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[abc-g]", temp1);
  int suc2 = sscanf(str1, "%[abc-g]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_21) {
  char str1[30] = "abcdefg";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[abc]%[defg]", temp1, temp1);
  int suc2 = sscanf(str1, "%[abc]%[defg]", temp2, temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_22) {
  char str1[30] = "abc123defg123";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[abc0-9]%[defg0-9]", temp1, temp1);
  int suc2 = sscanf(str1, "%[abc0-9]%[defg0-9]", temp2, temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_23) {
  char str1[30] = "a[bc123def[g123";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[[abc]%[[d-g]", temp1, temp1);
  int suc2 = sscanf(str1, "%[[abc]%[[d-g]", temp2, temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_24) {
  char str1[30] = "ab]c123def]g123";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[^]1]", temp1);
  int suc2 = sscanf(str1, "%[^]1]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_25) {
  char str1[30] = "abc123defg123";
  char temp1[10];
  char temp2[10];
  int suc1 = my_sscanf(str1, "%[^b]", temp1);
  int suc2 = sscanf(str1, "%[^b]", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_26) {
  char str1[30] = "100";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%d", &temp1);
  int suc2 = sscanf(str1, "%d", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_27) {
  char str1[30] = "-100";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%d", &temp1);
  int suc2 = sscanf(str1, "%d", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_28) {
  char str1[30] = "+100";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%d", &temp1);
  int suc2 = sscanf(str1, "%d", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_29) {
  char str1[30] = "        +100";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%d", &temp1);
  int suc2 = sscanf(str1, "%d", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_30) {
  char str1[30] = "90000";
  short temp1;
  short temp2;
  int suc1 = my_sscanf(str1, "%hd", &temp1);
  int suc2 = sscanf(str1, "%hd", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_31) {
  char str1[30] = "4678695987";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%d", &temp1);
  int suc2 = sscanf(str1, "%d", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_32) {
  char str1[30] = "3213345353543225";
  long int temp1;
  long int temp2;
  int suc1 = my_sscanf(str1, "%ld", &temp1);
  int suc2 = sscanf(str1, "%ld", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_33) {
  char str1[30] = "-90000";
  unsigned short temp1;
  unsigned short temp2;
  int suc1 = my_sscanf(str1, "%hu", &temp1);
  int suc2 = sscanf(str1, "%hu", &temp2);
  ck_assert_uint_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_34) {
  char str1[30] = "-7568695987";
  unsigned int temp1;
  unsigned int temp2;
  int suc1 = my_sscanf(str1, "%u", &temp1);
  int suc2 = sscanf(str1, "%u", &temp2);
  ck_assert_uint_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_35) {
  char str1[30] = "31879543225321344324";
  unsigned long temp1;
  unsigned long temp2;
  int suc1 = my_sscanf(str1, "%lu", &temp1);
  int suc2 = sscanf(str1, "%lu", &temp2);
  ck_assert_uint_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_36) {
  char str1[40] = "-000000009232131234234312";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%d", &temp1);
  int suc2 = sscanf(str1, "%d", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_37) {
  char str1[30] = "765757";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%o", &temp1);
  int suc2 = sscanf(str1, "%o", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_39) {
  char str1[30] = "-4351346";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%o", &temp1);
  int suc2 = sscanf(str1, "%o", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_40) {
  char str1[30] = "-4134FaD";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%x", &temp1);
  int suc2 = sscanf(str1, "%x", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_41) {
  char str1[30] = "-4134yfad";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%X", &temp1);
  int suc2 = sscanf(str1, "%X", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_42) {
  char str1[30] = "2134faAd";
  int temp1;
  int temp2;
  int suc1 = my_sscanf(str1, "%X", &temp1);
  int suc2 = sscanf(str1, "%X", &temp2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

#ifdef __linux__
START_TEST(my_sscanf_43) {
  char str1[30] = "2134faAd";
  int temp1;
  int temp2;
  int count1 = 0;
  int count2 = 0;
  int suc1 = my_sscanf(str1, "%X%n", &temp1, &count1);
  int suc2 = sscanf(str1, "%X%n", &temp2, &count2);
  ck_assert_int_eq(temp1, temp2);
  ck_assert_int_eq(count1, count2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST
#endif

START_TEST(my_sscanf_44) {
  char str1[30] = "";
  int count1 = 0;
  int count2 = 0;
  int suc1 = my_sscanf(str1, "%n", &count1);
  int suc2 = sscanf(str1, "%n", &count1);
  ck_assert_int_eq(count1, count2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

#ifdef __linux__
START_TEST(my_sscanf_45) {
  char str1[30] = "abc";
  char temp1[20];
  char temp2[20];
  int count1 = 0;
  int count2 = 0;
  int suc1 = my_sscanf(str1, "%s%n", temp1, &count1);
  int suc2 = sscanf(str1, "%s%n", temp2, &count2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(count1, count2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_46) {
  char str1[30] = "abcdef";
  char temp1[20];
  char temp2[20];
  int count1 = 0;
  int count2 = 0;
  int suc1 = my_sscanf(str1, "%8s%n", temp1, &count1);
  int suc2 = sscanf(str1, "%8s%n", temp2, &count2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(count1, count2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST
#endif

START_TEST(my_sscanf_47) {
  char str1[40] = "10560.05543";
  float temp1 = 0;
  float temp2 = 0;
  int suc1 = my_sscanf(str1, "%f", &temp1);
  int suc2 = sscanf(str1, "%f", &temp2);
  ck_assert_float_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_48) {
  char str1[40] = "10560.2131405543";
  double temp1 = 0;
  double temp2 = 0;
  int suc1 = my_sscanf(str1, "%lf", &temp1);
  int suc2 = sscanf(str1, "%lf", &temp2);
  ck_assert_double_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_49) {
  char str1[40] = "131264560560.21314765705543";
  long double temp1 = 0;
  long double temp2 = 0;
  int suc1 = my_sscanf(str1, "%Lf", &temp1);
  int suc2 = sscanf(str1, "%Lf", &temp2);
  ck_assert_ldouble_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_50) {
  char str1[40] = "-876560.000043";
  float temp1 = 0;
  float temp2 = 0;
  int suc1 = my_sscanf(str1, "%f", &temp1);
  int suc2 = sscanf(str1, "%f", &temp2);
  ck_assert_float_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_51) {
  char str1[40] = "-876560.000043e+4";
  float temp1 = 0;
  float temp2 = 0;
  int suc1 = my_sscanf(str1, "%e", &temp1);
  int suc2 = sscanf(str1, "%e", &temp2);
  ck_assert_float_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_52) {
  char str1[40] = "836560.43E-15";
  float temp1 = 0;
  float temp2 = 0;
  int suc1 = my_sscanf(str1, "%e", &temp1);
  int suc2 = sscanf(str1, "%e", &temp2);
  ck_assert_float_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_54) {
  char str1[40] = "-nan";
  float temp1 = 0;
  int suc1 = my_sscanf(str1, "%g", &temp1);
  ck_assert_float_nan(temp1);
  ck_assert_int_eq(suc1, 1);
}
END_TEST

START_TEST(my_sscanf_55) {
  char str1[40] = "nan";
  float temp1 = 0;
  int suc1 = my_sscanf(str1, "%g", &temp1);
  ck_assert_float_nan(temp1);
  ck_assert_int_eq(suc1, 1);
}
END_TEST

START_TEST(my_sscanf_56) {
  char str1[40] = "inf";
  float temp1 = 0;
  int suc1 = my_sscanf(str1, "%g", &temp1);
  ck_assert_float_infinite(temp1);
  ck_assert_int_eq(suc1, 1);
}
END_TEST

START_TEST(my_sscanf_57) {
  char str1[40] = "INFINITE";
  float temp1 = 0;
  int suc1 = my_sscanf(str1, "%g", &temp1);
  ck_assert_float_infinite(temp1);
  ck_assert_int_eq(suc1, 1);
}
END_TEST

START_TEST(my_sscanf_58) {
  char a;
  char str1[20];
  char str2[20];
  my_sprintf(str1, "%p", &a);
  sprintf(str2, "%p", &a);
  void *ptr1;
  void *ptr2;
  int suc1 = my_sscanf(str1, "%p", &ptr1);
  int suc2 = my_sscanf(str1, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_59) {
  char str[20] = " \f\n\r\t\vabc";
  char temp1[20];
  char temp2[20];
  int suc1 = my_sscanf(str, " %s", temp1);
  int suc2 = my_sscanf(str, " %s", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

START_TEST(my_sscanf_60) {
  char str[20] = "123 abc";
  char temp1[20];
  char temp2[20];
  int suc1 = my_sscanf(str, "%*d%s", temp1);
  int suc2 = my_sscanf(str, "%*d%s", temp2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST

#ifdef __linux__
START_TEST(my_sscanf_61) {
  char str[20] = "123 abc ABC";
  char temp1[20];
  char temp2[20];
  int temp_i1;
  int temp_i2;
  int suc1 = my_sscanf(str, "%*d%s%n", temp1, &temp_i1);
  int suc2 = my_sscanf(str, "%*d%s%n", temp2, &temp_i2);
  ck_assert_str_eq(temp1, temp2);
  ck_assert_int_eq(temp_i1, temp_i2);
  ck_assert_int_eq(suc1, suc2);
}
END_TEST
#endif

Suite *my_sscanf_test(void) {
  Suite *suite = suite_create("\033[33m--my_sscanf--\033[0m");
  TCase *tcase_core = tcase_create("sscanf_tc");
  tcase_add_test(tcase_core, my_sscanf_1);
  tcase_add_test(tcase_core, my_sscanf_2);
  tcase_add_test(tcase_core, my_sscanf_3);
  tcase_add_test(tcase_core, my_sscanf_4);
  tcase_add_test(tcase_core, my_sscanf_5);
  tcase_add_test(tcase_core, my_sscanf_6);
  tcase_add_test(tcase_core, my_sscanf_7);
  tcase_add_test(tcase_core, my_sscanf_8);
  tcase_add_test(tcase_core, my_sscanf_9);
  tcase_add_test(tcase_core, my_sscanf_10);
  tcase_add_test(tcase_core, my_sscanf_11);
  tcase_add_test(tcase_core, my_sscanf_12);
  tcase_add_test(tcase_core, my_sscanf_13);
  tcase_add_test(tcase_core, my_sscanf_14);
  tcase_add_test(tcase_core, my_sscanf_15);
  tcase_add_test(tcase_core, my_sscanf_16);
  tcase_add_test(tcase_core, my_sscanf_17);
  tcase_add_test(tcase_core, my_sscanf_18);
  tcase_add_test(tcase_core, my_sscanf_19);
  tcase_add_test(tcase_core, my_sscanf_20);
  tcase_add_test(tcase_core, my_sscanf_21);
  tcase_add_test(tcase_core, my_sscanf_22);
  tcase_add_test(tcase_core, my_sscanf_23);
  tcase_add_test(tcase_core, my_sscanf_24);
  tcase_add_test(tcase_core, my_sscanf_25);
  tcase_add_test(tcase_core, my_sscanf_26);
  tcase_add_test(tcase_core, my_sscanf_27);
  tcase_add_test(tcase_core, my_sscanf_28);
  tcase_add_test(tcase_core, my_sscanf_29);
  tcase_add_test(tcase_core, my_sscanf_30);
  tcase_add_test(tcase_core, my_sscanf_31);
  tcase_add_test(tcase_core, my_sscanf_32);
  tcase_add_test(tcase_core, my_sscanf_33);
  tcase_add_test(tcase_core, my_sscanf_34);
  tcase_add_test(tcase_core, my_sscanf_35);
  tcase_add_test(tcase_core, my_sscanf_36);
  tcase_add_test(tcase_core, my_sscanf_37);
  tcase_add_test(tcase_core, my_sscanf_39);
  tcase_add_test(tcase_core, my_sscanf_40);
  tcase_add_test(tcase_core, my_sscanf_41);
  tcase_add_test(tcase_core, my_sscanf_42);
#ifdef __linux__
  tcase_add_test(tcase_core, my_sscanf_43);
#endif
  tcase_add_test(tcase_core, my_sscanf_44);
#ifdef __linux__
  tcase_add_test(tcase_core, my_sscanf_45);
  tcase_add_test(tcase_core, my_sscanf_46);
#endif
  tcase_add_test(tcase_core, my_sscanf_47);
  tcase_add_test(tcase_core, my_sscanf_48);
  tcase_add_test(tcase_core, my_sscanf_49);
  tcase_add_test(tcase_core, my_sscanf_50);
  tcase_add_test(tcase_core, my_sscanf_51);
  tcase_add_test(tcase_core, my_sscanf_52);
  tcase_add_test(tcase_core, my_sscanf_54);
  tcase_add_test(tcase_core, my_sscanf_55);
  tcase_add_test(tcase_core, my_sscanf_56);
  tcase_add_test(tcase_core, my_sscanf_57);
  tcase_add_test(tcase_core, my_sscanf_58);
  tcase_add_test(tcase_core, my_sscanf_59);
  tcase_add_test(tcase_core, my_sscanf_60);
#ifdef __linux__
  tcase_add_test(tcase_core, my_sscanf_61);
#endif
  suite_add_tcase(suite, tcase_core);
  return suite;
}