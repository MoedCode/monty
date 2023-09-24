#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

n_CATA  NCATA;



void Get_Inout(char *filePath)
{
	FILE *file = fopen(filePath, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filePath);
		exit(EXIT_FAILURE);
	}
	while (NCATA.status  != -1)
	{
		NCATA.line++;
		NCATA.command = NULL;
		NCATA.status = getline(&NCATA.command, &NCATA.size, file);

		if (!strlen(NCATA.command))
		{
			FreeVar(NCATA.command);
			break;
		}
		NCATA.CATA = Tokenize_in_Arr(NCATA.command, " $\n");
		instructionF( &NCATA.STACK);
		FreeVar(NCATA.command);
		FREE_2D_ARR(NCATA.CATA);



	}
		if (NCATA.status == -1 )
			fclose(file);
	free_stack(&NCATA.STACK);
	return ;

}
