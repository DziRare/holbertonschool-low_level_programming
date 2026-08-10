#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_dnodeint_at_index - Gets nth node of linked list
 * @head: Pointer to head of linked list
 * @index: Index of node to retrieve
 *
 * Return: Node of nth index or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int current_index;
	dlistint_t *tracker;

	current_index = 0;
	tracker = head;

	while (current_index < index && tracker)
	{
		tracker = tracker->next;
		current_index = current_index + 1;
	}

	return (tracker);
}
