#include "libft.h"
#include "push_swap.h"

int		has_trailing_spaces(char *buffer)
{
	// if op code has 2 chars we are good
	if (ft_strlen(buffer) == 2)
		return (1);
	// if opcode has 3 chars, it must be rra rrb or rrr
	if (ft_strlen(buffer) == 3)
		if (ft_strncmp(buffer, "rra", 3) == 0
			|| ft_strncmp(buffer, "rrb", 3) == 0
			|| ft_strncmp(buffer, "rrr", 3) == 0)
			return (1);
	// if opcode has more than 3 chars there is an error
	return (0);
}


void	execute_op(t_stack **a, t_stack **b, char *buffer)
{
	printf("%s\n", buffer);
	if (has_trailing_spaces(buffer) == 0)
		exit_error();
	else if (strncmp(buffer, SA, 2) == 0)
		op_swap(*a);
	else if (strncmp(buffer, SB, 2) == 0)
		op_swap(*b);
	else if (strncmp(buffer, SS, 2) == 0)
		op_swap_both(*a, *b);
	else if (strncmp(buffer, PA, 2) == 0)
		op_push(a, b);
	else if (strncmp(buffer, PB, 2) == 0)
		op_push(b, a);
	else if (strncmp(buffer, RA, 2) == 0)
		op_rotate(a);
	else if (strncmp(buffer, RB, 2) == 0)
		op_rotate(b);
	else if (strncmp(buffer, RR, 3) == 0)
		op_rotate_both(a, b);
	else if (strncmp(buffer, RRA, 3) == 0)
		op_rev_rotate(a);
	else if (strncmp(buffer, RRB, 3) == 0)
		op_rev_rotate(b);
	else if (strncmp(buffer, RRR, 3) == 0)
		op_rev_rotate_both(a, b);
	else
		exit_error();
}
