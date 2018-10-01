
#include "push_swap.h"

int				count_top(t_stack *first, t_stack *cur)
{
	int			count;

	count = 0;
	while (first)
	{
		if (first == cur)
			return (count);
		first = first->next;
		count++;
	}
	return (count);
}

int				count_bottom(t_stack *first, t_stack *cur)
{
	int			count;

	while (first != cur)
		first = first->next;
	count = 0;
	while (first->next)
	{
		first = first->next;
		count++;
	}
	return (count);
}

/*
**  HERE we want to get the biggest element in b thats smaller
** than what we want to insert
** RIGHT NOW we have the smallest element in b thats bigger
** than what we want to insert
*/

t_stack			*get_max_b(t_stack **b, int to_insert)
{
	int			max;
	t_stack		*p;

	max = INT_MIN;
	p = NULL;
	while (*b)
	{
		if ((*b)->val > max && (*b)->val < to_insert)
		{
			p = *b;
			max = (*b)->val;
		}
		b = &((*b)->next);
	}
	return (p);
}

t_stack			*get_min_a(t_stack **a)
{
	t_stack		*cur;
	t_stack		*min;
	int			n;

	n = INT_MAX;
	cur = *a;
	while (cur)
	{
		if (cur->val < n)
		{
			min = cur;
			n = cur->val;
		}
		cur = cur->next;
	}
	return (min);
}

/*
** 1st ret : there is an element in b thats bigger than what we want to insert
** there is an element in b thats smaller than what we want to insert,
** we want the BIGGEST element in b thats SMALLER than  what we want to insert
**  the element we want to insert is bigger or smaller than ALL elements in b
*/

t_stack			*get_index_b(t_stack **b, int val)
{
	if (get_max_b(b, val) == NULL)
		return (get_max_b(b, INT_MAX));
	else
		return (get_max_b(b, val));
}
