#include "main.h"

/**
  * main - code entry point
  * @argc: number of args to main func
  * @argv: list of args to main function
  * @envp: environment variables passed to main
  *             envp pass is not part of POSIX can be replaced by extern environ var
  * Return: 0 hopefully
  */
int main(int argc, __attribute__((unused))char *argv[], char *envp[])
{
        pid_t parent, pid;
        char *new_buffer;
        (void)argc;

        parent = getpid();
	int is_exit, is_env, is_found;

        while (1)
        {
                new_buffer = read_line(); //previously read_line()
                is_exit = !(strcmp(new_buffer, "exit"));
		is_env = !(strcmp(new_buffer, "env"));
		is_found = !(access(new_buffer, F_OK));

		if (is_found || is_exit || is_env) //remove the one
                {    
                    pid = fork();
                    if (pid == -1) /*checking if fork failed*/
                    {
                            printf("fork failed");
    
                    }
                    else if (pid > 0) /*parent process code*/
                    {
                            int status;
    
                            waitpid(pid, &status, 0); /*waits until child process returns*/
                    }
                    else /*child process code*/
                    {
			    //printf("calling exec\n");
                            execute(new_buffer, envp, parent);
                    }
                }
                
                else
                {
                    printf("./shell : No such file or directory\n");
                }
        }
        
        return (0);
}
