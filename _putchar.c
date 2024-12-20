#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - outputs a single character
 *
 * @c: the character to be printed
 * @buffer: pointer to a the buffer where the characters are stored
 * @old_size: pointer to the current index in the buffer
 *
 * Return: 1
 */
int _putchar(char c, char **buffer, unsigned int *old_size)
{
	char *ptr;

	if (*old_size == 1024)
	{
		*old_size = 0;
		write(STDOUT_FILENO, buffer, 1023);
		free(*buffer);
	}
	ptr = _realloc(*buffer, *old_size, *old_size + 1);
	ptr[*old_size] = c;

	*old_size = *old_size + 1;

	*buffer = ptr;
	return (1);
}
