#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - Add a new node at the start of a linked list
 * @head: Pointer to a pointer of the head of a linked list
 * @n: Value of node
 *
 * Return: Pointer to new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;

	return (new_node);
}
