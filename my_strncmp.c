#include "my_string.h"

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  int diff = 0;
  for (my_size_t counter = 0; counter < n && !diff; counter++)
    diff = str1[counter] - str2[counter];
  return diff;
}