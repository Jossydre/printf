#include "main.h"

/**
 * _write - writes the character c to stdout
 * @c: The character to print
 *
 * Return: success always
 */
int _write(char c)
{
	return (write(1, &c, 1));
}
