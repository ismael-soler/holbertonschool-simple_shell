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
	char *token;

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
	if (string == NULL)
		return (NULL);

	token = strtok(string, delimitators);
	for (k = 0; k < argument_count - 1; k++)
	{
		array[k] = token;
		token = strtok(NULL, delimitators);
	}
	array[k] = NULL;
	return (array);
}
