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

    len = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%", 'W', 'i', "some ", "more", 'r', "s", "", NULL, 't', ", Jon", '\n');
    len2 = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%", 'W', 'i', "some ", "more", 'r', "s", "", NULL, 't', ", Jon", '\n');


	printf("%d\n", len);
	printf("%d\n", len2);

	return (0);
}
