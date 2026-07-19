#include "main.h"

/**
 * *_strcmp - Compare strings
 * @s1: First string
 * @s2: Second string
 * Description: Compares two strings
 * Return: Integer showing comparison
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}

	return (s1[i] - s2[i]);
}
