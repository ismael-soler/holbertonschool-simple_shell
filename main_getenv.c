#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*
 * main - getenv
 */

int main()
{
	char *genv = NULL;

	genv = _getenv("PATH");
	printf("%s", genv);
	printf("\n");
	return (0);
}
