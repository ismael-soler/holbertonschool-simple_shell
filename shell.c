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
		buffer = _start_(); /*Chequeo el modo interactivo, control D y getline*/
		if (!buffer)
			return (0);
		if (buffer[0] == '\n')
			continue;
		buffer = strtok(buffer, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			exit(1); /*Exit failure es 1*/
		}
		else if (child_pid == 0)
		{
			arguments = build_path(buffer);
			exit_built_in(arguments);
			env_built_in(arguments);
			if (execve(arguments[0], arguments, environ) == -1)
			{
				perror("Error");
				exit(-1);
			}
		}
		else
			wait(&status);
		free(arguments);
	}
	free(buffer);
	return (0);
}
