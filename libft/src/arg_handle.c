/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:19 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:10:33 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			prt_is_type(char c)
{
	return (c == 's' || c == 'S' || c == 'p'\
	|| c == 'd' || c == 'D' || c == 'i' || c == 'o'\
	|| c == 'O' || c == 'u' || c == 'U' || c == 'x'\
	|| c == 'X' || c == 'c' || c == 'C' || c == '%')\
	? (1) : (0);
}

int			prt_is_flag(char c)
{
	return (c == '#' || c == '0' || c == '+'\
	|| c == '-' || c == ' ') ? (1) : (0);
}

static int	set_type(t_print *p, char c)
{
	if ((prt_is_type(c)) && (p->type = c))
		return (1);
	return (0);
}

static void	get_specs(t_print *p)
{
	if (prt_is_flag(p->fmt[p->i]))
		prt_get_flags(p);
	if (ft_isdigit(p->fmt[p->i]))
		prt_get_width(p);
	if (p->fmt[p->i] == '.' && p->i++)
		prt_get_prec(p);
	if (prt_is_length(p->fmt[p->i]))
		prt_get_length(p);
	set_type(p, p->fmt[p->i]);
}

void		prt_arg_handle(t_print *p)
{
	p->i++;
	get_specs(p);
	if (p->type == 's')
		prt_stringify(p);
	else if (p->type == 'S')
		prt_wide_stringify(p);
	else if (p->type == 'p')
		prt_pointerfy(p);
	else if (p->type == 'd' || p->type == 'D' || p->type == 'i')
		prt_decimalfy(p);
	else if (p->type == 'o' || p->type == 'O')
		prt_octalfy(p);
	else if (p->type == 'u' || p->type == 'U')
		prt_undecimalfy(p);
	else if (p->type == 'x' || p->type == 'X')
		prt_hexify(p);
	else if (p->type == 'c' || p->type == 'C')
		prt_charify(p);
	else if (p->type == '%')
		p->ret = write(p->fd, "%", 1);
}
