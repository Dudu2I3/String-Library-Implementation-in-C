#include "my_error.h"
#include "my_string.h"

char *my_strerror(int errnum) {
#ifdef __linux__
  if (errnum >= 0 && (my_size_t)errnum < ERROR_COUNT) {
    return (char *)linux_error_messages[errnum];
  }
#elif __APPLE__
  if (errnum >= 0 && (my_size_t)errnum < ERROR_COUNT) {
    return (char *)mac_error_messages[errnum];
  }
#endif
  static char unknown_error[50];
  my_sprintf(unknown_error,
#ifdef __APPLE__
             "Unknown error: %d",
#else
             "Unknown error %d",
#endif
             errnum);

  return unknown_error;
}