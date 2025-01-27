#include "my_sprintf.h"

int my_sprintf(char *str, const char *format, ...) {
  va_list ap;
  params param;
  int error = 0;
  int counter = 0;
  pr_param_reset(&param);
  va_start(ap, format);
  while (*format != '\0' && !error) {
    if (*format == '%') {
      format++;
      int pass = pr_param_single(str, &counter, *format, ap);
      if (pass) {
        while (param.checker != 4 && !error) {
          error = pr_param_processing(&param, str, &counter, *format, ap);
          format++;
        }
        pr_param_reset(&param);
      } else {
        format++;
      }
    } else {
      str[counter++] = *format;
      format++;
    }
  }
  str[counter] = '\0';
  va_end(ap);
  return counter;
}

void pr_param_reset(params *param) {
  param->checker = 0;
  param->flag_minus = 0;
  param->flag_plus = 0;
  param->flag_space = 0;
  param->flag_hashtag = 0;
  param->flag_zero = 0;
  param->flag_space_number = 0;
  param->flag_asterisk = 0;
  param->flag_dot = 0;
  param->flag_dot_space_number = 0;
  param->flag_dot_asterisk = 0;
  param->flag_h_length = 0;
  param->flag_l_length = 0;
  param->flag_L_length = 0;
}

int pr_param_single(char *str, int *counter, char c, va_list ap) {
  int pass = 0;
  char *temp;
  switch (c) {
    case 'p':
      temp = pr_format_p(ap);
      if (temp) {
        for (int i = 0; i < (int)my_strlen(temp); i++) {
          str[(*counter) + i] = temp[i];
        }
        *counter = *counter + (int)my_strlen(temp);
        free(temp);
      }
      break;
    case '%':
      str[(*counter)++] = '%';
      break;
    default:
      pass = 1;
  }
  return pass;
}

int pr_param_processing(params *param, char *str, int *counter, char c,
                        va_list ap) {
  int error = 0;
  char *temp = my_NULL;
  if (param->checker == 0) error += pr_param_flags(param, c);
  if (param->checker == 1) error += pr_param_width_desc(param, c);
  if (param->checker == 2) error += pr_param_length_desc(param, c);
  if (param->checker == 3) {
    error += pr_param_check(*param, c);
    pr_param_asterisk_check(param, ap);
    error += pr_format_checker(param, c, ap, &temp, *counter);
    if (temp && !error) {
      if (temp[0] != '\0') {
        for (int i = 0; i < (int)my_strlen(temp); i++) {
          str[(*counter) + i] = temp[i];
        }
        *counter = *counter + (int)my_strlen(temp);
      }
      param->checker = 4;
    } else {
      error++;
    }
    if (temp) free(temp);
  }
  return error;
}

int pr_param_flags(params *param, char c) {
  int error = 0;
  switch (c) {
    case '-':
      error = (param->flag_minus) * 1;
      param->flag_minus = 1;
      break;
    case '+':
      error = (param->flag_plus) * 1;
      param->flag_plus = 1;
      break;
    case ' ':
      error = (param->flag_space) * 1;
      param->flag_space = 1;
      break;
    case '#':
      error = (param->flag_hashtag) * 1;
      param->flag_hashtag = 1;
      break;
    case '0':
      error = (param->flag_zero) * 1;
      param->flag_zero = 1;
      break;
    default:
      param->checker = 1;
  }
  return error;
}

int pr_param_width_desc(params *param, char c) {
  int error = 0;
  int *befDot = &(param->flag_space_number);
  int *aftDot = &(param->flag_dot_space_number);
  switch (c) {
    case 48 ... 57:
      if (!param->flag_dot) {
        error += (param->flag_asterisk) * 1;
        *befDot = *befDot * 10 + c - '0';
      } else {
        error += (param->flag_dot_asterisk) * 1;
        *aftDot = *aftDot * 10 + c - '0';
      }
      break;
    case '*':
      if (!param->flag_dot) {
        error += (*befDot > 0) * 1;
        error += (param->flag_asterisk) * 1;
        param->flag_asterisk = 1;
      } else {
        error += (*aftDot > 0) * 1;
        error += (param->flag_dot_asterisk) * 1;
        param->flag_dot_asterisk = 1;
      }
      break;
    case '.':
      error += (param->flag_dot) * 1;
      param->flag_dot = 1;
      break;
    default:
      param->checker = 2;
  }
  return error;
}

