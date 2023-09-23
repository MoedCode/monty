#include "monty.h"
/**
 * swap -swap the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
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

	IF_NULL_STACK

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
	IF_NULL_STACK
	STCK_LEN_2
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	delete_stack_t_at_index(stack, 0);
}

