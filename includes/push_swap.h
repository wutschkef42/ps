

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

#define BUFSIZE 0xFFFF

#define VAL(x)	x->val

enum				e_strategy
{
	UPUP = 1,
	UPDOWN,
	DOWNUP,
	DOWNDOWN
};


typedef struct	s_stack
{
	int				val;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_next_op
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	t_stack	*min_a;
	t_stack	*min_b;
	int		size_a;
	int		size_b;
	int		no_top_a;
	int		no_top_b;
	int		no_bottom_a;
	int		no_bottom_b;
	int		strategy;
	int		cost;
}				t_next_op;


typedef struct 	s_opcodes
{
	char	buf[BUFSIZE];
	int		i;
}				t_opcodes;

/* stack.c */

t_stack	*new(int val);
void	push(t_stack **stack, t_stack *new);
t_stack	*pop(t_stack **stack);
void	print_stack(t_stack *s);
int		is_sorted(t_stack *s);
int		stack_size(t_stack *s);


/* util.c */
void	exit_error();
int		is_nan(char *s);
int		is_int_overflow(char *s);
int		has_duplicates(t_stack *s);
int		max(int a, int b);

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

/* calc_cost.c */
int	calc_cost(t_next_op *next_op);

/* exec_next_op.c */
void	exec_next_op(t_stack **a, t_stack **b, t_next_op next_op, t_opcodes *opcodes);

/* opcodes.c */
void    add_opcode(t_opcodes *opcodes, char *op);

#endif
