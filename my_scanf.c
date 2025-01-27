#include "my_scanf.h"

int my_sscanf(const char *str, const char *format, ...) {
  va_list ap;
  params param;
  int error = 0;
  int str_counter = 0;
  int format_counter = 0;
  sc_param_reset(&param);
  param.success_checker = 0;
  va_start(ap, format);
  while (format[format_counter] != '\0' && !error &&
         !(str[str_counter] == '\0')) {
    if (format[format_counter] == ' ')
      while (my_strchr(IS_SPACE, str[str_counter])) str_counter++;
    else if (format[format_counter] == '%') {
      for (; param.checker != 3 && !error;) {
        format_counter++;
        error += sc_param_processing(&param, format[format_counter]);
      }
      if (!error)
        error += sc_format_checker(&param, (char *)str, &str_counter, ap,
                                   (char *)format, &format_counter);
      sc_param_reset(&param);
    } else {
      if (format[format_counter] == str[str_counter])
        str_counter++;
      else
        error++;
    }
    format_counter++;
  }
  if (format[format_counter] == '%') {
    format_counter++;
    if (format[format_counter] == 'n') sc_format_size(str_counter, ap);
  }
  va_end(ap);
  return param.success_checker;
}

void sc_param_reset(params *param) {
  param->checker = 0;
  param->flag_space_number = 0;
  param->flag_asterisk = 0;
  param->flag_h_length = 0;
  param->flag_l_length = 0;
  param->flag_L_length = 0;
}

int sc_param_processing(params *param, char c) {
  int error = 0;
  if (param->checker == 0) error += sc_param_width_desc(param, c);
  if (param->checker == 1) error += sc_param_length_desc(param, c);
  if (param->checker == 2) {
    error += sc_param_check(*param, c);
    param->checker = 3;
  }
  return error;
}

int sc_param_width_desc(params *param, char c) {
  int error = 0;
  int *befDot = &(param->flag_space_number);
  switch (c) {
    case 48 ... 57:
      error += (param->flag_asterisk) * 1;
      *befDot = *befDot * 10 + c - '0';
      break;
    case '*':
      error += (*befDot > 0) * 1;
      error += (param->flag_asterisk) * 1;
      param->flag_asterisk = 1;
      break;
    default:
      param->checker = 1;
  }
  return error;
}

int sc_param_length_desc(params *param, char c) {
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
      param->checker = 2;
  }
  return error;
}

int sc_param_check(params param, char c) {
  int error = 0;
  if (param.flag_space_number) error += !((my_strchr("n", c)) == my_NULL);
  if (param.flag_h_length) error += ((my_strchr("diuoxXn", c)) == my_NULL);
  if (param.flag_l_length)
    error += ((my_strchr("diuoxXneEfFgGcs", c)) == my_NULL);
  if (param.flag_L_length) error += ((my_strchr("eEfFgG", c)) == my_NULL);
  return error;
}

void sc_soc_params_init(set_of_char_params *socparam) {
  socparam->soc_str = my_NULL;
  socparam->soc_str_size = 0;
  socparam->soc_int_s = 0;
  socparam->soc_int_e = 0;
  socparam->soc_reverse = 0;
}

int sc_format_checker(params *param, char *str, int *str_counter, va_list ap,
                      char *format, int *format_counter) {
  int error = 0;
  if (!my_strchr("[cn", format[*format_counter]))
    while (my_strchr(IS_SPACE, str[*str_counter])) (*str_counter)++;
  if (format[*format_counter] == '\0')
    error++;
  else if (my_strchr("idoxXu", format[*format_counter]))
    error += sc_format_integer(*param, str, str_counter, ap,
                               format[*format_counter]);
  else if (my_strchr("fFeEgG", format[*format_counter]))
    error += sc_format_float(*param, str, str_counter, ap);
  else if (my_strchr("cs", format[*format_counter]))
    error +=
        sc_format_chars(*param, str, str_counter, ap, format[*format_counter]);
  else if (format[*format_counter] == 'p')
    error += sc_format_pointer(*param, str, str_counter, ap);
  else if (format[*format_counter] == 'n')
    sc_format_size(*str_counter, ap);
  else if (format[*format_counter] == '[') {
    (*format_counter)++;
    error +=
        sc_format_soc(*param, str, str_counter, ap, format, format_counter);
  } else
    error++;
  if (!error && !param->flag_asterisk && format[*format_counter] != 'n')
    param->success_checker++;
  return error;
}

