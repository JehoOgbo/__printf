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


	len = _printf("dkjfk jkfjkjk  %d kdjfksfkj kfkjksjfk \n", INT_MIN);
    len2 = printf("dkjfk jkfjkjk  %d kdjfksfkj kfkjksjfk \n", INT_MIN);
	printf("%d\n", len);
	printf("%d\n", len2);

	return (0);
}
