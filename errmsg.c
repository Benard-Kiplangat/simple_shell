#include "main.h"

/**
 * errmsg - a function that prints error messages
 *
 * @cnt: the number of prints to the terminal
 * @getlin: the array of the commands
 *
 * Return: nothing
 */

void errmsg(char **getlin, int *cnt)
{
	char snum[5];
	char *buff;
	int num, i, rem, len = 0, n;

	buff = calloc(sizeof(char), 1024);
	num = *cnt;
	n = *cnt;

	while (n != 0)
	{
		len++;
		n /= 10;
	}

	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		snum[len - (i + 1)] = rem + '0';
	}

	snum[len] = ':';
	snum[len + 1] = ' ';
	snum[len + 2] = '\0';

	strcat(buff, "hsh: ");
	strcat(buff, snum);
	strcat(buff, getlin[0]);

	if (!strncmp(getlin[0], "cd", 2))
	{
		strcat(buff, ": can't cd into ");
		strcat(buff, getlin[1]);
		strcat(buff, "\n");
	}
	else
		strcat(buff, ": not found\n");
	write(STDERR_FILENO, buff, strlen(buff));
	free(buff);
}
