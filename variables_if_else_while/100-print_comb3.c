#include <stdio.h>

/**
 * main - Print Comb 3
 * Description: Print all possible combos of 2 digits
 * Return: 0 (Success)
 */
int main(void)
{
	int tens;
	int gap = 1;

	for (tens = 0; tens < 9; tens++)
	{
		int ones;

		for (ones = gap; ones <= 9; ones++)
		{
			putchar(tens + '0');
			putchar(ones + '0');
			if (tens != 8)
			{
				putchar(',');
				putchar(' ');
			}
			else
			{
				putchar('\n');
			}
		}

		gap++;
	}

	return (0);
}
