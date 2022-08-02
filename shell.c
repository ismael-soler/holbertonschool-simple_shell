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
			perror(av[0]);
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
			if (execve(arguments[0], arguments, env) == -1)
			{
				perror("err00r");
				exit(-1);	
			}
		}
		else
		{
			wait(&status);
			free_array(arguments);
		}
	}
	return (0);
}
