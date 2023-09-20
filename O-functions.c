#include "main.h"

/**
 * team_int - interger argument
 * @args: agurment passed
 * Return: success
 */
int team_int(va_list args)
{
	int u;

	u = print_number(args);
	return (u);
}
