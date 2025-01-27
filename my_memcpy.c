#include "my_string.h"

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  for (my_size_t i = 0; i < n; i++) *(char *)(dest + i) = *(char *)(src + i);
  return dest;
}