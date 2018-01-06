/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:32:28 by sjones            #+#    #+#             */
/*   Updated: 2017/01/10 16:37:10 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *t1;
	unsigned char *t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (*t1 == *t2)
		{
			t1++;
			t2++;
		}
		else
			return (*t1 - *t2);
	}
	return (0);
}
