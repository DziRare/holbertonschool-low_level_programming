#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - Initialise variable of type struct dog_t
 * @name: Name of dog
 * @age: Age of dog
 * @owner: Name of dog owner
 *
 * Return: Pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new;
	char *name_copy;
	char *owner_copy;
	int len, i;

	new = malloc(sizeof(dog_t));
	if (new == NULL)
		return (NULL);

	for (len = 0; name[len] != '\0'; len++)
		;
	name_copy = malloc(sizeof(char) * (len + 1));
	if (name_copy == NULL)
	{
		free(new);
		return (NULL);
	}
	for (i = 0; i < len; i++)
		name_copy[i] = name[i];
	name_copy[len] = '\0';

	for (len = 0; owner[len] != '\0'; len++)
		;
	owner_copy = malloc(sizeof(char) * (len + 1));
	if (owner_copy == NULL)
	{
		free(new);
		free(name_copy);
		return (NULL);
	}
	for (i = 0; i < len; i++)
		owner_copy[i] = owner[i];
	owner_copy[len] = '\0';

	new->name = name_copy;
	new->age = age;
	new->owner = owner_copy;

	return (new);
}
