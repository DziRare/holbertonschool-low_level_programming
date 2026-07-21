#include <stdlib.h>
#include "main.h"

/**
 * str_concat - Concatenate strings
 * @s1: First string
 * @s2: Second string
 * Description: Concatenate two strings
 * Return: Pointers to concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int s1_len;
	unsigned int s2_len;
	char *concat_string;
	unsigned int i;
	unsigned int j;

	s1_len = 0;
	if (s1 != NULL)
	{
	while (s1[s1_len] != '\0')
		s1_len++;
	}

	s2_len = 0;
	if (s2 != NULL)
	{
	while (s2[s2_len] != '\0')
		s2_len++;
	}

	concat_string = malloc((s1_len + s2_len + 2) * sizeof(char));
	if (concat_string == NULL)
		return (0);

	i = 0;
	while (i < s1_len)
	{
		concat_string[i] = s1[i];
		i++;
	}

	j = 0;
	while (i < s1_len + s2_len)
	{
		concat_string[i] = s2[j];
		i++;
		j++;
	}

	return (concat_string);
}
