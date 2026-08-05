#include <stdio.h>
#include "lists.h"

/**
 * list_len - Retrieves number of elements of a list_t list
 * @h: Head of linked list
 *
 * Return: The number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t count;
	const list_t *current_node;

	count = 0;
	current_node = h;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		count += 1;
	}
	return (count);
}
