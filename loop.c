#include "main.h"
/**
 * loop - the shell loop
 * @getlin: the command container
 * @cnt: command counter
 * Return: 0 on success, -1 on failure
 */
int loop(char **getlin, int *cnt)
{
	int nrd, ext, env, cdf, status = 0, term = isatty(STDIN_FILENO);
	char *prompt, *get_token, *path[10];

	prompt = calloc(sizeof(char), 1024);
	get_token = calloc(sizeof(char), 100);
	do {
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
	} while (term);
	return (nrd); /* return the number of chars read */
}
