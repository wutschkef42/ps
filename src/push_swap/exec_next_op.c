
#include "libft.h"
#include "push_swap.h"

static	int	min(int a, int b)
{
	return (a < b ? a : b);
}

static void	exec_upup(t_stack **a, t_stack **b, t_next_op next_op, t_opcodes *opcodes)
{
	int i;

	i = 0;
	while (i < min(next_op.no_top_a, next_op.no_top_b))
	{
		op_rotate_both(a, b);
		add_opcode(opcodes, "rr\n");
//		ft_printf(RR);
//		ft_printf("\n");
		i++;
	}
	i = 0;
	while (i < max(next_op.no_top_a, next_op.no_top_b) - min(next_op.no_top_a, next_op.no_top_b))
	{
		if (next_op.no_top_a > next_op.no_top_b)
		{
			op_rotate(a);
			add_opcode(opcodes, "ra\n");
//			ft_printf(RA);
		}
		else
		{
			op_rotate(b);
			add_opcode(opcodes, "rb\n");
//			ft_printf(RB);
		}
//		ft_printf("\n");
		i++;
	}
}

static void	exec_updown(t_stack **a, t_stack **b, t_next_op next_op, t_opcodes *opcodes)
{
	int	i;

	i = 0;
	while (i < next_op.no_top_a)
	{
		op_rotate(a);
//		ft_printf(RA);
		add_opcode(opcodes, "ra\n");
//		ft_printf("\n");
		i++;
	}
	i = 0;
	while (i < next_op.no_bottom_b + 1)
	{
		op_rev_rotate(b);
//		ft_printf(RRB);
		add_opcode(opcodes, "rrb\n");
//		ft_printf("\n");
		i++;
	}
}

static void	exec_downup(t_stack **a, t_stack **b, t_next_op next_op, t_opcodes *opcodes)
{
	int	i;

	i = 0;
	while (i < next_op.no_top_b)
	{
		op_rotate(b);
//		ft_printf(RB);
		add_opcode(opcodes, "rb\n");
//		ft_printf("\n");
		i++;
	}
	i = 0;
	while (i < next_op.no_bottom_a + 1)
	{
		op_rev_rotate(a);
//		ft_printf(RRA);
		add_opcode(opcodes, "rra\n");
//		ft_printf("\n");
		i++;
	}
}

static void	exec_downdown(t_stack **a, t_stack **b, t_next_op next_op, t_opcodes *opcodes)
{
	int i;

	i = 0;
	while (i < min(next_op.no_bottom_a, next_op.no_bottom_b) + 1)
	{
		op_rev_rotate_both(a, b);
//		ft_printf(RRR);
		add_opcode(opcodes, "rrr\n");
//		ft_printf("\n");
		i++;
	}
	i = 0;
	while (i < max(next_op.no_bottom_a, next_op.no_bottom_b) - min(next_op.no_bottom_a, next_op.no_bottom_b))
	{
		if (next_op.no_bottom_a > next_op.no_bottom_b)
		{
			op_rev_rotate(a);
			add_opcode(opcodes, "rra\n");
//			ft_printf(RRA);
		}
		else
		{
			op_rev_rotate(b);
			add_opcode(opcodes, "rrb\n");
//			ft_printf(RRB);
		}
//		ft_printf("\n");
		i++;
	}
}


void	print_next_op(t_next_op next_op)
{
	printf("cur_a: %d, cur_b: %d, size_a = %d, size_b = %d, no_top_a = %d, no_top_b = %d, no_bottom_a = %d, no_bottom_b = %d, strategy = %d, cost = %d\n", next_op.cur_a->val, next_op.cur_b->val, next_op.size_a, next_op.size_b, next_op.no_top_a, next_op.no_top_b, next_op.no_bottom_a, next_op.no_bottom_b, next_op.strategy, next_op.cost);
}

void	exec_next_op(t_stack **a, t_stack **b, t_next_op next_op, t_opcodes *opcodes)
{
	if (next_op.strategy == UPUP)
		exec_upup(a, b, next_op, opcodes);
	else if (next_op.strategy == UPDOWN)
		exec_updown(a, b, next_op, opcodes);
	else if (next_op.strategy == DOWNUP)
		exec_downup(a, b, next_op, opcodes);
	else if (next_op.strategy == DOWNDOWN)
		exec_downdown(a, b, next_op, opcodes);
	
	op_push(b, a);
	add_opcode(opcodes, "pb\n");
//	printf("pb\n");
}