
#include "push_swap.h"

void			init_next_op(t_stack *a, t_stack *b, t_next_op *next_op)
{
	next_op->cur_a = NULL;
	next_op->cur_b = NULL;
	next_op->size_a = stack_size(a);
	next_op->size_b = stack_size(b);
	next_op->strategy = UPUP;
	next_op->cost = INT_MAX;
}

void			rotate_min_to_top(t_stack **a, t_opcodes *opcodes)
{
	int			nrot;
	int			i;

	nrot = count_top(*a, get_min_a(a));
	i = 0;
	while (i < nrot)
	{
		op_rotate(a);
		add_opcode(opcodes, "ra\n");
		i++;
	}
}

void			calc_next_op(t_stack **a, t_stack **b, t_next_op *next_op)
{
	t_stack		*cur_a;
	t_stack		*cur_b;

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

void			solve(t_stack **a, t_stack **b)
{
	t_next_op	next_op;
	t_opcodes	opcodes;

	op_push(b, a);
	opcodes.i = 0;
	add_opcode(&opcodes, "pb\n");
	while (*a)
	{
		init_next_op(*a, *b, &next_op);
		calc_next_op(a, b, &next_op);
		next_op.no_top_a = count_top(*a, next_op.cur_a);
		next_op.no_top_b = count_top(*b, next_op.cur_b);
		next_op.no_bottom_a = next_op.size_a - next_op.no_top_a - 1;
		next_op.no_bottom_b = next_op.size_b - next_op.no_top_b - 1;
		exec_next_op(a, b, next_op, &opcodes);
	}
	while (*b)
	{
		op_push(a, b);
		add_opcode(&opcodes, "pa\n");
	}
	rotate_min_to_top(a, &opcodes);
	ft_printf("%s", opcodes.buf);
}
