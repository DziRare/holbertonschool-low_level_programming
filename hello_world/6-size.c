#include <stdio.h>

/**
 * main - Entry of code
 * Description: Prints the size of various data types
 * Return: 0
 */
int main(void)
{

	char my_char;
	int my_int;
	long my_long_int;
	long long my_long_long_int;
	float my_float;

	printf("Size of a char: %zu (bytes)\n", sizeof(my_char));
	printf("Size of an int: %zu (bytes)\n", sizeof(my_int));
	printf("Size of a long int: %zu (bytes)\n", sizeof(my_long_int));
	printf("Size of a long long int: %zu (bytes)\n", sizeof(my_long_long_int));
	printf("Size of a float: %zu (bytes)\n", sizeof(my_float));

	return (0);
}
