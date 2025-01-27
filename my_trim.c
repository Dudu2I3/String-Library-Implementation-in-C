#include "my_string.h"

void *my_trim(const char *src, const char *trim_chars) {
  my_size_t l_counter = 0;
  my_size_t r_counter = 0;
  my_size_t trim_checker = 1;
  for (int i = 0; trim_checker && src[i] != '\0'; i++) {
    trim_checker = 0;
    if (my_strchr(trim_chars, src[i]) != my_NULL) {
      trim_checker = 1;
      l_counter++;
    }
  }
  trim_checker = 1;
  for (int i = my_strlen(src) - 1; trim_checker && i >= 0; i--) {
    trim_checker = 0;
    if (my_strchr(trim_chars, src[i]) != my_NULL) {
      trim_checker = 1;
      r_counter++;
    }
  }
  my_size_t counter = 0;
  char *temp = my_NULL;
  if (my_strlen(src) - l_counter != 0) {
    temp = (char *)malloc(sizeof(char) *
                          (my_strlen(src) - l_counter - r_counter + 1));
    for (my_size_t i = l_counter; i < my_strlen(src) - r_counter; i++) {
      temp[counter] = src[i];
      counter++;
    }
    temp[counter] = '\0';
  }
  return (void *)temp;
}