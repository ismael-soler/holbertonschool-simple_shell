#include "main.h"
/*
 * exit_built_in - implementation of exit
 * @arguments: pointer to arguments entered by input
 * Return: 0
 */

void exit_built_in(char **arguments)
{
	if (strcmp(arguments[0], "exit") == 0)
	{
		exit(0);
	}
}

