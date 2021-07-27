#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

int _printf(const char *format, ...);
int _printch(char c);
int _strlen(char *s);
int _printstr(char *str);
int _print_percent(const char k);

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

#endif
