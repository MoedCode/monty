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
	char *command, tmp2;
	FILE *file = fopen(filePath, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filePath);
		exit(EXIT_FAILURE);
	}
	while (status != -1)
	{
		command  = malloc(1000 * sizeof(char));
		status = getline(&command, &size, file);
		CATA = Tokenize_in_Arr(command, " \n");

		instructionF(CATA[0], CATA[1], line);
		line++;
		FreeVar(command);
		FREE_2D_ARR(CATA);
		printf("while[%u]\n",line);
	}
		if (status == -1 )
			fclose(file);

	return (size);

}