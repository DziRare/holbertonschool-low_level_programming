#include "main.h"

/**
 * reverse_array - Reverse Array
 * @a: Pointer to start of array
 * @n: Number of elements of the array
 * Description: Reverses the content of an array
 */
void reverse_array(int *a, int n)
{
	int start;
	int end;
	int temp;

	start = 0;
	end = n - 1;

	while (start < end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;

		start++;
		end--;
	}
}
