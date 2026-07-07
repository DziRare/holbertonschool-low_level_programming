#include <stdio.h>

/**
 * main - Entry point of program
 * Description: Prints out the alphabet
 * Return: 0
 */
int main(void)
{
	int i;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < 26; i++)
	{
		putchar(alphabet[i]);
	}
	putchar('\n');

	return (0);
}
