#include "main.h"
/**
 * loop - the shell loop
 * @getlin: the command container
 * @cnt: command counter
 * Return: 0 on success, -1 on failure
 */
int loop(char **getlin, int *cnt)
{
	int nrd, ext, i, env, cdf, status = 0, term = isatty(STDIN_FILENO);
	char *prompt, *get_token, *path[10];

	do {
		prompt = calloc(sizeof(char), 1024);
		get_token = calloc(sizeof(char), 100);
		if (term)
			write(STDOUT_FILENO, "~$ ", 3);
		nrd = _getline(prompt); /* getting the input */
		ext = strncmp(prompt, "exit", 4);
		env = strncmp(prompt, "env", 3);
		cdf = strncmp(prompt, "cd", 2);
		_strtok(prompt, get_token, getlin, " \t\n\r\aEOF");
		if (env == 0)
		{
			envfunc();
			continue;
		}
		if (ext == 0)
		{
			if (getlin[1])
				status = atoi(getlin[1]);
			exitfunc(status);
		}
		if (cdf == 0)
		{
			cdfunc(getlin, cnt);
			continue;
		}
		if (getlin[0][0] != '/')
			findexec(environ, get_token, path, getlin);
		forkfunc(getlin, environ, cnt);
		for (i = 0; getlin[i] != NULL; i++)
			free(getlin[i]);
		for (i = 0; path[i] != NULL; i++)
			free(path[i]);
		if (prompt)
			free(prompt);
		if (get_token)
			free(get_token);
	} while (term);
	return (nrd); /* return the number of chars read */
}
