#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates array
 * @size: Size of array
 * @c: Character to initialise with
 * Description: Creates an array of chars, and initializes it with a char
 * Return: Pointer to array
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	arr = malloc(size * sizeof(char));

	if (size == 0 || arr == NULL)
		return (0);

	i = 0;
	while (i < size)
	{
		arr[i] = c;
		i++;
	}
	return (arr);
}
