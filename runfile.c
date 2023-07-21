#include "main.h"
/**
 * runshfile - a function that runs commands in files
 * @filename: the file with the commands
 * @getlin: array for our commands
 * Return: the number of chars read
 */
int runshfile(char *filename, char **getlin)
{
	pid_t p; /* for the new child process to execute programs */
	int ext, env, rtd = 0, j = 0, cnt = 0;
	char *prompt, *command, *commands[100], *path[10];

	prompt = malloc(sizeof(char) * 1024);
	command = calloc(sizeof(char), 100);
	rtd = readshfile(filename, &prompt);
	_strtok(prompt, command, commands, ";\nEOF");
	do {
		ext = strncmp(commands[j], "exit", 4);
		env = strncmp(commands[j], "env", 3);
		_strtok(commands[j], command, getlin, " \t\n\r\a");
		if (env == 0)
		{
			envfunc();
			break;
		}
		if (ext == 0)
			exitfunc(getlin[1], prompt, get_token);
		j++;
		if (getlin[0][0] != '/')
			findexec(environ, command, path, getlin);
		if (!access(getlin[0], X_OK))
		{
			p = fork();
			if (p == 0)
			{
				execve(getlin[0], getlin, environ);
				sleep(1);
			}
			if (p != -1)
				wait(NULL);
		}
		else
		{
			cnt++;
			errmsg(getlin, cnt);
		}
	} while (commands[j] != NULL);
	return (rtd); /* return the number of chars read */
}
