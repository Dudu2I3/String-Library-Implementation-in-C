#ifndef MY_SPRINTF_H
#define MY_SPRINTF_H

#include "my_string.h"

#define PREC 16

typedef struct {
  int checker;

  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_hashtag;
  int flag_zero;

  int flag_space_number;
  int flag_asterisk;
  int flag_dot;
  int flag_dot_space_number;
  int flag_dot_asterisk;

  int flag_h_length;
  int flag_l_length;
  int flag_L_length;
} params;

typedef struct {
  int dot;
  int counter_prec;
  int counter_prec_undefined;
  int counter_int;
  int counter_int_undefined;
  int is_nan;
  unsigned long long int_i;
  unsigned long long mod_i;
} float_params;

typedef struct {
  int precision_num;
  int space_num;
  int is_space;
  int is_sign;
  int is_minus;
  int str_len;
  int temp_str_len;
} string_params;

void pr_param_reset(params *param);

int pr_param_single(char *str, int *counter, char c, va_list ap);

int pr_param_processing(params *param, char *str, int *counter, char c,
                        va_list ap);
int pr_param_flags(params *param, char c);
int pr_param_width_desc(params *param, char c);
int pr_param_length_desc(params *param, char c);

void pr_param_asterisk_check(params *param, va_list ap);
int pr_param_check(params param, char c);

int pr_format_checker(params *param, char c, va_list ap, char **temp,
                      int counter);

void pr_format_chars(params param, va_list ap, char **temp, char c);
void pr_format_integer(params param, va_list ap, char **temp, char c);
void pr_format_float(params param, va_list ap, char **temp, char c);
void pr_format_eE(long double *temp_i, params param, float_params *fp,
                  string_params *sp, char **temp, char c);
void pr_format_gG(long double *temp_i, params param, float_params *fp,
                  string_params *sp, char **temp, char c);
char *pr_format_p(va_list ap);
void pr_format_n(params param, va_list ap, int counter);

void pr_string_params_init(string_params *sp);
void pr_float_params_init(params param, float_params *fp);

int pr_integer_to_str(params param, unsigned long i, char **temp, char c);
void pr_float_to_str(int len, float_params fp, char **temp, char c);
int pr_float_parsing(long double i, float_params *fp);
int pr_float_to_decimal_not(long double *i);
int pr_exp_add_to_str(int len, int exp, char c, char **temp);

void pr_string_check(params param, string_params *sp, char c);
void pr_string_print(string_params *sp, params param, char **temp);

#endif