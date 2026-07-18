#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the converted integer, or 0 if no digits are found
 */
int _atoi(char *s)
{
	int i;
	int sign = 1;
	int started = 0;
	unsigned int num = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-' && started == 0)
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = num * 10 + (unsigned int)(s[i] - '0');
		}
		else if (started == 1)
			break;
	}

	if (sign == -1)
		return (-num);
	return (num);
}
