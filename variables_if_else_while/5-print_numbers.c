#include <stdio.h>

/**
 * main - Entry point of program
 * Description: Prints all single digit numbers of base 10 starting from zero
 * Return: 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 48; i < 58; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
