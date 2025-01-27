#include "my_string.h"

char *my_strtok(char *str, const char *delim) {
  static char *buff_str = my_NULL;
  if (str == my_NULL) str = buff_str;
  my_size_t counter = 0;
  my_size_t str_addr = 0;
  int delim_checker = 1;
  int checker = 0;
  if (str && *str != '\0') {
    for (; str[counter] != '\0' && checker != 2; counter++) {
      if (my_strchr(delim, str[counter]) != my_NULL) {
        if (delim_checker)
          str_addr++;
        else {
          str[counter] = '\0';
          checker = 1;
        }
      }
      if (str[counter] != '\0' && (counter + 1) != str_addr) {
        delim_checker = 0;
        if (checker) {
          checker = 2;
          counter--;
        }
      }
    }
    if (str[counter] == '\0')
      buff_str = my_NULL;
    else
      buff_str = &str[counter];
  } else
    str = my_NULL;
  return &str[str_addr];
}