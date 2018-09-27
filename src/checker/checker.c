
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
	print_stack(a);
	while (get_next_line(0, &buffer))
	{
		execute_op(&a, &b, buffer);
		printf("stack a:\n");
		print_stack(a);
		printf("stack b:\n");
		print_stack(b);
	}
	if (is_sorted(a) && !b)
		printf("OK\n");
	else
		printf("KO\n");
  	return(0);
}
