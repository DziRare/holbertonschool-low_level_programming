#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes node at given position
 * @head: Pointer to pointer head of linked list
 * @index: Index where node should be added
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int current_index;
	dlistint_t *tracker;

	if (*head == NULL)
		return (-1);

	tracker = *head;

	if (index == 0)
	{
		*head = tracker->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tracker);
		return (1);
	}

	current_index = 0;
	while (current_index < index && tracker)
	{
		tracker = tracker->next;
		current_index = current_index + 1;
	}

	if (tracker == NULL)
		return (-1);

	tracker->prev->next = tracker->next;
	if (tracker->next != NULL)
		tracker->next->prev = tracker->prev;

	free(tracker);

	return (1);
}
