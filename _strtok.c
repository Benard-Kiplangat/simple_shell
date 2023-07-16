#include "main.h"

/**
 * _strtok - implementation of the strtok function
 * @prompt: the pointer to the string read from the stdin
 *
 * Return: pointer to getlin or -1 on error
 */

int _strtok(char *prompt, char **toks)
{
	size_t n = 0;
	int i; /* i: iterator */
	char *get_token; /* temporarily store tokens and arguments recieved */
	char *getlin[100]; /* to store tokens after they've been stripped */
	int nread;
	/**
	 * nread: number of chars read from stdin
	 * ext: to compare if the user typed exit to terminate their session
	 * cnt: to count the number of calls to the shell
	 */

	nread = getline(&prompt, &n, stdin); /* getting the input */
	ext = strncmp(prompt, "exit", 4);
	/* reading the first 4 chars if it matches with exit */
	get_token = strtok(prompt, " \t\n\r\a");
	/* stripping the user input for the program path/name */

	for (i = 0; get_token != NULL; i++)
	{
	/* stripping and saving the program and its arguments */
		getlin[i] = strdup(get_token);
		get_token = strtok(NULL, " \n\t\r\a");
	}
	getlin[i] = NULL; /* NULL-terminating the array */
	return (getlin); /* return the number of chars read */
}
