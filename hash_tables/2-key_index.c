#include "hash_tables.h"

/**
 * key_index - Gets the index of a key
 * @key: Key that is going to be used
 * @size: Size of the array of hash table
 *
 * Return: Index where the key/value pair will be stored in the array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	(void)size;
	return (hash_djb2(key) % size);
}
