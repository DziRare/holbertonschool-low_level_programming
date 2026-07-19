#include "main.h"

/**
 * *_strncpy - Copy string
 * @dest: Destination string
 * @src: Source string
 * @n: Amount of bytes to be copied
 * Description: Copies a string to a destination
 * Return: Pointer to resulting dest string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int dest_i;
	int src_i;

	dest_i = 0;
	src_i = 0;

	while (src_i < n)
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}

	while (dest_i < n)
	{
		dest[dest_i] = '\0';
		dest_i++;
	}

	return (dest);
}
