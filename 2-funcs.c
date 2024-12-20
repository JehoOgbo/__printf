#include "main.h"

/**
 * op_unsigned - writes an unsigned integer into a buffer
 *
 * @arg: pointer to the unsigned integer
 * @buffer: pointer to the buffer
 * @old_size: pointer to the current index in the buffer
 *
 * Return: the number of characters printed
 */
int op_unsigned(va_list arg, char **buffer, unsigned int *old_size)
{
	unsigned int num;

	num = va_arg(arg, unsigned int);

	if (num == 0)
	{
		_putchar(num + '0', buffer, old_size);
		return (1);
	}

	return (print_unsigned(num, buffer, old_size));
}

/**
 * op_octal - writes the octal equivalent of a number into a buffer
 *
 * @arg: argument ptr to the number
 * @buffer: the pointer to the buffer to which the equivalent is to be written
 * @old_size: pointer to the current active index in the buffer
 *
 * Return: the number of characters written
 */
int op_octal(va_list arg, char **buffer, unsigned int *old_size)
{
	unsigned int oct;

	oct = va_arg(arg, unsigned int);
	return (oct_conv(oct, buffer, old_size));
}

/**
 * op_hex - writes the hexadecimal equivalent of a number into a buffer
 *
 * @arg: argument ptr to the number
 * @buffer: the pointer to the buffer to which the equivalent is to be written
 * @old_size: pointer to the current active index in the buffer
 *
 * Return: the number of characters written
 */
int op_hex(va_list arg, char **buffer, unsigned int *old_size)
{
	unsigned int hex;

	hex = va_arg(arg, unsigned int);
	return (hex_conv(hex, buffer, old_size, 87));
}

/**
 * op_sp_string - prints a string with some caveats
 * Description: Non printable characters (0 < ASCII value < 32 or >= 127)
 * are printed this way: \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 *
 * @arg: argument ptr to the string
 * @buffer: the pointer to the buffer to which the equivalent is to be written
 * @old_size: pointer to the current active index in the buffer
 *
 * Return: the number of characters written
 */
int op_sp_string(va_list arg, char **buffer, unsigned int *old_size)
{
	int i;
	int count;
	char *string;

	i = 0;
	count = 0;
	string = va_arg(arg, char *);

	while (string[i])
	{
		if ((string[i] > 0 && string[i] < 32) || (string[i] >= 127))
		{
			count += hex_print(string[i], buffer, old_size);
			i++;
		}
		_putchar(string[i], buffer, old_size);
		i++;
		count++;
	}
	return (count);
}

/**
 * op_pointer - writes an address into a buffer
 *
 * @arg: argument ptr to the number
 * @buffer: the pointer to the buffer to which the address is to be written
 * @old_size: pointer to the current active index in the buffer
 *
 * Return: the number of characters written
 */
int op_pointer(va_list arg, char **buffer, unsigned int *old_size)
{
	long unsigned int point;
	int count;

	count = 0;
	point = va_arg(arg, long unsigned int);
	count += _putchar('0', buffer, old_size);
	count += _putchar('x', buffer, old_size);
	count += hex_conv(point, buffer, old_size, 87);

	return (count);
}
