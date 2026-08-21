#include "main.h"

/**
 * sqrt_helper - Finds the natural square root of n
 * @n: The number to find the square root of
 * @guess: The current guess being tested
 *
 * Return: the natural square root if found, otherwise -1
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);

	if (guess * guess > n)
		return (-1);

	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - Natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The natural square root of n
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 0));
}
