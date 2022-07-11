#include "main.h"
/**
* _printf - produces output according to format
* @format: string that holds what will be printed
* Return: string that specifies how subsequent arguments
* (or arguments accessed via the variable-length argument
* facilities of stdarg(3)) are converted for output
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int i, charCount = 0;

	if (!format || !strcmp(format, "%"))
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 0 || format[i + 1] == '%'))
		{
			putchar('%');
			i++;
			charCount++;
		}
		else if (format[i] == '%')
		{
			charCount += map_func(ap, format[i + 1]);
			i++;
		}
		else
		{
			charCount += 1;
			putchar(format[i]);
		}
	}
	va_end(ap);
	return (charCount);
}
/**
* map_func - maps format specifiers to functions
* @ap: va_list that contains args
* @c: char (format[i + 1])
* Return: 2 (number of chars printed)
*/
int map_func(va_list ap, char c)
{
	int j;
	format_t f[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_dec},
		{"i", print_dec}
	};
	for (j = 0; j < 4; j++)
		if (*f[j].let == c)
			return (f[j].func(ap));
	putchar('%');
	putchar(c);
	return (2);
}
