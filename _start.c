#include "main.h"
/**
 * _start_ - check mode, generate prompt, Ctrl D and buffer with arguments
 * @flag: flag
 * Return: Buffer string with arguments
 */

char *_start_(int flag)
{
	char *buffer = NULL;
	size_t buffsize = 0;
	int i;

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

	for (i = 0; buffer[i]; i++) /* recorre la string en busca de ' ' o '\t'*/
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			break;
	}
	if (buffer[i] == '\0') /*significa que recorrio hasta el final*/
	{
		free(buffer);
		return (NULL);
	}
	if (strstr(buffer, "exit"))
	{
		free(buffer);
		exit(flag);
	}
	return (buffer);
}
