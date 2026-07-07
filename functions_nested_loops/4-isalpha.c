#include "main.h"
#include <stdio.h>

/**
 * _isalpha - Is a letter
 * @c: The character to be checked
 * Description: Checks for alphabetic character.
 * Return: 0 (Success)
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
