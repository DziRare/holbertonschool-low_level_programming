#include "main.h"
#include <stdio.h>

/**
 * print_array - Print line
 * @a: Array of integers
 * @n: Number of elements to be printed
 * Description: Prints n elements of an array of integers
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%d, ", a[i]);
		else
			printf("%d", a[i]);
	}
	putchar('\n');
}
