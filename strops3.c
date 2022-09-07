#include "main.h"

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
	size_t i;

	if (s1 == NULL)
	return (-1);
	
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - Duplicate a string
 * @s1: string1
 * Return: returns string duplicate
 */
char *_strdup(char *s1)
{	 int i;
	 int x;
	 char *s2;
	 
	 i = _strlen(s1);
	 s2 = malloc(sizeof(char) * (i + 1));
	 if (s2 == NULL)
	 return (NULL);

	 for (x = 0; x < i; x++)
	 {
		 s1[x] = s2[x];
	 }
	 s2[x] = '\0';
	 return (s2);
}
/**
 * cmpChar - comapres each char in a string
 * @str1: array of string
 * @del: input delimeter to compare(also an array)
 * Return: 1 on sucess
 */
int cmpChar(char str1[], const char *del)
{
	unsigned int i, j, k;

	for (i = 0; str1[i] != '\0'; i++)
	{
		for (j = 0; del[j] != '\0'; j++)
		{
			if (str1[i] != del[j])
			break;
			k++;
		}
	}
	if (i == k)
	return (1);
	return (0);
}

/**
 * revstr - reverse an inputed string
 * @str: input string
 * Return: void
 */
void revstr(char *s)
{
	int i, x;
	char temp;
	
	i = 0; 

	while (s[i] != '\0')
	{
		i++;
	}

	for (x = 0; x <= ((i - 1) / 2); x++)
	{
		temp = *(s + (i - x -1));
		*(s + (i - x -1)) =  *(s + x);
		*(s + x) = temp;
	}
}
