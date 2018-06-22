/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 22:16:45 by sjones            #+#    #+#             */
/*   Updated: 2018/05/07 15:42:34 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	trav(t_lslist *l, t_ls *ls, int d)
{
	t_lslist *t;

	t = d ? l->prev : l->next;
	l->type == 'f' ? ls_listfile(l->name, ls) : ls_listdir(l->name, ls);
	while (l != t)
	{
		t->type == 'f' ? ls_listfile(t->name, ls) : ls_listdir(t->name, ls);
		t = d ? t->prev : t->next;
	}
}

void		ls_main(t_ls *ls)
{
	if (ls->all)
		LS_R(ls->flags) ? trav(ls->all, ls, 1) : trav(ls->all, ls, 0);
	else if (!LS_RR(ls->flags))
		ls_listdir(".", ls);
}
