#include "shell.h"

/**
 * _realloc -will allocate memory and set all values to 0
 * @ptr:is the pointer to the memory previously allocated (malloc(old_size))
 * @old_size: is the size previously allocated
 * @new_size:is the new size to be reallocated
 * Return: pointer to the reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);


	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr);

	return (p);
}
