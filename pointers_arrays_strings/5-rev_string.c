#include "main.h"

/**
 * rev_string - reverse a string
 * @s: String to be reversed
 * Description: Reverses a string
 */
void rev_string(char *s)
{
	char *start;

	start = s;
	while (*s != '\0')
	{
		s++;
	}
	s--;

	while (start < s)
	{
		char temp;

		temp = *start;
		*start = *s;
		*s = temp;

		start++;
		s--;
	}
}
