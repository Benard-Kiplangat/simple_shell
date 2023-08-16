#include "main.h"

/**
 * _strtok - implementation of the strtok function
 * @prompt: the pointer to the string read from the stdin
 * @token: pointer to hold the tokens temporarily
 * @getlin: the array of tokens
 * @delims: the delimeters to break the string into tokens
 *
 * Return: pointer to getlin or -1 on error
 */

int _strtok(char *prompt, char *token, char **getlin, char *delims)
{
	int i;

	token = strtok(prompt, delims);
	for (i = 0; token != NULL; i++)
	{
		free(getlin[i]);
		getlin[i] = _strdup(token);
		token = strtok(NULL, delims);
	}
	free(getlin[i]);
	getlin[i] = NULL;
	free(token);
	return (0);
}
