#include "main.h"

/**
 * _memcpy - Copies memory
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 * Description: Copies n bytes from src to dest memory area
 * Return: Pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
