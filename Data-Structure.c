#include "monty.h"



/**
 * Add_Head -  adds a new node
 * with null previous and next filelds
 * @H: a null pointer to an empty list
 * @n: element to be added in the linked list as the new head
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *Add_Head(stack_t **H, int n)
{
	stack_t *N = malloc(sizeof(stack_t));

	if (!N)
		return (NULL);
	N->n = n;
	N->next = NULL;
	N->prev = NULL;
	*H = N;
	return (N);
}
/**
 * add_stack -  adds a new node at the beginning of
 *a stack_t list.
 *
 * @head: pointer to pointer to head
 * @n: new node integer value
 * Return: stack_t* new added node
 */
stack_t *add_stack(stack_t **head, const int n)
{
	stack_t *NODE, *HEAD  = *head;

		if (!head)
			return (NULL);
		if (!*head)
			return (Add_Head(head, n));
	NODE = malloc(sizeof(stack_t) * 1);
	if (!NODE)
		return (NULL);

	/* NRW NODE*/
	NODE->n = n;
	NODE->prev = NULL;
	NODE->next = HEAD;
	/*HEAD*/
	(*head)->prev = NODE;

	*head = NODE;

	return (NODE);
}


/**
 * insert_stack_at_index - inserts a new node at a given position
 *
 * @h:double pointer to Hrad node
 * @idx: the given position
 * @n:inter value all node data
 * Return: stack_t* momory address of  added node,
 *(NULL) if it fail to add node
 */
stack_t *insert_stack_at_index(stack_t **h, unsigned int idx, int n)
{
	size_t i;
	stack_t *H = *h, *midNode;

	if (idx == 0)
		return (add_stack(h, n));

	for (i = 0; H; i++, H = H->next)
	{
		if (H->next == NULL && i + 1 == idx)
			return (add_stack_end(h, n));
		if (i == idx)
		{
			midNode = malloc(sizeof(stack_t));
			if (!midNode)
				return (NULL);
			midNode->n = n;
			midNode->next = H;
			midNode->prev = H->prev;

			H->prev->next = midNode;
			H->prev = midNode;
			return (midNode);
		}

	}

		return (NULL);
}
/**
 * add_stack_end -  adds a new node at the  end  of
 *a stack_t list.
 *
 * @head: pointer to pointer to head
 * @n: new node integer value
 * Return: stack_t* new added node
 */
stack_t *add_stack_end(stack_t **head, const int n)
{
	stack_t *NODE, *HEAD  = *head;

		if (!head)
			return (NULL);
		if (!*head)
			return (Add_Head(head, n));
	NODE = malloc(sizeof(stack_t) * 1);
	if (!NODE)
		return (NULL);
	while (HEAD->next)
		HEAD = HEAD->next;
	/* NRW NODE*/
	NODE->n = n;
	NODE->prev = HEAD;
	NODE->next = NULL;
	/* (*head)->prev = NODE; */
	HEAD->next = NODE;



	return (NODE);
}


/**
 * delete_stack_t_at_index - delet a  node at a given position
 *
 * @head:double pointer to Hrad node
 * @index: the given position
 * Return:(-1) if cant delet node , else (1)
 */
int delete_stack_t_at_index(stack_t **head, unsigned int index);

int delete_stack_t_at_index(stack_t **head, unsigned int index)
{

	size_t i = 0;
	stack_t *H = *head, *tmpH;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		/* in all cases make list pointer point node1*/
		(*head)  = H->next;
		/*split node0 from list*/
		H->prev = NULL;
		/* if index=0 and list lenth > 1*/
		if (H->next)
		{
			/* node 0 will be deletd so   node1 ▶ node 0*/
			/* make node1 prev = NULL */
			H->next->prev = NULL;
		}
			/* deleting node 0*/
			free(H);
		return (1);
	}

	for (; H; H = H->next, i++)
	{

		if ((H->next == NULL) && (i == index))
		{
			/* tmpH = H; */
			H->prev->next = NULL;
			free(H);
			return (1);
		}

		if (i == index)
		{
			tmpH = H;

			H->prev->next = H->next;
			H->next->prev = H->prev;
			free(tmpH);
			return (1);
		}
	}
	return (-1);
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
