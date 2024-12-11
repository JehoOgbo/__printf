#include "main.h"
#include <stdlib.h>

int (*func(const char *format)) (va_list arg);

/**
 * _printf - function to handle printing of formatted output to stdout
 * Description: The format string is composed of zero or more directives
 *
 * @format: string containing the initial string to be printed and the format
 *
 * Return: The number of chars printed
 */
int _printf(const char *format, ...)
{
	int i;
	va_list ap;
	int (*f) (va_list arg);

	i = 0;
	va_start(ap, format);

	if (!format || !(*format))
	{
		return (-1);
	}
	while (format && *format)
	{
		/* check for format specifier and ensure it isn't end of string */
		if (*format == '%' && format[1])
		{
			/* call format finder */
			format++;
			f = func(format);
			if (f == NULL)
			{
				_putchar(*(--format));
				format++;
				continue;
			}
			i += f(ap);
			format++;
			continue;
		}
		/* if '%' is end of string don't print anything. return -1 */
		else if (*format == '%' && !(format[1]))
		{
			return (-1);
		}
		i += _putchar(*format);
		format++;
	}
	va_end(ap);
	return (i);
}

/**
 * format_find - finds the function for the appropriate char
 *
 * @format: pointer to first element of string to be checked
 *
 * Return: the right function
 */
int (*func(const char *format)) (va_list arg)
{
	int i;
	ops_t ops[] = {
		{"c", op_char},
		{"s", op_string},
		{"%", op_percent},
		{NULL, NULL}
	};

	i = 0;
	while (ops[i].f_spec)
	{
		if (*format == *ops[i].f_spec)
		{
			return(ops[i].f);	
		}
		i++;
	}

	return (NULL);
}
