#include "function_pointers.h"

/**
 * print_name - Prints a name
 * @name: Name to be printed
 * @f: Function that prints name
 *
 * Return: No return value
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}

