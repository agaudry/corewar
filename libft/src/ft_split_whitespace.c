/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 09:08:47 by agaudry           #+#    #+#             */
/*   Updated: 2017/06/21 09:15:29 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wrdlen_w(char const *s)
{
	int i;

	i = 0;
	while (!(ft_is_whitespace(s[i])) && s[i] != '\0')
		i++;
	return (i);
}

size_t			ft_count_w(char const *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (ft_is_whitespace(s[i]) && s[i] != '\0')
			i++;
		if (!(ft_is_whitespace(s[i])) && s[i] != '\0')
			j++;
		while (!(ft_is_whitespace(s[i])) && s[i] != '\0')
			i++;
	}
	return (j);
}

char			**ft_split_whitespace(char const *s)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	nb_len;

	tab = NULL;
	if (s != NULL)
		if ((tab = (char **)ft_memalloc(sizeof(char *) * (ft_count_w(s) + 1))))
		{
			i = 0;
			j = 0;
			while (j < ft_count_w(s))
			{
				while (ft_is_whitespace(s[i]) && s[i])
					i++;
				nb_len = ft_wrdlen_w(s + i);
				tab[j] = ft_strsub(s, i, nb_len);
				i += nb_len;
				j++;
			}
			tab[j] = NULL;
		}
	return (tab);
}
