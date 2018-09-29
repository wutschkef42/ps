
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

t_stack	*get_min_a(t_stack **a)
{
	t_stack	*cur;
	t_stack	*min;
	int		n;

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


// HERE we want to get the biggest element in b thats smaller than what we want to insert
// RIGHT NOW we have the smallest element in b thats bigger than what we want to insert
t_stack	*get_max_b(t_stack **b, int to_insert)
{
	int		max;
	t_stack	*p;

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



t_stack	*get_index_b(t_stack **b, int val)
{
		
	if (get_max_b(b, val) == NULL)
		return (get_max_b(b, INT_MAX)); /* the element we want to insert is bigger or smaller than ALL elements in b */
	else
		return (get_max_b(b, val));  /* there is an element in b thats bigger than what we want to insert */ /* there is an element in b thats smaller than what we want to insert, we want the BIGGEST element in b thats SMALLER than what we want to insert */

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

void	rotate_min_to_top(t_stack **a, t_opcodes *opcodes)
{
	int	nrot;
	int	i;

	nrot = count_top(*a, get_min_a(a));
	i = 0;
	while (i < nrot)
	{
		op_rotate(a);
	//	printf(RA);
		add_opcode(opcodes, "ra\n");
	//	printf("\n");
		i++;
	}
}


void	calc_next_op(t_stack **a, t_stack **b, t_next_op *next_op)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = *a;
	while (cur_a)
	{
		cur_b = get_index_b(b, cur_a->val);
		next_op->no_top_a = count_top(*a, cur_a);
		next_op->no_top_b = count_top(*b, cur_b);
		next_op->no_bottom_a = next_op->size_a - next_op->no_top_a - 1;
		next_op->no_bottom_b = next_op->size_b - next_op->no_top_b - 1;
		if (calc_cost(next_op))
		{
			next_op->cur_a = cur_a;
			next_op->cur_b = cur_b;	
		}
		cur_a = cur_a->next;
	}
}



void	solve(t_stack **a, t_stack **b)
{
	t_next_op	next_op;
	t_opcodes	opcodes;

	op_push(b, a);
	opcodes.i = 0;
	add_opcode(&opcodes, "pb\n");
	//printf("pb\n");
	while (*a)
	{
		init_next_op(*a, *b, &next_op);
		calc_next_op(a, b, &next_op);
		next_op.no_top_a = count_top(*a, next_op.cur_a);
		next_op.no_top_b = count_top(*b, next_op.cur_b);
		next_op.no_bottom_a = next_op.size_a - next_op.no_top_a - 1;
		next_op.no_bottom_b = next_op.size_b - next_op.no_top_b - 1;
		exec_next_op(a, b, next_op, &opcodes); // remove one element from a
	}
	while (*b)
	{
		op_push(a, b);
		add_opcode(&opcodes, "pa\n");
	//	printf("pa\n");
	}
	rotate_min_to_top(a, &opcodes);
	//ft_printf("----\n");
	ft_printf("%s", opcodes.buf);
	
}



int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (!(a = read_input(ac, av)))
		return (0);
	if (is_sorted(a))
		return (0);
	solve(&a, &b);
	//print_stack(a);
	return (0);
}