
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char **split_args(char *input_str);
char *allocate_string(char *c);
int execute(char *c, char **envp);
int is_builtin(char *prog);

#endif
