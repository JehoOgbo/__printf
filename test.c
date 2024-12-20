#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

/**
 * main - test _printf function
 *
 * Return: 0 on success
 */
int main(void)
{
	int len;
	int len2;

	len = _printf("%X\n", (void *)&len2);
	len2 = printf("%p\n", (void *)&len2);
	printf("%d\n", len);
	printf("%d\n", len2);

	return (0);
}
