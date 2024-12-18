#include "main.h"
#include <stdlib.h>
#include <unistd.h>

int (*func(const char *format)) (va_list arg, char **buffer, unsigned int *old_size);

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
	int (*f) (va_list arg, char **buffer, unsigned int *old_size);
	char **buffer;
	char *buf;
	unsigned int *old_size;
	unsigned int old;

	buf = NULL;
	buffer = &buf;
	old = 0;
	old_size = &old;
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
				i += _putchar(*(--format), buffer, old_size);
				format++;
				continue;
			}
			i += f(ap, buffer, old_size);
			format++;
			continue;
		}
		/* if '%' is end of string don't print anything. return -1 */
		/* Don't forget to free */
		else if (*format == '%' && !(format[1]))
		{
			free(*buffer);
			return (-1);
		}
		i += _putchar(*format, buffer, old_size);
		format++;
	}
	write(STDOUT_FILENO, *buffer, i);
	va_end(ap);
	free(*buffer);
	return (i);
}

/**
 * format_find - finds the function for the appropriate char
 *
 * @format: pointer to first element of string to be checked
 *
 * Return: the right function
 */
int (*func(const char *format)) (va_list arg, char **buffer, unsigned int *old_size)
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
