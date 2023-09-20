#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct specifiers - Struct specifiers
 * @specifier: The conversion specifier
 * @f: function pointer
 */
typedef struct specifiers
{
	char *spec;
	int (*f)(va_list args);
} specy_datype;

int _print_form(const char *format, va_list args);
int _valid_char(char type);
int print_invalid(char prev_form, char format, int num_count);
int print_spe(char format, va_list args);
int _write(char c);
int _print_char(va_list args);
int _print_str(va_list args);
int _print_int(va_list args);
void _recursion_int(int e);
int _printf(const char *format, ...);

#endif
