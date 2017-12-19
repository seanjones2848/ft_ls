/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:42:35 by sjones            #+#    #+#             */
/*   Updated: 2017/01/10 17:11:12 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	while (*s && len)
	{
		*d = *s;
		s++;
		d++;
		len--;
	}
	while (len)
	{
		*d = '\0';
		d++;
		len--;
	}
	return (dst);
}
