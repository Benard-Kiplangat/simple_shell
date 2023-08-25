#include "main.h"
/**
 * loop - the shell loop
 * @cnt: counter
 */
void loop(int *cnt)
{
	int term = isatty(STDIN_FILENO), status = 0, rd = 0, ext, cdf, env;
	char *prompt, **getlin, **path, *get_token;

	getlin = calloc(sizeof(char *), 50);
	path = calloc(sizeof(char *), 20);
	prompt = calloc(sizeof(char), 1024);
	get_token = calloc(sizeof(char), 200);
	do {
		freer(getlin);
		freer(path);
		free(prompt);
		getlin = calloc(sizeof(char *), 50);
		path = calloc(sizeof(char *), 20);
		prompt = calloc(sizeof(char), 1024);
		if (term)
			write(STDOUT_FILENO, "~$ ", 3);
		rd += _getline(prompt); /* getting the input */
		if (prompt[0] == '\0')
			continue;
		ext = strncmp(prompt, "exit", 4);
		cdf = strncmp(prompt, "cd", 2);
		env = strncmp(prompt, "env", 3);
		_strtok(prompt, get_token, getlin, " \t\n\r\a");
		if (ext == 0)
		{
			status = getlin[1] != NULL ? atoi(getlin[1]) : 0;
			exitfunc(get_token, getlin, path, prompt, status);
		}
		if (env == 0)
		{
			envfunc();
			continue;
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
}
