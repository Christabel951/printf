#include <stdarg.h>
#include "holberton.h"
/*
 * _printf - produce output to stdout according to a format.
 * @format: constant string value -fixed argument.
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int i, cc = 0;
	char *str;
	va_list vl;

	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					cc += _printch(va_arg(vl, int));
					break;
				case 's':
					cc += _printstr(va_arg(vl, char *));
					break;
				case '%':
					cc += _printch('%');
					break;
				default:
					cc += _printch('%');
					cc += _printch(format[i]);
			}
			i++;
		}
		else
		{
			cc += _printch(format[i]);
			i++;
		}
	}
	va_end(vl);
	return (cc);
}
