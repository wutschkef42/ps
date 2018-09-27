
#include "push_swap.h"

/* swaps the topmost two elements of a */
void	op_swap(t_stack *a)
{
	int	tmp;

	if (a->next)
	{
		tmp = a->val;
		a->val = a->next->val;
		a->next->val = tmp;
	}		
}

void	op_swap_both(t_stack *a, t_stack *b)
{
	op_swap(a);
	op_swap(b);
}

/* pops element off b and pushes it on a */
void	op_push(t_stack **a, t_stack **b)
{
	t_stack	*p;

	if (!*b)
		return ;
	p = pop(b);
	push(a, p);	

}

/* shift up all elements by 1, first one becomes last one */
void	op_rotate(t_stack **a)
{
	t_stack	*top;
	
	top = *a;
	if (!top || !top->next)
		return ;
	*a = (*a)->next;
	while ((*a)->next)
		a = &((*a)->next);
	(*a)->next = top;
	top->next = NULL;
}


/* first element becomes last */
void	op_rotate_both(t_stack **a, t_stack **b)
{
	op_rotate(a);
	op_rotate(b);
}
