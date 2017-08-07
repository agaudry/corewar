/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:14:07 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/17 12:01:07 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	a;
	size_t	z;
	size_t	len;
	char	*ret;

	if (s == NULL)
		return (NULL);
	a = 0;
	z = ft_strlen(s) - 1;
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t') && s[a])
		a++;
	while ((s[z] == ' ' || s[z] == '\n' || s[z] == '\t') && z > 0)
		z--;
	len = z - a + 1;
	if (z == 0 && a == ft_strlen(s))
		return (ft_strnew(0));
	else
	{
		ret = ft_strsub(s, (unsigned int)a, len);
		return (ret);
	}
}
