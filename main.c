#include "main.h"
/**
 * main - the shell
 * @argc: the number of arguments suplied from the command line
 * @argv: an array of arguments supplied to the program
 * Return: 0 on success, -1 on failure
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	char *getlin[100];
	int cnt = 0, readch = 0;

	readch += loop(getlin, &cnt);

	/*
	do {
		if (term)
			write(STDOUT_FILENO, "~$ ", 3);
		nrd = _getline(prompt); * getting the input *
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
				cnt++;
				execve(getlin[0], getlin, environ);
				sleep(1);
			}
			if (p != -1)
				wait(NULL);
		}
		else
		{
			cnt++;
			printf("hsh: %i: %s: not found\n", cnt, getlin[0]);
		}
	} while (term);
	return (nrd); * return the number of chars read */
	return (readch);
}
