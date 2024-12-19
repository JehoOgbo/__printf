#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdarg.h>
int _printf(const char *format, ...);

/**
 * struct operations - stores the specifiers and associated functions
 *
 * @f_spec: format specifier
 * @f: function to be executed
 *
 */
typedef struct operations
{
	char *f_spec;
	int (*f)(va_list arg, char **buffer, unsigned int *old_size);
} ops_t;

int op_char(va_list arg, char **buffer, unsigned int *old_size);
int op_string(va_list arg, char **buffer, unsigned int *old_size);
int op_percent(va_list arg, char **buffer, unsigned int *old_size);
int op_integer(va_list arg, char **buffer, unsigned int *old_size);
int op_binary(va_list arg, char **buffer, unsigned int *old_size);
int op_unsigned(va_list arg, char **buffer, unsigned int *old_size);
int op_octal(va_list arg, char **buffer, unsigned int *old_size);
int op_hex(va_list arg, char **buffer, unsigned int *old_size);
int op_sp_string(va_list arg, char **buffer, unsigned int *old_size);

int print_num(int num, char **buffer, unsigned int *old_size);
int _putchar(char c, char **buffer, unsigned int *old_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int print_unsigned(unsigned int num, char **buffer, unsigned int *oldsize);
int bin_conv(unsigned int num, char **buffer, unsigned int *old_size);
int oct_conv(unsigned int num, char **buffer, unsigned int *old_size);
int hex_conv(unsigned int num, char **buffer, unsigned int *old_size, int chk);

int hex_print(int num, char **buffer, unsigned int *old_size);

#endif /* _MAIN_H_ */
