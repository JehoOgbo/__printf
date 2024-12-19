#include "main.h"

/**
 * print_num - sends the number into the buffer digit by digit
 *
 * @num: the number which is to be printed
 * @buffer: pointer to the buffer which is to be used for calling _putchar
 * @old_size: pointer to current buffer index
 *
 * Return: the number of digits in the number
 */
int print_num(int num, char **buffer, unsigned int *old_size)
{
	int count;

	count = 0;
	if (num == 0)
	{
		return (0);
	}

	count =  1 + print_num(num / 10, buffer, old_size);
	_putchar(num % 10 + 48, buffer, old_size);

	return (count);
}

/**
 * bin_conv - converts an integer to binary and pass the result into a buffer
 *
 * @num: the number to be converted and written
 * @buffer: pointer to the buffer in which it is to be stored
 * @old_size: pointer to current buffer index
 *
 * Return: the number of digits of the binary
 */
int bin_conv(unsigned int num, char **buffer, unsigned int *old_size)
{
	int count;

	count = 0;
	if (num / 2 == 0)
	{
		_putchar(num % 2 + 48, buffer, old_size);
		return (1);
	}

	count = 1 + bin_conv(num / 2, buffer, old_size);
	_putchar(num % 2 + 48, buffer, old_size);
	return (count);
}
