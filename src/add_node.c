/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:37:56 by sjones            #+#    #+#             */
/*   Updated: 2018/05/07 23:52:50 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lslist	*ls_new_node(char *name, char type)
{
	t_lslist	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		ls_error(NOSPACE, "new node");
	ft_strcpy(new->name, name);
	new->type = type;
	new->prev = NULL;
	new->next = NULL;
	new->down = NULL;
	return (new);
}

int			cmp_time(t_lslist *l, t_lslist *n)
{
	if (l->stat->st_mtimespec.tv_sec < n->stat->st_mtimespec.tv_sec)
		return (1);
	else if (l->stat->st_mtimespec.tv_sec == n->stat->st_mtimespec.tv_sec)
	{
		if (l->stat->st_mtime < n->stat->st_mtime)
			return (1);
		else if (l->stat->st_mtime == n->stat->st_mtime)
		{
			if (l->stat->st_mtimespec.tv_nsec < n->stat->st_mtimespec.tv_nsec)
				return (1);
			else if (l->stat->st_mtimespec.tv_nsec ==
					n->stat->st_mtimespec.tv_nsec)
				if (ft_strcmp(l->name, n->name) < 0)
					return (1);
		}
	}
	return (0);
}

void		add_time(t_lslist *l, t_lslist *n)
{
	t_lslist *t;

	if (l == NULL)
		l = n;
	else
	{
		t = l;
		while (cmp_time(t,n))
			t = t->next;
		n->prev = t;
		n->next = t->next;
		t->next = n;
	}
}

void		add_node(t_lslist *l, t_lslist *n)
{
	t_lslist *t;

	if (l == NULL)
		l = n;
	else
	{
		t = l;
		while (ft_strcmp(t->name, n->name) < 0)
			t = t->next;
		n->prev = t;
		n->next = t->next;
		t->next = n;
	}
}

void		ls_add(char *name, char type, t_ls *ls)
{
	t_lslist *new;

	new = ls_new_node(name, type);
	if (LS_T(ls->flags))
		add_time(ls->all, new);
	else
		add_node(ls->all, new);
}
