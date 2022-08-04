#include "main.h"
/**
 * check_command - insert the path to command entered by input
 * @buffer: string with commands
 * Return: pointer to array with arguments
 */
char **check_command(char *buffer)
{
	char **array_arg = NULL;
	struct stat st;

	array_arg = buff_to_array(buffer, " \n\t");
	if (array_arg[0] != NULL)
	{
		if (strchr(array_arg[0], 47)) /*chequea si contiene un path*/
		{
			if (stat(array_arg[0], &st) == 0)
				return (array_arg);
			free_array(array_arg);
			return (NULL);
		}
		array_arg[0] = fix_dir(array_arg[0]); /*se ejecuta cuando no contiene un path*/
		if (array_arg[0])
		{
		if (stat(array_arg[0], &st) == 0)
			return (array_arg);
		free_array(array_arg);
		}
		return (NULL);
	}
	free(array_arg);
	return (NULL);
}
