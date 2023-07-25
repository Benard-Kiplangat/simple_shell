#include "main.h"
/**
 * setenvfunc - a function to find and set environment variables
 * @key: name to add to environ
 * @value: the value to add to environ
 * @status: set status if to overwrite or not
 * Return: 0 when successful and -1 on error
 */
int setenvfunc(char *key, char *value, int status)
{
	int i = 0, j = 0;
	char *currkey = malloc(sizeof(char) * 100);

	if (key == NULL || strlen(key) == 0 || value == NULL)
	{
		write(STDOUT_FILENO, "Name shouldn't be 0 length", 26);
		return (-1);
	}
	for (i = 0; key[i] != '\0'; i++)
	{
		if (key[i] == '=')
		{
			write(STDOUT_FILENO, "Name shouldn't contain =", 29);
			return (-1);
		}
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		strncat(currkey, environ[i], j);
		if (status && !strncmp(environ[i], currkey, strlen(key)))
		{
			environ[i][j] = '\0';
			strcat(environ[i], value);
			currkey[0] = '\0';
			break;
		}
	}
	if (environ[i] == NULL && status)
	{
		environ[i] = malloc(sizeof(key) + sizeof(value) - sizeof(char));
		environ[i] = strdup(key);
		strcat(environ[i], "=");
		strcat(environ[i], value);
		environ[i + 1] = NULL;
	}
	free(currkey);
	return (0);
}
