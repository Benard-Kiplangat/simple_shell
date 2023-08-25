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
	int i, n, j;

	for (i = 0; getlin[i] != NULL; i++)
		;
	if (i >= 2)
	{
		if (!strncmp(getlin[0], getlin[1], 2))
			n = 1;
		if (n == 1)
		{
			for (j = i; j <= 1; j--)
				free(getlin[j]);
			getlin[1] = NULL;
		}
	}
	i--;
	do {
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
		i--;
	} while (i >= 0 && n);
}
