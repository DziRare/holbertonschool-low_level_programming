#include "lists.h"
#include <stdlib.h>

/**
 * sum_dlistint - Sums all of the data in linked list
 * @head: Pointer to head of linked list
 *
 * Return: Sum of data in linked list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;
	dlistint_t *tracker;

	sum = 0;
	tracker = head;

	while (tracker)
	{
		sum = sum + tracker->n;
		tracker = tracker->next;
	}

	return (sum);
}
