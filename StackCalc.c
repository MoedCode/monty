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
	delete_stack_t_at_index(stack, 0);
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
/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 */
void divf(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		EXIT(stack);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		EXIT(stack);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number of the opcode in the Monty bytecode file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		EXIT(stack);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}




