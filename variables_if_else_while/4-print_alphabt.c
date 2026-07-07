#include <stdio.h>

/**
 * main - Entry point of program
 * Description: Prints out the alphabet without q and e
 * Return: 0
 */
int main(void)
{
	int i;

	for (i = 97; i < 123; i++)
	{
		if (i != 101 && i != 113)
			putchar(i);
	}
	putchar('\n');

	return (0);
}
