#include "main.h"

/**
 * _strpbrk - Searches a string
 * @s: The string to search
 * @accept: The set of bytes to search for
 * Description: Searchs a string for any of a set of bytes
 * Return: pointer to the byte in s
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (s + i);
			j++;
		}
		i++;
	}
	return (0);
}
