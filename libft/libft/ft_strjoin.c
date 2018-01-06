/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:50:08 by sjones            #+#    #+#             */
/*   Updated: 2017/01/11 15:14:26 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	char	*sub;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(sub = ft_strnew((ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		t = sub;
		while (*s1)
		{
			*t = *s1;
			s1++;
			t++;
		}
		while (*s2)
		{
			*t = *s2;
			s2++;
			t++;
		}
		return (sub);
	}
	return (NULL);
}
