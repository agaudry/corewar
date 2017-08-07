/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:37:55 by agaudry           #+#    #+#             */
/*   Updated: 2017/02/28 17:50:06 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long nbr, char *base)
{
	char				*str;
	int					power;
	int					baselen;
	unsigned long		i;

	baselen = ft_strlen(base);
	power = 1;
	i = nbr;
	while ((i /= baselen))
		power++;
	str = (char*)malloc(power + 1);
	str[power] = '\0';
	while (power--)
	{
		str[power] = base[nbr % baselen];
		nbr /= baselen;
	}
	return (str);
}
