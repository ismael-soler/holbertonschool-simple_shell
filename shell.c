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
		if (buffer[0] == '\n')
			continue;
		printf("antes del strtok");
		buffer = strtok(buffer, "\n");
		printf("Buffer desp de strtok %s\n", buffer);
		if (check_env(buffer) == 1)
			continue;
		printf("antes del build_path\n");
		if ((arguments = build_path(buffer)) == NULL)
		{
			free(arguments);
			continue;
		}
		printf("despues de built in en main\n");
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
				perror("Error");
				exit(-1);
				
			}
			free(arguments[0]);
		}
		else
		{
			wait(&status);
			free(arguments[0]);
		}
	}
	free(buffer);
	return (0);
}
