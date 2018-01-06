/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:58:57 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 22:58:02 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init(t_ls *ls)
{
	ls->flags = 0;
	ls->f = NULL;
	ls->d = NULL;
}

int			main(int ac, char **av)
{
	t_ls	ls;

	init(&ls);
	ls_parse(av, &ls);
	ls_main(&ls);
	ls_free(&ls);
	return (0);
}
