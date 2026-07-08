#include "main.h"
#include <stdio.h>

/**
 * times_table - 9 times table
 * Description: Prints the 9 times table, starting with 0.
 * Return: No return value
 */
void times_table(void)
{
	int i;
	int j;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			int multiplication;

			multiplication = i * j;

			if (multiplication / 10 == 0 && j == 0)
			{
				_putchar(multiplication + '0');
			}
			else if (multiplication / 10 == 0)
			{
				_putchar(32);
				_putchar(32);
				_putchar(multiplication + '0');
			}
			else
			{
				_putchar(32);
				_putchar((multiplication / 10) + '0');
				_putchar((multiplication % 10) + '0');
			}

			if (j == 9)
			{
				_putchar('\n');
			}
			else
			{
				_putchar(',');
			}
		}
	} 
}
