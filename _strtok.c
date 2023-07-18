#include "main.h"

/**
 * _strtok - implementation of the strtok function
 * @prompt: the pointer to the string read from the stdin
 *
 * Return: pointer to getlin or -1 on error
 */

int _strtok(char *prompt, char **getlin, char *delims)
{
	int frm = 0, to = 0;
	int i, j, k = 0; /* i: iterator */
	char *get_token; /* temporarily store tokens and arguments recieved */

	/**
	 * nread: number of chars read from stdin
	 * ext: to compare if the user typed exit to terminate their session
	 * cnt: to count the number of calls to the shell
	 */

	get_token = malloc(sizeof(char) * 50);

	if (!get_token)
		return (-1);

	for (i = 0; prompt[i] != '\0'; i++)
	{
		for (j = 0; delims[j] != '\0'; j++)
		{
			if (prompt[i] == delims[j])
			{
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
	free(get_token);
	/**
	get_token = strtok(prompt, " \t\n\r\a");
	* stripping the user input for the program path/name */
/*
	for (i = 0; get_token != NULL; i++)
	{
	* stripping and saving the program and its arguments */
/*		getlin[i] = strdup(get_token);
		get_token = strtok(NULL, " \n\t\r\a");
	}
	getlin[i] = NULL; * NULL-terminating the array */
	return (0); /* return the number of chars read */
}
