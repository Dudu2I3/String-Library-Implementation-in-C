#include "my_string.h"

char *my_strchr(const char *str, int c) {
  my_size_t counter = 0;
  char *temp = my_NULL;
  while (str[counter] != '\0' && str[counter] != c) counter++;
  if (str[counter] == c) temp = (char *)&str[counter];
  return temp;
}