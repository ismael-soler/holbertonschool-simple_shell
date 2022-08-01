#include "main.h"
/**
 * check_env - implement de corresponding built in
 * @arguments: pointer to array with user inputs
 */

int check_env(char *buffer)
{
	int i = 0;

	if (strcmp(buffer, "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		printf("Despues del for de env\n");
		return (1);
	}
	return (0);
}
