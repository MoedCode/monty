#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char **CATA;
size_t Get_Inout(char *filePath)
{
	int status;
	size_t size;
	unsigned int line = 0;
	FILE *file = fopen(filePath, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filePath);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (status == -1)
			break;
		char *command  = malloc(sizeof(char));
		status = getline(&command, &size, file);
		CATA = Tokenize_in_Arr(command, " \n");
		instructionF(CATA[0], line);
		line++;
		Print_2D_Arr(CATA, 0);
		FreeVar(command);
		FREE_2D_ARR(CATA);


	}
		if (status == -1 )
			fclose(file);

	return (size);

}