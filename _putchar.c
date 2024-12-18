#include "main.h"
#include <unistd.h>

/**
 * _putchar - outputs a single character
 *
 * @c: the character to be printed
 *
 * Return: 1
 */
int _putchar(char c, char **buffer, unsigned int *old_size)
{
	char *ptr;

	ptr = _realloc(*buffer, *old_size, *old_size + 1);
	ptr[*old_size] = c;

	*old_size = *old_size + 1;

	*buffer = ptr;
	return (1);
}
