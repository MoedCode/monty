#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeZ, *nodeAfterZ;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	nodeZ = *stack;
	nodeAfterZ = NULL;


	while (nodeZ->next)
	{
		nodeAfterZ = nodeZ;
		nodeZ = nodeZ->next;
	}

	nodeAfterZ->next = NULL;
	nodeZ->prev = NULL;
	nodeZ->next = *stack;
	*stack = nodeZ;
}
