#include "my_string.h"

void *my_insert(const char *src, const char *str, my_size_t start_index) {
  char *temp = my_NULL;
  if (src && str) {
    if (my_strlen(src) >= start_index) {
      my_size_t counter = 0;
      my_size_t str_counter = 0;
      my_size_t str_size = my_strlen(src) + my_strlen(str) + 1;
      temp = malloc(str_size * sizeof(char));
      for (; counter < start_index; counter++) temp[counter] = src[counter];
      for (; str[str_counter] != '\0'; str_counter++)
        temp[counter + str_counter] = str[str_counter];
      for (; src[counter] != '\0'; counter++)
        temp[counter + str_counter] = src[counter];
      temp[counter + str_counter] = '\0';
    }
  }
  return (void *)temp;
}