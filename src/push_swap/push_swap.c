
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

t_stack	*get_min_b(t_stack **b, int to_insert)
{
	int		min;
	t_stack	*p;

	min = INT_MAX;
	p = *b;
	while (*b)
	{
		if ((*b)->val < min && (*b)->val > to_insert)
		{

			p = *b;
			printf("$$$$%p\n", p);
			min = (*b)->val;
		}
		b = &((*b)->next);
	}

	return (p);
}

t_stack	*get_index_b(t_stack **b, int val)
{
		
	if (get_min_b(b, val) == NULL)
		return (get_min_b(b, INT_MIN)); /* the element we want to insert is bigger or smaller than ALL elements in b */
	else
		return (get_min_b(b, val));  /* there is an element in b thats bigger than what we want to insert */

}

int		count_top(t_stack *first, t_stack *cur)
{
	int	count;

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

int		count_bottom(t_stack *first, t_stack *cur)
{
	int	count;

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

void	calc_next_op(t_stack **a, t_stack **b, t_next_op *next_op)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = *a;
	while (cur_a)
	{
		cur_b = get_index_b(b, cur_a->val);
		printf("cur_b: %p\n", cur_b);
		

		// no_top_a = cur_a - first_a = number of elements in stack a that are on top of cur_a
		// no_top_b = cur_b - first_b = number of elements in stack b that are on top of cur_b
		// no_bottom_a = size_a - no_top_a - 1 = number of elements in stack a that are under cur_a
		// no_bottom_b = size_b - no_top_b - 1 = number of elements in stack b that are under cur_b
		
		printf("top_a: %d, cur_a: %d, top_b: %d, cur_b: %d\n", (*a)->val, cur_a->val, (*b)->val, cur_b->val);
		next_op->no_top_a = count_top(*a, cur_a);
		next_op->no_top_b = count_top(*b, cur_b);
		next_op->no_bottom_a = next_op->size_a - next_op->no_top_a - 1;
		next_op->no_bottom_b = next_op->size_b - next_op->no_top_b - 1;
		if (calc_cost(next_op))
		{
			printf("ALARM\n");
			next_op->cur_a = cur_a;
			next_op->cur_b = cur_b;	
		}
		cur_a = cur_a->next;
//		ft_printf("calc_next_op\n");
	}
}


void	solve(t_stack **a, t_stack **b)
{
	t_next_op	next_op;

	op_push(b, a);
	while (*a)
	{
//		ft_printf("solve loop a\n");
		init_next_op(*a, *b, &next_op);
		calc_next_op(a, b, &next_op);
		printf("before next op:\n");
		print_stack(*a);
		print_stack(*b);
		next_op.no_top_a = count_top(*a, next_op.cur_a);
		next_op.no_top_b = count_top(*b, next_op.cur_b);
		next_op.no_bottom_a = next_op.size_a - next_op.no_top_a - 1;
		next_op.no_bottom_b = next_op.size_b - next_op.no_top_b - 1;
		exec_next_op(a, b, next_op); // remove one element from a
		printf("after next op:\n");
		print_stack(*a);
		print_stack(*b);

	}
	while (*b)
	{
//		ft_printf("solve loop b\n");
		op_push(a, b);
		printf("pa\n");
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
	printf("end result stack a\n");
	print_stack(a);
	return (0);
}