int pr_param_length_desc(params *param, char c) {
  int error = 0;
  int checker =
      param->flag_h_length + param->flag_l_length + param->flag_L_length;
  switch (c) {
    case 'h':
      error = checker;
      param->flag_h_length = 1;
      break;
    case 'l':
      error = checker;
      param->flag_l_length = 1;
      break;
    case 'L':
      error = checker;
      param->flag_L_length = 1;
      break;
    default:
      param->checker = 3;
  }
  return error;
}

int pr_param_check(params param, char c) {
  int error = 0;
  if (param.flag_minus) error += (param.flag_zero) + (c == 'n');
  if (param.flag_plus) {
    error += (param.flag_space) * 1;
    error += ((my_strchr("csoxXun", c)) != my_NULL) * 1;
  }
  if (param.flag_space) error += ((my_strchr("csn", c)) != my_NULL) * 1;
  if (param.flag_hashtag) error += ((my_strchr("csdiun", c)) != my_NULL) * 1;
  if (param.flag_zero) {
    error += (param.flag_dot && (my_strchr("idoxXu", c)) != my_NULL) * 1;
    error += ((my_strchr("csn", c)) != my_NULL) * 1;
  }
  if (param.flag_dot) error += ((my_strchr("csn", c)) != my_NULL) * 1;
  if (param.flag_h_length) error += ((my_strchr("csfFeEgG", c)) != my_NULL) * 1;
  if (param.flag_L_length)
    error += ((my_strchr("csdioxXun", c)) != my_NULL) * 1;
  return error;
}

void pr_param_asterisk_check(params *param, va_list ap) {
  if (param->flag_asterisk) param->flag_space_number = va_arg(ap, int);
  if (param->flag_dot_asterisk) param->flag_dot_space_number = va_arg(ap, int);
}

int pr_format_checker(params *param, char c, va_list ap, char **temp,
                      int counter) {
  int error = 0;
  if (my_strchr("cs", c))
    pr_format_chars(*param, ap, temp, c);
  else if (my_strchr("idoxXu", c))
    pr_format_integer(*param, ap, temp, c);
  else if (my_strchr("fFeEgG", c))
    pr_format_float(*param, ap, temp, c);
  else if (c == 'n')
    pr_format_n(*param, ap, counter);
  else
    error++;
  return error;
}

void pr_format_chars(params param, va_list ap, char **temp, char c) {
  unsigned int ch1 = 0;
  char ch2 = 0;
  char *ch3 = my_NULL;
  string_params sp;
  pr_string_params_init(&sp);
  if (c == 'c' && param.flag_l_length) {
    ch1 = va_arg(ap, unsigned int);
    sp.temp_str_len = 2;
  } else if (c == 'c') {
    ch2 = va_arg(ap, int);
    sp.temp_str_len = 1;
  } else {
    ch3 = va_arg(ap, char *);
    sp.temp_str_len = my_strlen(ch3);
  }
  *temp = (char *)malloc(sizeof(char) * sp.temp_str_len);
  if (ch3)
    my_memcpy(*temp, ch3, sp.temp_str_len);
  else {
    unsigned int temp_c = ch1 * (ch1 > 0) + ch2 * (ch2 > 0);
    my_memcpy(*temp, &temp_c, sp.temp_str_len);
  }
  pr_string_check(param, &sp, c);
  pr_string_print(&sp, param, temp);
}

void pr_format_integer(params param, va_list ap, char **temp, char c) {
  unsigned short u1 = 0;
  short i1 = 0;
  unsigned long u2 = 0;
  long i2 = 0;
  unsigned int u3 = 0;
  int i3 = 0;
  string_params sp;
  pr_string_params_init(&sp);
  if (param.flag_h_length) {
    if (c == 'i' || c == 'd')
      i1 = va_arg(ap, int);
    else
      u1 = va_arg(ap, unsigned int);
  } else if (param.flag_l_length) {
    if (c == 'i' || c == 'd')
      i2 = va_arg(ap, long);
    else
      u2 = va_arg(ap, unsigned long);
  } else {
    if (c == 'i' || c == 'd')
      i3 = va_arg(ap, int);
    else
      u3 = va_arg(ap, unsigned int);
  }
  long temp_i = i1 + i2 + i3;
  if (temp_i < 0) {
    temp_i *= -1;
    sp.is_minus = 1;
  }
  unsigned long temp_u = u1 + u2 + u3 + temp_i;
  sp.temp_str_len = pr_integer_to_str(param, temp_u, temp, c);
  if (param.flag_hashtag && sp.temp_str_len - param.flag_dot_space_number > 0 &&
      c == 'o')
    param.flag_dot_space_number = sp.temp_str_len + 1;
  pr_string_check(param, &sp, c);
  pr_string_print(&sp, param, temp);
}

