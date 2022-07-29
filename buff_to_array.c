#include "main.h"

/**
 * buff_to_array - inserts a buffer into an array separated by a separator
 * @string: string
 * @delimitator: delimitator
 * Return: pointer to an array
 */

char **buff_to_array(char *string, char delimitator)
{
	char **array = NULL;
	int i, k;
	int argument_count = 2;
	char *token;
	char delim[1];

	delim[0] = delimitator;
	if (string != NULL)
		for (i = 0; string[i]; i++)
			if (string[i] == delimitator)
				argument_count++;

	array = malloc(argument_count * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (string == NULL)
		return (NULL);

	token = strtok(string, delim);
	for (k = 0; k < argument_count - 1; k++)
	{
		array[k] = token;
		token = strtok(NULL, delim);
	}
	array[k] = NULL;
	return (array);
}
