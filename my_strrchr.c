#include "my_string.h"

char *my_strrchr(const char *str, int c) {
  char *temp = my_NULL;
  my_size_t counter = 0;
  my_size_t str_size = my_strlen(str) + 1;
  for (; counter < str_size; counter++)
    if (str[counter] == c) temp = (char *)&str[counter];
  return temp;
}