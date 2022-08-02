#include "main.h"

/**
 * main - Runs a Shell program
 * @ac: arguemnt count
 * @av: argument value
 * @env: enviroment values
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	char **arguments = NULL;
	char *buffer = NULL;
	int child_pid, status;
	(void)ac;
	(void)av;
	(void)env;

	while (1)
	{
		buffer = _start_(); /*Chequeo el modo interactivo, control D, exit y getline*/
		if (buffer == NULL)
			continue;
		if (check_input(buffer) == 1)
			continue;
		arguments = check_command(buffer);
		if (arguments == NULL)
		{
			perror("Poner error");
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			exit(1); /*Exit failure es 1*/
		}
		else if (child_pid == 0)
		{
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror("err00r");
				exit(-1);	
			}
		}
		else
		{
			wait(&status);
		}

	free(arguments[0]);
	free(arguments);
	}
	return (0);
}
