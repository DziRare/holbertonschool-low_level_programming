#include "main.h"

/**
 * _memset - fills the first n bytes of the memory area s with byte b
 * @s: pointer to the memory area
 * @b: byte to fill with
 * @n: number of bytes to fill
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
