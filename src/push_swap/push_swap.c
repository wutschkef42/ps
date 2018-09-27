
#include "libft.h"
#include "push_swap.h"


void	init_next_op(t_stack *a, t_stack *b, t_next_op *next_op)
{
	next_op->cur_a = NULL;
	next_op->cur_b = NULL;
	next_op->size_a = stack_size(a);
	next_op->size_b = stack_size(b);
	next_op->strategy = UPUP;
	next_op->cost = INT_MAX;
}

t_stack	*get_index_b(t_stack **b, int val)
{
	while (*b)
	{
		if ((*b)->val < val)
			return (*b);
		b = &((*b)->next);
		ft_printf("get_index_b\n");
	}
	return (*b);
}


void	calc_next_op(t_stack **a, t_stack **b, t_next_op *next_op)
{
	t_stack	*cur_a;

	cur_a = *a;
	while (cur_a)
	{
		next_op->cur_a = cur_a;
		next_op->cur_b = get_index_b(b, cur_a->val);
		// no_top_a = cur_a - first_a = number of elements in stack a that are on top of cur_a
		// no_top_b = cur_b - first_b = number of elements in stack b that are on top of cur_b
		// no_bottom_a = size_a - no_top_a - 1 = number of elements in stack a that are under cur_a
		// no_bottom_b = size_b - no_top_b - 1 = number of elements in stack b that are under cur_b
		next_op->no_top_a = *a - next_op->cur_a;
		next_op->no_top_b = *b - next_op->cur_b;
		next_op->no_bottom_a = next_op->size_a - next_op->no_top_a - 1;
		next_op->no_bottom_b = next_op->size_b - next_op->no_top_b - 1;
		calc_cost(next_op);
		cur_a = cur_a->next;
		ft_printf("calc_next_op\n");
	}
}


void	solve(t_stack **a, t_stack **b)
{
	t_next_op	next_op;

	op_push(b, a);
	while (*a)
	{
		ft_printf("solve loop a\n");
		init_next_op(*a, *b, &next_op);
		calc_next_op(a, b, &next_op);
		exec_next_op(a, b, next_op); // remove one element from a
	}
	while (*b)
	{
		ft_printf("solve loop b\n");
		op_push(a, b);
	}
}



int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (!(a = read_input(ac, av)))
		return (0);
	solve(&a, &b);
	return (0);
}