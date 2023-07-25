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

int _strtok(char *prompt, char *get_token, char **getlin, char *delims)
{
	int i, j = 0, k = 0, frm = 0, to = 0; /* i: iterator */

	for (i = 0; prompt[i] != '\0'; i++)
	{
		for (j = 0; delims[j] != '\0'; j++)
		{
			if (prompt[i] == delims[j])
			{
				if (prompt[i + 1] == '\0')
				{
					get_token = strndup(prompt + frm, i - frm);
					getlin[k] = strdup(get_token);
					break;
				}
				to = i;
				get_token = strndup(prompt + frm, to - frm);
				getlin[k] = strdup(get_token);
				to++;
				k++;
				break;
			}
			frm = to;
		}
	}
	if (k == 0 && to == 0 && i > 0)
	{
		getlin[k] = strdup(prompt);
		k++;
	}
	getlin[k] = NULL;
	return (0); /* return the number of chars read */
}
