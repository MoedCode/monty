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
 * free_stack -  frees a stack_t list.
 * @head:  pointer of the head node.
 * Return: VOID
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