int sc_format_soc(params param, char *str, int *str_counter, va_list ap,
                  char *format, int *format_counter) {
  int error = 0;
  set_of_char_params socparam;
  sc_soc_params_init(&socparam);
  char *temp_format = &format[*format_counter];
  error += sc_format_soc_str_size(&socparam, temp_format);
  socparam.soc_str = (char *)calloc(sizeof(char), socparam.soc_str_size + 1);
  error += sc_format_soc_range(&socparam, temp_format);
  *format_counter += socparam.soc_str_size;
  char *str_pointer = va_arg(ap, char *);
  int checker = 0;
  int counter = 0;
  for (; (counter < param.flag_space_number || !param.flag_space_number) &&
         !checker && !error;) {
    if (((my_strchr(socparam.soc_str, str[*str_counter]) != my_NULL ||
          (str[*str_counter] >= socparam.soc_int_s &&
           str[*str_counter] <= socparam.soc_int_e)) ^
         (socparam.soc_reverse)) &&
        str[*str_counter] != '\0')
      str_pointer[counter++] = str[(*str_counter)++];
    else
      checker++;
  }
  error += (!counter);
  free(socparam.soc_str);
  if (!error) str_pointer[counter] = '\0';
  return error;
}

int sc_format_soc_str_size(set_of_char_params *socparam, char *temp_format) {
  int checker = 0;
  for (int i = 0; *(temp_format + i) != '\0' && !checker; i++) {
    if (*(temp_format + i) == '^' && !i)
      socparam->soc_reverse++;
    else if (*(temp_format + i) == ']') {
      if ((socparam->soc_reverse && i == 1) || (!socparam->soc_reverse && !i))
        socparam->soc_str_size++;
      else
        checker++;
    } else
      socparam->soc_str_size++;
  }
  return (!checker || !socparam->soc_str_size);
}

int sc_format_soc_range(set_of_char_params *socparam, char *temp_format) {
  int prev_soc_char = 0;
  int temp_soc_counter = 0;
  int temp_soc_size = socparam->soc_str_size;
  for (int i = 0; i < temp_soc_size + socparam->soc_reverse; i++) {
    if (socparam->soc_reverse && !i) i++;
    if (*(temp_format + i) == '-' && prev_soc_char && i + 1 <= temp_soc_size)
      if (*(temp_format + i + 1) > prev_soc_char) {
        i++;
        if (socparam->soc_int_s > prev_soc_char || !socparam->soc_int_s)
          socparam->soc_int_s = prev_soc_char;
        if (socparam->soc_int_e < *(temp_format + i))
          socparam->soc_int_e = (int)(*(temp_format + i));
      }
    socparam->soc_str[temp_soc_counter++] = *(temp_format + i);
    prev_soc_char = (int)(*(temp_format + i));
  }
  return (!temp_soc_counter || (!temp_soc_counter));
}

int sc_format_integer(params param, char *str, int *str_counter, va_list ap,
                      char c) {
  int minus = 0;
  int error = 0;
  int temp_number = param.flag_space_number;
  if (str[*str_counter] == '+' || str[*str_counter] == '-') {
    minus += (str[*str_counter] == '-');
    temp_number -= (temp_number > 0);
    (*str_counter)++;
  }
  unsigned long temp_i = 0;
  error += sc_format_integer_transform(param, str, str_counter, &temp_i,
                                       temp_number, c);
  if (minus) temp_i *= -1;
  if (!error && !param.flag_asterisk)
    sc_format_integer_assign(param, ap, temp_i, c);
  return error;
}

int sc_format_integer_transform(params param, char *str, int *str_counter,
                                unsigned long *temp_i, int temp_number,
                                char c) {
  int error = 0;
  int temp = 0;
  int int_counter = 0;
  char *temp_str = &str[*str_counter];
  for (; ((temp_number > 0) || (!param.flag_space_number)) &&
         ((*temp_str >= '0' && *temp_str <= '9') ||
          (((*temp_str >= 'a' && *temp_str <= 'f') ||
            (*temp_str >= 'A' && *temp_str <= 'F')) &&
           (c == 'x' || c == 'X')));
       temp_str++) {
    int_counter++;
    temp_number -= (temp_number > 0) * 1;
  }
  temp_str = &str[*str_counter];
  for (int i = int_counter - 1; i >= 0 && !error; i--) {
    if (my_strchr("diu", c))
      *temp_i += pow(10, temp++) * (*(temp_str + i) - '0');
    else if (c == 'o')
      if (*(temp_str + i) >= '8')
        error++;
      else
        *temp_i += pow(8, temp++) * (*(temp_str + i) - '0');
    else {
      if (*(temp_str + i) - '0' < 10)
        *temp_i += pow(16, temp++) * (*(temp_str + i) - '0');
      else
        *temp_i +=
            pow(16, temp++) * (*(temp_str + i) - 'a' +
                               (*(temp_str + i) < 'a') * ('a' - 'A') + 10);
    }
  }
  if (int_counter >= 20 && c == 'u') *temp_i = ULONG_MAX;
  *str_counter += int_counter;
  return error += (!int_counter);
}

