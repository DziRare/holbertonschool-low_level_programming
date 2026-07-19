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
	int mid;
	int sum1;
	int sum2;

	sum1 = 0;
	sum2 = 0;
	mid = size / 2;
	i = 0;
	while (i <= mid)
	{
		sum1 += a[i * size + i];
		sum1 += a[(size - 1 - i) * size + (size - 1 - i)];
		sum2 += a[i * size + (size - 1 - i)];
		sum2 += a[(size - 1 - i) * size + i];
		i++;
	}
	if (size % 2 == 1)
	{
		sum1 -= a[mid * size + mid];
		sum2 -= a[mid * size + mid];
	}
	printf("%d, %d\n", sum1, sum2);
}
