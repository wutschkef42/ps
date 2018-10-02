/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:28:26 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:28:30 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	if (!(a = read_input(ac, av)))
		return (0);
	if (is_sorted(a))
		return (0);
	if (stack_size(a) < 7)
		bruteforce(&a, &b);
	else
		solve(&a, &b);
	free_stack(a);
	free_stack(b);
	while (1);
	return (0);
}
