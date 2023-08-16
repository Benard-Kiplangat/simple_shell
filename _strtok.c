#include "main.h"

/**
 * _strtok - implementation of the strtok function
 * @prompt: the pointer to the string read from the stdin
 * @get_token: pointer to hold the tokens temporarily
 * @getlin: the array of tokens
 * @delims: the delimeters to break the string into tokens
 *
 * Return: pointer to getlin or -1 on error
 */

int _strtok(char *prompt, char *token, char **getlin, char *delims)
{
	int i;

	token = _strdup(strtok(prompt, delims));
	for (i = 0; token != NULL; i++)
	{
		getlin[i] = _strdup(token);
		token = strtok(NULL, delims);
	}
	getlin[i] = NULL;
	free(token);
/*	int i, j = 0;*//* i: iterator */
/*	int k = 0, c = 0, d = 0;

	if (prompt != NULL)
	{
		for (i = 0; prompt[i] != '\0'; i++)
		{
			for (j = 0; delims[j] != '\0'; j++)
			{
				if (prompt[i] == delims[j])
				{
					if (d == 0 && prompt[i + 1] == '\0')
					{
						token[c] = '\0';
						getlin[k] = _strdup(token);
						i++;
						getlin[k + 1] = NULL;
						return (0);
					}
					token[c] = '\0';
					i++;
					c = 0;
					getlin[k] = _strdup(token);
					k++;
					d = i;
					break;
				}
			}
			if (prompt[i + 1] == '\0' && d < i + 1)
			{
				i = d;
				for (c = 0; prompt[i] != '\0'; i++)
				{
					token[c] = prompt[i];
					c++;
				}
				token[c] = '\0';
				getlin[k] = _strdup(token);
				if (getlin[k][0] == '\0')
				{
					getlin[k] = NULL;
					break;
				}
				getlin[k + 1] = NULL;
				break;
			}
			else
			{
				token[c] = prompt[i];
				c++;
			}
		}
	}*/
	return (0);
}
