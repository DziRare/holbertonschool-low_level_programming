#include "main.h"
#include <stdio.h>

/**
 * print_sign - Number sign
 * @n: Number that is to be checked
 * Description: Prints the sign of a number.
 * Return: 0 (Success)
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
