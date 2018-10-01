/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_next_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:28:23 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:28:25 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_upup(t_stack **a, t_stack **b,
		t_next_op next_op, t_opcodes *opcodes)
{
	int		i;

	i = 0;
	while (i < min(next_op.no_top_a, next_op.no_top_b))
	{
		op_rotate_both(a, b);
		add_opcode(opcodes, "rr\n");
		i++;
	}
	i = 0;
	while (i < max(next_op.no_top_a, next_op.no_top_b) -
			min(next_op.no_top_a, next_op.no_top_b))
	{
		if (next_op.no_top_a > next_op.no_top_b)
		{
			op_rotate(a);
			add_opcode(opcodes, "ra\n");
		}
		else
		{
			op_rotate(b);
			add_opcode(opcodes, "rb\n");
		}
		i++;
	}
}

static void	exec_updown(t_stack **a, t_stack **b,
		t_next_op next_op, t_opcodes *opcodes)
{
	int		i;

	i = 0;
	while (i < next_op.no_top_a)
	{
		op_rotate(a);
		add_opcode(opcodes, "ra\n");
		i++;
	}
	i = 0;
	while (i < next_op.no_bottom_b + 1)
	{
		op_rev_rotate(b);
		add_opcode(opcodes, "rrb\n");
		i++;
	}
}

static void	exec_downup(t_stack **a, t_stack **b,
		t_next_op next_op, t_opcodes *opcodes)
{
	int		i;

	i = 0;
	while (i < next_op.no_top_b)
	{
		op_rotate(b);
		add_opcode(opcodes, "rb\n");
		i++;
	}
	i = 0;
	while (i < next_op.no_bottom_a + 1)
	{
		op_rev_rotate(a);
		add_opcode(opcodes, "rra\n");
		i++;
	}
}

static void	exec_downdown(t_stack **a, t_stack **b,
		t_next_op next_op, t_opcodes *opcodes)
{
	int		i;

	i = 0;
	while (i < min(next_op.no_bottom_a, next_op.no_bottom_b) + 1)
	{
		op_rev_rotate_both(a, b);
		add_opcode(opcodes, "rrr\n");
		i++;
	}
	i = 0;
	while (i < max(next_op.no_bottom_a, next_op.no_bottom_b)
			- min(next_op.no_bottom_a, next_op.no_bottom_b))
	{
		if (next_op.no_bottom_a > next_op.no_bottom_b)
		{
			op_rev_rotate(a);
			add_opcode(opcodes, "rra\n");
		}
		else
		{
			op_rev_rotate(b);
			add_opcode(opcodes, "rrb\n");
		}
		i++;
	}
}

void		exec_next_op(t_stack **a, t_stack **b, t_next_op next_op,
		t_opcodes *opcodes)
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
}
