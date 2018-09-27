
#include "push_swap.h"


void	execute_op(t_stack **a, t_stack **b, char *buffer)
{
	if (strcmp(buffer, SA) == 0)
		op_swap(*a);
	else if (strcmp(buffer, SB) == 0)
		op_swap(*b);
	else if (strcmp(buffer, SS) == 0)
		op_swap_both(*a, *b);
	else if (strcmp(buffer, PA) == 0)
		op_push(a, b);
	else if (strcmp(buffer, PB) == 0)
		op_push(b, a);
	else if (strcmp(buffer, RA) == 0)
		op_rotate(a);
	else if (strcmp(buffer, RB) == 0)
		op_rotate(b);
	else if (strcmp(buffer, RR) == 0)
		op_rotate_both(a, b);
	else if (strcmp(buffer, RRA) == 0)
		op_rev_rotate(a);
	else if (strcmp(buffer, RRB) == 0)
		op_rev_rotate(b);
	else if (strcmp(buffer, RRR) == 0)
		op_rev_rotate_both(a, b);
	else
		exit_error();
}
