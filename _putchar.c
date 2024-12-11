#include "main.h"
#include <unistd.h>

/**
 * _putchar - outputs a single character
 *
 * @c: the character to be printed
 *
 * Return: 1
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
