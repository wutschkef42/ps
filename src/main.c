
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void	exit_error()
{
	printf("Error\n");
	exit(1);

}

typedef struct	s_stack
{
	int		val;
	struct s_stack	*next;
}		t_stack;


/* returns new stack element */
t_stack	*new(int val)
{
	t_stack	*new;
	
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->val = val;
	new->next = NULL;
	return (new);
}


/* push new element onto stack */
void	push(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

/* pop top element off stack */
t_stack	*pop(t_stack **stack)
{
	t_stack *p;

	p = *stack;
	
	if (*stack)
		*stack = (*stack)->next;
	return (p);
}

void	print_stack(t_stack *s)
{
	printf("---\n");
	while (s)
	{
		printf("%d\n", s->val);
		s = s->next;
	}
	printf("---\n");
}

/* returns 1 if stack is sorted */
int	is_sorted(t_stack *s)
{
	if (!s || !(s->next))
		return (1);
	if (s->val < s->next->val)
		return (0);
	return (is_sorted(s->next));
}


int	is_nan(char *s)
{
	int	i;
	
	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;	
	}
	return (0);
}

#define INT_MAX 2147483647
#define INT_MIN -214783648

int	is_int_overflow(char *s)
{
	if (atol(s) > INT_MAX || atol(s) < INT_MIN)
		return (1);	
	return(0);
}

int	has_duplicates(t_stack *s)
{
	int	val;
	t_stack *p;

	if (!s)
		return (0);
	p = s;
	while (p)
	{

		while (s)
		{
			if (p != s && p->val == s->val)
				return (1);
			s = s->next;
		}
		p = p->next;
	}	
	return (0);
}

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

/* swaps the topmost two elements of a */
void	op_swap(t_stack *a)
{
	int	tmp;

	if (a->next)
	{
		tmp = a->val;
		a->val = a->next->val;
		a->next->val = tmp;
	}		
}

void	op_swap_both(t_stack *a, t_stack *b)
{
	op_swap(a);
	op_swap(b);
}

/* pops element off b and pushes it on a */
void	op_push(t_stack **a, t_stack **b)
{
	t_stack	*p;

	if (!*b)
		return ;
	p = pop(b);
	push(a, p);	

}

/* shift up all elements by 1, first one becomes last one */
void	op_rotate(t_stack **a)
{
	t_stack	*top;
	
	top = *a;
	if (!top || !top->next)
		return ;
	*a = (*a)->next;
	while ((*a)->next)
		a = &((*a)->next);
	(*a)->next = top;
	top->next = NULL;
}


/* first element becomes last */
void	op_rotate_both(t_stack **a, t_stack **b)
{
	op_rotate(a);
	op_rotate(b);
}


/* last element becomes first */
void	op_rev_rotate(t_stack **a)
{
	t_stack *bottom;
	t_stack *p;

	if (!*a || !((*a)->next))
		return ;
	bottom = *a;
	while (bottom->next->next)
	{
		
		bottom = bottom->next;
	}
	bottom->next->next = *a;
	*a = bottom->next;
	bottom->next = NULL;
}

/* last element becomes first */
void	op_rev_rotate_both(t_stack **a, t_stack **b)
{
	op_rev_rotate(a);
	op_rev_rotate(b);
}



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


int	main(int ac, char **av) 
{
	char	*buffer;
	size_t	bufsize = 32;
	size_t	nread;
	t_stack	*a;
	t_stack	*b;
	b = NULL;
	if (!(a = read_input(ac, av)))
	{
		return (0);
	}
	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
        	perror("Unable to allocate buffer");
        	exit(1);
	}

	print_stack(a);
	while((nread = getline(&buffer, &bufsize, stdin)) > 0 && buffer[0])
	{
		buffer[nread-1] = '\0';
		execute_op(&a, &b, buffer);
		bzero(buffer, bufsize);
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
