#include "main.h"

/**
 * loop - the shell loop
 *
 * @argc: the number of arguments suplied from the command line
 * @argv: an array of arguments supplied to the program
 *
 * Return: 0 on success, -1 on failure
 */

int loop(char **getlin)
{
	pid_t p; /* for the new child process to execute programs */
	int nrd, ext, env, cmd_avaibl, cntint = 0, term = isatty(STDIN_FILENO);
	char *prompt, *get_token, *status, *path[10];
	int *cnt = &cntint;

	prompt = calloc(sizeof(char), 1024);
	get_token = calloc(sizeof(char), 100);
	do {
		if (term)
			write(STDOUT_FILENO, "~$ ", 3);
		nrd = _getline(prompt); /* getting the input */
		ext = strncmp(prompt, "exit", 4);
		env = strncmp(prompt, "env", 3);
		_strtok(prompt, get_token, getlin, " \t\n\r\a");
		if (env == 0)
		{
			envfunc();
			break;
		}
		if (ext == 0)
		{
			status = getlin[1];
			free(prompt);
			free(get_token);
			exitfunc(status);
		}
		if (getlin[0][0] != '/')
			findexec(environ, get_token, path, getlin);

		cmd_avaibl = access(getlin[0], X_OK);
		if (!cmd_avaibl)
		{
			p = fork();
			if (p == 0)
			{
				*cnt = *cnt + 1;
				execve(getlin[0], getlin, environ);
				sleep(1);
			}
			if (p != -1)
				wait(NULL);
		}
		else
		{
			*cnt = *cnt + 1;
			printf("Error: \n");
			errmsg(getlin, cnt);
		}
	} while (term);
	return (nrd); /* return the number of chars read */
}
