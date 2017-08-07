/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:52:44 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/22 15:07:54 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendst;

	i = 0;
	while (dst[i] && i < size)
		i++;
	lendst = i;
	j = 0;
	while (src[j] && (int)i < (int)size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (lendst < size)
		dst[i] = '\0';
	return (lendst + ft_strlen(src));
}
