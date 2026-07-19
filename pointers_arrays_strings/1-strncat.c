#include "main.h"

/**
 * *_strncat - Join strings
 * @dest: Destination string
 * @src: Source string
 * @n: Amount of bytes to be concatenated
 * Description: Concatenates strings
 * Return: Pointer to resulting dest string
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_i;
	int src_i;

	dest_i = 0;
	src_i = 0;

	while (dest[dest_i] != '\0')
		dest_i++;

	while (src_i < n)
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	dest[dest_i] = '\0';

	return (dest);
}
