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
	char *token1 = NULL, *token2 = NULL, *token3 = NULL;

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
			var = strdup(environ[i]);
			break;
		}
	}
	if (environ[i] == NULL)
		return (NULL);

	token1 = strtok(var, "=");
	token2 = strdup(token1);
	token1 = strtok(NULL, "=");
	if (token1)
		token3 = strdup(token1);
	free(var);
	free(token2);
	return (token3);
}
