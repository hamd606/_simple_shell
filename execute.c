#include "main.h"

/**
  * execute - passes a string to execve sys call
  * @c: pointer to string to be executed
  * Return: whatever execve returned
  */
int execute(char *c)
{

	int exec_value;
	char **args_list = split_args(c);
	char *envp[] = {NULL};


	exec_value = execve((args_list[0]), args_list, envp);
	if (exec_value == -1)
		printf("./shell : No such file or directory\n");

	exit(-1);

	return (exec_value); /*just in case the kernel cought in fire*/
}
