#include "main.h"

/**
 * print_diagonal - Diagonal Line
 * @n: Number of \ that are drawn
 * Description: Draws diagonal line on the terminal
 * Return: N/A
 */
void print_diagonal(int n)
{
	int i;
	int j;

	if (n <= 0)
		_putchar('\n');

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				_putchar(92);
				_putchar('\n');
				break;
			}
			else
			{
				_putchar(32);
			}
		}
	}
}
