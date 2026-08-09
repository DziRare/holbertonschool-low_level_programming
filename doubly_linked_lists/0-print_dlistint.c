#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dlistint - Prints all the elements of a linked list
 * @h: Pointer to head of linked list
 *
 * Return: Number of nodes in linked list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t node_count;
	const dlistint_t *tracker;

	node_count = 0;
	tracker = h;

	while (tracker)
	{
		printf("%d\n", tracker->n);
		node_count = node_count + 1;
		tracker = tracker->next;
	}

	return node_count; 
}
