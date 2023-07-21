#include "main.h"

/**
 * runshfile - a function that runs commands in files
 *
 * @filename: the file with the commands
 *
 * Return: the number of chars read
 */

int runshfile(char *filename, char **getlin)
{
	pid_t p; /* for the new child process to execute programs */
	int ext, env, cmd_avaibl;
	char *prompt, *command, *status, *path[10];
	int rtd = 0, j = 0, cntint = 0;
	char *commands[100];
	int *cnt = &cntint;

	prompt = malloc(sizeof(char) * 1024);
	command = calloc(sizeof(char), 100);

	rtd = readshfile(filename, &prompt);
	_strtok(prompt, command, commands, ";\nEOF");

	if (rtd == 0)
		return(0);

	do {
		printf("commds: %s\n", commands[j]);
		ext = strncmp(commands[j], "exit", 4);
		env = strncmp(commands[j], "env", 3);
		_strtok(commands[j], command, getlin, " \t\n\r\a");
		if (env == 0)
		{
			envfunc();
			break;
		}
		if (ext == 0)
		{
			status = getlin[1];
			free(prompt);
			exitfunc(status);
		}
		j++;
		if (getlin[0][0] != '/')
			findexec(environ, command, path, getlin);

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
	} while (commands[j] != NULL);
	return (rtd); /* return the number of chars read */
}
