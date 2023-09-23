#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

n_CATA  NCATA;



size_t Get_Inout(char *filePath)
{
	int status = 0;
	size_t size  = 0;
	char *command = NULL;
	FILE *file = fopen(filePath, "r");
	stack_t *STACK = NULL;
	NCATA.line = 0;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filePath);
		exit(EXIT_FAILURE);
	}
	while (status != -1)
	{


		NCATA.line +=1;
		command  = malloc(1000 * sizeof(char));
		status = getline(&command, NULL, file);

		if (!strlen(command))
		{
			FreeVar(command);
			break;
		}
		NCATA.CATA = Tokenize_in_Arr(command, " $\n");
		instructionF( &STACK);
		FreeVar(command);
		FREE_2D_ARR(NCATA.CATA);

	}
		if (status == -1 )
			fclose(file);
	free_stack(&STACK);
	return (size);

}
