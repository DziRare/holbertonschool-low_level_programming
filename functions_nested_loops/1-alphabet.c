#include <stdio.h>
#include "main.h"

/**
 * print_alphabet - Prints the alphabet
 * Description: Prints the alphabet, in lowercase, followed by a new line.
 * Return: 0 (Success)
 */
void print_alphabet(void)
{
	int i;

	for (i = 97; i < 123; i++)
		_putchar(i);

	_putchar('\n');
}
