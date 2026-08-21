#include "main.h"

/**
 * _strlen_recursion - Count characters in a string
 * @s: String of characters to count
 *
 * Return: Amount of characters in string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (_strlen_recursion(s + 1) + 1);
}
