#include "main.h"

/**
  * execute - passes a string to execve sys call
  * @c: pointer to string to be executed
  * Return: whatever execve returned
  */
int execute(char *c, char **envp)
{

	int exec_value;
	char **args_list = split_args(c);
	
	//check for built-ins 
	is_builtin(args_list[0]); //this is just a proof of concept function isn't implimented yet

	exec_value = execve((args_list[0]), args_list, envp);
	if (exec_value == -1)
		printf("./shell : No such file or directory\n");

	exit(-1);

	return (exec_value); /*just in case the kernel cought in fire*/
}
