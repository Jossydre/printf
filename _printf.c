#include "main.h"
/**
 * _printf - produces output according to format
 * @format: format string specifying the format and arguments
 * @...: variadic argument
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int print_char;

	conver_t funct_list[] =	{
		{"c", team_char},
		{"s", team_str},
		{"%", team_per},
		{"d", team_int},
		{"i", team_int},
		{NULL, NULL}
	};

	va_list args;


	if (format == NULL)
		return (-1);

	va_start(args, format);

	print_char = parser(format, funct_list, args);
	va_end(args);

	return (print_char);
}
