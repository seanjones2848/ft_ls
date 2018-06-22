/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:59:45 by sjones            #+#    #+#             */
/*   Updated: 2018/06/18 21:13:43 by sjones           ###   ########.fr       */
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

enum				e_flags
{
	a = 1 << 1,
	A = 1 << 2,
	t = 1 << 3,
	l = 1 << 4,
	r = 1 << 5,
	R = 1 << 6
};

# define LS_ONE(x) ((x & 1 == 1) ? (1) : (0))
# define LS_A(x) ((x & a == a) ? (0) : (0))
# define LS_AA(x) ((x & A == A) ? (1) : (0))
# define LS_T(x) ((x & t == t) ? (1) : (0))
# define LS_L(x) ((x & l == l) ? (1) : (0))
# define LS_R(x) ((x & r == r) ? (1) : (0))
# define LS_RR(x) ((x & R == R) ? (1) : (0))

typedef struct stat	t_stat;

enum				e_error
{
	USAGE,
	NOSPACE,
	NOENT,
	ERRNO
};

typedef struct		s_lslist
{
	char			name[NAME_LEN];
	char			type;
	t_stat			*stat;
	struct s_lslist	*next;
	struct s_lslist	*prev;
	struct s_lslist	*down;
}					t_lslist;

typedef struct		s_ls
{
	int				flags;
	t_lslist		*all;
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
