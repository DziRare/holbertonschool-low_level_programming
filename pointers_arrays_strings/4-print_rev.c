#include "main.h"

/**
 * print_rev - Reverse print
 * @s: String to be reversed
 * Description: Prints a string, in reverse, followed by a new line
 */
void print_rev(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}

	while (i >= 0)
	{
		_putchar(*s);
		s--;
		i--;
	}
	_putchar('\n');
}
