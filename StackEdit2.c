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
/**
 * push_end - Pushes a node to the end of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void push_end(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node,  *Cur_node;

	if (NCATA.CATA[1])
		NCATA.n = atoi(NCATA.CATA[1]);
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		EXIT(stack);
	}

	new_node = creat_One(NCATA.n);
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed at line %u\n", line_number);
		EXIT(stack);
	}

	if (!*stack)
	{
		*stack = new_node;
		return;
	}

	Cur_node = *stack;
	while (Cur_node->next != NULL)
	{
		Cur_node = Cur_node->next;
	}
	Cur_node->next = new_node;
	new_node->prev = Cur_node;
}
