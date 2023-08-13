#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * _strtok - implementation of the strtok function
 * @prompt: the pointer to the string read from the stdin
 * @get_token: pointer to hold the tokens temporarily
 * @getlin: the array of tokens
 * @delims: the delimeters to break the string into tokens
 *
 * Return: pointer to getlin or -1 on error
 */

int main(void)
{
	char *getlin[100];
	char *prompt = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char *token = calloc(sizeof(char), 100);
	char *delims = "=: \n";
	int i = 0, j = 0;/* i: iterator */
	int k = 0, c = 0, d = 0;

	if (prompt != NULL)
	{
		for (; prompt[i] != '\0'; i++)
		{
			for (j = 0; delims[j] != '\0'; j++)
			{
				if (prompt[i] == delims[j])
				{
					token[c] = '\0';
					i++;
					c = 0;
					getlin[k] = strdup(token);
					k++;
					d = i;
					break;
				}
			}
			if (prompt[i] == '\0')
			{
				for (i = d, c = 0; prompt[i] != '\0'; i++)
				{
					token[c] = prompt[i];
					getlin[k] = strdup(token);
					c++;
				}
			}
			else
			{
				token[c] = prompt[i];
				c++;
			}
		}
		token[c] = '\0';
		getlin[k] = strdup(token);
		getlin[k + 1] = NULL;
		printf("prompt %s\n", prompt);
		for (j = 0; getlin[j] != NULL; j++)
			printf("tokens: %s\n", getlin[j]);
	}
	return (0);
}
/*
	for (i = 0; prompt[i] != '\0'; i++)
	{
		for (j = 0; delims[j] != '\0'; j++)
		{
			if (prompt[i] == delims[j])
			{
				if (prompt[i + 1] == '\0')
				{
					get_token = strndup(prompt + frm, i - frm);
					getlin[k] = strdup(get_token);
					break;
				}
				to = i;
				get_token = strndup(prompt + frm, to - frm);
				getlin[k] = strdup(get_token);
				to++;
				k++;
				break;
			}
			frm = to;
		}
	}
	if (k == 0 && to == 0 && i > 0)
	{
		getlin[k] = strdup(prompt);
		k++;
	}
	getlin[k] = NULL;
	return (0); * return the number of chars read /
}*/
