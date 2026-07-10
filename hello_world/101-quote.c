#include <stdio.h>

/**
 * main - Print quote
 * Description: Prints a quote with restrictions to functions
 * Return: 1 (Success)
 */
int main(void)
{
	int i;
	char quote[] = "and that piece of art is useful";

	for (i = 0; i < 31; i++)
	{
		putchar(quote[i]);
	}
	putchar('\n');

	return (1);
}
