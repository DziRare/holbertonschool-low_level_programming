#include "main.h"

/**
 * print_square - Print a square
 * @size: Size of the square
 * Description: Prints a square followed by a new line
 * Return: N/A
 */
void print_square(int size)
{
	int m;
	int n;

	for (m = 0; m < size; m++)
	{
		for (n = 0; n < size; n++)
		{
			_putchar(35);
		}
		_putchar('\n');
	}

	if (size <= 0)
		_putchar('\n');
}
