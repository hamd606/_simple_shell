#include "main.h"

char *read_read_line()
{
	char *buffer = malloc(sizeof(char *));
	size_t bufsize = 1024;
	char *new_buffer = malloc(sizeof(char *));

	if (buffer == NULL || new_buffer == NULL)
	{
		perror("malloc() failed : Unable to allocate buffer\n");
		free(buffer);
		free(new_buffer);
		exit(-1);
	}

	printf("$ ");
	if (read(0, buffer, 1024) < 1)
	{
		printf("read returned -1\n");
		/*end of file encountred*/
		free(buffer);
		free(new_buffer);
		exit(0);
	}

	new_buffer = allocate_string(buffer);

	printf("return of read_read_line : %s\n", new_buffer);

	return (new_buffer);
}
