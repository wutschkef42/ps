
#include "push_swap.h"


void	execute_op(t_stack **a, t_stack **b, char *buffer)
{
	printf("op: %s\n", buffer);
	if (strncmp(buffer, SA, 2) == 0)
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
	else if (strncmp(buffer, RR, 2) == 0)
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
