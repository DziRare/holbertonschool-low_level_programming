#include "main.h"
#include <stdlib.h>

/**
 * *malloc_checked - Allocates memory using malloc
 * @b: Pointer to memory that needs to be allocated for
 *
 * Return: Pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	unsigned int *space;

	space = malloc(sizeof(b));
	if (space == NULL)
	{
		exit(98);
	}
	return (space);
}
