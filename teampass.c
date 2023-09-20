#include "main.h"
/**
 * parser - Parse a format string and perform conversions
 * @format: The format string to be parsed, containing format specifiers
 * @funct_list: An array of conversion specifiers
 * and their associated functions
 * @args: A variable argument list containing the values to be converted
 * Return: The total number of characters printed, or -1 on error
 */
int parser(const char *format, conver_t funct_list[], va_list args)
{
	int n, m, d_val, print_char;

	print_char = 0;
	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] == '%')
		{
			for (m = 0; funct_list[m].sym != NULL; m++)
			{
				if (format[n + 1] == funct_list[m].sym[0])
				{
					d_val = funct_list[m].f(args);
					if (d_val == -1)
						return (-1);
					print_char += d_val;
					break;
				}
			}
			if (funct_list[m].sym == NULL && format[n + 1] != ' ')
			{
				if (format[n + 1] != '\0')
				{
					_putchar(format[n]);
					_putchar(format[n + 1]);
					print_char += 2;
				}
				else
					return (-1);
			}
			n = n + 1;
		}
		else
		{
			_putchar(format[n]);
			print_char++;
		}
	}
	return (print_char);
}
