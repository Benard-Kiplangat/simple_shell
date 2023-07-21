#include "main.h"

/**
 *  exitfunc - a function to exit the shell
 *
 * @status: a pointer to the exit status provided by the user
 * @prompt: holding our script
 * @get_token: get toks pointer to free
 *
 * Return: nothing
 */

void exitfunc(char *status, char *prompt, char *get_token)
{
	int intstatus = 0;

	if (status)
		intstatus = atoi(status);
	free(prompt);
	free(get_token);
	free(status);
	exit(intstatus); /* exiting if the user typed exit */
}
