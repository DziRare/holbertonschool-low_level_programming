#include "main.h"

/**
 * _strlen - String Length
 * @s: String to be checked
 * Description: Returns the length of a string
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		count += 1;
		s++;
	}

	return (count);
}
