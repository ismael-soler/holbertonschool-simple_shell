#include "main.h"

/**
 * fix_dir - complete the route
 * @argument: input
 * @av: argument value
 * Return: pointer to string
 */

char *fix_dir(char *argument, char *av)
{
	int i = 0, path_size = 0;
	char **array_dir = NULL;
	char *aux = NULL, *path = NULL, *argument_aux = NULL;
	struct stat st;

	path = _getenv("PATH=");
	if (path)
	{
		array_dir = buff_to_array(path, ":");
		for (i = 0; array_dir[i + 1]; i++) /*sustituye con cada PATH y el comando*/
		{
			if (aux)
				free(aux);
			path_size = (strlen(array_dir[i]) + strlen(argument) + 2);
			aux = malloc(sizeof(char) * path_size);
			if (aux == NULL)
				return (NULL);
			strcpy(aux, array_dir[i]);
			strcat(aux, "/");
			strcat(aux, argument);
			if (stat(aux, &st) == 0)
				break;
		}
		free_array(array_dir);
		if (aux)
		{
			if (stat(aux, &st) == 0)
			{
				free(argument); /* liberamos porque vamos a sustituir*/
				argument_aux = malloc(strlen(aux) * sizeof(char) + 1);
				strcpy(argument_aux, aux);
				free(aux);
			}
			else
				return (argument);
		}
		return (argument_aux);
	}
	print_error(av, argument);
	return (NULL);
}
