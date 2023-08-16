#include "main.h"
/**
 * runshfile - a function that runs commands in files
 * @filename: the file with the commands
 * @getlin: array for our commands
 * @cnt: command counter
 * Return: the number of chars read
 */
int runshfile(char *filename, char **getlin, int *cnt)
{
	int ext, cdf, env, rtd = 0, j = 0, status = 0;
	char *prompt, *get_token, *commands[100], *path[10];

	prompt = malloc(sizeof(char) * 1024);
	get_token = malloc(sizeof(char) * 100);
	rtd = readshfile(filename, &prompt);
	free(filename);
	_strtok(prompt, get_token, commands, "\n;");
	do {
		strcat(commands[j], "");
		ext = strncmp(commands[j], "exit", 4);
		env = strncmp(commands[j], "env", 3);
		cdf = strncmp(commands[j], "cd", 2);
		_strtok(commands[j], get_token, getlin, " \t\n\r\a");
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
		free(get_token);
		free(prompt);
		forkfunc(getlin, environ, cnt);
		j++;
	} while (commands[j] != NULL);
	return (rtd); /* return the number of chars read */
}
