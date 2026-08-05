#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all the elements of a list_t list
 * @h: Head of linked list
 *
 * Return: The number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count;
	const list_t *current_node;

	count = 0;
	current_node = h;
	while (current_node != NULL)
	{
		if (current_node->str == NULL)
		{
			printf("[0] ");
			printf("(nil)\n");
		}
		else
		{
			printf("[%d] ", current_node->len);
			printf("%s\n", current_node->str);
		}
		current_node = current_node->next;
		count += 1;
	}
	return (count);
}
