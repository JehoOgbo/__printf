#include "main.h"

/**
 * op_heX - writes the hexadecimal equivalent of a number into a buffer
 * Description: uses capital letters
 *
 * @arg: argument ptr to the number
 * @buffer: the pointer to the buffer to which the equivalent is to be written
 * @old_size: pointer to the current active index in the buffer
 *
 * Return: the number of characters written
 */
int op_heX(va_list arg, char **buffer, unsigned int *old_size)
{
	unsigned int hex;

	hex = va_arg(arg, unsigned int);
	return (hex_conv(hex, buffer, old_size, 55));
}
