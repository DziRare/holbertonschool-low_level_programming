#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts new node at given position
 * @h: Pointer to pointer head of linked list
 * @idx: Index where node should be added
 * @n: Value of new node
 *
 * Return: Node of nth index or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int current_index;
	dlistint_t *tracker;
	dlistint_t *new_node;

	current_index = 0;
	tracker = *h;
	if (idx == 0)
		return (add_dnodeint(h, n));

	if (*h == NULL)
		return (NULL);

	while (current_index < idx - 1 && tracker->next)
	{
		tracker = tracker->next;
		current_index = current_index + 1;
	}

	if (tracker->next == NULL)
	{
		if (idx == current_index + 1)
			return (add_dnodeint_end(h, n));
		else if (idx > current_index + 1)
			return (NULL);
	}

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = tracker;
	tracker->next->prev = new_node;
	new_node->next = tracker->next;
	tracker->next = new_node;

	return (new_node);
}