void pr_format_float(params param, va_list ap, char **temp, char c) {
  long double i1 = 0.0;
  double i2 = 0.0;
  string_params sp;
  float_params fp;
  pr_string_params_init(&sp);
  pr_float_params_init(param, &fp);
  if (param.flag_L_length)
    i1 = va_arg(ap, long double);
  else
    i2 = va_arg(ap, double);
  long double temp_i = i1 + i2;
  if (temp_i < 0) {
    temp_i *= -1.0;
    sp.is_minus++;
  }
  if (c == 'e' || c == 'E')
    pr_format_eE(&temp_i, param, &fp, &sp, temp, c);
  else if (c == 'g' || c == 'G')
    pr_format_gG(&temp_i, param, &fp, &sp, temp, c);
  else {
    if (param.flag_hashtag) {
      param.flag_dot_space_number = 0;
      fp.dot = 1;
    }
    sp.temp_str_len = pr_float_parsing(temp_i, &fp);
    pr_float_to_str(sp.temp_str_len, fp, temp, c);
  }
  pr_string_check(param, &sp, c);
  pr_string_print(&sp, param, temp);
}

void pr_format_eE(long double *temp_i, params param, float_params *fp,
                  string_params *sp, char **temp, char c) {
  int exp = 0;
  exp = pr_float_to_decimal_not(temp_i);
  if (param.flag_hashtag) {
    param.flag_dot_space_number = 0;
    fp->dot = 1;
  }
  sp->temp_str_len = pr_float_parsing(*temp_i, fp);
  pr_float_to_str(sp->temp_str_len, *fp, temp, c);
  sp->temp_str_len = pr_exp_add_to_str(sp->temp_str_len, exp, c, temp);
}

void pr_format_gG(long double *temp_i, params param, float_params *fp,
                  string_params *sp, char **temp, char c) {
  long double temp_temp_i = *temp_i;
  if (!fp->counter_prec) {
    fp->counter_prec = 1;
    fp->dot = 1;
  }
  int exp = pr_float_to_decimal_not(&temp_temp_i);
  if (fp->counter_prec > exp && exp >= -4) {
    fp->counter_prec = fp->counter_prec - 1 - exp;
    if (!fp->counter_prec && !param.flag_hashtag) fp->dot = 0;
    sp->temp_str_len = pr_float_parsing(*temp_i, fp);
    pr_float_to_str(sp->temp_str_len, *fp, temp, c);
  } else {
    fp->counter_prec = fp->counter_prec - 1;
    exp = pr_float_to_decimal_not(temp_i);
    sp->temp_str_len = pr_float_parsing(*temp_i, fp);
    if (!fp->mod_i && !param.flag_hashtag) {
      sp->temp_str_len -= fp->counter_prec + fp->dot;
      fp->counter_prec = 0;
      fp->dot = 0;
    }
    pr_float_to_str(sp->temp_str_len, *fp, temp, c);
    sp->temp_str_len =
        pr_exp_add_to_str(sp->temp_str_len, exp, 'e' + (c - 'g'), temp);
  }
}

char *pr_format_p(va_list ap) {
  long int num = va_arg(ap, long int);
  long int temp = num;
  int counter = 0;
  while (temp > 0) {
    temp /= 16;
    counter++;
  }
  counter += 2;
  char *str = malloc(sizeof(char) * counter + 1);
  str[0] = '0';
  str[1] = 'x';
  for (int i = counter - 1; i >= 2; i--) {
    temp = num % 16;
    num = num / 16;
    if (temp > 9)
      str[i] = temp % 10 + 'a';
    else
      str[i] = temp + '0';
  }
  str[counter] = '\0';
  return str;
}

void pr_format_n(params param, va_list ap, int counter) {
  if (param.flag_h_length) {
    short *i1 = va_arg(ap, short *);
    *i1 = counter;
  } else if (param.flag_l_length) {
    long *i2 = va_arg(ap, long *);
    *i2 = counter;
  } else {
    int *i3 = va_arg(ap, int *);
    *i3 = counter;
  }
}

