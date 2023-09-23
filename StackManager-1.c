#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{


	stack = stack;
	line_number = line_number;
}
/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop, stack empty\n", line_number);
		EXIT(stack);
	}

	top = *stack;
	*stack = top->next;  /* Update the stack pointer to the next element */
	free(top);          /* Free the old top element */
}