#include "main.h"

/**
 * _strspn - Prefix substring
 * @s: The string to check
 * @accept: The set of accepted bytes
 * Description: Gets the length of a prefix substring
 * Return: the number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	unsigned int i;
	unsigned int j;
	int match;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		match = 0;
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
			j++;
		}
		if (match == 0)
			break;
		count++;
		i++;
	}
	return (count);
}
