#include "main.h"

/**
 *  exitfunc - a function to exit the shell
 *
 * @status: a pointer to the exit status provided by the user
 * @tok: get_token pointer to freeing
 * @lin: getlin pointer to freeing
 * @path: path pointer to freeing
 * @prompt: prompt pointer for freeing
 *
 * Return: nothing
 */

void exitfunc(char *tok, char **lin, char **path, char *prompt, int status)
{
	free(tok);
	freer(lin);
	freer(path);
	free(prompt);
	exit(status); /* exiting if the user typed exit */
}
