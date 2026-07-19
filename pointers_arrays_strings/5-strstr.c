#include "main.h"

/**
 * _strstr - Substring
 * @haystack: The string to search
 * @needle: The substring to find
 * Description: Locates a substring
 * Return: Pointer to the beginning of the substring
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;

		if (needle[j] == '\0')
			return (haystack + i);
		i++;
	}
	return (0);
}
