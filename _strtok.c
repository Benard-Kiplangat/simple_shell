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
	int frm = 0, to = 0;
	int i, j, k = 0; /* i: iterator */

	for (i = 0; prompt[i] != '\0'; i++)
	{
		for (j = 0; delims[j] != '\0'; j++)
		{
			if (prompt[i] == delims[j] || prompt[i + 1] == '\0')
			{
				if (frm == 0 && prompt[i + 1] == '\0')
				{
					i++;
				}
				if (prompt[i + 1] == delims[j + 1])
				{
					i++;
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
		getlin[k] = NULL;
	}
	return (0); /* return the number of chars read */
}
