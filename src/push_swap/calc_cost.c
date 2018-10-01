/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:28:19 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:28:21 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_upup(t_next_op *next_op)
{
	int	cost;

	cost = max(next_op->no_top_a, next_op->no_top_b);
	if (cost < next_op->cost)
	{
		next_op->strategy = UPUP;
		next_op->cost = cost;
		return (1);
	}
	return (0);
}

static int	calc_updown(t_next_op *next_op)
{
	int	cost;

	cost = next_op->no_top_a + (next_op->no_bottom_b + 1);
	if (cost < next_op->cost)
	{
		next_op->strategy = UPDOWN;
		next_op->cost = cost;
		return (1);
	}
	return (0);
}

static int	calc_downup(t_next_op *next_op)
{
	int	cost;

	cost = (next_op->no_bottom_a + 1) + next_op->no_top_b;
	if (cost < next_op->cost)
	{
		next_op->strategy = DOWNUP;
		next_op->cost = cost;
		return (1);
	}
	return (0);
}

static int	calc_downdown(t_next_op *next_op)
{
	int	cost;

	cost = max(next_op->no_bottom_a, next_op->no_bottom_b) + 1;
	if (cost < next_op->cost)
	{
		next_op->strategy = DOWNDOWN;
		next_op->cost = cost;
		return (1);
	}
	return (0);
}

int			calc_cost(t_next_op *next_op)
{
	if (calc_upup(next_op) || calc_updown(next_op) || calc_downup(next_op)
			|| calc_downdown(next_op))
		return (1);
	return (0);
}
