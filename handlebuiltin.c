#include "main.h"
/**
 * handlebuiltin - a function to handle builtins
 * @getlin: array of inputs
 * @cnt: counter
 * @env: environment builtin
 * @cdf: cd builtin
 */

void handlebuiltin(char **getlin, int *cnt, int env, int cdf)
{
	if (env == 0)
		envfunc();
	if (cdf == 0)
		cdfunc(getlin, cnt);
}
