#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
int _printf(const char *format, ...);

/**
 * struct operations
 *
 * @f_spec: format specifier
 * @f: function to be executed
 *
 */
typedef struct operations
{
	char *f_spec;
	int (*f)(va_list arg);
} ops_t;

int op_char(va_list arg);
int op_string(va_list arg);
int op_percent(va_list arg);
int _putchar(char c);

#endif /* _MAIN_H_ */
