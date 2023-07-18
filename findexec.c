#include "main.h"

/**
 * findexec - a function to find the right executable file path
 *
 * @environ: variable to extract the right path from the $PATH variable
 *
 * Return: 1 if an excecutable is found and 0 if not found
 */

int findexec(char **environ, char **getlin)
{
	int i;
	char *path[10];

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(environ[i], "PATH", 4))
		{
			_strtok(environ[i] + 5, path, ":\n");
			break;
		}
	}
	for (i = 0; path[i] != NULL; i++)
	{
		strcat(path[i], "/");
		strcat(path[i], getlin[0]);
		if (!access(path[i], X_OK))
		{
			getlin[0] = strdup(path[i]);
		}
	}
	for (i = 0; path[i] != NULL; i++)
		free(path[i];
	return (0);
}
