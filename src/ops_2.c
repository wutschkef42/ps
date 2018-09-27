
#include "push_swap.h"

/* last element becomes first */
void	op_rev_rotate(t_stack **a)
{
	t_stack *bottom;

	if (!*a || !((*a)->next))
		return ;
	bottom = *a;
	while (bottom->next->next)
	{
		
		bottom = bottom->next;
	}
	bottom->next->next = *a;
	*a = bottom->next;
	bottom->next = NULL;
}

/* last element becomes first */
void	op_rev_rotate_both(t_stack **a, t_stack **b)
{
	op_rev_rotate(a);
	op_rev_rotate(b);
}
