/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:12:04 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:12:17 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rev_rotate(t_stack **a)
{
	t_stack *bottom;

	if (!*a || !((*a)->next))
		return ;
	bottom = *a;
	while (bottom->next->next)
	{
		bottom = bottom->next;
	}
	bottom->next->next = *a;
	*a = bottom->next;
	bottom->next = NULL;
}

void	op_rev_rotate_both(t_stack **a, t_stack **b)
{
	op_rev_rotate(a);
	op_rev_rotate(b);
}
