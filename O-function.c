#include "main.h"

/**
 * print_number - print numbers to a standard output
 * @args: argument passed
 * Return: length of a given number
 */
int print_number(va_list args)
{
	int u;
	int checks;
	int leng;
	unsigned int numb;

	u  = va_arg(args, int);
	checks = 1;
	leng = 0;
	if (u < 0)
	{
		leng += _putchar('-');
		numb = u * -1;
	}
	else
		numb = u;
	for (; numb / checks > 9; )
		checks *= 10;
	for (; checks != 0; )
	{
		leng += _putchar('0' + numb / checks);
		numb %= checks;
		checks /= 10;
	}
	return (leng);
}

/**
 * print_unsigned_number - print unsigned numbers
 * @m: numbers to be printed
 * Return: lenght of number
 */
int print_unsigned_number(unsigned int m)
{
	int checks;
	int leng;
	unsigned int numb;

	checks = 1;
	leng = 0;
	numb = m;
	for (; numb / checks > 9; )
		checks *= 10;
	for (; checks != 0; )
	{
		leng += _putchar('0' + numb / checks);
		numb %= checks;
		checks /= 10;
	}
	return (leng);
}

/**
 * team_char - character argument
 * @args: number of chararcter argument
 * Return: 1 success
 */
int team_char(va_list args)
{
	char val;

	val = va_arg(args, int);
	_putchar(val);
	return (1);
}

/**
 * team_str - string argument
 * @args: number of string argument
 * Return: integer
 */
int team_str(va_list args)
{
	int t;
	const char *s;

	s = va_arg(args, const char *);
	if (s == NULL)
		s = "(null)";
	for (t = 0; s[t] != '\0'; t++)
		_putchar(s[t]);
	return (t);
}

/**
 * team_per - percent argument
 * @args: number of argument passed
 * Return: 1
 */
int team_per(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}
