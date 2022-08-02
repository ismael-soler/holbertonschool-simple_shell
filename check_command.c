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
	printf("arg[0] antes de if en chcommand %s\n", array_arg[0]);
	if (buffer[0] == '/')
	{
		if (stat(array_arg[0], &st) == 0)
			return (array_arg);
		else
		{
			free(array_arg);
			return (NULL);
		}
	}
	printf("arg[0] despues de if en chcommand %s\n", array_arg[0]);
	/*free(buffer);*/
	printf("arg[0] despue de free buffer %s\n", array_arg[0]);
	array_arg[0] = fix_dir(array_arg[0]);
	printf("arg[0] despues de fix dir %s\n", array_arg[0]);
	if (stat(array_arg[0], &st) == 0)
		return (array_arg);
	else
	{
		printf("Despues de evaluar stat\n");
		/*free(array_arg[0]);*/
		/*free(array_arg);*/
		return (NULL);
	}
	return (NULL);
}	
