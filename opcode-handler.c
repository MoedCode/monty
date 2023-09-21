#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
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
int instructionF(char *arg0, char *arg1, unsigned int line )
{
	int i;
	stack_t **x;

	if (arg1 == NULL || !is_valid_integer(arg1))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line);
		}
	else
	 	n = atoi(arg1);

	if (arg0 && arg1)
	{
		for (i = 0; i <= 5 ; i++ )
		{

			if (!strcmp(opcode_arr[i].opcode, arg0) )
			{
				DBG;
			 	 opcode_arr[i].f(x, line);
				 DBG;
			}
		}
	}
	Print_stack(*x);

	return (0);
}



void push(stack_t **stack,unsigned int line_number)
{
	unsigned int size = 0;
	printf("n = [%d]\n", n);
	DBG;
	if (!*stack)
	{
		*stack = Add_Head(stack,  n);
		printf(">> %d",(*stack)->n);
	}
	else
		{
			DBG;
			size = stack_len(*stack);
			DBG;
			*stack = insert_stack_at_index(stack, size, n);
		}

	DBG;


}
void pint(stack_t **stack, unsigned int line_number)
{

	printf("n = [%d]\n", n);

}
void add(stack_t **stack, unsigned int line_number)
{

	printf("n = [%d]\n", n);
}
void pall(stack_t **stack, unsigned int line_number)
{

}
void swap(stack_t **stack, unsigned int line_number)
{
	printf("n = [%d]\n", n);

}
void pop(stack_t **stack, unsigned int line_number)
{
	printf("n = [%d]\n", n);
}
bool is_valid_integer(const char *str)
{
	if (str == NULL || str[0] == '\0')
		return false;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && (i == 0 && str[i] != '-' && str[i] != '+'))
			return false;
	}

	return true;
}