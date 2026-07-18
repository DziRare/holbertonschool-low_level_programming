#include "main.h"

/**
 * puts2 - Print part of line
 * @str: String to be printed
 * Description: Prints every second character, followed by a new line
 */
void puts2(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		str++;
	}
	_putchar('\n');
}
