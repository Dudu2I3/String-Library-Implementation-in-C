#include "tests.h"

int main(void) {
  int fail = 0;
  Suite *my_string_test[] = {my_insert_test(),   my_memchr_test(),
                             my_memcmp_test(),   my_memcpy_test(),
                             my_memset_test(),   my_sprintf_test(),
                             my_sscanf_test(),   my_strchr_test(),
                             my_strerror_test(), my_strcspn_test(),
                             my_strlen_test(),   my_strncat_test(),
                             my_strncmp_test(),  my_strncpy_test(),
                             my_strpbrk_test(),  my_strrchr_test(),
                             my_strstr_test(),   my_strtok_test(),
                             my_to_lower_test(), my_to_upper_test(),
                             my_trim_test(),     my_NULL};
  for (int i = 0; my_string_test[i] != my_NULL; i++) {
    SRunner *sr = srunner_create(my_string_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    fail += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  if (fail > 0)
    printf("Failed: \033[31m%d\033[0m\n", fail);
  else
    printf("Failed: \033[32m%d\033[0m\n", fail);
  return fail ? 1 : 0;
}
