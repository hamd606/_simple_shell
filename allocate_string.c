#include "main.h"

char *allocate_string(char *c)
{
	int len = strlen(c);

	int i = 0;

	char *tmp = malloc(len - 1);

	while (c[i])
	{
		tmp[i] = c[i];
		i++;
	}

	tmp[i - 1] = '\0';

	return (tmp);
}
