#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table
 *
 * Return: No return value
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node;
	hash_node_t *temp;
	unsigned long int index;

	if (ht == NULL)
	{
		return;
	}

	for (index = 0; index < ht->size; index++)
	{
		node = ht->array[index];
		temp = ht->array[index];
		while (node != NULL)
		{
			node = node->next;
			temp->next = NULL;
			free(temp);
			temp = node;
		}
	}
	free(ht);
	ht = NULL;
}
