#include "main.h"

/**
 * parse_cmd - parse line of input
 * @input: input parameter form getline
 * Return: an array of the input
 */

char **parse_cmd(char *input)
{   char **tokens, *token;
	int i;

	i = 0;
	if (input == NULL)
	return (NULL);
	tokens = malloc(sizeof(char) * BUFFSIZE);
	if (tokens == NULL)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, TOK_BUFSIZE);

	while (token != NULL)
	{
		tokens[i] = token;
		token = _strtok(NULL, TOK_BUFSIZE);
		i++;
	}
	return (tokens);
}
