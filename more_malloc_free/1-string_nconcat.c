#include "main.h"
#include <stdlib.h>

/**
 * *string_nconcat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 * @n: Bytes to be concatenated
 *
 * Return: Pointer to joined string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int len_s1;
	unsigned int len_s2;
	unsigned int i;

	len_s1 = 0;
	len_s2 = 0;
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			len_s1 += 1;
			i++;
		}
		i = 0;
	}
	if (s2 != NULL)
	{
		while (s2[i] != '\0' && i < n)
		{
			len_s2 += 1;
			i++;
		}
		i = 0;
	}

	ptr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	for (i = 0; i < len_s1; i++)
	{
		ptr[i] = s1[i];
	}
	for (i = 0; i < len_s1 + len_s2; i++)
	{
		ptr[i + len_s1] = s2[i];
	}
	ptr[i] = '\0';
	return (ptr);
}
