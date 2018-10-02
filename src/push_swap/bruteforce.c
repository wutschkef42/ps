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


/*
** brute force small stacks ... because yallah
** stacks with <= 6 elements can be brute forced.
** there are 12 operations in total,
** so 6^12 = 2 billion possibilities
**
** backtracking approach
**
*/

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

/*
** opc contains string of opcodes, separated by \n
*/
static int	backtracking(t_stack **a, t_stack **b, t_bt *vars, t_opcodes *opc)
{
	int			i;
	t_op_assoc	op_pair;

	if (vars->depth == vars->max_depth)
		return (0);	
	if (is_sorted(*a) && is_sorted(*b))
		return (1);
	i = 0;
	while (1)
	{

		// if i == 11 (last operation has been tried) break
		if (i == 11)
			break ;
		// get i-th operation
		op_pair = get_op(i);
		
		// apply i-th op and add it to opc
		ft_printf("op: %s\n", op_pair.op);
		execute_op_wrapper_lol(a, b, op_pair.op);
		
		add_opcode(opc, op_pair.op);
		
		vars->depth += 1;
		
		if (backtracking(a, b, vars, opc))
				return (1);
		// undo i-th op and delete it from opc
		
		execute_op_wrapper_lol(a, b, op_pair.rev_op);
		pop_opcode(opc);
		i++;
	}
	return (0);
}



void	bruteforce(t_stack **a, t_stack **b)
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
			ft_printf("%s", opc.buf);
			return ;
		}
		vars.max_depth += 1;
	}
}

