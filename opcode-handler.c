#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 0;
struct instruction_s opcode_arr[] =
{
{"push", push},
{"add", add},
{"pall", pall},
{"swap", swap},
{"pop", pop},
{"pint", pint},
{NULL, NULL}
};
int *instructionF(char *arg0, char *arg1, unsigned int line, stack_t **list )
{
	static int i;


/*
	if (arg1 == NULL || !is_valid_integer(arg1))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line);
		}
	else
	 	n = atoi(arg1);
*/
	if (arg0 )
	{
		if(arg1)
			n = atoi(arg1);
		for (i = 0; i <= 5 ; i++ )
		{
			 if(!strcmp("pall$", arg0) )
			 {
				printf("its kaky %s\n",arg0);DBG;
			 }
			if ( strcmp(opcode_arr[i].opcode, arg0) == 0 )
			{
			 	 opcode_arr[i].f(list, line);

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