/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:29:58 by sjones            #+#    #+#             */
/*   Updated: 2017/11/27 14:03:54 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned long long int value, int base)
{
	unsigned long long int	n;
	char					*ret;
	int						len;
	int						i;

	n = ABS(value);
	len = 1;
	i = 0;
	while (n && (len++))
		n /= base;
	if (value == 0)
		len = 2;
	len += IS_NEG(value);
	ret = (char*)malloc(sizeof(char) * len);
	if (IS_NEG(value))
		ret[i] = '-';
	i = len - 1;
	n = ABS(value);
	while (--i >= IS_NEG(value))
	{
		ret[i] = HEX[n % base];
		n /= base;
	}
	ret[len - 1] = '\0';
	return (ret);
}
