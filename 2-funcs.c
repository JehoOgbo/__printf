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
 * op_hex - writes the octal equivalent of a number into a buffer
 *
 * @arg: argument ptr to the number
 * @buffer: the pointer to the buffer to which the equivalent is to be written
 * @old_size: pointer to the current active index in the buffer
 *
 * Return: the number of characters written
 */
int op_hex(va_list arg, char **buffer, unsigned int *old_size)
{
	unsigned int oct;

	oct = va_arg(arg, unsigned int);
	return (hex_conv(oct, buffer, old_size));
}
