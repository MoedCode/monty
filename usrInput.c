#include "monty.h"
#include <stddef.h>
#include <stdio.h>

size_t Get_Inout()
{
	int status;
	size_t size;
	char *command, **args;


	status = getline(&command, &size, stdin);
	args = Tokenize_in_Arr(command, " \n");
	Print_2D_Arr(args, 0);
	FreeVar(command);
	FREE_2D_ARR(args);


	return (size);

}