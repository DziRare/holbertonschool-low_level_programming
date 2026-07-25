#ifndef _DOG_T_H_
#define _DOG_T_H_

/**
 * struct dog_t - Defines a dog
 * @name: Name of dog
 * @age: Age of dog
 * @owner: Owner of dog
 */
struct dog_t
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

void print_dog(struct dog *d);

#endif /* _DOG_T_H_ */
