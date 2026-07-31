#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Add postive numbers
 * @argc: Number of command line arguments
 * @argv: List of command line arguments
 *
 * Return: Success (0)
 */
int main(int argc, char *argv[])
{
	int sum;
	int i;
	int j;

	sum = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		sum += atoi(argv[i]);
		i++;
	}

	printf("%d\n", sum);
	return (0);
}
