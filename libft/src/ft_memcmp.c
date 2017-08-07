/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:36:38 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/11 11:20:28 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	cmp = 0;
	while (i < n && cmp == 0)
	{
		cmp = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		i++;
	}
	return (cmp);
}
