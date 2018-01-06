/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:30:24 by sjones            #+#    #+#             */
/*   Updated: 2017/01/07 17:01:00 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*s;
	unsigned char	*d;
	unsigned char	c1;

	s = src;
	d = dst;
	c1 = c;
	while (n-- > 0)
	{
		*d++ = *s++;
		if (*(d - 1) == c1)
			return (d);
	}
	return (NULL);
}
