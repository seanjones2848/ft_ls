/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:35 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:15:30 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_print_char(t_print *p, char c, int t)
{
	p->ret += t;
	while (t > 0)
	{
		ft_putchar_fd(c, p->fd);
		t--;
	}
}

void	prt_print_num(t_print *p)
{
	p->ret += write(p->fd, p->num, p->len);
}

/*
** For debuging
**
**void	print_all(t_print *p)
**{
**	printf("\n--All of the print_struct\nfmt {%s}\nnum {%s}\nsign {%c}\n
**spaces {%d}\nzeroes {%d}\nlen {%d}\nret {%d}\ni {%d}\n--All flags\nhash {%d}\n
**zero {%d}\nplus {%d}\nminus {%d}\nspace {%d}\nwidth {%d}\nprec {%d}\n
**type {%c}\nlength {%s}\n\n", p->fmt, p->num, p->sign, p->spaces, p->zeroes,
**p->len, p->ret, p->i, (int)p->hash, (int)p->zero, (int)p->plus, (int)p->minus,
**(int)p->space, p->width, p->prec, p->type, p->l_mod);
**}
*/
