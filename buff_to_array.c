#include "main.h"

/**
 * buff_to_array - inserts a buffer into an array separated by a separator
 * @string: string
 * @delimitators: delimitator
 * Return: pointer to an array
 */

char **buff_to_array(char *string, char *delimitators)
{
	char **array = NULL;
	int i, k, j;
	int argument_count = 2;
	char *token, *aux_string = NULL;

	if (string != NULL)
		for (i = 0; string[i]; i++)
			for (j = 0; delimitators[j]; j++)
			{
				if (string[i] == delimitators[j])
					argument_count++;
			}

	array = malloc(argument_count * sizeof(char *));
	if (array == NULL)
		return (NULL);
	aux_string = strdup(string);
	free(string);
	token = strtok(aux_string, delimitators);
	for (k = 0; k < argument_count - 1; k++)
	{
		if (token == NULL)
			break;
		array[k] = strdup(token);
		token = strtok(NULL, delimitators);
	}
	array[k] = NULL;
	free(aux_string);
	return (array);
}
