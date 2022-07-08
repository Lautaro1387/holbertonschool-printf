#include "main.h"
/**
 * print_char - prints chars
 * @list: va_list that holds arguments from main func
 * Return: number of chars printed
 */
int print_char(va_list list)
{
	putchar(va_arg(list, int));
	return (1);
}
/**
 * print_str - prints strings
 * @list: va_list that holds arguments from main func
 * Return: number of chars printed
 */
int print_str(va_list list)
{
	char *str, null[] = "(null)";
	int i;

	str = va_arg(list, char *);
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
* print_dec - prints ints
* @list: va_list that holds arguments from main func
* Return: number of ints printed
*/
int print_dec(va_list list)
{
	int n;

	n = va_arg(list, int);
	if (n < 0)
	{
		putchar('-');
		return (print_digit(-n) + 1);
	}
	return (print_digit(n));
}
/**
* print_digit - prints multi digit unsigned ints
* @n: unsigned multi digit int to print.
* Return: int.
*/
int print_digit(unsigned int n)
{
	int c = 0;

	if (n / 10 != 0)
	{
		c = print_digit(n / 10);
	}
	putchar((n % 10) + '0');
	return (1 + c);
}