void pr_float_params_init(params param, float_params *fp) {
  fp->counter_prec =
      (param.flag_dot) * param.flag_dot_space_number + (!param.flag_dot) * 6;
  fp->counter_prec_undefined = 0;
  fp->counter_int = 0;
  fp->counter_int_undefined = 0;
  fp->dot = 0 + (fp->counter_prec > 0) * 1;
  fp->int_i = 0;
  fp->mod_i = 0;
  fp->is_nan = 0;
}

int pr_integer_to_str(params param, unsigned long i, char **temp, char c) {
  int counter = 0;
  unsigned long temp_i = i;
  int hashtag_prefix = 0;
  int ch = 1 * (c == 'i' || c == 'd' || c == 'u') + 2 * (c == 'o') +
           3 * (c == 'x' || c == 'X');
  while (temp_i) {
    temp_i /= ((ch == 1) * 10 + (ch == 2) * 8 + (ch == 3) * 16);
    counter++;
  }
  if (param.flag_hashtag && ch == 3) {
    counter += 2;
    hashtag_prefix += 2;
  }
  *temp = (char *)malloc(sizeof(char) * counter);
  for (int a = counter - 1; a >= hashtag_prefix; a--) {
    temp_i = i % ((ch == 1) * 10 + (ch == 2) * 8 + (ch == 3) * 16);
    i /= ((ch == 1) * 10 + (ch == 2) * 8 + (ch == 3) * 16);
    if (temp_i > 9) {
      temp_i %= 10;
      (*temp)[a] = temp_i + 'a' + (c - 'x');
    } else
      (*temp)[a] = temp_i + '0';
  }
  if (param.flag_hashtag && ch == 3) {
    (*temp)[0] = '0';
    (*temp)[1] = 'x' + (c - 'x');
  }
  return counter;
}

int pr_float_to_decimal_not(long double *i) {
  int counter = 0;
  long double temp_i = *i;
  if (!isnan(temp_i) && !isinf(temp_i)) {
    while (floorl(temp_i) > 9.0) {
      temp_i /= 10.0;
      counter--;
    }
    while (floorl(temp_i) < 1.0) {
      temp_i *= 10.0;
      counter++;
    }
    temp_i = *i;
    temp_i *= pow(10, counter);
    *i = temp_i;
  }
  return (-counter);
}

int pr_float_parsing(long double i, float_params *fp) {
  long double temp_int;
  long double temp_mod = modfl(i, &temp_int);
  long double temp_temp_int = temp_int;
  int temp_str_len = 0;
  if (isnan(i) || isinf(i)) {
    fp->dot = 0;
    fp->is_nan += isnan(i) * 1;
    fp->is_nan += isinf(i) * 2;
    temp_str_len = 3;
  } else {
    while ((int)temp_temp_int) {
      temp_temp_int /= 10;
      fp->counter_int++;
    }
    if (!fp->counter_int) fp->counter_int = 1;
    if (fp->counter_int > PREC) {
      fp->counter_int_undefined = fp->counter_int - PREC;
      fp->counter_int -= fp->counter_int_undefined;
    }
    if (fp->counter_prec > PREC) {
      fp->counter_prec_undefined = fp->counter_prec - PREC;
      fp->counter_prec -= fp->counter_prec_undefined;
    }
    temp_mod *= pow(10, fp->counter_prec);
    temp_mod = roundl(temp_mod);
    if (fp->counter_int_undefined) {
      temp_int /= pow(10, fp->counter_int_undefined);
      temp_int = roundl(temp_int);
    }
    fp->mod_i = (long long)temp_mod;
    fp->int_i = (long long)temp_int;
    temp_str_len = fp->counter_int + fp->counter_int_undefined + fp->dot +
                   fp->counter_prec + fp->counter_prec_undefined;
  }
  return temp_str_len;
}

int pr_exp_add_to_str(int len, int exp, char c, char **temp) {
  int size = len;
  int counter = 0;
  if (len > 0) {
    int is_minus = 0;
    if (exp < 0) {
      exp *= -1;
      is_minus++;
    }
    int temp_i = exp;
    while (temp_i > 0) {
      temp_i /= 10;
      counter++;
    }
    counter += (!counter);
    counter -= (counter > 2);
    size = len + 3 + counter;
    (*temp) = (char *)realloc(*temp, size);
    (*temp)[len] = c;
    (*temp)[len + 1] = is_minus * '-' + !is_minus * '+';
    temp_i = exp;
    for (int i = 1; i <= counter; i++) {
      temp_i = temp_i % (int)pow(10, counter + 2 - i);
      int temp_temp_i = temp_i / (int)pow(10, counter + 1 - i);
      (*temp)[len + 1 + i] = temp_temp_i + '0';
    }
    (*temp)[len + counter + 2] = temp_i % 10 + '0';
  }
  return size;
}

