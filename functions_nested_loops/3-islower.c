#include <stdio.h>
#include "main.h"

/**
 * _islower - Lowercase characters
 * @c: The character to be checked
 * Description: Checks for lowercase character.
 * Return: 0 (Success)
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
