#include "main.h"
#include <stdio.h>

/**
 * print_last_digit - Last digit
 * @n: Number which digit is to be retrieved
 * Description: Prints the last digit of a number.
 * Return: 0 (Success)
 */
int print_last_digit(int n)
{
	int result;
	result = n % 10;

	if (result < 0)
		result = result * -1;

	_putchar(result + '0');
	return (result);
}
