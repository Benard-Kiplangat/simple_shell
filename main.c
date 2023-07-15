#include "main.h"

/**
 * main - the shell
 * argc - the number of arguments suplied from the command line
 * argv - an array of arguments supplied to the program
 *
 * Return: 0 on success, -1 on failure
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	size_t n = 0;
	int i;
	pid_t p;
	char *prompt;
	char *get_token;
	char *getlin[100];
	int nread, ext, cnt = 0;

	do
	{
		write(STDOUT_FILENO, "~$ ", 3);
		nread = getline(&prompt, &n, stdin);
		ext = strncmp(prompt, "exit", 4);
		get_token = strtok(prompt, " \t\n\r\a");

		for (i = 0; get_token != NULL; i++)
		{
			getlin[i] = strdup(get_token);
			get_token = strtok(NULL, " \n\t\r\a");
		}
		getlin[i] = NULL;
		if (ext == 0)
			return (0);
		p = fork();
		if (p == 0)
		{
			execve(getlin[0], getlin, NULL);
			sleep(1);
		}
		else if (p != -1)
			wait(NULL);
		else
		{
			cnt++;
			prompt[nread - 1] = '\0';
			printf("hsh: %i: %s: not found", cnt, prompt);
		}
	}
	while (isatty(STDIN_FILENO));
	return (nread);
}
