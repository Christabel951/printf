#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

int _printf(const char *format, ...);

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

#endif
