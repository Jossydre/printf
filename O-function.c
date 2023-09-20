#include "main.h"

/**
 * _print_form - Print the format
 * @format: Format to be printed
 * @args: The list of variadic arguments
 *
 * Return: The length of the format
 */
int _print_form(const char *format, va_list args)
{
	int num_count = 0;
	int b = 0;

	while (format && format[b])
	{
		if (format[b] == '%')
		{
			if (format[b + 1] == '\0')
				return (-1);

			b++;

			while (format[b] == ' ')
				b++;

			if (format[b] == '%')
				num_count += _write(format[b]);

			if (_valid_char(format[b]) == 0)
			{
				num_count = print_invalid(format[b - 1], format[b], num_count);
			}
			else
			{
				num_count += print_spe(format[b], args);
			}
		}
		else
		{
			num_count += _write(format[b]);
		}
		b++;
	}
	return (num_count);
}

/**
 * print_spe - Prints valid specifier
 * @format: Specifier to be printed
 * @args: list of variadic arguments
 *
 * Return: The length of the specifier
 */
int print_spe(char format, va_list args)
{
	int m  = 0, lenh = 0;
	specy_datype _types[] = {
		{"c", _print_char},
		{"s", _print_str},
		{"d", _print_int},
		{"i", _print_int},
		{NULL, NULL}
	};

	while (_types[m].spec)
	{
		if (*_types[m].spec == format)
			lenh = _types[m].f(args);

		m++;
	}

	return (lenh);
}

/**
 * print_invalid - Prints invalid specifier
 * @prev_form: Previous specifier of actual specifier
 * @format: Specifier to prints
 * @num_count: Current count before printing invalid specifiers
 *
 * Return: The current count after prints invalid specifiers
 */
int print_invalid(char prev_form, char format, int num_count)
{
	num_count += _write('%');

	if (prev_form == ' ')
	{
		num_count += _write(' ');
		num_count += _write(format);
	}
	else
	{
		num_count += _write(format);
	}

	return (num_count);
}

/**
 * _valid_char - validates type
 * @type: character compared
 *
 * Return: 1 if char is equals type
 */
int _valid_char(char type)
{
	char types[] = {'c', 's', 'd', 'i', '%'};
	int ch = 0;

	while (types[ch])
	{
		if (types[ch] == type)
			return (1);
		ch++;
	}
	return (0);
}