void sc_format_integer_assign(params param, va_list ap, unsigned long temp_i,
                              char c) {
  if (param.flag_h_length) {
    if (c == 'u') {
      unsigned short *i1 = va_arg(ap, unsigned short *);
      *i1 = temp_i;
    } else {
      short *i1 = va_arg(ap, short *);
      *i1 = temp_i;
    }
  } else if (param.flag_l_length) {
    if (c == 'u') {
      unsigned long *i2 = va_arg(ap, unsigned long *);
      *i2 = temp_i;
    } else {
      long *i2 = va_arg(ap, long *);
      *i2 = temp_i;
    }
  } else {
    if (c == 'u') {
      unsigned *i3 = va_arg(ap, unsigned *);
      *i3 = temp_i;
    } else {
      int *i3 = va_arg(ap, int *);
      *i3 = temp_i;
    }
  }
}

int sc_format_float(params param, char *str, int *str_counter, va_list ap) {
  int minus = 0;
  int error = 0;
  int temp_number = param.flag_space_number;
  if (str[*str_counter] == '+' || str[*str_counter] == '-') {
    minus += (str[*str_counter] == '-');
    (*str_counter)++;
    temp_number -= (temp_number > 0);
  }
  long double temp_i = 0.0;
  if (my_strchr("iInN", str[*str_counter]))
    error += sc_format_float_exc(param, str, str_counter, &temp_i, temp_number,
                                 minus);
  else {
    error += sc_format_float_transform(param, str, str_counter, &temp_i,
                                       &temp_number);
    sc_format_float_exp(param, str, str_counter, &temp_i, temp_number);
    if (minus && temp_i != 0.0) temp_i *= -1;
  }
  if (!error && !param.flag_asterisk) sc_format_float_assign(param, ap, temp_i);
  return error;
}

int sc_format_float_exc(params param, char *str, int *str_counter,
                        long double *temp_i, int temp_number, int minus) {
  int error = 0;
  char *temp_str = &str[*str_counter];
  char str_infinity[9] = "infinity";
  char str_inf[4] = "inf";
  char str_nan[4] = "nan";
  char *temp_comp = calloc(sizeof(char), 9);
  for (int i = 0; (temp_number > 0 || !param.flag_space_number) && i < 8 &&
                  *temp_str != '\0';
       i++) {
    if (*(temp_str + i) <= 'Z' && *(temp_str + i) >= 'A')
      temp_comp[i] = *(temp_str + i) + ('a' - 'A');
    else
      temp_comp[i] = *(temp_str + i);
  }
  int counter = 0;
  if (my_strstr(temp_comp, str_infinity) == temp_comp) {
    if (minus)
      *temp_i = -INFINITY;
    else
      *temp_i = INFINITY;
    counter = 8;
  } else if (my_strstr(temp_comp, str_inf) == temp_comp) {
    if (minus)
      *temp_i = -INFINITY;
    else
      *temp_i = INFINITY;
    counter = 3;
  } else if (my_strstr(temp_comp, str_nan) == temp_comp) {
    if (minus)
      *temp_i = -NAN;
    else
      *temp_i = NAN;
    counter = 3;
  } else
    error++;
  *str_counter += counter;
  free(temp_comp);
  return error;
}

int sc_format_float_transform(params param, char *str, int *str_counter,
                              long double *temp_i, int *temp_number) {
  int error = 0;
  int dec_counter = 0;
  int mod_counter = 0;
  int dot = 0;
  char *temp_str = &str[*str_counter];
  long double temp_dec = 0;
  long double temp_mod = 0;
  for (; (*temp_number > 0 || !param.flag_space_number) &&
         ((*temp_str >= '0' && *temp_str <= '9') ||
          (*temp_str == '.' && dot < 2));
       temp_str++) {
    if (*temp_str == '.')
      dot++;
    else {
      if (!dot) {
        temp_dec = temp_dec * 10.0 + (*temp_str - '0');
        dec_counter++;
      } else {
        temp_mod = temp_mod * 10.0 + (*temp_str - '0');
        mod_counter++;
      }
    }
    (*temp_number)--;
  }
  *temp_i = temp_dec + temp_mod * pow(10, -mod_counter);
  *str_counter += dec_counter + dot + mod_counter;
  return error += (dot > 2 || (!dec_counter && !mod_counter));
}

