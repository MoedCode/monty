#include "monty.h"
#include <stdio.h>
#include <string.h>
/**
 * nop - Doesn't do anything.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * comments - This opcode doesn't do anything, as it treats the line as a comment.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 */
void comments(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}



/**
 * pchar - Prints the ASCII  value at the top of the stack, followed by a new line.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		EXIT(stack);
	}
	if ((*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		EXIT(stack);
	}

	putchar((*stack)->n);
	putchar(10);
}


/**
 * pstr - Prints the string starting at the top of the stack, followed by a new line.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_node = *stack;

	while (cur_node && cur_node->n != 0)
	{
		if (cur_node->n < 0 || cur_node->n > 127)
		{
			fprintf(stderr, "L%u: can't pstr, value out of range\n", line_number);
			EXIT(stack);
		}

		printf("%c", cur_node->n);
		cur_node = cur_node->next;
	}

	putchar(10);
}
