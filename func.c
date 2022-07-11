#include "main.h"
/**
* print_char - prints chars
* @ap: va_list that holds arguments from main func
* Return: number of chars printed
*/
int print_char(va_list ap)
{
	putchar(va_arg(ap, int));
	return (1);
}
/**
* print_str - prints strings
* @ap: va_list that holds arguments from main func
* Return: number of chars printed
*/
int print_str(va_list ap)
{
	char *str, null[] = "(null)";
	int i;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		for (i = 0; null[i]; i++)
			putchar(null[i]);
	}
	else
		for (i = 0; str[i]; i++)
			putchar(str[i]);
	return (i);
}
/**
* print_int - prints ints
* @ap: va_list that holds arguments from main func
* Return: number of ints printed
*/
int print_int(va_list ap)
{
	int n;

	n = va_arg(ap, int);
	if (n < 0)
	{
		putchar('-');
		return (print_unsigned_int(-n) + 1);
	}
	return (print_unsigned_int(n));
}
/**
* print_unsigned_int - prints unsigned ints
* @n: unsigned int to print
* Return: int
*/
int print_unsigned_int(unsigned int n)
{
	int c = 0;

	if (n / 10 != 0)
		c = print_unsigned_int(n / 10);
	putchar((n % 10) + '0');
	return (1 + c);
}
