#include "main.h"

/**
 * main - Runs a Shell program
 * @ac: arguemnt count
 * @av: argument value
 * @env: enviroment values
 * Return: exit status
 */

int main(int ac, char **av, char **env)
{
	char **arguments = NULL;
	char *buffer = NULL;
	int child_pid, status = 0, exit_value = 0;
	(void)ac;

	while (1)
	{
		buffer = _start_(exit_value); /*Modo interactivo, control D, exit y getline*/
		if (buffer == NULL)
			continue;
		if (check_input(buffer) == 1)
			continue;
		arguments = check_command(buffer, av[0]);
		if (arguments == NULL)
		{
			exit_value = 127;
			if (isatty(0) == 0)
				exit(exit_value);
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
			execve(arguments[0], arguments, env);
		}
		else
		{
			wait(&status);
			exit_value = WEXITSTATUS(status);
		}
		if (arguments)
			free_array(arguments);
	}
	return (exit_value);
}
