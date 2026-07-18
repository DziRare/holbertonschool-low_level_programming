#include "main.h"

/**
 * _strcpy - Copy string
 * @dest: Place where string will be copied to
 * @src: String to be copied
 * Description: Copies string to a destination
 * Return: Destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
