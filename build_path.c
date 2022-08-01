#include "main.h"
/**
 * build_path - insert the path to command entered by input
 * @buffer: string with commands
 * Return: pointer to array with arguments
 */
char **build_path(char *buffer)
{
	char **array_dir = NULL, **array_arg = NULL;
	int i, path_size = 0;
	char *aux = NULL;
	struct stat st;
	int flag = 0;

	array_dir = buff_to_array(_getenv("PATH"), ":");
	if (buffer[0] == '/')
	{
		array_arg = buff_to_array(buffer, " \n\t");
		return (array_arg);
	}
	array_arg = buff_to_array(buffer, " \n\t");
	for (i = 0; i < 7; i++)
	{
		path_size = (strlen(array_dir[i]) + strlen(array_arg[0]) + 2);
		aux = malloc(sizeof(char) * path_size);
		if (aux == NULL)
			return (NULL);
		strcpy(aux, array_dir[i]);
		strcat(aux, "/");
		strcat(aux, array_arg[0]);
		printf("%s\n", aux);
		if (stat(aux, &st) == 0)
		{
			flag = 1;
			break;
		}
		free(aux);
	}
	free(array_dir);
	if (flag == 1)
	{
		/*array_arg[0] = malloc(strlen(aux) * sizeof(char));*/
		strcpy(array_arg[0], aux);
		free(aux);
	}
	else if (flag == 0)
	{
		perror("Command doesn't exist");
		return (NULL);
	}
	return (array_arg);
}
