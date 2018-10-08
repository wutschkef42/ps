/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:31:34 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:27:25 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*buffer;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (!(a = read_input(ac, av)))
		return (0);
	buffer = NULL;
	while (get_next_line(0, &buffer))
	{
		execute_op_wrapper_lol(&a, &b, buffer);
		ft_printf("stack a:\n");
		print_stack(a);
		ft_printf("stack b:\n");
		print_stack(b);
		bzero(buffer, ft_strlen(buffer));
	}
	if (is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
