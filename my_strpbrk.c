#include "my_string.h"

char *my_strpbrk(const char *str1, const char *str2) {
  int checker = 0;
  my_size_t counter = 0;
  char *temp = my_NULL;
  while (str1[counter] != '\0' && !checker) {
    my_size_t temp_counter = 0;
    for (; str2[temp_counter] != '\0' && !checker; temp_counter++)
      if (str1[counter] == str2[temp_counter]) checker++;
    if (!checker) counter++;
  }
  if (checker) temp = (char *)&str1[counter];
  return temp;
}