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
	char **saveptr = calloc(sizeof(char *), 20);
	char *commandpath = calloc(sizeof(char), 150);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(environ[i], "PATH", 4))
			break;
	}
	strcpy(commandpath, environ[i] + 5);
	get_token = strtok_r(commandpath, ":", saveptr);
	for (i = 0; get_token != NULL; i++)
	{
		path[i] = _strdup(get_token);
		get_token = strtok_r(NULL, ":", saveptr);
	}
	getlin[i] = NULL;
	free(commandpath);
	free(get_token);

	for (i = 0; path[i] != NULL; i++)
	{
		strcat(path[i], "/");
		strcat(path[i], getlin[0]);
		if (!access(path[i], F_OK | X_OK))
		{
			free(getlin[0]);
			getlin[0] = _strdup(path[i]);
			break;
		}
	}
	free(saveptr);
	return (0);
}
