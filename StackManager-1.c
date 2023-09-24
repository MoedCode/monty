#include "monty.h"
/**
 * swap -swap the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void swap(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		EXIT(stack);
	}
}
/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		EXIT(stack);
	}

	top = *stack;
	*stack = top->next;  /* Update the stack pointer to the next element */
	free(top);          /* Free the old top element */
}
/**
 * sub - sub the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
 void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		EXIT(stack);
	}
	STCK_LEN_2
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	delete_stack_t_at_index(stack, 0);
}

