
#include "push_swap.h"



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
