#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - Create a hash table
 * @size: Size of the array
 *
 * Return: Pointer to hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;

	hash_table = malloc(sizeof(hash_table_t) * size);

	if (hash_table == NULL)
	{
		return (NULL);
	}

	return hash_table;
}
