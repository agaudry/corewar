/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:53:41 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/17 11:58:42 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	int		nb;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	nb = s1[0] - s2[0];
	while (s1[i] && s2[i] && nb == 0)
	{
		i++;
		nb = s1[i] - s2[i];
	}
	if (nb == 0)
		return (1);
	else
		return (0);
}
