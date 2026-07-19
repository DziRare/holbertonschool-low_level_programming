#include "main.h"

/**
 * _strchr - Locates character
 * @s: Pointer to string
 * @c: Character to be located
 * Description: Locates a character in a string
 * Return: Pointer to first occurrences of the character
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}
