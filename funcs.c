#include "main.h"

/**
 * op_char - prints a character
 *
 * @arg: character argument
 *
 * Return: 1
 */
int op_char(va_list arg)
{
	char c = va_arg(arg, int);

	return (_putchar(c));
}

/**
 * op_string - prints a string
 *
 * @arg: string argument pointer
 *
 * Return: no of chars printed
 */
int op_string(va_list arg)
{
	int len;
	char *string;

	string = va_arg(arg, char *);
	/* if string is null, return 0 */
	if (!string)
	{
		string = "(null)";
	}
	len = 0;

	while (string[len])
	{
		_putchar(string[len]);
		len++;
	}
	return (len);
}

/**
 * op_percent - prints the percent sign
 * 
 * @arg: to be ignored
 *
 * Return: 1 for 1 char printed
 */
int op_percent(va_list arg)
{
	(void) arg;

	return (_putchar('%'));
}
