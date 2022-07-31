#include "main.h"
/**
 * env_built_in - prints the current environment
 * @arguments: array with argumentes entered by input
 */
void env_built_in(char **arguments)
{
	int i = 0, j = 0;

	if (arguments[1] == NULL && (strcmp(arguments[0], "env") == 0))
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return;
	}
}
