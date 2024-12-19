#include "main.h"
#include <stdlib.h>
#include <unistd.h>

int (*func(const char *format)) (va_list, char **, unsigned int *);
int writer(char *buffer, int i);

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
	int (*f)(va_list arg, char **buffer, unsigned int *old_size);
	char **buffer, *buf;
	unsigned int *old_size, old;

	buf = NULL;
	buffer = &buf;
	old = 0;
	old_size = &old;
	i = 0;
	va_start(ap, format);
	if (!format || !(*format))
		return (-1);
	while (format && *format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			f = func(format);
			if (f == NULL)
			{
				i += _putchar(*(format - 1), buffer, old_size);
				continue;
			}
			i += f(ap, buffer, old_size);
			format++;
			continue;
		}
		else if (*format == '%' && !(format[1]))
		{
			free(*buffer);
			return (-1);
		}
		i += _putchar(*format, buffer, old_size);
		format++;
	}
	va_end(ap);
	return (writer(*buffer, i));
}

/**
 * func - finds the function for the appropriate char
 *
 * @format: pointer to first element of string to be checked
 *
 * Return: the right function
 */
int (*func(const char *format)) (va_list, char **, unsigned int *)
{
	int i;
	ops_t ops[] = {
		{"c", op_char},
		{"s", op_string},
		{"%", op_percent},
		{"d", op_integer},
		{"i", op_integer},
		{"b", op_binary},
		{"u", op_unsigned},
		{"o", op_octal},
		{"x", op_hex},
		{"X", op_hex},
		{NULL, NULL}
	};

	i = 0;
	while (ops[i].f_spec)
	{
		if (*format == *ops[i].f_spec)
		{
			return (ops[i].f);
		}
		i++;
	}

	return (NULL);
}

/**
 * writer - writes the input to stdout
 *
 * @buffer: the buffer to be written
 * @i: number of bytes to be written
 *
 * Return: the number of bytes written
 */
int writer(char *buffer, int i)
{
	int count;

	count = write(STDOUT_FILENO, buffer, i);
	free(buffer);

	return (count);
}
