#include <unistd.h>

/**
 * _putchar - character c is wrriten to stdout
 * @c: character to be printed
 * Return: Returns 1 On success.
 * On error, -1 is returned, then sets errno appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
