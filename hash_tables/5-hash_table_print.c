#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table
 *
 * Return: No return value
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *temp;
	unsigned long int index;
	int start;

	if (ht == NULL)
	{
		return;
	}

	start = 1;
	putchar('{');

	for (index = 0; index < ht->size; index++)
	{
		temp = ht->array[index];
		while (temp != NULL)
		{
			if (!start)
			{
				printf(", ");
			}
			printf("'%s': '%s'", temp->key, temp->value);
			start = 0;
			temp = temp->next;
		}
	}
	printf("}\n");
}
