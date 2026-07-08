#include "main.h"

/**
 * print_triangle - Draw triangle
 * @size: Size of triangle
 * Description: Prints a triangle, followed by a new line
 * Return: N/A
 */
void print_triangle(int size)
{
	int a;
	int b;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			if (a + b >= size - 1)
				_putchar(35);
			else
				_putchar(32);
		}
		_putchar('\n');
	}
}
