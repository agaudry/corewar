/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:49:38 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/09 17:32:32 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;

	i = ft_strlen(s + 1);
	if (s[i + 1] == '\0' && c == '\0')
		return (&((char *)s)[i + 1]);
	while (s[i] && s[i] != c)
		i--;
	if (s[i] != c)
		return (NULL);
	else
		return (&((char *)s)[i]);
}
