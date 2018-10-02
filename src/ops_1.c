/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:11:06 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:11:55 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_stack *a)
{
	int	tmp;

	if (!a)
		return ;
	if (a->next)
	{
		tmp = a->val;
		a->val = a->next->val;
		a->next->val = tmp;
	}
}

void	op_swap_both(t_stack *a, t_stack *b)
{
	op_swap(a);
	op_swap(b);
}

void	op_push(t_stack **a, t_stack **b)
{
	t_stack	*p;

	if (!*b)
		return ;
	p = pop(b);
	push(a, p);
}

void	op_rotate(t_stack **a)
{
	t_stack	*top;

	top = *a;
	if (!top || !top->next)
		return ;
	*a = (*a)->next;
	while ((*a)->next)
		a = &((*a)->next);
	(*a)->next = top;
	top->next = NULL;
}

void	op_rotate_both(t_stack **a, t_stack **b)
{
	op_rotate(a);
	op_rotate(b);
}
