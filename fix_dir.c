#include "main.h"

/**
 * fix_dir - complete the route
 * @string: input
 * @av: value
 * Return: pointer to string
 */

char *fix_dir(char **string, char *av)
{
	int i = 0, path_size = 0;
	char **array_dir = NULL;
	char *aux = NULL, *path = NULL;
	struct stat st;

	path = _getenv("PATH=");
	if (path)
	{
		array_dir = buff_to_array(path, ":");
		for (i = 0; array_dir[i]; i++) /*sustituye con cada PATH y el comando*/
		{
			if (aux)
				free(aux);
			path_size = (strlen(array_dir[i]) + strlen(string[0]) + 2);
			aux = malloc(sizeof(char) * path_size);
			if (aux == NULL)
				return (NULL);
			strcpy(aux, array_dir[i]);
			strcat(aux, "/");
			strcat(aux, string[0]);
			if (stat(aux, &st) == 0)
				break;
		}
		free_array(array_dir);
		if (aux)
		{
			if (stat(aux, &st) == 0)
				free(string[0]); /* liberamos porque vamos a sustituir*/
			else
			{
				free(aux);
				return (string[0]);
			}
		}
		return (aux);
	}
	print_error(av, string[0]);
	free(string[0]);
	string[0] = strdup("flag271103");
	return (string[0]);
}
