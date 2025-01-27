#include "my_string.h"

int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  int diff = 0;
  my_size_t len1 = my_strlen(str1), len2 = my_strlen(str2), max = 0;
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  max = (len1 >= len2) ? len2 + 1 : len1 + 1;
  if (n <= max) {
    max = n;
  }
  for (my_size_t i = 0; i < max && !diff; i++) {
    diff = s1[i] - s2[i];
  }
  return diff;
}