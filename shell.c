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
	size_t buff_size = 0;
	ssize_t buff_count = 0;
	char *buffer = NULL;
	int child_pid, status;
	(void)ac;
	(void)av;
	(void)env;

	while (1)
	{
	printf("$ ");
	buff_count = getline(&buffer, &buff_size, stdin);
	if (buff_count == EOF) /*Control D*/
		break;
	if (buffer[0] == '\n')
		continue;
	buffer = strtok(buffer, "\n");
	child_pid = fork();
	if (child_pid == -1)
		perror("Error");
		exit(1); //Exit failure es 1
	else if (child_pid == 0)
	{	arguments = build_path(buffer);//La funcion afuera funciona,aca no
		env_built_in(arguments);
		if (execve(arguments[0], arguments, NULL) == -1)
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
