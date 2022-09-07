#include "main.h"
/**
 * _strspn - gets the length of a prefix substring
 * @s: inital prefix
 * @a: substring
 * Return: the number of accepted bytes
 */
int _strspn(char *s, char *a)
{
	int i, j, bool;
	
	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(a + j) != '\0'; j++)
		{
			if (*(s + i) == *(a + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
		 break;
	}
	return (1);
}
/**
 * _strcat - combines two strings
 * @s1: first string
 * @s2: second string
 * Return: a poniter to a new string
 */
char *_strcat(char *s1, const char *s2)
{
	int i,j;

	for (i = 0; s1[i] != '\0'; i++)
	;
	for (j = 0; s2[j] != '\0'; j++)
	{
		s1[i] = s2[j];
		i++;
	}

	s1[i] = '\0';

	return (s1);
}

/**
 * _isdigit - checks if string passed is a number
 * @s: input string
 * Return: 1 on sucess and 0 on failure
 */
int _isdigit(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			   return (0);
	}
	return (1);
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
