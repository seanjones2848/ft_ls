/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:58 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 17:08:21 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>

typedef union
{
	char		c;
	char		*s;
	wchar_t		*w;
	intmax_t	i;
	uintmax_t	u;
	void		*v;
}				t_types;

typedef struct	s_print
{
	bool		hash;
	bool		zero;
	bool		plus;
	bool		minus;
	bool		space;
	int			width;
	int			prec;
	char		type;
	char		*l_mod;
	va_list		args;
	t_types		arg;
	char		*fmt;
	char		*num;
	char		sign;
	int			spaces;
	int			zeroes;
	int			len;
	int			ret;
	int			fd;
	int			i;
}				t_print;

/*
** printf types
*/

int				ft_printf(const char *fmt, ...);
int				ft_fprintf(int fd, const char *fmt, ...);

/*
** printf meat
*/

void			prt_init_print(t_print *p, int fd, char *fmt);
void			prt_printf_meat(t_print *p);
void			prt_arg_handle(t_print *p);
void			prt_get_flags(t_print *p);
void			prt_get_prec(t_print *p);
void			prt_get_width(t_print *p);
void			prt_get_length(t_print *p);
void			prt_convert(t_print *p);
void			prt_unconvert(t_print *p);
void			prt_reset(t_print *p);
void			prt_print_char(t_print *p, char c, int t);
void			prt_print_num(t_print *p);
int				prt_is_flag(char c);
int				prt_is_type(char c);
int				prt_is_length(char c);

/*
** formaters
*/

void			prt_charify(t_print *p);
void			prt_stringify(t_print *p);
void			prt_wide_stringify(t_print *p);
void			prt_octalfy(t_print *p);
void			prt_decimalfy(t_print *p);
void			prt_undecimalfy(t_print *p);
void			prt_hexify(t_print *p);
void			prt_pointerfy(t_print *p);

/*
** error
*/

int				prt_is_error(char c);
void			prt_get_error(t_print *p);

/*
** Debug functions
*/

void			prt_print_all(t_print *p);

#endif
