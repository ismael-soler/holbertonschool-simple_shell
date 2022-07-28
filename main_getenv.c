#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*
 * main - getenv
 */

int main()
{
	char *genv = NULL;
	int i;

	genv = _getenv("HOSTNAME");
	printf("%s", genv);
	printf("\n");
	return (0);
}
