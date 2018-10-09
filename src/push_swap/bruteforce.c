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
	int			push_had_effect;
	t_op_assoc	op_pair;

	
	if (vars->depth >= vars->max_depth)
	{
		return (0);	
	}
	if (is_sorted(*a) && stack_size(*b) == 0)
	{
		//ft_printf("what\n");	
		return (1);
	}
	i = 0;
	while (i <= 10)
	{
		push_had_effect = 0;

		// if i == 11 (last operation has been tried) break
		//if (i >= 11)
		//	break ;
		// get i-th operation
		op_pair = get_op(i);
		
		// apply i-th op and add it to opc
		//ft_printf("op: %s\n", op_pair.op);
		//ft_printf("i: %d\n", i);
		//t_printf("opc i: %d\n", opc->i);
		if (i == 3 && stack_size(*b) == 0)
		{
	//		ft_printf("CLACK A\n");
			op_pair.rev_op = NULL;
		}
		if (i == 4 && stack_size(*a) == 0)
		{
			op_pair.rev_op = NULL;
		}
	//	ft_printf("i: %d\n", i);
		execute_op_wrapper_lol(a, b, op_pair.op);
		
		add_opcode2(opc, op_pair.op);
	//	ft_printf("buf: %s\n", opc->buf);
		vars->depth += 1;
	//	ft_printf("depth: %d\n", vars->depth);
	//	ft_printf("max depth: %d\n", vars->max_depth);
		
		if (backtracking(a, b, vars, opc))
				return (1);
		// undo i-th op and delete it from opc
		
	//	ft_printf("UNDO: ");
	//	if (i != 3)
//		{
		execute_op_wrapper_lol(a, b, op_pair.rev_op);
	//	}
	//	else if (push_had_effect)
		//	execute_op_wrapper_lol(a, b, op_pair.rev_op);

		//ft_printf("i: %d\n", i);
		pop_opcode(opc);
		vars->depth -= 1;
	//	ft_printf("buf after pop hamdulah: %s\n", opc->buf);
	//	ft_printf("opc i after pop hamdulah: %d\n", opc->i);
		i++;
	//	ft_printf("inshallah\n");
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
	//`		ft_printf("ALLAHUAKBAR\n");
			return ;
		}
		vars.max_depth += 1;
	}
}

