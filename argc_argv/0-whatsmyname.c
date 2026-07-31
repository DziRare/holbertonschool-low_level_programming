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
	if (argc > 0)
	{
		printf("%s\n", argv[0]);
	}
	return (0);
}
