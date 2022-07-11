#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
* struct format - structure that maps format specifier to func
* @let: format specifier
* @f: function to be called
*/
typedef struct format
{
	char *let;
	int (*f)(va_list list);
} format_t;

int _printf(const char *format, ...);
int map_func(va_list list, char c);

int print_char(va_list list);
int print_str(va_list list);
int print_dec(va_list list);

int print_digit(unsigned int n);
#endif
