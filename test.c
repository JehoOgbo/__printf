#include "main.h"
#include <stdio.h>

/**
 * main - test _printf function
 *
 * Return: 0 on success
 */
int main(void)
{
	int len;
	int len2;


    len = _printf("dkjfk jkfjkjk  %i kdjfksfkj kfkjksjfk \n", 1984);
    len2 = printf("dkjfk jkfjkjk  %i kdjfksfkj kfkjksjfk \n", 1984);
	printf("%d\n", len);
	printf("%d\n", len2);

	return (0);
}
