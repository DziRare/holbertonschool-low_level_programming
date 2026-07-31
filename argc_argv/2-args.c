#include <stdarg.h>
#include <stdio.h>

/**
 * main - Prints the name of program
 * @argc: Number of command line arguments
 * @argv: List of command line arguments
 *
 * Return: Success (0)
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
