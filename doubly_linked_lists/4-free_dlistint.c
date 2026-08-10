#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_dlistint - Frees a linked list
 * @head: Pointer to head of linked list
 *
 * Return: No return value 
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	temp = head;

	while (temp)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}
