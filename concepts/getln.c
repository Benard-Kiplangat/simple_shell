#include "../main.h"

/**
 * main - implimentation of getline function
 * argc - the number of arguments suplied from the command line
 * argv - an array of arguments supplied to the program
 *
 * Return: 0 on success
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (read(stream, *lineptr, *n));
}
