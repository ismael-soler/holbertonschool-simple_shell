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

	array_dir = buff_to_array(path, ':');
	if (buffer != NULL)
		for (i = 0; buffer[i]; i++)
			if (buffer[i] == 32)
				argument_count++;

	if (buffer[0] == '/')
	{
		array_arg = buff_to_array(buffer, ' ');
		return (array_arg);
	}

	array_arg = buff_to_array(buffer, ' ');
	for (i = 0; array_arg[i]; i++)
		printf("%s\n", array_arg[i]);


	printf("iii%i\n", argument_count);
	printf("%s\n", array_dir[0]);
	printf("final: %s\n", array_arg[0]);
	return (array_arg);
}
