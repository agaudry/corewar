/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:28:40 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/17 14:54:03 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while ((int)i < ((int)n - 1) && ((unsigned char *)s)[i] !=
			(unsigned char)c)
		i++;
	if (((unsigned char *)s)[i] == (unsigned char)c && n != 0)
		return ((void *)(s + i));
	else
		return (NULL);
}
