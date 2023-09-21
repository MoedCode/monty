#include "monty.h"

stack_t *creat_One ( int n)
{		stack_t *x = malloc(sizeof(stack_t));
 		x->next = 0;
 		x->prev = 0;
		x->n  = n;
		return (x);

}
stack_t *Creat_stack_t( int n, stack_t **LIST, int index);
stack_t *Creat_stack_t( int n, stack_t **LIST, int index)
{
	size_t i;
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