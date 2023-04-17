#include "main.h"

int main() {

    char * buffer;
    size_t bufsize = 512;
    size_t characters;
    int i;

    char * new_buffer = malloc(sizeof(char * ));
    buffer = (char * ) malloc(bufsize * sizeof(char));

    if (buffer == NULL) {
        perror("malloc() failed : Unable to allocate buffer\n");
        exit(1);
    }

    pid_t pid;
    pid_t parent = getpid();

    char * argv[1];
    char * envp[1];

    argv[0] = NULL;
    envp[0] = NULL;

    int exec_return;

    while (1) {
        printf("#cisfun$ ");
        if (getline( & buffer, & bufsize, stdin) == -1) {
            //ctrl-d is pressed

            //printf("getline returned -1\n");
            free(buffer);
            free(new_buffer);
            exit(-1);
        }

        new_buffer = allocate_string(buffer);

        pid = fork();

        if (pid == -1) //checking if fork failed
        {
            printf("fork failed\n");
        } else if (pid > 0) //parent process code
        {
            //we are the parent
            int status;
            waitpid(pid, & status, 0); //waits until child process returns
            if (status == 0) {
                ;
                //printf("child process returned 0 continuing...\n");
                //exit(0);
            }

        } else //child process code
        {
            // we are the child
            exec_return = execute(new_buffer);
        }

    }

    return 0;
}
