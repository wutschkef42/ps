/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:18:41 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:18:45 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	if (!s || !(s->next))
		return (1);
	if (s->val > s->next->val)
		return (0);
	return (is_sorted(s->next));
}
