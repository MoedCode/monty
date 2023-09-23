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
	stack_t *new_node = creat_One(NCATA.n);

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
		EXIT(stack);
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
	if (!*stack)
		return;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pall, stack empty\n", line_number);
		EXIT(stack);

	}
	Print_stack(*stack);
}
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
	stack_t *top ;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop, stack empty\n", line_number);
		EXIT(stack);
	}

	top = *stack;
	*stack = top->next;  /* Update the stack pointer to the next element */
	free(top);          /* Free the old top element */
}