void sc_format_float_exp(params param, char *str, int *str_counter,
                         long double *temp_i, int temp_number) {
  int power = 0;
  int power_minus = 0;
  if ((str[*str_counter] == 'e' || str[*str_counter] == 'E') &&
      (temp_number > 0 || !param.flag_space_number)) {
    temp_number -= (temp_number > 0);
    (*str_counter)++;
    if ((str[*str_counter] == '+' || str[*str_counter] == '-') &&
        (temp_number > 0 || !param.flag_space_number)) {
      power_minus += (str[*str_counter] == '-');
      temp_number -= (temp_number > 0);
      (*str_counter)++;
    }
    for (; (str[*str_counter] >= '0' && str[*str_counter] <= '9') &&
           (temp_number > 0 || !param.flag_space_number);
         (*str_counter)++) {
      power = power * 10 + (str[*str_counter] - '0');
      temp_number -= (temp_number > 0);
    }
  }
  if (power)
    *temp_i *= pow(10, -power * (power_minus) + power * (!power_minus));
}

void sc_format_float_assign(params param, va_list ap, long double temp_i) {
  if (param.flag_L_length) {
    long double *i1 = va_arg(ap, long double *);
    *i1 = temp_i;
  } else if (param.flag_l_length) {
    double *i2 = va_arg(ap, double *);
    *i2 = temp_i;
  } else {
    float *i3 = va_arg(ap, float *);
    *i3 = temp_i;
  }
}

int sc_format_chars(params param, char *str, int *str_counter, va_list ap,
                    char c) {
  int error = 0;
  char *temp_str = my_NULL;
  int temp_str_counter = 0;
  if (param.flag_l_length && c == 'c') {
    temp_str_counter = 2;
    temp_str = (char *)calloc(sizeof(char), temp_str_counter);
    temp_str[0] = str[(*str_counter)++];
    if (str[*str_counter] != '\0')
      temp_str[1] = str[(*str_counter)++];
    else
      error++;
  } else if (c == 'c') {
    temp_str_counter = 1;
    temp_str = (char *)calloc(sizeof(char), temp_str_counter);
    temp_str[0] = str[(*str_counter)++];
  } else {
    int temp_space_number = param.flag_space_number;
    for (int i = 0; (temp_space_number > 0 || !param.flag_space_number) &&
                    str[*str_counter + i] != '\0' &&
                    !my_strchr(IS_SPACE, str[*str_counter + i]);
         i++) {
      temp_space_number -= (temp_space_number > 0) * 1;
      temp_str_counter++;
    }
    temp_str = (char *)calloc(sizeof(char), temp_str_counter + 1);
    for (int i = 0; i < temp_str_counter; i++) {
      temp_str[i] = str[(*str_counter)++];
    }
    temp_str[temp_str_counter++] = '\0';
  }
  if (!error && !param.flag_asterisk) {
    char *s = va_arg(ap, char *);
    for (int i = 0; i < temp_str_counter; i++) {
      s[i] = temp_str[i];
    }
  }
  free(temp_str);
  return error++;
}

int sc_format_pointer(params param, char *str, int *str_counter, va_list ap) {
  int error = 0;
  void **temp = va_arg(ap, void **);
  (*temp) = my_NULL;
  if (str[*str_counter] == '0' &&
      (str[*str_counter + 1] == 'x' || str[*str_counter + 1] == 'X'))
    (*str_counter) += 2;
  else
    error++;
  long temp_i = 0;
  char c;
  for (int i = 11; i >= 0 && !error; i--) {
    c = str[*str_counter];
    if (c - '0' >= 0 && c - '0' < 10)
      temp_i += pow(16, i) * (str[(*str_counter)++] - '0');
    else if ((c - 'a' >= 0 && c - 'f' <= 0) || (c - 'A' >= 0 && c - 'F' <= 0))
      temp_i += pow(16, i) * (str[(*str_counter)++] - 'a' + 10);
    else
      error++;
  }
  if (!error && !param.flag_asterisk) (*temp) += temp_i;
  return error;
}

void sc_format_size(int str_counter, va_list ap) {
  int *temp = va_arg(ap, int *);
  *temp = str_counter;
}