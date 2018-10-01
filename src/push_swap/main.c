
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
	print_stack(a);
	return (0);
}
