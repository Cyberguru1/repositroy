#include "main.h"

/**
 * parse_cmd - parse line of input
 * @input: input parameter form getline
 * Return: an array of the input
 */

char **parse_cmd(char *input)
{   char **tokens, *token;
	int i;
	char delim[5] = "\n ";

	i = 0;

	if (input == NULL)
	return (NULL);

	tokens = malloc(sizeof(char) * BUFFSIZE);
	
	if (tokens == NULL){
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, delim);

	while (token != NULL)
	{
		tokens[i] = token;
		token = _strtok(NULL, delim);
		i++;
	}
	return (tokens);
}