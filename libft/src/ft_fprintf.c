/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:47 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:12:53 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_fprintf(int fd, const char *fmt, ...)
{
	t_print		p;

	prt_init_print(&p, fd, (char*)fmt);
	va_start(p.args, fmt);
	prt_printf_meat(&p);
	va_end(p.args);
	return (p.ret);
}
