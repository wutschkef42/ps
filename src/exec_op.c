/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:06:53 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:33:19 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		has_trailing_spaces(char *buffer)
{
	if (ft_strlen(buffer) == 2)
		return (1);
	if (ft_strlen(buffer) == 3)
		if (ft_strncmp(buffer, "rra", 3) == 0
				|| ft_strncmp(buffer, "rrb", 3) == 0
				|| ft_strncmp(buffer, "rrr", 3) == 0)
			return (1);
	return (0);
}

void	execute_op(t_stack **a, t_stack **b, char *buffer)
{
	if (ft_strncmp(buffer, SA, 2) == 0)
		op_swap(*a);
	else if (ft_strncmp(buffer, SB, 2) == 0)
		op_swap(*b);
	else if (ft_strncmp(buffer, SS, 2) == 0)
		op_swap_both(*a, *b);
	else if (ft_strncmp(buffer, PA, 2) == 0)
		op_push(a, b);
	else if (ft_strncmp(buffer, PB, 2) == 0)
		op_push(b, a);
	else if (ft_strncmp(buffer, RA, 2) == 0)
		op_rotate(a);
	else if (ft_strncmp(buffer, RB, 2) == 0)
		op_rotate(b);
	else if (ft_strncmp(buffer, RR, 3) == 0)
		op_rotate_both(a, b);
	else if (ft_strncmp(buffer, RRA, 3) == 0)
		op_rev_rotate(a);
	else if (ft_strncmp(buffer, RRB, 3) == 0)
		op_rev_rotate(b);
	else if (ft_strncmp(buffer, RRR, 3) == 0)
		op_rev_rotate_both(a, b);
	else
		exit_error(*a, *b);
}

void	execute_op_wrapper_lol(t_stack **a, t_stack **b, char *buffer)
{
	if (!buffer)
		return ;
	if (has_trailing_spaces(buffer) == 0)
		exit_error(*a, *b);
	execute_op(a, b, buffer);
}
