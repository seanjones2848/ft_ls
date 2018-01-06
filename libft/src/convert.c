/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:37 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:11:18 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_unconvert(t_print *p)
{
	if (!(p->l_mod))
		p->arg.u = (unsigned int)va_arg(p->args, unsigned long long int);
	else if (!(ft_strcmp(p->l_mod, "hh")))
		p->arg.u = (unsigned char)va_arg(p->args, unsigned long long int);
	else if (!(ft_strcmp(p->l_mod, "h")))
		p->arg.u = (unsigned short)va_arg(p->args, unsigned long long int);
	else if (!(ft_strcmp(p->l_mod, "ll")))
		p->arg.u = (unsigned long long)va_arg(p->args, unsigned long long int);
	else if (!(ft_strcmp(p->l_mod, "l")))
		p->arg.u = (unsigned long)va_arg(p->args, unsigned long long int);
	else if (!(ft_strcmp(p->l_mod, "j")))
		p->arg.u = (uintmax_t)va_arg(p->args, unsigned long long int);
	else if (!(ft_strcmp(p->l_mod, "z")))
		p->arg.u = (size_t)va_arg(p->args, unsigned long long int);
}

void	prt_convert(t_print *p)
{
	if (!(p->l_mod))
		p->arg.i = (int)va_arg(p->args, long long int);
	else if (!(ft_strcmp(p->l_mod, "hh")))
		p->arg.i = (signed char)va_arg(p->args, long long int);
	else if (!(ft_strcmp(p->l_mod, "h")))
		p->arg.i = (short)va_arg(p->args, long long int);
	else if (!(ft_strcmp(p->l_mod, "ll")))
		p->arg.i = (long long)va_arg(p->args, long long int);
	else if (!(ft_strcmp(p->l_mod, "l")))
		p->arg.i = (long)va_arg(p->args, long long int);
	else if (!(ft_strcmp(p->l_mod, "j")))
		p->arg.i = (intmax_t)va_arg(p->args, long long int);
	else if (!(ft_strcmp(p->l_mod, "z")))
		p->arg.i = (size_t)va_arg(p->args, long long int);
}
