#include <stdarg.h>

/**
 * sum_them_all - Sum of all parameters
 * @n: First number to be added
 *
 * Return: Sum of all parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int total;
	va_list numbers;

	va_start(numbers, n);
	total = 0;
	for (i = 0; i < n; i++)
	{
		total += va_arg(numbers, int);
	}
	va_end(numbers);
	return (total);
}
