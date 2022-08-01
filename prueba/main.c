#include "main.h"

int main(void)
{
	struct stat st;

	if (stat("/bin/ls -l", &st) == 0)
		printf("se encontro");
	else
		printf("no se encontro");

	return (0);
}
