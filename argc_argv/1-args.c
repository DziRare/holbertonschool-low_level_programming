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
	(void)argv;
	if (argc >= 0)
	{
		printf("%d\n", argc - 1);
	}
	return (0);
}
