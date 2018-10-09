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

static int		count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static t_stack	*read_string_input(char **av)
{
	t_stack	*a;
	int		i;
	char	**tab;

	tab = ft_strsplit(av[1], ' ');
	a = NULL;
	i = count_words(av[1], ' ') - 1;
	if (i == -1)
		exit_error(a, NULL);
	while (i >= 0)
	{
		if (is_nan(tab[i]) || is_int_overflow(tab[i]))
		{
			exit_error(a, NULL);
		}
		push(&a, new(ft_atoi(tab[i])));
		i--;
	}
	if (has_duplicates(a))
	{
		exit_error(a, NULL);
	}
	free_tab(tab);
	return (a);
}

t_stack			*read_input(int ac, char **av)
{
	t_stack	*a;
	int		i;

	if (ac == 2)
		return (read_string_input(av));
	a = NULL;
	i = ac - 1;
	while (i > 0)
	{
		if (is_nan(av[i]) || is_int_overflow(av[i]))
		{
			exit_error(a, NULL);
		}
		push(&a, new(ft_atoi(av[i])));
		i--;
	}
	if (has_duplicates(a))
	{
		exit_error(a, NULL);
	}
	return (a);
}
