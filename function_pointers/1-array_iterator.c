#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - Executes a function on each element of an array
 * @array: Array of elements to have function executed on
 * @size: Size of array
 * @action: Function to execute
 *
 * Return: No return value
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
