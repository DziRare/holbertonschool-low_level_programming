#include "main.h"

/**
 * puts2 - Print part of line
 * @str: String to be printed
 * Description: Prints every second character, followed by a new line
 */
void puts2(char *str)
{
	int i;
	i = 0;

	while (*str != '\0')
	{
		if (i % 2 == 0)
			_putchar(*str);
		i++;
		str++;
	}
	_putchar('\n');
}
