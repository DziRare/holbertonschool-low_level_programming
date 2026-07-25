#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * init_dog - Initialise variable of type struct dog
 * @d: Struct to create dog
 * @name: Name of dog
 * @age: Age of dog
 * @owner: Name of dog owner
 *
 * Return: No return value
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	(*d).age = age;
	(*d).owner = owner;
}
