/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 22:51:29 by sjones            #+#    #+#             */
/*   Updated: 2018/05/07 23:51:40 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_listfile(char *name, t_ls *ls)
{
	(void)ls;
	printf("%s\n", name);
}

void	ls_listdir(char *name, t_ls *ls)
{
	(void)ls;
	printf("%s\n", name);
}
