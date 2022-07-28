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
	buff_count = strlen(buffer);
	if (buff_count == EOF) /*Control D*/
		break;
	buffer = strtok(buffer, "\n");
	arguments = buff_to_array(buffer, 32);
	child_pid = fork();
	if (child_pid == -1)
		perror("Error");
	else if (child_pid == 0)
	{
		if (buffer[0] != '/') /* When the user doesnt specify a programs path */
			arguments = search_path(buffer, _getenv("PATH"));
		/* When the user does specify a programs path */
			if (execve(arguments[0], arguments, NULL) == -1)
				perror("Error");
		printf("Despues de execve\n");
	}
	else
		wait(&status);


	printf("total chars: %li\n", buff_count);

	free(arguments);
	}
	free(buffer);
	return (0);
}
