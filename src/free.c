/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:01:58 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 22:58:16 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	circle_free(t_lslist *l)
{
	t_lslist *t;
	while (l)
	{
		t = l;
		if (l->next)
			l = l->next;
		t->next = NULL;
		t->prev = NULL;
		free(t);
	}
}

void		ls_free(t_ls *ls)
{
	circle_free(ls->f);
	circle_free(ls->d);
}
