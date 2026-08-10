#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_get - Retrieves value associated with key
 * @ht: Pointer to hash table
 * @key: Key to look for
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp;

	index = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[index];
	while (temp != NULL && strcmp(temp->key, key) != 0)
	{
		temp = temp->next;
	}

	if (temp == NULL)
	{
		return (NULL);
	} 

	return (temp->value);
}
