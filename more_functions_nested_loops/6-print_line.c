#include "main.h"

/**
 * print_line - Print straight line
 * @n: Number of times _ is drawn
 * Description: Draws a straight line in the terminal
 * Return: N/A
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
		_putchar(95);
	_putchar('\n');
}
