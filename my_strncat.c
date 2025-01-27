#include "my_string.h"

char *my_strncat(char *dest, const char *src, my_size_t n) {
  my_size_t dest_size = my_strlen(dest);
  my_size_t src_counter = 0;
  for (; src_counter < n && src[src_counter] != '\0'; src_counter++)
    dest[dest_size + src_counter] = src[src_counter];
  dest[dest_size + src_counter] = '\0';
  return dest;
}