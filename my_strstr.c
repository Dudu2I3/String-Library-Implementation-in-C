#include "my_string.h"

char *my_strstr(const char *haystack, const char *needle) {
  my_size_t counter = 0;
  my_size_t needle_size = my_strlen(needle);
  my_size_t checker = 0;
  char *temp = my_NULL;
  for (; haystack[counter] != '\0' && needle_size != checker; counter++) {
    if (haystack[counter] == needle[checker])
      checker++;
    else {
      if (checker) counter--;
      checker = 0;
    }
  }
  if (checker == needle_size) temp = (char *)&haystack[counter - checker];
  return temp;
}