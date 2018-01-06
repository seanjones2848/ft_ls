/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octalfy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:24 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:15:10 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format(t_print *p)
{
	p->num = ft_uitoa_base(p->arg.u, 8);
	p->len = ft_strlen(p->num);
	if (p->hash && p->num[0] != '0')
		p->zeroes++;
	if (p->prec > p->len + p->zeroes)
		p->zeroes = p->prec - p->len;
	if (p->minus)
		p->spaces = p->width - (p->zeroes + p->len);
	else
		(p->zero) ? (p->zeroes += p->width - (p->zeroes + p->len))
			: (p->spaces = p->width - (p->zeroes + p->len));
}

void		prt_octalfy(t_print *p)
{
	if (p->type == 'O')
		p->l_mod = "l";
	prt_unconvert(p);
	format(p);
	if (p->minus)
	{
		prt_print_char(p, '0', p->zeroes);
		prt_print_num(p);
		prt_print_char(p, ' ', p->spaces);
	}
	else
	{
		prt_print_char(p, ' ', p->spaces);
		prt_print_char(p, '0', p->zeroes);
		prt_print_num(p);
	}
}
