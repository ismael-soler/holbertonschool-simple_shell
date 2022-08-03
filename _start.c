#include "main.h"
/**
 * _start_ - check mode, generate prompt, Ctrl D and buffer with arguments
 * Return: Buffer string with arguments
 */

char *_start_(void)
{
	char *buffer = NULL;
	size_t buffsize = 0;

	/*Evaluo modo interactivo*/
	if (isatty(0) == 1) /*0 el fd de stdin vale 0*/
		printf("$ ");
	if (getline(&buffer, &buffsize, stdin) == -1)
	{
		free(buffer);
		exit(0);
	}
	if (buffer[0] == '\n')
	{
		free(buffer);
		return (NULL);
	}
	buffer = strtok(buffer, "\n");
	if (strncmp(buffer, "exit", 5) == 0)
	{
		free(buffer);
		exit(0);
	}
	return (buffer);
}
