#include "main.h"

/**
 * prime_helper - Checks if n is divisible by any number
 * @n: The number to check
 * @divisor: The current divisor being tested
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int prime_helper(int n, int divisor)
{
	if (divisor * divisor > n)
	{
		return (1);
	}

	if (n % divisor == 0)
	{
		return (0);
	}

	return (prime_helper(n, divisor + 1));
}

/**
 * is_prime_number - checks if an integer is a prime number
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
	{
		return (0);
	}
	return (prime_helper(n, 2));
}
