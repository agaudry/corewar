/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:09:09 by agaudry           #+#    #+#             */
/*   Updated: 2017/06/20 19:42:24 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *big, char const *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[j] && little[j])
			j++;
		if (little[j] == '\0')
		{
			return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
