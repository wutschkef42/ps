/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:12:30 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:13:06 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*read_input(int ac, char **av)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = ac - 1;
	while (i > 0)
	{
		if (is_nan(av[i]) || is_int_overflow(av[i]))
		{
			ft_printf("a: %s\n", av[i]);
			exit_error(a, NULL);
		}
		push(&a, new(ft_atoi(av[i])));
		i--;
	}
	if (has_duplicates(a))
	{
		ft_printf("b\n");
		exit_error(a, NULL);
	}
	return (a);
}
