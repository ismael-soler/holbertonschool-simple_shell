#include "main.h"

int main(void)
{
	char **directories;
	char *path;

	path = _getenv("PATH");
	directories = buff_to_array(path, 58);

	for(int i = 0; directories[i]; i++)
		printf("%s\n", directories[i]);

	return (0);
}
