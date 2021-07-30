#include <stdarg.h>
#include "holberton.h"
/*
 * _printf - produce output to stdout according to a format.
 * @format: constant string value -fixed argument.
 * @...: optional argument.
 *
 * Description: handle output of different data types by converting them to string. Use 
 * a given set of format specifiers[%c, %s, %%, %d] to invoke conversion of a certain data type to
 * string and display it on the standard output stream.
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};
	int (*pfunc)(va_list, flags_t *);

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
