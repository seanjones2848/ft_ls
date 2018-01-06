/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:59:45 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 22:57:55 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/src/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdbool.h>

# define NAME_LEN 256
# define LS_ONE(x) ((x && 1) ? (1) : (0))
# define LS_A(x) ((x && (1 << 1)) ? (0) : (0))
# define LS_AA(x) ((x && (1 << 2)) ? (1) : (0))
# define LS_T(x) ((x && (1 << 3)) ? (1) : (0))
# define LS_L(x) ((x && (1 << 4)) ? (1) : (0))
# define LS_R(x) ((x && (1 << 5)) ? (1) : (0))
# define LS_RR(x) ((x && (1 << 6)) ? (1) : (0))

enum				e_error
{
	USAGE,
	NOSPACE,
	NOENT,
	ERRNO
};

enum				e_flags
{
	a = 1 << 1,
	A = 1 << 2,
	t = 1 << 3,
	l = 1 << 4,
	r = 1 << 5,
	R = 1 << 6
};

typedef struct		s_lslist
{
	char			name[NAME_LEN];
	char			type;
	struct stat		*stat;
	s_lslist		*next;
	s_lslist		*prev;
}					t_lslist;

typedef struct		s_ls
{
	int				flags;
	t_lslist		*f;
	t_lslist		*d;
}					t_ls;

/*
**	error.c
*/

void				ls_error(int error, char *message);

/*
**	parse.c
*/

void				ls_parse(char **av, t_ls *ls);

/*
**	add_node.c
*/

void				ls_add(char *name, char type, t_ls *ls);

/*
**	free.c
*/

void				ls_free(t_ls *ls);

/*
**	ls.c
*/

void				ls_main(t_ls *ls);

/*
**	list.c
*/

void				ls_listfile(char *name, t_ls *ls);
void				ls_listdir(char *name, t_ls *ls);

#endif
