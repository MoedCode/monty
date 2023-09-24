#include "monty.h"
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't add an empty stack\n", line_number);
		EXIT(stack);
	}
		if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		EXIT(stack);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number being processed.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		EXIT(stack);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}


/**
 * sub - sub the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
 void sub(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		EXIT(stack);
	}

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	delete_stack_t_at_index(stack, 0);
}

