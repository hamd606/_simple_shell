#include "main.h"

int execute(char *c)
{
	
	int return_value;    
	char **args_list = split_args(c);
	char *envp[] = {NULL};


	return_value = execve(args_list[0], args_list, envp);
	if (return_value == -1)
		printf("./shell : No such file or directory\n");

	exit(-1);
	
}
