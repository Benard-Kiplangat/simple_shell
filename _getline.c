#include "main.h"

/**
 * _getline - implementation of getline function
 * @prompt: a pointer to the string pointer to store the user's input
 *
 * Return: the number of successful chars read from stdin
 */

int _getline(char *prompt)
{
	size_t sz = 2048;
	char *ptemp = calloc(sizeof(char), sz);
	int nread = 0, n = 0, rd = 0, i;
	/* nread: number of chars read from stdin */

	prompt[0] = '\0';
	ptemp[0] = '\0';

	do {
		rd = read(STDIN_FILENO, ptemp, 2048);
		for (i = 0; ptemp[i] != '\0'; i++)
		{
			if (ptemp[i] != ' ' && ptemp[i] != '\n')
			{
				n = 1;
				break;
			}
		}
		if (n == 1)
			strcat(prompt, ptemp);
		else
			prompt[0] = '\0';
		if (rd > 0)
			nread = nread + rd;
		if (rd > 2047)
		{
			sz = sz * 2;
			prompt = realloc(prompt, sz);
		}
	} while (rd >= 2048);
	free(ptemp);
	return (nread);
}
