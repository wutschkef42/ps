/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:28:10 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:28:12 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_assoc	get_op(int i)
{
	static const t_op_assoc	op_pairs[] = {
		{"sa", "sa"},
		{"sb", "sb"},
		{"ss", "ss"},
		{"pa", "pb"},
		{"pb", "pa"},
		{"ra", "rra"},
		{"rb", "rrb"},
		{"rr", "rrr"},
		{"rra", "ra"},
		{"rrb", "rb"},
		{"rrr", "rr"},
		{NULL, NULL}
	};

	return (op_pairs[i]);
}

static int	backtracking(t_stack **a, t_stack **b, t_bt *vars, t_opcodes *opc)
{
	int			i;
	t_op_assoc	op_pair;

	if (vars->depth >= vars->max_depth)
		return (0);
	if (is_sorted(*a) && stack_size(*b) == 0)
		return (1);
	i = 0;
	while (i <= 10)
	{
		op_pair = get_op(i);
		if ((i == 3 && stack_size(*b) == 0) || (i == 4 && stack_size(*a) == 0))
			op_pair.rev_op = NULL;
		execute_op_wrapper_lol(a, b, op_pair.op);
		add_opcode2(opc, op_pair.op);
		vars->depth += 1;
		if (backtracking(a, b, vars, opc))
			return (1);
		execute_op_wrapper_lol(a, b, op_pair.rev_op);
		pop_opcode(opc);
		vars->depth -= 1;
		i++;
	}
	return (0);
}

void		trim_trailing_spaces(t_opcodes *opc)
{
	int	i;

	i = opc->i - 1;
	while ((opc->buf)[i] == '\n')
	{
		(opc->buf)[i] = '\0';
		i--;
	}
}

void		bruteforce(t_stack **a, t_stack **b)
{
	t_opcodes	opc;
	t_bt		vars;

	opc.i = 0;
	vars.depth = 0;
	vars.max_depth = 0;
	while (1)
	{
		if (backtracking(a, b, &vars, &opc))
		{
			trim_trailing_spaces(&opc);
			ft_printf("%s\n", opc.buf);
			return ;
		}
		vars.max_depth += 1;
	}
}
