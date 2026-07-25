#include "main.h"
#include <stdlib.h>

/**
 * *array_range - Creates an array of integers
 * @min: Smallest integer in array
 * @max: Highest integer in array
 *
 * Return: Pointer to array
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i;
	int size;
	int *temp;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
		return (NULL);
	temp = ptr;
	for (i = 0; i < size; i++, temp++)
	{
		*temp = min++;
	}

	return (ptr);
}
