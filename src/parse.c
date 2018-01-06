/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:15:47 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 22:14:01 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_flags(char *av, t_ls *ls)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (av[i] == 'a' || av[i] == 'A' || av[i] == 'l' || av[i] == 'R'
				|| av[i] == 'r' || av[i] == 't' || av[i] == '1')
			ls->flags |= av[i] == '1' ? (1) : av[i];
		else
			ls_error(USAGE, NULL);
	}
}

static int	ls_check_file(char *file)
{
	char			*name;
	char			*path;
	DIR				*dir;
	struct dirent	*sd;

	name = (name = strrchr(file, '/') + 1) ? (name) : (file);
	path = ((path = strrchr(file, '/'))) ? (ft_strndup(file, file - path)) :
		(ft_strdup("./"));
	if(!(dir = opendir(path)))
		return (0);
	free(path);
	while ((sd = readdir(dir)))
		if (ft_strcmp(sd->d_name, name) == 0)
			return (1);
	closedir(dir);
	return (0);
}

static void	get_places(char *av, t_ls *ls)
{
	DIR	*dir;

	if ((dir = opendir(av)))
	{
		ls_add(av, 'd', ls);
		closedir(dir);
	}
	else
		if (ls_check_file(av))
			ls_add(av, 'f', ls);
	ls_error(NOENT, av);
}

void		ls_parse(char **av, t_ls *ls)
{
	int	i;

	i = 0;
	while (av[++i] && av[i][0] == '-')
		get_flags(av[i], ls);
	while (av[++i])
		get_places(av[i], ls);
}
