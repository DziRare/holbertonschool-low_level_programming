#include <stdio.h>

/**
 * main - Print Comb 4
 * Description: Print all possible combos of 3 digits
 * Return: 0 (Success)
 */
int main(void)
{
	int hundreds;
	int tens_gap = 1;

	for (hundreds = 0; hundreds <= 7; hundreds++)
	{
		int tens;
		int ones_gap = 1 + tens_gap;

		for (tens = tens_gap; tens <= 8; tens++)
		{
			int ones;

			for (ones = ones_gap; ones <= 9; ones++)
			{
				putchar(hundreds + '0');
				putchar(tens + '0');
				putchar(ones + '0');
				if (hundreds != 7)
				{
					putchar(',');
					putchar(' ');
				}
				else
				{
					putchar('\n');
				}
			}

			ones_gap++;
		}
		tens_gap++;
	}
	return (0);
}
