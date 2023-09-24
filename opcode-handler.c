#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 0;
struct instruction_s opcode_arr[] =
{
{"push", push},
{"pall", pall},
{"swap", swap},
{"pop", pop},
{"pint", pint},
{"nop", nop},
{"add", add},
{"sub", sub},
{"div", divf},
{"mul", mul},
{"mod", mod},

{NULL, NULL}
};
int *instructionF(  stack_t **list )
{
	 int i;


	if (NCATA.CATA[0] )
	{

		for (i = 0; opcode_arr[i].opcode ; i++ )
		{

			if ( strcmp(opcode_arr[i].opcode, NCATA.CATA[0]) == 0 )
			{
			 	 opcode_arr[i].f(list, NCATA.line);

			}
		}
	}

	return (0);
}

bool is_valid_integer(const char *str)
{
	int i ;

	if (str == NULL || str[0] == '\0')
		return false;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && (i == 0 && str[i] != '-' && str[i] != '+'))
			return false;
	}

	return true;
}