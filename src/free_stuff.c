

#include "libft.h"
#include "push_swap.h"

void	free_stack(t_stack *s)
{
	if (!s)
		return ;
	free_stack(s->next);
	free(s);
}
