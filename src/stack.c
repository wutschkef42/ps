/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:16:02 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:23:13 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new(int val)
{
	t_stack	*new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->val = val;
	new->next = NULL;
	return (new);
}

void	push(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack	*pop(t_stack **stack)
{
	t_stack *p;

	p = *stack;
	if (*stack)
		*stack = (*stack)->next;
	return (p);
}

void	print_stack(t_stack *s)
{
	ft_printf("---\n");
	while (s)
	{
		ft_printf("%d\n", s->val);
		s = s->next;
	}
	ft_printf("---\n");
}

int		stack_size(t_stack *s)
{
	int	size;

	size = 0;
	while (s)
	{
		s = s->next;
		size++;
	}
	return (size);
}
