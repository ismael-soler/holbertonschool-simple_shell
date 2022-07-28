#include "main.h"

/**
 * _getenv - gets an environemnt variable
 * @name: name of variable
 * Return: string with name
 */

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0, j = 0, c_len;
	char *var ;

	c_len = strlen(name);
	if (name == NULL)
	{
		printf("Error\n");
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, c_len) == 0)
			var = environ[i];
	}
	return (var);
}
