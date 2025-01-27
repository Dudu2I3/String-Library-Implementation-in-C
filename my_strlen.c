#include "my_string.h"

my_size_t my_strlen(const char *str) {
  my_size_t counter = 0;
  while (str[counter] != '\0') counter++;
  return counter;
}