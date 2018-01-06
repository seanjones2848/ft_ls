/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:37:56 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 22:58:08 by sjones           ###   ########.fr       */
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
	return (new);
}

void		add_time(t_lslist *l, t_lslist *n)
{
	t_lslist *t;

	if (l == NULL)
		l = n;
	else
	{
		t = l;
		while (t->stat->st_mtimespec.tv_nsec <= n->stat->st_mtimespec.tv_nsec)
			t = t->next;
		if (t->stat->st_mtimespec.tv_nsec == n->stat->st_mtimespec.tv_nsec)
			if (ft_strcmp(t->name, n->name) < 0)
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

int			add(char *name, char type, t_ls *ls)
{
	t_lslist *new;

	new = ls_new_node(name, type);
	if (type == 'f')
	{
		if (LS_T(ls->flags))
			add_time(ls->f, new);
		else
			add_node(ls->f, new);
	}
	else
	{
		if (LS_T(ls->flags))
			add_time(ls->d, new);
		else
			add_node(ls->d, new);
	}
}
