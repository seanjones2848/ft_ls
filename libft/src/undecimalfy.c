/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undecimalfy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:48 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:16:46 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format(t_print *p)
{
	if (p->plus)
		p->sign = '+';
	p->num = ft_uitoa_base(p->arg.u, 10);
	p->len = ft_strlen(p->num);
	if (p->prec > p->len)
		p->zeroes = p->prec - p->len;
	if (p->width > p->len + p->zeroes)
		p->spaces = p->width - (p->len + p->zeroes);
}

void		prt_undecimalfy(t_print *p)
{
	if (p->type == 'U')
		p->l_mod = "l";
	prt_unconvert(p);
	format(p);
	if (p->minus)
	{
		if (p->sign && (p->ret++))
			ft_putchar_fd(p->sign, p->fd);
		prt_print_char(p, '0', p->zeroes);
		prt_print_num(p);
		prt_print_char(p, ' ', p->spaces);
	}
	else
	{
		if (p->sign && !p->zero && (p->ret++))
			ft_putchar_fd(p->sign, p->fd);
		(p->zero) ? prt_print_char(p, '0', p->spaces)
			: prt_print_char(p, ' ', p->spaces);
		prt_print_char(p, '0', p->zeroes);
		prt_print_num(p);
	}
}
