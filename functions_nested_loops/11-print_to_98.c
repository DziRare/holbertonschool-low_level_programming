#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - n to 98
 * @n: Integer where the count starts
 * Description: Prints all integers from n to 98
 * Return: No return value
 */
void print_to_98(int n)
{
	int i;

	for (i = n; i <= 98; i++)
	{
		if (i != 98)
			printf("%d, ", i);
		else
			printf("%d\n", i);
	}
}
