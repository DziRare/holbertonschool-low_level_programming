#include <stdio.h>
#include "main.h"

/**
 * _isupper - Uppercase
 * @c: Character to be checked
 * Description: Checks for uppercase character
 * Return: 1 if character is uppercase or 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
