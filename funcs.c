#include "main.h"
#include <limits.h>

/**
 * op_char - prints a character
 *
 * @arg: character argument
 * @buffer: pointer to buffer in which output is to be stored
 * @old_size: pointer to current index in buffer
 *
 * Return: 1
 */
int op_char(va_list arg, char **buffer, unsigned int *old_size)
{
	char c = va_arg(arg, int);

	return (_putchar(c, buffer, old_size));
}

/**
 * op_string - prints a string
 *
 * @arg: string argument pointer
 * @buffer: pointer to buffer in which output is to be stored
 * @old_size: pointer to current index in buffer
 *
 * Return: no of chars printed
 */
int op_string(va_list arg, char **buffer, unsigned int *old_size)
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
		_putchar(string[len], buffer, old_size);
		len++;
	}
	return (len);
}

/**
 * op_percent - prints the percent sign
 *
 * @arg: to be ignored
 * @buffer: pointer to buffer in which output is to be stored
 * @old_size: pointer to current index in buffer
 * Return: 1 for 1 char printed
 */
int op_percent(va_list arg, char **buffer, unsigned int *old_size)
{
	(void) arg;

	return (_putchar('%', buffer, old_size));
}

/**
 * op_integer - prints an integer
 *
 * @arg: pointer to the integer
 * @buffer: pointer to buffer in which output is to be stored
 * @old_size: pointer to current index in buffer
 *
 * Return: number of digits the integer has
 */
int op_integer(va_list arg, char **buffer, unsigned int *old_size)
{
	int num;
	int negative;

	negative = 0;
	num = va_arg(arg, int);
	/* if num is negative print - and convert the num to positive */
	if (num < 0)
	{
		_putchar('-', buffer, old_size);
		num = num * -1;

		negative = 1;
		if (num == INT_MIN)
		{
			num = INT_MAX;
			negative += print_num(INT_MAX / 10, buffer, old_size);
			negative += _putchar('8', buffer, old_size);
			return (negative);
		}
	}
	if (num == 0)
	{
		/* if num is 0 print zero and return 1 */
		_putchar('0', buffer, old_size);
		return (1);
	}
	negative += print_num(num, buffer, old_size);

	return (negative);
}

/**
 * op_binary - writes the binary equivalent of a number into a buffer
 *
 * @arg: argument ptr to the number
 * @buffer: the pointer to the buffer to which the equivalent is to be written
 * @old_size: pointer to the current active index in the buffer
 *
 * Return: the number of characters written 
 */
int op_binary(va_list arg, char **buffer, unsigned int *old_size)
{
	int bin;

	bin = va_arg(arg, int);
	return (bin_conv(bin, buffer, old_size));
}
