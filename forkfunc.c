#include "main.h"
/**
 * forkfunc - the fork function
 *
 * @getlin: the command container
 * @environ: the environment
 * @cnt: the command counter
 *
 * Return: nothing
 */

void forkfunc(char **getlin, char **environ, int *cnt)
{
	pid_t p; /* for the new child process to execute programs */

	if (!access(getlin[0], X_OK))
	{
		*cnt = *cnt + 1;
		p = fork();
		if (p == 0)
		{
			execve(getlin[0], getlin, environ);
			sleep(1);
		}
		if (p != -1)
			wait(NULL);
	}
	else
	{
		*cnt = *cnt + 1;
		errmsg(getlin, cnt);
	}
}
