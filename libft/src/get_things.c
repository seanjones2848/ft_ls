/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:08 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:13:41 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_is_length(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z') ? (1) : (0);
}

void	prt_get_flags(t_print *p)
{
	while (prt_is_flag(p->fmt[p->i]))
	{
		if (p->fmt[p->i] == '#')
			p->hash = true;
		else if (p->fmt[p->i] == '0')
			p->zero = true;
		else if (p->fmt[p->i] == '+')
			p->plus = true;
		else if (p->fmt[p->i] == '-')
			p->minus = true;
		else if (p->fmt[p->i] == ' ')
			p->space = true;
		p->i++;
	}
}

void	prt_get_prec(t_print *p)
{
	if (ft_isdigit(p->fmt[p->i]))
	{
		p->prec = ft_atoi(p->fmt + p->i);
		while (ft_isdigit(p->fmt[p->i]))
			p->i++;
	}
	else
		p->prec = 0;
}

void	prt_get_width(t_print *p)
{
	p->width = ft_atoi(p->fmt + p->i);
	while (ft_isdigit(p->fmt[p->i]))
		p->i++;
}

void	prt_get_length(t_print *p)
{
	if (p->fmt[p->i] == 'h' && p->fmt[p->i + 1] == 'h' && (p->i += 2))
		p->l_mod = "hh";
	else if (p->fmt[p->i] == 'h' && (p->i++))
		p->l_mod = "h";
	else if (p->fmt[p->i] == 'l' && p->fmt[p->i + 1] == 'l' && (p->i += 2))
		p->l_mod = "ll";
	else if (p->fmt[p->i] == 'l' && (p->i++))
		p->l_mod = "l";
	else if (p->fmt[p->i] == 'j' && (p->i++))
		p->l_mod = "j";
	else if (p->fmt[p->i] == 'z' && (p->i++))
		p->l_mod = "z";
}
