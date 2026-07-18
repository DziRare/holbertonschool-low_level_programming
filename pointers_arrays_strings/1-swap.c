#include "main.h"

/**
 * swap_int - Swap values
 * @a: First integer
 * @b: Second integer
 * Description: Swaps the values of two integers
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
