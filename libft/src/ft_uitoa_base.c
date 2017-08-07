/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:46:45 by agaudry           #+#    #+#             */
/*   Updated: 2017/01/29 18:50:31 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int value, int base)
{
	int		len;

	len = 0;
	while (value >= (unsigned int)base)
	{
		value = value / base;
		len++;
	}
	return (len + 1);
}

char		*ft_uitoa_base(unsigned int value, int base)
{
	char	*ret;
	int		i;

	if (base == 10)
		return (ft_itoa(value));
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
