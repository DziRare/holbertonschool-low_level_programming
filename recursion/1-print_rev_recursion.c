#include "main.h"

/**
 * _print_rev_recursion - Print a string backwards
 * @s: String to print
 *
 * Return: No return value
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		s++;
		_print_rev_recursion(s);
		_putchar(*s);
	}	
}
