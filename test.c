#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - test _printf function
 *
 * Return: 0 on success
 */
int main(void)
{
	int len;
	int len2;

	len = _printf("%d - %b = %d\n", 1024, -2, -1024);
	len2 = printf("%d - %b = %d\n", 1024, -2, -1024);
	printf("%d\n", len);
	printf("%d\n", len2);

	return (0);
}
