# _PRINTF

My own implementation of the printf function provided in the C standard library. This was done in order to learn and better understand as well as appreciate how the C language formats and prints output to stdout using concepts like variadic functions, structs, arrays, e.t.c

- Prototype: int _printf(const char *format, ...);
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
- format is a character string. The format string is composed of zero or more directives

## Handle format specifiers c, s and %

Including edge cases such as when the % sign is written without any format specifier
- You don’t have to reproduce the buffer handling of the C library printf function
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

## Handle format specifiers d and i

For printing integers
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

## Handle custom conversion specifier b

For printing integers as their binary equivalent

## Handle conversion specifier u, o, x, X

For printing unsigned, octal and hexadecimal representations of unsigned integers.
Behaviour similar to that of printf function
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

## Implement the use of a local buffer of max 1024 characters

This is done in order to reduce calls to write
Memory allocation was done dynamically with a custom _realloc function. See 100-realloc.c

## Handle custom conversion specifier S

Handle the following custom conversion specifier:

- S : prints the string.
- Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

## Handle conversion specifier p

For printing addresses

- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

Subsequent modifications of this code will handle the flag characters '+', space ' ' and '#' for use with the non custom format specifiers. To contribute submit a pull request and I'll reply as soon as possible.

If you have any questions you can email me at jehoshaphaturom@gmail.com or uromjehoshaphat@gmail.com
