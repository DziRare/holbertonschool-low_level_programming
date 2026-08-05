#include "lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _strlen - Get the length of a string
 * @str: The string to be checked
 *
 * Return: Number of characters in the string
 */
size_t _strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
	{
		count += 1;
	}
	return (count);
}

/**
 * add_node - Adds a new node at the beginning of a linked list
 * @head: Head of a linked list
 * @str: str value of linked list
 *
 * Return: Pointer to new node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	if (str == NULL)
	{
		return (NULL);
	}

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = *head;
	*head = new;

	return (*head);
}
