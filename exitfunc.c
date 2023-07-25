#include "main.h"

/**
 *  exitfunc - a function to exit the shell
 *
 * @status: a pointer to the exit status provided by the user
 *
 * Return: nothing
 */

void exitfunc(int status)
{
	exit(status); /* exiting if the user typed exit */
}
