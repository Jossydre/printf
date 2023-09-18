#include "main.h"

/**
 * _printf - produces output according to format
 * @format: format according to the argument to be printed
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int num = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				num += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);

				if (str == NULL)
					str = "(null)";
				num += write(1, str, strlen(str));
			}
			else if (*format != '%')
				num += write(1, format - 1, 1);
		}
		else
			num += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (num);
}
