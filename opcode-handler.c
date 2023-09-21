#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct instruction_s opcode_arr[] =
{
{"push", push},
{"add", add},
{"pall", pall},
{"swap", swap},
{"pop", pop},
{NULL, NULL}
};
int instructionF(char *str_arg, int int_arg)
{
	stack_t *node = malloc(sizeof(stack_t));
	if (!node)
	{
    	fprintf(stderr, "Error: Failed to allocate memory\n");
    	exit(EXIT_FAILURE);
	}
	node->n = int_arg * 2;
	node->next = NULL;
	node->prev = NULL;
	for (int i = 0; opcode_arr[i].opcode ; i++ )
			if (!strcmp(opcode_arr[i].opcode, str_arg))
				opcode_arr[i].f(&node, int_arg);
	return (0);

}



void push(stack_t *(*stack), unsigned int line_number)
{
	printf("push  %u, node%i\n",line_number,((*stack))->n);
		free((*stack));
}
void add(stack_t *(*stack), unsigned int line_number)
{
		printf("add %u, node%i\n",line_number,((*stack))->n);
		free((*stack));

}
void pall(stack_t *(*stack), unsigned int line_number)
{
		printf("pall %u, node%i\n",line_number,((*stack))->n);
		free((*stack));

}
void swap(stack_t *(*stack), unsigned int line_number)
{
		printf("swap  %u, node%i\n",line_number,((*stack))->n);
		free((*stack));
}
void pop(stack_t *(*stack), unsigned int line_number)
{
		printf(" pop  %u, node%i\n",line_number,((*stack))->n);
		free((*stack));
}