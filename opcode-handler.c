#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct instruction_ss opcode_arr[] =
{
{"push", push},
{"add", add},
{"pall", pall},
{"swap", swap},
{"pop", pop},
{NULL, NULL}
};
int instructionF(char *arg0, char *arg1, unsigned int line )
{
	int i;
	for (i = 0; opcode_arr[i].opcode ; i++ )
	{
		printf("arg[0]=> %s arg[1]=> %s\n",arg0, arg1);
		/* if (!strcmp(opcode_arr[i].opcode, arg0) && line)
				 opcode_arr[i].f(line);*/
	}

	return (0);
}



void push( unsigned int line_number)
{
		printf("%u\n", line_number);


}
void add( unsigned int line_number)
{
		printf("%u\n", line_number);


}
void pall( unsigned int line_number)
{
		printf("%u\n", line_number);


}
void swap( unsigned int line_number)
{
		printf("%u\n", line_number);


}
void pop( unsigned int line_number)
{
		printf("%u\n", line_number);

}
