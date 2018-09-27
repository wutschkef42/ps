
#include "push_swap.h"

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

int		stack_size(t_stack *s)
{
	int	size;

	size = 0;
	while (s)
	{
		s = s->next;
		size++;
	}
	return (size);
}
