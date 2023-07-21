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
	char snum[6];
	int num;
	int i, rem, len = 0, n;

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

	write(STDOUT_FILENO, "hsh: ", 6);
	write(STDOUT_FILENO, snum, 6);
	write(STDOUT_FILENO, getlin[0], strlen(getlin[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
