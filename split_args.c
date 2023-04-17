#include "main.h"

char **split_args(char *input_str) {

	int index = 0;

	char *tok;

	char *dup;
	
	char **args_list = NULL;  //pointer to list of dynamically created list od char aka string (list of strings)
	
	char *argument = malloc(strlen(input_str) + 1); //one string entry in args_list

	strcpy(argument, input_str);

	tok = strtok(argument, " "); //initial call for strtok

	while(tok!=NULL) {

		args_list = realloc(args_list, sizeof(char*) * (index + 1));
		
		dup = malloc(strlen(tok) + 1);
		
		strcpy(dup, tok);
		
		args_list[index++] = dup;
		
		tok = strtok(NULL, " ");
	}
	// Need space to store the "terminating" NULL
	args_list = realloc(args_list, sizeof(char*)*(index+1));
	args_list[index] = NULL;
	
	free(argument);
	
	return args_list;
}
