#ifndef SRC_TESTS_TESTS_H
#define SRC_TESTS_TESTS_H

#include <check.h>
#include <stddef.h>
#include <stdio.h>

#include "../my_string.h"

Suite *my_insert_test(void);
Suite *my_memchr_test(void);
Suite *my_memcmp_test(void);
Suite *my_memcpy_test(void);
Suite *my_memset_test(void);
Suite *my_sprintf_test(void);
Suite *my_sscanf_test(void);
Suite *my_strchr_test(void);
Suite *my_strcspn_test(void);
Suite *my_strlen_test(void);
Suite *my_strncat_test(void);
Suite *my_strncmp_test(void);
Suite *my_strncpy_test(void);
Suite *my_strpbrk_test(void);
Suite *my_strrchr_test(void);
Suite *my_strstr_test(void);
Suite *my_strtok_test(void);
Suite *my_to_lower_test(void);
Suite *my_to_upper_test(void);
Suite *my_trim_test(void);
Suite *my_strerror_test(void);
Suite *my_sprintf_test(void);

#endif
