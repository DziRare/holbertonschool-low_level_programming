#include "main.h"
#include <stdlib.h>

/**
 * *calloc - Allocates memory for an array
 * @nmemb: Number of elements
 * @size: Byte size of elements
 *
 * Return: Pointer to allocated space
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int *ptr;
	unsigned int i;

	ptr = malloc(size * nmemb);
	if (ptr == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		ptr[i] = 0;

	return (ptr);
}
