#include "main.h"

/**
 *  exitfunc - a function to exit the shell
 * @status: a pointer to the exit status provided by the user
 *
 * Return: nothing 
 */

void exitfunc(char *status)
{
	int intstatus = 0;
	if (status)
		intstatus = atoi(status);
	free(status);
	exit(intstatus); /* exiting if the user typed exit */
}
