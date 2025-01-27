#include "my_string.h"

void *my_to_upper(const char *str) {
  char *temp = my_NULL;
  if (str) {
    temp = (char *)str;
    int diff = 32;
    for (my_size_t counter = 0; temp[counter] != '\0'; counter++)
      if (temp[counter] >= 'a' && temp[counter] <= 'z')
        temp[counter] = temp[counter] - diff;
  }
  return (void *)temp;
}