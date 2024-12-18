#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * Description:
 *  - The contents will be copied to the newly allocated space, in the
 * range from the start of ptr up to the minimum of the old and new sizes
 *  - If new_size > old_size, the “added” memory should not be initialized
 *  - If new_size == old_size do not do anything and return ptr
 *  - If ptr is NULL, then the call is equivalent to malloc(new_size),
 * for all values of old_size and new_size
 *  - If new_size is equal to zero, and ptr is not NULL, then the call
 * is equivalent to free(ptr). Return NULL
 *
 * @ptr: pointer to the memory block to be reallocated
 * @old_size: the former size of the memory block
 * @new_size: the new size to which the block must be set
 *
 * Return: a pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int decide;
	unsigned int i;
	char *char_ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_size < old_size)
		decide = new_size;
	else
		decide = old_size;

	/* char_ptr is used so as not to dereference a void pointer */
	char_ptr = (char *)ptr;
	/* copy bytes from the old pointer to min of old_size and new_size */
	for (i = 0; i < decide; i++)
	{
		new_ptr[i] = char_ptr[i];
	}
	free(ptr);

	return (new_ptr);
}
