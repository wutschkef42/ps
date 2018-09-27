

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 2147483647
#define INT_MIN -214783648

/* available instructions */

#define SA	"sa"
#define SB	"sb"
#define SS	"ss"
#define PA	"pa"
#define PB	"pb"
#define RA	"ra"
#define RB	"rb"
#define RR	"rr"
#define RRA	"rra"
#define RRB	"rrb"
#define RRR	"rrr"

#define VAL(x)	x->val

typedef struct	s_stack
{
	int		val;
	struct s_stack	*next;
}		t_stack;


/* stack.c */

t_stack	*new(int val);
void	push(t_stack **stack, t_stack *new);
t_stack	*pop(t_stack **stack);
void	print_stack(t_stack *s);
int		is_sorted(t_stack *s);


/* util.c */
void	exit_error();
int		is_nan(char *s);
int		is_int_overflow(char *s);
int		has_duplicates(t_stack *s);


/* exec_op.c */
void	execute_op(t_stack **a, t_stack **b, char *buffer);


/* ops_1.c */
void	op_swap(t_stack *a);
void	op_swap_both(t_stack *a, t_stack *b);
void	op_push(t_stack **a, t_stack **b);
void	op_rotate(t_stack **a);
void	op_rotate_both(t_stack **a, t_stack **b);


/* ops_2.c */
void	op_rev_rotate(t_stack **a);
void	op_rev_rotate_both(t_stack **a, t_stack **b);


/* read_input.c */
t_stack	*read_input(int ac, char **av);

#endif
