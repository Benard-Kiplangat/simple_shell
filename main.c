#include "main.h"

/**
 * main - the shell
 * @argc: the number of arguments suplied from the command line
 * @argv: an array of arguments supplied to the program
 *
 * Return: 0 on success, -1 on failure
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	int term = isatty(STDIN_FILENO); /* check if it's a terminal */
	size_t n = 0;
	pid_t p; /* for the new child process to execute programs */
	char *prompt; /* what we will read from the standard in */
	char *getlin[100]; /* to store tokens after they've been stripped */
	int i, nread, ext, env, cnt = 0;
	int cmd_avaibl;

	/**
	 * nread: number of chars read from stdin
	 * ext: to compare if the user typed exit to terminate their session
	 * cnt: to count the number of calls to the shell
	 */

	do {
		if (term)
			write(STDOUT_FILENO, "~$ ", 3);
		/* to print the prompt */
		nread = getline(&prompt, &n, stdin); /* getting the input */
		ext = strncmp(prompt, "exit", 4);
		env = strncmp(prompt, "env", 3);
		/* reading the first 4 chars if it matches with exit */
		_strtok(prompt, getlin, " \t\n\r\a");
		/**
		get_token = strtok(prompt, " \t\n\r\a");
		* stripping the user input for the program path/name *

		for (i = 0; get_token != NULL; i++)
		{
		* stripping and saving the program and its arguments *
			getlin[i] = strdup(get_token);
			get_token = strtok(NULL, " \n\t\r\a");
		}
		getlin[i] = NULL; * NULL-terminating the array */
		if (env == 0)
		{
			envfunc();
			break;
		}
		if (ext == 0)
			exitfunc(getlin[1]);
		/* exiting if the user typed exit */
		if (getlin[0][0] != '/')
			findexec(environ, getlin);
		cmd_avaibl = access(getlin[0], X_OK);
		if (!cmd_avaibl)
		{
			p = fork();
		/*creating the child process to handle the arguments*/
			if (p == 0)
			{
				cnt++;
			/* if successful, execute the user's commands */
				execve(getlin[0], getlin, environ);
				sleep(1);
			/* sleep for a second as the OS executes */
			}
			if (p != -1)
				wait(NULL);
			/* wait till the child process terminates*/
		}
		else
		{
		/* if fork returns an error(-1), handle errors */
			cnt++;
			prompt[nread - 1] = '\0';
			printf("hsh: %i: %s: not found\n", cnt, getlin[0]);
		}
		while (getlin[i] != NULL)
			free(getlin[i]);
		free(prompt);
	} while (term);
	/**
	 * As long as its a terminal, this program will always
	 * prompt a user to enter a command
	 */
	return (nread); /* return the number of chars read */
}
