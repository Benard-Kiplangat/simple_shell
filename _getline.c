#include "main.h"

/**
 * _getline - implementation of getline function
 * @prompt: a pointer to the string pointer to store the user's input
 *
 * Return: the number of successful chars read from stdin
 */

int _getline(char *prompt)
{
	size_t sz = 1024;
	char *ptemp = calloc(sizeof(char), sz);
	int nread = 0, rd = 0;
	/* nread: number of chars read from stdin */

	prompt[0] = '\0';
	ptemp[0] = '\0';

	do {
		rd = read(STDIN_FILENO, ptemp, 1024);
		strcat(ptemp, " \n");
		strcat(prompt, ptemp);
		if (rd > 0)
			nread = nread + rd;
		if (rd > 1023)
		{
			sz = sz * 2;
			prompt = realloc(prompt, sz);
		}
	} while (rd >= 1024);
	if (prompt[nread - 1] == '\n')
	{
		prompt[nread] = '\n';
		prompt[nread + 1] = '\0';
	}
	free(ptemp);
	return (nread);
}
