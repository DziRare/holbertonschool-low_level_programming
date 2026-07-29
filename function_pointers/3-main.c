#include "3-calc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Entry point of program
 * @argc: Number of arguments to be passed into function
 * @argv: Array of arguments
 *
 * Return: Successful Program (0), Error (98, 99, 100)
 */

int main(int argc, char *argv[])
{
	int solution;
	int (*op_func)(int, int);
	int div_check;
	int mod_check;

	op_func = get_op_func(argv[2]);
	div_check = strcmp(argv[2], "/");
	mod_check = strcmp(argv[2], "%");
	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}
	else if (op_func == NULL)
	{
		printf("Error\n");
		return (99);
	}
	else if ((div_check == 0 || mod_check == 0) && atoi(argv[3]) == 0)
	{
		printf("Error\n");
		return (100);
	}

	solution = op_func(atoi(argv[1]), atoi(argv[3]));
	printf("%d\n", solution);
	return (0);
}


