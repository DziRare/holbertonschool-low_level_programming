#include "main.h"
#include <stdio.h>

/**
 * _abs - Absolute Value
 * @n: Number that is to be computed
 * Description: Computes the absolute value of an integer.
 * Return: 0 (Success)
 */
int _abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}
