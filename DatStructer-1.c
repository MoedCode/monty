#include "monty.h"
/**
 * creat_One -  adds a new node
 * with null previous and next filelds
 * @n: element to be added in the linked list as the new head
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *creat_One( int n)
{		stack_t *x = malloc(sizeof(stack_t));
 		x->next = 0;
 		x->prev = 0;
		x->n  = n;
		return (x);

}
/**
 * Creat_stack_t - inserts a new node at a given position
 *
 * @LIST:double pointer to Hrad node
 * @index: the given position
 * @n:inter value all node data
 * Return: stack_t* momory address of  added node,
 *(NULL) if it fail to add node
 */
stack_t *Creat_stack_t( int n, stack_t **LIST, int index);
stack_t *Creat_stack_t( int n, stack_t **LIST, int index)
{
	int i;
	stack_t *tmp, *List_;

	if (n || !LIST)
			return (0);
	if (!*LIST ||  (index == 0 && !*LIST))
		return  ( creat_One(n));
	if (LIST && index == 0)
		{
			tmp = creat_One(n);
			tmp->prev = 0;
			tmp->next = (*LIST);
			(*LIST)->next->prev =tmp;

				return (tmp);

		}
		for (i = 0, List_ = *LIST; List_->next; List_ = List_->next, i++ )
		{
			if (i == index)
			{
				tmp = creat_One(n);
				tmp->next = List_;
				tmp->prev = List_->prev;

				List_->prev = tmp;

				return (tmp);

			}
			if (index == i + 1 && !List_->next )
			{
				tmp = creat_One(n);
				List_->next = tmp;
				tmp->prev = List_;
				return (tmp);

			}
		}
		return (0);
 }
/**
 *print_stack - print linked singaly list nodes
 * @h: pointer to first node
 * Return: size_t i whics number of printd  nodes
 */
unsigned int  Print_stack(const stack_t *h)
{
	unsigned int  i;
	const stack_t *H = h;

	for (i = 0; H; i++)
	{
		printf("%d\n", H->n);
		H = H->next;
	}
	return (i);
}
/**
 *stack_len - return  singaly list length
 * @h: pointer to first node
 * Return: size_t i whics number of  nodes
 */
unsigned int stack_len(const stack_t *h)
{
	size_t i;
	const stack_t *H = h;

	for (i = 0; H; i++)
	{
		H = H->next;
	}
	return (i);
}
