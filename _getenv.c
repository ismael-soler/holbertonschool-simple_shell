#include "main.h"

/**
 * _getenv - gets an environemnt variable
 * @name: name of variable
 * Return: string with name
 */

char *_getenv(const char *name)
{
	int i = 0, c_len;
	char *var = NULL;

	c_len = strlen(name);
	if (name == NULL)
	{
		printf("Error\n");
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, c_len) == 0)
		{
			var = malloc(strlen(environ[i] + 1));
			if (var == NULL)
				return (NULL);
			strcpy(var, environ[i]);
			break;
		}
	}
	var = strtok(var, "=");
	var = strtok(NULL, "=");
	printf("var = %s\n", var);
	return (var);
}
