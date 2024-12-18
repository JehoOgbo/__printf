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