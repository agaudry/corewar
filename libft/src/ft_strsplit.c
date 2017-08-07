/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:55:01 by agaudry           #+#    #+#             */
/*   Updated: 2017/06/21 17:39:45 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wrdlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

size_t			ft_count(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	nb_len;

	tab = NULL;
	if (s != NULL)
		if ((tab = (char **)ft_memalloc(sizeof(char *) * (ft_count(s, c) + 1))))
		{
			i = 0;
			j = 0;
			while (j < ft_count(s, c))
			{
				while (s[i] == c && s[i])
					i++;
				nb_len = ft_wrdlen(s + i, c);
				tab[j] = ft_strsub(s, i, nb_len);
				i += nb_len;
				j++;
			}
			tab[j] = NULL;
		}
	return (tab);
}
