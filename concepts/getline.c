#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - a function that reads an entire line from stdin 
 * argc: the number of arguments passed to main
 * argv: the array of arguments passed as strings
 *
 * Return: Always 0
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	size_t n = 0;
	ssize_t linesize = 0;
	char *line = malloc(sizeof(char) * 100);

	do
	{
		printf("$ ");
		linesize = getline(&line, &n, stdin);
		printf("Linesize = %lu\n", linesize);
	}
	while (strncmp("exit", line, 4));
	free(line);
	return (0);
}
