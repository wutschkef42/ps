/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:28:32 by fwutschk          #+#    #+#             */
/*   Updated: 2018/10/01 19:28:36 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_opcode(t_opcodes *opc, char *code)
{
	if (opc->i + ft_strlen(code) > BUFSIZE)
	{
		ft_printf("%s", opc->buf);
		opc->i = 0;
		ft_bzero(opc->buf, BUFSIZE);
	}
	ft_memccpy(&(opc->buf[opc->i]), code, 0, max(ft_strlen(code), BUFSIZE));
	opc->i += ft_strlen(code);
}

void	add_opcode2(t_opcodes *opc, char *code)
{
	if (opc->i + ft_strlen(code) > BUFSIZE)
	{
		ft_printf("%s", opc->buf);
		opc->i = 0;
		ft_bzero(opc->buf, BUFSIZE);
	}
	ft_memccpy(&(opc->buf[opc->i]), code, 0, max(ft_strlen(code), BUFSIZE));
	opc->i += ft_strlen(code);
	opc->buf[opc->i] = '\n';
	opc->i += 1;
}

void	pop_opcode(t_opcodes *opc)
{
	if (opc->i == 0)
		return ;
	opc->i -= 2;
	while (opc->i >= 0 && opc->buf[opc->i] != '\n')
	{
		opc->buf[opc->i] = '\0';
		opc->i -= 1;
	}
	opc->i += 1;
}
