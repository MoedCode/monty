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

#include "monty.h"




/**
 * push_rev - Pushes an element onto the stack in reverse order (FILO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty byte code file.
 *
 * Description: The push_rev function adds a new node to the beginning of the
 * stack, effectively reversing the order of elements.
 */
void push(stack_t **stack, unsigned int line_number)
{
	/* Create a new node */
	stack_t *new_node = creat_One(n);

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed at line %u\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* Link the new node to the stack */
	new_node->next = *stack;
	new_node->prev = NULL;

	/* Update the previous pointer of the current top node */
	if (*stack)
		(*stack)->prev = new_node;

	/* Update the stack pointer to the new node */
	*stack = new_node;
}
/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
void add(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

}
void pall(stack_t **stack, unsigned int line_number)
{
		if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	Print_stack(*stack);
}
void swap(stack_t **stack, unsigned int line_number)
{

	stack = stack;
	line_number = line_number;
}
void pop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
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