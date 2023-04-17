#include "main.h"

/**
  * main - code entry point
  * Return: 0 hopefully
  */
int main(void)
{
	char *buffer;
	size_t bufsize = 512;
	pid_t pid;
	char *new_buffer = malloc(sizeof(char *));

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("malloc() failed : Unable to allocate buffer\n");
		exit(1);
	}
	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			free(buffer);
			free(new_buffer);
			exit(-1);
		}
		new_buffer = allocate_string(buffer);
		pid = fork();

		if (pid == -1) /*checking if fork failed*/
		{
			printf("fork failed\n");
		}
		else if (pid > 0) /*parent process code*/
		{
			int status;

			waitpid(pid, &status, 0); /*waits until child process returns*/
		}
		else /*child process code*/
		{
			execute(new_buffer);
		}
	}
	return (0);
}
