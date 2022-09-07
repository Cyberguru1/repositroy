#include "main.h"

/**
 * _putchar - writes to stdout a char
 * @c: character to write
 * Return: 0 on failure and 1 on success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strlen - length of string
 * @s: char
 * Return: returns size of string
 */

int _strlen(char *s)
{
	int i;

	while (*s)
	{
		s++;
		i++;
	}

	return (i);
}
/**
 * _puts - print a string
 * @str: pointer to an array of char ending with a '\0'
 * Return: void
 * iterate through the list and use _putchar to print char
 */
void _puts(char *str)
{
	int i;

	i = 0;	
	while (*str)
	{
		_putchar(str[i]);
		i++;
	}

}

/**
 * _strcpy - copies one string to another
 * @dest: destination of the copied string
 * @src: source of string
 * Return: an addres tor dest
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - compares two string
 * check 'man strcmp' for more
 * @first_str: first string to compare
 * @second_str: second string to compare
 * Return: returns 1 on success and 0 on failure
 */

int _strcmp(char *first_str, char *second_str)
{
	int i;

	for (i = 0; first_str[i] == second_str[i] && first_str[i]; i++)
	;
	if (first_str[i] > second_str[i])
	return (1);
	if (first_str[i] < second_str[i])
	return (-1);

	return (0);
}
