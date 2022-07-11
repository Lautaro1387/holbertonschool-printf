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
	int (*func)(va_list ap);
} format_t;

int _printf(const char *format, ...);
int map_func(va_list, char);

int print_char(va_list);
int print_str(va_list);
int print_int(va_list);

int print_unsigned_int(unsigned int n);

#endif
