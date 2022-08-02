#include "main.h"

/**
 * free_array - frees all memory in an array of strings
 * @array: array
 * Return: 0 un succcess
 */

int free_array(char **array)
{
	int i = 0;

	for (i = 0; array[i]; i++)
		;
	for (; i >= 0; i--)
	{
		free(array[i]);
	}
	free(array);
	return (0);
}
