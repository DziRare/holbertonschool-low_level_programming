#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list
 * @h: Head of linked list
 *
 * Return: No return value
 */
void free_list(list_t *head)
{
	list_t *current_node;
	list_t *prev_node;

	current_node = head;
	while (current_node != NULL)
	{
		prev_node = current_node;
		current_node = current_node->next;
		free(prev_node->str);
		free(prev_node);
	}
}
