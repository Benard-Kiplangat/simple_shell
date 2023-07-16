#include "main.h"

/**
 * envfunc  - a function that prints the current environment
 *
 * Returns: nothing
 */

void envfunc(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
