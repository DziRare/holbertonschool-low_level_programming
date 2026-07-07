#include <stdio.h>

/**
 * main - Entry point of program
 * Description: Prints out the alphabet
 * Return: 0
 */
int main(void)
{
	int i;

	for (i = 122; i > 96; i--)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}
