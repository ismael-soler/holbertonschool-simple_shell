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
	char *blank[] = {"blank"};
	char **blank_id = blank;

	array_arg = buff_to_array(buffer, " \n\t");
	if (array_arg[0] != NULL)
	{
		if (strchr(array_arg[0], 47))
		{
			if (stat(array_arg[0], &st) == 0)
				return (array_arg);
			else
			{
				free_array(array_arg);
				return (NULL);
			}
		}
		array_arg[0] = fix_dir(array_arg[0]);
		if (stat(array_arg[0], &st) == 0)
			return (array_arg);
		else
		{
			free_array(array_arg);
			return (NULL);
		}
	}
	free(array_arg);
	return (blank_id);
}
