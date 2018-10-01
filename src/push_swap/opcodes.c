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
	if (opc->i + strlen(code) > BUFSIZE)
	{
		ft_printf("%s", opc->buf);
		opc->i = 0;
		bzero(opc->buf, BUFSIZE);
	}
	ft_memccpy(&(opc->buf[opc->i]), code, 0, max(ft_strlen(code), BUFSIZE);
	opc->i += ft_strlen(code);
}
