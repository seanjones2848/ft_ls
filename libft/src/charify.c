/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:31 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:11:25 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_spaces(t_print *p)
{
	p->spaces = p->width - p->len;
	while (p->spaces > 0)
	{
		p->ret = write(1, "          ", (p->spaces >= 10) ? (10) : (p->spaces));
		p->spaces -= (p->spaces >= 10) ? (10) : (p->spaces);
	}
}

void		prt_charify(t_print *p)
{
	p->arg.c = (char)va_arg(p->args, int);
	p->len = 1;
	if (p->minus)
	{
		prt_print_char(p, p->arg.c, 1);
		print_spaces(p);
	}
	else
	{
		print_spaces(p);
		prt_print_char(p, p->arg.c, 1);
	}
}
