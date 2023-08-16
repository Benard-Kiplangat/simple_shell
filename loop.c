#include "main.h"
/**
 * loop - the shell loop
 * @getlin: the command container
 * @cnt: command counter
 * Return: 0 on success, -1 on failure
 */
int loop(int *cnt)
{
	int term = isatty(STDIN_FILENO), status = 0, i;
	int readchars = 0, ext;
	char *prompt, **getlin, **path, *get_token;

	getlin = calloc(sizeof(char *), 50);;
	path = calloc(sizeof(char *), 20);
	prompt = calloc(sizeof(char), 1024);;
	do {
		freer(getlin);
		freer(path);
		free(prompt);
		getlin = calloc(sizeof(char *), 50);
		path = calloc(sizeof(char *), 20);
		prompt = calloc(sizeof(char), 1024);
		if (term)
			write(STDOUT_FILENO, "~$ ", 3);
		readchars = _getline(prompt); /* getting the input */
		printf("prompt: %s\n", prompt);
		if (prompt[readchars - 1] == '\n')
			prompt[readchars - 1] = '\0';
		ext = strncmp(prompt, "exit", 4);
		if (readchars <= 0)
		{
			write(STDOUT_FILENO, "\n~$ ", 4);
			free(prompt);
			freer(getlin);
			freer(path);
			free(get_token);
			continue;
		}
		get_token = strtok(prompt, " \t\n\r\a");
		for (i = 0; get_token != NULL; i++)
		{
			getlin[i] = strdup(get_token);
			get_token = strtok(NULL, " \t\n\r\a");
		}
		getlin[i] = NULL;

		if (ext == 0)
		{
			if (getlin[1])
				status = atoi(getlin[1]);
			free(get_token);
			freer(getlin);
			freer(path);
			free(prompt);
			exitfunc(status);
		}
		if (getlin[0][0] != '/')
			findexec(environ, get_token, path, getlin);
		forkfunc(getlin, environ, cnt);
	} while (term);
	return (readchars); /* return the number of chars read */
}
