#include "main.h"

/**
 * puts_half - Half of string
 * @str: String to be halved
 * Description: Prints half of a string, followed by new line
 */
void puts_half(char *str)
{
	int len;
	int  n;

	len = 0;
	while (*str != '\0')
	{
		len += 1;
		str++;
	}
	str--;

	n = (len + 1) / 2;
	while (len > n)
	{
		len -= 1;
		str--;
	}
	str++;

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
