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
    int i;

    while (*s)
    {
        s++;
        i++;
    }

    return i;
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
    int i;
    i = 0;

    while(*str)
    {
        _putchar(str[i]);
        i++;
    }

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

/**
 * _strdup - Duplicate a string
 * @s1: string1
 * Return: returns string duplicate
 */
 char *_strdup(char *s1)
 {
     int i;
     int x;
     char *s2;

     i = _strlen(s1);

     if((s2 = malloc(sizeof(char) * (i + 1))) == NULL)
         return NULL;

     for (x = 0; x < i; x++)
     {
         s1[x] = s2[x];
     }
     s2[x] = '\0';

    return s2;
}

/**
 * _strchr - search for a character in a given str
 * @c: character to search for
 * @s: string where the character will be searched
 * Return: pointer to the first occurence of the character
 */
char *_strchr(char *s, char c)
{
    unsigned int i = 0;

    for (; *(s + i) != '\0'; i++)
    {
        if (*(s + i) == c)
         return (s + i);
    }

    if (*(s + i) == c)
       return (s + i);
    return ('\0');
}

/**
 * _strspn - gets the length of a prefix substring
 * @s: inital prefix
 * @a: substring
 * Return: the number of accepted bytes
 */
int _strspn(char *s, char *a)
{
    int i, j, bool;
    
    for
}