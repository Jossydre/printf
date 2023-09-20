#include "main.h"

/**
 * _print_char - Prints a char
 * @args: list of variadic arguments
 *
 * Return: The length of the character
 */
int _print_char(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}

/**
 * _print_str - Prints string
 * @args: list of variadic arguments
 *
 * Return: length of string
 */
int _print_str(va_list args)
{
	char *arg = va_arg(args, char *);
	int n = 0;

	if (arg != NULL)
	{
		while (arg[n])
		{
			_write(arg[n]);
			n++;
		}

		return (n);
	}

	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}

/**
 * _print_int - Print integer
 * @args: list of variadic arguments
 *
 * Return: length of the string
 */
int _print_int(va_list args)
{
	int num_count = 1, d = 0;
	unsigned int c = 0;

	c = va_arg(args, int);
	d = c;
	if (d < 0)
	{
		_write('-');
		d *= -1;
		c = d;
		num_count += 1;
	}
	while (c > 9)
	{
		c /= 10;
		num_count++;
	}

	_recursion_int(d);
	return (num_count);
}

/**
 * _recursion_int - Print an integer
 * @e: integer to be printed
 *
 * Return: None
 */
void _recursion_int(int e)
{
	unsigned int u;

	u = e;
	if (u / 10)
		_recursion_int(u / 10);
	_write(u % 10 + '0');
}
