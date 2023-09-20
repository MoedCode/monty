#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


size_t Get_Inout(char *filePath)
{
	int status;
	size_t size;
	char *command  = malloc(sizeof(char)), **args;
	FILE *file = fopen(filePath, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filePath);
		exit(EXIT_FAILURE);
	}
	while (status != -1 )
	{
		status = getline(&command, &size, file);
		args = Tokenize_in_Arr(command, " \n");
		Print_2D_Arr(args, 0);
		FreeVar(command);
		FREE_2D_ARR(args);

	}
	return (size);

}