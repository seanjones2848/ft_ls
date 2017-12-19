/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:59:45 by sjones            #+#    #+#             */
/*   Updated: 2017/12/18 16:30:19 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

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

typedef struct		s_flags
{
	bool			a;
	bool			l;
	bool			r;
	bool			t;
	bool			R;
}					t_flags;

typedef struct		s_attr
{
	DIR				*dir;
	struct dirent	*dirent;
	struct stat		*stat;
	struct passwd	*pwd;
	struct group	*grp;
	time_t			*time;
}					t_attr;

typedef struct		s_file
{
	DIR				*dir;
	s_attr			*attr;
	s_file			*next;
}					t_file;

typedef struct		s_ls
{
	t_flags			*flags;
	t_file			*files;
}					t_ls;

#endif
