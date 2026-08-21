#include "main.h"

/**
 * _puts_recursion - Print a string followed by a new line
 * @s: String to print
 *
 * Return: No return value
 */
void _puts_recursion(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i = i + 1;
	}
	_putchar('\n');
}
