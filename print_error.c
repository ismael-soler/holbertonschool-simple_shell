#include "main.h"

/**
 * print_error - prints error message
 * @av: argument value
 * @command: array_arg[0]
 */

void print_error(char *av, char *command)
{
	write(2, av, strlen(av));
	write(2, ": 1: ", 5);
	write(2, command, strlen(command));
	write(2, ": not found\n", 12);
}
