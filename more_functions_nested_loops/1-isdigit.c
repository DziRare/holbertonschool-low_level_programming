#include "main.h"

/**
 * _isdigit - Checks digit
 * @c: Value to be checked
 * Description: Checks if value is a single digit
 * Return: 1 if c is a digit or 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
