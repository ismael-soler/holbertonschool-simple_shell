#include "main.h"
/*
 * search_path - insert path
 * @buffer: string with commands
 * @path: string with path
 * Return: pointer to array;
 */
char **search_path(char *buffer, char *path)
{
	char **array_dir = NULL, **array_arg = NULL;
	int i, argument_count = 2, size_path = 0;
	char *aux;
	struct stat st;

	array_dir = buff_to_array(path, ':');
	if (buffer[0] == '/')
	{
		array_arg = buff_to_array(buffer, ' ');
		return (array_arg);
	}
	array_arg = buff_to_array(buffer, ' ');
	for (i = 0; array_arg[i]; i++)
		printf("%s\n", array_arg[i]);
	for (i = 0; array_dir; i++)
	{
		size_path = (strlen(array_dir[i]) + strlen(array_arg[0]) + 1);
		aux = malloc(sizeof(char) * size_path);
		if (aux == NULL)
			return (NULL);
		strcpy(aux, array_dir[i]);
		strcat(aux, "/");
		strcat(aux, array_arg[0]);
		if (stat(aux, &st) == 0)
			break;
	}
	strcpy(array_arg[0], aux);
	return (array_arg);
}
