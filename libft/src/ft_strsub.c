/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:48:26 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/29 17:48:08 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	ret = ft_strnew(len);
	if (ret == 0)
		return (NULL);
	while (i < len)
	{
		ret[i] = ((char *)s)[start];
		i++;
		start++;
	}
	return (ret);
}
