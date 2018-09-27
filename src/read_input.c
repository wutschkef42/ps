
#include "push_swap.h"

t_stack	*read_input(int ac, char **av)
{
	t_stack	*a;		
	int	i;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		if (is_nan(av[i]) || is_int_overflow(av[i]))
			exit_error();
		push(&a, new(atoi(av[i])));
		i++;
	}
	if (has_duplicates(a))
		exit_error();
	return (a);
}

