#include "my_string.h"

my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t counter = 0;
  int checker = 0;
  while (str1[counter] != '\0' && !checker) {
    for (int temp_counter = 0; str2[temp_counter] != '\0'; temp_counter++)
      if (str1[counter] == str2[temp_counter]) checker++;
    if (!checker) counter++;
  }
  return counter;
}