/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base_u_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:37:55 by agaudry           #+#    #+#             */
/*   Updated: 2017/02/28 17:45:22 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long value, long long base)
{
	long long	len;

	len = 0;
	while (value >= base)
	{
		value = value / base;
		len++;
	}
	return (len + 1);
}

char		*ft_ltoa_base_u_conv(long long value, long long base)
{
	char		*ret;
	long long	i;

	if (base == 10)
		return (ft_ltoa_u_conv(value));
	if (value < 0 && base != 10)
		value = -value;
	ret = (char *)malloc(sizeof(char) * ft_len(value, base));
	if (ret == NULL)
		return (NULL);
	i = ft_len(value, base);
	ret[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (value % base < 10)
			ret[i] = value % base + 48;
		else
			ret[i] = value % base + 87;
		value = value / base;
		i--;
	}
	return (ret);
}
