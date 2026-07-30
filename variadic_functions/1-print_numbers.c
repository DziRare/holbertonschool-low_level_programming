#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - Print numbers followed by a new line
 * @separator: String printed between numbers
 * @n: Amount of integers passed
 *
 * Return: No return value
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;
	int current_number;

	va_start(numbers, n);
	for (i = 0; i < n; i++)
	{
		current_number = va_arg(numbers, int);
		if (i < n - 1)
		{
			printf("%d%s", current_number, separator);
		}
		else
		{
			printf("%d\n", current_number);
		}
	}
	va_end(numbers);
}
