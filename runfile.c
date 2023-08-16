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
	int cdf, env, rtd = 0, j = 0;
	char *prompt, *get_token, **commands, **path;

	prompt = calloc(sizeof(char), 1024);
	get_token = calloc(sizeof(char), 100);
	commands = calloc(sizeof(char *), 100);
	path = calloc(sizeof(char *), 50);
	rtd = readshfile(filename, &prompt);
	free(filename);
	_strtok(prompt, get_token, commands, "\n;");
	do {
		freer(path);
		free(get_token);
		free(prompt);
		prompt = calloc(sizeof(char), 1024);
		get_token = calloc(sizeof(char), 100);
		path = calloc(sizeof(char *), 50);
		strcat(commands[j], "");
		env = strncmp(commands[j], "env", 3);
		cdf = strncmp(commands[j], "cd", 2);
		_strtok(commands[j], get_token, getlin, " \t\n\r\a");
		if (env == 0)
		{
			envfunc();
			j++;
			continue;
		}
		if (cdf == 0)
		{
			cdfunc(getlin, cnt);
			j++;
			continue;
		}
		if (getlin[0][0] != '/')
			findexec(environ, get_token, path, getlin);
		forkfunc(getlin, environ, cnt);
		j++;
	} while (commands[j] != NULL);
	free(get_token);
	free(prompt);
	freer(path);
	freer(commands);
	return (rtd); /* return the number of chars read */
}
