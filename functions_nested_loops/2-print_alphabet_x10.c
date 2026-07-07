#include <stdio.h>
#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet 10 times
 * Description: Prints 10 times the alphabet, in lowercase
 * Return: 0 (Success)
 */
void print_alphabet_x10(void)
{
	int i;
	int j;

	for (j = 0; j < 10; j++)
	{

		for (i = 97; i < 123; i++)
			_putchar(i);
		_putchar('\n');
	}
}
