/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:06:57 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/17 11:58:13 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	ret = ft_strnew(ft_strlen(s));
	while (s[i] && ret != NULL)
	{
		ret[i] = f(i, ((char *)s)[i]);
		i++;
	}
	return (ret);
}
