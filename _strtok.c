#include "main.h"
/**
 * check_delimeter - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */

unsigned int check_delimeter(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++) //checks if c is a null character
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - Token A String Into Token (strtrok)
 * @str: String
 * @delim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */

char *_strtok(char *str, const char *delim)
{
	static char *ts, *nt; //ts - stored token, nt - next token
	unsigned int i;

	if (str != NULL) // checks if current string is null
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delimeter(ts[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (check_delimeter(nt[i], delim) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}