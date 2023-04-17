#include "main.h"

int execute(char * c) {
	
    int return_value;
    char* arg_list[] = { "myprog", NULL };
    char * envp[1];

    return_value = execve(c, arg_list, envp);

    if (return_value == -1)
        printf("./shell : No such file or directory\n");

    exit(-1);
}
