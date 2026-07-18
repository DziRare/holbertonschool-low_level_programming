#include "main.h"

/**
 * *_strcat - Join strings
 * @dest: Destination string
 * @src: Source string
 * Description: Appends the src string to the dest string
 * Return: Pointer to resulting dest string
 */
char *_strcat(char *dest, char *src)
{
	int dest_i;
	int src_i;

	dest_i = 0;
	src_i = 0;

	while (dest[dest_i] != '\0')
		dest_i++;

	while (src[src_i] != '\0')
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	dest[dest_i] = '\0';

	return (dest);
}
