#include "main.h"
/**
 * built_in - implement de corresponding built in
 * @arguments: pointer to array with user inputs
 */

int built_in(char *buffer, char **buff)
{
	int i = 0;

	if (strcmp(buffer, "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		printf("Despues del for de env\n");
		return (1);
	}
	if (strcmp(buffer, "exit") == 0)
	{
		printf("Estoy adentro del if de exit\n");
		free(buff);
		exit(0);
	}
}
