/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:09:09 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/04 19:35:24 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[j] && little[j] &&
				(size_t)i + (size_t)j < len)
			j++;
		if (little[j] == '\0')
		{
			return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
