#include "main.h"

/**
 * cap_string - capitalizes the first letter of every word in a string
 * @str: the string to capitalize
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i;
	int j;
	int start;
	char separators[] = " \t\n,;.!?\"(){}";

	start = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (start && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';

		start = 0;
		j = 0;
		while (separators[j] != '\0')
		{
			if (str[i] == separators[j])
			{
				start = 1;
				break;
			}
			j++;
		}
		i++;
	}
	return (str);
}
