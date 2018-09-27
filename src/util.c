
#include "libft.h"
#include "push_swap.h"



void	exit_error()
{
	printf("Error\n");
	exit(1);

}


int	max(int a, int b)
{
	return (a > b ? a : b);
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

int	is_int_overflow(char *s)
{
	if (ft_atol(s) > INT_MAX || ft_atol(s) < INT_MIN)
		return (1);	
	return(0);
}

int	has_duplicates(t_stack *s)
{
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