#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - Print strings followed by a new line
 * @separator: String printed between numbers
 * @n: Amount of strings passed
 *
 * Return: No return value
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	unsigned int i;
	char *current_string;

	va_start(strings, n);
	if (separator == NULL)
	{
		separator = "";
	}
	for (i = 0; i < n; i++)
	{
		current_string = va_arg(strings, char *);
		if (current_string == NULL)
		{
			current_string = "(nil)";
		}

		if (i < n - 1)
		{
			printf("%s%s", current_string, separator);
		}
		else
		{
			printf("%s", current_string);
		}
	}
	printf("\n");
	va_end(strings);
}
