#include "main.h"
/**
 * main - the shell
 * @argc: the number of arguments suplied from the command line
 * @argv: an array of arguments supplied to the program
 * Return: 0 on success, -1 on failure
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	int cnt = 0;
	/*char *opnerr = malloc(sizeof(char) * 35);
	char *path = _strdup("./");
	int readch = 0;

	opnerr[0] = '\0';

	strcat(opnerr, "sh: 0: can't open ");

	if (argc > 1)
	{
		if (argv[1][0] != '.' || argv[1][0] != '/')
			strcat(path, argv[1]);
		else
			path = _strdup(argv[1]);

		if (!access(path, R_OK))
		{
			free(opnerr);
			runshfile(path, getlin, &cnt);
		}
		else
		{
			strcat(opnerr, argv[1]);
			strcat(opnerr, "\n");
			write(STDERR_FILENO, opnerr, 35);
			opnerr[0] = '\0';
			free(opnerr);
			free(path);
		}
	}
	else
	*/
	cnt += loop(&cnt);
	return (cnt);
}
