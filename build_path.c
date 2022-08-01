#include "main.h"
/*
 * build_path - insert the path to command entered by input
 * @buffer: string with commands
 * Return: pointer to array with arguments
 */
char **build_path(char *buffer)
{
	char **array_dir = NULL, **array_arg = NULL;
	int i, path_size = 0;
	char *aux;
	struct stat st;

	array_dir = buff_to_array(_getenv("PATH"), ":");
	if (buffer[0] == '/')
	{
		array_arg = buff_to_array(buffer, " \n\t");
		return (array_arg);
	}
	array_arg = buff_to_array(buffer, " \n\t");
	for (i = 0; array_dir; i++)
	{
		path_size = (strlen(array_dir[i]) + strlen(array_arg[0]) + 2);
		aux = malloc(sizeof(char) * path_size);
		if (aux == NULL)
			return (NULL);
		strcpy(aux, array_dir[i]);
		strcat(aux, "/");
		strcat(aux, array_arg[0]);
		if (stat(aux, &st) == 0)
			break;
		if (stat(aux, &st) == '1')
			perror("Error de stat:");
		free(aux);
	}
	if (aux)
	{
		array_arg[0] = malloc(strlen(aux) * sizeof(char));
		strcpy(array_arg[0], aux);
		free(aux);
	}
	return (array_arg);
}
