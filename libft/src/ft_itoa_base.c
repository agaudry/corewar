/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:49:26 by agaudry           #+#    #+#             */
/*   Updated: 2017/01/29 18:20:22 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int value, int base)
{
	int		len;

	len = 0;
	while (value >= base)
	{
		value = value / base;
		len++;
	}
	return (len + 1);
}

char		*ft_itoa_base(int value, int base)
{
	char	*ret;
	int		i;

	if (base == 10)
		return (ft_itoa(value));
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
