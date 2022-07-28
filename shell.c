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
	size_t buff_size = 0, buff_count = 0;
	char *buffer = NULL;
	int child_pid, status;
	(void)ac;
	(void)av;
	(void)env;

	printf("$ ");
	buff_count = getline(&buffer, &buff_size, stdin);
	strtok(buffer, "\n");
	buff_count = strlen(buffer);

	printf("%s with %li chars", buffer, buff_count);
	if (child_pid == -1)
		perror("Error");
	if (child_pid == 0)
	{
		if (execve)
	}
	else
	{
		wait(&status);
	}
	return (0);
}
