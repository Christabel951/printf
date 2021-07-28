#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"
/*
 * _printf - produce output to stdout according to a format.
 * @format: constant string value -fixed argument.
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int i, cc = 0;
	char pch;
	char *str;
	va_list vl;

	va_start(vl, format);
	while (format[i])
	{
		if(format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					pch = va_arg(vl, int);
					_printch(pch);
					cc++;
					i++;
					break;
				case 's':
					str = va_arg(vl, char *);
					_printstr(str);
					cc += _strlen(str);
					i++;
					break;
				case '%':
					_printch('%');
					cc++;
					i++;
					break;
				default:
					_printch('%');
					_printch(format[i]);
					cc += 2;
					i++;
			}
		}
		else
		{
			_printch(format[i]);
			cc++;
			i++;
		}
	}
	va_end(vl);
	return (cc);
}
