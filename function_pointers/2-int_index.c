#include "function_pointers.h"

/**
 * int_index - Searches for an integer
 * @array: Array to be searched through
 * @size: Size of the array
 * @cmp: Function used to compare values
 *
 * Return: Returns the index of the first element for which the cmp function
 * does not return 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	int match;

	if (size <= 0 || array == NULL || cmp || NULL)
		return (-1);

	match = 0;
	i = 0;
	while (!match && i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}
	return (-1);
}
