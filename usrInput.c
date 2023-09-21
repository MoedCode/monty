#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char **CATA;

size_t Get_Inout(char *filePath)
{
	int status, tmp = 0;
	size_t size;
	unsigned int line = 0;
	char *command;
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
		command  = malloc(sizeof(char));
		status = getline(&command, &size, file);
		CATA = Tokenize_in_Arr(command, " \n");
		if (CATA[1])
			tmp = atoi(CATA[1]);
		instructionF(CATA[0], tmp);
		line++;
		/* Print_2D_Arr(CATA, 0); */
		FreeVar(command);
		FREE_2D_ARR(CATA);
	}
		if (status == -1 )
			fclose(file);

	return (size);

}