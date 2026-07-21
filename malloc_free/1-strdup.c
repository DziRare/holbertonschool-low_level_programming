#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Creates pointer to duplicate string
 * @str: String to be duplicated
 * Description: Returns a pointer to a newly allocated space in memory
 *has copy of string
 * Return: Pointer to duplicated string
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i;
	unsigned int size;

	if (str == NULL)
		return (0);
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}

	dup = malloc(size * sizeof(char));
	i = 0;
	if (dup == NULL)
		return (NULL);

	while (i < size)
	{
		dup[i] = str[i];
		i++;
	}

	return (dup);
}
