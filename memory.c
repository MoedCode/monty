#include "monty.h"
/**
 * Free_2D_Array - free Double array
 *
 * @Array: array to pefree
 * Return: (size_t) size of indexes has been freed,
 *(0) on errors
 */
size_t Free_2D_Array(char **Array)
{
	size_t i, j;

	for (j = 0; Array[j]; j++)
		;
	for (i = 0; i <= j; i++)
		if (Array[i])
		{

			free(Array[i]);
			Array[i] = NULL;
		}



	if (Array)
	{
		free(Array);
		Array = NULL;
	}
	return (i);
}
/**
 * free_node - Frees a node and updates its neighbors
 * @node: The node to be freed
 */
void free_node(stack_t *node)
{
	if (node)
	{
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		free(node);
	}
}

/**
 * free_stack - Frees the entire stack
 * @head: A pointer to the head of the stack
 */
void free_stack(stack_t **head)
{
	stack_t *current = *head;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}

	*head = NULL;
}
void EXIT( stack_t **stack)
{
	FreeVar(NCATA.command);
	Free_2D_Array(NCATA.CATA);
	free_stack(stack);
	exit(EXIT_FAILURE);
}