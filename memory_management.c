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
 * _memcpy - copy ones memory to another
 * @src: source to copy from
 * @dest: destination to copy to
 * @n: size in bytes of dest
 * Return: void pointer
 */

void *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}


/**
 * free_all - free an arrya of char pointer with a character pointer
 * @ptr: array pointer
 * @line: char pointer
 * Return: void
 */

void free_all(char **ptr, char *line)
{
	free(ptr);
	free(line);
	ptr = NULL;
	line = NULL;
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

/**
 * _calloc - allocates an n size memory initialized with 0's
 * @size: size of memory to allocate
 * Return: an initialized memory
 */

void *_calloc(unsigned int size)
{
	unsigned int i;
	char *mem;

	if (size == 0)
	return (NULL);
	mem = malloc(size);
	if (mem == NULL)
	{
		perror("hsh");
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		mem[i] = '\0';
	}

	return (mem);
}
