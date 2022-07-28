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
	int i, argument_count = 2;
	char *aux = NULL;
	struct stat st;

	array_dir = buff_to_array(path, ':');
	if (buffer != NULL)
		for (i = 0; buffer[i]; i++)
			if (buffer[i] == ' ')
				argument_count++;

	array_arg = buff_to_array(buffer, ' ');

	for (i = 0; array_dir[i]; i++)
	{
		aux = strcpy(aux, array_dir[i]);
		aux = strcat(aux, "/");
		aux = strcat(aux, array_arg[0]);
		if (stat(aux, &st) == 0)
			break;
	}
	array_arg[0] = strcpy(array_arg[0], aux);
	printf("%s\n", array_arg[0]);
	return (array_arg);
}
