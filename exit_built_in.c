#include "main.h"
/*
 * exit_built_in - implementation of exit
 * @arguments: pointer to arguments entered by input
 * Return: 0
 */
void exit_built_in(char **arguments)
{
	if (strcmp(argument[0] == "exit") == 0)
	{
		free(buffer);//Libero el malloc de getline
		exit(0);
	}
	return;
}

