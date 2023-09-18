#include "main.h"

/**
 * _printf - produces output accordng to format
 * @format: format according to the argument to be printed
 * Return: Number of printed character
 */
int _printf(const char *format, ...)
{
	int num = 0;
	int str_len = 0;

	va_list args;

	if (*format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num ++;
		}
		else
		{
			format++;

			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				num++;
			}

			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				num++
			}

			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				for (int i = 0; str[i] != '\0'; i++)
				{
					str_len++;
					write(1, str, str_len);
					num += str_len;
				}
			}
			format++;
		}
	}
	va_end(args);
	return (num);
}

