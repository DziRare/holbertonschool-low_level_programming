#include "3-calc.h"
#include <stdio.h>
#include <string.h>

/**
 * get_op_func - Retrieve the function for operation to be performed
 * @s: Operation to be performed
 *
 * Return: Pointer to function that performs operation
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL && strcmp(ops[i].op, s) != 0)
	{
		i++;
	}
	return (ops[i].f);
}
