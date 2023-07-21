#include "main.h"
/**
 * main - the shell
 * @argc: the number of arguments suplied from the command line
 * @argv: an array of arguments supplied to the program
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{
	char *getlin[100];
	char *path = strdup("./");
	int readch = 0, i = 1;

	if (argc > 1)
	{
		while (i < argc)
		{
			if (argv[i][0] != '.' || argv[i][0] != '/')
				path = strcat(path, argv[i]);
			else
				path = strdup(argv[i]);

			i = i + 1;
			printf("path: %s\n", path);
			if (!access(path, R_OK))
			{
				printf("ok");
				runshfile(path, getlin);
			}
			else
			{
				write(STDOUT_FILENO, "Can't read echo", 17);
			}
			i++;
		}
	}
	else
		readch += loop(getlin);

	return (readch);
}
