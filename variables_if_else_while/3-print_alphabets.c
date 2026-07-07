#include <stdio.h>

/**
 * main - Entry point of program
 * Description: Prints out the alphabet
 * Return: 0
 */
int main(void)
{
	int i;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (i = 0; i < 52; i++)
	{
		putchar(alphabet[i]);
	}
	putchar('\n');

	return (0);
}
