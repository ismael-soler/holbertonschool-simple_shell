#include "main.h"
/**
 * fix_dir - complete the route
 * @argument: - input
 * Return: pointer to string
 */
char *fix_dir(char *argument)
{
	int i = 0, path_size = 0;
	char **array_dir = NULL;
	char *aux = NULL, *path = NULL;
	struct stat st;
	
	path = _getenv("PATH");
	array_dir = buff_to_array(path, ":");
	/*free(path);*/
	for (i = 0; array_dir[i + 1]; i++)
	{
		path_size = (strlen(array_dir[i]) + strlen(argument) + 2);
		aux = malloc(sizeof(char) * path_size);
		if (aux == NULL)
			return (NULL);
		strcpy(aux, array_dir[i]);
		strcat(aux, "/");
		strcat(aux, argument);
		if (stat(aux, &st) == 0)
			break;
		free(aux);
	}
	free(array_dir);
	if (aux)
	{
		argument = malloc(strlen(aux) * sizeof(char));
		strcpy(argument, aux);
		free(aux);
	}
	return (argument);
}
