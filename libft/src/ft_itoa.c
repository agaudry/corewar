/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:49:34 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/13 11:47:12 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = ft_len(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = ft_strnew(ft_len(n));
	if (s == NULL)
		return (0);
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (i >= 0 && s[i] != '-')
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
