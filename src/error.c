/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:16:34 by sjones            #+#    #+#             */
/*   Updated: 2018/01/05 22:58:11 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_error(int error, char *message)
{
	if (error == USAGE)
		ft_fprintf(2, "usage: ft_ls [-1aAltrR] [file ...]\n");
	if (error == NOSPACE)
		ft_fprintf(2, "not enough space to malloc a %s\n", message);
	if (error == NOENT)
		ft_fprintf(2, "ft_ls: %s: No, such file or directory\n", message);
	exit(-1);
}
