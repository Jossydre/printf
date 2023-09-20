#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct conver_t - structure to represent conversion functions
 * @sym: format specifier symbol
 * @f: pointer to the conversion function
 */
typedef struct
{
	const char *sym;
	int (*f)(va_list);
} conver_t;


int _putchar(char c);
int _printf(const char *format, ...);
int parser(const char *format, conver_t funct_list[], va_list args);
int team_int(va_list);
int team_per(va_list);
int team_str(va_list args);
int team_char(va_list);
int print_unsigned_number(unsigned int m);
int print_number(va_list);

#endif
