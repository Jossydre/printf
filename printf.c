#include "main.h"

/**
 * _printf - produces output accordng to format
 * @format: format according to the argument to be printed
 * Return: Number of printed character
 */
int _printf(const char *format, ...)
{
	int num = 0;
	va_list args;

	if (*format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '\0')
		{
			write(1, format, 1);
		}

		format++;
	}

	return (num);
}
