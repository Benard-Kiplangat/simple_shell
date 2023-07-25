#include "main.h"
/**
 * cdfunc - a function to find the right executable file path
 * @getlin: to hold the paths
 * @cnt: command counter
 * Return: 0 when successful and -1 on error
 */
int cdfunc(char **getlin, int *cnt)
{
	int i = 0;
	char nwd[150];
	char *homepath, *cderr = "sh: cd: too many arguments\n";

	for (i = 0; getlin[i] != NULL; i++)
	{
		if (i >= 2)
		{
			write(STDERR_FILENO, cderr, 27);
			return (-1);
		}
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(environ[i], "HOME", 4))
			break;
	}
	homepath = strdup(environ[i] + 5);
	if (getlin[1] == NULL || getlin[1][0] == '~')
		getlin[1] = strdup(homepath);
	if (!strncmp(getlin[1], "-", 1))
	{
		write(STDOUT_FILENO, homepath, strlen(homepath));
		write(STDOUT_FILENO, "\n", 1);
	}
	else if (chdir(getlin[1]) == -1)
	{
		*cnt = *cnt + 1;
		errmsg(getlin, cnt);
		return (-1);
	}
	getcwd(nwd, 150);
	if (nwd == NULL)
		return (-1);
	setenvfunc("PWD", nwd, 1);
	return (0);
}
