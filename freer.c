#include "main.h"

/**
 * freer - a function that frees the buffers
 * buff - the buffer to free
 *
 * Return: always 0 or -1 on error
 */

int freer(char **buff)
{
	int i = 0;
	char **buf = buff;

	buff = NULL;
	if (buf == NULL || !buf)
		return (-1);
	for (i = 0; buf[i]; i++)
		free(buf[i]);
	free(buf);
	return (0);
}
