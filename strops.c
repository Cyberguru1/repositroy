#include "main.h"

/**
 * _putchar - writes to stdout a char
 * @c: character to write
 * Return: 0 on failure and 1 on success
 */

int _putchar(char c)
{
    return(write(1, &c, 1));
}

/**
 * _strncpy - copy a string
 * @dest: char array to copy to
 * @src: char array to copy from
 * @n: size of bytes to copy
 * Return: dest of char
 */

char *_strncpy(char *dest, char *src, int n)
{
    int i;

    for (i = 0; i < n && *(src + i); i++)
    {
        *(dest + i) = *(src + i);
    }

    /* fill the remainning space if exitsting with '\0' */
    while (i < n)
    {
        *(dest + i) = '\0';
        i++;
    }
    return dest;

}

/**
 * _strlen - length of string
 * @s: char
 * Return: returns size of string
 */

int _strlen(char *s)
{

}

/**
 * _atoi - converts a string to int
 * @s: char to convert
 * Return: int
 */

int _atoi(char *s)
{

}

/**
 * _puts - print a string
 * @str: pointer to an array of char ending with a '\0'
 * Return: void
 * iterate through the list and use _putchar to print char
 */
void _puts(char *str)
{

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

}

/**
 * _strncmp - compares N characters of string
 * check 'man strncmp' for more detail
 * @s1: first string
 * @s2: second string
 * @n: size of bytes for comparison
 * Return: returns 1 on success and 0 on failure
 */
int _strncmp(char *s1, char *s2, size_t n)
{

}
