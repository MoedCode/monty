#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **CATA;

size_t Get_Inout(char *filePath)
{
	int status;
	size_t size;
	unsigned int line = 0;
	char *command, **CATA;
	FILE *file = fopen(filePath, "r");
	stack_t *x = NULL;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filePath);
		exit(EXIT_FAILURE);
	}
	while (status != -1)
	{
		line++;
		command  = malloc(1000 * sizeof(char));
		status = getline(&command, &size, file);



		if (!strlen(command))
		{
			FreeVar(command);
			break;
		}
		CATA = Tokenize_in_Arr(command, " \n");
		instructionF(CATA[0], CATA[1], line, &x);
		FreeVar(command);
		FREE_2D_ARR(CATA);

	}
		if (status == -1 )
			fclose(file);

	return (size);

}