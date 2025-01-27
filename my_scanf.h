#ifndef MY_SCANF_H
#define MY_SCANF_H

#include "my_string.h"

#define PREC 16
#define IS_SPACE " \f\n\r\t\v"

typedef struct {
  int checker;
  int success_checker;

  int flag_space_number;
  int flag_asterisk;

  int flag_h_length;
  int flag_l_length;
  int flag_L_length;
} params;

typedef struct {
  char *soc_str;
  int soc_str_size;
  int soc_int_s;
  int soc_int_e;
  int soc_reverse;
} set_of_char_params;

void sc_param_reset(params *param);
int sc_param_processing(params *param, char c);
int sc_param_width_desc(params *param, char c);
int sc_param_length_desc(params *param, char c);
int sc_param_check(params param, char c);
void sc_param_asterisk_check(params *param, va_list ap);

int sc_format_checker(params *param, char *str, int *str_counter, va_list ap,
                      char *format, int *format_counter);

int sc_format_chars(params param, char *str, int *str_counter, va_list ap,
                    char c);
int sc_format_integer(params param, char *str, int *str_counter, va_list ap,
                      char c);
int sc_format_float(params param, char *str, int *str_counter, va_list ap);
int sc_format_pointer(params param, char *str, int *str_counter, va_list ap);
int sc_format_soc(params param, char *str, int *str_counter, va_list ap,
                  char *format, int *format_counter);
void sc_soc_params_init(set_of_char_params *socparam);
int sc_format_soc_str_size(set_of_char_params *socparam, char *temp_format);
int sc_format_soc_range(set_of_char_params *socparam, char *temp_format);
void sc_format_size(int str_counter, va_list ap);

int sc_format_integer_transform(params param, char *str, int *str_counter,
                                unsigned long *temp_i, int temp_space, char c);
void sc_format_integer_assign(params param, va_list ap, unsigned long temp_i,
                              char c);

int sc_format_float_exc(params param, char *str, int *str_counter,
                        long double *temp_i, int temp_number, int minus);
int sc_format_float_transform(params param, char *str, int *str_counter,
                              long double *temp_i, int *temp_number);
void sc_format_float_exp(params param, char *str, int *str_counter,
                         long double *temp_i, int temp_number);
void sc_format_float_assign(params param, va_list ap, long double temp_i);

#endif