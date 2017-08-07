/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_u_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:49:34 by agaudry           #+#    #+#             */
/*   Updated: 2017/02/28 17:46:00 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long n)
{
	long long	len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char		*ft_ltoa_u_conv(long long n)
{
	char		*s;
	long long	i;

	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("9223372036854775808"));
	i = ft_len(n) - 1;
	s = ft_strnew(ft_len(n));
	if (s == NULL)
		return (0);
	if (n < 0)
		n = -n;
	while (i >= 0 && s[i] != '-')
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
