#include "main.h"

/**
 * _getline - implementation of getline function
 * @prompt: a pointer to the string pointer to store the user's input
 * @n: the number of bytes to read from stdin
 *
 * Return: the number of successful chars read from stdin
 */

int _getline(char *prompt)
{
	size_t sz = 1024;
	char *ptemp;
	int nread = 0, rd = 0;
	/* nread: number of chars read from stdin */

	*prompt = '\0';
	ptemp = malloc(sizeof(char) * sz);
	do {
		rd = read(STDIN_FILENO, ptemp, 1024);
		strcat(prompt, ptemp);
		if (rd > 0)
			nread = nread + rd;
		if (rd > 1023)
		{
			sz = sz * 2;
			prompt = realloc(prompt, sz);
		}
	} while (rd >= 1024);

	prompt[nread] = '\0';
	free(ptemp);
	return (nread);
}
