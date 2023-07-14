#include <stdio.h>

/**
 * main - a function that work with commandline arguments
 * argc: the number of arguments passed to main
 * argv: the array of arguments passed as strings
 *
 * Return: Always 0
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	int i = 1;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
