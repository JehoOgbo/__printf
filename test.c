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
	long int res;

	res = INT_MAX;

	len = _printf("%x + %X = %x\n", UINT_MAX, 0, res);
	len2 = printf("%x + %X = %x\n", UINT_MAX, 0, res);
	printf("%d\n", len);
	printf("%d\n", len2);

	return (0);
}
