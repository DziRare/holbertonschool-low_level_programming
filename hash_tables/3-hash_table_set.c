#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Adds an element to hash table
 * @ht: Pointer to hash table
 * @key: String that's going to be used as a key for the hash table
 * @value: Value associated with key
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;
	hash_node_t *temp;

	if (ht == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;
	if (ht->array[index] == NULL)
	{
		ht->array[index] = new_node;
	}
	else
	{
		temp = ht->array[index];
		while (temp)
		{
			if (strcmp(new_node->key, temp->key) == 0)
			{
				free(temp->value);
				temp->value = new_node->value;
				free(new_node->key);
				free(new_node);
				return (1);
			}
			temp = temp->next;
		}

		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}

	return (1);
}
