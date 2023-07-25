#include "main.h"

/**
 * findexec - a function to find the right executable file path
 *
 * @environ: variable to extract the right path from the $PATH variable
 * @get_token: temporary tokens
 * @path: temporary paths
 * @getlin: to hold the paths
 *
 * Return: 1 if an excecutable is found and 0 if not found
 */

int findexec(char **environ, char *get_token, char **path, char **getlin)
{
	int i;
	char *paths;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(environ[i], "PATH", 4))
		{
			/*_strtok(environ[i] + 5, get_token, path, ":");*/
			break;
		}
	}
	paths = strdup(environ[i] + 5);

	_strtok(paths, get_token, path, ":");

	for (i = 0; path[i] != NULL; i++)
	{
		strcat(path[i], "/");
		strcat(path[i], getlin[0]);
		if (!access(path[i], X_OK))
		{
			getlin[0] = strdup(path[i]);
			break;
		}
	}
	return (0);
}
