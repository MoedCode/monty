#include "monty.h"
#include <stdio.h>
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



