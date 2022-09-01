#include "main.h"

/**
 * _realloc - function to reallocates memory
 * @ptr: pointer to previous memory address
 * @old_size: old byte size
 * @new_size: new byte size
 *
 * Return: pointer memory address
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *buffer;

	if (!ptr)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}

	buffer = malloc(new_size);
	if (buffer == NULL)
		return (NULL);

	if (old_size >= new_size)
		old_size = new_size;

	old_size--;
	while (old_size)
	{
		buffer[old_size] = ((char *)ptr)[old_size];
		old_size--;
	}
	free(ptr);

	return (buffer);
}

/**
 * _memset - fills memory
 * @str: pointer to string memory
 * @fill: the byte to fill with
 * @num: the number of bytes to fill
 *
 * Return: pointer to the memory address
 */
char *_memset(char *str, char fill, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		str[i] = fill;

	return (str);
}
