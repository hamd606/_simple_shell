#include "main.h"

int is_builtin(char *prog)
{
    //impliment builtins like env and pwd
    //this function isn't finished yet
    char *pwd = "pwd";

    if (strcmp(pwd, prog) == 0)
	{
		exit(-1);
	}


    else
        return (0);
}
