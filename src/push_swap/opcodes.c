
#include "libft.h"
#include "push_swap.h"



void    add_opcode(t_opcodes *opc, char *code)
{
    if (opc->i + strlen(code) > BUFSIZE)
    {
        ft_printf("%s", opc->buf);
        opc->i = 0;
        bzero(opc->buf, BUFSIZE);
    }
    ft_memccpy(&(opc->buf[opc->i]), code, 0, ft_strlen(code));
    opc->i += ft_strlen(code);
}

