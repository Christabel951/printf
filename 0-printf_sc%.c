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
	int i, counter = 0;
	va_list opt;

	if (format)
	{
		va_start(opt, format);
		i = 0;
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				if (format [i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%')	
				{
					if (format[i + 1] == 'c')
						counter += _printch(va_arg(opt, int));
					if (format[i] == 's')
						counter += _printstr(va_arg(opt, char *));
					if (format[i + 1] == '%')
						counter += _print_percent(va_arg(opt, int));
					i += 2;
					continue;
				}
				else
				{
					_printch(format[i]);
					i++;
				}
			}
			_printch(format[i]);
			counter++;
			i++;
		}
		return (counter);
	}
	return (-1);
}
