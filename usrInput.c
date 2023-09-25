#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

n_CATA  NCATA;



void Get_Inout(char *filePath)
{
	FILE *file = fopen(filePath, "r");
struct instruction_s opcode_arr[] =
{
/*Edit*/
{"push", push},
{"pall", pall},
{"swap", swap},
{"pop", pop},
{"pint", pint},
{"nop", nop},
/*calc*/
{"add", add},
{"sub", sub},
{"div", divf},
{"mul", mul},
{"mod", mod},
{"#", comments},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},

{NULL, NULL}
};
NCATA.opcode_arr = opcode_arr;

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
		if (NCATA.CATA[0])
		{
		if (!strcmp("queue", NCATA.CATA[0]) )
			NCATA.mode = 1;
		else if (!strcmp("stack", NCATA.CATA[0]))
			NCATA.mode = 0;
		}
		instructionF( &NCATA.STACK);
		FreeVar(NCATA.command);
		FREE_2D_ARR(NCATA.CATA);



	}
		if (NCATA.status == -1 )
			fclose(file);
	free_stack(&NCATA.STACK);
	return ;

}
