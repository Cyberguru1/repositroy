#include "main.h"
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
