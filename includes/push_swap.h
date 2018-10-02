/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:34:26 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:40:21 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <string.h>

# define INT_MAX	2147483647
# define INT_MIN	-214783648

# define SA			"sa"
# define SB			"sb"
# define SS			"ss"
# define PA			"pa"
# define PB			"pb"
# define RA			"ra"
# define RB			"rb"
# define RR			"rr"
# define RRA		"rra"
# define RRB		"rrb"
# define RRR		"rrr"
# define BUFSIZE	 0xFFFF
# define VAL(x)		x->val

enum				e_strategy
{
	UPUP = 1,
	UPDOWN,
	DOWNUP,
	DOWNDOWN
};

typedef struct		s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_next_op
{
	t_stack			*cur_a;
	t_stack			*cur_b;
	t_stack			*min_a;
	t_stack			*min_b;
	int				size_a;
	int				size_b;
	int				no_top_a;
	int				no_top_b;
	int				no_bottom_a;
	int				no_bottom_b;
	int				strategy;
	int				cost;
}					t_next_op;

typedef struct		s_opcodes
{
	char			buf[BUFSIZE];
	int				i;
}					t_opcodes;


typedef struct		s_bt
{
	int				depth;
	int				max_depth;
}					t_bt;

typedef struct		s_op_assoc
{
	char	*op;
	char	*rev_op;

}					t_op_assoc;




t_stack				*new(int val);
void				push(t_stack **stack, t_stack *new);
t_stack				*pop(t_stack **stack);
void				print_stack(t_stack *s);
int					is_sorted(t_stack *s);
int					stack_size(t_stack *s);
void				exit_error();
int					is_nan(char *s);
int					is_int_overflow(char *s);
int					has_duplicates(t_stack *s);
int					max(int a, int b);
int					min(int a, int b);
void				execute_op_wrapper_lol(t_stack **a, t_stack **b,
						char *buffer);
void				op_swap(t_stack *a);
void				op_swap_both(t_stack *a, t_stack *b);
void				op_push(t_stack **a, t_stack **b);
void				op_rotate(t_stack **a);
void				op_rotate_both(t_stack **a, t_stack **b);
void				op_rev_rotate(t_stack **a);
void				op_rev_rotate_both(t_stack **a, t_stack **b);
int					count_bottom(t_stack *first, t_stack *cur);
int					count_top(t_stack *first, t_stack *cur);
t_stack				*get_min_a(t_stack **a);
t_stack				*get_max_b(t_stack **b, int to_insert);
t_stack				*get_index_b(t_stack **b, int val);
t_stack				*read_input(int ac, char **av);
int					calc_cost(t_next_op *next_op);
void				exec_next_op(t_stack **a, t_stack **b, t_next_op next_op,
						t_opcodes *opcodes);
void				solve(t_stack **a, t_stack **b);
void				add_opcode(t_opcodes *opcodes, char *op);
void				pop_opcode(t_opcodes *opc);
void				bruteforce(t_stack **a, t_stack **b);
void				free_stack(t_stack *s);
#endif
