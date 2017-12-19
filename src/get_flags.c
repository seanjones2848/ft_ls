/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:15:47 by sjones            #+#    #+#             */
/*   Updated: 2017/12/18 17:00:45 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_flag(char c)
{
	return (c == 'a' || c == 'l' || c == 'R' || c == 'r' || c == 't') ?
		(1) : (0);
}

void	grab_flags(char *av, t_flags *flags)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (is_flag(av[i])
		{
			if (av[i]
		}
		else
			error(flags);
	}
}


t_flags	*get_flags(char **av)
{
	t_flags	*flags;
	int		i;

	i = 0;
	while (av[++i])
	{
		if (avi[i][0] == '-')
			grab_flags(av[i], flags)
		else
			break;
	}
	return (flags);
}