void pr_float_to_str(int len, float_params fp, char **temp, char c) {
  int temp_i = 0;
  int counter = 0;
  unsigned long long temp_int = fp.int_i;
  unsigned long long temp_mod = fp.mod_i;
  if (fp.is_nan) {
    *temp = (char *)malloc(sizeof(char) * 4);
    if (fp.is_nan == 1 && !(c - 'a' < 0))
      *temp = my_memcpy(*temp, "nan", 3);
    else if (fp.is_nan == 1 && (c - 'a' < 0))
      *temp = my_memcpy(*temp, "NAN", 3);
    else if (fp.is_nan == 2 && !(c - 'a' < 0))
      *temp = my_memcpy(*temp, "inf", 3);
    else if (fp.is_nan == 2 && (c - 'a' < 0))
      *temp = my_memcpy(*temp, "INF", 3);
    (*temp)[3] = '\0';
  } else {
    *temp = (char *)malloc(sizeof(char) * len);
    for (int i = fp.counter_int - 1; i >= 0; i--) {
      temp_i = temp_int % 10;
      temp_int /= 10;
      (*temp)[i] = temp_i + '0';
      counter++;
    }
    for (int i = 0; i < fp.counter_int_undefined; i++) {
      (*temp)[counter++] = '0';
    }
    if (fp.dot) (*temp)[counter++] = '.';
    for (int i = fp.counter_prec - 1; i >= 0; i--) {
      temp_i = temp_mod % 10;
      temp_mod /= 10;
      (*temp)[counter + i] = temp_i + '0';
    }
    for (int i = 0; i < fp.counter_prec_undefined; i++) {
      (*temp)[counter + fp.counter_prec + i] = '0';
    }
  }
}

void pr_string_params_init(string_params *sp) {
  sp->precision_num = 0;
  sp->space_num = 0;
  sp->is_space = 0;
  sp->is_sign = 0;
  sp->is_minus = 0;
  sp->str_len = 0;
  sp->temp_str_len = 0;
}

void pr_string_check(params param, string_params *sp, char c) {
  if (my_strchr("idoxXu", c) != my_NULL)
    sp->precision_num = ((param.flag_dot_space_number - sp->temp_str_len) > 0) *
                        (param.flag_dot_space_number - sp->temp_str_len);
  sp->space_num =
      (param.flag_space_number - sp->precision_num - sp->temp_str_len > 0) *
      (param.flag_space_number - sp->precision_num - sp->temp_str_len);
  sp->is_space = (param.flag_space && !sp->is_minus && !sp->precision_num &&
                  (!sp->space_num || param.flag_minus)) *
                 1;
  sp->space_num -= (sp->is_space && sp->space_num);
  if (param.flag_plus || sp->is_minus) {
    sp->is_sign++;
    sp->space_num += (sp->space_num > 0) * -1;
  }
  if (param.flag_zero && sp->space_num) {
    sp->precision_num = sp->space_num;
    sp->space_num = 0;
  }
  sp->str_len = sp->temp_str_len + sp->space_num + sp->precision_num +
                sp->is_space + sp->is_sign;
  sp->is_sign = (sp->is_minus) * 2 + (param.flag_plus && !sp->is_minus) * 1;
}

void pr_string_print(string_params *sp, params param, char **temp) {
  char *temp_str = (char *)malloc(sizeof(char) * sp->str_len + 1);
  int str_counter = 0;
  for (int i = 0; i < sp->str_len; i++) {
    if (sp->is_space) {
      temp_str[i] = ' ';
      sp->is_space--;
    } else if (sp->space_num && !param.flag_minus) {
      temp_str[i] = (param.flag_zero) * '0' + (!param.flag_zero) * ' ';
      sp->space_num--;
    } else if (param.flag_minus && str_counter == sp->temp_str_len) {
      temp_str[i] = ' ';
    } else {
      if (sp->is_sign) {
        temp_str[i] = (sp->is_sign == 2) * '-' + (sp->is_sign == 1) * '+';
        sp->is_sign = 0;
      } else if (sp->precision_num) {
        temp_str[i] = '0';
        sp->precision_num--;
      } else {
        temp_str[i] = (*temp)[str_counter];
        str_counter++;
      }
    }
  }
  temp_str[sp->str_len] = '\0';
  if (*temp) free(*temp);
  *temp = temp_str;
}