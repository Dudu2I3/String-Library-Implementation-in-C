#include "my_string.h"

void *my_memchr(const void *str, int c, my_size_t n) {
  char *temp = (char *)str;
  my_size_t counter = 0;
  for (; counter < n && temp && *temp != c; counter++) temp++;
  if (counter == n) temp = my_NULL;
  return (void *)temp;
}