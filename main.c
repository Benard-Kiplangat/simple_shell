#include "main.h"

/**
 * main - the shell
 * argc - the number of arguments suplied from the command line
 * argv - an array of arguments supplied to the program
 *
 * Return: 0 on success, -1 on failure
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	char prompt[300];
	int ext, ech, cnt = 0;

	do
	{
		write(STDOUT_FILENO, "~$ ", 3);
		scanf("%s", prompt);
		ext = strncmp(prompt, "exit", 4);
		ech = strncmp(prompt, "echo", 4);

		if (ech == 0 || ext == 0)
		{
			printf("%s", prompt + 4);
			if (ech == 0)
				printf("\n");
		}
		else
		{
			cnt++;
			printf("hsh: %i : %s command not found\n", cnt, prompt);
		}
	}
	while (isatty(STDIN_FILENO) && ext);
	return (0);
}
