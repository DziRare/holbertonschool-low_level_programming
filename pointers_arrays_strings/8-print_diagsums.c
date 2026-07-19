#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Two diagonals
 * @a: Pointer to the first element of the matrix
 * @size: Number of rows and columns of the matrix
 * Description: Prints the sum of the two diagonals
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1;
	int sum2;

	sum1 = 0;
	sum2 = 0;
	i = 0;
	while (i < size)
	{
		sum1 += a[i * size + i];
		sum2 += a[i * size + (size - 1 - i)];
		i++;
	}
	printf("%d, %d\n", sum1, sum2);
}
