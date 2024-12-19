#include "main.h"

/**
 * hex_print - print a hexadecimal no. with some special formats
 *
 * @num: the decimal of the number to be printed
 * @buffer: the buffer which the output is to be written
 * @old_size: current index in the buffer
 *
 * Return: the number of characters printed (i.e 4 because of the format)
 */
int hex_print(int num, char **buffer, unsigned int *old_size)
{
	int chars;

	chars = 0;
	chars += _putchar('\\', buffer, old_size);
	chars += _putchar('x', buffer, old_size);
	if (num / 16 == 0)
	{
		chars += _putchar('0', buffer, old_size);
	}
	chars += hex_conv(num, buffer, old_size, 55);

	return (chars);
}
